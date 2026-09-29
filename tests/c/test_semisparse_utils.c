/* Checks of the semi-sparse Phase 2 kernels (include/oti/semisparse/{scalar,soa}/utils.h,
 * PLAN-semisparse-sparse-leveling.md): extraction of directions and derivatives, truncated
 * subtraction and matrix product, dot product, rom_eval, the global layouts of get_all_ims /
 * get_order_im_array / set_order_im_from_array, moving_average and interp1d.
 *
 * The oracle is sotinum_t / arrso_t: operands are built as sparse numbers (random coefficients over
 * a given active set), converted with ssoti_from_soti() / oarrss_from_arrso(), run through the
 * kernel under test, and compared against the matching sparse operation on the same inputs. Every
 * comparison walks every global direction over bases 1..NB up to order MAXO, so a coefficient
 * outside either active set is compared too (it must be zero on both sides).
 *
 * arrso_t is row-major, (i, j) at p_data[j + i*ncols]; oarrss_t is read through its accessors. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>

#define NB   6   // Global bases walked by the comparisons.
#define MAXO 5   // Highest order walked by the comparisons.

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
static double rng_range(double lo, double hi){

    return lo + (hi - lo) * ((double)(rng_next() >> 11) / (double)(1ULL << 53));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int approx_equal(coeff_t a, coeff_t b, double tol){

    double scale = fmax(1.0, fmax(fabs(a), fabs(b)));

    return fabs(a - b) <= tol * scale;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A random sotinum_t with every direction over `bases` up to order trc set (each base is present). */
