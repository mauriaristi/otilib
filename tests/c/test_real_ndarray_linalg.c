/* Tests of the ndarray linear algebra, tier 1 (include/oti/real/ndarray/linalg.h, Phase 3): nd_lu_factor,
 * nd_lu_solve, nd_lu_free, nd_solve, nd_inv, nd_det, nd_slogdet, nd_cholesky, nd_cho_solve,
 * nd_solve_triangular.
 *
 * Written from PLAN-ndarray-contracts.md (rows 9.3, 9.4, 9.5, 1.4, [k5], [k10]) and linalg.h,
 * independently of
 * src/c/real/ndarray/linalg.c. Oracles: Gaussian elimination with partial pivoting in long double (det,
 * slogdet, solutions of well-conditioned systems); backward-error residuals for solves, which hold for LU
 * with
 * partial pivoting at these sizes: max |A x - b| <= 16 (n + 1) eps (||A|| ||x|| + ||b||) (the factor 16
 * absorbs
 * the growth factor and the unspecified summation order of the BLAS); A X = I for the inverse
 * (32 n^2 eps ||A|| ||X||); L L^T = A / U^T U = A for Cholesky (32 (n + 1) eps scale); substitution in
 * long
 * double for triangular solves (1e-10 relative, the matrices are diagonally dominant). Exactly singular
 * matrices are built by hand ([[1,2],[2,4]]: the second pivot is exactly zero). Inputs come in C, F and
 * strided layouts; NaN is planted in the triangle that must not be read. The [k5] test replaces the
 * LAPACK
 * provider table by one whose every routine counts a call and does nothing, and checks that empty systems
 * make none. */
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
#include <oti/real/ndarray/linalg.h>

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
static void fill_random_small(ndarr_t* a){

    int64_t n = shape_size(a->ndim, a->shape), i;

    for (i = 0; i < n; i++){
        set_f(a, i, (rng_uniform() - 0.5) * 2.0);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Matrix helpers
// =======================================================================================================


// *******************************************************************************************************
// Element (i, j) of matrix `bl` of an array of shape (..., n, n) (logical C order of the batch).
static double bget(const ndarr_t* a, int64_t bl, int64_t i, int64_t j){

    int64_t n = a->shape[a->ndim - 1];

    return get_f(a, (bl * n + i) * n + j);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int64_t batch_count(const ndarr_t* a){

    int64_t nb = 1;
    int32_t k;

    for (k = 0; k < a->ndim - 2; k++){
        nb *= a->shape[k];
    }
    return nb;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills an (..., n, n) array with random values; diag > 0 makes it diagonally dominant (well
// conditioned).
static void fill_matrices(ndarr_t* a, double diag){

    int64_t n = a->shape[a->ndim - 1], nb = batch_count(a), bl, i, j;

    for (bl = 0; bl < nb; bl++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                double v = (rng_uniform() - 0.5) * 2.0;
                if (i == j){
                    v += diag * (rng_int(2) ? 1.0 : -1.0);
                }
                set_f(a, (bl * n + i) * n + j, v);
            }
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Long double LU with partial pivoting of one matrix: returns det and slogdet (sign, logabs); `x` solves
// A x = b for the single right-hand side when b is given (n values) and the matrix is not singular.
static int ref_lu(const ndarr_t* a, int64_t bl, const double* b, long double* x, long double* det,
                  int* sign, long double* logabs){

    int64_t n = a->shape[a->ndim - 1], i, j, k;
    long double m[16 * 16], rhs[16], dt = 1.0L, la = 0.0L;
    int sg = 1, singular = 0, swaps = 1;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            m[i * n + j] = (long double)bget(a, bl, i, j);
        }
        rhs[i] = b ? (long double)b[i] : 0.0L;
    }
    for (k = 0; k < n; k++){
        int64_t p = k;
        long double best = fabsl(m[k * n + k]);
        for (i = k + 1; i < n; i++){
            if (fabsl(m[i * n + k]) > best){
                best = fabsl(m[i * n + k]);
                p = i;
            }
        }
        if (best == 0.0L){
            singular = 1;
            break;
        }
        if (p != k){
            for (j = 0; j < n; j++){
                long double t = m[k * n + j]; m[k * n + j] = m[p * n + j]; m[p * n + j] = t;
            }
            { long double t = rhs[k]; rhs[k] = rhs[p]; rhs[p] = t; }
            sg = -sg;
            swaps = -swaps;
        }
        for (i = k + 1; i < n; i++){
            long double f = m[i * n + k] / m[k * n + k];
            for (j = k; j < n; j++){
                m[i * n + j] -= f * m[k * n + j];
            }
            rhs[i] -= f * rhs[k];
        }
        dt *= m[k * n + k];
        if (m[k * n + k] < 0){
            sg = -sg;
        }
        la += logl(fabsl(m[k * n + k]));
    }
    if (singular){
        *det = 0.0L;
        *sign = 0;
        *logabs = -INFINITY;
        return 1;
    }
    *det = dt * (long double)swaps;
    *sign = sg;
    *logabs = la;
    if (x != NULL && b != NULL){
        for (i = n - 1; i >= 0; i--){
            long double s = rhs[i];
            for (j = i + 1; j < n; j++){
                s -= m[i * n + j] * x[j];
            }
            x[i] = s / m[i * n + i];
        }
    }
    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Infinity norm of matrix `bl`.
static double mnorm(const ndarr_t* a, int64_t bl){

    int64_t n = a->shape[a->ndim - 1], i, j;
    double mx = 0.0;

    for (i = 0; i < n; i++){
        double s = 0.0;
        for (j = 0; j < n; j++){
            s += fabs(bget(a, bl, i, j));
        }
        mx = s > mx ? s : mx;
    }
    return mx;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Backward-error residual of A x = b for column `col` of matrix `bl` (b, x with shapes (..., n, k)):
// max_i |sum_j A_ij x_j - b_i| <= c * n * eps * (|A||x| + |b|)_i is the criterion; returns the ratio of
// the residual to n * eps * (||A|| ||x|| + ||b||), which must be below a small constant for an LU with
// partial pivoting on these matrices (growth factors are modest at n <= 12).
static double residual_ratio(const ndarr_t* a, int64_t abl, const double* x, const double* b, int64_t n){

    double res = 0.0, xn = 0.0, bn = 0.0;
    int64_t i, j;

    for (i = 0; i < n; i++){
        long double s = 0.0L;
        for (j = 0; j < n; j++){
            s += (long double)bget(a, abl, i, j) * (long double)x[j];
        }
        s -= (long double)b[i];
        res = fabs((double)s) > res ? fabs((double)s) : res;
        xn = fabs(x[i]) > xn ? fabs(x[i]) : xn;
        bn = fabs(b[i]) > bn ? fabs(b[i]) : bn;
    }
    return res / ((double)(n + 1) * DBL_EPSILON * (mnorm(a, abl) * xn + bn) + 1e-300);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 9.3 LU
// =======================================================================================================

// *******************************************************************************************************
static int ndarr_is_empty(const ndarr_t* a){

    return a->buf == NULL && a->data == NULL && a->ndim == 1 && a->shape[0] == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_lu_factor_orientation(void){

    ndarr_t a = {0}, f = {0}, base = {0}, view = {0}, x = {0}, b = {0};
    nd_lu_t lu;
    int64_t sh[2] = {5, 5}, i;
    double rhs[5], sol[5], resid = 0.0;
    int st, ok;
    double saved[25];

    rng_seed(1848);
    nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &a);
    fill_matrices(&a, 6.0);
    memcpy(saved, a.data, sizeof(saved));
    nd_lu_init(&lu);
    check(lu.ipiv == NULL && lu.n == 0 && ndarr_is_empty(&lu.lu), "nd_lu_init: an empty factorization");
    st = nd_lu_factor(NULL, &a, 0, &lu);
    check(st == OTI_OK && lu.n == 5 && lu.info == 0 && lu.ipiv != NULL,
            "lu_factor of a C matrix: OK, n 5, info 0");
    check(lu.trans == 1, "lu_factor: a C-contiguous input is read as A^T (trans = 1)");
    check(lu.lu.data != a.data && memcmp(a.data, saved, sizeof(saved)) == 0,
            "lu_factor(overwrite = 0): the input is unchanged and not the factor");
    check((lu.lu.flags & ND_F_CONTIG) && lu.lu.shape[0] == 5 && lu.lu.shape[1] == 5,
            "lu: the factor buffer is an F-order 5 x 5");
    for (i = 0; i < 5; i++){
        rhs[i] = (double)(i + 1);
    }
    make_from(1, (int64_t[]){5}, ND_LAYOUT_C, rhs, &b);
    check(nd_lu_solve(NULL, &lu, &b, &x) == OTI_OK && x.ndim == 1 && x.shape[0] == 5, "lu_solve (5,)");
    for (i = 0; i < 5; i++){
        sol[i] = get_f(&x, i);
    }
    resid = residual_ratio(&a, 0, sol, rhs, 5);
    check(resid < 16.0, "lu_solve residual ||Ax - b|| below 16 n eps (||A|| ||x|| + ||b||)");
    nd_release(&x);
    nd_release(&b);
    nd_lu_free(&lu);
    check(lu.ipiv == NULL && lu.n == 0 && ndarr_is_empty(&lu.lu),
            "nd_lu_free resets to empty; a second free is safe");
    nd_lu_free(&lu);
    nd_lu_free(NULL);

    // F input: trans 0
    nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_F, 0, &f);
    fill_matrices(&f, 6.0);
    nd_lu_init(&lu);
    check(nd_lu_factor(NULL, &f, 0, &lu) == OTI_OK && lu.trans == 0,
            "lu_factor of an F matrix: trans = 0");
    nd_lu_free(&lu);

    // strided input (every other row and column of a 10 x 10): packed to F, trans 0
    {
        int64_t bsh[2] = {10, 10};
        nd_index_t ix[2];
        nd_alloc(NULL, OTI_F64, 2, bsh, ND_LAYOUT_C, ND_ALLOC_ZERO, &base);
        ix[0] = mk_slice(HT, 0, 0, 2);
        ix[1] = mk_slice(HT, 0, 0, 2);
        nd_view_index(&base, 2, ix, &view);
        fill_matrices(&view, 6.0);
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &view, 0, &lu) == OTI_OK && lu.trans == 0 && lu.n == 5,
                "lu_factor of a strided view: packed, trans = 0");
        {
            ndarr_t bb = {0}, xx = {0};
            double r2[5] = {1, -1, 2, -2, 3}, s2[5];
            make_from(1, (int64_t[]){5}, ND_LAYOUT_C, r2, &bb);
            nd_lu_solve(NULL, &lu, &bb, &xx);
            for (i = 0; i < 5; i++){
                s2[i] = get_f(&xx, i);
            }
            check(residual_ratio(&view, 0, s2, r2, 5) < 16.0,
                    "lu_solve with the packed factors: small residual");
            nd_release(&bb); nd_release(&xx);
        }
        nd_lu_free(&lu);
        nd_release(&base);
    }

    // overwrite: a writeable C or F contiguous input is factored in place
    {
        double keep[25];
        memcpy(keep, a.data, sizeof(keep));
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &a, 1, &lu) == OTI_OK && lu.lu.data == a.data && lu.trans == 1,
              "lu_factor(overwrite = 1) of a C matrix: in place (lu.lu aliases the input), trans 1");
        ok = (lu.lu.flags & ND_RETAINED) != 0 && nd_buffer_refs(a.buf) == 2;
        check(ok, "overwrite: lu.lu is a retained view of the input (refs 2)");
        nd_lu_free(&lu);
        check(nd_buffer_refs(a.buf) == 1, "nd_lu_free releases that reference");
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &f, 1, &lu) == OTI_OK && lu.lu.data == f.data && lu.trans == 0,
              "overwrite of an F matrix: in place, trans 0");
        nd_lu_free(&lu);
        (void)keep;
    }
    // overwrite on a growing buffer: BUSY, lu empty (cL2)
    {
        ndarr_t g = {0};
        nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &g);
        fill_matrices(&g, 6.0);
        check(nd_buffer_lock_layout(g.buf) == OTI_OK, "lock the layout of the input");
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &g, 1, &lu) == OTI_ERR_BUSY && lu.n == 0 && lu.ipiv == NULL &&
                ndarr_is_empty(&lu.lu),
              "lu_factor(overwrite = 1) on a growing buffer -> BUSY, lu left empty");
        nd_lu_free(&lu);
        check(nd_lu_factor(NULL, &g, 0, &lu) == OTI_OK,
                "without overwrite the same input factors fine (no retain)");
        nd_lu_free(&lu);
        nd_buffer_unlock_layout(g.buf);
        nd_release(&g);
    }
    // overwrite of a trusted temporary (no buffer): lu.lu is a temporary
    {
        static double mem[25];
        ndarr_t t = {0};
        memcpy(mem, saved, sizeof(mem));
        nd_wrap_trusted(mem, OTI_F64, 2, sh, NULL, 1, &t);
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &t, 1, &lu) == OTI_OK && lu.lu.data == (void*)mem &&
                !(lu.lu.flags & ND_RETAINED),
              "overwrite of a trusted temporary: lu.lu is a temporary over the same memory");
        nd_lu_free(&lu);
    }
    // non-overwritable layouts fall back to a copy even with overwrite = 1
    {
        ndarr_t bb = {0}, vv = {0};
        int64_t bsh[2] = {10, 5};
        nd_index_t ix[2];
        nd_alloc(NULL, OTI_F64, 2, bsh, ND_LAYOUT_C, 0, &bb);
        ix[0] = mk_slice(HT, 0, 0, 2);
        ix[1] = mk_slice(0, 0, 0, 0);
        nd_view_index(&bb, 2, ix, &vv);
        fill_matrices(&vv, 6.0);
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &vv, 1, &lu) == OTI_OK && lu.lu.data != vv.data,
                "overwrite = 1 of a strided view: factored from a copy");
        nd_lu_free(&lu);
        nd_release(&bb);
    }
    nd_release(&a);
    nd_release(&f);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_lu_errors_and_singular(void){

    ndarr_t a = {0}, r = {0}, b = {0};
    nd_lu_t lu;
    double sing[4] = {1, 2, 2, 4};
    int64_t s22[2] = {2, 2};
    int st;

    nd_lu_init(&lu);
    {
        ndarr_t u = {0}, ns = {0}, v1 = {0}, c3 = {0};
        nd_alloc(NULL, OTI_U8, 2, s22, ND_LAYOUT_C, 0, &u);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){2, 3}, ND_LAYOUT_C, 0, &ns);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){2}, ND_LAYOUT_C, 0, &v1);
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, 2, 3}, ND_LAYOUT_C, 0, &c3);
        check(nd_lu_factor(NULL, &u, 0, &lu) == OTI_ERR_DTYPE && lu.n == 0,
                "lu_factor of U8 -> DTYPE, lu empty");
        check(nd_lu_factor(NULL, &ns, 0, &lu) == OTI_ERR_SHAPE, "lu_factor of (2,3) -> SHAPE");
        check(nd_lu_factor(NULL, &v1, 0, &lu) == OTI_ERR_SHAPE, "lu_factor of a 1-D array -> SHAPE");
        check(nd_lu_factor(NULL, &c3, 0, &lu) == OTI_ERR_SHAPE, "lu_factor of (2,2,3) -> SHAPE");
        nd_lu_free(&lu);
        nd_release(&u); nd_release(&ns); nd_release(&v1); nd_release(&c3);
    }
    // exactly singular: [[1,2],[2,4]] has the zero pivot U(2,2)
    make_from(2, s22, ND_LAYOUT_C, sing, &a);
    st = nd_lu_factor(NULL, &a, 0, &lu);
    check(st == 2 && lu.info == 2 && lu.n == 2 && lu.ipiv != NULL,
            "lu_factor of [[1,2],[2,4]]: positive status 2 (U(2,2) exactly zero), lu complete");
    make_from(1, (int64_t[]){2}, ND_LAYOUT_C, (double[]){1, 2}, &b);
    check(nd_lu_solve(NULL, &lu, &b, &r) == 2 && r.buf == NULL,
            "lu_solve with info > 0 returns info, nothing solved");
    nd_lu_free(&lu);
    check(nd_solve(NULL, &a, &b, &r) == 2 && r.buf == NULL,
            "nd_solve of a singular matrix: info 2 (LinAlgError)");
    check(nd_inv(NULL, &a, &r) == 2 && r.buf == NULL, "nd_inv of a singular matrix: info 2");
    check(nd_det(NULL, &a, &r) == OTI_OK && r.ndim == 0 && get_f(&r, 0) == 0.0,
            "nd_det of a singular matrix: OK, 0.0");
    nd_release(&r);
    {
        ndarr_t sg = {0}, lg = {0};
        check(nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK && get_f(&sg, 0) == 0.0 && get_f(&lg,
                0) == -INFINITY,
              "nd_slogdet of a singular matrix: (0.0, -inf), OK");
        nd_release(&sg); nd_release(&lg);
    }
    {
        double z[4] = {0, 0, 0, 1};
        ndarr_t za = {0};
        make_from(2, s22, ND_LAYOUT_C, z, &za);
        check(nd_inv(NULL, &za, &r) == 1, "inv of [[0,0],[0,1]]: info 1 (the first column is zero)");
        check(nd_det(NULL, &za, &r) == OTI_OK && get_f(&r, 0) == 0.0, "det of [[0,0],[0,1]] is 0.0");
        nd_release(&r);
        nd_release(&za);
    }
    nd_release(&a);
    nd_release(&b);

    // solve argument errors
    {
        ndarr_t m = {0}, bb = {0}, bu = {0}, mb = {0};
        double iv[4] = {1, 0, 0, 1};
        make_from(2, s22, ND_LAYOUT_C, iv, &m);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){3}, ND_LAYOUT_C, 0, &bb);
        nd_alloc(NULL, OTI_U8, 1, (int64_t[]){2}, ND_LAYOUT_C, 0, &bu);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){3, 2}, ND_LAYOUT_C, 0, &mb);
        check(nd_solve(NULL, &m, &bb, &r) == OTI_ERR_SHAPE && r.buf == NULL,
                "solve with b of length 3 for a 2 x 2: SHAPE");
        check(nd_solve(NULL, &m, &mb, &r) == OTI_ERR_SHAPE, "solve with b (3,2) for a 2 x 2: SHAPE");
        check(nd_solve(NULL, &m, &bu, &r) == OTI_ERR_DTYPE, "solve with U8 b: DTYPE");
        check(nd_inv(NULL, &bb, &r) == OTI_ERR_SHAPE, "inv of a 1-D array: SHAPE");
        check(nd_det(NULL, &mb, &r) == OTI_ERR_SHAPE, "det of a (3,2) array: SHAPE");
        check(nd_det(NULL, &bu, &r) == OTI_ERR_SHAPE || nd_det(NULL, &bu, &r) == OTI_ERR_DTYPE,
                "det of a 1-D U8: an error");
        {
            oti_ctx ctx;
            oti_ctx_init(&ctx);
            check(nd_solve(&ctx, &m, &bb, &r) == OTI_ERR_SHAPE && oti_ctx_last_error(&ctx, NULL,
                    NULL) == OTI_ERR_SHAPE,
                  "a failing nd_solve records SHAPE");
            ctx.device_type = 2;
            check(nd_inv(&ctx, &m, &r) == oti_ctx_check(&ctx), "nd_inv rejects a bad context");
        }
        nd_release(&m); nd_release(&bb); nd_release(&bu); nd_release(&mb);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_solve_inv_det_random(void){

    int iter, f_solve = 0, f_inv = 0, f_det = 0, f_slog = 0, f_layout = 0, f_ref = 0, f_input = 0;

    rng_seed(1905);
    for (iter = 0; iter < 800; iter++){

        int64_t n = 1 + rng_int(9), k = 1 + rng_int(4), i, j, c;
        int kind = (int)rng_int(3), bk = (int)rng_int(3);
        int diag = (rng_int(3) != 0);
        int64_t sh[2], bsh[2];
        ndarr_t ba = {0}, a = {0}, bb = {0}, b = {0}, x = {0}, inv = {0}, det = {0}, sg = {0}, lg = {0};
        double snap[16 * 16];
        long double dref, lref;
        int sref, sing;

        sh[0] = sh[1] = n;
        make_view(2, sh, kind, OTI_F64, &ba, &a);
        fill_matrices(&a, diag ? (double)n + 1.0 : 0.0);
        for (i = 0; i < n * n; i++){
            snap[i] = get_f(&a, i);
        }
        sing = ref_lu(&a, 0, NULL, NULL, &dref, &sref, &lref);

        // solve with several right-hand sides (and the vector form)
        bsh[0] = n; bsh[1] = k;
        make_view(2, bsh, bk, OTI_F64, &bb, &b);
        fill_random_small(&b);
        if (!sing && nd_solve(NULL, &a, &b, &x) == OTI_OK){
            int ok = x.ndim == 2 && x.shape[0] == n && x.shape[1] == k;
            for (c = 0; ok && c < k; c++){
                double xc[16], bc[16];
                for (i = 0; i < n; i++){
                    xc[i] = get_f(&x, i * k + c);
                    bc[i] = get_f(&b, i * k + c);
                }
                if (residual_ratio(&a, 0, xc, bc, n) > 16.0 + 16.0 * 0){
                    ok = 0;
                }
                if (diag){
                    long double xr[16];
                    ref_lu(&a, 0, bc, xr, &dref, &sref, &lref);
                    for (i = 0; i < n; i++){
                        if (fabs(xc[i] - (double)xr[i]) > 1e-11 * (1.0 + fabs((double)xr[i]))){
                            f_ref++;
                        }
                    }
                }
            }
            if (!ok){
                f_solve++;
            }
            nd_release(&x);
        } else if (!sing){
            f_solve++;
        }
        // inputs are never modified
        for (i = 0; i < n * n; i++){
            if (!same_bits(get_f(&a, i), snap[i])){
                f_input++;
                break;
            }
        }
        // inverse: A X = I
        if (!sing){
            if (nd_inv(NULL, &a, &inv) != OTI_OK || inv.shape[0] != n || inv.shape[1] != n){
                f_inv++;
            } else {
                double xn = 0.0;
                int ok = 1;
                for (j = 0; j < n * n; j++){
                    xn = fabs(get_f(&inv, j)) > xn ? fabs(get_f(&inv, j)) : xn;
                }
                for (i = 0; i < n; i++){
                    for (j = 0; j < n; j++){
                        long double s = 0;
                        for (c = 0; c < n; c++){
                            s += (long double)bget(&a, 0, i, c) * (long double)get_f(&inv, c * n + j);
                        }
                        if (fabs((double)s - (i == j ? 1.0 : 0.0)) >
                            32.0 * (double)(n + 1) * DBL_EPSILON * mnorm(&a,
                                    0) * xn * (double)n + 1e-300){
                            ok = 0;
                        }
                    }
                }
                if (!ok){
                    f_inv++;
                }
                // orientation: a C-contiguous input gives a C result, anything else an F result
                {
                    int want_c = (a.flags & ND_C_CONTIG) && !(a.flags & ND_F_CONTIG);
                    if (n > 1 && ((want_c && !(inv.flags & ND_C_CONTIG)) ||
                                  (!want_c && !(inv.flags & ND_F_CONTIG)))){
                        f_layout++;
                        if (f_layout < 4){
                            fprintf(stderr, "  inv layout: input flags %d kind %d -> result flags %d\n",
                                    a.flags & 3, kind, inv.flags & 3);
                        }
                    }
                }
                nd_release(&inv);
            }
        }
        // det and slogdet
        if (nd_det(NULL, &a, &det) != OTI_OK || det.ndim != 0){
            f_det++;
        } else {
            double got = get_f(&det, 0);
            if (sing){
                f_det += (got != 0.0);
            } else if (!(fabs(got - (double)dref) <= 1e-10 * fabs((double)dref) + 1e-300)){
                f_det++;
                if (f_det < 4){
                    fprintf(stderr, "  det iter %d n %lld diag %d: got %.17g ref %.17g\n", iter,
                            (long long)n, diag,
                            got, (double)dref);
                }
            }
            nd_release(&det);
        }
        if (nd_slogdet(NULL, &a, &sg, &lg) != OTI_OK || sg.ndim != 0 || lg.ndim != 0){
            f_slog++;
        } else if (!sing){
            f_slog += !(get_f(&sg, 0) == (double)sref && fabs(get_f(&lg,
                    0) - (double)lref) <= 1e-10 * (1.0 + fabs((double)lref)));
            nd_release(&sg);
            nd_release(&lg);
        } else {
            f_slog += !(get_f(&sg, 0) == 0.0 && get_f(&lg, 0) == -INFINITY);
            nd_release(&sg);
            nd_release(&lg);
        }
        nd_release(&ba);
        nd_release(&bb);
    }
    check(f_solve == 0,
            "nd_solve: 800 random n x n (C, F, strided) with (n,k) right-hand sides: small residual");
    check(f_ref == 0,
            "nd_solve of a well-conditioned matrix equals the long double elimination to 1e-11");
    check(f_input == 0, "solve / inv / det never modify the input");
    check(f_inv == 0, "nd_inv: A X = I to 32 n^2 eps ||A|| ||X||");
    check(f_layout == 0, "nd_inv: a C input gives a C result, F and strided inputs an F result");
    check(f_det == 0, "nd_det equals the long double determinant to 1e-10 (0.0 for exactly singular)");
    check(f_slog == 0, "nd_slogdet: sign and log|det| equal the reference");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_solve_vector_and_batches(void){

    int64_t n = 4, i, bl, c;
    ndarr_t a = {0}, b = {0}, x = {0}, det = {0}, sg = {0}, lg = {0}, inv = {0};
    int ok;
    double xc[16], bc[16];

    rng_seed(7);
    // stacked (3,n,n)
    nd_alloc(NULL, OTI_F64, 3, (int64_t[]){3, n, n}, ND_LAYOUT_C, 0, &a);
    fill_matrices(&a, 6.0);

    // vector b (n,) against a stack: result (3,n)
    nd_alloc(NULL, OTI_F64, 1, (int64_t[]){n}, ND_LAYOUT_C, 0, &b);
    fill_random_small(&b);
    check(nd_solve(NULL, &a, &b, &x) == OTI_OK && x.ndim == 2 && x.shape[0] == 3 && x.shape[1] == n,
          "solve with a stack (3,4,4) and a vector (4,): result (3,4)");
    ok = 1;
    for (bl = 0; bl < 3; bl++){
        for (i = 0; i < n; i++){
            xc[i] = get_f(&x, bl * n + i);
            bc[i] = get_f(&b, i);
        }
        ok = ok && residual_ratio(&a, bl, xc, bc, n) < 16.0;
    }
    check(ok, "stack with a vector b: every matrix solved (small residual)");
    nd_release(&x);
    nd_release(&b);

    // (n, k) against a stack: (3, n, k); (3, n, k) against a stack
    {
        int64_t k = 2;
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &b);
        fill_random_small(&b);
        check(nd_solve(NULL, &a, &b, &x) == OTI_OK && x.ndim == 3 && x.shape[0] == 3 && x.shape[1] == n &&
                x.shape[2] == k,
              "solve with a stack and one (4,2): result (3,4,2)");
        ok = 1;
        for (bl = 0; bl < 3; bl++){
            for (c = 0; c < k; c++){
                for (i = 0; i < n; i++){
                    xc[i] = get_f(&x, (bl * n + i) * k + c);
                    bc[i] = get_f(&b, i * k + c);
                }
                ok = ok && residual_ratio(&a, bl, xc, bc, n) < 16.0;
            }
        }
        check(ok, "stack with a shared (n,k) b: residuals small");
        nd_release(&x);
        nd_release(&b);
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){3, n, k}, ND_LAYOUT_C, 0, &b);
        fill_random_small(&b);
        check(nd_solve(NULL, &a, &b, &x) == OTI_OK && x.ndim == 3 && x.shape[0] == 3,
                "solve with a stack and a (3,4,2) b");
        ok = 1;
        for (bl = 0; bl < 3; bl++){
            for (c = 0; c < k; c++){
                for (i = 0; i < n; i++){
                    xc[i] = get_f(&x, (bl * n + i) * k + c);
                    bc[i] = get_f(&b, (bl * n + i) * k + c);
                }
                ok = ok && residual_ratio(&a, bl, xc, bc, n) < 16.0;
            }
        }
        check(ok, "stack with a stacked b: residuals small");
        nd_release(&x);
        nd_release(&b);
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, n, k}, ND_LAYOUT_C, 0, &b);
        check(nd_solve(NULL, &a, &b, &x) == OTI_ERR_SHAPE, "batch (3) against b batch (2): SHAPE");
        nd_release(&b);
    }
    // inv, det, slogdet of the stack against the per-matrix results
    check(nd_inv(NULL, &a, &inv) == OTI_OK && inv.ndim == 3 && inv.shape[0] == 3,
            "inv of a stack: shape (3,4,4)");
    ok = 1;
    for (bl = 0; bl < 3; bl++){
        ndarr_t one = {0}, oinv = {0};
        nd_index_t ix[1];
        ix[0].kind = ND_IDX_INT; ix[0].has = 0; ix[0].start = bl;
        ix[0].stop = 0; ix[0].step = 0; ix[0].arr = NULL;
        nd_view_index(&a, 1, ix, &one);
        nd_inv(NULL, &one, &oinv);
        for (i = 0; i < n * n; i++){
            ok = ok && fabs(get_f(&inv, bl * n * n + i) - get_f(&oinv,
                    i)) <= 1e-14 * (1.0 + fabs(get_f(&oinv, i)));
        }
        nd_release(&oinv);
    }
    check(ok, "stacked inv equals the per-matrix inverses");
    nd_release(&inv);
    check(nd_det(NULL, &a, &det) == OTI_OK && det.ndim == 1 && det.shape[0] == 3,
            "det of a stack: shape (3,)");
    check(nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK && sg.ndim == 1 && lg.shape[0] == 3,
            "slogdet of a stack: shapes (3,)");
    ok = 1;
    for (bl = 0; bl < 3; bl++){
        long double d, l;
        int s;
        ref_lu(&a, bl, NULL, NULL, &d, &s, &l);
        ok = ok && fabs(get_f(&det, bl) - (double)d) <= 1e-10 * fabs((double)d) && get_f(&sg,
                bl) == (double)s &&
             fabs(get_f(&lg, bl) - (double)l) <= 1e-10 * (1.0 + fabs((double)l));
    }
    check(ok, "stacked det / slogdet equal the references");
    nd_release(&det); nd_release(&sg); nd_release(&lg);

    // the first singular matrix of the batch (C order) decides the positive status
    {
        int64_t cnt = 0;
        double z[16] = {0};
        for (i = 0; i < n * n; i++){
            z[i] = 0.0;
        }
        // matrix 1: first column zero; matrix 2: first row zero. Both are exactly singular, but the pivot
        // at which
        // dgetrf finds the zero differs (the factored matrix is A^T for a C input), so the status says
        // which
        // matrix decided: the first singular matrix of the batch in C order must.
        int st1, st2, stall;
        ndarr_t m1 = {0}, m2 = {0};
        nd_index_t ixm[1];
        for (i = 0; i < n; i++){
            set_f(&a, 1 * n * n + i * n + 0, 0.0);
            set_f(&a, 2 * n * n + 0 * n + i, 0.0);
        }
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){n}, ND_LAYOUT_C, 0, &b);
        fill_random_small(&b);
        ixm[0].kind = ND_IDX_INT; ixm[0].has = 0; ixm[0].start = 1;
        ixm[0].stop = 0; ixm[0].step = 0; ixm[0].arr = NULL;
        nd_view_index(&a, 1, ixm, &m1);
        ixm[0].start = 2;
        nd_view_index(&a, 1, ixm, &m2);
        st1 = nd_solve(NULL, &m1, &b, &x);
        st2 = nd_solve(NULL, &m2, &b, &x);
        stall = nd_solve(NULL, &a, &b, &x);
        check(st1 > 0 && st2 > 0 && st1 != st2,
                "the two singular matrices alone give different positive infos");
        check(stall == st1 && x.buf == NULL,
                "a stack with singular matrices 1 and 2: solve returns the info of matrix 1");
        check(nd_inv(NULL, &a, &inv) == st1 && inv.buf == NULL,
                "stack inv: the info of the first singular matrix");
        check(nd_det(NULL, &a, &det) == OTI_OK && get_f(&det, 1) == 0.0 && get_f(&det, 2) == 0.0 &&
                get_f(&det, 0) != 0.0,
              "stack det: zeros exactly for the singular matrices, OK status");
        nd_release(&det);
        nd_release(&b);
        (void)cnt; (void)z;
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_det_specials(void){

    ndarr_t a = {0}, r = {0}, sg = {0}, lg = {0};
    int64_t s4[2] = {4, 4}, s2[2] = {2, 2}, s0[2] = {0, 0};
    double d4[16] = {0}, sw[4] = {0, 1, 1, 0}, big[4] = {1e200, 0, 0, 1e200};
    double dn[9] = {-1, 0, 0, 0, 2, 0, 0, 0, 3};

    // [k10]: diag(1e200, 1e200, 1e-200, 1e-200) has determinant 1.0 (the plain product of U would
    // overflow)
    d4[0] = 1e200; d4[5] = 1e200; d4[10] = 1e-200; d4[15] = 1e-200;
    make_from(2, s4, ND_LAYOUT_C, d4, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && fabs(get_f(&r, 0) - 1.0) <= 1e-12,
            "det diag(1e200, 1e200, 1e-200, 1e-200) = 1.0 as NumPy");
    nd_release(&r);
    check(nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK && get_f(&sg, 0) == 1.0 && fabs(get_f(&lg, 0)) <= 1e-9,
          "slogdet of the same: (1.0, ~0)");
    nd_release(&sg); nd_release(&lg);
    nd_release(&a);
    // overflow: det inf while slogdet is finite
    make_from(2, s2, ND_LAYOUT_C, big, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && get_f(&r, 0) == INFINITY,
            "det diag(1e200, 1e200) overflows to inf, status OK");
    nd_release(&r);
    check(nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK && get_f(&sg, 0) == 1.0 && fabs(get_f(&lg,
            0) - 2.0 * log(1e200)) <= 1e-9,
          "slogdet of the same stays finite: log|det| = 2 log(1e200)");
    nd_release(&sg); nd_release(&lg);
    nd_release(&a);
    // permutation sign
    make_from(2, s2, ND_LAYOUT_C, sw, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && fabs(get_f(&r, 0) + 1.0) <= 1e-15, "det [[0,1],[1,0]] = -1");
    nd_release(&r);
    check(nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK && get_f(&sg, 0) == -1.0 && fabs(get_f(&lg,
            0)) <= 1e-15,
          "slogdet [[0,1],[1,0]] = (-1, 0)");
    nd_release(&sg); nd_release(&lg);
    nd_release(&a);
    make_from(2, (int64_t[]){3, 3}, ND_LAYOUT_C, dn, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && fabs(get_f(&r, 0) + 6.0) <= 1e-14, "det diag(-1, 2, 3) = -6");
    nd_release(&r);
    nd_release(&a);
    // 0 x 0
    nd_alloc(NULL, OTI_F64, 2, s0, ND_LAYOUT_C, 0, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && r.ndim == 0 && get_f(&r, 0) == 1.0,
            "det of a 0 x 0 matrix is 1.0");
    nd_release(&r);
    check(nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK && get_f(&sg, 0) == 1.0 && get_f(&lg, 0) == 0.0,
            "slogdet of 0 x 0 is (1.0, 0.0)");
    nd_release(&sg); nd_release(&lg);
    nd_release(&a);
    // a stack of 0 x 0 matrices
    nd_alloc(NULL, OTI_F64, 3, (int64_t[]){3, 0, 0}, ND_LAYOUT_C, 0, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 3 && get_f(&r, 2) == 1.0,
            "det of three 0 x 0 matrices: (1,1,1)");
    nd_release(&r);
    nd_release(&a);
    // an empty batch of 2 x 2 matrices
    nd_alloc(NULL, OTI_F64, 3, (int64_t[]){0, 2, 2}, ND_LAYOUT_C, 0, &a);
    check(nd_det(NULL, &a, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 0,
            "det of an empty batch: an empty (0,)");
    nd_release(&r);
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


static int g_traps = 0;

// *******************************************************************************************************
static void trap_fn(void){

    g_traps++;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// [k5]: empty systems (n = 0, k = 0) make NO provider call. The provider table is replaced by one whose
// every routine counts a call and does nothing.
static void test_empty_makes_no_provider_call(void){

    oti_lapack_provider_t p = *oti_lapack_provider();
    ndarr_t a = {0}, b = {0}, r = {0}, sg = {0}, lg = {0};
    nd_lu_t lu;
    int calls_ok = 1;

    p.dgetrf = trap_fn; p.dgetrs = trap_fn; p.dtrsm = trap_fn; p.dtrmm = trap_fn; p.dgemm = trap_fn;
    p.ddot = trap_fn; p.daxpy = trap_fn; p.dscal = trap_fn; p.dnrm2 = trap_fn; p.dcopy = trap_fn;
    p.dswap = trap_fn; p.dasum = trap_fn; p.idamax = trap_fn; p.dgemv = trap_fn; p.dger = trap_fn;
    p.dsyrk = trap_fn; p.dgesv = trap_fn; p.dgetri = trap_fn; p.dpotrf = trap_fn; p.dpotrs = trap_fn;
    p.dtrtrs = trap_fn;
    if (oti_lapack_provider_set(&p) != OTI_OK){
        check(0, "[k5] the mock provider was accepted");
        return;
    }
    check(1, "[k5] the mock provider was accepted");
    g_traps = 0;

    // 0 x 0
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){0, 0}, ND_LAYOUT_C, 0, &a);
    nd_alloc(NULL, OTI_F64, 1, (int64_t[]){0}, ND_LAYOUT_C, 0, &b);
    calls_ok = calls_ok && nd_solve(NULL, &a, &b, &r) == OTI_OK && r.ndim == 1 && r.shape[0] == 0;
    nd_release(&r);
    nd_release(&b);
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){0, 3}, ND_LAYOUT_C, 0, &b);
    calls_ok = calls_ok && nd_solve(NULL, &a, &b, &r) == OTI_OK && r.ndim == 2 && r.shape[0] == 0 &&
            r.shape[1] == 3;
    nd_release(&r);
    nd_release(&b);
    calls_ok = calls_ok && nd_inv(NULL, &a, &r) == OTI_OK && r.shape[0] == 0 && r.shape[1] == 0;
    nd_release(&r);
    calls_ok = calls_ok && nd_det(NULL, &a, &r) == OTI_OK && get_f(&r, 0) == 1.0;
    nd_release(&r);
    calls_ok = calls_ok && nd_slogdet(NULL, &a, &sg, &lg) == OTI_OK;
    nd_release(&sg); nd_release(&lg);
    nd_lu_init(&lu);
    calls_ok = calls_ok && nd_lu_factor(NULL, &a, 0, &lu) == OTI_OK && lu.n == 0 && lu.info == 0;
    nd_lu_free(&lu);
    nd_release(&a);
    check(calls_ok, "[k5] solve / inv / det / slogdet / lu_factor of 0 x 0 succeed");
    check(g_traps == 0, "[k5] ... without a single provider call (n = 0)");

    // k = 0 right-hand sides
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){3, 3}, ND_LAYOUT_C, ND_ALLOC_ZERO, &a);
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){3, 0}, ND_LAYOUT_C, 0, &b);
    {
        double iv[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        int i;
        for (i = 0; i < 9; i++){
            set_f(&a, i, iv[i]);
        }
    }
    g_traps = 0;
    calls_ok = nd_solve(NULL, &a, &b, &r) == OTI_OK && r.ndim == 2 && r.shape[0] == 3 && r.shape[1] == 0;
    nd_release(&r);
    check(calls_ok, "[k5] solve with k = 0 right-hand sides: an empty (3,0)");
    nd_release(&a);
    nd_release(&b);

    // an empty batch
    g_traps = 0;
    nd_alloc(NULL, OTI_F64, 3, (int64_t[]){0, 3, 3}, ND_LAYOUT_C, 0, &a);
    calls_ok = nd_inv(NULL, &a, &r) == OTI_OK && r.shape[0] == 0;
    nd_release(&r);
    nd_release(&a);
    check(calls_ok && g_traps == 0, "[k5] inv of an empty batch makes no provider call");

    // the mock is live: a real product reaches it
    {
        ndarr_t x = {0}, y = {0}, z = {0};
        int64_t s22[2] = {2, 2};
        nd_alloc(NULL, OTI_F64, 2, s22, ND_LAYOUT_C, ND_ALLOC_ZERO, &x);
        nd_alloc(NULL, OTI_F64, 2, s22, ND_LAYOUT_C, ND_ALLOC_ZERO, &y);
        nd_alloc(NULL, OTI_F64, 2, s22, ND_LAYOUT_C, ND_ALLOC_ZERO, &z);
        g_traps = 0;
        nd_gemm(NULL, 0, 0, 1.0, &x, &y, 0.0, &z);
        check(g_traps >= 1, "[k5] sanity: a 2 x 2 gemm does reach the mock provider");
        nd_release(&x); nd_release(&y); nd_release(&z);
    }
    oti_lapack_provider_set(NULL);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_linalg_fail_alloc(void){

    ndarr_t a = {0}, b = {0}, r = {0};
    nd_lu_t lu;
    int k, saw, finished, ok;
    int64_t sh[2] = {4, 4};

    rng_seed(2020);
    nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &a);
    fill_matrices(&a, 6.0);
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 30 && !finished; k++){
        int st;
        nd_lu_init(&lu);
        nd_test_fail_alloc(k);
        st = nd_lu_factor(NULL, &a, 0, &lu);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            finished = 1;
        } else {
            saw++;
            ok = ok && st == OTI_ERR_MEMORY && lu.n == 0 && lu.ipiv == NULL && ndarr_is_empty(&lu.lu);
        }
        nd_lu_free(&lu);
    }
    check(saw >= 2 && finished && ok,
            "nd_lu_factor: factor buffer, control block, ipiv allocations fail with MEMORY, lu empty");

    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){4, 2}, ND_LAYOUT_C, 0, &b);
    fill_random_small(&b);
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 40 && !finished; k++){
        int st;
        nd_init_empty(&r);
        nd_test_fail_alloc(k);
        st = nd_solve(NULL, &a, &b, &r);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            finished = 1;
            nd_release(&r);
        } else {
            saw++;
            ok = ok && st == OTI_ERR_MEMORY && r.buf == NULL;
        }
    }
    check(saw >= 2 && finished && ok,
            "nd_solve: every allocation can fail: MEMORY, an empty res, then success");
    saw = 0; finished = 0; ok = 1;
    for (k = 1; k < 40 && !finished; k++){
        int st;
        nd_init_empty(&r);
        nd_test_fail_alloc(k);
        st = nd_inv(NULL, &a, &r);
        nd_test_fail_alloc(0);
        if (st == OTI_OK){
            finished = 1;
            nd_release(&r);
        } else {
            saw++;
            ok = ok && st == OTI_ERR_MEMORY && r.buf == NULL;
        }
    }
    check(saw >= 2 && finished && ok,
            "nd_inv: every allocation (factor, workspace, result) can fail: MEMORY, an empty res");
    {
        ndarr_t sg = {0}, lg = {0};
        saw = 0; finished = 0; ok = 1;
        for (k = 1; k < 40 && !finished; k++){
            int st;
            nd_init_empty(&sg);
            nd_init_empty(&lg);
            nd_test_fail_alloc(k);
            st = nd_slogdet(NULL, &a, &sg, &lg);
            nd_test_fail_alloc(0);
            if (st == OTI_OK){
                finished = 1;
                nd_release(&sg); nd_release(&lg);
            } else {
                saw++;
                ok = ok && st == OTI_ERR_MEMORY && sg.buf == NULL && lg.buf == NULL;
            }
        }
        check(saw >= 1 && finished && ok, "nd_slogdet: allocation failures leave both outputs empty");
    }
    // a temporary budget of one byte refuses the private factor buffer
    {
        oti_ctx tiny;
        oti_ctx_init(&tiny);
        tiny.max_temp_bytes = 1;
        nd_lu_init(&lu);
        check(nd_lu_factor(&tiny, &a, 0, &lu) == OTI_ERR_MEMORY && lu.n == 0,
                "lu_factor with a 1-byte temporary budget -> MEMORY");
        nd_lu_free(&lu);
        check(nd_inv(&tiny, &a, &r) == OTI_ERR_MEMORY && r.buf == NULL,
                "inv with a 1-byte temporary budget -> MEMORY");
    }
    nd_release(&a);
    nd_release(&b);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 9.5 Cholesky and triangular solves
