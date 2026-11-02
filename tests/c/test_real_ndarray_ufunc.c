/* Tests of the ndarray creators, copies, elementwise operations and assignment
 * (include/oti/real/ndarray/{create,elementwise}.h, Phase 1): nd_empty / zeros / ones / full / eye /
 * arange / linspace, nd_copy / ascontiguous / asfortran / reshape, nd_binary(_to), nd_binary_scalar(_to),
 * nd_unary(_to), nd_assign, nd_fill.
 *
 * Written from PLAN-ndarray-contracts.md (3.3 read-only, 3.4 per-operation aliasing rules, 5.4
 * determinism, the creator rows of the test matrix) independently of the implementation files. Oracles:
 * plain coordinate loops and the C library (pow, sin, exp, ... are called by the test on the same inputs;
 * a mul followed by an add is split through a volatile so that this file's compiler cannot fuse it, the
 * library being built with -ffp-contract=off); NumPy 2's documented values for the creators (arange and
 * linspace follow the formulas of create.h; eye is the definition); hand-derived values elsewhere (each
 * says where it comes from). Floating-point results are compared bitwise (any NaN equals any NaN)
 * except where the comment says "numerically": maximum / minimum, whose zero sign is not specified.
 *
 * Guard regions: outputs are views into buffers pre-filled with a NaN canary pattern; after every write
 * path the elements outside the view are checked untouched. Aliasing: exact alias runs in place with a
 * 1-byte temporary budget (so any temporary would fail), a partial overlap needs the temporary (the same
 * budget fails it with MEMORY, so does an injected allocation failure) and gives snapshot results.
 * Determinism: the same operation under the serial backend and under 2, 3 and N OpenMP threads, on
 * sizes around the 4096-element chunk boundaries, is compared with memcmp. */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // contracts S23
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/core/exec.h>
#include <oti/real/ndarray/structures.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>
#include <oti/real/ndarray/views.h>
#include <oti/real/ndarray/elementwise.h>

static int n_failed = 0;
static uint64_t g_rng_state;

