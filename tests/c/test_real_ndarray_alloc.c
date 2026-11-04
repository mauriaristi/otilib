/* Tests of the W4 allocation paths of include/oti/real/ndarray/buffer.h (the 7a allocation fix):
 * nd_alloc_extra() (an extra zone in the control block's allocation; small data in the same
 * allocation), ND_ALLOC_SCRATCH (call-local arrays from the calling thread's arena), nd_buffer_extra(),
 * nd_buffer_extra_bytes() and nd_scratch_release().
 *
 * Written by nd-core (the implementer; oracle has no test of these paths, W4 brief). Checks: alignment
 * and disjointness of control block, zone and data; zone lifetime through views and exports; growth
 * (the data moves, the control block and the zone stay); exports refused for scratch arrays; the LIFO
 * reuse of the arena, its overflow to the heap and its regrowth; budgets; failure injection at every
 * allocation; scratch arrays on several threads, with the thread-exit destructor; and, in ASan builds,
 * that a stale use of a released scratch block is reported (forked children). Leaks are checked with
 * ASan / `leaks --atExit` on this executable. */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // contracts S23
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <oti/core/exec.h>
#include <oti/real/ndarray/structures.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>
#include <oti/real/ndarray/views.h>

#ifdef __has_feature
#if __has_feature(address_sanitizer)
#define TA_ASAN 1
#endif
#endif
#if !defined(TA_ASAN) && defined(__SANITIZE_ADDRESS__)
#define TA_ASAN 1
#endif

// Size of a scratch block in the arena: control block (96 bytes), zone, data, each start 64-aligned.
#define TA_HDR 96

