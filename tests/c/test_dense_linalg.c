/* Independent checks of the dense SoA linear algebra (include/oti/dense/soa/linalg.h,
 * PLAN-dense-update.md WP3): oarr_lu_factor / oarr_lu_solve / oarr_solve_to / oarr_inv_to /
 * oarr_det_to. Oracles: the sparse arrso_t linear algebra (1e-13, well-conditioned real parts) and
 * the semi-sparse oarrss_ linear algebra over the active set [1..k] (1e-14: the coefficient layout of
 * a dense array over 1..k is byte-identical to the semi-sparse one). Operands are filled directly as
 * dense arrays and converted to the oracles here (not through oarr_to_arrso()), so the comparison
 * does not depend on the dense conversion functions.
 *
 * Covers n in {1, 2, 3, 4, 5, 8} at orders 1..5 (n >= 4 is the bug of the old dense det/invert),
 * K and b with different nact (either larger) and different trc, b with act_order below trc, real
 * and imaginary mixes, aliasing, lu_factor + several lu_solve calls, singular real parts (status
 * above 0, no crash, results freeable), shape/argument/pivot errors, the rank-fallback case (nact 11
 * at order 5, above Nbasis(5) = 10), the identities inv(A) A = I and det(A B) = det(A) det(B), and
 * 1 vs N OpenMP threads.
 *
 * Column-major SoA blocks: element (i, j) of block b is p_data[b*size + i + j*nrows]; arrso_t is
 * row-major, (i, j) at p_data[j + i*ncols]. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>

#ifdef _OPENMP
#include <omp.h>
#endif

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
static double rng_uniform(void){

    uint64_t x = g_rng_state;

    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    g_rng_state = x;

    return (double)(x >> 11) / (double)(1ULL << 53);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rng_range(double lo, double hi){

    return lo + (hi - lo) * rng_uniform();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int approx_equal(coeff_t a, coeff_t b, double tol){

    double diff = fabs(a - b);
    double scale = fmax(1.0, fmax(fabs(a), fabs(b)));

    return diff <= tol * scale;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COEFFICIENT ACCESS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Coefficient of the global direction (idx, p) of element (i, j) of a dense array; zero when the
 * direction is structurally absent (order above trc, base above nact). */
