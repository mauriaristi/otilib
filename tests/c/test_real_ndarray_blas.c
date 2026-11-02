/* Tests of the ndarray BLAS dispatch (include/oti/real/ndarray/blas.h, Phase 3): nd_gemm, nd_gemv,
   nd_ger,
 * nd_matmul(_to), nd_dot(_to) and the level 1 functions nd_vdot, nd_axpy, nd_scal, nd_nrm2, nd_asum,
 * nd_iamax.
 *
 * Written from PLAN-ndarray-contracts.md (rows 9.1, 9.2, 1.4, 3.4) and blas.h, independently of
 * src/c/real/ndarray/blas.c. Oracles: the definitions evaluated in long double with plain loops (naive
 * GEMM, matmul by batch coordinates, dot / axpy / nrm2 by their sums). Tolerances: every product element
 * is
 * compared to 4 * (k + 2) * DBL_EPSILON * sum(|a_il b_lj|) (+ |beta c| for the accumulated term), the
 * classical
 * rounding bound of a length-k dot product evaluated in ANY order (gamma_k = k eps / (1 - k eps)), with a
 * safety factor of 4, because the BLAS in use orders the sums as it likes; nrm2 uses 8 * (n + 2) eps
 * relative.
 * Layouts of the operands: C, F, padded leading dimension (C and F), transposed view, negative stride,
 * step-2 columns, stride-0 broadcast rows (inputs), reversed columns; vectors with positive, negative,
 * doubled,
 * zero strides. Where the contracts promise that no pack is made ('N' / 'T' usable operands, section 9.1)
 * the test runs with a 1-byte temporary budget: it must still succeed, and an operand that has to be
 * packed
 * must fail with MEMORY. Guard regions: the unaddressed elements of padded or strided outputs are NaN
 * canaries
 * that must survive. */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // contracts S23
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
#include <oti/core/exec.h>
#include <oti/core/lapack.h>
#include <oti/real/ndarray/structures.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>
#include <oti/real/ndarray/views.h>
#include <oti/real/ndarray/blas.h>

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
static int same_bits(double a, double b){

    if (isnan(a) && isnan(b)){
        return 1;
    }
    return memcmp(&a, &b, sizeof(double)) == 0;

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
// Small random values for matmul tests.
static void fill_random_small(ndarr_t* a){

    int64_t n = shape_size(a->ndim, a->shape), i;

    for (i = 0; i < n; i++){
        set_f(a, i, (rng_uniform() - 0.5) * 2.0);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Matrix makers: 2-D operands in many layouts, filled with random values (logical C order)
// =======================================================================================================

#define KINDS_ALL   9
#define KINDS_OUT   7

// *******************************************************************************************************
// kind: 0 C, 1 F, 2 C with padded leading dimension, 3 F with padded leading dimension, 4 transposed view
// of a C array, 5 rows reversed (negative stride), 6 columns taken with step 2, 7 broadcast rows (stride
// 0
// on axis 0; inputs only), 8 columns reversed. `base` keeps the allocation (the caller releases it).
static void make_mat(int64_t r, int64_t c, int kind, ndarr_t* base, ndarr_t* view){

    int64_t bs[2];
    nd_index_t ix[2];

    nd_init_empty(base);
    nd_init_empty(view);
    switch (kind){
        case 0:
        case 1:
            bs[0] = r; bs[1] = c;
            nd_alloc(NULL, OTI_F64, 2, bs, kind == 0 ? ND_LAYOUT_C : ND_LAYOUT_F, 0, base);
            *view = *base;
            view->flags &= ~ND_RETAINED;
            break;
        case 2:
        case 3:
            bs[0] = r + 2; bs[1] = c + 3;
            nd_alloc(NULL, OTI_F64, 2, bs, kind == 2 ? ND_LAYOUT_C : ND_LAYOUT_F, 0, base);
            ix[0] = mk_slice(HS | HP, 0, r, 0);
            ix[1] = mk_slice(HS | HP, 0, c, 0);
            nd_view_index(base, 2, ix, view);
            break;
        case 4:
            bs[0] = c; bs[1] = r;
            nd_alloc(NULL, OTI_F64, 2, bs, ND_LAYOUT_C, 0, base);
            nd_view_transpose(base, 0, NULL, view);
            break;
        case 5:
            bs[0] = r; bs[1] = c;
            nd_alloc(NULL, OTI_F64, 2, bs, ND_LAYOUT_C, 0, base);
            ix[0] = mk_slice(HT, 0, 0, -1);
            ix[1] = mk_slice(0, 0, 0, 0);
            nd_view_index(base, 2, ix, view);
            break;
        case 6:
            bs[0] = r; bs[1] = 2 * c;
            nd_alloc(NULL, OTI_F64, 2, bs, ND_LAYOUT_C, 0, base);
            ix[0] = mk_slice(0, 0, 0, 0);
            ix[1] = mk_slice(HT, 0, 0, 2);
            nd_view_index(base, 2, ix, view);
            break;
        case 7:
            bs[0] = 1; bs[1] = c;
            nd_alloc(NULL, OTI_F64, 2, bs, ND_LAYOUT_C, 0, base);
            nd_view_broadcast_to(base, 2, (int64_t[]){r, c}, view);
            break;
        default:
            bs[0] = r; bs[1] = c;
            nd_alloc(NULL, OTI_F64, 2, bs, ND_LAYOUT_C, 0, base);
            ix[0] = mk_slice(0, 0, 0, 0);
            ix[1] = mk_slice(HT, 0, 0, -1);
            nd_view_index(base, 2, ix, view);
            break;
    }
    if (view->shape[0] != r || view->shape[1] != c){
        // a doubled or padded slice can be longer than asked for: trim
        view->shape[0] = r;
        view->shape[1] = c;
        nd_update_flags(view);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fill_mat(ndarr_t* v, int kind, double scale){

    int64_t r = v->shape[0], c = v->shape[1], i, j;

    if (kind == 7){
        // broadcast rows: fill the single stored row, so every row is equal
        ndarr_t row = *v;
        for (j = 0; j < c; j++){
            ((double*)row.data)[j * v->strides[1]] = scale * (rng_uniform() - 0.5);
        }
        return;
    }
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            ((double*)v->data)[i * v->strides[0] + j * v->strides[1]] = scale * (rng_uniform() - 0.5);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double mget(const ndarr_t* m, int64_t i, int64_t j){

    return ((double*)m->data)[i * m->strides[0] + j * m->strides[1]];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// c = alpha op(a) op(b) + beta c0 by definition in long double; tol[i * n + j] receives the rounding
// bound k * eps * (|alpha| sum |a||b| + |beta c0|) times a safety factor of 4 (the classical bound for a
// dot product evaluated in any order, gamma_k).
static void ref_gemm(int ta, int tb, double alpha, const ndarr_t* a, const ndarr_t* b, double beta,
                     const ndarr_t* c0, int64_t m, int64_t n, int64_t k, double* res, double* tol){

    int64_t i, j, l;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            long double s = 0.0L, sa = 0.0L;
            for (l = 0; l < k; l++){
                double av = ta ? mget(a, l, i) : mget(a, i, l);
                double bv = tb ? mget(b, j, l) : mget(b, l, j);
                s += (long double)av * (long double)bv;
                sa += fabsl((long double)av * (long double)bv);
            }
            s *= (long double)alpha;
            sa *= fabsl((long double)alpha);
            if (beta != 0.0){
                long double c0v = (long double)mget(c0, i, j);
                s += (long double)beta * c0v;
                sa += fabsl((long double)beta * c0v);
            }
            res[i * n + j] = (double)s;
            tol[i * n + j] = 4.0 * (double)(k + 2) * DBL_EPSILON * (double)sa + 1e-300;
        }
    }

}
// -------------------------------------------------------------------------------------------------------


static double g_gres[64 * 64];
static double g_gtol[64 * 64];

#define CANARY UINT64_C(0x7FF8DEADBEEF0001)

// *******************************************************************************************************
// Fills the whole base allocation with a NaN canary, then the view elements are written by the caller.
static void canary_base(ndarr_t* base){

    int64_t n = nd_buffer_nbytes(base->buf) / 8, i;
    uint64_t bits = CANARY;

    for (i = 0; i < n; i++){
        memcpy((double*)nd_buffer_base(base->buf) + i, &bits, 8);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when every element of the base allocation that the view does not address still holds the canary.
static int canary_ok(const ndarr_t* base, const ndarr_t* view){

    int64_t n = nd_buffer_nbytes(base->buf) / 8, i, tot = shape_size(view->ndim, view->shape);
    unsigned char* touched = (unsigned char*)calloc((size_t)(n > 0 ? n : 1), 1);
    const double* b0 = (const double*)nd_buffer_base(base->buf);
    uint64_t bits = CANARY;
    int ok = 1;

    for (i = 0; i < tot; i++){
        int64_t off = (double*)elem_ptr(view, i) - b0;
        if (off >= 0 && off < n){
            touched[off] = 1;
        }
    }
    for (i = 0; i < n; i++){
        if (!touched[i] && memcmp(&b0[i], &bits, 8) != 0){
            ok = 0;
        }
    }
    free(touched);
    return ok;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 9.1 GEMM
// =======================================================================================================

// *******************************************************************************************************
static void test_gemm_random(void){

    int iter, fails = 0, fails_nan = 0, fails_guard = 0, ka, kb, kc, nk0 = 0;
    static const int64_t dims[] = {0, 1, 2, 3, 5, 6, 9, 17, 33};

    rng_seed(1969);
    for (iter = 0; iter < 3000; iter++){

        int64_t m = dims[rng_int(9)], n = dims[rng_int(9)], k = dims[rng_int(9)];
        int ta = (int)rng_int(2), tb = (int)rng_int(2);
        double alpha = (rng_int(8) == 0) ? 0.0 : (rng_uniform() - 0.5) * 4.0;
        double beta = rng_int(3) == 0 ? 0.0 : (rng_int(4) == 0 ? 1.0 : (rng_uniform() - 0.5) * 3.0);
        ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bc = {0}, vc = {0};
        int64_t ar = ta ? k : m, ac = ta ? m : k, br = tb ? n : k, bcols = tb ? k : n;
        int64_t i, j;
        int st, ok = 1, nanc = 0;
        double* c0 = (double*)malloc(sizeof(double) * (size_t)(m * n + 1));

        if (m * n > 64 * 64){
            continue;
        }
        ka = (int)rng_int(KINDS_ALL);
        kb = (int)rng_int(KINDS_ALL);
        kc = (int)rng_int(KINDS_OUT);
        make_mat(ar, ac, ka, &ba, &va);
        make_mat(br, bcols, kb, &bb, &vb);
        make_mat(m, n, kc, &bc, &vc);
        fill_mat(&va, ka, 2.0);
        fill_mat(&vb, kb, 2.0);
        canary_base(&bc);
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                double v = (rng_uniform() - 0.5) * 2.0;
                if (beta == 0.0 && rng_int(2) == 0){
                    v = NAN;                          // beta = 0: C is not read, NaN must not propagate
                    nanc = 1;
                }
                ((double*)vc.data)[i * vc.strides[0] + j * vc.strides[1]] = v;
                c0[i * n + j] = v;
            }
        }
        {
            ndarr_t c0v = {0};
            int64_t sh2[2];
            sh2[0] = m; sh2[1] = n;
            make_desc(&c0v, c0, OTI_F64, 2, sh2, (int64_t[]){n > 0 ? n : 1, 1}, 0);
            ref_gemm(ta, tb, alpha, &va, &vb, beta, &c0v, m, n, k, g_gres, g_gtol);
        }
        st = nd_gemm(NULL, ta, tb, alpha, &va, &vb, beta, &vc);
        if (st != OTI_OK){
            ok = 0;
        } else {
            for (i = 0; ok && i < m; i++){
                for (j = 0; j < n; j++){
                    double got = mget(&vc, i, j), want = g_gres[i * n + j];
                    if (!(fabs(got - want) <= g_gtol[i * n + j]) || isnan(got)){
                        ok = 0;
                        if (fails < 4){
                            fprintf(stderr,
                                    "  gemm iter %d (m%lld n%lld k%lld %d %d k%d %d %d b%g): "
                                    "C[%lld,%lld] = %.17g, want %.17g +- %g\n", iter, (long long)m,
                                            (long long)n,
                                    (long long)k, ta, tb, ka, kb, kc, beta, (long long)i, (long long)j,
                                            got, want,
                                    g_gtol[i * n + j]);
                        }
                        break;
                    }
                }
            }
            if (st == OTI_OK && !canary_ok(&bc, &vc)){
                fails_guard++;
            }
        }
        if (!ok){
            fails++;
            if (nanc){
                fails_nan++;
            }
            if (st != OTI_OK && fails < 4){
                fprintf(stderr, "  gemm iter %d: status %d\n", iter, st);
            }
        }
        if (k == 0 && m * n > 0){
            nk0++;
        }
        nd_release(&ba); nd_release(&bb); nd_release(&bc);
        free(c0);
    }
    check(fails == 0,
            "nd_gemm: 3000 random m, n, k, transposes, 9 / 9 / 7 layouts, alpha, beta vs the definition");
    check(fails_nan == 0, "nd_gemm: beta = 0 never reads C (NaN in C does not propagate)");
    check(fails_guard == 0,
            "nd_gemm: only the C view is written (canaries around padded / strided outputs)");
    check(nk0 > 0, "nd_gemm: the random cases include k = 0");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_gemm_hand(void){

    ndarr_t a = {0}, b = {0}, c = {0};
    double av[6] = {1, 2, 3, 4, 5, 6};       // (2,3)
    double bv[6] = {7, 8, 9, 10, 11, 12};    // (3,2)
    int64_t sa[2] = {2, 3}, sb[2] = {3, 2}, sc[2] = {2, 2};
    double zero4[4] = {0};

    make_from(2, sa, ND_LAYOUT_C, av, &a);
    make_from(2, sb, ND_LAYOUT_C, bv, &b);
    make_from(2, sc, ND_LAYOUT_C, zero4, &c);
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &c) == OTI_OK && get_f(&c, 0) == 58 && get_f(&c,
            1) == 64 &&
          get_f(&c, 2) == 139 && get_f(&c, 3) == 154,
                  "gemm [[1,2,3],[4,5,6]] x [[7,8],[9,10],[11,12]] = [[58,64],[139,154]]");
    check(nd_gemm(NULL, 0, 0, 2.0, &a, &b, 1.0, &c) == OTI_OK && get_f(&c, 0) == 174 && get_f(&c,
            3) == 462,
          "gemm alpha 2, beta 1 accumulates: [[174,192],[417,462]]");
    nd_release(&a); nd_release(&b); nd_release(&c);

    // k = 0, m = 0, n = 0
    {
        ndarr_t a0 = {0}, b0 = {0}, c2 = {0};
        int64_t s02[2] = {2, 0}, s20[2] = {0, 3}, s23[2] = {2, 3};
        double cv[6] = {NAN, 2, 3, 4, 5, 6};
        nd_alloc(NULL, OTI_F64, 2, s02, ND_LAYOUT_C, 0, &a0);
        nd_alloc(NULL, OTI_F64, 2, s20, ND_LAYOUT_C, 0, &b0);
        make_from(2, s23, ND_LAYOUT_C, cv, &c2);
        check(nd_gemm(NULL, 0, 0, 1.0, &a0, &b0, 0.0, &c2) == OTI_OK && get_f(&c2, 0) == 0.0 && get_f(&c2,
                5) == 0.0,
              "k = 0, beta = 0: C = 0 (the NaN in C is not propagated)");
        {
            double c6[6] = {1, 2, 3, 4, 5, 6};
            int i;
            for (i = 0; i < 6; i++){
                set_f(&c2, i, c6[i]);
            }
        }
        check(nd_gemm(NULL, 0, 0, 1.0, &a0, &b0, 3.0, &c2) == OTI_OK && get_f(&c2, 0) == 3 && get_f(&c2,
                5) == 18,
              "k = 0, beta = 3: C = 3 C");
        nd_release(&a0); nd_release(&b0); nd_release(&c2);
        // m = 0 or n = 0: nothing is written, no error
        {
            int64_t s0k[2] = {0, 4}, sk3[2] = {4, 3}, s03[2] = {0, 3};
            ndarr_t x = {0}, y = {0}, z = {0};
            nd_alloc(NULL, OTI_F64, 2, s0k, ND_LAYOUT_C, 0, &x);
            nd_alloc(NULL, OTI_F64, 2, sk3, ND_LAYOUT_C, ND_ALLOC_ZERO, &y);
            nd_alloc(NULL, OTI_F64, 2, s03, ND_LAYOUT_C, 0, &z);
            check(nd_gemm(NULL, 0, 0, 1.0, &x, &y, 0.0, &z) == OTI_OK, "m = 0: OK, nothing to do");
            nd_release(&x); nd_release(&y); nd_release(&z);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_gemm_errors(void){

    ndarr_t a = {0}, b = {0}, c = {0}, u = {0}, ro = {0}, ov = {0}, v1 = {0};
    int64_t sa[2] = {3, 4}, sb[2] = {4, 5}, sc[2] = {3, 5}, s3[1] = {3};
    double z[60] = {0};

    make_from(2, sa, ND_LAYOUT_C, z, &a);
    make_from(2, sb, ND_LAYOUT_C, z, &b);
    make_from(2, sc, ND_LAYOUT_C, z, &c);
    nd_alloc(NULL, OTI_U8, 2, sa, ND_LAYOUT_C, 0, &u);
    nd_alloc(NULL, OTI_F64, 1, s3, ND_LAYOUT_C, 0, &v1);
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &c) == OTI_OK, "gemm (3,4)x(4,5) -> (3,5)");
    check(nd_gemm(NULL, 1, 0, 1.0, &a, &b, 0.0, &c) == OTI_ERR_SHAPE,
            "gemm with transa: (4,3)x(4,5) -> SHAPE");
    check(nd_gemm(NULL, 0, 1, 1.0, &a, &b, 0.0, &c) == OTI_ERR_SHAPE,
            "gemm with transb: inner dimensions differ -> SHAPE");
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &a, 0.0, &c) == OTI_ERR_SHAPE,
            "(3,4)x(3,4): inner mismatch -> SHAPE");
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &a) == OTI_ERR_SHAPE, "C of the wrong shape -> SHAPE");
    check(nd_gemm(NULL, 0, 0, 1.0, &v1, &b, 0.0, &c) == OTI_ERR_SHAPE, "a 1-D operand to gemm -> SHAPE");
    check(nd_gemm(NULL, 0, 0, 1.0, &u, &b, 0.0, &c) == OTI_ERR_DTYPE, "a U8 operand -> DTYPE");
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &u) == OTI_ERR_DTYPE, "a U8 C -> DTYPE");
    {
        ndarr_t d = {0};
        make_desc(&d, c.data, OTI_F64, 2, sc, c.strides, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &ro) == OTI_ERR_READONLY, "read-only C -> READONLY");
        nd_release(&ro);
        make_desc(&d, c.data, OTI_F64, 2, sc, (int64_t[]){0, 1}, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
        check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &ov) == OTI_ERR_LAYOUT,
                "C with internal overlap (stride 0) -> LAYOUT");
        nd_release(&ov);
    }
    // C overlapping A or B -> LAYOUT (square case: C is A itself, or a view of A's memory)
    {
        ndarr_t s = {0}, t = {0}, rev = {0};
        int64_t s33[2] = {3, 3};
        nd_index_t ix[2];
        make_from(2, s33, ND_LAYOUT_C, z, &s);
        make_from(2, s33, ND_LAYOUT_C, z, &t);
        check(nd_gemm(NULL, 0, 0, 1.0, &s, &t, 0.0, &s) == OTI_ERR_LAYOUT, "C = A -> LAYOUT");
        check(nd_gemm(NULL, 0, 0, 1.0, &s, &t, 0.0, &t) == OTI_ERR_LAYOUT, "C = B -> LAYOUT");
        ix[0] = mk_slice(HT, 0, 0, -1);
        ix[1] = mk_slice(0, 0, 0, 0);
        nd_view_index(&s, 2, ix, &rev);
        check(nd_gemm(NULL, 0, 0, 1.0, &s, &t, 0.0, &rev) == OTI_ERR_LAYOUT,
                "C = A[::-1] (partial overlap) -> LAYOUT");
        nd_release(&s); nd_release(&t);
    }
    // last error
    {
        oti_ctx ctx;
        oti_ctx_init(&ctx);
        check(nd_gemm(&ctx, 0, 0, 1.0, &a, &a, 0.0, &c) == OTI_ERR_SHAPE &&
              oti_ctx_last_error(&ctx, NULL, NULL) == OTI_ERR_SHAPE, "a failing nd_gemm records SHAPE");
        ctx.device_type = 2;
        check(nd_gemm(&ctx, 0, 0, 1.0, &a, &b, 0.0, &c) == oti_ctx_check(&ctx),
                "a bad context is rejected");
    }
    nd_release(&a); nd_release(&b); nd_release(&c); nd_release(&u); nd_release(&v1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Singleton extents: their strides are irrelevant (contracts 9.1), and wrap_trusted accepts any stride.
static void test_gemm_odd_singleton_strides(void){

    static double mem[4096];
    double wantv[24];
    ndarr_t a = {0}, b = {0}, c = {0};
    int64_t i, j, l;
    int ok = 1;
    int case_no;

    rng_seed(55);
    for (i = 0; i < 4096; i++){
        mem[i] = (rng_uniform() - 0.5) * 2.0;
    }
    for (case_no = 0; case_no < 6; case_no++){
        int64_t m = (case_no < 3) ? 1 : 4, n = (case_no % 3 == 1) ? 1 : 3, k = (case_no == 2 ||
                case_no == 5) ? 1 : 5;
        int64_t sa[2] = {m, k}, sb[2] = {k, n}, sc[2] = {m, n};
        int64_t sta[2] = {k == 1 ? 77 : k, m == 1 ? 53 : 1};
        int64_t stb[2] = {n == 1 ? 1 : n, n == 1 ? 91 : 1};
        int64_t stc[2] = {n == 1 ? 13 : n, n == 1 ? 17 : 1};
        double c0[24];
        double* cptr = mem + 2000;
        if (m > 1 && k > 1){
            sta[0] = k; sta[1] = 1;
        } else if (m > 1){
            sta[0] = 1; sta[1] = 29;
        }
        make_desc(&a, mem, OTI_F64, 2, sa, sta, 0);
        make_desc(&b, mem + 500, OTI_F64, 2, sb, stb, 0);
        make_desc(&c, cptr, OTI_F64, 2, sc, stc, ND_WRITEABLE);
        if (nd_validate(&a, NULL, NULL, 0) || nd_validate(&b, NULL, NULL, 0) || nd_validate(&c, NULL,
                NULL, ND_V_OUTPUT)){
            continue;
        }
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                c0[i * n + j] = 0.0;
                cptr[i * c.strides[0] + j * c.strides[1]] = 99.0;
            }
        }
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                long double s = 0;
                for (l = 0; l < k; l++){
                    s += (long double)mget(&a, i, l) * (long double)mget(&b, l, j);
                }
                wantv[i * n + j] = (double)s;
            }
        }
        (void)c0;
        if (nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &c) != OTI_OK){
            ok = 0;
            continue;
        }
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                ok = ok && fabs(mget(&c, i, j) - wantv[i * n + j]) <= 1e-13;
            }
        }
    }
    check(ok, "gemm with singleton extents and arbitrary strides on them (m, n or k = 1): correct");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Dispatch: operands that 'N' or 'T' can use directly need no pack, so a 1-byte temporary budget still
