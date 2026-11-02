/* Independent checks of the semi-sparse OTI sparse matrices (include/oti/semisparse/csr/csr.h,
 * PLAN-semisparse-sparse-leveling.md Phase 6): the triplet builder (set overwrites, set_r replaces,
 * add accumulates, missing entries, hash growth, copy), its CSR conversion (row / column order,
 * union of the entries' sets, explicit zeros kept), the CSR pattern check, CSR times dense SoA
 * against the dense SoA matmul of the same matrix (same, leading, interleaved, disjoint sets and
 * mixed truncation orders), and the order-by-order solve right-hand sides against the dense SoA
 * solve, with the real systems solved here by Gaussian elimination. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>

static int n_failed = 0;

static uint64_t g_rng_state = 0x5EED0C5A11223344ULL;

static const bases_t SET_A[2] = {1, 2};
static const bases_t SET_B[4] = {1, 2, 3, 4};
static const bases_t SET_C[2] = {1, 3};
static const bases_t SET_D[2] = {2, 4};
static const bases_t SET_E[2] = {3, 4};
static const bases_t SET_F[3] = {1, 3, 5};
static const bases_t SET_G[3] = {2, 4, 6};


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

    return (g_rng_state >> 17) % n;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------     BUILDING OBJECTS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// A scalar over `bases` with real part `re` and random coefficients up to order `trc`.
static ssotinum_t make_scalar(coeff_t re, const bases_t* bases, bases_t k, ord_t trc){

    ssotinum_t num = ssoti_create_empty(bases, k, trc);
    ndir_t j;

    num.re = re;

    for (j = 0; j < sshelp_ndir_total(k, trc); j++){
        num.p_im[j] = 0.5 * rng_value();
    }

    num.act_order = trc;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A dense SoA array over `bases` with random coefficients in every block.
static oarrss_t make_soa(const bases_t* bases, bases_t k, uint64_t nrows, uint64_t ncols,
                         ord_t trc){

    oarrss_t arr = oarrss_zeros(bases, k, nrows, ncols, trc);
    uint64_t e, n = (1 + sshelp_ndir_total(k, trc)) * arr.size;

    for (e = 0; e < n; e++){
        arr.p_data[e] = rng_value();
    }

    arr.act_order = trc;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// An n x n builder with a strongly dominant real diagonal, off-diagonal band entries (bandwidth 2,
// plus a few far entries) over `bases` at order `trc`; the diagonal is real only on even rows, so
// the entries' sets differ.
static lilss_t make_system(uint64_t n, const bases_t* bases, bases_t k, ord_t trc){

    lilss_t lil = lilss_init(n, n);
    uint64_t i;

    for (i = 0; i < n; i++){

        uint64_t j;

        for (j = (i >= 2) ? i - 2 : 0; j <= i + 2 && j < n; j++){

            ssotinum_t v;

            if (i == j && i % 2 == 0){

                lilss_set_r(&lil, i, j, 10.0 + rng_value());
                continue;

            }

            v = make_scalar((i == j) ? 10.0 + rng_value() : rng_value(), bases, k, trc);
            lilss_set(&lil, i, j, &v);
            ssoti_free(&v);

        }

    }

    {
        ssotinum_t v = make_scalar(0.3, bases, (k > 0) ? 1 : 0, trc);

        lilss_set(&lil, 0, n - 1, &v);
        lilss_set(&lil, n - 1, 0, &v);
        ssoti_free(&v);
    }

    return lil;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest absolute coefficient of a scalar.
static double scalar_max_abs(const ssotinum_t* num){

    double m = fabs(num->re);
    ndir_t j;

    for (j = 0; j < sshelp_ndir_total(num->nbases, num->trc_order); j++){

        if (fabs(num->p_im[j]) > m){
            m = fabs(num->p_im[j]);
        }

    }

    return m;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest absolute coefficient of an array.
static double soa_max_abs(const oarrss_t* arr){

    double m = 0.0;
    uint64_t e, n = (1 + sshelp_ndir_total(arr->nbases, arr->trc_order)) * arr->size;

    for (e = 0; e < n; e++){

        if (fabs(arr->p_data[e]) > m){
            m = fabs(arr->p_data[e]);
        }

    }

    return m;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// max |a - b| / max(1, max |b|) over every coefficient (the union set, larger order).
static double soa_rel_diff(const oarrss_t* a, const oarrss_t* b, dhelpl_t dhl){

    oarrss_t d = oarrss_init();
    double scale = soa_max_abs(b), diff;

    oarrss_sub_OO_to(a, b, &d, dhl);
    diff = soa_max_abs(&d);
    oarrss_free(&d);

    return diff / ((scale > 1.0) ? scale : 1.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds the CSR arrays of a builder; the caller frees *val, *indices and *indptr.
static csrss_t to_csr(const lilss_t* lil, oarrss_t* val, int64_t** indices, int64_t** indptr){

    csrss_t K;

    *indices = (int64_t*)malloc((size_t)lil->nnz * sizeof(int64_t) + 1);
    *indptr  = (int64_t*)malloc((size_t)(lil->nrows + 1) * sizeof(int64_t));
    *val     = oarrss_init();

    lilss_to_csr(lil, val, *indices, *indptr);

    K.p_val     = val;
    K.p_indices = *indices;
    K.p_indptr  = *indptr;
    K.nrows     = lil->nrows;
    K.ncols     = lil->ncols;

    return K;

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

                A[c + j * n] = A[piv + j * n];
                A[piv + j * n] = t;

            }

            for (j = 0; j < nrhs; j++){

                double t = B[c + j * n];

                B[c + j * n] = B[piv + j * n];
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
// Block solve of K u = b through csrss_solve_init() / csrss_solve_rhs(), the real systems solved with
// real_solve() on the dense real part of K. Returns the solution (caller frees).
static oarrss_t block_solve(const csrss_t* K, const oarrss_t* b, dhelpl_t dhl){

    oarrss_t u = oarrss_init(), dense = oarrss_init();
    uint64_t n = K->nrows, m = b->ncols;
    double* A = (double*)malloc((size_t)(n * n) * sizeof(double) + 1);
    ord_t p;

    check(csrss_solve_init(K, b, &u) == CSRSS_OK, "block solve: init status");
    csrss_to_dense(K, &dense);

    memcpy(A, dense.p_data, (size_t)(n * n) * sizeof(double));
    real_solve(A, n, u.p_data, m);

    for (p = 1; p <= u.trc_order; p++){

        ndir_t Np = sshelp_ndir_order(u.nbases, p);

        check(csrss_solve_rhs(K, &u, p, dhl) == CSRSS_OK, "block solve: rhs status");
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

    lilss_t lil = lilss_init(4, 5), cp = lilss_init(1, 1);
    ssotinum_t a = make_scalar(2.0, SET_A, 2, 3);
    ssotinum_t b = make_scalar(-1.0, SET_E, 2, 2);
    ssotinum_t sum = ssoti_init(), diff = ssoti_init();
    const ssotinum_t* g;

    check(lilss_get(&lil, 0, 0) == NULL, "builder: empty get is NULL");
    check(lilss_trc_order(&lil) == 0, "builder: empty order 0");

    lilss_set(&lil, 1, 2, &a);
    g = lilss_get(&lil, 1, 2);
    check(g != NULL && g->nbases == 2 && g->trc_order == 3, "builder: set keeps set and order");
    ssoti_sub_oo_to(g, &a, &diff, dhl);
    check(scalar_max_abs(&diff) == 0.0, "builder: set copies the value exactly");
    check(lilss_get(&lil, 2, 1) == NULL, "builder: transposed position not stored");

    // Overwrite, not accumulate (pyoti.sparse lil_matrix semantics).
    lilss_set(&lil, 1, 2, &b);
    g = lilss_get(&lil, 1, 2);
    check(lil.nnz == 1 && g->nbases == 2 && g->p_bases[0] == 3 && g->trc_order == 2,
        "builder: set overwrites the entry");

    // add accumulates into a stored entry and inserts a missing one.
    lilss_add(&lil, 1, 2, &a, dhl);
    ssoti_sum_oo_to(&b, &a, &sum, dhl);
    ssoti_sub_oo_to(lilss_get(&lil, 1, 2), &sum, &diff, dhl);
    check(scalar_max_abs(&diff) < 1e-15 && lilss_get(&lil, 1, 2)->nbases == 4,
        "builder: add accumulates over the union set");
    lilss_add(&lil, 3, 4, &a, dhl);
    check(lil.nnz == 2 && lilss_get(&lil, 3, 4) != NULL, "builder: add inserts a missing entry");

    // A real replaces the entry entirely, explicit zeros are stored.
    lilss_set_r(&lil, 3, 4, 7.5);
    g = lilss_get(&lil, 3, 4);
    check(g->nbases == 0 && g->trc_order == 0 && g->re == 7.5, "builder: set_r replaces entry");
    lilss_set_r(&lil, 0, 0, 0.0);
    check(lil.nnz == 3 && lilss_get(&lil, 0, 0) != NULL, "builder: explicit zero is stored");
    check(lilss_trc_order(&lil) == 3, "builder: largest truncation order");

    lilss_copy_to(&lil, &cp);
    check(cp.nnz == 3 && cp.nrows == 4 && cp.ncols == 5, "builder: copy shape and count");
    ssoti_sub_oo_to(lilss_get(&cp, 1, 2), &sum, &diff, dhl);
    check(scalar_max_abs(&diff) < 1e-15, "builder: copy value");
    lilss_set_r(&cp, 1, 2, 1.0);
    check(lilss_get(&lil, 1, 2)->nbases == 4, "builder: copy is independent");

    lilss_free(&lil);
    check(lil.nnz == 0 && lilss_get(&lil, 1, 2) == NULL && lil.nrows == 4,
        "builder: free empties and keeps shape");

    lilss_free(&cp);
    ssoti_free(&a);
    ssoti_free(&b);
    ssoti_free(&sum);
    ssoti_free(&diff);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Many random insertions (hash table growth, collisions), checked against a dense shadow.
static void test_builder_many(void){

    const uint64_t n = 300, ninsert = 40000;
    double* shadow = (double*)calloc((size_t)(n * n), sizeof(double));
    uint8_t* stored = (uint8_t*)calloc((size_t)(n * n), 1);
    lilss_t lil = lilss_init(n, n);
    uint64_t t, count = 0, bad = 0, i, j;

    for (t = 0; t < ninsert; t++){

        double v = rng_value();

        i = rng_index(n);
        j = rng_index(n);
        lilss_set_r(&lil, i, j, v);
        shadow[i + j * n] = v;

        if (!stored[i + j * n]){

            stored[i + j * n] = 1;
            count++;

        }

    }

    for (i = 0; i < n; i++){

        for (j = 0; j < n; j++){

            const ssotinum_t* g = lilss_get(&lil, i, j);

            if (stored[i + j * n]){
                bad += (g == NULL || g->re != shadow[i + j * n]);
            } else {
                bad += (g != NULL);
            }

        }

    }

    check(lil.nnz == count, "builder (many): entry count");
    check(bad == 0, "builder (many): every position reads back");

    {
        uint64_t* perm = (uint64_t*)malloc((size_t)lil.nnz * sizeof(uint64_t));
        int64_t* indptr = (int64_t*)malloc((size_t)(n + 1) * sizeof(int64_t));
        int ok = 1;

        lilss_sorted(&lil, perm, indptr);
        ok = (indptr[0] == 0 && (uint64_t)indptr[n] == lil.nnz);

        for (i = 0; i < n && ok; i++){

            int64_t s;

            for (s = indptr[i]; s < indptr[i + 1]; s++){

                ok = ok && lil.p_row[perm[s]] == i;
                ok = ok && (s == indptr[i] || lil.p_col[perm[s - 1]] < lil.p_col[perm[s]]);

            }

        }

        check(ok, "builder (many): sorted by row, then column");

        free(perm);
        free(indptr);
    }

    lilss_free(&lil);
    free(shadow);
    free(stored);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// CSR conversion: pattern, union of sets, values of every entry.
static void test_to_csr(dhelpl_t dhl){

    lilss_t lil = lilss_init(3, 4);
    ssotinum_t a = make_scalar(1.5, SET_A, 2, 2);
    ssotinum_t c = make_scalar(-2.0, SET_F, 3, 3);
    ssotinum_t d = make_scalar(0.25, SET_D, 2, 1);
    oarrss_t val;
    int64_t *indices, *indptr;
    csrss_t K;
    uint64_t t;
    int ok = 1;

    lilss_set(&lil, 2, 3, &a);
    lilss_set(&lil, 0, 1, &c);
    lilss_set(&lil, 2, 0, &d);
    lilss_set_r(&lil, 0, 0, 4.0);
    lilss_set_r(&lil, 1, 2, 0.0);

    K = to_csr(&lil, &val, &indices, &indptr);

    check(val.nrows == 5 && val.ncols == 1, "to_csr: values are nnz x 1");
    check(val.nbases == 5 && val.p_bases[0] == 1 && val.p_bases[4] == 5, "to_csr: union set");
    check(val.trc_order == 3 && val.act_order == 3, "to_csr: largest orders");
    check(indptr[0] == 0 && indptr[1] == 2 && indptr[2] == 3 && indptr[3] == 5, "to_csr: indptr");
    check(indices[0] == 0 && indices[1] == 1 && indices[2] == 2 && indices[3] == 0 &&
        indices[4] == 3, "to_csr: indices sorted within rows");
    check(csrss_check(&K) == CSRSS_OK, "to_csr: pattern passes the check");

    for (t = 0; t < 5; t++){

        uint64_t r = 0;
        ssotinum_t e, diff = ssoti_init();
        const ssotinum_t* g;

        while ((uint64_t)indptr[r + 1] <= t){
            r++;
        }

        g = lilss_get(&lil, r, (uint64_t)indices[t]);
        e = oarrss_get_item(t, 0, &val);
        ssoti_sub_oo_to(&e, g, &diff, dhl);
        ok = ok && scalar_max_abs(&diff) == 0.0;
        ssoti_free(&e);
        ssoti_free(&diff);

    }

    check(ok, "to_csr: every value exact over the union set");

    {
        oarrss_t dense = oarrss_init();
        ssotinum_t e = ssoti_init(), diff = ssoti_init();

        csrss_to_dense(&K, &dense);
        oarrss_get_item_to(0, 1, &dense, &e);
        ssoti_sub_oo_to(&e, &c, &diff, dhl);
        check(dense.nrows == 3 && dense.ncols == 4 && scalar_max_abs(&diff) == 0.0,
            "to_dense: element value");
        oarrss_get_item_to(1, 1, &dense, &e);
        check(scalar_max_abs(&e) == 0.0, "to_dense: missing element is zero");

        oarrss_free(&dense);
        ssoti_free(&e);
        ssoti_free(&diff);
    }

    // Pattern check failures.
    indices[1] = 4;
    check(csrss_check(&K) == CSRSS_ERR_INDEX, "check: column out of range");
    indices[1] = 1;
    indptr[1] = 4;
    indptr[2] = 3;
    check(csrss_check(&K) == CSRSS_ERR_INDEX, "check: indptr not monotone");
    indptr[1] = 2;
    indptr[3] = 4;
    check(csrss_check(&K) == CSRSS_ERR_INDEX, "check: indptr end differs from nnz");

    {
        lilss_t empty = lilss_init(2, 2);
        oarrss_t eval;
        int64_t *eind, *eptr;
        csrss_t E = to_csr(&empty, &eval, &eind, &eptr);

        check(eval.nrows == 0 && eptr[2] == 0 && csrss_check(&E) == CSRSS_OK, "to_csr: empty");

        oarrss_free(&eval);
        free(eind);
        free(eptr);
    }

    oarrss_free(&val);
    free(indices);
    free(indptr);
    lilss_free(&lil);
    ssoti_free(&a);
    ssoti_free(&c);
    ssoti_free(&d);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MATMUL AND SOLVE     --------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct {
    const bases_t* kb; ///< Matrix set.
    bases_t         kk; ///< Its size.
    ord_t         ktrc; ///< Matrix truncation order.
    const bases_t* xb; ///< Array set.
    bases_t         xk; ///< Its size.
    ord_t         xtrc; ///< Array truncation order.
    const char*   name; ///< Scenario name.
} scenario_t;

static const scenario_t SCENARIOS[] = {
    { SET_A, 2, 3, SET_A, 2, 3, "same" },
    { SET_A, 2, 4, SET_B, 4, 4, "leading" },
    { SET_B, 4, 2, SET_A, 2, 2, "array leads" },
    { SET_C, 2, 3, SET_D, 2, 3, "interleaved" },
    { SET_F, 3, 3, SET_G, 3, 3, "interleaved 135/246" },
    { SET_A, 2, 2, SET_E, 2, 2, "disjoint" },
    { SET_C, 2, 1, SET_D, 2, 4, "orders 1 vs 4" },
    { SET_B, 4, 5, SET_A, 2, 2, "orders 5 vs 2" },
    { NULL,  0, 0, SET_B, 4, 3, "real matrix" },
    { SET_B, 4, 3, NULL,  0, 0, "real array" },
};

#define N_SCENARIOS (sizeof(SCENARIOS) / sizeof(SCENARIOS[0]))


// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    size_t s;

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        lilss_t lil = make_system(9, sc->kb, sc->kk, sc->ktrc);
        oarrss_t x = make_soa(sc->xb, sc->xk, 9, 3, sc->xtrc);
        oarrss_t val, dense = oarrss_init(), ref = oarrss_init(), res = oarrss_init();
        int64_t *indices, *indptr;
        csrss_t K = to_csr(&lil, &val, &indices, &indptr);
        char name[160];

        csrss_to_dense(&K, &dense);
        check(oarrss_matmul_OO_to(&dense, &x, &ref, dhl) == 0, "matmul: dense oracle status");
        check(csrss_matmul_to(&K, &x, &res, dhl) == CSRSS_OK, "matmul: status");

        snprintf(name, sizeof(name), "matmul (%s): same set and order as dense", sc->name);
        check(res.nbases == ref.nbases && res.trc_order == ref.trc_order &&
            memcmp(res.p_bases, ref.p_bases, (size_t)res.nbases * sizeof(bases_t)) == 0, name);
        snprintf(name, sizeof(name), "matmul (%s): matches dense matmul", sc->name);
        check(soa_rel_diff(&res, &ref, dhl) < 1e-13, name);

        oarrss_free(&val);
        oarrss_free(&dense);
        oarrss_free(&ref);
        oarrss_free(&res);
        oarrss_free(&x);
        free(indices);
        free(indptr);
        lilss_free(&lil);

    }

    {
        lilss_t lil = make_system(4, SET_A, 2, 2);
        oarrss_t x = make_soa(SET_A, 2, 3, 1, 2), res = oarrss_init(), val;
        int64_t *indices, *indptr;
        csrss_t K = to_csr(&lil, &val, &indices, &indptr);

        check(csrss_matmul_to(&K, &x, &res, dhl) == CSRSS_ERR_SIZE && res.p_data == NULL,
            "matmul: shape mismatch leaves res alone");

        oarrss_free(&val);
        oarrss_free(&x);
        free(indices);
        free(indptr);
        lilss_free(&lil);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_solve(dhelpl_t dhl){

    size_t s;

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        lilss_t lil = make_system(12, sc->kb, sc->kk, sc->ktrc);
        oarrss_t b = make_soa(sc->xb, sc->xk, 12, 2, sc->xtrc);
        oarrss_t val, dense = oarrss_init(), ref = oarrss_init(), u, Ku = oarrss_init();
        int64_t *indices, *indptr;
        csrss_t K = to_csr(&lil, &val, &indices, &indptr);
        char name[160];

        csrss_to_dense(&K, &dense);
        check(oarrss_solve_to(&dense, &b, &ref, dhl) == 0, "solve: dense oracle status");
        u = block_solve(&K, &b, dhl);

        snprintf(name, sizeof(name), "solve (%s): matches dense solve", sc->name);
        check(u.nbases == ref.nbases && u.trc_order == ref.trc_order &&
            soa_rel_diff(&u, &ref, dhl) < 1e-12, name);

        csrss_matmul_to(&K, &u, &Ku, dhl);
        snprintf(name, sizeof(name), "solve (%s): residual K u - b", sc->name);
        check(soa_rel_diff(&Ku, &b, dhl) < 1e-12, name);

        oarrss_free(&val);
        oarrss_free(&dense);
        oarrss_free(&ref);
        oarrss_free(&u);
        oarrss_free(&Ku);
        oarrss_free(&b);
        free(indices);
        free(indptr);
        lilss_free(&lil);

    }

    {
        lilss_t lil = make_system(4, SET_B, 4, 2);
        oarrss_t b = make_soa(SET_A, 2, 4, 1, 2), u = make_soa(SET_A, 2, 4, 1, 2), val;
        int64_t *indices, *indptr;
        csrss_t K = to_csr(&lil, &val, &indices, &indptr);

        check(csrss_solve_rhs(&K, &u, 1, dhl) == CSRSS_ERR_SET, "solve_rhs: K set not in u's");
        check(csrss_solve_init(&K, &b, &u) == CSRSS_OK, "solve_init: status");
        check(csrss_solve_rhs(&K, &u, 0, dhl) == CSRSS_ERR_ORDER, "solve_rhs: order 0 refused");
        check(csrss_solve_rhs(&K, &u, 3, dhl) == CSRSS_ERR_ORDER, "solve_rhs: order above trc");

        oarrss_free(&b);
        b = make_soa(SET_A, 2, 3, 1, 2);
        check(csrss_solve_init(&K, &b, &u) == CSRSS_ERR_SIZE, "solve_init: shape mismatch");

        oarrss_free(&val);
        oarrss_free(&b);
        oarrss_free(&u);
        free(indices);
        free(indptr);
        lilss_free(&lil);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);

    test_builder_basics(dhl);
    test_builder_many();
    test_to_csr(dhl);
    test_matmul(dhl);
    test_solve(dhl);

    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse CSR test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse CSR tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
