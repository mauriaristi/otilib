// ndarray memory: the control block, its atomic state word and the descriptor lifecycle
// (include/oti/real/ndarray/buffer.h, lifecycle half; PLAN-ndarray-contracts.md sections 1.1-1.7).
// Included first from the unity translation unit src/c/real_ndarray.c: the helpers below (checked
// arithmetic, allocation with failure injection, the non-recording allocator ndb_alloc_array) are
// shared by the later ndarray files of the same unit. File-static prefix: ndb_.
//
// Every state transition is one CAS loop on the whole word (__atomic_* builtins on a plain uint64_t,
// contracts S9). Public functions record their failure once with oti_ctx_set_error(); the ndb_
// helpers return statuses only.
//
// Blocks (W4, the 7a allocation fix): a library array's control block is followed in the same
// allocation by the caller's extra zone (nd_alloc_extra()) and, for data up to NDB_INLINE_MAX bytes,
// by the data itself (64-byte aligned): one allocation per small array. Larger data is a second
// allocation. Scratch arrays (ND_ALLOC_SCRATCH) take the whole block from the calling thread's arena,
// a LIFO bump region: a released block is popped once every block above it is released too, and the
// arena empties when its last block goes. A grown buffer always moves its data to the heap.

#include <pthread.h>
#include <stdlib.h>
#include <string.h>

// AddressSanitizer: released scratch blocks are poisoned so stale uses are reported.
#ifdef __has_feature
#if __has_feature(address_sanitizer)
#define NDB_ASAN 1
#endif
#endif
#if !defined(NDB_ASAN) && defined(__SANITIZE_ADDRESS__)
#define NDB_ASAN 1
#endif
#ifdef NDB_ASAN
#include <sanitizer/asan_interface.h>
#define NDB_POISON(p, n) \
    do { if ((p) != NULL && (n) > 0) ASAN_POISON_MEMORY_REGION((p), (size_t)(n)); } while (0)
#define NDB_UNPOISON(p, n) \
    do { if ((p) != NULL && (n) > 0) ASAN_UNPOISON_MEMORY_REGION((p), (size_t)(n)); } while (0)
#else
#define NDB_POISON(p, n) ((void)0)
#define NDB_UNPOISON(p, n) ((void)0)
#endif


// -------------------------------------------------------------------------------------------------------
// ---------------------------------    CHECKED ARITHMETIC    --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// Overflow-checked int64 arithmetic (contracts 2.3): nonzero on overflow, *r holds the wrapped value.
// The contracts place these macros in src/c/real/ndarray/nd_internal.h; until that header exists
// (header request in build-orch/w1-header-requests.md) they are defined here, first in the unity.
#ifndef oti_ckd_mul_i64
#define oti_ckd_mul_i64(a, b, r) __builtin_mul_overflow((int64_t)(a), (int64_t)(b), (r))
#endif
#ifndef oti_ckd_add_i64
#define oti_ckd_add_i64(a, b, r) __builtin_add_overflow((int64_t)(a), (int64_t)(b), (r))
#endif

// Debug-build checks of the receiving descriptors (contracts 1.4, [cL7]) and of the inputs (1.1).
#ifdef OTI_ND_DEBUG
#define NDB_ASSERT_RECV(p) assert((p) == NULL || !((p)->flags & ND_RETAINED))
#define NDB_ASSERT_INPUT(p) assert((p) == NULL || nd_validate((p), NULL, NULL, 0) == OTI_OK)
#else
#define NDB_ASSERT_RECV(p) ((void)0)
#define NDB_ASSERT_INPUT(p) ((void)0)
#endif

// Alignment of library allocations (contracts 1.2).
#define NDB_ALIGN 64

// Data of at most this many bytes shares the control block's allocation.
#define NDB_INLINE_MAX ((int64_t)4096)

// Scratch arena: first capacity, largest capacity, largest block taken from it (else the heap).
#define NDB_ARENA_MIN ((int64_t)16 * 1024)
#define NDB_ARENA_MAX ((int64_t)1024 * 1024)
#define NDB_SCRATCH_BLOCK_MAX ((int64_t)256 * 1024)


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    CONTROL BLOCK    -------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct ndb_arena_s ndb_arena_t;

struct nd_buffer_s {
    uint64_t      state;        // atomic state word (ND_STATE_*); __atomic_* builtins only
    void*         base;         // start of the allocation span
    int64_t       nbytes;       // span length; -1 = unknown (foreign memory, no span check)
    nd_release_fn release;      // called exactly once when refs reach 0; may be NULL
    void*         release_ctx;  // argument of release
    void*         inl;          // data stored inside this block's allocation (never freed alone), or NULL
    void*         extra;        // the caller's zone (nd_alloc_extra()), right after this struct, or NULL
    int64_t       extra_bytes;  // size of the zone
    ndb_arena_t*  arena;        // scratch arena holding this block, or NULL (a heap block)
    int64_t       ar_prev;      // scratch: arena offset of the block below, -1 for none
    int64_t       ar_size;      // scratch: bytes of this block in the arena (a multiple of 64)
    int64_t       ar_freed;     // scratch: released, popped once the blocks above it are
};

