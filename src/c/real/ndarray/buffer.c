// ndarray memory: the control block, its atomic state word and the descriptor lifecycle
// (include/oti/real/ndarray/buffer.h, lifecycle half; PLAN-ndarray-contracts.md sections 1.1-1.7).
// Included first from the unity translation unit src/c/real_ndarray.c: the helpers below (checked
// arithmetic, allocation with failure injection, the non-recording allocator ndb_alloc_array) are
// shared by the later ndarray files of the same unit. File-static prefix: ndb_.
//
// Every state transition is one CAS loop on the whole word (__atomic_* builtins on a plain uint64_t,
// contracts S9). Public functions record their failure once with oti_ctx_set_error(); the ndb_
// helpers return statuses only.

#include <stdlib.h>
#include <string.h>


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


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    CONTROL BLOCK    -------------------------------------------
// -------------------------------------------------------------------------------------------------------

struct nd_buffer_s {
    uint64_t      state;        // atomic state word (ND_STATE_*); __atomic_* builtins only
    void*         base;         // start of the allocation span
    int64_t       nbytes;       // span length; -1 = unknown (foreign memory, no span check)
    nd_release_fn release;      // called exactly once when refs reach 0; may be NULL
    void*         release_ctx;  // argument of release
};

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
// 64-byte aligned allocation through the failure injection (array data, temporaries). Free with free().
static void* ndb_aligned_alloc(size_t nbytes){

    void* p = NULL;

    if (ndb_inject_fail()){
        return NULL;
    }
    if (posix_memalign(&p, NDB_ALIGN, nbytes > 0 ? nbytes : 1) != 0){
        return NULL;
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Frees the memory and the control block of a buffer whose last reference was just dropped.
static void ndb_destroy(nd_buffer_t* b){

    nd_release_fn release = b->release;
    void* rctx = b->release_ctx;

    if (__atomic_load_n(&b->state, __ATOMIC_RELAXED) & ND_STATE_OWNS){
        free(b->base);
    }
    if (release != NULL){
        release(rctx);
    }
    free(b);

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
// The allocator of nd_alloc() (given == NULL: C or F layout) and nd_alloc_strided() (given strides,
// checked compact), without last-error recording. Every library buffer is OWNS | GROWABLE (S25). On
// failure res is empty and nothing remains allocated.
static int ndb_alloc_core(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                          const int64_t* given, int32_t layout, int32_t alloc_flags, ndarr_t* res){

    int64_t isz, nz = 1, nbytes;
    int64_t strides[OTI_ND_MAXDIM];
    nd_buffer_t* b;
    void* data;
    int32_t k;
    int st;

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
        (alloc_flags & ~(ND_ALLOC_ZERO | ND_ALLOC_GROWABLE)) != 0){
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
    if (st != OTI_OK){
        return st;
    }

    b = (nd_buffer_t*)ndb_malloc(sizeof(nd_buffer_t));
    if (b == NULL){
        return OTI_ERR_MEMORY;
    }
    data = ndb_aligned_alloc((size_t)nbytes);
    if (data == NULL){
        free(b);
        return OTI_ERR_MEMORY;
    }
    if (alloc_flags & ND_ALLOC_ZERO){
        memset(data, 0, (size_t)nbytes);
    }
    b->base = data;
    b->nbytes = nbytes;
    b->release = NULL;
    b->release_ctx = NULL;
    b->state = 1u | ND_STATE_OWNS | ND_STATE_GROWABLE | ND_STATE_WRITEABLE;    // S25

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

    return ndb_alloc_core(ctx, dtype, ndim, shape, NULL, layout, alloc_flags, res);

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
                          res);

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

    st = oti_ctx_check_alloc(ctx, nbytes);
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
    free(old_base);

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
