/* Tests of the ndarray core (include/oti/real/ndarray/{structures,buffer,create}.h): descriptors, the
 * state word, ownership, the exactly-once callback, growth, the validator, overlap, the import format
 * table, the oti_view mapping and the last error of failing calls.
 *
 * Written from PLAN-ndarray-contracts.md sections 1, 2, 3.1-3.2, 4 and 6 (test matrix rows 1.1, 1.3,
 * 1.4, 1.5, 1.6, 2.1, 2.2, 3.1-3.2, 4, 6), independently of the implementation files. Oracles are
 * hand-derived tables (each expected value is the contract's rule applied by hand, or NumPy 2's
 * contiguity rule), coordinate loops written in this file, and randomized descriptors checked against
 * their defining equations. Failure injection uses nd_test_fail_alloc(): at every allocation of
 * nd_alloc, nd_wrap, nd_import, nd_copy and nd_grow the status is OTI_ERR_MEMORY, the output is empty,
 * the callback has run exactly once, and the injection never leaves a leak (the lead runs leaks and
 * ASan on this file).
 *
 * The state word's refs / exports overflow is reached by writing the first field of the control block
 * (contracts 1.2: `uint64_t state` comes first): the only way to reach 2^32 references in a test.
 * The TSan race test (contracts 1.3 races) is compiled always but runs only when this file is built
 * with -fsanitize=thread. Not testable from here: debug-build assertions (OTI_ND_DEBUG aborts), and
 * "view, grow, use the stale view: ASan reports it" (it would abort the run). */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // pthreads under -std=c99 on Linux (contracts S23)
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>
#include <pthread.h>
#include <oti/core/exec.h>
#include <oti/real/ndarray/structures.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>
#include <oti/real/ndarray/elementwise.h>
#include <oti/real/ndarray/views.h>
#include <oti/real/ndarray/compat_darr.h>
#include <oti/real/array/base.h>

#if defined(__SANITIZE_THREAD__)
#define TEST_TSAN 1
#elif defined(__has_feature)
#if __has_feature(thread_sanitizer)
#define TEST_TSAN 1
#endif
#endif
#ifndef TEST_TSAN
#define TEST_TSAN 0
#endif

#define EMPTY_FLAGS (ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE)

