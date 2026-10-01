/* Tests of the dense SoA utilities (include/oti/dense/soa/utils.h, src/c/dense/soa/utils.c): extract_im /
 * extract_deriv, trunc_sub, trunc_matmul, dot_product, rom_eval, the global layouts (get_all_ims,
 * order_max_base, get_order_im_array, add_order_im_array), moving_average and interp1d. The scalar
 * utilities belong to test_dense_scalar.c.
 *
 * Oracles: the sparse arrso_t / sotinum_t functions (1e-13) and the semi-sparse oarrss_ functions over
 * the active set [1..k] (1e-14; the layout of a dense array over 1..k is byte-identical to the
 * semi-sparse one). Operands are filled as dense arrays and converted to the oracles here, so the
 * comparison does not depend on the dense conversion functions. Every scenario covers equal nact, a
 * smaller-nact (prefix) operand, nact = 0 and unequal truncation and active orders; trunc_matmul and
 * dot_product also run at nact 11 / order 5, above Nbasis(5) = 10 (rank fallback), against the
 * semi-sparse result.
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

#define TOL_SPARSE 1e-13
#define TOL_SEMI   1e-14

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

    return fabs(a - b) <= tol * fmax(1.0, fmax(fabs(a), fabs(b)));

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     OPERANDS AND ACCESS     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A random nrows x ncols dense array over bases 1..k with truncation order trc: real parts in
 * [0.5, 1.5], a `density` fraction of the imaginary coefficients of orders 1..act nonzero in
 * [-0.7, 0.7]. */