// works; negative or doubled strides must be packed, which the budget refuses. (Contracts 9.1.)
static void test_gemm_dispatch_no_pack(void){

    oti_ctx tiny;
    int ka, kc, bad_direct = 0, bad_pack = 0;
    static const int direct_in[5] = {0, 1, 2, 3, 4};
    static const int pack_in[3] = {5, 6, 8};

    oti_ctx_init(&tiny);
    tiny.max_temp_bytes = 1;
    rng_seed(88);
    for (ka = 0; ka < 5; ka++){
        for (kc = 0; kc < 5; kc++){
            ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bc = {0}, vc = {0};
            int kb = direct_in[(ka + kc) % 5];
            make_mat(5, 6, direct_in[ka], &ba, &va);
            make_mat(6, 4, kb, &bb, &vb);
            make_mat(5, 4, direct_in[kc] == 4 ? 4 : direct_in[kc], &bc, &vc);
            fill_mat(&va, 0, 2.0);
            fill_mat(&vb, 0, 2.0);
            if (nd_gemm(&tiny, 0, 0, 1.0, &va, &vb, 0.0, &vc) != OTI_OK){
                bad_direct++;
                fprintf(stderr, "  gemm kinds %d %d %d needed a temporary\n", direct_in[ka], kb,
                        direct_in[kc]);
            }
            nd_release(&ba); nd_release(&bb); nd_release(&bc);
        }
    }
    check(bad_direct == 0,
            "gemm: C, F, padded and transposed operands / outputs need no temporary (1-byte budget OK)");
    for (ka = 0; ka < 3; ka++){
        ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bc = {0}, vc = {0};
        make_mat(5, 6, pack_in[ka], &ba, &va);
        make_mat(6, 4, 0, &bb, &vb);
        make_mat(5, 4, 0, &bc, &vc);
        fill_mat(&va, 0, 2.0);
        fill_mat(&vb, 0, 2.0);
        if (nd_gemm(&tiny, 0, 0, 1.0, &va, &vb, 0.0, &vc) != OTI_ERR_MEMORY){
            bad_pack++;
        }
        nd_release(&ba); nd_release(&bb); nd_release(&bc);
    }
    check(bad_pack == 0,
            "gemm: an A with negative or step-2 strides must be packed: 1-byte budget -> MEMORY");
    {
        ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bc = {0}, vc = {0};
        make_mat(5, 6, 0, &ba, &va);
        make_mat(6, 4, 0, &bb, &vb);
        make_mat(5, 4, 5, &bc, &vc);               // output with a negative row stride
        check(nd_gemm(&tiny, 0, 0, 1.0, &va, &vb, 0.0, &vc) == OTI_ERR_MEMORY,
              "gemm: an output that is neither 'N' nor 'T' usable needs an F temporary: MEMORY");
        nd_release(&ba); nd_release(&bb); nd_release(&bc);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Critic 9.1: the order-q blocks of an operand as one (n, m*N) F matrix are a transposed reshape (a view
// with strides (1, n)); 'N' uses it directly, so no pack is made, and the product is correct.
static void test_gemm_order_block_view(void){

    ndarr_t blocks = {0}, tr = {0}, mat = {0}, b = {0}, res = {0};
    int64_t N = 4, n = 6, m = 5, p = 3;
    int64_t sh[3], st[3];
    int64_t i, j, l;
    int32_t perm[3] = {1, 2, 0};
    int64_t msh[2];
    oti_ctx tiny;
    int ok = 1;
    int64_t bsh[2];
    double* bv;

    sh[0] = N; sh[1] = n; sh[2] = m;
    st[0] = n * m; st[1] = 1; st[2] = n;
    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &blocks);
    rng_seed(2468);
    for (i = 0; i < N * n * m; i++){
        ((double*)blocks.data)[i] = (rng_uniform() - 0.5) * 2.0;
    }
    check(nd_view_transpose(&blocks, 3, perm, &tr) == OTI_OK, "blocks: transpose (1,2,0)");
    msh[0] = n; msh[1] = m * N;
    check(nd_view_reshape(&tr, 2, msh, ND_LAYOUT_F, &mat) == OTI_OK && mat.strides[0] == 1 &&
            mat.strides[1] == n,
          "blocks: the (n, m*N) matrix is a view with strides (1, n)");
    bsh[0] = m * N; bsh[1] = p;
    bv = (double*)malloc(sizeof(double) * (size_t)(m * N * p));
    for (i = 0; i < m * N * p; i++){
        bv[i] = (rng_uniform() - 0.5) * 2.0;
    }
    make_from(2, bsh, ND_LAYOUT_C, bv, &b);
    oti_ctx_init(&tiny);
    tiny.max_temp_bytes = 1;
    check(nd_matmul(&tiny, &mat, &b, &res) == OTI_OK,
            "blocks: matmul of the block matrix needs no pack (1-byte temp budget)");
    for (i = 0; ok && i < n; i++){
        for (j = 0; j < p; j++){
            long double s = 0;
            for (l = 0; l < m * N; l++){
                s += (long double)mget(&mat, i, l) * (long double)bv[l * p + j];
            }
            ok = ok && fabs(get_f(&res, i * p + j) - (double)s) <= 1e-13;
        }
    }
    check(ok, "blocks: the product of the block matrix is correct");
    nd_release(&res);

    // a pair of blocks (each an F (n, m) matrix with strides (1, n)) multiplies with no temporary either
    {
        ndarr_t b0 = {0}, b1t = {0}, out = {0}, b1 = {0};
        nd_index_t ix[1];
        int64_t osh[2];
        int okb = 1;
        ix[0].kind = ND_IDX_INT; ix[0].has = 0; ix[0].stop = 0; ix[0].step = 0; ix[0].arr = NULL;
        ix[0].start = 0;
        nd_view_index(&blocks, 1, ix, &b0);
        ix[0].start = 1;
        nd_view_index(&blocks, 1, ix, &b1);
        nd_view_transpose(&b1, 0, NULL, &b1t);                   // (m, n) with strides (n, 1): C-like
        osh[0] = n; osh[1] = n;
        nd_alloc(NULL, OTI_F64, 2, osh, ND_LAYOUT_F, 0, &out);
        check(nd_gemm(&tiny, 0, 0, 1.0, &b0, &b1t, 0.0, &out) == OTI_OK,
              "gemm of two blocks (an F (n,m) times a (m,n) view): no temporary");
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                long double s = 0;
                for (l = 0; l < m; l++){
                    s += (long double)mget(&b0, i, l) * (long double)mget(&b1t, l, j);
                }
                okb = okb && fabs(mget(&out, i, j) - (double)s) <= 1e-13;
            }
        }
        check(okb, "gemm of two blocks: values");
        nd_release(&out);
    }
    nd_release(&b);
    free(bv);
    nd_release(&blocks);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// matmul / dot
// =======================================================================================================

static double g_mres[1 << 14];
static double g_mtol[1 << 14];

// *******************************************************************************************************
// numpy.matmul by definition. Returns 0 and fills g_mres / g_mtol / the result shape, or OTI_ERR_SHAPE.
static int ref_matmul(const ndarr_t* a, const ndarr_t* b, int* rnd, int64_t* rshape){

    int ra = a->ndim, rb = b->ndim, nbd, k, i, j, l;
    int64_t m, n, ka, kb, nb = 1, bl;
    int64_t bshape[OTI_ND_MAXDIM];
    int ba_nd, bb_nd;

    if (ra == 0 || rb == 0){
        return OTI_ERR_SHAPE;
    }
    m = ra >= 2 ? a->shape[ra - 2] : 1;
    ka = a->shape[ra - 1];
    kb = rb >= 2 ? b->shape[rb - 2] : b->shape[0];
    n = rb >= 2 ? b->shape[rb - 1] : 1;
    if (ka != kb){
        return OTI_ERR_SHAPE;
    }
    ba_nd = ra > 2 ? ra - 2 : 0;
    bb_nd = rb > 2 ? rb - 2 : 0;
    nbd = ba_nd > bb_nd ? ba_nd : bb_nd;
    for (k = 0; k < nbd; k++){
        int64_t ea = (k - (nbd - ba_nd) >= 0) ? a->shape[k - (nbd - ba_nd)] : 1;
        int64_t eb = (k - (nbd - bb_nd) >= 0) ? b->shape[k - (nbd - bb_nd)] : 1;
        if (ea != eb && ea != 1 && eb != 1){
            return OTI_ERR_SHAPE;
        }
        bshape[k] = (ea == 1) ? eb : ea;
        nb *= bshape[k];
    }
    *rnd = 0;
    for (k = 0; k < nbd; k++){
        rshape[(*rnd)++] = bshape[k];
    }
    if (ra >= 2){
        rshape[(*rnd)++] = m;
    }
    if (rb >= 2){
        rshape[(*rnd)++] = n;
    }
    for (bl = 0; bl < nb; bl++){
        int64_t abl = 0, bbl = 0, rem = bl;
        int64_t coord[OTI_ND_MAXDIM];
        for (k = nbd - 1; k >= 0; k--){
            coord[k] = rem % bshape[k];
            rem /= bshape[k];
        }
        for (k = 0; k < ba_nd; k++){
            int64_t ext = a->shape[k];
            abl = abl * ext + (ext == 1 ? 0 : coord[nbd - ba_nd + k]);
        }
        for (k = 0; k < bb_nd; k++){
            int64_t ext = b->shape[k];
            bbl = bbl * ext + (ext == 1 ? 0 : coord[nbd - bb_nd + k]);
        }
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                long double s = 0, sa = 0;
                for (l = 0; l < ka; l++){
                    int64_t la = ra >= 2 ? (abl * m + i) * ka + l : l;
                    int64_t lb = rb >= 2 ? (bbl * kb + l) * n + j : l;
                    long double p = (long double)get_f(a, la) * (long double)get_f(b, lb);
                    s += p;
                    sa += fabsl(p);
                }
                g_mres[(bl * m + i) * n + j] = (double)s;
                g_mtol[(bl * m + i) * n + j] = 4.0 * (double)(ka + 2) * DBL_EPSILON * (double)sa + 1e-300;
            }
        }
    }
    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int result_matches(const ndarr_t* r, int rnd, const int64_t* rshape){

    int64_t i, n = shape_size(rnd, rshape);
    int k;

    if (r->ndim != rnd || r->dtype != OTI_F64){
        return 0;
    }
    for (k = 0; k < rnd; k++){
        if (r->shape[k] != rshape[k]){
            return 0;
        }
    }
    for (i = 0; i < n; i++){
        double got = get_f(r, i);
        if (!(fabs(got - g_mres[i]) <= g_mtol[i])){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul_random(void){

    int iter, fails = 0, fails_to = 0, fails_err = 0, fails_c = 0;

    rng_seed(3141);
    for (iter = 0; iter < 1500; iter++){

        int ra = 1 + (int)rng_int(4), rb = 1 + (int)rng_int(4);
        int64_t sa[4], sb[4];
        int64_t m = rng_int(5), n = rng_int(5), k = rng_int(6);
        int nba = ra > 2 ? ra - 2 : 0, nbb = rb > 2 ? rb - 2 : 0;
        int nbd = nba > nbb ? nba : nbb;
        int64_t bsh[2];
        int i;
        ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, res = {0};
        int rnd = 0;
        int64_t rshape[OTI_ND_MAXDIM];
        int expect, st;
        int mismatch = (rng_int(12) == 0);

        for (i = 0; i < nbd; i++){
            bsh[0] = 1 + rng_int(3);
            bsh[1] = (rng_int(3) == 0) ? 1 : bsh[0];
            if (ra > 2 && i >= nbd - (ra - 2)){
                sa[i - (nbd - (ra - 2))] = bsh[0];
            }
            if (rb > 2 && i >= nbd - (rb - 2)){
                sb[i - (nbd - (rb - 2))] = bsh[1];
            }
        }
        if (ra >= 2){ sa[ra - 2] = m; }
        sa[ra - 1] = k;
        if (rb >= 2){
            sb[rb - 2] = mismatch ? k + 1 : k;
            sb[rb - 1] = n;
        } else {
            sb[0] = mismatch ? k + 1 : k;
        }
        if (shape_size(ra, sa) > 3000 || shape_size(rb, sb) > 3000){
            continue;
        }
        make_view(ra, sa, (int)rng_int(3), OTI_F64, &ba, &va);
        make_view(rb, sb, (int)rng_int(3), OTI_F64, &bb, &vb);
        fill_random_small(&va);
        fill_random_small(&vb);
        expect = ref_matmul(&va, &vb, &rnd, rshape);
        st = nd_matmul(NULL, &va, &vb, &res);
        if (expect != 0){
            if (st != expect || res.buf != NULL){
                fails_err++;
            }
        } else if (st != OTI_OK || !result_matches(&res, rnd, rshape) ||
                   (shape_size(rnd, rshape) > 1 && rnd > 0 && !(res.flags & ND_C_CONTIG))){
            fails++;
            if (fails < 4){
                fprintf(stderr, "  matmul iter %d: ra %d rb %d st %d\n", iter, ra, rb, st);
            }
            if (st == OTI_OK && !(res.flags & ND_C_CONTIG)){
                fails_c++;
            }
        }
        if (res.buf != NULL){
            nd_release(&res);
        }
        if (expect == 0){
            ndarr_t bo = {0}, vo = {0};
            make_view(rnd, rshape, (int)rng_int(3), OTI_F64, &bo, &vo);
            st = nd_matmul_to(NULL, &va, &vb, &vo);
            if (st != OTI_OK || !result_matches(&vo, rnd, rshape)){
                fails_to++;
            }
            nd_release(&bo);
        }
        nd_release(&ba);
        nd_release(&bb);
    }
    check(fails == 0,
            "nd_matmul: 1500 random ranks 1..4, batch broadcast, 1-D promotion, layouts");
    check(fails_c == 0, "nd_matmul: results are C-contiguous");
    check(fails_err == 0, "nd_matmul: inner-dimension and batch mismatches -> SHAPE, res empty");
    check(fails_to == 0, "nd_matmul_to into random output views");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul_hand_and_errors(void){

    ndarr_t a = {0}, b = {0}, r = {0}, s0 = {0};
    double av[6] = {1, 2, 3, 4, 5, 6};
    double bv[3] = {1, 0, -1};
    int64_t sa[2] = {2, 3}, sb[1] = {3}, s1[1] = {2};
    double one = 2.0;

    make_from(2, sa, ND_LAYOUT_C, av, &a);
    make_from(1, sb, ND_LAYOUT_C, bv, &b);
    check(nd_matmul(NULL, &a, &b, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 2 && get_f(&r, 0) == -2 &&
          get_f(&r, 1) == -2, "matmul (2,3) @ (3,) = [-2, -2]");
    nd_release(&r);
    {
        double w[2] = {1, 1};
        ndarr_t wv = {0};
        make_from(1, s1, ND_LAYOUT_C, w, &wv);
        check(nd_matmul(NULL, &wv, &a, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 3 && get_f(&r,
                0) == 5 &&
              get_f(&r, 2) == 9, "matmul (2,) @ (2,3) = [5, 7, 9]");
        nd_release(&r);
        check(nd_matmul(NULL, &wv, &wv, &r) == OTI_OK && r.ndim == 0 && get_f(&r, 0) == 2.0,
                "matmul (2,) @ (2,) is a rank-0 2.0");
        nd_release(&r);
        nd_release(&wv);
    }
    make_from(0, NULL, ND_LAYOUT_C, &one, &s0);
    check(nd_matmul(NULL, &s0, &a, &r) == OTI_ERR_SHAPE && r.buf == NULL,
            "matmul of a rank-0 operand -> SHAPE");
    check(nd_matmul(NULL, &a, &s0, &r) == OTI_ERR_SHAPE, "matmul with a rank-0 right operand -> SHAPE");
    check(nd_matmul(NULL, &a, &a, &r) == OTI_ERR_SHAPE, "matmul (2,3) @ (2,3) -> SHAPE");
    {
        ndarr_t u = {0};
        nd_alloc(NULL, OTI_U8, 1, sb, ND_LAYOUT_C, 0, &u);
        check(nd_matmul(NULL, &a, &u, &r) == OTI_ERR_DTYPE, "matmul with a U8 operand -> DTYPE");
        nd_release(&u);
    }
    // empty
    {
        ndarr_t e = {0}, f = {0};
        int64_t se[2] = {0, 3}, sf[2] = {3, 0}, sg[2] = {2, 0};
        nd_alloc(NULL, OTI_F64, 2, se, ND_LAYOUT_C, 0, &e);
        nd_alloc(NULL, OTI_F64, 2, sf, ND_LAYOUT_C, 0, &f);
        check(nd_matmul(NULL, &e, &b, &r) == OTI_OK && r.shape[0] == 0, "(0,3) @ (3,): an empty (0,)");
        nd_release(&r);
        check(nd_matmul(NULL, &e, &f, &r) == OTI_OK && r.shape[0] == 0 && r.shape[1] == 0,
                "(0,3) @ (3,0): (0,0)");
        nd_release(&r);
        {
            ndarr_t k0a = {0}, k0b = {0};
            nd_alloc(NULL, OTI_F64, 2, sg, ND_LAYOUT_C, 0, &k0a);          // (2,0)
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){0, 4}, ND_LAYOUT_C, 0, &k0b);
            check(nd_matmul(NULL, &k0a, &k0b, &r) == OTI_OK && r.shape[0] == 2 && r.shape[1] == 4 &&
                  get_f(&r, 0) == 0.0 && get_f(&r, 7) == 0.0, "(2,0) @ (0,4): zeros (2,4)");
            nd_release(&r);
            nd_release(&k0a); nd_release(&k0b);
        }
        nd_release(&e); nd_release(&f);
    }
    // matmul_to: shape, read-only, overlap with a temporary
    {
        ndarr_t out = {0}, bad = {0};
        int64_t so[1] = {2}, sbad[1] = {3};
        nd_alloc(NULL, OTI_F64, 1, so, ND_LAYOUT_C, 0, &out);
        nd_alloc(NULL, OTI_F64, 1, sbad, ND_LAYOUT_C, 0, &bad);
        check(nd_matmul_to(NULL, &a, &b, &out) == OTI_OK && get_f(&out, 0) == -2, "matmul_to (2,)");
        check(nd_matmul_to(NULL, &a, &b, &bad) == OTI_ERR_SHAPE,
                "matmul_to into the wrong shape -> SHAPE");
        {
            ndarr_t d = {0}, ro = {0}, ov = {0};
            make_desc(&d, out.data, OTI_F64, 1, so, (int64_t[]){1}, 0);
            nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
            check(nd_matmul_to(NULL, &a, &b, &ro) == OTI_ERR_READONLY,
                    "matmul_to into read-only -> READONLY");
            nd_release(&ro);
            make_desc(&d, out.data, OTI_F64, 1, so, (int64_t[]){0}, ND_WRITEABLE);
            nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
            check(nd_matmul_to(NULL, &a, &b, &ov) == OTI_ERR_LAYOUT, "matmul_to into stride 0 -> LAYOUT");
            nd_release(&ov);
        }
        nd_release(&out);
        nd_release(&bad);
    }
    nd_release(&a);
    nd_release(&b);
    nd_release(&s0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// S14: nd_matmul_to / nd_dot_to with an overlapping out compute through a temporary: numpy.matmul(a, b,
// out=a) semantics.
static void test_matmul_overlap(void){

    int64_t sh[2] = {4, 4};
    double av[16], bv[16];
    ndarr_t a = {0}, b = {0}, ref = {0}, rev = {0}, t = {0};
    int i, j, l, ok;
    oti_ctx tiny, ctx;
    nd_index_t ix[2];
    double want[16];

    rng_seed(1414);
    for (i = 0; i < 16; i++){
        av[i] = (rng_uniform() - 0.5) * 2.0;
        bv[i] = (rng_uniform() - 0.5) * 2.0;
    }
    make_from(2, sh, ND_LAYOUT_C, av, &a);
    make_from(2, sh, ND_LAYOUT_C, bv, &b);
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            long double s = 0;
            for (l = 0; l < 4; l++){
                s += (long double)av[i * 4 + l] * (long double)bv[l * 4 + j];
            }
            want[i * 4 + j] = (double)s;
        }
    }
    oti_ctx_init(&ctx);
    check(nd_matmul_to(&ctx, &a, &b, &a) == OTI_OK, "matmul(a, b, out=a): OK");
    ok = 1;
    for (i = 0; i < 16; i++){
        ok = ok && fabs(get_f(&a, i) - want[i]) <= 1e-13;
    }
    check(ok, "matmul(a, b, out=a): the product of the ORIGINAL a and b");
    nd_release(&a);

    make_from(2, sh, ND_LAYOUT_C, av, &a);
    check(nd_matmul_to(&ctx, &a, &b, &b) == OTI_OK, "matmul(a, b, out=b): OK");
    ok = 1;
    for (i = 0; i < 16; i++){
        ok = ok && fabs(get_f(&b, i) - want[i]) <= 1e-13;
    }
    check(ok, "matmul(a, b, out=b): the product of the original operands");
    nd_release(&b);
    make_from(2, sh, ND_LAYOUT_C, bv, &b);

    // a partially overlapping out: the reversed rows of a
    ix[0] = mk_slice(HT, 0, 0, -1);
    ix[1] = mk_slice(0, 0, 0, 0);
    nd_view_index(&a, 2, ix, &rev);
    check(nd_matmul_to(&ctx, &a, &b, &rev) == OTI_OK, "matmul(a, b, out=a[::-1]): OK");
    ok = 1;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            ok = ok && fabs(mget(&rev, i, j) - want[i * 4 + j]) <= 1e-13;
        }
    }
    check(ok, "matmul(a, b, out=a[::-1]): the product of the original a, stored reversed");
    nd_release(&a);

    // the temporary is charged to the temp budget and fails with MEMORY
    make_from(2, sh, ND_LAYOUT_C, av, &a);
    oti_ctx_init(&tiny);
    tiny.max_temp_bytes = 1;
    check(nd_matmul_to(&tiny, &a, &b, &a) == OTI_ERR_MEMORY,
            "overlapping out with a 1-byte temporary budget -> MEMORY");
    nd_test_fail_alloc(1);
    {
        int st = nd_matmul_to(&ctx, &a, &b, &a);
        nd_test_fail_alloc(0);
        check(st == OTI_ERR_MEMORY, "overlapping out with an injected allocation failure -> MEMORY");
    }
    // nd_dot_to with the same overlap
    nd_release(&a);
    make_from(2, sh, ND_LAYOUT_C, av, &a);
    check(nd_dot_to(&ctx, &a, &b, &a) == OTI_OK, "dot(a, b, out=a): OK");
    ok = 1;
    for (i = 0; i < 16; i++){
        ok = ok && fabs(get_f(&a, i) - want[i]) <= 1e-13;
    }
    check(ok, "dot(a, b, out=a): the product of the original operands");
    (void)ref; (void)t;
    nd_release(&a);
    nd_release(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_dot(void){

    ndarr_t x = {0}, y = {0}, a = {0}, b = {0}, r = {0}, sc = {0}, c3 = {0};
    double xv[3] = {1, 2, 3}, yv[3] = {4, -5, 6};
    double av[6] = {1, 2, 3, 4, 5, 6};
    double bv[6] = {1, 0, 0, 1, 1, 1};
    int64_t s3[1] = {3}, s23[2] = {2, 3}, s32[2] = {3, 2}, s2[1] = {2};
    double two = 2.0;
    int i;

    make_from(1, s3, ND_LAYOUT_C, xv, &x);
    make_from(1, s3, ND_LAYOUT_C, yv, &y);
    make_from(2, s23, ND_LAYOUT_C, av, &a);
    make_from(2, s32, ND_LAYOUT_C, bv, &b);
    make_from(0, NULL, ND_LAYOUT_C, &two, &sc);

    check(nd_dot(NULL, &x, &y, &r) == OTI_OK && r.ndim == 0 && get_f(&r, 0) == 12.0,
            "dot (3,).(3,) = 12, rank 0");
    nd_release(&r);
    check(nd_dot(NULL, &a, &x, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 2 && get_f(&r, 0) == 14 &&
          get_f(&r, 1) == 32, "dot (2,3).(3,) = [14, 32]");
    nd_release(&r);
    {
        double w[2] = {1, 2};
        ndarr_t wv = {0};
        make_from(1, s2, ND_LAYOUT_C, w, &wv);
        check(nd_dot(NULL, &wv, &a, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 3 && get_f(&r,
                0) == 9 &&
              get_f(&r, 2) == 15, "dot (2,).(2,3) = [9, 12, 15]");
        nd_release(&r);
        nd_release(&wv);
    }
    check(nd_dot(NULL, &a, &b, &r) == OTI_OK && r.ndim == 2 && r.shape[0] == 2 && r.shape[1] == 2 &&
          get_f(&r, 0) == 4 && get_f(&r, 1) == 5 && get_f(&r, 2) == 10 && get_f(&r, 3) == 11,
          "dot (2,3).(3,2) = [[4,5],[10,11]]");
    nd_release(&r);
    check(nd_dot(NULL, &sc, &a, &r) == OTI_OK && r.ndim == 2 && get_f(&r, 5) == 12.0,
            "dot of a rank-0 and a matrix: the scalar product");
    nd_release(&r);
    check(nd_dot(NULL, &a, &sc, &r) == OTI_OK && r.ndim == 2 && get_f(&r, 0) == 2.0,
            "dot of a matrix and a rank-0");
    nd_release(&r);
    check(nd_dot(NULL, &sc, &sc, &r) == OTI_OK && r.ndim == 0 && get_f(&r, 0) == 4.0,
            "dot of two rank-0 arrays");
    nd_release(&r);
    nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, 2, 2}, ND_LAYOUT_C, 0, &c3);
    check(nd_dot(NULL, &c3, &a, &r) == OTI_ERR_SHAPE && r.buf == NULL,
            "dot with a 3-D operand -> SHAPE (tensordot is later)");
    check(nd_dot(NULL, &a, &c3, &r) == OTI_ERR_SHAPE, "dot with a 3-D right operand -> SHAPE");
    check(nd_dot(NULL, &a, &a, &r) == OTI_ERR_SHAPE, "dot (2,3).(2,3) -> SHAPE");
    check(nd_dot(NULL, &x, &a, &r) == OTI_ERR_SHAPE, "dot (3,).(2,3) -> SHAPE");
    {
        ndarr_t u = {0};
        nd_alloc(NULL, OTI_U8, 1, s3, ND_LAYOUT_C, 0, &u);
        check(nd_dot(NULL, &x, &u, &r) == OTI_ERR_DTYPE, "dot with U8 -> DTYPE");
        nd_release(&u);
    }
    // dot_to: rank-0 out for 1-D . 1-D
    {
        ndarr_t o0 = {0}, o1 = {0};
        nd_alloc(NULL, OTI_F64, 0, NULL, ND_LAYOUT_C, 0, &o0);
        nd_alloc(NULL, OTI_F64, 1, s3, ND_LAYOUT_C, 0, &o1);
        check(nd_dot_to(NULL, &x, &y, &o0) == OTI_OK && get_f(&o0, 0) == 12.0,
                "dot_to into a rank-0 out");
        check(nd_dot_to(NULL, &x, &y, &o1) == OTI_ERR_SHAPE,
                "dot_to of 1-D.1-D into a (3,) out -> SHAPE");
        nd_release(&o0);
        nd_release(&o1);
    }
    for (i = 0; i < 1; i++){
        (void)i;
    }
    nd_release(&x); nd_release(&y); nd_release(&a); nd_release(&b); nd_release(&sc); nd_release(&c3);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 9.2 Level 1 and 2
// =======================================================================================================

// *******************************************************************************************************
// kind: 0 contiguous, 1 stride 2, 2 reversed, 3 broadcast (stride 0; inputs only), 4 reversed stride 2.
static void make_vec(int64_t n, int kind, ndarr_t* base, ndarr_t* view){

    int64_t bs[1];
    nd_index_t ix[1];

    nd_init_empty(base);
    nd_init_empty(view);
    if (kind == 3){
        bs[0] = 1;
        nd_alloc(NULL, OTI_F64, 1, bs, ND_LAYOUT_C, 0, base);
        nd_view_broadcast_to(base, 1, &n, view);
        return;
    }
    bs[0] = (kind == 1 || kind == 4) ? 2 * n : n;
    nd_alloc(NULL, OTI_F64, 1, bs, ND_LAYOUT_C, 0, base);
    if (kind == 0){
        *view = *base;
        view->flags &= ~ND_RETAINED;
        return;
    }
    if (kind == 1){
        ix[0] = mk_slice(HT, 0, 0, 2);
    } else if (kind == 2){
        ix[0] = mk_slice(HT, n > 0 ? n - 1 : 0, 0, -1);
    } else {
        ix[0] = mk_slice(HT, n > 0 ? 2 * n - 1 : 0, 0, -2);
    }
    nd_view_index(base, 1, ix, view);
    view->shape[0] = n;
    nd_update_flags(view);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fill_vec(ndarr_t* v, int kind){

    int64_t n = v->shape[0], i;

    if (kind == 3){
        if (n > 0){
            *(double*)v->data = (rng_uniform() - 0.5) * 2.0;
        }
        return;
    }
    for (i = 0; i < n; i++){
        ((double*)v->data)[i * v->strides[0]] = (rng_uniform() - 0.5) * 2.0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double vget(const ndarr_t* v, int64_t i){

    return ((double*)v->data)[i * v->strides[0]];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_level1_random(void){

    int iter, f_dot = 0, f_axpy = 0, f_scal = 0, f_nrm = 0, f_asum = 0, f_iamax = 0, f_guard = 0;

    rng_seed(1066);
    for (iter = 0; iter < 2000; iter++){
        int64_t n = (rng_int(10) == 0) ? 0 : (rng_int(6) == 0 ? 1 : 2 + rng_int(40));
        int kx = (int)rng_int(5), ky = (int)rng_int(5), kw = (int)rng_int(5);
        ndarr_t bx = {0}, vx = {0}, by = {0}, vy = {0}, bw = {0}, vw = {0};
        double alpha = (rng_uniform() - 0.5) * 3.0, res;
        long double s = 0, sa = 0, sq = 0, as = 0;
        int64_t i, imax = -1, got_i;
        double mx = -1.0;
        double y0[64], x0[64];

        if (ky == 3){ ky = 0; }
        if (kw == 3){ kw = 2; }
        make_vec(n, kx, &bx, &vx);
        make_vec(n, ky, &by, &vy);
        make_vec(n, kw, &bw, &vw);
        fill_vec(&vx, kx);
        fill_vec(&vy, ky);
        fill_vec(&vw, kw);
        for (i = 0; i < n; i++){
            double xv = vget(&vx, i), yv = vget(&vy, i);
            s += (long double)xv * (long double)yv;
            sa += fabsl((long double)xv * (long double)yv);
            sq += (long double)xv * (long double)xv;
            as += fabsl((long double)xv);
            if (fabs(xv) > mx){
                mx = fabs(xv);
                imax = i;
            }
            x0[i] = xv;
            y0[i] = yv;
        }
        // vdot
        if (nd_vdot(NULL, &vx, &vy, &res) != OTI_OK ||
            !(fabs(res - (double)s) <= 4.0 * (double)(n + 2) * DBL_EPSILON * (double)sa + 1e-300)){
            f_dot++;
        }
        // nrm2, asum, iamax on x
        if (nd_nrm2(NULL, &vx, &res) != OTI_OK ||
            !(fabs(res - (double)sqrtl(sq)) <=
              8.0 * (double)(n + 2) * DBL_EPSILON * (double)sqrtl(sq) + 1e-300)){
            f_nrm++;
        }
        if (nd_asum(NULL, &vx, &res) != OTI_OK ||
            !(fabs(res - (double)as) <= 4.0 * (double)(n + 2) * DBL_EPSILON * (double)as + 1e-300)){
            f_asum++;
        }
        if (nd_iamax(NULL, &vx, &got_i) != OTI_OK || got_i != imax){
            f_iamax++;
        }
        // axpy into y (x and y never overlap: distinct allocations)
        canary_base(&by);
        for (i = 0; i < n; i++){
            ((double*)vy.data)[i * vy.strides[0]] = y0[i];
        }
        if (nd_axpy(NULL, alpha, &vx, &vy) != OTI_OK){
            f_axpy++;
        } else {
            for (i = 0; i < n; i++){
                double want = alpha * x0[i] + y0[i];
                if (!(fabs(vget(&vy,
                        i) - want) <= 4.0 * DBL_EPSILON * (fabs(alpha * x0[i]) + fabs(y0[i])) + 1e-300)){
                    f_axpy++;
                    break;
                }
            }
            if (!canary_ok(&by, &vy)){
                f_guard++;
            }
        }
        // scal on w
        {
            double w0[64];
            for (i = 0; i < n; i++){
                w0[i] = vget(&vw, i);
            }
            canary_base(&bw);
            for (i = 0; i < n; i++){
                ((double*)vw.data)[i * vw.strides[0]] = w0[i];
            }
            if (nd_scal(NULL, alpha, &vw) != OTI_OK){
                f_scal++;
            } else {
                for (i = 0; i < n; i++){
                    if (!same_bits(vget(&vw, i), alpha * w0[i])){
                        f_scal++;
                        break;
                    }
                }
                if (!canary_ok(&bw, &vw)){
                    f_guard++;
                }
            }
        }
        nd_release(&bx); nd_release(&by); nd_release(&bw);
    }
    check(f_dot == 0,
            "nd_vdot: 2000 random lengths and strides (positive, negative, 0, doubled) vs long double");
    check(f_nrm == 0, "nd_nrm2 vs sqrt of the long double sum of squares");
    check(f_asum == 0, "nd_asum vs the long double sum of |x|");
    check(f_iamax == 0, "nd_iamax: the first index of the largest |x| (0-based), -1 for an empty vector");
    check(f_axpy == 0, "nd_axpy: y = alpha x + y for every stride combination");
    check(f_scal == 0, "nd_scal: bitwise alpha * x for every stride");
    check(f_guard == 0, "level 1: only the vector view is written (canaries)");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_level1_specials_and_errors(void){

    ndarr_t x = {0}, y = {0}, a2 = {0}, u = {0}, ro = {0}, ov = {0};
    double xv[4] = {1e200, 1e200, 0, 0};
    double tv[2] = {1e-200, 1e-200};
    int64_t s4[1] = {4}, s2[1] = {2}, s3[1] = {3}, s33[2] = {2, 2};
    double r;
    int64_t idx;

    make_from(1, s4, ND_LAYOUT_C, xv, &x);
    check(nd_nrm2(NULL, &x, &r) == OTI_OK && fabs(r - 1.4142135623730951e200) <= 1e185,
            "nrm2 of (1e200, 1e200): no overflow");
    nd_release(&x);
    make_from(1, s2, ND_LAYOUT_C, tv, &x);
    check(nd_nrm2(NULL, &x, &r) == OTI_OK && fabs(r - 1.4142135623730951e-200) <= 1e-215,
            "nrm2 of (1e-200, 1e-200): no underflow");
    nd_release(&x);
    {
        double e[1] = {0};
        int64_t s0[1] = {0};
        ndarr_t z = {0}, z1 = {0};
        nd_alloc(NULL, OTI_F64, 1, s0, ND_LAYOUT_C, 0, &z);
        check(nd_vdot(NULL, &z, &z, &r) == OTI_OK && r == 0.0, "vdot of empty vectors is 0.0");
        check(nd_nrm2(NULL, &z, &r) == OTI_OK && r == 0.0, "nrm2 of an empty vector is 0.0");
        check(nd_asum(NULL, &z, &r) == OTI_OK && r == 0.0, "asum of an empty vector is 0.0");
        check(nd_iamax(NULL, &z, &idx) == OTI_OK && idx == -1, "iamax of an empty vector is -1");
        nd_release(&z);
        e[0] = 3.0;
        make_from(1, (int64_t[]){1}, ND_LAYOUT_C, e, &z1);
        z1.strides[0] = 12345;
        check(nd_nrm2(NULL, &z1, &r) == OTI_OK && r == 3.0, "n = 1: any stride is fine");
        nd_release(&z1);
    }
    // hand values and tie-breaking of iamax
    {
        double v[5] = {1, -7, 3, 7, -2};
        ndarr_t t = {0};
        make_from(1, (int64_t[]){5}, ND_LAYOUT_C, v, &t);
        check(nd_iamax(NULL, &t, &idx) == OTI_OK && idx == 1,
                "iamax of (1,-7,3,7,-2): the first of the ties (1)");
        check(nd_asum(NULL, &t, &r) == OTI_OK && r == 20.0, "asum = 20");
        check(nd_nrm2(NULL, &t, &r) == OTI_OK && fabs(r - sqrt(112.0)) <= 1e-14, "nrm2 = sqrt(112)");
        nd_release(&t);
    }

    // errors
    make_from(1, s3, ND_LAYOUT_C, (double[]){1, 2, 3}, &x);
    make_from(1, s3, ND_LAYOUT_C, (double[]){4, 5, 6}, &y);
    make_from(2, s33, ND_LAYOUT_C, (double[]){1, 2, 3, 4}, &a2);
    nd_alloc(NULL, OTI_U8, 1, s3, ND_LAYOUT_C, 0, &u);
    check(nd_vdot(NULL, &x, &y, &r) == OTI_OK && r == 32.0, "vdot((1,2,3),(4,5,6)) = 32");
    check(nd_vdot(NULL, &x, &a2, &r) == OTI_ERR_SHAPE, "vdot with a 2-D operand -> SHAPE");
    {
        ndarr_t sh2 = {0};
        nd_alloc(NULL, OTI_F64, 1, s2, ND_LAYOUT_C, 0, &sh2);
        check(nd_vdot(NULL, &x, &sh2, &r) == OTI_ERR_SHAPE, "vdot with a length mismatch -> SHAPE");
        check(nd_axpy(NULL, 1.0, &x, &sh2) == OTI_ERR_SHAPE, "axpy with a length mismatch -> SHAPE");
        nd_release(&sh2);
    }
    check(nd_vdot(NULL, &x, &u, &r) == OTI_ERR_DTYPE, "vdot with U8 -> DTYPE");
    check(nd_nrm2(NULL, &u, &r) == OTI_ERR_DTYPE, "nrm2 of U8 -> DTYPE");
    check(nd_asum(NULL, &a2, &r) == OTI_ERR_SHAPE, "asum of a 2-D array -> SHAPE");
    check(nd_iamax(NULL, &a2, &idx) == OTI_ERR_SHAPE, "iamax of a 2-D array -> SHAPE");
    check(nd_scal(NULL, 2.0, &a2) == OTI_ERR_SHAPE, "scal of a 2-D array -> SHAPE");
    check(nd_axpy(NULL, 1.0, &x, &u) == OTI_ERR_DTYPE, "axpy into U8 -> DTYPE");
    {
        ndarr_t d = {0};
        make_desc(&d, y.data, OTI_F64, 1, s3, (int64_t[]){1}, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        check(nd_axpy(NULL, 1.0, &x, &ro) == OTI_ERR_READONLY, "axpy into read-only y -> READONLY");
        check(nd_scal(NULL, 2.0, &ro) == OTI_ERR_READONLY, "scal of read-only x -> READONLY");
        nd_release(&ro);
        make_desc(&d, y.data, OTI_F64, 1, s3, (int64_t[]){0}, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
        check(nd_axpy(NULL, 1.0, &x, &ov) == OTI_ERR_LAYOUT, "axpy into y with stride 0 -> LAYOUT");
        check(nd_scal(NULL, 2.0, &ov) == OTI_ERR_LAYOUT, "scal of x with stride 0 -> LAYOUT");
        nd_release(&ov);
    }
    // an output overlapping an input
    {
        ndarr_t big = {0}, v1 = {0}, v2 = {0};
        int64_t sb[1] = {6};
        nd_index_t ix[1];
        double bv[6] = {1, 2, 3, 4, 5, 6};
        make_from(1, sb, ND_LAYOUT_C, bv, &big);
        check(nd_axpy(NULL, 1.0, &big, &big) == OTI_ERR_LAYOUT, "axpy with y = x -> LAYOUT");
        ix[0] = mk_slice(HP, 0, 4, 0);
        nd_view_index(&big, 1, ix, &v1);
        ix[0] = mk_slice(HS, 2, 0, 0);
        nd_view_index(&big, 1, ix, &v2);
        check(nd_axpy(NULL, 1.0, &v1, &v2) == OTI_ERR_LAYOUT,
                "axpy with partially overlapping x and y -> LAYOUT");
        nd_release(&big);
    }
    nd_release(&x); nd_release(&y); nd_release(&a2); nd_release(&u);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_gemv_ger_random(void){

    int iter, f_gemv = 0, f_ger = 0, f_nan = 0, f_guard = 0;

    rng_seed(1215);
    for (iter = 0; iter < 2500; iter++){
        int64_t m = (rng_int(10) == 0) ? 0 : 1 + rng_int(9), n = (rng_int(10) == 0) ? 0 : 1 + rng_int(9);
        int trans = (int)rng_int(2), ka = (int)rng_int(KINDS_ALL), kx = (int)rng_int(5),
                ky = (int)rng_int(5);
        int64_t lx = trans ? m : n, ly = trans ? n : m, i, j;
        double alpha = (rng_uniform() - 0.5) * 3.0;
        double beta = rng_int(3) == 0 ? 0.0 : (rng_uniform() - 0.5) * 3.0;
        ndarr_t ba = {0}, va = {0}, bx = {0}, vx = {0}, by = {0}, vy = {0};
        double y0[16], want[16], tol[16];
        int nanc = 0;

        if (ky == 3){ ky = 0; }
        make_mat(m, n, ka, &ba, &va);
        make_vec(lx, kx, &bx, &vx);
        make_vec(ly, ky, &by, &vy);
        fill_mat(&va, ka, 2.0);
        fill_vec(&vx, kx);
        canary_base(&by);
        for (i = 0; i < ly; i++){
            double v = (rng_uniform() - 0.5) * 2.0;
            if (beta == 0.0 && rng_int(2) == 0){
                v = NAN;
                nanc = 1;
            }
            y0[i] = v;
            ((double*)vy.data)[i * vy.strides[0]] = v;
        }
        for (i = 0; i < ly; i++){
            long double s = 0, sa = 0;
            for (j = 0; j < lx; j++){
                double av = trans ? mget(&va, j, i) : mget(&va, i, j);
                s += (long double)av * (long double)vget(&vx, j);
                sa += fabsl((long double)av * (long double)vget(&vx, j));
            }
            s *= alpha;
            sa *= fabs(alpha);
            if (beta != 0.0){
                s += (long double)beta * y0[i];
                sa += fabsl((long double)beta * y0[i]);
            }
            want[i] = (double)s;
            tol[i] = 4.0 * (double)(lx + 2) * DBL_EPSILON * (double)sa + 1e-300;
        }
        if (nd_gemv(NULL, trans, alpha, &va, &vx, beta, &vy) != OTI_OK){
            f_gemv++;
        } else {
            int ok = 1;
            for (i = 0; i < ly; i++){
                if (!(fabs(vget(&vy, i) - want[i]) <= tol[i])){
                    ok = 0;
                }
            }
            if (!ok){
                f_gemv++;
                if (nanc){
                    f_nan++;
                }
            }
            if (!canary_ok(&by, &vy)){
                f_guard++;
            }
        }
        nd_release(&bx); nd_release(&by);

        // ger: a = alpha x y^T + a, a in a writeable layout
        {
            int kg = (int)rng_int(KINDS_OUT);
            ndarr_t bg = {0}, vg = {0}, bgx = {0}, vgx = {0}, bgy = {0}, vgy = {0};
            double a0[100], wantg[100];
            int okg = 1;
            make_mat(m, n, kg, &bg, &vg);
            make_vec(m, kx, &bgx, &vgx);
            make_vec(n, kx == 3 ? 0 : (int)rng_int(5) == 3 ? 1 : (int)rng_int(3), &bgy, &vgy);
            fill_vec(&vgx, kx);
            fill_vec(&vgy, 0);
            canary_base(&bg);
            for (i = 0; i < m; i++){
                for (j = 0; j < n; j++){
                    double v = (rng_uniform() - 0.5) * 2.0;
                    a0[i * n + j] = v;
                    ((double*)vg.data)[i * vg.strides[0] + j * vg.strides[1]] = v;
                }
            }
            for (i = 0; i < m; i++){
                for (j = 0; j < n; j++){
                    wantg[i * n + j] = a0[i * n + j] + alpha * vget(&vgx, i) * vget(&vgy, j);
                }
            }
            if (nd_ger(NULL, alpha, &vgx, &vgy, &vg) != OTI_OK){
                f_ger++;
            } else {
                for (i = 0; i < m; i++){
                    for (j = 0; j < n; j++){
                        double tolg = 8.0 * DBL_EPSILON * (fabs(a0[i * n + j]) + fabs(alpha * vget(&vgx,
                                i) * vget(&vgy, j))) +
                                      1e-300;
                        if (!(fabs(mget(&vg, i, j) - wantg[i * n + j]) <= tolg)){
                            okg = 0;
                        }
                    }
                }
                if (!okg){
                    f_ger++;
                }
                if (!canary_ok(&bg, &vg)){
                    f_guard++;
                }
            }
            nd_release(&bg); nd_release(&bgx); nd_release(&bgy);
        }
        nd_release(&ba);
    }
    check(f_gemv == 0,
            "nd_gemv: 2500 random shapes, trans, 9 layouts of A, vector strides (+, -, 0), alpha, beta");
    check(f_nan == 0, "nd_gemv: beta = 0 never reads y");
    check(f_ger == 0, "nd_ger: a += alpha x y^T in C, F, padded, transposed, reversed, step-2 layouts");
    check(f_guard == 0, "gemv / ger write exactly the y / a view (canaries)");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_gemv_ger_errors(void){

    ndarr_t a = {0}, x = {0}, y = {0}, big = {0}, row = {0}, u = {0};
    int64_t s33[2] = {3, 4}, s4[1] = {4}, s3[1] = {3}, s5[1] = {5};
    double z[12] = {0};
    nd_index_t ix[1];

    make_from(2, s33, ND_LAYOUT_C, z, &a);
    make_from(1, s4, ND_LAYOUT_C, z, &x);
    make_from(1, s3, ND_LAYOUT_C, z, &y);
    check(nd_gemv(NULL, 0, 1.0, &a, &x, 0.0, &y) == OTI_OK, "gemv (3,4) (4,) -> (3,)");
    check(nd_gemv(NULL, 1, 1.0, &a, &x, 0.0, &y) == OTI_ERR_SHAPE,
            "gemv trans with x of length 4 -> SHAPE");
    check(nd_gemv(NULL, 0, 1.0, &a, &y, 0.0, &y) == OTI_ERR_SHAPE, "gemv with x of length 3 -> SHAPE");
    {
        ndarr_t y5 = {0};
        nd_alloc(NULL, OTI_F64, 1, s5, ND_LAYOUT_C, 0, &y5);
        check(nd_gemv(NULL, 0, 1.0, &a, &x, 0.0, &y5) == OTI_ERR_SHAPE,
                "gemv with y of the wrong length -> SHAPE");
        nd_release(&y5);
    }
    check(nd_gemv(NULL, 0, 1.0, &x, &x, 0.0, &y) == OTI_ERR_SHAPE, "gemv with a 1-D A -> SHAPE");
    nd_alloc(NULL, OTI_U8, 1, s4, ND_LAYOUT_C, 0, &u);
    check(nd_gemv(NULL, 0, 1.0, &a, &u, 0.0, &y) == OTI_ERR_DTYPE, "gemv with a U8 x -> DTYPE");
    // y overlapping A or x -> LAYOUT
    make_from(1, (int64_t[]){12}, ND_LAYOUT_C, z, &big);
    {
        ndarr_t a2 = {0}, rv = {0};
        int64_t s34[2] = {3, 4};
        make_desc(&a2, big.data, OTI_F64, 2, s34, (int64_t[]){4, 1}, ND_WRITEABLE);
        nd_update_flags(&a2);
        ix[0] = mk_slice(HP, 0, 3, 0);
        nd_view_index(&big, 1, ix, &rv);
        check(nd_gemv(NULL, 0, 1.0, &a2, &x, 0.0, &rv) == OTI_ERR_LAYOUT,
                "gemv with y inside A's memory -> LAYOUT");
    }
    {
        ndarr_t sq = {0}, v = {0};
        int64_t s44[2] = {4, 4};
        make_from(2, s44, ND_LAYOUT_C, (double[16]){0}, &sq);
        make_from(1, s4, ND_LAYOUT_C, z, &v);
        check(nd_gemv(NULL, 0, 1.0, &sq, &v, 0.0, &v) == OTI_ERR_LAYOUT, "gemv with y = x -> LAYOUT");
        nd_release(&sq); nd_release(&v);
    }
    // ger: a overlapping x
    {
        ndarr_t g = {0}, gx = {0};
        int64_t s34[2] = {3, 4};
        make_from(2, s34, ND_LAYOUT_C, z, &g);
        ix[0].kind = ND_IDX_INT; ix[0].has = 0; ix[0].start = 0;
        ix[0].stop = 0; ix[0].step = 0; ix[0].arr = NULL;
        nd_view_index(&g, 1, ix, &gx);                   // the first row, length 4
        check(nd_ger(NULL, 1.0, &y, &x, &g) == OTI_OK, "ger (3,) (4,) into (3,4)");
        check(nd_ger(NULL, 1.0, &x, &y, &g) == OTI_ERR_SHAPE, "ger with swapped vector lengths -> SHAPE");
        check(nd_ger(NULL, 1.0, &y, &gx, &g) == OTI_ERR_LAYOUT, "ger with y inside a -> LAYOUT");
        {
            ndarr_t d = {0}, ro = {0};
            make_desc(&d, g.data, OTI_F64, 2, s34, g.strides, 0);
            nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
            check(nd_ger(NULL, 1.0, &y, &x, &ro) == OTI_ERR_READONLY,
                    "ger into a read-only a -> READONLY");
            nd_release(&ro);
        }
        nd_release(&g);
    }
    nd_release(&a); nd_release(&x); nd_release(&y); nd_release(&big); nd_release(&u);
    (void)row;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 1.4 allocation failures, sizes
// =======================================================================================================

// *******************************************************************************************************
static void test_blas_fail_alloc(void){

    ndarr_t ba = {0}, va = {0}, bb = {0}, vb = {0}, bc = {0}, vc = {0}, res = {0};
    int k, saw, finished, ok;
    double want[20];
    int64_t i, j, l;

    rng_seed(404);
    make_mat(4, 6, 5, &ba, &va);          // negative row stride: packed
    make_mat(6, 5, 6, &bb, &vb);          // step-2 columns: packed
    fill_mat(&va, 5, 2.0);
    fill_mat(&vb, 6, 2.0);
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            long double s = 0;
            for (l = 0; l < 6; l++){
                s += (long double)mget(&va, i, l) * (long double)mget(&vb, l, j);
            }
            want[i * 5 + j] = (double)s;
        }
    }
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 40 && !finished; k++){
        int st;
        nd_init_empty(&res);
        nd_test_fail_alloc(k);
        st = nd_matmul(NULL, &va, &vb, &res);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            for (i = 0; i < 20; i++){
                ok = ok && fabs(get_f(&res, i) - want[i]) <= 1e-12;
            }
            nd_release(&res);
            finished = 1;
        } else {
            saw++;
            ok = ok && st == OTI_ERR_MEMORY && res.buf == NULL && res.ndim == 1 && res.shape[0] == 0;
        }
    }
    check(saw >= 2 && finished,
            "nd_matmul with packs: several allocations (result, packs) each can fail, then success");
    check(ok,
            "nd_matmul fail_alloc: MEMORY and an empty res at every allocation; the result is right");

    // nd_gemm with a packed input and a temporary output
    make_mat(4, 5, 5, &bc, &vc);
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 40 && !finished; k++){
        int st;
        for (i = 0; i < 4; i++){
            for (j = 0; j < 5; j++){
                ((double*)vc.data)[i * vc.strides[0] + j * vc.strides[1]] = 1.0;
            }
        }
        nd_test_fail_alloc(k);
        st = nd_gemm(NULL, 0, 0, 1.0, &va, &vb, 1.0, &vc);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            for (i = 0; i < 4; i++){
                for (j = 0; j < 5; j++){
                    ok = ok && fabs(mget(&vc, i, j) - (want[i * 5 + j] + 1.0)) <= 1e-12;
                }
            }
            finished = 1;
        } else {
            saw++;
            ok = ok && st == OTI_ERR_MEMORY;
        }
    }
    check(saw >= 1 && finished && ok,
            "nd_gemm with packs and an F temporary for C: failures are MEMORY, then the right result");
    nd_release(&ba); nd_release(&bb); nd_release(&bc);

    // a batched matmul with one failing allocation at a time
    {
        ndarr_t x = {0}, y = {0}, bx = {0}, by = {0};
        int64_t sx[3] = {3, 4, 5}, sy[3] = {3, 5, 2};
        saw = 0; finished = 0;
        make_view(3, sx, 2, OTI_F64, &bx, &x);
        make_view(3, sy, 2, OTI_F64, &by, &y);
        fill_random_small(&x);
        fill_random_small(&y);
        for (k = 1; k < 60 && !finished; k++){
            int st;
            nd_init_empty(&res);
            nd_test_fail_alloc(k);
            st = nd_matmul(NULL, &x, &y, &res);
            nd_test_fail_alloc(0);
            if (st == OTI_OK){
                finished = 1;
                nd_release(&res);
            } else {
                saw++;
                if (st != OTI_ERR_MEMORY || res.buf != NULL){
                    saw = -1000;
                }
            }
        }
        check(saw >= 1 && finished,
                "batched nd_matmul: allocation failures are MEMORY with an empty res, then success");
        nd_release(&bx); nd_release(&by);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_blas_int_limit(void){

    int64_t saved = oti_lapack_int_limit();
    ndarr_t a = {0}, b = {0}, c = {0}, v = {0};
    int64_t sa[2] = {4, 2}, sb[2] = {2, 2}, sc[2] = {4, 2}, s4[1] = {4};
    double r;
    ndarr_t res = {0};

    nd_alloc(NULL, OTI_F64, 2, sa, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
    nd_alloc(NULL, OTI_F64, 2, sb, ND_LAYOUT_C, ND_ALLOC_ZERO, &b);
    nd_alloc(NULL, OTI_F64, 2, sc, ND_LAYOUT_C, ND_ALLOC_ZERO, &c);
    nd_alloc(NULL, OTI_F64, 1, s4, ND_LAYOUT_C, ND_ALLOC_ZERO, &v);
    oti_lapack_test_set_int_limit(3);
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &c) == OTI_ERR_SIZE,
            "gemm with m = 4 above a LAPACK int limit of 3 -> SIZE");
    check(nd_matmul(NULL, &a, &b, &res) == OTI_ERR_SIZE && res.buf == NULL,
            "matmul with m = 4 above the limit -> SIZE, res empty");
    check(nd_vdot(NULL, &v, &v, &r) == OTI_ERR_SIZE, "vdot of length 4 above the limit -> SIZE");
    check(nd_nrm2(NULL, &v, &r) == OTI_ERR_SIZE, "nrm2 of length 4 above the limit -> SIZE");
    oti_lapack_test_set_int_limit(saved);
    check(nd_gemm(NULL, 0, 0, 1.0, &a, &b, 0.0, &c) == OTI_OK, "the limit restored: the same gemm works");
    check(oti_lapack_int_limit() == saved, "oti_lapack_int_limit is restored");
    nd_release(&a); nd_release(&b); nd_release(&c); nd_release(&v);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// W2 fix 1, checker 2: the peak of the simultaneous packs is checked once against the temp budget.
static void test_fix1_blas_peak(void){

    int64_t n = 100;
    ndarr_t b1 = {0}, b2 = {0}, x = {0}, y = {0};
    double r = 0.0;
    oti_ctx c;

    // two length-100 zero-stride read-only vectors: both are packed (800 bytes each, 1600 live together)
    make_from(1, (int64_t[]){1}, ND_LAYOUT_C, (double[]){2.0}, &b1);
    make_from(1, (int64_t[]){1}, ND_LAYOUT_C, (double[]){3.0}, &b2);
    nd_view_broadcast_to(&b1, 1, &n, &x);
    nd_view_broadcast_to(&b2, 1, &n, &y);
    oti_ctx_init(&c);
    c.max_temp_bytes = 800;
    check(nd_vdot(&c, &x, &y, &r) == OTI_ERR_MEMORY,
          "fix1.2: vdot packs two 800-byte vectors at once: an 800-byte budget -> MEMORY");
    c.max_temp_bytes = 1599;
    check(nd_vdot(&c, &x, &y, &r) == OTI_ERR_MEMORY, "fix1.2: a 1599-byte budget is still too small");
    c.max_temp_bytes = 1600;
    r = 0.0;
    check(nd_vdot(&c, &x, &y, &r) == OTI_OK && fabs(r - 600.0) <= 1e-12,
            "fix1.2: 1600 bytes suffice: dot = 600");
    nd_release(&b1);
    nd_release(&b2);

    // gemv with a negative-stride A (800-byte pack), x (80) and y (80) packs: 960 bytes at once
    {
        ndarr_t ba = {0}, va = {0}, bx = {0}, vx = {0}, by = {0}, vy = {0};
        int st;
        rng_seed(99);
        make_mat(10, 10, 5, &ba, &va);
        make_vec(10, 2, &bx, &vx);
        make_vec(10, 2, &by, &vy);
        fill_mat(&va, 5, 2.0);
        fill_vec(&vx, 2);
        fill_vec(&vy, 2);
        c.max_temp_bytes = 900;
        check(nd_gemv(&c, 0, 1.0, &va, &vx, 1.0, &vy) == OTI_ERR_MEMORY,
              "fix1.2: gemv packing A (800) + x (80) + y (80) = 960 bytes: a 900-byte budget -> MEMORY");
        c.max_temp_bytes = 960;
        st = nd_gemv(&c, 0, 1.0, &va, &vx, 1.0, &vy);
        check(st == OTI_OK, "fix1.2: a 960-byte budget suffices");
        nd_release(&ba); nd_release(&bx); nd_release(&by);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_gemm_hand();
    test_gemm_random();
    test_gemm_errors();
    test_gemm_odd_singleton_strides();
    test_gemm_dispatch_no_pack();
    test_gemm_order_block_view();
    test_matmul_hand_and_errors();
    test_matmul_random();
    test_matmul_overlap();
    test_dot();
    test_level1_random();
    test_level1_specials_and_errors();
    test_gemv_ger_random();
    test_gemv_ger_errors();
    test_blas_fail_alloc();
    test_blas_int_limit();

    test_fix1_blas_peak();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