// =======================================================================================================

// *******************************************************************************************************
// SPD matrix M M^T + n I into `a` (n x n, any layout), optionally with NaN garbage in the triangle that
// must not be read (garbage_upper: the strict upper triangle).
static void make_spd(ndarr_t* a, int garbage_triangle){

    int64_t n = a->shape[0], i, j, l;
    double m[12 * 12];

    for (i = 0; i < n * n; i++){
        m[i] = (rng_uniform() - 0.5) * 2.0;
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            long double s = 0;
            for (l = 0; l < n; l++){
                s += (long double)m[i * n + l] * (long double)m[j * n + l];
            }
            if (i == j){
                s += (long double)n;
            }
            set_f(a, i * n + j, (double)s);
        }
    }
    if (garbage_triangle == 1){            // strict upper garbage (the lower triangle is the data)
        for (i = 0; i < n; i++){
            for (j = i + 1; j < n; j++){
                set_f(a, i * n + j, NAN);
            }
        }
    } else if (garbage_triangle == 2){     // strict lower garbage
        for (i = 0; i < n; i++){
            for (j = 0; j < i; j++){
                set_f(a, i * n + j, NAN);
            }
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_cholesky(void){

    int iter, f_fact = 0, f_zero = 0, f_garb = 0, f_solve = 0, f_notpd = 0;

    rng_seed(1950);
    for (iter = 0; iter < 400; iter++){
        int64_t n = 1 + rng_int(9), i, j, l;
        int kind = (int)rng_int(3), lower = (int)rng_int(2);
        int64_t sh[2];
        ndarr_t ba = {0}, a = {0}, ref = {0}, res = {0}, res2 = {0}, x = {0}, bb = {0};
        double full[12 * 12];
        sh[0] = sh[1] = n;

        make_view(2, sh, kind, OTI_F64, &ba, &a);
        make_spd(&a, 0);
        for (i = 0; i < n * n; i++){
            full[i] = get_f(&a, i);
        }
        if (nd_cholesky(NULL, &a, lower, &res) != OTI_OK || res.ndim != 2 || res.shape[0] != n){
            f_fact++;
            nd_release(&ba);
            continue;
        }
        // reconstruct: L L^T or U^T U
        {
            int ok = 1;
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    long double s = 0;
                    for (l = 0; l < n; l++){
                        double u1 = lower ? get_f(&res, i * n + l) : get_f(&res, l * n + i);
                        double u2 = lower ? get_f(&res, j * n + l) : get_f(&res, l * n + j);
                        s += (long double)u1 * (long double)u2;
                    }
                    if (fabs((double)s - full[i * n + j]) >
                        32.0 * (double)(n + 1) * DBL_EPSILON * (fabs(full[i * n + i]) + (double)n + 1.0)){
                        ok = 0;
                    }
                }
            }
            if (!ok){
                f_fact++;
            }
            // the other triangle is exactly zero
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    int in_other = lower ? (j > i) : (j < i);
                    if (in_other && get_f(&res, i * n + j) != 0.0){
                        f_zero++;
                    }
                }
            }
        }
        // garbage in the unused triangle is never read
        {
            nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &ref);
            for (i = 0; i < n * n; i++){
                set_f(&ref, i, full[i]);
            }
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    if (lower ? (j > i) : (j < i)){
                        set_f(&ref, i * n + j, NAN);
                    }
                }
            }
            if (nd_cholesky(NULL, &ref, lower, &res2) != OTI_OK){
                f_garb++;
                if (f_garb < 4){
                    fprintf(stderr, "  chol garbage: status n %lld lo %d k %d\n", (long long)n, lower,
                            kind);
                }
            } else {
                for (i = 0; i < n * n; i++){
                    if (!(fabs(get_f(&res, i) - get_f(&res2, i)) <=
                          1e-13 * (1.0 + fabs(get_f(&res, i))))){
                        f_garb++;
                        if (f_garb < 5){
                            fprintf(stderr, "  garbage chol: n %lld lo %d k %d i %lld: %.17g %.17g\n",
                                    (long long)n, lower, kind, (long long)i, get_f(&res, i),
                                    get_f(&res2, i));
                        }
                        break;
                    }
                }
                nd_release(&res2);
            }
        }
        // cho_solve: A x = b with the factor
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, 2}, ND_LAYOUT_C, 0, &bb);
        fill_random_small(&bb);
        if (nd_cho_solve(NULL, &res, lower, &bb, &x) != OTI_OK || x.shape[0] != n || x.shape[1] != 2){
            f_solve++;
        } else {
            int64_t cc;
            for (cc = 0; cc < 2; cc++){
                double xc[16], bc[16];
                ndarr_t am = {0};
                make_desc(&am, full, OTI_F64, 2, sh, (int64_t[]){n, 1}, 0);
                for (i = 0; i < n; i++){
                    xc[i] = get_f(&x, i * 2 + cc);
                    bc[i] = get_f(&bb, i * 2 + cc);
                }
                if (residual_ratio(&am, 0, xc, bc, n) > 16.0){
                    f_solve++;
                    break;
                }
            }
        }
        nd_release(&res); nd_release(&ref); nd_release(&bb); nd_release(&x); nd_release(&ba);
    }
    check(f_fact == 0,
            "nd_cholesky: 400 random SPD (C, F, strided), lower and upper: L L^T = A / U^T U = A");
    check(f_zero == 0, "nd_cholesky: the other triangle is exactly zero");
    check(f_garb == 0,
            "nd_cholesky reads only the chosen triangle (NaN in the other one changes nothing)");
    check(f_solve == 0, "nd_cho_solve: A x = b with the Cholesky factor, small residual");
    (void)f_notpd;

    // not positive definite
    {
        double ind[4] = {1, 2, 2, 1}, neg[4] = {-1, 0, 0, 1};
        ndarr_t a = {0}, r = {0};
        int64_t s22[2] = {2, 2};
        make_from(2, s22, ND_LAYOUT_C, ind, &a);
        check(nd_cholesky(NULL, &a, 1, &r) == OTI_ERR_NOTPD && r.buf == NULL,
                "cholesky of [[1,2],[2,1]] -> NOTPD, res empty");
        check(nd_cholesky(NULL, &a, 0, &r) == OTI_ERR_NOTPD, "upper cholesky of the same -> NOTPD");
        nd_release(&a);
        make_from(2, s22, ND_LAYOUT_C, neg, &a);
        check(nd_cholesky(NULL, &a, 1, &r) == OTI_ERR_NOTPD,
                "cholesky with a negative leading entry -> NOTPD");
        nd_release(&a);
        {
            ndarr_t e = {0}, ns = {0}, v = {0}, u = {0};
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){0, 0}, ND_LAYOUT_C, 0, &e);
            check(nd_cholesky(NULL, &e, 1, &r) == OTI_OK && r.shape[0] == 0 && r.shape[1] == 0,
                    "cholesky of 0 x 0: an empty 0 x 0");
            nd_release(&r);
            nd_release(&e);
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){2, 3}, ND_LAYOUT_C, 0, &ns);
            nd_alloc(NULL, OTI_F64, 1, (int64_t[]){2}, ND_LAYOUT_C, 0, &v);
            nd_alloc(NULL, OTI_U8, 2, s22, ND_LAYOUT_C, 0, &u);
            check(nd_cholesky(NULL, &ns, 1, &r) == OTI_ERR_SHAPE, "cholesky of (2,3) -> SHAPE");
            check(nd_cholesky(NULL, &v, 1, &r) == OTI_ERR_SHAPE, "cholesky of a 1-D array -> SHAPE");
            check(nd_cholesky(NULL, &u, 1, &r) == OTI_ERR_DTYPE, "cholesky of U8 -> DTYPE");
            nd_release(&ns); nd_release(&v); nd_release(&u);
        }
    }
    // a stack
    {
        ndarr_t a = {0}, r = {0};
        int64_t bl, n = 3, i, j, l;
        int ok = 1;
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, n, n}, ND_LAYOUT_C, 0, &a);
        for (bl = 0; bl < 2; bl++){
            ndarr_t one = {0};
            nd_index_t ix[1];
            ix[0].kind = ND_IDX_INT; ix[0].has = 0; ix[0].start = bl;
        ix[0].stop = 0; ix[0].step = 0; ix[0].arr = NULL;
            nd_view_index(&a, 1, ix, &one);
            make_spd(&one, 0);
        }
        check(nd_cholesky(NULL, &a, 1, &r) == OTI_OK && r.ndim == 3 && r.shape[0] == 2,
                "cholesky of a stack (2,3,3)");
        for (bl = 0; bl < 2; bl++){
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    long double s = 0;
                    for (l = 0; l < n; l++){
                        s += (long double)get_f(&r, (bl * n + i) * n + l) * (long double)get_f(&r,
                                (bl * n + j) * n + l);
                    }
                    ok = ok && fabs((double)s - bget(&a, bl, i, j)) <= 1e-13 * (1.0 + fabs(bget(&a, bl, i,
                            j)));
                }
            }
        }
        check(ok, "stacked cholesky: L L^T = A per matrix");
        nd_release(&r);
        nd_release(&a);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_solve_triangular(void){

    int iter, fails = 0, f_garb = 0;
    int combo;

    rng_seed(1976);
    for (iter = 0; iter < 800; iter++){
        int64_t n = 1 + rng_int(8), k = 1 + rng_int(3), i, j, l, c;
        int lower, trans, unit;
        int kind = (int)rng_int(3), vec = (int)rng_int(3) == 0;
        ndarr_t bt = {0}, t = {0}, b = {0}, x = {0};
        int64_t sh[2], bsh[2];
        double tt[12 * 12], sol_ref[12], rhs[12];

        combo = iter % 8;
        lower = combo & 1;
        trans = (combo >> 1) & 1;
        unit = (combo >> 2) & 1;
        sh[0] = sh[1] = n;
        make_view(2, sh, kind, OTI_F64, &bt, &t);
        // random triangular data with a dominant diagonal; NaN garbage in the other triangle (and on the
        // diagonal when it is unit)
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                int inside = lower ? (j <= i) : (j >= i);
                double v;
                if (!inside){
                    v = NAN;
                } else if (i == j){
                    v = unit ? NAN : ((rng_int(2) ? 1.0 : -1.0) * (2.0 + rng_uniform()));
                } else {
                    v = (rng_uniform() - 0.5);
                }
                set_f(&t, i * n + j, v);
                tt[i * n + j] = inside ? (i == j ? (unit ? 1.0 : v) : v) : 0.0;
            }
        }
        if (vec){
            bsh[0] = n;
            nd_alloc(NULL, OTI_F64, 1, bsh, ND_LAYOUT_C, 0, &b);
            k = 1;
        } else {
            bsh[0] = n; bsh[1] = k;
            nd_alloc(NULL, OTI_F64, 2, bsh, ND_LAYOUT_C, 0, &b);
        }
        fill_random_small(&b);
        if (nd_solve_triangular(NULL, &t, &b, lower, trans, unit, &x) != OTI_OK ||
            x.ndim != b.ndim || x.shape[0] != n){
            fails++;
            nd_release(&bt); nd_release(&b);
            continue;
        }
        for (c = 0; c < k; c++){
            long double xr[12];
            for (i = 0; i < n; i++){
                rhs[i] = vec ? get_f(&b, i) : get_f(&b, i * k + c);
            }
            // reference substitution on op(T)
            if (!trans ? lower : !lower){
                for (i = 0; i < n; i++){
                    long double s = rhs[i];
                    for (l = 0; l < i; l++){
                        s -= (long double)(trans ? tt[l * n + i] : tt[i * n + l]) * xr[l];
                    }
                    xr[i] = s / (long double)(trans ? tt[i * n + i] : tt[i * n + i]);
                }
            } else {
                for (i = n - 1; i >= 0; i--){
                    long double s = rhs[i];
                    for (l = i + 1; l < n; l++){
                        s -= (long double)(trans ? tt[l * n + i] : tt[i * n + l]) * xr[l];
                    }
                    xr[i] = s / (long double)tt[i * n + i];
                }
            }
            for (i = 0; i < n; i++){
                double got = vec ? get_f(&x, i) : get_f(&x, i * k + c);
                sol_ref[i] = (double)xr[i];
                if (!(fabs(got - sol_ref[i]) <= 1e-10 * (1.0 + fabs(sol_ref[i])))){
                    fails++;
                    if (fails < 4){
                        fprintf(stderr,
                                "  trisolve %d lo %d tr %d un %d: x[%lld] = %.17g want %.17g\n", iter,
                                lower, trans, unit, (long long)i, got, sol_ref[i]);
                    }
                    i = n;
                    c = k;
                }
            }
        }
        (void)f_garb;
        nd_release(&bt); nd_release(&b); nd_release(&x);
    }
    check(fails == 0,
            "nd_solve_triangular: 800 random cases, all 8 flag combinations, NaN in the unused part");

    // exactly zero diagonal entry: positive info; unit_diagonal ignores it
    {
        double tz[9] = {1, 0, 0, 2, 0, 0, 3, 4, 5};      // lower with T(2,2) = 0 (1-based index 2)
        ndarr_t t = {0}, b = {0}, x = {0};
        make_from(2, (int64_t[]){3, 3}, ND_LAYOUT_C, tz, &t);
        make_from(1, (int64_t[]){3}, ND_LAYOUT_C, (double[]){1, 1, 1}, &b);
        check(nd_solve_triangular(NULL, &t, &b, 1, 0, 0, &x) == 2 && x.buf == NULL,
              "solve_triangular with a zero diagonal entry T(2,2): info 2 (positive)");
        check(nd_solve_triangular(NULL, &t, &b, 1, 0, 1, &x) == OTI_OK,
                "unit_diagonal ignores the zero diagonal");
        nd_release(&x);
        nd_release(&t); nd_release(&b);
    }
    // errors and empties
    {
        ndarr_t t = {0}, b = {0}, x = {0}, u = {0};
        double iv[4] = {1, 0, 0, 1};
        make_from(2, (int64_t[]){2, 2}, ND_LAYOUT_C, iv, &t);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){3}, ND_LAYOUT_C, 0, &b);
        nd_alloc(NULL, OTI_U8, 1, (int64_t[]){2}, ND_LAYOUT_C, 0, &u);
        check(nd_solve_triangular(NULL, &t, &b, 1, 0, 0, &x) == OTI_ERR_SHAPE,
                "solve_triangular with b of length 3 for 2 x 2: SHAPE");
        check(nd_solve_triangular(NULL, &t, &u, 1, 0, 0, &x) == OTI_ERR_DTYPE,
                "solve_triangular with U8 b: DTYPE");
        nd_release(&b); nd_release(&u); nd_release(&t);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){0, 0}, ND_LAYOUT_C, 0, &t);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){0}, ND_LAYOUT_C, 0, &b);
        check(nd_solve_triangular(NULL, &t, &b, 1, 0, 0, &x) == OTI_OK && x.shape[0] == 0,
                "solve_triangular of 0 x 0: an empty result");
        nd_release(&x); nd_release(&t); nd_release(&b);
    }
    // cho_solve errors
    {
        ndarr_t c = {0}, b = {0}, x = {0};
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){2, 2}, ND_LAYOUT_C, ND_ALLOC_ZERO, &c);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){3}, ND_LAYOUT_C, 0, &b);
        check(nd_cho_solve(NULL, &c, 1, &b, &x) == OTI_ERR_SHAPE && x.buf == NULL,
                "cho_solve with b of length 3 for 2 x 2: SHAPE");
        nd_release(&c); nd_release(&b);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// W2 fix 1, checker 3: the broadcast batch count of nd_solve is checked.