static oarr_t build_dense(uint64_t nrows, uint64_t ncols, bases_t k, ord_t trc, ord_t act,
                          double density){

    oarr_t A = oarr_init();
    uint64_t i, b, nblocks;
    int status = oarr_zeros_to(k, nrows, ncols, trc, &A);

    if (status != DN_OK){

        fprintf(stderr, "build_dense: oarr_zeros_to failed (%d)\n", status);
        n_failed++;
        return A;

    }

    for (i = 0; i < A.size; i++){
        A.p_data[i] = rng_range(0.5, 1.5);
    }

    nblocks = 1 + sshelp_ndir_total(k, act);

    for (b = 1; b < nblocks; b++){

        for (i = 0; i < A.size; i++){

            if (rng_uniform() < density){
                A.p_data[b * A.size + i] = rng_range(-0.7, 0.7);
            }

        }

    }

    A.act_order = (k == 0) ? 0 : act;

    return A;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Coefficient (idx, p) of element (i, j) of a dense array, zero when structurally absent. */
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
/* Coefficient (idx, p) of a dense number, zero when structurally absent. */
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
/* Coefficient (idx, p) of element (i, j) of a semi-sparse array (global direction). */
static coeff_t ss_coef(const oarrss_t* S, uint64_t i, uint64_t j, imdir_t idx, ord_t p){

    ndir_t l;

    if (p == 0){
        return S->p_data[i + j * S->nrows];
    }

    if (p > S->trc_order || sshelp_global_to_local(idx, p, S->p_bases, S->nbases, &l) != 1){
        return 0.0;
    }

    return S->p_data[(1 + sshelp_order_offset(S->nbases, p) + l) * S->size + i + j * S->nrows];

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

                }

            }

        }

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The same values as a semi-sparse SoA array over [1..k]: the layouts are byte-identical. */
static oarrss_t to_oarrss(const oarr_t* A){

    bases_t bases[64], u;
    oarrss_t s;

    for (u = 0; u < A->nact && u < 64; u++){
        bases[u] = u + 1;
    }

    s = oarrss_zeros(bases, A->nact, A->nrows, A->ncols, A->trc_order);

    if (A->size > 0){
        memcpy(s.p_data, A->p_data,
               (size_t)((1 + sshelp_ndir_total(A->nact, A->trc_order)) * A->size) * sizeof(coeff_t));
    }

    s.act_order = A->act_order;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Dense array against a sparse array, over the directions of bases 1..kmax at every order the dense
 * array holds. The sparse array is read with soti_get_item (zero for absent directions). */
static void compare_vs_arrso(const char* tag, const oarr_t* a, arrso_t* o, bases_t kmax, double tol,
                             dhelpl_t dhl){

    uint64_t i, j, n_checked = 0, n_bad = 0;
    imdir_t idx;
    ord_t p;
    char name[256];

    if (a->nrows != o->nrows || a->ncols != o->ncols){

        snprintf(name, sizeof(name), "%s: same shape as the sparse oracle", tag);
        check(0, name);
        return;

    }

    for (i = 0; i < a->nrows; i++){

        for (j = 0; j < a->ncols; j++){

            sotinum_t* e = &o->p_data[j + i * o->ncols];

            for (p = 0; p <= a->trc_order; p++){

                ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

                for (idx = 0; idx < np; idx++){

                    coeff_t v1 = arr_coef(a, i, j, idx, p);
                    coeff_t v2 = (p == 0) ? e->re : soti_get_item(idx, p, e, dhl);

                    n_checked++;

                    if (!approx_equal(v1, v2, tol)){

                        if (n_bad < 5){
                            fprintf(stderr, "  mismatch %s (%llu,%llu) p=%u idx=%llu: %.17g vs %.17g\n",
                                    tag, (unsigned long long)i, (unsigned long long)j, (unsigned)p,
                                    (unsigned long long)idx, v1, v2);
                        }

                        n_bad++;

                    }

                }

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match sparse", tag,
             (unsigned long long)(n_checked - n_bad), (unsigned long long)n_checked);
    check(n_bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against a semi-sparse array over [1..k] (values by global direction). */
static void compare_vs_ss(const char* tag, const oarr_t* a, const oarrss_t* s, bases_t kmax,
                          double tol){

    uint64_t i, j, n_checked = 0, n_bad = 0;
    imdir_t idx;
    ord_t p, trc = (a->trc_order > s->trc_order) ? a->trc_order : s->trc_order;
    char name[256];

    if (a->nrows != s->nrows || a->ncols != s->ncols){

        snprintf(name, sizeof(name), "%s: same shape as the semi-sparse result", tag);
        check(0, name);
        return;

    }

    for (i = 0; i < a->nrows; i++){

        for (j = 0; j < a->ncols; j++){

            for (p = 0; p <= trc; p++){

                ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

                for (idx = 0; idx < np; idx++){

                    coeff_t v1 = arr_coef(a, i, j, idx, p), v2 = ss_coef(s, i, j, idx, p);

                    n_checked++;

                    if (!approx_equal(v1, v2, tol)){

                        if (n_bad < 5){
                            fprintf(stderr, "  mismatch %s (%llu,%llu) p=%u idx=%llu: %.17g vs %.17g\n",
                                    tag, (unsigned long long)i, (unsigned long long)j, (unsigned)p,
                                    (unsigned long long)idx, v1, v2);
                        }

                        n_bad++;

                    }

                }

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match semi-sparse", tag,
             (unsigned long long)(n_checked - n_bad), (unsigned long long)n_checked);
    check(n_bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against a dense array: values equal within tol over every direction (and the layout
 * fields nact, trc when same_layout is set). */
static void compare_dense(const char* tag, const oarr_t* a, const oarr_t* b, double tol,
                          int same_layout){

    uint64_t i, j, n_checked = 0, n_bad = 0;
    imdir_t idx;
    ord_t p, trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order;
    bases_t kmax = (a->nact > b->nact) ? a->nact : b->nact;
    char name[256];

    if (a->nrows != b->nrows || a->ncols != b->ncols ||
        (same_layout && (a->nact != b->nact || a->trc_order != b->trc_order))){

        snprintf(name, sizeof(name), "%s: same shape/layout (%llux%llu k=%u trc=%u vs %llux%llu k=%u "
                 "trc=%u)", tag, (unsigned long long)a->nrows, (unsigned long long)a->ncols,
                 (unsigned)a->nact, (unsigned)a->trc_order, (unsigned long long)b->nrows,
                 (unsigned long long)b->ncols, (unsigned)b->nact, (unsigned)b->trc_order);
        check(0, name);
        return;

    }

    for (i = 0; i < a->nrows; i++){

        for (j = 0; j < a->ncols; j++){

            for (p = 0; p <= trc; p++){

                ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

                for (idx = 0; idx < np; idx++){

                    n_checked++;

                    if (!approx_equal(arr_coef(a, i, j, idx, p), arr_coef(b, i, j, idx, p), tol)){
                        n_bad++;
                    }

                }

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match", tag,
             (unsigned long long)(n_checked - n_bad), (unsigned long long)n_checked);
    check(n_bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense number against a sparse number and/or a semi-sparse number, by global direction. */
static void compare_num(const char* tag, const otinum_t* a, sotinum_t* o, const ssotinum_t* s,
                        bases_t kmax, double tol_so, double tol_ss, dhelpl_t dhl){

    uint64_t bad_o = 0, bad_s = 0;
    ord_t p;
    imdir_t idx;
    char name[256];

    for (p = 0; p <= a->trc_order; p++){

        ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kmax, p);

        for (idx = 0; idx < np; idx++){

            coeff_t v = num_coef(a, idx, p);

            if (o != NULL && !approx_equal(v, (p == 0) ? o->re : soti_get_item(idx, p, o, dhl), tol_so)){
                bad_o++;
            }

            if (s != NULL && !approx_equal(v, (p == 0) ? s->re : ssoti_get_item(idx, p, s), tol_ss)){
                bad_s++;
            }

        }

    }

    if (o != NULL){

        snprintf(name, sizeof(name), "%s: matches sparse (%llu bad)", tag, (unsigned long long)bad_o);
        check(bad_o == 0, name);

    }

    if (s != NULL){

        snprintf(name, sizeof(name), "%s: matches semi-sparse (%llu bad)", tag,
                 (unsigned long long)bad_s);
        check(bad_s == 0, name);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     SCENARIOS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct {
    bases_t k1; ord_t trc1, act1;   ///< First operand.
    bases_t k2; ord_t trc2, act2;   ///< Second operand.
    const char* label;
} scenario_t;

static const scenario_t SCENARIOS[] = {
    {2, 4, 4, 2, 3, 3, "equal_nact"},
    {2, 4, 4, 4, 3, 3, "b_larger_nact"},
    {4, 4, 4, 2, 3, 3, "a_larger_nact"},
    {0, 4, 0, 3, 3, 3, "a_nact0"},
    {3, 4, 4, 0, 3, 0, "b_nact0"},
    {0, 3, 0, 0, 3, 0, "both_nact0"},
    {3, 4, 2, 3, 4, 4, "a_act_lt_trc"},
    {3, 3, 3, 3, 5, 5, "b_higher_trc"},
};

#define N_SCENARIOS (sizeof(SCENARIOS) / sizeof(SCENARIOS[0]))

static bases_t max_k(bases_t a, bases_t b){ return (a > b) ? a : b; }


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     EXTRACTION     ----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_extract(dhelpl_t dhl){

    static const struct { bases_t k; ord_t trc, act; const char* label; } CASES[] = {
        {3, 4, 4, "k3_trc4"}, {3, 4, 2, "k3_trc4_act2"}, {0, 3, 0, "nact0"}, {2, 5, 5, "k2_trc5"},
    };
    size_t c;
    ord_t p;
    ndir_t idx;
    char ctx[160];

    for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

        oarr_t A;
        arrso_t Aso;
        oarrss_t S;
        bases_t kq;

        rng_seed(100 + c);
        A   = build_dense(3, 2, CASES[c].k, CASES[c].trc, CASES[c].act, 0.7);
        Aso = to_arrso(&A, dhl);
        S   = to_oarrss(&A);
        kq  = (bases_t)(CASES[c].k + 1);

        for (p = 0; p <= (ord_t)(CASES[c].trc + 1); p++){

            ndir_t np = (p == 0) ? 1 : sshelp_ndir_order(kq, p);

            for (idx = 0; idx < np; idx++){

                oarr_t res_im = oarr_init(), res_dr = oarr_init(), alias = oarr_init();
                int st_im, st_dr, st_al;

                st_im = oarr_extract_im_to((imdir_t)idx, p, &A, &res_im);
                st_dr = oarr_extract_deriv_to((imdir_t)idx, p, &A, &res_dr);
                oarr_copy_to(&A, &alias);
                st_al = oarr_extract_deriv_to((imdir_t)idx, p, &alias, &alias);

                check(st_im == DN_OK && st_dr == DN_OK && st_al == DN_OK, "extract statuses");

                if (p == 0 || p <= CASES[c].trc){

                    arrso_t ref_im = arrso_extract_im((imdir_t)idx, p, &Aso, dhl);
                    arrso_t ref_dr = arrso_extract_deriv((imdir_t)idx, p, &Aso, dhl);
                    oarrss_t s_im = oarrss_init(), s_dr = oarrss_init();

                    oarrss_extract_im_to((imdir_t)idx, p, &S, &s_im);
                    oarrss_extract_deriv_to((imdir_t)idx, p, &S, &s_dr);

                    snprintf(ctx, sizeof(ctx), "extract_im %s (%llu, %u)", CASES[c].label,
                             (unsigned long long)idx, (unsigned)p);
                    compare_vs_arrso(ctx, &res_im, &ref_im, kq, TOL_SPARSE, dhl);
                    compare_vs_ss(ctx, &res_im, &s_im, kq, TOL_SEMI);

                    snprintf(ctx, sizeof(ctx), "extract_deriv %s (%llu, %u)", CASES[c].label,
                             (unsigned long long)idx, (unsigned)p);
                    compare_vs_arrso(ctx, &res_dr, &ref_dr, kq, TOL_SPARSE, dhl);
                    compare_vs_ss(ctx, &res_dr, &s_dr, kq, TOL_SEMI);

                    snprintf(ctx, sizeof(ctx), "extract_deriv aliased %s (%llu, %u)", CASES[c].label,
                             (unsigned long long)idx, (unsigned)p);
                    compare_dense(ctx, &alias, &res_dr, 0.0, 1);

                    // Layout: nact kept, trc lowered by the order (a zero result still has it).
                    if (p >= 1){

                        snprintf(ctx, sizeof(ctx), "extract_im layout %s (%llu, %u)", CASES[c].label,
                                 (unsigned long long)idx, (unsigned)p);
                        check(res_im.nact == A.nact && res_im.trc_order == A.trc_order - p &&
                              res_im.nrows == 3 && res_im.ncols == 2, ctx);

                    }

                    arrso_free(&ref_im);
                    arrso_free(&ref_dr);
                    oarrss_free(&s_im);
                    oarrss_free(&s_dr);

                } else {

                    // Order above trc: a real zero array with truncation order 0.
                    snprintf(ctx, sizeof(ctx), "extract_im order %u above trc %s", (unsigned)p,
                             CASES[c].label);
                    check(res_im.nact == 0 && res_im.trc_order == 0 && res_im.size == 6 &&
                          res_im.act_order == 0 && arr_coef(&res_im, 2, 1, 0, 0) == 0.0, ctx);

                }

                oarr_free(&res_im);
                oarr_free(&res_dr);
                oarr_free(&alias);

            } // end for

        } // end for

        oarr_free(&A);
        arrso_free(&Aso);
        oarrss_free(&S);

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     TRUNCATED ALGEBRA     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_trunc_sub(dhelpl_t dhl){

    size_t s;
    ord_t o;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        oarr_t A, B, bad;
        arrso_t Aso, Bso;
        oarrss_t SA, SB;
        bases_t kq = max_k(sc->k1, sc->k2);

        rng_seed(200 + s);
        A   = build_dense(2, 3, sc->k1, sc->trc1, sc->act1, 0.7);
        B   = build_dense(2, 3, sc->k2, sc->trc2, sc->act2, 0.7);
        Aso = to_arrso(&A, dhl);
        Bso = to_arrso(&B, dhl);
        SA  = to_oarrss(&A);
        SB  = to_oarrss(&B);

        for (o = 0; o <= 6; o++){

            arrso_t ref = arrso_zeros_bases(2, 3, 0, 4, dhl);
            oarrss_t sres = oarrss_init();
            oarr_t res = oarr_init(), al1 = oarr_init(), al2 = oarr_init();
            ord_t trc = (A.trc_order > B.trc_order) ? A.trc_order : B.trc_order;

            arrso_trunc_sub_OO_to(o, &Aso, &Bso, &ref, dhl);
            oarrss_trunc_sub_OO_to(o, &SA, &SB, &sres);
            check(oarr_trunc_sub_OO_to(o, &A, &B, &res) == DN_OK, "trunc_sub status");

            oarr_copy_to(&A, &al1);
            oarr_copy_to(&B, &al2);
            oarr_trunc_sub_OO_to(o, &al1, &B, &al1);
            oarr_trunc_sub_OO_to(o, &A, &al2, &al2);

            snprintf(ctx, sizeof(ctx), "trunc_sub %s order %u", sc->label, (unsigned)o);
            compare_vs_arrso(ctx, &res, &ref, kq, TOL_SPARSE, dhl);
            compare_vs_ss(ctx, &res, &sres, kq, TOL_SEMI);
            check(res.nact == kq && res.trc_order == trc, "trunc_sub: nact = max, trc = max");

            snprintf(ctx, sizeof(ctx), "trunc_sub aliased (res = A) %s order %u", sc->label,
                     (unsigned)o);
            compare_dense(ctx, &al1, &res, 0.0, 1);
            snprintf(ctx, sizeof(ctx), "trunc_sub aliased (res = B) %s order %u", sc->label,
                     (unsigned)o);
            compare_dense(ctx, &al2, &res, 0.0, 1);

            arrso_free(&ref);
            oarrss_free(&sres);
            oarr_free(&res);
            oarr_free(&al1);
            oarr_free(&al2);

        } // end for

        bad = build_dense(3, 2, 1, 2, 2, 0.5);

        {
            oarr_t res = oarr_init();

            check(oarr_trunc_sub_OO_to(1, &A, &bad, &res) == DN_ERR_SIZE,
                  "trunc_sub rejects a shape mismatch");
            check(res.p_data == NULL && res.size == 0, "a failed trunc_sub leaves res untouched");
            oarr_free(&res);
        }

        oarr_free(&bad);
        oarr_free(&A);
        oarr_free(&B);
        arrso_free(&Aso);
        arrso_free(&Bso);
        oarrss_free(&SA);
        oarrss_free(&SB);

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_trunc_matmul(dhelpl_t dhl){

    size_t s;
    ord_t oa, ob;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        oarr_t A, B;
        arrso_t Aso, Bso;
        oarrss_t SA, SB;
        bases_t kq = max_k(sc->k1, sc->k2);
        ord_t trc = (sc->trc1 > sc->trc2) ? sc->trc1 : sc->trc2;

        rng_seed(300 + s);
        A   = build_dense(3, 2, sc->k1, sc->trc1, sc->act1, 0.7);
        B   = build_dense(2, 4, sc->k2, sc->trc2, sc->act2, 0.7);
        Aso = to_arrso(&A, dhl);
        Bso = to_arrso(&B, dhl);
        SA  = to_oarrss(&A);
        SB  = to_oarrss(&B);

        for (oa = 0; oa <= 4; oa++){

            for (ob = 0; ob <= 5 - oa; ob++){

                arrso_t Ao = arrso_get_order_im(oa, &Aso, dhl);
                arrso_t Bo = arrso_get_order_im(ob, &Bso, dhl);
                arrso_t P  = arrso_matmul_OO(&Ao, &Bo, dhl);
                arrso_t ref = arrso_get_order_im((ord_t)(oa + ob), &P, dhl);
                oarrss_t sres = oarrss_init();
                oarr_t res = oarr_init(), alias = oarr_init();

                oarrss_trunc_matmul_OO_to(oa, &SA, ob, &SB, &sres, dhl);
                check(oarr_trunc_matmul_OO_to(oa, &A, ob, &B, &res, dhl) == DN_OK,
                      "trunc_matmul status");

                snprintf(ctx, sizeof(ctx), "trunc_matmul %s (%u, %u)", sc->label, (unsigned)oa,
                         (unsigned)ob);

                // Orders past the truncation order give zero (the oracle is truncated the same way).
                compare_vs_arrso(ctx, &res, &ref, kq, TOL_SPARSE, dhl);
                compare_vs_ss(ctx, &res, &sres, kq, TOL_SEMI);
                check(res.nact == kq && res.trc_order == trc && res.nrows == 3 && res.ncols == 4,
                      "trunc_matmul: nact = max, trc = max, shape");

                check(res.act_order == 0 || res.act_order == (ord_t)(oa + ob),
                      "trunc_matmul: act_order is the order computed (0 for an empty product)");

                if (oa == 1 && ob == 1){

                    oarr_copy_to(&A, &alias);
                    oarr_trunc_matmul_OO_to(oa, &alias, ob, &B, &alias, dhl);
                    snprintf(ctx, sizeof(ctx), "trunc_matmul aliased (res = A) %s", sc->label);
                    compare_dense(ctx, &alias, &res, 0.0, 1);

                }

                arrso_free(&Ao);
                arrso_free(&Bo);
                arrso_free(&P);
                arrso_free(&ref);
                oarrss_free(&sres);
                oarr_free(&res);
                oarr_free(&alias);

            } // end for

        } // end for

        {
            // res aliasing the second operand: square operands so that the shape is kept.
            oarr_t Bt = build_dense(3, 3, sc->k1, sc->trc1, sc->act1, 0.7);
            oarr_t B2 = build_dense(3, 3, sc->k2, sc->trc2, sc->act2, 0.7);
            oarr_t ref2 = oarr_init();

            oarr_trunc_matmul_OO_to(1, &Bt, 1, &B2, &ref2, dhl);
            oarr_trunc_matmul_OO_to(1, &Bt, 1, &B2, &B2, dhl);
            snprintf(ctx, sizeof(ctx), "trunc_matmul aliased (res = B) %s", sc->label);
            compare_dense(ctx, &B2, &ref2, 0.0, 1);

            oarr_free(&Bt);
            oarr_free(&B2);
            oarr_free(&ref2);
        }

        {
            oarr_t res = oarr_init();

            check(oarr_trunc_matmul_OO_to(1, &B, 1, &A, &res, dhl) == DN_ERR_SIZE,
                  "trunc_matmul rejects unaligned shapes");
            check(res.p_data == NULL, "a failed trunc_matmul leaves res untouched");
            oarr_free(&res);
        }

        oarr_free(&A);
        oarr_free(&B);
        arrso_free(&Aso);
        arrso_free(&Bso);
        oarrss_free(&SA);
        oarrss_free(&SB);

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_dot_product(dhelpl_t dhl){

    size_t s;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        oarr_t A, B, C, D;
        arrso_t Aso, Bso, Cso, Dso;
        oarrss_t SA, SB, SC, SD;
        sotinum_t ref1, ref2;
        otinum_t res = oti_init();
        ssotinum_t sres = ssoti_init();
        bases_t kq = max_k(sc->k1, sc->k2);
        oarr_t bad = build_dense(3, 3, 1, 1, 1, 0.5);

        rng_seed(400 + s);
        A = build_dense(5, 1, sc->k1, sc->trc1, sc->act1, 0.7);
        B = build_dense(1, 5, sc->k2, sc->trc2, sc->act2, 0.7);
        C = build_dense(2, 3, sc->k2, sc->trc2, sc->act2, 0.7);
        D = build_dense(2, 3, sc->k1, sc->trc1, sc->act1, 0.7);
        Aso = to_arrso(&A, dhl);
        Bso = to_arrso(&B, dhl);
        Cso = to_arrso(&C, dhl);
        Dso = to_arrso(&D, dhl);
        SA = to_oarrss(&A);
        SB = to_oarrss(&B);
        SC = to_oarrss(&C);
        SD = to_oarrss(&D);
        ref1 = arrso_dotproduct_OO(&Aso, &Bso, dhl);
        ref2 = arrso_dotproduct_OO(&Cso, &Dso, dhl);

        check(oarr_dot_product_OO_to(&A, &B, &res, dhl) == DN_OK, "dot_product status");
        oarrss_dot_product_OO_to(&SA, &SB, &sres, dhl);
        snprintf(ctx, sizeof(ctx), "dot_product (5,1).(1,5) %s", sc->label);
        compare_num(ctx, &res, &ref1, &sres, kq, TOL_SPARSE, TOL_SEMI, dhl);
        check(res.nact == kq && res.trc_order == ((sc->trc1 > sc->trc2) ? sc->trc1 : sc->trc2),
              "dot_product: nact = max, trc = max");

        oarr_dot_product_OO_to(&C, &D, &res, dhl);
        oarrss_dot_product_OO_to(&SC, &SD, &sres, dhl);
        snprintf(ctx, sizeof(ctx), "dot_product (2,3).(2,3) %s", sc->label);
        compare_num(ctx, &res, &ref2, &sres, kq, TOL_SPARSE, TOL_SEMI, dhl);

        check(oarr_dot_product_OO_to(&A, &bad, &res, dhl) == DN_ERR_SIZE,
              "dot_product rejects different sizes");

        soti_free(&ref1);
        soti_free(&ref2);
        oti_free(&res);
        ssoti_free(&sres);
        oarr_free(&A);
        oarr_free(&B);
        oarr_free(&C);
        oarr_free(&D);
        oarr_free(&bad);
        arrso_free(&Aso);
        arrso_free(&Bso);
        arrso_free(&Cso);
        arrso_free(&Dso);
        oarrss_free(&SA);
        oarrss_free(&SB);
        oarrss_free(&SC);
        oarrss_free(&SD);

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Rank-fallback case: nact 11 at order 5 (above Nbasis(5) = 10) and a prefix operand beside it. The
 * sparse type cannot hold these labels, so the semi-sparse result over [1..11] is the oracle. */
static void test_fallback_k11(dhelpl_t dhl){

    static const struct { bases_t k1, k2; } KS[] = {{11, 11}, {11, 4}, {4, 11}};
    static const struct { ord_t oa, ob; } ORD[] = {{1, 1}, {2, 3}, {1, 4}, {0, 5}, {5, 0}, {3, 2}};
    size_t c, t;
    char ctx[160];

    for (c = 0; c < 3; c++){

        oarr_t A, B, M, N;
        oarrss_t SA, SB, SM, SN;
        otinum_t res = oti_init();
        ssotinum_t sres = ssoti_init();
        bases_t kq = max_k(KS[c].k1, KS[c].k2);

        rng_seed(500 + c);
        A = build_dense(2, 2, KS[c].k1, 5, 5, 0.1);
        B = build_dense(2, 2, KS[c].k2, 5, 5, 0.1);
        M = build_dense(6, 1, KS[c].k1, 5, 5, 0.1);
        N = build_dense(6, 1, KS[c].k2, 5, 5, 0.1);
        SA = to_oarrss(&A);
        SB = to_oarrss(&B);
        SM = to_oarrss(&M);
        SN = to_oarrss(&N);

        for (t = 0; t < 6; t++){

            oarr_t res_m = oarr_init();
            oarrss_t sres_m = oarrss_init();

            check(oarr_trunc_matmul_OO_to(ORD[t].oa, &A, ORD[t].ob, &B, &res_m, dhl) == DN_OK,
                  "k = 11 trunc_matmul status");
            oarrss_trunc_matmul_OO_to(ORD[t].oa, &SA, ORD[t].ob, &SB, &sres_m, dhl);
            snprintf(ctx, sizeof(ctx), "k = 11 trunc_matmul k1=%u k2=%u (%u, %u)", (unsigned)KS[c].k1,
                     (unsigned)KS[c].k2, (unsigned)ORD[t].oa, (unsigned)ORD[t].ob);
            compare_vs_ss(ctx, &res_m, &sres_m, kq, TOL_SPARSE);

            oarr_free(&res_m);
            oarrss_free(&sres_m);

        }

        check(oarr_dot_product_OO_to(&M, &N, &res, dhl) == DN_OK, "k = 11 dot_product status");
        oarrss_dot_product_OO_to(&SM, &SN, &sres, dhl);
        snprintf(ctx, sizeof(ctx), "k = 11 dot_product k1=%u k2=%u", (unsigned)KS[c].k1,
                 (unsigned)KS[c].k2);
        compare_num(ctx, &res, NULL, &sres, kq, TOL_SPARSE, TOL_SPARSE, dhl);

        oarr_free(&A);
        oarr_free(&B);
        oarr_free(&M);
        oarr_free(&N);
        oarrss_free(&SA);
        oarrss_free(&SB);
        oarrss_free(&SM);
        oarrss_free(&SN);
        oti_free(&res);
        ssoti_free(&sres);

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ROM EVALUATION AND LAYOUTS     ------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_rom_eval(dhelpl_t dhl){

    oarr_t A, R = oarr_init();
    arrso_t Aso, ref;
    coeff_t gdel[8];
    uint64_t i, j, bad = 0;
    int u;

    rng_seed(600);
    A = build_dense(2, 3, 3, 3, 3, 0.8);

    for (u = 0; u < 8; u++){
        gdel[u] = rng_range(-0.3, 0.3);
    }

    Aso = to_arrso(&A, dhl);
    ref = arrso_taylor_integrate(gdel, &Aso, dhl);

    check(oarr_rom_eval_to(&A, gdel, &R) == DN_OK, "rom_eval status");

    for (i = 0; i < 2; i++){

        for (j = 0; j < 3; j++){
            bad += !approx_equal(R.p_data[i + j * 2], ref.p_data[j + i * 3].re, 1e-14);
        }

    }

    check(bad == 0 && R.nact == 0 && R.trc_order == 0 && R.act_order == 0 && R.nrows == 2 && R.ncols == 3,
          "rom_eval vs arrso_taylor_integrate, real result (nact 0, trc 0)");

    check(oarr_rom_eval_to(&A, gdel, &A) == DN_OK && A.nact == 0 &&
          approx_equal(A.p_data[1], ref.p_data[3].re, 1e-14), "rom_eval aliased");

    // A real array needs no deltas.
    {
        oarr_t Rr = build_dense(2, 2, 0, 2, 0, 0.0);

        check(oarr_rom_eval_to(&Rr, NULL, &R) == DN_OK && R.nact == 0 && R.nrows == 2 &&
              R.p_data[3] == Rr.p_data[3], "rom_eval of a real array");
        oarr_free(&Rr);
    }

    arrso_free(&Aso);
    arrso_free(&ref);
    oarr_free(&A);
    oarr_free(&R);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* get_all_ims / get_all_derivs against the per-element scalar layout (oti_get_all_ims_to) and the
 * semi-sparse layout (byte-identical); order_max_base, get_order_im_array and add_order_im_array. */
static void test_layouts(dhelpl_t dhl){

    static const struct { bases_t nbasis; ord_t order; } LAY[] = {{6, 3}, {2, 3}, {3, 2}, {4, 4}};
    oarr_t A;
    arrso_t Aso;
    oarrss_t S;
    uint64_t i, j, bad;
    size_t l;
    int derivs;
    ord_t p;

    rng_seed(700);
    A   = build_dense(2, 3, 3, 4, 4, 0.6);
    Aso = to_arrso(&A, dhl);
    S   = to_oarrss(&A);

    for (l = 0; l < sizeof(LAY) / sizeof(LAY[0]); l++){

        ndir_t ntot = (ndir_t)dhelp_ndirTotal(LAY[l].nbasis, LAY[l].order) - 1;  // without the real part
        coeff_t* out = (coeff_t*)malloc((1 + (size_t)ntot) * A.size * sizeof(coeff_t));
        coeff_t* sout = (coeff_t*)malloc((1 + (size_t)ntot) * A.size * sizeof(coeff_t));
        coeff_t* col = (coeff_t*)malloc((1 + (size_t)ntot) * sizeof(coeff_t));
        char ctx[128];

        for (derivs = 0; derivs <= 1; derivs++){

            ndir_t d;

            bad = 0;
            check(oarr_get_all_ims_to(&A, LAY[l].nbasis, LAY[l].order, derivs, out) == DN_OK,
                  "get_all_ims status");
            oarrss_get_all_ims_to(&S, LAY[l].nbasis, LAY[l].order, derivs, sout);

            for (i = 0; i < 2; i++){

                for (j = 0; j < 3; j++){

                    otinum_t item = oti_init();

                    oarr_get_item_to(i, j, &A, &item);
                    memset(col, 0, (1 + (size_t)ntot) * sizeof(coeff_t));
                    oti_get_all_ims_to(&item, LAY[l].nbasis, LAY[l].order, derivs, col, 1);

                    for (d = 0; d <= ntot; d++){
                        bad += (out[d * 6 + i * 3 + j] != col[d]);
                    }

                    oti_free(&item);

                }

            }

            snprintf(ctx, sizeof(ctx), "%s layout (nbasis %u, order %u) vs the scalar layout",
                     derivs ? "get_all_derivs" : "get_all_ims", (unsigned)LAY[l].nbasis,
                     (unsigned)LAY[l].order);
            check(bad == 0, ctx);
            snprintf(ctx, sizeof(ctx), "%s layout (nbasis %u, order %u) is byte-identical to semi-sparse",
                     derivs ? "get_all_derivs" : "get_all_ims", (unsigned)LAY[l].nbasis,
                     (unsigned)LAY[l].order);
            check(memcmp(out, sout, (1 + (size_t)ntot) * A.size * sizeof(coeff_t)) == 0, ctx);

        } // end for

        free(out);
        free(sout);
        free(col);

    } // end for

    // order_max_base, get_order_im_array, add_order_im_array, per order.
    for (p = 0; p <= 4; p++){

        bases_t mb = (p == 0) ? 0 : oarr_order_max_base(p, &A);
        bases_t smb = (p == 0) ? 0 : oarrss_order_max_base(p, &S);
        ndir_t width = (p == 0) ? 1 : sshelp_ndir_order((mb > 0) ? mb : 1, p);
        uint64_t nb = A.size * width;
        coeff_t* buf = (coeff_t*)malloc(nb * sizeof(coeff_t) + 1);
        coeff_t* sbuf = (coeff_t*)malloc(nb * sizeof(coeff_t) + 1);
        arrso_t part = arrso_get_order_im(p, &Aso, dhl);
        oarr_t fresh = oarr_init(), sfresh_d = oarr_init();
        oarrss_t sfresh = oarrss_zeros(NULL, 0, 2, 3, 0);
        char ctx[160];

        check(mb == smb, "order_max_base equals semi-sparse");
        check(p == 0 || mb == 3, "order_max_base: the largest base of the dense blocks");

        check(oarr_get_order_im_array_to(p, &A, width, buf) == DN_OK, "get_order_im_array status");
        oarrss_get_order_im_array_to(p, &S, width, sbuf);
        snprintf(ctx, sizeof(ctx), "get_order_im_array order %u is byte-identical to semi-sparse",
                 (unsigned)p);
        check(memcmp(buf, sbuf, nb * sizeof(coeff_t)) == 0, ctx);

        // Narrower and wider layouts: the extra global directions are zero / skipped.
        {
            ndir_t wide = width + 3;
            coeff_t* b2 = (coeff_t*)malloc(A.size * wide * sizeof(coeff_t) + 1);
            coeff_t* s2 = (coeff_t*)malloc(A.size * wide * sizeof(coeff_t) + 1);
            ndir_t narrow = (width > 1) ? width - 1 : 1;
            coeff_t* b3 = (coeff_t*)malloc(A.size * narrow * sizeof(coeff_t) + 1);
            coeff_t* s3 = (coeff_t*)malloc(A.size * narrow * sizeof(coeff_t) + 1);

            oarr_get_order_im_array_to(p, &A, wide, b2);
            oarrss_get_order_im_array_to(p, &S, wide, s2);
            check(memcmp(b2, s2, A.size * wide * sizeof(coeff_t)) == 0, "get_order_im_array wide layout");
            oarr_get_order_im_array_to(p, &A, narrow, b3);
            oarrss_get_order_im_array_to(p, &S, narrow, s3);
            check(memcmp(b3, s3, A.size * narrow * sizeof(coeff_t)) == 0,
                  "get_order_im_array narrow layout");

            free(b2);
            free(s2);
            free(b3);
            free(s3);
        }

        // Round trip into a fresh real array: values, and nact / trc / act_order growth.
        oarr_zeros_to(0, 2, 3, 0, &fresh);
        oarr_zeros_to(0, 2, 3, 0, &sfresh_d);
        check(oarr_add_order_im_array(p, buf, width, &fresh) == DN_OK, "add_order_im_array status");
        oarrss_add_order_im_array(p, sbuf, width, &sfresh);
        snprintf(ctx, sizeof(ctx), "add_order_im_array round trip order %u", (unsigned)p);
        compare_vs_arrso(ctx, &fresh, &part, 3, 1e-15, dhl);
        snprintf(ctx, sizeof(ctx), "add_order_im_array order %u vs semi-sparse", (unsigned)p);
        compare_vs_ss(ctx, &fresh, &sfresh, 3, 1e-15);

        if (p >= 1){

            check(fresh.nact == mb && fresh.trc_order == p && fresh.act_order == p,
                  "add_order_im_array: nact = largest base, trc raised to p, act_order p");

        } else {
            check(fresh.nact == 0 && fresh.trc_order == 0,
                  "add_order_im_array order 0 adds to the real part");
        }

        // Adding again doubles the values in place (no growth).
        if (p >= 1){

            oarr_add_order_im_array(p, buf, width, &fresh);
            check(arr_coef(&fresh, 1, 1, 0, p) == 2.0 * arr_coef(&A, 1, 1, 0, p) || A.act_order < p,
                  "add_order_im_array accumulates");

        }

        free(buf);
        free(sbuf);
        arrso_free(&part);
        oarr_free(&fresh);
        oarr_free(&sfresh_d);
        oarrss_free(&sfresh);

    } // end for

    // Adding into an array that already has a larger layout and higher trc keeps them.
    {
        oarr_t big = build_dense(2, 2, 5, 4, 4, 0.5), ref = oarr_init();
        coeff_t vals[4 * 3];
        ndir_t g;

        for (g = 0; g < 12; g++){
            vals[g] = (coeff_t)(g + 1);
        }

        oarr_copy_to(&big, &ref);
        check(oarr_add_order_im_array(2, vals, 3, &big) == DN_OK,
              "add_order_im_array into a larger array");
        check(big.nact == 5 && big.trc_order == 4 &&
              approx_equal(arr_coef(&big, 0, 0, 0, 2), arr_coef(&ref, 0, 0, 0, 2) + vals[0], 1e-15) &&
              approx_equal(arr_coef(&big, 1, 1, 2, 2),
                           arr_coef(&ref, 1, 1, 2, 2) + vals[1 * 6 + 1 + 2 * 2], 1e-15),
              "add_order_im_array keeps a larger nact and trc and adds in place");
        oarr_free(&big);
        oarr_free(&ref);
    }

    oarr_free(&A);
    arrso_free(&Aso);
    oarrss_free(&S);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     FILTERS AND INTERPOLATION     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_moving_average(dhelpl_t dhl){

    oarr_t A, R = oarr_init();
    arrso_t Aso;
    oarrss_t S, SR = oarrss_init();
    uint64_t sizes[5] = {1, 2, 3, 4, 9}, w;
    int n = 7;
    char ctx[160];

    rng_seed(800);
    A   = build_dense(7, 1, 2, 3, 3, 0.8);
    Aso = to_arrso(&A, dhl);
    S   = to_oarrss(&A);

    for (w = 0; w < 5; w++){

        uint64_t size = sizes[w];
        int64_t left = (int64_t)size - (int64_t)(size / 2) - 1, right = (int64_t)size - left;
        coeff_t factor = 1.0 / (coeff_t)size;
        arrso_t ref = arrso_zeros_bases(7, 1, 0, 3, dhl);
        oarr_t al = oarr_init();
        int k;

        check(oarr_moving_average_to(&A, size, &R) == DN_OK, "moving_average status");
        oarrss_moving_average_to(&S, size, &SR);

        // The sparse algorithm, in sotinum_t arithmetic.
        for (k = 0; k < n; k++){

            int64_t lo = k - left, hi = k + right;
            int64_t startj = lo > 0 ? lo : 0, endj = hi < n ? hi : n, j;
            int64_t ns = lo < 0 ? -lo : 0, ne = hi > n ? hi - n : 0;
            sotinum_t value = soti_createEmpty(3, dhl);

            if (ns > 0){

                sotinum_t t1 = soti_mul_ro((coeff_t)ns, &Aso.p_data[startj], dhl);
                sotinum_t t2 = soti_mul_ro(factor, &t1, dhl);

                soti_copy_to(&t2, &value, dhl);
                soti_free(&t1);
                soti_free(&t2);

            }

            if (ne > 0){

                sotinum_t t1 = soti_mul_ro((coeff_t)ne, &Aso.p_data[endj - 1], dhl);
                sotinum_t t2 = soti_mul_ro(factor, &t1, dhl);
                sotinum_t t3 = soti_sum_oo(&value, &t2, dhl);

                soti_copy_to(&t3, &value, dhl);
                soti_free(&t1);
                soti_free(&t2);
                soti_free(&t3);

            }

            for (j = startj; j < endj; j++){

                sotinum_t t1 = soti_mul_ro(factor, &Aso.p_data[j], dhl);
                sotinum_t t2 = soti_sum_oo(&value, &t1, dhl);

                soti_copy_to(&t2, &value, dhl);
                soti_free(&t1);
                soti_free(&t2);

            }

            soti_copy_to(&value, &ref.p_data[k], dhl);
            soti_free(&value);

        } // end for

        snprintf(ctx, sizeof(ctx), "moving_average size %llu", (unsigned long long)size);
        compare_vs_arrso(ctx, &R, &ref, 2, 1e-15, dhl);
        compare_vs_ss(ctx, &R, &SR, 2, 1e-15);
        check(R.nact == A.nact && R.trc_order == A.trc_order && R.act_order == A.act_order &&
              R.nrows == 7 && R.ncols == 1, "moving_average keeps nact, trc and act_order; n x 1");

        // Aliasing is supported (built in a call-local array).
        oarr_copy_to(&A, &al);
        check(oarr_moving_average_to(&al, size, &al) == DN_OK, "moving_average aliased status");
        snprintf(ctx, sizeof(ctx), "moving_average aliased size %llu", (unsigned long long)size);
        compare_dense(ctx, &al, &R, 0.0, 1);

        arrso_free(&ref);
        oarr_free(&al);

    } // end for

    check(oarr_moving_average_to(&A, 0, &R) == DN_ERR_SIZE, "moving_average rejects size 0");

    arrso_free(&Aso);
    oarr_free(&A);
    oarr_free(&R);
    oarrss_free(&S);
    oarrss_free(&SR);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_interp1d(dhelpl_t dhl){

    oarr_t X, Y, Xt;
    arrso_t Xso, Yso;
    coeff_t reals[4] = {0.0, 1.0, 2.5, 4.0};
    coeff_t probes[6] = {-1.0, 0.0, 0.3, 2.5, 3.9, 5.0};
    int t, i;
    char ctx[160];

    rng_seed(900);
    X = build_dense(4, 1, 2, 3, 3, 0.8);
    Y = build_dense(4, 1, 3, 3, 3, 0.8);

    for (i = 0; i < 4; i++){
        X.p_data[i] = reals[i];
    }

    Xso = to_arrso(&X, dhl);
    Yso = to_arrso(&Y, dhl);

    for (t = 0; t < 6; t++){

        oarr_t xa = build_dense(1, 1, 3, 3, 3, 0.8);
        arrso_t xas;
        otinum_t x = oti_init(), res = oti_init(), xal = oti_init();
        sotinum_t ref;

        xa.p_data[0] = probes[t];
        xas = to_arrso(&xa, dhl);
        oarr_get_item_to(0, 0, &xa, &x);

        if (probes[t] < reals[0]){

            ref = soti_copy(&Yso.p_data[0], dhl);

        } else if (probes[t] > reals[3]){

            ref = soti_copy(&Yso.p_data[3], dhl);

        } else {

            int m = 1;
            sotinum_t dy, dx, sl, tt, pr;

            while (m < 3 && probes[t] > reals[m]){
                m++;
            }

            dy = soti_sub_oo(&Yso.p_data[m], &Yso.p_data[m - 1], dhl);
            dx = soti_sub_oo(&Xso.p_data[m], &Xso.p_data[m - 1], dhl);
            sl = soti_div_oo(&dy, &dx, dhl);
            tt = soti_sub_oo(&xas.p_data[0], &Xso.p_data[m - 1], dhl);
            pr = soti_mul_oo(&sl, &tt, dhl);
            ref = soti_sum_oo(&pr, &Yso.p_data[m - 1], dhl);

            soti_free(&dy);
            soti_free(&dx);
            soti_free(&sl);
            soti_free(&tt);
            soti_free(&pr);

        }

        check(oarr_interp1d_o_to(&X, &Y, &x, &res, dhl) == DN_OK, "interp1d status");
        snprintf(ctx, sizeof(ctx), "interp1d at %g", probes[t]);
        compare_num(ctx, &res, &ref, NULL, 3, 1e-13, 0.0, dhl);

        // res aliasing x.
        oti_copy_to(&x, &xal);
        check(oarr_interp1d_o_to(&X, &Y, &xal, &xal, dhl) == DN_OK, "interp1d aliased status");
        snprintf(ctx, sizeof(ctx), "interp1d aliased at %g", probes[t]);
        compare_num(ctx, &xal, &ref, NULL, 3, 1e-13, 0.0, dhl);

        oti_free(&x);
        oti_free(&res);
        oti_free(&xal);
        soti_free(&ref);
        arrso_free(&xas);
        oarr_free(&xa);

    } // end for

    // Array of points against the scalar version per element; res aliasing X.
    Xt = build_dense(2, 2, 3, 2, 2, 0.8);
    {
        oarr_t R = oarr_init(), al = oarr_init();
        uint64_t bad = 0, r, c;

        Xt.p_data[0] = 0.5;
        Xt.p_data[1] = 3.0;
        Xt.p_data[2] = -2.0;
        Xt.p_data[3] = 2.0;

        check(oarr_interp1d_O_to(&X, &Y, &Xt, &R, dhl) == DN_OK, "interp1d array status");
        check(R.nrows == 2 && R.ncols == 2 && R.trc_order == 3, "interp1d array shape and trc");

        for (r = 0; r < 2; r++){

            for (c = 0; c < 2; c++){

                otinum_t xe = oti_init(), ye = oti_init(), got = oti_init();
                ord_t p;
                ndir_t idx;

                oarr_get_item_to(r, c, &Xt, &xe);
                oarr_get_item_to(r, c, &R, &got);
                oarr_interp1d_o_to(&X, &Y, &xe, &ye, dhl);

                for (p = 0; p <= 3; p++){

                    for (idx = 0; idx < ((p == 0) ? 1 : sshelp_ndir_order(3, p)); idx++){
                        bad += !approx_equal(num_coef(&got, (imdir_t)idx, p),
                                             num_coef(&ye, (imdir_t)idx, p), 1e-15);
                    }

                }

                oti_free(&xe);
                oti_free(&ye);
                oti_free(&got);

            }

        }

        check(bad == 0, "interp1d array vs scalar per element");

        oarr_copy_to(&Xt, &al);
        check(oarr_interp1d_O_to(&X, &Y, &al, &al, dhl) == DN_OK, "interp1d array aliased status");
        compare_dense("interp1d array aliased (res = X)", &al, &R, 0.0, 1);

        // res aliasing xvals or yvals: the result replaces that input (its shape changes).
        oarr_copy_to(&X, &al);
        check(oarr_interp1d_O_to(&al, &Y, &Xt, &al, dhl) == DN_OK, "interp1d array aliased xvals status");
        compare_dense("interp1d array aliased (res = xvals)", &al, &R, 0.0, 1);

        oarr_copy_to(&Y, &al);
        check(oarr_interp1d_O_to(&X, &al, &Xt, &al, dhl) == DN_OK, "interp1d array aliased yvals status");
        compare_dense("interp1d array aliased (res = yvals)", &al, &R, 0.0, 1);

        oarr_free(&R);
        oarr_free(&al);
    }

    // Shape errors.
    {
        oarr_t e0 = oarr_init(), R = oarr_init(), short_y = build_dense(2, 1, 1, 1, 1, 0.5);
        otinum_t x = oti_create_r(1.0, 1), res = oti_init();

        oarr_zeros_to(0, 0, 1, 1, &e0);
        check(oarr_interp1d_o_to(&e0, &Y, &x, &res, dhl) == DN_ERR_SIZE, "interp1d rejects empty xvals");
        check(oarr_interp1d_o_to(&X, &short_y, &x, &res, dhl) == DN_ERR_SIZE,
              "interp1d rejects yvals with fewer rows");
        check(oarr_interp1d_O_to(&X, &short_y, &Xt, &R, dhl) == DN_ERR_SIZE,
              "interp1d array rejects yvals with fewer rows");

        oarr_free(&e0);
        oarr_free(&R);
        oarr_free(&short_y);
        oti_free(&res);
        oti_free(&x);
    }

    arrso_free(&Xso);
    arrso_free(&Yso);
    oarr_free(&X);
    oarr_free(&Y);
    oarr_free(&Xt);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);

    test_extract(dhl);
    test_trunc_sub(dhl);
    test_trunc_matmul(dhl);
    test_dot_product(dhl);
    test_fallback_k11(dhl);
    test_rom_eval(dhl);
    test_layouts(dhl);
    test_moving_average(dhl);
    test_interp1d(dhl);

    oti_ws_release();
    ssoti_ws_release();
    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d dense utils test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C dense utils tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
