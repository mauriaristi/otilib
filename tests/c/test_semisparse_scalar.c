/* Independent checks of the semi-sparse scalar type (include/oti/semisparse/scalar/{structures,
 * base,algebra,functions}.h, PLAN-semisparse.md step 2). The oracle is sotinum_t (the sparse
 * type): operands are built as sotinum_t, converted with ssoti_from_soti(), run through the ssoti_
 * kernel under test, converted back with ssoti_to_soti() is not needed since ssoti_get_item()
 * already reads global directions directly; every direction is compared against the same soti_
 * operation applied to the same sotinum_t inputs. Exhaustive for k <= 4 bases, trc_order <= 5,
 * over the operand-set relations named in the task (same, leading part, interleaved, disjoint,
 * empty/real), plus the listed edge cases (act_order < trc_order, mismatched trc_order, in-place
 * aliasing, cancellation, the largest base label, and the order-5/11-base rank fallback, where the
 * oracle itself cannot be built and an independent from-scratch computation is used instead). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>

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
static sotinum_t build_soti_operand(const bases_t* bases, bases_t k, ord_t trc, ord_t max_order,
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
/* A random ssotinum_t built directly through the ssoti_ API, bypassing sotinum_t entirely: used
 * where the oracle cannot represent the case (labels or base counts beyond dhelp's tables). */
