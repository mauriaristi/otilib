/* Checks of the dense scalar type (include/oti/dense/scalar/{structures,base,algebra,functions,
 * utils}.h, PLAN-dense-update.md, WP1). The oracle is sotinum_t: operands are built as sotinum_t,
 * converted with oti_from_soti(), run through the oti_ function under test, and compared direction by
 * direction with the same soti_ operation on the same inputs (1e-13 relative). Every binary case is
 * also run through the semi-sparse type over [1..k] built from the same sotinum_t, whose coefficient
 * buffer must match the dense one (1e-14). Where the sparse oracle cannot represent the case (nact
 * above Nbasis(p+q)), semi-sparse and a naive product are the references. Orders 1 to 5 throughout.
 *
 * Run without arguments it runs everything, then runs itself again with OTI_SS_TABLE_CACHE_MB=0 and
 * the argument --fallback, which only runs the k = 11 tests: with no local-table cache they take the
 * rank fallback of the product kernel. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>
#include <oti/oti.h>

#define TOL_ORACLE 1e-13
#define TOL_SS     1e-14

static int n_failed = 0;
static uint64_t g_rng_state = 0x1234567890ABCDEFULL;


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

    double diff = fabs(a - b);
    double scale = fmax(1.0, fmax(fabs(a), fabs(b)));

    if (isnan(a) || isnan(b)){
        return isnan(a) && isnan(b);
    }

    return diff <= tol * scale;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A random sotinum_t over bases 1..k at truncation order trc: every order-1 coefficient is nonzero (so
 * the dense and semi-sparse conversions both see every base), orders 2..maxorder hold a `density`
 * fraction of the directions. */
