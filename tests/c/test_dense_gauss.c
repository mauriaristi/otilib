/* Checks of the dense Gauss-point types (include/oti/dense/gauss/gauss.h, PLAN-dense-update.md, WP6).
 * Oracles: per point, the plain oarr_t result of the same operation (itself checked against arrso_t in
 * test_dense_soa.c; the matrix product is also checked here against arrso_t through the conversions),
 * and the semi-sparse feoarrss_t over [1..k] built from the same data, whose arr.p_data must match
 * the dense one (1e-14; 1e-12 where both sides go through an LU). Orders 1 to 5, nip in {1, 4, 9}.
 *
 * Run without arguments it runs everything, then runs itself again with OTI_SS_TABLE_CACHE_MB=0 and
 * the argument --fallback, which only runs the k = 11 tests (rank fallback of the product kernels). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>

#define TOL      1e-13
#define TOL_SS   1e-14
#define TOL_LU   1e-12

static int n_failed = 0;
static uint64_t g_rng_state = 0xD37A20260929ULL;
static const uint64_t NIPS[3] = {1, 4, 9};


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

    return fabs(a - b) <= tol * fmax(1.0, fmax(fabs(a), fabs(b)));

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Fills the blocks of orders 0..maxorder of an array with random values; `diag` is added to the real
 * part of every diagonal entry of each point's matrix (rows x cols, nip points fastest; nip = 1 for
 * a plain array). */