static void test_fix1_solve_overflow(void){

    static double mem[1] = {1.0};
    ndarr_t a = {0}, b = {0}, r = {0};
    int64_t sa[4] = {INT64_C(1) << 32, 1, 1, 1};
    int64_t sb[4] = {1, INT64_C(1) << 32, 1, 1};
    int64_t z[4] = {0, 0, 0, 0};
    int st1, st2;

    st1 = nd_wrap_trusted(mem, OTI_F64, 4, sa, z, 0, &a);
    st2 = nd_wrap_trusted(mem, OTI_F64, 4, sb, z, 0, &b);
    check(st1 == OTI_OK && st2 == OTI_OK,
            "fix1.3: zero-stride read-only (2^32,1,1,1) and (1,2^32,1,1) wrap");
    if (st1 == OTI_OK && st2 == OTI_OK){
        nd_init_empty(&r);
        check(nd_solve(NULL, &a, &b, &r) == OTI_ERR_SIZE && r.buf == NULL,
              "fix1.3: the broadcast batch count 2^64 overflows: SIZE, res empty (no signed overflow)");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// W2 fix 1, critic 2 / S29: stacked nd_lu_factor, nd_lu_solve_to, nd_solve_to, nd_cho_solve_to,
// nd_solve_triangular_to.
static int arrays_close(const ndarr_t* a, const ndarr_t* b, double rtol){

    int64_t n = shape_size(a->ndim, a->shape), i;
    int32_t k;

    if (a->ndim != b->ndim){
        return 0;
    }
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] != b->shape[k]){
            return 0;
        }
    }
    for (i = 0; i < n; i++){
        double x = get_f(a, i), y = get_f(b, i);
        if (!(fabs(x - y) <= rtol * (1.0 + fabs(y)))){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fix1_stacked_lu(void){

    int64_t n = 4, nb = 3, bl, i, c;
    ndarr_t a = {0}, b = {0}, x = {0}, copy = {0};
    nd_lu_t lu;
    int ok, st;
    int64_t sh[3];

    rng_seed(616);
    sh[0] = nb; sh[1] = n; sh[2] = n;
    nd_alloc(NULL, OTI_F64, 3, sh, ND_LAYOUT_C, 0, &a);
    fill_matrices(&a, 6.0);
    nd_lu_init(&lu);
    st = nd_lu_factor(NULL, &a, 0, &lu);
    check(st == OTI_OK && lu.nbatch == 3 && lu.n == n && lu.info == 0 && lu.infos != NULL &&
            lu.ipiv != NULL,
          "fix1.S29: nd_lu_factor of a (3,4,4) stack: nbatch 3, infos, ipiv");
    check(lu.lu.ndim == 3 && lu.lu.shape[0] == 3 && lu.lu.shape[1] == n && lu.lu.shape[2] == n &&
          lu.lu.strides[1] == 1 && lu.lu.strides[2] == n,
                  "fix1.S29: lu.lu is (3,4,4) with every matrix F (strides (., 1, 4))");
    check(lu.trans == 1, "fix1.S29: a C stack is read as A^T (trans 1), shared by the stack");
    ok = 1;
    for (bl = 0; bl < nb; bl++){
        ok = ok && lu.infos[bl] == 0;
    }
    check(ok, "fix1.S29: infos are all 0 for non-singular matrices");
    nd_alloc(NULL, OTI_F64, 3, (int64_t[]){nb, n, 2}, ND_LAYOUT_C, 0, &b);
    fill_random_small(&b);
    check(nd_lu_solve(NULL, &lu, &b, &x) == OTI_OK && x.ndim == 3 && x.shape[0] == 3 && x.shape[2] == 2,
          "fix1.S29: nd_lu_solve with the stacked factors and a (3,4,2) b");
    ok = 1;
    for (bl = 0; bl < nb; bl++){
        for (c = 0; c < 2; c++){
            double xc[8], bc[8];
            for (i = 0; i < n; i++){
                xc[i] = get_f(&x, (bl * n + i) * 2 + c);
                bc[i] = get_f(&b, (bl * n + i) * 2 + c);
            }
            ok = ok && residual_ratio(&a, bl, xc, bc, n) < 16.0;
        }
    }
    check(ok, "fix1.S29: every matrix of the stack solved (small residuals)");
    nd_release(&x);
    nd_release(&b);
    nd_lu_free(&lu);
    check(lu.infos == NULL && lu.ipiv == NULL && lu.nbatch == 0,
            "fix1.S29: nd_lu_free clears infos and the batch count");

    // singular matrices in the stack: infos tell which; status = the first positive in C order
    nd_copy(NULL, &a, ND_LAYOUT_C, &copy);
    for (i = 0; i < n; i++){
        set_f(&copy, 1 * n * n + i * n + 0, 0.0);          // matrix 1 singular
        set_f(&copy, 2 * n * n + 0 * n + i, 0.0);          // matrix 2 singular, found at another pivot
    }
    nd_lu_init(&lu);
    st = nd_lu_factor(NULL, &copy, 0, &lu);
    check(st > 0 && lu.info == st && lu.infos[0] == 0 && lu.infos[1] > 0 && lu.infos[2] > 0 &&
            lu.infos[1] == st,
          "fix1.S29: stack with singular matrices 1 and 2: status = infos[1], infos[0] = 0");
    check(lu.infos[1] != lu.infos[2], "fix1.S29: the two singular matrices have different infos");
    {
        ndarr_t bb = {0}, xx = {0};
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){n}, ND_LAYOUT_C, ND_ALLOC_ZERO, &bb);
        check(nd_lu_solve(NULL, &lu, &bb, &xx) == lu.info && xx.buf == NULL,
                "fix1.S29: solving with info > 0 returns lu.info");
        nd_release(&bb);
    }
    nd_lu_free(&lu);
    nd_release(&copy);

    // overwrite on a stack of C matrices: in place; a stack of strided matrices: from a copy
    nd_copy(NULL, &a, ND_LAYOUT_C, &copy);
    nd_lu_init(&lu);
    check(nd_lu_factor(NULL, &copy, 1, &lu) == OTI_OK && lu.lu.data == copy.data && lu.nbatch == 3,
          "fix1.S29: overwrite = 1 of a C stack factors in place");
    nd_lu_free(&lu);
    nd_release(&copy);
    {
        ndarr_t bs = {0}, vs = {0};
        nd_index_t ix[3];
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){3, n, 2 * n}, ND_LAYOUT_C, 0, &bs);
        ix[0] = mk_slice(0, 0, 0, 0);
        ix[1] = mk_slice(0, 0, 0, 0);
        ix[2] = mk_slice(HP, 0, n, 0);
        nd_view_index(&bs, 3, ix, &vs);                      // each matrix has a padded leading dimension
        fill_matrices(&vs, 6.0);
        nd_lu_init(&lu);
        st = nd_lu_factor(NULL, &vs, 0, &lu);
        check(st == OTI_OK && lu.nbatch == 3, "fix1.S29: a stack of padded matrices factors");
        nd_lu_free(&lu);
        nd_release(&bs);
    }
    // errors
    {
        ndarr_t ns = {0};
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, 3, 4}, ND_LAYOUT_C, 0, &ns);
        nd_lu_init(&lu);
        check(nd_lu_factor(NULL, &ns, 0, &lu) == OTI_ERR_SHAPE && lu.nbatch == 0,
                "fix1.S29: a (2,3,4) stack -> SHAPE");
        nd_lu_free(&lu);
        nd_release(&ns);
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fix1_lu_solve_to(void){

    int64_t n = 5, k = 3, i, j, c;
    ndarr_t a = {0}, b = {0}, ref = {0}, out = {0}, bo = {0}, vo = {0};
    nd_lu_t lu;
    oti_ctx tiny;
    int ok;

    rng_seed(8484);
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_F, 0, &a);
    fill_matrices(&a, 6.0);
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_F, 0, &b);
    fill_random_small(&b);
    nd_lu_init(&lu);
    nd_lu_factor(NULL, &a, 0, &lu);
    nd_lu_solve(NULL, &lu, &b, &ref);

    // separate out in several layouts (F, C, strided / reversed through make_view)
    for (c = 0; c < 6; c++){
        int kind = (int)(c % 3);
        int64_t osh[2];
        osh[0] = n; osh[1] = k;
        make_view(2, osh, kind, OTI_F64, &bo, &vo);
        ok = nd_lu_solve_to(NULL, &lu, &b, &vo) == OTI_OK && arrays_close(&vo, &ref, 1e-12);
        check(ok, "fix1.S29: nd_lu_solve_to into an out of kind C / F / strided equals nd_lu_solve");
        nd_release(&bo);
    }
    // in place: b == out, an F matrix: no pack (a 1-byte temp budget still works) and the same memory
    {
        ndarr_t bc = {0};
        void* before;
        nd_copy(NULL, &b, ND_LAYOUT_F, &bc);
        before = bc.data;
        oti_ctx_init(&tiny);
        tiny.max_temp_bytes = 1;
        check(nd_lu_solve_to(&tiny, &lu, &bc, &bc) == OTI_OK && bc.data == before && arrays_close(&bc,
                &ref, 1e-12),
              "fix1.S29: nd_lu_solve_to with b == out (F) solves in place, no pack (1-byte temp budget)");
        nd_release(&bc);
        // through a pack: b == out with negative row stride needs a pack, so the same budget refuses it
        {
            ndarr_t bb = {0}, vb = {0};
            nd_index_t ix[2];
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &bb);
            ix[0] = mk_slice(HT, 0, 0, -1);
            ix[1] = mk_slice(0, 0, 0, 0);
            nd_view_index(&bb, 2, ix, &vb);
            for (i = 0; i < n; i++){
                for (j = 0; j < k; j++){
                    set_f(&vb, i * k + j, get_f(&b, i * k + j));
                }
            }
            check(nd_lu_solve_to(&tiny, &lu, &vb, &vb) == OTI_ERR_MEMORY,
                  "fix1.S29: in place on a reversed out needs a pack: a 1-byte budget -> MEMORY");
            for (i = 0; i < n; i++){
                for (j = 0; j < k; j++){
                    set_f(&vb, i * k + j, get_f(&b, i * k + j));
                }
            }
            check(nd_lu_solve_to(NULL, &lu, &vb, &vb) == OTI_OK && arrays_close(&vb, &ref, 1e-12),
                  "fix1.S29: ... with the default budget the in-place solve through a pack is correct");
            nd_release(&bb);
        }
    }
    // the vector form in place
    {
        ndarr_t v = {0}, rv = {0};
        double vv[5];
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){n}, ND_LAYOUT_C, 0, &v);
        fill_random_small(&v);
        for (i = 0; i < n; i++){
            vv[i] = get_f(&v, i);
        }
        nd_lu_solve(NULL, &lu, &v, &rv);
        check(nd_lu_solve_to(NULL, &lu, &v, &v) == OTI_OK && arrays_close(&v, &rv, 1e-12),
              "fix1.S29: nd_lu_solve_to of a vector in place");
        nd_release(&v); nd_release(&rv);
    }
    // errors
    {
        ndarr_t wrong = {0}, d = {0}, ro = {0}, ov = {0};
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k + 1}, ND_LAYOUT_F, 0, &wrong);
        check(nd_lu_solve_to(NULL, &lu, &b, &wrong) == OTI_ERR_SHAPE,
                "fix1.S29: out of the wrong shape -> SHAPE");
        nd_release(&wrong);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_F, 0, &out);
        make_desc(&d, out.data, OTI_F64, 2, (int64_t[]){n, k}, out.strides, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        check(nd_lu_solve_to(NULL, &lu, &b, &ro) == OTI_ERR_READONLY,
                "fix1.S29: read-only out -> READONLY");
        nd_release(&ro);
        make_desc(&d, out.data, OTI_F64, 2, (int64_t[]){n, k}, (int64_t[]){0, 1}, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
        check(nd_lu_solve_to(NULL, &lu, &b, &ov) == OTI_ERR_LAYOUT,
                "fix1.S29: out with internal overlap -> LAYOUT");
        nd_release(&ov);
        // out overlapping the factors
        {
            ndarr_t over = lu.lu;
            over.flags &= ~ND_RETAINED;
            over.shape[1] = k;
            nd_update_flags(&over);
            check(nd_lu_solve_to(NULL, &lu, &b, &over) == OTI_ERR_LAYOUT,
                    "fix1.S29: out overlapping lu.lu -> LAYOUT");
        }
        nd_release(&out);
    }
    nd_lu_free(&lu);
    nd_release(&a); nd_release(&b); nd_release(&ref);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fix1_solve_to_family(void){

    int64_t n = 5, k = 3, i;
    ndarr_t a = {0}, b = {0}, ref = {0}, out = {0};
    int ok, iter;

    rng_seed(6502);
    // nd_solve_to: separate out, out == b, out == a (square), stacks
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_C, 0, &a);
    fill_matrices(&a, 6.0);
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &b);
    fill_random_small(&b);
    nd_solve(NULL, &a, &b, &ref);
    nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &out);
    check(nd_solve_to(NULL, &a, &b, &out) == OTI_OK && arrays_close(&out, &ref, 1e-12),
            "fix1.S29: nd_solve_to equals nd_solve");
    {
        ndarr_t bc = {0};
        nd_copy(NULL, &b, ND_LAYOUT_C, &bc);
        check(nd_solve_to(NULL, &a, &bc, &bc) == OTI_OK && arrays_close(&bc, &ref, 1e-12),
              "fix1.S29: nd_solve_to with out == b (in place)");
        nd_release(&bc);
    }
    nd_release(&out);
    nd_release(&ref);
    nd_release(&b);
    // out overlapping a: a (n,n) and b (n,n); the result is written over a, which is factored first
    {
        ndarr_t aa = {0}, bb = {0}, r2 = {0};
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_C, 0, &bb);
        fill_random_small(&bb);
        nd_copy(NULL, &a, ND_LAYOUT_C, &aa);
        nd_solve(NULL, &a, &bb, &r2);
        check(nd_solve_to(NULL, &aa, &bb, &aa) == OTI_OK && arrays_close(&aa, &r2, 1e-12),
              "fix1.S29: nd_solve_to with out == a: A is factored into a private buffer first");
        nd_release(&aa); nd_release(&bb); nd_release(&r2);
    }
    // stacks with broadcasting
    {
        ndarr_t sa = {0}, sb = {0}, sr = {0}, so = {0};
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){3, n, n}, ND_LAYOUT_C, 0, &sa);
        fill_matrices(&sa, 6.0);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &sb);
        fill_random_small(&sb);
        nd_solve(NULL, &sa, &sb, &sr);
        nd_alloc(NULL, OTI_F64, 3, (int64_t[]){3, n, k}, ND_LAYOUT_C, 0, &so);
        check(nd_solve_to(NULL, &sa, &sb, &so) == OTI_OK && arrays_close(&so, &sr, 1e-12),
              "fix1.S29: nd_solve_to of a stack with a shared b into (3,5,3)");
        {
            ndarr_t wr = {0};
            nd_alloc(NULL, OTI_F64, 3, (int64_t[]){2, n, k}, ND_LAYOUT_C, 0, &wr);
            check(nd_solve_to(NULL, &sa, &sb, &wr) == OTI_ERR_SHAPE,
                    "fix1.S29: nd_solve_to into (2,5,3) for a 3-stack -> SHAPE");
            nd_release(&wr);
        }
        nd_release(&sa); nd_release(&sb); nd_release(&sr); nd_release(&so);
    }
    // singular: positive status
    {
        double z[4] = {1, 2, 2, 4};
        ndarr_t sg = {0}, bv = {0}, ov = {0};
        make_from(2, (int64_t[]){2, 2}, ND_LAYOUT_C, z, &sg);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){2}, ND_LAYOUT_C, ND_ALLOC_ZERO, &bv);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){2}, ND_LAYOUT_C, 0, &ov);
        check(nd_solve_to(NULL, &sg, &bv, &ov) == 2,
                "fix1.S29: nd_solve_to of a singular matrix: info 2");
        nd_release(&sg); nd_release(&bv); nd_release(&ov);
    }
    nd_release(&a);

    // nd_cho_solve_to
    for (iter = 0; iter < 2; iter++){
        int lower = iter;
        ndarr_t spd = {0}, fac = {0}, cb = {0}, cr = {0}, co = {0};
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_C, 0, &spd);
        make_spd(&spd, 0);
        nd_cholesky(NULL, &spd, lower, &fac);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &cb);
        fill_random_small(&cb);
        nd_cho_solve(NULL, &fac, lower, &cb, &cr);
        nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &co);
        ok = nd_cho_solve_to(NULL, &fac, lower, &cb, &co) == OTI_OK && arrays_close(&co, &cr, 1e-12);
        check(ok, "fix1.S29: nd_cho_solve_to equals nd_cho_solve (lower and upper)");
        {
            ndarr_t bc = {0};
            nd_copy(NULL, &cb, ND_LAYOUT_C, &bc);
            check(nd_cho_solve_to(NULL, &fac, lower, &bc, &bc) == OTI_OK && arrays_close(&bc, &cr, 1e-12),
                  "fix1.S29: nd_cho_solve_to with out == b");
            nd_release(&bc);
        }
        // the factor overlapping out (n x n right-hand sides stored over the factor)
        {
            ndarr_t bb2 = {0}, ff = {0}, r3 = {0};
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_C, 0, &bb2);
            fill_random_small(&bb2);
            nd_copy(NULL, &fac, ND_LAYOUT_C, &ff);
            nd_cho_solve(NULL, &fac, lower, &bb2, &r3);
            check(nd_cho_solve_to(NULL, &ff, lower, &bb2, &ff) == OTI_OK && arrays_close(&ff, &r3, 1e-12),
                  "fix1.S29: nd_cho_solve_to with out == c: the factor is copied first");
            nd_release(&bb2); nd_release(&ff); nd_release(&r3);
        }
        {
            ndarr_t wr = {0};
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k + 1}, ND_LAYOUT_C, 0, &wr);
            check(nd_cho_solve_to(NULL, &fac, lower, &cb, &wr) == OTI_ERR_SHAPE,
                    "fix1.S29: cho_solve_to wrong out -> SHAPE");
            nd_release(&wr);
        }
        nd_release(&spd); nd_release(&fac); nd_release(&cb); nd_release(&cr); nd_release(&co);
    }

    // nd_solve_triangular_to over all flag combinations
    {
        int combo, okc = 1, okin = 1, okov = 1;
        for (combo = 0; combo < 8; combo++){
            int lower = combo & 1, trans = (combo >> 1) & 1, unit = (combo >> 2) & 1;
            ndarr_t t = {0}, tb = {0}, tr = {0}, to = {0};
            int64_t j;
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_C, 0, &t);
            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                    int inside = lower ? j <= i : j >= i;
                    double v = inside ? ((i == j) ? 3.0 + rng_uniform() : rng_uniform() - 0.5) : NAN;
                    set_f(&t, i * n + j, v);
                }
            }
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &tb);
            fill_random_small(&tb);
            nd_solve_triangular(NULL, &t, &tb, lower, trans, unit, &tr);
            nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, k}, ND_LAYOUT_C, 0, &to);
            okc = okc && nd_solve_triangular_to(NULL, &t, &tb, lower, trans, unit, &to) == OTI_OK &&
                  arrays_close(&to, &tr, 1e-12);
            {
                ndarr_t bc = {0};
                nd_copy(NULL, &tb, ND_LAYOUT_C, &bc);
                okin = okin && nd_solve_triangular_to(NULL, &t, &bc, lower, trans, unit, &bc) == OTI_OK &&
                       arrays_close(&bc, &tr, 1e-12);
                nd_release(&bc);
            }
            {
                // T overlapping out: the right-hand sides are (n, n) and stored over T's memory
                ndarr_t tt = {0}, bb2 = {0}, r4 = {0};
                nd_copy(NULL, &t, ND_LAYOUT_C, &tt);
                nd_alloc(NULL, OTI_F64, 2, (int64_t[]){n, n}, ND_LAYOUT_C, 0, &bb2);
                fill_random_small(&bb2);
                nd_solve_triangular(NULL, &t, &bb2, lower, trans, unit, &r4);
                okov = okov && nd_solve_triangular_to(NULL, &tt, &bb2, lower, trans, unit,
                        &tt) == OTI_OK &&
                       arrays_close(&tt, &r4, 1e-12);
                nd_release(&tt); nd_release(&bb2); nd_release(&r4);
            }
            nd_release(&t); nd_release(&tb); nd_release(&tr); nd_release(&to);
        }
        check(okc,
                "fix1.S29: nd_solve_triangular_to equals nd_solve_triangular, all 8 flag combinations");
        check(okin, "fix1.S29: nd_solve_triangular_to with out == b (in place), all 8 combinations");
        check(okov,
                "fix1.S29: nd_solve_triangular_to with out == t: T is copied first, all 8 combinations");
    }
    // singular triangle: positive info
    {
        double tz[9] = {1, 0, 0, 2, 0, 0, 3, 4, 5};
        ndarr_t t = {0}, bb = {0}, oo = {0};
        make_from(2, (int64_t[]){3, 3}, ND_LAYOUT_C, tz, &t);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){3}, ND_LAYOUT_C, ND_ALLOC_ZERO, &bb);
        nd_alloc(NULL, OTI_F64, 1, (int64_t[]){3}, ND_LAYOUT_C, 0, &oo);
        check(nd_solve_triangular_to(NULL, &t, &bb, 1, 0, 0, &oo) == 2,
                "fix1.S29: solve_triangular_to with a zero diagonal: info 2");
        nd_release(&t); nd_release(&bb); nd_release(&oo);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// W2 fix 2, checker 8: ipiv + infos (and the factor buffer of the copy branch) are charged to the temp
