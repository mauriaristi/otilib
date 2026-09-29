/* Independent checks of the semi-sparse SoA array type (include/oti/semisparse/soa/{structures,
 * base,algebra}.h, PLAN-semisparse.md step 3). The oracle is arrso_t: operands are built as
 * arrso_t (each element an independently random sotinum_t), converted with oarrss_from_arrso(),
 * run through the oarrss_ kernel under test, and compared element by element against the same
 * arrso_ operation applied to the same arrso_t inputs (oarrss_get_item() / soti_get_item() at
 * matching global directions, so the comparison does not itself depend on oarrss_to_arrso()).
 * Covers memory/access, conversion round trips, add_bases, truncation/compaction, elementwise
 * algebra (OO/oO/rO/Oo/Or) and functions, matmul (square and non-square), transpose, aliasing, and
 * 1 vs N OpenMP threads for a large elementwise mul and exp.
 *
 * IMPORTANT: arrso_t stores elements row-major, (i, j) at p_data[j + i*ncols]; oarrss_t blocks are
 * column-major, (i, j) at block[i + j*nrows]. Every comparison below reads arrso_t with the
 * row-major mapping and oarrss_t through its own accessors (which already use column-major
 * indexing internally). */
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
static double rng_uniform(void){

    return (double)(rng_next() >> 11) / (double)(1ULL << 53);

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
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A random sotinum_t over the given active bases: order 1 is always set explicitly for every base
 * (possibly to 0), so the base is guaranteed present per ssoti_from_soti's contract; orders 2.. up
 * to max_order are a `density` fraction of the local directions, each mapped to its global index. */
static sotinum_t build_soti_elem(const bases_t* bases, bases_t k, ord_t trc, ord_t max_order,
                                 double density, coeff_t re, dhelpl_t dhl){

    sotinum_t num = soti_createEmpty(trc, dhl);
    ord_t p;
    bases_t i;

    soti_set_item(re, 0, 0, &num, dhl);

    for (i = 0; i < k; i++){

        double v = (rng_uniform() < density) ? rng_range(-0.3, 0.3) : 0.0;

        soti_set_item(v, (imdir_t)(bases[i] - 1), 1, &num, dhl);

    }

    for (p = 2; p <= max_order; p++){

        bases_t u[8];
        ndir_t ndir = sshelp_ndir_order(k, p);
        ndir_t j;

        if (ndir == 0){
            continue;
        }

        memset(u, 0, sizeof(u));

        for (j = 0; j < ndir; j++){

            if (rng_uniform() < density){

                bases_t g[8];
                ord_t ii;
                imdir_t gidx;

                for (ii = 0; ii < p; ii++){
                    g[ii] = bases[u[ii]];
                }

                gidx = sshelp_global_rank(g, p);
                soti_set_item(rng_range(-0.3, 0.3), gidx, p, &num, dhl);

            }

            sshelp_next_dir(u, p, k);

        }

    }

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* An nrows x ncols arrso_t whose elements are each an independent build_soti_elem() over the same
 * (bases, k, trc, max_order) family, real parts spread over [re_lo, re_hi]. */
static arrso_t build_arrso_operand(uint64_t nrows, uint64_t ncols, const bases_t* bases, bases_t k,
                                   ord_t trc, ord_t max_order, double density, double re_lo,
                                   double re_hi, dhelpl_t dhl){

    arrso_t arr = arrso_zeros_bases(nrows, ncols, 0, trc, dhl);
    uint64_t e;

    for (e = 0; e < arr.size; e++){

        sotinum_t tmp = build_soti_elem(bases, k, trc, max_order, density,
            rng_range(re_lo, re_hi), dhl);

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
/* Every element and every direction of `res`'s own active set against soti_get_item on the
 * matching arrso_t oracle element (row-major), at the same global (idx, order). */
static void compare_oarrss_vs_arrso(const oarrss_t* res, arrso_t* oracle, dhelpl_t dhl, double tol,
                                    const char* ctx){

    uint64_t i, j, n_checked = 0, n_mismatch = 0;
    const uint64_t max_reported = 5;
    char name[224];

    check(res->nrows == oracle->nrows && res->ncols == oracle->ncols, ctx);

    for (i = 0; i < res->nrows; i++){

        for (j = 0; j < res->ncols; j++){

            ssotinum_t item = oarrss_get_item(i, j, res);
            sotinum_t* oracle_elem = &oracle->p_data[j + i * oracle->ncols];
            ord_t p;

            n_checked++;

            if (!approx_equal(item.re, oracle_elem->re, tol)){

                if (n_mismatch < max_reported){
                    fprintf(stderr, "  mismatch %s (%llu,%llu) real: oarrss=%.17g arrso=%.17g\n",
                        ctx, (unsigned long long)i, (unsigned long long)j, item.re,
                        oracle_elem->re);
                }

                n_mismatch++;

            }

            for (p = 1; p <= item.trc_order; p++){

                ndir_t ndir = sshelp_ndir_order(item.nbases, p);
                ndir_t idx;

                for (idx = 0; idx < ndir; idx++){

                    imdir_t gidx;
                    coeff_t v1, v2;

                    sshelp_local_to_global(idx, p, item.p_bases, item.nbases, &gidx);
                    v1 = ssoti_get_item(gidx, p, &item);
                    v2 = soti_get_item(gidx, p, oracle_elem, dhl);
                    n_checked++;

                    if (!approx_equal(v1, v2, tol)){

                        if (n_mismatch < max_reported){
                            fprintf(stderr,
                                "  mismatch %s (%llu,%llu) order=%u idx=%llu: oarrss=%.17g "
                                "arrso=%.17g\n", ctx, (unsigned long long)i, (unsigned long long)j,
                                (unsigned)p, (unsigned long long)idx, v1, v2);
                        }

                        n_mismatch++;

                    }

                }

            }

            ssoti_free(&item);

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu directions match", ctx,
        (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     SCENARIOS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

static const bases_t SET_A[2]       = {1, 2};
static const bases_t SET_B_SUPER[4] = {1, 2, 3, 4};
static const bases_t SET_C[2]       = {1, 3};
static const bases_t SET_D[2]       = {2, 4};
static const bases_t SET_E[2]       = {3, 4};

typedef struct {
    const bases_t* bases1; bases_t k1;
    const bases_t* bases2; bases_t k2;
    const char* label;
} scenario_t;

static const scenario_t SCENARIOS[] = {
    { SET_A,       2, SET_A,       2, "same" },
    { SET_A,       2, SET_B_SUPER, 4, "leading" },
    { SET_C,       2, SET_D,       2, "interleaved" },
    { SET_A,       2, SET_E,       2, "disjoint" },
    { NULL,        0, SET_B_SUPER, 4, "empty_op1" },
    { NULL,        0, NULL,        0, "both_real" },
};

#define N_SCENARIOS (sizeof(SCENARIOS) / sizeof(SCENARIOS[0]))

static const ord_t TRC = 4;
static const ord_t MAXORDER = 4;
static const double DENSITY = 0.6;


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MEMORY AND ACCESS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_memory_and_access(void){

    bases_t bases[3] = {1, 2, 4};
    oarrss_t arr = oarrss_zeros(bases, 3, 2, 3, 3);
    ssotinum_t num = ssoti_create_empty(bases, 3, 3);
    coeff_t* blk;

    check(arr.nrows == 2 && arr.ncols == 3 && arr.size == 6, "zeros: shape");
    check(arr.nbases == 3 && arr.trc_order == 3 && arr.act_order == 0, "zeros: fields");
    check(oarrss_density(&arr) == 0.0, "zeros: density is 0");

    ssoti_set_item(1.5, 0, 1, &num);
    { bases_t g[2] = {2, 4}; imdir_t gidx = sshelp_global_rank(g, 2); ssoti_set_item(-2.5, gidx, 2, &num); }

    oarrss_set_item(&num, 1, 2, &arr);
    check(arr.act_order == 2, "set_item: raises act_order");

    {
        ssotinum_t got = oarrss_get_item(1, 2, &arr);

        check(approx_equal(got.re, num.re, 0.0), "get_item: real part round trip");
        check(ssoti_get_item(0, 1, &got) == 1.5, "get_item: order1 coefficient round trip");
        { bases_t g[2] = {2, 4}; imdir_t gidx = sshelp_global_rank(g, 2);
            check(ssoti_get_item(gidx, 2, &got) == -2.5, "get_item: order2 coefficient round trip"); }
        ssoti_free(&got);
    }

    {
        ssotinum_t other = oarrss_get_item(0, 0, &arr);

        check(other.re == 0.0, "get_item: untouched element is zero");
        ssoti_free(&other);
    }

    blk = oarrss_get_block(0, 1, &arr);
    check(blk != NULL && blk[1 + 2 * arr.nrows] == 1.5, "get_block: order1 block matches set value");
    check(oarrss_get_block(999999, 1, &arr) == NULL, "get_block: inactive base returns NULL");
    check(oarrss_get_block(0, 9, &arr) == NULL, "get_block: order above trc_order returns NULL");

    oarrss_set_item_r(7.0, 0, 0, &arr);
    {
        ssotinum_t got = oarrss_get_item(0, 0, &arr);

        check(got.re == 7.0, "set_item_r: real part set");
        { bases_t g[1] = {1}; imdir_t gidx = sshelp_global_rank(g, 1);
            check(ssoti_get_item(gidx, 1, &got) == 0.0, "set_item_r: imaginary part cleared"); }
        ssoti_free(&got);
    }

    check(oarrss_density(&arr) > 0.0, "density: nonzero after setting coefficients");
    check(oarrss_memory_size(&arr) > 0, "memory_size: positive");

    {
        oarrss_t eye = oarrss_eye(3, 2);
        ssotinum_t d0 = oarrss_get_item(0, 0, &eye), d1 = oarrss_get_item(0, 1, &eye);

        check(d0.re == 1.0, "eye: diagonal is 1");
        check(d1.re == 0.0, "eye: off-diagonal is 0");
        ssoti_free(&d0);
        ssoti_free(&d1);
        oarrss_free(&eye);
    }

    {
        coeff_t data[4] = {1.0, 2.0, 3.0, 4.0};
        oarrss_t r = oarrss_from_real(data, 2, 2, 2);
        ssotinum_t e00 = oarrss_get_item(0, 0, &r), e10 = oarrss_get_item(1, 0, &r);

        check(e00.re == 1.0 && e10.re == 2.0, "from_real: column-major layout");
        ssoti_free(&e00);
        ssoti_free(&e10);
        oarrss_free(&r);
    }

    ssoti_free(&num);
    oarrss_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     CONVERSION ROUND TRIP     ------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_conversion_roundtrip(dhelpl_t dhl){

    size_t s;
    static const struct { uint64_t nrows, ncols; } SHAPES[] = { {1,1}, {3,3}, {4,2} };
    size_t sh;

    for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

        for (s = 0; s < N_SCENARIOS; s++){

            const scenario_t* sc = &SCENARIOS[s];
            arrso_t arr = build_arrso_operand(SHAPES[sh].nrows, SHAPES[sh].ncols, sc->bases1, sc->k1,
                TRC, MAXORDER, DENSITY, 0.5, 1.5, dhl);
            oarrss_t soa = oarrss_from_arrso(&arr, dhl);
            char ctx[128];

            snprintf(ctx, sizeof(ctx), "from_arrso(%llux%llu,%s)",
                (unsigned long long)SHAPES[sh].nrows, (unsigned long long)SHAPES[sh].ncols,
                sc->label);
            compare_oarrss_vs_arrso(&soa, &arr, dhl, 0.0, ctx);

            {
                arrso_t back = oarrss_to_arrso(&soa, dhl);
                oarrss_t roundtrip = oarrss_from_arrso(&back, dhl);
                char ctx2[144];

                snprintf(ctx2, sizeof(ctx2), "to_arrso/from_arrso roundtrip(%llux%llu,%s)",
                    (unsigned long long)SHAPES[sh].nrows, (unsigned long long)SHAPES[sh].ncols,
                    sc->label);
                compare_oarrss_vs_arrso(&roundtrip, &arr, dhl, 0.0, ctx2);

                oarrss_free(&roundtrip);
                arrso_free(&back);
            }

            oarrss_free(&soa);
            arrso_free(&arr);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ADD_BASES     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_add_bases(dhelpl_t dhl){

    {
        bases_t add[2] = {3, 4};
        arrso_t arr = build_arrso_operand(3, 2, SET_A, 2, TRC, MAXORDER, DENSITY, 0.5, 1.5, dhl);
        oarrss_t before = oarrss_from_arrso(&arr, dhl);
        oarrss_t after = oarrss_copy(&before);

        oarrss_add_bases(add, 2, &after);

        check(after.nbases == 4, "add_bases (leading): new nbases");
        check(after.p_bases[0] == 1 && after.p_bases[1] == 2 && after.p_bases[2] == 3
            && after.p_bases[3] == 4, "add_bases (leading): new active set");
        compare_oarrss_vs_arrso(&after, &arr, dhl, 0.0, "add_bases(leading) value preserved");

        oarrss_free(&before);
        oarrss_free(&after);
        arrso_free(&arr);
    }

    {
        bases_t add[2] = {2, 3};
        arrso_t arr = build_arrso_operand(2, 3, SET_D, 2, TRC, MAXORDER, DENSITY, 0.5, 1.5, dhl);

        // SET_D = {2,4}; adding {2,3} enlarges to {2,3,4}, base 2 already active (no-op there),
        // base 3 lands between 2 and 4: interleaved growth.
        oarrss_t before = oarrss_from_arrso(&arr, dhl);
        oarrss_t after = oarrss_copy(&before);

        oarrss_add_bases(add, 2, &after);

        check(after.nbases == 3, "add_bases (interleaved): new nbases");
        check(after.p_bases[0] == 2 && after.p_bases[1] == 3 && after.p_bases[2] == 4,
            "add_bases (interleaved): new active set");
        compare_oarrss_vs_arrso(&after, &arr, dhl, 0.0, "add_bases(interleaved) value preserved");

        oarrss_free(&before);
        oarrss_free(&after);
        arrso_free(&arr);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ELEMENTWISE ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef void (*arrso_OO_fn)(arrso_t*, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*oarrss_OO_fn)(const oarrss_t*, const oarrss_t*, oarrss_t*, dhelpl_t);

typedef struct { const char* name; arrso_OO_fn arrso_fn; oarrss_OO_fn oarrss_fn; double tol; }
    oo_op_t;

static const oo_op_t OO_OPS[] = {
    { "sum_OO", arrso_sum_OO_to, oarrss_sum_OO_to, 0.0 },
    { "sub_OO", arrso_sub_OO_to, oarrss_sub_OO_to, 0.0 },
    { "mul_OO", arrso_mul_OO_to, oarrss_mul_OO_to, 1e-9 },
    { "div_OO", arrso_div_OO_to, oarrss_div_OO_to, 1e-9 },
};

#define N_OO_OPS (sizeof(OO_OPS) / sizeof(OO_OPS[0]))


// *******************************************************************************************************
static void test_elementwise_OO(dhelpl_t dhl){

    static const struct { uint64_t nrows, ncols; } SHAPES[] = { {1,1}, {3,3}, {4,2} };
    size_t sh, s, o;

    for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

        for (s = 0; s < N_SCENARIOS; s++){

            const scenario_t* sc = &SCENARIOS[s];
            arrso_t arr1 = build_arrso_operand(SHAPES[sh].nrows, SHAPES[sh].ncols, sc->bases1,
                sc->k1, TRC, MAXORDER, DENSITY, 0.6, 1.4, dhl);
            arrso_t arr2 = build_arrso_operand(SHAPES[sh].nrows, SHAPES[sh].ncols, sc->bases2,
                sc->k2, TRC, MAXORDER, DENSITY, 0.4, 0.9, dhl);
            oarrss_t soa1 = oarrss_from_arrso(&arr1, dhl);
            oarrss_t soa2 = oarrss_from_arrso(&arr2, dhl);

            for (o = 0; o < N_OO_OPS; o++){

                arrso_t oracle = arrso_empty_like(&arr1, dhl);
                oarrss_t res = oarrss_init();
                char ctx[144];

                OO_OPS[o].arrso_fn(&arr1, &arr2, &oracle, dhl);
                OO_OPS[o].oarrss_fn(&soa1, &soa2, &res, dhl);

                snprintf(ctx, sizeof(ctx), "%s(%llux%llu,%s)", OO_OPS[o].name,
                    (unsigned long long)SHAPES[sh].nrows, (unsigned long long)SHAPES[sh].ncols,
                    sc->label);
                compare_oarrss_vs_arrso(&res, &oracle, dhl, OO_OPS[o].tol, ctx);

                oarrss_free(&res);
                arrso_free(&oracle);

            }

            oarrss_free(&soa1);
            oarrss_free(&soa2);
            arrso_free(&arr1);
            arrso_free(&arr2);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Scalar/array and real/array variants (oO, rO, Oo, Or), one representative scenario/shape. */
static void test_elementwise_mixed(dhelpl_t dhl){

    const scenario_t* sc = &SCENARIOS[1];
    arrso_t arr1 = build_arrso_operand(3, 2, sc->bases1, sc->k1, TRC, MAXORDER, DENSITY, 0.6, 1.4,
        dhl);
    sotinum_t soti_scalar = build_soti_elem(sc->bases2, sc->k2, TRC, MAXORDER, DENSITY, 0.7, dhl);
    ssotinum_t ss_scalar = ssoti_from_soti(&soti_scalar, dhl);
    oarrss_t soa1 = oarrss_from_arrso(&arr1, dhl);
    coeff_t val = 0.65;

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_sum_oO_to(&soti_scalar, &arr1, &oracle, dhl);
        oarrss_sum_oO_to(&ss_scalar, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "sum_oO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_sub_oO_to(&soti_scalar, &arr1, &oracle, dhl);
        oarrss_sub_oO_to(&ss_scalar, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "sub_oO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_mul_oO_to(&soti_scalar, &arr1, &oracle, dhl);
        oarrss_mul_oO_to(&ss_scalar, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "mul_oO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_div_oO_to(&soti_scalar, &arr1, &oracle, dhl);
        oarrss_div_oO_to(&ss_scalar, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "div_oO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_sum_rO_to(val, &arr1, &oracle, dhl);
        oarrss_sum_rO_to(val, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "sum_rO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_sub_rO_to(val, &arr1, &oracle, dhl);
        oarrss_sub_rO_to(val, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "sub_rO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_mul_rO_to(val, &arr1, &oracle, dhl);
        oarrss_mul_rO_to(val, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "mul_rO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_div_rO_to(val, &arr1, &oracle, dhl);
        oarrss_div_rO_to(val, &soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "div_rO");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_sub_Oo_to(&arr1, &soti_scalar, &oracle, dhl);
        oarrss_sub_Oo_to(&soa1, &ss_scalar, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "sub_Oo");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_div_Oo_to(&arr1, &soti_scalar, &oracle, dhl);
        oarrss_div_Oo_to(&soa1, &ss_scalar, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "div_Oo");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_sub_Or_to(&arr1, val, &oracle, dhl);
        oarrss_sub_Or_to(&soa1, val, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "sub_Or");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_empty_like(&arr1, dhl);
        oarrss_t res = oarrss_init();

        arrso_div_Or_to(&arr1, val, &oracle, dhl);
        oarrss_div_Or_to(&soa1, val, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "div_Or");
        oarrss_free(&res); arrso_free(&oracle);
    }

    {
        arrso_t oracle = arrso_neg(&arr1, dhl);
        oarrss_t res = oarrss_init();

        oarrss_neg_to(&soa1, &res, dhl);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "neg");
        oarrss_free(&res); arrso_free(&oracle);
    }

    ssoti_free(&ss_scalar);
    soti_free(&soti_scalar);
    oarrss_free(&soa1);
    arrso_free(&arr1);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     FUNCTIONS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef void (*arrso_un_fn)(arrso_t*, arrso_t*, dhelpl_t);
typedef void (*oarrss_un_fn)(const oarrss_t*, oarrss_t*, dhelpl_t);

typedef struct { const char* name; coeff_t re_lo, re_hi; arrso_un_fn arrso_fn; oarrss_un_fn oarrss_fn; }
    unary_case_t;

static const unary_case_t UNARY_FUNCS[] = {
    { "exp",   0.8, 1.4, arrso_exp_to,   oarrss_exp_to },
    { "log",   0.8, 1.4, arrso_log_to,   oarrss_log_to },
    { "log10", 0.8, 1.4, arrso_log10_to, oarrss_log10_to },
    { "sqrt",  0.8, 1.4, arrso_sqrt_to,  oarrss_sqrt_to },
    { "cbrt",  0.8, 1.4, arrso_cbrt_to,  oarrss_cbrt_to },
    { "sin",   0.2, 0.9, arrso_sin_to,   oarrss_sin_to },
    { "cos",   0.2, 0.9, arrso_cos_to,   oarrss_cos_to },
    { "tan",   0.1, 0.5, arrso_tan_to,   oarrss_tan_to },
    { "asin",  0.1, 0.5, arrso_asin_to,  oarrss_asin_to },
    { "acos",  0.1, 0.5, arrso_acos_to,  oarrss_acos_to },
    { "atan",  0.2, 0.9, arrso_atan_to,  oarrss_atan_to },
    { "sinh",  0.2, 0.9, arrso_sinh_to,  oarrss_sinh_to },
    { "cosh",  0.2, 0.9, arrso_cosh_to,  oarrss_cosh_to },
    { "tanh",  0.2, 0.9, arrso_tanh_to,  oarrss_tanh_to },
    { "asinh", 0.2, 0.9, arrso_asinh_to, oarrss_asinh_to },
    { "acosh", 1.2, 1.8, arrso_acosh_to, oarrss_acosh_to },
    { "atanh", 0.1, 0.5, arrso_atanh_to, oarrss_atanh_to },
    { "erf",   0.2, 0.9, arrso_erf_to,   oarrss_erf_to },
};

#define N_UNARY_FUNCS (sizeof(UNARY_FUNCS) / sizeof(UNARY_FUNCS[0]))


// *******************************************************************************************************
static void test_functions(dhelpl_t dhl){

    size_t f;
    const scenario_t* sc = &SCENARIOS[2];

    for (f = 0; f < N_UNARY_FUNCS; f++){

        arrso_t arr = build_arrso_operand(3, 3, sc->bases1, sc->k1, TRC, MAXORDER, DENSITY,
            UNARY_FUNCS[f].re_lo, UNARY_FUNCS[f].re_hi, dhl);
        arrso_t oracle = arrso_empty_like(&arr, dhl);
        oarrss_t soa = oarrss_from_arrso(&arr, dhl);
        oarrss_t res = oarrss_init();
        char ctx[64];

        UNARY_FUNCS[f].arrso_fn(&arr, &oracle, dhl);
        UNARY_FUNCS[f].oarrss_fn(&soa, &res, dhl);

        snprintf(ctx, sizeof(ctx), "%s", UNARY_FUNCS[f].name);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, ctx);

        oarrss_free(&res);
        oarrss_free(&soa);
        arrso_free(&oracle);
        arrso_free(&arr);

    }

    {
        double exps[2] = {2.5, -1.0};
        int e;

        for (e = 0; e < 2; e++){

            arrso_t arr = build_arrso_operand(3, 3, sc->bases1, sc->k1, TRC, MAXORDER, DENSITY,
                0.8, 1.4, dhl);
            arrso_t oracle = arrso_empty_like(&arr, dhl);
            oarrss_t soa = oarrss_from_arrso(&arr, dhl);
            oarrss_t res = oarrss_init();
            char ctx[64];

            arrso_pow_to(&arr, exps[e], &oracle, dhl);
            oarrss_pow_to(&soa, exps[e], &res, dhl);

            snprintf(ctx, sizeof(ctx), "pow(e=%.1f)", exps[e]);
            compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, ctx);

            oarrss_free(&res);
            oarrss_free(&soa);
            arrso_free(&oracle);
            arrso_free(&arr);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MATMUL AND TRANSPOSE     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    {
        // Square.
        arrso_t a = build_arrso_operand(3, 3, SET_A, 2, TRC, MAXORDER, DENSITY, 0.5, 1.2, dhl);
        arrso_t b = build_arrso_operand(3, 3, SET_D, 2, TRC, MAXORDER, DENSITY, 0.3, 0.9, dhl);
        arrso_t oracle = arrso_matmul_OO(&a, &b, dhl);
        oarrss_t soa_a = oarrss_from_arrso(&a, dhl), soa_b = oarrss_from_arrso(&b, dhl);
        oarrss_t res = oarrss_init();
        int status = oarrss_matmul_OO_to(&soa_a, &soa_b, &res, dhl);

        check(status == 0, "matmul (square): status 0");
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "matmul_OO (square 3x3 * 3x3)");

        oarrss_free(&res); oarrss_free(&soa_a); oarrss_free(&soa_b);
        arrso_free(&oracle); arrso_free(&a); arrso_free(&b);
    }

    {
        // Non-square: (3x4) * (4x2).
        arrso_t a = build_arrso_operand(3, 4, SET_A, 2, TRC, MAXORDER, DENSITY, 0.5, 1.2, dhl);
        arrso_t b = build_arrso_operand(4, 2, SET_D, 2, TRC, MAXORDER, DENSITY, 0.3, 0.9, dhl);
        arrso_t oracle = arrso_matmul_OO(&a, &b, dhl);
        oarrss_t soa_a = oarrss_from_arrso(&a, dhl), soa_b = oarrss_from_arrso(&b, dhl);
        oarrss_t res = oarrss_init();
        int status = oarrss_matmul_OO_to(&soa_a, &soa_b, &res, dhl);

        check(status == 0, "matmul (non-square): status 0");
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 1e-9, "matmul_OO (3x4 * 4x2)");

        oarrss_free(&res); oarrss_free(&soa_a); oarrss_free(&soa_b);
        arrso_free(&oracle); arrso_free(&a); arrso_free(&b);
    }

    {
        // Mismatched inner dimension.
        arrso_t a = build_arrso_operand(2, 3, SET_A, 2, TRC, MAXORDER, DENSITY, 0.5, 1.2, dhl);
        arrso_t b = build_arrso_operand(2, 2, SET_D, 2, TRC, MAXORDER, DENSITY, 0.3, 0.9, dhl);
        oarrss_t soa_a = oarrss_from_arrso(&a, dhl), soa_b = oarrss_from_arrso(&b, dhl);
        oarrss_t res = oarrss_init();
        int status = oarrss_matmul_OO_to(&soa_a, &soa_b, &res, dhl);

        check(status == OTI_LINALG_ERR_SIZE, "matmul: mismatched inner dim reports error");

        oarrss_free(&res); oarrss_free(&soa_a); oarrss_free(&soa_b);
        arrso_free(&a); arrso_free(&b);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose(dhelpl_t dhl){

    arrso_t arr = build_arrso_operand(4, 2, SET_A, 2, TRC, MAXORDER, DENSITY, 0.5, 1.2, dhl);
    arrso_t oracle = arrso_transpose(&arr, dhl);
    oarrss_t soa = oarrss_from_arrso(&arr, dhl);
    oarrss_t res = oarrss_init();

    oarrss_transpose_to(&soa, &res, dhl);

    check(res.nrows == 2 && res.ncols == 4, "transpose: shape swapped");
    compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "transpose (4x2 -> 2x4)");

    oarrss_free(&res);
    oarrss_free(&soa);
    arrso_free(&oracle);
    arrso_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     TRUNCATION AND COMPACT     -----------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_truncation(dhelpl_t dhl){

    arrso_t arr = build_arrso_operand(3, 2, SET_B_SUPER, 4, TRC, MAXORDER, DENSITY, 0.6, 1.4, dhl);
    oarrss_t soa = oarrss_from_arrso(&arr, dhl);
    ord_t order;

    for (order = 0; order <= TRC; order++){

        arrso_t oracle = arrso_truncate_order(order, &arr, dhl);
        oarrss_t res = oarrss_init();
        char ctx[64];

        oarrss_truncate_order_to(order, &soa, &res);

        snprintf(ctx, sizeof(ctx), "truncate_order(%u)", (unsigned)order);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, ctx);

        oarrss_free(&res);
        arrso_free(&oracle);

    }

    for (order = 0; order <= TRC; order++){

        arrso_t oracle = arrso_get_order_im(order, &arr, dhl);
        oarrss_t res = oarrss_init();
        char ctx[64];

        oarrss_get_order_im_to(order, &soa, &res);

        snprintf(ctx, sizeof(ctx), "get_order_im(%u)", (unsigned)order);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, ctx);

        oarrss_free(&res);
        arrso_free(&oracle);

    }

    {
        bases_t g2[2] = {2, 3};
        imdir_t idx2 = sshelp_global_rank(g2, 2);
        arrso_t oracle = arrso_truncate_im(idx2, 2, &arr, dhl);
        oarrss_t res = oarrss_init();

        oarrss_truncate_im_to(idx2, 2, &soa, &res);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "truncate_im(order2 dir (2,3))");

        oarrss_free(&res);
        arrso_free(&oracle);
    }

    {
        bases_t g4[4] = {1, 2, 3, 4};
        imdir_t idx4 = sshelp_global_rank(g4, 4);
        arrso_t oracle = arrso_truncate_im(idx4, 4, &arr, dhl);
        oarrss_t res = oarrss_init();

        oarrss_truncate_im_to(idx4, 4, &soa, &res);
        compare_oarrss_vs_arrso(&res, &oracle, dhl, 0.0, "truncate_im(order4 dir (1,2,3,4))");

        oarrss_free(&res);
        arrso_free(&oracle);
    }

    oarrss_free(&soa);
    arrso_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A base that is zero in every element (across the whole array) is dropped; a base that is nonzero
 * in at least one element is kept. Value is unchanged (checked via compare_oarrss_vs_arrso against
 * the original arrso oracle, which does not depend on oarrss's internal active set). */
static void test_compact(dhelpl_t dhl){

    bases_t bases[3] = {1, 2, 3};
    oarrss_t arr = oarrss_zeros(bases, 3, 2, 2, 3);
    arrso_t oracle = arrso_zeros_bases(2, 2, 0, 3, dhl);
    ssotinum_t nz;
    uint64_t i, j;

    // Base 2 is zero in every element; bases 1 and 3 are nonzero in at least one element.
    for (i = 0; i < 2; i++){

        for (j = 0; j < 2; j++){

            bases_t g[1];
            imdir_t gidx;
            coeff_t v = 0.3 + (coeff_t)(i + 2 * j);

            g[0] = (bases_t)((i + j) % 2 == 0 ? 1 : 3);
            gidx = sshelp_global_rank(g, 1);

            nz = ssoti_create_empty(bases, 3, 3);
            ssoti_set_item(v, gidx, 1, &nz);
            oarrss_set_item(&nz, i, j, &arr);
            ssoti_free(&nz);

        }

    }

    {
        oarrss_t before = oarrss_copy(&arr);
        oarrss_t after = oarrss_init();

        oarrss_compact_to(&arr, &after);

        check(after.nbases == 2, "compact: drops the all-zero base");
        check(after.p_bases[0] == 1 && after.p_bases[1] == 3, "compact: kept bases are {1,3}");

        // Cross-check against the arrso oracle built independently with only bases {1,3}.
        for (i = 0; i < 2; i++){

            for (j = 0; j < 2; j++){

                bases_t g[1];
                imdir_t gidx;
                coeff_t v = 0.3 + (coeff_t)(i + 2 * j);

                g[0] = (bases_t)((i + j) % 2 == 0 ? 1 : 3);
                gidx = sshelp_global_rank(g, 1);
                soti_set_item(v, gidx, 1, &oracle.p_data[j + i * oracle.ncols], dhl);

            }

        }

        compare_oarrss_vs_arrso(&after, &oracle, dhl, 0.0, "compact: value unchanged vs oracle");

        oarrss_free(&before);
        oarrss_free(&after);
    }

    oarrss_free(&arr);
    arrso_free(&oracle);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ALIASING     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_aliasing(dhelpl_t dhl){

    const scenario_t* sc = &SCENARIOS[1];
    arrso_t arr1 = build_arrso_operand(2, 2, sc->bases1, sc->k1, TRC, MAXORDER, DENSITY, 0.6, 1.4,
        dhl);
    arrso_t arr2 = build_arrso_operand(2, 2, sc->bases2, sc->k2, TRC, MAXORDER, DENSITY, 0.4, 0.9,
        dhl);
    oarrss_t soa1 = oarrss_from_arrso(&arr1, dhl);
    oarrss_t soa2 = oarrss_from_arrso(&arr2, dhl);
    arrso_t oracle_sum = arrso_empty_like(&arr1, dhl);
    arrso_t oracle_mul = arrso_empty_like(&arr1, dhl);

    arrso_sum_OO_to(&arr1, &arr2, &oracle_sum, dhl);
    arrso_mul_OO_to(&arr1, &arr2, &oracle_mul, dhl);

    {
        oarrss_t a1 = oarrss_copy(&soa1);

        oarrss_sum_OO_to(&a1, &soa2, &a1, dhl);
        compare_oarrss_vs_arrso(&a1, &oracle_sum, dhl, 0.0, "sum_OO_to aliasing res==arr1");
        oarrss_free(&a1);
    }

    {
        oarrss_t a2 = oarrss_copy(&soa2);

        oarrss_sum_OO_to(&soa1, &a2, &a2, dhl);
        compare_oarrss_vs_arrso(&a2, &oracle_sum, dhl, 0.0, "sum_OO_to aliasing res==arr2");
        oarrss_free(&a2);
    }

    {
        oarrss_t a1 = oarrss_copy(&soa1);

        oarrss_mul_OO_to(&a1, &soa2, &a1, dhl);
        compare_oarrss_vs_arrso(&a1, &oracle_mul, dhl, 1e-9, "mul_OO_to aliasing res==arr1");
        oarrss_free(&a1);
    }

    {
        oarrss_t a2 = oarrss_copy(&soa2);

        oarrss_mul_OO_to(&soa1, &a2, &a2, dhl);
        compare_oarrss_vs_arrso(&a2, &oracle_mul, dhl, 1e-9, "mul_OO_to aliasing res==arr2");
        oarrss_free(&a2);
    }

    {
        arrso_t sq_arr = build_arrso_operand(2, 2, sc->bases1, sc->k1, TRC, MAXORDER, DENSITY, 0.6,
            1.4, dhl);
        oarrss_t soa_sq = oarrss_from_arrso(&sq_arr, dhl);
        arrso_t oracle_mm = arrso_matmul_OO(&sq_arr, &sq_arr, dhl);
        oarrss_t a1 = oarrss_copy(&soa_sq);

        oarrss_matmul_OO_to(&a1, &soa_sq, &a1, dhl);
        compare_oarrss_vs_arrso(&a1, &oracle_mm, dhl, 1e-9, "matmul_OO_to aliasing res==arr1");

        oarrss_free(&a1);
        oarrss_free(&soa_sq);
        arrso_free(&oracle_mm);
        arrso_free(&sq_arr);
    }

    {
        arrso_t oracle_t = arrso_transpose(&arr1, dhl);
        oarrss_t a1 = oarrss_copy(&soa1);

        oarrss_transpose_to(&a1, &a1, dhl);
        compare_oarrss_vs_arrso(&a1, &oracle_t, dhl, 0.0, "transpose_to aliasing res==arr1");

        oarrss_free(&a1);
        arrso_free(&oracle_t);
    }

    oarrss_free(&soa1);
    oarrss_free(&soa2);
    arrso_free(&oracle_sum);
    arrso_free(&oracle_mul);
    arrso_free(&arr1);
    arrso_free(&arr2);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     OPENMP THREAD COUNT     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A large (80x80) elementwise mul and exp must give bit-identical results with 1 and with several
 * OpenMP threads: each thread only ever writes a disjoint element range of the shared output. */
static void test_openmp_threads(dhelpl_t dhl){

#ifdef _OPENMP
    int max_threads = omp_get_max_threads();
#endif
    arrso_t a = build_arrso_operand(80, 80, SET_A, 2, 3, 3, 0.5, 0.6, 1.3, dhl);
    arrso_t b = build_arrso_operand(80, 80, SET_A, 2, 3, 3, 0.5, 0.4, 0.9, dhl);
    oarrss_t soa_a = oarrss_from_arrso(&a, dhl), soa_b = oarrss_from_arrso(&b, dhl);
    oarrss_t mul_1t = oarrss_init(), mul_nt = oarrss_init();
    oarrss_t exp_1t = oarrss_init(), exp_nt = oarrss_init();

#ifdef _OPENMP
    omp_set_num_threads(1);
#endif
    oarrss_mul_OO_to(&soa_a, &soa_b, &mul_1t, dhl);
    oarrss_exp_to(&soa_a, &exp_1t, dhl);

#ifdef _OPENMP
    omp_set_num_threads((max_threads > 1) ? max_threads : 4);
#endif
    oarrss_mul_OO_to(&soa_a, &soa_b, &mul_nt, dhl);
    oarrss_exp_to(&soa_a, &exp_nt, dhl);

#ifdef _OPENMP
    omp_set_num_threads(max_threads);
#endif

    {
        size_t n = (size_t)(1 + sshelp_ndir_total(mul_1t.nbases, mul_1t.trc_order)) * mul_1t.size;

        check(mul_1t.nbases == mul_nt.nbases && mul_1t.trc_order == mul_nt.trc_order,
            "mul (1 vs N threads): same shape/set");
        check(memcmp(mul_1t.p_data, mul_nt.p_data, n * sizeof(coeff_t)) == 0,
            "mul (1 vs N threads): bit-identical result");
    }

    {
        size_t n = (size_t)(1 + sshelp_ndir_total(exp_1t.nbases, exp_1t.trc_order)) * exp_1t.size;

        check(exp_1t.nbases == exp_nt.nbases && exp_1t.trc_order == exp_nt.trc_order,
            "exp (1 vs N threads): same shape/set");
        check(memcmp(exp_1t.p_data, exp_nt.p_data, n * sizeof(coeff_t)) == 0,
            "exp (1 vs N threads): bit-identical result");
    }

    oarrss_free(&mul_1t); oarrss_free(&mul_nt);
    oarrss_free(&exp_1t); oarrss_free(&exp_nt);
    oarrss_free(&soa_a); oarrss_free(&soa_b);
    arrso_free(&a); arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     LINEAR ALGEBRA     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Only the real block of an oarrss_t (e.g. an LU factorization's real LAPACK factors) against the
 * real part of the matching arrso_t oracle element. Used where the OTI-valued imaginary blocks of
 * the two representations legitimately differ (oarrss_lu_t keeps A's own imaginary blocks
 * unpacked; arrso's packed LU transforms them into L/U form), so only the shared real
 * LAPACK-factor computation can be cross-checked directly. */
static void compare_real_block(const oarrss_t* soa, arrso_t* oracle, double tol, const char* ctx){

    uint64_t i, j;
    int ok = 1;

    for (i = 0; i < soa->nrows; i++){

        for (j = 0; j < soa->ncols; j++){

            coeff_t v1 = soa->p_data[i + j * soa->nrows];
            coeff_t v2 = oracle->p_data[j + i * oracle->ncols].re;

            if (!approx_equal(v1, v2, tol)){

                fprintf(stderr, "  mismatch %s (%llu,%llu) real block: oarrss=%.17g arrso=%.17g\n",
                    ctx, (unsigned long long)i, (unsigned long long)j, v1, v2);
                ok = 0;

            }

        }

    }

    check(ok, ctx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_ssoti_vs_soti(const ssotinum_t* a, sotinum_t* b, dhelpl_t dhl, double tol,
                                  const char* ctx){

    ord_t p;
    uint64_t n_checked = 1, n_mismatch = 0;
    char name[224];

    if (!approx_equal(a->re, b->re, tol)){
        fprintf(stderr, "  mismatch %s real: ssoti=%.17g soti=%.17g\n", ctx, a->re, b->re);
        n_mismatch++;
    }

    for (p = 1; p <= a->trc_order; p++){

        ndir_t ndir = sshelp_ndir_order(a->nbases, p);
        ndir_t idx;

        for (idx = 0; idx < ndir; idx++){

            imdir_t gidx;
            coeff_t v1, v2;

            sshelp_local_to_global(idx, p, a->p_bases, a->nbases, &gidx);
            v1 = ssoti_get_item(gidx, p, a);
            v2 = soti_get_item(gidx, p, b, dhl);
            n_checked++;

            if (!approx_equal(v1, v2, tol)){
                fprintf(stderr, "  mismatch %s order=%u idx=%llu: ssoti=%.17g soti=%.17g\n", ctx,
                    (unsigned)p, (unsigned long long)idx, v1, v2);
                n_mismatch++;
            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu directions match", ctx,
        (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_ssoti_vs_ssoti(const ssotinum_t* a, const ssotinum_t* b, double tol,
                                   const char* ctx){

    ord_t p, trc = (a->trc_order < b->trc_order) ? a->trc_order : b->trc_order;
    uint64_t n_checked = 1, n_mismatch = 0;
    char name[224];

    if (!approx_equal(a->re, b->re, tol)){
        fprintf(stderr, "  mismatch %s real: a=%.17g b=%.17g\n", ctx, a->re, b->re);
        n_mismatch++;
    }

    for (p = 1; p <= trc; p++){

        ndir_t ndir = sshelp_ndir_order(a->nbases, p);
        ndir_t idx;

        for (idx = 0; idx < ndir; idx++){

            imdir_t gidx;
            coeff_t v1, v2;

            sshelp_local_to_global(idx, p, a->p_bases, a->nbases, &gidx);
            v1 = ssoti_get_item(gidx, p, a);
            v2 = ssoti_get_item(gidx, p, b);
            n_checked++;

            if (!approx_equal(v1, v2, tol)){
                fprintf(stderr, "  mismatch %s order=%u idx=%llu: a=%.17g b=%.17g\n", ctx,
                    (unsigned)p, (unsigned long long)idx, v1, v2);
                n_mismatch++;
            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu directions match", ctx,
        (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Full round trip for one (K, b) pair: LU factor + LU solve, solve_to, inv_to, det_to, each
 * compared against the arrso_t oracle (arrso destinations pre-sized with arrso_zeros_bases since
 * the arrso _to functions do not auto-resize). Only the real block of the LU factorization is
 * compared directly (see compare_real_block); pivots and the final solved X are the real
 * correctness checks, since oarrss_lu_t and arrso's packed LU keep the imaginary blocks in
 * different (but equivalent) representations. */
static void run_linalg_case(arrso_t* K, arrso_t* b, dhelpl_t dhl, const char* ctx){

    uint64_t n = K->nrows, m = b->ncols;
    oarrss_t soa_K = oarrss_from_arrso(K, dhl);
    oarrss_t soa_b = oarrss_from_arrso(b, dhl);
    char name[256];

    check(K->nrows == K->ncols, ctx);

    // LU factor + LU solve.
    {
        int32_t* ipiv_o = (int32_t*)malloc((size_t)n * sizeof(int32_t) + 1);
        arrso_t LU_o = arrso_zeros_bases(n, n, 0, 0, dhl);
        int status_o = arrso_lu_factor_to(K, &LU_o, ipiv_o, dhl);
        oarrss_lu_t lu_s;
        int status_s = oarrss_lu_factor(&soa_K, &lu_s);

        snprintf(name, sizeof(name), "%s: lu_factor status match (%d vs %d)", ctx, status_s,
            status_o);
        check(status_o == status_s, name);

        if (status_o == 0 && status_s == 0){

            uint64_t r;
            int piv_ok = 1;

            snprintf(name, sizeof(name), "%s: lu_factor real block", ctx);
            compare_real_block(&lu_s.A, &LU_o, 1e-8, name);

            for (r = 0; r < n; r++){
                if (lu_s.p_ipiv[r] != ipiv_o[r]){
                    piv_ok = 0;
                }
            }

            snprintf(name, sizeof(name), "%s: lu_factor ipiv match", ctx);
            check(piv_ok, name);

            {
                arrso_t x_o = arrso_zeros_bases(n, m, 0, 0, dhl);
                int st_o = arrso_lu_solve_to(&LU_o, ipiv_o, b, &x_o, dhl);
                oarrss_t x_s = oarrss_init();
                int st_s = oarrss_lu_solve(&lu_s, &soa_b, &x_s, dhl);

                snprintf(name, sizeof(name), "%s: lu_solve status match", ctx);
                check(st_o == st_s, name);

                if (st_o == 0 && st_s == 0){
                    snprintf(name, sizeof(name), "%s: lu_solve x", ctx);
                    compare_oarrss_vs_arrso(&x_s, &x_o, dhl, 1e-7, name);
                }

                oarrss_free(&x_s);
                arrso_free(&x_o);
            }

        }

        oarrss_lu_free(&lu_s);
        free(ipiv_o);
        arrso_free(&LU_o);
    }

    // solve_to.
    {
        arrso_t x_o = arrso_zeros_bases(n, m, 0, 0, dhl);
        int st_o = arrso_solve_to(K, b, &x_o, dhl);
        oarrss_t x_s = oarrss_init();
        int st_s = oarrss_solve_to(&soa_K, &soa_b, &x_s, dhl);

        snprintf(name, sizeof(name), "%s: solve_to status match", ctx);
        check(st_o == st_s, name);

        if (st_o == 0 && st_s == 0){
            snprintf(name, sizeof(name), "%s: solve_to x", ctx);
            compare_oarrss_vs_arrso(&x_s, &x_o, dhl, 1e-7, name);
        }

        oarrss_free(&x_s);
        arrso_free(&x_o);
    }

    // inv_to.
    {
        arrso_t inv_o = arrso_zeros_bases(n, n, 0, 0, dhl);
        int st_o = arrso_invert_to(K, &inv_o, dhl);
        oarrss_t inv_s = oarrss_init();
        int st_s = oarrss_inv_to(&soa_K, &inv_s, dhl);

        snprintf(name, sizeof(name), "%s: inv_to status match", ctx);
        check(st_o == st_s, name);

        if (st_o == 0 && st_s == 0){
            snprintf(name, sizeof(name), "%s: inv_to result", ctx);
            compare_oarrss_vs_arrso(&inv_s, &inv_o, dhl, 1e-6, name);
        }

        oarrss_free(&inv_s);
        arrso_free(&inv_o);
    }

    // det_to.
    {
        sotinum_t det_o = soti_init();
        int st_o = arrso_det_to(K, &det_o, dhl);
        ssotinum_t det_s = ssoti_init();
        int st_s = oarrss_det_to(&soa_K, &det_s, dhl);

        snprintf(name, sizeof(name), "%s: det_to status match", ctx);
        check(st_o == st_s, name);

        if (st_o == 0 && st_s == 0){
            snprintf(name, sizeof(name), "%s: det_to result", ctx);
            compare_ssoti_vs_soti(&det_s, &det_o, dhl, 1e-6, name);
        }

        soti_free(&det_o);
        ssoti_free(&det_s);
    }

    oarrss_free(&soa_K);
    oarrss_free(&soa_b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* n in {1, 2, 5, 12}, paired with truncation orders 1..4 (k=2 both operands). */
static void test_linalg_scenarios(dhelpl_t dhl){

    static const struct { uint64_t n; ord_t trc; } CASES[] = { {1,1}, {2,2}, {5,3}, {12,4} };
    size_t c;

    for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

        arrso_t K = build_arrso_operand(CASES[c].n, CASES[c].n, SET_A, 2, CASES[c].trc,
            CASES[c].trc, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(CASES[c].n, 1, SET_D, 2, CASES[c].trc, CASES[c].trc,
            DENSITY, 0.4, 0.9, dhl);
        char ctx[64];

        snprintf(ctx, sizeof(ctx), "n=%llu,trc=%u", (unsigned long long)CASES[c].n,
            (unsigned)CASES[c].trc);
        run_linalg_case(&K, &b, dhl, ctx);

        arrso_free(&K);
        arrso_free(&b);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Active-set relations (b not contained in K, K not contained in b), multiple RHS columns, b with
 * act_order < trc, K real with imaginary b, b real with imaginary K. */
static void test_linalg_operand_relations(dhelpl_t dhl){

    {
        arrso_t K = build_arrso_operand(4, 4, SET_A, 2, 3, 3, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(4, 1, SET_E, 2, 3, 3, DENSITY, 0.4, 0.9, dhl);

        run_linalg_case(&K, &b, dhl, "b_not_in_K");
        arrso_free(&K);
        arrso_free(&b);
    }

    {
        arrso_t K = build_arrso_operand(4, 4, SET_B_SUPER, 4, 3, 3, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(4, 1, SET_A, 2, 3, 3, DENSITY, 0.4, 0.9, dhl);

        run_linalg_case(&K, &b, dhl, "K_not_in_b(K_superset)");
        arrso_free(&K);
        arrso_free(&b);
    }

    {
        arrso_t K = build_arrso_operand(5, 5, SET_A, 2, 3, 3, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(5, 3, SET_D, 2, 3, 3, DENSITY, 0.4, 0.9, dhl);

        run_linalg_case(&K, &b, dhl, "multi_rhs_cols");
        arrso_free(&K);
        arrso_free(&b);
    }

    {
        arrso_t K = build_arrso_operand(4, 4, SET_A, 2, 4, 4, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(4, 1, SET_D, 2, 4, 2, DENSITY, 0.4, 0.9, dhl);

        check(b.p_data[0].act_order < 4, "b_act_lt_trc setup: act_order below trc_order");
        run_linalg_case(&K, &b, dhl, "b_act_lt_trc");
        arrso_free(&K);
        arrso_free(&b);
    }

    {
        arrso_t K = build_arrso_operand(4, 4, NULL, 0, 3, 0, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(4, 1, SET_D, 2, 3, 3, DENSITY, 0.4, 0.9, dhl);

        run_linalg_case(&K, &b, dhl, "K_real_b_imag");
        arrso_free(&K);
        arrso_free(&b);
    }

    {
        arrso_t K = build_arrso_operand(4, 4, SET_A, 2, 3, 3, DENSITY, 0.8, 1.5, dhl);
        arrso_t b = build_arrso_operand(4, 1, NULL, 0, 3, 0, DENSITY, 0.4, 0.9, dhl);

        run_linalg_case(&K, &b, dhl, "K_imag_b_real");
        arrso_free(&K);
        arrso_free(&b);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_linalg_aliasing(dhelpl_t dhl){

    arrso_t K = build_arrso_operand(4, 4, SET_A, 2, 3, 3, DENSITY, 0.8, 1.5, dhl);
    arrso_t b = build_arrso_operand(4, 1, SET_D, 2, 3, 3, DENSITY, 0.4, 0.9, dhl);
    oarrss_t soa_K = oarrss_from_arrso(&K, dhl), soa_b = oarrss_from_arrso(&b, dhl);
    arrso_t x_oracle = arrso_zeros_bases(4, 1, 0, 0, dhl);
    arrso_t inv_oracle = arrso_zeros_bases(4, 4, 0, 0, dhl);
    int st_x = arrso_solve_to(&K, &b, &x_oracle, dhl);
    int st_inv = arrso_invert_to(&K, &inv_oracle, dhl);

    check(st_x == 0, "aliasing setup: oracle solve status 0");
    check(st_inv == 0, "aliasing setup: oracle invert status 0");

    {
        oarrss_t x = oarrss_copy(&soa_b);
        int st = oarrss_solve_to(&soa_K, &x, &x, dhl);

        check(st == 0, "solve_to aliasing res==b: status 0");
        compare_oarrss_vs_arrso(&x, &x_oracle, dhl, 1e-7, "solve_to aliasing res==b");
        oarrss_free(&x);
    }

    {
        oarrss_t x = oarrss_copy(&soa_K);
        int st = oarrss_solve_to(&x, &soa_b, &x, dhl);

        check(st == 0, "solve_to aliasing res==K: status 0");
        compare_oarrss_vs_arrso(&x, &x_oracle, dhl, 1e-7, "solve_to aliasing res==K");
        oarrss_free(&x);
    }

    {
        oarrss_t r = oarrss_copy(&soa_K);
        int st = oarrss_inv_to(&r, &r, dhl);

        check(st == 0, "inv_to aliasing res==A: status 0");
        compare_oarrss_vs_arrso(&r, &inv_oracle, dhl, 1e-6, "inv_to aliasing res==A");
        oarrss_free(&r);
    }

    oarrss_free(&soa_K);
    oarrss_free(&soa_b);
    arrso_free(&x_oracle);
    arrso_free(&inv_oracle);
    arrso_free(&K);
    arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A real part with a repeated row (row1 = 2*row0): every solver must report status > 0 (LAPACK's
 * dgetrf info), matching the arrso oracle exactly. */
static void test_linalg_singular(dhelpl_t dhl){

    bases_t bases[2] = {1, 2};
    arrso_t K = arrso_zeros_bases(2, 2, 0, 3, dhl);
    arrso_t b = arrso_zeros_bases(2, 1, 0, 3, dhl);
    uint64_t i, j;

    for (i = 0; i < 2; i++){

        for (j = 0; j < 2; j++){

            coeff_t re = (i == 0) ? (1.0 + (coeff_t)j) : (2.0 * (1.0 + (coeff_t)j));
            bases_t g[1] = { (bases_t)(1 + (i + j) % 2) };
            imdir_t gidx = sshelp_global_rank(g, 1);

            soti_set_item(re, 0, 0, &K.p_data[j + i * K.ncols], dhl);
            soti_set_item(0.2 + 0.1 * (coeff_t)(i + j), gidx, 1, &K.p_data[j + i * K.ncols], dhl);

        }

    }

    for (i = 0; i < 2; i++){
        soti_set_item(0.5 + 0.3 * (coeff_t)i, 0, 0, &b.p_data[i], dhl);
    }

    {
        oarrss_t soa_K = oarrss_from_arrso(&K, dhl);
        oarrss_t soa_b = oarrss_from_arrso(&b, dhl);

        {
            int32_t ipiv_o[2];
            arrso_t LU_o = arrso_zeros_bases(2, 2, 0, 0, dhl);
            int st_o = arrso_lu_factor_to(&K, &LU_o, ipiv_o, dhl);
            oarrss_lu_t lu_s;
            int st_s = oarrss_lu_factor(&soa_K, &lu_s);

            check(st_o > 0, "singular: oracle lu_factor status > 0");
            check(st_s > 0, "singular: oarrss lu_factor status > 0");
            check(st_o == st_s, "singular: lu_factor statuses match");

            oarrss_lu_free(&lu_s);
            arrso_free(&LU_o);
        }

        {
            arrso_t x_o = arrso_zeros_bases(2, 1, 0, 0, dhl);
            int st_o = arrso_solve_to(&K, &b, &x_o, dhl);
            oarrss_t x_s = oarrss_init();
            int st_s = oarrss_solve_to(&soa_K, &soa_b, &x_s, dhl);

            check(st_o > 0 && st_s > 0 && st_o == st_s, "singular: solve_to status match (>0)");

            arrso_free(&x_o);
            oarrss_free(&x_s);
        }

        {
            // n=2 is within _OTI_LINALG_CLOSED_FORM_MAX: arrso_invert_to uses the cofactor closed
            // form, which detects singularity via det.re == 0.0 and returns the fixed status 1
            // (not a LAPACK pivot index), while oarrss_inv_to always goes through dgetrf and
            // reports the pivot index (2 here). Both correctly signal failure (status > 0); the
            // exact status value is not expected to match between the two code paths.
            arrso_t inv_o = arrso_zeros_bases(2, 2, 0, 0, dhl);
            int st_o = arrso_invert_to(&K, &inv_o, dhl);
            oarrss_t inv_s = oarrss_init();
            int st_s = oarrss_inv_to(&soa_K, &inv_s, dhl);

            check(st_o > 0, "singular: oracle inv_to status > 0");
            check(st_s > 0, "singular: oarrss inv_to status > 0");

            arrso_free(&inv_o);
            oarrss_free(&inv_s);
        }

        {
            // arrso_det_to's n=2 closed form computes the determinant by cofactor expansion (no
            // division), so a singular real part is not a failure there: it returns status 0 with
            // a valid (near-)zero result. oarrss_det_to has no closed-form path (PLAN-semisparse's
            // "det = det(A_re) exp(...)" needs A_re invertible for every n), so it reports failure
            // via dgetrf's info. This is a real capability gap, not a bug to fix here (see report).
            sotinum_t det_o = soti_init();
            int st_o = arrso_det_to(&K, &det_o, dhl);
            ssotinum_t det_s = ssoti_init();
            int st_s = oarrss_det_to(&soa_K, &det_s, dhl);

            check(st_o == 0, "singular: oracle det_to (closed form) succeeds with a valid result");
            check(st_o != 0 || approx_equal(det_o.re, 0.0, 1e-9),
                "singular: oracle det_to result has a (near-)zero real part");
            check(st_s > 0,
                "singular: oarrss det_to reports failure (LU-only, no closed form for n<=3)");

            soti_free(&det_o);
            ssoti_free(&det_s);
        }

        oarrss_free(&soa_K);
        oarrss_free(&soa_b);
    }

    arrso_free(&K);
    arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A non-square K: every solver must report OTI_LINALG_ERR_SIZE. */
static void test_linalg_nonsquare(dhelpl_t dhl){

    // NOTE: the arrso_t oracle's own lu_factor_to/lu_solve_to/solve_to/invert_to/det_to all call
    // arrso_dimCheck_O_squareness()/arrso_dimCheck_OO_matmul() unconditionally at entry, and those
    // helpers exit() the whole process on a shape mismatch ("ERROR: Arrso array not square.")
    // instead of returning OTI_LINALG_ERR_SIZE as their own headers document. That is a
    // pre-existing arrso_t (src/c/sparse/array) discrepancy, not part of the semisparse code this
    // test targets, so it is reported (see the task report) rather than exercised here: calling it
    // in-process would abort this whole test binary. Only the oarrss_ side's documented
    // OTI_LINALG_ERR_SIZE contract is checked below.
    arrso_t K = build_arrso_operand(3, 4, SET_A, 2, 3, 3, DENSITY, 0.8, 1.5, dhl);
    arrso_t b = build_arrso_operand(3, 1, SET_D, 2, 3, 3, DENSITY, 0.4, 0.9, dhl);
    oarrss_t soa_K = oarrss_from_arrso(&K, dhl);
    oarrss_t soa_b = oarrss_from_arrso(&b, dhl);

    {
        oarrss_lu_t lu_s;
        int st_s = oarrss_lu_factor(&soa_K, &lu_s);

        check(st_s == OTI_LINALG_ERR_SIZE, "non-square: oarrss lu_factor ERR_SIZE");

        oarrss_lu_free(&lu_s);
    }

    {
        oarrss_t x_s = oarrss_init();
        int st_s = oarrss_solve_to(&soa_K, &soa_b, &x_s, dhl);

        check(st_s == OTI_LINALG_ERR_SIZE, "non-square: oarrss solve_to ERR_SIZE");

        oarrss_free(&x_s);
    }

    {
        oarrss_t inv_s = oarrss_init();
        int st_s = oarrss_inv_to(&soa_K, &inv_s, dhl);

        check(st_s == OTI_LINALG_ERR_SIZE, "non-square: oarrss inv_to ERR_SIZE");

        oarrss_free(&inv_s);
    }

    {
        ssotinum_t det_s = ssoti_init();
        int st_s = oarrss_det_to(&soa_K, &det_s, dhl);

        check(st_s == OTI_LINALG_ERR_SIZE, "non-square: oarrss det_to ERR_SIZE");

        ssoti_free(&det_s);
    }

    oarrss_free(&soa_K);
    oarrss_free(&soa_b);
    arrso_free(&K);
    arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* n=40, k=3, order=3: a larger case run through the full round trip. */
static void test_linalg_large(dhelpl_t dhl){

    bases_t bases[3] = { 1, 2, 3 };
    arrso_t K = build_arrso_operand(40, 40, bases, 3, 3, 3, DENSITY, 0.8, 1.5, dhl);
    arrso_t b = build_arrso_operand(40, 1, bases, 3, 3, 3, DENSITY, 0.4, 0.9, dhl);

    run_linalg_case(&K, &b, dhl, "n=40,k=3,order=3");

    arrso_free(&K);
    arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* det(A * B) == det(A) * det(B), k=3, order=4, using oarrss_matmul_OO_to for the product. */
static void test_det_multiplicative(dhelpl_t dhl){

    bases_t bases[3] = { 1, 2, 3 };
    arrso_t A_o = build_arrso_operand(4, 4, bases, 3, 4, 4, DENSITY, 0.7, 1.3, dhl);
    arrso_t B_o = build_arrso_operand(4, 4, bases, 3, 4, 4, DENSITY, 0.5, 1.1, dhl);
    oarrss_t A = oarrss_from_arrso(&A_o, dhl), B = oarrss_from_arrso(&B_o, dhl);
    oarrss_t C = oarrss_init();
    int st = oarrss_matmul_OO_to(&A, &B, &C, dhl);

    check(st == 0, "det multiplicative: matmul status 0");

    {
        ssotinum_t detA = ssoti_init(), detB = ssoti_init(), detC = ssoti_init();
        ssotinum_t prod = ssoti_init();
        int stA = oarrss_det_to(&A, &detA, dhl);
        int stB = oarrss_det_to(&B, &detB, dhl);
        int stC = oarrss_det_to(&C, &detC, dhl);

        check(stA == 0 && stB == 0 && stC == 0, "det multiplicative: det statuses 0");

        ssoti_mul_oo_to(&detA, &detB, &prod, dhl);
        compare_ssoti_vs_ssoti(&detC, &prod, 1e-7, "det(A*B) == det(A)*det(B)");

        ssoti_free(&detA);
        ssoti_free(&detB);
        ssoti_free(&detC);
        ssoti_free(&prod);
    }

    oarrss_free(&A);
    oarrss_free(&B);
    oarrss_free(&C);
    arrso_free(&A_o);
    arrso_free(&B_o);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);
    rng_seed(0xC0FFEE1234567890ULL);

    test_memory_and_access();
    test_conversion_roundtrip(dhl);
    test_add_bases(dhl);
    test_elementwise_OO(dhl);
    test_elementwise_mixed(dhl);
    test_functions(dhl);
    test_matmul(dhl);
    test_transpose(dhl);
    test_truncation(dhl);
    test_compact(dhl);
    test_aliasing(dhl);
    test_openmp_threads(dhl);
    test_linalg_scenarios(dhl);
    test_linalg_operand_relations(dhl);
    test_linalg_aliasing(dhl);
    test_linalg_singular(dhl);
    test_linalg_nonsquare(dhl);
    test_linalg_large(dhl);
    test_det_multiplicative(dhl);

    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse SoA test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse SoA tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