static ssotinum_t build_ssoti_direct(const bases_t* bases, bases_t k, ord_t trc, double density,
                                     coeff_t re){

    ssotinum_t num = ssoti_create_empty(bases, k, trc);
    ord_t p;

    ssoti_set_item(re, 0, 0, &num);

    for (p = 1; p <= trc; p++){

        bases_t u[8];
        ndir_t ndir = sshelp_ndir_order(k, p);
        ndir_t j;

        if (ndir == 0){
            continue;
        }

        memset(u, 0, sizeof(u));

        for (j = 0; j < ndir; j++){

            if (rng_uniform() < density){

                imdir_t gidx;

                sshelp_local_to_global(j, p, bases, k, &gidx);
                ssoti_set_item(rng_range(-0.3, 0.3), gidx, p, &num);

            }

            sshelp_next_dir(u, p, k);

        }

    }

    return num;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESSES     ------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Every direction of ssoti_res (its own active set, orders 1..trc_order) against soti_get_item on
 * the oracle at the same global (idx, order). Only ssoti_res's own range is walked; results take
 * the larger truncation order of their operands, the same convention as soti. */
static void compare_ssoti_vs_soti(const ssotinum_t* ssoti_res, sotinum_t* soti_oracle,
                                  dhelpl_t dhl, double tol, const char* ctx){

    ord_t p;
    uint64_t n_checked = 1, n_mismatch = 0;
    const uint64_t max_reported = 5;
    char name[192];

    if (!approx_equal(ssoti_res->re, soti_oracle->re, tol)){
        fprintf(stderr, "  mismatch %s real part: ssoti=%.17g soti=%.17g\n", ctx, ssoti_res->re,
            soti_oracle->re);
        n_mismatch++;
    }

    for (p = 1; p <= ssoti_res->trc_order; p++){

        ndir_t ndir = sshelp_ndir_order(ssoti_res->nbases, p);
        ndir_t idx;

        for (idx = 0; idx < ndir; idx++){

            imdir_t gidx;
            coeff_t v1, v2;

            sshelp_local_to_global(idx, p, ssoti_res->p_bases, ssoti_res->nbases, &gidx);
            v1 = ssoti_get_item(gidx, p, ssoti_res);
            v2 = soti_get_item(gidx, p, soti_oracle, dhl);
            n_checked++;

            if (!approx_equal(v1, v2, tol)){

                if (n_mismatch < max_reported){
                    fprintf(stderr,
                        "  mismatch %s order=%u idx=%llu global=%llu: ssoti=%.17g soti=%.17g\n",
                        ctx, (unsigned)p, (unsigned long long)idx, (unsigned long long)gidx, v1,
                        v2);
                }
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
/* Same idea as compare_ssoti_vs_soti, but both sides are ssotinum_t: enumerates `a`'s own active
 * set and compares ssoti_get_item on both `a` and `b` at the same global (idx, order). Works across
 * differing internal layouts (ssoti_get_item takes global directions), so `b` may have a smaller
 * or larger active set than `a`. */
static void compare_ssoti_vs_ssoti(const ssotinum_t* a, const ssotinum_t* b, double tol,
                                   const char* ctx){

    ord_t p, trc = (a->trc_order < b->trc_order) ? a->trc_order : b->trc_order;
    uint64_t n_checked = 1, n_mismatch = 0;
    const uint64_t max_reported = 5;
    char name[192];

    if (!approx_equal(a->re, b->re, tol)){
        fprintf(stderr, "  mismatch %s real part: a=%.17g b=%.17g\n", ctx, a->re, b->re);
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

                if (n_mismatch < max_reported){
                    fprintf(stderr,
                        "  mismatch %s order=%u idx=%llu global=%llu: a=%.17g b=%.17g\n", ctx,
                        (unsigned)p, (unsigned long long)idx, (unsigned long long)gidx, v1, v2);
                }
                n_mismatch++;

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu directions match", ctx,
        (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------------     SCENARIOS AND OPERANDS     -----------------------------------
// -------------------------------------------------------------------------------------------------------

static const bases_t SET_A[2]       = {1, 2};
static const bases_t SET_B_SUPER[4] = {1, 2, 3, 4};
static const bases_t SET_C[2]       = {1, 3};
static const bases_t SET_D[2]       = {2, 4};
static const bases_t SET_E[2]       = {3, 4};

typedef struct {
    const bases_t* bases1; bases_t k1; ord_t trc1; ord_t maxorder1; coeff_t re1;
    const bases_t* bases2; bases_t k2; ord_t trc2; ord_t maxorder2; coeff_t re2;
    const char* label;
} scenario_t;

static const scenario_t SCENARIOS[] = {
    { SET_A,       2, 5, 5, 1.3,  SET_A,       2, 5, 5, 0.8, "same" },
    { SET_A,       2, 5, 5, 1.3,  SET_B_SUPER, 4, 5, 5, 0.8, "leading" },
    { SET_C,       2, 5, 5, 1.3,  SET_D,       2, 5, 5, 0.8, "interleaved" },
    { SET_A,       2, 5, 5, 1.3,  SET_E,       2, 5, 5, 0.8, "disjoint" },
    { NULL,        0, 5, 0, 1.3,  SET_B_SUPER, 4, 5, 5, 0.8, "empty_op1" },
    { NULL,        0, 5, 0, 1.3,  NULL,        0, 5, 0, 0.8, "both_real" },
    { SET_A,       2, 3, 3, 1.3,  SET_A,       2, 5, 5, 0.8, "diff_trc" },
    { SET_B_SUPER, 4, 5, 2, 1.3,  SET_B_SUPER, 4, 5, 5, 0.8, "act_lt_trc" },
};

#define N_SCENARIOS (sizeof(SCENARIOS) / sizeof(SCENARIOS[0]))

typedef void (*soti_oo_to_fn)(sotinum_t*, sotinum_t*, sotinum_t*, dhelpl_t);
typedef void (*ssoti_oo_to_fn)(const ssotinum_t*, const ssotinum_t*, ssotinum_t*, dhelpl_t);

typedef struct { const char* name; soti_oo_to_fn soti_fn; ssoti_oo_to_fn ssoti_fn; double tol; }
    oo_op_t;

static const oo_op_t OO_OPS[] = {
    { "sum_oo", soti_sum_oo_to, ssoti_sum_oo_to, 0.0 },
    { "sub_oo", soti_sub_oo_to, ssoti_sub_oo_to, 0.0 },
    { "mul_oo", soti_mul_oo_to, ssoti_mul_oo_to, 1e-9 },
    { "div_oo", soti_div_oo_to, ssoti_div_oo_to, 1e-9 },
};

#define N_OO_OPS (sizeof(OO_OPS) / sizeof(OO_OPS[0]))


// -------------------------------------------------------------------------------------------------------
// ------------------------------------     BINARY OPS AND GEM     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* sum/sub/mul/div (oo) over every operand-set-relation scenario: same, leading part, interleaved,
 * disjoint, one/both real, mismatched trc_order, act_order < trc_order. */
static void test_binary_ops(dhelpl_t dhl){

    size_t s, o;

    for (s = 0; s < N_SCENARIOS; s++){

        const scenario_t* sc = &SCENARIOS[s];
        sotinum_t soti1 = build_soti_operand(sc->bases1, sc->k1, sc->trc1, sc->maxorder1, 0.6,
            sc->re1, dhl);
        sotinum_t soti2 = build_soti_operand(sc->bases2, sc->k2, sc->trc2, sc->maxorder2, 0.6,
            sc->re2, dhl);
        ssotinum_t ssoti1 = ssoti_from_soti(&soti1, dhl);
        ssotinum_t ssoti2 = ssoti_from_soti(&soti2, dhl);

        for (o = 0; o < N_OO_OPS; o++){

            sotinum_t soti_res = soti_init();
            ssotinum_t ssoti_res = ssoti_init();
            char ctx[96];

            OO_OPS[o].soti_fn(&soti1, &soti2, &soti_res, dhl);
            OO_OPS[o].ssoti_fn(&ssoti1, &ssoti2, &ssoti_res, dhl);

            snprintf(ctx, sizeof(ctx), "%s(%s)", OO_OPS[o].name, sc->label);
            compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, OO_OPS[o].tol, ctx);

            soti_free(&soti_res);
            ssoti_free(&ssoti_res);

        }

        ssoti_free(&ssoti1);
        ssoti_free(&ssoti2);
        soti_free(&soti1);
        soti_free(&soti2);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Fused multiply-add res = num1*num2 + num3, oracle-compared across three scenarios. */
static void test_gem(dhelpl_t dhl){

    size_t s;

    for (s = 0; s < 3; s++){

        const scenario_t* sc = &SCENARIOS[s];
        sotinum_t soti1 = build_soti_operand(sc->bases1, sc->k1, sc->trc1, sc->maxorder1, 0.6,
            sc->re1, dhl);
        sotinum_t soti2 = build_soti_operand(sc->bases2, sc->k2, sc->trc2, sc->maxorder2, 0.6,
            sc->re2, dhl);
        sotinum_t soti3 = build_soti_operand(sc->bases1, sc->k1, sc->trc1, sc->maxorder1, 0.6, 0.4,
            dhl);
        ssotinum_t ssoti1 = ssoti_from_soti(&soti1, dhl);
        ssotinum_t ssoti2 = ssoti_from_soti(&soti2, dhl);
        ssotinum_t ssoti3 = ssoti_from_soti(&soti3, dhl);
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();
        char ctx[64];

        soti_gem_oo_to(&soti1, &soti2, &soti3, &soti_res, dhl);
        ssoti_gem_oo_to(&ssoti1, &ssoti2, &ssoti3, &ssoti_res, dhl);

        snprintf(ctx, sizeof(ctx), "gem_oo(%s)", sc->label);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, ctx);

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
        ssoti_free(&ssoti1);
        ssoti_free(&ssoti2);
        ssoti_free(&ssoti3);
        soti_free(&soti1);
        soti_free(&soti2);
        soti_free(&soti3);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Real-number variants: sum_or, sub_or, sub_ro, mul_or, div_or, div_ro, neg. */
static void test_real_variants(dhelpl_t dhl){

    const scenario_t* sc = &SCENARIOS[1];
    sotinum_t soti1 = build_soti_operand(sc->bases1, sc->k1, sc->trc1, sc->maxorder1, 0.6, sc->re1,
        dhl);
    ssotinum_t ssoti1 = ssoti_from_soti(&soti1, dhl);
    coeff_t val = 0.65;

    {
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();

        soti_sum_or_to(&soti1, val, &soti_res, dhl);
        ssoti_sum_or_to(&ssoti1, val, &ssoti_res, dhl);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, "sum_or");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();

        soti_sub_or_to(&soti1, val, &soti_res, dhl);
        ssoti_sub_or_to(&ssoti1, val, &ssoti_res, dhl);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, "sub_or");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();

        soti_sub_ro_to(val, &soti1, &soti_res, dhl);
        ssoti_sub_ro_to(val, &ssoti1, &ssoti_res, dhl);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, "sub_ro");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();

        soti_mul_or_to(&soti1, val, &soti_res, dhl);
        ssoti_mul_or_to(&ssoti1, val, &ssoti_res, dhl);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, "mul_or");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();

        soti_div_or_to(&soti1, val, &soti_res, dhl);
        ssoti_div_or_to(&ssoti1, val, &ssoti_res, dhl);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, "div_or");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        sotinum_t soti_res = soti_init();
        ssotinum_t ssoti_res = ssoti_init();

        soti_div_ro_to(val, &soti1, &soti_res, dhl);
        ssoti_div_ro_to(val, &ssoti1, &ssoti_res, dhl);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, "div_ro");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        sotinum_t soti_res = soti_neg(&soti1, dhl);
        ssotinum_t ssoti_res = ssoti_neg(&ssoti1, dhl);

        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, "neg");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    ssoti_free(&ssoti1);
    soti_free(&soti1);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ELEMENTARY FUNCTIONS     ------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef sotinum_t (*soti_un_fn)(sotinum_t*, dhelpl_t);
typedef ssotinum_t (*ssoti_un_fn)(const ssotinum_t*, dhelpl_t);

typedef struct { const char* name; coeff_t re; soti_un_fn soti_fn; ssoti_un_fn ssoti_fn; }
    unary_case_t;

static const unary_case_t UNARY_FUNCS[] = {
    { "exp",   1.3, soti_exp,   ssoti_exp },
    { "log",   1.3, soti_log,   ssoti_log },
    { "log10", 1.3, soti_log10, ssoti_log10 },
    { "sqrt",  1.3, soti_sqrt,  ssoti_sqrt },
    { "cbrt",  1.3, soti_cbrt,  ssoti_cbrt },
    { "sin",   0.6, soti_sin,   ssoti_sin },
    { "cos",   0.6, soti_cos,   ssoti_cos },
    { "tan",   0.4, soti_tan,   ssoti_tan },
    { "asin",  0.4, soti_asin,  ssoti_asin },
    { "acos",  0.4, soti_acos,  ssoti_acos },
    { "atan",  0.6, soti_atan,  ssoti_atan },
    { "sinh",  0.6, soti_sinh,  ssoti_sinh },
    { "cosh",  0.6, soti_cosh,  ssoti_cosh },
    { "tanh",  0.6, soti_tanh,  ssoti_tanh },
    { "asinh", 0.6, soti_asinh, ssoti_asinh },
    { "acosh", 1.6, soti_acosh, ssoti_acosh },
    { "atanh", 0.4, soti_atanh, ssoti_atanh },
    { "erf",   0.6, soti_erf,   ssoti_erf },
};

#define N_UNARY_FUNCS (sizeof(UNARY_FUNCS) / sizeof(UNARY_FUNCS[0]))


// *******************************************************************************************************
/* All 18 feval-based functions, over two active-set configurations, plus pow (non-integer and
 * negative exponent) and logb. */
static void test_functions(dhelpl_t dhl){

    int cfg;
    size_t f;

    for (cfg = 0; cfg < 2; cfg++){

        const bases_t* bases = (cfg == 0) ? SET_A : SET_B_SUPER;
        bases_t k = (cfg == 0) ? 2 : 4;

        for (f = 0; f < N_UNARY_FUNCS; f++){

            sotinum_t soti = build_soti_operand(bases, k, 5, 5, 0.5, UNARY_FUNCS[f].re, dhl);
            ssotinum_t ssoti_in = ssoti_from_soti(&soti, dhl);
            sotinum_t soti_res = UNARY_FUNCS[f].soti_fn(&soti, dhl);
            ssotinum_t ssoti_res = UNARY_FUNCS[f].ssoti_fn(&ssoti_in, dhl);
            char ctx[96];

            snprintf(ctx, sizeof(ctx), "%s(%s)", UNARY_FUNCS[f].name, (cfg == 0) ? "A" : "B_SUPER");
            compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, ctx);

            soti_free(&soti);
            soti_free(&soti_res);
            ssoti_free(&ssoti_in);
            ssoti_free(&ssoti_res);

        }

    }

    {
        double exps[2] = {2.5, -1.0};
        int e;

        for (e = 0; e < 2; e++){

            sotinum_t soti = build_soti_operand(SET_A, 2, 5, 5, 0.5, 1.3, dhl);
            ssotinum_t ssoti_in = ssoti_from_soti(&soti, dhl);
            sotinum_t soti_res = soti_pow(&soti, exps[e], dhl);
            ssotinum_t ssoti_res = ssoti_pow(&ssoti_in, exps[e], dhl);
            char ctx[64];

            snprintf(ctx, sizeof(ctx), "pow(e=%.1f)", exps[e]);
            compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, ctx);

            soti_free(&soti);
            soti_free(&soti_res);
            ssoti_free(&ssoti_in);
            ssoti_free(&ssoti_res);

        }

    }

    {
        sotinum_t soti = build_soti_operand(SET_A, 2, 5, 5, 0.5, 1.3, dhl);
        ssotinum_t ssoti_in = ssoti_from_soti(&soti, dhl);
        sotinum_t soti_res = soti_logb(&soti, 3.0, dhl);
        ssotinum_t ssoti_res = ssoti_logb(&ssoti_in, 3.0, dhl);

        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 1e-9, "logb(base=3)");

        soti_free(&soti);
        soti_free(&soti_res);
        ssoti_free(&ssoti_in);
        ssoti_free(&ssoti_res);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     TRUNCATION AND EXTRACTION     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_truncate_and_extract(dhelpl_t dhl){

    sotinum_t soti = build_soti_operand(SET_B_SUPER, 4, 5, 5, 0.6, 1.3, dhl);
    ssotinum_t ssoti_num = ssoti_from_soti(&soti, dhl);
    ord_t order;

    for (order = 0; order <= 5; order++){

        sotinum_t soti_res = soti_truncate_order(order, &soti, dhl);
        ssotinum_t ssoti_res = ssoti_truncate_order(order, &ssoti_num);
        char ctx[64];

        snprintf(ctx, sizeof(ctx), "truncate_order(%u)", (unsigned)order);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, ctx);

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);

    }

    for (order = 0; order <= 5; order++){

        sotinum_t soti_res = soti_get_order_im(order, &soti, dhl);
        ssotinum_t ssoti_res = ssoti_get_order_im(order, &ssoti_num);
        char ctx[64];

        snprintf(ctx, sizeof(ctx), "get_order_im(%u)", (unsigned)order);
        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, ctx);

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);

    }

    {
        bases_t g2[2] = {2, 3};
        imdir_t idx2 = sshelp_global_rank(g2, 2);
        sotinum_t soti_res = soti_truncate_im(idx2, 2, &soti, dhl);
        ssotinum_t ssoti_res = ssoti_truncate_im(idx2, 2, &ssoti_num);

        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0, "truncate_im(order2 dir (2,3))");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    {
        bases_t g4[4] = {1, 2, 3, 4};
        imdir_t idx4 = sshelp_global_rank(g4, 4);
        sotinum_t soti_res = soti_truncate_im(idx4, 4, &soti, dhl);
        ssotinum_t ssoti_res = ssoti_truncate_im(idx4, 4, &ssoti_num);

        compare_ssoti_vs_soti(&ssoti_res, &soti_res, dhl, 0.0,
            "truncate_im(order4 dir (1,2,3,4))");

        soti_free(&soti_res);
        ssoti_free(&ssoti_res);
    }

    ssoti_free(&ssoti_num);
    soti_free(&soti);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Compaction: value unchanged (checked directly through ssoti_get_item on before vs after, which
 * is layout-independent), the all-zero base removed, act_order lowered. */
static void test_compact(void){

    bases_t bases[3] = {1, 2, 3};
    bases_t expected_bases[2] = {1, 3};
    ssotinum_t num = ssoti_create_empty(bases, 3, 4);
    ssotinum_t before, after;

    ssoti_set_item(1.5, 0, 1, &num);
    ssoti_set_item(0.0, 1, 1, &num);
    ssoti_set_item(2.0, 2, 1, &num);

    {
        bases_t g[2] = {2, 2};
        imdir_t gidx = sshelp_global_rank(g, 2);

        ssoti_set_item(0.0, gidx, 2, &num);
    }

    {
        bases_t g[2] = {1, 3};
        imdir_t gidx = sshelp_global_rank(g, 2);

        ssoti_set_item(0.7, gidx, 2, &num);
    }

    before = ssoti_copy(&num);
    after = ssoti_compact(&num);

    check(after.nbases == 2, "compact: drops the all-zero base");
    check(memcmp(after.p_bases, expected_bases, sizeof(expected_bases)) == 0,
        "compact: kept bases are {1,3}");
    check(after.act_order <= before.act_order, "compact: does not raise act_order");

    compare_ssoti_vs_ssoti(&before, &after, 0.0, "compact: value unchanged");

    ssoti_free(&before);
    ssoti_free(&after);
    ssoti_free(&num);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ACCESS AND DERIVATIVES     ----------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static double factorial_int(int n){

    double f = 1.0;

    while (n > 1){
        f *= n;
        n--;
    }

    return f;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Independent reference for ssoti_get_deriv: the coefficient times the product of the factorials
 * of the repeated-base run lengths in the direction's tuple (from sshelp_global_unrank). */
static double reference_deriv_factor(imdir_t idx, ord_t order){

    bases_t g[8];
    double factor = 1.0;
    ord_t i = 0;

    sshelp_global_unrank(idx, order, g);

    while (i < order){

        ord_t run = 1;

        while ((ord_t)(i + run) < order && g[i + run] == g[i]){
            run++;
        }

        factor *= factorial_int(run);
        i = (ord_t)(i + run);

    }

    return factor;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_get_set_deriv(dhelpl_t dhl){

    bases_t bases[3] = {1, 2, 4};
    sotinum_t soti = build_soti_operand(bases, 3, 4, 4, 0.7, 1.2, dhl);
    ssotinum_t num = ssoti_from_soti(&soti, dhl);
    ord_t order;

    for (order = 1; order <= 4; order++){

        ndir_t ndir = sshelp_ndir_order(num.nbases, order);
        ndir_t idx;

        for (idx = 0; idx < ndir; idx++){

            imdir_t gidx;
            coeff_t item, deriv, expected;
            char name[112];

            sshelp_local_to_global(idx, order, num.p_bases, num.nbases, &gidx);
            item = ssoti_get_item(gidx, order, &num);
            deriv = ssoti_get_deriv(gidx, order, &num);
            expected = item * reference_deriv_factor(gidx, order);

            snprintf(name, sizeof(name),
                "get_deriv(order=%u,idx=%llu) vs item * multiplicity factorials", (unsigned)order,
                (unsigned long long)idx);
            check(fabs(deriv - expected) <= 1e-9 * fmax(1.0, fabs(expected)), name);

        }

    }

    {
        bases_t new_base[1] = {3};
        imdir_t gidx = sshelp_global_rank(new_base, 1);

        check(num.nbases == 3, "set_item setup: base 3 not yet active");
        ssoti_set_item(4.4, gidx, 1, &num);
        check(num.nbases == 4, "set_item: adds a missing base");
        check(ssoti_get_item(gidx, 1, &num) == 4.4, "set_item: value readable back");
    }

    {
        bases_t new_base[1] = {6};
        imdir_t gidx = sshelp_global_rank(new_base, 1);
        bases_t nbases_before = num.nbases;

        ssoti_set_item(0.0, gidx, 1, &num);
        check(num.nbases == nbases_before, "set_item(0) on a missing base does not add it");
    }

    ssoti_free(&num);
    soti_free(&soti);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ADD_BASES     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Adding bases keeps the value: every direction of the enlarged set matches ssoti_get_item on the
 * original number (0 for any direction using a newly added base, per its own contract). */
static void test_add_bases(dhelpl_t dhl){

    {
        bases_t bases0[2] = {1, 2};
        bases_t add[2] = {3, 4};
        sotinum_t soti = build_soti_operand(bases0, 2, 4, 4, 0.6, 1.1, dhl);
        ssotinum_t before = ssoti_from_soti(&soti, dhl);
        ssotinum_t after = ssoti_copy(&before);

        ssoti_add_bases(add, 2, &after);

        check(after.nbases == 4, "add_bases (leading): new nbases");
        check(after.p_bases[0] == 1 && after.p_bases[1] == 2 && after.p_bases[2] == 3
            && after.p_bases[3] == 4, "add_bases (leading): new active set");
        compare_ssoti_vs_ssoti(&after, &before, 0.0, "add_bases(leading) value preserved");

        ssoti_free(&before);
        ssoti_free(&after);
        soti_free(&soti);
    }

    {
        bases_t bases0[2] = {1, 4};
        bases_t add[2] = {2, 3};
        sotinum_t soti = build_soti_operand(bases0, 2, 4, 4, 0.6, 1.1, dhl);
        ssotinum_t before = ssoti_from_soti(&soti, dhl);
        ssotinum_t after = ssoti_copy(&before);

        ssoti_add_bases(add, 2, &after);

        check(after.nbases == 4, "add_bases (interleaved): new nbases");
        check(after.p_bases[0] == 1 && after.p_bases[1] == 2 && after.p_bases[2] == 3
            && after.p_bases[3] == 4, "add_bases (interleaved): new active set");
        compare_ssoti_vs_ssoti(&after, &before, 0.0, "add_bases(interleaved) value preserved");

        ssoti_free(&before);
        ssoti_free(&after);
        soti_free(&soti);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ALIASING     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* res == num1, res == num2 (sum_oo_to, mul_oo_to), and gem with res == num3 / res == num1: the
 * aliased call must produce the same content as a fresh, non-aliased baseline. */
static void test_aliasing(dhelpl_t dhl){

    const scenario_t* sc = &SCENARIOS[1];
    sotinum_t soti1 = build_soti_operand(sc->bases1, sc->k1, sc->trc1, sc->maxorder1, 0.6, sc->re1,
        dhl);
    sotinum_t soti2 = build_soti_operand(sc->bases2, sc->k2, sc->trc2, sc->maxorder2, 0.6, sc->re2,
        dhl);
    sotinum_t soti3 = build_soti_operand(sc->bases1, sc->k1, sc->trc1, sc->maxorder1, 0.6, 0.5,
        dhl);
    ssotinum_t ssoti1 = ssoti_from_soti(&soti1, dhl);
    ssotinum_t ssoti2 = ssoti_from_soti(&soti2, dhl);
    ssotinum_t ssoti3 = ssoti_from_soti(&soti3, dhl);
    ssotinum_t baseline, a1, a2;

    baseline = ssoti_init();
    ssoti_sum_oo_to(&ssoti1, &ssoti2, &baseline, dhl);

    a1 = ssoti_copy(&ssoti1);
    ssoti_sum_oo_to(&a1, &ssoti2, &a1, dhl);
    compare_ssoti_vs_ssoti(&baseline, &a1, 0.0, "sum_oo_to aliasing res==num1");
    ssoti_free(&a1);

    a2 = ssoti_copy(&ssoti2);
    ssoti_sum_oo_to(&ssoti1, &a2, &a2, dhl);
    compare_ssoti_vs_ssoti(&baseline, &a2, 0.0, "sum_oo_to aliasing res==num2");
    ssoti_free(&a2);
    ssoti_free(&baseline);

    baseline = ssoti_init();
    ssoti_mul_oo_to(&ssoti1, &ssoti2, &baseline, dhl);

    a1 = ssoti_copy(&ssoti1);
    ssoti_mul_oo_to(&a1, &ssoti2, &a1, dhl);
    compare_ssoti_vs_ssoti(&baseline, &a1, 1e-9, "mul_oo_to aliasing res==num1");
    ssoti_free(&a1);

    a2 = ssoti_copy(&ssoti2);
    ssoti_mul_oo_to(&ssoti1, &a2, &a2, dhl);
    compare_ssoti_vs_ssoti(&baseline, &a2, 1e-9, "mul_oo_to aliasing res==num2");
    ssoti_free(&a2);
    ssoti_free(&baseline);

    baseline = ssoti_init();
    ssoti_gem_oo_to(&ssoti1, &ssoti2, &ssoti3, &baseline, dhl);

    a1 = ssoti_copy(&ssoti3);
    ssoti_gem_oo_to(&ssoti1, &ssoti2, &a1, &a1, dhl);
    compare_ssoti_vs_ssoti(&baseline, &a1, 1e-9, "gem_oo_to aliasing res==num3");
    ssoti_free(&a1);

    a1 = ssoti_copy(&ssoti1);
    ssoti_gem_oo_to(&a1, &ssoti2, &ssoti3, &a1, dhl);
    compare_ssoti_vs_ssoti(&baseline, &a1, 1e-9, "gem_oo_to aliasing res==num1");
    ssoti_free(&a1);
    ssoti_free(&baseline);

    ssoti_free(&ssoti1);
    ssoti_free(&ssoti2);
    ssoti_free(&ssoti3);
    soti_free(&soti1);
    soti_free(&soti2);
    soti_free(&soti3);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     CANCELLATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* x - x: every coefficient zero, but the active set is kept (per PLAN-semisparse.md Section 3);
 * compacting it afterwards removes every base. */
static void test_cancellation(dhelpl_t dhl){

    bases_t bases0[3] = {1, 2, 4};
    sotinum_t soti = build_soti_operand(bases0, 3, 4, 4, 0.7, 1.3, dhl);
    ssotinum_t x = ssoti_from_soti(&soti, dhl);
    ssotinum_t y = ssoti_init();
    ssotinum_t compacted;
    ord_t p;
    int all_zero = 1;

    ssoti_sub_oo_to(&x, &x, &y, dhl);

    check(y.nbases == x.nbases
        && memcmp(y.p_bases, x.p_bases, (size_t)x.nbases * sizeof(bases_t)) == 0,
        "cancellation: x - x keeps the active set");
    check(y.re == 0.0, "cancellation: x - x has zero real part");

    for (p = 1; p <= y.trc_order && all_zero; p++){

        ndir_t ndir = sshelp_ndir_order(y.nbases, p);
        ndir_t idx;

        for (idx = 0; idx < ndir; idx++){

            imdir_t gidx;

            sshelp_local_to_global(idx, p, y.p_bases, y.nbases, &gidx);

            if (ssoti_get_item(gidx, p, &y) != 0.0){
                all_zero = 0;
                break;
            }

        }

    }

    check(all_zero, "cancellation: x - x is zero in every imaginary direction");

    compacted = ssoti_compact(&y);
    check(compacted.nbases == 0, "cancellation: compact(x - x) removes every base");
    check(compacted.re == 0.0, "cancellation: compact(x - x) keeps zero real part");

    ssoti_free(&compacted);
    ssoti_free(&y);
    ssoti_free(&x);
    soti_free(&soti);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     LARGEST LABEL (65535)     -----------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* bases {1, 65535}: the sotinum_t oracle cannot represent this (dhelp's own tables stop at
 * Nbasis(order) bases, e.g. 65000 at order 1), so it is built directly through the ssoti_ API and
 * checked with direct get_item calls and a hand-derived reference for a couple of mul_oo terms. */
static void test_large_label(dhelpl_t dhl){

    bases_t bases[2] = {1, 65535};
    ssotinum_t num = ssoti_create_empty(bases, 2, 4);
    ssotinum_t sq;
    imdir_t g_base2, g_pair;
    coeff_t v1 = 1.7, v2 = -0.9;

    g_base2 = sshelp_global_rank(&bases[1], 1);

    ssoti_set_item(2.5, 0, 1, &num);
    ssoti_set_item(v1, g_base2, 1, &num);

    check(ssoti_get_item(0, 1, &num) == 2.5, "large label: get_item base1 order1");
    check(ssoti_get_item(g_base2, 1, &num) == v1, "large label: get_item base65535 order1");
    check(ssoti_get_item((imdir_t)999999, 1, &num) == 0.0,
        "large label: get_item of an unset direction is 0");

    {
        bases_t pair_tuple[2] = {65535, 65535};

        g_pair = sshelp_global_rank(pair_tuple, 2);
    }
    ssoti_set_item(v2, g_pair, 2, &num);

    check(ssoti_get_item(g_pair, 2, &num) == v2, "large label: get_item (65535,65535) order2");

    sq = ssoti_mul_oo(&num, &num, dhl);

    {
        bases_t quad[4] = {65535, 65535, 65535, 65535};
        imdir_t g_quad = sshelp_global_rank(quad, 4);
        coeff_t got = ssoti_get_item(g_quad, 4, &sq);
        // Only the p=2,q=2 split is nonzero (num has no order-3 data), and unlike a p=1,q=1
        // cross term between two distinct bases, p==q here is a single split, not doubled.
        coeff_t expected = v2 * v2;

        check(fabs(got - expected) <= 1e-9 * fmax(1.0, fabs(expected)),
            "large label: mul_oo order4 (65535 x4) matches hand-derived reference");
    }

    {
        bases_t cross[2] = {1, 65535};
        imdir_t g_cross = sshelp_global_rank(cross, 2);
        coeff_t got = ssoti_get_item(g_cross, 2, &sq);
        coeff_t expected = 2.0 * 2.5 * v1;

        check(fabs(got - expected) <= 1e-9 * fmax(1.0, fabs(expected)),
            "large label: mul_oo order2 (1,65535) matches hand-derived reference");
    }

    ssoti_free(&sq);
    ssoti_free(&num);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     RANK FALLBACK (k=11, order 5)     ---------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Same-active-set dense product built from scratch with sshelp_unrank + a manual merge of the
 * global base labels + sshelp_global_rank, independent of both ssoti_mul_oo and sshelp_prod_rank.
 * Used only where the sotinum_t oracle cannot represent the case either (k beyond Nbasis(order)). */
static ssotinum_t naive_mul_same_set(const ssotinum_t* a, const ssotinum_t* b, ord_t trc){

    ssotinum_t out = ssoti_create_empty(a->p_bases, a->nbases, trc);
    ord_t p, q;

    ssoti_set_item(a->re * b->re, 0, 0, &out);

    for (p = 1; p <= trc && p <= a->trc_order; p++){

        ndir_t np = sshelp_ndir_order(a->nbases, p);
        ndir_t i;

        for (i = 0; i < np; i++){

            imdir_t gi;
            coeff_t ai;

            sshelp_local_to_global(i, p, a->p_bases, a->nbases, &gi);
            ai = ssoti_get_item(gi, p, a);

            if (ai != 0.0){
                ssoti_set_item(ssoti_get_item(gi, p, &out) + ai * b->re, gi, p, &out);
            }

        }

    }

    for (q = 1; q <= trc && q <= b->trc_order; q++){

        ndir_t nq = sshelp_ndir_order(b->nbases, q);
        ndir_t j;

        for (j = 0; j < nq; j++){

            imdir_t gj;
            coeff_t bj;

            sshelp_local_to_global(j, q, b->p_bases, b->nbases, &gj);
            bj = ssoti_get_item(gj, q, b);

            if (bj != 0.0){
                ssoti_set_item(ssoti_get_item(gj, q, &out) + a->re * bj, gj, q, &out);
            }

        }

    }

    for (p = 1; p <= trc && p <= a->trc_order; p++){

        ndir_t np = sshelp_ndir_order(a->nbases, p);
        ndir_t i;

        for (i = 0; i < np; i++){

            bases_t ui[8];
            imdir_t gi;
            coeff_t ai;
            ord_t q;

            sshelp_unrank(i, p, ui);
            sshelp_local_to_global(i, p, a->p_bases, a->nbases, &gi);
            ai = ssoti_get_item(gi, p, a);

            if (ai == 0.0){
                continue;
            }

            for (q = 1; p + q <= trc && q <= b->trc_order; q++){

                ndir_t nq = sshelp_ndir_order(b->nbases, q);
                ndir_t j;

                for (j = 0; j < nq; j++){

                    bases_t uj[8], merged[16];
                    imdir_t gj, g_out;
                    coeff_t bj, v;
                    ord_t ia = 0, ib = 0, m;

                    sshelp_unrank(j, q, uj);
                    sshelp_local_to_global(j, q, b->p_bases, b->nbases, &gj);
                    bj = ssoti_get_item(gj, q, b);

                    if (bj == 0.0){
                        continue;
                    }

                    for (m = 0; ia < p || ib < q; m++){

                        bases_t la = (ia < p) ? a->p_bases[ui[ia]] : 0;
                        bases_t lb = (ib < q) ? b->p_bases[uj[ib]] : 0;

                        if (ib == q || (ia < p && la <= lb)){
                            merged[m] = la;
                            ia++;
                        } else {
                            merged[m] = lb;
                            ib++;
                        }

                    }

                    g_out = sshelp_global_rank(merged, (ord_t)(p + q));
                    v = ssoti_get_item(g_out, (ord_t)(p + q), &out) + ai * bj;
                    ssoti_set_item(v, g_out, (ord_t)(p + q), &out);

                }

            }

        }

    }

    return out;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* ssoti_e against soti_createReal + soti_set_item (what pyoti.sparse.e does): every direction of
 * orders 1..4 over labels 1..5, at requested truncation orders below, equal to and above the
 * direction's order. Also the order-0 unit and the largest label. */
static void test_e(dhelpl_t dhl){

    static const ord_t trcs[] = {0, 2, 5};
    bases_t g[8], expect[8], nexp;
    ord_t p, t, i, trc;
    ndir_t idx;
    char name[160];
    int ok_sets = 1, ok_orders = 1;

    for (p = 1; p <= 4; p++){

        for (idx = 0; idx < sshelp_ndir_order(5, p); idx++){

            sshelp_global_unrank(idx, p, g);

            for (nexp = 0, i = 0; i < p; i++){

                if (nexp == 0 || expect[nexp - 1] != g[i]){
                    expect[nexp++] = g[i];
                }

            }

            for (t = 0; t < sizeof(trcs) / sizeof(trcs[0]); t++){

                ssotinum_t x = ssoti_e(idx, p, trcs[t]);
                sotinum_t ref;

                trc = (trcs[t] > p) ? trcs[t] : p;
                ref = soti_createReal(0.0, trc, dhl);
                soti_set_item(1.0, idx, p, &ref, dhl);

                ok_orders &= (x.trc_order == trc) && (x.act_order == p) && (x.re == 0.0);
                ok_sets   &= (x.nbases == nexp);

                for (i = 0; i < nexp && i < x.nbases; i++){
                    ok_sets &= (x.p_bases[i] == expect[i]);
                }

                snprintf(name, sizeof(name), "e(idx=%llu, order=%u, trc=%u) vs soti",
                    (unsigned long long)idx, (unsigned)p, (unsigned)trcs[t]);
                compare_ssoti_vs_soti(&x, &ref, dhl, 0.0, name);

                ssoti_free(&x);
                soti_free(&ref);

            }

        }

    }

    check(ok_orders, "e: trc_order = max(requested, direction order), act_order = order, re = 0");
    check(ok_sets, "e: active set = distinct bases of the direction");

    {
        ssotinum_t one = ssoti_e(0, 0, 3);
        bases_t top = 65535, gg[2] = {65535, 65535};
        ssotinum_t big = ssoti_e(sshelp_global_rank(gg, 2), 2, 0);

        check(one.re == 1.0 && one.nbases == 0 && one.trc_order == 3, "e: order 0 is the real 1");
        check(big.nbases == 1 && big.p_bases[0] == top && big.trc_order == 2
              && ssoti_get_item(sshelp_global_rank(gg, 2), 2, &big) == 1.0,
              "e: direction (65535, 65535) at the largest label");

        ssoti_free(&one);
        ssoti_free(&big);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_rank_fallback(dhelpl_t dhl){

    bases_t bases[11];
    bases_t i;
    ssotinum_t num, sq, ref;
    ord_t trc = 5;
    sshelp_pair_t pair;

    for (i = 0; i < 11; i++){
        bases[i] = (bases_t)(i + 1);
    }

    // k=11 at order5 is beyond the global table (Nbasis(5)=10), but within the local
    // product-table cache's default budget (include/oti/core/semisparse.h), so sshelp_get_pair()
    // now lazily builds and caches a table for it instead of leaving pair.p_tab NULL: the scalar
    // kernels (ssoti_kernel_mul_acc) use that table transparently, and this is no longer a
    // per-call rank-only path -- only the name "rank fallback" for this test is now a misnomer for
    // the setup check, kept for the file section title since the naive-reference comparison below
    // is still the point.
    pair = sshelp_get_pair(11, 2, 3, dhl);
    check(pair.p_tab != NULL,
        "cache setup: k=11 at order5 has a cached table (within budget, Nbasis(5)=10)");

    if (pair.p_tab != NULL){

        sshelp_rank_tab_t tab;
        ndir_t np = sshelp_ndir_order(11, 2), nq = sshelp_ndir_order(11, 3);
        ndir_t ii, jj, n_mismatch = 0;

        sshelp_rank_tab_init(&tab, 11, 5);

        for (ii = 0; ii < np; ii++){

            bases_t ui[2];
            sshelp_unrank(ii, 2, ui);

            for (jj = 0; jj < nq; jj++){

                bases_t uj[3];
                ndir_t got, exp;

                sshelp_unrank(jj, 3, uj);
                got = sshelp_pair_idx(&pair, ii, jj);
                exp = sshelp_prod_rank(ui, 2, uj, 3, &tab);

                if (got != exp){
                    n_mismatch++;
                }

            }

        }

        check(n_mismatch == 0, "cache setup: k=11 order5 cached table matches sshelp_prod_rank");

        sshelp_rank_tab_free(&tab);

    }

    rng_seed(0xABCDEF01ULL);
    num = build_ssoti_direct(bases, 11, trc, 0.5, 1.1);

    sq = ssoti_mul_oo(&num, &num, dhl);
    ref = naive_mul_same_set(&num, &num, trc);

    compare_ssoti_vs_ssoti(&ref, &sq, 1e-9, "rank fallback: mul_oo(k=11,order<=5) vs naive dense");

    ssoti_free(&ref);
    ssoti_free(&sq);
    ssoti_free(&num);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);
    rng_seed(0x1234567890ABCDEFULL);

    test_binary_ops(dhl);
    test_gem(dhl);
    test_real_variants(dhl);
    test_functions(dhl);
    test_truncate_and_extract(dhl);
    test_compact();
    test_get_set_deriv(dhl);
    test_add_bases(dhl);
    test_aliasing(dhl);
    test_cancellation(dhl);
    test_large_label(dhl);
    test_rank_fallback(dhl);
    test_e(dhl);

    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse scalar test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse scalar tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