// budget
// before anything is retained, allocated or factored.
static void test_fix2_lu_budget(void){

    ndarr_t a = {0};
    nd_lu_t lu;
    oti_ctx ctx;
    int64_t i;
    int64_t sh[3] = {100, 1, 1};

    nd_alloc(NULL, OTI_F64, 3, sh, ND_LAYOUT_C, 0, &a);
    for (i = 0; i < 100; i++){
        set_f(&a, i, 2.0 + (double)i);
    }
    oti_ctx_init(&ctx);

    // overwrite = 1, in place: (100 + 100) * sizeof(int) = 800 bytes of ipiv + infos
    {
        int64_t budgets[2] = {1, 799};
        int b;
        for (b = 0; b < 2; b++){
            ctx.max_temp_bytes = budgets[b];
            nd_lu_init(&lu);
            check(nd_lu_factor(&ctx, &a, 1, &lu) == OTI_ERR_MEMORY && lu.lu.buf == NULL &&
                    lu.ipiv == NULL &&
                  lu.infos == NULL && nd_buffer_refs(a.buf) == 1,
                  "fix2.8: overwrite of (100,1,1) under 800 bytes -> MEMORY, lu empty, no retain");
            nd_lu_free(&lu);
        }
        ctx.max_temp_bytes = 800;
        nd_lu_init(&lu);
        check(nd_lu_factor(&ctx, &a, 1, &lu) == OTI_OK && lu.lu.data == a.data && lu.nbatch == 100 &&
              nd_buffer_refs(a.buf) == 2, "fix2.8: exactly 800 bytes: OK, in place, nbatch 100, refs 2");
        nd_lu_free(&lu);
        check(nd_buffer_refs(a.buf) == 1, "fix2.8: nd_lu_free releases the retained input");
    }

    // the copy branch: 800 + 100 * 8 = 1600 bytes
    for (i = 0; i < 100; i++){
        set_f(&a, i, 2.0 + (double)i);
    }
    ctx.max_temp_bytes = 1599;
    nd_lu_init(&lu);
    check(nd_lu_factor(&ctx, &a, 0, &lu) == OTI_ERR_MEMORY && lu.lu.buf == NULL && lu.ipiv == NULL &&
            lu.infos == NULL,
          "fix2.8: the copy branch of the same stack with 1599 bytes -> MEMORY, lu empty");
    nd_lu_free(&lu);
    ctx.max_temp_bytes = 1600;
    nd_lu_init(&lu);
    check(nd_lu_factor(&ctx, &a, 0, &lu) == OTI_OK && lu.nbatch == 100 && lu.lu.data != a.data,
          "fix2.8: 1600 bytes: OK, factored from a private copy");
    nd_lu_free(&lu);
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_lu_factor_orientation();
    test_lu_errors_and_singular();
    test_solve_inv_det_random();
    test_solve_vector_and_batches();
    test_det_specials();
    test_empty_makes_no_provider_call();
    test_linalg_fail_alloc();
    test_cholesky();
    test_solve_triangular();

    test_fix1_solve_overflow();

    test_fix1_stacked_lu();
    test_fix1_lu_solve_to();
    test_fix1_solve_to_family();

    test_fix2_lu_budget();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