// The extra zone starts right after the struct: its size must keep the zone ND_EXTRA_ALIGN-aligned.
typedef char ndb_assert_block_size[(sizeof(struct nd_buffer_s) % ND_EXTRA_ALIGN == 0) ? 1 : -1];

// The calling thread's scratch arena (one per thread, freed at thread exit or nd_scratch_release()).
struct ndb_arena_s {
    char*   mem;     // NDB_ALIGN-aligned region of cap bytes, or NULL
    int64_t cap;     // capacity
    int64_t top;     // first free byte
    int64_t last;    // offset of the topmost block, -1 for none
    int64_t live;    // blocks not yet released
    int64_t spill;   // bytes of the blocks that did not fit since the arena was last empty
    int64_t want;    // capacity those requests needed (applied when the arena is next empty)
};

static _Thread_local ndb_arena_t* ndb_tls_arena = NULL;
static pthread_key_t ndb_arena_key;
static pthread_once_t ndb_arena_once = PTHREAD_ONCE_INIT;
static int ndb_arena_key_ok = 0;

// Countdown of nd_test_fail_alloc(); 0 = disabled.
static int64_t ndb_fail_countdown = 0;


// *******************************************************************************************************
void nd_test_fail_alloc(int64_t countdown){

    __atomic_store_n(&ndb_fail_countdown, countdown > 0 ? countdown : 0, __ATOMIC_SEQ_CST);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when the allocation about to be made must fail (nd_test_fail_alloc()). One relaxed load when off.
static inline int ndb_inject_fail(void){

    int64_t c = __atomic_load_n(&ndb_fail_countdown, __ATOMIC_RELAXED);

    while (c > 0){
        if (__atomic_compare_exchange_n(&ndb_fail_countdown, &c, c - 1, 1, __ATOMIC_RELAXED,
                                        __ATOMIC_RELAXED)){
            return c == 1;
        }
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// malloc through the failure injection. For control blocks and small private tables.
static void* ndb_malloc(size_t nbytes){

    if (ndb_inject_fail()){
        return NULL;
    }

    return malloc(nbytes > 0 ? nbytes : 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 64-byte aligned allocation without the failure injection. Free with free().
static void* ndb_raw_aligned(size_t nbytes){

    void* p = NULL;

    if (posix_memalign(&p, NDB_ALIGN, nbytes > 0 ? nbytes : 1) != 0){
        return NULL;
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 64-byte aligned allocation through the failure injection (array data, temporaries). Free with free().
static void* ndb_aligned_alloc(size_t nbytes){

    if (ndb_inject_fail()){
        return NULL;
    }

    return ndb_raw_aligned(nbytes);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Thread-exit destructor of an arena. Live blocks at thread exit break the scratch contract (released on
// the allocating thread before it ends): their arena is then left allocated rather than freed under them.
static void ndb_arena_destroy(void* p){

    ndb_arena_t* ar = (ndb_arena_t*)p;

    if (ndb_tls_arena == ar){
        ndb_tls_arena = NULL;
    }
    if (ar->live == 0){
        NDB_UNPOISON(ar->mem, ar->cap);
        free(ar->mem);
        free(ar);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Creates the arena key (once per process).
static void ndb_arena_key_create(void){

    ndb_arena_key_ok = (pthread_key_create(&ndb_arena_key, ndb_arena_destroy) == 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The calling thread's arena, created on first use and registered for its thread-exit destructor; NULL
// when that fails (scratch arrays then come from the heap).
static ndb_arena_t* ndb_arena(void){

    ndb_arena_t* ar = ndb_tls_arena;

    if (ar != NULL){
        return ar;
    }
    (void)pthread_once(&ndb_arena_once, ndb_arena_key_create);
    if (!ndb_arena_key_ok){
        return NULL;
    }
    ar = (ndb_arena_t*)calloc(1, sizeof(ndb_arena_t));
    if (ar == NULL){
        return NULL;
    }
    ar->last = -1;
    if (pthread_setspecific(ndb_arena_key, ar) != 0){
        free(ar);
        return NULL;
    }
    ndb_tls_arena = ar;

    return ar;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Takes a block of size bytes (a multiple of NDB_ALIGN) from the top of the arena, or NULL when it does
// not fit. An empty arena is first resized to what earlier requests wanted.
static nd_buffer_t* ndb_arena_take(ndb_arena_t* ar, int64_t size){

    nd_buffer_t* b;
    int64_t cap;

    if (ar->live == 0){
        ar->top = 0;
        ar->last = -1;
        ar->spill = 0;
        if (ar->mem == NULL || ar->cap < ar->want){
            cap = NDB_ARENA_MIN;
            while (cap < ar->want && cap < NDB_ARENA_MAX){
                cap *= 2;
            }
            NDB_UNPOISON(ar->mem, ar->cap);
            free(ar->mem);
            ar->mem = (char*)ndb_raw_aligned((size_t)cap);
            ar->cap = (ar->mem != NULL) ? cap : 0;
            NDB_POISON(ar->mem, ar->cap);
        }
    }
    if (ar->mem == NULL || size > ar->cap - ar->top){
        // Peak demand: what is in the arena plus every block that spilled to the heap meanwhile.
        ar->spill += size;
        if (ar->top + ar->spill > ar->want){
            ar->want = (ar->top + ar->spill < NDB_ARENA_MAX) ? ar->top + ar->spill : NDB_ARENA_MAX;
        }
        return NULL;
    }
    b = (nd_buffer_t*)(ar->mem + ar->top);
    NDB_UNPOISON(b, size);
    b->arena = ar;
    b->ar_prev = ar->last;
    b->ar_size = size;
    b->ar_freed = 0;
    ar->last = ar->top;
    ar->top += size;
    ar->live++;

    return b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gives a scratch block back to its arena (on the allocating thread): pops it and every released block
// below it while they are on top.
static void ndb_arena_give(nd_buffer_t* b){

    ndb_arena_t* ar = b->arena;
    int64_t old_top = ar->top;
    nd_buffer_t* t;

#ifdef OTI_ND_DEBUG
    assert(ar == ndb_tls_arena && ar->live > 0);    // released on the allocating thread
#endif
    b->ar_freed = 1;
    NDB_POISON((char*)b + sizeof(nd_buffer_t), b->ar_size - (int64_t)sizeof(nd_buffer_t));
    ar->live--;
    if (ar->live == 0){
        ar->top = 0;
        ar->last = -1;
    } else {
        while (ar->last >= 0){
            t = (nd_buffer_t*)(ar->mem + ar->last);
            if (!t->ar_freed){
                break;
            }
            ar->top = ar->last;
            ar->last = t->ar_prev;
        }
    }
    NDB_POISON(ar->mem + ar->top, old_top - ar->top);
    (void)old_top;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A new library block: control block, extra zone (zeroed) and data (contents unspecified), state refs
// 1 | OWNS | GROWABLE | WRITEABLE (| SCRATCH). One allocation event of the failure injection, plus one
// for data above NDB_INLINE_MAX bytes on the heap. NULL on failure (nothing remains allocated).
static nd_buffer_t* ndb_block_new(int64_t nbytes, int64_t extra_bytes, int scratch){

    int64_t xoff = (int64_t)sizeof(nd_buffer_t);
    int64_t doff = (xoff + extra_bytes + NDB_ALIGN - 1) & ~(int64_t)(NDB_ALIGN - 1);
    nd_buffer_t* b = NULL;
    ndb_arena_t* ar;
    char* data = NULL;

    // nbytes is under the budget and extra_bytes <= ND_EXTRA_MAX_BYTES: no sum below overflows.
    if (ndb_inject_fail()){
        return NULL;
    }
    if (scratch && nbytes <= NDB_SCRATCH_BLOCK_MAX){
        ar = ndb_arena();
        if (ar != NULL){
            b = ndb_arena_take(ar, (doff + nbytes + NDB_ALIGN - 1) & ~(int64_t)(NDB_ALIGN - 1));
        }
        if (b != NULL){
            data = (char*)b + doff;
        }
    }
    if (b == NULL && nbytes <= NDB_INLINE_MAX){
        b = (nd_buffer_t*)ndb_raw_aligned((size_t)(doff + nbytes));
        if (b == NULL){
            return NULL;
        }
        b->arena = NULL;
        data = (char*)b + doff;
    } else if (b == NULL){
        b = (nd_buffer_t*)ndb_raw_aligned((size_t)(xoff + extra_bytes));
        if (b == NULL){
            return NULL;
        }
        data = (char*)ndb_aligned_alloc((size_t)nbytes);
        if (data == NULL){
            free(b);
            return NULL;
        }
        b->arena = NULL;
    }
    b->state = 1u | ND_STATE_OWNS | ND_STATE_GROWABLE | ND_STATE_WRITEABLE |    // S25
               (scratch ? ND_STATE_SCRATCH : 0);
    b->base = data;
    b->nbytes = nbytes;
    b->release = NULL;
    b->release_ctx = NULL;
    b->inl = (data == (char*)b + doff) ? data : NULL;
    b->extra = (extra_bytes > 0) ? (char*)b + xoff : NULL;
    b->extra_bytes = extra_bytes;
    if (extra_bytes > 0){
        memset(b->extra, 0, (size_t)extra_bytes);
    }

    return b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Frees the memory and the control block of a buffer whose last reference was just dropped.
static void ndb_destroy(nd_buffer_t* b){

    nd_release_fn release = b->release;
    void* rctx = b->release_ctx;

    if ((__atomic_load_n(&b->state, __ATOMIC_RELAXED) & ND_STATE_OWNS) && b->base != b->inl){
        free(b->base);
    }
    if (release != NULL){
        release(rctx);
    }
    if (b->arena != NULL){
        ndb_arena_give(b);
    } else {
        free(b);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// retain / export transition (contracts 1.3): add = 1, or 1 + (1 << 32) for an export.
static int ndb_retain(nd_buffer_t* b, uint64_t add){

    uint64_t s = __atomic_load_n(&b->state, __ATOMIC_RELAXED), n;

    do {
        if (s & ND_STATE_GROWING){
            return OTI_ERR_BUSY;
        }
        if ((s & ND_STATE_REFS_MASK) == ND_STATE_REFS_MASK){
            return OTI_ERR_SIZE;
        }
        if ((add >> ND_STATE_EXPORTS_SHIFT) && (s & ND_STATE_SCRATCH)){
            return OTI_ERR_BUSY;    // a call-local array never escapes
        }
        if ((add >> ND_STATE_EXPORTS_SHIFT) &&
            (s & ND_STATE_EXPORTS_MASK) == ND_STATE_EXPORTS_MASK){
            return OTI_ERR_SIZE;
        }
        n = s + add;
    } while (!__atomic_compare_exchange_n(&b->state, &s, n, 1, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED));

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// release / unexport transition (contracts 1.3): sub = 1, or 1 + (1 << 32). Destroys at refs 0.
static void ndb_unref(nd_buffer_t* b, uint64_t sub){

    uint64_t n;

#ifdef OTI_ND_DEBUG
    uint64_t s = __atomic_load_n(&b->state, __ATOMIC_RELAXED);
    do {
        assert((s & ND_STATE_REFS_MASK) > 0);
        assert(!(sub >> ND_STATE_EXPORTS_SHIFT) || (s & ND_STATE_EXPORTS_MASK) != 0);
        n = s - sub;
    } while (!__atomic_compare_exchange_n(&b->state, &s, n, 1, __ATOMIC_RELEASE, __ATOMIC_RELAXED));
    if ((n & ND_STATE_REFS_MASK) == 0){
        __atomic_thread_fence(__ATOMIC_ACQUIRE);
        ndb_destroy(b);
    }
#else
    n = __atomic_sub_fetch(&b->state, sub, __ATOMIC_ACQ_REL);
    if ((n & ND_STATE_REFS_MASK) == 0){
        ndb_destroy(b);
    }
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Contiguous strides (elements) of a shape in C or F order. Extents of 0 are skipped in the running
// product, as NumPy does, so an empty array gets the strides of its nonzero extents.
static int ndb_contig_strides(int32_t ndim, const int64_t* shape, int32_t layout, int64_t* strides){

    int64_t s = 1;
    int32_t k;

    if (layout == ND_LAYOUT_F){
        for (k = 0; k < ndim; k++){
            strides[k] = s;
            if (shape[k] > 0 && oti_ckd_mul_i64(s, shape[k], &s)){
                return OTI_ERR_SIZE;
            }
        }
    } else {
        for (k = ndim - 1; k >= 0; k--){
            strides[k] = s;
            if (shape[k] > 0 && oti_ckd_mul_i64(s, shape[k], &s)){
                return OTI_ERR_SIZE;
            }
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when the strides of (ndim, shape) are compact and injective (nd_alloc_strided(), S24): strides > 0
// on every axis of extent > 1, no internal overlap, and the highest offset + 1 equals the element
// count. Any strides describe an empty array; axes of extent <= 1 never step.
static int ndb_strides_compact(int32_t ndim, const int64_t* shape, const int64_t* strides){

    int64_t count = 1, hi = 0, d;
    ndarr_t t;
    int32_t k;

    for (k = 0; k < ndim; k++){
        if (shape[k] == 0){
            return 1;
        }
    }
    t.ndim = ndim;
    for (k = 0; k < ndim; k++){
        t.shape[k] = shape[k];
        t.strides[k] = strides[k];
        if (shape[k] > 1){
            if (strides[k] <= 0 || oti_ckd_mul_i64(shape[k] - 1, strides[k], &d) ||
                oti_ckd_add_i64(hi, d, &hi)){
                return 0;
            }
        }
        count *= shape[k];    // fits: checked by the caller
    }
    if (hi != count - 1){    // count >= 1 here; hi + 1 could overflow for extreme strides
        return 0;
    }

    return !nd_internal_overlap(&t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The allocator of nd_alloc() (given == NULL: C or F layout), nd_alloc_strided() (given strides,
// checked compact) and nd_alloc_extra(), without last-error recording. Every library buffer is OWNS |
// GROWABLE (S25). On failure res is empty, *extra NULL and nothing remains allocated.
static int ndb_alloc_core(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                          const int64_t* given, int32_t layout, int32_t alloc_flags,
                          int64_t extra_bytes, void** extra, ndarr_t* res){

    int64_t isz, nz = 1, nbytes;
    int64_t strides[OTI_ND_MAXDIM];
    nd_buffer_t* b;
    void* data;
    int32_t k;
    int st;

    if (extra != NULL){
        *extra = NULL;
    }
    if (res == NULL){
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_RECV(res);
    nd_init_empty(res);
    if (ndim < 0 || ndim > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }
    if (ndim > 0 && shape == NULL){
        return OTI_ERR_ARGUMENT;
    }
    for (k = 0; k < ndim; k++){
        if (shape[k] < 0){
            return OTI_ERR_SHAPE;
        }
    }
    isz = nd_itemsize(dtype);
    if (isz == 0){
        return OTI_ERR_DTYPE;
    }
    if ((given == NULL && layout != ND_LAYOUT_C && layout != ND_LAYOUT_F) ||
        (alloc_flags & ~(ND_ALLOC_ZERO | ND_ALLOC_GROWABLE | ND_ALLOC_SCRATCH)) != 0 ||
        extra_bytes < 0 || extra_bytes > ND_EXTRA_MAX_BYTES){
        return OTI_ERR_ARGUMENT;
    }

    // Product of the nonzero extents in bytes (NumPy's "array is too big" rule), at least one element.
    for (k = 0; k < ndim; k++){
        if (shape[k] > 0 && oti_ckd_mul_i64(nz, shape[k], &nz)){
            return OTI_ERR_SIZE;
        }
    }
    if (oti_ckd_mul_i64(nz, isz, &nbytes)){
        return OTI_ERR_SIZE;
    }
    for (k = 0; k < ndim; k++){
        if (shape[k] == 0){
            nbytes = isz;
            break;
        }
    }
    if (given != NULL){
        if (!ndb_strides_compact(ndim, shape, given)){
            return OTI_ERR_LAYOUT;
        }
        for (k = 0; k < ndim; k++){
            strides[k] = given[k];
        }
    } else {
        st = ndb_contig_strides(ndim, shape, layout, strides);
        if (st != OTI_OK){
            return st;
        }
    }
    st = oti_ctx_check_alloc(ctx, nbytes);
    if (st == OTI_OK && (alloc_flags & ND_ALLOC_SCRATCH)){
        st = oti_ctx_check_temp(ctx, nbytes);
    }
    if (st != OTI_OK){
        return st;
    }

    b = ndb_block_new(nbytes, extra_bytes, (alloc_flags & ND_ALLOC_SCRATCH) != 0);
    if (b == NULL){
        return OTI_ERR_MEMORY;
    }
    data = b->base;
    if (alloc_flags & ND_ALLOC_ZERO){
        memset(data, 0, (size_t)nbytes);
    }
    if (extra != NULL){
        *extra = b->extra;
    }

    res->data = data;
    res->ndim = ndim;
    res->dtype = dtype;
    for (k = 0; k < ndim; k++){
        res->shape[k] = shape[k];
        res->strides[k] = strides[k];
    }
    res->flags = ND_WRITEABLE | ND_RETAINED;
    res->buf = b;
    nd_update_flags(res);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_alloc() without last-error recording, for the other ndarray files of the unity.
static int ndb_alloc_array(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                           int32_t layout, int32_t alloc_flags, ndarr_t* res){

    return ndb_alloc_core(ctx, dtype, ndim, shape, NULL, layout, alloc_flags, 0, NULL, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_alloc_strided() without last-error recording.
static int ndb_alloc_strided(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                             const int64_t* strides, int32_t alloc_flags, ndarr_t* res){

    if (ndim > 0 && strides == NULL){
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
        return OTI_ERR_ARGUMENT;
    }

    // Rank 0 has no strides: the C path allocates the one element.
    return ndb_alloc_core(ctx, dtype, ndim, shape, ndim > 0 ? strides : NULL, ND_LAYOUT_C, alloc_flags,
                          0, NULL, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_wrap() without last-error recording (also used by nd_import()). The callback runs exactly once on
// every failure path; on success it belongs to the new buffer.
static int ndb_wrap(const ndarr_t* desc, const void* span_lo, int64_t span_nbytes,
                    nd_release_fn release, void* release_ctx, ndarr_t* res){

    const void* span_hi = NULL;
    int32_t vflags = 0, k;
    nd_buffer_t* b;
    int st = OTI_OK;

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
        goto fail;
    }
    NDB_ASSERT_RECV(res);
    nd_init_empty(res);
    if (desc == NULL || span_nbytes < -1){
        st = OTI_ERR_ARGUMENT;
        goto fail;
    }
    if (span_lo != NULL && span_nbytes >= 0){
        uintptr_t lo = (uintptr_t)span_lo;
        if ((uint64_t)span_nbytes > (uint64_t)(UINTPTR_MAX - lo)){
            st = OTI_ERR_LAYOUT;
            goto fail;
        }
        span_hi = (const void*)(lo + (uintptr_t)span_nbytes);
        vflags = ND_V_SPAN;
    }
    st = nd_validate(desc, span_lo, span_hi, vflags);
    if (st != OTI_OK){
        goto fail;
    }

    b = (nd_buffer_t*)ndb_malloc(sizeof(nd_buffer_t));
    if (b == NULL){
        st = OTI_ERR_MEMORY;
        goto fail;
    }
    b->base = (vflags & ND_V_SPAN) ? (void*)span_lo : NULL;
    b->nbytes = (vflags & ND_V_SPAN) ? span_nbytes : -1;
    b->release = release;
    b->release_ctx = release_ctx;
    b->inl = NULL;
    b->extra = NULL;
    b->extra_bytes = 0;
    b->arena = NULL;
    b->state = 1u | ((desc->flags & ND_WRITEABLE) ? ND_STATE_WRITEABLE : 0);

    res->data = desc->data;
    res->ndim = desc->ndim;
    res->dtype = desc->dtype;
    for (k = 0; k < desc->ndim; k++){
        res->shape[k] = desc->shape[k];
        res->strides[k] = desc->strides[k];
    }
    res->flags = (desc->flags & ND_WRITEABLE) | ND_RETAINED;
    res->buf = b;
    nd_update_flags(res);

    return OTI_OK;

fail:
    if (release != NULL){
        release(release_ctx);
    }
    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_view_retain() without last-error recording. res may be src (a temporary).
static int ndb_view_retain(const ndarr_t* src, ndarr_t* res){

    ndarr_t tmp;
    int st;

    if (src == NULL || res == NULL){
        if (res != NULL){
            nd_init_empty(res);
        }
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_RECV(res);
    if (src->buf == NULL){
        nd_init_empty(res);
        return OTI_ERR_ARGUMENT;
    }
    tmp = *src;
    st = ndb_retain(tmp.buf, 1u);
    if (st != OTI_OK){
        nd_init_empty(res);
        return st;
    }
    tmp.flags = (tmp.flags & ~ND_EXPORTED) | ND_RETAINED;
    *res = tmp;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    LIFECYCLE    -----------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_init_empty(ndarr_t* a){

    if (a == NULL){
        return;
    }
    // Field stores only (critic finding 5): entries of shape / strides at index >= ndim are never read.
    a->data = NULL;
    a->shape[0] = 0;
    a->strides[0] = 1;
    a->ndim = 1;
    a->dtype = OTI_F64;
    a->flags = ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE;
    a->reserved = 0;
    a->buf = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_alloc(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape, int32_t layout,
             int32_t alloc_flags, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    if (st != OTI_OK){
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
    } else {
        st = ndb_alloc_array(ctx, dtype, ndim, shape, layout, alloc_flags, res);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_alloc", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_alloc_strided(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                     const int64_t* strides, int32_t alloc_flags, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    if (st != OTI_OK){
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
    } else {
        st = ndb_alloc_strided(ctx, dtype, ndim, shape, strides, alloc_flags, res);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_alloc_strided", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_alloc_extra(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                   const int64_t* strides, int32_t layout, int32_t alloc_flags, int64_t extra_bytes,
                   void** extra, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    if (st != OTI_OK){
        if (extra != NULL){
            *extra = NULL;
        }
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
    } else {
        // Strides given: as nd_alloc_strided() (rank 0 has none and takes the C path).
        st = ndb_alloc_core(ctx, dtype, ndim, shape, (ndim > 0) ? strides : NULL,
                            (strides != NULL) ? ND_LAYOUT_C : layout, alloc_flags, extra_bytes, extra,
                            res);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_alloc_extra", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_wrap(oti_ctx* ctx, const ndarr_t* desc, const void* span_lo, int64_t span_nbytes,
            nd_release_fn release, void* release_ctx, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    if (st != OTI_OK){
        // The callback was handed over on entry: it runs exactly once, here.
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
        if (release != NULL){
            release(release_ctx);
        }
    } else {
        st = ndb_wrap(desc, span_lo, span_nbytes, release, release_ctx, res);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_wrap", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_wrap_trusted() without last-error recording.
static int ndb_wrap_trusted(void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                            const int64_t* strides, int32_t writeable, ndarr_t* out){

    ndarr_t tmp;
    int32_t k;
    int st;

    if (out == NULL){
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_RECV(out);
    nd_init_empty(out);
    if (ndim < 0 || ndim > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }
    if (ndim > 0 && shape == NULL){
        return OTI_ERR_ARGUMENT;
    }
    memset(&tmp, 0, sizeof(tmp));
    tmp.data = data;
    tmp.ndim = ndim;
    tmp.dtype = dtype;
    for (k = 0; k < ndim; k++){
        tmp.shape[k] = shape[k];
        if (shape[k] < 0){
            return OTI_ERR_SHAPE;
        }
    }
    if (strides != NULL){
        for (k = 0; k < ndim; k++){
            tmp.strides[k] = strides[k];
        }
    } else {
        st = ndb_contig_strides(ndim, tmp.shape, ND_LAYOUT_C, tmp.strides);
        if (st != OTI_OK){
            return st;
        }
    }
    tmp.flags = writeable ? ND_WRITEABLE : 0;
    st = nd_validate(&tmp, NULL, NULL, 0);
    if (st != OTI_OK){
        return st;
    }
    nd_update_flags(&tmp);
    *out = tmp;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_wrap_trusted(void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                    const int64_t* strides, int32_t writeable, ndarr_t* out){

    int st = ndb_wrap_trusted(data, dtype, ndim, shape, strides, writeable, out);

    if (st != OTI_OK){
        oti_ctx_set_error(NULL, st, "nd_wrap_trusted", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_retain(const ndarr_t* src, ndarr_t* res){

    int st = ndb_view_retain(src, res);

    if (st != OTI_OK){
        oti_ctx_set_error(NULL, st, "nd_view_retain",
                          st == OTI_ERR_ARGUMENT ? "no control block to retain" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_clone(const ndarr_t* src, ndarr_t* res){

    int st;

    if (src == NULL || res == NULL){
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
        oti_ctx_set_error(NULL, OTI_ERR_ARGUMENT, "nd_clone", NULL);
        return OTI_ERR_ARGUMENT;
    }
    if (!(src->flags & ND_RETAINED)){
        NDB_ASSERT_RECV(res);
        if (res != src){
            *res = *src;
        }
        return OTI_OK;
    }
    st = ndb_view_retain(src, res);
    if (st != OTI_OK){
        oti_ctx_set_error(NULL, st, "nd_clone", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_move(ndarr_t* src, ndarr_t* dst){

    if (src == NULL || dst == NULL || src == dst){
        return;
    }
    NDB_ASSERT_RECV(dst);
    *dst = *src;
    nd_init_empty(src);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_export(const ndarr_t* src, int32_t writeable, ndarr_t* res){

    ndarr_t tmp;
    int st = OTI_OK;

    if (src == NULL || res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        NDB_ASSERT_RECV(res);
        if (src->buf == NULL){
            st = OTI_ERR_ARGUMENT;
        } else if (writeable && !(src->flags & ND_WRITEABLE)){
            st = OTI_ERR_READONLY;
        }
    }
    if (st != OTI_OK){
        if (res != NULL){
            nd_init_empty(res);
        }
        oti_ctx_set_error(NULL, st, "nd_export", NULL);
        return st;
    }
    tmp = *src;
    st = ndb_retain(tmp.buf, 1u + (1ull << ND_STATE_EXPORTS_SHIFT));
    if (st != OTI_OK){
        nd_init_empty(res);
        oti_ctx_set_error(NULL, st, "nd_export", NULL);
        return st;
    }
    tmp.flags = (tmp.flags & (ND_C_CONTIG | ND_F_CONTIG)) | ND_RETAINED | ND_EXPORTED |
                (writeable ? ND_WRITEABLE : 0);
    *res = tmp;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_release(ndarr_t* a){

    if (a == NULL){
        return;
    }
    if ((a->flags & ND_RETAINED) && a->buf != NULL){
        ndb_unref(a->buf, (a->flags & ND_EXPORTED) ? 1u + (1ull << ND_STATE_EXPORTS_SHIFT) : 1u);
    }
    nd_init_empty(a);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------    LAYOUT LOCK AND GROWTH    ---------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_buffer_lock_layout(nd_buffer_t* buf){

    uint64_t s, n;

    if (buf == NULL){
        return OTI_ERR_ARGUMENT;
    }
    s = __atomic_load_n(&buf->state, __ATOMIC_RELAXED);
    do {
        if ((s & ND_STATE_REFS_MASK) != 1u || (s & ND_STATE_EXPORTS_MASK) != 0 ||
            (s & ND_STATE_GROWING)){
            return OTI_ERR_BUSY;
        }
        n = s | ND_STATE_GROWING;
    } while (!__atomic_compare_exchange_n(&buf->state, &s, n, 1, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED));

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_buffer_unlock_layout(nd_buffer_t* buf){

    if (buf == NULL){
        return;
    }
#ifdef OTI_ND_DEBUG
    assert(__atomic_load_n(&buf->state, __ATOMIC_RELAXED) & ND_STATE_GROWING);
#endif
    __atomic_and_fetch(&buf->state, ~ND_STATE_GROWING, __ATOMIC_RELEASE);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Arguments shared by nd_grow() and nd_grow_locked(): a retained root with a control block, sizes in
// range. Borrowed or non-growable buffers are OTI_ERR_BUSY (contracts S4).
static int ndb_grow_check(const ndarr_t* root, int64_t nbytes, int64_t keep_bytes){

    uint64_t s;
    int64_t old;

    if (root == NULL || nbytes < 0 || keep_bytes < 0){
        return OTI_ERR_ARGUMENT;
    }
    if (root->buf == NULL){
        return OTI_ERR_BUSY;
    }
    if (!(root->flags & ND_RETAINED)){
        return OTI_ERR_ARGUMENT;
    }
    s = __atomic_load_n(&root->buf->state, __ATOMIC_ACQUIRE);
    if ((s & (ND_STATE_OWNS | ND_STATE_GROWABLE)) != (ND_STATE_OWNS | ND_STATE_GROWABLE)){
        return OTI_ERR_BUSY;
    }
    old = root->buf->nbytes;
    if (keep_bytes > nbytes || keep_bytes > old){
        return OTI_ERR_ARGUMENT;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The growth itself, the lock held and the arguments checked.
static int ndb_grow_held(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes){

    nd_buffer_t* b = root->buf;
    char* old_base = (char*)b->base;
    char* new_base;
    int st;

    // A scratch buffer stays scratch after growth (its new data comes from the heap), so the new size is
    // charged against the temporary budget too, as at allocation (checker W4 finding 1). Shared by
    // nd_grow and nd_grow_locked; on rejection nothing has changed and the old data stays valid.
    st = oti_ctx_check_alloc(ctx, nbytes);
    if (st == OTI_OK && (__atomic_load_n(&b->state, __ATOMIC_RELAXED) & ND_STATE_SCRATCH)){
        st = oti_ctx_check_temp(ctx, nbytes);
    }
    if (st != OTI_OK){
        return st;
    }
    new_base = (char*)ndb_aligned_alloc((size_t)nbytes);
    if (new_base == NULL){
        return OTI_ERR_MEMORY;
    }
    if (keep_bytes > 0){
        memcpy(new_base, old_base, (size_t)keep_bytes);
    }
#ifdef OTI_ND_DEBUG
    {
        // Poison the old allocation (signalling-NaN pattern) so stale views read garbage loudly.
        static const unsigned char snan[8] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF4, 0x7F};
        int64_t i;
        for (i = 0; i < b->nbytes; i++){
            old_base[i] = (char)snan[i & 7];
        }
    }
#endif
    root->data = new_base + ((char*)root->data - old_base);
    b->base = new_base;
    b->nbytes = nbytes;
    if ((void*)old_base != b->inl){
        free(old_base);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_grow_locked(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndb_grow_check(root, nbytes, keep_bytes);
    }

    // The lock must be held (checked in every build: one atomic load).
    if (st == OTI_OK && !(__atomic_load_n(&root->buf->state, __ATOMIC_RELAXED) & ND_STATE_GROWING)){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        st = ndb_grow_held(ctx, root, nbytes, keep_bytes);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_grow_locked", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_grow(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndb_grow_check(root, nbytes, keep_bytes);
    }

    if (st == OTI_OK){
        st = nd_buffer_lock_layout(root->buf);
        if (st == OTI_OK){
            st = ndb_grow_held(ctx, root, nbytes, keep_bytes);
            nd_buffer_unlock_layout(root->buf);
        }
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_grow", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_set_layout(ndarr_t* root, int32_t ndim, const int64_t* shape, const int64_t* strides){

    const char* lo;
    ndarr_t t;
    int32_t k;
    int st = OTI_OK;

    if (root == NULL || !(root->flags & ND_RETAINED) || root->buf == NULL ||
        !(__atomic_load_n(&root->buf->state, __ATOMIC_RELAXED) & ND_STATE_OWNS)){
        st = OTI_ERR_ARGUMENT;
    } else if (ndim < 0 || ndim > OTI_ND_MAXDIM){
        st = OTI_ERR_SHAPE;
    } else if (ndim > 0 && (shape == NULL || strides == NULL)){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        // Validate the new layout over the buffer's span; root is written only on success.
        t = *root;
        t.ndim = ndim;
        for (k = 0; k < ndim; k++){
            t.shape[k] = shape[k];
            t.strides[k] = strides[k];
        }
        lo = (const char*)root->buf->base;
        st = nd_validate(&t, lo, lo + root->buf->nbytes, ND_V_SPAN);
        if (st == OTI_OK){
            nd_update_flags(&t);
            *root = t;
        }
    }
    if (st != OTI_OK){
        oti_ctx_set_error(NULL, st, "nd_set_layout", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    QUERIES    -------------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
uint64_t nd_buffer_state(const nd_buffer_t* buf){

    return buf == NULL ? 0 : __atomic_load_n(&buf->state, __ATOMIC_ACQUIRE);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t nd_buffer_refs(const nd_buffer_t* buf){

    return (int64_t)(nd_buffer_state(buf) & ND_STATE_REFS_MASK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t nd_buffer_exports(const nd_buffer_t* buf){

    return (int64_t)((nd_buffer_state(buf) & ND_STATE_EXPORTS_MASK) >> ND_STATE_EXPORTS_SHIFT);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const void* nd_buffer_base(const nd_buffer_t* buf){

    return buf == NULL ? NULL : buf->base;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t nd_buffer_nbytes(const nd_buffer_t* buf){

    return buf == NULL ? 0 : buf->nbytes;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void* nd_buffer_extra(const nd_buffer_t* buf){

    return buf == NULL ? NULL : buf->extra;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t nd_buffer_extra_bytes(const nd_buffer_t* buf){

    return buf == NULL ? 0 : buf->extra_bytes;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_scratch_release(void){

    ndb_arena_t* ar = ndb_tls_arena;

    if (ar == NULL){
        return OTI_OK;
    }
    if (ar->live > 0){
        oti_ctx_set_error(NULL, OTI_ERR_BUSY, "nd_scratch_release", "scratch arrays are alive");
        return OTI_ERR_BUSY;
    }
    NDB_UNPOISON(ar->mem, ar->cap);
    free(ar->mem);
    ar->mem = NULL;
    ar->cap = 0;
    ar->top = 0;
    ar->last = -1;
    ar->spill = 0;
    ar->want = 0;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------