#define HS 0x1
#define HP 0x2
#define HT 0x4


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
static int64_t rng_int(int64_t n){

    return (int64_t)(rng_next() % (uint64_t)n);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rng_uniform(void){

    return (double)(rng_next() >> 11) / (double)(1ULL << 53);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A value that stresses floating point: mostly moderate, sometimes zero, negative zero, huge, tiny,
// infinite or NaN.
static double rng_value(void){

    switch (rng_int(24)){
        case 0:  return 0.0;
        case 1:  return -0.0;
        case 2:  return INFINITY;
        case 3:  return -INFINITY;
        case 4:  return NAN;
        case 5:  return 1e308;
        case 6:  return -1e-308;
        case 7:  return 1.0;
        case 8:  return -1.0;
        case 9:  return 2.0;
        case 10: return 0.5;
        default: return (rng_uniform() - 0.5) * 20.0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_bits(double a, double b){

    if (isnan(a) && isnan(b)){
        return 1;
    }
    return memcmp(&a, &b, sizeof(double)) == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_num(double a, double b){

    if (isnan(a) && isnan(b)){
        return 1;
    }
    return a == b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int64_t shape_size(int32_t nd, const int64_t* shape){

    int64_t n = 1;
    int32_t k;

    for (k = 0; k < nd; k++){
        n *= shape[k];
    }
    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void make_desc(ndarr_t* a, void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                      const int64_t* strides, int32_t flags){

    int32_t k;

    memset(a, 0, sizeof(*a));
    a->data = data;
    a->dtype = dtype;
    a->ndim = ndim;
    a->flags = flags;
    for (k = 0; k < ndim; k++){
        a->shape[k] = shape[k];
        a->strides[k] = strides[k];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static nd_index_t mk_slice(int has, int64_t start, int64_t stop, int64_t step){

    nd_index_t s;

    memset(&s, 0, sizeof(s));
    s.kind = ND_IDX_SLICE;
    s.has = has;
    s.start = start;
    s.stop = stop;
    s.step = step;
    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Pointer to the element of logical C-order position `lin` of any-dtype array.
static void* elem_ptr(const ndarr_t* a, int64_t lin){

    int64_t off = 0, rem = lin;
    int32_t k;

    for (k = a->ndim - 1; k >= 0; k--){
        off += (rem % a->shape[k]) * a->strides[k];
        rem /= a->shape[k];
    }
    return (char*)a->data + off * nd_itemsize(a->dtype);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double get_f(const ndarr_t* a, int64_t lin){

    return *(double*)elem_ptr(a, lin);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void set_f(ndarr_t* a, int64_t lin, double v){

    *(double*)elem_ptr(a, lin) = v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-axis recipe for a test view: plain, reversed (step -1) or doubled (step 2 over a double-size base).
// `kind` picks one of: 0 C base, 1 F base, 2 random slices over a bigger base.
static void make_view(int32_t nd, const int64_t* shape, int kind, int32_t dtype, ndarr_t* base,
        ndarr_t* view){

    int64_t big[OTI_ND_MAXDIM];
    nd_index_t idx[OTI_ND_MAXDIM];
    int32_t k;
    int st;

    for (k = 0; k < nd; k++){
        int64_t pick = (kind == 2 && shape[k] > 0) ? rng_int(3) : 0;
        big[k] = (pick == 2) ? 2 * shape[k] : shape[k];
        if (pick == 0){
            idx[k] = mk_slice(0, 0, 0, 0);
        } else if (pick == 1){
            idx[k] = mk_slice(HS | HT, shape[k] - 1, 0, -1);
        } else {
            idx[k] = mk_slice(HS | HT, 0, 0, 2);
        }
    }
    st = nd_alloc(NULL, dtype, nd, big, kind == 1 ? ND_LAYOUT_F : ND_LAYOUT_C, ND_ALLOC_ZERO, base);
    if (st != OTI_OK){
        fprintf(stderr, "make_view: nd_alloc failed (%d)\n", st);
        exit(2);
    }
    st = nd_view_index(base, nd, idx, view);
    if (st != OTI_OK){
        fprintf(stderr, "make_view: view_index failed (%d)\n", st);
        exit(2);
    }
    // a doubled axis of an odd extent has one more element than asked: trim
    for (k = 0; k < nd; k++){
        view->shape[k] = shape[k];
    }
    nd_update_flags(view);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A plain C or F array holding `vals` (logical C order).
static void make_from(int32_t nd, const int64_t* shape, int32_t layout, const double* vals, ndarr_t* a){

    int64_t n = shape_size(nd, shape), i;

    if (nd_alloc(NULL, OTI_F64, nd, shape, layout, ND_ALLOC_ZERO, a) != OTI_OK){
        fprintf(stderr, "make_from: nd_alloc failed\n");
        exit(2);
    }
    for (i = 0; i < n; i++){
        set_f(a, i, vals[i]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int arr_equals(const ndarr_t* a, const double* expect, int64_t n, int bitwise){

    int64_t i;

    if (shape_size(a->ndim, a->shape) != n){
        return 0;
    }
    for (i = 0; i < n; i++){
        double g = get_f(a, i);
        if (bitwise ? !same_bits(g, expect[i]) : !same_num(g, expect[i])){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// mul then add through a volatile: never fused.
static double mul_add(double a, double b, double c){

    volatile double p = a * b;

    return p + c;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Creators
// =======================================================================================================

// *******************************************************************************************************
static void test_filled_creators(void){

    ndarr_t a = {0};
    int64_t shape[3] = {2, 3, 4};
    int64_t i, n;
    int ok;
    uint64_t negzero_bits, nan_bits;
    double nz = -0.0, qn = NAN;

    memcpy(&negzero_bits, &nz, 8);
    memcpy(&nan_bits, &qn, 8);

    check(nd_empty(NULL, 3, shape, ND_LAYOUT_C, &a) == OTI_OK && a.dtype == OTI_F64 && a.ndim == 3 &&
          (a.flags & ND_C_CONTIG) && (a.flags & ND_WRITEABLE) && (a.flags & ND_RETAINED) &&
          a.strides[0] == 12 && a.strides[2] == 1, "nd_empty C: shape, strides, flags");
    nd_release(&a);
    check(nd_empty(NULL, 3, shape, ND_LAYOUT_F, &a) == OTI_OK && (a.flags & ND_F_CONTIG) &&
            a.strides[0] == 1 &&
          a.strides[1] == 2 && a.strides[2] == 6, "nd_empty F: strides (1,2,6)");
    nd_release(&a);

    n = 24;
    nd_zeros(NULL, 3, shape, ND_LAYOUT_C, &a);
    ok = 1;
    for (i = 0; i < n; i++){
        double z = get_f(&a, i);
        ok = ok && same_bits(z, 0.0);
    }
    check(ok, "nd_zeros: +0.0 everywhere");
    nd_release(&a);
    nd_zeros(NULL, 3, shape, ND_LAYOUT_F, &a);
    ok = 1;
    for (i = 0; i < n; i++){
        ok = ok && same_bits(get_f(&a, i), 0.0);
    }
    check(ok && (a.flags & ND_F_CONTIG), "nd_zeros F");
    nd_release(&a);

    nd_ones(NULL, 3, shape, ND_LAYOUT_C, &a);
    ok = 1;
    for (i = 0; i < n; i++){
        ok = ok && get_f(&a, i) == 1.0;
    }
    check(ok, "nd_ones");
    nd_release(&a);

    nd_full(NULL, 3, shape, 2.5, ND_LAYOUT_F, &a);
    ok = 1;
    for (i = 0; i < n; i++){
        ok = ok && get_f(&a, i) == 2.5;
    }
    check(ok && (a.flags & ND_F_CONTIG), "nd_full 2.5, F layout");
    nd_release(&a);
    nd_full(NULL, 3, shape, -0.0, ND_LAYOUT_C, &a);
    ok = 1;
    for (i = 0; i < n; i++){
        uint64_t bits;
        double v = get_f(&a, i);
        memcpy(&bits, &v, 8);
        ok = ok && bits == negzero_bits;
    }
    check(ok, "nd_full stores -0.0 with its sign");
    nd_release(&a);
    nd_full(NULL, 3, shape, NAN, ND_LAYOUT_C, &a);
    ok = 1;
    for (i = 0; i < n; i++){
        ok = ok && isnan(get_f(&a, i));
    }
    check(ok, "nd_full stores NaN");
    nd_release(&a);

    // rank 0 and zero size
    check(nd_full(NULL, 0, NULL, 7.0, ND_LAYOUT_C, &a) == OTI_OK && a.ndim == 0 && get_f(&a, 0) == 7.0 &&
          (a.flags & ND_C_CONTIG) && (a.flags & ND_F_CONTIG), "nd_full rank 0");
    nd_release(&a);
    {
        int64_t zs[2] = {0, 5};
        check(nd_zeros(NULL, 2, zs, ND_LAYOUT_C, &a) == OTI_OK && nd_size(&a) == 0 && a.shape[0] == 0 &&
              a.shape[1] == 5, "nd_zeros of shape (0,5)");
        nd_release(&a);
    }

    // statuses are those of nd_alloc
    {
        int64_t neg[1] = {-1};
        check(nd_zeros(NULL, 1, neg, ND_LAYOUT_C, &a) == OTI_ERR_SHAPE,
                "nd_zeros negative extent -> SHAPE");
        check(nd_ones(NULL, 1, shape, 9, &a) == OTI_ERR_ARGUMENT, "nd_ones bad layout -> ARGUMENT");
        check(nd_full(NULL, 40, shape, 1.0, ND_LAYOUT_C, &a) == OTI_ERR_SHAPE,
                "nd_full ndim 40 -> SHAPE");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_eye(void){

    static const struct { int64_t n, m, k; } cases[] = {
        {3, 3, 0}, {3, 4, 1}, {4, 3, -1}, {3, 3, 2}, {3, 3, -2}, {3, 3, 3}, {3, 3, -3}, {3, 3, 10}, {5, 2,
                0},
        {2, 5, 4}, {1, 1, 0}, {0, 3, 0}, {3, 0, 0}, {0, 0, 0}, {4, 4, 1}, {6, 4, -3}
    };
    int c, layout, ok_all = 1;

    for (c = 0; c < (int)(sizeof(cases) / sizeof(cases[0])); c++){
        for (layout = 0; layout < 2; layout++){
            ndarr_t a = {0};
            int64_t i, j;
            int ok;
            if (nd_eye(NULL, cases[c].n, cases[c].m, cases[c].k, layout, &a) != OTI_OK){
                ok_all = 0;
                continue;
            }
            ok = (a.ndim == 2 && a.shape[0] == cases[c].n && a.shape[1] == cases[c].m &&
                  (layout == ND_LAYOUT_C ? (a.flags & ND_C_CONTIG) : (a.flags & ND_F_CONTIG)));
            for (i = 0; ok && i < cases[c].n; i++){
                for (j = 0; j < cases[c].m; j++){
                    double expect = (j - i == cases[c].k) ? 1.0 : 0.0;
                    double got = ((double*)a.data)[i * a.strides[0] + j * a.strides[1]];
                    if (!same_bits(got, expect)){
                        ok = 0;
                    }
                }
            }
            if (!ok){
                fprintf(stderr, "  eye(%lld, %lld, %lld) layout %d wrong\n", (long long)cases[c].n,
                        (long long)cases[c].m, (long long)cases[c].k, layout);
                ok_all = 0;
            }
            nd_release(&a);
        }
    }
    check(ok_all, "nd_eye: 16 shapes and diagonals x C / F against the definition (j - i == k)");
    {
        ndarr_t a = {0};
        check(nd_eye(NULL, -1, 3, 0, ND_LAYOUT_C, &a) == OTI_ERR_SHAPE, "nd_eye negative n -> SHAPE");
        check(nd_eye(NULL, 3, -2, 0, ND_LAYOUT_C, &a) == OTI_ERR_SHAPE, "nd_eye negative m -> SHAPE");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// NumPy's arange fill as documented in create.h: y0 = start, y1 = start + step, delta = y1 - y0,
// y[i] = start + i * delta for i >= 2.
static void ref_arange(double start, double step, int64_t n, double* y){

    int64_t i;
    double y1, delta;

    if (n > 0){
        y[0] = start;
    }
    if (n > 1){
        y1 = start + step;
        y[1] = y1;
        delta = y1 - start;
        for (i = 2; i < n; i++){
            y[i] = mul_add((double)i, delta, start);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_arange(void){

    ndarr_t a = {0};
    double expect[64];
    int ok;
    int64_t i;

    // hand-derived
    check(nd_arange(NULL, 0, 5, 1, &a) == OTI_OK && a.ndim == 1 && a.shape[0] == 5 &&
          get_f(&a, 0) == 0 && get_f(&a, 1) == 1 && get_f(&a, 4) == 4, "arange(0, 5, 1) = 0..4");
    nd_release(&a);
    check(nd_arange(NULL, 5, 0, -1, &a) == OTI_OK && a.shape[0] == 5 && get_f(&a, 0) == 5 &&
          get_f(&a, 4) == 1, "arange(5, 0, -1) = 5, 4, 3, 2, 1");
    nd_release(&a);
    check(nd_arange(NULL, 0, 1, 0.25, &a) == OTI_OK && a.shape[0] == 4 && get_f(&a, 1) == 0.25 &&
          get_f(&a, 3) == 0.75, "arange(0, 1, 0.25) = 0, .25, .5, .75");
    nd_release(&a);
    check(nd_arange(NULL, 3, 3, 1, &a) == OTI_OK && a.shape[0] == 0 && a.ndim == 1,
            "arange(3, 3, 1): empty");
    nd_release(&a);
    check(nd_arange(NULL, 5, 0, 1, &a) == OTI_OK && a.shape[0] == 0,
            "arange(5, 0, 1): empty (wrong direction)");
    nd_release(&a);
    check(nd_arange(NULL, 0, 5, -1, &a) == OTI_OK && a.shape[0] == 0, "arange(0, 5, -1): empty");
    nd_release(&a);
    check(nd_arange(NULL, 0, 10, 3, &a) == OTI_OK && a.shape[0] == 4 && get_f(&a, 3) == 9.0,
          "arange(0, 10, 3): length ceil(10/3) = 4, last 9");
    nd_release(&a);
    check(nd_arange(NULL, 0, 1, 0.1, &a) == OTI_OK && a.shape[0] == 10, "arange(0, 1, 0.1): length 10");
    ref_arange(0.0, 0.1, 10, expect);
    check(arr_equals(&a, expect, 10, 1), "arange(0, 1, 0.1): values follow y[i] = start + i * delta");
    nd_release(&a);
    check(nd_arange(NULL, 0, 0.3, 0.1, &a) == OTI_OK && a.shape[0] == 3,
          "arange(0, 0.3, 0.1): length ceil(0.3 / 0.1) = ceil(2.9999999999999996) = 3 as NumPy");
    nd_release(&a);

    // [k9]: np.arange(1e16, 1e16 + 10, 1) - 1e16 is ten zeros (y1 rounds to y0, delta = 0)
    check(nd_arange(NULL, 1e16, 1e16 + 10, 1, &a) == OTI_OK && a.shape[0] == 10,
            "arange(1e16, 1e16 + 10, 1): length 10");
    ok = 1;
    for (i = 0; i < 10; i++){
        ok = ok && ((get_f(&a, i) - 1e16) == 0.0);
    }
    check(ok, "arange(1e16, 1e16 + 10, 1) - 1e16 equals NumPy: ten zeros ([k9])");
    nd_release(&a);

    // random start / step against the documented fill
    {
        int it, okr = 1;
        rng_seed(2718);
        for (it = 0; it < 300; it++){
            double start = (rng_uniform() - 0.5) * 100.0;
            double step = (rng_uniform() - 0.5) * 7.0;
            double stop = start + (rng_uniform() - 0.3) * 60.0;
            double len_f;
            int64_t n;
            if (fabs(step) < 1e-3){
                step = 0.37;
            }
            len_f = ceil((stop - start) / step);
            n = len_f > 0 ? (int64_t)len_f : 0;
            if (n > 64){
                continue;
            }
            if (nd_arange(NULL, start, stop, step, &a) != OTI_OK || a.shape[0] != n){
                okr = 0;
                continue;
            }
            ref_arange(start, step, n, expect);
            okr = okr && arr_equals(&a, expect, n, 1);
            nd_release(&a);
        }
        check(okr, "arange: 300 random (start, stop, step) agree with the documented fill, bitwise");
    }

    // errors
    check(nd_arange(NULL, 0, 5, 0, &a) == OTI_ERR_ARGUMENT, "arange: step 0 -> ARGUMENT");
    check(nd_arange(NULL, 0, NAN, 1, &a) == OTI_ERR_ARGUMENT, "arange: NaN stop -> ARGUMENT");
    check(nd_arange(NULL, NAN, 5, 1, &a) == OTI_ERR_ARGUMENT, "arange: NaN start -> ARGUMENT");
    check(nd_arange(NULL, 0, INFINITY, 1, &a) == OTI_ERR_ARGUMENT, "arange: infinite stop -> ARGUMENT");
    check(nd_arange(NULL, 0, 5, INFINITY, &a) == OTI_ERR_ARGUMENT, "arange: infinite step -> ARGUMENT");
    check(nd_arange(NULL, 0, 1e300, 1, &a) == OTI_ERR_SIZE,
            "arange(0, 1e300, 1): length above INT64_MAX -> SIZE");
    {
        oti_ctx ctx;
        oti_ctx_init(&ctx);
        ctx.max_alloc_bytes = 80;
        check(nd_arange(&ctx, 0, 11, 1, &a) == OTI_ERR_MEMORY,
                "arange over the allocation budget -> MEMORY");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// create.h's linspace formula.
static void ref_linspace(double start, double stop, int64_t num, int endpoint, double* y){

    int64_t i;
    double div = (double)(endpoint ? num - 1 : num);
    double step, delta = stop - start;

    if (num <= 0){
        return;
    }
    step = (div > 0) ? delta / div : 0.0;
    for (i = 0; i < num; i++){
        if (div > 0){
            if (step != 0.0){
                y[i] = mul_add((double)i, step, start);
            } else {
                y[i] = mul_add((double)i / div, delta, start);
            }
        } else {
            y[i] = start;
        }
    }
    if (endpoint && num > 1){
        y[num - 1] = stop;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_linspace(void){

    ndarr_t a = {0};
    double expect[200];
    int it, ok;

    check(nd_linspace(NULL, 0, 1, 5, 1, &a) == OTI_OK && a.shape[0] == 5 && get_f(&a, 0) == 0 &&
          get_f(&a, 1) == 0.25 && get_f(&a, 2) == 0.5 && get_f(&a, 3) == 0.75 && get_f(&a, 4) == 1,
          "linspace(0, 1, 5) = 0, .25, .5, .75, 1");
    nd_release(&a);
    check(nd_linspace(NULL, 0, 1, 4, 0, &a) == OTI_OK && a.shape[0] == 4 && get_f(&a, 3) == 0.75,
          "linspace(0, 1, 4, endpoint=False) = 0, .25, .5, .75");
    nd_release(&a);
    check(nd_linspace(NULL, 2, 9, 1, 1, &a) == OTI_OK && a.shape[0] == 1 && get_f(&a, 0) == 2.0,
          "linspace(2, 9, 1) = [2]");
    nd_release(&a);
    check(nd_linspace(NULL, 2, 9, 0, 1, &a) == OTI_OK && a.shape[0] == 0, "linspace num 0: empty");
    nd_release(&a);
    check(nd_linspace(NULL, 3, 3, 4, 1, &a) == OTI_OK && a.shape[0] == 4 && get_f(&a, 0) == 3 &&
          get_f(&a, 2) == 3 && get_f(&a, 3) == 3, "linspace(3, 3, 4): all 3 (step 0 branch)");
    nd_release(&a);
    check(nd_linspace(NULL, 0, 1, 11, 1, &a) == OTI_OK && get_f(&a, 10) == 1.0,
            "linspace: the endpoint is exactly stop");
    nd_release(&a);
    check(nd_linspace(NULL, 0, 1, -1, 1, &a) == OTI_ERR_ARGUMENT, "linspace num -1 -> ARGUMENT");

    rng_seed(1618);
    ok = 1;
    for (it = 0; it < 300; it++){
        double start = (rng_uniform() - 0.5) * 100.0;
        double stop = (rng_int(8) == 0) ? start : (rng_uniform() - 0.5) * 100.0;
        int64_t num = rng_int(60);
        int endpoint = (int)rng_int(2);
        if (nd_linspace(NULL, start, stop, num, endpoint, &a) != OTI_OK || a.shape[0] != num){
            ok = 0;
            continue;
        }
        ref_linspace(start, stop, num, endpoint, expect);
        ok = ok && arr_equals(&a, expect, num, 1);
        nd_release(&a);
    }
    check(ok, "linspace: 300 random cases agree with the documented formula, bitwise");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Copies and view-or-copy conversions
// =======================================================================================================

// *******************************************************************************************************
static void test_copies(void){

    ndarr_t a = {0}, f = {0}, c = {0}, v = {0}, t = {0};
    int64_t sh[2] = {3, 4};
    double vals[12];
    int i, ok;
    int32_t copied;

    for (i = 0; i < 12; i++){
        vals[i] = i;
    }
    make_from(2, sh, ND_LAYOUT_C, vals, &a);
    make_from(2, sh, ND_LAYOUT_F, vals, &f);

    // nd_copy layouts
    check(nd_copy(NULL, &a, ND_LAYOUT_C, &c) == OTI_OK && (c.flags & ND_C_CONTIG) && c.data != a.data &&
          arr_equals(&c, vals, 12, 1), "nd_copy C of a C array");
    nd_release(&c);
    check(nd_copy(NULL, &a, ND_LAYOUT_F, &c) == OTI_OK && (c.flags & ND_F_CONTIG) &&
            !(c.flags & ND_C_CONTIG) &&
          arr_equals(&c, vals, 12, 1), "nd_copy F of a C array");
    nd_release(&c);
    check(nd_copy(NULL, &f, ND_LAYOUT_A, &c) == OTI_OK && (c.flags & ND_F_CONTIG) &&
            !(c.flags & ND_C_CONTIG),
          "nd_copy A of an F array is F");
    nd_release(&c);
    check(nd_copy(NULL, &a, ND_LAYOUT_A, &c) == OTI_OK && (c.flags & ND_C_CONTIG),
            "nd_copy A of a C array is C");
    nd_release(&c);
    check(nd_copy(NULL, &f, ND_LAYOUT_K, &c) == OTI_OK && c.strides[0] == 1 && c.strides[1] == 3 &&
          arr_equals(&c, vals, 12, 1), "nd_copy K of an F array keeps F strides (1, 3)");
    nd_release(&c);
    check(nd_copy(NULL, &a, ND_LAYOUT_K, &c) == OTI_OK && c.strides[0] == 4 && c.strides[1] == 1,
          "nd_copy K of a C array keeps C strides (4, 1)");
    nd_release(&c);
    // K of a transpose of a C array: strides (1, 4) with shape (4, 3) -> positive, same axis order
    nd_view_transpose(&a, 0, NULL, &t);
    check(nd_copy(NULL, &t, ND_LAYOUT_K, &c) == OTI_OK && c.shape[0] == 4 && c.shape[1] == 3 &&
          c.strides[0] == 1 && c.strides[1] == 4, "nd_copy K of a transposed array: strides (1, 4)");
    {
        double tv[12];
        int j;
        for (i = 0; i < 4; i++){
            for (j = 0; j < 3; j++){
                tv[i * 3 + j] = vals[j * 4 + i];
            }
        }
        check(arr_equals(&c, tv, 12, 1), "nd_copy K of a transposed array: logical values");
    }
    nd_release(&c);
    // K of a reversed array: positive strides, same axis order
    {
        nd_index_t idx[2];
        double rv[12];
        idx[0] = mk_slice(HT, 0, 0, -1);
        idx[1] = mk_slice(HT, 0, 0, -1);
        nd_view_index(&a, 2, idx, &v);
        for (i = 0; i < 12; i++){
            rv[i] = vals[11 - i];
        }
        check(nd_copy(NULL, &v, ND_LAYOUT_K, &c) == OTI_OK && c.strides[0] == 4 && c.strides[1] == 1 &&
              arr_equals(&c, rv, 12, 1),
                      "nd_copy K of a reversed C array: positive C strides, logical values");
        nd_release(&c);
        check(nd_copy(NULL, &v, ND_LAYOUT_C, &c) == OTI_OK && arr_equals(&c, rv, 12, 1),
                "nd_copy C of a reversed view");
        nd_release(&c);
    }
    // copies keep the dtype
    {
        ndarr_t u = {0};
        int64_t s1[1] = {5};
        nd_alloc(NULL, OTI_U8, 1, s1, ND_LAYOUT_C, ND_ALLOC_ZERO, &u);
        ((uint8_t*)u.data)[2] = 1;
        check(nd_copy(NULL, &u, ND_LAYOUT_C, &c) == OTI_OK && c.dtype == OTI_U8 &&
                ((uint8_t*)c.data)[2] == 1,
              "nd_copy keeps the dtype (U8)");
        nd_release(&c);
        nd_release(&u);
    }
    // copy of a read-only source is writeable
    {
        ndarr_t d = {0}, ro = {0};
        make_desc(&d, a.data, OTI_F64, 2, sh, a.strides, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        check(nd_copy(NULL, &ro, ND_LAYOUT_C, &c) == OTI_OK && (c.flags & ND_WRITEABLE),
                "copy of a read-only array is writeable");
        nd_release(&c);
        nd_release(&ro);
    }

    // ascontiguous / asfortran
    copied = -1;
    check(nd_ascontiguous(NULL, &a, &c, &copied) == OTI_OK && copied == 0 && c.data == a.data &&
          (c.flags & ND_RETAINED) && nd_buffer_refs(a.buf) == 2,
                  "ascontiguous of a C array: a retained view");
    nd_release(&c);
    check(nd_buffer_refs(a.buf) == 1, "ascontiguous view released");
    check(nd_ascontiguous(NULL, &f, &c, &copied) == OTI_OK && copied == 1 && c.data != f.data &&
          (c.flags & ND_C_CONTIG) && arr_equals(&c, vals, 12, 1), "ascontiguous of an F array: a C copy");
    nd_release(&c);
    check(nd_ascontiguous(NULL, &f, &c, NULL) == OTI_OK, "ascontiguous: copied may be NULL");
    nd_release(&c);
    check(nd_asfortran(NULL, &f, &c, &copied) == OTI_OK && copied == 0 && c.data == f.data,
            "asfortran of an F array: a view");
    nd_release(&c);
    check(nd_asfortran(NULL, &a, &c, &copied) == OTI_OK && copied == 1 && (c.flags & ND_F_CONTIG) &&
          arr_equals(&c, vals, 12, 1), "asfortran of a C array: an F copy");
    nd_release(&c);
    {
        ndarr_t o = {0};
        int64_t s1[1] = {6};
        make_from(1, s1, ND_LAYOUT_C, vals, &o);
        check(nd_ascontiguous(NULL, &o, &c, &copied) == OTI_OK && copied == 0,
                "1-D contiguous: ascontiguous is a view");
        nd_release(&c);
        check(nd_asfortran(NULL, &o, &c, &copied) == OTI_OK && copied == 0,
                "1-D contiguous: asfortran is a view");
        nd_release(&c);
        nd_release(&o);
    }
    {
        ndarr_t s = {0};
        make_from(0, NULL, ND_LAYOUT_C, vals, &s);
        check(nd_ascontiguous(NULL, &s, &c, &copied) == OTI_OK && c.ndim == 0 && copied == 0,
              "ascontiguous of a rank-0 array stays rank 0");
        nd_release(&c);
        nd_release(&s);
    }
    // a transposed array is neither: copy
    check(nd_ascontiguous(NULL, &t, &c, &copied) == OTI_OK && copied == (t.flags & ND_C_CONTIG ? 0 : 1) &&
          (c.flags & ND_C_CONTIG), "ascontiguous of a transposed array");
    nd_release(&c);
    // a trusted temporary (buf NULL) is always copied
    {
        static double mem[12];
        ndarr_t tr = {0};
        for (i = 0; i < 12; i++){
            mem[i] = i;
        }
        nd_wrap_trusted(mem, OTI_F64, 2, sh, NULL, 1, &tr);
        check(nd_ascontiguous(NULL, &tr, &c, &copied) == OTI_OK && copied == 1 && c.data != (void*)mem &&
              arr_equals(&c, vals, 12, 1), "ascontiguous of a trusted temporary (buf NULL): a copy");
        nd_release(&c);
        check(nd_asfortran(NULL, &tr, &c, &copied) == OTI_OK && copied == 1,
                "asfortran of a trusted temporary: a copy");
        nd_release(&c);
    }

    ok = 1;
    (void)ok;
    nd_release(&a);
    nd_release(&f);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reshape(void){

    ndarr_t a = {0}, f = {0}, r = {0};
    int64_t sh[2] = {3, 4};
    double vals[12];
    int64_t tgt[3];
    int32_t copied;
    int i;
    oti_ctx ctx;

    for (i = 0; i < 12; i++){
        vals[i] = i;
    }
    make_from(2, sh, ND_LAYOUT_C, vals, &a);
    make_from(2, sh, ND_LAYOUT_F, vals, &f);

    tgt[0] = 12;
    check(nd_reshape(NULL, &a, 1, tgt, ND_LAYOUT_C, &r, &copied) == OTI_OK && copied == 0 &&
            r.data == a.data &&
          (r.flags & ND_RETAINED) && nd_buffer_refs(a.buf) == 2 && arr_equals(&r, vals, 12, 1),
          "reshape C (3,4) -> (12): a retained view, no copy");
    nd_release(&r);
    check(nd_buffer_refs(a.buf) == 1, "reshape view released");
    tgt[0] = 2; tgt[1] = -1;
    check(nd_reshape(NULL, &a, 2, tgt, ND_LAYOUT_C, &r, &copied) == OTI_OK && r.shape[0] == 2 &&
            r.shape[1] == 6 &&
          copied == 0, "reshape with -1 inferred");
    nd_release(&r);

    // F data reshaped in C index order: a copy with the logical C-order values
    tgt[0] = 12;
    check(nd_reshape(NULL, &f, 1, tgt, ND_LAYOUT_C, &r, &copied) == OTI_OK && copied == 1 &&
            r.data != f.data &&
          (r.flags & ND_C_CONTIG) && arr_equals(&r, vals, 12, 1),
                  "reshape F -> (12) in C order: a copy, C order values");
    nd_release(&r);
    check(nd_reshape(NULL, &f, 1, tgt, ND_LAYOUT_F, &r, &copied) == OTI_OK && copied == 0,
            "reshape F -> (12) in F order: view");
    {
        // logical order F: element k of the result is f's element in F order = vals at (k % 3, k / 3)
        double fv[12];
        int j;
        for (i = 0; i < 12; i++){
            j = i;
            fv[i] = vals[(j % 3) * 4 + (j / 3)];
        }
        check(arr_equals(&r, fv, 12, 1), "reshape F in F order: values in F order");
    }
    nd_release(&r);
    // the copy made in F index order of a C array
    check(nd_reshape(NULL, &a, 1, tgt, ND_LAYOUT_F, &r, &copied) == OTI_OK && copied == 1,
            "reshape C -> (12) in F order: a copy");
    {
        double fv[12];
        int j;
        for (i = 0; i < 12; i++){
            j = i;
            fv[i] = vals[(j % 3) * 4 + (j / 3)];
        }
        check(arr_equals(&r, fv, 12, 1), "reshape C in F order: the copy holds F-order values");
    }
    nd_release(&r);

    // errors
    tgt[0] = 5;
    check(nd_reshape(NULL, &a, 1, tgt, ND_LAYOUT_C, &r, &copied) == OTI_ERR_SHAPE,
            "reshape to size 5 -> SHAPE");
    tgt[0] = -1; tgt[1] = -1;
    check(nd_reshape(NULL, &a, 2, tgt, ND_LAYOUT_C, &r, &copied) == OTI_ERR_SHAPE,
            "reshape with two -1 -> SHAPE");
    tgt[0] = 12;
    check(nd_reshape(NULL, &a, 1, tgt, ND_LAYOUT_K, &r, &copied) == OTI_ERR_ARGUMENT,
            "reshape with layout K -> ARGUMENT");

    // the internal "no view" signal is never recorded as a last error
    oti_ctx_init(&ctx);
    check(nd_reshape(&ctx, &f, 1, tgt, ND_LAYOUT_C, &r, &copied) == OTI_OK && copied == 1,
            "reshape that needs a copy, user ctx");
    check(oti_ctx_last_error(&ctx, NULL, NULL) == OTI_OK,
            "reshape: the LAYOUT signal is consumed, not recorded as a last error");
    nd_release(&r);

    nd_release(&a);
    nd_release(&f);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Elementwise: references
// =======================================================================================================

// *******************************************************************************************************
static double ref_binary(int32_t op, double a, double b){

    switch (op){
        case ND_OP_ADD: return a + b;
        case ND_OP_SUB: return a - b;
        case ND_OP_MUL: return a * b;
        case ND_OP_DIV: return a / b;
        case ND_OP_POW: return pow(a, b);
        case ND_OP_MAXIMUM: return (isnan(a) || isnan(b)) ? NAN : (a >= b ? a : b);
        case ND_OP_MINIMUM: return (isnan(a) || isnan(b)) ? NAN : (a <= b ? a : b);
        default: return 0.0;
    }

}
// -------------------------------------------------------------------------------------------------------


static const int32_t k_ops[7] = {ND_OP_ADD, ND_OP_SUB, ND_OP_MUL, ND_OP_DIV, ND_OP_POW, ND_OP_MAXIMUM,
                                 ND_OP_MINIMUM};


// *******************************************************************************************************
static int op_bitwise(int32_t op){

    return op != ND_OP_MAXIMUM && op != ND_OP_MINIMUM;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double ref_sign(double x){

    if (isnan(x)){
        return NAN;
    }
    return (x > 0) ? 1.0 : (x < 0) ? -1.0 : 0.0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_neg(double x){

    return -x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_abs(double x){

    return fabs(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_sqrt(double x){

    return sqrt(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_cbrt(double x){

    return cbrt(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_exp(double x){

    return exp(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_exp2(double x){

    return exp2(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_expm1(double x){

    return expm1(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_log(double x){

    return log(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_log2(double x){

    return log2(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_log10(double x){

    return log10(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_log1p(double x){

    return log1p(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_sin(double x){

    return sin(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_cos(double x){

    return cos(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_tan(double x){

    return tan(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_asin(double x){

    return asin(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_acos(double x){

    return acos(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_atan(double x){

    return atan(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_sinh(double x){

    return sinh(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_cosh(double x){

    return cosh(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_tanh(double x){

    return tanh(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_asinh(double x){

    return asinh(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_acosh(double x){

    return acosh(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_atanh(double x){

    return atanh(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_floor(double x){

    return floor(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_ceil(double x){

    return ceil(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_trunc(double x){

    return trunc(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_rint(double x){

    return rint(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_square(double x){

    return x * x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double r_recip(double x){

    return 1.0 / x;

}
// -------------------------------------------------------------------------------------------------------



typedef struct { int32_t code; double (*f)(double); const char* name; } unary_t;

static const unary_t k_unary[] = {
    {ND_FN_NEG, r_neg, "neg"}, {ND_FN_ABS, r_abs, "abs"}, {ND_FN_SQRT, r_sqrt, "sqrt"},
    {ND_FN_CBRT, r_cbrt, "cbrt"}, {ND_FN_EXP, r_exp, "exp"}, {ND_FN_EXP2, r_exp2, "exp2"},
    {ND_FN_EXPM1, r_expm1, "expm1"}, {ND_FN_LOG, r_log, "log"}, {ND_FN_LOG2, r_log2, "log2"},
    {ND_FN_LOG10, r_log10, "log10"}, {ND_FN_LOG1P, r_log1p, "log1p"}, {ND_FN_SIN, r_sin, "sin"},
    {ND_FN_COS, r_cos, "cos"}, {ND_FN_TAN, r_tan, "tan"}, {ND_FN_ASIN, r_asin, "asin"},
    {ND_FN_ACOS, r_acos, "acos"}, {ND_FN_ATAN, r_atan, "atan"}, {ND_FN_SINH, r_sinh, "sinh"},
    {ND_FN_COSH, r_cosh, "cosh"}, {ND_FN_TANH, r_tanh, "tanh"}, {ND_FN_ASINH, r_asinh, "asinh"},
    {ND_FN_ACOSH, r_acosh, "acosh"}, {ND_FN_ATANH, r_atanh, "atanh"}, {ND_FN_FLOOR, r_floor, "floor"},
    {ND_FN_CEIL, r_ceil, "ceil"}, {ND_FN_TRUNC, r_trunc, "trunc"}, {ND_FN_RINT, r_rint, "rint"},
    {ND_FN_SQUARE, r_square, "square"}, {ND_FN_RECIPROCAL, r_recip, "reciprocal"},
    {ND_FN_SIGN, ref_sign, "sign"}
};
#define N_UNARY ((int)(sizeof(k_unary) / sizeof(k_unary[0])))


// =======================================================================================================
// Elementwise: binary with broadcasting, layouts, strides
// =======================================================================================================

// *******************************************************************************************************
// Reference: out[c] = op(a[c mapped], b[c mapped]) with right-aligned broadcasting.
static void ref_binary_array(int32_t op, const ndarr_t* a, const ndarr_t* b, int32_t nd, const int64_t* S,
                             double* out){

    int64_t n = shape_size(nd, S), lin;
    int32_t k;

    for (lin = 0; lin < n; lin++){
        int64_t c[OTI_ND_MAXDIM], rem = lin;
        int64_t la = 0, lb = 0;
        for (k = nd - 1; k >= 0; k--){
            c[k] = rem % S[k];
            rem /= S[k];
        }
        for (k = 0; k < a->ndim; k++){
            int32_t ax = nd - a->ndim + k;
            la = la * a->shape[k] + (a->shape[k] == 1 ? 0 : c[ax]);
        }
        for (k = 0; k < b->ndim; k++){
            int32_t ax = nd - b->ndim + k;
            lb = lb * b->shape[k] + (b->shape[k] == 1 ? 0 : c[ax]);
        }
        out[lin] = ref_binary(op, get_f(a, la), get_f(b, lb));
    }

}
// -------------------------------------------------------------------------------------------------------


static double g_ref[1 << 14];

// *******************************************************************************************************
static void random_shapes(int32_t* nd, int64_t* S, int32_t* nda, int64_t* sa, int32_t* ndb, int64_t* sb,
                          int max_total){

    int32_t k;
    int64_t total;

    *nd = (int32_t)rng_int(4);
    for (k = 0; k < *nd; k++){
        S[k] = (rng_int(12) == 0) ? 0 : 1 + rng_int(5);
    }
    total = shape_size(*nd, S);
    while (total > max_total){
        S[rng_int(*nd)] = 1;
        total = shape_size(*nd, S);
    }
    // each operand: rank <= nd, trailing axes of S, some replaced by 1; the first has the full shape
    // for every axis the second does not cover
    *nda = (int32_t)rng_int(*nd + 1);
    *ndb = (int32_t)rng_int(*nd + 1);
    for (k = 0; k < *nda; k++){
        sa[k] = (rng_int(3) == 0) ? 1 : S[*nd - *nda + k];
    }
    for (k = 0; k < *ndb; k++){
        sb[k] = (rng_int(3) == 0) ? 1 : S[*nd - *ndb + k];
    }
    // S must be exactly the broadcast shape of (a, b): its rank is the larger operand rank and an axis
    // where both operands have extent 1 has extent 1
    {
        int32_t r = (*nda > *ndb) ? *nda : *ndb;
        for (k = 0; k < r; k++){
            int64_t ea = (k - (r - *nda) >= 0) ? sa[k - (r - *nda)] : 1;
            int64_t eb = (k - (r - *ndb) >= 0) ? sb[k - (r - *ndb)] : 1;
            S[k] = (ea == 1) ? eb : ea;
        }
        *nd = r;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fill_random(ndarr_t* a){

    int64_t n = shape_size(a->ndim, a->shape), i;

    for (i = 0; i < n; i++){
        set_f(a, i, rng_value());
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_binary_random(void){

    int iter, fails = 0, fails_alloc = 0, fails_to = 0;

    rng_seed(60221);
    for (iter = 0; iter < 700; iter++){

        int32_t nd, nda, ndb;
        int64_t S[OTI_ND_MAXDIM], sa[OTI_ND_MAXDIM], sb[OTI_ND_MAXDIM];
        ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bo = {0}, vo = {0}, res = {0};
        int32_t op = k_ops[iter % 7];
        int64_t n;
        int ok = 1;

        random_shapes(&nd, S, &nda, sa, &ndb, sb, 600);
        n = shape_size(nd, S);
        make_view(nda, sa, (int)rng_int(3), OTI_F64, &ba, &va);
        make_view(ndb, sb, (int)rng_int(3), OTI_F64, &bb, &vb);
        fill_random(&va);
        fill_random(&vb);
        ref_binary_array(op, &va, &vb, nd, S, g_ref);

        // allocating form
        {
            int st0 = nd_binary(NULL, op, &va, &vb, &res);
            if (st0 != OTI_OK && fails_alloc < 4){
                fprintf(stderr, "  nd_binary iter %d op %d nd %d: status %d\n", iter, op, nd, st0);
            }
            if (st0 != OTI_OK){
                ok = 0;
                fails_alloc++;
            } else
        {
            int64_t i;
            if (res.ndim != nd || !(res.flags & ND_RETAINED) || !(res.flags & ND_WRITEABLE)){
                ok = 0;
            }
            for (i = 0; ok && i < nd; i++){
                ok = ok && res.shape[i] == S[i];
            }
            ok = ok && arr_equals(&res, g_ref, n, op_bitwise(op));
            if (!ok){
                fails_alloc++;
                if (fails_alloc < 4){
                    int64_t q;
                    for (q = 0; q < n; q++){
                        if (!(op_bitwise(op) ? same_bits(get_f(&res, q), g_ref[q]) : same_num(get_f(&res,
                                q), g_ref[q]))){
                            fprintf(stderr,
                                    "  binary iter %d op %d nd %d: element %lld got %.17g want %.17g\n",
                                    iter, op, nd, (long long)q, get_f(&res, q), g_ref[q]);
                            break;
                        }
                    }
                }
            }
            nd_release(&res);
        }
        }

        // _to form into a random view of the right shape
        make_view(nd, S, (int)rng_int(3), OTI_F64, &bo, &vo);
        {
            int st1 = nd_binary_to(NULL, op, &va, &vb, &vo);
            if (st1 != OTI_OK || !arr_equals(&vo, g_ref, n, op_bitwise(op))){
                fails_to++;
                if (fails_to < 4){
                    fprintf(stderr, "  binary_to iter %d op %d nd %d failed (status %d)\n", iter, op, nd,
                            st1);
                }
            }
        }
        nd_release(&bo);
        nd_release(&ba);
        nd_release(&bb);
        if (!ok){
            fails++;
        }
    }
    check(fails_alloc == 0,
            "nd_binary: 700 random broadcasts x 7 ops, random layouts / strides, vs the reference");
    check(fails_to == 0, "nd_binary_to: the same into random (negative / doubled / F) output views");
    (void)fails;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_binary_hand(void){

    ndarr_t a = {0}, b = {0}, r = {0}, s = {0};
    int64_t sa[2] = {2, 3};
    int64_t sb[1] = {3};
    double va[6] = {1, 2, 3, 4, 5, 6};
    double vb[3] = {10, 20, 30};
    double e[6];
    int i;

    make_from(2, sa, ND_LAYOUT_C, va, &a);
    make_from(1, sb, ND_LAYOUT_C, vb, &b);

    nd_binary(NULL, ND_OP_ADD, &a, &b, &r);
    for (i = 0; i < 6; i++){
        e[i] = va[i] + vb[i % 3];
    }
    check(arr_equals(&r, e, 6, 1) && r.ndim == 2 && r.shape[0] == 2 && r.shape[1] == 3,
          "(2,3) + (3,) = [[11,22,33],[14,25,36]] (hand-derived)");
    check(get_f(&r, 0) == 11 && get_f(&r, 5) == 36, "(2,3) + (3,): corner values 11 and 36");
    nd_release(&r);

    // IEEE results with no status
    {
        double xv[4] = {1, -1, 0, INFINITY};
        double yv[4] = {0, 0, 0, INFINITY};
        int64_t s4[1] = {4};
        ndarr_t x = {0}, y = {0};
        make_from(1, s4, ND_LAYOUT_C, xv, &x);
        make_from(1, s4, ND_LAYOUT_C, yv, &y);
        check(nd_binary(NULL, ND_OP_DIV, &x, &y, &r) == OTI_OK && get_f(&r, 0) == INFINITY && get_f(&r,
                1) == -INFINITY &&
              isnan(get_f(&r, 2)) && isnan(get_f(&r, 3)),
                      "division: 1/0 = inf, -1/0 = -inf, 0/0 = NaN, inf/inf = NaN, status OK");
        nd_release(&r);
        check(nd_binary(NULL, ND_OP_SUB, &x, &y, &r) == OTI_OK && isnan(get_f(&r, 3)),
                "inf - inf = NaN, status OK");
        nd_release(&r);
        {
            double big[2] = {1e308, 1e308};
            int64_t s2[1] = {2};
            ndarr_t g = {0};
            make_from(1, s2, ND_LAYOUT_C, big, &g);
            check(nd_binary(NULL, ND_OP_MUL, &g, &g, &r) == OTI_OK && get_f(&r, 0) == INFINITY,
                    "overflow -> inf, status OK");
            nd_release(&r);
            nd_release(&g);
        }
        nd_release(&x);
        nd_release(&y);
    }

    // maximum / minimum propagate NaN (numpy.maximum, not fmax)
    {
        double xv[4] = {NAN, 1, NAN, 2};
        double yv[4] = {1, NAN, NAN, 3};
        int64_t s4[1] = {4};
        ndarr_t x = {0}, y = {0};
        make_from(1, s4, ND_LAYOUT_C, xv, &x);
        make_from(1, s4, ND_LAYOUT_C, yv, &y);
        nd_binary(NULL, ND_OP_MAXIMUM, &x, &y, &r);
        check(isnan(get_f(&r, 0)) && isnan(get_f(&r, 1)) && isnan(get_f(&r, 2)) && get_f(&r, 3) == 3.0,
              "maximum: NaN propagates from either side (numpy.maximum)");
        nd_release(&r);
        nd_binary(NULL, ND_OP_MINIMUM, &x, &y, &r);
        check(isnan(get_f(&r, 0)) && isnan(get_f(&r, 1)) && isnan(get_f(&r, 2)) && get_f(&r, 3) == 2.0,
              "minimum: NaN propagates from either side (numpy.minimum)");
        nd_release(&r);
        nd_release(&x);
        nd_release(&y);
    }

    // layout of allocating results: F when every input with more than one element is F and not C
    {
        int64_t sh[2] = {3, 4};
        double v12[12];
        ndarr_t fa = {0}, fb = {0}, ca = {0}, sc = {0}, row = {0};
        int64_t one[1] = {1};
        int64_t r4[1] = {4};
        for (i = 0; i < 12; i++){
            v12[i] = i;
        }
        make_from(2, sh, ND_LAYOUT_F, v12, &fa);
        make_from(2, sh, ND_LAYOUT_F, v12, &fb);
        make_from(2, sh, ND_LAYOUT_C, v12, &ca);
        make_from(1, one, ND_LAYOUT_C, v12, &sc);
        make_from(1, r4, ND_LAYOUT_C, v12, &row);
        nd_binary(NULL, ND_OP_ADD, &fa, &fb, &r);
        check((r.flags & ND_F_CONTIG) && !(r.flags & ND_C_CONTIG) && r.strides[0] == 1,
                "F + F gives an F result");
        nd_release(&r);
        nd_binary(NULL, ND_OP_ADD, &fa, &ca, &r);
        check((r.flags & ND_F_CONTIG) && !(r.flags & ND_C_CONTIG),
              "F + C gives an F result (K layout: the first operand drives on a tie, S26)");
        nd_release(&r);
        nd_binary(NULL, ND_OP_ADD, &fa, &sc, &r);
        check((r.flags & ND_F_CONTIG) && !(r.flags & ND_C_CONTIG),
              "F + a one-element operand gives an F result (single-element operands do not count)");
        nd_release(&r);
        nd_binary(NULL, ND_OP_ADD, &fa, &row, &r);
        check((r.flags & ND_F_CONTIG) && !(r.flags & ND_C_CONTIG),
              "F (3,4) + a contiguous (4,) gives an F result (the F operand has more non-zero axes)");
        nd_release(&r);
        nd_binary(NULL, ND_OP_ADD, &ca, &fa, &r);
        check((r.flags & ND_C_CONTIG) && !(r.flags & ND_F_CONTIG),
                "C + F gives a C result (first operand drives)");
        nd_release(&r);
        nd_binary(NULL, ND_OP_ADD, &ca, &ca, &r);
        check((r.flags & ND_C_CONTIG), "C + C gives a C result");
        nd_release(&r);
        nd_release(&fa); nd_release(&fb); nd_release(&ca); nd_release(&sc); nd_release(&row);
    }

    // scalar variants: both operand orders, non-commutative operations
    {
        double xv[3] = {1, 4, 9};
        int64_t s3[1] = {3};
        ndarr_t x = {0};
        make_from(1, s3, ND_LAYOUT_C, xv, &x);
        nd_binary_scalar(NULL, ND_OP_SUB, &x, 10.0, 0, &r);
        check(get_f(&r, 0) == -9 && get_f(&r, 1) == -6 && get_f(&r, 2) == -1, "a - 10");
        nd_release(&r);
        nd_binary_scalar(NULL, ND_OP_SUB, &x, 10.0, 1, &r);
        check(get_f(&r, 0) == 9 && get_f(&r, 1) == 6 && get_f(&r, 2) == 1, "10 - a (scalar_left)");
        nd_release(&r);
        nd_binary_scalar(NULL, ND_OP_DIV, &x, 2.0, 0, &r);
        check(get_f(&r, 0) == 0.5 && get_f(&r, 1) == 2 && get_f(&r, 2) == 4.5, "a / 2");
        nd_release(&r);
        nd_binary_scalar(NULL, ND_OP_DIV, &x, 36.0, 1, &r);
        check(get_f(&r, 0) == 36 && get_f(&r, 1) == 9 && get_f(&r, 2) == 4, "36 / a (scalar_left)");
        nd_release(&r);
        nd_binary_scalar(NULL, ND_OP_POW, &x, 2.0, 1, &r);
        check(get_f(&r, 0) == 2 && get_f(&r, 1) == 16 && get_f(&r, 2) == 512,
                "2 ** a (scalar_left): 2, 16, 512");
        nd_release(&r);
        nd_binary_scalar(NULL, ND_OP_MAXIMUM, &x, 5.0, 0, &r);
        check(get_f(&r, 0) == 5 && get_f(&r, 1) == 5 && get_f(&r, 2) == 9, "maximum(a, 5)");
        nd_release(&r);

        // _to
        nd_alloc(NULL, OTI_F64, 1, s3, ND_LAYOUT_C, 0, &s);
        check(nd_binary_scalar_to(NULL, ND_OP_MUL, &x, 3.0, 0, &s) == OTI_OK && get_f(&s, 2) == 27,
                "binary_scalar_to: a * 3");
        check(nd_binary_scalar_to(NULL, ND_OP_ADD, &x, 0.5, 1, &s) == OTI_OK && get_f(&s, 0) == 1.5,
                "binary_scalar_to: 0.5 + a");
        nd_release(&s);
        nd_release(&x);
    }

    nd_release(&a);
    nd_release(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scalar exponents: NumPy's fast paths (2 -> x*x, 0.5 -> sqrt, -1 -> 1/x, 1 -> x, 0 -> 1).
static void test_pow_fast_paths(void){

    double xv[8] = {-0.0, 0.0, -4.0, 4.0, NAN, INFINITY, -INFINITY, 2.5};
    int64_t s8[1] = {8};
    ndarr_t x = {0}, r = {0};
    int i, ok;
    static const double exps[5] = {2.0, 0.5, -1.0, 1.0, 0.0};

    make_from(1, s8, ND_LAYOUT_C, xv, &x);
    for (i = 0; i < 5; i++){
        int64_t j;
        char msg[96];
        ok = (nd_binary_scalar(NULL, ND_OP_POW, &x, exps[i], 0, &r) == OTI_OK);
        for (j = 0; ok && j < 8; j++){
            double expect;
            if (exps[i] == 2.0){
                expect = xv[j] * xv[j];
            } else if (exps[i] == 0.5){
                expect = sqrt(xv[j]);
            } else if (exps[i] == -1.0){
                expect = 1.0 / xv[j];
            } else if (exps[i] == 1.0){
                expect = xv[j];
            } else {
                expect = 1.0;
            }
            if (!same_bits(get_f(&r, j), expect)){
                fprintf(stderr, "  pow x=%g exponent %g: got %g (bits differ from %g)\n", xv[j], exps[i],
                        get_f(&r, j), expect);
                ok = 0;
            }
        }
        snprintf(msg, sizeof(msg), "pow with scalar exponent %g follows NumPy's fast path, bitwise",
                exps[i]);
        check(ok, msg);
        nd_release(&r);
    }
    // sqrt of -0.0 keeps the sign, sqrt of -4 is NaN, through the 0.5 fast path
    nd_binary_scalar(NULL, ND_OP_POW, &x, 0.5, 0, &r);
    check(signbit(get_f(&r, 0)) && isnan(get_f(&r, 2)) && get_f(&r, 3) == 2.0,
            "x ** 0.5: sqrt(-0.0) = -0.0, sqrt(-4) = NaN, sqrt(4) = 2");
    nd_release(&r);
    // any other exponent calls pow()
    nd_binary_scalar(NULL, ND_OP_POW, &x, 3.0, 0, &r);
    ok = 1;
    for (i = 0; i < 8; i++){
        ok = ok && same_bits(get_f(&r, i), pow(xv[i], 3.0));
    }
    check(ok, "x ** 3 calls pow()");
    nd_release(&r);
    nd_release(&x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_binary_errors(void){

    ndarr_t a = {0}, b = {0}, out = {0}, u = {0}, ro = {0}, ov = {0}, r = {0};
    int64_t sa[2] = {3, 4};
    int64_t sb[1] = {5};
    int64_t so[2] = {3, 5};
    oti_ctx ctx;
    double v12[12] = {0};

    nd_alloc(NULL, OTI_F64, 2, sa, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
    nd_alloc(NULL, OTI_F64, 1, sb, ND_LAYOUT_C, ND_ALLOC_ZERO, &b);
    nd_alloc(NULL, OTI_F64, 2, sa, ND_LAYOUT_C, ND_ALLOC_ZERO, &out);
    nd_alloc(NULL, OTI_U8, 2, sa, ND_LAYOUT_C, ND_ALLOC_ZERO, &u);

    check(nd_binary(NULL, ND_OP_ADD, &a, &b, &r) == OTI_ERR_SHAPE && r.buf == NULL,
            "(3,4) + (5,): SHAPE, res empty");
    check(nd_binary_to(NULL, ND_OP_ADD, &a, &a, &b) == OTI_ERR_SHAPE,
            "out of the wrong shape (5,) for (3,4): SHAPE");
    {
        ndarr_t wrong = {0};
        nd_alloc(NULL, OTI_F64, 2, so, ND_LAYOUT_C, 0, &wrong);
        check(nd_binary_to(NULL, ND_OP_ADD, &a, &a, &wrong) == OTI_ERR_SHAPE,
                "out (3,5) for (3,4): SHAPE");
        nd_release(&wrong);
        nd_alloc(NULL, OTI_F64, 1, sa, ND_LAYOUT_C, 0, &wrong);
        check(nd_binary_to(NULL, ND_OP_ADD, &a, &a, &wrong) == OTI_ERR_SHAPE,
                "out of lower rank: SHAPE (no broadcast of the output)");
        nd_release(&wrong);
    }
    check(nd_binary(NULL, ND_OP_ADD, &a, &u, &r) == OTI_ERR_DTYPE, "F64 + U8 -> DTYPE");
    check(nd_binary(NULL, ND_OP_ADD, &u, &a, &r) == OTI_ERR_DTYPE, "U8 + F64 -> DTYPE");
    check(nd_binary_to(NULL, ND_OP_ADD, &a, &a, &u) == OTI_ERR_DTYPE, "out of dtype U8 -> DTYPE");
    check(nd_binary(NULL, 99, &a, &a, &r) == OTI_ERR_ARGUMENT, "unknown operation -> ARGUMENT");
    check(nd_binary(NULL, 0, &a, &a, &r) == OTI_ERR_ARGUMENT, "operation 0 -> ARGUMENT");

    // read-only output (3.3)
    {
        ndarr_t d = {0};
        make_desc(&d, out.data, OTI_F64, 2, sa, out.strides, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        check(nd_binary_to(NULL, ND_OP_ADD, &a, &a, &ro) == OTI_ERR_READONLY,
                "binary_to into a read-only out -> READONLY");
        check(nd_binary_scalar_to(NULL, ND_OP_ADD, &a, 1.0, 0, &ro) == OTI_ERR_READONLY,
                "binary_scalar_to into read-only -> READONLY");
        check(nd_unary_to(NULL, ND_FN_NEG, &a, &ro) == OTI_ERR_READONLY,
                "unary_to into read-only -> READONLY");
        check(nd_assign(NULL, &a, &ro) == OTI_ERR_READONLY, "assign into read-only -> READONLY");
        check(nd_fill(NULL, &ro, 1.0) == OTI_ERR_READONLY, "fill of read-only -> READONLY");
        nd_release(&ro);
    }
    // internal overlap of the output
    {
        ndarr_t d = {0};
        int64_t st[2] = {0, 1};
        make_desc(&d, out.data, OTI_F64, 2, sa, st, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
        check(nd_binary_to(NULL, ND_OP_ADD, &a, &a, &ov) == OTI_ERR_LAYOUT,
                "binary_to into an out with stride 0 -> LAYOUT");
        check(nd_unary_to(NULL, ND_FN_NEG, &a, &ov) == OTI_ERR_LAYOUT,
                "unary_to into stride 0 -> LAYOUT");
        check(nd_assign(NULL, &a, &ov) == OTI_ERR_LAYOUT, "assign into stride 0 -> LAYOUT");
        check(nd_fill(NULL, &ov, 1.0) == OTI_ERR_LAYOUT, "fill of stride 0 -> LAYOUT");
        nd_release(&ov);
    }
    // an empty read-only output still fails (contracts S5 / 2.1 step 6)
    {
        ndarr_t d = {0}, e = {0};
        int64_t z[1] = {0};
        int64_t st[1] = {1};
        make_desc(&d, v12, OTI_F64, 1, z, st, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &e);
        {
            ndarr_t za = {0};
            nd_alloc(NULL, OTI_F64, 1, z, ND_LAYOUT_C, 0, &za);
            check(nd_assign(NULL, &za, &e) == OTI_ERR_READONLY,
                    "assign into an EMPTY read-only array -> READONLY");
            check(nd_fill(NULL, &e, 1.0) == OTI_ERR_READONLY,
                    "fill of an EMPTY read-only array -> READONLY");
            check(nd_binary_to(NULL, ND_OP_ADD, &za, &za, &e) == OTI_ERR_READONLY,
                    "binary_to into an EMPTY read-only array -> READONLY");
            check(nd_unary_to(NULL, ND_FN_NEG, &za, &e) == OTI_ERR_READONLY,
                    "unary_to into an EMPTY read-only array -> READONLY");
            nd_release(&za);
        }
        nd_release(&e);
    }

    // last error of failing public calls
    oti_ctx_init(&ctx);
    check(nd_binary(&ctx, ND_OP_ADD, &a, &b, &r) == OTI_ERR_SHAPE && oti_ctx_last_error(&ctx, NULL,
            NULL) == OTI_ERR_SHAPE,
          "a failing nd_binary records SHAPE in the user context");
    {
        const char* where = NULL;
        oti_ctx_last_error(&ctx, &where, NULL);
        check(where != NULL && strncmp(where, "nd_", 3) == 0,
                "last error: where names the public function");
    }
    oti_ctx_clear_error(NULL);
    check(nd_unary(NULL, 99, &a, &r) == OTI_ERR_ARGUMENT && oti_ctx_last_error(NULL, NULL,
            NULL) == OTI_ERR_ARGUMENT,
          "a failing nd_unary with NULL ctx records ARGUMENT thread-locally");
    oti_ctx_clear_error(NULL);

    nd_release(&a);
    nd_release(&b);
    nd_release(&out);
    nd_release(&u);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Unary functions
// =======================================================================================================

// *******************************************************************************************************
static void test_unary_all_functions(void){

    // inputs spanning every domain: negatives, zeros, small, 1, large, specials
    static const double xs[] = {-3.5, -1.5, -1.0, -0.5, -0.0, 0.0, 1e-300, 0.25, 0.5, 0.999, 1.0, 1.5,
            2.0, 5.5,
                                10.0, 700.0, 1e10, NAN, INFINITY, -INFINITY, 2.5, -2.5, 3.5, -4.5, 0.1};
    const int n = (int)(sizeof(xs) / sizeof(xs[0]));
    int64_t sh[1];
    ndarr_t x = {0}, r = {0};
    int f;

    sh[0] = n;
    make_from(1, sh, ND_LAYOUT_C, xs, &x);

    for (f = 0; f < N_UNARY; f++){
        int64_t i;
        int ok = (nd_unary(NULL, k_unary[f].code, &x, &r) == OTI_OK);
        char msg[96];
        for (i = 0; ok && i < n; i++){
            double expect = k_unary[f].f(xs[i]);
            if (!same_bits(get_f(&r, i), expect)){
                fprintf(stderr, "  %s(%.17g): got %.17g (bits differ from %.17g)\n", k_unary[f].name,
                        xs[i],
                        get_f(&r, i), expect);
                ok = 0;
            }
        }
        snprintf(msg, sizeof(msg), "nd_unary %s: bitwise equal to the C library on 25 inputs",
                k_unary[f].name);
        check(ok, msg);
        if (r.buf != NULL){
            nd_release(&r);
        }
    }

    // sign(-0.0) is +0.0, sign(0.0) is +0.0, sign(NaN) is NaN ([cH3], [k9])
    {
        double sv[6] = {-0.0, 0.0, NAN, -INFINITY, INFINITY, -7.25};
        int64_t s6[1] = {6};
        ndarr_t s = {0};
        make_from(1, s6, ND_LAYOUT_C, sv, &s);
        nd_unary(NULL, ND_FN_SIGN, &s, &r);
        check(same_bits(get_f(&r, 0), 0.0) && !signbit(get_f(&r, 0)), "sign(-0.0) is +0.0 (not -0.0)");
        check(same_bits(get_f(&r, 1), 0.0) && !signbit(get_f(&r, 1)), "sign(+0.0) is +0.0");
        check(isnan(get_f(&r, 2)), "sign(NaN) is NaN");
        check(get_f(&r, 3) == -1.0 && get_f(&r, 4) == 1.0 && get_f(&r, 5) == -1.0,
                "sign(-inf) = -1, sign(inf) = 1, sign(-7.25) = -1");
        nd_release(&r);
        nd_release(&s);
    }
    // neg and abs on zeros keep NumPy's signs
    {
        double zv[2] = {0.0, -0.0};
        int64_t s2[1] = {2};
        ndarr_t z = {0};
        make_from(1, s2, ND_LAYOUT_C, zv, &z);
        nd_unary(NULL, ND_FN_NEG, &z, &r);
        check(signbit(get_f(&r, 0)) && !signbit(get_f(&r, 1)), "neg(+0.0) = -0.0 and neg(-0.0) = +0.0");
        nd_release(&r);
        nd_unary(NULL, ND_FN_ABS, &z, &r);
        check(!signbit(get_f(&r, 0)) && !signbit(get_f(&r, 1)), "abs(-0.0) = +0.0");
        nd_release(&r);
        nd_release(&z);
    }
    // rint rounds half to even
    {
        double hv[8] = {0.5, 1.5, 2.5, 3.5, -0.5, -1.5, -2.5, 2.4999999};
        double ev[8] = {0.0, 2.0, 2.0, 4.0, -0.0, -2.0, -2.0, 2.0};
        int64_t s8[1] = {8};
        ndarr_t h = {0};
        make_from(1, s8, ND_LAYOUT_C, hv, &h);
        nd_unary(NULL, ND_FN_RINT, &h, &r);
        check(arr_equals(&r, ev, 8, 1),
                "rint rounds half to even (hand-derived: 0, 2, 2, 4, -0, -2, -2, 2)");
        nd_release(&r);
        nd_release(&h);
    }
    nd_release(&x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_unary_random_layouts(void){

    int iter, ok = 1, ok_to = 1;

    rng_seed(31415);
    for (iter = 0; iter < 400; iter++){

        int32_t nd = (int32_t)rng_int(4);
        int64_t S[OTI_ND_MAXDIM];
        int32_t k;
        ndarr_t ba = {0}, va = {0}, bo = {0}, vo = {0}, r = {0};
        const unary_t* u = &k_unary[iter % N_UNARY];
        int64_t n, i;

        for (k = 0; k < nd; k++){
            S[k] = (rng_int(10) == 0) ? 0 : 1 + rng_int(5);
        }
        n = shape_size(nd, S);
        make_view(nd, S, (int)rng_int(3), OTI_F64, &ba, &va);
        make_view(nd, S, (int)rng_int(3), OTI_F64, &bo, &vo);
        fill_random(&va);
        if (nd_unary(NULL, u->code, &va, &r) != OTI_OK){
            ok = 0;
        } else {
            for (i = 0; i < n; i++){
                ok = ok && same_bits(get_f(&r, i), u->f(get_f(&va, i)));
            }
            nd_release(&r);
        }
        if (nd_unary_to(NULL, u->code, &va, &vo) != OTI_OK){
            ok_to = 0;
        } else {
            for (i = 0; i < n; i++){
                ok_to = ok_to && same_bits(get_f(&vo, i), u->f(get_f(&va, i)));
            }
        }
        nd_release(&ba);
        nd_release(&bo);
    }
    check(ok, "nd_unary: 400 random functions / shapes / layouts / strides agree with the C library");
    check(ok_to, "nd_unary_to into random output views agrees too");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_unary_misc(void){

    ndarr_t a = {0}, f = {0}, r = {0}, u = {0}, out = {0};
    int64_t sh[2] = {3, 4};
    double v[12];
    int i;

    for (i = 0; i < 12; i++){
        v[i] = 0.5 + i;
    }
    make_from(2, sh, ND_LAYOUT_C, v, &a);
    make_from(2, sh, ND_LAYOUT_F, v, &f);
    nd_unary(NULL, ND_FN_SQRT, &f, &r);
    check((r.flags & ND_F_CONTIG) && !(r.flags & ND_C_CONTIG), "unary of an F array gives an F result");
    nd_release(&r);
    nd_unary(NULL, ND_FN_SQRT, &a, &r);
    check(r.flags & ND_C_CONTIG, "unary of a C array gives a C result");
    nd_release(&r);

    nd_alloc(NULL, OTI_U8, 2, sh, ND_LAYOUT_C, ND_ALLOC_ZERO, &u);
    check(nd_unary(NULL, ND_FN_SQRT, &u, &r) == OTI_ERR_DTYPE, "unary of a U8 array -> DTYPE");
    check(nd_unary(NULL, 999, &a, &r) == OTI_ERR_ARGUMENT, "unknown function -> ARGUMENT");
    check(nd_unary(NULL, 0, &a, &r) == OTI_ERR_ARGUMENT, "function 0 -> ARGUMENT");
    {
        int64_t bad[2] = {4, 3};
        nd_alloc(NULL, OTI_F64, 2, bad, ND_LAYOUT_C, 0, &out);
        check(nd_unary_to(NULL, ND_FN_NEG, &a, &out) == OTI_ERR_SHAPE,
                "unary_to into the wrong shape -> SHAPE");
        nd_release(&out);
    }
    check(nd_unary_to(NULL, ND_FN_NEG, &a, &u) == OTI_ERR_DTYPE, "unary_to into a U8 out -> DTYPE");

    // in place (exact alias)
    check(nd_unary_to(NULL, ND_FN_SQRT, &a, &a) == OTI_OK, "unary_to in place");
    {
        int ok = 1;
        for (i = 0; i < 12; i++){
            ok = ok && same_bits(get_f(&a, i), sqrt(v[i]));
        }
        check(ok, "unary in place: values");
    }

    // rank 0 and empty
    {
        ndarr_t s = {0}, e = {0};
        int64_t z[1] = {0};
        double four = 4.0;
        make_from(0, NULL, ND_LAYOUT_C, &four, &s);
        check(nd_unary(NULL, ND_FN_SQRT, &s, &r) == OTI_OK && r.ndim == 0 && get_f(&r, 0) == 2.0,
                "unary of rank 0");
        nd_release(&r);
        nd_release(&s);
        nd_alloc(NULL, OTI_F64, 1, z, ND_LAYOUT_C, 0, &e);
        check(nd_unary(NULL, ND_FN_EXP, &e, &r) == OTI_OK && nd_size(&r) == 0, "unary of an empty array");
        nd_release(&r);
        nd_release(&e);
    }

    nd_release(&a);
    nd_release(&f);
    nd_release(&u);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 3.4 aliasing: in place, partial overlap, snapshot assignment
// =======================================================================================================

// *******************************************************************************************************
static void test_binary_aliasing(void){

    ndarr_t a = {0}, lhs = {0}, rhs = {0}, outv = {0}, t = {0};
    int64_t sh[1] = {10};
    double v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double e[10];
    nd_index_t idx[1];
    oti_ctx tiny, ctx;
    int i;

    oti_ctx_init(&tiny);
    tiny.max_temp_bytes = 1;             // any temporary fails
    oti_ctx_init(&ctx);

    // exact alias: in place with no temporary (a 1-byte temp budget still succeeds)
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    check(nd_binary_to(&tiny, ND_OP_ADD, &a, &a, &a) == OTI_OK,
            "a + a -> a: exact alias, no temporary needed");
    for (i = 0; i < 10; i++){
        e[i] = 2 * v[i];
    }
    check(arr_equals(&a, e, 10, 1), "a + a -> a: values");
    nd_release(&a);

    make_from(1, sh, ND_LAYOUT_C, v, &a);
    {
        double w[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        ndarr_t b = {0};
        make_from(1, sh, ND_LAYOUT_C, w, &b);
        check(nd_binary_to(&tiny, ND_OP_SUB, &a, &b, &a) == OTI_OK,
                "a - b -> a: out exactly the first input, in place");
        for (i = 0; i < 10; i++){
            e[i] = v[i] - w[i];
        }
        check(arr_equals(&a, e, 10, 1), "a - b -> a: values");
        check(nd_binary_to(&tiny, ND_OP_SUB, &b, &a, &a) == OTI_OK,
                "b - a -> a: out exactly the second input");
        for (i = 0; i < 10; i++){
            e[i] = w[i] - e[i];
        }
        check(arr_equals(&a, e, 10, 1), "b - a -> a: values");
        nd_release(&b);
    }
    nd_release(&a);

    // partial overlap: a[1:] + a[:-1] -> a[1:] equals the snapshot result
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HS, 1, 0, 0);
    nd_view_index(&a, 1, idx, &outv);
    idx[0] = mk_slice(HP, 0, -1, 0);
    nd_view_index(&a, 1, idx, &lhs);
    rhs = outv;                           // a[1:] as the other input (exactly the output)
    check(nd_binary_to(&ctx, ND_OP_ADD, &rhs, &lhs, &outv) == OTI_OK,
            "a[1:] + a[:-1] -> a[1:]: partial overlap handled");
    e[0] = v[0];
    for (i = 1; i < 10; i++){
        e[i] = v[i] + v[i - 1];
    }
    check(arr_equals(&a, e, 10, 1), "a[1:] + a[:-1] -> a[1:]: snapshot values");
    nd_release(&a);

    // the temporary is charged to the temp budget: a 1-byte budget fails it with MEMORY
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HS, 1, 0, 0);
    nd_view_index(&a, 1, idx, &outv);
    idx[0] = mk_slice(HP, 0, -1, 0);
    nd_view_index(&a, 1, idx, &lhs);
    check(nd_binary_to(&tiny, ND_OP_ADD, &lhs, &lhs, &outv) == OTI_ERR_MEMORY,
          "partial overlap with a 1-byte temporary budget -> MEMORY (the temporary is charged)");
    // an injected allocation failure also fails it
    nd_test_fail_alloc(1);
    {
        int st = nd_binary_to(&ctx, ND_OP_ADD, &lhs, &lhs, &outv);
        nd_test_fail_alloc(0);
        check(st == OTI_ERR_MEMORY, "partial overlap with an injected allocation failure -> MEMORY");
    }
    nd_release(&a);

    // reversed alias: a - a[::-1] -> a (out exactly the first input, the second maybe-overlapping)
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HT, 0, 0, -1);
    nd_view_index(&a, 1, idx, &t);
    check(nd_binary_to(&ctx, ND_OP_SUB, &a, &t, &a) == OTI_OK, "a - a[::-1] -> a: handled");
    for (i = 0; i < 10; i++){
        e[i] = v[i] - v[9 - i];
    }
    check(arr_equals(&a, e, 10, 1), "a - a[::-1] -> a: snapshot values");
    nd_release(&a);

    // unary: sqrt(a[1:]) -> a[:-1] overlaps; the result equals the snapshot
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HS, 1, 0, 0);
    nd_view_index(&a, 1, idx, &rhs);
    idx[0] = mk_slice(HP, 0, -1, 0);
    nd_view_index(&a, 1, idx, &lhs);
    check(nd_unary_to(&ctx, ND_FN_SQRT, &rhs, &lhs) == OTI_OK,
            "sqrt(a[1:]) -> a[:-1]: partial overlap handled");
    for (i = 0; i < 9; i++){
        e[i] = sqrt(v[i + 1]);
    }
    e[9] = v[9];
    check(arr_equals(&a, e, 10, 1), "sqrt(a[1:]) -> a[:-1]: snapshot values");
    nd_release(&a);

    // scalar variant in place and with partial overlap of a view with itself shifted
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    check(nd_binary_scalar_to(&tiny, ND_OP_MUL, &a, 3.0, 0, &a) == OTI_OK,
            "a * 3 -> a in place with no temporary");
    for (i = 0; i < 10; i++){
        e[i] = 3.0 * v[i];
    }
    check(arr_equals(&a, e, 10, 1), "a * 3 -> a: values");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_assign_snapshot(void){

    ndarr_t a = {0}, src = {0}, dst = {0}, t = {0}, b = {0};
    int64_t sh[1] = {8};
    double v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double e[8];
    nd_index_t idx[1];
    oti_ctx tiny, ctx;
    int i;

    oti_ctx_init(&tiny);
    tiny.max_temp_bytes = 1;
    oti_ctx_init(&ctx);

    // a[1:] = a[:-1]  (NumPy: shifts right, snapshot semantics) -> [1,1,2,3,4,5,6,7]
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HP, 0, -1, 0);
    nd_view_index(&a, 1, idx, &src);
    idx[0] = mk_slice(HS, 1, 0, 0);
    nd_view_index(&a, 1, idx, &dst);
    check(nd_assign(&ctx, &src, &dst) == OTI_OK, "a[1:] = a[:-1]: OK");
    e[0] = 1;
    for (i = 1; i < 8; i++){
        e[i] = v[i - 1];
    }
    check(arr_equals(&a, e, 8, 1), "a[1:] = a[:-1] gives [1,1,2,3,4,5,6,7] (NumPy)");
    nd_release(&a);

    // a[:-1] = a[1:] -> [2,3,4,5,6,7,8,8]
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HS, 1, 0, 0);
    nd_view_index(&a, 1, idx, &src);
    idx[0] = mk_slice(HP, 0, -1, 0);
    nd_view_index(&a, 1, idx, &dst);
    check(nd_assign(&ctx, &src, &dst) == OTI_OK, "a[:-1] = a[1:]: OK");
    for (i = 0; i < 7; i++){
        e[i] = v[i + 1];
    }
    e[7] = 8;
    check(arr_equals(&a, e, 8, 1), "a[:-1] = a[1:] gives [2,3,4,5,6,7,8,8] (NumPy)");
    nd_release(&a);

    // a[::-1] = a -> reversed
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HT, 0, 0, -1);
    nd_view_index(&a, 1, idx, &dst);
    check(nd_assign(&ctx, &a, &dst) == OTI_OK, "a[::-1] = a: OK");
    for (i = 0; i < 8; i++){
        e[i] = v[7 - i];
    }
    check(arr_equals(&a, e, 8, 1), "a[::-1] = a reverses the array (snapshot semantics, NumPy)");
    nd_release(&a);

    // a = a[::-1] (destination the whole array, source reversed view)
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    idx[0] = mk_slice(HT, 0, 0, -1);
    nd_view_index(&a, 1, idx, &src);
    check(nd_assign(&ctx, &src, &a) == OTI_OK && arr_equals(&a, e, 8, 1),
            "a[...] = a[::-1] reverses too");
    nd_release(&a);

    // exact alias: a no-op even with a 1-byte temporary budget
    make_from(1, sh, ND_LAYOUT_C, v, &a);
    check(nd_assign(&tiny, &a, &a) == OTI_OK && arr_equals(&a, v, 8, 1),
            "a = a: exact alias is a no-op, no temporary");
    // a partial overlap needs a temporary: the tiny budget fails it
    idx[0] = mk_slice(HP, 0, -1, 0);
    nd_view_index(&a, 1, idx, &src);
    idx[0] = mk_slice(HS, 1, 0, 0);
    nd_view_index(&a, 1, idx, &dst);
    check(nd_assign(&tiny, &src, &dst) == OTI_ERR_MEMORY,
            "a[1:] = a[:-1] with a 1-byte temporary budget -> MEMORY");
    nd_test_fail_alloc(1);
    {
        int st = nd_assign(&ctx, &src, &dst);
        nd_test_fail_alloc(0);
        check(st == OTI_ERR_MEMORY, "a[1:] = a[:-1] with an injected allocation failure -> MEMORY");
    }
    nd_release(&a);

    // 2-D: a = a.T in place (snapshot)
    {
        int64_t s33[2] = {3, 3};
        double m[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        double mt[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
        make_from(2, s33, ND_LAYOUT_C, m, &a);
        nd_view_transpose(&a, 0, NULL, &t);
        check(nd_assign(&ctx, &t, &a) == OTI_OK && arr_equals(&a, mt, 9, 1),
                "a[...] = a.T transposes in place (snapshot)");
        nd_release(&a);
    }

    // broadcasting sources and dtype conversions
    {
        int64_t s34[2] = {3, 4};
        int64_t s4[1] = {4};
        double rowv[4] = {5, 6, 7, 8};
        double zero12[12] = {0};
        double one = 9.5;
        ndarr_t row = {0}, scal = {0}, d2 = {0}, ui = {0}, ii = {0};
        double exp12[12];
        make_from(2, s34, ND_LAYOUT_C, zero12, &d2);
        make_from(1, s4, ND_LAYOUT_C, rowv, &row);
        check(nd_assign(&ctx, &row, &d2) == OTI_OK, "assign: (4,) broadcast into (3,4)");
        for (i = 0; i < 12; i++){
            exp12[i] = rowv[i % 4];
        }
        check(arr_equals(&d2, exp12, 12, 1), "assign: the row is copied into every row");
        make_from(0, NULL, ND_LAYOUT_C, &one, &scal);
        check(nd_assign(&ctx, &scal, &d2) == OTI_OK, "assign: rank-0 source");
        for (i = 0; i < 12; i++){
            exp12[i] = 9.5;
        }
        check(arr_equals(&d2, exp12, 12, 1), "assign: the scalar fills");
        // U8 (a bool mask: nonzero = true -> 1.0) and I64 sources convert to F64
        nd_alloc(NULL, OTI_U8, 1, s4, ND_LAYOUT_C, 0, &ui);
        nd_alloc(NULL, OTI_I64, 1, s4, ND_LAYOUT_C, 0, &ii);
        for (i = 0; i < 4; i++){
            ((uint8_t*)ui.data)[i] = (uint8_t)(i * 70);
            ((int64_t*)ii.data)[i] = (int64_t)i * -3 + (i == 3 ? INT64_C(1) << 40 : 0);
        }
        check(nd_assign(&ctx, &ui, &d2) == OTI_OK, "assign U8 into F64");
        {
            int ok = 1;
            for (i = 0; i < 12; i++){
                ok = ok && get_f(&d2, i) == (((i % 4) * 70) != 0 ? 1.0 : 0.0);
            }
            if (!ok){
                for (i = 0; i < 12; i++){
                    fprintf(stderr, "  d2[%d] = %g (expected %g)\n", i, get_f(&d2, i),
                            (((i % 4) * 70) != 0 ? 1.0 : 0.0));
                }
            }
            check(ok,
                    "assign U8 -> F64: a mask converts as bool (0 -> 0.0, nonzero -> 1.0)");
        }
        check(nd_assign(&ctx, &ii, &d2) == OTI_OK, "assign I64 into F64");
        {
            int ok = 1;
            for (i = 0; i < 12; i++){
                int64_t q = i % 4;
                ok = ok && get_f(&d2, i) == (double)(q * -3 + (q == 3 ? INT64_C(1) << 40 : 0));
            }
            check(ok, "assign I64 -> F64: numeric conversion");
        }
        // same-dtype U8 and I64 assignment
        {
            ndarr_t u2 = {0};
            nd_alloc(NULL, OTI_U8, 1, s4, ND_LAYOUT_C, ND_ALLOC_ZERO, &u2);
            check(nd_assign(&ctx, &ui, &u2) == OTI_OK && ((uint8_t*)u2.data)[3] == 210,
                    "assign U8 -> U8");
            nd_release(&u2);
            nd_alloc(NULL, OTI_I64, 1, s4, ND_LAYOUT_C, ND_ALLOC_ZERO, &u2);
            check(nd_assign(&ctx, &ii, &u2) == OTI_OK && ((int64_t*)u2.data)[1] == -3,
                    "assign I64 -> I64");
            // F64 -> U8 / I64 is not allowed
            check(nd_assign(&ctx, &row, &u2) == OTI_ERR_DTYPE, "assign F64 -> I64 -> DTYPE");
            nd_release(&u2);
            nd_alloc(NULL, OTI_U8, 1, s4, ND_LAYOUT_C, ND_ALLOC_ZERO, &u2);
            check(nd_assign(&ctx, &row, &u2) == OTI_ERR_DTYPE, "assign F64 -> U8 -> DTYPE");
            check(nd_assign(&ctx, &ii, &u2) == OTI_ERR_DTYPE, "assign I64 -> U8 -> DTYPE");
            nd_release(&u2);
        }
        // shape errors
        {
            int64_t s3[1] = {3};
            ndarr_t r3 = {0};
            nd_alloc(NULL, OTI_F64, 1, s3, ND_LAYOUT_C, 0, &r3);
            check(nd_assign(&ctx, &r3, &d2) == OTI_ERR_SHAPE, "assign (3,) into (3,4): SHAPE");
            check(nd_assign(&ctx, &d2, &r3) == OTI_ERR_SHAPE,
                    "assign (3,4) into (3,): SHAPE (the source may not exceed dst)");
            nd_release(&r3);
        }
        nd_release(&row); nd_release(&scal); nd_release(&d2); nd_release(&ui); nd_release(&ii);
    }

    // assignment into a transposed / reversed 2-D destination
    {
        int64_t s23[2] = {2, 3};
        int64_t s32[2] = {3, 2};
        double sv[6] = {1, 2, 3, 4, 5, 6};
        double zero6[6] = {0};
        ndarr_t dd = {0}, ss = {0}, dt = {0};
        make_from(2, s23, ND_LAYOUT_C, sv, &ss);
        make_from(2, s32, ND_LAYOUT_C, zero6, &dd);
        nd_view_transpose(&dd, 0, NULL, &dt);          // shape (2,3)
        check(nd_assign(&ctx, &ss, &dt) == OTI_OK, "assign into a transposed destination");
        {
            int ok = 1, j;
            for (i = 0; i < 2; i++){
                for (j = 0; j < 3; j++){
                    ok = ok && ((double*)dd.data)[j * 2 + i] == sv[i * 3 + j];
                }
            }
            check(ok, "assign into a transposed destination: element (i, j) lands at dd[j, i]");
        }
        nd_release(&ss);
        nd_release(&dd);
    }
    (void)b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fill(void){

    ndarr_t a = {0}, v = {0}, t = {0};
    int64_t sh[2] = {3, 4};
    int64_t i;
    int ok;
    nd_index_t idx[2];

    nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_F, ND_ALLOC_ZERO, &a);
    check(nd_fill(NULL, &a, 3.25) == OTI_OK, "fill F array");
    ok = 1;
    for (i = 0; i < 12; i++){
        ok = ok && get_f(&a, i) == 3.25;
    }
    check(ok, "fill: every element");
    nd_fill(NULL, &a, -0.0);
    ok = 1;
    for (i = 0; i < 12; i++){
        ok = ok && same_bits(get_f(&a, i), -0.0);
    }
    check(ok, "fill stores -0.0 with its sign");
    nd_fill(NULL, &a, NAN);
    check(isnan(get_f(&a, 7)), "fill stores NaN");

    // a strided destination: only the view is written
    nd_fill(NULL, &a, 0.0);
    idx[0] = mk_slice(HT, 0, 0, -1);
    idx[1] = mk_slice(HT, 0, 0, 2);
    nd_view_index(&a, 2, idx, &v);
    nd_fill(NULL, &v, 5.0);
    ok = 1;
    for (i = 0; i < 12; i++){
        int64_t r = i / 4, c = i % 4;
        double expect = (c % 2 == 0) ? 5.0 : 0.0;
        ok = ok && get_f(&a, i) == expect;
        (void)r;
    }
    check(ok, "fill of a[::-1, ::2]: exactly those elements");

    // U8 / I64 destinations are DTYPE
    {
        ndarr_t u = {0};
        nd_alloc(NULL, OTI_U8, 1, sh, ND_LAYOUT_C, 0, &u);
        check(nd_fill(NULL, &u, 1.0) == OTI_ERR_DTYPE, "fill of a U8 array -> DTYPE");
        nd_release(&u);
        nd_alloc(NULL, OTI_I64, 1, sh, ND_LAYOUT_C, 0, &u);
        check(nd_fill(NULL, &u, 1.0) == OTI_ERR_DTYPE, "fill of an I64 array -> DTYPE");
        nd_release(&u);
    }
    // zero-size and rank 0
    {
        ndarr_t z = {0}, s = {0};
        int64_t zs[1] = {0};
        nd_alloc(NULL, OTI_F64, 1, zs, ND_LAYOUT_C, 0, &z);
        check(nd_fill(NULL, &z, 1.0) == OTI_OK, "fill of an empty array: OK");
        nd_release(&z);
        nd_alloc(NULL, OTI_F64, 0, NULL, ND_LAYOUT_C, 0, &s);
        check(nd_fill(NULL, &s, 2.0) == OTI_OK && get_f(&s, 0) == 2.0, "fill of rank 0");
        nd_release(&s);
    }
    (void)t;
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Guard regions
// =======================================================================================================

#define CANARY_BITS UINT64_C(0x7FF8DEADBEEF0001)
#define GUARD_N 96

// *******************************************************************************************************
static void canary_fill(double* buf, int n){

    int i;
    uint64_t bits = CANARY_BITS;

    for (i = 0; i < n; i++){
        memcpy(&buf[i], &bits, 8);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Verifies that exactly the elements of `view` (a descriptor over buf) changed: every element of buf that
// is not addressed by the view still carries the canary. Returns 1 when intact.
static int canary_intact(const double* buf, int n, const ndarr_t* view){

    unsigned char touched[GUARD_N];
    int64_t i, total = shape_size(view->ndim, view->shape);
    int j;
    uint64_t bits = CANARY_BITS;

    memset(touched, 0, sizeof(touched));
    for (i = 0; i < total; i++){
        int64_t off = ((double*)elem_ptr(view, i) - buf);
        if (off < 0 || off >= n){
            return 0;
        }
        touched[off] = 1;
    }
    for (j = 0; j < n; j++){
        if (!touched[j] && memcmp(&buf[j], &bits, 8) != 0){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_guard_regions(void){

    static double buf[GUARD_N];
    static const struct { int64_t off, s0, s1, n0, n1; const char* name; } layouts[] = {
        {10, 8, 2, 3, 4, "strides (8,2)"},
        {70, -8, -2, 3, 4, "strides (-8,-2)"},
        {5, 1, 3, 3, 4, "F strides (1,3) with offset"},
        {40, -3, 1, 4, 3, "strides (-3,1)"}
    };
    int l, ok_fill = 1, ok_assign = 1, ok_unary = 1, ok_binary = 1, ok_scalar = 1;

    for (l = 0; l < 4; l++){
        ndarr_t out = {0}, in = {0};
        int64_t shape[2], st[2];
        double invals[12];
        int64_t i;
        ndarr_t src = {0};
        int64_t ssh[2];

        shape[0] = layouts[l].n0;
        shape[1] = layouts[l].n1;
        st[0] = layouts[l].s0;
        st[1] = layouts[l].s1;
        make_desc(&out, buf + layouts[l].off, OTI_F64, 2, shape, st, ND_WRITEABLE);
        nd_update_flags(&out);
        ssh[0] = shape[0]; ssh[1] = shape[1];
        for (i = 0; i < 12; i++){
            invals[i] = 1.0 + (double)i;
        }
        make_from(2, ssh, ND_LAYOUT_C, invals, &src);
        in = src;
        in.flags &= ~ND_RETAINED;

        canary_fill(buf, GUARD_N);
        ok_fill = ok_fill && nd_fill(NULL, &out, 4.0) == OTI_OK && canary_intact(buf, GUARD_N, &out);
        for (i = 0; i < 12; i++){
            ok_fill = ok_fill && get_f(&out, i) == 4.0;
        }
        canary_fill(buf, GUARD_N);
        ok_assign = ok_assign && nd_assign(NULL, &in, &out) == OTI_OK && canary_intact(buf, GUARD_N,
                &out);
        for (i = 0; i < 12; i++){
            ok_assign = ok_assign && get_f(&out, i) == invals[i];
        }
        canary_fill(buf, GUARD_N);
        ok_unary = ok_unary && nd_unary_to(NULL, ND_FN_SQRT, &in, &out) == OTI_OK && canary_intact(buf,
                GUARD_N, &out);
        for (i = 0; i < 12; i++){
            ok_unary = ok_unary && same_bits(get_f(&out, i), sqrt(invals[i]));
        }
        canary_fill(buf, GUARD_N);
        ok_binary = ok_binary && nd_binary_to(NULL, ND_OP_MUL, &in, &in, &out) == OTI_OK &&
                canary_intact(buf, GUARD_N, &out);
        for (i = 0; i < 12; i++){
            ok_binary = ok_binary && get_f(&out, i) == invals[i] * invals[i];
        }
        canary_fill(buf, GUARD_N);
        ok_scalar = ok_scalar && nd_binary_scalar_to(NULL, ND_OP_ADD, &in, 0.5, 0, &out) == OTI_OK &&
                    canary_intact(buf, GUARD_N, &out);
        nd_release(&src);
        if (!(ok_fill && ok_assign && ok_unary && ok_binary && ok_scalar)){
            fprintf(stderr, "  guard region failure with layout %s\n", layouts[l].name);
            break;
        }
    }
    check(ok_fill, "guard regions: nd_fill writes exactly the view (4 layouts incl. negative strides)");
    check(ok_assign, "guard regions: nd_assign writes exactly the view");
    check(ok_unary, "guard regions: nd_unary_to writes exactly the view");
    check(ok_binary, "guard regions: nd_binary_to writes exactly the view");
    check(ok_scalar, "guard regions: nd_binary_scalar_to writes exactly the view");

    // a large strided output crossing several 4096-element chunks
    {
        enum { BIG = 20000 };
        static double* big = NULL;
        ndarr_t out = {0}, in = {0};
        int64_t shp[1] = {BIG / 2 - 1};
        int64_t stp[1] = {2};
        double* inb;
        int64_t i;
        int ok = 1;
        uint64_t bits = CANARY_BITS;

        big = (double*)malloc(sizeof(double) * BIG);
        inb = (double*)malloc(sizeof(double) * (BIG / 2 - 1));
        for (i = 0; i < BIG; i++){
            memcpy(&big[i], &bits, 8);
        }
        for (i = 0; i < BIG / 2 - 1; i++){
            inb[i] = (double)i + 0.25;
        }
        make_desc(&out, big + 1, OTI_F64, 1, shp, stp, ND_WRITEABLE);
        nd_update_flags(&out);
        {
            int64_t one[1] = {1};
            ndarr_t d = {0};
            make_desc(&d, inb, OTI_F64, 1, shp, one, ND_WRITEABLE);
            nd_update_flags(&d);
            in = d;
        }
        ok = ok && nd_unary_to(NULL, ND_FN_NEG, &in, &out) == OTI_OK;
        for (i = 0; ok && i < BIG; i++){
            if (i % 2 == 1 && i / 2 < BIG / 2 - 1){
                ok = ok && big[i] == -((double)(i / 2) + 0.25);
            } else {
                ok = ok && memcmp(&big[i], &bits, 8) == 0;
            }
        }
        check(ok,
                "guard regions: a 9999-element stride-2 output (3 chunks) writes only its own elements");
        free(big);
        free(inb);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 5.4 Determinism across backends and thread counts
// =======================================================================================================

// *******************************************************************************************************
// Adversarial data: cancellation, mixed magnitudes, NaN, -0.0, infinities.
static void fill_adversarial(ndarr_t* a, uint64_t seed){

    int64_t n = shape_size(a->ndim, a->shape), i;
    uint64_t save = g_rng_state;

    rng_seed(seed);
    for (i = 0; i < n; i++){
        double v;
        switch (rng_int(10)){
            case 0: v = 1e16; break;
            case 1: v = -1e16; break;
            case 2: v = 1.0; break;
            case 3: v = -0.0; break;
            case 4: v = NAN; break;
            case 5: v = (rng_uniform() - 0.5) * 1e-300; break;
            case 6: v = (rng_uniform() - 0.5) * 1e300; break;
            default: v = (rng_uniform() - 0.5) * 100.0; break;
        }
        set_f(a, i, v);
    }
    g_rng_state = save;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int bits_equal_arrays(const ndarr_t* a, const ndarr_t* b){

    int64_t n = shape_size(a->ndim, a->shape), i;

    for (i = 0; i < n; i++){
        double x = get_f(a, i), y = get_f(b, i);
        if (memcmp(&x, &y, 8) != 0){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_determinism(void){

    static const int64_t sizes[] = {1, 100, 4095, 4096, 4097, 8191, 8192, 8193, 20000, 70001};
    static const int32_t threads[] = {1, 2, 3, 5, 0};
    int si, ti, f, bad = 0, bad_ref = 0;

    for (si = 0; si < (int)(sizeof(sizes) / sizeof(sizes[0])); si++){

        ndarr_t x = {0}, y = {0}, ref = {0}, got = {0};
        int64_t sh[1];
        oti_ctx serial, par;
        int64_t n = sizes[si];

        sh[0] = n;
        nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, 0, &x);
        nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, 0, &y);
        fill_adversarial(&x, 1000 + (uint64_t)si);
        fill_adversarial(&y, 5000 + (uint64_t)si);

        oti_ctx_init(&serial);
        serial.exec.backend = OTI_BACKEND_SERIAL;

        for (f = 0; f < 3; f++){
            int32_t op = (f == 0) ? ND_OP_ADD : (f == 1) ? ND_OP_DIV : ND_OP_POW;
            nd_binary(&serial, op, &x, &y, &ref);
            for (ti = 0; ti < 5; ti++){
                oti_ctx_init(&par);
                par.exec.nthreads = threads[ti];
                par.exec.min_parallel_elems = 1;     // force the parallel path
                nd_binary(&par, op, &x, &y, &got);
                if (!bits_equal_arrays(&ref, &got)){
                    bad++;
                    fprintf(stderr, "  determinism: op %d n=%lld nthreads %d differs from serial\n", op,
                            (long long)n, threads[ti]);
                }
                nd_release(&got);
            }
            // against the reference loop (bitwise, also for the serial result)
            {
                int64_t i;
                for (i = 0; i < n; i++){
                    double expect = ref_binary(op, get_f(&x, i), get_f(&y, i));
                    if (!same_bits(get_f(&ref, i), expect)){
                        bad_ref++;
                        break;
                    }
                }
            }
            nd_release(&ref);
        }
        for (f = 0; f < 4; f++){
            int32_t fn = (f == 0) ? ND_FN_EXP : (f == 1) ? ND_FN_SIN : (f == 2) ? ND_FN_LOG : ND_FN_TANH;
            nd_unary(&serial, fn, &x, &ref);
            for (ti = 0; ti < 5; ti++){
                oti_ctx_init(&par);
                par.exec.nthreads = threads[ti];
                par.exec.min_parallel_elems = 1;
                nd_unary(&par, fn, &x, &got);
                if (!bits_equal_arrays(&ref, &got)){
                    bad++;
                    fprintf(stderr, "  determinism: fn %d n=%lld nthreads %d differs from serial\n", fn,
                            (long long)n, threads[ti]);
                }
                nd_release(&got);
            }
            nd_release(&ref);
        }
        nd_release(&x);
        nd_release(&y);

    }
    check(bad == 0,
            "determinism: binary ops and functions bit-identical at 1, 2, 3, 5, N threads");
    check(bad_ref == 0, "determinism: the serial results equal the coordinate-loop reference, bitwise");

    // strided / F-ordered operands too
    {
        ndarr_t x = {0}, y = {0}, ref = {0}, got = {0};
        int64_t sh[2] = {150, 200};
        oti_ctx serial, par;
        int ti2, ok = 1;

        nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_F, 0, &x);
        nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &y);
        fill_adversarial(&x, 77);
        fill_adversarial(&y, 78);
        oti_ctx_init(&serial);
        serial.exec.backend = OTI_BACKEND_SERIAL;
        nd_binary(&serial, ND_OP_MUL, &x, &y, &ref);
        for (ti2 = 0; ti2 < 5; ti2++){
            oti_ctx_init(&par);
            par.exec.nthreads = threads[ti2];
            par.exec.min_parallel_elems = 1;
            nd_binary(&par, ND_OP_MUL, &x, &y, &got);
            ok = ok && bits_equal_arrays(&ref, &got);
            nd_release(&got);
        }
        check(ok,
                "determinism: an F x C operand pair (30000 elements), every thread count");
        nd_release(&ref);
        nd_release(&x);
        nd_release(&y);
    }

    // below the parallel threshold the result is the same too
    {
        ndarr_t x = {0}, ref = {0}, got = {0};
        int64_t sh[1] = {5000};
        oti_ctx a, b;
        nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, 0, &x);
        fill_adversarial(&x, 4242);
        oti_ctx_init(&a);
        a.exec.min_parallel_elems = 1;
        oti_ctx_init(&b);
        b.exec.min_parallel_elems = INT64_C(1) << 40;     // never parallel
        nd_unary(&a, ND_FN_COS, &x, &ref);
        nd_unary(&b, ND_FN_COS, &x, &got);
        check(bits_equal_arrays(&ref, &got),
                "determinism: min_parallel_elems does not change the values");
        nd_release(&ref);
        nd_release(&got);
        nd_release(&x);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 1 regression (checker finding 6, elementwise half): a bad context is rejected and recorded.
static void test_fix1_ufunc(void){

    double v[4] = {1, 2, 3, 4};
    int64_t sh[1] = {4};
    ndarr_t a = {0}, o = {0}, r = {0};
    oti_ctx ctx;
    int k;

    make_from(1, sh, ND_LAYOUT_C, v, &a);
    make_from(1, sh, ND_LAYOUT_C, v, &o);
    for (k = 0; k < 3; k++){
        int expect;
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
        oti_ctx_clear_error(&ctx);
        check(nd_fill(&ctx, &o, 9.0) == expect && oti_ctx_last_error(&ctx, NULL, NULL) == expect &&
              get_f(&o, 0) == 1.0, "fix1.6: nd_fill rejects the context, records it, writes nothing");
        oti_ctx_clear_error(&ctx);
        memset(&r, 0, sizeof(r));
        check(nd_binary(&ctx, ND_OP_ADD, &a, &a, &r) == expect && r.buf == NULL &&
              oti_ctx_last_error(&ctx, NULL, NULL) == expect,
                      "fix1.6: nd_binary rejects the context and records it");
        oti_ctx_clear_error(&ctx);
        check(nd_binary_to(&ctx, ND_OP_ADD, &a, &a, &o) == expect && get_f(&o, 0) == 1.0 &&
              oti_ctx_last_error(&ctx, NULL, NULL) == expect,
                      "fix1.6: nd_binary_to rejects the context, no write");
        oti_ctx_clear_error(&ctx);
        check(nd_unary_to(&ctx, ND_FN_NEG, &a, &o) == expect && get_f(&o, 0) == 1.0 &&
              oti_ctx_last_error(&ctx, NULL, NULL) == expect,
                      "fix1.6: nd_unary_to rejects the context, no write");
        oti_ctx_clear_error(&ctx);
        check(nd_assign(&ctx, &a, &o) == expect && oti_ctx_last_error(&ctx, NULL, NULL) == expect,
              "fix1.6: nd_assign rejects the context and records it");
    }
    nd_release(&a);
    nd_release(&o);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 3 (S24): allocating results keep the K layout of the inputs; copies, empty_like, block
// writes.
static void test_fix3_ufunc(void){

    ndarr_t a = {0}, b = {0}, r = {0}, c = {0}, e = {0}, col = {0}, f = {0}, b0 = {0}, b1 = {0}, b2 = {0},
            b3 = {0};
    int64_t sh[3] = {6, 8, 5};
    int64_t st[3] = {40, 1, 8};
    int64_t i, n = 240;
    int op, fn, ok, okv;
    int64_t keep_stride_ok;
    nd_index_t idx[1];

    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &a);
    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &b);
    for (i = 0; i < n; i++){
        set_f(&a, i, 0.25 * (double)i + 0.5);
        set_f(&b, i, 1.0 + 0.125 * (double)(i % 17));
    }

    // every allocating binary operation keeps (40, 1, 8)
    ok = 1; okv = 1;
    for (op = 0; op < 7; op++){
        if (nd_binary(NULL, k_ops[op], &a, &b, &r) != OTI_OK){
            ok = 0;
            continue;
        }
        ok = ok && r.strides[0] == 40 && r.strides[1] == 1 && r.strides[2] == 8 && r.ndim == 3;
        for (i = 0; i < n; i++){
            double expect = ref_binary(k_ops[op], get_f(&a, i), get_f(&b, i));
            okv = okv && (op_bitwise(k_ops[op]) ? same_bits(get_f(&r, i), expect) : same_num(get_f(&r, i),
                    expect));
        }
        nd_release(&r);
    }
    check(ok, "fix3.S24: nd_binary of two SoA arrays returns strides (40,1,8), all 7 operations");
    check(okv, "fix3.S24: ... with the right values");

    // scalar variants, both orders
    ok = 1;
    for (op = 0; op < 7; op++){
        int left;
        for (left = 0; left < 2; left++){
            if (nd_binary_scalar(NULL, k_ops[op], &a, 1.5, left, &r) != OTI_OK){
                ok = 0;
                continue;
            }
            ok = ok && r.strides[0] == 40 && r.strides[1] == 1 && r.strides[2] == 8;
            nd_release(&r);
        }
    }
    check(ok, "fix3.S24: nd_binary_scalar keeps (40,1,8) for every operation, both operand orders");

    // every unary function
    ok = 1; okv = 1;
    for (fn = 0; fn < N_UNARY; fn++){
        if (nd_unary(NULL, k_unary[fn].code, &a, &r) != OTI_OK){
            ok = 0;
            continue;
        }
        ok = ok && r.strides[0] == 40 && r.strides[1] == 1 && r.strides[2] == 8;
        for (i = 0; i < n; i++){
            okv = okv && same_bits(get_f(&r, i), k_unary[fn].f(get_f(&a, i)));
        }
        nd_release(&r);
    }
    check(ok, "fix3.S24: nd_unary keeps (40,1,8) for all 30 functions");
    check(okv, "fix3.S24: ... with values bitwise equal to the C library");

    // mixed: a SoA array with a scalar-shaped operand and with a broadcast row keeps the SoA layout
    {
        double rowv[5] = {1, 2, 3, 4, 5};
        int64_t s5[1] = {5};
        ndarr_t row = {0};
        make_from(1, s5, ND_LAYOUT_C, rowv, &row);
        check(nd_binary(NULL, ND_OP_ADD, &a, &row, &r) == OTI_OK && r.strides[0] == 40 &&
                r.strides[1] == 1 &&
              r.strides[2] == 8, "fix3.S24: SoA + a broadcast (5,) row keeps (40,1,8)");
        nd_release(&r);
        nd_release(&row);
    }

    // nd_copy layouts
    check(nd_copy(NULL, &a, ND_LAYOUT_C, &c) == OTI_OK && c.strides[0] == 40 && c.strides[1] == 5 &&
            c.strides[2] == 1,
          "fix3: nd_copy C of the SoA array: strides (40,5,1)");
    okv = 1;
    for (i = 0; i < n; i++){
        okv = okv && get_f(&c, i) == get_f(&a, i);
    }
    check(okv, "fix3: nd_copy C values");
    nd_release(&c);
    check(nd_copy(NULL, &a, ND_LAYOUT_F, &c) == OTI_OK && c.strides[0] == 1 && c.strides[1] == 6 &&
            c.strides[2] == 48,
          "fix3: nd_copy F: strides (1,6,48)");
    nd_release(&c);
    check(nd_copy(NULL, &a, ND_LAYOUT_A, &c) == OTI_OK && c.strides[0] == 40 && c.strides[1] == 5 &&
            c.strides[2] == 1,
          "fix3: nd_copy A of the SoA array maps to C");
    nd_release(&c);
    check(nd_copy(NULL, &a, ND_LAYOUT_K, &c) == OTI_OK && c.strides[0] == 40 && c.strides[1] == 1 &&
            c.strides[2] == 8,
          "fix3: nd_copy K keeps the SoA strides (40,1,8)");
    okv = 1;
    for (i = 0; i < n; i++){
        okv = okv && get_f(&c, i) == get_f(&a, i);
    }
    check(okv, "fix3: nd_copy K values");
    nd_release(&c);

    // nd_empty_like
    check(nd_empty_like(NULL, &a, 0, &e) == OTI_OK && e.strides[0] == 40 && e.strides[1] == 1 &&
            e.strides[2] == 8 &&
          e.dtype == OTI_F64 && e.shape[0] == 6 && e.shape[1] == 8 && e.shape[2] == 5 &&
                  (e.flags & ND_RETAINED),
          "fix3: nd_empty_like keeps (40,1,8)");
    nd_release(&e);
    check(nd_empty_like(NULL, &a, ND_ALLOC_ZERO, &e) == OTI_OK && get_f(&e, 100) == 0.0 && get_f(&e,
            239) == 0.0,
          "fix3: nd_empty_like with ND_ALLOC_ZERO");
    nd_release(&e);
    {
        // zero and negative strides become a compact positive layout
        ndarr_t rv = {0}, bc = {0};
        int64_t s34[2] = {3, 4};
        nd_index_t ix[2];
        double z12[12] = {0};
        make_from(2, s34, ND_LAYOUT_C, z12, &c);
        ix[0] = mk_slice(HT, 0, 0, -1);
        ix[1] = mk_slice(0, 0, 0, 0);
        nd_view_index(&c, 2, ix, &rv);
        check(nd_empty_like(NULL, &rv, 0, &e) == OTI_OK && e.strides[0] == 4 && e.strides[1] == 1,
              "fix3: nd_empty_like of a reversed C view: compact positive C strides");
        nd_release(&e);
        nd_view_broadcast_to(&c, 3, (int64_t[]){2, 3, 4}, &bc);
        check(nd_empty_like(NULL, &bc, 0, &e) == OTI_OK && e.ndim == 3 && nd_internal_overlap(&e) == 0 &&
              e.strides[0] == 1 && e.strides[2] == 2 && e.strides[1] == 8,
              "fix3: nd_empty_like of a stride-0 broadcast view: compact, 0 stride innermost");
        nd_release(&e);
        nd_release(&c);
    }
    (void)keep_stride_ok;

    // _to writes into block views of the SoA array and only there
    idx[0].kind = ND_IDX_INT; idx[0].has = 0; idx[0].stop = 0; idx[0].step = 0; idx[0].arr = NULL;
    idx[0].start = 0; nd_view_index(&a, 1, idx, &b0);
    idx[0].start = 1; nd_view_index(&a, 1, idx, &b1);
    idx[0].start = 2; nd_view_index(&a, 1, idx, &b2);
    idx[0].start = 3; nd_view_index(&a, 1, idx, &b3);
    {
        double keep[40];
        int64_t q;
        for (q = 0; q < 40; q++){
            keep[q] = get_f(&b3, q);
        }
        check(nd_binary_to(NULL, ND_OP_MUL, &b0, &b1, &b2) == OTI_OK,
                "fix3: nd_binary_to writes block 2");
        okv = 1;
        for (q = 0; q < 40; q++){
            okv = okv && same_bits(get_f(&b2, q), get_f(&b0, q) * get_f(&b1, q)) && get_f(&b3,
                    q) == keep[q];
        }
        check(okv, "fix3: block 2 = block 0 * block 1, block 3 untouched");
        check(nd_unary_to(NULL, ND_FN_SQRT, &b0, &b3) == OTI_OK, "fix3: nd_unary_to writes block 3");
        okv = 1;
        for (q = 0; q < 40; q++){
            okv = okv && same_bits(get_f(&b3, q), sqrt(get_f(&b0, q)));
        }
        check(okv, "fix3: block 3 = sqrt(block 0)");
        check(nd_fill(NULL, &b1, -2.0) == OTI_OK && get_f(&b1, 39) == -2.0 && get_f(&b0, 0) == 0.5,
              "fix3: nd_fill of one block");
    }

    // S26: an (n,1) column times an F (n,m) matrix: the result is F
    {
        int64_t cs[2] = {4, 1}, fs[2] = {4, 3};
        double cv[4] = {1, 2, 3, 4}, fv[12];
        for (i = 0; i < 12; i++){
            fv[i] = 10.0 + (double)i;
        }
        make_from(2, cs, ND_LAYOUT_C, cv, &col);
        make_from(2, fs, ND_LAYOUT_F, fv, &f);
        check(nd_binary(NULL, ND_OP_MUL, &col, &f, &r) == OTI_OK && (r.flags & ND_F_CONTIG) &&
              !(r.flags & ND_C_CONTIG) && r.strides[0] == 1 && r.strides[1] == 4,
              "fix3.S26: (n,1) column * F (n,m): the result is F");
        okv = 1;
        for (i = 0; i < 12; i++){
            okv = okv && get_f(&r, i) == cv[i / 3] * fv[i];
        }
        check(okv, "fix3.S26: ... with the right values");
        nd_release(&r);
        nd_release(&col);
        nd_release(&f);
    }

    nd_release(&a);
    nd_release(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Phase 2: comparisons and mask operators, ND_FN_NOT.
static int ref_cmp(int32_t op, double a, double b){

    switch (op){
        case ND_OP_EQ: return a == b;
        case ND_OP_NE: return a != b;
        case ND_OP_LT: return a < b;
        case ND_OP_LE: return a <= b;
        case ND_OP_GT: return a > b;
        default: return a >= b;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_comparisons_and_masks(void){

    static const int32_t cmp[6] = {ND_OP_EQ, ND_OP_NE, ND_OP_LT, ND_OP_LE, ND_OP_GT, ND_OP_GE};
    double xv[8] = {NAN, 1.0, NAN, 2.0, -0.0, 0.0, INFINITY, -INFINITY};
    double yv[8] = {1.0, NAN, NAN, 2.0, 0.0, -0.0, INFINITY, INFINITY};
    int64_t s8[1] = {8};
    ndarr_t x = {0}, y = {0}, r = {0};
    int c, i, ok, iter, fails = 0, fails_to = 0;

    make_from(1, s8, ND_LAYOUT_C, xv, &x);
    make_from(1, s8, ND_LAYOUT_C, yv, &y);
    for (c = 0; c < 6; c++){
        char msg[96];
        ok = (nd_binary(NULL, cmp[c], &x, &y, &r) == OTI_OK && r.dtype == OTI_U8 && r.ndim == 1 &&
                r.shape[0] == 8);
        for (i = 0; ok && i < 8; i++){
            ok = ok && ((uint8_t*)r.data)[i] == (uint8_t)ref_cmp(cmp[c], xv[i], yv[i]);
        }
        snprintf(msg, sizeof(msg), "comparison op %d with NaN, +-0, inf: U8 0/1 as IEEE", cmp[c]);
        check(ok, msg);
        if (r.buf != NULL){
            nd_release(&r);
        }
    }
    // hand-derived NaN rules: NaN == NaN is 0, NaN != NaN is 1, every ordered comparison with NaN is 0
    nd_init_empty(&r);
    nd_binary(NULL, ND_OP_EQ, &x, &y, &r);
    check(r.buf != NULL && ((uint8_t*)r.data)[2] == 0 && ((uint8_t*)r.data)[4] == 1,
          "NaN == NaN is 0; -0.0 == 0.0 is 1");
    nd_release(&r);
    nd_binary(NULL, ND_OP_NE, &x, &y, &r);
    check(r.buf != NULL && ((uint8_t*)r.data)[2] == 1 && ((uint8_t*)r.data)[0] == 1,
          "NaN != NaN is 1; NaN != 1 is 1");
    nd_release(&r);
    nd_binary(NULL, ND_OP_LE, &x, &y, &r);
    check(r.buf != NULL && ((uint8_t*)r.data)[0] == 0 && ((uint8_t*)r.data)[1] == 0 &&
          ((uint8_t*)r.data)[2] == 0 &&
          ((uint8_t*)r.data)[3] == 1, "NaN <= anything is 0");
    nd_release(&r);

    // scalar comparisons, both operand orders
    for (c = 0; c < 6; c++){
        int left;
        for (left = 0; left < 2; left++){
            ok = (nd_binary_scalar(NULL, cmp[c], &x, 1.0, left, &r) == OTI_OK && r.dtype == OTI_U8);
            for (i = 0; ok && i < 8; i++){
                ok = ok && ((uint8_t*)r.data)[i] ==
                     (uint8_t)(left ? ref_cmp(cmp[c], 1.0, xv[i]) : ref_cmp(cmp[c], xv[i], 1.0));
            }
            if (!ok){
                fprintf(stderr, "  scalar comparison op %d left %d wrong\n", cmp[c], left);
            }
            check(ok, "comparison with a scalar (both orders) into a new U8 array");
            if (r.buf != NULL){
                nd_release(&r);
            }
        }
    }
    {
        ndarr_t o = {0};
        nd_alloc(NULL, OTI_U8, 1, s8, ND_LAYOUT_C, ND_ALLOC_ZERO, &o);
        check(nd_binary_scalar_to(NULL, ND_OP_GT, &x, 0.5, 0, &o) == OTI_OK &&
                ((uint8_t*)o.data)[1] == 1 &&
              ((uint8_t*)o.data)[0] == 0, "nd_binary_scalar_to comparison into a U8 out");
        nd_release(&o);
    }

    // random shapes, layouts, output views
    rng_seed(6502);
    for (iter = 0; iter < 600; iter++){
        int32_t nd, nda, ndb;
        int64_t S[OTI_ND_MAXDIM], sa[OTI_ND_MAXDIM], sb[OTI_ND_MAXDIM];
        ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bo = {0}, vo = {0}, res = {0};
        int32_t op = cmp[iter % 6];
        int64_t n, q;
        int st, good = 1;

        random_shapes(&nd, S, &nda, sa, &ndb, sb, 400);
        n = shape_size(nd, S);
        make_view(nda, sa, (int)rng_int(3), OTI_F64, &ba, &va);
        make_view(ndb, sb, (int)rng_int(3), OTI_F64, &bb, &vb);
        fill_random(&va);
        fill_random(&vb);
        ref_binary_array(ND_OP_ADD, &va, &vb, nd, S,
                g_ref);       // positions only: recompute operands below
        {
            int64_t lin;
            for (lin = 0; lin < n; lin++){
                int64_t cc[OTI_ND_MAXDIM], rem = lin, la = 0, lb = 0;
                int32_t k;
                for (k = nd - 1; k >= 0; k--){
                    cc[k] = rem % S[k];
                    rem /= S[k];
                }
                for (k = 0; k < va.ndim; k++){
                    la = la * va.shape[k] + (va.shape[k] == 1 ? 0 : cc[nd - va.ndim + k]);
                }
                for (k = 0; k < vb.ndim; k++){
                    lb = lb * vb.shape[k] + (vb.shape[k] == 1 ? 0 : cc[nd - vb.ndim + k]);
                }
                g_ref[lin] = (double)ref_cmp(op, get_f(&va, la), get_f(&vb, lb));
            }
        }
        st = nd_binary(NULL, op, &va, &vb, &res);
        if (st != OTI_OK || res.dtype != OTI_U8 || res.ndim != nd){
            good = 0;
        } else {
            for (q = 0; q < n; q++){
                good = good && (double)*(uint8_t*)elem_ptr(&res, q) == g_ref[q];
            }
            nd_release(&res);
        }
        if (!good){
            fails++;
        }
        make_view(nd, S, (int)rng_int(3), OTI_U8, &bo, &vo);
        st = nd_binary_to(NULL, op, &va, &vb, &vo);
        good = (st == OTI_OK);
        for (q = 0; good && q < n; q++){
            good = good && (double)*(uint8_t*)elem_ptr(&vo, q) == g_ref[q];
        }
        if (!good){
            fails_to++;
        }
        nd_release(&ba);
        nd_release(&bb);
        nd_release(&bo);
    }
    check(fails == 0, "comparisons: 600 random broadcasts / layouts into new U8 arrays agree with IEEE");
    check(fails_to == 0, "comparisons into random U8 output views (negative / doubled / F strides)");

    // K layout of a comparison result (S24): F inputs give an F mask
    {
        ndarr_t f = {0};
        int64_t s34[2] = {3, 4};
        double v12[12] = {0};
        make_from(2, s34, ND_LAYOUT_F, v12, &f);
        nd_binary(NULL, ND_OP_EQ, &f, &f, &r);
        check(r.dtype == OTI_U8 && r.strides[0] == 1 && r.strides[1] == 3,
                "comparison of F arrays gives an F mask");
        nd_release(&r);
        nd_release(&f);
    }

    // errors
    {
        ndarr_t u = {0}, w = {0}, o8 = {0};
        uint8_t bits[8] = {0, 1, 1, 0, 1, 0, 0, 1};
        make_desc(&u, bits, OTI_U8, 1, s8, (int64_t[]){1}, ND_WRITEABLE);
        nd_update_flags(&u);
        nd_alloc(NULL, OTI_F64, 1, s8, ND_LAYOUT_C, 0, &w);
        nd_alloc(NULL, OTI_U8, 1, s8, ND_LAYOUT_C, 0, &o8);
        check(nd_binary_to(NULL, ND_OP_EQ, &x, &y, &w) == OTI_ERR_DTYPE,
                "comparison into an F64 out -> DTYPE");
        check(nd_binary_to(NULL, ND_OP_ADD, &x, &y, &o8) == OTI_ERR_DTYPE,
                "addition into a U8 out -> DTYPE");
        check(nd_binary(NULL, ND_OP_AND, &x, &y, &r) == OTI_ERR_DTYPE, "AND of F64 operands -> DTYPE");
        check(nd_binary(NULL, ND_OP_OR, &x, &u, &r) == OTI_ERR_DTYPE, "OR of F64 and U8 -> DTYPE");
        check(nd_unary(NULL, ND_FN_NOT, &x, &r) == OTI_ERR_DTYPE, "NOT of an F64 array -> DTYPE");
        check(nd_unary(NULL, ND_FN_SQRT, &u, &r) == OTI_ERR_DTYPE, "sqrt of a U8 array -> DTYPE");

        // mask operators on 0 / 1 masks
        {
            uint8_t b2[8] = {1, 1, 0, 0, 1, 0, 1, 0};
            ndarr_t m2 = {0};
            make_desc(&m2, b2, OTI_U8, 1, s8, (int64_t[]){1}, ND_WRITEABLE);
            nd_update_flags(&m2);
            ok = nd_binary(NULL, ND_OP_AND, &u, &m2, &r) == OTI_OK && r.dtype == OTI_U8;
            for (i = 0; ok && i < 8; i++){
                ok = ok && ((uint8_t*)r.data)[i] == (uint8_t)(bits[i] & b2[i]);
            }
            check(ok, "AND of two masks");
            nd_release(&r);
            ok = nd_binary(NULL, ND_OP_OR, &u, &m2, &r) == OTI_OK;
            for (i = 0; ok && i < 8; i++){
                ok = ok && ((uint8_t*)r.data)[i] == (uint8_t)(bits[i] | b2[i]);
            }
            check(ok, "OR of two masks");
            nd_release(&r);
            ok = nd_binary(NULL, ND_OP_XOR, &u, &m2, &r) == OTI_OK;
            for (i = 0; ok && i < 8; i++){
                ok = ok && ((uint8_t*)r.data)[i] == (uint8_t)(bits[i] ^ b2[i]);
            }
            check(ok, "XOR of two masks");
            nd_release(&r);
            ok = nd_unary(NULL, ND_FN_NOT, &u, &r) == OTI_OK && r.dtype == OTI_U8;
            for (i = 0; ok && i < 8; i++){
                ok = ok && ((uint8_t*)r.data)[i] == (uint8_t)(bits[i] ? 0 : 1);
            }
            check(ok, "NOT of a mask: 0 -> 1, 1 -> 0");
            nd_release(&r);
            check(nd_unary_to(NULL, ND_FN_NOT, &u, &o8) == OTI_OK && ((uint8_t*)o8.data)[0] == 1 &&
                  ((uint8_t*)o8.data)[1] == 0, "NOT into a U8 out");
            check(nd_unary_to(NULL, ND_FN_NOT, &u, &u) == OTI_OK && bits[0] == 1 && bits[1] == 0,
                  "NOT in place (exact alias)");
            check(nd_unary_to(NULL, ND_FN_NOT, &u, &w) == OTI_ERR_DTYPE, "NOT into an F64 out -> DTYPE");
        }
        nd_release(&w);
        nd_release(&o8);
    }
    nd_release(&x);
    nd_release(&y);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Phase 2: elementwise results bit-identical at 1, 2, N threads above the parallel threshold, and the
// trivially-iterable fast path against the general path.
static void test_phase2_threads_and_fast_path(void){

    enum { N = 1100000 };
    int64_t sh[1];
    ndarr_t x = {0}, y = {0}, ref = {0}, got = {0};
    static const int32_t threads[4] = {2, 3, 5, 0};
    int f, t, bad = 0;
    oti_ctx serial, par;
    static const int32_t cmp[4] = {ND_OP_EQ, ND_OP_LT, ND_OP_GE, ND_OP_NE};

    sh[0] = N;
    nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, 0, &x);
    nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, 0, &y);
    fill_adversarial(&x, 31337);
    fill_adversarial(&y, 4711);
    oti_ctx_init(&serial);
    serial.exec.backend = OTI_BACKEND_SERIAL;

    for (f = 0; f < 10; f++){
        int is_cmp = (f >= 6);
        int is_un = (f == 5 || f == 4);
        int32_t code = f < 4 ? k_ops[f] : f == 4 ? ND_FN_EXP : f == 5 ? ND_FN_SIN : cmp[f - 6];
        int st;
        nd_init_empty(&ref);
        nd_init_empty(&got);
        st = is_un ? nd_unary(&serial, code, &x, &ref) : nd_binary(&serial, code, &x, &y, &ref);
        if (st != OTI_OK){
            bad++;
            continue;
        }
        for (t = 0; t < 4; t++){
            oti_ctx_init(&par);
            par.exec.nthreads = threads[t];
            st = is_un ? nd_unary(&par, code, &x, &got) : nd_binary(&par, code, &x, &y, &got);
            if (st != OTI_OK || ref.buf == NULL || memcmp(ref.data, got.data,
                    (size_t)N * (size_t)nd_itemsize(ref.dtype)) != 0){
                bad++;
                fprintf(stderr, "  threads: op/fn %d nthreads %d differs from serial\n", code,
                        threads[t]);
            }
            if (got.buf != NULL){
                nd_release(&got);
            }
        }
        // the default context (default threshold, inherited threads)
        st = is_un ? nd_unary(NULL, code, &x, &got) : nd_binary(NULL, code, &x, &y, &got);
        if (st != OTI_OK || ref.buf == NULL ||
            memcmp(ref.data, got.data, (size_t)N * (size_t)nd_itemsize(ref.dtype)) != 0){
            bad++;
        }
        if (got.buf != NULL){
            nd_release(&got);
        }
        nd_release(&ref);
        (void)is_cmp;
    }
    check(bad == 0,
            "1.1M elements: ADD SUB MUL DIV exp sin comparisons bit-identical at 2, 3, 5, N threads");

    // the fast path (contiguous, same layout) against the general path (strided copies of the same data)
    {
        enum { M = 6001 };
        ndarr_t cx = {0}, cy = {0}, bx = {0}, by = {0}, sx = {0}, sy = {0}, rev = {0}, r1 = {0}, r2 = {0};
        int64_t msh[1], bsh[1];
        nd_index_t ix[1];
        int64_t i;
        int op, okf = 1;

        msh[0] = M;
        bsh[0] = 2 * M;
        nd_alloc(NULL, OTI_F64, 1, msh, ND_LAYOUT_C, 0, &cx);
        nd_alloc(NULL, OTI_F64, 1, msh, ND_LAYOUT_C, 0, &cy);
        nd_alloc(NULL, OTI_F64, 1, bsh, ND_LAYOUT_C, 0, &bx);
        nd_alloc(NULL, OTI_F64, 1, bsh, ND_LAYOUT_C, 0, &by);
        fill_adversarial(&cx, 11);
        fill_adversarial(&cy, 12);
        ix[0] = mk_slice(HT, 0, 0, 2);
        nd_view_index(&bx, 1, ix, &sx);
        nd_view_index(&by, 1, ix, &sy);
        for (i = 0; i < M; i++){
            set_f(&sx, i, get_f(&cx, i));
            set_f(&sy, i, get_f(&cy, i));
        }
        for (op = 0; op < 7; op++){
            nd_binary(NULL, k_ops[op], &cx, &cy, &r1);
            nd_binary(NULL, k_ops[op], &sx, &sy, &r2);
            okf = okf && memcmp(r1.data, r2.data, (size_t)M * 8) == 0;
            nd_release(&r1);
            nd_release(&r2);
        }
        for (op = 0; op < 6; op++){
            static const int32_t c6[6] = {ND_OP_EQ, ND_OP_NE, ND_OP_LT, ND_OP_LE, ND_OP_GT, ND_OP_GE};
            nd_init_empty(&r1);
            nd_init_empty(&r2);
            nd_binary(NULL, c6[op], &cx, &cy, &r1);
            nd_binary(NULL, c6[op], &sx, &sy, &r2);
            okf = okf && r1.buf != NULL && r2.buf != NULL && memcmp(r1.data, r2.data, (size_t)M) == 0;
            nd_release(&r1);
            nd_release(&r2);
        }
        for (op = 0; op < N_UNARY; op++){
            nd_unary(NULL, k_unary[op].code, &cx, &r1);
            nd_unary(NULL, k_unary[op].code, &sx, &r2);
            okf = okf && memcmp(r1.data, r2.data, (size_t)M * 8) == 0;
            nd_release(&r1);
            nd_release(&r2);
        }
        check(okf,
                "fast path (contiguous) = general path (stride 2): 7 ops, 6 comparisons, 30 functions");

        // reversed views of reversed data: same values in the same logical order
        {
            double* tmp = (double*)malloc(sizeof(double) * M);
            ndarr_t br = {0}, vr = {0};
            int64_t one[1] = {M};
            nd_index_t rx[1];
            int ok2 = 1;
            nd_alloc(NULL, OTI_F64, 1, one, ND_LAYOUT_C, 0, &br);
            rx[0] = mk_slice(HT, 0, 0, -1);
            nd_view_index(&br, 1, rx, &vr);
            for (i = 0; i < M; i++){
                tmp[i] = get_f(&cx, i);
                set_f(&vr, i, tmp[i]);
            }
            nd_binary(NULL, ND_OP_MUL, &cx, &cx, &r1);
            nd_binary(NULL, ND_OP_MUL, &vr, &vr, &r2);
            for (i = 0; i < M; i++){
                ok2 = ok2 && same_bits(get_f(&r1, i), get_f(&r2, i));
            }
            check(ok2, "a negative-stride operand gives the contiguous result, bitwise");
            nd_release(&r1);
            nd_release(&r2);
            nd_release(&br);
            free(tmp);
        }
        // a rank-0 / one-element operand against the same value in a full array
        {
            ndarr_t sc = {0}, full = {0};
            double c = 3.25;
            int64_t i2;
            int ok3 = 1;
            make_from(0, NULL, ND_LAYOUT_C, &c, &sc);
            nd_alloc(NULL, OTI_F64, 1, msh, ND_LAYOUT_C, 0, &full);
            nd_fill(NULL, &full, c);
            for (op = 0; op < 7; op++){
                nd_binary(NULL, k_ops[op], &cx, &sc, &r1);
                nd_binary(NULL, k_ops[op], &cx, &full, &r2);
                for (i2 = 0; i2 < M; i2++){
                    ok3 = ok3 && same_bits(get_f(&r1, i2), get_f(&r2, i2)) ;
                }
                nd_release(&r1);
                nd_release(&r2);
            }
            check(ok3, "a rank-0 operand gives the same results as a full array of that value (7 ops)");
            nd_release(&sc);
            nd_release(&full);
        }
        // in place (exact alias) against out of place
        {
            ndarr_t cp = {0};
            int ok4 = 1;
            for (op = 0; op < 7; op++){
                nd_copy(NULL, &cx, ND_LAYOUT_C, &cp);
                nd_binary_to(NULL, k_ops[op], &cp, &cy, &cp);
                nd_binary(NULL, k_ops[op], &cx, &cy, &r1);
                ok4 = ok4 && memcmp(cp.data, r1.data, (size_t)M * 8) == 0;
                nd_release(&r1);
                nd_release(&cp);
            }
            check(ok4, "in place (out == a) equals out of place, bitwise, 7 ops");
        }
        (void)rev;
        nd_release(&cx); nd_release(&cy); nd_release(&bx); nd_release(&by);
    }
    nd_release(&x);
    nd_release(&y);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_filled_creators();
    test_eye();
    test_arange();
    test_linspace();
    test_copies();
    test_reshape();
    test_binary_hand();
    test_pow_fast_paths();
    test_binary_random();
    test_binary_errors();
    test_unary_all_functions();
    test_unary_random_layouts();
    test_unary_misc();
    test_binary_aliasing();
    test_assign_snapshot();
    test_fill();
    test_guard_regions();
    test_determinism();

    test_fix1_ufunc();

    test_fix3_ufunc();

    test_comparisons_and_masks();
    test_phase2_threads_and_fast_path();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