static sotinum_t build_soti(const bases_t* bases, bases_t k, ord_t trc, coeff_t re, dhelpl_t dhl){

    sotinum_t num = soti_createEmpty(trc, dhl);
    ord_t p, i;

    soti_set_item(re, 0, 0, &num, dhl);

    for (p = 1; p <= trc; p++){

        bases_t u[16], g[16];
        ndir_t ndir = sshelp_ndir_order(k, p), j;

        memset(u, 0, sizeof(u));

        for (j = 0; j < ndir; j++){

            for (i = 0; i < p; i++){
                g[i] = bases[u[i]];
            }

            soti_set_item(rng_range(-0.5, 0.5), sshelp_global_rank(g, p), p, &num, dhl);
            sshelp_next_dir(u, p, k);

        }

    }

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static arrso_t build_arrso(uint64_t nrows, uint64_t ncols, const bases_t* bases, bases_t k, ord_t trc,
                           dhelpl_t dhl){

    arrso_t arr = arrso_zeros_bases(nrows, ncols, 0, trc, dhl);
    uint64_t e;

    for (e = 0; e < arr.size; e++){

        sotinum_t tmp = build_soti(bases, k, trc, rng_range(1.0, 2.0), dhl);

        soti_copy_to(&tmp, &arr.p_data[e], dhl);
        soti_free(&tmp);

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Number of global directions compared that differ, over bases 1..NB and orders 0..MAXO. */
static uint64_t count_mismatch(const ssotinum_t* a, sotinum_t* b, double tol, dhelpl_t dhl){

    uint64_t bad = 0;
    ord_t p, i;

    if (!approx_equal(a->re, b->re, tol)){
        bad++;
    }

    for (p = 1; p <= MAXO; p++){

        bases_t u[16], g[16];
        ndir_t ndir = sshelp_ndir_order(NB, p), j;

        memset(u, 0, sizeof(u));

        for (j = 0; j < ndir; j++){

            imdir_t gidx;
            coeff_t vb;

            for (i = 0; i < p; i++){
                g[i] = (bases_t)(u[i] + 1);
            }

            gidx = sshelp_global_rank(g, p);
            vb = (p <= b->act_order) ? soti_get_item(gidx, p, b, dhl) : 0.0;

            if (!approx_equal(ssoti_get_item(gidx, p, a), vb, tol)){
                bad++;
            }

            sshelp_next_dir(u, p, NB);

        }

    }

    return bad;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_scalar(const ssotinum_t* a, sotinum_t* b, double tol, const char* ctx,
                           dhelpl_t dhl){

    char name[256];
    uint64_t bad = count_mismatch(a, b, tol, dhl);

    snprintf(name, sizeof(name), "%s (%llu mismatches)", ctx, (unsigned long long)bad);
    check(bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_array(const oarrss_t* a, arrso_t* b, double tol, const char* ctx, dhelpl_t dhl){

    char name[256];
    uint64_t bad = 0, i, j;

    if (a->nrows != b->nrows || a->ncols != b->ncols){

        snprintf(name, sizeof(name), "%s (shape)", ctx);
        check(0, name);
        return;

    }

    for (i = 0; i < a->nrows; i++){

        for (j = 0; j < a->ncols; j++){

            ssotinum_t item = oarrss_get_item(i, j, a);

            bad += count_mismatch(&item, &b->p_data[j + i * b->ncols], tol, dhl);
            ssoti_free(&item);

        }

    }

    snprintf(name, sizeof(name), "%s (%llu mismatches)", ctx, (unsigned long long)bad);
    check(bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     SCENARIOS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

static const bases_t SET_123[3]  = {1, 2, 3};
static const bases_t SET_12[2]   = {1, 2};
static const bases_t SET_1234[4] = {1, 2, 3, 4};
static const bases_t SET_135[3]  = {1, 3, 5};
static const bases_t SET_246[3]  = {2, 4, 6};

typedef struct {
    const bases_t* b1; bases_t k1;
    const bases_t* b2; bases_t k2;
    const char* label;
} scenario_t;

static const scenario_t SCENARIOS[] = {
    { SET_123, 3, SET_123,  3, "same" },
    { SET_12,  2, SET_1234, 4, "leading" },
    { SET_135, 3, SET_246,  3, "interleaved" },
    { NULL,    0, SET_12,   2, "real_lhs" },
};

#define N_SCENARIOS (sizeof(SCENARIOS) / sizeof(SCENARIOS[0]))

// Directions exercised by the extraction tests (global labels, sorted; 0 terminates).
static const bases_t DIRS[][4] = {
    {1, 0}, {2, 0}, {3, 0}, {6, 0}, {1, 1, 0}, {1, 3, 0}, {2, 5, 0}, {3, 3, 3, 0}, {1, 2, 3, 0},
};

#define N_DIRS (sizeof(DIRS) / sizeof(DIRS[0]))


// *******************************************************************************************************
static ord_t dir_order(const bases_t* d){

    ord_t p = 0;

    while (d[p] != 0){
        p++;
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     SCALAR TESTS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_scalar_extract(dhelpl_t dhl){

    const bases_t* sets[3] = {SET_123, SET_135, SET_1234};
    const bases_t ks[3] = {3, 3, 4};
    const ord_t trcs[3] = {5, 4, 3};
    int s;
    size_t d;
    char ctx[160];

    for (s = 0; s < 3; s++){

        sotinum_t x = build_soti(sets[s], ks[s], trcs[s], 1.25, dhl);
        ssotinum_t y = ssoti_from_soti(&x, dhl);

        for (d = 0; d < N_DIRS; d++){

            ord_t p = dir_order(DIRS[d]);
            imdir_t gidx = sshelp_global_rank(DIRS[d], p);
            sotinum_t ref_im = soti_extract_im(gidx, p, &x, dhl);
            sotinum_t ref_dr = soti_extract_deriv(gidx, p, &x, dhl);
            ssotinum_t res_im = ssoti_extract_im(gidx, p, &y);
            ssotinum_t res_dr = ssoti_init();
            ssotinum_t alias = ssoti_copy(&y);

            ssoti_extract_deriv_to(gidx, p, &y, &res_dr);
            ssoti_extract_im_to(gidx, p, &alias, &alias);

            snprintf(ctx, sizeof(ctx), "scalar extract_im set %d dir %zu", s, d);
            compare_scalar(&res_im, &ref_im, 1e-14, ctx, dhl);
            snprintf(ctx, sizeof(ctx), "scalar extract_deriv set %d dir %zu", s, d);
            compare_scalar(&res_dr, &ref_dr, 1e-14, ctx, dhl);
            snprintf(ctx, sizeof(ctx), "scalar extract_im aliased set %d dir %zu", s, d);
            compare_scalar(&alias, &ref_im, 1e-14, ctx, dhl);

            if (p <= x.act_order){
                snprintf(ctx, sizeof(ctx), "scalar extract trc_order set %d dir %zu", s, d);
                check(res_im.trc_order == trcs[s] - p && res_dr.trc_order == trcs[s] - p, ctx);
            }

            soti_free(&ref_im);
            soti_free(&ref_dr);
            ssoti_free(&res_im);
            ssoti_free(&res_dr);
            ssoti_free(&alias);

        }

        {
            ssotinum_t r0 = ssoti_extract_im(0, 0, &y);

            compare_scalar(&r0, &x, 0.0, "scalar extract_im order 0 copies", dhl);
            ssoti_free(&r0);
        }

        soti_free(&x);
        ssoti_free(&y);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_scalar_trunc_sub(dhelpl_t dhl){

    size_t s;
    ord_t o;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        sotinum_t a = build_soti(sc->b1, sc->k1, 4, 1.5, dhl);
        sotinum_t b = build_soti(sc->b2, sc->k2, 3, -0.5, dhl);
        ssotinum_t sa = ssoti_from_soti(&a, dhl), sb = ssoti_from_soti(&b, dhl);

        for (o = 0; o <= 5; o++){

            sotinum_t ref = soti_createEmpty(4, dhl);
            ssotinum_t res = ssoti_init(), alias = ssoti_copy(&sa);

            soti_trunc_sub_oo_to(o, &a, &b, &ref, dhl);
            ssoti_trunc_sub_to(o, &sa, &sb, &res);
            ssoti_trunc_sub_to(o, &alias, &sb, &alias);

            snprintf(ctx, sizeof(ctx), "scalar trunc_sub %s order %u", sc->label, (unsigned)o);
            compare_scalar(&res, &ref, 1e-14, ctx, dhl);
            snprintf(ctx, sizeof(ctx), "scalar trunc_sub aliased %s order %u", sc->label,
                (unsigned)o);
            compare_scalar(&alias, &ref, 1e-14, ctx, dhl);
            check(res.trc_order == 4, "scalar trunc_sub: truncation order is the max");

            soti_free(&ref);
            ssoti_free(&res);
            ssoti_free(&alias);

        }

        soti_free(&a);
        soti_free(&b);
        ssoti_free(&sa);
        ssoti_free(&sb);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_scalar_rom_eval(dhelpl_t dhl){

    const bases_t* sets[3] = {SET_123, SET_246, SET_1234};
    const bases_t ks[3] = {3, 3, 4};
    coeff_t gdel[NB + 1], loc[8], pts[8 * 5], outp[5];
    int s, t;
    bases_t u;
    char ctx[160];

    for (s = 0; s < 3; s++){

        sotinum_t x = build_soti(sets[s], ks[s], 4, 0.75, dhl);
        ssotinum_t y = ssoti_from_soti(&x, dhl);
        coeff_t ref, val;
        int ok = 1;

        for (u = 0; u <= NB; u++){
            gdel[u] = rng_range(-0.3, 0.3);
        }

        for (u = 0; u < y.nbases; u++){
            loc[u] = gdel[y.p_bases[u] - 1];
        }

        {
            sotinum_t tay = soti_taylor_integrate(gdel, &x, dhl);

            ref = tay.re;
            soti_free(&tay);
        }

        val = ssoti_rom_eval(&y, loc);

        snprintf(ctx, sizeof(ctx), "scalar rom_eval set %d (%.17g vs %.17g)", s, val, ref);
        check(approx_equal(val, ref, 1e-14), ctx);

        // Five points: the batched version against the one-point version.
        for (t = 0; t < 5; t++){

            for (u = 0; u < y.nbases; u++){
                pts[u * 5 + t] = rng_range(-0.3, 0.3);
            }

        }

        check(ssoti_rom_eval_points(&y, pts, 5, outp) == 0, "scalar rom_eval_points status");

        for (t = 0; t < 5; t++){

            for (u = 0; u < y.nbases; u++){
                loc[u] = pts[u * 5 + t];
            }

            ok = ok && approx_equal(outp[t], ssoti_rom_eval(&y, loc), 1e-14);

        }

        snprintf(ctx, sizeof(ctx), "scalar rom_eval_points set %d", s);
        check(ok, ctx);

        soti_free(&x);
        ssoti_free(&y);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_scalar_global_layouts(dhelpl_t dhl){

    sotinum_t x = build_soti(SET_135, 3, 4, 2.0, dhl);
    ssotinum_t y = ssoti_from_soti(&x, dhl);
    bases_t nbasis_list[2] = {6, 3};
    ord_t order_list[2] = {4, 2};
    int c, derivs;

    for (c = 0; c < 2; c++){

        bases_t nbasis = nbasis_list[c];
        ord_t order = order_list[c], p, i;
        ndir_t ntot = (ndir_t)dhelp_ndirTotal(nbasis, order);
        coeff_t* out = (coeff_t*)malloc(ntot * 2 * sizeof(coeff_t));

        for (derivs = 0; derivs <= 1; derivs++){

            uint64_t bad = 0, pos = 1;
            char ctx[160];

            memset(out, 0, ntot * 2 * sizeof(coeff_t));
            ssoti_get_all_ims_to(&y, nbasis, order, derivs, out, 2);

            bad += (out[0] != x.re);

            for (p = 1; p <= order; p++){

                bases_t u[16], g[16];
                ndir_t n = sshelp_ndir_order(nbasis, p), j;

                memset(u, 0, sizeof(u));

                for (j = 0; j < n; j++){

                    coeff_t ref;

                    for (i = 0; i < p; i++){
                        g[i] = (bases_t)(u[i] + 1);
                    }

                    ref = soti_get_item(sshelp_global_rank(g, p), p, &x, dhl);

                    if (derivs){
                        ref *= dhelp_get_deriv_factor(sshelp_global_rank(g, p), p, dhl);
                    }

                    bad += !approx_equal(out[2 * (pos + j)], ref, 1e-15);
                    sshelp_next_dir(u, p, nbasis);

                }

                pos += n;

            }

            snprintf(ctx, sizeof(ctx), "scalar get_all_ims nbasis %u order %u derivs %d",
                (unsigned)nbasis, (unsigned)order, derivs);
            check(bad == 0 && pos == ntot, ctx);

        }

        free(out);

    }

    // Scatter one order to global positions and add it back to other numbers.
    {
        ord_t p = 2;
        bases_t mb = ssoti_order_max_base(p, &y);
        ndir_t width = sshelp_ndir_order(mb, p);
        coeff_t* buf = (coeff_t*)calloc(width, sizeof(coeff_t));
        sotinum_t part = soti_get_order_im(p, &x, dhl);
        sotinum_t other = build_soti(SET_246, 3, 1, 3.0, dhl), ref;
        ssotinum_t fresh = ssoti_init(), sother = ssoti_from_soti(&other, dhl);

        check(mb == 5, "scalar order_max_base");
        ssoti_scatter_order_im(p, &y, width, buf, 1);
        ssoti_add_order_im_global(p, buf, width, 1, &fresh);
        compare_scalar(&fresh, &part, 1e-15, "scalar scatter + add_order_im_global round trip", dhl);
        check(fresh.trc_order == 2 && fresh.act_order == 2, "scalar add_order_im_global orders");

        ssoti_add_order_im_global(p, buf, width, 1, &sother);
        ref = soti_sum_oo(&other, &part, dhl);
        compare_scalar(&sother, &ref, 1e-15, "scalar add_order_im_global into a number", dhl);
        check(sother.trc_order == 2, "scalar add_order_im_global raises trc_order");

        free(buf);
        soti_free(&part);
        soti_free(&other);
        soti_free(&ref);
        ssoti_free(&fresh);
        ssoti_free(&sother);
    }

    soti_free(&x);
    ssoti_free(&y);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     SOA TESTS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_soa_extract(dhelpl_t dhl){

    arrso_t A = build_arrso(3, 2, SET_135, 3, 4, dhl);
    oarrss_t S = oarrss_from_arrso(&A, dhl);
    size_t d;
    char ctx[160];

    for (d = 0; d < N_DIRS; d++){

        ord_t p = dir_order(DIRS[d]);
        imdir_t gidx = sshelp_global_rank(DIRS[d], p);
        arrso_t ref_im = arrso_extract_im(gidx, p, &A, dhl);
        arrso_t ref_dr = arrso_extract_deriv(gidx, p, &A, dhl);
        oarrss_t res = oarrss_init(), alias = oarrss_copy(&S);

        oarrss_extract_im_to(gidx, p, &S, &res);
        snprintf(ctx, sizeof(ctx), "soa extract_im dir %zu", d);
        compare_array(&res, &ref_im, 1e-14, ctx, dhl);

        oarrss_extract_deriv_to(gidx, p, &S, &res);
        snprintf(ctx, sizeof(ctx), "soa extract_deriv dir %zu", d);
        compare_array(&res, &ref_dr, 1e-14, ctx, dhl);

        oarrss_extract_deriv_to(gidx, p, &alias, &alias);
        snprintf(ctx, sizeof(ctx), "soa extract_deriv aliased dir %zu", d);
        compare_array(&alias, &ref_dr, 1e-14, ctx, dhl);

        arrso_free(&ref_im);
        arrso_free(&ref_dr);
        oarrss_free(&res);
        oarrss_free(&alias);

    }

    arrso_free(&A);
    oarrss_free(&S);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_trunc_sub(dhelpl_t dhl){

    size_t s;
    ord_t o;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        arrso_t A = build_arrso(2, 3, sc->b1, sc->k1, 4, dhl);
        arrso_t B = build_arrso(2, 3, sc->b2, sc->k2, 3, dhl);
        oarrss_t SA = oarrss_from_arrso(&A, dhl), SB = oarrss_from_arrso(&B, dhl);

        for (o = 0; o <= 5; o++){

            arrso_t ref = arrso_zeros_bases(2, 3, 0, 4, dhl);
            oarrss_t res = oarrss_init(), alias = oarrss_copy(&SB);

            arrso_trunc_sub_OO_to(o, &A, &B, &ref, dhl);
            check(oarrss_trunc_sub_OO_to(o, &SA, &SB, &res) == 0, "soa trunc_sub status");
            oarrss_trunc_sub_OO_to(o, &SA, &alias, &alias);

            snprintf(ctx, sizeof(ctx), "soa trunc_sub %s order %u", sc->label, (unsigned)o);
            compare_array(&res, &ref, 1e-14, ctx, dhl);
            snprintf(ctx, sizeof(ctx), "soa trunc_sub aliased %s order %u", sc->label,
                (unsigned)o);
            compare_array(&alias, &ref, 1e-14, ctx, dhl);

            arrso_free(&ref);
            oarrss_free(&res);
            oarrss_free(&alias);

        }

        {
            oarrss_t bad = oarrss_zeros(NULL, 0, 3, 2, 1), res = oarrss_init();

            check(oarrss_trunc_sub_OO_to(1, &SA, &bad, &res) == OTI_LINALG_ERR_SIZE,
                "soa trunc_sub rejects a shape mismatch");
            oarrss_free(&bad);
            oarrss_free(&res);
        }

        arrso_free(&A);
        arrso_free(&B);
        oarrss_free(&SA);
        oarrss_free(&SB);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_trunc_matmul(dhelpl_t dhl){

    size_t s;
    ord_t oa, ob;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        arrso_t A = build_arrso(3, 2, sc->b1, sc->k1, 4, dhl);
        arrso_t B = build_arrso(2, 4, sc->b2, sc->k2, 4, dhl);
        oarrss_t SA = oarrss_from_arrso(&A, dhl), SB = oarrss_from_arrso(&B, dhl);

        for (oa = 0; oa <= 4; oa++){

            for (ob = 0; ob <= 5 - oa; ob++){

                arrso_t Ao = arrso_get_order_im(oa, &A, dhl);
                arrso_t Bo = arrso_get_order_im(ob, &B, dhl);
                arrso_t P  = arrso_matmul_OO(&Ao, &Bo, dhl);
                arrso_t ref = arrso_get_order_im((ord_t)(oa + ob), &P, dhl);
                oarrss_t res = oarrss_init(), alias = oarrss_copy(&SA);
                int st;

                st = oarrss_trunc_matmul_OO_to(oa, &SA, ob, &SB, &res, dhl);
                snprintf(ctx, sizeof(ctx), "soa trunc_matmul %s (%u, %u)", sc->label,
                    (unsigned)oa, (unsigned)ob);
                check(st == 0, "soa trunc_matmul status");

                // Orders past the truncation order give zero (P is truncated the same way).
                compare_array(&res, &ref, 1e-13, ctx, dhl);

                if (oa == 1 && ob == 1){

                    oarrss_trunc_matmul_OO_to(oa, &alias, ob, &SB, &alias, dhl);
                    snprintf(ctx, sizeof(ctx), "soa trunc_matmul aliased %s", sc->label);
                    compare_array(&alias, &ref, 1e-13, ctx, dhl);

                }

                arrso_free(&Ao);
                arrso_free(&Bo);
                arrso_free(&P);
                arrso_free(&ref);
                oarrss_free(&res);
                oarrss_free(&alias);

            }

        }

        {
            oarrss_t res = oarrss_init();

            check(oarrss_trunc_matmul_OO_to(1, &SB, 1, &SA, &res, dhl) == OTI_LINALG_ERR_SIZE,
                "soa trunc_matmul rejects unaligned shapes");
            oarrss_free(&res);
        }

        arrso_free(&A);
        arrso_free(&B);
        oarrss_free(&SA);
        oarrss_free(&SB);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_dot_product(dhelpl_t dhl){

    size_t s;
    char ctx[160];

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        arrso_t A = build_arrso(5, 1, sc->b1, sc->k1, 4, dhl);
        arrso_t B = build_arrso(1, 5, sc->b2, sc->k2, 3, dhl);
        arrso_t C = build_arrso(2, 3, sc->b2, sc->k2, 3, dhl);
        arrso_t D = build_arrso(2, 3, sc->b1, sc->k1, 2, dhl);
        oarrss_t SA = oarrss_from_arrso(&A, dhl), SB = oarrss_from_arrso(&B, dhl);
        oarrss_t SC = oarrss_from_arrso(&C, dhl), SD = oarrss_from_arrso(&D, dhl);
        sotinum_t ref1 = arrso_dotproduct_OO(&A, &B, dhl);
        sotinum_t ref2 = arrso_dotproduct_OO(&C, &D, dhl);
        ssotinum_t res = ssoti_init();

        check(oarrss_dot_product_OO_to(&SA, &SB, &res, dhl) == 0, "soa dot_product status");
        snprintf(ctx, sizeof(ctx), "soa dot_product (5,1).(1,5) %s", sc->label);
        compare_scalar(&res, &ref1, 1e-13, ctx, dhl);

        oarrss_dot_product_OO_to(&SC, &SD, &res, dhl);
        snprintf(ctx, sizeof(ctx), "soa dot_product (2,3).(2,3) %s", sc->label);
        compare_scalar(&res, &ref2, 1e-13, ctx, dhl);

        check(oarrss_dot_product_OO_to(&SA, &SC, &res, dhl) == OTI_LINALG_ERR_SIZE,
            "soa dot_product rejects different sizes");

        soti_free(&ref1);
        soti_free(&ref2);
        ssoti_free(&res);
        arrso_free(&A);
        arrso_free(&B);
        arrso_free(&C);
        arrso_free(&D);
        oarrss_free(&SA);
        oarrss_free(&SB);
        oarrss_free(&SC);
        oarrss_free(&SD);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_rom_eval_and_layouts(dhelpl_t dhl){

    arrso_t A = build_arrso(2, 3, SET_246, 3, 3, dhl);
    oarrss_t S = oarrss_from_arrso(&A, dhl), R = oarrss_init();
    coeff_t gdel[NB + 1], loc[8];
    arrso_t ref;
    bases_t u;
    uint64_t i, j, bad = 0;

    for (u = 0; u <= NB; u++){
        gdel[u] = rng_range(-0.3, 0.3);
    }

    for (u = 0; u < S.nbases; u++){
        loc[u] = gdel[S.p_bases[u] - 1];
    }

    ref = arrso_taylor_integrate(gdel, &A, dhl);
    oarrss_rom_eval_to(&S, loc, &R);

    for (i = 0; i < 2; i++){

        for (j = 0; j < 3; j++){
            bad += !approx_equal(R.p_data[i + j * 2], ref.p_data[j + i * 3].re, 1e-14);
        }

    }

    check(bad == 0 && R.nbases == 0 && R.trc_order == 0, "soa rom_eval vs arrso_taylor_integrate");
    oarrss_rom_eval_to(&S, loc, &S);
    check(S.nbases == 0 && approx_equal(S.p_data[1], ref.p_data[3].re, 1e-14),
        "soa rom_eval aliased");
    arrso_free(&ref);
    oarrss_free(&S);
    oarrss_free(&R);

    // get_all_ims / get_all_derivs against the per-element scalar layout.
    S = oarrss_from_arrso(&A, dhl);

    {
        ndir_t ntot = (ndir_t)dhelp_ndirTotal(6, 3);
        coeff_t* out = (coeff_t*)malloc(ntot * S.size * sizeof(coeff_t));
        coeff_t* col = (coeff_t*)malloc(ntot * sizeof(coeff_t));
        int derivs;

        for (derivs = 0; derivs <= 1; derivs++){

            ndir_t d;

            bad = 0;
            oarrss_get_all_ims_to(&S, 6, 3, derivs, out);

            for (i = 0; i < 2; i++){

                for (j = 0; j < 3; j++){

                    ssotinum_t item = oarrss_get_item(i, j, &S);

                    memset(col, 0, ntot * sizeof(coeff_t));
                    ssoti_get_all_ims_to(&item, 6, 3, derivs, col, 1);

                    for (d = 0; d < ntot; d++){
                        bad += (out[d * 6 + i * 3 + j] != col[d]);
                    }

                    ssoti_free(&item);

                }

            }

            check(bad == 0, derivs ? "soa get_all_derivs layout" : "soa get_all_ims layout");

        }

        free(out);
        free(col);
    }

    // get_order_im_array / add_order_im_array round trip, per order.
    {
        ord_t p;

        for (p = 0; p <= 3; p++){

            bases_t mb = (p == 0) ? 0 : oarrss_order_max_base(p, &S);
            ndir_t width = (p == 0) ? 1 : sshelp_ndir_order(mb, p);
            coeff_t* buf = (coeff_t*)malloc(S.size * width * sizeof(coeff_t));
            arrso_t part = arrso_get_order_im(p, &A, dhl);
            oarrss_t fresh = oarrss_zeros(NULL, 0, 2, 3, 0);
            char ctx[160];

            check(p == 0 || mb == 6, "soa order_max_base");

            oarrss_get_order_im_array_to(p, &S, width, buf);

            // The row-major layout against the scalar scatter of each element.
            bad = 0;

            for (i = 0; i < 2; i++){

                for (j = 0; j < 3; j++){

                    ssotinum_t item = oarrss_get_item(i, j, &S);
                    coeff_t* col = (coeff_t*)calloc(width, sizeof(coeff_t));
                    ndir_t g;

                    ssoti_scatter_order_im(p, &item, width, col, 1);

                    for (g = 0; g < width; g++){
                        bad += (buf[i * 3 * width + j + 3 * g] != col[g]);
                    }

                    free(col);
                    ssoti_free(&item);

                }

            }

            snprintf(ctx, sizeof(ctx), "soa get_order_im_array layout order %u", (unsigned)p);
            check(bad == 0, ctx);

            oarrss_add_order_im_array(p, buf, width, &fresh);
            snprintf(ctx, sizeof(ctx), "soa add_order_im_array round trip order %u", (unsigned)p);
            compare_array(&fresh, &part, 1e-15, ctx, dhl);

            free(buf);
            arrso_free(&part);
            oarrss_free(&fresh);

        }

    }

    oarrss_free(&S);
    arrso_free(&A);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_moving_average(dhelpl_t dhl){

    arrso_t A = build_arrso(7, 1, SET_12, 2, 3, dhl);
    oarrss_t S = oarrss_from_arrso(&A, dhl), R = oarrss_init();
    uint64_t sizes[4] = {1, 2, 3, 4}, w;
    int n = 7;

    for (w = 0; w < 4; w++){

        uint64_t size = sizes[w];
        int64_t left = (int64_t)size - (int64_t)(size / 2) - 1, right = (int64_t)size - left;
        coeff_t factor = 1.0 / (coeff_t)size;
        arrso_t ref = arrso_zeros_bases(7, 1, 0, 3, dhl);
        int k;
        char ctx[160];

        check(oarrss_moving_average_to(&S, size, &R) == 0, "soa moving_average status");

        // The sparse algorithm, in sotinum_t arithmetic.
        for (k = 0; k < n; k++){

            int64_t lo = k - left, hi = k + right;
            int64_t startj = lo > 0 ? lo : 0, endj = hi < n ? hi : n, j;
            int64_t ns = lo < 0 ? -lo : 0, ne = hi > n ? hi - n : 0;
            sotinum_t value = soti_createEmpty(3, dhl);

            if (ns > 0){

                sotinum_t t1 = soti_mul_ro((coeff_t)ns, &A.p_data[startj], dhl);
                sotinum_t t2 = soti_mul_ro(factor, &t1, dhl);

                soti_copy_to(&t2, &value, dhl);
                soti_free(&t1);
                soti_free(&t2);

            }

            if (ne > 0){

                sotinum_t t1 = soti_mul_ro((coeff_t)ne, &A.p_data[endj - 1], dhl);
                sotinum_t t2 = soti_mul_ro(factor, &t1, dhl);
                sotinum_t t3 = soti_sum_oo(&value, &t2, dhl);

                soti_copy_to(&t3, &value, dhl);
                soti_free(&t1);
                soti_free(&t2);
                soti_free(&t3);

            }

            for (j = startj; j < endj; j++){

                sotinum_t t1 = soti_mul_ro(factor, &A.p_data[j], dhl);
                sotinum_t t2 = soti_sum_oo(&value, &t1, dhl);

                soti_copy_to(&t2, &value, dhl);
                soti_free(&t1);
                soti_free(&t2);

            }

            soti_copy_to(&value, &ref.p_data[k], dhl);
            soti_free(&value);

        }

        snprintf(ctx, sizeof(ctx), "soa moving_average size %llu", (unsigned long long)size);
        compare_array(&R, &ref, 1e-15, ctx, dhl);
        arrso_free(&ref);

    }

    check(oarrss_moving_average_to(&S, 0, &R) == OTI_LINALG_ERR_SIZE,
        "soa moving_average rejects size 0");

    arrso_free(&A);
    oarrss_free(&S);
    oarrss_free(&R);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_interp1d(dhelpl_t dhl){

    arrso_t X = build_arrso(4, 1, SET_12, 2, 3, dhl);
    arrso_t Y = build_arrso(4, 1, SET_246, 3, 3, dhl);
    oarrss_t SX, SY;
    coeff_t reals[4] = {0.0, 1.0, 2.5, 4.0};
    coeff_t probes[6] = {-1.0, 0.0, 0.3, 2.5, 3.9, 5.0};
    int t, i;

    for (i = 0; i < 4; i++){
        X.p_data[i].re = reals[i];
    }

    SX = oarrss_from_arrso(&X, dhl);
    SY = oarrss_from_arrso(&Y, dhl);

    for (t = 0; t < 6; t++){

        sotinum_t x = build_soti(SET_135, 3, 3, probes[t], dhl), ref;
        ssotinum_t sx = ssoti_from_soti(&x, dhl), res = ssoti_init();
        char ctx[160];

        if (probes[t] < reals[0]){

            ref = soti_copy(&Y.p_data[0], dhl);

        } else if (probes[t] > reals[3]){

            ref = soti_copy(&Y.p_data[3], dhl);

        } else {

            int m = 1;
            sotinum_t dy, dx, sl, tt, pr;

            while (m < 3 && probes[t] > reals[m]){
                m++;
            }

            dy = soti_sub_oo(&Y.p_data[m], &Y.p_data[m - 1], dhl);
            dx = soti_sub_oo(&X.p_data[m], &X.p_data[m - 1], dhl);
            sl = soti_div_oo(&dy, &dx, dhl);
            tt = soti_sub_oo(&x, &X.p_data[m - 1], dhl);
            pr = soti_mul_oo(&sl, &tt, dhl);
            ref = soti_sum_oo(&pr, &Y.p_data[m - 1], dhl);

            soti_free(&dy);
            soti_free(&dx);
            soti_free(&sl);
            soti_free(&tt);
            soti_free(&pr);

        }

        check(oarrss_interp1d_o_to(&SX, &SY, &sx, &res, dhl) == 0, "soa interp1d status");
        snprintf(ctx, sizeof(ctx), "soa interp1d at %g", probes[t]);
        compare_scalar(&res, &ref, 1e-13, ctx, dhl);

        soti_free(&x);
        soti_free(&ref);
        ssoti_free(&sx);
        ssoti_free(&res);

    }

    // Array of points against the scalar version per element.
    {
        arrso_t P = build_arrso(2, 2, SET_135, 3, 2, dhl);
        oarrss_t SP, R = oarrss_init();
        uint64_t bad = 0, r, c;

        P.p_data[0].re = 0.5;
        P.p_data[1].re = 3.0;
        P.p_data[2].re = -2.0;
        P.p_data[3].re = 2.0;
        SP = oarrss_from_arrso(&P, dhl);

        check(oarrss_interp1d_O_to(&SX, &SY, &SP, &R, dhl) == 0, "soa interp1d array status");

        for (r = 0; r < 2; r++){

            for (c = 0; c < 2; c++){

                ssotinum_t xe = oarrss_get_item(r, c, &SP), ye = ssoti_init();
                ssotinum_t got = oarrss_get_item(r, c, &R);
                sotinum_t yes;

                oarrss_interp1d_o_to(&SX, &SY, &xe, &ye, dhl);
                yes = ssoti_to_soti(&ye, dhl);
                bad += count_mismatch(&got, &yes, 1e-15, dhl);

                soti_free(&yes);
                ssoti_free(&xe);
                ssoti_free(&ye);
                ssoti_free(&got);

            }

        }

        check(bad == 0, "soa interp1d array vs scalar");

        arrso_free(&P);
        oarrss_free(&SP);
        oarrss_free(&R);
    }

    arrso_free(&X);
    arrso_free(&Y);
    oarrss_free(&SX);
    oarrss_free(&SY);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);
    g_rng_state = 0x5EED5EED12345678ULL;

    test_scalar_extract(dhl);
    test_scalar_trunc_sub(dhl);
    test_scalar_rom_eval(dhl);
    test_scalar_global_layouts(dhl);
    test_soa_extract(dhl);
    test_soa_trunc_sub(dhl);
    test_soa_trunc_matmul(dhl);
    test_soa_dot_product(dhl);
    test_soa_rom_eval_and_layouts(dhl);
    test_soa_moving_average(dhl);
    test_soa_interp1d(dhl);

    ssoti_ws_release();
    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse utils test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse utils tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
