/* Checks of the dense SoA array type oarr_t (include/oti/dense/soa/{structures,base,algebra}.h,
 * PLAN-dense-update.md WP2). Two oracles:
 *   - arrso_t: operands are built as arrso_t (each element an independent random sotinum_t over
 *     bases 1..k), converted with oarr_from_arrso_to(), run through the oarr_ function under test,
 *     and compared block by block against the same arrso_ operation on the same inputs (1e-13
 *     relative; the comparison reads oarr_t blocks directly, not through oarr_to_arrso());
 *   - semi-sparse oarrss_t over the active set [1..k], built from the same arrso_t: a dense array
 *     over 1..k has the same layout, so its p_data must match the semi-sparse result's (1e-14).
 * Cases: equal nact, a smaller-nact operand on each side, nact = 0, mixed truncation orders, orders
 * 1..5, res aliasing each operand, scalar and real operands, every function, matmul shapes (square,
 * rectangular, 1 x n, n x 1, 0 x 0), transpose, add_bases in place vs reallocating, compact,
 * truncation, 1 vs N OpenMP threads, statuses (DN_ERR_SIZE, DN_ERR_INDEX, DN_ERR_MEMORY), and the
 * k = 11 / order 5 case beyond the global multiplication table (Nbasis(5) = 10), both through the
 * cached local tables and, in a child process run with OTI_SS_TABLE_CACHE_MB=0, the rank fallback.
 *
 * arrso_t stores elements row-major, (i, j) at p_data[j + i*ncols]; oarr_t blocks are column-major,
 * (i, j) at block[i + j*nrows]. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>
#include <oti/dense.h>

#ifdef _OPENMP
#include <omp.h>
#endif

static int n_failed = 0;
static int n_passed = 0;
static int g_verbose = 0;

static uint64_t g_rng_state;

/// Relative tolerance against the arrso_t oracle (plan section 6).
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

    if (isnan(a) && isnan(b)){
        return 1;
    }

    return diff <= tol * scale;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A random sotinum_t over bases 1..k at truncation order trc: every order-1 direction is set to a
 * nonzero value (so its dense nact is exactly k), orders 2..max_order hold a `density` fraction of
 * the directions. */