static int n_failed = 0;
static int n_passed = 0;


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        n_passed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when the descriptor is the empty temporary (the state of every output after a failure).
static int is_empty(const ndarr_t* a){

    return a->data == NULL && a->buf == NULL && !(a->flags & ND_RETAINED) && a->ndim == 1 &&
           a->shape[0] == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int64_t round64(int64_t n){

    return (n + 63) & ~(int64_t)63;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes a scratch block of n data bytes and x zone bytes takes in the arena.
static int64_t block_size(int64_t n, int64_t x){

    return round64(round64(TA_HDR + x) + n);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int scratch_alloc(int64_t n, int32_t flags, ndarr_t* a){

    nd_init_empty(a);

    return nd_alloc(NULL, OTI_F64, 1, &n, ND_LAYOUT_C, ND_ALLOC_SCRATCH | flags, a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fill(ndarr_t* a, double v){

    int64_t i, n = nd_size(a);

    for (i = 0; i < n; i++){
        ((double*)a->data)[i] = v + (double)i;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int holds(const ndarr_t* a, double v){

    int64_t i, n = nd_size(a);

    for (i = 0; i < n; i++){
        if (((const double*)a->data)[i] != v + (double)i){
            return 0;
        }
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_alloc(): small data shares the control block's allocation, large data does not.
static void test_inline(void){

    int64_t sh[2] = {2, 3}, big = 1000, k;
    ndarr_t a;
    int st;

    nd_init_empty(&a);

    st = nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &a);
    check(st == OTI_OK && a.data == nd_buffer_base(a.buf) && ((uintptr_t)a.data % 64) == 0,
          "small nd_alloc: data at base, 64-byte aligned");
    check(nd_buffer_nbytes(a.buf) == 48 && nd_buffer_extra(a.buf) == NULL &&
          nd_buffer_extra_bytes(a.buf) == 0, "small nd_alloc: nbytes 48, no zone");
    check((nd_buffer_state(a.buf) & ND_STATE_SCRATCH) == 0 && nd_buffer_refs(a.buf) == 1,
          "small nd_alloc: not scratch, refs 1");
    nd_release(&a);

    // One allocation event for small data, two for large data.
    nd_test_fail_alloc(1);
    st = nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &a);
    nd_test_fail_alloc(0);
    check(st == OTI_ERR_MEMORY && is_empty(&a), "small nd_alloc: injected failure 1 -> MEMORY, empty");
    nd_test_fail_alloc(2);
    st = nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &a);
    nd_test_fail_alloc(0);
    check(st == OTI_OK, "small nd_alloc: one allocation (injected failure 2 not reached)");
    nd_release(&a);
    for (k = 1; k <= 2; k++){
        nd_test_fail_alloc(k);
        st = nd_alloc(NULL, OTI_F64, 1, &big, ND_LAYOUT_C, 0, &a);
        nd_test_fail_alloc(0);
        check(st == OTI_ERR_MEMORY && is_empty(&a), "large nd_alloc: injected failure -> MEMORY");
    }
    nd_test_fail_alloc(3);
    st = nd_alloc(NULL, OTI_F64, 1, &big, ND_LAYOUT_C, 0, &a);
    nd_test_fail_alloc(0);
    check(st == OTI_OK && ((uintptr_t)a.data % 64) == 0 && a.data == nd_buffer_base(a.buf),
          "large nd_alloc: two allocations, aligned");
    fill(&a, 1.0);
    check(holds(&a, 1.0), "large nd_alloc: data usable");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_alloc_extra(): alignment, zero fill, disjointness, every size class, arguments.
static void test_extra(void){

    static const int64_t xs[] = {1, 15, 16, 17, 100, 4000, ND_EXTRA_MAX_BYTES};
    static const int64_t ns[] = {1, 24, 512, 513, 5000};
    int64_t sh3[3] = {3, 2, 2}, st3[3] = {4, 1, 2}, bad3[3] = {5, 1, 2}, x, n, i;
    const char* where = NULL;
    size_t ix, in;
    unsigned char* z;
    void* extra;
    ndarr_t a;
    oti_ctx ctx;
    int st, ok;

    nd_init_empty(&a);

    for (ix = 0; ix < sizeof(xs) / sizeof(xs[0]); ix++){
        for (in = 0; in < sizeof(ns) / sizeof(ns[0]); in++){
            x = xs[ix];
            n = ns[in];
            nd_init_empty(&a);
            extra = (void*)&a;
            st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, 0, x, &extra, &a);
            ok = (st == OTI_OK) && extra != NULL && ((uintptr_t)extra % ND_EXTRA_ALIGN) == 0 &&
                 ((uintptr_t)a.data % 64) == 0 && nd_buffer_extra(a.buf) == extra &&
                 nd_buffer_extra_bytes(a.buf) == x;
            check(ok, "nd_alloc_extra: zone aligned to 16, data to 64, queries");
            if (!ok){
                nd_release(&a);
                continue;
            }
            z = (unsigned char*)extra;
            for (i = 0; i < x && z[i] == 0; i++){
            }
            check(i == x, "nd_alloc_extra: zone zero-filled");
            check((const char*)z + x <= (const char*)a.data ||
                  (const char*)a.data + 8 * n <= (const char*)z,
                  "nd_alloc_extra: zone and data disjoint");
            // Fill both completely: an overlap with the control block would show in the state word
            // (and to ASan as an overflow).
            memset(z, 0xA5, (size_t)x);
            fill(&a, 3.0);
            check(nd_buffer_refs(a.buf) == 1 && nd_buffer_nbytes(a.buf) == 8 * n &&
                  holds(&a, 3.0) && z[x - 1] == 0xA5, "nd_alloc_extra: zone and data writable");
            nd_release(&a);
        }
    }

    // extra_bytes 0: no zone; extra may be NULL.
    n = 7;
    extra = (void*)&a;
    st = nd_alloc_extra(NULL, OTI_I64, 1, &n, NULL, ND_LAYOUT_C, ND_ALLOC_ZERO, 0, &extra, &a);
    check(st == OTI_OK && extra == NULL && nd_buffer_extra(a.buf) == NULL && a.dtype == OTI_I64 &&
          ((int64_t*)a.data)[6] == 0, "nd_alloc_extra: extra_bytes 0, ZERO");
    nd_release(&a);
    st = nd_alloc_extra(NULL, OTI_U8, 1, &n, NULL, ND_LAYOUT_C, 0, 32, NULL, &a);
    check(st == OTI_OK && nd_buffer_extra_bytes(a.buf) == 32, "nd_alloc_extra: extra pointer NULL");
    nd_release(&a);

    // Arguments.
    extra = (void*)&a;
    st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, 0, -1, &extra, &a);
    check(st == OTI_ERR_ARGUMENT && extra == NULL && is_empty(&a),
          "nd_alloc_extra: extra -1 -> ARGUMENT");
    oti_ctx_clear_error(NULL);
    extra = (void*)&a;
    st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, 0, ND_EXTRA_MAX_BYTES + 1, &extra, &a);
    check(st == OTI_ERR_ARGUMENT && extra == NULL && is_empty(&a) &&
          oti_ctx_last_error(NULL, &where, NULL) == OTI_ERR_ARGUMENT && where != NULL &&
          strcmp(where, "nd_alloc_extra") == 0, "nd_alloc_extra: too large -> ARGUMENT, recorded");
    st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, 7, 0, 16, &extra, &a);
    check(st == OTI_ERR_ARGUMENT && is_empty(&a), "nd_alloc_extra: bad layout -> ARGUMENT");
    st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, 0x40, 16, &extra, &a);
    check(st == OTI_ERR_ARGUMENT && is_empty(&a), "nd_alloc_extra: unknown flag -> ARGUMENT");
    st = nd_alloc_extra(NULL, 99, 1, &n, NULL, ND_LAYOUT_C, 0, 16, &extra, &a);
    check(st == OTI_ERR_DTYPE && is_empty(&a), "nd_alloc_extra: dtype -> DTYPE");
    oti_ctx_init(&ctx);
    ctx.struct_size = 3;
    st = nd_alloc_extra(&ctx, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, 0, 16, &extra, &a);
    check(st == OTI_ERR_ARGUMENT && extra == NULL && is_empty(&a), "nd_alloc_extra: bad context");

    // Strided (dense SoA block layout), F layout, rank 0.
    st = nd_alloc_extra(NULL, OTI_F64, 3, sh3, st3, ND_LAYOUT_F, 0, 48, &extra, &a);
    check(st == OTI_OK && a.strides[0] == 4 && a.strides[1] == 1 && a.strides[2] == 2 &&
          nd_buffer_nbytes(a.buf) == 96 && extra != NULL, "nd_alloc_extra: given strides");
    nd_release(&a);
    st = nd_alloc_extra(NULL, OTI_F64, 3, sh3, bad3, ND_LAYOUT_C, 0, 48, &extra, &a);
    check(st == OTI_ERR_LAYOUT && extra == NULL && is_empty(&a), "nd_alloc_extra: non-compact -> LAYOUT");
    st = nd_alloc_extra(NULL, OTI_F64, 3, sh3, NULL, ND_LAYOUT_F, 0, 48, &extra, &a);
    check(st == OTI_OK && a.strides[0] == 1 && a.strides[1] == 3 && a.strides[2] == 6 &&
          (a.flags & ND_F_CONTIG), "nd_alloc_extra: F layout");
    nd_release(&a);
    st = nd_alloc_extra(NULL, OTI_F64, 0, NULL, st3, ND_LAYOUT_C, 0, 48, &extra, &a);
    check(st == OTI_OK && a.ndim == 0 && nd_buffer_nbytes(a.buf) == 8, "nd_alloc_extra: rank 0");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The zone lives exactly as long as the buffer: through retained views and exports.
static void test_extra_lifetime(void){

    int64_t n = 10, i;
    ndarr_t a, v, e;
    unsigned char* z;
    void* extra;
    int st, ok;

    nd_init_empty(&a);
    nd_init_empty(&v);
    nd_init_empty(&e);

    st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, 0, 200, &extra, &a);
    check(st == OTI_OK, "lifetime: alloc");
    z = (unsigned char*)extra;
    for (i = 0; i < 200; i++){
        z[i] = (unsigned char)i;
    }
    st = nd_view_retain(&a, &v);
    check(st == OTI_OK && nd_buffer_extra(v.buf) == extra, "lifetime: a view sees the zone");
    st = nd_export(&a, 1, &e);
    check(st == OTI_OK, "lifetime: export of a heap array");
    nd_release(&a);
    nd_release(&v);
    z = (unsigned char*)nd_buffer_extra(e.buf);
    ok = (z == extra);
    for (i = 0; ok && i < 200; i++){
        ok = (z[i] == (unsigned char)i);
    }
    check(ok && nd_buffer_refs(e.buf) == 1 && nd_buffer_exports(e.buf) == 1,
          "lifetime: zone intact while the export lives");
    nd_release(&e);

    // nd_wrap buffers have no zone.
    {
        double mem[4] = {1, 2, 3, 4};
        ndarr_t d, w;
        nd_init_empty(&d);
        nd_init_empty(&w);
        nd_wrap_trusted(mem, OTI_F64, 1, &(int64_t){4}, NULL, 1, &d);
        st = nd_wrap(NULL, &d, mem, (int64_t)sizeof(mem), NULL, NULL, &w);
        check(st == OTI_OK && nd_buffer_extra(w.buf) == NULL && nd_buffer_extra_bytes(w.buf) == 0 &&
              !(nd_buffer_state(w.buf) & ND_STATE_SCRATCH), "nd_wrap: no zone, not scratch");
        nd_release(&w);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Growth moves the data, never the control block or the zone (inline -> heap, heap -> heap).
static void grow_case(int32_t flags, int64_t n0, const char* name){

    nd_buffer_t* b;
    unsigned char* z;
    ndarr_t a, v;
    void* extra;
    char msg[160];
    int64_t i;
    int st, ok;

    nd_init_empty(&a);
    nd_init_empty(&v);

    st = nd_alloc_extra(NULL, OTI_F64, 1, &n0, NULL, ND_LAYOUT_C, flags, 64, &extra, &a);
    snprintf(msg, sizeof(msg), "%s: alloc", name);
    check(st == OTI_OK, msg);
    if (st != OTI_OK){
        return;
    }
    b = a.buf;
    z = (unsigned char*)extra;
    memset(z, 0x5A, 64);
    fill(&a, 10.0);

    // A second reference blocks growth.
    nd_init_empty(&v);
    nd_view_retain(&a, &v);
    st = nd_grow(NULL, &a, 100000, 8 * n0);
    snprintf(msg, sizeof(msg), "%s: grow while viewed -> BUSY", name);
    check(st == OTI_ERR_BUSY && a.buf == b, msg);
    nd_release(&v);

    st = nd_grow(NULL, &a, 100000, 8 * n0);
    ok = (st == OTI_OK) && a.buf == b && nd_buffer_extra(a.buf) == extra && a.data == nd_buffer_base(b) &&
         nd_buffer_nbytes(b) == 100000 && ((uintptr_t)a.data % 64) == 0 && holds(&a, 10.0);
    for (i = 0; ok && i < 64; i++){
        ok = (z[i] == 0x5A);
    }
    snprintf(msg, sizeof(msg), "%s: grow to 100000 bytes keeps buffer, zone and data", name);
    check(ok, msg);
    ((double*)a.data)[12499] = 7.0;

    // Heap -> heap under the caller's lock.
    st = nd_buffer_lock_layout(a.buf);
    if (st == OTI_OK){
        st = nd_grow_locked(NULL, &a, 8 * n0 + 8, 8 * n0);
        nd_buffer_unlock_layout(a.buf);
    }
    snprintf(msg, sizeof(msg), "%s: shrink under the lock keeps buffer, zone and data", name);
    check(st == OTI_OK && a.buf == b && nd_buffer_extra(b) == extra && holds(&a, 10.0) &&
          nd_buffer_nbytes(b) == 8 * n0 + 8, msg);
    snprintf(msg, sizeof(msg), "%s: state after growth", name);
    check(nd_buffer_refs(b) == 1 && !(nd_buffer_state(b) & ND_STATE_GROWING) &&
          (nd_buffer_state(b) & ND_STATE_SCRATCH) == ((flags & ND_ALLOC_SCRATCH) ? ND_STATE_SCRATCH : 0),
          msg);
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_growth(void){

    grow_case(0, 24, "growth, inline");
    grow_case(0, 1000, "growth, heap data");
    grow_case(ND_ALLOC_SCRATCH, 24, "growth, scratch");
    check(nd_scratch_release() == OTI_OK, "growth: arena empty after the scratch case");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scratch arrays: state, retain, clone, lock, exports refused.
static void test_scratch_basic(void){

    int64_t sh3[3] = {3, 2, 2}, st3[3] = {4, 1, 2};
    uint64_t s;
    ndarr_t a, v, c, e;
    void* extra;
    int st;

    nd_init_empty(&a);
    nd_init_empty(&v);
    nd_init_empty(&c);
    nd_init_empty(&e);

    st = scratch_alloc(16, 0, &a);
    s = nd_buffer_state(a.buf);
    check(st == OTI_OK && (s & ND_STATE_SCRATCH) && (s & ND_STATE_OWNS) && (s & ND_STATE_GROWABLE) &&
          (s & ND_STATE_WRITEABLE) && nd_buffer_refs(a.buf) == 1 && (a.flags & ND_RETAINED) &&
          ((uintptr_t)a.data % 64) == 0, "scratch: state SCRATCH | OWNS | GROWABLE | WRITEABLE");
    check(nd_scratch_release() == OTI_ERR_BUSY, "scratch: nd_scratch_release while alive -> BUSY");

    nd_init_empty(&e);
    st = nd_export(&a, 0, &e);
    check(st == OTI_ERR_BUSY && is_empty(&e) && nd_buffer_refs(a.buf) == 1 &&
          nd_buffer_exports(a.buf) == 0, "scratch: nd_export -> BUSY, nothing changed");
    st = nd_view_retain(&a, &v);
    check(st == OTI_OK && nd_buffer_refs(a.buf) == 2, "scratch: nd_view_retain");
    st = nd_clone(&v, &c);
    check(st == OTI_OK && nd_buffer_refs(a.buf) == 3, "scratch: nd_clone");
    check(nd_buffer_lock_layout(a.buf) == OTI_ERR_BUSY, "scratch: lock refused while shared");
    nd_release(&v);
    nd_release(&c);
    check(nd_buffer_lock_layout(a.buf) == OTI_OK, "scratch: lock taken when unshared");
    nd_buffer_unlock_layout(a.buf);
    nd_release(&a);

    st = nd_alloc_strided(NULL, OTI_F64, 3, sh3, st3, ND_ALLOC_SCRATCH | ND_ALLOC_ZERO, &a);
    check(st == OTI_OK && (nd_buffer_state(a.buf) & ND_STATE_SCRATCH) && a.strides[0] == 4 &&
          ((double*)a.data)[11] == 0.0, "scratch: nd_alloc_strided");
    st = nd_alloc_extra(NULL, OTI_U8, 3, sh3, NULL, ND_LAYOUT_C, ND_ALLOC_SCRATCH, 40, &extra, &v);
    check(st == OTI_OK && extra != NULL && ((uintptr_t)extra % 16) == 0 &&
          (nd_buffer_state(v.buf) & ND_STATE_SCRATCH) && nd_buffer_extra_bytes(v.buf) == 40,
          "scratch: nd_alloc_extra with a zone");
    st = nd_export(&v, 1, &e);
    check(st == OTI_ERR_BUSY && is_empty(&e), "scratch: writeable export -> BUSY");
    nd_release(&v);
    nd_release(&a);
    check(nd_scratch_release() == OTI_OK, "scratch: nd_scratch_release when empty");
    check(nd_scratch_release() == OTI_OK, "scratch: nd_scratch_release twice");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// LIFO reuse: a released block is reused once the blocks above it are released.
static void test_scratch_lifo(void){

    int64_t bs = block_size(800, 0);
    ndarr_t a, b, c, d, e, f;
    nd_buffer_t* base_a;

    nd_init_empty(&a);
    nd_init_empty(&b);
    nd_init_empty(&c);
    nd_init_empty(&d);
    nd_init_empty(&e);
    nd_init_empty(&f);

    scratch_alloc(100, 0, &a);
    base_a = a.buf;
    scratch_alloc(100, 0, &b);
    scratch_alloc(100, 0, &c);
    check((char*)b.buf - (char*)a.buf == bs && (char*)c.buf - (char*)b.buf == bs,
          "lifo: consecutive blocks are adjacent");
    fill(&a, 1.0);
    fill(&b, 2.0);
    fill(&c, 3.0);
    nd_release(&b);
    scratch_alloc(100, 0, &d);
    check((char*)d.buf - (char*)c.buf == bs, "lifo: a released middle block is not reused yet");
    check(holds(&a, 1.0) && holds(&c, 3.0), "lifo: neighbours intact");
    nd_release(&d);
    nd_release(&c);
    scratch_alloc(100, 0, &e);
    check((char*)e.buf - (char*)a.buf == bs, "lifo: c, d and the released b popped together");
    nd_release(&a);
    check(nd_scratch_release() == OTI_ERR_BUSY, "lifo: e alive -> BUSY");
    nd_release(&e);
    scratch_alloc(3, 0, &f);
    check(f.buf == base_a, "lifo: an empty arena restarts at its base");
    nd_release(&f);
    check(nd_scratch_release() == OTI_OK, "lifo: arena freed");

    // A new arena after nd_scratch_release().
    check(scratch_alloc(5, ND_ALLOC_ZERO, &a) == OTI_OK && ((double*)a.data)[4] == 0.0,
          "lifo: arena re-created");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reuse returns dirty memory: ND_ALLOC_ZERO and the zone are still zero-filled.
static void test_scratch_reuse(void){

    nd_buffer_t* first;
    unsigned char* z;
    void* extra;
    ndarr_t a;
    int64_t n = 64, i;
    int ok;

    nd_init_empty(&a);

    nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, ND_ALLOC_SCRATCH, 32, &extra, &a);
    first = a.buf;
    fill(&a, 7.0);
    memset(extra, 0xFF, 32);
    nd_release(&a);
    nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, ND_ALLOC_SCRATCH | ND_ALLOC_ZERO, 32,
                   &extra, &a);
    z = (unsigned char*)extra;
    ok = (a.buf == first);
    for (i = 0; ok && i < 64; i++){
        ok = (((double*)a.data)[i] == 0.0);
    }
    for (i = 0; ok && i < 32; i++){
        ok = (z[i] == 0);
    }
    check(ok, "reuse: same block, data zeroed (ZERO), zone zeroed");
    nd_release(&a);
    check(nd_scratch_release() == OTI_OK, "reuse: arena freed");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A full arena overflows to the heap (still scratch), and grows when it is next empty.
static void test_scratch_overflow(void){

    int64_t bs = block_size(16000, 0), big = 40000;
    int order[10] = {2, 0, 9, 5, 1, 8, 3, 7, 4, 6};
    ndarr_t a[10], e, l;
    int k, ok = 1, adj = 1;

    nd_init_empty(&e);
    nd_init_empty(&l);

    for (k = 0; k < 10; k++){
        ok = ok && scratch_alloc(2000, 0, &a[k]) == OTI_OK &&
             (nd_buffer_state(a[k].buf) & ND_STATE_SCRATCH) && ((uintptr_t)a[k].data % 64) == 0;
        fill(&a[k], 100.0 * k);
    }
    check(ok, "overflow: ten 16 kB scratch arrays (the first arena is 16 kB)");

    nd_init_empty(&e);
    check(nd_export(&a[9], 0, &e) == OTI_ERR_BUSY,
          "overflow: a heap-fallback scratch array is not exported");
    for (k = 0; k < 10; k++){
        ok = ok && holds(&a[k], 100.0 * k);
    }
    check(ok, "overflow: every array intact");
    for (k = 0; k < 10; k++){
        nd_release(&a[order[k]]);
    }

    // The arena grew to what the ten wanted: four now sit side by side.
    for (k = 0; k < 4; k++){
        scratch_alloc(2000, 0, &a[k]);
    }
    for (k = 1; k < 4; k++){
        adj = adj && ((char*)a[k].buf - (char*)a[k - 1].buf == bs);
    }
    check(adj, "overflow: the arena grew when it emptied");
    for (k = 3; k >= 0; k--){
        nd_release(&a[k]);
    }

    // Larger than a scratch block: heap, still scratch; the arena holds nothing.
    check(scratch_alloc(big, 0, &l) == OTI_OK && (nd_buffer_state(l.buf) & ND_STATE_SCRATCH),
          "overflow: a 320 kB scratch array comes from the heap");
    fill(&l, 5.0);
    check(nd_scratch_release() == OTI_OK && holds(&l, 5.0),
          "overflow: nd_scratch_release while only heap scratch arrays live");
    check(nd_export(&l, 0, &e) == OTI_ERR_BUSY, "overflow: large scratch array not exported");
    nd_release(&l);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Growth is charged like allocation: a scratch buffer stays scratch, so growing it is checked against
// max_temp_bytes as well (checker W4 finding 1: temp cap 64, alloc cap 4096, a one-element scratch array
// grown to 1024 bytes was accepted). Both entry points; the old buffer and data survive a rejection.
static void test_budgets_growth(void){

    int64_t n1 = 1;
    const char* where = NULL;
    nd_buffer_t* b;
    void* base;
    oti_ctx ctx;
    ndarr_t a;
    int st;

    nd_init_empty(&a);
    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = 4096;
    ctx.max_temp_bytes = 64;

    st = nd_alloc(&ctx, OTI_F64, 1, &n1, ND_LAYOUT_C, ND_ALLOC_SCRATCH, &a);
    check(st == OTI_OK, "budgets, growth: scratch alloc of 8 bytes under a 64-byte temp cap");
    if (st != OTI_OK){
        return;
    }
    b = a.buf;
    base = a.data;
    ((double*)a.data)[0] = 3.5;

    st = nd_grow(&ctx, &a, 1024, 8);
    check(st == OTI_ERR_MEMORY && oti_ctx_last_error(&ctx, &where, NULL) == OTI_ERR_MEMORY &&
          strcmp(where, "nd_grow") == 0,
          "budgets, growth: nd_grow of scratch to 1024 > temp cap -> MEMORY");
    check(a.buf == b && a.data == base && nd_buffer_nbytes(b) == 8 && ((double*)a.data)[0] == 3.5 &&
          !(nd_buffer_state(b) & ND_STATE_GROWING) && nd_buffer_refs(b) == 1,
          "budgets, growth: rejected nd_grow keeps buffer, data and state");

    st = nd_buffer_lock_layout(a.buf);
    if (st == OTI_OK){
        st = nd_grow_locked(&ctx, &a, 1024, 8);
        nd_buffer_unlock_layout(a.buf);
    }
    check(st == OTI_ERR_MEMORY && oti_ctx_last_error(&ctx, &where, NULL) == OTI_ERR_MEMORY &&
          strcmp(where, "nd_grow_locked") == 0,
          "budgets, growth: nd_grow_locked of scratch to 1024 > temp cap -> MEMORY");
    check(a.buf == b && a.data == base && nd_buffer_nbytes(b) == 8 && ((double*)a.data)[0] == 3.5 &&
          !(nd_buffer_state(b) & ND_STATE_GROWING), "budgets, growth: rejected locked growth keeps all");

    st = nd_grow(&ctx, &a, 64, 8);
    check(st == OTI_OK && a.buf == b && nd_buffer_nbytes(b) == 64 && ((double*)a.data)[0] == 3.5 &&
          (nd_buffer_state(b) & ND_STATE_SCRATCH), "budgets, growth: scratch growth up to the temp cap");
    nd_release(&a);
    check(nd_scratch_release() == OTI_OK, "budgets, growth: arena empty");

    // A heap array is not limited by max_temp_bytes when growing, only by max_alloc_bytes.
    st = nd_alloc(&ctx, OTI_F64, 1, &n1, ND_LAYOUT_C, 0, &a);
    check(st == OTI_OK, "budgets, growth: heap alloc");
    if (st != OTI_OK){
        return;
    }
    b = a.buf;
    st = nd_grow(&ctx, &a, 1024, 8);
    check(st == OTI_OK && a.buf == b && nd_buffer_nbytes(b) == 1024,
          "budgets, growth: heap growth to 1024 ignores the temp cap");
    st = nd_grow(&ctx, &a, 8192, 8);
    check(st == OTI_ERR_MEMORY && a.buf == b && nd_buffer_nbytes(b) == 1024,
          "budgets, growth: heap growth past max_alloc_bytes -> MEMORY, buffer kept");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Budgets: max_alloc_bytes for every array, max_temp_bytes also for scratch arrays.
static void test_budgets(void){

    int64_t n200 = 200, n100 = 100;
    const char* where = NULL;
    oti_ctx ctx;
    ndarr_t a;
    int st;

    nd_init_empty(&a);

    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = 1000;
    st = nd_alloc(&ctx, OTI_F64, 1, &n200, ND_LAYOUT_C, 0, &a);
    check(st == OTI_ERR_MEMORY && is_empty(&a), "budgets: max_alloc_bytes, heap");
    st = nd_alloc(&ctx, OTI_F64, 1, &n200, ND_LAYOUT_C, ND_ALLOC_SCRATCH, &a);
    check(st == OTI_ERR_MEMORY && is_empty(&a) &&
          oti_ctx_last_error(&ctx, &where, NULL) == OTI_ERR_MEMORY &&
          strcmp(where, "nd_alloc") == 0, "budgets: max_alloc_bytes, scratch, recorded");

    oti_ctx_init(&ctx);
    ctx.max_temp_bytes = 1000;
    st = nd_alloc(&ctx, OTI_F64, 1, &n200, ND_LAYOUT_C, 0, &a);
    check(st == OTI_OK, "budgets: max_temp_bytes does not limit a heap array");
    nd_release(&a);
    st = nd_alloc_extra(&ctx, OTI_F64, 1, &n200, NULL, ND_LAYOUT_C, ND_ALLOC_SCRATCH, 16, NULL, &a);
    check(st == OTI_ERR_MEMORY && is_empty(&a), "budgets: max_temp_bytes limits a scratch array");
    st = nd_alloc(&ctx, OTI_F64, 1, &n100, ND_LAYOUT_C, ND_ALLOC_SCRATCH, &a);
    check(st == OTI_OK, "budgets: a scratch array under max_temp_bytes");
    nd_release(&a);
    check(nd_scratch_release() == OTI_OK, "budgets: arena empty");

    test_budgets_growth();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Failure injection at every allocation of each path: MEMORY, empty output, NULL zone, no residue.
static void test_fail_alloc(void){

    static const int64_t ns[] = {4, 4, 3000, 3000, 40000};
    static const int32_t fl[] = {0, ND_ALLOC_SCRATCH, 0, ND_ALLOC_SCRATCH, ND_ALLOC_SCRATCH};
    void* extra;
    ndarr_t a;
    int64_t k, n;
    size_t c;
    int st, ok;

    nd_init_empty(&a);

    for (c = 0; c < sizeof(ns) / sizeof(ns[0]); c++){
        ok = 1;
        n = ns[c];
        for (k = 1; k < 10; k++){
            nd_test_fail_alloc(k);
            extra = (void*)&a;
            st = nd_alloc_extra(NULL, OTI_F64, 1, &n, NULL, ND_LAYOUT_C, fl[c], 24, &extra, &a);
            nd_test_fail_alloc(0);
            if (st == OTI_OK){
                ok = ok && extra != NULL && (k >= 2);
                nd_release(&a);
                break;
            }
            ok = ok && st == OTI_ERR_MEMORY && extra == NULL && is_empty(&a);
        }
        check(ok && k < 10, "fail_alloc: every injected failure -> MEMORY, then OK");
        check(nd_scratch_release() == OTI_OK, "fail_alloc: no scratch block left behind");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One thread's workload: nested and out-of-order scratch arrays with thread-specific values, verified
// before every release. Returns the number of failures.
static void* thread_work(void* arg){

    int64_t id = (int64_t)(intptr_t)arg, it, sz;
    uint64_t r = 0x9E3779B97F4A7C15ULL ^ (uint64_t)(id * 7919 + 1);
    ndarr_t live[8];
    double val[8];
    int nlive = 0, j, bad = 0;

    for (it = 0; it < 4000; it++){
        r ^= r << 13;
        r ^= r >> 7;
        r ^= r << 17;
        if (nlive < 8 && (nlive == 0 || (r & 3) != 0)){
            sz = 1 + (int64_t)((r >> 8) % 700);
            if (scratch_alloc(sz, 0, &live[nlive]) != OTI_OK){
                bad++;
                continue;
            }
            val[nlive] = (double)(id * 1000000 + it);
            fill(&live[nlive], val[nlive]);
            nlive++;
        } else {
            j = (int)((r >> 20) % (uint64_t)nlive);    // any live array, not only the top one
            bad += !holds(&live[j], val[j]);
            nd_release(&live[j]);
            live[j] = live[nlive - 1];
            val[j] = val[nlive - 1];
            nd_init_empty(&live[nlive - 1]);
            nlive--;
        }
    }
    while (nlive > 0){
        nlive--;
        bad += !holds(&live[nlive], val[nlive]);
        nd_release(&live[nlive]);
    }
    if (id == 0 && nd_scratch_release() != OTI_OK){
        bad++;
    }

    // The other threads end with their arena allocated: the thread-exit destructor frees it.
    return (void*)(intptr_t)bad;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_threads(void){

    pthread_t th[4];
    void* ret;
    int64_t k;
    int bad = 0, started = 0;

    for (k = 0; k < 4; k++){
        if (pthread_create(&th[k], NULL, thread_work, (void*)(intptr_t)k) == 0){
            started++;
        }
    }
    for (k = 0; k < started; k++){
        pthread_join(th[k], &ret);
        bad += (int)(intptr_t)ret;
    }
    check(started == 4 && bad == 0, "threads: four threads, nested out-of-order scratch arrays intact");
    ret = thread_work((void*)(intptr_t)0);
    check(ret == NULL, "threads: the same workload on the main thread");

}
// -------------------------------------------------------------------------------------------------------


#ifdef TA_ASAN
// *******************************************************************************************************
// Forks a child that reads a released scratch block (mode 0: the top one; 1: one in the middle); ASan
// must abort it. Returns 1 when the child failed (the expected outcome).
static int stale_child(int mode){

    pid_t pid = fork();
    int status = 0;

    if (pid == 0){
        ndarr_t a, b;
        volatile double x;
        int fd = open("/dev/null", O_WRONLY);
        if (fd >= 0){
            dup2(fd, 2);
        }
        scratch_alloc(16, 0, &a);
        scratch_alloc(16, 0, &b);
        {
            double* p = (mode == 0) ? (double*)b.data : (double*)a.data;
            if (mode == 0){
                nd_release(&b);
            } else {
                nd_release(&a);
            }
            x = p[3];
            (void)x;
        }
        _exit(0);
    }
    if (pid < 0){
        return 0;
    }
    waitpid(pid, &status, 0);

    return !(WIFEXITED(status) && WEXITSTATUS(status) == 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_asan_stale(void){

    check(stale_child(0), "asan: a read of a released top scratch block is reported");
    check(stale_child(1), "asan: a read of a released middle scratch block is reported");

}
// -------------------------------------------------------------------------------------------------------
#endif


// *******************************************************************************************************
int main(void){

    test_inline();
    test_extra();
    test_extra_lifetime();
    test_growth();
    test_scratch_basic();
    test_scratch_lifo();
    test_scratch_reuse();
    test_scratch_overflow();
    test_budgets();
    test_fail_alloc();
    test_threads();
#ifdef TA_ASAN
    test_asan_stale();
#endif
    check(nd_scratch_release() == OTI_OK, "end: the main thread's arena is freed");

    printf("test_real_ndarray_alloc: %d passed, %d failed\n", n_passed, n_failed);

    return n_failed == 0 ? 0 : 1;

}
// -------------------------------------------------------------------------------------------------------