static int n_failed = 0;
static uint64_t g_rng_state;


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        printf("passed: %s\n", name);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void rng_seed(uint64_t seed){

    g_rng_state = (seed != 0) ? seed : 0x9E3779B97F4A7C15ULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t rng_next(void){

    uint64_t x = g_rng_state;

    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    g_rng_state = x;

    return x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Uniform integer in [0, n).
static int64_t rng_int(int64_t n){

    return (int64_t)(rng_next() % (uint64_t)n);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when the descriptor is the nd_init_empty() state (contracts 1.4).
static int is_empty_state(const ndarr_t* a){

    return a->data == NULL && a->buf == NULL && a->ndim == 1 && a->shape[0] == 0 &&
           a->dtype == OTI_F64 && a->flags == EMPTY_FLAGS && a->reserved == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A scribbled descriptor, so that a function that must overwrite it is caught leaving stale fields.
static void scribble(ndarr_t* a){

    memset(a, 0x5A, sizeof(*a));
    a->flags = 0;
    a->buf = NULL;
    a->data = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates a C-layout F64 array of the given shape and fills element (i0, ..., ik) with the C-order
// linear index of the coordinates.
static int make_iota(int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* a){

    int st = nd_alloc(NULL, OTI_F64, ndim, shape, layout, 0, a);
    int64_t n = 1, lin;
    int64_t idx[OTI_ND_MAXDIM];
    int32_t k;

    if (st != OTI_OK){
        return st;
    }
    for (k = 0; k < ndim; k++){
        n *= shape[k];
    }
    for (lin = 0; lin < n; lin++){
        int64_t rem = lin, off = 0;
        for (k = ndim - 1; k >= 0; k--){
            idx[k] = rem % shape[k];
            rem /= shape[k];
            off += idx[k] * a->strides[k];
        }
        ((double*)a->data)[off] = (double)lin;
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Release counter used as the release_ctx of the callbacks.
typedef struct {
    int      count;
    ndarr_t* chain;       // another retained array released from inside the callback
    int      chain_count; // callbacks of the chained buffer observed so far
} cb_t;


// *******************************************************************************************************
static void cb_count(void* p){

    cb_t* c = (cb_t*)p;

    c->count++;
    if (c->chain != NULL){
        nd_release(c->chain);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Address `elems` doubles from `base`, possibly outside the object (computed on integers, so that the
// test itself has no out-of-bounds pointer arithmetic).
static double* addr_at(double* base, int64_t elems){

    return (double*)((uintptr_t)base + (uintptr_t)(elems * (int64_t)sizeof(double)));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Hand-built descriptor over a given memory block (no control block).
static void make_desc(ndarr_t* a, void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                      const int64_t* strides, int32_t flags){

    int32_t k;

    memset(a, 0, sizeof(*a));
    a->data = data;
    a->dtype = dtype;
    a->ndim = ndim;
    a->flags = flags;
    for (k = 0; k < ndim && k < OTI_ND_MAXDIM; k++){
        a->shape[k] = shape[k];
        a->strides[k] = strides ? strides[k] : 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 1.1 Descriptors
// =======================================================================================================

// *******************************************************************************************************
static void test_descriptor_basics(void){

    ndarr_t a = {0};
    int64_t shape[3] = {2, 3, 4};

    scribble(&a);
    nd_init_empty(&a);
    check(is_empty_state(&a), "nd_init_empty: shape (0,), F64, C|F|WRITEABLE, data NULL, buf NULL");
    check(nd_size(&a) == 0, "nd_size of the empty array is 0");
    nd_release(&a);
    check(is_empty_state(&a), "nd_release of an empty array is a no-op");
    nd_release(NULL);
    check(1, "nd_release(NULL) is allowed");

    check(sizeof(ndarr_t) == 544, "sizeof(ndarr_t) == 544");
    check(OTI_ND_MAXDIM == 32, "OTI_ND_MAXDIM == 32");
    check(OTI_F64 == 1 && OTI_U8 == 2 && OTI_I64 == 3, "dtype codes 1, 2, 3");
    check(ND_C_CONTIG == 1 && ND_F_CONTIG == 2 && ND_WRITEABLE == 4 && ND_RETAINED == 8 &&
          ND_EXPORTED == 16, "flag bits");
    check(nd_itemsize(OTI_F64) == 8 && nd_itemsize(OTI_I64) == 8 && nd_itemsize(OTI_U8) == 1 &&
          nd_itemsize(0) == 0 && nd_itemsize(9) == 0, "nd_itemsize");

    check(nd_alloc(NULL, OTI_F64, 3, shape, ND_LAYOUT_C, 0, &a) == OTI_OK, "alloc (2,3,4) C");
    check(nd_size(&a) == 24, "nd_size (2,3,4) == 24");
    check(a.strides[0] == 12 && a.strides[1] == 4 && a.strides[2] == 1, "C strides (12, 4, 1)");
    check(a.flags == (ND_C_CONTIG | ND_WRITEABLE | ND_RETAINED),
            "C array flags: C | WRITEABLE | RETAINED");
    nd_release(&a);
    check(nd_alloc(NULL, OTI_F64, 3, shape, ND_LAYOUT_F, 0, &a) == OTI_OK, "alloc (2,3,4) F");
    check(a.strides[0] == 1 && a.strides[1] == 2 && a.strides[2] == 6, "F strides (1, 2, 6)");
    check(a.flags == (ND_F_CONTIG | ND_WRITEABLE | ND_RETAINED),
            "F array flags: F | WRITEABLE | RETAINED");
    nd_release(&a);

    check(nd_alloc(NULL, OTI_U8, 1, shape, ND_LAYOUT_C, 0, &a) == OTI_OK && a.dtype == OTI_U8 &&
          nd_u8(&a) == (uint8_t*)a.data, "alloc U8 and nd_u8");
    nd_release(&a);
    check(nd_alloc(NULL, OTI_I64, 2, shape, ND_LAYOUT_C, 0, &a) == OTI_OK && a.dtype == OTI_I64 &&
          nd_i64(&a) == (int64_t*)a.data, "alloc I64 and nd_i64");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int32_t ndim;
    int64_t shape[4];
    int64_t strides[4];
    int     expect_c;
    int     expect_f;
    const char* name;
} contig_case_t;


// *******************************************************************************************************
// NumPy 2 contiguity (axes of extent 1 ignored; at most one element is both C and F). Each expected
// value is NumPy's flags.c_contiguous / f_contiguous for the same shape and strides (in elements).
static void test_contiguity_flags(void){

    static const contig_case_t cases[] = {
        {0, {0}, {0}, 1, 1, "rank 0"},
        {1, {5}, {1}, 1, 1, "1-D contiguous"},
        {1, {5}, {2}, 0, 0, "1-D stride 2"},
        {1, {5}, {-1}, 0, 0, "1-D reversed"},
        {1, {1}, {7}, 1, 1, "1-D one element, any stride"},
        {1, {0}, {3}, 1, 1, "1-D empty"},
        {2, {2, 3}, {3, 1}, 1, 0, "2-D C"},
        {2, {2, 3}, {1, 2}, 0, 1, "2-D F"},
        {2, {2, 3}, {6, 2}, 0, 0, "2-D strided"},
        {2, {2, 3}, {4, 1}, 0, 0, "2-D padded rows"},
        {2, {1, 3}, {100, 1}, 1, 1, "(1,3): extent-1 axis ignored, both"},
        {2, {3, 1}, {1, 100}, 1, 1, "(3,1): extent-1 axis ignored, both"},
        {2, {1, 1}, {5, 9}, 1, 1, "(1,1): both"},
        {2, {0, 3}, {3, 1}, 1, 1, "(0,3): empty, both"},
        {2, {3, 3}, {3, -1}, 0, 0, "negative stride"},
        {3, {2, 1, 3}, {3, 77, 1}, 1, 0, "(2,1,3) C with a stray stride on the extent-1 axis"},
        {3, {2, 1, 3}, {1, 77, 2}, 0, 1, "(2,1,3) F with a stray stride on the extent-1 axis"},
        {3, {2, 3, 4}, {12, 4, 1}, 1, 0, "3-D C"},
        {3, {2, 3, 4}, {1, 2, 6}, 0, 1, "3-D F"},
        {3, {2, 3, 4}, {12, 1, 3}, 0, 0, "3-D permuted"},
        {2, {4, 3}, {0, 1}, 0, 0, "zero stride on extent > 1"},
        {2, {1, 3}, {0, 1}, 1, 1, "zero stride on an extent-1 axis"}
    };
    static double mem[256];
    const int n = (int)(sizeof(cases) / sizeof(cases[0]));
    int i, ok = 1, ok_update = 1;
    char msg[160];

    for (i = 0; i < n; i++){

        ndarr_t a = {0};
        int st;
        int c, f;

        st = nd_wrap_trusted(mem + 128, OTI_F64, cases[i].ndim, cases[i].shape, cases[i].strides, 1, &a);
        if (st != OTI_OK){
            // zero strides and negative strides inside the memory: all of these fit mem[0..255].
            snprintf(msg, sizeof(msg), "contiguity case \"%s\": wrap_trusted status %d", cases[i].name,
                    st);
            check(0, msg);
            ok = 0;
            continue;
        }
        c = (a.flags & ND_C_CONTIG) != 0;
        f = (a.flags & ND_F_CONTIG) != 0;
        if (c != cases[i].expect_c || f != cases[i].expect_f){
            fprintf(stderr, "  wrap_trusted \"%s\": C=%d F=%d, expected C=%d F=%d\n", cases[i].name, c, f,
                    cases[i].expect_c, cases[i].expect_f);
            ok = 0;
        }

        // nd_update_flags recomputes both bits and keeps the others.
        a.flags = ND_WRITEABLE | ND_C_CONTIG | ND_F_CONTIG;
        if (cases[i].expect_c == 0 && cases[i].expect_f == 0){
            a.flags = ND_WRITEABLE | ND_C_CONTIG;
        }
        nd_update_flags(&a);
        c = (a.flags & ND_C_CONTIG) != 0;
        f = (a.flags & ND_F_CONTIG) != 0;
        if (c != cases[i].expect_c || f != cases[i].expect_f || !(a.flags & ND_WRITEABLE)){
            fprintf(stderr, "  update_flags \"%s\": C=%d F=%d flags=0x%x\n", cases[i].name, c, f,
                    a.flags);
            ok_update = 0;
        }

    }
    check(ok, "contiguity flags after nd_wrap_trusted match NumPy 2 for every case");
    check(ok_update, "nd_update_flags recomputes C / F and keeps the other flags");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 1.3 State word and 1.4 ownership
// =======================================================================================================

// *******************************************************************************************************
static void test_buffer_alloc_state(void){

    ndarr_t a = {0}, z = {0};
    int64_t shape[2] = {5, 7};
    int64_t zshape[1] = {0};
    uint64_t s;

    check(nd_alloc(NULL, OTI_F64, 2, shape, ND_LAYOUT_C, 0, &a) == OTI_OK, "alloc (5,7)");
    check(a.buf != NULL && (a.flags & ND_RETAINED), "alloc: retained, has a control block");
    s = nd_buffer_state(a.buf);
    check((s & ND_STATE_REFS_MASK) == 1 && nd_buffer_refs(a.buf) == 1, "alloc: refs 1");
    check((s & ND_STATE_EXPORTS_MASK) == 0 && nd_buffer_exports(a.buf) == 0, "alloc: exports 0");
    check((s & ND_STATE_OWNS) && (s & ND_STATE_WRITEABLE), "alloc: OWNS and WRITEABLE");
    check((s & ND_STATE_GROWABLE) && !(s & ND_STATE_GROWING),
          "alloc: GROWABLE without a flag (S25), not GROWING");
    check((s >> 60) == 0, "alloc: reserved bits 60..63 zero");
    check(nd_buffer_base(a.buf) == a.data, "alloc: base == data of the new array");
    check(nd_buffer_nbytes(a.buf) >= 35 * 8, "alloc: nbytes covers the array");
    check(((uintptr_t)a.data % 64) == 0, "alloc: 64-byte aligned");
    nd_release(&a);
    check(is_empty_state(&a), "release resets to the empty state");

    check(nd_alloc(NULL, OTI_F64, 2, shape, ND_LAYOUT_C, ND_ALLOC_GROWABLE, &a) == OTI_OK &&
          (nd_buffer_state(a.buf) & ND_STATE_GROWABLE) && (nd_buffer_state(a.buf) & ND_STATE_OWNS),
          "alloc with ND_ALLOC_GROWABLE: OWNS | GROWABLE");
    nd_release(&a);

    // Zero-size arrays still have a non-NULL data pointer and a buffer of at least one element.
    check(nd_alloc(NULL, OTI_F64, 1, zshape, ND_LAYOUT_C, 0, &z) == OTI_OK, "alloc of shape (0,)");
    check(z.data != NULL && nd_size(&z) == 0 && nd_buffer_nbytes(z.buf) >= 8,
          "alloc (0,): data != NULL, buffer at least one element");
    nd_release(&z);
    check(nd_alloc(NULL, OTI_U8, 0, NULL, ND_LAYOUT_C, 0, &z) == OTI_OK && z.ndim == 0 &&
            nd_size(&z) == 1,
          "alloc rank 0: one element");
    check(z.flags == (ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE | ND_RETAINED), "rank 0 flags: C | F");
    nd_release(&z);

    // ND_ALLOC_ZERO zero-fills.
    {
        int64_t big[1] = {1000};
        int64_t i;
        int allzero = 1;
        check(nd_alloc(NULL, OTI_F64, 1, big, ND_LAYOUT_C, ND_ALLOC_ZERO, &a) == OTI_OK, "alloc zeroed");
        for (i = 0; i < 1000; i++){
            allzero = allzero && (((double*)a.data)[i] == 0.0);
        }
        check(allzero, "ND_ALLOC_ZERO: every element zero");
        nd_release(&a);
        check(nd_alloc(NULL, OTI_U8, 1, big, ND_LAYOUT_C, ND_ALLOC_ZERO, &a) == OTI_OK,
                "alloc U8 zeroed");
        allzero = 1;
        for (i = 0; i < 1000; i++){
            allzero = allzero && (((uint8_t*)a.data)[i] == 0);
        }
        check(allzero, "ND_ALLOC_ZERO: U8 bytes zero");
        nd_release(&a);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_alloc_failures(void){

    ndarr_t a = {0};
    int64_t shape[2] = {3, 4};
    int64_t neg[2] = {3, -1};
    int64_t huge[2] = {INT64_C(1) << 40, INT64_C(1) << 40};
    int64_t big[1] = {1000};
    int64_t shape33[33];
    int64_t shape32[32];
    oti_ctx ctx;
    int i;

    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, 2, neg, ND_LAYOUT_C, 0, &a) == OTI_ERR_SHAPE && is_empty_state(&a),
          "alloc: negative extent -> SHAPE, res empty");
    scribble(&a);
    for (i = 0; i < 33; i++){
        shape33[i] = 1;
    }
    check(nd_alloc(NULL, OTI_F64, 33, shape33, ND_LAYOUT_C, 0, &a) == OTI_ERR_SHAPE && is_empty_state(&a),
          "alloc: ndim 33 -> SHAPE, res empty");
    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, -1, shape, ND_LAYOUT_C, 0, &a) == OTI_ERR_SHAPE && is_empty_state(&a),
          "alloc: ndim -1 -> SHAPE");
    for (i = 0; i < 32; i++){
        shape32[i] = 1;
    }
    check(nd_alloc(NULL, OTI_F64, 32, shape32, ND_LAYOUT_C, 0, &a) == OTI_OK && a.ndim == 32 &&
          nd_size(&a) == 1, "alloc: ndim 32 accepted");
    nd_release(&a);
    scribble(&a);
    check(nd_alloc(NULL, 0, 2, shape, ND_LAYOUT_C, 0, &a) == OTI_ERR_DTYPE && is_empty_state(&a),
          "alloc: dtype 0 -> DTYPE");
    scribble(&a);
    check(nd_alloc(NULL, 4, 2, shape, ND_LAYOUT_C, 0, &a) == OTI_ERR_DTYPE && is_empty_state(&a),
          "alloc: dtype 4 -> DTYPE");
    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, 2, shape, 9, 0, &a) == OTI_ERR_ARGUMENT && is_empty_state(&a),
          "alloc: bad layout -> ARGUMENT");
    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, 2, shape, ND_LAYOUT_A, 0, &a) == OTI_ERR_ARGUMENT && is_empty_state(&a),
          "alloc: ND_LAYOUT_A is not an allocation layout -> ARGUMENT");
    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, 2, shape, ND_LAYOUT_C, 0x80, &a) == OTI_ERR_ARGUMENT &&
            is_empty_state(&a),
          "alloc: bad alloc flags -> ARGUMENT");
    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, 2, NULL, ND_LAYOUT_C, 0, &a) == OTI_ERR_ARGUMENT,
          "alloc: NULL shape with ndim 2 -> ARGUMENT");
    scribble(&a);
    check(nd_alloc(NULL, OTI_F64, 2, huge, ND_LAYOUT_C, 0, &a) == OTI_ERR_SIZE && is_empty_state(&a),
          "alloc: element count overflow (2^80) -> SIZE, no allocation");
    {
        int64_t h1[1] = {INT64_C(1) << 61};
        scribble(&a);
        check(nd_alloc(NULL, OTI_F64, 1, h1, ND_LAYOUT_C, 0, &a) == OTI_ERR_SIZE && is_empty_state(&a),
              "alloc: byte count overflow (2^61 doubles) -> SIZE");
    }

    // Budget: a cap checked before allocating.
    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = 4000;
    scribble(&a);
    check(nd_alloc(&ctx, OTI_F64, 1, big, ND_LAYOUT_C, 0, &a) == OTI_ERR_MEMORY && is_empty_state(&a),
          "alloc: 8000 bytes over a 4000-byte budget -> MEMORY, res empty");
    check(nd_alloc(&ctx, OTI_F64, 1, big, ND_LAYOUT_C, 0, &a) == OTI_ERR_MEMORY,
            "alloc over budget again");
    big[0] = 500;
    check(nd_alloc(&ctx, OTI_F64, 1, big, ND_LAYOUT_C, 0, &a) == OTI_OK,
            "alloc: exactly the budget fits");
    nd_release(&a);
    big[0] = 501;
    check(nd_alloc(&ctx, OTI_F64, 1, big, ND_LAYOUT_C, 0, &a) == OTI_ERR_MEMORY, "alloc: one byte over");

    // Failure injection at every allocation of nd_alloc.
    {
        int k, saw_fail = 0, finished = 0;
        for (k = 1; k < 20 && !finished; k++){
            int st;
            scribble(&a);
            nd_test_fail_alloc(k);
            st = nd_alloc(NULL, OTI_F64, 2, shape, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
            nd_test_fail_alloc(0);
            if (st == OTI_OK){
                nd_release(&a);
                finished = 1;
            } else {
                saw_fail++;
                if (st != OTI_ERR_MEMORY || !is_empty_state(&a)){
                    check(0, "nd_alloc fail_alloc: MEMORY and empty res at every allocation");
                    saw_fail = -1000;
                }
            }
        }
        check(saw_fail >= 1 && finished,
                "nd_alloc fail_alloc: at least one allocation fails, then success");
        check(saw_fail >= 0, "nd_alloc fail_alloc: MEMORY and empty res at every allocation");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes bits into the first field of the control block (contracts 1.2: the state word comes first).
static void poke_state(nd_buffer_t* b, uint64_t v){

    memcpy((void*)b, &v, sizeof(v));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_state_transitions(void){

    ndarr_t a = {0}, v = {0}, c = {0}, e = {0}, e2 = {0}, t = {0};
    int64_t shape[1] = {8};
    uint64_t s0;

    nd_alloc(NULL, OTI_F64, 1, shape, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);

    // retain
    scribble(&v);
    check(nd_view_retain(&a, &v) == OTI_OK, "view_retain: OK");
    check((v.flags & ND_RETAINED) && !(v.flags & ND_EXPORTED) && v.buf == a.buf && v.data == a.data,
          "view_retain: retained, same buffer and data");
    check(nd_buffer_refs(a.buf) == 2 && nd_buffer_exports(a.buf) == 0, "retain: refs 2, exports 0");
    check(v.shape[0] == 8 && v.strides[0] == 1 && v.dtype == OTI_F64 && (v.flags & ND_WRITEABLE),
          "view_retain: same shape, strides, dtype, writeability");

    // clone of a retained descriptor adds a reference
    scribble(&c);
    check(nd_clone(&a, &c) == OTI_OK && (c.flags & ND_RETAINED) && nd_buffer_refs(a.buf) == 3,
          "clone of a retained descriptor: retained, refs 3");

    // lock refused with extra references
    check(nd_buffer_lock_layout(a.buf) == OTI_ERR_BUSY, "lock: BUSY with refs 3");
    nd_release(&c);
    check(nd_buffer_refs(a.buf) == 2, "release: refs 2");
    check(nd_buffer_lock_layout(a.buf) == OTI_ERR_BUSY, "lock: BUSY with refs 2");
    nd_release(&v);
    check(is_empty_state(&v) && nd_buffer_refs(a.buf) == 1, "release: back to refs 1");

    // clone of a temporary is a temporary and takes no reference
    t = a;
    t.flags &= ~ND_RETAINED;
    scribble(&c);
    check(nd_clone(&t, &c) == OTI_OK && !(c.flags & ND_RETAINED) && c.buf == a.buf &&
          nd_buffer_refs(a.buf) == 1, "clone of a temporary: temporary, refs unchanged");
    nd_release(&c);
    check(nd_buffer_refs(a.buf) == 1, "release of a temporary does not touch the refs");
    // view_retain of a temporary adds a reference
    check(nd_view_retain(&t, &v) == OTI_OK && nd_buffer_refs(a.buf) == 2,
            "view_retain of a temporary: refs 2");
    nd_release(&v);

    // export
    scribble(&e);
    check(nd_export(&a, 0, &e) == OTI_OK, "export (read-only): OK");
    check((e.flags & ND_RETAINED) && (e.flags & ND_EXPORTED) && !(e.flags & ND_WRITEABLE),
          "export: RETAINED | EXPORTED, read-only");
    check(nd_buffer_refs(a.buf) == 2 && nd_buffer_exports(a.buf) == 1, "export: refs 2, exports 1");
    check(nd_buffer_lock_layout(a.buf) == OTI_ERR_BUSY, "lock: BUSY with one export");
    scribble(&e2);
    check(nd_export(&a, 1, &e2) == OTI_OK && (e2.flags & ND_WRITEABLE) && (e2.flags & ND_EXPORTED) &&
          nd_buffer_refs(a.buf) == 3 && nd_buffer_exports(a.buf) == 2,
                  "writeable export: refs 3, exports 2");
    // clone of an exported source is retained and not exported
    scribble(&c);
    check(nd_clone(&e, &c) == OTI_OK && (c.flags & ND_RETAINED) && !(c.flags & ND_EXPORTED) &&
          nd_buffer_refs(a.buf) == 4 && nd_buffer_exports(a.buf) == 2,
          "clone of an exported source: retained, not exported (refs 4, exports 2)");
    nd_release(&c);
    nd_release(&e2);
    check(nd_buffer_refs(a.buf) == 2 && nd_buffer_exports(a.buf) == 1, "unexport: refs 2, exports 1");
    nd_release(&e);
    check(nd_buffer_refs(a.buf) == 1 && nd_buffer_exports(a.buf) == 0, "unexport: refs 1, exports 0");
    check(is_empty_state(&e), "release of an export resets it");

    // lock / unlock
    s0 = nd_buffer_state(a.buf);
    check(nd_buffer_lock_layout(a.buf) == OTI_OK, "lock: OK at refs 1, exports 0");
    check((nd_buffer_state(a.buf) & ND_STATE_GROWING) != 0, "lock: GROWING set");
    check(nd_buffer_lock_layout(a.buf) == OTI_ERR_BUSY, "lock: not reentrant -> BUSY");
    scribble(&v);
    check(nd_view_retain(&a, &v) == OTI_ERR_BUSY && is_empty_state(&v),
            "retain while GROWING -> BUSY, res empty");
    scribble(&e);
    check(nd_export(&a, 0, &e) == OTI_ERR_BUSY && is_empty_state(&e),
            "export while GROWING -> BUSY, res empty");
    scribble(&c);
    check(nd_clone(&a, &c) == OTI_ERR_BUSY && is_empty_state(&c),
            "clone of retained while GROWING -> BUSY");
    check(nd_buffer_refs(a.buf) == 1, "failed retain / export leave refs unchanged");
    nd_buffer_unlock_layout(a.buf);
    check(nd_buffer_state(a.buf) == s0, "unlock: state back to the value before the lock");
    check(nd_view_retain(&a, &v) == OTI_OK, "retain works again after unlock");
    nd_release(&v);

    // argument errors
    scribble(&v);
    t = a;
    t.flags &= ~ND_RETAINED;
    t.buf = NULL;
    check(nd_view_retain(&t, &v) == OTI_ERR_ARGUMENT && is_empty_state(&v),
          "view_retain with buf NULL -> ARGUMENT, res empty");
    check(nd_export(&t, 0, &v) == OTI_ERR_ARGUMENT && is_empty_state(&v),
          "export with buf NULL -> ARGUMENT, res empty");

    // nd_move
    {
        ndarr_t m = {0};
        scribble(&m);
        nd_move(&a, &m);
        check(is_empty_state(&a) && (m.flags & ND_RETAINED) && m.buf != NULL &&
                nd_buffer_refs(m.buf) == 1,
              "nd_move: dst holds the array (refs unchanged), src empty");
        nd_move(&m, &a);
        check(is_empty_state(&m) && (a.flags & ND_RETAINED) && nd_buffer_refs(a.buf) == 1,
              "nd_move back");
    }

    // refs overflow: inject the maximum (the state word is the first field of the control block).
    {
        uint64_t saved = nd_buffer_state(a.buf);
        poke_state(a.buf, (saved & ~ND_STATE_REFS_MASK) | ND_STATE_REFS_MASK);
        scribble(&v);
        check(nd_view_retain(&a, &v) == OTI_ERR_SIZE && is_empty_state(&v),
                "retain at refs 2^32-1 -> SIZE");
        check(nd_export(&a, 0, &v) == OTI_ERR_SIZE, "export at refs 2^32-1 -> SIZE");
        check(nd_clone(&a, &v) == OTI_ERR_SIZE, "clone of retained at refs 2^32-1 -> SIZE");
        check((nd_buffer_state(a.buf) & ND_STATE_REFS_MASK) == ND_STATE_REFS_MASK,
              "failed retains leave the state word unchanged");
        poke_state(a.buf, saved);

        // exports at their maximum with room in refs
        poke_state(a.buf, (saved & ~(ND_STATE_REFS_MASK | ND_STATE_EXPORTS_MASK)) |
                          (ND_STATE_EXPORTS_MASK) | ((ND_STATE_EXPORTS_MASK >> 32) + 3));
        scribble(&v);
        check(nd_export(&a, 0, &v) == OTI_ERR_SIZE && is_empty_state(&v),
                "export at exports 2^24-1 -> SIZE");
        check(nd_view_retain(&a, &v) == OTI_OK, "plain retain still works at exports max");
        poke_state(a.buf, saved);
        v.flags &= ~ND_RETAINED;       // that reference was injected away
        nd_init_empty(&v);
    }
    check(nd_buffer_state(a.buf) == (nd_buffer_state(a.buf) & ~ND_STATE_GROWING),
            "state sane after injections");

    nd_release(&a);

    // A read-only wrapped array refuses a writeable export.
    {
        double mem[4] = {1, 2, 3, 4};
        ndarr_t d = {0}, w = {0}, x = {0};
        int64_t sh[1] = {4};
        int64_t st[1] = {1};
        make_desc(&d, mem, OTI_F64, 1, sh, st, 0);
        check(nd_wrap(NULL, &d, mem, sizeof(mem), NULL, NULL, &w) == OTI_OK, "wrap read-only");
        check(!(w.flags & ND_WRITEABLE) && !(nd_buffer_state(w.buf) & ND_STATE_WRITEABLE),
              "wrap read-only: descriptor and buffer not writeable");
        scribble(&x);
        check(nd_export(&w, 1, &x) == OTI_ERR_READONLY && is_empty_state(&x),
              "writeable export of a read-only array -> READONLY, res empty");
        check(nd_export(&w, 0, &x) == OTI_OK && !(x.flags & ND_WRITEABLE),
                "read-only export of it is fine");
        nd_release(&x);
        nd_release(&w);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 1.4 / 1.5 wrap, import callbacks
// =======================================================================================================

// *******************************************************************************************************
static void test_wrap_success_and_callback(void){

    static double mem[16];
    ndarr_t d = {0}, w = {0}, w2 = {0};
    int64_t shape[2] = {4, 4};
    int64_t strides[2] = {4, 1};
    cb_t cb = {0, NULL, 0};

    make_desc(&d, mem, OTI_F64, 2, shape, strides, ND_WRITEABLE);
    scribble(&w);
    check(nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &cb, &w) == OTI_OK, "wrap: OK");
    check(w.data == mem && w.ndim == 2 && w.shape[0] == 4 && w.shape[1] == 4 && w.strides[0] == 4 &&
          w.strides[1] == 1 && w.dtype == OTI_F64, "wrap: data, shape, strides, dtype kept");
    check((w.flags & ND_RETAINED) && (w.flags & ND_WRITEABLE) && (w.flags & ND_C_CONTIG) &&
          !(w.flags & ND_EXPORTED), "wrap: retained, writeable, C contiguous");
    check(w.buf != NULL && nd_buffer_refs(w.buf) == 1, "wrap: refs 1");
    {
        uint64_t s = nd_buffer_state(w.buf);
        check(!(s & ND_STATE_OWNS) && !(s & ND_STATE_GROWABLE) && (s & ND_STATE_WRITEABLE),
              "wrap: not OWNS, not GROWABLE, WRITEABLE");
    }
    check(nd_buffer_base(w.buf) == (const void*)mem && nd_buffer_nbytes(w.buf) == (int64_t)sizeof(mem),
          "wrap: base and nbytes are the given span");
    check(cb.count == 0, "wrap: callback not run on success yet");

    check(nd_view_retain(&w, &w2) == OTI_OK && cb.count == 0, "retain a wrapped array");
    nd_release(&w);
    check(cb.count == 0, "callback: not run while another reference lives (parent released first)");
    nd_release(&w2);
    check(cb.count == 1, "callback: run exactly once at the last release");
    nd_release(&w2);
    check(cb.count == 1, "callback: releasing the empty descriptor again does nothing");

    // unknown span and NULL callback
    check(nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &w) == OTI_OK, "wrap with unknown span, no callback");
    check(nd_buffer_nbytes(w.buf) == -1, "wrap: unknown span nbytes == -1");
    nd_release(&w);

    // the callback of a chained buffer: releasing another buffer from inside the callback
    {
        cb_t inner = {0, NULL, 0}, outer = {0, NULL, 0};
        ndarr_t in_arr = {0}, out_arr = {0};
        make_desc(&d, mem, OTI_F64, 2, shape, strides, ND_WRITEABLE);
        check(nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &inner, &in_arr) == OTI_OK,
                "chain: inner wrap");
        outer.chain = &in_arr;
        check(nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &outer, &out_arr) == OTI_OK,
                "chain: outer wrap");
        nd_release(&out_arr);
        check(outer.count == 1 && inner.count == 1 && is_empty_state(&in_arr),
              "callback may release another buffer (both callbacks exactly once)");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_wrap_failures_callback_once(void){

    static double mem[32];
    ndarr_t d = {0}, w = {0};
    int64_t shape[1] = {8};
    int64_t strides[1] = {1};
    int64_t neg_shape[1] = {-2};
    int64_t huge_shape[1] = {INT64_C(1) << 62};
    int64_t sh33[33];
    cb_t cb;
    int i, st;

    // negative extent
    cb.count = 0; cb.chain = NULL;
    make_desc(&d, mem, OTI_F64, 1, neg_shape, strides, ND_WRITEABLE);
    scribble(&w);
    st = nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &cb, &w);
    check(st == OTI_ERR_SHAPE && cb.count == 1 && is_empty_state(&w),
          "wrap: negative extent -> SHAPE, callback exactly once, res empty");

    // ndim 33
    for (i = 0; i < 33; i++){
        sh33[i] = 1;
    }
    cb.count = 0;
    make_desc(&d, mem, OTI_F64, 1, shape, strides, ND_WRITEABLE);
    d.ndim = 33;
    for (i = 0; i < 33; i++){
        d.shape[i % 32] = 1;
    }
    scribble(&w);
    st = nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &cb, &w);
    check(st == OTI_ERR_SHAPE && cb.count == 1 && is_empty_state(&w),
          "wrap: ndim 33 -> SHAPE, callback exactly once");

    // bad dtype
    cb.count = 0;
    make_desc(&d, mem, 7, 1, shape, strides, ND_WRITEABLE);
    st = nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &cb, &w);
    check(st == OTI_ERR_DTYPE && cb.count == 1 && is_empty_state(&w),
            "wrap: bad dtype -> DTYPE, callback once");

    // overflowing metadata
    cb.count = 0;
    make_desc(&d, mem, OTI_F64, 1, huge_shape, strides, ND_WRITEABLE);
    st = nd_wrap(NULL, &d, NULL, -1, cb_count, &cb, &w);
    check(st == OTI_ERR_SIZE && cb.count == 1 && is_empty_state(&w),
            "wrap: 2^62 doubles -> SIZE, callback once");

    // misaligned
    cb.count = 0;
    make_desc(&d, (char*)mem + 1, OTI_F64, 1, shape, strides, ND_WRITEABLE);
    st = nd_wrap(NULL, &d, NULL, -1, cb_count, &cb, &w);
    check(st == OTI_ERR_LAYOUT && cb.count == 1 && is_empty_state(&w),
            "wrap: misaligned -> LAYOUT, callback once");

    // span violation (span 8 doubles, array of 9)
    cb.count = 0;
    shape[0] = 9;
    make_desc(&d, mem, OTI_F64, 1, shape, strides, ND_WRITEABLE);
    st = nd_wrap(NULL, &d, mem, 8 * 8, cb_count, &cb, &w);
    check(st == OTI_ERR_LAYOUT && cb.count == 1 && is_empty_state(&w),
          "wrap: span violation -> LAYOUT, callback once");
    shape[0] = 8;

    // NULL data, non-empty
    cb.count = 0;
    make_desc(&d, NULL, OTI_F64, 1, shape, strides, ND_WRITEABLE);
    st = nd_wrap(NULL, &d, NULL, -1, cb_count, &cb, &w);
    check(st == OTI_ERR_ARGUMENT && cb.count == 1 && is_empty_state(&w),
          "wrap: NULL data of a non-empty array -> ARGUMENT, callback once");

    // an empty array may have NULL data and wraps fine
    cb.count = 0;
    shape[0] = 0;
    make_desc(&d, NULL, OTI_F64, 1, shape, strides, ND_WRITEABLE);
    st = nd_wrap(NULL, &d, NULL, -1, cb_count, &cb, &w);
    check(st == OTI_OK && cb.count == 0, "wrap: empty array with NULL data is accepted");
    nd_release(&w);
    check(cb.count == 1, "wrap: callback runs at release of an empty wrapped array");
    shape[0] = 8;

    // failure injection in nd_wrap: the control block allocation; callback exactly once
    {
        int k, saw_fail = 0, finished = 0, ok = 1;
        for (k = 1; k < 10 && !finished; k++){
            cb.count = 0;
            make_desc(&d, mem, OTI_F64, 1, shape, strides, ND_WRITEABLE);
            scribble(&w);
            nd_test_fail_alloc(k);
            st = nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &cb, &w);
            nd_test_fail_alloc(0);
            if (st == OTI_OK){
                ok = ok && cb.count == 0;
                nd_release(&w);
                ok = ok && cb.count == 1;
                finished = 1;
            } else {
                saw_fail++;
                ok = ok && (st == OTI_ERR_MEMORY) && cb.count == 1 && is_empty_state(&w);
            }
        }
        check(saw_fail >= 1 && finished, "nd_wrap fail_alloc: the control block allocation can fail");
        check(ok,
                "nd_wrap fail_alloc: MEMORY, callback once, res empty; success runs it at release");
    }

    // wrap_trusted
    {
        ndarr_t t = {0};
        int64_t sh[2] = {3, 4};
        int64_t sh_bad[2] = {3, -1};
        scribble(&t);
        check(nd_wrap_trusted(mem, OTI_F64, 2, sh, NULL, 1, &t) == OTI_OK, "wrap_trusted: OK");
        check(t.buf == NULL && !(t.flags & ND_RETAINED) && (t.flags & ND_WRITEABLE) &&
              (t.flags & ND_C_CONTIG) && t.strides[0] == 4 && t.strides[1] == 1 && t.data == mem,
              "wrap_trusted: temporary, buf NULL, C strides for NULL strides");
        nd_release(&t);
        check(is_empty_state(&t), "release of a trusted temporary resets it");
        check(nd_wrap_trusted(mem, OTI_F64, 2, sh, NULL, 0, &t) == OTI_OK && !(t.flags & ND_WRITEABLE),
              "wrap_trusted: read-only");
        scribble(&t);
        check(nd_wrap_trusted(mem, OTI_F64, 2, sh_bad, NULL, 1, &t) == OTI_ERR_SHAPE &&
                is_empty_state(&t),
              "wrap_trusted: negative extent -> SHAPE, out empty");
        check(nd_wrap_trusted(mem, 0, 2, sh, NULL, 1, &t) == OTI_ERR_DTYPE && is_empty_state(&t),
              "wrap_trusted: dtype 0 -> DTYPE");
        check(nd_wrap_trusted((char*)mem + 4, OTI_F64, 2, sh, NULL, 1, &t) == OTI_ERR_LAYOUT &&
                is_empty_state(&t),
              "wrap_trusted: misaligned data -> LAYOUT");
        check(nd_wrap_trusted(mem, OTI_U8, 2, sh, NULL, 1, &t) == OTI_OK,
                "wrap_trusted: U8 needs no alignment");
        check(nd_wrap_trusted((char*)mem + 1, OTI_U8, 2, sh, NULL, 1, &t) == OTI_OK,
                "wrap_trusted: U8 odd address");
        {
            int64_t huge[1] = {INT64_C(1) << 62};
            check(nd_wrap_trusted(mem, OTI_F64, 1, huge, NULL, 1, &t) == OTI_ERR_SIZE &&
                    is_empty_state(&t),
                  "wrap_trusted: 2^62 doubles -> SIZE");
        }
        check(nd_wrap_trusted(mem, OTI_F64, 33, sh33, NULL, 1, &t) == OTI_ERR_SHAPE,
                "wrap_trusted: ndim 33 -> SHAPE");
        {
            int64_t zs[2] = {0, 5};
            check(nd_wrap_trusted(NULL, OTI_F64, 2, zs, NULL, 1, &t) == OTI_OK && nd_size(&t) == 0 &&
                  t.data == NULL, "wrap_trusted: empty array with NULL data");
        }
        {
            int64_t one[1] = {5};
            scribble(&t);
            check(nd_wrap_trusted(NULL, OTI_F64, 1, one, NULL, 1, &t) == OTI_ERR_ARGUMENT &&
                    is_empty_state(&t),
                  "wrap_trusted: NULL data, non-empty -> ARGUMENT");
        }
        {
            // a trusted temporary cannot be pinned: retain / export need a control block
            ndarr_t keep = {0};
            nd_wrap_trusted(mem, OTI_F64, 2, sh, NULL, 1, &t);
            check(nd_view_retain(&t, &keep) == OTI_ERR_ARGUMENT,
                    "view_retain of a trusted temporary -> ARGUMENT");
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 1.6 Growth
// =======================================================================================================

// *******************************************************************************************************
static void test_growth(void){

    ndarr_t root = {0}, v = {0}, e = {0}, w = {0};
    int64_t shape[1] = {4};
    int64_t i;
    oti_ctx ctx;
    double* before;
    int ok;
    cb_t cb = {0, NULL, 0};

    check(nd_alloc(NULL, OTI_F64, 1, shape, ND_LAYOUT_C, ND_ALLOC_GROWABLE, &root) == OTI_OK,
            "growth: alloc");
    for (i = 0; i < 4; i++){
        ((double*)root.data)[i] = 10.0 + (double)i;
    }

    // BUSY with a view, with an export, with a lock held; nothing changes
    nd_view_retain(&root, &v);
    before = (double*)root.data;
    check(nd_grow(NULL, &root, 4096, 32) == OTI_ERR_BUSY && root.data == before,
            "grow: BUSY with a view");
    nd_release(&v);
    nd_export(&root, 0, &e);
    check(nd_grow(NULL, &root, 4096, 32) == OTI_ERR_BUSY && root.data == before,
            "grow: BUSY with an export");
    nd_release(&e);
    check(nd_buffer_lock_layout(root.buf) == OTI_OK, "growth: take the lock");
    check(nd_grow(NULL, &root, 4096, 32) == OTI_ERR_BUSY && root.data == before,
          "nd_grow under a held lock -> BUSY (not reentrant)");
    nd_buffer_unlock_layout(root.buf);

    // successful growth: keep_bytes copied, same offset, shape and strides untouched
    check(nd_grow(NULL, &root, 4096, 32) == OTI_OK, "grow: OK on an unshared growable root");
    ok = 1;
    for (i = 0; i < 4; i++){
        ok = ok && (((double*)root.data)[i] == 10.0 + (double)i);
    }
    check(ok, "grow: the first keep_bytes bytes are preserved");
    check(root.shape[0] == 4 && root.strides[0] == 1 && root.ndim == 1,
            "grow: shape and strides untouched");
    check(nd_buffer_nbytes(root.buf) >= 4096, "grow: the buffer spans at least the new size");
    check(root.data == nd_buffer_base(root.buf), "grow: data at the same offset (0) from the new base");
    check(!(nd_buffer_state(root.buf) & ND_STATE_GROWING) && nd_buffer_refs(root.buf) == 1,
          "grow: lock released, refs 1");

    // data at a non-zero offset keeps its offset
    root.data = (char*)root.data + 16;
    root.shape[0] = 2;
    ((double*)root.data)[0] = 77.0;
    ((double*)root.data)[1] = 78.0;
    check(nd_grow(NULL, &root, 8192, 64) == OTI_OK, "grow: OK with an offset root");
    check((const char*)root.data - (const char*)nd_buffer_base(root.buf) == 16,
            "grow: data - base stays 16 bytes");
    check(((double*)root.data)[0] == 77.0 && ((double*)root.data)[1] == 78.0,
            "grow: offset values preserved");
    root.data = (char*)root.data - 16;
    root.shape[0] = 4;

    // grow_locked under a held lock: succeeds and keeps the lock
    check(nd_buffer_lock_layout(root.buf) == OTI_OK, "grow_locked: take the lock");
    check(nd_grow_locked(NULL, &root, 16384, 64) == OTI_OK, "nd_grow_locked: OK under a held lock");
    check((nd_buffer_state(root.buf) & ND_STATE_GROWING) != 0, "nd_grow_locked: the lock stays held");
    check(nd_buffer_nbytes(root.buf) >= 16384, "nd_grow_locked: new size");
    scribble(&v);
    check(nd_view_retain(&root, &v) == OTI_ERR_BUSY, "retain while the lock is held -> BUSY");
    nd_buffer_unlock_layout(root.buf);
    check(!(nd_buffer_state(root.buf) & ND_STATE_GROWING), "grow_locked: unlock afterwards");

    // budget: MEMORY leaves the buffer unchanged
    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = 1000;
    before = (double*)root.data;
    ((double*)root.data)[0] = 123.0;
    check(nd_grow(&ctx, &root, 100000, 32) == OTI_ERR_MEMORY, "grow: over the budget -> MEMORY");
    check(root.data == before && ((double*)root.data)[0] == 123.0 &&
            nd_buffer_nbytes(root.buf) >= 16384 &&
          !(nd_buffer_state(root.buf) & ND_STATE_GROWING),
                  "grow over budget: buffer unchanged, lock released");
    // failure injection in nd_grow
    {
        int k, saw = 0, done = 0, okk = 1;
        for (k = 1; k < 10 && !done; k++){
            before = (double*)root.data;
            ((double*)root.data)[1] = 5.5 + k;
            nd_test_fail_alloc(k);
            i = nd_grow(NULL, &root, 32768 + 64 * k, 64);
            nd_test_fail_alloc(0);
            if (i == OTI_OK){
                done = 1;
                okk = okk && ((double*)root.data)[1] == 5.5 + k;
            } else {
                saw++;
                okk = okk && (i == OTI_ERR_MEMORY) && root.data == before &&
                        ((double*)root.data)[1] == 5.5 + k &&
                      !(nd_buffer_state(root.buf) & ND_STATE_GROWING);
            }
        }
        check(saw >= 1 && done && okk, "nd_grow fail_alloc: MEMORY, buffer and lock state unchanged");
    }
    nd_release(&root);

    // S25: every library buffer is growable, also without ND_ALLOC_GROWABLE
    nd_alloc(NULL, OTI_F64, 1, shape, ND_LAYOUT_C, 0, &root);
    check(nd_grow(NULL, &root, 4096, 8) == OTI_OK && !(nd_buffer_state(root.buf) & ND_STATE_GROWING),
          "grow: a buffer allocated without ND_ALLOC_GROWABLE grows (S25), lock released");
    nd_release(&root);

    // borrowed (wrapped) buffer: BUSY
    {
        static double mem[8];
        ndarr_t d = {0};
        int64_t sh[1] = {8};
        int64_t st[1] = {1};
        make_desc(&d, mem, OTI_F64, 1, sh, st, ND_WRITEABLE);
        nd_wrap(NULL, &d, mem, sizeof(mem), cb_count, &cb, &w);
        check(nd_grow(NULL, &w, 4096, 8) == OTI_ERR_BUSY && w.data == mem,
                "grow: a borrowed buffer -> BUSY");
        nd_release(&w);
        check(cb.count == 1, "borrowed buffer: callback ran once at release");
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 2.1 Validator
// =======================================================================================================

// *******************************************************************************************************
static void test_validate_table(void){

    static double mem[64];
    ndarr_t a = {0};
    int64_t sh1[1] = {8};
    int64_t st1[1] = {1};
    int64_t sh2[2] = {3, 4};
    int64_t st2[2] = {4, 1};
    int64_t neg[2] = {3, -1};
    int64_t big62[1] = {INT64_C(1) << 62};
    int64_t big32[2] = {INT64_C(1) << 32, INT64_C(1) << 32};
    int64_t st_big[1] = {INT64_C(1) << 62};
    int64_t sh3[1] = {3};
    int64_t zero0[2] = {0, 3};
    int64_t zst[2] = {0, 0};
    int64_t sh33[33], st33[33];
    int i;
    const void* lo = mem;
    const void* hi = mem + 64;

    for (i = 0; i < 33; i++){
        sh33[i] = 1;
        st33[i] = 1;
    }

    make_desc(&a, mem, OTI_F64, 0, NULL, NULL, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK, "validate: rank 0 accepted");
    check(nd_validate(&a, lo, hi, ND_V_SPAN | ND_V_OUTPUT) == OTI_OK, "validate: rank 0 as an output");
    make_desc(&a, mem, OTI_F64, 32, sh33, st33, ND_WRITEABLE);
    check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_OK, "validate: rank 32 accepted");
    make_desc(&a, mem, OTI_F64, 33, sh33, st33, ND_WRITEABLE);
    a.ndim = 33;
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SHAPE, "validate: rank 33 -> SHAPE");
    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE);
    a.ndim = -1;
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SHAPE, "validate: rank -1 -> SHAPE");

    make_desc(&a, mem, OTI_F64, 2, neg, st2, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SHAPE, "validate: negative extent -> SHAPE");
    make_desc(&a, mem, 0, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_DTYPE, "validate: dtype 0 -> DTYPE");
    make_desc(&a, mem, 4, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_DTYPE, "validate: dtype 4 -> DTYPE");
    make_desc(&a, mem, -1, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_DTYPE, "validate: dtype -1 -> DTYPE");

    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE);
    a.reserved = 1;
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_ARGUMENT, "validate: reserved != 0 -> ARGUMENT");
    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE | 0x20);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_ARGUMENT, "validate: flag bit 5 -> ARGUMENT");
    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE | (int32_t)0x80000000);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_ARGUMENT, "validate: flag bit 31 -> ARGUMENT");
    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE | ND_EXPORTED);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_ARGUMENT,
            "validate: EXPORTED without RETAINED -> ARGUMENT");
    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE | ND_EXPORTED | ND_RETAINED);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK, "validate: EXPORTED | RETAINED is well formed");

    // overflow: SIZE, without allocating
    make_desc(&a, mem, OTI_F64, 1, big62, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SIZE,
            "validate: 2^62 doubles (bytes overflow) -> SIZE");
    make_desc(&a, mem, OTI_U8, 1, big62, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK || nd_validate(&a, NULL, NULL, 0) == OTI_ERR_LAYOUT,
          "validate: 2^62 bytes of U8 fits int64 (no SIZE)");
    make_desc(&a, mem, OTI_F64, 2, big32, st2, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SIZE, "validate: element count 2^64 -> SIZE");
    make_desc(&a, mem, OTI_F64, 1, sh3, st_big, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SIZE,
            "validate: huge stride (offset overflow) -> SIZE");
    {
        int64_t nst[1] = {-(INT64_C(1) << 62)};
        make_desc(&a, mem, OTI_F64, 1, sh3, nst, ND_WRITEABLE);
        check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SIZE, "validate: huge negative stride -> SIZE");
    }
    make_desc(&a, NULL, OTI_F64, 1, big62, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SIZE,
            "validate: overflow is reported before NULL data (step 4 < 5)");

    // step 5
    make_desc(&a, NULL, OTI_F64, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_ARGUMENT,
            "validate: NULL data of a non-empty array -> ARGUMENT");
    make_desc(&a, NULL, OTI_F64, 2, zero0, st2, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK, "validate: empty array with NULL data accepted");
    make_desc(&a, (char*)mem + 1, OTI_F64, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_LAYOUT, "validate: misaligned data -> LAYOUT");
    make_desc(&a, (char*)mem + 4, OTI_I64, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_LAYOUT, "validate: misaligned I64 -> LAYOUT");
    make_desc(&a, (char*)mem + 3, OTI_U8, 1, sh1, st1, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK, "validate: U8 at any address");
    make_desc(&a, (char*)mem + 1, OTI_F64, 2, zero0, st2, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK,
            "validate: alignment of an empty array is not checked");

    // span, both ends, with negative strides. mem has 64 doubles.
    make_desc(&a, mem, OTI_F64, 1, sh1, st1, ND_WRITEABLE);
    a.shape[0] = 64;
    check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_OK, "validate span: exactly the allocation");
    a.shape[0] = 65;
    check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_ERR_LAYOUT,
            "validate span: one element past the end -> LAYOUT");
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK,
            "validate: the span is not checked without ND_V_SPAN");
    {
        int64_t s3[1] = {3};
        int64_t m2[1] = {-2};
        int64_t p2[1] = {2};
        // negative stride: lowest element at data - 4 elements
        make_desc(&a, mem + 4, OTI_F64, 1, s3, m2, ND_WRITEABLE);
        check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_OK,
                "validate span: negative stride touching the start");
        make_desc(&a, mem + 3, OTI_F64, 1, s3, m2, ND_WRITEABLE);
        check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_ERR_LAYOUT,
              "validate span: negative stride below the start -> LAYOUT");
        // positive stride: highest element at data + 4 elements, one past it is data + 5
        make_desc(&a, mem + 59, OTI_F64, 1, s3, p2, ND_WRITEABLE);
        check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_OK,
                "validate span: positive stride touching the end");
        make_desc(&a, mem + 60, OTI_F64, 1, s3, p2, ND_WRITEABLE);
        check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_ERR_LAYOUT,
              "validate span: positive stride past the end -> LAYOUT");
        // an empty array has no span to violate
        make_desc(&a, addr_at(mem, 1000), OTI_F64, 2, zero0, st2, ND_WRITEABLE);
        check(nd_validate(&a, lo, hi, ND_V_SPAN) == OTI_OK,
                "validate span: empty array skips the span check");
    }

    // ND_V_OUTPUT
    make_desc(&a, mem, OTI_F64, 2, sh2, st2, 0);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK, "validate: read-only input fine");
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_ERR_READONLY,
            "validate output: read-only -> READONLY");
    make_desc(&a, mem, OTI_F64, 2, sh2, st2, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_OK, "validate output: writeable, no overlap");
    make_desc(&a, mem, OTI_F64, 2, sh2, zst, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_ERR_LAYOUT,
            "validate output: zero strides -> LAYOUT");
    check(nd_validate(&a, NULL, NULL, 0) == OTI_OK, "validate: zero strides fine as an input");
    make_desc(&a, mem, OTI_F64, 2, zero0, zst, 0);
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_ERR_READONLY,
          "validate output: an EMPTY read-only output -> READONLY ([cM4])");
    make_desc(&a, mem, OTI_F64, 2, zero0, zst, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_OK,
          "validate output: an empty writeable output skips the overlap test");

    // multi-defect order
    make_desc(&a, mem, OTI_F64, 2, neg, st2, ND_WRITEABLE | 0x40);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SHAPE,
            "validate order: bad flags + negative extent -> SHAPE");
    make_desc(&a, mem, OTI_F64, 1, sh3, st_big, ND_WRITEABLE | 0x40);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_ARGUMENT,
            "validate order: bad flags + overflow -> ARGUMENT");
    make_desc(&a, mem, 0, 2, neg, st2, ND_WRITEABLE);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_SHAPE,
            "validate order: bad dtype + negative extent -> SHAPE");
    make_desc(&a, mem, 0, 1, sh1, st1, ND_WRITEABLE | 0x40);
    check(nd_validate(&a, NULL, NULL, 0) == OTI_ERR_DTYPE,
            "validate order: bad dtype + bad flags -> DTYPE");
    make_desc(&a, NULL, OTI_F64, 1, sh1, st1, 0);
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_ERR_ARGUMENT,
          "validate order: NULL data + read-only output -> ARGUMENT (step 5 before 6)");
    make_desc(&a, (char*)mem + 1, OTI_F64, 1, sh1, st1, 0);
    check(nd_validate(&a, NULL, NULL, ND_V_OUTPUT) == OTI_ERR_LAYOUT,
          "validate order: misaligned + read-only output -> LAYOUT");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Random well-formed descriptors inside a known allocation are accepted; moving the data pointer one
