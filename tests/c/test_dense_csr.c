/* Checks of the dense OTI sparse matrices (include/oti/dense/csr/csr.h, PLAN-dense-update.md WP7):
 * the triplet builder lilo_t (set overwrites, set_r replaces, add accumulates in place or grows the
 * entry, add_block against repeated add, missing entries, hash growth, copy, statuses), its CSR
 * conversion (row / column order, largest nact and order, explicit zeros kept, empty rows), the CSR
 * pattern check (duplicates and unsorted columns allowed), csro_to_dense, CSR times dense SoA and the
 * order-by-order solve right-hand sides. Oracles:
 *   - the dense SoA equivalents: csro_to_dense() then oarr_matmul_OO_to() (1e-13 relative), and the
 *     block solve built from csro_solve_init() / csro_solve_rhs() plus a real solve per order
 *     against oarr_solve_to() on the dense matrix;
 *   - semi-sparse lilss_t / csrss_t on the same data over the active sets [1..k] (same layout, so
 *     values and patterns compare directly, 1e-14).
 * Cases: K and x with different nact (either larger) and orders, nact 0, unequal act_order, orders
 * 1..5, 0 x 0 and 1 x 1, rectangular K, the k = 11 / order 5 case beyond the global multiplication
 * table (cached local tables, and the rank fallback in a child run with OTI_SS_TABLE_CACHE_MB=0),
 * and an FEM-like 2-D Laplacian assembled with lilo_add_block(). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>
#include <oti/dense.h>

static int n_failed = 0;
static int n_passed = 0;
static int g_verbose = 0;

static uint64_t g_rng_state = 0x5EED0C5A11223344ULL;

static bases_t g_bases[256];

/// Relative tolerance against the dense SoA oracle.
#define TOL_ORACLE 1e-13
/// Relative tolerance against semi-sparse on identical inputs.
#define TOL_SS 1e-14


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){

        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;

    } else {

        n_passed++;

        if (g_verbose){
            printf("passed: %s\n", name);
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A value in (-1, 1), never exactly zero.
static coeff_t rng_value(void){

    g_rng_state = g_rng_state * 6364136223846793005ULL + 1442695040888963407ULL;

    return ((double)(g_rng_state >> 11) / 9007199254740992.0) * 2.0 - 1.0 + 1e-3;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// An integer in [0, n).
static uint64_t rng_index(uint64_t n){

    g_rng_state = g_rng_state * 6364136223846793005ULL + 1442695040888963407ULL;

    return (g_rng_state >> 33) % n;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     BUILDING OPERANDS     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// A dense scalar over bases 1..k at order trc, random coefficients up to order act.
static otinum_t make_num(coeff_t re, bases_t k, ord_t trc, ord_t act){

    otinum_t num = oti_init();
    ord_t p;

    check(oti_create_empty_to(k, trc, &num) == DN_OK, "make_num: status");
    num.re = re;

    for (p = 1; p <= act && p <= trc && k > 0; p++){

        ndir_t n = sshelp_ndir_order(k, p), i, off = sshelp_order_offset(k, p);

        for (i = 0; i < n; i++){
            num.p_im[off + i] = 0.5 * rng_value();
        }

    }

    num.act_order = (k > 0 && act < trc) ? act : ((k > 0) ? trc : 0);

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A dense SoA array over bases 1..k at order trc, random coefficients up to order act.
static oarr_t make_soa(bases_t k, uint64_t nrows, uint64_t ncols, ord_t trc, ord_t act){

    oarr_t arr = oarr_init();
    ord_t p;
    uint64_t e;

    check(oarr_zeros_to(k, nrows, ncols, trc, &arr) == DN_OK, "make_soa: status");

    for (e = 0; e < arr.size; e++){
        arr.p_data[e] = rng_value();
    }

    for (p = 1; p <= act && p <= trc && k > 0; p++){

        size_t n = (size_t)sshelp_ndir_order(k, p) * arr.size, i;
        coeff_t* b0 = arr.p_data + oarr_block_index(k, p, 0) * arr.size;

        for (i = 0; i < n; i++){
            b0[i] = 0.5 * rng_value();
        }

    }

    arr.act_order = (k > 0 && act < trc) ? act : ((k > 0) ? trc : 0);

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Semi-sparse twin of a dense scalar: active set [1..nact], identical coefficients.
static ssotinum_t ss_num(const otinum_t* num){

    ssotinum_t s = ssoti_create_empty(g_bases, num->nact, num->trc_order);
    ndir_t n = sshelp_ndir_total(num->nact, num->trc_order);

    s.re = num->re;

    if (n > 0){
        memcpy(s.p_im, num->p_im, (size_t)n * sizeof(coeff_t));
    }

    s.act_order = num->act_order;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Semi-sparse twin of a dense array: active set [1..nact], identical blocks.
static oarrss_t ss_soa(const oarr_t* arr){

    oarrss_t s = oarrss_zeros(g_bases, arr->nact, arr->nrows, arr->ncols, arr->trc_order);
    size_t n = (size_t)(1 + sshelp_ndir_total(arr->nact, arr->trc_order)) * arr->size;

    if (n > 0){
        memcpy(s.p_data, arr->p_data, n * sizeof(coeff_t));
    }

    s.act_order = arr->act_order;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Two builders filled alike: an n x n system with a dominant diagonal (real on even rows), a band of
// width 2 and two far entries, entries over bases 1..k (a few over fewer bases) at order trc.
static void make_system(uint64_t n, bases_t k, ord_t trc, lilo_t* lil, lilss_t* ss){

    uint64_t i, j;

    *lil = lilo_init(n, n);
    *ss  = lilss_init(n, n);

    for (i = 0; i < n; i++){

        for (j = (i >= 2) ? i - 2 : 0; j <= i + 2 && j < n; j++){

            otinum_t v;
            ssotinum_t sv;
            bases_t kk = (i + j) % 3 == 0 && k > 0 ? (bases_t)(k - 1) : k;

            if (i == j && i % 2 == 0){

                coeff_t r = 10.0 + rng_value();

                check(lilo_set_r(lil, i, j, r) == CSRO_OK, "make_system: set_r");
                lilss_set_r(ss, i, j, r);
                continue;

            }

            v  = make_num((i == j) ? 10.0 + rng_value() : rng_value(), kk, trc, trc);
            sv = ss_num(&v);
            check(lilo_set(lil, i, j, &v) == CSRO_OK, "make_system: set");
            lilss_set(ss, i, j, &sv);
            ssoti_free(&sv);
            oti_free(&v);

        }

    }

    if (n > 3){

        otinum_t v = make_num(0.3, (k > 0) ? 1 : 0, trc, trc);
        ssotinum_t sv = ss_num(&v);

        lilo_set(lil, 0, n - 1, &v);
        lilo_set(lil, n - 1, 0, &v);
        lilss_set(ss, 0, n - 1, &sv);
        lilss_set(ss, n - 1, 0, &sv);
        ssoti_free(&sv);
        oti_free(&v);

    }

}
// -------------------------------------------------------------------------------------------------------


/// CSR arrays owned by a test (the csro_t views them).
typedef struct {
    oarr_t        val;
    int64_t*  indices;
    int64_t*   indptr;
    csro_t          K;
} csr_hold_t;


// *******************************************************************************************************
static void to_csr(const lilo_t* lil, csr_hold_t* hp){

    csr_hold_t h;

    h.indices = (int64_t*)malloc((size_t)lil->nnz * sizeof(int64_t) + 1);
    h.indptr  = (int64_t*)malloc((size_t)(lil->nrows + 1) * sizeof(int64_t));
    h.val     = oarr_init();

    check(lilo_to_csr(lil, &h.val, h.indices, h.indptr) == CSRO_OK, "lilo_to_csr: status");

    h.K.p_val     = &h.val;
    h.K.p_indices = h.indices;
    h.K.p_indptr  = h.indptr;
    h.K.nrows     = lil->nrows;
    h.K.ncols     = lil->ncols;

    // The view points at the caller's copy of the values.
    *hp = h;
    hp->K.p_val = &hp->val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void hold_free(csr_hold_t* h){

    oarr_free(&h->val);
    free(h->indices);
    free(h->indptr);

}
// -------------------------------------------------------------------------------------------------------


/// Semi-sparse CSR arrays owned by a test.
typedef struct {
    oarrss_t      val;
    int64_t*  indices;
    int64_t*   indptr;
    csrss_t         K;
} ss_hold_t;


// *******************************************************************************************************
static void to_csr_ss(const lilss_t* lil, ss_hold_t* hp){

    ss_hold_t h;

    h.indices = (int64_t*)malloc((size_t)lil->nnz * sizeof(int64_t) + 1);
    h.indptr  = (int64_t*)malloc((size_t)(lil->nrows + 1) * sizeof(int64_t));
    h.val     = oarrss_init();

    lilss_to_csr(lil, &h.val, h.indices, h.indptr);

    h.K.p_val     = &h.val;
    h.K.p_indices = h.indices;
    h.K.p_indptr  = h.indptr;
    h.K.nrows     = lil->nrows;
    h.K.ncols     = lil->ncols;

    // The view points at the caller's copy of the values.
    *hp = h;
    hp->K.p_val = &hp->val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void ss_hold_free(ss_hold_t* h){

    oarrss_free(&h->val);
    free(h->indices);
    free(h->indptr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     COMPARISONS     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Coefficient of a dense array element: order p direction idx (0 when outside the layout).
static coeff_t soa_coef(const oarr_t* a, uint64_t e, ord_t p, ndir_t idx){

    if (p == 0){
        return a->p_data[e];
    }

    if (p > a->trc_order || idx >= sshelp_ndir_order(a->nact, p)){
        return 0.0;
    }

    return a->p_data[(oarr_block_index(a->nact, p, 0) + idx) * a->size + e];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// max |a - b| / max(1, max |b|) over the union of the two layouts; -1 on a shape mismatch.
static double soa_rel_diff(const oarr_t* a, const oarr_t* b){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order, p;
    double diff = 0.0, scale = 1.0;
    uint64_t e;

    if (a->nrows != b->nrows || a->ncols != b->ncols){
        return -1.0;
    }

    for (e = 0; e < a->size; e++){

        for (p = 0; p <= trc; p++){

            ndir_t n = sshelp_ndir_order(k, p), i;

            for (i = 0; i < n; i++){

                double x = soa_coef(a, e, p, i), y = soa_coef(b, e, p, i);

                diff  = fmax(diff, fabs(x - y));
                scale = fmax(scale, fabs(y));

            }

        }

    }

    return diff / scale;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Dense against semi-sparse: same layout over [1..nact] and p_data within tol (relative to 1).
static void compare_vs_ss(const oarr_t* a, const oarrss_t* s, double tol, const char* ctx){

    size_t n, i, bad = 0;
    char name[256];
    int same = (a->nrows == s->nrows && a->ncols == s->ncols && a->nact == s->nbases
                && a->trc_order == s->trc_order);
    bases_t u;

    for (u = 0; same && u < s->nbases; u++){
        same = (s->p_bases[u] == u + 1);
    }

    if (!same){

        snprintf(name, sizeof(name), "%s: layout (dense nact %u trc %u, ss k %u trc %u)", ctx,
                 (unsigned)a->nact, (unsigned)a->trc_order, (unsigned)s->nbases,
                 (unsigned)s->trc_order);
        check(0, name);
        return;

    }

    n = (size_t)(1 + sshelp_ndir_total(a->nact, a->trc_order)) * a->size;

    for (i = 0; i < n; i++){

        double sc = fmax(1.0, fmax(fabs(a->p_data[i]), fabs(s->p_data[i])));

        if (fabs(a->p_data[i] - s->p_data[i]) > tol * sc){

            if (bad < 5){
                fprintf(stderr, "  mismatch %s at %zu: dense=%.17g ss=%.17g\n", ctx, i, a->p_data[i],
                        s->p_data[i]);
            }

            bad++;

        }

    }

    snprintf(name, sizeof(name), "%s: %zu/%zu reals match semi-sparse", ctx, n - bad, n);
    check(bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Two dense scalars hold the same value (the union of their layouts, exactly).
static int same_value(const otinum_t* a, const otinum_t* b){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order, p;

    if (a->re != b->re){
        return 0;
    }

    for (p = 1; p <= trc; p++){

        ndir_t n = sshelp_ndir_order(k, p), i;

        for (i = 0; i < n; i++){

            if (oti_get_item(i, p, a) != oti_get_item(i, p, b)){
                return 0;
            }

        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Every entry of a dense builder equals the same entry of a semi-sparse builder.
static int lil_matches_ss(const lilo_t* lil, const lilss_t* ss){

    uint64_t e;

    if (lil->nnz != ss->nnz){
        return 0;
    }

    for (e = 0; e < lil->nnz; e++){

        const otinum_t* v = &lil->p_val[e];
        const ssotinum_t* s = lilss_get(ss, lil->p_row[e], lil->p_col[e]);
        ord_t p;

        if (s == NULL || s->re != v->re){
            return 0;
        }

        for (p = 1; p <= v->trc_order; p++){

            ndir_t n = sshelp_ndir_order(v->nact, p), i;

            for (i = 0; i < n; i++){

                if (fabs(ssoti_get_item(i, p, s) - oti_get_item(i, p, v)) > 1e-15){
                    return 0;
                }

            }

        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Solves the real system A X = B in place (A n x n column-major, overwritten; B n x nrhs column-major)
// by Gaussian elimination with partial pivoting.
static void real_solve(double* A, uint64_t n, double* B, uint64_t nrhs){

    uint64_t c, r, i, j;

    for (c = 0; c < n; c++){

        uint64_t piv = c;

        for (r = c + 1; r < n; r++){

            if (fabs(A[r + c * n]) > fabs(A[piv + c * n])){
                piv = r;
            }

        }

        if (piv != c){

            for (j = 0; j < n; j++){

                double t = A[c + j * n];

                A[c + j * n]   = A[piv + j * n];
                A[piv + j * n] = t;

            }

            for (j = 0; j < nrhs; j++){

                double t = B[c + j * n];

                B[c + j * n]   = B[piv + j * n];
                B[piv + j * n] = t;

            }

        }

        for (r = c + 1; r < n; r++){

            double f = A[r + c * n] / A[c + c * n];

            for (j = c; j < n; j++){
                A[r + j * n] -= f * A[c + j * n];
            }

            for (j = 0; j < nrhs; j++){
                B[r + j * n] -= f * B[c + j * n];
            }

        }

    }

    for (j = 0; j < nrhs; j++){

        for (i = n; i > 0; i--){

            double s = B[(i - 1) + j * n];

            for (c = i; c < n; c++){
                s -= A[(i - 1) + c * n] * B[c + j * n];
            }

            B[(i - 1) + j * n] = s / A[(i - 1) + (i - 1) * n];

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Block solve of K u = b through csro_solve_init() / csro_solve_rhs(), the real systems solved with
// real_solve() on the dense real part of K.
static oarr_t block_solve(const csro_t* K, const oarr_t* b, dhelpl_t dhl){

    oarr_t u = oarr_init(), dense = oarr_init();
    uint64_t n = K->nrows, m = b->ncols;
    double* A = (double*)malloc((size_t)(n * n) * sizeof(double) + 1);
    ord_t p;

    check(csro_solve_init(K, b, &u) == CSRO_OK, "block solve: init status");
    check(csro_to_dense(K, &dense) == CSRO_OK, "block solve: to_dense status");

    memcpy(A, dense.p_data, (size_t)(n * n) * sizeof(double));
    real_solve(A, n, u.p_data, m);

    for (p = 1; p <= u.trc_order; p++){

        ndir_t Np = sshelp_ndir_order(u.nact, p);

        check(csro_solve_rhs(K, &u, p, dhl) == CSRO_OK, "block solve: rhs status");
        memcpy(A, dense.p_data, (size_t)(n * n) * sizeof(double));
        real_solve(A, n, u.p_data + oarr_block_index(u.nact, p, 0) * u.size, m * Np);

    }

    free(A);
    oarr_free(&dense);

    return u;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The same block solve through the semi-sparse CSR helpers.
static oarrss_t block_solve_ss(const csrss_t* K, const oarrss_t* b, dhelpl_t dhl){

    oarrss_t u = oarrss_init(), dense = oarrss_init();
    uint64_t n = K->nrows, m = b->ncols;
    double* A = (double*)malloc((size_t)(n * n) * sizeof(double) + 1);
    ord_t p;

    csrss_solve_init(K, b, &u);
    csrss_to_dense(K, &dense);

    memcpy(A, dense.p_data, (size_t)(n * n) * sizeof(double));
    real_solve(A, n, u.p_data, m);

    for (p = 1; p <= u.trc_order; p++){

        ndir_t Np = sshelp_ndir_order(u.nbases, p);

        csrss_solve_rhs(K, &u, p, dhl);
        memcpy(A, dense.p_data, (size_t)(n * n) * sizeof(double));
        real_solve(A, n, u.p_data + oarrss_block_index(u.nbases, p, 0) * u.size, m * Np);

    }

    free(A);
    oarrss_free(&dense);

    return u;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRIPLET BUILDER     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_builder_basics(dhelpl_t dhl){

    lilo_t lil = lilo_init(4, 5), cp = lilo_init(1, 1);
    otinum_t a = make_num(1.5, 2, 2, 2), b = make_num(-0.5, 3, 3, 3), sum = oti_init();
    const otinum_t* got;

    check(lilo_get(&lil, 0, 0) == NULL, "get on an empty builder is NULL");
    check(lilo_trc_order(&lil) == 0, "trc_order of an empty builder is 0");

    check(lilo_set(&lil, 1, 2, &a) == CSRO_OK && lil.nnz == 1, "set: new entry");
    got = lilo_get(&lil, 1, 2);
    check(got != NULL && same_value(got, &a) && got->nact == 2 && got->trc_order == 2,
          "get: the stored copy");
    check(lilo_get(&lil, 2, 1) == NULL, "get: missing entry is NULL");

    // Overwrite, not accumulate.
    check(lilo_set(&lil, 1, 2, &b) == CSRO_OK && lil.nnz == 1, "set: overwrite keeps nnz");
    check(same_value(lilo_get(&lil, 1, 2), &b) && lilo_get(&lil, 1, 2)->nact == 3,
          "set: overwrite takes the new value and layout");

    // set_r replaces the entry by a real of order 0.
    check(lilo_set_r(&lil, 1, 2, 4.0) == CSRO_OK, "set_r: status");
    got = lilo_get(&lil, 1, 2);
    check(got->re == 4.0 && got->nact == 0 && got->trc_order == 0 && got->act_order == 0,
          "set_r: real of order 0");

    // add accumulates: onto a real (grows), onto a larger entry (in place), onto a missing entry.
    check(lilo_add(&lil, 1, 2, &a, dhl) == CSRO_OK, "add onto a real: status");
    check(oti_sum_or_to(&a, 4.0, &sum, dhl) == DN_OK && same_value(lilo_get(&lil, 1, 2), &sum),
          "add onto a real: value");
    check(lilo_set(&lil, 3, 4, &b) == CSRO_OK && lilo_add(&lil, 3, 4, &a, dhl) == CSRO_OK,
          "add onto a larger entry: status");
    check(oti_sum_oo_to(&b, &a, &sum, dhl) == DN_OK && same_value(lilo_get(&lil, 3, 4), &sum)
          && lilo_get(&lil, 3, 4)->nact == 3 && lilo_get(&lil, 3, 4)->trc_order == 3,
          "add onto a larger entry: value and layout");
    check(lilo_add(&lil, 0, 0, &b, dhl) == CSRO_OK && same_value(lilo_get(&lil, 0, 0), &b),
          "add onto a missing entry: copy");
    check(lilo_trc_order(&lil) == 3, "trc_order: largest entry order");

    // Out of range.
    check(lilo_set(&lil, 4, 0, &a) == CSRO_ERR_INDEX, "set: row out of range");
    check(lilo_set_r(&lil, 0, 5, 1.0) == CSRO_ERR_INDEX, "set_r: column out of range");
    check(lilo_add(&lil, 9, 9, &a, dhl) == CSRO_ERR_INDEX, "add: out of range");
    check(lil.nnz == 3, "failed calls add no entry");

    // Copy.
    check(lilo_copy_to(&lil, &cp) == CSRO_OK && cp.nnz == 3 && cp.nrows == 4 && cp.ncols == 5,
          "copy_to: shape and entries");
    check(same_value(lilo_get(&cp, 3, 4), lilo_get(&lil, 3, 4))
          && lilo_get(&cp, 3, 4) != lilo_get(&lil, 3, 4), "copy_to: deep copy");
    check(lilo_copy_to(&cp, &cp) == CSRO_OK && cp.nnz == 3, "copy_to: onto itself");

    lilo_free(&lil);
    check(lil.nnz == 0 && lil.nrows == 4 && lilo_get(&lil, 1, 2) == NULL, "free: empty, same shape");
    check(lilo_copy_to(&lil, &cp) == CSRO_OK && cp.nnz == 0, "copy_to: empty builder");

    lilo_free(&cp);
    oti_free(&a); oti_free(&b); oti_free(&sum);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Many entries (hash growth), against a plain dense accumulation.
static void test_builder_many(dhelpl_t dhl){

    uint64_t n = 60, e, i, j;
    lilo_t lil = lilo_init(n, n);
    double* ref = (double*)calloc((size_t)(n * n), sizeof(double));
    uint8_t* has = (uint8_t*)calloc((size_t)(n * n), 1);
    int ok = 1;

    for (e = 0; e < 3000; e++){

        coeff_t v = rng_value();

        i = rng_index(n);
        j = rng_index(n);

        if (e % 3 == 0){

            check(lilo_set_r(&lil, i, j, v) == CSRO_OK, "many: set_r");
            ref[i + j * n] = v;

        } else {

            otinum_t num = make_num(v, 1, 1, 0);

            num.act_order = 0;
            check(lilo_add(&lil, i, j, &num, dhl) == CSRO_OK, "many: add");
            ref[i + j * n] = has[i + j * n] ? ref[i + j * n] + v : v;
            oti_free(&num);

        }

        has[i + j * n] = 1;

    }

    for (i = 0; i < n; i++){

        for (j = 0; j < n; j++){

            const otinum_t* got = lilo_get(&lil, i, j);

            if (has[i + j * n]){
                ok = ok && got != NULL && fabs(got->re - ref[i + j * n]) <= 1e-14;
            } else {
                ok = ok && got == NULL;
            }

        }

    }

    check(ok, "many: every entry matches the accumulation (hash growth)");

    free(ref);
    free(has);
    lilo_free(&lil);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// lilo_add_block against repeated lilo_add (new entries, in-place updates, grown entries, repeated
// rows and columns), and against lilss_add_block.
static void test_add_block(dhelpl_t dhl){

    static const uint64_t rows[3] = {2, 5, 2}, cols[3] = {1, 1, 4};
    ord_t trc;

    for (trc = 1; trc <= 4; trc++){

        lilo_t A = lilo_init(6, 6), B = lilo_init(6, 6);
        lilss_t S = lilss_init(6, 6);
        oarr_t blk = make_soa(3, 3, 3, trc, trc);
        oarrss_t sblk = ss_soa(&blk);
        otinum_t small = make_num(2.0, 1, 1, 1), big = make_num(3.0, 4, (ord_t)(trc + 1), trc);
        otinum_t item = oti_init();
        ssotinum_t ssmall = ss_num(&small), sbig = ss_num(&big);
        uint64_t a, b, e, nnz;
        int round, ok = 1;
        char ctx[128];

        // Pre-existing entries: smaller than the block (grown) and larger (updated in place).
        lilo_set(&A, 2, 1, &small); lilo_set(&B, 2, 1, &small); lilss_set(&S, 2, 1, &ssmall);
        lilo_set(&A, 5, 4, &big);   lilo_set(&B, 5, 4, &big);   lilss_set(&S, 5, 4, &sbig);

        for (round = 0; round < 2; round++){

            check(lilo_add_block(&A, rows, 3, cols, 3, &blk, dhl) == CSRO_OK, "add_block: status");
            check(lilss_add_block(&S, rows, 3, cols, 3, &sblk, dhl) == CSRSS_OK, "ss add_block");

            for (b = 0; b < 3; b++){

                for (a = 0; a < 3; a++){

                    check(oarr_get_item_to(a, b, &blk, &item) == DN_OK, "get_item_to");
                    check(lilo_add(&B, rows[a], cols[b], &item, dhl) == CSRO_OK, "add: status");

                }

            }

        }

        for (e = 0; e < A.nnz; e++){

            const otinum_t* x = lilo_get(&B, A.p_row[e], A.p_col[e]);

            ok = ok && x != NULL && same_value(&A.p_val[e], x) && A.p_val[e].nact == x->nact
                 && A.p_val[e].trc_order == x->trc_order && A.p_val[e].act_order == x->act_order;

        }

        snprintf(ctx, sizeof(ctx), "add_block == repeated add (trc=%u)", (unsigned)trc);
        check(ok && A.nnz == B.nnz, ctx);
        snprintf(ctx, sizeof(ctx), "add_block matches semi-sparse (trc=%u)", (unsigned)trc);
        check(lil_matches_ss(&A, &S), ctx);

        // Failed checks change nothing.
        nnz = A.nnz;
        {
            uint64_t bad_rows[3] = {2, 6, 2};

            check(lilo_add_block(&A, bad_rows, 3, cols, 3, &blk, dhl) == CSRO_ERR_INDEX
                  && A.nnz == nnz, "add_block: row out of range, no change");
            check(lilo_add_block(&A, rows, 2, cols, 3, &blk, dhl) == CSRO_ERR_SIZE && A.nnz == nnz,
                  "add_block: block shape mismatch");
        }

        oti_free(&item); oti_free(&small); oti_free(&big);
        ssoti_free(&ssmall); ssoti_free(&sbig);
        oarrss_free(&sblk); oarr_free(&blk);
        lilo_free(&A); lilo_free(&B); lilss_free(&S);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CSR CONVERSION AND CHECK     ------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_to_csr(dhelpl_t dhl){

    lilo_t lil = lilo_init(4, 5);
    lilss_t ss = lilss_init(4, 5);
    otinum_t v1 = make_num(1.0, 2, 3, 3), v2 = make_num(2.0, 4, 2, 1), z = oti_init();
    ssotinum_t s1 = ss_num(&v1), s2 = ss_num(&v2), sz;
    csr_hold_t h;
    ss_hold_t hs;
    uint64_t t;
    int ok = 1;

    (void)dhl;

    // Unsorted insertion, an explicit OTI zero and a real zero, row 2 empty.
    check(oti_create_empty_to(3, 1, &z) == DN_OK, "zero entry");
    sz = ss_num(&z);
    lilo_set(&lil, 3, 4, &v1); lilss_set(&ss, 3, 4, &s1);
    lilo_set(&lil, 0, 3, &v2); lilss_set(&ss, 0, 3, &s2);
    lilo_set(&lil, 0, 1, &z);  lilss_set(&ss, 0, 1, &sz);
    lilo_set_r(&lil, 3, 0, 0.0); lilss_set_r(&ss, 3, 0, 0.0);
    lilo_set(&lil, 1, 2, &v1); lilss_set(&ss, 1, 2, &s1);

    to_csr(&lil, &h);
    to_csr_ss(&ss, &hs);

    check(h.val.nrows == 5 && h.val.ncols == 1, "to_csr: values are nnz x 1");
    check(h.val.nact == 4 && h.val.trc_order == 3 && h.val.act_order == 3,
          "to_csr: largest nact, order and act_order");
    check(h.indptr[0] == 0 && h.indptr[1] == 2 && h.indptr[2] == 3 && h.indptr[3] == 3
          && h.indptr[4] == 5, "to_csr: indptr (explicit zeros kept, empty row)");
    check(h.indices[0] == 1 && h.indices[1] == 3 && h.indices[2] == 2 && h.indices[3] == 0
          && h.indices[4] == 4, "to_csr: columns sorted within rows");

    for (t = 0; t < 5; t++){
        ok = ok && h.indices[t] == hs.indices[t];
    }

    check(ok, "to_csr: same pattern as semi-sparse");
    compare_vs_ss(&h.val, &hs.val, 0.0, "to_csr values");
    check(csro_check(&h.K) == CSRO_OK, "check: converted matrix is valid");

    // Values of each entry, read back.
    {
        oarr_t dense = oarr_init();
        otinum_t e = oti_init();

        check(csro_to_dense(&h.K, &dense) == CSRO_OK && dense.nrows == 4 && dense.ncols == 5,
              "to_dense: shape");
        check(oarr_get_item_to(3, 4, &dense, &e) == DN_OK && same_value(&e, &v1),
              "to_dense: entry (3,4)");
        check(oarr_get_item_to(0, 3, &dense, &e) == DN_OK && same_value(&e, &v2),
              "to_dense: entry (0,3)");
        check(oarr_get_item_to(2, 2, &dense, &e) == DN_OK && e.re == 0.0, "to_dense: empty row");

        // res may be the matrix's own value array.
        {
            oarr_t cp = oarr_init();
            csro_t K2 = h.K;

            check(oarr_copy_to(&h.val, &cp) == DN_OK, "copy values");
            K2.p_val = &cp;
            check(csro_to_dense(&K2, &cp) == CSRO_OK && soa_rel_diff(&cp, &dense) == 0.0,
                  "to_dense: into the matrix's own value array");
            oarr_free(&cp);
        }

        oti_free(&e);
        oarr_free(&dense);
    }

    // An empty builder.
    {
        lilo_t em = lilo_init(3, 2);
        csr_hold_t he;

        to_csr(&em, &he);

        check(he.val.size == 0 && he.indptr[0] == 0 && he.indptr[3] == 0, "to_csr: empty builder");
        check(csro_check(&he.K) == CSRO_OK, "check: empty matrix");
        hold_free(&he);
        lilo_free(&em);
    }

    hold_free(&h);
    ss_hold_free(&hs);
    ssoti_free(&s1); ssoti_free(&s2); ssoti_free(&sz);
    oti_free(&v1); oti_free(&v2); oti_free(&z);
    lilo_free(&lil);
    lilss_free(&ss);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_check(void){

    int64_t indptr[4] = {0, 2, 2, 4}, indices[4] = {3, 0, 1, 1};
    oarr_t val = make_soa(2, 4, 1, 2, 2), bad = make_soa(2, 2, 2, 2, 2);
    csro_t K;

    K.p_val = &val; K.p_indices = indices; K.p_indptr = indptr; K.nrows = 3; K.ncols = 4;

    check(csro_check(&K) == CSRO_OK, "check: unsorted and duplicate columns are valid");

    indptr[0] = 1;
    check(csro_check(&K) == CSRO_ERR_INDEX, "check: indptr[0] != 0");
    indptr[0] = 0; indptr[1] = 3; indptr[2] = 2;
    check(csro_check(&K) == CSRO_ERR_INDEX, "check: indptr decreasing");
    indptr[1] = 2; indptr[3] = 3;
    check(csro_check(&K) == CSRO_ERR_INDEX, "check: indptr[nrows] != nnz");
    indptr[3] = 4; indices[2] = 4;
    check(csro_check(&K) == CSRO_ERR_INDEX, "check: column out of range");
    indices[2] = -1;
    check(csro_check(&K) == CSRO_ERR_INDEX, "check: negative column");
    indices[2] = 1;
    K.p_val = &bad;
    check(csro_check(&K) == CSRO_ERR_SIZE, "check: values not nnz x 1");

    oarr_free(&val);
    oarr_free(&bad);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MATMUL     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/// Matrix and array: nact, truncation order and act_order of each.
typedef struct { bases_t kK; ord_t tK, aK; bases_t kx; ord_t tx, ax; const char* label; } mm_case_t;


// *******************************************************************************************************
// Cases at an order: equal nact, K or x larger, K or x real, mixed orders, unequal act_order.
static int mm_cases(ord_t trc, mm_case_t* c){

    bases_t k = (trc >= 5) ? 3 : 4;
    ord_t tl = (trc > 1) ? (ord_t)(trc - 1) : 1;
    int n = 0;

    c[n++] = (mm_case_t){ k, trc, trc, k, trc, trc, "equal" };
    c[n++] = (mm_case_t){ k, trc, trc, (bases_t)(k - 2), trc, trc, "K-larger" };
    c[n++] = (mm_case_t){ (bases_t)(k - 2), trc, trc, k, trc, trc, "x-larger" };
    c[n++] = (mm_case_t){ 0, trc, 0, k, trc, trc, "K-real" };
    c[n++] = (mm_case_t){ k, trc, trc, 0, trc, 0, "x-real" };

    if (trc > 1){

        c[n++] = (mm_case_t){ k, tl, tl, (bases_t)(k - 1), trc, trc, "K-lower-order" };
        c[n++] = (mm_case_t){ (bases_t)(k - 1), trc, trc, k, tl, tl, "x-lower-order" };
        c[n++] = (mm_case_t){ k, trc, 1, k, trc, tl, "unequal-act" };

    }

    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills two builders alike with a random nrows x ncols pattern (about half full, one empty row).
static void random_matrix(uint64_t nrows, uint64_t ncols, bases_t k, ord_t trc, ord_t act,
                          lilo_t* lil, lilss_t* ss){

    uint64_t i, j;

    *lil = lilo_init(nrows, ncols);
    *ss  = lilss_init(nrows, ncols);

    for (i = 0; i < nrows; i++){

        if (nrows > 2 && i == 1){
            continue;
        }

        for (j = 0; j < ncols; j++){

            if (rng_index(2) == 0 || i == j){

                otinum_t v = make_num(rng_value(), k, trc, act);
                ssotinum_t s = ss_num(&v);

                lilo_set(lil, i, j, &v);
                lilss_set(ss, i, j, &s);
                ssoti_free(&s);
                oti_free(&v);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    static const struct { uint64_t n, m, p; } SHAPES[] = { {5, 5, 1}, {5, 5, 3}, {4, 6, 2}, {1, 1, 1},
                                                            {3, 2, 4} };
    mm_case_t mc[8];
    size_t sh;
    ord_t trc;
    int c, nc;

    for (trc = 1; trc <= 5; trc++){

        nc = mm_cases(trc, mc);

        for (c = 0; c < nc; c++){

            for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

                lilo_t lil;
                lilss_t ss;
                csr_hold_t h;
                ss_hold_t hs;
                oarr_t x, xs_d = oarr_init(), dense = oarr_init(), ref = oarr_init(), res = oarr_init();
                oarrss_t xs, rs = oarrss_init();
                char ctx[160];
                double d;

                random_matrix(SHAPES[sh].n, SHAPES[sh].m, mc[c].kK, mc[c].tK, mc[c].aK, &lil, &ss);
                to_csr(&lil, &h);
                to_csr_ss(&ss, &hs);
                x  = make_soa(mc[c].kx, SHAPES[sh].m, SHAPES[sh].p, mc[c].tx, mc[c].ax);
                xs = ss_soa(&x);

                snprintf(ctx, sizeof(ctx), "matmul(trc=%u,%s,%llux%llu x %llux%llu)", (unsigned)trc,
                         mc[c].label, (unsigned long long)SHAPES[sh].n,
                         (unsigned long long)SHAPES[sh].m, (unsigned long long)SHAPES[sh].m,
                         (unsigned long long)SHAPES[sh].p);

                check(csro_matmul_to(&h.K, &x, &res, dhl) == CSRO_OK, ctx);
                check(csro_to_dense(&h.K, &dense) == CSRO_OK
                      && oarr_matmul_OO_to(&dense, &x, &ref, dhl) == DN_OK, ctx);
                d = soa_rel_diff(&res, &ref);
                check(d >= 0.0 && d <= TOL_ORACLE && res.nact == ref.nact
                      && res.trc_order == ref.trc_order && res.act_order == ref.act_order, ctx);
                check(csrss_matmul_to(&hs.K, &xs, &rs, dhl) == CSRSS_OK, ctx);

                // A real result has an empty semi-sparse set; only compare layouts that exist.
                if (res.nact > 0){
                    compare_vs_ss(&res, &rs, TOL_SS, ctx);
                }

                oarr_free(&xs_d);
                oarrss_free(&xs); oarrss_free(&rs);
                oarr_free(&x); oarr_free(&dense); oarr_free(&ref); oarr_free(&res);
                hold_free(&h); ss_hold_free(&hs);
                lilo_free(&lil); lilss_free(&ss);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Hand-made patterns: duplicates, unsorted columns, empty rows, 0 x 0, shape errors, res as the
// matrix's own value array, a dirty destination.
static void test_matmul_patterns(dhelpl_t dhl){

    int64_t indptr[5] = {0, 3, 3, 5, 6}, indices[6] = {2, 0, 2, 1, 1, 0};
    oarr_t val = make_soa(3, 6, 1, 3, 3), x = make_soa(2, 3, 2, 3, 3);
    oarr_t dense = oarr_init(), ref = oarr_init(), res = oarr_init();
    oarrss_t sval = ss_soa(&val), sx = ss_soa(&x), sres = oarrss_init();
    csro_t K;
    csrss_t Ks;
    double d;

    K.p_val = &val; K.p_indices = indices; K.p_indptr = indptr; K.nrows = 4; K.ncols = 3;
    Ks.p_val = &sval; Ks.p_indices = indices; Ks.p_indptr = indptr; Ks.nrows = 4; Ks.ncols = 3;

    check(csro_check(&K) == CSRO_OK, "patterns: valid");
    check(csro_matmul_to(&K, &x, &res, dhl) == CSRO_OK, "patterns: matmul status");
    check(csro_to_dense(&K, &dense) == CSRO_OK && oarr_matmul_OO_to(&dense, &x, &ref, dhl) == DN_OK,
          "patterns: oracle");
    d = soa_rel_diff(&res, &ref);
    check(d >= 0.0 && d <= TOL_ORACLE, "patterns: duplicates and unsorted columns add up");
    check(csrss_matmul_to(&Ks, &sx, &sres, dhl) == CSRSS_OK, "patterns: ss status");
    compare_vs_ss(&res, &sres, TOL_SS, "patterns vs semi-sparse");

    // Dirty destination (larger layout) gives the same bits.
    {
        oarr_t dd = make_soa(6, 7, 7, 4, 4);
        size_t n = (size_t)(1 + sshelp_ndir_total(res.nact, res.trc_order)) * res.size;

        check(csro_matmul_to(&K, &x, &dd, dhl) == CSRO_OK && dd.nact == res.nact
              && dd.trc_order == res.trc_order && dd.nrows == 4 && dd.ncols == 2
              && memcmp(dd.p_data, res.p_data, n * sizeof(coeff_t)) == 0,
              "patterns: dirty destination");
        oarr_free(&dd);
    }

    // res may be the matrix's own value array.
    {
        oarr_t cp = oarr_init();
        csro_t K2 = K;

        check(oarr_copy_to(&val, &cp) == DN_OK, "copy values");
        K2.p_val = &cp;
        check(csro_matmul_to(&K2, &x, &cp, dhl) == CSRO_OK && soa_rel_diff(&cp, &res) == 0.0,
              "patterns: res is the matrix's value array");
        oarr_free(&cp);
    }

    // Shape error leaves res unchanged.
    {
        oarr_t y = make_soa(2, 4, 2, 3, 3);
        coeff_t* before = res.p_data;

        check(csro_matmul_to(&K, &y, &res, dhl) == CSRO_ERR_SIZE && res.p_data == before
              && res.nrows == 4 && res.ncols == 2, "matmul: shape mismatch -> CSRO_ERR_SIZE");
        oarr_free(&y);
    }

    // 0 x 0 and 1 x 1.
    {
        lilo_t e0 = lilo_init(0, 0), e1 = lilo_init(1, 1);
        csr_hold_t h0, h1;
        oarr_t x0 = oarr_init(), x1 = make_soa(2, 1, 1, 2, 2), r = oarr_init();
        otinum_t v = make_num(2.0, 3, 2, 2), prod = oti_init(), got = oti_init();

        check(oarr_zeros_to(2, 0, 0, 2, &x0) == DN_OK, "0x0 setup");
        to_csr(&e0, &h0);
        check(csro_matmul_to(&h0.K, &x0, &r, dhl) == CSRO_OK && r.nrows == 0 && r.ncols == 0,
              "matmul 0x0");
        check(csro_solve_init(&h0.K, &x0, &r) == CSRO_OK && r.nrows == 0, "solve_init 0x0");
        check(csro_solve_rhs(&h0.K, &r, 1, dhl) == CSRO_OK, "solve_rhs 0x0");

        lilo_set(&e1, 0, 0, &v);
        to_csr(&e1, &h1);
        check(oarr_get_item_to(0, 0, &x1, &got) == DN_OK && oti_mul_oo_to(&v, &got, &prod, dhl) == DN_OK,
              "1x1 oracle");
        check(csro_matmul_to(&h1.K, &x1, &r, dhl) == CSRO_OK, "matmul 1x1: status");
        {
            oarr_t pr = oarr_init();

            check(oarr_zeros_to(prod.nact, 1, 1, prod.trc_order, &pr) == DN_OK
                  && oarr_set_item(&prod, 0, 0, &pr) == DN_OK && soa_rel_diff(&r, &pr) <= TOL_ORACLE,
                  "matmul 1x1 == scalar product");
            oarr_free(&pr);
        }

        hold_free(&h0); hold_free(&h1);
        oarr_free(&x0); oarr_free(&x1); oarr_free(&r);
        oti_free(&v); oti_free(&prod); oti_free(&got);
        lilo_free(&e0); lilo_free(&e1);
    }

    oarrss_free(&sval); oarrss_free(&sx); oarrss_free(&sres);
    oarr_free(&val); oarr_free(&x); oarr_free(&dense); oarr_free(&ref); oarr_free(&res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     SOLVE     -------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_solve(dhelpl_t dhl){

    static const struct { bases_t kK, kb; int tKlow, tblow; const char* label; } CASES[] = {
        { 3, 3, 0, 0, "equal" }, { 3, 1, 0, 0, "K-larger" }, { 1, 3, 0, 0, "b-larger" },
        { 0, 3, 0, 0, "K-real" }, { 3, 0, 0, 0, "b-real" }, { 3, 2, 1, 0, "K-lower-order" },
        { 2, 3, 0, 1, "b-lower-order" },
    };
    size_t c;
    ord_t trc;

    for (trc = 1; trc <= 5; trc++){

        for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

            ord_t tK = (CASES[c].tKlow && trc > 1) ? (ord_t)(trc - 1) : trc;
            ord_t tb = (CASES[c].tblow && trc > 1) ? (ord_t)(trc - 1) : trc;
            bases_t kK = (trc >= 5 && CASES[c].kK > 2) ? 2 : CASES[c].kK;
            bases_t kb = (trc >= 5 && CASES[c].kb > 2) ? 2 : CASES[c].kb;
            lilo_t lil;
            lilss_t ss;
            csr_hold_t h;
            ss_hold_t hs;
            oarr_t b = make_soa(kb, 8, 2, tb, tb), u, dense = oarr_init(), ref = oarr_init();
            oarrss_t sb = ss_soa(&b), su;
            char ctx[128];
            double d;

            make_system(8, kK, tK, &lil, &ss);
            to_csr(&lil, &h);
            to_csr_ss(&ss, &hs);

            snprintf(ctx, sizeof(ctx), "solve(trc=%u,%s)", (unsigned)trc, CASES[c].label);
            u = block_solve(&h.K, &b, dhl);
            check(csro_to_dense(&h.K, &dense) == CSRO_OK && oarr_solve_to(&dense, &b, &ref, dhl) == 0,
                  ctx);
            d = soa_rel_diff(&u, &ref);
            check(d >= 0.0 && d <= 1e-12 && u.nact == ref.nact && u.trc_order == ref.trc_order, ctx);

            su = block_solve_ss(&hs.K, &sb, dhl);

            if (u.nact > 0){
                compare_vs_ss(&u, &su, TOL_SS, ctx);
            }

            oarrss_free(&sb); oarrss_free(&su);
            oarr_free(&b); oarr_free(&u); oarr_free(&dense); oarr_free(&ref);
            hold_free(&h); ss_hold_free(&hs);
            lilo_free(&lil); lilss_free(&ss);

        }

    }

    // Statuses, and solve_init in place (u == b).
    {
        lilo_t lil;
        lilss_t ss;
        csr_hold_t h;
        oarr_t b = make_soa(1, 6, 1, 2, 2), u = oarr_init(), v = oarr_init(), r = make_soa(3, 5, 1, 2, 2);

        make_system(6, 3, 2, &lil, &ss);
        to_csr(&lil, &h);

        check(csro_solve_init(&h.K, &b, &u) == CSRO_OK && u.nact == 3 && u.trc_order == 2,
              "solve_init: layout max(nact), max(trc)");
        check(oarr_copy_to(&b, &v) == DN_OK && csro_solve_init(&h.K, &v, &v) == CSRO_OK
              && soa_rel_diff(&u, &v) == 0.0 && v.nact == 3, "solve_init: in place");
        check(csro_solve_init(&h.K, &r, &u) == CSRO_ERR_SIZE && u.nrows == 6,
              "solve_init: wrong rows -> CSRO_ERR_SIZE, u unchanged");
        check(csro_solve_rhs(&h.K, &u, 0, dhl) == CSRO_ERR_ORDER, "solve_rhs: order 0");
        check(csro_solve_rhs(&h.K, &u, 3, dhl) == CSRO_ERR_ORDER, "solve_rhs: order above trc");
        check(csro_solve_rhs(&h.K, &b, 1, dhl) == CSRO_ERR_NACT, "solve_rhs: K nact above u's");
        check(csro_solve_rhs(&h.K, &r, 1, dhl) == CSRO_ERR_SIZE, "solve_rhs: wrong rows");

        oarr_free(&b); oarr_free(&u); oarr_free(&v); oarr_free(&r);
        hold_free(&h);
        lilo_free(&lil); lilss_free(&ss);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     BEYOND THE GLOBAL TABLE     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// k = 11 at order 5 (Nbasis(5) = 10): matmul (K over 11 x x over 6, and 6 x 11) and the solve
// right-hand sides against semi-sparse.
static void test_beyond_table(dhelpl_t dhl, const char* tag){

    lilo_t lil;
    lilss_t ss;
    csr_hold_t h;
    ss_hold_t hs;
    oarr_t x6 = make_soa(6, 5, 1, 5, 5), x11 = make_soa(11, 5, 1, 5, 5), res = oarr_init(), u;
    oarrss_t s6 = ss_soa(&x6), s11 = ss_soa(&x11), rs = oarrss_init(), su;
    char ctx[128];

    random_matrix(5, 5, 11, 5, 5, &lil, &ss);
    to_csr(&lil, &h);
    to_csr_ss(&ss, &hs);

    snprintf(ctx, sizeof(ctx), "matmul(K k=11 x x k=6, trc 5, %s)", tag);
    check(csro_matmul_to(&h.K, &x6, &res, dhl) == CSRO_OK
          && csrss_matmul_to(&hs.K, &s6, &rs, dhl) == CSRSS_OK, ctx);
    compare_vs_ss(&res, &rs, TOL_SS, ctx);

    lilo_free(&lil); lilss_free(&ss);
    hold_free(&h); ss_hold_free(&hs);

    random_matrix(5, 5, 6, 5, 5, &lil, &ss);
    to_csr(&lil, &h);
    to_csr_ss(&ss, &hs);

    snprintf(ctx, sizeof(ctx), "matmul(K k=6 x x k=11, trc 5, %s)", tag);
    check(csro_matmul_to(&h.K, &x11, &res, dhl) == CSRO_OK
          && csrss_matmul_to(&hs.K, &s11, &rs, dhl) == CSRSS_OK, ctx);
    compare_vs_ss(&res, &rs, TOL_SS, ctx);

    lilo_free(&lil); lilss_free(&ss);
    hold_free(&h); ss_hold_free(&hs);

    make_system(5, 11, 5, &lil, &ss);
    to_csr(&lil, &h);
    to_csr_ss(&ss, &hs);

    snprintf(ctx, sizeof(ctx), "block solve(K k=11, b k=6, trc 5, %s)", tag);
    u  = block_solve(&h.K, &x6, dhl);
    su = block_solve_ss(&hs.K, &s6, dhl);
    compare_vs_ss(&u, &su, TOL_SS, ctx);

    oarr_free(&u); oarrss_free(&su);
    lilo_free(&lil); lilss_free(&ss);
    hold_free(&h); ss_hold_free(&hs);
    oarr_free(&x6); oarr_free(&x11); oarr_free(&res);
    oarrss_free(&s6); oarrss_free(&s11); oarrss_free(&rs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reruns this executable with the local table cache disabled (rank fallback of the kernels).
static void test_rank_fallback_child(const char* self){

    char cmd[4096];
    int rc;

    if (self == NULL || strlen(self) > 3000 || strchr(self, '\'') != NULL){

        check(0, "rank fallback: cannot rerun the test executable");
        return;

    }

    snprintf(cmd, sizeof(cmd), "OTI_SS_TABLE_CACHE_MB=0 '%s' --rank-fallback", self);
    fflush(stdout);
    fflush(stderr);
    rc = system(cmd);
    check(rc == 0, "rank fallback (child with OTI_SS_TABLE_CACHE_MB=0) passes");

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FEM-LIKE MATRIX     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// A 2-D Laplacian-like stiffness of a g x g grid of quad elements ((g+1)^2 nodes), assembled with
// one lilo_add_block() per element from 4 x 4 OTI element matrices (nact 2, order 2), against the
// same assembly in semi-sparse, then matmul and the block solve against the dense SoA oracle.
static void test_fem_like(dhelpl_t dhl){

    uint64_t g = 17, nn = (g + 1) * (g + 1), ex, ey, i;
    lilo_t lil = lilo_init(nn, nn);
    lilss_t ss = lilss_init(nn, nn);
    static const double KE[4][4] = { { 4, -1, -2, -1 }, { -1, 4, -1, -2 }, { -2, -1, 4, -1 },
                                     { -1, -2, -1, 4 } };
    csr_hold_t h;
    ss_hold_t hs;
    oarr_t x, res = oarr_init(), ref = oarr_init(), dense = oarr_init(), u, uref = oarr_init();
    oarrss_t sx, rs = oarrss_init();
    double d;

    for (ey = 0; ey < g; ey++){

        for (ex = 0; ex < g; ex++){

            uint64_t n0 = ex + ey * (g + 1);
            uint64_t nodes[4] = { n0, n0 + 1, n0 + g + 2, n0 + g + 1 };
            oarr_t ke = make_soa(2, 4, 4, 2, 2);
            oarrss_t ske;
            uint64_t a, b;

            // Real part: the element Laplacian plus a mass-like shift (nonsingular assembly).
            for (a = 0; a < 4; a++){

                for (b = 0; b < 4; b++){
                    ke.p_data[a + 4 * b] = KE[a][b] + ((a == b) ? 0.5 : 0.0);
                }

            }

            ske = ss_soa(&ke);
            check(lilo_add_block(&lil, nodes, 4, nodes, 4, &ke, dhl) == CSRO_OK, "fem: add_block");
            check(lilss_add_block(&ss, nodes, 4, nodes, 4, &ske, dhl) == CSRSS_OK, "fem: ss add_block");

            oarrss_free(&ske);
            oarr_free(&ke);

        }

    }

    check(lil_matches_ss(&lil, &ss), "fem: assembly matches semi-sparse");

    to_csr(&lil, &h);
    to_csr_ss(&ss, &hs);
    x  = make_soa(3, nn, 1, 2, 2);
    sx = ss_soa(&x);

    check(h.val.size == hs.val.size && csro_check(&h.K) == CSRO_OK, "fem: pattern");

    for (i = 0; i <= nn; i++){

        if (h.indptr[i] != hs.indptr[i]){
            break;
        }

    }

    check(i == nn + 1, "fem: indptr matches semi-sparse");
    compare_vs_ss(&h.val, &hs.val, 0.0, "fem: CSR values");

    check(csro_matmul_to(&h.K, &x, &res, dhl) == CSRO_OK, "fem: matmul status");
    check(csro_to_dense(&h.K, &dense) == CSRO_OK && oarr_matmul_OO_to(&dense, &x, &ref, dhl) == DN_OK,
          "fem: oracle");
    d = soa_rel_diff(&res, &ref);
    check(d >= 0.0 && d <= TOL_ORACLE, "fem: matmul vs dense SoA");
    check(csrss_matmul_to(&hs.K, &sx, &rs, dhl) == CSRSS_OK, "fem: ss matmul");
    compare_vs_ss(&res, &rs, TOL_SS, "fem: matmul vs semi-sparse");

    u = block_solve(&h.K, &x, dhl);
    check(oarr_solve_to(&dense, &x, &uref, dhl) == 0, "fem: dense solve");
    d = soa_rel_diff(&u, &uref);
    check(d >= 0.0 && d <= 1e-11, "fem: block solve vs dense SoA solve");

    oarr_free(&u); oarr_free(&uref);
    oarr_free(&x); oarr_free(&res); oarr_free(&ref); oarr_free(&dense);
    oarrss_free(&sx); oarrss_free(&rs);
    hold_free(&h); ss_hold_free(&hs);
    lilo_free(&lil); lilss_free(&ss);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Review fixes (review-phase2-wp7.md): a value pointing into the builder (F1), the reservation of
// lilo_add_block (F2), in-capacity growth of a stored entry (F3), a mapped inner failure (F4), K's
// value array as x or u (F5), no rehash on an update (F6).
static void test_review_fixes(dhelpl_t dhl){

    char ctx[128];

    // F1: 64 entries fill the first entry capacity, so the next insertion moves the entry array.
    {
        lilo_t L = lilo_init(100, 100);
        otinum_t v = make_num(5.0, 3, 2, 2), twice = oti_init();
        uint64_t e;
        int ok = 1;

        for (e = 0; e < 64; e++){
            ok = ok && lilo_set_r(&L, e, e, 1.0) == CSRO_OK;
        }

        ok = ok && lilo_set(&L, 0, 0, &v) == CSRO_OK && L.nnz == 64 && L.cap == 64;
        check(ok, "F1 setup: entry array full");
        check(lilo_add(&L, 99, 98, lilo_get(&L, 0, 0), dhl) == CSRO_OK && L.cap > 64
              && same_value(lilo_get(&L, 99, 98), &v), "F1: lilo_add of a lilo_get() result");

        for (e = 64; e < 127; e++){
            lilo_set_r(&L, e % 100, 99 - e % 100, 2.0);
        }

        snprintf(ctx, sizeof(ctx), "F1: lilo_set of a lilo_get() result (cap %llu, nnz %llu)",
                 (unsigned long long)L.cap, (unsigned long long)L.nnz);
        check(lilo_set(&L, 98, 97, lilo_get(&L, 0, 0)) == CSRO_OK
              && same_value(lilo_get(&L, 98, 97), &v), ctx);
        check(oti_sum_oo_to(&v, &v, &twice, dhl) == DN_OK
              && lilo_add(&L, 0, 0, lilo_get(&L, 0, 0), dhl) == CSRO_OK
              && same_value(lilo_get(&L, 0, 0), &twice), "F1: entry += itself");

        oti_free(&v); oti_free(&twice);
        lilo_free(&L);
    }

    // F2 and F6: the hash grows only for new positions; add_block reserves for its whole block.
    {
        lilo_t L = lilo_init(40, 40);
        oarr_t blk = make_soa(2, 4, 4, 2, 2);
        uint64_t rows[4] = {0, 1, 38, 39}, e;
        int ok = 1;

        for (e = 0; e < 32; e++){
            ok = ok && lilo_set_r(&L, e, 0, 1.0) == CSRO_OK;
        }

        check(ok && L.nslot == 64, "F6 setup: 32 entries in 64 slots");
        check(lilo_set_r(&L, 5, 0, 3.0) == CSRO_OK && L.nslot == 64,
              "F6: updating a stored entry at the load threshold does not rehash");
        check(lilo_set_r(&L, 5, 1, 3.0) == CSRO_OK && L.nslot == 128, "F6: a new entry rehashes");
        check(lilo_add_block(&L, rows, 4, rows, 4, &blk, dhl) == CSRO_OK && L.nnz == 33 + 14
              && L.cap >= L.nnz && 2 * L.nnz <= L.nslot, "F2: add_block with reserved capacity");

        oarr_free(&blk);
        lilo_free(&L);
    }

    // F3: a stored entry whose capacity already holds the addend's nact grows in place.
    {
        lilo_t L = lilo_init(3, 3);
        otinum_t big = make_num(1.0, 5, 3, 3), small = make_num(2.0, 2, 3, 3);
        otinum_t add = make_num(3.0, 4, 3, 3), ref = oti_init();
        oarr_t blk = oarr_init();
        uint64_t r0 = 1;

        check(lilo_set(&L, 1, 1, &big) == CSRO_OK && lilo_set(&L, 1, 1, &small) == CSRO_OK
              && lilo_get(&L, 1, 1)->nact == 2 && lilo_get(&L, 1, 1)->nbases >= 4,
              "F3 setup: small entry in a large buffer");
        check(lilo_add(&L, 1, 1, &add, dhl) == CSRO_OK && oti_sum_oo_to(&small, &add, &ref, dhl) == DN_OK
              && same_value(lilo_get(&L, 1, 1), &ref) && lilo_get(&L, 1, 1)->nact == 4,
              "F3: lilo_add grows the entry within its capacity");

        check(lilo_set(&L, 1, 1, &big) == CSRO_OK && lilo_set(&L, 1, 1, &small) == CSRO_OK
              && oarr_zeros_to(4, 1, 1, 3, &blk) == DN_OK && oarr_set_item(&add, 0, 0, &blk) == DN_OK,
              "F3 setup (block)");
        check(lilo_add_block(&L, &r0, 1, &r0, 1, &blk, dhl) == CSRO_OK
              && same_value(lilo_get(&L, 1, 1), &ref), "F3: lilo_add_block grows the entry in place");

        oti_free(&big); oti_free(&small); oti_free(&add); oti_free(&ref);
        oarr_free(&blk);
        lilo_free(&L);
    }

    // F4: an inner DN_ERR_MEMORY comes out as CSRO_ERR_MEMORY (an empty K with 2^42 rows).
    {
        oarr_t val = oarr_init(), x = make_soa(3, 4, 1, 2, 2), res = make_soa(1, 2, 2, 1, 1);
        int64_t dummy[2] = {0, 0};
        csro_t K;

        check(oarr_zeros_to(3, 0, 1, 2, &val) == DN_OK, "F4 setup");
        K.p_val = &val; K.p_indices = dummy; K.p_indptr = dummy; K.nrows = 1ULL << 42; K.ncols = 4;
        check(csro_matmul_to(&K, &x, &res, dhl) == CSRO_ERR_MEMORY, "F4: mapped DN_ERR_MEMORY");
        check(res.nrows == 2 && res.ncols == 2, "F4: res unchanged and freeable");

        oarr_free(&val); oarr_free(&x); oarr_free(&res);
    }

    // F5: K's value array as x (matmul) or u (solve_init) is refused, K unchanged.
    {
        int64_t indptr[4] = {0, 1, 2, 3}, indices[3] = {0, 1, 2};
        oarr_t val = make_soa(2, 3, 1, 2, 2), b = make_soa(1, 3, 1, 2, 2);
        oarr_t res = oarr_init(), cp = oarr_init();
        csro_t K;

        K.p_val = &val; K.p_indices = indices; K.p_indptr = indptr; K.nrows = 3; K.ncols = 3;
        check(oarr_copy_to(&val, &cp) == DN_OK, "F5 setup");
        check(csro_matmul_to(&K, &val, &res, dhl) == CSRO_ERR_SIZE, "F5: x is K's values");
        check(csro_solve_init(&K, &b, &val) == CSRO_ERR_SIZE && soa_rel_diff(&val, &cp) == 0.0
              && val.nrows == 3 && val.ncols == 1, "F5: u is K's values, K unchanged");

        oarr_free(&val); oarr_free(&b); oarr_free(&res); oarr_free(&cp);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MAIN     --------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;
    int child = (argc > 1 && strcmp(argv[1], "--rank-fallback") == 0);
    unsigned u;

    g_verbose = (getenv("DN_TEST_VERBOSE") != NULL);

    for (u = 0; u < 256; u++){
        g_bases[u] = (bases_t)(u + 1);
    }

    dhelp_load(NULL, &dhl);

    if (child){

        check(sshelp_get_pair(11, 2, 3, dhl).p_tab == NULL, "rank fallback: no table for k=11, 2x3");
        test_beyond_table(dhl, "rank fallback");

    } else {

        test_builder_basics(dhl);
        test_builder_many(dhl);
        test_add_block(dhl);
        test_to_csr(dhl);
        test_check();
        test_matmul(dhl);
        test_matmul_patterns(dhl);
        test_solve(dhl);
        test_fem_like(dhl);
        test_review_fixes(dhl);
        // The cache can be disabled from the environment (debugging the fallback): skip the check then.
        if (getenv("OTI_SS_TABLE_CACHE_MB") == NULL){
            check(sshelp_get_pair(11, 2, 3, dhl).p_tab != NULL, "k=11, 2x3 uses a cached local table");
        }

        test_beyond_table(dhl, "cached table");
        test_rank_fallback_child(argv[0]);

    }

    oti_ws_release();
    dhelp_free(&dhl);

    printf("%s%d checks passed, %d failed.\n", child ? "[rank-fallback child] " : "", n_passed,
           n_failed);

    if (n_failed != 0){

        fprintf(stderr, "%d dense CSR test(s) failed.\n", n_failed);
        return 1;

    }

    printf("C dense CSR tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