static coeff_t arr_coef(const oarr_t* A, uint64_t i, uint64_t j, imdir_t idx, ord_t p){

    if (p == 0){
        return A->p_data[i + j * A->nrows];
    }

    if (p > A->trc_order || idx >= sshelp_ndir_order(A->nact, p)){
        return 0.0;
    }

    return A->p_data[(1 + sshelp_order_offset(A->nact, p) + idx) * A->size + i + j * A->nrows];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Coefficient of the global direction (idx, p) of a dense number; zero when structurally absent. */
static coeff_t num_coef(const otinum_t* t, imdir_t idx, ord_t p){

    if (p == 0){
        return t->re;
    }

    if (p > t->trc_order || idx >= sshelp_ndir_order(t->nact, p)){
        return 0.0;
    }

    return t->p_im[sshelp_order_offset(t->nact, p) + idx];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Number of reals in the buffer of an array (all blocks). */
static uint64_t arr_nreals(const oarr_t* A){

    return (1 + sshelp_ndir_total(A->nact, A->trc_order)) * A->size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Largest absolute coefficient in the buffer of an array (NaN when any coefficient is NaN). */
static double arr_max_abs(const oarr_t* A){

    double res = 0.0;
    uint64_t i, n = arr_nreals(A);

    for (i = 0; i < n; i++){

        if (isnan(A->p_data[i])){
            return NAN;
        }

        res = fmax(res, fabs(A->p_data[i]));

    }

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A random nrows x ncols dense array over bases 1..k with truncation order trc. Real parts are in
 * [-0.5, 0.5], plus a dominant diagonal when diag is set (well conditioned). A `density` fraction of
 * the imaginary coefficients of orders 1..act is a nonzero in [-0.3, 0.3]. */
static oarr_t build_dense(uint64_t nrows, uint64_t ncols, bases_t k, ord_t trc, ord_t act,
                          double density, int diag){

    oarr_t A = oarr_init();
    uint64_t i, j, b, nblocks;
    int status = oarr_zeros_to(k, nrows, ncols, trc, &A);

    if (status != DN_OK){
        fprintf(stderr, "build_dense: oarr_zeros_to failed (%d)\n", status);
        n_failed++;
        return A;
    }

    for (j = 0; j < ncols; j++){

        for (i = 0; i < nrows; i++){

            A.p_data[i + j * nrows] = rng_range(-0.5, 0.5);

            if (diag && i == j){
                A.p_data[i + j * nrows] += 0.5 * (double)nrows + 1.0;
            }

        }

    }

    nblocks = 1 + sshelp_ndir_total(k, act);

    for (b = 1; b < nblocks; b++){

        for (j = 0; j < ncols; j++){

            for (i = 0; i < nrows; i++){

                if (rng_uniform() < density){
                    A.p_data[b * A.size + i + j * nrows] = rng_range(-0.3, 0.3);
                }

            }

        }

    }

    A.act_order = (k == 0) ? 0 : act;

    return A;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Sets the coefficient of block b at element (i, j) of a dense array. */
static void set_coef(oarr_t* A, uint64_t b, uint64_t i, uint64_t j, coeff_t v){

    A->p_data[b * A->size + i + j * A->nrows] = v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The same values as an arrso_t (row-major), through soti_set_item on every nonzero direction. */
static arrso_t to_arrso(const oarr_t* A, dhelpl_t dhl){

    arrso_t arr = arrso_zeros_bases(A->nrows, A->ncols, 0, A->trc_order, dhl);
    uint64_t i, j;
    imdir_t idx;
    ord_t p;

    for (i = 0; i < A->nrows; i++){

        for (j = 0; j < A->ncols; j++){

            sotinum_t* e = &arr.p_data[j + i * A->ncols];

            e->re = A->p_data[i + j * A->nrows];

            for (p = 1; p <= A->trc_order; p++){

                ndir_t np = sshelp_ndir_order(A->nact, p);

                for (idx = 0; idx < np; idx++){

                    coeff_t v = arr_coef(A, i, j, idx, p);

                    if (v != 0.0){
                        soti_set_item(v, idx, p, e, dhl);
                    }

                } // end for

            } // end for

        }

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The same values as a semi-sparse SoA array over the active set [1..k]: the coefficient layouts are
 * byte-identical, so the buffer is copied. */
static oarrss_t to_oarrss(const oarr_t* A){

    bases_t bases[64];
    bases_t u;
    oarrss_t s;

    for (u = 0; u < A->nact && u < 64; u++){
        bases[u] = u + 1;
    }

    s = oarrss_zeros(bases, A->nact, A->nrows, A->ncols, A->trc_order);

    if (A->size > 0){
        memcpy(s.p_data, A->p_data, (size_t)arr_nreals(A) * sizeof(coeff_t));
    }

    s.act_order = A->act_order;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Dense array against a dense array: same shape, nact and trc, every coefficient within tol. */
static void compare_dense_vs_dense(const oarr_t* a, const oarr_t* b, double tol, const char* ctx){

    uint64_t n_checked = 0, n_mismatch = 0, i, j;
    bases_t kmax;
    imdir_t idx;
    ord_t p;
    char name[256];

    if (a->nrows != b->nrows || a->ncols != b->ncols || a->nact != b->nact ||
        a->trc_order != b->trc_order){

        snprintf(name, sizeof(name), "%s: same shape, nact and trc (%llux%llu k=%u trc=%u vs "
                 "%llux%llu k=%u trc=%u)", ctx, (unsigned long long)a->nrows,
                 (unsigned long long)a->ncols, (unsigned)a->nact, (unsigned)a->trc_order,
                 (unsigned long long)b->nrows, (unsigned long long)b->ncols, (unsigned)b->nact,
                 (unsigned)b->trc_order);
        check(0, name);
        return;

    }

    kmax = a->nact;

    for (p = 0; p <= a->trc_order; p++){

        ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

        for (idx = 0; idx < np; idx++){

            for (j = 0; j < a->ncols; j++){

                for (i = 0; i < a->nrows; i++){

                    coeff_t v1 = arr_coef(a, i, j, idx, p), v2 = arr_coef(b, i, j, idx, p);

                    n_checked++;

                    if (!approx_equal(v1, v2, tol) && !(isnan(v1) && isnan(v2))){

                        if (n_mismatch < 5){
                            fprintf(stderr, "  mismatch %s (%llu,%llu) p=%u idx=%llu: %.17g vs %.17g\n",
                                    ctx, (unsigned long long)i, (unsigned long long)j, (unsigned)p,
                                    (unsigned long long)idx, v1, v2);
                        }

                        n_mismatch++;

                    }

                } // end for

            } // end for

        } // end for

    } // end for

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match", ctx,
             (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against the semi-sparse SoA result over [1..k] (bases 1..nbases), within tol. Checks
 * shape, nact = nbases, trc and act_order. */
static void compare_dense_vs_ss(const oarr_t* a, const oarrss_t* s, double tol, const char* ctx){

    uint64_t n_checked = 0, n_mismatch = 0, i, j, e;
    ndir_t idx;
    ord_t p;
    bases_t u;
    int prefix = 1;
    char name[256];

    for (u = 0; u < s->nbases; u++){
        prefix = prefix && (s->p_bases[u] == u + 1);
    }

    if (a->nrows != s->nrows || a->ncols != s->ncols || a->nact != s->nbases ||
        a->trc_order != s->trc_order || !prefix){

        snprintf(name, sizeof(name), "%s: dense and semi-sparse have the same shape, set, trc "
                 "(k=%u/%u trc=%u/%u)", ctx, (unsigned)a->nact, (unsigned)s->nbases,
                 (unsigned)a->trc_order, (unsigned)s->trc_order);
        check(0, name);
        return;

    }

    for (p = 0; p <= a->trc_order; p++){

        ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(a->nact, p);
        uint64_t bp = oarr_block_index(a->nact, p, 0);

        for (idx = 0; idx < np; idx++){

            for (j = 0; j < a->ncols; j++){

                for (i = 0; i < a->nrows; i++){

                    e = (bp + idx) * a->size + i + j * a->nrows;
                    n_checked++;

                    if (!approx_equal(a->p_data[e], s->p_data[e], tol) &&
                        !(isnan(a->p_data[e]) && isnan(s->p_data[e]))){

                        if (n_mismatch < 5){
                            fprintf(stderr, "  mismatch %s (%llu,%llu) p=%u idx=%llu: %.17g vs %.17g\n",
                                    ctx, (unsigned long long)i, (unsigned long long)j, (unsigned)p,
                                    (unsigned long long)idx, a->p_data[e], s->p_data[e]);
                        }

                        n_mismatch++;

                    }

                } // end for

            } // end for

        } // end for

    } // end for

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match semi-sparse", ctx,
             (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

    snprintf(name, sizeof(name), "%s: act_order %u covers semi-sparse's %u", ctx,
             (unsigned)a->act_order, (unsigned)s->act_order);
    check(a->act_order >= s->act_order && a->act_order <= a->trc_order, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against the sparse arrso_t oracle (row-major), over the directions of bases 1..kmax at
 * orders 1..trc of the dense array. The oracle's own truncation order must equal the dense one
 * (a real result may have any: the sparse types give real elements order 0). */
static void compare_dense_vs_arrso(const oarr_t* a, arrso_t* o, bases_t kmax, double tol,
                                   dhelpl_t dhl, const char* ctx){

    uint64_t n_checked = 0, n_mismatch = 0, i, j;
    imdir_t idx;
    ord_t p;
    int trc_ok = 1;
    char name[256];

    if (a->nrows != o->nrows || a->ncols != o->ncols){

        snprintf(name, sizeof(name), "%s: same shape as the sparse oracle", ctx);
        check(0, name);
        return;

    }

    for (i = 0; i < a->nrows; i++){

        for (j = 0; j < a->ncols; j++){

            sotinum_t* e = &o->p_data[j + i * o->ncols];

            trc_ok = trc_ok && (e->trc_order == a->trc_order || a->act_order == 0);

            for (p = 0; p <= a->trc_order; p++){

                ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

                for (idx = 0; idx < np; idx++){

                    coeff_t v1 = arr_coef(a, i, j, idx, p);
                    coeff_t v2 = (p == 0) ? e->re : soti_get_item(idx, p, e, dhl);

                    n_checked++;

                    if (!approx_equal(v1, v2, tol) && !(isnan(v1) && isnan(v2))){

                        if (n_mismatch < 5){
                            fprintf(stderr, "  mismatch %s (%llu,%llu) p=%u idx=%llu: %.17g vs %.17g\n",
                                    ctx, (unsigned long long)i, (unsigned long long)j, (unsigned)p,
                                    (unsigned long long)idx, v1, v2);
                        }

                        n_mismatch++;

                    }

                } // end for

            } // end for

        } // end for

    } // end for

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match sparse", ctx,
             (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

    snprintf(name, sizeof(name), "%s: sparse oracle has the same truncation order", ctx);
    check(trc_ok, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense number against a dense number (same nact and trc), within tol. */
static void compare_oti_vs_oti(const otinum_t* a, const otinum_t* b, double tol, const char* ctx){

    uint64_t n_checked = 0, n_mismatch = 0;
    bases_t kmax = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order, p;
    imdir_t idx;
    char name[256];

    for (p = 0; p <= trc; p++){

        ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

        for (idx = 0; idx < np; idx++){

            coeff_t v1 = num_coef(a, idx, p), v2 = num_coef(b, idx, p);

            n_checked++;

            if (!approx_equal(v1, v2, tol)){

                if (n_mismatch < 5){
                    fprintf(stderr, "  mismatch %s p=%u idx=%llu: %.17g vs %.17g\n", ctx,
                            (unsigned)p, (unsigned long long)idx, v1, v2);
                }

                n_mismatch++;

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match", ctx,
             (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0 && a->trc_order == b->trc_order, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense number against a semi-sparse number over [1..k] and against a sparse number, by global
 * direction; both oracles are optional (NULL to skip). */
static void compare_oti_vs_oracles(const otinum_t* a, const ssotinum_t* s, sotinum_t* o,
                                   double tol_ss, double tol_so, dhelpl_t dhl, const char* ctx){

    uint64_t bad_s = 0, bad_o = 0;
    bases_t kmax = a->nact;
    ord_t p;
    imdir_t idx;
    char name[256];

    if (s != NULL && s->nbases > kmax){
        kmax = s->nbases;
    }

    for (p = 0; p <= a->trc_order; p++){

        ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

        for (idx = 0; idx < np; idx++){

            coeff_t v = num_coef(a, idx, p);

            if (s != NULL && !approx_equal(v, (p == 0) ? s->re : ssoti_get_item(idx, p, s), tol_ss)){
                bad_s++;
            }

            if (o != NULL && !approx_equal(v, (p == 0) ? o->re : soti_get_item(idx, p, o, dhl), tol_so)){
                bad_o++;
            }

        }

    }

    if (s != NULL){

        snprintf(name, sizeof(name), "%s: matches semi-sparse (%llu bad, trc %u vs %u)", ctx,
                 (unsigned long long)bad_s, (unsigned)a->trc_order, (unsigned)s->trc_order);
        check(bad_s == 0 && a->trc_order == s->trc_order, name);

    }

    if (o != NULL){

        snprintf(name, sizeof(name), "%s: matches sparse (%llu bad, trc %u vs %u)", ctx,
                 (unsigned long long)bad_o, (unsigned)a->trc_order, (unsigned)o->trc_order);
        check(bad_o == 0 && a->trc_order == o->trc_order, name);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ROUND TRIP CASES     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Residual K x - b of a solve, as the largest absolute coefficient over every direction. */
static double solve_residual(const oarr_t* K, const oarr_t* x, const oarr_t* b, dhelpl_t dhl){

    oarr_t r = oarr_init();
    double res = NAN;

    if (oarr_matmul_OO_to(K, x, &r, dhl) == DN_OK && oarr_sub_OO_to(&r, b, &r, dhl) == DN_OK){
        res = arr_max_abs(&r);
    }

    oarr_free(&r);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Full round trip for one (K, b) pair: lu_factor + lu_solve, solve_to, inv_to and det_to against the
 * semi-sparse oracle (always) and the sparse oracle (when with_sparse), plus the residuals
 * K x = b and K inv(K) = I. */
static void run_case(const oarr_t* K, const oarr_t* b, int with_sparse, dhelpl_t dhl,
                     const char* ctx){

    uint64_t n = K->nrows;
    bases_t kmax = (K->nact > b->nact) ? K->nact : b->nact;
    oarrss_t sK = to_oarrss(K), sb = to_oarrss(b);
    arrso_t aK, ab;
    oarr_lu_t lu;
    oarr_t x_lu = oarr_init(), x = oarr_init();
    int status;
    char name[256];
    double res;

    if (with_sparse){
        aK = to_arrso(K, dhl);
        ab = to_arrso(b, dhl);
    }

    // lu_factor + lu_solve.
    status = oarr_lu_factor(K, &lu);
    snprintf(name, sizeof(name), "%s: lu_factor status (%d)", ctx, status);
    check(status == 0, name);

    status = oarr_lu_solve(&lu, b, &x_lu, dhl);
    snprintf(name, sizeof(name), "%s: lu_solve status (%d)", ctx, status);
    check(status == 0, name);

    // solve_to: identical to lu_factor + lu_solve, and against the oracles.
    status = oarr_solve_to(K, b, &x, dhl);
    snprintf(name, sizeof(name), "%s: solve_to status (%d)", ctx, status);
    check(status == 0, name);

    snprintf(name, sizeof(name), "%s: solve_to = lu_solve", ctx);
    compare_dense_vs_dense(&x, &x_lu, 0.0, name);

    snprintf(name, sizeof(name), "%s: solve act_order %u = trc, or 0 for a real result", ctx,
             (unsigned)x.act_order);
    check(x.act_order == ((K->act_order == 0 && b->act_order == 0) ? 0 : x.trc_order), name);
    check(x.nact == kmax, "solve: nact = max(nact_K, nact_b)");
    check(x.trc_order == ((K->trc_order > b->trc_order) ? K->trc_order : b->trc_order),
          "solve: trc = max(trc_K, trc_b)");

    {
        oarrss_t xs = oarrss_init();
        int st = oarrss_solve_to(&sK, &sb, &xs, dhl);

        check(st == 0, "semi-sparse solve status");
        snprintf(name, sizeof(name), "%s: solve vs semi-sparse", ctx);
        compare_dense_vs_ss(&x, &xs, 1e-14, name);
        oarrss_free(&xs);
    }

    if (with_sparse){

        arrso_t xo = arrso_zeros_bases(n, b->ncols, 0, 0, dhl);
        int st = arrso_solve_to(&aK, &ab, &xo, dhl);

        check(st == 0, "sparse solve status");
        snprintf(name, sizeof(name), "%s: solve vs sparse", ctx);
        compare_dense_vs_arrso(&x, &xo, kmax, 1e-13, dhl, name);
        arrso_free(&xo);

    }

    res = solve_residual(K, &x, b, dhl);
    snprintf(name, sizeof(name), "%s: residual K x - b = %.2e", ctx, res);
    check(res < 1e-11, name);

    // inv_to.
    {
        oarr_t inv = oarr_init(), eye = oarr_init();

        status = oarr_inv_to(K, &inv, dhl);
        snprintf(name, sizeof(name), "%s: inv_to status (%d)", ctx, status);
        check(status == 0, name);

        snprintf(name, sizeof(name), "%s: inv act_order %u = trc, or 0 for a real matrix", ctx,
                 (unsigned)inv.act_order);
        check(inv.act_order == ((K->act_order == 0) ? 0 : inv.trc_order), name);

        {
            oarrss_t is = oarrss_init();
            int st = oarrss_inv_to(&sK, &is, dhl);

            check(st == 0, "semi-sparse inv status");
            snprintf(name, sizeof(name), "%s: inv vs semi-sparse", ctx);
            compare_dense_vs_ss(&inv, &is, 1e-14, name);
            oarrss_free(&is);
        }

        if (with_sparse){

            arrso_t io = arrso_zeros_bases(n, n, 0, 0, dhl);
            int st = arrso_invert_to(&aK, &io, dhl);

            check(st == 0, "sparse inv status");
            snprintf(name, sizeof(name), "%s: inv vs sparse", ctx);
            compare_dense_vs_arrso(&inv, &io, K->nact, 1e-13, dhl, name);
            arrso_free(&io);

        }

        oarr_eye_to(n, K->trc_order, &eye);
        res = solve_residual(K, &inv, &eye, dhl);
        snprintf(name, sizeof(name), "%s: residual K inv(K) - I = %.2e", ctx, res);
        check(res < 1e-11, name);

        oarr_free(&inv);
        oarr_free(&eye);
    }

    // det_to.
    {
        otinum_t det = oti_init();

        status = oarr_det_to(K, &det, dhl);
        snprintf(name, sizeof(name), "%s: det_to status (%d)", ctx, status);
        check(status == 0, name);

        {
            ssotinum_t ds = ssoti_init();
            int st = oarrss_det_to(&sK, &ds, dhl);
            sotinum_t dor = soti_init();
            int sto = 0;

            check(st == 0, "semi-sparse det status");

            if (with_sparse){
                sto = arrso_det_to(&aK, &dor, dhl);
                check(sto == 0, "sparse det status");
            }

            snprintf(name, sizeof(name), "%s: det nact = nact_A, act_order %u = trc (0 if real)", ctx,
                     (unsigned)det.act_order);
            check(det.nact == K->nact &&
                  det.act_order == ((K->act_order == 0) ? 0 : det.trc_order), name);
            snprintf(name, sizeof(name), "%s: det", ctx);
            compare_oti_vs_oracles(&det, &ds, with_sparse ? &dor : NULL, 1e-14, 1e-13, dhl, name);

            ssoti_free(&ds);
            soti_free(&dor);
        }

        oti_free(&det);
    }

    if (with_sparse){
        arrso_free(&aK);
        arrso_free(&ab);
    }

    oarr_lu_free(&lu);
    oarr_free(&x_lu);
    oarr_free(&x);
    oarrss_free(&sK);
    oarrss_free(&sb);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* n in {1, 2, 3, 4, 5, 8} at orders 1..5, k = 3 for both operands (n >= 4 is the old dense bug). */
static void test_oracle_grid(dhelpl_t dhl){

    static const uint64_t NS[6] = {1, 2, 3, 4, 5, 8};
    size_t c;
    ord_t trc;
    char ctx[64];

    for (c = 0; c < 6; c++){

        for (trc = 1; trc <= 5; trc++){

            oarr_t K, b;

            rng_seed(1000 * NS[c] + trc);
            K = build_dense(NS[c], NS[c], 3, trc, trc, 0.6, 1);
            b = build_dense(NS[c], 2, 3, trc, trc, 0.6, 0);

            snprintf(ctx, sizeof(ctx), "grid n=%llu trc=%u", (unsigned long long)NS[c],
                     (unsigned)trc);
            run_case(&K, &b, 1, dhl, ctx);

            oarr_free(&K);
            oarr_free(&b);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Operand relations: b with a smaller or a larger nact than K (prefix operands), nact = 0, mixed trc
 * in both directions, b with act_order below trc, K real with imaginary b, b real with imaginary K,
 * a real K that has bases, and several right-hand-side columns. */
static void test_operand_relations(dhelpl_t dhl){

    static const struct {
        uint64_t n; uint64_t m;
        bases_t kK; ord_t trcK, actK;
        bases_t kb; ord_t trcb, actb;
        const char* label;
    } CASES[] = {
        {5, 2, 2, 3, 3, 4, 3, 3, "b_larger_nact"},
        {5, 2, 4, 3, 3, 2, 3, 3, "K_larger_nact"},
        {4, 1, 3, 4, 4, 0, 4, 0, "b_nact0"},
        {4, 1, 0, 4, 0, 3, 4, 4, "K_nact0"},
        {4, 3, 0, 3, 0, 0, 3, 0, "both_nact0"},
        {4, 2, 3, 2, 2, 3, 4, 4, "trc_b_larger"},
        {4, 2, 3, 4, 4, 3, 2, 2, "trc_K_larger"},
        {4, 2, 2, 5, 5, 4, 3, 3, "trc_K_larger_and_b_larger_nact"},
        {5, 2, 3, 4, 4, 3, 4, 2, "b_act_lt_trc"},
        {4, 2, 3, 4, 2, 3, 4, 4, "K_act_lt_trc"},
        {4, 2, 3, 4, 0, 3, 4, 4, "K_real_b_imag"},
        {4, 2, 3, 4, 4, 3, 4, 0, "K_imag_b_real"},
        {4, 2, 3, 3, 0, 3, 4, 2, "K_real_b_act_lt_trc"},
        {4, 2, 3, 3, 0, 3, 3, 0, "both_real_with_bases"},
        {6, 3, 3, 3, 3, 3, 3, 3, "multi_rhs"},
    };
    size_t c;

    for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

        oarr_t K, b;

        rng_seed(77 + c);
        K = build_dense(CASES[c].n, CASES[c].n, CASES[c].kK, CASES[c].trcK, CASES[c].actK, 0.6, 1);
        b = build_dense(CASES[c].n, CASES[c].m, CASES[c].kb, CASES[c].trcb, CASES[c].actb, 0.6, 0);

        run_case(&K, &b, 1, dhl, CASES[c].label);

        oarr_free(&K);
        oarr_free(&b);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Rank-fallback case: nact 11 is above Nbasis(5) = 10, so the product pairs of the order-5 solve leave
 * the global multiplication table. Semi-sparse over [1..11] and the residual K x = b are the
 * oracles (the sparse type cannot hold these labels). Also K with fewer bases than b. */
static void test_fallback_k11(dhelpl_t dhl){

    static const struct {
        bases_t kK, kb; ord_t trc; uint64_t n;
        const char* label;
    } CASES[] = {
        {11, 11, 5, 3, "k11_order5"},
        {11, 11, 4, 3, "k11_order4"},
        {4, 11, 5, 2, "k4_b_k11_order5"},
        {11, 4, 5, 2, "k11_b_k4_order5"},
    };
    size_t c;

    for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

        oarr_t K, b;

        rng_seed(900 + c);
        K = build_dense(CASES[c].n, CASES[c].n, CASES[c].kK, CASES[c].trc, CASES[c].trc, 0.3, 1);
        b = build_dense(CASES[c].n, 2, CASES[c].kb, CASES[c].trc, CASES[c].trc, 0.3, 0);

        run_case(&K, &b, 0, dhl, CASES[c].label);

        oarr_free(&K);
        oarr_free(&b);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Hand values. A is the upper triangular T, T(i,i) = i + 1 with T(0,0) = 1 + e1 and T(2,2) = 3 - e1,
 * T(i,j) = 0.5 (i + j) + 1 + (0.1 (i + 2 j)) e1 + (0.05 (j - i)) e1^2 for j > i, with rows 0 and 1
 * swapped (zero leading real entry: forces pivoting). det A = -det T = -24 - 16 e1 + 8 e1^2, and
 * A inv(A) = I in every direction. */
static void test_hand_4x4(dhelpl_t dhl){

    oarr_t T = oarr_init(), A = oarr_init(), inv = oarr_init(), eye = oarr_init();
    otinum_t det = oti_init();
    uint64_t i, j, r;
    int status;

    oarr_zeros_to(1, 4, 4, 2, &T);
    oarr_zeros_to(1, 4, 4, 2, &A);

    for (i = 0; i < 4; i++){

        for (j = i; j < 4; j++){

            set_coef(&T, 0, i, j, (i == j) ? (double)(i + 1) : 0.5 * (double)(i + j) + 1.0);

            if (j > i){
                set_coef(&T, 1, i, j, 0.1 * (double)(i + 2 * j));
                set_coef(&T, 2, i, j, 0.05 * (double)(j - i));
            }

        }

    }

    set_coef(&T, 1, 0, 0, 1.0);
    set_coef(&T, 1, 2, 2, -1.0);
    T.act_order = 2;

    for (j = 0; j < 4; j++){

        for (i = 0; i < 4; i++){

            r = (i == 0) ? 1 : ((i == 1) ? 0 : i);
            A.p_data[i + j * 4] = T.p_data[r + j * 4];
            A.p_data[16 + i + j * 4] = T.p_data[16 + r + j * 4];
            A.p_data[32 + i + j * 4] = T.p_data[32 + r + j * 4];

        }

    }

    A.act_order = 2;

    status = oarr_det_to(&A, &det, dhl);
    check(status == 0, "hand 4x4: det status");
    check(fabs(det.re + 24.0) < 1e-12 * 24.0, "hand 4x4: det real part -24");
    check(fabs(num_coef(&det, 0, 1) + 16.0) < 1e-12 * 16.0, "hand 4x4: det e1 coefficient -16");
    check(fabs(num_coef(&det, 0, 2) - 8.0) < 1e-12 * 8.0, "hand 4x4: det e1^2 coefficient 8");
    check(det.nact == 1 && det.trc_order == 2, "hand 4x4: det nact and trc");

    status = oarr_inv_to(&A, &inv, dhl);
    check(status == 0, "hand 4x4: inv status");
    oarr_eye_to(4, 2, &eye);
    check(solve_residual(&A, &inv, &eye, dhl) < 1e-12, "hand 4x4: A inv(A) = I in every direction");
    check(solve_residual(&inv, &A, &eye, dhl) < 1e-12, "hand 4x4: inv(A) A = I in every direction");

    oarr_free(&T);
    oarr_free(&A);
    oarr_free(&inv);
    oarr_free(&eye);
    oti_free(&det);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Real matrices, empty matrices and the determinant's result handling. det of a 1 x 1 is its element;
 * a matrix with no imaginary part gives a real determinant (nact 0, the requested trc) even into a
 * result that held a larger number; 0 x 0 matrices give det 1, an empty inverse and an empty solve. */
static void test_real_and_empty(dhelpl_t dhl){

    oarr_t A, b, x = oarr_init(), inv = oarr_init(), one, e0 = oarr_init();
    otinum_t det = oti_create_empty(5, 4), elem = oti_init();
    int status;

    // 1 x 1: det is the element itself.
    rng_seed(5);
    one = build_dense(1, 1, 3, 4, 4, 1.0, 1);
    status = oarr_det_to(&one, &det, dhl);
    check(status == 0, "1x1 det status");
    oarr_get_item_to(0, 0, &one, &elem);
    compare_oti_vs_oti(&det, &elem, 1e-14, "1x1 det = element");

    // Real 3 x 3 with a result number that held a larger one.
    A = build_dense(3, 3, 0, 2, 0, 0.0, 1);
    status = oarr_det_to(&A, &det, dhl);
    check(status == 0 && det.nact == 0 && det.trc_order == 2 && det.act_order == 0,
          "real 3x3 det: real result, nact 0, trc 2");
    check(fabs(det.re - (A.p_data[0] * (A.p_data[4] * A.p_data[8] - A.p_data[7] * A.p_data[5])
                        - A.p_data[3] * (A.p_data[1] * A.p_data[8] - A.p_data[7] * A.p_data[2])
                        + A.p_data[6] * (A.p_data[1] * A.p_data[5] - A.p_data[4] * A.p_data[2]))) < 1e-12,
          "real 3x3 det: cofactor expansion");

    // Matrix with bases but no nonzero imaginary part (act_order 0).
    b = build_dense(3, 3, 2, 3, 0, 0.0, 1);
    status = oarr_det_to(&b, &det, dhl);
    check(status == 0 && det.nact == 2 && det.trc_order == 3 && det.act_order == 0,
          "act_order 0 with bases: real det keeps nact 2, act_order 0");

    status = oarr_inv_to(&b, &inv, dhl);
    check(status == 0 && inv.act_order == 0 && inv.trc_order == 3 && inv.nact == 2,
          "act_order 0 with bases: inverse is real with nact 2");
    oarr_free(&b);

    // Empty matrices.
    oarr_zeros_to(0, 0, 0, 3, &e0);
    status = oarr_det_to(&e0, &det, dhl);
    check(status == 0 && det.re == 1.0 && det.nact == 0, "0x0 det is 1");
    status = oarr_inv_to(&e0, &inv, dhl);
    check(status == 0 && inv.nrows == 0 && inv.ncols == 0, "0x0 inverse is empty");
    status = oarr_solve_to(&e0, &e0, &x, dhl);
    check(status == 0 && x.nrows == 0, "0x0 solve is empty");

    oarr_free(&A);
    oarr_free(&one);
    oarr_free(&e0);
    oarr_free(&x);
    oarr_free(&inv);
    oti_free(&det);
    oti_free(&elem);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ALIASING AND REUSE     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* x aliasing b, x aliasing K, inv(A, A) and lu_solve with x aliasing b give the same values as the
 * non-aliased calls (identical, the algorithm is the same). Also with a b of larger nact and larger
 * trc than K, where the aliased result changes shape. */
static void test_aliasing(dhelpl_t dhl){

    static const struct { bases_t kK, kb; ord_t trcK, trcb; const char* label; } CASES[] = {
        {3, 3, 3, 3, "equal"},
        {2, 4, 3, 4, "b_larger"},
        {4, 2, 4, 3, "K_larger"},
    };
    size_t c;
    char name[128];

    for (c = 0; c < 3; c++){

        oarr_t K, b, ref = oarr_init(), y = oarr_init(), Kcopy = oarr_init();
        oarr_lu_t lu;
        int status;

        rng_seed(300 + c);
        K = build_dense(5, 5, CASES[c].kK, CASES[c].trcK, CASES[c].trcK, 0.6, 1);
        b = build_dense(5, 2, CASES[c].kb, CASES[c].trcb, CASES[c].trcb, 0.6, 0);

        status = oarr_solve_to(&K, &b, &ref, dhl);
        check(status == 0, "aliasing: reference solve status");

        // x == b.
        oarr_copy_to(&b, &y);
        status = oarr_solve_to(&K, &y, &y, dhl);
        snprintf(name, sizeof(name), "aliasing %s: solve_to x == b", CASES[c].label);
        check(status == 0, name);
        compare_dense_vs_dense(&y, &ref, 0.0, name);

        // lu_solve with x == b.
        oarr_lu_factor(&K, &lu);
        oarr_copy_to(&b, &y);
        status = oarr_lu_solve(&lu, &y, &y, dhl);
        snprintf(name, sizeof(name), "aliasing %s: lu_solve x == b", CASES[c].label);
        check(status == 0, name);
        compare_dense_vs_dense(&y, &ref, 0.0, name);
        oarr_lu_free(&lu);

        // x == K (K square 5 x 5 and b 5 x 5, so the shapes agree).
        {
            oarr_t b5 = build_dense(5, 5, CASES[c].kb, CASES[c].trcb, CASES[c].trcb, 0.6, 0);
            oarr_t ref5 = oarr_init();

            oarr_solve_to(&K, &b5, &ref5, dhl);
            oarr_copy_to(&K, &Kcopy);
            status = oarr_solve_to(&Kcopy, &b5, &Kcopy, dhl);
            snprintf(name, sizeof(name), "aliasing %s: solve_to x == K", CASES[c].label);
            check(status == 0, name);
            compare_dense_vs_dense(&Kcopy, &ref5, 0.0, name);

            oarr_free(&b5);
            oarr_free(&ref5);
        }

        // inv(A, A).
        oarr_inv_to(&K, &ref, dhl);
        oarr_copy_to(&K, &y);
        status = oarr_inv_to(&y, &y, dhl);
        snprintf(name, sizeof(name), "aliasing %s: inv_to res == A", CASES[c].label);
        check(status == 0, name);
        compare_dense_vs_dense(&y, &ref, 0.0, name);

        oarr_free(&K);
        oarr_free(&b);
        oarr_free(&ref);
        oarr_free(&y);
        oarr_free(&Kcopy);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* One factorization, several lu_solve calls with right-hand sides of different nact, trc and width;
 * each equals a fresh solve_to. The result buffer is reused between calls (grown or shrunk shape). */
static void test_lu_reuse(dhelpl_t dhl){

    static const struct { uint64_t m; bases_t kb; ord_t trcb; } RHS[4] = {
        {1, 3, 4}, {3, 5, 4}, {2, 1, 2}, {4, 0, 3},
    };
    oarr_t K, x = oarr_init(), ref = oarr_init();
    oarr_lu_t lu;
    size_t c;
    int status;
    char name[128];

    rng_seed(4242);
    K = build_dense(6, 6, 3, 4, 4, 0.6, 1);

    status = oarr_lu_factor(&K, &lu);
    check(status == 0, "lu reuse: factor status");
    check(lu.A.nrows == 6 && lu.p_ipiv != NULL, "lu reuse: factorization holds the matrix and pivots");

    for (c = 0; c < 4; c++){

        oarr_t b = build_dense(6, RHS[c].m, RHS[c].kb, RHS[c].trcb, RHS[c].trcb, 0.6, 0);

        status = oarr_lu_solve(&lu, &b, &x, dhl);
        snprintf(name, sizeof(name), "lu reuse: solve %zu status", c);
        check(status == 0, name);

        oarr_solve_to(&K, &b, &ref, dhl);
        snprintf(name, sizeof(name), "lu reuse: solve %zu = solve_to", c);
        compare_dense_vs_dense(&x, &ref, 0.0, name);

        snprintf(name, sizeof(name), "lu reuse: solve %zu residual", c);
        check(solve_residual(&K, &x, &b, dhl) < 1e-11, name);

        oarr_free(&b);

    }

    // The factorization is not modified by the solves.
    {
        oarr_t b = build_dense(6, 1, 3, 4, 4, 0.6, 0);

        oarr_lu_solve(&lu, &b, &x, dhl);
        oarr_lu_solve(&lu, &b, &ref, dhl);
        compare_dense_vs_dense(&x, &ref, 0.0, "lu reuse: repeated solve of the same b");
        oarr_free(&b);
    }

    oarr_lu_free(&lu);
    check(lu.p_ipiv == NULL && lu.A.p_data == NULL, "lu_free leaves the factorization empty");
    oarr_lu_free(&lu);      // twice: no-op.

    oarr_free(&K);
    oarr_free(&x);
    oarr_free(&ref);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* inv(A) A = A inv(A) = I, det(A B) = det(A) det(B) and det(inv(A)) det(A) = 1, in every direction. */
static void test_identities(dhelpl_t dhl){

    static const struct { uint64_t n; bases_t k; ord_t trc; } CASES[] = {
        {4, 3, 4}, {5, 2, 5}, {8, 3, 3},
    };
    size_t c;
    char name[128];

    for (c = 0; c < 3; c++){

        oarr_t A, B, AB = oarr_init(), Ai = oarr_init(), P = oarr_init(), I = oarr_init(),
               D = oarr_init();
        otinum_t dA = oti_init(), dB = oti_init(), dAB = oti_init(), dAi = oti_init(),
                 prod = oti_init(), unit = oti_init();
        uint64_t n = CASES[c].n;
        int status;

        rng_seed(600 + c);
        A = build_dense(n, n, CASES[c].k, CASES[c].trc, CASES[c].trc, 0.7, 1);
        B = build_dense(n, n, CASES[c].k, CASES[c].trc, CASES[c].trc, 0.7, 1);

        oarr_inv_to(&A, &Ai, dhl);
        oarr_eye_to(n, CASES[c].trc, &I);

        oarr_matmul_OO_to(&Ai, &A, &P, dhl);
        oarr_sub_OO_to(&P, &I, &D, dhl);
        snprintf(name, sizeof(name), "identity n=%llu: inv(A) A = I (%.1e)", (unsigned long long)n,
                 arr_max_abs(&D));
        check(arr_max_abs(&D) < 1e-11, name);

        oarr_matmul_OO_to(&A, &Ai, &P, dhl);
        oarr_sub_OO_to(&P, &I, &D, dhl);
        snprintf(name, sizeof(name), "identity n=%llu: A inv(A) = I (%.1e)", (unsigned long long)n,
                 arr_max_abs(&D));
        check(arr_max_abs(&D) < 1e-11, name);

        oarr_matmul_OO_to(&A, &B, &AB, dhl);
        status = oarr_det_to(&A, &dA, dhl);
        status |= oarr_det_to(&B, &dB, dhl);
        status |= oarr_det_to(&AB, &dAB, dhl);
        status |= oarr_det_to(&Ai, &dAi, dhl);
        check(status == 0, "identity: det statuses");

        oti_mul_oo_to(&dA, &dB, &prod, dhl);
        snprintf(name, sizeof(name), "identity n=%llu: det(A B) = det(A) det(B)", (unsigned long long)n);
        compare_oti_vs_oti(&dAB, &prod, 1e-12, name);

        oti_mul_oo_to(&dA, &dAi, &prod, dhl);
        oti_create_empty_to(0, CASES[c].trc, &unit);
        unit.re = 1.0;
        snprintf(name, sizeof(name), "identity n=%llu: det(inv(A)) det(A) = 1", (unsigned long long)n);
        compare_oti_vs_oti(&prod, &unit, 1e-12, name);

        oarr_free(&A);
        oarr_free(&B);
        oarr_free(&AB);
        oarr_free(&Ai);
        oarr_free(&P);
        oarr_free(&I);
        oarr_free(&D);
        oti_free(&dA);
        oti_free(&dB);
        oti_free(&dAB);
        oti_free(&dAi);
        oti_free(&prod);
        oti_free(&unit);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     FAILURES     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Singular real part (row 1 = 0; a single zero for n = 1) with imaginary parts present: every
 * function reports status > 0 (the LAPACK pivot index, equal to the semi-sparse status), does not
 * crash, and leaves its result freeable. */
static void test_singular(dhelpl_t dhl){

    static const uint64_t NS[4] = {1, 2, 4, 5};
    size_t c;
    char name[128];

    for (c = 0; c < 4; c++){

        uint64_t n = NS[c], j;
        oarr_t K, b, x = oarr_init(), inv = oarr_init();
        oarr_lu_t lu;
        otinum_t det = oti_create_empty(2, 2);
        oarrss_t sK, sb, sx = oarrss_init();
        int st, st_ss;

        rng_seed(50 + n);
        K = build_dense(n, n, 2, 3, 3, 0.7, 1);
        b = build_dense(n, 2, 2, 3, 3, 0.7, 0);

        if (n == 1){
            K.p_data[0] = 0.0;
        } else {

            for (j = 0; j < n; j++){
                K.p_data[1 + j * n] = 0.0;
            }

        }

        sK = to_oarrss(&K);
        sb = to_oarrss(&b);

        st    = oarr_lu_factor(&K, &lu);
        st_ss = 0;
        snprintf(name, sizeof(name), "singular n=%llu: lu_factor status %d > 0",
                 (unsigned long long)n, st);
        check(st > 0, name);

        {
            oarrss_lu_t slu;

            st_ss = oarrss_lu_factor(&sK, &slu);
            snprintf(name, sizeof(name), "singular n=%llu: lu_factor status = semi-sparse's (%d)",
                     (unsigned long long)n, st_ss);
            check(st == st_ss, name);
            oarrss_lu_free(&slu);
        }

        // lu_solve on the factorization of a singular matrix: the same info, x untouched.
        {
            oarr_t xs = oarr_init();
            int st_lu = oarr_lu_solve(&lu, &b, &xs, dhl);

            snprintf(name, sizeof(name), "singular n=%llu: lu_solve on the factors gives %d = %d",
                     (unsigned long long)n, st_lu, st);
            check(st_lu == st, name);
            check(xs.p_data == NULL && xs.nrows == 0 && xs.nact == 0, "singular: lu_solve leaves x");

            oarr_copy_to(&b, &xs);
            st_lu = oarr_lu_solve(&lu, &xs, &xs, dhl);
            check(st_lu == st, "singular: lu_solve with x == b gives info");
            compare_dense_vs_dense(&xs, &b, 0.0, "singular: lu_solve with x == b leaves b");
            oarr_free(&xs);
        }

        oarr_lu_free(&lu);

        st = oarr_solve_to(&K, &b, &x, dhl);
        snprintf(name, sizeof(name), "singular n=%llu: solve_to status %d > 0",
                 (unsigned long long)n, st);
        check(st > 0 && st == oarrss_solve_to(&sK, &sb, &sx, dhl), name);

        st = oarr_inv_to(&K, &inv, dhl);
        snprintf(name, sizeof(name), "singular n=%llu: inv_to status %d > 0", (unsigned long long)n, st);
        check(st > 0, name);

        st = oarr_det_to(&K, &det, dhl);
        snprintf(name, sizeof(name), "singular n=%llu: det_to status %d > 0", (unsigned long long)n, st);
        check(st > 0, name);

        // The results are valid and freeable (and untouched by a failed call).
        check(det.nact == 2 && det.trc_order == 2, "singular: det result left untouched");
        oarr_free(&x);
        oarr_free(&inv);
        oti_free(&det);
        oarr_free(&K);
        oarr_free(&b);
        oarrss_free(&sK);
        oarrss_free(&sb);
        oarrss_free(&sx);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Shape, size, pivot and argument errors. Sizes past the LAPACK integer range and coefficient counts
 * past size_t are rejected before any buffer is touched, so the operands can be shells. */
static void test_errors(dhelpl_t dhl){

    oarr_t A, R, b, b_bad, x = oarr_init(), inv = oarr_init(), huge = oarr_init();
    oarr_lu_t lu, lu2;
    otinum_t det = oti_init();
    int st;

    rng_seed(8);
    A     = build_dense(3, 3, 2, 3, 3, 0.5, 1);
    R     = build_dense(3, 4, 2, 3, 3, 0.5, 0);
    b     = build_dense(3, 2, 2, 3, 3, 0.5, 0);
    b_bad = build_dense(4, 2, 2, 3, 3, 0.5, 0);

    // Non-square.
    st = oarr_lu_factor(&R, &lu);
    check(st == DN_ERR_SIZE && lu.p_ipiv == NULL, "non-square: lu_factor DN_ERR_SIZE");
    oarr_lu_free(&lu);
    check(oarr_solve_to(&R, &b, &x, dhl) == DN_ERR_SIZE, "non-square: solve_to DN_ERR_SIZE");
    check(oarr_inv_to(&R, &inv, dhl) == DN_ERR_SIZE, "non-square: inv_to DN_ERR_SIZE");
    check(oarr_det_to(&R, &det, dhl) == DN_ERR_SIZE, "non-square: det_to DN_ERR_SIZE");

    // Mismatched right-hand side rows.
    check(oarr_solve_to(&A, &b_bad, &x, dhl) == DN_ERR_SIZE, "mismatched b rows: solve_to DN_ERR_SIZE");

    // Pivot indices out of range.
    oarr_lu_factor(&A, &lu);
    lu.p_ipiv[1] = 99;
    check(oarr_lu_solve(&lu, &b, &x, dhl) == DN_ERR_PIVOT, "pivot above n: DN_ERR_PIVOT");
    lu.p_ipiv[1] = 0;
    check(oarr_lu_solve(&lu, &b, &x, dhl) == DN_ERR_PIVOT, "pivot 0: DN_ERR_PIVOT");
    lu.p_ipiv[1] = 2;
    check(oarr_lu_solve(&lu, &b, &x, dhl) == DN_OK, "valid pivots again: DN_OK");
    oarr_lu_free(&lu);

    // NULL arguments.
    check(oarr_lu_factor(NULL, &lu2) == DN_ERR_ARGUMENT, "NULL A: lu_factor DN_ERR_ARGUMENT");
    oarr_lu_free(&lu2);
    check(oarr_lu_factor(&A, NULL) == DN_ERR_ARGUMENT, "NULL lu: lu_factor DN_ERR_ARGUMENT");
    check(oarr_solve_to(&A, &b, NULL, dhl) == DN_ERR_ARGUMENT, "NULL x: solve_to DN_ERR_ARGUMENT");
    check(oarr_inv_to(&A, NULL, dhl) == DN_ERR_ARGUMENT, "NULL res: inv_to DN_ERR_ARGUMENT");
    check(oarr_det_to(&A, NULL, dhl) == DN_ERR_ARGUMENT, "NULL res: det_to DN_ERR_ARGUMENT");
    oarr_lu_free(NULL);

    // Dimensions past the LAPACK integers (2^32): shells with no buffers.
    huge        = oarr_init();
    huge.nrows  = 1ULL << 32;
    huge.ncols  = 1ULL << 32;
    check(oarr_lu_factor(&huge, &lu2) == DN_ERR_SIZE, "n = 2^32: lu_factor DN_ERR_SIZE");
    oarr_lu_free(&lu2);
    check(oarr_det_to(&huge, &det, dhl) == DN_ERR_SIZE, "n = 2^32: det_to DN_ERR_SIZE");
    check(oarr_inv_to(&huge, &inv, dhl) == DN_ERR_SIZE, "n = 2^32: inv_to DN_ERR_SIZE");

    huge       = oarr_init();
    huge.nrows = 3;
    huge.ncols = 1ULL << 32;
    oarr_lu_factor(&A, &lu);
    check(oarr_lu_solve(&lu, &huge, &x, dhl) == DN_ERR_SIZE,
          "b with 2^32 columns: lu_solve DN_ERR_SIZE");

    // Coefficient counts past size_t: nact 60000 at order 5 (C(60005, 5) > 2^64).
    huge        = oarr_init();
    huge.nrows  = 3;
    huge.ncols  = 1;
    huge.size   = 3;
    huge.nact   = 60000;
    huge.nbases = 60000;
    huge.trc_order = 5;
    check(oarr_lu_solve(&lu, &huge, &x, dhl) == DN_ERR_MEMORY,
          "coefficient count overflow: lu_solve DN_ERR_MEMORY");
    oarr_lu_free(&lu);

    huge.nrows = 3;
    huge.ncols = 3;
    huge.size  = 9;
    check(oarr_det_to(&huge, &det, dhl) == DN_ERR_MEMORY,
          "coefficient count overflow: det_to DN_ERR_MEMORY");

    // After every failure the outputs are still valid and freeable.
    oarr_free(&x);
    oarr_free(&inv);
    oti_free(&det);
    oarr_free(&A);
    oarr_free(&R);
    oarr_free(&b);
    oarr_free(&b_bad);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     OPENMP THREAD COUNT     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* solve, inv and det with 1 and with several OpenMP threads agree to 1e-14 (BLAS may reorder sums). */
static void test_threads(dhelpl_t dhl){

#ifdef _OPENMP
    int max_threads = omp_get_max_threads();
#endif
    oarr_t K, b, x1 = oarr_init(), xn = oarr_init(), i1 = oarr_init(), in = oarr_init();
    otinum_t d1 = oti_init(), dn = oti_init();

    rng_seed(31337);
    K = build_dense(8, 8, 4, 4, 4, 0.6, 1);
    b = build_dense(8, 3, 4, 4, 4, 0.6, 0);

#ifdef _OPENMP
    omp_set_num_threads(1);
#endif
    oarr_solve_to(&K, &b, &x1, dhl);
    oarr_inv_to(&K, &i1, dhl);
    oarr_det_to(&K, &d1, dhl);

#ifdef _OPENMP
    omp_set_num_threads((max_threads > 1) ? max_threads : 4);
#endif
    oarr_solve_to(&K, &b, &xn, dhl);
    oarr_inv_to(&K, &in, dhl);
    oarr_det_to(&K, &dn, dhl);

#ifdef _OPENMP
    omp_set_num_threads(max_threads);
#endif

    compare_dense_vs_dense(&x1, &xn, 1e-14, "threads: solve 1 vs N");
    compare_dense_vs_dense(&i1, &in, 1e-14, "threads: inv 1 vs N");
    compare_oti_vs_oti(&d1, &dn, 1e-14, "threads: det 1 vs N");

    oarr_free(&K);
    oarr_free(&b);
    oarr_free(&x1);
    oarr_free(&xn);
    oarr_free(&i1);
    oarr_free(&in);
    oti_free(&d1);
    oti_free(&dn);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Independent systems solved concurrently from an OpenMP parallel region (how a per-point Gauss LU
 * would call it): k = 11 at order 4 (the local product-table cache is built on first use), 16
 * systems, bitwise equal to the serial results. */
static void test_concurrent(dhelpl_t dhl){

#ifdef _OPENMP
    enum { NSYS = 16 };
    oarr_t K[NSYS], b[NSYS], xs[NSYS], xp[NSYS];
    otinum_t ds[NSYS], dp[NSYS];
    int st_s[NSYS], st_p[NSYS], dst_s[NSYS], dst_p[NSYS], bad = 0, max_threads = omp_get_max_threads();
    int i;

    for (i = 0; i < NSYS; i++){

        rng_seed(7000 + i);
        K[i]  = build_dense(3, 3, 11, 4, 4, 0.2, 1);
        b[i]  = build_dense(3, 2, 11, 4, 4, 0.2, 0);
        xs[i] = oarr_init();
        xp[i] = oarr_init();
        ds[i] = oti_init();
        dp[i] = oti_init();

    }

    for (i = 0; i < NSYS; i++){

        st_s[i]  = oarr_solve_to(&K[i], &b[i], &xs[i], dhl);
        dst_s[i] = oarr_det_to(&K[i], &ds[i], dhl);

    }

    omp_set_num_threads((max_threads > 1) ? max_threads : 4);

    #pragma omp parallel for schedule(static, 1)
    for (i = 0; i < NSYS; i++){

        st_p[i]  = oarr_solve_to(&K[i], &b[i], &xp[i], dhl);
        dst_p[i] = oarr_det_to(&K[i], &dp[i], dhl);

    }

    // Every worker thread keeps a per-thread workspace (oti_ws()): release them before leak checking.
    #pragma omp parallel
    {
        oti_ws_release();
    }

    omp_set_num_threads(max_threads);

    for (i = 0; i < NSYS; i++){

        bad += (st_s[i] != 0 || st_p[i] != 0 || dst_s[i] != 0 || dst_p[i] != 0);
        bad += (xs[i].nact != xp[i].nact || xs[i].trc_order != xp[i].trc_order ||
                memcmp(xs[i].p_data, xp[i].p_data, (size_t)arr_nreals(&xs[i]) * sizeof(coeff_t)) != 0);
        bad += (ds[i].nact != dp[i].nact || ds[i].trc_order != dp[i].trc_order ||
                memcmp(ds[i].p_im, dp[i].p_im,
                       (size_t)sshelp_ndir_total(ds[i].nact, ds[i].trc_order) * sizeof(coeff_t)) != 0 ||
                ds[i].re != dp[i].re);

        oarr_free(&K[i]);
        oarr_free(&b[i]);
        oarr_free(&xs[i]);
        oarr_free(&xp[i]);
        oti_free(&ds[i]);
        oti_free(&dp[i]);

    }

    check(bad == 0, "concurrent: 16 systems (k = 11, order 4) from a parallel for, bitwise = serial");
#else
    (void)dhl;
    printf("skipped: concurrent solves (not built with OpenMP)\n");
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Child run with OTI_DENSE_MAX_MB=1 (131072 reals per buffer): the solve scratch X and the expanded A go
 * through the byte budget before anything is allocated or written, so a wide right-hand side against a
 * matrix over many bases, or a right-hand side over more bases than the matrix, gives DN_ERR_MEMORY with
 * the result untouched, while a solve within the budget works. */
static void test_budget_child(dhelpl_t dhl){

    oarr_t K, b_wide = oarr_init(), b_many, b_ok = oarr_init(), x = oarr_init();
    oarr_lu_t lu;
    int status;

    rng_seed(99);
    K      = build_dense(2, 2, 100, 2, 2, 0.01, 1);       // 5152 blocks of 4 reals: within the budget.
    b_many = build_dense(2, 1, 300, 2, 0, 0.0, 0);        // 45451 blocks of 2 reals; A expanded: 181804.
    oarr_zeros_to(0, 2, 100, 0, &b_wide);                 // X = 5152 * 200 reals = 1.03 M > budget.
    oarr_zeros_to(0, 2, 1, 0, &b_ok);
    b_ok.p_data[0] = 1.0;
    b_ok.p_data[1] = 2.0;

    check(oarr_lu_factor(&K, &lu) == DN_OK, "budget 1 MB: lu_factor within the budget");
    check(oarr_lu_solve(&lu, &b_wide, &x, dhl) == DN_ERR_MEMORY && x.p_data == NULL,
          "budget 1 MB: wide right-hand side refused (X above the budget), x untouched");
    check(oarr_solve_to(&K, &b_wide, &x, dhl) == DN_ERR_MEMORY && x.p_data == NULL,
          "budget 1 MB: solve_to with a wide right-hand side refused");
    check(oarr_lu_solve(&lu, &b_many, &x, dhl) == DN_ERR_MEMORY && x.p_data == NULL,
          "budget 1 MB: expanded A above the budget refused, x untouched");
    status = oarr_lu_solve(&lu, &b_ok, &x, dhl);
    check(status == DN_OK && x.nact == 100 && x.nrows == 2 && x.ncols == 1,
          "budget 1 MB: a solve within the budget works");

    oarr_lu_free(&lu);
    oarr_free(&K);
    oarr_free(&b_wide);
    oarr_free(&b_many);
    oarr_free(&b_ok);
    oarr_free(&x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Reruns the test executable with OTI_DENSE_MAX_MB=1 (the budget is read once per process). */
static void test_budget_run_child(const char* self){

    char cmd[4096];
    int rc;

    if (self == NULL || strlen(self) > 3000 || strchr(self, '\'') != NULL){

        check(0, "budget: cannot rerun the test executable");
        return;

    }

    snprintf(cmd, sizeof(cmd), "OTI_DENSE_MAX_MB=1 '%s' --budget", self);
    fflush(stdout);
    fflush(stderr);
    rc = system(cmd);
    check(rc == 0, "budget (child with OTI_DENSE_MAX_MB=1) passes");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;
    int budget = (argc > 1 && strcmp(argv[1], "--budget") == 0);

    dhelp_load(NULL, &dhl);

    if (budget){

        test_budget_child(dhl);
        dhelp_free(&dhl);

        if (n_failed){
            fprintf(stderr, "%d dense linalg budget test(s) failed.\n", n_failed);
            return 1;
        }

        printf("[budget child] dense linalg budget tests passed.\n");
        return 0;

    }

    test_hand_4x4(dhl);
    test_real_and_empty(dhl);
    test_oracle_grid(dhl);
    test_operand_relations(dhl);
    test_fallback_k11(dhl);
    test_aliasing(dhl);
    test_lu_reuse(dhl);
    test_identities(dhl);
    test_singular(dhl);
    test_errors(dhl);
    test_threads(dhl);
    test_concurrent(dhl);
    test_budget_run_child(argv[0]);

    dhelp_free(&dhl);

    if (n_failed){
        fprintf(stderr, "%d dense linalg test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C dense linalg tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