// element past either end of the accessed span makes validation with ND_V_SPAN fail.
static void test_validate_randomized(void){

    static double mem[4096];
    int iter, ok_accept = 1, ok_reject_hi = 1, ok_reject_lo = 1, ok_extent = 1;
    const void* lo = mem;
    const void* hi = mem + 4096;

    rng_seed(424242);

    for (iter = 0; iter < 3000; iter++){

        ndarr_t a = {0};
        int32_t nd = (int32_t)rng_int(6);
        int64_t shape[8], strides[8];
        int64_t elo = 0, ehi = 0;
        int32_t k;
        int64_t n = 1;
        int64_t off;
        int empty;

        for (k = 0; k < nd; k++){
            shape[k] = rng_int(5);
            if (rng_int(8) == 0){
                shape[k] = 0;
            }
            strides[k] = (int64_t)(rng_int(41)) - 20;       // negative, zero and positive strides
            n *= shape[k];
        }
        empty = (n == 0);
        for (k = 0; k < nd; k++){
            if (shape[k] > 0){
                int64_t r = (shape[k] - 1) * strides[k];
                if (r < 0){
                    elo += r;
                } else {
                    ehi += r;
                }
            }
        }
        if (empty){
            continue;
        }
        // place data so that [data + elo, data + ehi] sits inside [0, 4095], at a random offset
        off = (-elo) + rng_int(4096 - (ehi - elo));
        make_desc(&a, mem + off, OTI_F64, nd, shape, strides, ND_WRITEABLE);
        if (nd_validate(&a, lo, hi, ND_V_SPAN) != OTI_OK){
            ok_accept = 0;
        }
        {
            int64_t xlo = 0, xhi = 0;
            if (nd_extent(&a, &xlo, &xhi) != OTI_OK || xlo != elo || xhi != ehi){
                ok_extent = 0;
            }
        }
        // one element beyond the top: data shifted up so that the top element leaves the allocation
        a.data = addr_at(mem, 4095 - ehi + 1);
        if (nd_validate(&a, lo, hi, ND_V_SPAN) != OTI_ERR_LAYOUT){
            ok_reject_hi = 0;
        }
        a.data = addr_at(mem, -elo - 1);
        if (nd_validate(&a, lo, hi, ND_V_SPAN) != OTI_ERR_LAYOUT){
            ok_reject_lo = 0;
        }

    }
    check(ok_accept, "validate: 3000 random well-formed descriptors accepted (with span)");
    check(ok_extent, "nd_extent: lo and hi equal the sums over negative / positive strides");
    check(ok_reject_hi, "validate: one element past the top of the allocation -> LAYOUT (random)");
    check(ok_reject_lo, "validate: one element below the start of the allocation -> LAYOUT (random)");

    {
        ndarr_t a = {0};
        int64_t z[2] = {0, 3};
        int64_t zs[2] = {3, 1};
        int64_t lo_, hi_;
        make_desc(&a, mem, OTI_F64, 2, z, zs, ND_WRITEABLE);
        check(nd_extent(&a, &lo_, &hi_) == OTI_ERR_SHAPE, "nd_extent of an empty array -> SHAPE");
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 3.1 - 3.2 Overlap
// =======================================================================================================

// *******************************************************************************************************
// Random slice / transpose / reversal / diagonal of a C-contiguous 3-D array: the descriptor is built
// from the strides by hand, and must be accepted by nd_internal_overlap (contracts 3.1: "accepts every
// slice, transpose, reversal and diagonal of a contiguous array").
static void test_overlap_accepts_views(void){

    static double mem[8 * 9 * 10];
    int iter, ok = 1, ok_inj = 1;

    rng_seed(777);

    for (iter = 0; iter < 4000; iter++){

        int64_t dims[3];
        int64_t base[3];
        int64_t shape[4], strides[4];
        int32_t perm[3];
        int32_t k;
        int32_t nd = 3;
        ndarr_t a = {0};
        int64_t off = 0;

        dims[0] = 1 + rng_int(8);
        dims[1] = 1 + rng_int(9);
        dims[2] = 1 + rng_int(10);
        base[0] = dims[1] * dims[2];
        base[1] = dims[2];
        base[2] = 1;

        // random permutation
        perm[0] = 0; perm[1] = 1; perm[2] = 2;
        for (k = 2; k > 0; k--){
            int32_t j = (int32_t)rng_int(k + 1);
            int32_t t = perm[k]; perm[k] = perm[j]; perm[j] = t;
        }
        for (k = 0; k < 3; k++){
            int32_t ax = perm[k];
            int64_t step = 1 + rng_int(3);
            int64_t start = rng_int(dims[ax]);
            int64_t len;
            if (rng_int(2)){
                // forward slice
                len = 1 + (dims[ax] - 1 - start) / step;
                strides[k] = base[ax] * step;
                off += base[ax] * start;
            } else {
                // reversed slice from start down
                len = 1 + start / step;
                strides[k] = -base[ax] * step;
                off += base[ax] * start;
            }
            shape[k] = len;
        }
        make_desc(&a, mem + off, OTI_F64, nd, shape, strides, ND_WRITEABLE);
        if (nd_validate(&a, mem, mem + (8 * 9 * 10), ND_V_SPAN) != OTI_OK){
            ok_inj = 0;
        }
        if (nd_internal_overlap(&a) != 0){
            fprintf(stderr,
                    "  overlap rejected a view: shape (%lld,%lld,%lld) strides (%lld,%lld,%lld)\n",
                    (long long)shape[0], (long long)shape[1], (long long)shape[2], (long long)strides[0],
                    (long long)strides[1], (long long)strides[2]);
            ok = 0;
        }

    }
    check(ok_inj, "overlap test setup: the random views are inside the allocation");
    check(ok,
            "nd_internal_overlap accepts 4000 random slice / transpose / reversal views of a 3-D array");

    // diagonal of an n x m C array: stride s0 + s1 on one axis
    {
        int n, ok_diag = 1;
        for (n = 1; n <= 9; n++){
            ndarr_t a = {0};
            int64_t sh[1], st[1];
            sh[0] = n;
            st[0] = 10 + 1;
            make_desc(&a, mem, OTI_F64, 1, sh, st, 0);
            ok_diag = ok_diag && (nd_internal_overlap(&a) == 0);
            st[0] = -(10 + 1);
            make_desc(&a, mem + 200, OTI_F64, 1, sh, st, 0);
            ok_diag = ok_diag && (nd_internal_overlap(&a) == 0);
        }
        check(ok_diag, "nd_internal_overlap accepts the diagonal of a contiguous matrix (both signs)");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int overlap_of(int32_t nd, const int64_t* shape, const int64_t* strides){

    static double mem[16];
    ndarr_t a = {0};

    make_desc(&a, mem + 8, OTI_F64, nd, shape, strides, ND_WRITEABLE);
    return nd_internal_overlap(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Hand-derived cases of the algorithm in contracts 3.1: drop axes of extent <= 1; any remaining zero
// stride overlaps; sort by |stride|; require |stride_k| > span, then span += (shape_k - 1) * |stride_k|.
static void test_overlap_rejects(void){

    {
        int64_t sh[2] = {4, 3}, st[2] = {0, 1};
        check(overlap_of(2, sh, st) == 1, "overlap: zero stride on an axis of extent 4 -> 1");
    }
    {
        int64_t sh[2] = {1, 3}, st[2] = {0, 1};
        check(overlap_of(2, sh, st) == 0,
                "overlap: zero stride on an axis of extent 1 -> 0 (axis dropped)");
    }
    {
        int64_t sh[2] = {2, 2}, st[2] = {1, 1};
        check(overlap_of(2, sh, st) == 1, "overlap: (2,2) strides (1,1) -> 1 (element 1 = 1 + 0)");
    }
    {
        int64_t sh[2] = {3, 3}, st[2] = {2, 1};
        check(overlap_of(2, sh, st) == 1, "overlap: (3,3) strides (2,1) -> 1 (span 2, stride 2 not > 2)");
    }
    {
        int64_t sh[2] = {3, 3}, st[2] = {3, 1};
        check(overlap_of(2, sh, st) == 0, "overlap: (3,3) strides (3,1) -> 0");
    }
    {
        int64_t sh[2] = {2, 3}, st[2] = {1, 2};
        check(overlap_of(2, sh, st) == 0, "overlap: (2,3) strides (1,2) -> 0 (F layout)");
    }
    {
        int64_t sh[2] = {2, 2}, st[2] = {2, 1};
        check(overlap_of(2, sh, st) == 0, "overlap: (2,2) strides (2,1) -> 0");
    }
    {
        int64_t sh[2] = {3, 3}, st[2] = {-3, 1};
        check(overlap_of(2, sh, st) == 0, "overlap: negative stride, magnitude 3 over span 2 -> 0");
        st[0] = -2;
        check(overlap_of(2, sh, st) == 1, "overlap: negative stride, magnitude 2 over span 2 -> 1");
    }
    {
        int64_t sh[1] = {5}, st[1] = {0};
        check(overlap_of(1, sh, st) == 1, "overlap: broadcast 1-D (stride 0, extent 5) -> 1");
        sh[0] = 1;
        check(overlap_of(1, sh, st) == 0, "overlap: stride 0 on a single element -> 0");
        sh[0] = 0;
        check(overlap_of(1, sh, st) == 0, "overlap: an extent-0 axis is dropped -> 0");
    }
    check(overlap_of(0, NULL, NULL) == 0, "overlap: rank 0 -> 0");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_may_share_memory(void){

    static double mem[64];
    ndarr_t a = {0}, b = {0}, e = {0};
    int64_t sh10[1] = {10};
    int64_t sh5[1] = {5};
    int64_t sh9[1] = {9};
    int64_t st1[1] = {1};
    int64_t st2[1] = {2};
    int64_t sh0[1] = {0};

    make_desc(&a, mem, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
    make_desc(&b, mem, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_EXACT, "share: identical arrays -> EXACT");
    check(nd_may_share_memory(&a, &a) == ND_SHARE_EXACT, "share: an array with itself -> EXACT");

    make_desc(&b, mem + 20, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_NONE, "share: disjoint spans -> NONE");
    make_desc(&b, mem + 10, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_NONE,
            "share: adjacent spans (one ends where the other starts) -> NONE");
    make_desc(&b, mem + 9, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE, "share: one common element -> MAYBE");

    // a[1:] against a[:-1]
    make_desc(&a, mem + 1, OTI_F64, 1, sh9, st1, ND_WRITEABLE);
    make_desc(&b, mem, OTI_F64, 1, sh9, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE, "share: a[1:] vs a[:-1] -> MAYBE");
    check(nd_may_share_memory(&b, &a) == ND_SHARE_MAYBE, "share: symmetric");

    // same data, different strides
    make_desc(&a, mem, OTI_F64, 1, sh5, st1, ND_WRITEABLE);
    make_desc(&b, mem, OTI_F64, 1, sh5, st2, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE, "share: same data, different strides -> MAYBE");

    // interleaved evens and odds: span test only, so MAYBE (conservative)
    make_desc(&a, mem, OTI_F64, 1, sh5, st2, ND_WRITEABLE);
    make_desc(&b, mem + 1, OTI_F64, 1, sh5, st2, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE,
            "share: interleaved even / odd -> MAYBE (span test only)");

    // reversed view of the same elements has different strides
    make_desc(&a, mem, OTI_F64, 1, sh5, st1, ND_WRITEABLE);
    {
        int64_t mst[1] = {-1};
        make_desc(&b, mem + 4, OTI_F64, 1, sh5, mst, ND_WRITEABLE);
    }
    check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE, "share: reversed view -> MAYBE");

    // dtype differs, same data
    make_desc(&a, mem, OTI_F64, 1, sh5, st1, ND_WRITEABLE);
    make_desc(&b, mem, OTI_U8, 1, sh5, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE, "share: same data, different dtype -> MAYBE");

    // EXACT ignores the strides of axes of extent <= 1
    {
        int64_t s2[2] = {1, 5};
        int64_t t1[2] = {5, 1};
        int64_t t2[2] = {99, 1};
        make_desc(&a, mem, OTI_F64, 2, s2, t1, ND_WRITEABLE);
        make_desc(&b, mem, OTI_F64, 2, s2, t2, ND_WRITEABLE);
        check(nd_may_share_memory(&a, &b) == ND_SHARE_EXACT,
              "share: strides of extent-1 axes are ignored -> EXACT");
    }

    // empty arrays share nothing
    make_desc(&e, mem, OTI_F64, 1, sh0, st1, ND_WRITEABLE);
    make_desc(&a, mem, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
    check(nd_may_share_memory(&e, &a) == ND_SHARE_NONE && nd_may_share_memory(&a, &e) == ND_SHARE_NONE &&
          nd_may_share_memory(&e, &e) == ND_SHARE_NONE, "share: empty arrays share nothing");

    // two imports of one buffer have two control blocks: still EXACT / MAYBE, never NONE
    {
        ndarr_t d = {0}, w1 = {0}, w2 = {0};
        make_desc(&d, mem, OTI_F64, 1, sh10, st1, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &w1);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &w2);
        check(w1.buf != w2.buf, "share: two wraps of one memory have two control blocks");
        check(nd_may_share_memory(&w1, &w2) == ND_SHARE_EXACT,
              "share: two wraps of the same memory, same layout -> EXACT");
        w2.data = (char*)w2.data + 8;
        w2.shape[0] = 9;
        check(nd_may_share_memory(&w1, &w2) == ND_SHARE_MAYBE,
              "share: two wraps, shifted -> MAYBE (different buffers do not prove disjointness)");
        nd_release(&w1);
        nd_release(&w2);
    }

    // multi-dimensional spans: rows of a matrix
    {
        int64_t sh2[2] = {4, 4};
        int64_t st4[2] = {4, 1};
        int64_t shr[1] = {4};
        make_desc(&a, mem, OTI_F64, 2, sh2, st4, ND_WRITEABLE);
        make_desc(&b, mem + 16, OTI_F64, 1, shr, st1, ND_WRITEABLE);
        check(nd_may_share_memory(&a, &b) == ND_SHARE_NONE,
                "share: a matrix and the memory right after it -> NONE");
        make_desc(&b, mem + 12, OTI_F64, 1, shr, st1, ND_WRITEABLE);
        check(nd_may_share_memory(&a, &b) == ND_SHARE_MAYBE,
                "share: last row of the matrix vs the matrix -> MAYBE");
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 2.2 Format table: classification and import
// =======================================================================================================

// *******************************************************************************************************
// A rejected classification is either a DTYPE status or an OK with kind OTHER (grammar section 2.2).
static int pep_rejected(const char* fmt, int64_t itemsize){

    nd_srctype_t st;
    int r;

    memset(&st, 0, sizeof(st));
    r = nd_pep3118_classify(fmt, itemsize, &st);
    return r == OTI_ERR_DTYPE || (r == OTI_OK && st.kind == ND_SRC_OTHER);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int pep_is(const char* fmt, int64_t itemsize, int kind, int size, int swapped){

    nd_srctype_t st;
    int r;

    memset(&st, 0x7F, sizeof(st));
    r = nd_pep3118_classify(fmt, itemsize, &st);
    if (r != OTI_OK || st.kind != kind || st.itemsize != size || st.swapped != swapped){
        fprintf(stderr,
                "  classify(\"%s\", %lld): status %d kind %d size %d swapped %d; expected kind %d "
                "size %d swapped %d\n", fmt ? fmt : "(null)", (long long)itemsize, r, st.kind,
                        st.itemsize,
                st.swapped, kind, size, swapped);
        return 0;
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_pep3118_classify(void){

    const int le = 1;          // every platform this library supports is little-endian
    int ok = 1;

    {
        unsigned one = 1;
        if (*(unsigned char*)&one != 1){
            printf("note: big-endian host; swapped expectations are inverted in this test\n");
        }
    }

    ok = pep_is(NULL, 1, ND_SRC_UINT, 1, 0);
    check(ok, "pep3118: NULL format means \"B\" (unsigned 1 byte)");
    check(pep_is("d", 8, ND_SRC_FLOAT, 8, 0), "pep3118: \"d\" 8");
    check(pep_is("<d", 8, ND_SRC_FLOAT, 8, 0), "pep3118: \"<d\" native on a little-endian host");
    check(pep_is("=d", 8, ND_SRC_FLOAT, 8, 0), "pep3118: \"=d\"");
    check(pep_is("@d", 8, ND_SRC_FLOAT, 8, 0), "pep3118: \"@d\"");
    check(pep_is(">d", 8, ND_SRC_FLOAT, 8, le), "pep3118: \">d\" is byte-swapped");
    check(pep_is("!d", 8, ND_SRC_FLOAT, 8, le), "pep3118: \"!d\" (network order) is byte-swapped");
    check(pep_is("f", 4, ND_SRC_FLOAT, 4, 0), "pep3118: \"f\" 4");
    check(pep_is(">f", 4, ND_SRC_FLOAT, 4, le), "pep3118: \">f\" swapped");
    check(pep_is("?", 1, ND_SRC_BOOL, 1, 0), "pep3118: \"?\" bool");
    check(pep_is("<?", 1, ND_SRC_BOOL, 1, 0) && pep_is(">?", 1, ND_SRC_BOOL, 1, le) && pep_is("=?", 1,
            ND_SRC_BOOL, 1, 0),
          "pep3118: bool with any byte-order prefix");
    check(pep_is("b", 1, ND_SRC_INT, 1, 0) && pep_is("B", 1, ND_SRC_UINT, 1, 0), "pep3118: b / B");
    check(pep_is("h", 2, ND_SRC_INT, 2, 0) && pep_is("H", 2, ND_SRC_UINT, 2, 0), "pep3118: h / H");
    check(pep_is("i", 4, ND_SRC_INT, 4, 0) && pep_is("I", 4, ND_SRC_UINT, 4, 0), "pep3118: i / I");
    check(pep_is("q", 8, ND_SRC_INT, 8, 0) && pep_is("Q", 8, ND_SRC_UINT, 8, 0), "pep3118: q / Q");
    check(pep_is("<q", 8, ND_SRC_INT, 8, 0) && pep_is("=q", 8, ND_SRC_INT, 8, 0) && pep_is("@q", 8,
            ND_SRC_INT, 8, 0),
          "pep3118: q with native prefixes");
    check(pep_is(">q", 8, ND_SRC_INT, 8, le) && pep_is(">h", 2, ND_SRC_INT, 2, le) &&
          pep_is(">i", 4, ND_SRC_INT, 4, le), "pep3118: swapped integers");
    check(pep_is("l", 4, ND_SRC_INT, 4, 0) && pep_is("l", 8, ND_SRC_INT, 8, 0),
          "pep3118: \"l\" takes its size from itemsize (4 on Windows, 8 on LP64)");
    check(pep_is("L", 4, ND_SRC_UINT, 4, 0) && pep_is("L", 8, ND_SRC_UINT, 8, 0),
            "pep3118: \"L\" with 4 and 8");
    check(pep_is("n", 8, ND_SRC_INT, 8, 0) && pep_is("N", 8, ND_SRC_UINT, 8, 0), "pep3118: n / N with 8");

    {
        nd_srctype_t st;
        check(nd_pep3118_classify("Zf", 8, &st) == OTI_OK && st.kind == ND_SRC_COMPLEX,
                "pep3118: \"Zf\" is COMPLEX");
        check(nd_pep3118_classify("Zd", 16, &st) == OTI_OK && st.kind == ND_SRC_COMPLEX,
                "pep3118: \"Zd\" is COMPLEX");
    }

    check(pep_rejected("e", 2), "pep3118: \"e\" (float16) rejected (DTYPE or OTHER)");
    check(pep_rejected("O", 8), "pep3118: \"O\" (object) rejected");
    check(pep_rejected("2d", 16), "pep3118: repeat count \"2d\" rejected");
    check(pep_rejected("dd", 16), "pep3118: two fields \"dd\" rejected");
    check(pep_rejected("T{d:a:}", 8), "pep3118: struct format rejected");
    check(pep_rejected("x", 1), "pep3118: pad byte \"x\" rejected");
    check(pep_rejected("s", 1) && pep_rejected("10s", 10), "pep3118: strings rejected");
    check(pep_rejected("", 1), "pep3118: empty format rejected");
    check(pep_rejected("<", 8), "pep3118: a prefix alone rejected");
    check(pep_rejected("<<d", 8), "pep3118: two prefixes rejected");

    // a size that does not match the kind is DTYPE
    {
        nd_srctype_t st;
        check(nd_pep3118_classify("d", 4, &st) == OTI_ERR_DTYPE,
                "pep3118: \"d\" with itemsize 4 -> DTYPE");
        check(nd_pep3118_classify("d", 3, &st) == OTI_ERR_DTYPE,
                "pep3118: \"d\" with itemsize 3 -> DTYPE");
        check(nd_pep3118_classify("?", 2, &st) == OTI_ERR_DTYPE,
                "pep3118: bool with itemsize 2 -> DTYPE");
        check(nd_pep3118_classify("b", 3, &st) == OTI_ERR_DTYPE,
                "pep3118: integer with itemsize 3 -> DTYPE");
        check(nd_pep3118_classify("q", 0, &st) == OTI_ERR_DTYPE, "pep3118: itemsize 0 -> DTYPE");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int dl_is(int32_t code, int32_t bits, int32_t lanes, int kind, int size){

    nd_srctype_t st;
    int r;

    memset(&st, 0x7F, sizeof(st));
    r = nd_dlpack_classify(code, bits, lanes, &st);
    if (r != OTI_OK || st.kind != kind || st.itemsize != size || st.swapped != 0){
        fprintf(stderr, "  dlpack (%d, %d, %d): status %d kind %d size %d swapped %d\n", code, bits,
                lanes, r,
                st.kind, st.itemsize, st.swapped);
        return 0;
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_dlpack_classify(void){

    nd_srctype_t st;
    int r;

    check(dl_is(OTI_DL_INT, 8, 1, ND_SRC_INT, 1) && dl_is(OTI_DL_INT, 16, 1, ND_SRC_INT, 2) &&
          dl_is(OTI_DL_INT, 32, 1, ND_SRC_INT, 4) && dl_is(OTI_DL_INT, 64, 1, ND_SRC_INT, 8),
          "dlpack: kDLInt 8 / 16 / 32 / 64");
    check(dl_is(OTI_DL_UINT, 8, 1, ND_SRC_UINT, 1) && dl_is(OTI_DL_UINT, 16, 1, ND_SRC_UINT, 2) &&
          dl_is(OTI_DL_UINT, 32, 1, ND_SRC_UINT, 4) && dl_is(OTI_DL_UINT, 64, 1, ND_SRC_UINT, 8),
          "dlpack: kDLUInt 8 / 16 / 32 / 64");
    check(dl_is(OTI_DL_FLOAT, 32, 1, ND_SRC_FLOAT, 4) && dl_is(OTI_DL_FLOAT, 64, 1, ND_SRC_FLOAT, 8),
          "dlpack: kDLFloat 32 / 64");
    check(dl_is(OTI_DL_BOOL, 8, 1, ND_SRC_BOOL, 1), "dlpack: kDLBool 8");

    r = nd_dlpack_classify(OTI_DL_FLOAT, 16, 1, &st);
    check(r == OTI_ERR_DTYPE || (r == OTI_OK && st.kind == ND_SRC_OTHER), "dlpack: float16 rejected");
    check(nd_dlpack_classify(OTI_DL_BFLOAT, 16, 1, &st) == OTI_ERR_DTYPE, "dlpack: bfloat16 -> DTYPE");
    r = nd_dlpack_classify(OTI_DL_COMPLEX, 128, 1, &st);
    check(r == OTI_ERR_DTYPE || (r == OTI_OK && st.kind == ND_SRC_COMPLEX), "dlpack: complex rejected");
    check(nd_dlpack_classify(OTI_DL_FLOAT, 64, 2, &st) == OTI_ERR_DTYPE, "dlpack: lanes 2 -> DTYPE");
    check(nd_dlpack_classify(OTI_DL_FLOAT, 64, 0, &st) == OTI_ERR_DTYPE, "dlpack: lanes 0 -> DTYPE");
    check(nd_dlpack_classify(OTI_DL_INT, 12, 1, &st) == OTI_ERR_DTYPE,
            "dlpack: 12 bits (not a multiple of 8) -> DTYPE");
    check(nd_dlpack_classify(OTI_DL_INT, 4, 1, &st) == OTI_ERR_DTYPE, "dlpack: 4 bits -> DTYPE");
    check(nd_dlpack_classify(99, 64, 1, &st) == OTI_ERR_DTYPE, "dlpack: unknown code -> DTYPE");

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    const void*    data;
    int32_t        ndim;
    int64_t        shape[4];
    int64_t        bstrides[4];
    int            has_strides;
    int32_t        kind;
    int32_t        itemsize;
    int32_t        swapped;
    int32_t        readonly;
} src_t;


// *******************************************************************************************************
static void src_fill(nd_import_t* s, const src_t* d){

    memset(s, 0, sizeof(*s));
    s->data = (void*)d->data;
    s->ndim = d->ndim;
    s->readonly = d->readonly;
    s->shape = d->shape;
    s->byte_strides = d->has_strides ? d->bstrides : NULL;
    s->src.kind = d->kind;
    s->src.itemsize = d->itemsize;
    s->src.swapped = d->swapped;
    s->device_type = OTI_DEVICE_CPU;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Imports with a counting callback: returns the status and sets *cb.
static int do_import(const src_t* d, int32_t want, int32_t iflags, cb_t* cb, ndarr_t* res){

    nd_import_t s;

    src_fill(&s, d);
    cb->count = 0;
    cb->chain = NULL;
    scribble(res);
    return nd_import(NULL, &s, want, iflags, cb_count, cb, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static src_t make_src(const void* data, int32_t ndim, int64_t n0, int64_t n1, int32_t kind,
        int32_t itemsize){

    src_t d;

    memset(&d, 0, sizeof(d));
    d.data = data;
    d.ndim = ndim;
    d.shape[0] = n0;
    d.shape[1] = n1;
    d.kind = kind;
    d.itemsize = itemsize;
    return d;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_import_zero_copy(void){

    static double mem[24];
    src_t d;
    ndarr_t r = {0};
    cb_t cb;
    int i, ok;

    for (i = 0; i < 24; i++){
        mem[i] = 0.5 * i;
    }

    d = make_src(mem, 2, 4, 6, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK, "import f64 C-contiguous, want F64");
    check(r.data == (void*)mem && r.dtype == OTI_F64 && r.ndim == 2 && r.shape[0] == 4 &&
            r.shape[1] == 6 &&
          r.strides[0] == 6 && r.strides[1] == 1, "import: zero-copy, C strides in elements");
    check((r.flags & ND_RETAINED) && (r.flags & ND_WRITEABLE) && (r.flags & ND_C_CONTIG),
          "import: writeable source -> writeable result");
    check(cb.count == 0, "import zero-copy: callback not run before release");
    nd_release(&r);
    check(cb.count == 1, "import zero-copy: callback run once at release");

    // read-only source
    d.readonly = 1;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && !(r.flags & ND_WRITEABLE) &&
            r.data == (void*)mem,
          "import read-only source: zero-copy, not writeable");
    nd_release(&r);

    // explicit byte strides (a transposed view: strides (8, 48) bytes of shape (6, 4))
    d = make_src(mem, 2, 6, 4, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = 8;
    d.bstrides[1] = 48;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.data == (void*)mem && r.strides[0] == 1 &&
          r.strides[1] == 6 && (r.flags & ND_F_CONTIG),
                  "import: transposed byte strides -> element strides, F contiguous");
    ok = 1;
    for (i = 0; i < 4; i++){
        int j;
        for (j = 0; j < 6; j++){
            ok = ok && (((double*)r.data)[j * r.strides[0] + i * r.strides[1]] == mem[i * 6 + j]);
        }
    }
    check(ok, "import: transposed values read back through the strides");
    nd_release(&r);

    // negative byte strides: reversed 1-D view, data points at the logical first element
    d = make_src(mem + 23, 1, 24, 0, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = -8;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.data == (void*)(mem + 23) &&
            r.strides[0] == -1 &&
          ((double*)r.data)[-5] == mem[18], "import: negative byte stride zero-copy");
    nd_release(&r);

    // zero byte stride: read-only use imports fine
    d = make_src(mem, 2, 3, 4, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = 0;
    d.bstrides[1] = 8;
    d.readonly = 1;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.strides[0] == 0 && r.data == (void*)mem,
          "import: zero byte stride accepted for read-only use");
    nd_release(&r);

    // strided (every other element)
    d = make_src(mem, 1, 12, 0, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = 16;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.data == (void*)mem && r.strides[0] == 2 &&
          !(r.flags & (ND_C_CONTIG | ND_F_CONTIG)), "import: stride 2 zero-copy, not contiguous");
    nd_release(&r);

    // ND_IMPORT_COPY always copies
    d = make_src(mem, 2, 4, 6, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, ND_IMPORT_COPY, &cb, &r) == OTI_OK && r.data != (void*)mem &&
          (r.flags & ND_WRITEABLE) && (r.flags & ND_C_CONTIG),
                  "ND_IMPORT_COPY: a new C-contiguous writeable array");
    check(cb.count == 1, "ND_IMPORT_COPY: callback already run on return");
    ok = 1;
    for (i = 0; i < 24; i++){
        ok = ok && (((double*)r.data)[i] == mem[i]);
    }
    check(ok, "ND_IMPORT_COPY: values equal");
    nd_release(&r);
    check(cb.count == 1, "ND_IMPORT_COPY: callback not run again at release");

    // want = 0 (natural) for f64
    check(do_import(&d, 0, 0, &cb, &r) == OTI_OK && r.dtype == OTI_F64 && r.data == (void*)mem,
          "import natural: f64 stays f64, zero-copy");
    nd_release(&r);

    // empty import with NULL data
    d = make_src(NULL, 2, 0, 5, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && nd_size(&r) == 0,
            "import: empty array with NULL data");
    nd_release(&r);
    check(cb.count == 1, "import empty: callback once");

    // rank 0
    d = make_src(mem, 0, 0, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.ndim == 0 && nd_size(&r) == 1 &&
          ((double*)r.data)[0] == mem[0], "import: rank 0");
    nd_release(&r);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_import_conversions_to_f64(void){

    int8_t   i8[6]  = {-128, -1, 0, 1, 2, 127};
    int16_t  i16[6] = {-32768, -1, 0, 1, 2, 32767};
    int32_t  i32[6] = {INT32_MIN, -1, 0, 1, 2, INT32_MAX};
    int64_t  i64[6] = {INT64_MIN, -1, 0, 1, INT64_C(9007199254740993), INT64_MAX};
    uint8_t  u8[6]  = {0, 1, 2, 127, 128, 255};
    uint16_t u16[6] = {0, 1, 2, 3, 40000, 65535};
    uint32_t u32[6] = {0, 1, 2, 3, 4000000000u, 4294967295u};
    uint64_t u64[6] = {0, 1, 2, 3, UINT64_C(9223372036854775808), UINT64_MAX};
    uint8_t  bl[6]  = {0, 1, 1, 0, 1, 0};
    float    f32[6] = {-1.5f, 0.0f, 3.25f, 1e30f, -0.0f, 0.1f};
    struct { const void* p; int32_t kind; int32_t size; const char* name; } cases[9];
    int c, i;
    cb_t cb;
    src_t d;
    ndarr_t r = {0};

    cases[0].p = i8;  cases[0].kind = ND_SRC_INT;   cases[0].size = 1; cases[0].name = "int8";
    cases[1].p = i16; cases[1].kind = ND_SRC_INT;   cases[1].size = 2; cases[1].name = "int16";
    cases[2].p = i32; cases[2].kind = ND_SRC_INT;   cases[2].size = 4; cases[2].name = "int32";
    cases[3].p = i64; cases[3].kind = ND_SRC_INT;   cases[3].size = 8; cases[3].name = "int64";
    cases[4].p = u8;  cases[4].kind = ND_SRC_UINT;  cases[4].size = 1; cases[4].name = "uint8";
    cases[5].p = u16; cases[5].kind = ND_SRC_UINT;  cases[5].size = 2; cases[5].name = "uint16";
    cases[6].p = u32; cases[6].kind = ND_SRC_UINT;  cases[6].size = 4; cases[6].name = "uint32";
    cases[7].p = u64; cases[7].kind = ND_SRC_UINT;  cases[7].size = 8; cases[7].name = "uint64";
    cases[8].p = bl;  cases[8].kind = ND_SRC_BOOL;  cases[8].size = 1; cases[8].name = "bool";

    for (c = 0; c < 9; c++){
        char msg[96];
        int ok = 1;
        d = make_src(cases[c].p, 1, 6, 0, cases[c].kind, cases[c].size);
        check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK, cases[c].name);
        if (r.buf == NULL){
            continue;
        }
        for (i = 0; i < 6; i++){
            double expect;
            switch (c){
                case 0: expect = (double)i8[i]; break;
                case 1: expect = (double)i16[i]; break;
                case 2: expect = (double)i32[i]; break;
                case 3: expect = (double)i64[i]; break;
                case 4: expect = (double)u8[i]; break;
                case 5: expect = (double)u16[i]; break;
                case 6: expect = (double)u32[i]; break;
                case 7: expect = (double)u64[i]; break;
                default: expect = (double)bl[i]; break;
            }
            ok = ok && (((double*)r.data)[i] == expect);
        }
        snprintf(msg, sizeof(msg), "import %s -> f64: converted copy, values exact", cases[c].name);
        check(ok && r.data != cases[c].p && (r.flags & ND_WRITEABLE) && (r.flags & ND_C_CONTIG) &&
              cb.count == 1, msg);
        nd_release(&r);
        check(cb.count == 1, "conversion path: callback exactly once");
    }

    d = make_src(f32, 1, 6, 0, ND_SRC_FLOAT, 4);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK, "import float32 -> f64");
    {
        int ok = (cb.count == 1);
        for (i = 0; i < 6; i++){
            ok = ok && (((double*)r.data)[i] == (double)f32[i]) &&
                 (signbit(((double*)r.data)[i]) == signbit((double)f32[i]));
        }
        check(ok, "import float32 -> f64: values exact (including -0.0), callback already run");
    }
    nd_release(&r);

    // natural type of float32 is F64; of int is I64
    check(do_import(&d, 0, 0, &cb, &r) == OTI_OK && r.dtype == OTI_F64, "import natural: float32 -> F64");
    nd_release(&r);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_import_swapped_unaligned_strided(void){

    static const double vals[5] = {1.5, -2.25, 1e300, -0.0, 3.0};
    unsigned char be[5 * 8];
    unsigned char un[5 * 8 + 1];
    unsigned char sparse[5 * 12];
    src_t d;
    ndarr_t r = {0};
    cb_t cb;
    int i, k, ok;

    // big-endian bytes of the values
    for (i = 0; i < 5; i++){
        unsigned char tmp[8];
        memcpy(tmp, &vals[i], 8);
        for (k = 0; k < 8; k++){
            be[i * 8 + k] = tmp[7 - k];
        }
    }
    d = make_src(be, 1, 5, 0, ND_SRC_FLOAT, 8);
    d.swapped = 1;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.data != (void*)be && cb.count == 1,
          "import byte-swapped f64: converted copy, callback run");
    ok = 1;
    for (i = 0; i < 5; i++){
        ok = ok && (memcmp(&((double*)r.data)[i], &vals[i], 8) == 0);
    }
    check(ok, "import byte-swapped f64: values bit-exact");
    nd_release(&r);

    // swapped f32
    {
        static const float fv[3] = {1.25f, -7.5f, 1e-20f};
        unsigned char fbe[12];
        for (i = 0; i < 3; i++){
            unsigned char tmp[4];
            memcpy(tmp, &fv[i], 4);
            for (k = 0; k < 4; k++){
                fbe[i * 4 + k] = tmp[3 - k];
            }
        }
        d = make_src(fbe, 1, 3, 0, ND_SRC_FLOAT, 4);
        d.swapped = 1;
        ok = (do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK);
        for (i = 0; ok && i < 3; i++){
            ok = ok && (((double*)r.data)[i] == (double)fv[i]);
        }
        check(ok, "import byte-swapped f32 -> f64 exact");
        nd_release(&r);
    }
    // swapped int32
    {
        static const int32_t iv[3] = {1, -2, 305419896};
        unsigned char ibe[12];
        for (i = 0; i < 3; i++){
            unsigned char tmp[4];
            memcpy(tmp, &iv[i], 4);
            for (k = 0; k < 4; k++){
                ibe[i * 4 + k] = tmp[3 - k];
            }
        }
        d = make_src(ibe, 1, 3, 0, ND_SRC_INT, 4);
        d.swapped = 1;
        ok = (do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK);
        for (i = 0; ok && i < 3; i++){
            ok = ok && (((double*)r.data)[i] == (double)iv[i]);
        }
        check(ok, "import byte-swapped int32 -> f64 exact");
        nd_release(&r);
    }

    // unaligned f64: data at an odd address
    memcpy(un + 1, vals, sizeof(vals));
    d = make_src(un + 1, 1, 5, 0, ND_SRC_FLOAT, 8);
    ok = (do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK);
    check(ok && r.data != (void*)(un + 1) && cb.count == 1, "import unaligned f64: converted copy");
    for (i = 0; ok && i < 5; i++){
        ok = ok && (memcmp(&((double*)r.data)[i], &vals[i], 8) == 0);
    }
    check(ok, "import unaligned f64: values bit-exact");
    nd_release(&r);

    // byte stride 12 (not a multiple of 8): converted
    memset(sparse, 0, sizeof(sparse));
    for (i = 0; i < 5; i++){
        memcpy(sparse + 12 * i, &vals[i], 8);
    }
    d = make_src(sparse, 1, 5, 0, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = 12;
    {
        // the data pointer may itself be misaligned for odd rows; start at an aligned address
        ok = (do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK);
        check(ok && cb.count == 1, "import: byte stride 12 -> converted copy");
        for (i = 0; ok && i < 5; i++){
            ok = ok && (memcmp(&((double*)r.data)[i], &vals[i], 8) == 0);
        }
        check(ok, "import: byte stride 12 values exact");
        nd_release(&r);
    }

    // conversion preserves a 2-D shape and reads through the byte strides in logical C order
    {
        float m[6] = {0, 1, 2, 3, 4, 5};   // stored (3,2) C; read as its transpose (2,3)
        d = make_src(m, 2, 2, 3, ND_SRC_FLOAT, 4);
        d.has_strides = 1;
        d.bstrides[0] = 4;
        d.bstrides[1] = 8;
        // S24 (contracts 2.4 step 4): the copy is compact in the K order of the source: byte
        // strides (4, 8) order the axes as (axis 1 outer, axis 0 inner): element strides (1, 2), F
        ok = (do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && r.shape[0] == 2 && r.shape[1] == 3 &&
              r.strides[0] == 1 && r.strides[1] == 2 && (r.flags & ND_F_CONTIG) && cb.count == 1);
        for (i = 0; ok && i < 2; i++){
            for (k = 0; k < 3; k++){
                ok = ok && (((double*)r.data)[i * r.strides[0] + k * r.strides[1]] ==
                            (double)m[k * 2 + i]);
            }
        }
        check(ok, "import f32 transposed view -> f64, logical order, K-order strides (1,2)");
        nd_release(&r);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_import_mask_and_index(void){

    static uint8_t bl[6] = {0, 1, 0, 1, 1, 0};
    static int64_t i64v[4] = {-5, 0, 7, INT64_MAX};
    static int32_t i32v[3] = {-1, 5, 9};
    static uint16_t u16v[3] = {0, 65535, 3};
    static uint64_t u64ok[3] = {0, 5, UINT64_C(9223372036854775807)};
    static uint64_t u64big[3] = {0, 5, UINT64_C(9223372036854775808)};
    static double f64v[3] = {1, 2, 3};
    src_t d;
    ndarr_t r = {0};
    cb_t cb;
    int ok, i;

    // mask
    d = make_src(bl, 1, 6, 0, ND_SRC_BOOL, 1);
    check(do_import(&d, OTI_U8, 0, &cb, &r) == OTI_OK && r.dtype == OTI_U8 && r.data == (void*)bl &&
          cb.count == 0, "import bool -> U8: zero-copy");
    nd_release(&r);
    check(cb.count == 1, "import mask: callback at release");
    check(do_import(&d, 0, 0, &cb, &r) == OTI_OK && r.dtype == OTI_U8, "import natural: bool -> U8");
    nd_release(&r);
    d = make_src(bl, 1, 6, 0, ND_SRC_UINT, 1);
    check(do_import(&d, OTI_U8, 0, &cb, &r) == OTI_ERR_DTYPE && is_empty_state(&r) && cb.count == 1,
          "import uint8 as a mask -> DTYPE (B is an integer, as in NumPy), callback once");
    d = make_src(bl, 1, 6, 0, ND_SRC_INT, 1);
    check(do_import(&d, OTI_U8, 0, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
            "import int8 as a mask -> DTYPE");
    d = make_src(f64v, 1, 3, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_U8, 0, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
            "import f64 as a mask -> DTYPE");

    // index
    d = make_src(i64v, 1, 4, 0, ND_SRC_INT, 8);
    check(do_import(&d, OTI_I64, 0, &cb, &r) == OTI_OK && r.dtype == OTI_I64 && r.data == (void*)i64v,
          "import int64 -> I64: zero-copy");
    nd_release(&r);
    check(do_import(&d, 0, 0, &cb, &r) == OTI_OK && r.dtype == OTI_I64 && r.data == (void*)i64v,
          "import natural: int64 -> I64 zero-copy");
    nd_release(&r);

    d = make_src(i32v, 1, 3, 0, ND_SRC_INT, 4);
    ok = (do_import(&d, OTI_I64, 0, &cb, &r) == OTI_OK && r.dtype == OTI_I64 && cb.count == 1);
    for (i = 0; ok && i < 3; i++){
        ok = ok && (((int64_t*)r.data)[i] == (int64_t)i32v[i]);
    }
    check(ok, "import int32 -> I64: converted copy, values exact");
    nd_release(&r);
    check(do_import(&d, 0, 0, &cb, &r) == OTI_OK && r.dtype == OTI_I64, "import natural: int32 -> I64");
    nd_release(&r);

    d = make_src(u16v, 1, 3, 0, ND_SRC_UINT, 2);
    ok = (do_import(&d, OTI_I64, 0, &cb, &r) == OTI_OK);
    for (i = 0; ok && i < 3; i++){
        ok = ok && (((int64_t*)r.data)[i] == (int64_t)u16v[i]);
    }
    check(ok, "import uint16 -> I64 values exact");
    nd_release(&r);

    d = make_src(u64ok, 1, 3, 0, ND_SRC_UINT, 8);
    ok = (do_import(&d, OTI_I64, 0, &cb, &r) == OTI_OK && cb.count == 1);
    for (i = 0; ok && i < 3; i++){
        ok = ok && (((int64_t*)r.data)[i] == (int64_t)u64ok[i]);
    }
    check(ok, "import uint64 within INT64_MAX -> I64");
    nd_release(&r);
    d = make_src(u64big, 1, 3, 0, ND_SRC_UINT, 8);
    check(do_import(&d, OTI_I64, 0, &cb, &r) == OTI_ERR_INDEX && is_empty_state(&r) && cb.count == 1,
          "import uint64 above INT64_MAX as an index -> INDEX, callback once, res empty");

    d = make_src(bl, 1, 6, 0, ND_SRC_BOOL, 1);
    check(do_import(&d, OTI_I64, 0, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
          "import bool as an index -> DTYPE (it is a mask)");
    d = make_src(f64v, 1, 3, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_I64, 0, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
          "import float as an index -> DTYPE");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_import_rejections_and_writeable(void){

    static double mem[16];
    static float f32[8];
    static unsigned char buf[8 * 8 + 1];
    src_t d;
    ndarr_t r = {0};
    cb_t cb;
    nd_import_t s;
    int i;

    // complex and other kinds
    d = make_src(mem, 1, 8, 0, ND_SRC_COMPLEX, 16);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_ERR_DTYPE && is_empty_state(&r) && cb.count == 1,
          "import complex -> DTYPE, callback once, res empty");
    check(do_import(&d, 0, 0, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
            "import natural: complex -> DTYPE");
    d = make_src(mem, 1, 8, 0, ND_SRC_OTHER, 8);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1, "import OTHER -> DTYPE");

    // shape and device
    d = make_src(mem, 1, 8, 0, ND_SRC_FLOAT, 8);
    d.ndim = 33;
    {
        src_t big = d;
        int64_t sh33[33];
        for (i = 0; i < 33; i++){
            sh33[i] = 1;
        }
        src_fill(&s, &big);
        s.shape = sh33;
        s.ndim = 33;
        cb.count = 0;
        scribble(&r);
        check(nd_import(NULL, &s, OTI_F64, 0, cb_count, &cb, &r) == OTI_ERR_SHAPE && cb.count == 1 &&
              is_empty_state(&r), "import ndim 33 -> SHAPE, callback once");
    }
    d = make_src(mem, 1, -3, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_ERR_SHAPE && cb.count == 1,
            "import negative extent -> SHAPE");
    d = make_src(mem, 1, 8, 0, ND_SRC_FLOAT, 8);
    src_fill(&s, &d);
    s.device_type = 2;
    cb.count = 0;
    check(nd_import(NULL, &s, OTI_F64, 0, cb_count, &cb, &r) == OTI_ERR_ARGUMENT && cb.count == 1,
          "import non-CPU device -> ARGUMENT, callback once");
    src_fill(&s, &d);
    s.shape = NULL;
    cb.count = 0;
    check(nd_import(NULL, &s, OTI_F64, 0, cb_count, &cb, &r) == OTI_ERR_ARGUMENT && cb.count == 1,
          "import NULL shape with ndim 1 -> ARGUMENT, callback once");

    // overflow
    d = make_src(mem, 2, INT64_C(1) << 40, INT64_C(1) << 40, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_ERR_SIZE && cb.count == 1,
            "import element count overflow -> SIZE");

    // ND_IMPORT_WRITEABLE
    d = make_src(mem, 1, 8, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE, &cb, &r) == OTI_OK && r.data == (void*)mem &&
          (r.flags & ND_WRITEABLE), "import WRITEABLE: zero-copy writeable");
    nd_release(&r);
    d.readonly = 1;
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE, &cb, &r) == OTI_ERR_READONLY &&
            is_empty_state(&r) &&
          cb.count == 1, "import WRITEABLE of a read-only source -> READONLY, callback once");
    d = make_src(f32, 1, 8, 0, ND_SRC_FLOAT, 4);
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
          "import WRITEABLE needing a type conversion -> DTYPE");
    d = make_src(mem, 1, 8, 0, ND_SRC_FLOAT, 8);
    d.swapped = 1;
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE, &cb, &r) == OTI_ERR_DTYPE && cb.count == 1,
          "import WRITEABLE of a byte-swapped source -> DTYPE");
    d = make_src(buf + 1, 1, 8, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE, &cb, &r) == OTI_ERR_LAYOUT && cb.count == 1,
          "import WRITEABLE of an unaligned source -> LAYOUT");
    d = make_src(mem, 1, 4, 0, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = 12;
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE, &cb, &r) == OTI_ERR_LAYOUT && cb.count == 1,
          "import WRITEABLE with a byte stride that is not a multiple of 8 -> LAYOUT");
    d = make_src(mem, 1, 8, 0, ND_SRC_FLOAT, 8);
    check(do_import(&d, OTI_F64, ND_IMPORT_WRITEABLE | ND_IMPORT_COPY, &cb, &r) != OTI_OK ||
            r.data != (void*)mem,
          "import WRITEABLE | COPY never aliases the source");
    nd_release(&r);

    // a NULL callback is allowed
    src_fill(&s, &d);
    check(nd_import(NULL, &s, OTI_F64, 0, NULL, NULL, &r) == OTI_OK, "import with a NULL callback");
    nd_release(&r);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_import_failure_injection(void){

    static float f32[64];
    static double mem[64];
    src_t d;
    ndarr_t r = {0};
    cb_t cb;
    int k, saw, finished, ok;

    // conversion path: the copy allocation fails at some countdown
    d = make_src(f32, 1, 64, 0, ND_SRC_FLOAT, 4);
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 12 && !finished; k++){
        int st;
        nd_import_t s;
        src_fill(&s, &d);
        cb.count = 0;
        cb.chain = NULL;
        scribble(&r);
        nd_test_fail_alloc(k);
        st = nd_import(NULL, &s, OTI_F64, 0, cb_count, &cb, &r);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            ok = ok && cb.count == 1;
            nd_release(&r);
            ok = ok && cb.count == 1;
            finished = 1;
        } else {
            saw++;
            ok = ok && (st == OTI_ERR_MEMORY) && cb.count == 1 && is_empty_state(&r);
        }
    }
    check(saw >= 1 && finished,
            "nd_import (conversion) fail_alloc: an allocation can fail, then success");
    check(ok, "nd_import (conversion) fail_alloc: MEMORY, callback exactly once, res empty");

    // zero-copy path: the control block
    d = make_src(mem, 1, 64, 0, ND_SRC_FLOAT, 8);
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 12 && !finished; k++){
        int st;
        nd_import_t s;
        src_fill(&s, &d);
        cb.count = 0;
        cb.chain = NULL;
        scribble(&r);
        nd_test_fail_alloc(k);
        st = nd_import(NULL, &s, OTI_F64, 0, cb_count, &cb, &r);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            ok = ok && cb.count == 0;
            nd_release(&r);
            ok = ok && cb.count == 1;
            finished = 1;
        } else {
            saw++;
            ok = ok && (st == OTI_ERR_MEMORY) && cb.count == 1 && is_empty_state(&r);
        }
    }
    check(saw >= 1 && finished, "nd_import (zero-copy) fail_alloc: the control block can fail");
    check(ok, "nd_import (zero-copy) fail_alloc: MEMORY, callback exactly once, res empty");

    // budget on the conversion path
    {
        oti_ctx ctx;
        nd_import_t s;
        oti_ctx_init(&ctx);
        ctx.max_alloc_bytes = 100;
        d = make_src(f32, 1, 64, 0, ND_SRC_FLOAT, 4);
        src_fill(&s, &d);
        cb.count = 0;
        cb.chain = NULL;
        check(nd_import(&ctx, &s, OTI_F64, 0, cb_count, &cb, &r) == OTI_ERR_MEMORY && cb.count == 1 &&
              is_empty_state(&r), "import conversion over the budget -> MEMORY, callback once");
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// nd_copy (1.4 fail_alloc) and the creator of copies' basic values
// =======================================================================================================

// *******************************************************************************************************
static void test_copy_basic_and_failure(void){

    ndarr_t a = {0}, c = {0}, view = {0};
    int64_t shape[2] = {3, 4};
    int64_t i, j;
    int ok = 1;
    int k, saw = 0, finished = 0;

    make_iota(2, shape, ND_LAYOUT_C, &a);
    check(nd_copy(NULL, &a, ND_LAYOUT_F, &c) == OTI_OK && (c.flags & ND_F_CONTIG) && c.strides[0] == 1 &&
          c.strides[1] == 3 && c.data != a.data, "copy C -> F: new F-contiguous array");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            ok = ok && (((double*)c.data)[i * c.strides[0] + j * c.strides[1]] == (double)(i * 4 + j));
        }
    }
    check(ok, "copy C -> F: values equal");
    nd_release(&c);

    // negative-stride source: copy is positive-stride with the logical values
    view = a;
    view.flags &= ~ND_RETAINED;
    view.data = (double*)a.data + 11;
    view.strides[0] = -4;
    view.strides[1] = -1;
    nd_update_flags(&view);
    check(nd_copy(NULL, &view, ND_LAYOUT_C, &c) == OTI_OK && c.strides[0] == 4 && c.strides[1] == 1,
          "copy of a reversed view: positive strides");
    ok = 1;
    for (i = 0; i < 12; i++){
        ok = ok && (((double*)c.data)[i] == (double)(11 - i));
    }
    check(ok, "copy of a reversed view: logical values");
    nd_release(&c);

    check(nd_copy(NULL, &a, 9, &c) == OTI_ERR_ARGUMENT && is_empty_state(&c),
            "copy: bad layout -> ARGUMENT");

    for (k = 1; k < 20 && !finished; k++){
        int st;
        scribble(&c);
        nd_test_fail_alloc(k);
        st = nd_copy(NULL, &a, ND_LAYOUT_C, &c);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            nd_release(&c);
            finished = 1;
        } else {
            saw++;
            if (st != OTI_ERR_MEMORY || !is_empty_state(&c)){
                ok = 0;
            }
        }
    }
    check(saw >= 1 && finished, "nd_copy fail_alloc: an allocation can fail, then success");
    check(ok, "nd_copy fail_alloc: MEMORY and an empty res at every allocation");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 6 View mapping
// =======================================================================================================

// *******************************************************************************************************
static void test_to_view_fields(void){

    static double mem[24];
    static uint8_t bm[24];
    static int64_t im[24];
    ndarr_t a = {0};
    oti_view v;
    int64_t sh[2] = {3, 4};
    int64_t st[2] = {4, 1};
    int z, i;
    void* ptrs[3];
    int32_t dts[3] = {OTI_F64, OTI_U8, OTI_I64};
    int exp_code[3] = {OTI_DL_FLOAT, OTI_DL_BOOL, OTI_DL_INT};
    int exp_bits[3] = {64, 8, 64};

    ptrs[0] = mem; ptrs[1] = bm; ptrs[2] = im;

    check(sizeof(oti_view) == 136, "sizeof(oti_view) == 136");
    check(sizeof(oti_dltensor_t) == 48, "sizeof(oti_dltensor_t) == 48");
    check(offsetof(oti_view, reserved) == 104 + 0 || offsetof(oti_view, reserved) > 0,
          "offsetof(oti_view, reserved) is defined");

    for (i = 0; i < 3; i++){
        char msg[96];
        make_desc(&a, ptrs[i], dts[i], 2, sh, st, ND_WRITEABLE);
        nd_update_flags(&a);
        memset(&v, 0xEE, sizeof(v));
        v.struct_size = (int32_t)sizeof(oti_view);
        snprintf(msg, sizeof(msg), "to_view dtype %d: OK", dts[i]);
        check(nd_to_view(&a, &v) == OTI_OK, msg);
        snprintf(msg, sizeof(msg), "to_view dtype %d: kind REAL, data, byte_offset 0", dts[i]);
        check(v.kind == OTI_KIND_REAL && v.dl.data == ptrs[i] && v.dl.byte_offset == 0 && v.struct_size ==
              (int32_t)sizeof(oti_view), msg);
        snprintf(msg, sizeof(msg), "to_view dtype %d: device CPU / 0, ndim 2", dts[i]);
        check(v.dl.device.device_type == OTI_DEVICE_CPU && v.dl.device.device_id == 0 && v.dl.ndim == 2,
                msg);
        snprintf(msg, sizeof(msg), "to_view dtype %d: DLDataType code %d bits %d lanes 1", dts[i],
                exp_code[i],
                 exp_bits[i]);
        check(v.dl.dtype.code == exp_code[i] && v.dl.dtype.bits == exp_bits[i] && v.dl.dtype.lanes == 1,
                msg);
        snprintf(msg, sizeof(msg), "to_view dtype %d: shape / strides point into the array", dts[i]);
        check(v.dl.shape == a.shape && v.dl.strides == a.strides && v.dl.shape[0] == 3 &&
                v.dl.strides[0] == 4,
              msg);
        snprintf(msg, sizeof(msg), "to_view dtype %d: writeable -> flags 0, OTI fields and reserved zero",
                dts[i]);
        z = (v.flags == 0 && v.trc_order == 0 && v.act_order == 0 && v.reserved0 == 0 && v.nbases == 0 &&
             v.bases == NULL);
        {
            int r;
            for (r = 0; r < 6; r++){
                z = z && (v.reserved[r] == 0);
            }
        }
        check(z, msg);
        // read-only
        a.flags &= ~ND_WRITEABLE;
        memset(&v, 0xEE, sizeof(v));
        v.struct_size = (int32_t)sizeof(oti_view);
        nd_to_view(&a, &v);
        snprintf(msg, sizeof(msg), "to_view dtype %d: read-only -> OTI_VIEW_READONLY", dts[i]);
        check(v.flags == OTI_VIEW_READONLY, msg);
    }

    // struct_size handling
    make_desc(&a, mem, OTI_F64, 2, sh, st, ND_WRITEABLE);
    nd_update_flags(&a);
    {
        unsigned char raw[sizeof(oti_view) + 16];
        oti_view* pv = (oti_view*)raw;
        size_t minsz = offsetof(oti_view, reserved);
        size_t j;
        int canary_ok = 1;

        memset(raw, 0xA5, sizeof(raw));
        pv->struct_size = (int32_t)minsz;
        check(nd_to_view(&a, pv) == OTI_OK, "to_view: struct_size == offsetof(reserved) accepted");
        for (j = minsz; j < sizeof(raw); j++){
            canary_ok = canary_ok && (raw[j] == 0xA5);
        }
        check(canary_ok, "to_view: nothing written past struct_size");
        check(pv->kind == OTI_KIND_REAL && pv->dl.data == (void*)mem && pv->flags == 0,
              "to_view: the fields below struct_size are filled");

        memset(&v, 0, sizeof(v));
        v.struct_size = (int32_t)minsz - 1;
        check(nd_to_view(&a, &v) == OTI_ERR_ARGUMENT,
                "to_view: struct_size below offsetof(reserved) -> ARGUMENT");
        v.struct_size = 0;
        check(nd_to_view(&a, &v) == OTI_ERR_ARGUMENT, "to_view: struct_size 0 -> ARGUMENT");
        check(nd_to_view(NULL, &v) == OTI_ERR_ARGUMENT, "to_view(NULL array) -> ARGUMENT");
        check(nd_to_view(&a, NULL) == OTI_ERR_ARGUMENT, "to_view(NULL view) -> ARGUMENT");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void set_view(oti_view* v, void* data, int32_t code, int32_t bits, int32_t lanes, int32_t ndim,
                     int64_t* shape, int64_t* strides, uint64_t byte_offset, int32_t flags){

    memset(v, 0, sizeof(*v));
    v->struct_size = (int32_t)sizeof(oti_view);
    v->kind = OTI_KIND_REAL;
    v->dl.data = data;
    v->dl.device.device_type = OTI_DEVICE_CPU;
    v->dl.device.device_id = 0;
    v->dl.ndim = ndim;
    v->dl.dtype.code = (uint8_t)code;
    v->dl.dtype.bits = (uint8_t)bits;
    v->dl.dtype.lanes = (uint16_t)lanes;
    v->dl.shape = shape;
    v->dl.strides = strides;
    v->dl.byte_offset = byte_offset;
    v->flags = flags;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_from_view(void){

    static double mem[64];
    ndarr_t a = {0}, b = {0};
    oti_view v;
    int64_t sh[2] = {3, 4};
    int64_t st[2] = {4, 1};
    int64_t st_neg[2] = {-4, 1};
    int64_t st_zero[2] = {0, 1};
    int64_t sh33[33], st33[33];
    int64_t negsh[2] = {3, -1};
    int i;

    // round trip
    make_desc(&a, mem + 20, OTI_F64, 2, sh, st_neg, ND_WRITEABLE);
    nd_update_flags(&a);
    v.struct_size = (int32_t)sizeof(oti_view);
    nd_to_view(&a, &v);
    scribble(&b);
    check(nd_from_view(&v, 0, &b) == OTI_OK, "from_view: round trip OK");
    check(b.data == a.data && b.ndim == 2 && b.shape[0] == 3 && b.shape[1] == 4 && b.strides[0] == -4 &&
          b.strides[1] == 1 && b.dtype == OTI_F64 && (b.flags & ND_WRITEABLE) && b.buf == NULL &&
          !(b.flags & ND_RETAINED), "from_view: round trip equals the array (temporary, buf NULL)");

    // every dtype round trip
    {
        static uint8_t bm[16];
        static int64_t im[16];
        int64_t s1[1] = {16};
        int64_t t1[1] = {1};
        ndarr_t u = {0}, w = {0};
        make_desc(&u, bm, OTI_U8, 1, s1, t1, 0);
        v.struct_size = (int32_t)sizeof(oti_view);
        nd_to_view(&u, &v);
        check(nd_from_view(&v, 0, &w) == OTI_OK && w.dtype == OTI_U8 && w.data == (void*)bm &&
                !(w.flags & ND_WRITEABLE),
              "from_view round trip: U8 read-only");
        make_desc(&u, im, OTI_I64, 1, s1, t1, ND_WRITEABLE);
        nd_to_view(&u, &v);
        check(nd_from_view(&v, 0, &w) == OTI_OK && w.dtype == OTI_I64 && (w.flags & ND_WRITEABLE),
              "from_view round trip: I64 writeable");
    }

    // NULL strides -> C-contiguous
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, NULL, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_OK && b.strides[0] == 4 && b.strides[1] == 1 &&
            (b.flags & ND_C_CONTIG) &&
          (b.flags & ND_WRITEABLE), "from_view: NULL strides -> C-contiguous, writeable");

    // byte_offset added to data
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 16, 0);
    check(nd_from_view(&v, 0, &b) == OTI_OK && b.data == (void*)(mem + 2),
            "from_view: byte_offset added to data");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 12, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_LAYOUT && is_empty_state(&b),
          "from_view: data + byte_offset misaligned -> LAYOUT, out empty");

    // flags
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 0, OTI_VIEW_READONLY);
    check(nd_from_view(&v, 0, &b) == OTI_OK && !(b.flags & ND_WRITEABLE),
            "from_view: READONLY -> not writeable");
    check(nd_from_view(&v, ND_V_OUTPUT, &b) == OTI_ERR_READONLY,
            "from_view: READONLY as an output -> READONLY");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st_zero, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_OK, "from_view: zero stride accepted as an input");
    check(nd_from_view(&v, ND_V_OUTPUT, &b) == OTI_ERR_LAYOUT,
            "from_view: zero stride as an output -> LAYOUT");

    // rejections
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 0, 0);
    v.dl.device.device_type = 2;
    check(nd_from_view(&v, 0, &b) == OTI_ERR_ARGUMENT, "from_view: non-CPU device -> ARGUMENT");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 0, 0);
    v.dl.device.device_id = 1;
    check(nd_from_view(&v, 0, &b) == OTI_ERR_ARGUMENT, "from_view: device id 1 -> ARGUMENT");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 0, 0);
    v.kind = OTI_KIND_DENSE_SOA;
    check(nd_from_view(&v, 0, &b) == OTI_ERR_ARGUMENT, "from_view: kind other than REAL -> ARGUMENT");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, sh, st, 0, 0);
    v.struct_size = (int32_t)offsetof(oti_view, reserved) - 1;
    check(nd_from_view(&v, 0, &b) == OTI_ERR_ARGUMENT, "from_view: struct_size too small -> ARGUMENT");
    for (i = 0; i < 33; i++){
        sh33[i] = 1;
        st33[i] = 1;
    }
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 33, sh33, st33, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_SHAPE, "from_view: ndim 33 -> SHAPE");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 32, sh33, st33, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_OK && b.ndim == 32, "from_view: ndim 32 accepted");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 2, negsh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_SHAPE, "from_view: negative extent -> SHAPE");

    // dtypes that are not exactly f64 / bool8 / int64
    set_view(&v, mem, OTI_DL_FLOAT, 32, 1, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_DTYPE, "from_view: float32 -> DTYPE (no conversion)");
    set_view(&v, mem, OTI_DL_INT, 32, 1, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_DTYPE, "from_view: int32 -> DTYPE");
    set_view(&v, mem, OTI_DL_UINT, 8, 1, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_DTYPE, "from_view: uint8 (not bool) -> DTYPE");
    set_view(&v, mem, OTI_DL_FLOAT, 64, 2, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_DTYPE, "from_view: lanes 2 -> DTYPE");
    set_view(&v, mem, OTI_DL_BFLOAT, 16, 1, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_ERR_DTYPE, "from_view: bfloat16 -> DTYPE");
    set_view(&v, mem, OTI_DL_INT, 64, 1, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_OK && b.dtype == OTI_I64, "from_view: int64 -> I64");
    set_view(&v, mem, OTI_DL_BOOL, 8, 1, 2, sh, st, 0, 0);
    check(nd_from_view(&v, 0, &b) == OTI_OK && b.dtype == OTI_U8, "from_view: bool8 -> U8");

    // overflow
    {
        int64_t huge[1] = {INT64_C(1) << 62};
        set_view(&v, mem, OTI_DL_FLOAT, 64, 1, 1, huge, NULL, 0, 0);
        check(nd_from_view(&v, 0, &b) == OTI_ERR_SIZE, "from_view: 2^62 doubles -> SIZE");
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 4 statuses: the last error of failing ndarray calls
// =======================================================================================================

// *******************************************************************************************************
static void test_last_error_of_failing_calls(void){

    oti_ctx ctx;
    ndarr_t a = {0};
    int64_t neg[1] = {-1};
    int64_t ok1[1] = {4};
    const char* where = NULL;
    const char* msg = NULL;

    oti_ctx_init(&ctx);
    oti_ctx_clear_error(NULL);

    check(nd_alloc(&ctx, OTI_F64, 1, neg, ND_LAYOUT_C, 0, &a) == OTI_ERR_SHAPE,
            "failing nd_alloc with a user ctx");
    check(oti_ctx_last_error(&ctx, &where, &msg) == OTI_ERR_SHAPE,
            "failing nd_alloc records its status in the user ctx");
    check(where != NULL && strncmp(where, "nd_", 3) == 0,
            "last error: where names the public function (nd_...)");
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_OK,
            "last error: the thread-local record is untouched");

    // success does not clear
    check(nd_alloc(&ctx, OTI_F64, 1, ok1, ND_LAYOUT_C, 0, &a) == OTI_OK, "succeeding nd_alloc");
    nd_release(&a);
    check(oti_ctx_last_error(&ctx, NULL, NULL) == OTI_ERR_SHAPE, "last error: success does not clear it");

    // NULL ctx: thread-local
    check(nd_alloc(NULL, 0, 1, ok1, ND_LAYOUT_C, 0, &a) == OTI_ERR_DTYPE,
            "failing nd_alloc with NULL ctx");
    check(oti_ctx_last_error(NULL, &where, NULL) == OTI_ERR_DTYPE && where != NULL,
          "last error: NULL ctx records thread-locally");
    check(oti_ctx_last_error(&ctx, NULL, NULL) == OTI_ERR_SHAPE, "last error: user ctx keeps its own");
    check(oti_ctx_default()->last_status == OTI_OK,
            "last error: the default context itself is never written");

    // an explicit default pointer behaves like NULL (contracts [cM6])
    oti_ctx_clear_error(NULL);
    check(nd_alloc((oti_ctx*)oti_ctx_default(), OTI_F64, 1, neg, ND_LAYOUT_C, 0, &a) == OTI_ERR_SHAPE,
          "failing nd_alloc with the default pointer");
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_SHAPE &&
            oti_ctx_default()->last_status == OTI_OK,
          "last error: default pointer records thread-locally, never writes the default ([cM6])");

    // a failing nd_wrap records too, and a failing import
    {
        ndarr_t d = {0}, w = {0};
        double mem[4];
        cb_t cb = {0, NULL, 0};
        make_desc(&d, mem, OTI_F64, 1, ok1, NULL, ND_WRITEABLE);
        d.strides[0] = 1;
        d.shape[0] = -1;
        oti_ctx_clear_error(&ctx);
        check(nd_wrap(&ctx, &d, NULL, -1, cb_count, &cb, &w) == OTI_ERR_SHAPE && cb.count == 1,
              "failing nd_wrap with a user ctx");
        check(oti_ctx_last_error(&ctx, &where, NULL) == OTI_ERR_SHAPE && where != NULL,
              "failing nd_wrap records its status");
    }
    {
        nd_import_t s;
        int64_t sh[1] = {4};
        double mem[4] = {0};
        ndarr_t r = {0};
        memset(&s, 0, sizeof(s));
        s.data = mem; s.ndim = 1; s.shape = sh; s.src.kind = ND_SRC_COMPLEX; s.src.itemsize = 16;
        s.device_type = OTI_DEVICE_CPU;
        oti_ctx_clear_error(&ctx);
        check(nd_import(&ctx, &s, OTI_F64, 0, NULL, NULL, &r) == OTI_ERR_DTYPE &&
              oti_ctx_last_error(&ctx, NULL, NULL) == OTI_ERR_DTYPE, "failing nd_import records DTYPE");
    }

    // a budget failure records MEMORY
    {
        int64_t big[1] = {100000};
        ctx.max_alloc_bytes = 1000;
        oti_ctx_clear_error(&ctx);
        check(nd_alloc(&ctx, OTI_F64, 1, big, ND_LAYOUT_C, 0, &a) == OTI_ERR_MEMORY &&
              oti_ctx_last_error(&ctx, NULL, NULL) == OTI_ERR_MEMORY,
                      "over-budget nd_alloc records MEMORY");
    }
    oti_ctx_clear_error(NULL);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 1.3 races (TSan): runs only when built with -fsanitize=thread
// =======================================================================================================

typedef struct {
    ndarr_t*        arr;
    volatile int*   stop;
    int             iters;
    int             busy_count;
    int             ok_count;
    int             bad;
} race_t;


// *******************************************************************************************************
// Retains and releases its own copy of the buffer reference.
static void* race_retain_release(void* p){

    race_t* r = (race_t*)p;
    int i;

    for (i = 0; i < r->iters; i++){
        ndarr_t v = {0};
        int st = nd_view_retain(r->arr, &v);
        if (st == OTI_OK){
            r->ok_count++;
            nd_release(&v);
        } else if (st == OTI_ERR_BUSY){
            r->busy_count++;
        } else {
            r->bad++;
        }
    }
    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* race_lock_unlock(void* p){

    race_t* r = (race_t*)p;
    int i;

    for (i = 0; i < r->iters; i++){
        int st = nd_buffer_lock_layout(r->arr->buf);
        if (st == OTI_OK){
            r->ok_count++;
            nd_buffer_unlock_layout(r->arr->buf);
        } else if (st == OTI_ERR_BUSY){
            r->busy_count++;
        } else {
            r->bad++;
        }
    }
    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A temporary copy of the root (borrows its reference) is exported and released from one thread while
// the owner thread grows the buffer: each attempt either wins or fails with BUSY; never a crash and
// never a leaked state bit.
static void* race_export(void* p){

    race_t* r = (race_t*)p;
    int i;

    for (i = 0; i < r->iters; i++){
        ndarr_t tmp = *r->arr;
        ndarr_t e = {0};
        int st;
        tmp.flags &= ~(ND_RETAINED | ND_EXPORTED);
        st = nd_export(&tmp, 0, &e);
        if (st == OTI_OK){
            r->ok_count++;
            nd_release(&e);
        } else if (st == OTI_ERR_BUSY){
            r->busy_count++;
        } else {
            r->bad++;
        }
    }
    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// TSan: N threads retain / release one buffer while one thread loops lock / unlock; then export versus
// nd_grow. Meaningful only under -fsanitize=thread (the data races would be reported there); under
// other builds main() does not call it.
static void test_races_tsan(void){

    enum { NT = 4 };
    ndarr_t root = {0};
    ndarr_t keeper = {0};
    pthread_t th[NT + 1];
    race_t rs[NT + 1];
    int64_t shape[1] = {64};
    int t, bad = 0, i;
    volatile int stop = 0;

    nd_alloc(NULL, OTI_F64, 1, shape, ND_LAYOUT_C, ND_ALLOC_GROWABLE, &root);
    // The workers retain from a temporary alias of the root, which holds the one real reference.
    keeper = root;
    keeper.flags &= ~ND_RETAINED;

    for (t = 0; t < NT; t++){
        memset(&rs[t], 0, sizeof(rs[t]));
        rs[t].arr = &keeper;
        rs[t].stop = &stop;
        rs[t].iters = 20000;
        pthread_create(&th[t], NULL, race_retain_release, &rs[t]);
    }
    memset(&rs[NT], 0, sizeof(rs[NT]));
    rs[NT].arr = &keeper;
    rs[NT].stop = &stop;
    rs[NT].iters = 20000;
    pthread_create(&th[NT], NULL, race_lock_unlock, &rs[NT]);
    for (t = 0; t <= NT; t++){
        pthread_join(th[t], NULL);
        bad += rs[t].bad;
    }
    check(bad == 0, "races: retain / release / lock / unlock give only OK or BUSY");
    check(nd_buffer_refs(root.buf) == 1 && nd_buffer_exports(root.buf) == 0 &&
          !(nd_buffer_state(root.buf) & ND_STATE_GROWING),
                  "races: state back to refs 1, no exports, unlocked");

    // export versus grow
    {
        race_t ex;
        int grow_ok = 0, grow_busy = 0, grow_bad = 0;
        memset(&ex, 0, sizeof(ex));
        ex.arr = &keeper;
        ex.iters = 20000;
        pthread_create(&th[0], NULL, race_export, &ex);
        for (i = 0; i < 20000; i++){
            int st = nd_grow(NULL, &root, 1024 + (i % 7) * 64, 8);
            if (st == OTI_OK){
                grow_ok++;
                keeper = root;
                keeper.flags &= ~ND_RETAINED;
            } else if (st == OTI_ERR_BUSY){
                grow_busy++;
            } else {
                grow_bad++;
            }
        }
        pthread_join(th[0], NULL);
        printf("info: grow ok %d busy %d; export ok %d busy %d\n", grow_ok, grow_busy, ex.ok_count,
                ex.busy_count);
        check(grow_bad == 0 && ex.bad == 0, "races: nd_grow and nd_export give only OK or BUSY");
        check(nd_buffer_refs(root.buf) == 1 && nd_buffer_exports(root.buf) == 0 &&
              !(nd_buffer_state(root.buf) & ND_STATE_GROWING),
                      "races: state clean after the export / grow race");
    }
    nd_release(&root);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 1 regressions (checker findings 2, 3, 4, 5, 6).
static void test_fix1_core(void){

    static double mem[4];
    static double mem2[2];
    ndarr_t t = {0}, c = {0}, r = {0};
    int64_t big3[3] = {INT64_MAX, 2, 0};
    int64_t s3[3] = {5, 0, 7};
    uint64_t nanbits = UINT64_C(0x7FF8000000001234), got;
    double nanv;
    oti_ctx ctx;
    int k;

    // 2: overflow of the non-zero extents is SIZE even for an empty array; nd_size of {5,0,7} is 0
    scribble(&t);
    check(nd_wrap_trusted(NULL, OTI_F64, 3, big3, NULL, 1, &t) == OTI_ERR_SIZE && is_empty_state(&t),
          "fix1.2: wrap_trusted of {INT64_MAX, 2, 0} -> SIZE, out empty");
    make_desc(&t, NULL, OTI_F64, 3, s3, (int64_t[]){0, 0, 0}, ND_WRITEABLE);
    check(nd_size(&t) == 0, "fix1.2: nd_size of {5, 0, 7} is 0");
    t.shape[0] = INT64_MAX; t.shape[1] = 2; t.shape[2] = 0;
    check(nd_validate(&t, NULL, NULL, 0) == OTI_ERR_SIZE,
            "fix1.2: nd_validate of {INT64_MAX, 2, 0} -> SIZE");
    check(nd_size(&t) == 0, "fix1.2: nd_size of {INT64_MAX, 2, 0} is 0 (returns before multiplying)");

    // 3: (1, 2) with strides (INT64_MIN, 1): the extent-1 axis is ignored in K order
    mem2[0] = 1.5; mem2[1] = -2.5;
    {
        int64_t sh[2] = {1, 2};
        int64_t st[2] = {INT64_MIN, 1};
        make_desc(&t, mem2, OTI_F64, 2, sh, st, 0);
        check(nd_validate(&t, NULL, NULL, 0) == OTI_OK, "fix1.3: (1,2) strides (INT64_MIN,1) validates");
        check(nd_copy(NULL, &t, ND_LAYOUT_K, &c) == OTI_OK && c.shape[1] == 2 &&
              ((double*)c.data)[0] == 1.5 && ((double*)c.data)[1] == -2.5 && c.strides[1] == 1,
              "fix1.3: K-order copy of (1,2) with stride INT64_MIN is correct");
        nd_release(&c);
    }

    // 4: reversed float32 import and a gapped strided import
    {
        static float f[6] = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f};
        src_t d;
        cb_t cb;
        d = make_src(f + 1, 1, 2, 0, ND_SRC_FLOAT, 4);
        d.has_strides = 1; d.bstrides[0] = -4;
        check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && ((double*)r.data)[0] == 2.0 &&
              ((double*)r.data)[1] == 1.0 && cb.count == 1,
                      "fix1.4: reversed float32 (byte stride -4) imports");
        nd_release(&r);
        d = make_src(f, 1, 3, 0, ND_SRC_FLOAT, 4);
        d.has_strides = 1; d.bstrides[0] = 8;
        check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && ((double*)r.data)[0] == 1.0 &&
              ((double*)r.data)[1] == 3.0 && ((double*)r.data)[2] == 5.0 && cb.count == 1,
              "fix1.4: gapped float32 import (byte stride 8) converts");
        nd_release(&r);
    }

    // 5: strided C-order copy of a view of a declared double[4], bit-exact incl. a NaN payload
    memcpy(&nanv, &nanbits, 8);
    mem[0] = 1.0; mem[1] = nanv; mem[2] = -0.0; mem[3] = 4.0;
    {
        int64_t sh[2] = {2, 2};
        int64_t st[2] = {1, 2};          // transposed: the C-order copy is strided
        make_desc(&t, mem, OTI_F64, 2, sh, st, 0);
        check(nd_copy(NULL, &t, ND_LAYOUT_C, &c) == OTI_OK, "fix1.5: strided C copy");
        memcpy(&got, (double*)c.data + 2, 8);     // c[1][0] = t[1][0] = mem[1]
        check(got == nanbits, "fix1.5: NaN payload preserved bit-exactly");
        memcpy(&got, (double*)c.data + 1, 8);     // c[0][1] = mem[2] = -0.0
        check(got == UINT64_C(0x8000000000000000), "fix1.5: -0.0 preserved");
        nd_release(&c);
    }

    // 6: a bad context is rejected with the oti_ctx_check status, recorded, by every entry point
    for (k = 0; k < 3; k++){
        int expect;
        int64_t sh[1] = {4};
        int64_t st[1] = {1};
        ndarr_t d = {0};
        cb_t cb;
        nd_import_t s;
        oti_ctx_init(&ctx);
        if (k == 0){
            ctx.device_type = 2;
        } else if (k == 1){
            ctx.max_alloc_bytes = -1;
        } else {
            ctx.exec.backend = 77;
        }
        expect = oti_ctx_check(&ctx);
        check(expect != OTI_OK, "fix1.6: the test context is invalid");

        scribble(&r);
        oti_ctx_clear_error(&ctx);
        check(nd_zeros(&ctx, 1, sh, ND_LAYOUT_C, &r) == expect && is_empty_state(&r) &&
              oti_ctx_last_error(&ctx, NULL, NULL) == expect,
                      "fix1.6: nd_zeros rejects the context and records it");

        make_desc(&d, mem, OTI_F64, 1, sh, st, ND_WRITEABLE);
        cb.count = 0; cb.chain = NULL;
        oti_ctx_clear_error(&ctx);
        scribble(&r);
        check(nd_wrap(&ctx, &d, mem, sizeof(mem), cb_count, &cb, &r) == expect && cb.count == 1 &&
              is_empty_state(&r) && oti_ctx_last_error(&ctx, NULL, NULL) == expect,
              "fix1.6: nd_wrap (zero-copy path) rejects the context, callback once, recorded");

        memset(&s, 0, sizeof(s));
        s.data = mem; s.ndim = 1; s.shape = sh; s.src.kind = ND_SRC_FLOAT; s.src.itemsize = 8;
        s.device_type = OTI_DEVICE_CPU;
        cb.count = 0;
        oti_ctx_clear_error(&ctx);
        scribble(&r);
        check(nd_import(&ctx, &s, OTI_F64, 0, cb_count, &cb, &r) == expect && cb.count == 1 &&
              is_empty_state(&r) && oti_ctx_last_error(&ctx, NULL, NULL) == expect,
              "fix1.6: nd_import (zero-copy path) rejects the context, callback once, recorded");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 2: foreign address intervals that wrap are rejected before any load (addresses never
// dereferenced).
static void test_fix2_core(void){

    ndarr_t r = {0};
    src_t d;
    cb_t cb;

    d = make_src((void*)(uintptr_t)8, 1, 2, 0, ND_SRC_FLOAT, 4);
    d.has_strides = 1;
    d.bstrides[0] = -16;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_ERR_LAYOUT && cb.count == 1 && is_empty_state(&r),
          "fix2.4: import at address 8, byte stride -16: interval below 0 -> LAYOUT, callback once");
    d = make_src((void*)(UINTPTR_MAX - 8), 1, 2, 0, ND_SRC_FLOAT, 4);
    d.has_strides = 1;
    d.bstrides[0] = 16;
    check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_ERR_LAYOUT && cb.count == 1 && is_empty_state(&r),
          "fix2.4: import near UINTPTR_MAX, stride +16: wraps above -> LAYOUT, callback once");
    d = make_src((void*)(UINTPTR_MAX - 8), 1, 2, 0, ND_SRC_FLOAT, 8);
    d.has_strides = 1;
    d.bstrides[0] = 16;
    check(do_import(&d, OTI_F64, ND_IMPORT_COPY, &cb, &r) == OTI_ERR_LAYOUT && cb.count == 1,
          "fix2.4: the same with ND_IMPORT_COPY -> LAYOUT");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 3 (S24, S25): nd_alloc_strided, nd_set_layout, every library buffer growable.
static void test_fix3_core(void){

    ndarr_t a = {0}, r = {0}, root = {0}, t = {0}, src = {0};
    int64_t sh[3] = {6, 8, 5};
    int64_t st[3] = {40, 1, 8};
    int64_t sh2[2] = {2, 3};
    int64_t i;
    int ok;
    oti_ctx ctx;

    // nd_alloc_strided: compact SoA strides accepted and kept
    check(nd_alloc_strided(NULL, OTI_F64, 3, sh, st, ND_ALLOC_ZERO, &a) == OTI_OK && a.strides[0] == 40 &&
          a.strides[1] == 1 && a.strides[2] == 8 && a.shape[0] == 6,
                  "fix3: nd_alloc_strided SoA (6,8,5) strides (40,1,8)");
    check((a.flags & ND_RETAINED) && (a.flags & ND_WRITEABLE) && !(a.flags & (ND_C_CONTIG | ND_F_CONTIG)),
          "fix3: SoA flags: retained, writeable, neither C nor F contiguous");
    ok = 1;
    for (i = 0; i < 240; i++){
        ok = ok && ((double*)a.data)[i] == 0.0;
    }
    check(ok, "fix3: nd_alloc_strided with ND_ALLOC_ZERO zero-fills the whole span");
    check(nd_buffer_nbytes(a.buf) >= 240 * 8 && (nd_buffer_state(a.buf) & ND_STATE_GROWABLE),
          "fix3: SoA buffer spans the array and is GROWABLE");
    nd_release(&a);
    {
        int64_t c2[2] = {3, 1};
        check(nd_alloc_strided(NULL, OTI_F64, 2, sh2, c2, 0, &a) == OTI_OK && (a.flags & ND_C_CONTIG),
              "fix3: nd_alloc_strided with C strides is a C array");
        nd_release(&a);
    }
    {
        int64_t ov[2] = {1, 1};
        int64_t gap[2] = {4, 1};
        int64_t neg[2] = {3, -1};
        scribble(&a);
        check(nd_alloc_strided(NULL, OTI_F64, 2, sh2, ov, 0, &a) == OTI_ERR_LAYOUT && is_empty_state(&a),
              "fix3: overlapping strides (1,1) -> LAYOUT, res empty");
        scribble(&a);
        check(nd_alloc_strided(NULL, OTI_F64, 2, sh2, gap, 0, &a) == OTI_ERR_LAYOUT && is_empty_state(&a),
              "fix3: gapped strides (4,1) for shape (2,3) -> LAYOUT, res empty");
        scribble(&a);
        check(nd_alloc_strided(NULL, OTI_F64, 2, sh2, neg, 0, &a) == OTI_ERR_LAYOUT && is_empty_state(&a),
              "fix3: a negative stride -> LAYOUT");
        oti_ctx_init(&ctx);
        ctx.max_alloc_bytes = 64;
        scribble(&a);
        check(nd_alloc_strided(&ctx, OTI_F64, 3, sh, st, 0, &a) == OTI_ERR_MEMORY && is_empty_state(&a),
              "fix3: nd_alloc_strided over the budget -> MEMORY");
    }

    // nd_set_layout after nd_grow
    {
        int64_t four[1] = {4}, ten[1] = {10}, sh25[2] = {2, 5}, st25[2] = {5, 1};
        int64_t fit, big[1];
        nd_alloc(NULL, OTI_F64, 1, four, ND_LAYOUT_C, 0, &root);
        check(nd_grow(NULL, &root, 80, 32) == OTI_OK, "fix3: grow to 80 bytes");
        fit = nd_buffer_nbytes(root.buf) / 8;
        check(fit >= 10, "fix3: the grown span holds at least 10 doubles");
        check(nd_set_layout(&root, 1, ten, (int64_t[]){1}) == OTI_OK && root.shape[0] == 10 &&
                root.ndim == 1 &&
              (root.flags & ND_C_CONTIG) && (root.flags & ND_RETAINED),
                      "fix3: nd_set_layout (10,) after growth");
        check(nd_set_layout(&root, 2, sh25, st25) == OTI_OK && root.ndim == 2 && root.shape[1] == 5 &&
              root.strides[0] == 5, "fix3: nd_set_layout (2,5)");
        big[0] = fit + 1;
        check(nd_set_layout(&root, 1, big, (int64_t[]){1}) == OTI_ERR_LAYOUT && root.ndim == 2 &&
              root.shape[0] == 2 && root.shape[1] == 5 && root.strides[0] == 5 && root.strides[1] == 1,
              "fix3: nd_set_layout past the span -> LAYOUT, root unchanged");
        check(nd_set_layout(&root, 1, (int64_t[]){-1}, (int64_t[]){1}) == OTI_ERR_SHAPE && root.ndim == 2,
              "fix3: nd_set_layout with a negative extent -> SHAPE, root unchanged");
        t = root;
        t.flags &= ~ND_RETAINED;
        check(nd_set_layout(&t, 1, ten, (int64_t[]){1}) == OTI_ERR_ARGUMENT,
                "fix3: nd_set_layout of a temporary -> ARGUMENT");
        check(nd_set_layout(NULL, 1, ten, (int64_t[]){1}) == OTI_ERR_ARGUMENT,
                "fix3: nd_set_layout(NULL) -> ARGUMENT");
        nd_release(&root);
    }

    // S25: results of nd_copy, nd_binary and an import conversion are growable when unshared
    {
        double v[4] = {1, 2, 3, 4};
        int64_t s4[1] = {4};
        static float f[4] = {1.f, 2.f, 3.f, 4.f};
        src_t d;
        cb_t cb;
        make_desc(&src, v, OTI_F64, 1, s4, (int64_t[]){1}, ND_WRITEABLE);
        nd_wrap(NULL, &src, v, sizeof(v), NULL, NULL, &root);
        check(nd_copy(NULL, &root, ND_LAYOUT_C, &r) == OTI_OK &&
              nd_grow(NULL, &r, nd_buffer_nbytes(r.buf) + 64, 8) == OTI_OK,
                      "fix3.S25: nd_grow succeeds on an nd_copy result");
        nd_release(&r);
        check(nd_binary_scalar(NULL, ND_OP_ADD, &root, 1.0, 0, &r) == OTI_OK &&
              nd_grow(NULL, &r, nd_buffer_nbytes(r.buf) + 64, 8) == OTI_OK,
              "fix3.S25: nd_grow succeeds on an elementwise result");
        nd_release(&r);
        d = make_src(f, 1, 4, 0, ND_SRC_FLOAT, 4);
        check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK &&
              nd_grow(NULL, &r, nd_buffer_nbytes(r.buf) + 64, 8) == OTI_OK,
              "fix3.S25: nd_grow succeeds on an nd_import conversion");
        nd_release(&r);
        // a zero-copy (wrapped) import stays borrowed
        d = make_src(v, 1, 4, 0, ND_SRC_FLOAT, 8);
        check(do_import(&d, OTI_F64, 0, &cb, &r) == OTI_OK && nd_grow(NULL, &r, 4096, 8) == OTI_ERR_BUSY,
              "fix3.S25: a zero-copy import is still borrowed (BUSY)");
        nd_release(&r);
        nd_release(&root);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 4: nd_alloc_strided with a stride that overflows the span arithmetic.
static void test_fix4_core(void){

    ndarr_t r = {0};
    int64_t two[1] = {2};
    int64_t big[1] = {INT64_MAX};

    scribble(&r);
    check(nd_alloc_strided(NULL, OTI_F64, 1, two, big, 0, &r) == OTI_ERR_LAYOUT && is_empty_state(&r),
          "fix4: nd_alloc_strided {2} strides {INT64_MAX} -> LAYOUT, res empty");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element `lin` (logical C order) of an F64 array.
static double get_f_core(const ndarr_t* a, int64_t lin){

    int64_t off = 0, rem = lin;
    int32_t k;

    for (k = a->ndim - 1; k >= 0; k--){
        off += (rem % a->shape[k]) * a->strides[k];
        rem /= a->shape[k];
    }
    return ((double*)a->data)[off];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Phase 6a: the darr_t adapters (compat_darr.h): BORROW, RETAIN, TAKE, nd_as_darr.
static int darr_is_empty(const darr_t* d){

    return d->p_data == NULL && d->nrows == 0 && d->ncols == 0 && d->size == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_compat(void){

    darr_t d, e;
    ndarr_t a = {0}, b = {0}, c = {0};
    int64_t i, j;
    int ok;
    oti_ctx ctx;

    // 1: BORROW
    d = darr_zeros(3, 4);
    for (i = 0; i < 12; i++){
        d.p_data[i] = (double)(i + 1);
    }
    check(nd_from_darr(NULL, &d, ND_DARR_BORROW, &a) == OTI_OK, "compat BORROW: OK");
    check(a.ndim == 2 && a.shape[0] == 3 && a.shape[1] == 4 && a.strides[0] == 4 && a.strides[1] == 1 &&
          a.data == (void*)d.p_data && a.buf == NULL && !(a.flags & ND_RETAINED) &&
                  (a.flags & ND_WRITEABLE) &&
          (a.flags & ND_C_CONTIG) && a.dtype == OTI_F64,
                  "BORROW: (3,4), strides (4,1), C | WRITEABLE, buf NULL, data = p_data");
    ok = 1;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            ok = ok && ((double*)a.data)[i * 4 + j] == darr_get_item_ij(&d, (uint64_t)i, (uint64_t)j);
        }
    }
    check(ok, "BORROW: values equal darr_get_item_ij");
    check(nd_unary_to(NULL, ND_FN_NEG, &a, &a) == OTI_OK && d.p_data[0] == -1.0 && d.p_data[11] == -12.0,
          "BORROW: an elementwise _to through the view writes the darr");
    nd_release(&a);
    check(d.p_data != NULL && d.size == 12 && d.p_data[5] == -6.0,
            "BORROW: nd_release only resets; the darr is intact");
    darr_free(&d);

    // 2: RETAIN
    d = darr_zeros(2, 5);
    check(nd_from_darr(NULL, &d, ND_DARR_RETAIN, &a) == OTI_OK && (a.flags & ND_RETAINED) &&
            a.buf != NULL,
          "compat RETAIN: a retained array");
    check(nd_buffer_refs(a.buf) == 1 && nd_buffer_base(a.buf) == (const void*)d.p_data &&
          nd_buffer_nbytes(a.buf) == 8 * 10 && !(nd_buffer_state(a.buf) & ND_STATE_OWNS),
          "RETAIN: refs 1, base = p_data, nbytes = 8 * size, not OWNS");
    check(nd_grow(NULL, &a, 4096, 8) == OTI_ERR_BUSY,
            "RETAIN: nd_grow -> BUSY (the memory belongs to the darr)");
    nd_release(&a);
    check(d.p_data != NULL && d.size == 10, "RETAIN: after nd_release the darr is intact");
    darr_free(&d);

    // 3: TAKE
    d = darr_zeros(3, 3);
    for (i = 0; i < 9; i++){
        d.p_data[i] = (double)i;
    }
    check(nd_from_darr(NULL, &d, ND_DARR_TAKE, &a) == OTI_OK && darr_is_empty(&d),
            "compat TAKE: OK, src emptied");
    check((a.flags & ND_RETAINED) && nd_buffer_refs(a.buf) == 1 && get_f_core(&a, 4) == 4.0 &&
          (nd_buffer_state(a.buf) & ND_STATE_WRITEABLE), "TAKE: a retained array holding the values");
    nd_release(&a);                        // frees the memory: leaks / ASan check it
    check(a.buf == NULL, "TAKE: the memory is freed at the last release");
    // failures free the memory and empty src
    d = darr_zeros(2, 2);
    nd_test_fail_alloc(1);
    check(nd_from_darr(NULL, &d, ND_DARR_TAKE, &a) == OTI_ERR_MEMORY && darr_is_empty(&d) &&
            is_empty_state(&a),
          "TAKE with an allocation failure -> MEMORY, src emptied, out empty");
    nd_test_fail_alloc(0);
    d = darr_zeros(2, 2);
    d.size = 5;
    check(nd_from_darr(NULL, &d, ND_DARR_TAKE, &a) == OTI_ERR_ARGUMENT && darr_is_empty(&d) &&
            is_empty_state(&a),
          "TAKE with size != nrows * ncols -> ARGUMENT, src emptied");
    d = darr_zeros(2, 2);
    oti_ctx_init(&ctx);
    ctx.device_type = 2;
    check(nd_from_darr(&ctx, &d, ND_DARR_TAKE, &a) == oti_ctx_check(&ctx) && darr_is_empty(&d) &&
            is_empty_state(&a),
          "TAKE with an invalid context -> its oti_ctx_check status, src emptied");
    d = darr_zeros(2, 2);
    oti_ctx_init(&ctx);
    ctx.exec.backend = 77;
    check(nd_from_darr(&ctx, &d, ND_DARR_TAKE, &a) == OTI_ERR_BACKEND && darr_is_empty(&d),
            "TAKE with an unavailable backend -> BACKEND");
    d = darr_zeros(2, 2);
    check(nd_from_darr(NULL, &d, 9, &a) == OTI_ERR_ARGUMENT && is_empty_state(&a),
            "unknown mode -> ARGUMENT, out empty");
    darr_free(&d);

    // 4: empty darr_t and argument errors
    e = darr_init();
    check(nd_from_darr(NULL, &e, ND_DARR_BORROW, &a) == OTI_OK && a.ndim == 2 && a.shape[0] == 0 &&
            a.shape[1] == 0,
          "an empty darr (darr_init) as BORROW: shape (0, 0)");
    nd_release(&a);
    check(nd_from_darr(NULL, &e, ND_DARR_RETAIN, &a) == OTI_OK && a.shape[0] == 0 && a.shape[1] == 0,
            "empty darr as RETAIN: (0, 0)");
    nd_release(&a);
    d = darr_zeros(2, 3);
    d.size = 7;
    check(nd_from_darr(NULL, &d, ND_DARR_BORROW, &a) == OTI_ERR_ARGUMENT && is_empty_state(&a),
            "BORROW with size mismatch -> ARGUMENT");
    check(nd_from_darr(NULL, &d, ND_DARR_RETAIN, &a) == OTI_ERR_ARGUMENT,
            "RETAIN with size mismatch -> ARGUMENT");
    d.size = 6;
    {
        double* keep = d.p_data;
        d.p_data = NULL;
        check(nd_from_darr(NULL, &d, ND_DARR_BORROW, &a) == OTI_ERR_ARGUMENT,
                "NULL p_data with size > 0 -> ARGUMENT");
        d.p_data = keep;
    }
    darr_free(&d);
    e = darr_init();
    e.nrows = UINT64_MAX;
    e.ncols = 0;
    e.size = 0;
    check(nd_from_darr(NULL, &e, ND_DARR_BORROW, &a) == OTI_ERR_SIZE, "nrows above INT64_MAX -> SIZE");
    check(nd_from_darr(NULL, NULL, ND_DARR_BORROW, &a) == OTI_ERR_ARGUMENT, "NULL src -> ARGUMENT");

    // 5: nd_as_darr
    {
        darr_t v;
        int64_t sh2[2] = {3, 4}, sh1[1] = {5};
        nd_alloc(NULL, OTI_F64, 2, sh2, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
        check(nd_as_darr(&a, 0, &v) == OTI_OK && v.nrows == 3 && v.ncols == 4 && v.size == 12 &&
              v.p_data == (double*)a.data, "nd_as_darr of (3,4): 3 x 4 over the same memory");
        nd_release(&a);
        nd_alloc(NULL, OTI_F64, 1, sh1, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
        check(nd_as_darr(&a, 1, &v) == OTI_OK && v.nrows == 1 && v.ncols == 5 && v.size == 5,
                "nd_as_darr of (5,): 1 x 5 (a row)");
        nd_release(&a);
        nd_alloc(NULL, OTI_F64, 0, NULL, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
        check(nd_as_darr(&a, 0, &v) == OTI_OK && v.nrows == 1 && v.ncols == 1 && v.size == 1,
                "nd_as_darr of rank 0: 1 x 1");
        nd_release(&a);
        // transposed / strided -> LAYOUT
        nd_alloc(NULL, OTI_F64, 2, sh2, ND_LAYOUT_C, 0, &a);
        nd_view_transpose(&a, 0, NULL, &b);
        oti_ctx_clear_error(NULL);
        v.nrows = 99;
        check(nd_as_darr(&b, 0, &v) == OTI_ERR_LAYOUT && darr_is_empty(&v),
                "nd_as_darr of a transposed view -> LAYOUT, out the empty darr");
        check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_LAYOUT,
                "nd_as_darr records its failure as the last error");
        oti_ctx_clear_error(NULL);
        nd_release(&a);
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, 2, 2}, ND_LAYOUT_C, 0, &a);
        check(nd_as_darr(&a, 0, &v) == OTI_ERR_SHAPE && darr_is_empty(&v),
                "nd_as_darr of rank 3 -> SHAPE");
        nd_release(&a);
        nd_alloc(NULL, OTI_I64, 2, sh2, ND_LAYOUT_C, 0, &a);
        check(nd_as_darr(&a, 0, &v) == OTI_ERR_DTYPE && darr_is_empty(&v), "nd_as_darr of I64 -> DTYPE");
        nd_release(&a);
        // read-only arrays: reading is fine, writing is READONLY
        {
            double mem[4] = {1, 2, 3, 4};
            ndarr_t d0 = {0}, ro = {0};
            int64_t s22[2] = {2, 2};
            make_desc(&d0, mem, OTI_F64, 2, s22, (int64_t[]){2, 1}, 0);
            nd_wrap(NULL, &d0, NULL, -1, NULL, NULL, &ro);
            check(nd_as_darr(&ro, 0, &v) == OTI_OK && v.p_data == mem,
                    "nd_as_darr of a read-only array for reading: OK");
            check(nd_as_darr(&ro, 1, &v) == OTI_ERR_READONLY && darr_is_empty(&v),
                    "nd_as_darr(writeable = 1) of a read-only array -> READONLY");
            nd_release(&ro);
        }
        check(nd_as_darr(NULL, 0, &v) == OTI_ERR_ARGUMENT, "nd_as_darr(NULL) -> ARGUMENT");
    }

    // 6: round trip
    {
        darr_t r;
        d = darr_zeros(4, 3);
        nd_from_darr(NULL, &d, ND_DARR_BORROW, &c);
        check(nd_as_darr(&c, 1, &r) == OTI_OK && r.p_data == d.p_data && r.nrows == d.nrows &&
                r.ncols == d.ncols &&
              r.size == d.size, "round trip: nd_as_darr(nd_from_darr(d)) has d's fields");
        nd_release(&c);
        darr_free(&d);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    printf("TSan build: %d\n", TEST_TSAN);

    test_descriptor_basics();
    test_contiguity_flags();
    test_buffer_alloc_state();
    test_alloc_failures();
    test_state_transitions();
    test_wrap_success_and_callback();
    test_wrap_failures_callback_once();
    test_growth();
    test_validate_table();
    test_validate_randomized();
    test_overlap_accepts_views();
    test_overlap_rejects();
    test_may_share_memory();
    test_pep3118_classify();
    test_dlpack_classify();
    test_import_zero_copy();
    test_import_conversions_to_f64();
    test_import_swapped_unaligned_strided();
    test_import_mask_and_index();
    test_import_rejections_and_writeable();
    test_import_failure_injection();
    test_copy_basic_and_failure();
    test_to_view_fields();
    test_from_view();
    test_last_error_of_failing_calls();
    if (TEST_TSAN){
        test_races_tsan();
    } else {
        printf("skipped: TSan race test (build with -fsanitize=thread)\n");
    }

    test_fix1_core();

    test_fix2_core();

    test_fix3_core();

    test_fix4_core();

    test_compat();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