static void fill_random(oarr_t* a, uint64_t rows, uint64_t nip, ord_t maxorder, coeff_t diag){

    uint64_t nb = 1 + sshelp_ndir_total(a->nact, maxorder), e, i, t;

    for (e = 0; e < nb * a->size; e++){
        a->p_data[e] = rng_range(-0.4, 0.4);
    }

    for (i = 0; i < rows && i * rows + i < a->size / nip; i++){

        for (t = 0; t < nip; t++){
            a->p_data[(i + i * rows) * nip + t] += diag;
        }

    }

    a->act_order = (a->nact == 0) ? 0 : maxorder;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static oarr_t build_oarr(uint64_t nrows, uint64_t ncols, bases_t k, ord_t trc, ord_t maxorder,
                         coeff_t diag){

    oarr_t a = oarr_init();

    oarr_zeros_to(k, nrows, ncols, trc, &a);
    fill_random(&a, (nrows == ncols) ? nrows : 0, 1, maxorder, diag);

    return a;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static feoarr_t build_fe(uint64_t nrows, uint64_t ncols, uint64_t nip, bases_t k, ord_t trc,
                         ord_t maxorder, coeff_t diag){

    feoarr_t fe = fearr_init();

    fearr_zeros_to(k, nrows, ncols, nip, trc, &fe);
    fill_random(&fe.arr, (nrows == ncols) ? nrows : 0, nip, maxorder, diag);

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The semi-sparse array over [1..k] with the same blocks. */
static oarrss_t ss_from_oarr(const oarr_t* a){

    bases_t b[256], i;
    oarrss_t s;

    for (i = 0; i < a->nact; i++){
        b[i] = (bases_t)(i + 1);
    }

    s = oarrss_zeros(b, a->nact, a->nrows, a->ncols, a->trc_order);
    memcpy(s.p_data, a->p_data, (1 + sshelp_ndir_total(a->nact, a->trc_order)) * a->size
        * sizeof(coeff_t));
    s.act_order = a->act_order;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static feoarrss_t ss_from_fe(const feoarr_t* fe){

    feoarrss_t s = feoarrss_init();

    s.arr   = ss_from_oarr(&fe->arr);
    s.nrows = fe->nrows;
    s.ncols = fe->ncols;
    s.nip   = fe->nip;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESSES     ------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Value of element e of the direction (order p, index i) of an array; 0 outside its layout. */
static coeff_t oarr_val(const oarr_t* a, ord_t p, ndir_t i, uint64_t e){

    if (p > a->trc_order || i >= sshelp_ndir_order(a->nact, p)){
        return 0.0;
    }

    return a->p_data[oarr_block_index(a->nact, p, i) * a->size + e];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Structural invariants: act_order <= trc_order, blocks above act_order are zero. */
static int oarr_valid(const oarr_t* a){

    uint64_t start, end, e;
    int ok = a->act_order <= a->trc_order && a->nbases >= a->nact && a->size == a->nrows * a->ncols;

    if (a->nact == 0){
        return ok;
    }

    start = (1 + sshelp_order_offset(a->nact, (ord_t)(a->act_order + 1))) * a->size;
    end   = (1 + sshelp_ndir_total(a->nact, a->trc_order)) * a->size;

    for (e = start; e < end; e++){
        ok = ok && a->p_data[e] == 0.0;
    }

    return ok;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Two plain arrays through global directions (layouts may differ): shape, trc and every value. */
static int same_oarr(const oarr_t* a, const oarr_t* b, double tol){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t p, trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order;
    ndir_t i, n;
    uint64_t e;
    int ok = a->nrows == b->nrows && a->ncols == b->ncols && a->trc_order == b->trc_order
             && oarr_valid(a) && oarr_valid(b);

    for (p = 0; ok && p <= trc; p++){

        n = sshelp_ndir_order(k, p);

        for (i = 0; ok && i < n; i++){

            for (e = 0; ok && e < a->size; e++){
                ok = approx_equal(oarr_val(a, p, i, e), oarr_val(b, p, i, e), tol);
            }

        }

    }

    return ok;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Every point of a Gauss result against the plain array expected there (oracle[ip]). */
static int fe_matches_points(const feoarr_t* fe, const oarr_t* oracle, double tol){

    oarr_t P = oarr_init();
    uint64_t ip;
    int ok = oarr_valid(&fe->arr) && fe->arr.nrows == fe->nip
             && fe->arr.ncols == fe->nrows * fe->ncols;

    for (ip = 0; ok && ip < fe->nip; ip++){
        ok = fearr_get_ip_to(ip, fe, &P) == DN_OK && same_oarr(&P, &oracle[ip], tol);
    }

    oarr_free(&P);

    return ok;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense Gauss array against the semi-sparse one over [1..nact]: identical layout and p_data. */
static int fe_matches_ss(const feoarr_t* fe, const feoarrss_t* s, double tol){

    uint64_t n, e;
    bases_t i;
    int ok = fe->arr.nact == s->arr.nbases && fe->arr.trc_order == s->arr.trc_order
             && fe->nrows == s->nrows && fe->ncols == s->ncols && fe->nip == s->nip
             && fe->arr.size == s->arr.size;

    for (i = 0; ok && i < s->arr.nbases; i++){
        ok = s->arr.p_bases[i] == i + 1;
    }

    n = ok ? (1 + sshelp_ndir_total(fe->arr.nact, fe->arr.trc_order)) * fe->arr.size : 0;

    for (e = 0; ok && e < n; e++){
        ok = approx_equal(fe->arr.p_data[e], s->arr.p_data[e], tol);
    }

    return ok;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The matrix of every point of a Gauss array (points[ip], released by free_points()). */
static oarr_t* get_points(const feoarr_t* fe){

    oarr_t* pts = (oarr_t*)malloc((fe->nip + 1) * sizeof(oarr_t));
    uint64_t ip;

    for (ip = 0; ip < fe->nip; ip++){

        pts[ip] = oarr_init();
        fearr_get_ip_to(ip, fe, &pts[ip]);

    }

    return pts;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void free_points(oarr_t* pts, uint64_t nip){

    uint64_t ip;

    for (ip = 0; ip < nip; ip++){
        oarr_free(&pts[ip]);
    }

    free(pts);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MEMORY AND ACCESS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_memory(dhelpl_t dhl){

    feoarr_t a = build_fe(2, 3, 4, 3, 3, 3, 0.0), b = fearr_init(), z = fearr_init();
    oarr_t* pa = get_points(&a);
    oarr_t P = oarr_init();
    int ok;

    check(fearr_zeros_to(2, 3, 2, 4, 2, &z) == DN_OK && z.nrows == 3 && z.ncols == 2 && z.nip == 4
          && z.arr.nrows == 4 && z.arr.ncols == 6 && z.arr.nact == 2 && z.arr.act_order == 0,
          "zeros_to shape");
    check(fearr_zeros_to(65535, 1000, 1000, 1000, 20, &z) == DN_ERR_MEMORY, "zeros_to oversized");
    check(fearr_zeros_to(1, 1, 1, 1, 151, &z) == DN_ERR_INDEX, "zeros_to trc 151");

    check(fearr_copy_to(&a, &b) == DN_OK && fe_matches_points(&b, pa, 0.0) && fearr_copy_to(&b, &b) == 0,
          "copy_to, and onto itself");

    // Growing keeps every value (zero-extension).
    check(fearr_grow(5, 5, &b) == DN_OK && b.arr.nact == 5 && b.arr.trc_order == 5, "grow layout");
    ok = 1;

    {
        uint64_t ip;

        for (ip = 0; ip < 4; ip++){

            oarr_t e = oarr_init();

            fearr_get_ip_to(ip, &b, &P);
            oarr_copy_to(&pa[ip], &e);
            oarr_reserve(&e, 5, 2, 3, 5);
            oarr_add_bases(5, &e);
            ok = ok && P.nact == 5 && same_oarr(&P, &e, 0.0);
            oarr_free(&e);

        }
    }

    check(ok, "grow keeps the values");

    check(fearr_set_shape(3, 2, 4, &b) == DN_OK && b.nrows == 3 && b.ncols == 2, "set_shape");
    check(fearr_set_shape(4, 2, 4, &b) == DN_ERR_SIZE, "set_shape mismatch gives DN_ERR_SIZE");
    check(fearr_get_ip_to(4, &a, &P) == DN_ERR_INDEX, "get_ip out of range");

    fearr_free(&a);
    fearr_free(&b);
    fearr_free(&z);
    fearr_free(&z);
    free_points(pa, 4);
    oarr_free(&P);
    check(a.arr.p_data == NULL && a.nip == 0, "free resets");
    (void)dhl;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_set_ip_ijk(dhelpl_t dhl){

    feoarr_t fe = build_fe(2, 2, 4, 2, 2, 2, 0.0);
    oarr_t* before = get_points(&fe);
    oarr_t v = build_oarr(2, 2, 4, 3, 3, 0.0), P = oarr_init(), bad = build_oarr(2, 3, 1, 1, 1, 0.0);
    otinum_t num = oti_e(5, 1, 4);
    uint64_t ip;
    int ok = 1;

    // Point 1 gets a value with larger nact and trc; the others keep theirs, zero-extended.
    check(fearr_set_ip(&v, 1, &fe) == DN_OK && fe.arr.nact == 4 && fe.arr.trc_order == 3
          && fe.arr.act_order == 3, "set_ip grows nact, trc and act");

    for (ip = 0; ip < 4; ip++){

        fearr_get_ip_to(ip, &fe, &P);

        if (ip == 1){
            ok = ok && same_oarr(&P, &v, 0.0);
        } else {
            oarr_reserve(&before[ip], 4, 2, 2, 3);
            oarr_add_bases(4, &before[ip]);
            ok = ok && same_oarr(&P, &before[ip], 0.0);
        }

    }

    check(ok, "set_ip writes one point only");
    check(fearr_set_ip(&bad, 0, &fe) == DN_ERR_SIZE, "set_ip shape mismatch");
    check(fearr_set_ip(&v, 4, &fe) == DN_ERR_INDEX, "set_ip point out of range");

    // A smaller value overwrites every direction of the point (the others become zero).
    {
        oarr_t s = build_oarr(2, 2, 1, 1, 1, 0.0), e = oarr_init();

        fearr_set_ip(&s, 2, &fe);
        fearr_get_ip_to(2, &fe, &P);
        oarr_copy_to(&s, &e);
        oarr_reserve(&e, 4, 2, 2, 3);
        oarr_add_bases(4, &e);
        check(same_oarr(&P, &e, 0.0), "set_ip of a smaller value clears the other directions");
        oarr_free(&s);
        oarr_free(&e);
    }

    // Single entries.
    num.re = 2.0;
    check(fearr_set_ijk_o(&num, 1, 0, 3, &fe) == DN_OK && fe.arr.nact == 6 && fe.arr.trc_order == 4,
          "set_ijk_o grows nact and trc");
    fearr_get_ip_to(3, &fe, &P);
    check(oarr_val(&P, 0, 0, 1) == 2.0 && oarr_val(&P, 1, 5, 1) == 1.0 && oarr_val(&P, 1, 0, 1) == 0.0,
          "set_ijk_o value");
    check(fearr_set_ijk_r(7.0, 0, 1, 0, &fe) == DN_OK, "set_ijk_r status");
    fearr_get_ip_to(0, &fe, &P);
    check(oarr_val(&P, 0, 0, 2) == 7.0 && oarr_val(&P, 1, 0, 2) == 0.0 && oarr_val(&P, 1, 1, 2) == 0.0,
          "set_ijk_r clears the imaginary slots");
    check(fearr_set_ijk_r(1.0, 2, 0, 0, &fe) == DN_ERR_INDEX && fearr_set_ijk_o(&num, 0, 0, 4, &fe)
          == DN_ERR_INDEX, "set_ijk out of range");

    fearr_free(&fe);
    free_points(before, 4);
    oarr_free(&v);
    oarr_free(&P);
    oarr_free(&bad);
    oti_free(&num);
    (void)dhl;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_slices(dhelpl_t dhl){

    static const struct { uint64_t i0, ni; int64_t is; uint64_t j0, nj; int64_t js; } S[] = {
        {0, 4, 1, 0, 3, 1}, {3, 2, -2, 2, 3, -1}, {1, 2, 1, 0, 2, 2}, {3, 4, -1, 1, 1, 1},
        {2, 1, 1, 2, 1, 1}
    };
    size_t s;
    ord_t T;
    char ctx[128];

    for (T = 1; T <= 5; T += 2){

        feoarr_t fe = build_fe(4, 3, 4, 3, T, T, 0.0);
        oarr_t* pts = get_points(&fe);

        for (s = 0; s < sizeof(S) / sizeof(S[0]); s++){

            feoarr_t sl = fearr_init(), dst = fearr_init();
            feoarr_t val = build_fe(S[s].ni, S[s].nj, 4, 5, (ord_t)(T + 1 > 5 ? 5 : T + 1), 2, 0.0);
            oarr_t* vpts = get_points(&val);
            oarr_t P = oarr_init(), Q = oarr_init();
            uint64_t ip, ii, jj;
            int ok, st;

            fearr_copy_to(&fe, &dst);

            st = fearr_get_slice_to(&fe, S[s].i0, S[s].ni, S[s].is, S[s].j0, S[s].nj, S[s].js, &sl);
            ok = st == DN_OK && sl.nrows == S[s].ni && sl.ncols == S[s].nj && sl.nip == 4;

            for (ip = 0; ok && ip < 4; ip++){

                fearr_get_ip_to(ip, &sl, &P);

                for (jj = 0; jj < S[s].nj; jj++){

                    for (ii = 0; ii < S[s].ni; ii++){

                        uint64_t i = (uint64_t)((int64_t)S[s].i0 + (int64_t)ii * S[s].is);
                        uint64_t j = (uint64_t)((int64_t)S[s].j0 + (int64_t)jj * S[s].js);
                        ord_t p;
                        ndir_t d;

                        for (p = 0; p <= T; p++){

                            for (d = 0; d < sshelp_ndir_order(3, p); d++){
                                ok = ok && oarr_val(&P, p, d, ii + jj * S[s].ni)
                                           == oarr_val(&pts[ip], p, d, i + j * 4);
                            }

                        }

                    }

                }

            }

            snprintf(ctx, sizeof(ctx), "get_slice T=%u case %zu", (unsigned)T, s);
            check(ok, ctx);

            // Set the slice from a larger layout: the block takes val's values, the rest is kept.
            st = fearr_set_slice(&val, S[s].i0, S[s].ni, S[s].is, S[s].j0, S[s].nj, S[s].js, &dst);
            ok = st == DN_OK && dst.arr.nact == 5 && dst.arr.trc_order == val.arr.trc_order;

            for (ip = 0; ok && ip < 4; ip++){

                oarr_t E = oarr_init();

                oarr_copy_to(&pts[ip], &E);
                oarr_reserve(&E, 5, 4, 3, val.arr.trc_order);
                oarr_add_bases(5, &E);

                for (jj = 0; jj < S[s].nj; jj++){

                    for (ii = 0; ii < S[s].ni; ii++){

                        uint64_t i = (uint64_t)((int64_t)S[s].i0 + (int64_t)ii * S[s].is);
                        uint64_t j = (uint64_t)((int64_t)S[s].j0 + (int64_t)jj * S[s].js);
                        otinum_t x = oti_init();

                        oarr_get_item_to(ii, jj, &vpts[ip], &x);
                        oarr_set_item(&x, i, j, &E);
                        oti_free(&x);

                    }

                }

                fearr_get_ip_to(ip, &dst, &Q);
                ok = ok && same_oarr(&Q, &E, 0.0);
                oarr_free(&E);

            }

            snprintf(ctx, sizeof(ctx), "set_slice T=%u case %zu", (unsigned)T, s);
            check(ok, ctx);

            fearr_free(&sl);
            fearr_free(&dst);
            fearr_free(&val);
            free_points(vpts, 4);
            oarr_free(&P);
            oarr_free(&Q);

        }

        // Broadcast of a 1 x 1 value into a block, and the error cases.
        {
            feoarr_t one = build_fe(1, 1, 4, 2, T, T, 0.0), dst = fearr_init(), bad = fearr_init();
            oarr_t P = oarr_init(), O = oarr_init();
            uint64_t ip;
            int ok;

            fearr_copy_to(&fe, &dst);
            ok = fearr_set_slice(&one, 3, 2, -1, 0, 3, 1, &dst) == DN_OK;

            for (ip = 0; ok && ip < 4; ip++){

                otinum_t a = oti_init(), b = oti_init();

                fearr_get_ip_to(ip, &dst, &P);
                fearr_get_ip_to(ip, &one, &O);
                oarr_get_item_to(0, 0, &O, &b);
                oarr_get_item_to(2, 1, &P, &a);
                ok = ok && oti_get_item(0, 0, &a) == b.re
                     && oti_get_item(1, 1, &a) == oti_get_item(1, 1, &b);
                oti_free(&a);
                oti_free(&b);

            }

            snprintf(ctx, sizeof(ctx), "set_slice broadcast T=%u", (unsigned)T);
            check(ok, ctx);

            check(fearr_get_slice_to(&fe, 0, 5, 1, 0, 1, 1, &bad) == DN_ERR_INDEX
                  && fearr_get_slice_to(&fe, 0, 1, 1, 0, 1, 1, &fe) == DN_ERR_ARGUMENT
                  && fearr_set_slice(&dst, 0, 1, 1, 0, 1, 1, &dst) == DN_ERR_ARGUMENT
                  && fearr_set_slice(&fe, 0, 2, 1, 0, 2, 1, &dst) == DN_ERR_SIZE,
                  "slice errors: index, aliasing, shape");

            // Ranges are checked before the column list is allocated, with overflow guards.
            check(fearr_get_slice_to(&fe, 0, 1ULL << 61, 1, 0, 1, 1, &bad) == DN_ERR_INDEX
                  && fearr_get_slice_to(&fe, 0, 1ULL << 40, 1, 0, 1, 1, &bad) == DN_ERR_INDEX
                  && fearr_get_slice_to(&fe, 3, 2, INT64_MIN, 0, 1, 1, &bad) == DN_ERR_INDEX
                  && fearr_get_slice_to(&fe, 0, 2, INT64_MAX, 0, 1, 1, &bad) == DN_ERR_INDEX
                  && fearr_get_slice_to(&fe, 3, 5, -1, 0, 1, 1, &bad) == DN_ERR_INDEX,
                  "slice ranges: out of range (huge length, extreme steps) -> DN_ERR_INDEX");
            check(fearr_get_slice_to(&fe, 3, 4, -1, 2, 3, -1, &bad) == DN_OK && bad.nrows == 4
                  && bad.ncols == 3 && fearr_get_slice_to(&fe, 1, 3, 0, 0, 1, 1, &bad) == DN_OK
                  && bad.nrows == 3, "slice ranges: exact fit with negative and zero steps");

            // An empty assignment changes nothing, not even the layout.
            {
                feoarr_t empty = build_fe(0, 3, 4, 6, 5, 5, 0.0);
                bases_t k0 = dst.arr.nact;
                ord_t t0 = dst.arr.trc_order, a0 = dst.arr.act_order;

                check(fearr_set_slice(&empty, 0, 0, 1, 0, 3, 1, &dst) == DN_OK && dst.arr.nact == k0
                      && dst.arr.trc_order == t0 && dst.arr.act_order == a0,
                      "empty set_slice: no change");
                fearr_free(&empty);
            }

            fearr_free(&one);
            fearr_free(&dst);
            fearr_free(&bad);
            oarr_free(&P);
            oarr_free(&O);
        }

        fearr_free(&fe);
        free_points(pts, 4);

    }

    (void)dhl;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_broadcasts(dhelpl_t dhl){

    oarr_t a = build_oarr(2, 3, 3, 3, 3, 0.0), P = oarr_init();
    feoarr_t fe = fearr_init(), one = build_fe(1, 1, 4, 2, 2, 2, 0.0), bc = fearr_init();
    oarr_t* opts = get_points(&one);
    uint64_t ip, e;
    int ok;

    ok = fearr_from_oarr_to(&a, 9, &fe) == DN_OK && fe.nrows == 2 && fe.ncols == 3 && fe.nip == 9;

    for (ip = 0; ok && ip < 9; ip++){
        ok = fearr_get_ip_to(ip, &fe, &P) == DN_OK && same_oarr(&P, &a, 0.0);
    }

    check(ok, "from_oarr repeats the array at every point");

    ok = fearr_bcast_to(&one, 3, 2, &bc) == DN_OK && bc.nrows == 3 && bc.ncols == 2 && bc.nip == 4;

    for (ip = 0; ok && ip < 4; ip++){

        fearr_get_ip_to(ip, &bc, &P);

        for (e = 0; e < 6; e++){

            ord_t p;
            ndir_t d;

            for (p = 0; p <= 2; p++){

                for (d = 0; d < sshelp_ndir_order(2, p); d++){
                    ok = ok && oarr_val(&P, p, d, e) == oarr_val(&opts[ip], p, d, 0);
                }

            }

        }

    }

    check(ok, "bcast repeats a Gauss scalar over the matrix");
    check(fearr_bcast_to(&fe, 2, 2, &bc) == DN_ERR_SIZE && fearr_bcast_to(&one, 2, 2, &one)
          == DN_ERR_ARGUMENT, "bcast errors");

    oarr_free(&a);
    oarr_free(&P);
    fearr_free(&fe);
    fearr_free(&one);
    fearr_free(&bc);
    free_points(opts, 4);
    (void)dhl;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     LINEAR ALGEBRA     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct { bases_t ka; int ta; int ma; bases_t kb; int tb; int mb; const char* label; } scen_t;

#define ORD_T  (-1)
#define ORD_L  (-2)

static const scen_t SCENS[] = {
    { 3, ORD_T, ORD_T,  3, ORD_T, ORD_T, "equal nact" },
    { 2, ORD_T, ORD_T,  4, ORD_T, ORD_T, "smaller nact left" },
    { 4, ORD_T, ORD_T,  2, ORD_L, ORD_L, "smaller nact and trc right" },
    { 0, ORD_T, 0,      3, ORD_T, ORD_T, "real left" },
    { 3, ORD_L, ORD_L,  3, ORD_T, 1,     "mixed trc, act 1 right" },
    { 3, ORD_T, ORD_T,  0, ORD_T, 0,     "real right" },
};

#define N_SCENS (sizeof(SCENS) / sizeof(SCENS[0]))


// *******************************************************************************************************
static ord_t scen_order(int code, ord_t T){

    if (code == ORD_T){
        return T;
    }

    if (code == ORD_L){
        return (ord_t)((T + 1) / 2);
    }

    return (ord_t)code;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose(dhelpl_t dhl){

    static const uint64_t shapes[][2] = {{1, 1}, {2, 3}, {3, 3}, {4, 1}};
    size_t s;
    ord_t T;
    char ctx[128];

    for (T = 1; T <= 5; T++){

        for (s = 0; s < 4; s++){

            uint64_t nip = NIPS[s % 3], ip;
            feoarr_t fe = build_fe(shapes[s][0], shapes[s][1], nip, 3, T, T, 0.0), r = fearr_init();
            feoarr_t al = fearr_init();
            feoarrss_t q = ss_from_fe(&fe), qr = feoarrss_init();
            oarr_t* pts = get_points(&fe);
            int ok = fearr_transpose_to(&fe, &r) == DN_OK;

            for (ip = 0; ip < nip; ip++){

                oarr_t t = oarr_init();

                oarr_transpose_to(&pts[ip], &t, dhl);
                oarr_free(&pts[ip]);
                pts[ip] = t;

            }

            feoarrss_transpose_to(&q, &qr);
            fearr_copy_to(&fe, &al);
            ok = ok && fe_matches_points(&r, pts, 0.0) && fe_matches_ss(&r, &qr, 0.0);
            ok = ok && fearr_transpose_to(&al, &al) == DN_OK && fe_matches_points(&al, pts, 0.0);

            snprintf(ctx, sizeof(ctx), "transpose %llux%llu nip %llu T=%u (and aliasing)",
                (unsigned long long)shapes[s][0], (unsigned long long)shapes[s][1],
                (unsigned long long)nip, (unsigned)T);
            check(ok, ctx);

            fearr_free(&fe);
            fearr_free(&r);
            fearr_free(&al);
            feoarrss_free(&q);
            feoarrss_free(&qr);
            free_points(pts, nip);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* One matrix-product case: FF, FO and OF against the per-point products, semi-sparse, and (FF, at
 * nip = 4) the sparse arrso_t oracle through the conversions; aliasing for FF and FO. */
static void check_matmul(const scen_t* sc, ord_t T, uint64_t n, uint64_t q, uint64_t m, uint64_t nip,
                         dhelpl_t dhl){

    ord_t ta = scen_order(sc->ta, T), tb = scen_order(sc->tb, T);
    feoarr_t a = build_fe(n, q, nip, sc->ka, ta, scen_order(sc->ma, T), 0.0);
    feoarr_t b = build_fe(q, m, nip, sc->kb, tb, scen_order(sc->mb, T), 0.0);
    oarr_t bo = build_oarr(q, m, sc->kb, tb, scen_order(sc->mb, T), 0.0);
    oarr_t ao = build_oarr(n, q, sc->ka, ta, scen_order(sc->ma, T), 0.0);
    feoarrss_t qa = ss_from_fe(&a), qb = ss_from_fe(&b), qr = feoarrss_init();
    oarrss_t qbo = ss_from_oarr(&bo), qao = ss_from_oarr(&ao);
    oarr_t *pa = get_points(&a), *pb = get_points(&b), *ex = get_points(&a);
    feoarr_t r = fearr_init(), al = fearr_init();
    uint64_t ip;
    int ok;
    char ctx[160];

    // FF.
    for (ip = 0; ip < nip; ip++){
        oarr_matmul_OO_to(&pa[ip], &pb[ip], &ex[ip], dhl);
    }

    ok = fearr_matmul_FF_to(&a, &b, &r, dhl) == DN_OK && fe_matches_points(&r, ex, TOL)
         && r.arr.nact == ((sc->ka > sc->kb) ? sc->ka : sc->kb);
    feoarrss_matmul_FF_to(&qa, &qb, &qr, dhl);
    ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
    fearr_copy_to(&a, &al);
    ok = ok && fearr_matmul_FF_to(&al, &b, &al, dhl) == DN_OK && fe_matches_points(&al, ex, TOL);
    fearr_copy_to(&b, &al);
    ok = ok && fearr_matmul_FF_to(&a, &al, &al, dhl) == DN_OK && fe_matches_points(&al, ex, TOL);

    if (nip == 4 && T <= 4){

        for (ip = 0; ip < nip; ip++){

            arrso_t sa = oarr_to_arrso(&pa[ip], dhl), sb = oarr_to_arrso(&pb[ip], dhl);
            arrso_t sr = arrso_matmul_OO(&sa, &sb, dhl);
            oarr_t so = oarr_init();

            oarr_from_arrso_to(&sr, &so, dhl);
            oarr_reserve(&so, so.nact, so.nrows, so.ncols, r.arr.trc_order);
            ok = ok && fearr_get_ip_to(ip, &r, &ex[ip]) == DN_OK;
            {
                bases_t kk = (so.nact > ex[ip].nact) ? so.nact : ex[ip].nact;
                ord_t p;
                ndir_t d;
                uint64_t e;

                for (p = 0; p <= r.arr.trc_order; p++){

                    for (d = 0; d < sshelp_ndir_order(kk, p); d++){

                        for (e = 0; e < so.size; e++){
                            ok = ok && approx_equal(oarr_val(&so, p, d, e), oarr_val(&ex[ip], p, d, e),
                                                    TOL);
                        }

                    }

                }
            }

            arrso_free(&sa);
            arrso_free(&sb);
            arrso_free(&sr);
            oarr_free(&so);

        }

    }

    snprintf(ctx, sizeof(ctx), "matmul_FF %llux%llu*%llux%llu nip %llu T=%u (%s)",
        (unsigned long long)n, (unsigned long long)q, (unsigned long long)q, (unsigned long long)m,
        (unsigned long long)nip, (unsigned)T, sc->label);
    check(ok, ctx);

    // FO.
    for (ip = 0; ip < nip; ip++){
        oarr_matmul_OO_to(&pa[ip], &bo, &ex[ip], dhl);
    }

    ok = fearr_matmul_FO_to(&a, &bo, &r, dhl) == DN_OK && fe_matches_points(&r, ex, TOL);
    feoarrss_matmul_FO_to(&qa, &qbo, &qr, dhl);
    ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
    fearr_copy_to(&a, &al);
    ok = ok && fearr_matmul_FO_to(&al, &bo, &al, dhl) == DN_OK && fe_matches_points(&al, ex, TOL);
    snprintf(ctx, sizeof(ctx), "matmul_FO nip %llu T=%u (%s)", (unsigned long long)nip, (unsigned)T,
        sc->label);
    check(ok, ctx);

    // OF.
    for (ip = 0; ip < nip; ip++){
        oarr_matmul_OO_to(&ao, &pb[ip], &ex[ip], dhl);
    }

    ok = fearr_matmul_OF_to(&ao, &b, &r, dhl) == DN_OK && fe_matches_points(&r, ex, TOL);
    feoarrss_matmul_OF_to(&qao, &qb, &qr, dhl);
    ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
    fearr_copy_to(&b, &al);
    ok = ok && fearr_matmul_OF_to(&ao, &al, &al, dhl) == DN_OK && fe_matches_points(&al, ex, TOL);
    snprintf(ctx, sizeof(ctx), "matmul_OF nip %llu T=%u (%s)", (unsigned long long)nip, (unsigned)T,
        sc->label);
    check(ok, ctx);

    fearr_free(&a);
    fearr_free(&b);
    fearr_free(&r);
    fearr_free(&al);
    oarr_free(&ao);
    oarr_free(&bo);
    feoarrss_free(&qa);
    feoarrss_free(&qb);
    feoarrss_free(&qr);
    oarrss_free(&qao);
    oarrss_free(&qbo);
    free_points(pa, nip);
    free_points(pb, nip);
    free_points(ex, nip);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    static const uint64_t shapes[][3] = {{1, 1, 1}, {2, 2, 2}, {2, 3, 2}, {3, 3, 3}, {4, 4, 4},
                                         {3, 1, 2}};
    size_t s, c;
    ord_t T;

    for (T = 1; T <= 5; T++){

        for (s = 0; s < sizeof(shapes) / sizeof(shapes[0]); s++){

            for (c = 0; c < N_SCENS; c++){
                check_matmul(&SCENS[c], T, shapes[s][0], shapes[s][1], shapes[s][2], NIPS[(s + c) % 3],
                             dhl);
            }

        }

    }

    // Shape errors.
    {
        feoarr_t a = build_fe(2, 3, 4, 1, 1, 1, 0.0), b = build_fe(2, 2, 4, 1, 1, 1, 0.0);
        feoarr_t c3 = build_fe(3, 2, 3, 1, 1, 1, 0.0), r = fearr_init();
        oarr_t o = build_oarr(2, 2, 1, 1, 1, 0.0);

        check(fearr_matmul_FF_to(&a, &b, &r, dhl) == DN_ERR_SIZE
              && fearr_matmul_FF_to(&a, &c3, &r, dhl) == DN_ERR_SIZE
              && fearr_matmul_FO_to(&a, &o, &r, dhl) == DN_ERR_SIZE
              && fearr_matmul_OF_to(&o, &c3, &r, dhl) == DN_ERR_SIZE, "matmul shape errors");

        fearr_free(&a);
        fearr_free(&b);
        fearr_free(&c3);
        fearr_free(&r);
        oarr_free(&o);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dot products and integration against per-point sums of products, and semi-sparse. */
static void test_dot_integrate(dhelpl_t dhl){

    size_t c;
    ord_t T;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        for (c = 0; c < N_SCENS; c++){

            const scen_t* sc = &SCENS[c];
            uint64_t nip = NIPS[c % 3], ip, e;
            ord_t ta = scen_order(sc->ta, T), tb = scen_order(sc->tb, T);
            feoarr_t a = build_fe(2, 3, nip, sc->ka, ta, scen_order(sc->ma, T), 0.0);
            feoarr_t b = build_fe(2, 3, nip, sc->kb, tb, scen_order(sc->mb, T), 0.0);
            feoarr_t w = build_fe(1, 1, nip, sc->kb, tb, scen_order(sc->mb, T), 1.0), r = fearr_init();
            feoarr_t al = fearr_init();
            oarr_t bo = build_oarr(2, 3, sc->kb, tb, scen_order(sc->mb, T), 0.0), integ = oarr_init();
            oarr_t *pa = get_points(&a), *pb = get_points(&b), *pw = get_points(&w);
            oarr_t *ex = get_points(&w), tmp = oarr_init(), acc = oarr_init();
            feoarrss_t qa = ss_from_fe(&a), qb = ss_from_fe(&b), qw = ss_from_fe(&w);
            feoarrss_t qr = feoarrss_init();
            oarrss_t qbo = ss_from_oarr(&bo), qint = oarrss_init();
            int ok;

            // FO: sum_e a_ip[e] bo[e].
            for (ip = 0; ip < nip; ip++){

                oarr_t x = oarr_init(), y = oarr_init();

                oarr_mul_OO_to(&pa[ip], &bo, &tmp, dhl);
                oarr_zeros_to(0, 1, 1, 0, &acc);

                for (e = 0; e < 6; e++){

                    otinum_t v = oti_init();

                    oarr_get_item_to(e % 2, e / 2, &tmp, &v);
                    oarr_zeros_to(v.nact, 1, 1, v.trc_order, &x);
                    oarr_set_item(&v, 0, 0, &x);
                    oarr_sum_OO_to(&acc, &x, &acc, dhl);
                    oti_free(&v);

                }

                oarr_copy_to(&acc, &ex[ip]);
                oarr_free(&x);
                oarr_free(&y);

            }

            ok = fearr_dot_product_FO_to(&a, &bo, &r, dhl) == DN_OK && r.nrows == 1 && r.ncols == 1
                 && fe_matches_points(&r, ex, TOL);
            feoarrss_dot_product_FO_to(&qa, &qbo, &qr, dhl);
            ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
            fearr_copy_to(&a, &al);
            ok = ok && fearr_dot_product_FO_to(&al, &bo, &al, dhl) == DN_OK
                 && fe_matches_points(&al, ex, TOL);
            snprintf(ctx, sizeof(ctx), "dot_product_FO nip %llu T=%u (%s)", (unsigned long long)nip,
                (unsigned)T, sc->label);
            check(ok, ctx);

            // FF.
            for (ip = 0; ip < nip; ip++){

                oarr_t x = oarr_init();

                oarr_mul_OO_to(&pa[ip], &pb[ip], &tmp, dhl);
                oarr_zeros_to(0, 1, 1, 0, &acc);

                for (e = 0; e < 6; e++){

                    otinum_t v = oti_init();

                    oarr_get_item_to(e % 2, e / 2, &tmp, &v);
                    oarr_zeros_to(v.nact, 1, 1, v.trc_order, &x);
                    oarr_set_item(&v, 0, 0, &x);
                    oarr_sum_OO_to(&acc, &x, &acc, dhl);
                    oti_free(&v);

                }

                oarr_copy_to(&acc, &ex[ip]);
                oarr_free(&x);

            }

            ok = fearr_dot_product_FF_to(&a, &b, &r, dhl) == DN_OK && fe_matches_points(&r, ex, TOL);
            feoarrss_dot_product_FF_to(&qa, &qb, &qr, dhl);
            ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
            fearr_copy_to(&b, &al);
            ok = ok && fearr_dot_product_FF_to(&a, &al, &al, dhl) == DN_OK
                 && fe_matches_points(&al, ex, TOL);
            snprintf(ctx, sizeof(ctx), "dot_product_FF nip %llu T=%u (%s)", (unsigned long long)nip,
                (unsigned)T, sc->label);
            check(ok, ctx);

            // Integration with OTI weights: sum_ip w_ip a_ip.
            oarr_zeros_to(0, 2, 3, 0, &acc);

            for (ip = 0; ip < nip; ip++){

                otinum_t wv = oti_init();

                oarr_get_item_to(0, 0, &pw[ip], &wv);
                oarr_mul_oO_to(&wv, &pa[ip], &tmp, dhl);
                oarr_sum_OO_to(&acc, &tmp, &acc, dhl);
                oti_free(&wv);

            }

            ok = fearr_integrate_to(&a, &w, &integ, dhl) == DN_OK && same_oarr(&integ, &acc, TOL);
            feoarrss_integrate_to(&qa, &qw, &qint, dhl);
            {
                feoarr_t fi = fearr_init();
                feoarrss_t qi = feoarrss_init();

                fearr_from_oarr_to(&integ, 1, &fi);
                qi.arr   = qint;
                qi.nrows = 2;
                qi.ncols = 3;
                qi.nip   = 1;
                qi.arr.nrows = 1;
                qi.arr.ncols = 6;
                ok = ok && fe_matches_ss(&fi, &qi, TOL_SS);
                fearr_free(&fi);
            }
            snprintf(ctx, sizeof(ctx), "integrate nip %llu T=%u (%s)", (unsigned long long)nip,
                (unsigned)T, sc->label);
            check(ok, ctx);

            fearr_free(&a);
            fearr_free(&b);
            fearr_free(&w);
            fearr_free(&r);
            fearr_free(&al);
            oarr_free(&bo);
            oarr_free(&integ);
            oarr_free(&tmp);
            oarr_free(&acc);
            free_points(pa, nip);
            free_points(pb, nip);
            free_points(pw, nip);
            free_points(ex, nip);
            feoarrss_free(&qa);
            feoarrss_free(&qb);
            feoarrss_free(&qw);
            feoarrss_free(&qr);
            oarrss_free(&qbo);
            oarrss_free(&qint);

        }

    }

    // Shape errors.
    {
        feoarr_t a = build_fe(2, 2, 4, 1, 1, 1, 0.0), b = build_fe(2, 3, 4, 1, 1, 1, 0.0);
        feoarr_t r = fearr_init();
        feoarr_t w3 = build_fe(1, 1, 3, 1, 1, 1, 1.0);
        oarr_t o = build_oarr(3, 1, 1, 1, 1, 0.0), x = oarr_init();

        check(fearr_dot_product_FO_to(&a, &o, &r, dhl) == DN_ERR_SIZE
              && fearr_dot_product_FF_to(&a, &b, &r, dhl) == DN_ERR_SIZE
              && fearr_integrate_to(&a, &w3, &x, dhl) == DN_ERR_SIZE
              && fearr_integrate_to(&a, &b, &x, dhl) == DN_ERR_SIZE, "dot / integrate shape errors");

        fearr_free(&a);
        fearr_free(&b);
        fearr_free(&r);
        fearr_free(&w3);
        oarr_free(&o);
        oarr_free(&x);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* det and inv: closed forms (n <= 3) and the LU path (n = 4, 5) against the per-point SoA results and
 * semi-sparse; aliasing; a singular point; shape errors. */
static void test_det_inv(dhelpl_t dhl){

    ord_t T;
    uint64_t n;
    char ctx[160];

    for (T = 1; T <= 5; T++){

        for (n = 1; n <= 5; n++){

          int v;

          // v = 0: act = trc; v = 1: act 1 below trc; v = 2: a real operand (nact 0).
          for (v = 0; v < 3; v++){

            uint64_t nip = NIPS[n % 3], ip;
            bases_t k = (v == 2) ? 0 : (bases_t)(n % 2 == 0 ? 2 : 3);
            ord_t ma = (v == 1) ? 1 : ((v == 2) ? 0 : T);
            ord_t act_expect = (k == 0) ? 0 : T;
            feoarr_t fe = build_fe(n, n, nip, k, T, ma, 2.0), r = fearr_init(), al = fearr_init();
            feoarrss_t q = ss_from_fe(&fe), qr = feoarrss_init();
            oarr_t *pts = get_points(&fe), *ex = get_points(&fe);
            double tol_ss = (n > 3) ? TOL_LU : TOL_SS;
            int ok, st;

            // Determinant.
            for (ip = 0; ip < nip; ip++){

                otinum_t d = oti_init();

                oarr_det_to(&pts[ip], &d, dhl);
                oarr_zeros_to(d.nact, 1, 1, d.trc_order, &ex[ip]);
                oarr_set_item(&d, 0, 0, &ex[ip]);
                oti_free(&d);

            }

            st = fearr_det_to(&fe, &r, dhl);
            ok = st == DN_OK && r.nrows == 1 && r.ncols == 1 && fe_matches_points(&r, ex, TOL_LU);
            ok = ok && r.arr.nact == k && r.arr.trc_order == T && r.arr.act_order == act_expect;
            feoarrss_det_to(&q, &qr, dhl);
            ok = ok && fe_matches_ss(&r, &qr, tol_ss);
            fearr_copy_to(&fe, &al);
            ok = ok && fearr_det_to(&al, &al, dhl) == DN_OK && fe_matches_points(&al, ex, TOL_LU);
            snprintf(ctx, sizeof(ctx), "det %llux%llu nip %llu T=%u case %d", (unsigned long long)n,
                (unsigned long long)n, (unsigned long long)nip, (unsigned)T, v);
            check(ok, ctx);

            // Inverse.
            for (ip = 0; ip < nip; ip++){
                oarr_inv_to(&pts[ip], &ex[ip], dhl);
            }

            st = fearr_inv_to(&fe, &r, dhl);
            ok = st == DN_OK && r.nrows == n && r.ncols == n && fe_matches_points(&r, ex, TOL_LU);
            ok = ok && r.arr.nact == k && r.arr.trc_order == T && r.arr.act_order == act_expect;
            feoarrss_inv_to(&q, &qr, dhl);
            ok = ok && fe_matches_ss(&r, &qr, tol_ss);
            fearr_copy_to(&fe, &al);
            ok = ok && fearr_inv_to(&al, &al, dhl) == DN_OK && fe_matches_points(&al, ex, TOL_LU);
            snprintf(ctx, sizeof(ctx), "inv %llux%llu nip %llu T=%u case %d", (unsigned long long)n,
                (unsigned long long)n, (unsigned long long)nip, (unsigned)T, v);
            check(ok, ctx);

            fearr_free(&fe);
            fearr_free(&r);
            fearr_free(&al);
            feoarrss_free(&q);
            feoarrss_free(&qr);
            free_points(pts, nip);
            free_points(ex, nip);

          } // end for

        }

    }

    // Degenerate results keep the operand's nact and trc: det of 0 x 0, det / inv at nip = 0.
    {
        feoarr_t z = fearr_init(), e3 = fearr_init(), e4 = fearr_init(), r = fearr_init();

        // No build_fe() here: it divides by nip, which is 0 for e3 and e4.
        check(fearr_zeros_to(2, 0, 0, 2, 3, &z) == DN_OK && fearr_zeros_to(3, 3, 3, 0, 3, &e3) == DN_OK
              && fearr_zeros_to(3, 4, 4, 0, 3, &e4) == DN_OK, "degenerate det / inv: setup");

        check(fearr_det_to(&z, &r, dhl) == DN_OK && r.arr.nact == 2 && r.arr.trc_order == 3
              && r.arr.act_order == 0 && r.nip == 2 && r.arr.p_data[0] == 1.0 && r.arr.p_data[1] == 1.0,
              "det 0 x 0 keeps nact and trc (real 1)");
        check(fearr_det_to(&e3, &r, dhl) == DN_OK && r.arr.nact == 3 && r.arr.trc_order == 3,
              "det 3 x 3 at nip 0 keeps nact and trc");
        check(fearr_det_to(&e4, &r, dhl) == DN_OK && r.arr.nact == 3 && r.arr.trc_order == 3
              && r.nip == 0, "det 4 x 4 at nip 0 keeps nact and trc");
        check(fearr_inv_to(&e4, &r, dhl) == DN_OK && r.arr.nact == 3 && r.arr.trc_order == 3
              && r.nrows == 4 && r.ncols == 4 && r.nip == 0, "inv 4 x 4 at nip 0 keeps nact and trc");

        fearr_free(&z); fearr_free(&e3); fearr_free(&e4); fearr_free(&r);
    }

    // A singular real part at one point of a 4 x 4 (LU path): a positive status. A 0 x 0 matrix.
    {
        feoarr_t fe = build_fe(4, 4, 4, 2, 2, 2, 2.0), r = fearr_init(), z = fearr_init();
        uint64_t j;

        for (j = 0; j < 4; j++){
            fearr_set_ijk_r(0.0, 1, j, 2, &fe);
        }

        check(fearr_det_to(&fe, &r, dhl) > 0 && fearr_inv_to(&fe, &r, dhl) > 0,
              "singular point (n = 4): info > 0");

        fearr_zeros_to(0, 0, 0, 3, 1, &z);
        check(fearr_det_to(&z, &r, dhl) == DN_OK && r.nip == 3 && r.arr.p_data[2] == 1.0,
              "det of 0 x 0 is 1");
        check(fearr_inv_to(&z, &r, dhl) == DN_OK && r.nrows == 0 && r.nip == 3, "inv of 0 x 0");

        fearr_free(&z);
        fearr_zeros_to(1, 2, 3, 2, 1, &z);
        check(fearr_det_to(&z, &r, dhl) == DN_ERR_SIZE && fearr_inv_to(&z, &r, dhl) == DN_ERR_SIZE,
              "det / inv of a non-square matrix: DN_ERR_SIZE");

        fearr_free(&fe);
        fearr_free(&r);
        fearr_free(&z);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     K = 11 FALLBACK AND THREADS     -----------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* nact = 11 at order 5 (Nbasis(5) = 10): per-point products and the closed-form inverse leave the
 * global table; checked against the per-point SoA products and semi-sparse. */
static void test_fallback(dhelpl_t dhl, const char* mode){

    feoarr_t a = build_fe(2, 2, 4, 11, 5, 5, 1.5), b = build_fe(2, 2, 4, 7, 5, 5, 1.5);
    feoarr_t r = fearr_init();
    feoarrss_t qa = ss_from_fe(&a), qb = ss_from_fe(&b), qr = feoarrss_init();
    oarr_t *pa = get_points(&a), *pb = get_points(&b), *ex = get_points(&a);
    uint64_t ip;
    int ok;
    char ctx[160];

    for (ip = 0; ip < 4; ip++){
        oarr_matmul_OO_to(&pb[ip], &pa[ip], &ex[ip], dhl);
    }

    ok = fearr_matmul_FF_to(&b, &a, &r, dhl) == DN_OK && fe_matches_points(&r, ex, TOL);
    feoarrss_matmul_FF_to(&qb, &qa, &qr, dhl);
    ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
    snprintf(ctx, sizeof(ctx), "k=7 x k=11 order 5 matmul_FF (%s)", mode);
    check(ok, ctx);

    for (ip = 0; ip < 4; ip++){
        oarr_inv_to(&pa[ip], &ex[ip], dhl);
    }

    ok = fearr_inv_to(&a, &r, dhl) == DN_OK && fe_matches_points(&r, ex, TOL_LU);
    feoarrss_inv_to(&qa, &qr, dhl);
    ok = ok && fe_matches_ss(&r, &qr, TOL_SS);
    snprintf(ctx, sizeof(ctx), "k=11 order 5 closed-form inverse (%s)", mode);
    check(ok, ctx);

    fearr_free(&a);
    fearr_free(&b);
    fearr_free(&r);
    feoarrss_free(&qa);
    feoarrss_free(&qb);
    feoarrss_free(&qr);
    free_points(pa, 4);
    free_points(pb, 4);
    free_points(ex, 4);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Products, det and inv on independent data from 1 and 4 threads give identical results. */
static void test_threads(dhelpl_t dhl){

#ifdef _OPENMP
    enum { NCASE = 12 };
    feoarr_t a[NCASE], r1[NCASE], rn[NCASE];
    int i, nt, ok = 1, st_ok[2][NCASE];

    for (i = 0; i < NCASE; i++){

        uint64_t n = (uint64_t)(i % 4 + 1);

        a[i]  = build_fe(n, n, 9, (bases_t)((i % 2 == 0) ? 11 : 3), 5, 5, 2.0);
        r1[i] = fearr_init();
        rn[i] = fearr_init();

    }

    for (nt = 0; nt < 2; nt++){

        feoarr_t* r = (nt == 0) ? r1 : rn;

        omp_set_num_threads((nt == 0) ? 1 : 4);

        #pragma omp parallel for schedule(dynamic, 1)
        for (i = 0; i < NCASE; i++){

            feoarr_t t = fearr_init();
            int good;

            good = fearr_matmul_FF_to(&a[i], &a[i], &t, dhl) == DN_OK;
            good = good && fearr_inv_to(&t, &r[i], dhl) == DN_OK;
            good = good && fearr_det_to(&t, &t, dhl) == DN_OK;
            good = good && fearr_dot_product_FF_to(&r[i], &r[i], &r[i], dhl) == DN_OK;
            st_ok[nt][i] = good;
            fearr_free(&t);
            oti_ws_release();

        }

    }

    for (i = 0; i < NCASE; i++){

        feoarrss_t q = ss_from_fe(&r1[i]);

        ok = ok && st_ok[0][i] && st_ok[1][i] && fe_matches_ss(&rn[i], &q, 0.0);
        feoarrss_free(&q);
        fearr_free(&a[i]);
        fearr_free(&r1[i]);
        fearr_free(&rn[i]);

    }

    check(ok, "1 vs 4 threads: every status DN_OK, identical results");
#else
    (void)dhl;
    printf("skipped: threads (no OpenMP)\n");
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;
    int status;

    dhelp_load(NULL, &dhl);

    if (argc > 1 && strcmp(argv[1], "--fallback") == 0){

        test_fallback(dhl, "no table cache");

    } else {

        test_memory(dhl);
        test_set_ip_ijk(dhl);
        test_slices(dhl);
        test_broadcasts(dhl);
        test_transpose(dhl);
        test_matmul(dhl);
        test_dot_integrate(dhl);
        test_det_inv(dhl);
        test_fallback(dhl, "table cache");
        test_threads(dhl);

        // The k = 11 tests again without the local-table cache: the rank fallback path.
        if (getenv("OTI_SS_TABLE_CACHE_MB") == NULL){

            char cmd[4096];

            snprintf(cmd, sizeof(cmd), "OTI_SS_TABLE_CACHE_MB=0 '%s' --fallback", argv[0]);
            status = system(cmd);
            check(status == 0, "k = 11 tests without the table cache (child run)");

        }

    }

    oti_ws_release();
    ssoti_ws_release();
    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d dense Gauss test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C dense Gauss tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