static sotinum_t build_soti(bases_t k, ord_t trc, ord_t max_order, double density, coeff_t re,
                            dhelpl_t dhl){

    sotinum_t num = soti_createEmpty(trc, dhl);
    ord_t p;
    bases_t i;

    soti_set_item(re, 0, 0, &num, dhl);

    if (trc == 0){
        return num;
    }

    for (i = 0; i < k; i++){

        double v = rng_range(0.05, 0.3) * ((rng_uniform() < 0.5) ? -1.0 : 1.0);

        soti_set_item(v, (imdir_t)i, 1, &num, dhl);

    }

    for (p = 2; p <= max_order && p <= trc; p++){

        ndir_t ndir = sshelp_ndir_order(k, p), j;

        for (j = 0; j < ndir; j++){

            if (rng_uniform() < density){
                soti_set_item(rng_range(-0.3, 0.3), (imdir_t)j, p, &num, dhl);
            }

        }

    }

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* An nrows x ncols arrso_t of independent build_soti() elements, real parts in [re_lo, re_hi]. */
static arrso_t build_arrso(uint64_t nrows, uint64_t ncols, bases_t k, ord_t trc, ord_t max_order,
                           double density, double re_lo, double re_hi, dhelpl_t dhl){

    arrso_t arr = arrso_zeros_bases(nrows, ncols, 0, trc, dhl);
    uint64_t e;

    for (e = 0; e < arr.size; e++){

        sotinum_t tmp = build_soti(k, trc, max_order, density, rng_range(re_lo, re_hi), dhl);

        soti_copy_to(&tmp, &arr.p_data[e], dhl);
        soti_free(&tmp);

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array from an arrso_t (fails the test on a status). */
static oarr_t to_dense(const arrso_t* arr, dhelpl_t dhl){

    oarr_t res = oarr_init();

    check(oarr_from_arrso_to(arr, &res, dhl) == DN_OK, "oarr_from_arrso_to: status");

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Every block of `res` against soti_get_item() on the matching oracle element, and every stored
 * nonzero of the oracle is inside the layout of `res`. */
static void compare_vs_arrso(const oarr_t* res, arrso_t* oracle, dhelpl_t dhl, double tol,
                             const char* ctx){

    uint64_t i, j, n_checked = 0, n_mismatch = 0, m = res->size;
    const uint64_t max_reported = 5;
    char name[256];

    if (res->nrows != oracle->nrows || res->ncols != oracle->ncols){

        snprintf(name, sizeof(name), "%s: shape %llux%llu vs oracle %llux%llu", ctx,
                 (unsigned long long)res->nrows, (unsigned long long)res->ncols,
                 (unsigned long long)oracle->nrows, (unsigned long long)oracle->ncols);
        check(0, name);
        return;

    }

    for (i = 0; i < res->nrows; i++){

        for (j = 0; j < res->ncols; j++){

            sotinum_t* el = &oracle->p_data[j + i * oracle->ncols];
            uint64_t e = i + j * res->nrows;
            ord_t p, ordi;

            n_checked++;

            if (!approx_equal(res->p_data[e], el->re, tol)){

                if (n_mismatch < max_reported){
                    fprintf(stderr, "  mismatch %s (%llu,%llu) real: dense=%.17g arrso=%.17g\n", ctx,
                            (unsigned long long)i, (unsigned long long)j, res->p_data[e], el->re);
                }

                n_mismatch++;

            }

            for (p = 1; p <= res->trc_order; p++){

                ndir_t np = sshelp_ndir_order(res->nact, p), idx;
                const coeff_t* b0 = res->p_data + oarr_block_index(res->nact, p, 0) * m + e;

                for (idx = 0; idx < np; idx++){

                    coeff_t v1 = b0[idx * m];
                    coeff_t v2 = (p <= el->trc_order) ? soti_get_item(idx, p, el, dhl) : 0.0;

                    n_checked++;

                    if (!approx_equal(v1, v2, tol)){

                        if (n_mismatch < max_reported){
                            fprintf(stderr, "  mismatch %s (%llu,%llu) order=%u idx=%llu: "
                                    "dense=%.17g arrso=%.17g\n", ctx, (unsigned long long)i,
                                    (unsigned long long)j, (unsigned)p, (unsigned long long)idx,
                                    v1, v2);
                        }

                        n_mismatch++;

                    }

                }

            }

            // Nonzeros of the oracle outside the dense layout would be lost coefficients.
            for (ordi = 0; ordi < el->trc_order; ordi++){

                ndir_t n;
                ord_t q = (ord_t)(ordi + 1);

                for (n = 0; n < el->p_nnz[ordi]; n++){

                    int inside = (q <= res->trc_order)
                                 && (el->p_idx[ordi][n] < sshelp_ndir_order(res->nact, q));

                    if (!inside && fabs(el->p_im[ordi][n]) > tol){

                        if (n_mismatch < max_reported){
                            fprintf(stderr, "  mismatch %s (%llu,%llu): oracle order %u idx %llu "
                                    "outside the dense layout\n", ctx, (unsigned long long)i,
                                    (unsigned long long)j, (unsigned)q,
                                    (unsigned long long)el->p_idx[ordi][n]);
                        }

                        n_mismatch++;

                    }

                }

            }

        }

    }

    snprintf(name, sizeof(name), "%s: %llu/%llu coefficients match", ctx,
             (unsigned long long)(n_checked - n_mismatch), (unsigned long long)n_checked);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A dense array against a semi-sparse one over the active set [1..nact]: same layout fields and
 * p_data equal to `tol` (relative). */
static void compare_vs_ss(const oarr_t* res, const oarrss_t* ss, double tol, const char* ctx){

    size_t n, i, n_mismatch = 0;
    bases_t u;
    char name[256];
    int same = (res->nrows == ss->nrows && res->ncols == ss->ncols && res->nact == ss->nbases
                && res->trc_order == ss->trc_order);

    for (u = 0; same && u < ss->nbases; u++){
        same = (ss->p_bases[u] == u + 1);
    }

    if (!same){

        snprintf(name, sizeof(name), "%s: layout (dense nact=%u trc=%u %llux%llu, ss k=%u trc=%u)",
                 ctx, (unsigned)res->nact, (unsigned)res->trc_order,
                 (unsigned long long)res->nrows, (unsigned long long)res->ncols,
                 (unsigned)ss->nbases, (unsigned)ss->trc_order);
        check(0, name);
        return;

    }

    n = (size_t)(1 + sshelp_ndir_total(res->nact, res->trc_order)) * res->size;

    for (i = 0; i < n; i++){

        if (!approx_equal(res->p_data[i], ss->p_data[i], tol)){

            if (n_mismatch < 5){
                fprintf(stderr, "  mismatch %s at %zu: dense=%.17g ss=%.17g\n", ctx, i,
                        res->p_data[i], ss->p_data[i]);
            }

            n_mismatch++;

        }

    }

    snprintf(name, sizeof(name), "%s: %zu/%zu reals match semi-sparse", ctx, n - n_mismatch, n);
    check(n_mismatch == 0, name);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Two dense arrays are bit-identical (layout fields and values). */
static int same_bits(const oarr_t* a, const oarr_t* b){

    size_t n;

    if (a->nrows != b->nrows || a->ncols != b->ncols || a->nact != b->nact
        || a->trc_order != b->trc_order || a->act_order != b->act_order){
        return 0;
    }

    n = (size_t)(1 + sshelp_ndir_total(a->nact, a->trc_order)) * a->size;

    return n == 0 || memcmp(a->p_data, b->p_data, n * sizeof(coeff_t)) == 0;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MEMORY AND ACCESS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_memory(void){

    oarr_t arr = oarr_init();
    size_t n, i;
    int all_zero = 1;

    check(arr.p_data == NULL && arr.nact == 0 && arr.size == 0, "init: empty array");
    oarr_free(&arr);
    check(arr.p_data == NULL, "free: on an empty array");

    check(oarr_zeros_to(3, 2, 3, 3, &arr) == DN_OK, "zeros_to: status");
    check(arr.nrows == 2 && arr.ncols == 3 && arr.size == 6, "zeros_to: shape");
    check(arr.nact == 3 && arr.nbases >= 3 && arr.trc_order == 3 && arr.act_order == 0,
          "zeros_to: fields");

    n = (size_t)(1 + sshelp_ndir_total(3, 3)) * 6;

    for (i = 0; i < n; i++){
        all_zero = all_zero && (arr.p_data[i] == 0.0);
    }

    check(all_zero, "zeros_to: every coefficient is zero");
    check(oarr_density(&arr) == 0.0, "zeros_to: density 0");
    check(oarr_memory_size(&arr) >= sizeof(oarr_t) + n * sizeof(coeff_t), "memory_size: capacity");

    // Reuse: a smaller zeros into the same array keeps the buffer.
    {
        coeff_t* before = arr.p_data;

        check(oarr_zeros_to(2, 2, 3, 2, &arr) == DN_OK && arr.p_data == before,
              "zeros_to: smaller layout reuses the buffer");
        check(arr.nact == 2 && arr.trc_order == 2, "zeros_to: smaller layout fields");
    }

    // Oversized requests fail with a status and leave the array valid.
    {
        coeff_t* before = arr.p_data;

        check(oarr_zeros_to(60000, 4, 4, 12, &arr) == DN_ERR_MEMORY, "zeros_to: huge -> DN_ERR_MEMORY");
        check(arr.p_data == before && arr.nact == 2, "zeros_to: failure leaves the array unchanged");
        check(oarr_zeros_to(2, UINT64_MAX / 2, 4, 2, &arr) == DN_ERR_MEMORY,
              "zeros_to: shape overflow -> DN_ERR_MEMORY");
        check(oarr_reserve(&arr, 60000, 2, 3, 12) == DN_ERR_MEMORY, "reserve: huge -> DN_ERR_MEMORY");
        check(arr.p_data == before && arr.trc_order == 2, "reserve: failure leaves the array unchanged");
    }

    oarr_free(&arr);

    {
        coeff_t data[4] = {1.0, 2.0, 3.0, 4.0};

        check(oarr_from_real_to(data, 2, 2, 2, &arr) == DN_OK, "from_real_to: status");
        check(arr.nact == 0 && arr.trc_order == 2, "from_real_to: fields");
        check(arr.p_data[0] == 1.0 && arr.p_data[1] == 2.0 && arr.p_data[2] == 3.0,
              "from_real_to: column-major layout");
        check(oarr_from_real_to(NULL, 3, 1, 1, &arr) == DN_OK && arr.p_data[2] == 0.0,
              "from_real_to: NULL data gives zeros");
    }

    check(oarr_eye_to(3, 2, &arr) == DN_OK, "eye_to: status");
    check(arr.p_data[0] == 1.0 && arr.p_data[4] == 1.0 && arr.p_data[8] == 1.0 && arr.p_data[1] == 0.0
          && arr.p_data[3] == 0.0, "eye_to: identity");
    oarr_free(&arr);

    // 0 x 0 and 0 x n arrays.
    check(oarr_zeros_to(3, 0, 0, 2, &arr) == DN_OK && arr.size == 0, "zeros_to: 0 x 0");
    check(oarr_density(&arr) == 0.0, "density: 0 x 0");
    check(oarr_zeros_to(3, 0, 5, 2, &arr) == DN_OK && arr.size == 0 && arr.ncols == 5,
          "zeros_to: 0 x 5");
    check(oarr_add_bases(5, &arr) == DN_OK && arr.nact == 5, "add_bases: 0 x 5");
    oarr_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reserve(dhelpl_t dhl){

    arrso_t a = build_arrso(3, 2, 2, 2, 2, 0.7, 0.5, 1.5, dhl);
    oarr_t arr = to_dense(&a, dhl);

    // Same size, higher order: values kept, new orders zero.
    check(oarr_reserve(&arr, 2, 3, 2, 4) == DN_OK, "reserve: raise trc status");
    check(arr.trc_order == 4 && arr.nact == 2, "reserve: raise trc fields");
    compare_vs_arrso(&arr, &a, dhl, 0.0, "reserve(raise trc) keeps values");

    // Same size, more capacity: values kept.
    check(oarr_reserve(&arr, 6, 3, 2, 2) == DN_OK, "reserve: capacity status");
    check(arr.nbases >= 6 && arr.nact == 2 && arr.trc_order == 4, "reserve: capacity fields");
    compare_vs_arrso(&arr, &a, dhl, 0.0, "reserve(capacity) keeps values");

    // Another shape: fields set.
    check(oarr_reserve(&arr, 2, 4, 5, 1) == DN_OK, "reserve: new shape status");
    check(arr.nrows == 4 && arr.ncols == 5 && arr.size == 20 && arr.trc_order == 4 && arr.nact == 2,
          "reserve: new shape fields");

    oarr_free(&arr);
    arrso_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_conversion(dhelpl_t dhl){

    static const struct { uint64_t nrows, ncols; } SHAPES[] = { {1, 1}, {3, 3}, {4, 2}, {1, 5} };
    size_t sh;
    ord_t trc;

    for (trc = 1; trc <= 5; trc++){

        for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

            bases_t k = (trc >= 5) ? 3 : 4;
            arrso_t arr = build_arrso(SHAPES[sh].nrows, SHAPES[sh].ncols, k, trc, trc, 0.6, 0.5, 1.5,
                                      dhl);
            oarr_t d = to_dense(&arr, dhl);
            oarrss_t ss = oarrss_from_arrso(&arr, dhl);
            arrso_t back;
            oarr_t d2 = oarr_init();
            char ctx[128];

            snprintf(ctx, sizeof(ctx), "from_arrso(%llux%llu,k=%u,trc=%u)",
                     (unsigned long long)SHAPES[sh].nrows, (unsigned long long)SHAPES[sh].ncols,
                     (unsigned)k, (unsigned)trc);
            check(d.nact == k && d.trc_order == trc, ctx);
            compare_vs_arrso(&d, &arr, dhl, 0.0, ctx);
            compare_vs_ss(&d, &ss, 0.0, ctx);

            back = oarr_to_arrso(&d, dhl);
            snprintf(ctx, sizeof(ctx), "to_arrso round trip(%llux%llu,k=%u,trc=%u)",
                     (unsigned long long)SHAPES[sh].nrows, (unsigned long long)SHAPES[sh].ncols,
                     (unsigned)k, (unsigned)trc);
            compare_vs_arrso(&d, &back, dhl, 0.0, ctx);
            check(oarr_from_arrso_to(&back, &d2, dhl) == DN_OK && same_bits(&d, &d2), ctx);

            arrso_free(&back);
            oarr_free(&d2);
            oarrss_free(&ss);
            oarr_free(&d);
            arrso_free(&arr);

        }

    }

    // A real array converts to nact = 0.
    {
        arrso_t arr = build_arrso(2, 2, 0, 2, 2, 0.5, 0.5, 1.5, dhl);
        oarr_t d = to_dense(&arr, dhl);

        check(d.nact == 0 && d.act_order == 0, "from_arrso: real array has nact 0");
        compare_vs_arrso(&d, &arr, dhl, 0.0, "from_arrso(real)");

        oarr_free(&d);
        arrso_free(&arr);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_add_bases(dhelpl_t dhl){

    ord_t trc;

    for (trc = 1; trc <= 4; trc++){

        arrso_t a = build_arrso(3, 2, 2, trc, trc, 0.7, 0.5, 1.5, dhl);
        oarr_t ref = to_dense(&a, dhl);
        oarr_t inplace = oarr_init(), realloced = oarr_init();
        coeff_t* before;
        char ctx[128];

        // Reallocating: capacity equals nact.
        check(oarr_copy_to(&ref, &realloced) == DN_OK, "copy_to: status");
        check(oarr_add_bases(5, &realloced) == DN_OK && realloced.nact == 5, "add_bases: realloc");
        snprintf(ctx, sizeof(ctx), "add_bases(realloc, trc=%u) keeps values", (unsigned)trc);
        compare_vs_arrso(&realloced, &a, dhl, 0.0, ctx);

        // In place: reserve the capacity first; the buffer must not move.
        check(oarr_copy_to(&ref, &inplace) == DN_OK, "copy_to: status");
        check(oarr_reserve(&inplace, 5, inplace.nrows, inplace.ncols, inplace.trc_order) == DN_OK,
              "reserve before add_bases");
        before = inplace.p_data;
        check(oarr_add_bases(5, &inplace) == DN_OK && inplace.nact == 5 && inplace.p_data == before,
              "add_bases: in place keeps the buffer");
        snprintf(ctx, sizeof(ctx), "add_bases(in place, trc=%u) keeps values", (unsigned)trc);
        compare_vs_arrso(&inplace, &a, dhl, 0.0, ctx);
        check(same_bits(&inplace, &realloced), "add_bases: in place == realloc");

        // Smaller or equal nact is a no-op.
        check(oarr_add_bases(3, &inplace) == DN_OK && inplace.nact == 5, "add_bases: smaller no-op");

        // Expansion kernel into a larger layout.
        {
            size_t n = (size_t)(1 + sshelp_ndir_total(6, (ord_t)(trc + 1))) * ref.size;
            coeff_t* dst = (coeff_t*)malloc(n * sizeof(coeff_t));
            oarr_t view = oarr_init();

            oarr_kernel_expand(&ref, 6, (ord_t)(trc + 1), dst);
            view.p_data = dst; view.nact = 6; view.nbases = 6; view.trc_order = (ord_t)(trc + 1);
            view.act_order = ref.act_order; view.nrows = ref.nrows; view.ncols = ref.ncols;
            view.size = ref.size;
            snprintf(ctx, sizeof(ctx), "kernel_expand(k 2->6, trc %u->%u)", (unsigned)trc,
                     (unsigned)(trc + 1));
            compare_vs_arrso(&view, &a, dhl, 0.0, ctx);
            free(dst);
        }

        oarr_free(&inplace);
        oarr_free(&realloced);
        oarr_free(&ref);
        arrso_free(&a);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_access(dhelpl_t dhl){

    arrso_t a = build_arrso(2, 3, 3, 3, 3, 0.7, 0.5, 1.5, dhl);
    oarr_t arr = to_dense(&a, dhl);
    coeff_t* blk;

    blk = oarr_get_block(0, 0, &arr);
    check(blk == arr.p_data, "get_block: order 0 is the real block");
    blk = oarr_get_block(2, 1, &arr);
    check(blk != NULL && blk[1 + 2 * arr.nrows] == soti_get_item(2, 1, &a.p_data[2 + 1 * 3], dhl),
          "get_block: order-1 block of base 3");
    check(oarr_get_block(3, 1, &arr) == NULL, "get_block: base above nact is NULL");
    check(oarr_get_block(0, 4, &arr) == NULL, "get_block: order above trc is NULL");
    check(oarr_get_block(sshelp_ndir_order(3, 2) - 1, 2, &arr) != NULL, "get_block: last order-2");
    check(oarr_get_block(sshelp_ndir_order(3, 2), 2, &arr) == NULL, "get_block: past order-2");

    check(oarr_set_item_r(7.0, 1, 2, &arr) == DN_OK, "set_item_r: status");
    {
        ndir_t n, nimag = sshelp_ndir_total(arr.nact, arr.trc_order);
        int cleared = 1;

        for (n = 0; n < nimag; n++){
            cleared = cleared && (arr.p_data[(1 + n) * arr.size + 1 + 2 * 2] == 0.0);
        }

        check(arr.p_data[1 + 2 * 2] == 7.0 && cleared, "set_item_r: real set, imaginary cleared");
    }

    check(oarr_set_item_r(1.0, 2, 0, &arr) == DN_ERR_INDEX, "set_item_r: row out of range");
    check(oarr_set_item_r(1.0, 0, 3, &arr) == DN_ERR_INDEX, "set_item_r: column out of range");
    check(oarr_density(&arr) > 0.0 && oarr_density(&arr) <= 1.0, "density: in (0, 1]");

    oarr_free(&arr);
    arrso_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Element accessors through otinum_t (WP1 memory functions). */
static void test_items(dhelpl_t dhl){

    arrso_t a = build_arrso(2, 3, 2, 2, 2, 0.7, 0.5, 1.5, dhl);
    oarr_t arr = to_dense(&a, dhl);
    otinum_t num = oti_init();
    sotinum_t s = build_soti(4, 3, 3, 0.8, 2.5, dhl);
    uint64_t i, j;
    char ctx[128];

    for (i = 0; i < arr.nrows; i++){

        for (j = 0; j < arr.ncols; j++){

            sotinum_t* el = &a.p_data[j + i * a.ncols];
            ndir_t n, nimag;
            int ok;

            ok = (oarr_get_item_to(i, j, &arr, &num) == DN_OK);
            ok = ok && num.nact == arr.nact && num.trc_order == arr.trc_order && num.re == el->re;
            nimag = sshelp_ndir_total(num.nact, num.trc_order);

            for (n = 0; ok && n < nimag; n++){
                ok = (num.p_im[n] == arr.p_data[(1 + n) * arr.size + i + j * arr.nrows]);
            }

            snprintf(ctx, sizeof(ctx), "get_item_to(%llu,%llu)", (unsigned long long)i,
                     (unsigned long long)j);
            check(ok, ctx);

        }

    }

    check(oarr_get_item_to(2, 0, &arr, &num) == DN_ERR_INDEX, "get_item_to: out of range");

    // Assignment rule: nact 2 -> 4 and trc 2 -> 3, the entries already there zero-extended.
    check(oti_from_soti_to(&s, &num, dhl) == DN_OK, "oti_from_soti_to: status");
    check(oarr_set_item(&num, 1, 2, &arr) == DN_OK, "set_item: status");
    check(arr.nact == 4 && arr.trc_order == 3, "set_item: raises nact and trc");
    check(arr.act_order == 3, "set_item: raises act_order");
    soti_copy_to(&s, &a.p_data[2 + 1 * a.ncols], dhl);
    compare_vs_arrso(&arr, &a, dhl, 0.0, "set_item(larger nact and trc)");
    check(oarr_set_item(&num, 0, 3, &arr) == DN_ERR_INDEX, "set_item: out of range");

    // A smaller scalar overwrites the whole element.
    {
        sotinum_t s2 = build_soti(1, 1, 1, 1.0, -1.5, dhl);

        check(oti_from_soti_to(&s2, &num, dhl) == DN_OK, "oti_from_soti_to: status");
        check(oarr_set_item(&num, 1, 2, &arr) == DN_OK, "set_item(smaller): status");
        check(arr.nact == 4 && arr.trc_order == 3, "set_item(smaller): keeps nact and trc");
        soti_copy_to(&s2, &a.p_data[2 + 1 * a.ncols], dhl);
        compare_vs_arrso(&arr, &a, dhl, 0.0, "set_item(smaller scalar)");
        soti_free(&s2);
    }

    oti_free(&num);
    soti_free(&s);
    oarr_free(&arr);
    arrso_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     KERNELS     -------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* oarr_kernel_mul_acc() and oarr_kernel_matmul_acc() over full order windows against arrso_t. */
static void test_kernels(dhelpl_t dhl){

    ord_t trc;

    for (trc = 1; trc <= 5; trc++){

        bases_t k = (trc >= 5) ? 3 : 4;
        arrso_t a = build_arrso(3, 4, k, trc, trc, 0.6, 0.5, 1.5, dhl);
        arrso_t b = build_arrso(3, 4, k, trc, trc, 0.6, 0.5, 1.5, dhl);
        arrso_t c = build_arrso(4, 2, k, trc, trc, 0.6, 0.5, 1.5, dhl);
        arrso_t o_mul = arrso_empty_like(&a, dhl);
        arrso_t o_mm = arrso_matmul_OO(&a, &c, dhl);
        oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl), C = to_dense(&c, dhl);
        oarr_t R = oarr_init();
        size_t nwork = (size_t)3 * 2 * sshelp_ndir_order(k, (ord_t)(trc / 2 + 1)) * 4;
        coeff_t* work = (coeff_t*)malloc(nwork * sizeof(coeff_t) + 1);
        char ctx[128];

        arrso_mul_OO_to(&a, &b, &o_mul, dhl);

        // Elementwise, in two element ranges.
        check(oarr_zeros_to(k, 3, 4, trc, &R) == DN_OK, "zeros_to for kernel");
        oarr_kernel_mul_acc(A.p_data, 0, trc, B.p_data, 0, trc, k, trc, 12, 0, 5, R.p_data, dhl);
        oarr_kernel_mul_acc(A.p_data, 0, trc, B.p_data, 0, trc, k, trc, 12, 5, 12, R.p_data, dhl);
        R.act_order = trc;
        snprintf(ctx, sizeof(ctx), "kernel_mul_acc(k=%u,trc=%u)", (unsigned)k, (unsigned)trc);
        compare_vs_arrso(&R, &o_mul, dhl, TOL_ORACLE, ctx);

        // Matrix product, one call per order window of A (p) to exercise the windows.
        {
            ord_t p;
            size_t maxNq = 0;
            coeff_t* wk;
            ord_t q;

            for (q = 0; q <= trc; q++){
                if (sshelp_ndir_order(k, q) > maxNq) maxNq = sshelp_ndir_order(k, q);
            }

            wk = (coeff_t*)malloc(3 * 2 * maxNq * sizeof(coeff_t));
            check(oarr_zeros_to(k, 3, 2, trc, &R) == DN_OK, "zeros_to for matmul kernel");

            for (p = 0; p <= trc; p++){
                check(oarr_kernel_matmul_acc(A.p_data, p, p, C.p_data, 0, trc, k, trc, 3, 4, 2, 1.0,
                                             R.p_data, wk, dhl) == DN_OK, "kernel_matmul_acc: status");
            }

            R.act_order = trc;
            snprintf(ctx, sizeof(ctx), "kernel_matmul_acc(k=%u,trc=%u)", (unsigned)k, (unsigned)trc);
            compare_vs_arrso(&R, &o_mm, dhl, TOL_ORACLE, ctx);
            free(wk);
        }

        free(work);
        oarr_free(&A); oarr_free(&B); oarr_free(&C); oarr_free(&R);
        arrso_free(&a); arrso_free(&b); arrso_free(&c); arrso_free(&o_mul); arrso_free(&o_mm);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     OPERAND CASES     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

/// Two operands: nact, truncation order and highest nonzero order (act_order) of each.
typedef struct {
    bases_t k1; ord_t t1; ord_t a1; bases_t k2; ord_t t2; ord_t a2; const char* label;
} pair_case_t;

#define MAX_PAIR_CASES 10


// *******************************************************************************************************
/* Operand cases at a given order: equal nact, a smaller-nact operand on each side, a real operand
 * on each side, mixed truncation orders and unequal act_order. The sparse oracle needs
 * k <= Nbasis(trc). */
static int pair_cases(ord_t trc, pair_case_t* pc){

    bases_t k = (trc >= 5) ? 3 : 4;
    ord_t tl = (trc > 1) ? (ord_t)(trc - 1) : 1;
    int n = 0;

    pc[n++] = (pair_case_t){ k, trc, trc, k, trc, trc, "equal" };
    pc[n++] = (pair_case_t){ (bases_t)(k - 2), trc, trc, k, trc, trc, "small-left" };
    pc[n++] = (pair_case_t){ k, trc, trc, (bases_t)(k - 2), trc, trc, "small-right" };
    pc[n++] = (pair_case_t){ 0, trc, 0, k, trc, trc, "real-left" };
    pc[n++] = (pair_case_t){ k, trc, trc, 0, trc, 0, "real-right" };

    if (trc > 1){

        pc[n++] = (pair_case_t){ k, tl, tl, (bases_t)(k - 1), trc, trc, "mixed-trc-left" };
        pc[n++] = (pair_case_t){ (bases_t)(k - 1), trc, trc, k, 1, 1, "mixed-trc-right" };
        pc[n++] = (pair_case_t){ k, trc, trc, k, trc, 1, "act-right-1" };
        pc[n++] = (pair_case_t){ k, trc, 1, (bases_t)(k - 1), trc, tl, "act-left-1" };

    }

    return n;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ELEMENTWISE ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef void (*arrso_OO_fn)(arrso_t*, arrso_t*, arrso_t*, dhelpl_t);
typedef int (*oarr_OO_fn)(const oarr_t*, const oarr_t*, oarr_t*, dhelpl_t);
typedef void (*oarrss_OO_fn)(const oarrss_t*, const oarrss_t*, oarrss_t*, dhelpl_t);

typedef struct { const char* name; arrso_OO_fn so; oarr_OO_fn dn; oarrss_OO_fn ss; } oo_op_t;

static const oo_op_t OO_OPS[] = {
    { "sum_OO", arrso_sum_OO_to, oarr_sum_OO_to, oarrss_sum_OO_to },
    { "sub_OO", arrso_sub_OO_to, oarr_sub_OO_to, oarrss_sub_OO_to },
    { "mul_OO", arrso_mul_OO_to, oarr_mul_OO_to, oarrss_mul_OO_to },
    { "div_OO", arrso_div_OO_to, oarr_div_OO_to, oarrss_div_OO_to },
};

#define N_OO_OPS (sizeof(OO_OPS) / sizeof(OO_OPS[0]))


// *******************************************************************************************************
/* Every OO operation, every operand case, orders 1..5, two shapes: arrso_t oracle and semi-sparse. */
static void test_elementwise_OO(dhelpl_t dhl){

    static const struct { uint64_t nrows, ncols; } SHAPES[] = { {1, 1}, {3, 2} };
    pair_case_t pc[MAX_PAIR_CASES];
    size_t sh, o;
    ord_t trc;
    int c, nc;

    for (trc = 1; trc <= 5; trc++){

        nc = pair_cases(trc, pc);

        for (c = 0; c < nc; c++){

            for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

                uint64_t nr = SHAPES[sh].nrows, ncl = SHAPES[sh].ncols;
                arrso_t a = build_arrso(nr, ncl, pc[c].k1, pc[c].t1, pc[c].a1, 0.6, 0.6, 1.4, dhl);
                arrso_t b = build_arrso(nr, ncl, pc[c].k2, pc[c].t2, pc[c].a2, 0.6, 0.6, 1.3, dhl);
                oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl);
                oarrss_t sa = oarrss_from_arrso(&a, dhl), sb = oarrss_from_arrso(&b, dhl);

                for (o = 0; o < N_OO_OPS; o++){

                    arrso_t oracle = arrso_empty_like((pc[c].t1 >= pc[c].t2) ? &a : &b, dhl);
                    oarr_t R = oarr_init();
                    oarrss_t sr = oarrss_init();
                    char ctx[160];

                    snprintf(ctx, sizeof(ctx), "%s(trc=%u,%s,%llux%llu)", OO_OPS[o].name,
                             (unsigned)trc, pc[c].label, (unsigned long long)nr,
                             (unsigned long long)ncl);

                    OO_OPS[o].so(&a, &b, &oracle, dhl);
                    OO_OPS[o].ss(&sa, &sb, &sr, dhl);
                    check(OO_OPS[o].dn(&A, &B, &R, dhl) == DN_OK, ctx);
                    check(R.nact == ((A.nact > B.nact) ? A.nact : B.nact)
                          && R.trc_order == ((A.trc_order > B.trc_order) ? A.trc_order : B.trc_order),
                          ctx);
                    compare_vs_arrso(&R, &oracle, dhl, TOL_ORACLE, ctx);
                    compare_vs_ss(&R, &sr, TOL_SS, ctx);

                    oarrss_free(&sr);
                    oarr_free(&R);
                    arrso_free(&oracle);

                }

                oarrss_free(&sa); oarrss_free(&sb);
                oarr_free(&A); oarr_free(&B);
                arrso_free(&a); arrso_free(&b);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


/// Scalar operand: nact and truncation order of the scalar, and of the array.
typedef struct { bases_t kn; ord_t tn; bases_t ka; ord_t ta; const char* label; } mix_case_t;


// *******************************************************************************************************
/* Scalar and real operands (oO, Oo, rO, Or) of every operation. */
static void test_elementwise_mixed(dhelpl_t dhl){

    ord_t trc;

    for (trc = 1; trc <= 5; trc++){

        bases_t k = (trc >= 5) ? 3 : 4;
        ord_t tl = (trc > 1) ? (ord_t)(trc - 1) : 1;
        mix_case_t mc[6];
        int c, nc = 0;

        mc[nc++] = (mix_case_t){ k, trc, k, trc, "equal" };
        mc[nc++] = (mix_case_t){ (bases_t)(k - 2), trc, k, trc, "small-scalar" };
        mc[nc++] = (mix_case_t){ k, trc, (bases_t)(k - 2), trc, "small-array" };
        mc[nc++] = (mix_case_t){ 0, trc, k, trc, "real-scalar" };
        mc[nc++] = (mix_case_t){ k, trc, k, tl, "scalar-higher-trc" };
        mc[nc++] = (mix_case_t){ k, tl, 0, trc, "real-array" };

        for (c = 0; c < nc; c++){

            arrso_t a = build_arrso(3, 2, mc[c].ka, mc[c].ta, mc[c].ta, 0.6, 0.6, 1.4, dhl);
            sotinum_t s = build_soti(mc[c].kn, mc[c].tn, mc[c].tn, 0.7, 0.8, dhl);
            oarr_t A = to_dense(&a, dhl);
            otinum_t num = oti_init();
            oarrss_t sa = oarrss_from_arrso(&a, dhl);
            ssotinum_t ss = ssoti_from_soti(&s, dhl);
            coeff_t val = 0.75;
            int op;

            check(oti_from_soti_to(&s, &num, dhl) == DN_OK, "oti_from_soti_to: status");

            for (op = 0; op < 12; op++){

                arrso_t oracle = arrso_empty_like(&a, dhl);
                oarr_t R = oarr_init();
                oarrss_t sr = oarrss_init();
                const char* name = "";
                char ctx[160];
                int st = DN_OK;

                switch (op){
                    case 0: name = "sum_oO"; arrso_sum_oO_to(&s, &a, &oracle, dhl);
                        oarrss_sum_oO_to(&ss, &sa, &sr, dhl); st = oarr_sum_oO_to(&num, &A, &R, dhl);
                        break;
                    case 1: name = "sub_oO"; arrso_sub_oO_to(&s, &a, &oracle, dhl);
                        oarrss_sub_oO_to(&ss, &sa, &sr, dhl); st = oarr_sub_oO_to(&num, &A, &R, dhl);
                        break;
                    case 2: name = "sub_Oo"; arrso_sub_Oo_to(&a, &s, &oracle, dhl);
                        oarrss_sub_Oo_to(&sa, &ss, &sr, dhl); st = oarr_sub_Oo_to(&A, &num, &R, dhl);
                        break;
                    case 3: name = "mul_oO"; arrso_mul_oO_to(&s, &a, &oracle, dhl);
                        oarrss_mul_oO_to(&ss, &sa, &sr, dhl); st = oarr_mul_oO_to(&num, &A, &R, dhl);
                        break;
                    case 4: name = "div_oO"; arrso_div_oO_to(&s, &a, &oracle, dhl);
                        oarrss_div_oO_to(&ss, &sa, &sr, dhl); st = oarr_div_oO_to(&num, &A, &R, dhl);
                        break;
                    case 5: name = "div_Oo"; arrso_div_Oo_to(&a, &s, &oracle, dhl);
                        oarrss_div_Oo_to(&sa, &ss, &sr, dhl); st = oarr_div_Oo_to(&A, &num, &R, dhl);
                        break;
                    case 6: name = "sum_rO"; arrso_sum_rO_to(val, &a, &oracle, dhl);
                        oarrss_sum_rO_to(val, &sa, &sr, dhl); st = oarr_sum_rO_to(val, &A, &R, dhl);
                        break;
                    case 7: name = "sub_rO"; arrso_sub_rO_to(val, &a, &oracle, dhl);
                        oarrss_sub_rO_to(val, &sa, &sr, dhl); st = oarr_sub_rO_to(val, &A, &R, dhl);
                        break;
                    case 8: name = "sub_Or"; arrso_sub_Or_to(&a, val, &oracle, dhl);
                        oarrss_sub_Or_to(&sa, val, &sr, dhl); st = oarr_sub_Or_to(&A, val, &R, dhl);
                        break;
                    case 9: name = "mul_rO"; arrso_mul_rO_to(val, &a, &oracle, dhl);
                        oarrss_mul_rO_to(val, &sa, &sr, dhl); st = oarr_mul_rO_to(val, &A, &R, dhl);
                        break;
                    case 10: name = "div_rO"; arrso_div_rO_to(val, &a, &oracle, dhl);
                        oarrss_div_rO_to(val, &sa, &sr, dhl); st = oarr_div_rO_to(val, &A, &R, dhl);
                        break;
                    default: name = "div_Or"; arrso_div_Or_to(&a, val, &oracle, dhl);
                        oarrss_div_Or_to(&sa, val, &sr, dhl); st = oarr_div_Or_to(&A, val, &R, dhl);
                        break;
                }

                snprintf(ctx, sizeof(ctx), "%s(trc=%u,%s)", name, (unsigned)trc, mc[c].label);
                check(st == DN_OK, ctx);
                compare_vs_arrso(&R, &oracle, dhl, TOL_ORACLE, ctx);
                compare_vs_ss(&R, &sr, TOL_SS, ctx);

                oarrss_free(&sr);
                oarr_free(&R);
                arrso_free(&oracle);

            }

            {
                arrso_t oracle = arrso_empty_like(&a, dhl);
                oarr_t R = oarr_init();
                char ctx[160];

                arrso_neg_to(&a, &oracle, dhl);
                snprintf(ctx, sizeof(ctx), "neg(trc=%u,%s)", (unsigned)trc, mc[c].label);
                check(oarr_neg_to(&A, &R, dhl) == DN_OK, ctx);
                compare_vs_arrso(&R, &oracle, dhl, 0.0, ctx);

                oarr_free(&R);
                arrso_free(&oracle);
            }

            ssoti_free(&ss);
            oarrss_free(&sa);
            oti_free(&num);
            oarr_free(&A);
            soti_free(&s);
            arrso_free(&a);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* act_order bookkeeping: products add the operands' act_order (capped at trc), sums take the max,
 * functions give trc. */
static void test_act_order(dhelpl_t dhl){

    arrso_t a = build_arrso(2, 2, 3, 5, 1, 0.5, 0.6, 1.4, dhl);
    arrso_t b = build_arrso(2, 2, 3, 5, 2, 0.5, 0.6, 1.4, dhl);
    oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl), R = oarr_init();

    check(A.act_order == 1 && B.act_order == 2, "act_order: from_arrso");
    check(oarr_mul_OO_to(&A, &B, &R, dhl) == DN_OK && R.act_order == 3, "act_order: mul 1 + 2 = 3");
    check(oarr_mul_OO_to(&B, &B, &R, dhl) == DN_OK && R.act_order == 4, "act_order: mul 2 + 2 = 4");
    check(oarr_mul_OO_to(&R, &B, &R, dhl) == DN_OK && R.act_order == 5, "act_order: mul capped at trc");
    check(oarr_sum_OO_to(&A, &B, &R, dhl) == DN_OK && R.act_order == 2, "act_order: sum max");
    check(oarr_exp_to(&A, &R, dhl) == DN_OK && R.act_order == 5, "act_order: function gives trc");
    check(oarr_div_OO_to(&A, &B, &R, dhl) == DN_OK && R.act_order == 5, "act_order: div gives trc");
    check(oarr_neg_to(&B, &R, dhl) == DN_OK && R.act_order == 2, "act_order: neg unchanged");
    check(oarr_transpose_to(&B, &R, dhl) == DN_OK && R.act_order == 2, "act_order: transpose unchanged");
    check(oarr_get_order_im_to(3, &B, &R) == DN_OK && R.act_order == 3, "act_order: get_order_im(o) = o");
    check(oarr_truncate_order_to(2, &B, &R) == DN_OK && R.act_order == 1,
          "act_order: truncate_order(o) = min(act, o - 1)");

    {
        arrso_t o = arrso_empty_like(&a, dhl);
        oarr_t P = oarr_init();

        // A product whose act bound is below trc leaves the higher orders exactly zero.
        arrso_mul_OO_to(&a, &a, &o, dhl);
        check(oarr_mul_OO_to(&A, &A, &P, dhl) == DN_OK && P.act_order == 2, "act_order: mul 1 + 1");
        compare_vs_arrso(&P, &o, dhl, TOL_ORACLE, "mul(act 1 x act 1)");

        oarr_free(&P);
        arrso_free(&o);
    }

    oarr_free(&A); oarr_free(&B); oarr_free(&R);
    arrso_free(&a); arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     FUNCTIONS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef void (*arrso_un_fn)(arrso_t*, arrso_t*, dhelpl_t);
typedef int (*oarr_un_fn)(const oarr_t*, oarr_t*, dhelpl_t);
typedef void (*oarrss_un_fn)(const oarrss_t*, oarrss_t*, dhelpl_t);

typedef struct {
    const char* name; coeff_t re_lo, re_hi; arrso_un_fn so; oarr_un_fn dn; oarrss_un_fn ss;
} unary_case_t;

static const unary_case_t UNARY_FUNCS[] = {
    { "exp",   0.8, 1.4, arrso_exp_to,   oarr_exp_to,   oarrss_exp_to },
    { "log",   0.8, 1.4, arrso_log_to,   oarr_log_to,   oarrss_log_to },
    { "log10", 0.8, 1.4, arrso_log10_to, oarr_log10_to, oarrss_log10_to },
    { "sqrt",  0.8, 1.4, arrso_sqrt_to,  oarr_sqrt_to,  oarrss_sqrt_to },
    { "cbrt",  0.8, 1.4, arrso_cbrt_to,  oarr_cbrt_to,  oarrss_cbrt_to },
    { "sin",   0.2, 0.9, arrso_sin_to,   oarr_sin_to,   oarrss_sin_to },
    { "cos",   0.2, 0.9, arrso_cos_to,   oarr_cos_to,   oarrss_cos_to },
    { "tan",   0.1, 0.5, arrso_tan_to,   oarr_tan_to,   oarrss_tan_to },
    { "asin",  0.1, 0.5, arrso_asin_to,  oarr_asin_to,  oarrss_asin_to },
    { "acos",  0.1, 0.5, arrso_acos_to,  oarr_acos_to,  oarrss_acos_to },
    { "atan",  0.2, 0.9, arrso_atan_to,  oarr_atan_to,  oarrss_atan_to },
    { "sinh",  0.2, 0.9, arrso_sinh_to,  oarr_sinh_to,  oarrss_sinh_to },
    { "cosh",  0.2, 0.9, arrso_cosh_to,  oarr_cosh_to,  oarrss_cosh_to },
    { "tanh",  0.2, 0.9, arrso_tanh_to,  oarr_tanh_to,  oarrss_tanh_to },
    { "asinh", 0.2, 0.9, arrso_asinh_to, oarr_asinh_to, oarrss_asinh_to },
    { "acosh", 1.2, 1.8, arrso_acosh_to, oarr_acosh_to, oarrss_acosh_to },
    { "atanh", 0.1, 0.5, arrso_atanh_to, oarr_atanh_to, oarrss_atanh_to },
    { "erf",   0.2, 0.9, arrso_erf_to,   oarr_erf_to,   oarrss_erf_to },
};

#define N_UNARY_FUNCS (sizeof(UNARY_FUNCS) / sizeof(UNARY_FUNCS[0]))


// *******************************************************************************************************
/* Every function and pow at orders 1..5, including a real array and a lower act_order. */
static void test_functions(dhelpl_t dhl){

    static const coeff_t EXPS[] = { 2.5, -1.0, 0.5, 3.0, -2.5 };
    size_t f, x;
    ord_t trc;

    for (trc = 1; trc <= 5; trc++){

        bases_t k = (trc >= 5) ? 3 : 4;

        for (f = 0; f < N_UNARY_FUNCS + sizeof(EXPS) / sizeof(EXPS[0]); f++){

            int is_pow = (f >= N_UNARY_FUNCS);
            coeff_t lo = is_pow ? 0.8 : UNARY_FUNCS[f].re_lo, hi = is_pow ? 1.4 : UNARY_FUNCS[f].re_hi;
            coeff_t ex = is_pow ? EXPS[f - N_UNARY_FUNCS] : 0.0;

            for (x = 0; x < 3; x++){

                // x = 0: full operand; 1: act_order 1; 2: real operand.
                bases_t kk = (x == 2) ? 0 : k;
                ord_t mx = (x == 1) ? 1 : trc;
                arrso_t a = build_arrso(3, 2, kk, trc, mx, 0.6, lo, hi, dhl);
                arrso_t oracle = arrso_empty_like(&a, dhl);
                oarr_t A = to_dense(&a, dhl), R = oarr_init();
                oarrss_t sa = oarrss_from_arrso(&a, dhl), sr = oarrss_init();
                char ctx[160];
                int st;

                if (is_pow){

                    arrso_pow_to(&a, ex, &oracle, dhl);
                    oarrss_pow_to(&sa, ex, &sr, dhl);
                    st = oarr_pow_to(&A, ex, &R, dhl);
                    snprintf(ctx, sizeof(ctx), "pow(%.1f)(trc=%u,case %zu)", ex, (unsigned)trc, x);

                } else {

                    UNARY_FUNCS[f].so(&a, &oracle, dhl);
                    UNARY_FUNCS[f].ss(&sa, &sr, dhl);
                    st = UNARY_FUNCS[f].dn(&A, &R, dhl);
                    snprintf(ctx, sizeof(ctx), "%s(trc=%u,case %zu)", UNARY_FUNCS[f].name,
                             (unsigned)trc, x);

                }

                check(st == DN_OK, ctx);
                compare_vs_arrso(&R, &oracle, dhl, TOL_ORACLE, ctx);
                compare_vs_ss(&R, &sr, TOL_SS, ctx);

                oarrss_free(&sa); oarrss_free(&sr);
                oarr_free(&A); oarr_free(&R);
                arrso_free(&a); arrso_free(&oracle);

            }

        }

    }

    // feval with explicit derivatives equals the function.
    {
        arrso_t a = build_arrso(2, 3, 3, 4, 4, 0.6, 0.8, 1.4, dhl);
        oarr_t A = to_dense(&a, dhl), R1 = oarr_init(), R2 = oarr_init();
        coeff_t derivs[5 * 6], tmp[5];
        uint64_t e;
        ord_t i;

        for (e = 0; e < 6; e++){

            der_r_exp(A.p_data[e], 4, tmp);

            for (i = 0; i <= 4; i++){
                derivs[i * 6 + e] = tmp[i];
            }

        }

        check(oarr_feval_to(derivs, &A, &R1, dhl) == DN_OK && oarr_exp_to(&A, &R2, dhl) == DN_OK
              && same_bits(&R1, &R2), "feval_to(exp derivatives) == exp_to");

        oarr_free(&A); oarr_free(&R1); oarr_free(&R2);
        arrso_free(&a);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MATMUL AND TRANSPOSE     ------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* True when every real of an array's layout is zero. */
static int all_zero_layout(const oarr_t* a){

    size_t n = (size_t)(1 + sshelp_ndir_total(a->nact, a->trc_order)) * a->size, i;

    for (i = 0; i < n; i++){

        if (a->p_data[i] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    static const struct { uint64_t n, m, p; } SHAPES[] = {
        {3, 3, 3}, {2, 4, 3}, {1, 4, 1}, {4, 1, 3}, {1, 3, 5}, {5, 2, 1}
    };
    pair_case_t pc[MAX_PAIR_CASES];
    size_t sh;
    ord_t trc;
    int c, nc;

    for (trc = 1; trc <= 5; trc++){

        nc = pair_cases(trc, pc);

        for (c = 0; c < nc; c++){

            for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

                arrso_t a = build_arrso(SHAPES[sh].n, SHAPES[sh].m, pc[c].k1, pc[c].t1, pc[c].a1,
                                        0.6, -1.0, 1.0, dhl);
                arrso_t b = build_arrso(SHAPES[sh].m, SHAPES[sh].p, pc[c].k2, pc[c].t2, pc[c].a2,
                                        0.6, -1.0, 1.0, dhl);
                arrso_t oracle = arrso_matmul_OO(&a, &b, dhl);
                oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl), R = oarr_init();
                oarrss_t sa = oarrss_from_arrso(&a, dhl), sb = oarrss_from_arrso(&b, dhl);
                oarrss_t sr = oarrss_init();
                char ctx[160];

                snprintf(ctx, sizeof(ctx), "matmul(trc=%u,%s,%llux%llu x %llux%llu)", (unsigned)trc,
                         pc[c].label, (unsigned long long)SHAPES[sh].n,
                         (unsigned long long)SHAPES[sh].m, (unsigned long long)SHAPES[sh].m,
                         (unsigned long long)SHAPES[sh].p);
                check(oarr_matmul_OO_to(&A, &B, &R, dhl) == DN_OK, ctx);
                check(oarrss_matmul_OO_to(&sa, &sb, &sr, dhl) == 0, ctx);
                compare_vs_arrso(&R, &oracle, dhl, TOL_ORACLE, ctx);
                compare_vs_ss(&R, &sr, TOL_SS, ctx);

                oarrss_free(&sa); oarrss_free(&sb); oarrss_free(&sr);
                oarr_free(&A); oarr_free(&B); oarr_free(&R);
                arrso_free(&a); arrso_free(&b); arrso_free(&oracle);

            }

        }

    }

    // Empty shapes: 0 x 0, 0 x n, n x 0 inner dimension.
    {
        oarr_t A = oarr_init(), B = oarr_init(), R = oarr_init();

        check(oarr_zeros_to(2, 0, 0, 3, &A) == DN_OK && oarr_zeros_to(3, 0, 0, 2, &B) == DN_OK,
              "matmul 0x0: setup");
        check(oarr_matmul_OO_to(&A, &B, &R, dhl) == DN_OK && R.nrows == 0 && R.ncols == 0
              && R.nact == 3 && R.trc_order == 3, "matmul 0x0 x 0x0");
        check(oarr_zeros_to(2, 0, 3, 3, &A) == DN_OK && oarr_zeros_to(2, 3, 2, 3, &B) == DN_OK,
              "matmul 0x3: setup");
        check(oarr_matmul_OO_to(&A, &B, &R, dhl) == DN_OK && R.nrows == 0 && R.ncols == 2,
              "matmul 0x3 x 3x2");
        check(oarr_zeros_to(2, 3, 0, 3, &A) == DN_OK && oarr_zeros_to(2, 0, 2, 3, &B) == DN_OK,
              "matmul 3x0: setup");
        check(oarr_matmul_OO_to(&A, &B, &R, dhl) == DN_OK && R.nrows == 3 && R.ncols == 2
              && all_zero_layout(&R), "matmul 3x0 x 0x2 is zero");

        oarr_free(&A); oarr_free(&B); oarr_free(&R);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose(dhelpl_t dhl){

    static const struct { uint64_t nrows, ncols; } SHAPES[] = { {3, 3}, {2, 5}, {1, 4}, {4, 1} };
    size_t sh;
    ord_t trc;

    for (trc = 1; trc <= 5; trc++){

        for (sh = 0; sh < sizeof(SHAPES) / sizeof(SHAPES[0]); sh++){

            bases_t k = (trc >= 5) ? 3 : 4;
            arrso_t a = build_arrso(SHAPES[sh].nrows, SHAPES[sh].ncols, k, trc, trc, 0.6, 0.5, 1.5,
                                    dhl);
            arrso_t oracle = arrso_transpose(&a, dhl);
            oarr_t A = to_dense(&a, dhl), R = oarr_init();
            oarrss_t sa = oarrss_from_arrso(&a, dhl), sr = oarrss_init();
            char ctx[128];

            snprintf(ctx, sizeof(ctx), "transpose(trc=%u,%llux%llu)", (unsigned)trc,
                     (unsigned long long)SHAPES[sh].nrows, (unsigned long long)SHAPES[sh].ncols);
            check(oarr_transpose_to(&A, &R, dhl) == DN_OK, ctx);
            oarrss_transpose_to(&sa, &sr, dhl);
            compare_vs_arrso(&R, &oracle, dhl, 0.0, ctx);
            compare_vs_ss(&R, &sr, 0.0, ctx);

            // In place (res aliases the operand).
            check(oarr_transpose_to(&A, &A, dhl) == DN_OK && same_bits(&A, &R), ctx);

            oarrss_free(&sa); oarrss_free(&sr);
            oarr_free(&A); oarr_free(&R);
            arrso_free(&a); arrso_free(&oracle);

        }

    }

    {
        oarr_t A = oarr_init(), R = oarr_init();

        check(oarr_zeros_to(2, 0, 3, 2, &A) == DN_OK && oarr_transpose_to(&A, &R, dhl) == DN_OK
              && R.nrows == 3 && R.ncols == 0, "transpose 0x3");
        oarr_free(&A); oarr_free(&R);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     TRUNCATION AND COMPACTION     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_truncation(dhelpl_t dhl){

    ord_t trc, o;

    for (trc = 1; trc <= 5; trc++){

        bases_t k = (trc >= 5) ? 3 : 4;
        arrso_t a = build_arrso(2, 3, k, trc, trc, 0.8, 0.5, 1.5, dhl);
        oarr_t A = to_dense(&a, dhl);
        oarrss_t sa = oarrss_from_arrso(&a, dhl);
        char ctx[128];

        // truncate_im for every direction of orders 1 and 2 (and one beyond nact).
        for (o = 1; o <= 2 && o <= trc; o++){

            imdir_t idx, nd = (imdir_t)sshelp_ndir_order(k, o) + 1;

            for (idx = 0; idx < nd; idx++){

                arrso_t oracle = arrso_truncate_im(idx, o, &a, dhl);
                oarr_t R = oarr_init();
                oarrss_t sr = oarrss_init();

                snprintf(ctx, sizeof(ctx), "truncate_im(idx=%llu,ord=%u,trc=%u)",
                         (unsigned long long)idx, (unsigned)o, (unsigned)trc);
                check(oarr_truncate_im_to(idx, o, &A, &R) == DN_OK, ctx);
                oarrss_truncate_im_to(idx, o, &sa, &sr);
                compare_vs_arrso(&R, &oracle, dhl, 0.0, ctx);

                if (idx < sshelp_ndir_order(k, o)){
                    compare_vs_ss(&R, &sr, 0.0, ctx);
                }

                oarrss_free(&sr);
                oarr_free(&R);
                arrso_free(&oracle);

            }

        }

        // truncate_order and get_order_im for every order (0 included).
        for (o = 0; o <= trc + 1; o++){

            arrso_t o1 = arrso_empty_like(&a, dhl), o2 = arrso_empty_like(&a, dhl);
            oarr_t R1 = oarr_init(), R2 = oarr_init();

            arrso_truncate_order_to(o, &a, &o1, dhl);
            arrso_get_order_im_to(o, &a, &o2, dhl);

            snprintf(ctx, sizeof(ctx), "truncate_order(%u,trc=%u)", (unsigned)o, (unsigned)trc);
            check(oarr_truncate_order_to(o, &A, &R1) == DN_OK && R1.trc_order == trc, ctx);
            check(R1.act_order <= ((o == 0) ? 0 : o - 1), ctx);
            compare_vs_arrso(&R1, &o1, dhl, 0.0, ctx);

            snprintf(ctx, sizeof(ctx), "get_order_im(%u,trc=%u)", (unsigned)o, (unsigned)trc);
            check(oarr_get_order_im_to(o, &A, &R2) == DN_OK && R2.trc_order == trc, ctx);
            compare_vs_arrso(&R2, &o2, dhl, 0.0, ctx);

            // In place.
            check(oarr_copy_to(&A, &R1) == DN_OK && oarr_truncate_order_to(o, &R1, &R1) == DN_OK,
                  "truncate_order in place: status");
            compare_vs_arrso(&R1, &o1, dhl, 0.0, "truncate_order in place");

            oarr_free(&R1); oarr_free(&R2);
            arrso_free(&o1); arrso_free(&o2);

        }

        oarrss_free(&sa);
        oarr_free(&A);
        arrso_free(&a);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_compact(dhelpl_t dhl){

    ord_t trc;

    for (trc = 1; trc <= 4; trc++){

        arrso_t a = build_arrso(3, 2, 2, trc, trc, 0.7, 0.5, 1.5, dhl);
        oarr_t A = to_dense(&a, dhl), R = oarr_init();
        char ctx[128];

        // Trailing zero bases are trimmed (not and in place).
        check(oarr_add_bases(5, &A) == DN_OK, "compact: setup");
        snprintf(ctx, sizeof(ctx), "compact(trailing, trc=%u)", (unsigned)trc);
        check(oarr_compact_to(&A, &R) == DN_OK && R.nact == 2 && R.act_order == A.act_order, ctx);
        compare_vs_arrso(&R, &a, dhl, 0.0, ctx);
        check(oarr_compact_to(&A, &A) == DN_OK && same_bits(&A, &R), "compact in place");

        // A zero base below a used one stays (dense over 1..nact).
        {
            arrso_t o = arrso_truncate_im(0, 1, &a, dhl);
            oarr_t T = oarr_init();

            check(oarr_truncate_im_to(0, 1, &A, &T) == DN_OK && oarr_compact_to(&T, &R) == DN_OK
                  && R.nact == 2, "compact: zero base 1 below base 2 stays");
            compare_vs_arrso(&R, &o, dhl, 0.0, "compact(zero leading base)");

            // Truncating base 2 leaves only base 1.
            arrso_free(&o);
            o = arrso_truncate_im(1, 1, &a, dhl);
            check(oarr_truncate_im_to(1, 1, &A, &T) == DN_OK && oarr_compact_to(&T, &T) == DN_OK
                  && T.nact == 1, "compact: base 2 removed -> nact 1");
            compare_vs_arrso(&T, &o, dhl, 0.0, "compact(trailing base removed)");

            oarr_free(&T);
            arrso_free(&o);
        }

        // Only a real part left: nact 0, act_order 0.
        check(oarr_truncate_order_to(1, &A, &R) == DN_OK && oarr_compact_to(&R, &R) == DN_OK
              && R.nact == 0 && R.act_order == 0, "compact: real part only");

        // act_order is lowered to the highest nonzero order.
        if (trc >= 2){

            check(oarr_truncate_order_to(2, &A, &R) == DN_OK && oarr_compact_to(&R, &R) == DN_OK
                  && R.act_order == 1 && R.nact == 2, "compact: act_order lowered");

        }

        oarr_free(&A); oarr_free(&R);
        arrso_free(&a);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ALIASING AND DESTINATIONS     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* A destination already holding something: smaller (reallocated), larger (reused), or empty. */
static oarr_t dirty_dest(int kind){

    oarr_t d = oarr_init();
    size_t n, i;

    if (kind == 0){
        return d;
    }

    if (kind == 1){
        oarr_zeros_to(1, 1, 1, 1, &d);
    } else {
        oarr_zeros_to(6, 5, 5, 5, &d);
    }

    n = (size_t)(1 + sshelp_ndir_total(d.nact, d.trc_order)) * d.size;

    for (i = 0; i < n; i++){
        d.p_data[i] = 1234.5;
    }

    d.act_order = d.trc_order;

    return d;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* res aliasing each operand, and dirty destinations, give the fresh-destination result bit for bit. */
static void test_aliasing(dhelpl_t dhl){

    pair_case_t pc[MAX_PAIR_CASES];
    int c, nc = pair_cases(3, pc), op, kind;
    char ctx[160];

    for (c = 0; c < nc; c++){

        arrso_t a = build_arrso(3, 3, pc[c].k1, pc[c].t1, pc[c].a1, 0.6, 0.6, 1.4, dhl);
        arrso_t b = build_arrso(3, 3, pc[c].k2, pc[c].t2, pc[c].a2, 0.6, 0.6, 1.4, dhl);
        sotinum_t s = build_soti(pc[c].k2, pc[c].t2, pc[c].a2, 0.7, 0.9, dhl);
        oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl);
        otinum_t num = oti_init();

        check(oti_from_soti_to(&s, &num, dhl) == DN_OK, "oti_from_soti_to: status");

        for (op = 0; op < 13; op++){

            oarr_t ref = oarr_init(), X = oarr_init(), Y = oarr_init();
            int two = (op < 5);
            int st_ref = DN_OK, st_x = DN_OK, st_y = DN_OK;
            const char* name = "";

            // X = copy of A used as res == arr1; Y = copy of B used as res == arr2.
            oarr_copy_to(&A, &X);
            oarr_copy_to(&B, &Y);

            switch (op){
                case 0: name = "sum_OO";
                    st_ref = oarr_sum_OO_to(&A, &B, &ref, dhl);
                    st_x = oarr_sum_OO_to(&X, &B, &X, dhl); st_y = oarr_sum_OO_to(&A, &Y, &Y, dhl);
                    break;
                case 1: name = "sub_OO";
                    st_ref = oarr_sub_OO_to(&A, &B, &ref, dhl);
                    st_x = oarr_sub_OO_to(&X, &B, &X, dhl); st_y = oarr_sub_OO_to(&A, &Y, &Y, dhl);
                    break;
                case 2: name = "mul_OO";
                    st_ref = oarr_mul_OO_to(&A, &B, &ref, dhl);
                    st_x = oarr_mul_OO_to(&X, &B, &X, dhl); st_y = oarr_mul_OO_to(&A, &Y, &Y, dhl);
                    break;
                case 3: name = "div_OO";
                    st_ref = oarr_div_OO_to(&A, &B, &ref, dhl);
                    st_x = oarr_div_OO_to(&X, &B, &X, dhl); st_y = oarr_div_OO_to(&A, &Y, &Y, dhl);
                    break;
                case 4: name = "matmul";
                    st_ref = oarr_matmul_OO_to(&A, &B, &ref, dhl);
                    st_x = oarr_matmul_OO_to(&X, &B, &X, dhl);
                    st_y = oarr_matmul_OO_to(&A, &Y, &Y, dhl);
                    break;
                case 5: name = "sum_oO";
                    st_ref = oarr_sum_oO_to(&num, &A, &ref, dhl);
                    st_x = oarr_sum_oO_to(&num, &X, &X, dhl);
                    break;
                case 6: name = "sub_Oo";
                    st_ref = oarr_sub_Oo_to(&A, &num, &ref, dhl);
                    st_x = oarr_sub_Oo_to(&X, &num, &X, dhl);
                    break;
                case 7: name = "mul_oO";
                    st_ref = oarr_mul_oO_to(&num, &A, &ref, dhl);
                    st_x = oarr_mul_oO_to(&num, &X, &X, dhl);
                    break;
                case 8: name = "div_Oo";
                    st_ref = oarr_div_Oo_to(&A, &num, &ref, dhl);
                    st_x = oarr_div_Oo_to(&X, &num, &X, dhl);
                    break;
                case 9: name = "div_rO";
                    st_ref = oarr_div_rO_to(2.0, &A, &ref, dhl); st_x = oarr_div_rO_to(2.0, &X, &X, dhl);
                    break;
                case 10: name = "exp";
                    st_ref = oarr_exp_to(&A, &ref, dhl); st_x = oarr_exp_to(&X, &X, dhl);
                    break;
                case 11: name = "pow";
                    st_ref = oarr_pow_to(&A, -1.5, &ref, dhl); st_x = oarr_pow_to(&X, -1.5, &X, dhl);
                    break;
                default: name = "transpose";
                    st_ref = oarr_transpose_to(&A, &ref, dhl); st_x = oarr_transpose_to(&X, &X, dhl);
                    break;
            }

            snprintf(ctx, sizeof(ctx), "%s aliasing arr1 (%s)", name, pc[c].label);
            check(st_ref == DN_OK && st_x == DN_OK && same_bits(&X, &ref), ctx);

            if (two){
                snprintf(ctx, sizeof(ctx), "%s aliasing arr2 (%s)", name, pc[c].label);
                check(st_y == DN_OK && same_bits(&Y, &ref), ctx);
            }

            // Dirty destinations.
            for (kind = 0; kind < 3; kind++){

                oarr_t D = dirty_dest(kind);
                int st;

                switch (op){
                    case 0: st = oarr_sum_OO_to(&A, &B, &D, dhl); break;
                    case 1: st = oarr_sub_OO_to(&A, &B, &D, dhl); break;
                    case 2: st = oarr_mul_OO_to(&A, &B, &D, dhl); break;
                    case 3: st = oarr_div_OO_to(&A, &B, &D, dhl); break;
                    case 4: st = oarr_matmul_OO_to(&A, &B, &D, dhl); break;
                    case 5: st = oarr_sum_oO_to(&num, &A, &D, dhl); break;
                    case 6: st = oarr_sub_Oo_to(&A, &num, &D, dhl); break;
                    case 7: st = oarr_mul_oO_to(&num, &A, &D, dhl); break;
                    case 8: st = oarr_div_Oo_to(&A, &num, &D, dhl); break;
                    case 9: st = oarr_div_rO_to(2.0, &A, &D, dhl); break;
                    case 10: st = oarr_exp_to(&A, &D, dhl); break;
                    case 11: st = oarr_pow_to(&A, -1.5, &D, dhl); break;
                    default: st = oarr_transpose_to(&A, &D, dhl); break;
                }

                snprintf(ctx, sizeof(ctx), "%s into dirty destination %d (%s)", name, kind, pc[c].label);
                check(st == DN_OK && same_bits(&D, &ref), ctx);
                oarr_free(&D);

            }

            oarr_free(&ref); oarr_free(&X); oarr_free(&Y);

        }

        // Both operands the same array, and the result too.
        {
            oarr_t ref = oarr_init(), X = oarr_init();

            check(oarr_mul_OO_to(&A, &A, &ref, dhl) == DN_OK && oarr_copy_to(&A, &X) == DN_OK
                  && oarr_mul_OO_to(&X, &X, &X, dhl) == DN_OK && same_bits(&X, &ref),
                  "mul_OO x*x into x");
            check(oarr_sum_OO_to(&A, &A, &ref, dhl) == DN_OK && oarr_copy_to(&A, &X) == DN_OK
                  && oarr_sum_OO_to(&X, &X, &X, dhl) == DN_OK && same_bits(&X, &ref),
                  "sum_OO x+x into x");
            check(oarr_matmul_OO_to(&A, &A, &ref, dhl) == DN_OK && oarr_copy_to(&A, &X) == DN_OK
                  && oarr_matmul_OO_to(&X, &X, &X, dhl) == DN_OK && same_bits(&X, &ref),
                  "matmul x@x into x");

            oarr_free(&ref); oarr_free(&X);
        }

        oti_free(&num);
        oarr_free(&A); oarr_free(&B);
        soti_free(&s);
        arrso_free(&a); arrso_free(&b);

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     STATUSES     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_statuses(dhelpl_t dhl){

    oarr_t A = oarr_init(), B = oarr_init(), R = oarr_init();
    otinum_t num = oti_init();

    oarr_zeros_to(2, 2, 3, 2, &A);
    oarr_zeros_to(2, 3, 2, 2, &B);
    oarr_zeros_to(1, 1, 1, 1, &R);

    check(oarr_sum_OO_to(&A, &B, &R, dhl) == DN_ERR_SIZE, "sum_OO: shape mismatch -> DN_ERR_SIZE");
    check(oarr_sub_OO_to(&A, &B, &R, dhl) == DN_ERR_SIZE, "sub_OO: shape mismatch -> DN_ERR_SIZE");
    check(oarr_mul_OO_to(&A, &B, &R, dhl) == DN_ERR_SIZE, "mul_OO: shape mismatch -> DN_ERR_SIZE");
    check(oarr_div_OO_to(&A, &B, &R, dhl) == DN_ERR_SIZE, "div_OO: shape mismatch -> DN_ERR_SIZE");
    check(oarr_matmul_OO_to(&A, &A, &R, dhl) == DN_ERR_SIZE, "matmul: inner mismatch -> DN_ERR_SIZE");
    check(R.nrows == 1 && R.ncols == 1 && R.nact == 1, "failed calls leave res unchanged");
    check(oarr_matmul_OO_to(&A, &B, &R, dhl) == DN_OK && R.nrows == 2 && R.ncols == 2,
          "matmul 2x3 x 3x2 after the failures");

    // A scalar whose layout does not fit: DN_ERR_MEMORY, no crash.
    check(oti_create_empty_to(3, 2, &num) == DN_OK, "scalar setup");
    num.nact = 60000;
    num.trc_order = 12;
    num.act_order = 0;
    check(oarr_sum_oO_to(&num, &A, &R, dhl) == DN_ERR_MEMORY,
          "sum_oO: oversized layout -> DN_ERR_MEMORY");
    num.nact = 3;
    num.trc_order = 2;

    oti_free(&num);
    oarr_free(&A); oarr_free(&B); oarr_free(&R);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     THREADS     -------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Large elementwise operations on 1 and N OpenMP threads give bit-identical results. */
static void test_openmp_threads(dhelpl_t dhl){

#ifdef _OPENMP
    int max_threads = omp_get_max_threads();
#endif
    arrso_t a = build_arrso(80, 80, 3, 3, 3, 0.5, 0.6, 1.3, dhl);
    arrso_t b = build_arrso(80, 80, 2, 3, 3, 0.5, 0.4, 0.9, dhl);
    sotinum_t s = build_soti(3, 3, 3, 0.8, 1.1, dhl);
    oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl);
    oarr_t r1[4], rn[4];
    otinum_t num = oti_init();
    int t, i;

    check(oti_from_soti_to(&s, &num, dhl) == DN_OK, "oti_from_soti_to: status");

    for (t = 0; t < 2; t++){

        oarr_t* r = (t == 0) ? r1 : rn;

#ifdef _OPENMP
        omp_set_num_threads((t == 0) ? 1 : ((max_threads > 1) ? max_threads : 4));
#endif

        for (i = 0; i < 4; i++){
            r[i] = oarr_init();
        }

        check(oarr_mul_OO_to(&A, &B, &r[0], dhl) == DN_OK, "threads: mul_OO status");
        check(oarr_exp_to(&A, &r[1], dhl) == DN_OK, "threads: exp status");
        check(oarr_mul_oO_to(&num, &B, &r[2], dhl) == DN_OK, "threads: mul_oO status");
        check(oarr_div_OO_to(&A, &B, &r[3], dhl) == DN_OK, "threads: div_OO status");

    }

#ifdef _OPENMP
    omp_set_num_threads(max_threads);
#endif

    check(same_bits(&r1[0], &rn[0]), "mul_OO (1 vs N threads): bit-identical");
    check(same_bits(&r1[1], &rn[1]), "exp (1 vs N threads): bit-identical");
    check(same_bits(&r1[2], &rn[2]), "mul_oO (1 vs N threads): bit-identical");
    check(same_bits(&r1[3], &rn[3]), "div_OO (1 vs N threads): bit-identical");

    {
        arrso_t o = arrso_empty_like(&a, dhl);

        arrso_mul_OO_to(&a, &b, &o, dhl);
        compare_vs_arrso(&rn[0], &o, dhl, TOL_ORACLE, "mul_OO (N threads) vs arrso");
        arrso_free(&o);
    }

    for (i = 0; i < 4; i++){
        oarr_free(&r1[i]);
        oarr_free(&rn[i]);
    }

    oti_free(&num);
    soti_free(&s);
    oarr_free(&A); oarr_free(&B);
    arrso_free(&a); arrso_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BEYOND THE GLOBAL TABLE     ---------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* k = 11 at order 5 (Nbasis(5) = 10): products go through the local table cache, or, with
 * OTI_SS_TABLE_CACHE_MB=0, the rank fallback. The sparse oracle cannot multiply these, so the
 * reference is semi-sparse over [1..11] (1e-14), plus a mixed-nact case (11 with 6). */
static void test_beyond_table(dhelpl_t dhl, const char* tag){

    arrso_t a = build_arrso(2, 2, 11, 5, 5, 0.3, 0.6, 1.4, dhl);
    arrso_t b = build_arrso(2, 2, 11, 5, 5, 0.3, 0.6, 1.4, dhl);
    arrso_t c = build_arrso(2, 2, 6, 5, 5, 0.3, 0.6, 1.4, dhl);
    sotinum_t s = build_soti(11, 5, 5, 0.3, 0.9, dhl);
    oarr_t A = to_dense(&a, dhl), B = to_dense(&b, dhl), C = to_dense(&c, dhl), R = oarr_init();
    oarrss_t sa = oarrss_from_arrso(&a, dhl), sb = oarrss_from_arrso(&b, dhl);
    oarrss_t sc = oarrss_from_arrso(&c, dhl), sr = oarrss_init();
    ssotinum_t ss = ssoti_from_soti(&s, dhl);
    otinum_t num = oti_init();
    char ctx[128];

    check(A.nact == 11 && C.nact == 6 && oti_from_soti_to(&s, &num, dhl) == DN_OK,
          "beyond table: setup");

    snprintf(ctx, sizeof(ctx), "mul_OO(k=11,trc=5,%s)", tag);
    check(oarr_mul_OO_to(&A, &B, &R, dhl) == DN_OK, ctx);
    oarrss_mul_OO_to(&sa, &sb, &sr, dhl);
    compare_vs_ss(&R, &sr, TOL_SS, ctx);

    snprintf(ctx, sizeof(ctx), "mul_OO(k=6 x k=11,trc=5,%s)", tag);
    check(oarr_mul_OO_to(&C, &A, &R, dhl) == DN_OK, ctx);
    oarrss_mul_OO_to(&sc, &sa, &sr, dhl);
    compare_vs_ss(&R, &sr, TOL_SS, ctx);

    snprintf(ctx, sizeof(ctx), "mul_oO(k=11,trc=5,%s)", tag);
    check(oarr_mul_oO_to(&num, &C, &R, dhl) == DN_OK, ctx);
    oarrss_mul_oO_to(&ss, &sc, &sr, dhl);
    compare_vs_ss(&R, &sr, TOL_SS, ctx);

    snprintf(ctx, sizeof(ctx), "exp(k=11,trc=5,%s)", tag);
    check(oarr_exp_to(&A, &R, dhl) == DN_OK, ctx);
    oarrss_exp_to(&sa, &sr, dhl);
    compare_vs_ss(&R, &sr, TOL_SS, ctx);

    snprintf(ctx, sizeof(ctx), "matmul(k=11 x k=6,trc=5,%s)", tag);
    check(oarr_matmul_OO_to(&A, &C, &R, dhl) == DN_OK, ctx);
    check(oarrss_matmul_OO_to(&sa, &sc, &sr, dhl) == 0, ctx);
    compare_vs_ss(&R, &sr, TOL_SS, ctx);

    ssoti_free(&ss);
    oti_free(&num);
    oarrss_free(&sa); oarrss_free(&sb); oarrss_free(&sc); oarrss_free(&sr);
    oarr_free(&A); oarr_free(&B); oarr_free(&C); oarr_free(&R);
    soti_free(&s);
    arrso_free(&a); arrso_free(&b); arrso_free(&c);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Reruns this executable with the local table cache disabled, so test_beyond_table() goes through
 * the rank fallback of the kernels. */
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


// *******************************************************************************************************
/* Byte budget of the size gate (default: the physical memory): a representable request far above it
   returns DN_ERR_MEMORY before any allocation and leaves the result valid. */
static void test_budget(dhelpl_t dhl){

    oarr_t A = oarr_init(), R = oarr_init();

    // 1000 x 1000 over nact 1000 at order 2: 5e11 coefficients, 3.6 TiB.
    check(oarr_zeros_to(1000, 1000, 1000, 2, &A) == DN_ERR_MEMORY && A.p_data == NULL,
          "budget: zeros_to far above the memory gives DN_ERR_MEMORY");

    check(oarr_zeros_to(2, 3, 3, 1, &A) == DN_OK, "budget: small zeros_to");
    check(oarr_reserve(&A, 1000, 1000, 1000, 2) == DN_ERR_MEMORY && A.nact == 2 && A.nrows == 3,
          "budget: reserve above the budget leaves the array unchanged");
    check(oarr_sum_OO_to(&A, &A, &R, dhl) == DN_OK, "budget: arrays within it still work");

    oarr_free(&A);
    oarr_free(&R);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Child run with OTI_DENSE_MAX_MB=1 (131072 reals): arrays just below pass, above fail, in creators,
   reserve and results of elementwise and matrix operations. */
static void test_budget_child(dhelpl_t dhl){

    oarr_t A = oarr_init(), B = oarr_init(), R = oarr_init();

    // (1 + 2) * 200 * 200 = 120000 reals fit; 3 * 300 * 300 = 270000 do not.
    check(oarr_zeros_to(2, 200, 200, 1, &A) == DN_OK, "budget 1 MB: 200 x 200, nact 2, trc 1 fits");
    check(oarr_zeros_to(2, 300, 300, 1, &B) == DN_ERR_MEMORY, "budget 1 MB: 300 x 300 refused");
    check(oarr_reserve(&A, 4, 200, 200, 1) == DN_ERR_MEMORY && A.nact == 2,
          "budget 1 MB: reserve refused, array unchanged");

    // A sum raising the result to nact 4 (5 * 40000 reals) is refused.
    check(oarr_zeros_to(4, 200, 1, 1, &B) == DN_OK, "budget 1 MB: 200 x 1, nact 4");
    check(oarr_matmul_OO_to(&A, &B, &R, dhl) == DN_OK, "budget 1 MB: product within it");
    oarr_free(&B);
    check(oarr_zeros_to(4, 200, 200, 0, &B) == DN_OK, "budget 1 MB: 200 x 200, nact 4, trc 0");
    check(oarr_sum_OO_to(&A, &B, &R, dhl) == DN_ERR_MEMORY, "budget 1 MB: sum above the budget");

    oarr_free(&A);
    oarr_free(&B);
    oarr_free(&R);

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
    check(rc == 0, "byte budget (child with OTI_DENSE_MAX_MB=1) passes");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Truncation orders up to _MAXORDER_OTI work; above it creators and reserve return DN_ERR_INDEX. */
static void test_max_order(dhelpl_t dhl){

    oarr_t A = oarr_init(), R = oarr_init();
    oarrss_t sa, sr = oarrss_init();
    arrso_t a = build_arrso(2, 1, 1, _MAXORDER_OTI, 3, 1.0, 0.5, 1.5, dhl);

    check(oarr_zeros_to(1, 2, 2, _MAXORDER_OTI, &R) == DN_OK, "zeros_to: trc = _MAXORDER_OTI");
    check(oarr_zeros_to(1, 2, 2, _MAXORDER_OTI + 1, &R) == DN_ERR_INDEX,
          "zeros_to: trc above _MAXORDER_OTI -> DN_ERR_INDEX");
    check(oarr_eye_to(2, _MAXORDER_OTI + 1, &R) == DN_ERR_INDEX, "eye_to: above max -> DN_ERR_INDEX");
    check(oarr_reserve(&R, 1, 2, 2, _MAXORDER_OTI + 1) == DN_ERR_INDEX,
          "reserve: above max -> DN_ERR_INDEX");
    check(R.trc_order == _MAXORDER_OTI, "reserve failure leaves the array unchanged");

    // A univariate order-150 function against semi-sparse.
    A  = to_dense(&a, dhl);
    sa = oarrss_from_arrso(&a, dhl);
    check(A.trc_order == _MAXORDER_OTI && A.nact == 1, "from_arrso: order 150");
    check(oarr_exp_to(&A, &R, dhl) == DN_OK, "exp at order 150: status");
    oarrss_exp_to(&sa, &sr, dhl);
    compare_vs_ss(&R, &sr, 1e-12, "exp at order 150");

    oarrss_free(&sa); oarrss_free(&sr);
    oarr_free(&A); oarr_free(&R);
    arrso_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MAIN     ----------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;
    int child = (argc > 1 && strcmp(argv[1], "--rank-fallback") == 0);
    int budget = (argc > 1 && strcmp(argv[1], "--budget") == 0);

    g_verbose = (getenv("DN_TEST_VERBOSE") != NULL);

    dhelp_load(NULL, &dhl);
    rng_seed(0xD15EA5E0C0FFEE11ULL);

    if (budget){

        test_budget_child(dhl);

    } else if (child){

        // Child run: the local table cache is disabled, so k = 11 at order 5 has no table.
        check(sshelp_get_pair(11, 2, 3, dhl).p_tab == NULL, "rank fallback: no table for k=11, 2x3");
        test_beyond_table(dhl, "rank fallback");

    } else {

        test_memory();
        test_reserve(dhl);
        test_conversion(dhl);
        test_add_bases(dhl);
        test_access(dhl);
        test_items(dhl);
        test_kernels(dhl);
        test_elementwise_OO(dhl);
        test_elementwise_mixed(dhl);
        test_act_order(dhl);
        test_functions(dhl);
        test_matmul(dhl);
        test_transpose(dhl);
        test_truncation(dhl);
        test_compact(dhl);
        test_aliasing(dhl);
        test_statuses(dhl);
        test_max_order(dhl);
        test_openmp_threads(dhl);
        // The cache can be disabled from the environment (debugging the fallback): skip the check then.
        if (getenv("OTI_SS_TABLE_CACHE_MB") == NULL){
            check(sshelp_get_pair(11, 2, 3, dhl).p_tab != NULL, "k=11, 2x3 uses a cached local table");
        }

        test_beyond_table(dhl, "cached table");
        test_rank_fallback_child(argv[0]);
        test_budget(dhl);

        if (getenv("OTI_DENSE_MAX_MB") == NULL){
            test_budget_run_child(argv[0]);
        }

    }

    oti_ws_release();
    dhelp_free(&dhl);

    printf("%s%d checks passed, %d failed.\n",
           child ? "[rank-fallback child] " : (budget ? "[budget child] " : ""), n_passed,
           n_failed);

    if (n_failed != 0){

        fprintf(stderr, "%d dense SoA test(s) failed.\n", n_failed);
        return 1;

    }

    printf("C dense SoA tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