static sotinum_t build_soti(bases_t k, ord_t trc, ord_t maxorder, double density, coeff_t re,
                            dhelpl_t dhl){

    sotinum_t num = soti_createEmpty(trc, dhl);
    ndir_t j, n;
    ord_t p;

    soti_set_item(re, 0, 0, &num, dhl);

    for (p = 1; p <= maxorder && k > 0; p++){

        n = sshelp_ndir_order(k, p);

        for (j = 0; j < n; j++){

            coeff_t v = rng_range(0.05, 0.3) * ((rng_next() & 1) ? 1.0 : -1.0);

            if (p == 1 || rng_range(0.0, 1.0) < density){
                soti_set_item(v, (imdir_t)j, p, &num, dhl);
            }

        }

    }

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A dense number over bases 1..k with every coefficient of orders 1..maxorder random (no oracle). */
static otinum_t build_dense_direct(bases_t k, ord_t trc, ord_t maxorder, coeff_t re){

    otinum_t num = oti_create_empty(k, trc);
    ndir_t j, n = sshelp_order_offset(k, (ord_t)(maxorder + 1));

    for (j = 0; j < n; j++){
        num.p_im[j] = rng_range(-0.3, 0.3);
    }

    num.re = re;
    num.act_order = (k == 0) ? 0 : maxorder;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The semi-sparse number over [1..k] with the same coefficients as a dense one. */
static ssotinum_t ss_from_dense(const otinum_t* num){

    bases_t b[256], i;
    ssotinum_t res;

    for (i = 0; i < num->nact; i++){
        b[i] = (bases_t)(i + 1);
    }

    res = ssoti_create_empty(b, num->nact, num->trc_order);

    if (num->nact > 0){
        memcpy(res.p_im, num->p_im, sshelp_ndir_total(num->nact, num->trc_order) * sizeof(coeff_t));
    }

    res.re = num->re;
    res.act_order = num->act_order;

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESSES     ------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Structural invariants: capacity, act_order <= trc_order, orders above act_order hold zeros. */
static int dn_valid(const otinum_t* d){

    ndir_t j, start, n;
    int ok = (d->nbases >= d->nact) && (d->act_order <= d->trc_order);

    if (d->nact == 0){
        return ok;
    }

    start = sshelp_order_offset(d->nact, (ord_t)(d->act_order + 1));
    n     = sshelp_ndir_total(d->nact, d->trc_order);

    for (j = start; j < n; j++){
        ok = ok && d->p_im[j] == 0.0;
    }

    return ok;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense result against the sparse oracle: real part, truncation order (when check_trc is set), every
 * direction of the dense layout, and every stored oracle direction (which catches oracle entries
 * outside the dense layout). */
static void compare_dn_soti_trc(const otinum_t* d, sotinum_t* s, double tol, const char* ctx,
                                int check_trc, dhelpl_t dhl){

    uint64_t n_checked = 1, n_bad = 0;
    ord_t p, ordi;
    ndir_t j, n;
    char name[256];

    if (!approx_equal(d->re, s->re, tol)){

        fprintf(stderr, "  %s: real part %.17g vs %.17g\n", ctx, d->re, s->re);
        n_bad++;

    }

    if (check_trc && d->trc_order != s->trc_order){

        fprintf(stderr, "  %s: trc_order %u vs %u\n", ctx, (unsigned)d->trc_order,
            (unsigned)s->trc_order);
        n_bad++;

    }

    if (!dn_valid(d)){

        fprintf(stderr, "  %s: invalid dense structure\n", ctx);
        n_bad++;

    }

    for (p = 1; p <= d->trc_order; p++){

        n = sshelp_ndir_order(d->nact, p);

        for (j = 0; j < n; j++){

            coeff_t v1 = oti_get_item(j, p, d), v2 = soti_get_item(j, p, s, dhl);

            n_checked++;

            if (!approx_equal(v1, v2, tol)){

                if (n_bad < 5){
                    fprintf(stderr, "  %s: order %u idx %llu: %.17g vs %.17g\n", ctx, (unsigned)p,
                        (unsigned long long)j, v1, v2);
                }

                n_bad++;

            }

        }

    }

    for (ordi = 0; ordi < s->act_order; ordi++){

        for (j = 0; j < s->p_nnz[ordi]; j++){

            coeff_t v1 = oti_get_item(s->p_idx[ordi][j], (ord_t)(ordi + 1), d);

            if (!approx_equal(v1, s->p_im[ordi][j], tol)){

                if (n_bad < 5){
                    fprintf(stderr, "  %s: oracle order %u idx %llu: %.17g vs %.17g\n", ctx,
                        (unsigned)(ordi + 1), (unsigned long long)s->p_idx[ordi][j], v1,
                        s->p_im[ordi][j]);
                }

                n_bad++;

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu match the sparse oracle", ctx,
        (unsigned long long)(n_checked - n_bad), (unsigned long long)n_checked);
    check(n_bad == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* compare_dn_soti_trc() with the truncation order checked. */
static void compare_dn_soti(const otinum_t* d, sotinum_t* s, double tol, const char* ctx,
                            dhelpl_t dhl){

    compare_dn_soti_trc(d, s, tol, ctx, 1, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense result against a semi-sparse result over [1..nact]: identical layout and coefficient buffer. */
static void compare_dn_ss(const otinum_t* d, const ssotinum_t* s, double tol, const char* ctx){

    int ok = (d->nact == s->nbases) && (d->trc_order == s->trc_order)
             && approx_equal(d->re, s->re, tol);
    ndir_t j, n;
    bases_t i;
    char name[256];

    for (i = 0; ok && i < s->nbases; i++){
        ok = s->p_bases[i] == i + 1;
    }

    n = ok ? sshelp_ndir_total(d->nact, d->trc_order) : 0;

    for (j = 0; j < n; j++){

        if (!approx_equal(d->p_im[j], s->p_im[j], tol)){

            fprintf(stderr, "  %s: coefficient %llu: %.17g vs %.17g\n", ctx, (unsigned long long)j,
                d->p_im[j], s->p_im[j]);
            ok = 0;
            break;

        }

    }

    snprintf(name, sizeof(name), "%s: p_im matches semi-sparse", ctx);
    check(ok, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense against dense through global directions (layouts may differ), including trc_order. */
static int same_dn(const otinum_t* a, const otinum_t* b, double tol){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t p;
    ndir_t j, n;
    int ok = approx_equal(a->re, b->re, tol) && a->trc_order == b->trc_order && dn_valid(a)
             && dn_valid(b);

    for (p = 1; ok && p <= a->trc_order; p++){

        n = sshelp_ndir_order(k, p);

        for (j = 0; ok && j < n; j++){
            ok = approx_equal(oti_get_item(j, p, a), oti_get_item(j, p, b), tol);
        }

    }

    return ok;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MEMORY     --------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_memory(void){

    otinum_t a = oti_init(), b = oti_init(), e;
    int status, ok;
    ord_t p;
    ndir_t i, n;

    // Zero creation, reuse of a larger buffer, and the capacity after lowering trc.
    status = oti_create_empty_to(4, 3, &a);
    n = sshelp_ndir_total(4, 3);
    ok = (status == DN_OK && a.nact == 4 && a.trc_order == 3 && a.act_order == 0 && a.nbases >= 4);

    for (i = 0; i < n; i++){
        ok = ok && a.p_im[i] == 0.0;
    }

    check(ok, "memory: create_empty_to zero layout");

    status = oti_create_empty_to(6, 1, &a);
    check(status == DN_OK && a.nact == 6 && a.trc_order == 1
          && sshelp_ndir_total(a.nbases, a.trc_order) >= sshelp_ndir_total(6, 1),
          "memory: create_empty_to reuses and keeps the capacity valid");

    // Oversized request: a status, no crash, and the number stays freeable.
    status = oti_create_empty_to(65535, 20, &a);
    check(status == DN_ERR_MEMORY, "memory: oversized create_empty_to gives DN_ERR_MEMORY");
    e = oti_create_empty(65535, 20);
    check(isnan(e.re) && e.p_im == NULL, "memory: oversized create_empty gives the NaN sentinel");
    oti_free(&e);

    // Imaginary units.
    e = oti_e(4, 1, 3);
    check(e.nact == 5 && e.trc_order == 3 && e.act_order == 1 && e.p_im[4] == 1.0,
          "memory: oti_e order 1 base 5");
    oti_free(&e);

    // Direction [2, 3] at order 2 has global index C(2,1) + C(3,2) = 2 + 3... ranked with the helper.
    {
        bases_t g[2] = {2, 3};
        imdir_t idx = sshelp_global_rank(g, 2);

        e = oti_e(idx, 2, 1);
        check(e.nact == 3 && e.trc_order == 2 && e.act_order == 2
              && e.p_im[sshelp_order_offset(3, 2) + idx] == 1.0,
              "memory: oti_e order 2 raises trc to the order");
        oti_free(&e);
    }

    e = oti_e(0, 0, 2);
    check(e.re == 1.0 && e.nact == 0 && e.trc_order == 2, "memory: oti_e order 0 is the real unit");
    oti_free(&e);

    // A base above 65535.
    status = oti_e_to(65535, 1, 1, &b);
    check(status == DN_ERR_INDEX, "memory: oti_e_to base 65536 gives DN_ERR_INDEX");
    e = oti_e(65535, 1, 1);
    check(isnan(e.re), "memory: oti_e base 65536 gives the NaN sentinel");
    oti_free(&e);

    // add_bases in place (capacity) versus reallocating, and reserve.
    for (p = 0; p < 2; p++){

        otinum_t x = oti_init(), ref;
        int in_place = (p == 0);

        oti_create_empty_to(3, 3, &x);
        n = sshelp_ndir_total(3, 3);

        for (i = 0; i < n; i++){
            x.p_im[i] = (coeff_t)(i + 1);
        }

        x.re = 7.0;
        x.act_order = 3;
        ref = oti_copy(&x);

        if (in_place){
            oti_reserve(&x, 6, 3);
        }

        {
            coeff_t* before = x.p_im;

            status = oti_add_bases(6, &x);
            ok = status == DN_OK && x.nact == 6 && x.re == 7.0 && x.act_order == 3;
            ok = ok && (in_place ? x.p_im == before : 1);
        }

        {
            ord_t q;

            for (q = 1; q <= 3; q++){

                ndir_t j, N3 = sshelp_ndir_order(3, q), N6 = sshelp_ndir_order(6, q);
                const coeff_t* S = ref.p_im + sshelp_order_offset(3, q);
                const coeff_t* D = x.p_im + sshelp_order_offset(6, q);

                for (j = 0; j < N6; j++){
                    ok = ok && D[j] == ((j < N3) ? S[j] : 0.0);
                }

            }
        }

        check(ok, in_place ? "memory: add_bases in place" : "memory: add_bases reallocating");

        // Reserve a higher order: the new order is zero, the others kept.
        status = oti_reserve(&x, 0, 4);
        ok = status == DN_OK && x.trc_order == 4 && x.nact == 6;

        for (i = sshelp_order_offset(6, 4); i < sshelp_ndir_total(6, 4); i++){
            ok = ok && x.p_im[i] == 0.0;
        }

        ok = ok && x.p_im[sshelp_order_offset(6, 3)] == ref.p_im[sshelp_order_offset(3, 3)];
        check(ok, "memory: reserve raises trc with zero new orders");

        oti_free(&x);
        oti_free(&ref);

    }

    // Copies.
    oti_e_to(2, 1, 2, &a);
    oti_copy_to(&a, &b);
    check(b.nact == 3 && b.trc_order == 2 && b.act_order == 1 && b.p_im[2] == 1.0,
          "memory: copy_to");
    check(oti_copy_to(&b, &b) == DN_OK && b.p_im[2] == 1.0, "memory: copy_to onto itself");

    oti_set_r(3.0, &b);
    check(b.re == 3.0 && b.nact == 0 && b.act_order == 0 && b.trc_order == 2 && b.p_im != NULL,
          "memory: set_r keeps the buffer");

    e = oti_create_r(2.5, 3);
    check(e.re == 2.5 && e.p_im == NULL && e.trc_order == 3, "memory: create_r");
    oti_free(&e);

    oti_free(&a);
    oti_free(&b);
    oti_free(&a);
    check(a.p_im == NULL && a.nact == 0, "memory: double free is safe");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Capacity rule of oti_reserve() and the maximum order. */
static void test_limits(dhelpl_t dhl){

    otinum_t a = oti_create_empty(200, 1), b = oti_init(), x;
    ord_t p;
    int ok = 1;
    double f = 1.0;

    // A number that held 200 bases at order 1, reused for 2 bases at order 4, stays small.
    oti_set_r(0.0, &a);
    check(oti_reserve(&a, 2, 4) == DN_OK && a.nbases == 2 && a.trc_order == 4
          && oti_memory_size(&a) <= sizeof(otinum_t) + 200 * sizeof(coeff_t),
          "reserve: required layout fits the old buffer, nbases = max(cap, nact)");
    oti_free(&a);

    a = oti_create_empty(3, 2);
    check(oti_reserve(&a, 5, 2) == DN_OK && a.nbases == 5 && a.nact == 3, "reserve: capacity grows");
    oti_free(&a);

    // trc 150 works, 151 gives DN_ERR_INDEX everywhere a trc is created or raised.
    check(oti_create_empty_to(1, 150, &b) == DN_OK && b.trc_order == 150, "trc 150 works");
    check(oti_create_empty_to(1, 151, &b) == DN_ERR_INDEX, "create_empty_to trc 151: DN_ERR_INDEX");
    x = oti_create_empty(1, 151);
    check(isnan(x.re), "create_empty trc 151: NaN sentinel");
    check(oti_e_to(0, 1, 151, &b) == DN_ERR_INDEX, "e_to trc 151: DN_ERR_INDEX");
    check(oti_e_to(0, 151, 1, &b) == DN_ERR_INDEX, "e_to order 151: DN_ERR_INDEX");
    oti_create_empty_to(1, 3, &b);
    check(oti_reserve(&b, 1, 151) == DN_ERR_INDEX && b.trc_order == 3, "reserve trc 151: DN_ERR_INDEX");
    oti_free(&b);

    // exp(0.5 + e1) at order 150: coefficient p is exp(0.5) / p!.
    b = oti_e(0, 1, 150);
    b.re = 0.5;
    x = oti_exp(&b, dhl);

    for (p = 1; p <= 150; p++){
        f *= p;
        ok = ok && approx_equal(x.p_im[p - 1] * f, exp(0.5), 1e-12);
    }

    check(ok && x.trc_order == 150 && x.act_order == 150, "exp of a univariate number at order 150");

    oti_free(&b);
    oti_free(&x);

}
// -------------------------------------------------------------------------------------------------------




// *******************************************************************************************************
/* Byte budget of the size gate (default: the physical memory): a representable request far above it
   returns DN_ERR_MEMORY before any allocation and leaves the result valid. */
static void test_budget(dhelpl_t dhl){

    otinum_t b = oti_init(), x;

    // nact 20000 at order 3: 1.3e12 coefficients, 9.9 TiB.
    check(oti_create_empty_to(20000, 3, &b) == DN_ERR_MEMORY && b.p_im == NULL,
          "budget: create_empty_to far above the memory gives DN_ERR_MEMORY");
    x = oti_create_empty(1000, 4);
    check(isnan(x.re) && x.p_im == NULL, "budget: create_empty (1000, 4) gives the NaN sentinel");
    check(oti_e_to(19999, 1, 3, &b) == DN_ERR_MEMORY, "budget: e_to base 20000 at trc 3");

    oti_create_empty_to(2, 2, &b);
    check(oti_reserve(&b, 20000, 3) == DN_ERR_MEMORY && b.nbases == 2 && b.trc_order == 2,
          "budget: reserve above the budget leaves the number unchanged");
    oti_free(&b);

    b = oti_e(19999, 1, 1);
    check(b.nact == 20000 && oti_reserve(&b, 20000, 3) == DN_ERR_MEMORY && b.trc_order == 1,
          "budget: raising the trc of a wide number above the budget fails cleanly");
    oti_free(&b);
    (void)dhl;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Child run with OTI_DENSE_MAX_MB=1 (131072 coefficients): requests just below pass, above fail,
   in creators, reserve and binary operations. */
static void test_budget_child(dhelpl_t dhl){

    otinum_t a = oti_init(), b = oti_init(), r = oti_init();

    // C(25, 5) - 1 = 53129 coefficients fit; C(35, 5) - 1 = 324631 do not.
    check(oti_create_empty_to(20, 5, &a) == DN_OK, "budget 1 MB: nact 20, trc 5 fits");
    check(oti_create_empty_to(30, 5, &b) == DN_ERR_MEMORY, "budget 1 MB: nact 30, trc 5 refused");
    check(oti_reserve(&a, 30, 5) == DN_ERR_MEMORY && a.nbases == 20, "budget 1 MB: reserve refused");

    // A sum raising the result to nact 20 at trc 6 (230229 coefficients) is refused.
    a.re = 1.0;
    oti_create_empty_to(1, 6, &b);
    b.re = 2.0;
    check(oti_sum_oo_to(&a, &b, &r, dhl) == DN_ERR_MEMORY, "budget 1 MB: sum above the budget");
    check(oti_mul_oo_to(&a, &b, &r, dhl) == DN_ERR_MEMORY, "budget 1 MB: product above the budget");
    check(oti_sum_oo_to(&a, &a, &r, dhl) == DN_OK && r.re == 2.0, "budget 1 MB: sum within it");

    oti_free(&a);
    oti_free(&b);
    oti_free(&r);

}
// -------------------------------------------------------------------------------------------------------




// -------------------------------------------------------------------------------------------------------
// -------------------------------------     CONVERSIONS AND ACCESS     ----------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_conversions(dhelpl_t dhl){

    ord_t trc;
    char ctx[128];

    for (trc = 1; trc <= 5; trc++){

        sotinum_t s = build_soti(4, trc, trc, 0.5, 1.5, dhl), back;
        otinum_t d = oti_from_soti(&s, dhl);
        ssotinum_t ss = ssoti_from_soti(&s, dhl);

        snprintf(ctx, sizeof(ctx), "from_soti trc %u", (unsigned)trc);
        compare_dn_soti(&d, &s, 0.0, ctx, dhl);
        compare_dn_ss(&d, &ss, 0.0, ctx);
        check(d.nact == 4 && d.act_order == trc, "from_soti nact and act_order");

        back = oti_to_soti(&d, dhl);
        snprintf(ctx, sizeof(ctx), "to_soti round trip trc %u", (unsigned)trc);
        compare_dn_soti(&d, &back, 0.0, ctx, dhl);

        soti_free(&s);
        soti_free(&back);
        oti_free(&d);
        ssoti_free(&ss);

    }

    // nact is the largest stored base, explicit zeros included; a real sotinum gives nact 0.
    {
        sotinum_t s = soti_createEmpty(3, dhl);
        bases_t g[2] = {2, 6};
        otinum_t d;

        soti_set_item(0.5, 0, 1, &s, dhl);
        soti_set_item(0.0, sshelp_global_rank(g, 2), 2, &s, dhl);
        d = oti_from_soti(&s, dhl);
        check(d.nact == 6 && d.trc_order == 3, "from_soti counts an explicit zero's base");
        oti_free(&d);
        soti_free(&s);

        s = soti_createEmpty(2, dhl);
        soti_set_item(2.0, 0, 0, &s, dhl);
        d = oti_from_soti(&s, dhl);
        check(d.nact == 0 && d.re == 2.0 && d.trc_order == 2 && d.act_order == 0,
              "from_soti of a real number");
        oti_free(&d);
        soti_free(&s);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_access(dhelpl_t dhl){

    otinum_t d = oti_create_empty(2, 3);
    bases_t g3[3] = {1, 4, 4}, g2[2] = {2, 3};
    imdir_t i3 = sshelp_global_rank(g3, 3), i2 = sshelp_global_rank(g2, 2);
    sotinum_t s;
    int status;

    // Growing through set_item, a zero outside the layout, an order above trc.
    status = oti_set_item(0.7, i3, 3, &d);
    check(status == DN_OK && d.nact == 4 && d.act_order == 3 && oti_get_item(i3, 3, &d) == 0.7,
          "set_item grows nact");
    check(oti_set_item(0.0, 7, 1, &d) == DN_OK && d.nact == 4, "set_item of a zero outside is a no-op");
    check(oti_set_item(1.0, 0, 4, &d) == DN_OK && oti_get_item(0, 4, &d) == 0.0,
          "set_item above trc is ignored");
    check(oti_set_item(1.0, 65535, 1, &d) == DN_ERR_INDEX, "set_item base 65536 gives DN_ERR_INDEX");
    oti_set_item(-0.25, i2, 2, &d);
    oti_set_item(3.0, 0, 0, &d);
    check(oti_get_item(i2, 2, &d) == -0.25 && d.re == 3.0 && oti_get_item(10, 1, &d) == 0.0,
          "get_item inside and outside");

    // Derivatives: coefficient times the multiplicity factorials.
    s = oti_to_soti(&d, dhl);
    check(oti_get_deriv(i3, 3, &d) == 0.7 * dhelp_get_deriv_factor(i3, 3, dhl)
          && oti_get_deriv(i3, 3, &d) == 1.4 && oti_get_deriv(i2, 2, &d) == -0.25,
          "get_deriv factors");
    check(approx_equal(oti_density(&d), 2.0 / (double)sshelp_ndir_total(4, 3), 1e-15),
          "density");
    check(oti_memory_size(&d) >= sizeof(otinum_t) + sshelp_ndir_total(4, 3) * sizeof(coeff_t),
          "memory_size");

    printf("oti_print sample:\n");
    oti_print(&d);

    soti_free(&s);
    oti_free(&d);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BINARY OPERATIONS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct {
    bases_t k1; int t1; int m1; bases_t k2; int t2; int m2; const char* label;
} scen_t;

// Truncation and maximum orders: T is the loop order, L = (T+1)/2, A = the act_order-limited order.
#define ORD_T  (-1)
#define ORD_L  (-2)
#define ORD_A  (-3)

static const scen_t SCENS[] = {
    { 3, ORD_T, ORD_T,  3, ORD_T, ORD_T, "equal nact" },
    { 2, ORD_T, ORD_T,  4, ORD_T, ORD_T, "smaller nact left" },
    { 4, ORD_T, ORD_T,  2, ORD_T, ORD_T, "smaller nact right" },
    { 0, ORD_T, 0,      3, ORD_T, ORD_T, "real left" },
    { 3, ORD_T, ORD_T,  0, ORD_T, 0,     "real right" },
    { 0, ORD_T, 0,      0, ORD_L, 0,     "both real" },
    { 3, ORD_L, ORD_L,  3, ORD_T, ORD_T, "mixed trc (low left)" },
    { 4, ORD_T, ORD_T,  2, ORD_L, ORD_L, "mixed trc and nact" },
    { 3, ORD_T, 1,      4, ORD_T, ORD_A, "act below trc" },
};

#define N_SCENS (sizeof(SCENS) / sizeof(SCENS[0]))

typedef int (*dn_oo_fn)(const otinum_t*, const otinum_t*, otinum_t*, dhelpl_t);
typedef void (*ss_oo_fn)(const ssotinum_t*, const ssotinum_t*, ssotinum_t*, dhelpl_t);
typedef sotinum_t (*so_oo_fn)(sotinum_t*, sotinum_t*, dhelpl_t);

typedef struct { const char* name; dn_oo_fn dn; ss_oo_fn ss; so_oo_fn so; } oo_op_t;

static const oo_op_t OO_OPS[] = {
    { "sum", oti_sum_oo_to, ssoti_sum_oo_to, soti_sum_oo },
    { "sub", oti_sub_oo_to, ssoti_sub_oo_to, soti_sub_oo },
    { "mul", oti_mul_oo_to, ssoti_mul_oo_to, soti_mul_oo },
    { "div", oti_div_oo_to, ssoti_div_oo_to, soti_div_oo },
};

#define N_OO_OPS (sizeof(OO_OPS) / sizeof(OO_OPS[0]))


// *******************************************************************************************************
static ord_t scen_order(int code, ord_t T){

    if (code == ORD_T){
        return T;
    }

    if (code == ORD_L){
        return (ord_t)((T + 1) / 2);
    }

    if (code == ORD_A){
        return (ord_t)((T > 1) ? T - 1 : 1);
    }

    return (ord_t)code;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* sum/sub/mul/div over every scenario at orders 1..5: oracle, semi-sparse, layout rules and aliasing
 * (res = num1, res = num2, num1 = num2 = res). */
static void test_binary(dhelpl_t dhl){

    size_t s, o;
    ord_t T;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        for (s = 0; s < N_SCENS; s++){

            const scen_t* sc = &SCENS[s];
            ord_t t1 = scen_order(sc->t1, T), t2 = scen_order(sc->t2, T);
            sotinum_t s1 = build_soti(sc->k1, t1, scen_order(sc->m1, T), 0.6, 1.3, dhl);
            sotinum_t s2 = build_soti(sc->k2, t2, scen_order(sc->m2, T), 0.6, 0.8, dhl);
            otinum_t d1 = oti_from_soti(&s1, dhl), d2 = oti_from_soti(&s2, dhl);
            ssotinum_t q1 = ssoti_from_soti(&s1, dhl), q2 = ssoti_from_soti(&s2, dhl);

            for (o = 0; o < N_OO_OPS; o++){

                sotinum_t ref = OO_OPS[o].so(&s1, &s2, dhl), ref_self;
                otinum_t res = oti_init(), al = oti_init();
                ssotinum_t qres = ssoti_init();
                bases_t kmax = (sc->k1 > sc->k2) ? sc->k1 : sc->k2;
                ord_t tmax = (t1 > t2) ? t1 : t2;
                int status;

                status = OO_OPS[o].dn(&d1, &d2, &res, dhl);
                OO_OPS[o].ss(&q1, &q2, &qres, dhl);

                snprintf(ctx, sizeof(ctx), "%s T=%u (%s)", OO_OPS[o].name, (unsigned)T, sc->label);
                check(status == DN_OK && res.nact == kmax && res.trc_order == tmax, ctx);
                compare_dn_soti(&res, &ref, TOL_ORACLE, ctx, dhl);
                compare_dn_ss(&res, &qres, TOL_SS, ctx);

                // res aliasing the first operand, then the second.
                oti_copy_to(&d1, &al);
                status = OO_OPS[o].dn(&al, &d2, &al, dhl);
                snprintf(ctx, sizeof(ctx), "%s T=%u (%s) res = num1", OO_OPS[o].name, (unsigned)T,
                    sc->label);
                check(status == DN_OK && same_dn(&al, &res, TOL_SS), ctx);

                oti_copy_to(&d2, &al);
                status = OO_OPS[o].dn(&d1, &al, &al, dhl);
                snprintf(ctx, sizeof(ctx), "%s T=%u (%s) res = num2", OO_OPS[o].name, (unsigned)T,
                    sc->label);
                check(status == DN_OK && same_dn(&al, &res, TOL_SS), ctx);

                // One number as both operands and the result.
                ref_self = OO_OPS[o].so(&s1, &s1, dhl);
                oti_copy_to(&d1, &al);
                status = OO_OPS[o].dn(&al, &al, &al, dhl);
                snprintf(ctx, sizeof(ctx), "%s T=%u (%s) num1 = num2 = res", OO_OPS[o].name,
                    (unsigned)T, sc->label);
                check(status == DN_OK, ctx);
                compare_dn_soti(&al, &ref_self, TOL_ORACLE, ctx, dhl);

                soti_free(&ref);
                soti_free(&ref_self);
                oti_free(&res);
                oti_free(&al);
                ssoti_free(&qres);

            }

            soti_free(&s1);
            soti_free(&s2);
            oti_free(&d1);
            oti_free(&d2);
            ssoti_free(&q1);
            ssoti_free(&q2);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The allocating variants and the act_order bookkeeping of products and sums. */
static void test_allocating_and_act(dhelpl_t dhl){

    otinum_t a = build_dense_direct(3, 5, 1, 0.5), b = build_dense_direct(2, 5, 2, 2.0), r;
    otinum_t c = build_dense_direct(4, 3, 3, -1.0), t = oti_init();

    r = oti_mul_oo(&a, &b, dhl);
    check(r.act_order == 3 && r.nact == 3 && r.trc_order == 5, "mul act_order = act1 + act2");
    oti_free(&r);

    r = oti_mul_oo(&c, &c, dhl);
    check(r.act_order == 3, "mul act_order capped at trc");
    oti_free(&r);

    r = oti_sum_oo(&a, &b, dhl);
    check(r.act_order == 2 && r.nact == 3, "sum act_order = max");
    oti_mul_oo_to(&a, &b, &t, dhl);
    oti_free(&r);

    r = oti_mul_oo(&a, &b, dhl);
    check(same_dn(&r, &t, 0.0), "mul_oo equals mul_oo_to");
    oti_free(&r);

    r = oti_sub_oo(&a, &b, dhl);
    oti_sub_oo_to(&a, &b, &t, dhl);
    check(same_dn(&r, &t, 0.0), "sub_oo equals sub_oo_to");
    oti_free(&r);

    r = oti_div_oo(&c, &b, dhl);
    oti_div_oo_to(&c, &b, &t, dhl);
    check(same_dn(&r, &t, 0.0) && r.nact == 4 && r.trc_order == 5,
          "div_oo uses both layouts and equals div_oo_to");
    oti_free(&r);

    oti_free(&a);
    oti_free(&b);
    oti_free(&c);
    oti_free(&t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* res = num1 * num2 + num3 against soti_gem_oo_to(), with every aliasing. */
static void test_gem(dhelpl_t dhl){

    size_t s;
    ord_t T;
    int al;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        // The second pass has both factors at the low order L and num3 at T: the product is
        // truncated at max(t1, t2) = L, whatever the aliasing.
        for (s = 0; s < 2 * N_SCENS; s++){

            const scen_t* sc = &SCENS[s % N_SCENS];
            int low = (s >= N_SCENS);
            ord_t L = scen_order(ORD_L, T);
            ord_t t1 = low ? L : scen_order(sc->t1, T), t2 = low ? L : scen_order(sc->t2, T);
            ord_t m1 = scen_order(sc->m1, T), m2 = scen_order(sc->m2, T);
            bases_t k3 = (s % 2 == 0) ? 5 : 1;
            ord_t t3 = (low || s % 3 == 0) ? T : L;
            sotinum_t s1 = build_soti(sc->k1, t1, (m1 < t1) ? m1 : t1, 0.6, 1.3, dhl);
            sotinum_t s2 = build_soti(sc->k2, t2, (m2 < t2) ? m2 : t2, 0.6, 0.8, dhl);
            sotinum_t s3 = build_soti(k3, t3, t3, 0.6, 0.4, dhl);
            sotinum_t ref = soti_init(), ref_sq = soti_init();
            otinum_t d1 = oti_from_soti(&s1, dhl), d2 = oti_from_soti(&s2, dhl);
            otinum_t d3 = oti_from_soti(&s3, dhl), res = oti_init(), x = oti_init();
            ssotinum_t q1 = ssoti_from_soti(&s1, dhl), q2 = ssoti_from_soti(&s2, dhl);
            ssotinum_t q3 = ssoti_from_soti(&s3, dhl), qres = ssoti_init();

            soti_gem_oo_to(&s1, &s2, &s3, &ref, dhl);
            soti_gem_oo_to(&s1, &s1, &s3, &ref_sq, dhl);
            oti_gem_oo_to(&d1, &d2, &d3, &res, dhl);
            ssoti_gem_oo_to(&q1, &q2, &q3, &qres, dhl);

            snprintf(ctx, sizeof(ctx), "gem T=%u (%s%s)", (unsigned)T, sc->label,
                low ? ", factors at L, num3 at T" : "");
            compare_dn_soti(&res, &ref, TOL_ORACLE, ctx, dhl);
            compare_dn_ss(&res, &qres, TOL_SS, ctx);

            for (al = 0; al < 4; al++){

                int status = 0;

                if (al == 0){
                    oti_copy_to(&d1, &x);
                    status = oti_gem_oo_to(&x, &d2, &d3, &x, dhl);
                } else if (al == 1){
                    oti_copy_to(&d2, &x);
                    status = oti_gem_oo_to(&d1, &x, &d3, &x, dhl);
                } else if (al == 2){
                    oti_copy_to(&d3, &x);
                    status = oti_gem_oo_to(&d1, &d2, &x, &x, dhl);
                } else {
                    oti_copy_to(&d1, &x);
                    status = oti_gem_oo_to(&x, &x, &d3, &x, dhl);
                }

                snprintf(ctx, sizeof(ctx), "gem T=%u (%s%s) aliasing %d", (unsigned)T, sc->label,
                    low ? ", factors at L, num3 at T" : "", al);

                if (al < 3){
                    check(status == DN_OK && same_dn(&x, &res, TOL_SS), ctx);
                } else {
                    check(status == DN_OK, ctx);
                    compare_dn_soti(&x, &ref_sq, TOL_ORACLE, ctx, dhl);
                }

            }

            soti_free(&s1);
            soti_free(&s2);
            soti_free(&s3);
            soti_free(&ref);
            soti_free(&ref_sq);
            oti_free(&d1);
            oti_free(&d2);
            oti_free(&d3);
            oti_free(&res);
            oti_free(&x);
            ssoti_free(&q1);
            ssoti_free(&q2);
            ssoti_free(&q3);
            ssoti_free(&qres);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Real-operand variants: sum_or, sub_or, sub_ro, mul_or, div_or, div_ro, neg, and their aliasing. */
static void test_real_variants(dhelpl_t dhl){

    coeff_t val = 0.65;
    ord_t T;
    int v;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        sotinum_t s = build_soti(3, T, T, 0.6, 1.3, dhl);
        otinum_t d = oti_from_soti(&s, dhl);

        for (v = 0; v < 7; v++){

            sotinum_t ref;
            otinum_t res = oti_init(), al = oti_copy(&d), a1;
            const char* name;

            switch (v){
                case 0:  ref = soti_sum_or(&s, val, dhl); name = "sum_or";
                         oti_sum_or_to(&d, val, &res, dhl); oti_sum_or_to(&al, val, &al, dhl);
                         a1 = oti_sum_or(&d, val, dhl); break;
                case 1:  ref = soti_sub_or(&s, val, dhl); name = "sub_or";
                         oti_sub_or_to(&d, val, &res, dhl); oti_sub_or_to(&al, val, &al, dhl);
                         a1 = oti_sub_or(&d, val, dhl); break;
                case 2:  ref = soti_sub_ro(val, &s, dhl); name = "sub_ro";
                         oti_sub_ro_to(val, &d, &res, dhl); oti_sub_ro_to(val, &al, &al, dhl);
                         a1 = oti_sub_ro(val, &d, dhl); break;
                case 3:  ref = soti_mul_or(&s, val, dhl); name = "mul_or";
                         oti_mul_or_to(&d, val, &res, dhl); oti_mul_or_to(&al, val, &al, dhl);
                         a1 = oti_mul_or(&d, val, dhl); break;
                case 4:  ref = soti_div_or(&s, val, dhl); name = "div_or";
                         oti_div_or_to(&d, val, &res, dhl); oti_div_or_to(&al, val, &al, dhl);
                         a1 = oti_div_or(&d, val, dhl); break;
                case 5:  ref = soti_div_ro(val, &s, dhl); name = "div_ro";
                         oti_div_ro_to(val, &d, &res, dhl); oti_div_ro_to(val, &al, &al, dhl);
                         a1 = oti_div_ro(val, &d, dhl); break;
                default: ref = soti_neg(&s, dhl); name = "neg";
                         oti_neg_to(&d, &res, dhl); oti_neg_to(&al, &al, dhl);
                         a1 = oti_neg(&d, dhl); break;
            }

            snprintf(ctx, sizeof(ctx), "%s T=%u", name, (unsigned)T);
            compare_dn_soti(&res, &ref, TOL_ORACLE, ctx, dhl);
            snprintf(ctx, sizeof(ctx), "%s T=%u aliasing and allocating variant", name, (unsigned)T);
            check(same_dn(&al, &res, TOL_SS) && same_dn(&a1, &res, 0.0), ctx);

            soti_free(&ref);
            oti_free(&res);
            oti_free(&al);
            oti_free(&a1);

        }

        soti_free(&s);
        oti_free(&d);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The raw kernels: expansion equals add_bases, the same-layout product equals oti_mul_oo_to(). */
static void test_kernels(dhelpl_t dhl){

    otinum_t a = build_dense_direct(2, 4, 3, 0.0), b = build_dense_direct(4, 4, 4, 0.0);
    otinum_t ea = oti_copy(&a), prod = oti_init();
    coeff_t *buf = (coeff_t*)malloc(sshelp_ndir_total(4, 5) * sizeof(coeff_t));
    coeff_t *acc = (coeff_t*)calloc(sshelp_ndir_total(4, 4), sizeof(coeff_t));
    ndir_t j, n;
    int ok = 1;

    // Expansion to a larger nact and a higher trc.
    oti_kernel_expand(&a, 4, 5, buf);
    oti_reserve(&ea, 4, 5);
    oti_add_bases(4, &ea);
    n = sshelp_ndir_total(4, 5);

    for (j = 0; j < n; j++){
        ok = ok && buf[j] == ea.p_im[j];
    }

    check(ok, "kernel_expand equals reserve + add_bases");

    // Same-layout product of the imaginary parts.
    oti_mul_oo_to(&ea, &b, &prod, dhl);
    oti_kernel_mul_acc(ea.p_im, 1, 3, b.p_im, 1, 4, 4, 4, acc, dhl);
    n  = sshelp_ndir_total(4, 4);
    ok = 1;

    for (j = 0; j < n; j++){
        ok = ok && approx_equal(acc[j], prod.p_im[j], 1e-15);
    }

    check(ok, "kernel_mul_acc equals the product of real-free operands");

    free(buf);
    free(acc);
    oti_free(&a);
    oti_free(&b);
    oti_free(&ea);
    oti_free(&prod);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     FUNCTIONS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef int (*dn_f_fn)(const otinum_t*, otinum_t*, dhelpl_t);
typedef void (*ss_f_fn)(const ssotinum_t*, ssotinum_t*, dhelpl_t);
typedef void (*so_f_fn)(sotinum_t*, sotinum_t*, dhelpl_t);

typedef struct { const char* name; dn_f_fn dn; ss_f_fn ss; so_f_fn so; coeff_t re; } f_op_t;

static const f_op_t F_OPS[] = {
    { "exp",   oti_exp_to,   ssoti_exp_to,   soti_exp_to,   0.4 },
    { "log",   oti_log_to,   ssoti_log_to,   soti_log_to,   1.7 },
    { "log10", oti_log10_to, ssoti_log10_to, soti_log10_to, 1.7 },
    { "sqrt",  oti_sqrt_to,  ssoti_sqrt_to,  soti_sqrt_to,  1.7 },
    { "cbrt",  oti_cbrt_to,  ssoti_cbrt_to,  soti_cbrt_to,  1.7 },
    { "sin",   oti_sin_to,   ssoti_sin_to,   soti_sin_to,   0.4 },
    { "cos",   oti_cos_to,   ssoti_cos_to,   soti_cos_to,   0.4 },
    { "tan",   oti_tan_to,   ssoti_tan_to,   soti_tan_to,   0.4 },
    { "asin",  oti_asin_to,  ssoti_asin_to,  soti_asin_to,  0.3 },
    { "acos",  oti_acos_to,  ssoti_acos_to,  soti_acos_to,  0.3 },
    { "atan",  oti_atan_to,  ssoti_atan_to,  soti_atan_to,  0.4 },
    { "sinh",  oti_sinh_to,  ssoti_sinh_to,  soti_sinh_to,  0.4 },
    { "cosh",  oti_cosh_to,  ssoti_cosh_to,  soti_cosh_to,  0.4 },
    { "tanh",  oti_tanh_to,  ssoti_tanh_to,  soti_tanh_to,  0.4 },
    { "asinh", oti_asinh_to, ssoti_asinh_to, soti_asinh_to, 0.4 },
    { "acosh", oti_acosh_to, ssoti_acosh_to, soti_acosh_to, 1.7 },
    { "atanh", oti_atanh_to, ssoti_atanh_to, soti_atanh_to, 0.3 },
    { "erf",   oti_erf_to,   ssoti_erf_to,   soti_erf_to,   0.4 },
};

#define N_F_OPS (sizeof(F_OPS) / sizeof(F_OPS[0]))


// *******************************************************************************************************
/* One function case: oracle, semi-sparse, layout (input's nact and trc, act_order = trc) and
 * res aliasing the input. fn_kind 0 uses F_OPS[idx]; 1 is pow with exponent par; 2 is logb. */
static void check_function(int fn_kind, size_t idx, coeff_t par, bases_t k, ord_t T, ord_t m,
                           coeff_t re, dhelpl_t dhl){

    sotinum_t s = build_soti(k, T, m, 0.6, re, dhl), ref = soti_init();
    otinum_t d = oti_from_soti(&s, dhl), res = oti_init(), al = oti_copy(&d), a1;
    ssotinum_t q = ssoti_from_soti(&s, dhl), qres = ssoti_init();
    int status, st_al;
    char ctx[160];

    if (fn_kind == 0){

        F_OPS[idx].so(&s, &ref, dhl);
        F_OPS[idx].ss(&q, &qres, dhl);
        status = F_OPS[idx].dn(&d, &res, dhl);
        st_al  = F_OPS[idx].dn(&al, &al, dhl);
        a1     = oti_copy(&res);
        snprintf(ctx, sizeof(ctx), "%s k=%u T=%u act=%u", F_OPS[idx].name, (unsigned)k,
            (unsigned)T, (unsigned)m);

    } else if (fn_kind == 1){

        soti_pow_to(&s, par, &ref, dhl);
        ssoti_pow_to(&q, par, &qres, dhl);
        status = oti_pow_to(&d, par, &res, dhl);
        st_al  = oti_pow_to(&al, par, &al, dhl);
        a1     = oti_pow(&d, par, dhl);
        snprintf(ctx, sizeof(ctx), "pow(%g) k=%u T=%u act=%u", par, (unsigned)k, (unsigned)T,
            (unsigned)m);

    } else {

        soti_logb_to(&s, par, &ref, dhl);
        ssoti_logb_to(&q, par, &qres, dhl);
        status = oti_logb_to(&d, par, &res, dhl);
        st_al  = oti_logb_to(&al, par, &al, dhl);
        a1     = oti_logb(&d, par, dhl);
        snprintf(ctx, sizeof(ctx), "logb(%g) k=%u T=%u act=%u", par, (unsigned)k, (unsigned)T,
            (unsigned)m);

    }

    check(status == DN_OK && st_al == DN_OK && res.nact == k && res.trc_order == T
          && res.act_order == ((k == 0) ? 0 : T), ctx);
    compare_dn_soti(&res, &ref, TOL_ORACLE, ctx, dhl);
    compare_dn_ss(&res, &qres, TOL_SS, ctx);
    check(same_dn(&al, &res, 0.0) && same_dn(&a1, &res, 0.0), "  aliasing and allocating variant");

    soti_free(&s);
    soti_free(&ref);
    oti_free(&d);
    oti_free(&res);
    oti_free(&al);
    oti_free(&a1);
    ssoti_free(&q);
    ssoti_free(&qres);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_functions(dhelpl_t dhl){

    static const coeff_t pows[] = {-1.0, -1.5, 0.5, 2.0, 3.0, 2.5, 0.0};
    size_t f, e;
    ord_t T;

    for (T = 1; T <= 5; T++){

        for (f = 0; f < N_F_OPS; f++){

            check_function(0, f, 0.0, 3, T, T, F_OPS[f].re, dhl);

            // act_order below trc (a linear seed), a real input.
            if (T == 4){
                check_function(0, f, 0.0, 3, T, 1, F_OPS[f].re, dhl);
                check_function(0, f, 0.0, 0, T, 0, F_OPS[f].re, dhl);
            }

        }

        for (e = 0; e < sizeof(pows) / sizeof(pows[0]); e++){
            check_function(1, 0, pows[e], 3, T, T, 1.3, dhl);
        }

        check_function(2, 0, 3.0, 3, T, T, 1.7, dhl);
        check_function(2, 0, 0.5, 2, T, 2 < T ? 2 : T, 2.5, dhl);

    }

    // Allocating feval with a user derivative list.
    {
        coeff_t derivs[4] = {1.0, 2.0, 3.0, 4.0};
        otinum_t x = build_dense_direct(2, 3, 3, 0.0), y = oti_feval(derivs, &x, dhl), z = oti_init();

        oti_feval_to(derivs, &x, &z, dhl);
        check(same_dn(&y, &z, 0.0) && y.re == 1.0, "feval allocating variant");
        oti_free(&x);
        oti_free(&y);
        oti_free(&z);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     TRUNCATION AND COMPACTION     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_truncation(dhelpl_t dhl){

    static const bases_t dirs[][3] = {{1, 0, 0}, {2, 3, 0}, {3, 3, 0}, {1, 2, 3}, {4, 0, 0},
                                      {2, 5, 0}};
    static const ord_t dir_ord[] = {1, 2, 2, 3, 1, 2};
    ord_t T, o;
    size_t i;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        sotinum_t s = build_soti(3, T, T, 0.7, 1.1, dhl);
        otinum_t d = oti_from_soti(&s, dhl);

        for (i = 0; i < sizeof(dir_ord) / sizeof(dir_ord[0]); i++){

            ord_t p = dir_ord[i];
            imdir_t idx = sshelp_global_rank(dirs[i], p);
            sotinum_t ref = soti_truncate_im(idx, p, &s, dhl);
            otinum_t res = oti_truncate_im(idx, p, &d), al = oti_copy(&d);
            int status = oti_truncate_im_to(idx, p, &al, &al);

            snprintf(ctx, sizeof(ctx), "truncate_im T=%u dir %zu", (unsigned)T, i);
            compare_dn_soti(&res, &ref, 0.0, ctx, dhl);
            check(status == DN_OK && same_dn(&al, &res, 0.0) && res.nact == 3, "  aliasing, nact kept");

            soti_free(&ref);
            oti_free(&res);
            oti_free(&al);

        }

        for (o = 0; o <= T + 1; o++){

            sotinum_t ref = soti_truncate_order(o, &s, dhl), ref2 = soti_get_order_im(o, &s, dhl);
            otinum_t res = oti_truncate_order(o, &d), al = oti_copy(&d);
            otinum_t res2 = oti_get_order_im(o, &d), al2 = oti_copy(&d);
            int st1 = oti_truncate_order_to(o, &al, &al), st2 = oti_get_order_im_to(o, &al2, &al2);

            // The sparse oracle drops trc to 0 for order 0; dense keeps it (checked below).
            snprintf(ctx, sizeof(ctx), "truncate_order T=%u order %u", (unsigned)T, (unsigned)o);
            compare_dn_soti_trc(&res, &ref, 0.0, ctx, o > 0, dhl);
            check(st1 == DN_OK && same_dn(&al, &res, 0.0) && res.trc_order == T && res.nact == 3
                  && al.nact == 3, "  aliasing, trc and nact kept");

            snprintf(ctx, sizeof(ctx), "get_order_im T=%u order %u", (unsigned)T, (unsigned)o);
            compare_dn_soti_trc(&res2, &ref2, 0.0, ctx, o > 0 && o <= T, dhl);
            check(st2 == DN_OK && same_dn(&al2, &res2, 0.0) && res2.trc_order == T,
                  "  aliasing, trc kept");

            soti_free(&ref);
            soti_free(&ref2);
            oti_free(&res);
            oti_free(&al);
            oti_free(&res2);
            oti_free(&al2);

        }

        soti_free(&s);
        oti_free(&d);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_compact(dhelpl_t dhl){

    otinum_t d = oti_create_empty(6, 4), c, al;
    bases_t g1[2] = {1, 3}, g2[3] = {1, 1, 3};
    int ok;

    // Nonzeros only on bases 1 and 3, orders 1 and 3 (act_order 4): nact 3, act_order 3.
    oti_set_item(0.5, 0, 1, &d);
    oti_set_item(0.25, sshelp_global_rank(g1, 2), 2, &d);
    oti_set_item(-2.0, sshelp_global_rank(g2, 3), 3, &d);
    oti_set_item(1.0, 5, 1, &d);
    oti_set_item(0.0, 5, 1, &d);
    d.act_order = 4;
    d.re = 3.0;

    c  = oti_compact(&d);
    ok = c.nact == 3 && c.act_order == 3 && c.trc_order == 4 && c.nbases == 3 && same_dn(&c, &d, 0.0);
    check(ok, "compact trims trailing zero bases, keeps the zero base 2");

    al = oti_copy(&d);
    check(oti_compact_to(&al, &al) == DN_OK && same_dn(&al, &c, 0.0) && al.nact == 3
          && al.nbases >= 6, "compact in place keeps the capacity");
    oti_free(&al);

    oti_set_r(4.0, &d);
    oti_compact_to(&d, &c);
    check(c.nact == 0 && c.act_order == 0 && c.re == 4.0 && c.trc_order == 4, "compact of a real");

    oti_free(&c);
    oti_free(&d);
    (void)dhl;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     UTILS     ---------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_extract(dhelpl_t dhl){

    static const bases_t dirs[][3] = {{1, 0, 0}, {2, 2, 0}, {1, 3, 0}, {1, 2, 3}, {5, 0, 0},
                                      {2, 4, 0}};
    static const ord_t dir_ord[] = {1, 2, 2, 3, 1, 2};
    ord_t T;
    size_t i;
    int deriv;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        sotinum_t s = build_soti(3, T, (T > 1) ? T - 1 : 1, 0.7, 1.1, dhl);
        otinum_t d = oti_from_soti(&s, dhl);

        for (i = 0; i < sizeof(dir_ord) / sizeof(dir_ord[0]); i++){

            for (deriv = 0; deriv <= 1; deriv++){

                ord_t p = dir_ord[i];
                imdir_t idx = sshelp_global_rank(dirs[i], p);
                sotinum_t ref = deriv ? soti_extract_deriv(idx, p, &s, dhl)
                                      : soti_extract_im(idx, p, &s, dhl);
                otinum_t res = deriv ? oti_extract_deriv(idx, p, &d) : oti_extract_im(idx, p, &d);
                otinum_t al = oti_copy(&d);
                int status = deriv ? oti_extract_deriv_to(idx, p, &al, &al)
                                   : oti_extract_im_to(idx, p, &al, &al);
                uint64_t bad = 0;
                ord_t q;
                ndir_t j;

                // The oracle's trc is unspecified above act_order; compare the values only.
                bad += !approx_equal(res.re, ref.re, TOL_ORACLE);

                for (q = 1; q <= res.trc_order; q++){

                    for (j = 0; j < sshelp_ndir_order(3, q); j++){
                        bad += !approx_equal(oti_get_item(j, q, &res), soti_get_item(j, q, &ref, dhl),
                                             TOL_ORACLE);
                    }

                }

                snprintf(ctx, sizeof(ctx), "extract_%s T=%u dir %zu", deriv ? "deriv" : "im",
                    (unsigned)T, i);
                check(bad == 0 && status == DN_OK && same_dn(&al, &res, 0.0) && dn_valid(&res)
                      && res.trc_order == ((p <= T) ? T - p : 0) && res.nact == ((p <= T) ? 3 : 0),
                      ctx);

                soti_free(&ref);
                oti_free(&res);
                oti_free(&al);

            }

        }

        soti_free(&s);
        oti_free(&d);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_trunc_sub(dhelpl_t dhl){

    size_t s;
    ord_t T, o;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        for (s = 0; s < N_SCENS; s++){

            const scen_t* sc = &SCENS[s];
            ord_t t1 = scen_order(sc->t1, T), t2 = scen_order(sc->t2, T);
            sotinum_t s1 = build_soti(sc->k1, t1, scen_order(sc->m1, T), 0.6, 1.3, dhl);
            sotinum_t s2 = build_soti(sc->k2, t2, scen_order(sc->m2, T), 0.6, 0.8, dhl);
            otinum_t d1 = oti_from_soti(&s1, dhl), d2 = oti_from_soti(&s2, dhl);

            for (o = 0; o <= T; o++){

                sotinum_t ref = soti_init();
                otinum_t res = oti_init(), al = oti_copy(&d1);
                int status, st_al;

                soti_trunc_sub_oo_to(o, &s1, &s2, &ref, dhl);
                status = oti_trunc_sub_to(o, &d1, &d2, &res);
                st_al  = oti_trunc_sub_to(o, &al, &d2, &al);

                snprintf(ctx, sizeof(ctx), "trunc_sub T=%u order %u (%s)", (unsigned)T, (unsigned)o,
                    sc->label);
                compare_dn_soti(&res, &ref, 0.0, ctx, dhl);
                check(status == DN_OK && st_al == DN_OK && same_dn(&al, &res, 0.0), "  aliasing");

                soti_free(&ref);
                oti_free(&res);
                oti_free(&al);

            }

            soti_free(&s1);
            soti_free(&s2);
            oti_free(&d1);
            oti_free(&d2);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_rom_eval(dhelpl_t dhl){

    coeff_t gdel[8], pts[5 * 5], out[5], loc[5];
    ord_t T;
    int t, u, ok;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        sotinum_t s = build_soti(5, T, T, 0.7, 0.9, dhl), tay;
        otinum_t d = oti_from_soti(&s, dhl);
        coeff_t val;

        for (u = 0; u < 8; u++){
            gdel[u] = rng_range(-0.3, 0.3);
        }

        tay = soti_taylor_integrate(gdel, &s, dhl);
        val = oti_rom_eval(&d, gdel);
        snprintf(ctx, sizeof(ctx), "rom_eval T=%u (%.17g vs %.17g)", (unsigned)T, val, tay.re);
        check(approx_equal(val, tay.re, 1e-14), ctx);

        for (t = 0; t < 5; t++){

            for (u = 0; u < 5; u++){
                pts[u * 5 + t] = rng_range(-0.3, 0.3);
            }

        }

        ok = oti_rom_eval_points(&d, pts, 5, out) == DN_OK;

        for (t = 0; t < 5; t++){

            for (u = 0; u < 5; u++){
                loc[u] = pts[u * 5 + t];
            }

            ok = ok && approx_equal(out[t], oti_rom_eval(&d, loc), 1e-14);

        }

        snprintf(ctx, sizeof(ctx), "rom_eval_points T=%u", (unsigned)T);
        check(ok, ctx);

        soti_free(&s);
        soti_free(&tay);
        oti_free(&d);

    }

    {
        otinum_t r = oti_create_r(2.5, 3);

        check(oti_rom_eval(&r, NULL) == 2.5 && oti_rom_eval_points(&r, NULL, 5, out) == DN_OK
              && out[4] == 2.5, "rom_eval of a real number");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_global_layouts(dhelpl_t dhl){

    sotinum_t s = build_soti(4, 4, 4, 0.7, 2.0, dhl);
    otinum_t d = oti_from_soti(&s, dhl);
    bases_t nbasis_list[2] = {6, 3};
    ord_t order_list[2] = {4, 2}, p;
    int c, derivs;
    char ctx[160];

    for (c = 0; c < 2; c++){

        bases_t nbasis = nbasis_list[c];
        ord_t order = order_list[c];
        ndir_t ntot = sshelp_ndir_total(nbasis, order) + 1, j, n;
        coeff_t* out = (coeff_t*)malloc(ntot * 2 * sizeof(coeff_t));

        for (derivs = 0; derivs <= 1; derivs++){

            uint64_t bad = 0, pos = 1;

            memset(out, 0, ntot * 2 * sizeof(coeff_t));
            oti_get_all_ims_to(&d, nbasis, order, derivs, out, 2);
            bad += (out[0] != s.re);

            for (p = 1; p <= order; p++){

                n = sshelp_ndir_order(nbasis, p);

                for (j = 0; j < n; j++){

                    coeff_t ref = soti_get_item(j, p, &s, dhl);

                    if (derivs){
                        ref *= dhelp_get_deriv_factor(j, p, dhl);
                    }

                    bad += !approx_equal(out[2 * (pos + j)], ref, 1e-15);

                }

                pos += n;

            }

            snprintf(ctx, sizeof(ctx), "get_all_ims nbasis %u order %u derivs %d", (unsigned)nbasis,
                (unsigned)order, derivs);
            check(bad == 0 && pos == ntot, ctx);

        }

        free(out);

    }

    // Largest base per order, scatter one order and add it back.
    {
        otinum_t e = oti_create_empty(5, 3), fresh = oti_init(), other;
        bases_t g[2] = {2, 4};
        ndir_t width;
        coeff_t* buf;
        sotinum_t part, so, ref;

        oti_set_item(0.5, sshelp_global_rank(g, 2), 2, &e);
        oti_set_item(0.5, 0, 1, &e);
        check(oti_order_max_base(2, &e) == 4 && oti_order_max_base(1, &e) == 1
              && oti_order_max_base(3, &e) == 0, "order_max_base");

        p     = 2;
        width = sshelp_ndir_order(oti_order_max_base(p, &d), p);
        buf   = (coeff_t*)calloc(width, sizeof(coeff_t));
        part  = soti_get_order_im(p, &s, dhl);

        oti_scatter_order_im(p, &d, width, buf, 1);
        check(oti_add_order_im_global(p, buf, width, 1, &fresh) == DN_OK, "add_order_im_global status");
        compare_dn_soti_trc(&fresh, &part, 0.0, "scatter + add_order_im_global round trip", 0, dhl);
        check(fresh.trc_order == 2 && fresh.act_order == 2, "add_order_im_global orders");

        so    = build_soti(2, 1, 1, 0.5, 3.0, dhl);
        other = oti_from_soti(&so, dhl);
        oti_add_order_im_global(p, buf, width, 1, &other);
        ref = soti_sum_oo(&so, &part, dhl);
        compare_dn_soti_trc(&other, &ref, 1e-15, "add_order_im_global into a number", 0, dhl);
        check(other.trc_order == 2 && other.nact == 4, "add_order_im_global raises trc and nact");

        free(buf);
        soti_free(&part);
        soti_free(&so);
        soti_free(&ref);
        oti_free(&e);
        oti_free(&fresh);
        oti_free(&other);
    }

    // A value at a base above 65535.
    {
        coeff_t* big = (coeff_t*)calloc(65536, sizeof(coeff_t));
        otinum_t x = oti_init();

        big[65535] = 1.0;
        check(oti_add_order_im_global(1, big, 65536, 1, &x) == DN_ERR_INDEX,
              "add_order_im_global base 65536 gives DN_ERR_INDEX");
        oti_free(&x);
        free(big);
    }

    soti_free(&s);
    oti_free(&d);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     K = 11 FALLBACK AND THREADS     -----------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Naive product of two dense numbers: every pair of directions, ranked from the merged labels. */
static otinum_t naive_mul(const otinum_t* a, const otinum_t* b){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact, u[16], v[16], w[32];
    ord_t trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order, p, q, t;
    otinum_t r = oti_create_empty(k, trc);
    ndir_t i, j;

    r.re = a->re * b->re;

    for (p = 0; p <= a->act_order; p++){

        for (q = 0; q <= b->act_order && p + q <= trc; q++){

            ndir_t Np = sshelp_ndir_order(a->nact, p), Nq = sshelp_ndir_order(b->nact, q);

            if (p + q == 0){
                continue;
            }

            for (i = 0; i < Np; i++){

                coeff_t ca = (p == 0) ? a->re : a->p_im[sshelp_order_offset(a->nact, p) + i];

                sshelp_unrank(i, p, u);

                for (j = 0; j < Nq; j++){

                    coeff_t cb = (q == 0) ? b->re : b->p_im[sshelp_order_offset(b->nact, q) + j];
                    ord_t x = 0, y = 0;

                    sshelp_unrank(j, q, v);

                    for (t = 0; t < p + q; t++){

                        if (y == q || (x < p && u[x] <= v[y])){
                            w[t] = (bases_t)(u[x++] + 1);
                        } else {
                            w[t] = (bases_t)(v[y++] + 1);
                        }

                    }

                    r.p_im[sshelp_order_offset(k, (ord_t)(p + q)) + sshelp_global_rank(w, p + q)]
                        += ca * cb;

                }

            }

        }

    }

    r.act_order = trc;

    return r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* nact = 11 at order 5 (Nbasis(5) = 10): the product kernel leaves the global table. Checked against
 * a naive product and semi-sparse, same and mixed nact, a function and a division. */
static void test_fallback(dhelpl_t dhl, const char* mode){

    otinum_t a = build_dense_direct(11, 5, 5, 1.2), b = build_dense_direct(11, 5, 5, -0.7);
    otinum_t c = build_dense_direct(7, 3, 3, 0.9), r = oti_init(), n = oti_init();
    ssotinum_t qa = ss_from_dense(&a), qb = ss_from_dense(&b), qc = ss_from_dense(&c);
    ssotinum_t qr = ssoti_init();
    char ctx[160];

    oti_mul_oo_to(&a, &b, &r, dhl);
    n = naive_mul(&a, &b);
    ssoti_mul_oo_to(&qa, &qb, &qr, dhl);
    snprintf(ctx, sizeof(ctx), "k=11 order 5 product vs naive (%s)", mode);
    check(same_dn(&r, &n, TOL_ORACLE), ctx);
    snprintf(ctx, sizeof(ctx), "k=11 order 5 product (%s)", mode);
    compare_dn_ss(&r, &qr, TOL_SS, ctx);
    oti_free(&n);

    oti_mul_oo_to(&c, &a, &r, dhl);
    n = naive_mul(&c, &a);
    ssoti_mul_oo_to(&qc, &qa, &qr, dhl);
    snprintf(ctx, sizeof(ctx), "k=7 x k=11 mixed product vs naive (%s)", mode);
    check(same_dn(&r, &n, TOL_ORACLE) && r.nact == 11 && r.trc_order == 5, ctx);
    snprintf(ctx, sizeof(ctx), "k=7 x k=11 mixed product (%s)", mode);
    compare_dn_ss(&r, &qr, TOL_SS, ctx);
    oti_free(&n);

    oti_exp_to(&a, &r, dhl);
    ssoti_exp_to(&qa, &qr, dhl);
    snprintf(ctx, sizeof(ctx), "k=11 order 5 exp (%s)", mode);
    compare_dn_ss(&r, &qr, TOL_SS, ctx);

    oti_div_oo_to(&c, &b, &r, dhl);
    ssoti_div_oo_to(&qc, &qb, &qr, dhl);
    snprintf(ctx, sizeof(ctx), "k=7 / k=11 division (%s)", mode);
    compare_dn_ss(&r, &qr, TOL_SS, ctx);

    oti_free(&a);
    oti_free(&b);
    oti_free(&c);
    oti_free(&r);
    ssoti_free(&qa);
    ssoti_free(&qb);
    ssoti_free(&qc);
    ssoti_free(&qr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Numbers above _MAXORDER_OTI: oti_create_r gives the NaN sentinel, and a hand-built number (which
 * the API cannot create) is rejected with DN_ERR_INDEX by every function before its derivative list
 * (sized _MAXORDER_OTI + 1) is written; oti_to_soti gives an empty number with re = NaN. */
static void test_max_order_guards(dhelpl_t dhl){

    otinum_t x = oti_create_r(0.5, 151), r = oti_init();
    coeff_t derivs[4] = {1.0, 1.0, 1.0, 1.0};
    sotinum_t so;
    size_t f;
    int ok = 1;

    check(isnan(x.re) && x.trc_order == 0 && x.p_im == NULL, "create_r trc 151: NaN sentinel");
    x = oti_create_r(0.5, 150);
    check(x.re == 0.5 && x.trc_order == 150, "create_r trc 150 works");

    // Hand-built: no buffer is needed for a real number, so nothing else stops it.
    x.trc_order = 200;

    for (f = 0; f < N_F_OPS; f++){
        ok = ok && F_OPS[f].dn(&x, &r, dhl) == DN_ERR_INDEX;
    }

    ok = ok && oti_pow_to(&x, 2.5, &r, dhl) == DN_ERR_INDEX && oti_logb_to(&x, 3.0, &r, dhl)
         == DN_ERR_INDEX && oti_feval_to(derivs, &x, &r, dhl) == DN_ERR_INDEX
         && oti_div_ro_to(1.0, &x, &r, dhl) == DN_ERR_INDEX && oti_div_oo_to(&x, &x, &r, dhl)
         == DN_ERR_INDEX && oti_copy_to(&x, &r) == DN_ERR_INDEX;
    check(ok, "a trc 200 number: every function returns DN_ERR_INDEX");

    so = oti_to_soti(&x, dhl);
    check(isnan(so.re) && so.p_im == NULL, "to_soti of a trc 200 number: empty, re = NaN");
    soti_free(&so);
    oti_free(&r);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Independent scalar chains (products with aliasing, functions in place, division, gem in place,
 * sums) from an omp parallel for give bitwise the serial results: the thread-local workspace and
 * its 64 KiB coefficient scratch are per thread. */
static void test_concurrency(dhelpl_t dhl){

#ifdef _OPENMP
    enum { NCHAIN = 256 };
    otinum_t *a = (otinum_t*)malloc(NCHAIN * sizeof(otinum_t));
    otinum_t *ser = (otinum_t*)malloc(NCHAIN * sizeof(otinum_t));
    otinum_t *par = (otinum_t*)malloc(NCHAIN * sizeof(otinum_t));
    int i, pass, ok = 1;

    for (i = 0; i < NCHAIN; i++){

        // Mixed sizes: small ones use the workspace scratch, k = 11 at order 5 goes past 64 KiB
        // in feval (3 x 4367 coefficients) and the table cache.
        bases_t k = (bases_t)((i % 4 == 0) ? 11 : i % 6 + 1);
        ord_t trc = (ord_t)((i % 4 == 0) ? 5 : i % 5 + 1);

        a[i]   = build_dense_direct(k, trc, trc, 0.5 + 0.01 * i);
        ser[i] = oti_init();
        par[i] = oti_init();

    }

    for (pass = 0; pass < 2; pass++){

        otinum_t* out = (pass == 0) ? ser : par;

        #pragma omp parallel for schedule(dynamic, 1) num_threads(8) if (pass == 1)
        for (i = 0; i < NCHAIN; i++){

            otinum_t t = oti_init(), u = oti_init();

            oti_mul_oo_to(&a[i], &a[(i + 1) % NCHAIN], &t, dhl);
            oti_mul_oo_to(&t, &a[i], &t, dhl);
            oti_exp_to(&t, &t, dhl);
            oti_div_oo_to(&t, &a[i], &u, dhl);
            oti_gem_oo_to(&u, &a[(i + 3) % NCHAIN], &t, &t, dhl);
            oti_sum_oo_to(&t, &u, &out[i], dhl);
            oti_free(&t);
            oti_free(&u);

            // Pool threads keep their workspace between calls; release it before they idle.
            oti_ws_release();

        }

    }

    for (i = 0; i < NCHAIN; i++){

        ndir_t j, n = sshelp_ndir_total(ser[i].nact, ser[i].trc_order);

        ok = ok && ser[i].re == par[i].re && ser[i].nact == par[i].nact
             && ser[i].trc_order == par[i].trc_order && ser[i].act_order == par[i].act_order;

        for (j = 0; ok && j < n; j++){
            ok = ser[i].p_im[j] == par[i].p_im[j];
        }

        oti_free(&a[i]);
        oti_free(&ser[i]);
        oti_free(&par[i]);

    }

    free(a);
    free(ser);
    free(par);
    check(ok, "256 scalar chains on 8 threads: bitwise equal to serial");
#else
    (void)dhl;
    printf("skipped: concurrency (no OpenMP)\n");
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The same products, functions and conversions on 1 and on N threads give identical results. */
static void test_threads(dhelpl_t dhl){

#ifdef _OPENMP
    enum { NCASE = 16 };
    otinum_t a[NCASE], b[NCASE], r1[NCASE], rn[NCASE];
    int i, nt, ok = 1;

    for (i = 0; i < NCASE; i++){

        bases_t k = (bases_t)((i % 2 == 0) ? 11 : 4);

        a[i]  = build_dense_direct(k, 5, 5, 0.5);
        b[i]  = build_dense_direct((bases_t)(i % 5 + 1), (ord_t)(i % 5 + 1), (ord_t)(i % 5 + 1), 1.5);
        r1[i] = oti_init();
        rn[i] = oti_init();

    }

    for (nt = 0; nt < 2; nt++){

        otinum_t* r = (nt == 0) ? r1 : rn;

        omp_set_num_threads((nt == 0) ? 1 : 4);

        #pragma omp parallel for schedule(dynamic, 1)
        for (i = 0; i < NCASE; i++){

            otinum_t t = oti_init();

            oti_mul_oo_to(&a[i], &b[i], &t, dhl);
            oti_sin_to(&t, &t, dhl);
            oti_div_oo_to(&t, &b[i], &r[i], dhl);
            oti_gem_oo_to(&a[i], &r[i], &b[i], &r[i], dhl);
            oti_free(&t);
            oti_ws_release();

        }

    }

    for (i = 0; i < NCASE; i++){

        ok = ok && same_dn(&r1[i], &rn[i], 0.0);
        oti_free(&a[i]);
        oti_free(&b[i]);
        oti_free(&r1[i]);
        oti_free(&rn[i]);

    }

    check(ok, "1 vs 4 threads give identical results");
#else
    (void)dhl;
    printf("skipped: threads (no OpenMP)\n");
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Argument and result of one short-lived worker thread. */
typedef struct {
    dhelpl_t dhl;   ///< Direction helper list (read-only tables).
    int    status;  ///< OR of the statuses of the calls.
    coeff_t value;  ///< Real part of the result.
} thread_job_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A worker that uses the dense scalar operations (so its thread-local workspace gets allocated) and
 * exits without releasing it: the thread-exit destructor of the workspace must. */
static void* short_lived_worker(void* p_arg){

    thread_job_t* job = (thread_job_t*)p_arg;
    otinum_t a = build_dense_direct(5, 4, 4, 0.5), t = oti_init();

    job->status  = oti_sum_oo_to(&a, &a, &t, job->dhl);
    job->status |= oti_mul_oo_to(&t, &t, &t, job->dhl);       // aliased: goes through the scratch.
    job->status |= oti_exp_to(&t, &t, job->dhl);              // in place, feval scratch.
    job->value   = t.re;

    oti_free(&a);
    oti_free(&t);

    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Many short-lived pthreads each use the workspace and exit: every thread must give the serial result,
 * and `leaks --atExit` must report nothing (the destructor releases each thread's workspace; without
 * it 200 threads leaked 76800 bytes). */
static void test_short_lived_threads(dhelpl_t dhl){

    enum { NTHREADS = 200, BATCH = 8 };
    pthread_t threads[BATCH];
    thread_job_t jobs[NTHREADS];
    thread_job_t reference;
    int i, j, ok = 1, created;

    reference.dhl = dhl;
    short_lived_worker(&reference);

    for (i = 0; i < NTHREADS; i += BATCH){

        created = 0;

        for (j = 0; j < BATCH && i + j < NTHREADS; j++){

            jobs[i + j].dhl    = dhl;
            jobs[i + j].status = -99;
            ok = ok && pthread_create(&threads[j], NULL, short_lived_worker, &jobs[i + j]) == 0;
            created++;

        }

        for (j = 0; j < created; j++){
            pthread_join(threads[j], NULL);
        }

    }

    for (i = 0; i < NTHREADS; i++){
        ok = ok && jobs[i].status == DN_OK && jobs[i].value == reference.value;
    }

    check(ok && reference.status == DN_OK, "200 short-lived threads give the serial result");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;
    int status = 0;

    dhelp_load(NULL, &dhl);

    if (argc > 1 && strcmp(argv[1], "--fallback") == 0){

        test_fallback(dhl, "no table cache");

    } else if (argc > 1 && strcmp(argv[1], "--budget") == 0){

        test_budget_child(dhl);

    } else {

        test_memory();
        test_limits(dhl);
        test_conversions(dhl);
        test_access(dhl);
        test_binary(dhl);
        test_allocating_and_act(dhl);
        test_gem(dhl);
        test_real_variants(dhl);
        test_kernels(dhl);
        test_functions(dhl);
        test_truncation(dhl);
        test_compact(dhl);
        test_extract(dhl);
        test_trunc_sub(dhl);
        test_rom_eval(dhl);
        test_global_layouts(dhl);
        test_fallback(dhl, "table cache");
        test_threads(dhl);
        test_concurrency(dhl);
        test_short_lived_threads(dhl);
        test_max_order_guards(dhl);
        test_budget(dhl);

        // The k = 11 tests again without the local-table cache: the rank fallback path.
        if (getenv("OTI_SS_TABLE_CACHE_MB") == NULL){

            char cmd[4096];

            snprintf(cmd, sizeof(cmd), "OTI_SS_TABLE_CACHE_MB=0 '%s' --fallback", argv[0]);
            status = system(cmd);
            check(status == 0, "k = 11 tests without the table cache (child run)");

        }

        // The byte budget again with OTI_DENSE_MAX_MB=1 (it is read once per process).
        if (getenv("OTI_DENSE_MAX_MB") == NULL){

            char cmd[4096];

            snprintf(cmd, sizeof(cmd), "OTI_DENSE_MAX_MB=1 '%s' --budget", argv[0]);
            fflush(stdout);
            status = system(cmd);
            check(status == 0, "byte budget with OTI_DENSE_MAX_MB=1 (child run)");

        }

    }

    oti_ws_release();
    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d dense scalar test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C dense scalar tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
