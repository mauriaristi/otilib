/* Phase 7b readiness and zero-skip checks of the dense 7a arrays (written from PLAN-ndarray-contracts.md
 * sections 7.1-7.3, the oarr_t / arro_t headers and the critic's finding 8 / the checker's finding 2 of
 * the W3 review, independently of the implementation):
 *   - a retained view or an export of an omat buffer makes every layout change (oarr_add_bases,
 *     oarr_reserve with growth) fail with OTI_ERR_BUSY and leave the array unchanged; once the extra
 *     references are released the same calls succeed;
 *   - a non-owning view (oarr_view_matrix) as `res` of a product is an error and writes nowhere;
 *   - arro_resize with another reference on the element store, or an export, is OTI_ERR_BUSY and the
 *     array is unchanged;
 *   - the non-finite zero-skip case: an A block that is zero over the first 4096 elements and a B with
 *     inf there give the same bits at 1, 2 and 4 threads, equal to the 1.x one-thread value (nan). */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // contracts S23
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/dense.h>
#include <oti/core/meta.h>
#include <oti/real/ndarray/buffer.h>

#ifdef _OPENMP
#include <omp.h>
#endif

/// Status of a non-owning view as `res`: dense's choice (note build-orch/w3-notes/dense.md, fix1).
#ifndef VIEW_RES_STATUS
#define VIEW_RES_STATUS OTI_ERR_BUSY
#endif

static int n_failed = 0;


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
static void fill_soa(oarr_t* a){

    int64_t nb = a->blocks.shape[0];
    uint64_t n = oarr_size(a);
    int64_t b;
    uint64_t e;

    for (b = 0; b < nb; b++){
        for (e = 0; e < n; e++){
            oarr_data(a)[b * oarr_bstride(a) + (int64_t)e] = (double)(1 + b) * 10.0 + (double)e;
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int soa_unchanged(const oarr_t* a, const oarr_t* ref, const coeff_t* data0){

    int64_t nb = a->blocks.shape[0];
    uint64_t n = oarr_size(a);
    int64_t b;
    uint64_t e;

    if (oarr_data(a) != data0 || oarr_nact(a) != oarr_nact(ref) || oarr_nrows(a) != oarr_nrows(ref)
        || oarr_ncols(a) != oarr_ncols(ref) || oarr_trc_order(a) != oarr_trc_order(ref)
        || oarr_act_order(a) != oarr_act_order(ref) || a->blocks.shape[0] != ref->blocks.shape[0]
        || a->nbases != ref->nbases){
        return 0;
    }
    for (b = 0; b < nb; b++){
        for (e = 0; e < n; e++){
            if (oarr_data(a)[b * oarr_bstride(a) + (int64_t)e] != (double)(1 + b) * 10.0 + (double)e){
                return 0;
            }
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Layout changes with one extra reference of a kind (0 = retained view + meta retain, 1 = export).
static void test_soa_busy(int kind){

    const char* tag = (kind == 0) ? "retained view" : "export";
    char msg[160];
    oarr_t a = oarr_init();
    oarr_t snap;
    ndarr_t extra;
    oti_meta_t* m2 = NULL;
    const coeff_t* data0;
    int st;

    memset(&extra, 0, sizeof(extra));
    check(oarr_zeros_to(2, 3, 4, 2, &a) == OTI_OK, "soa busy: zeros_to");
    fill_soa(&a);
    snap = a;                      // field copy for comparison only; never released
    data0 = oarr_data(&a);

    if (kind == 0){
        check(nd_view_retain(&a.blocks, &extra) == OTI_OK, "soa busy: nd_view_retain");
        m2 = oti_meta_retain(a.meta);
        check(m2 == a.meta, "soa busy: oti_meta_retain returns the meta");
    } else {
        check(nd_export(&a.blocks, 1, &extra) == OTI_OK, "soa busy: nd_export");
    }

    st = oarr_add_bases(5, &a);
    snprintf(msg, sizeof(msg), "soa busy (%s): oarr_add_bases -> BUSY", tag);
    check(st == OTI_ERR_BUSY, msg);
    snprintf(msg, sizeof(msg), "soa busy (%s): array unchanged after add_bases", tag);
    check(soa_unchanged(&a, &snap, data0), msg);

    st = oarr_reserve(&a, 9, 3, 4, 2);
    snprintf(msg, sizeof(msg), "soa busy (%s): oarr_reserve (growth) -> BUSY", tag);
    check(st == OTI_ERR_BUSY, msg);
    snprintf(msg, sizeof(msg), "soa busy (%s): array unchanged after reserve", tag);
    check(soa_unchanged(&a, &snap, data0), msg);

    st = oarr_reserve(&a, 2, 5, 6, 2);
    snprintf(msg, sizeof(msg), "soa busy (%s): oarr_reserve (new size) -> BUSY", tag);
    check(st == OTI_ERR_BUSY, msg);
    snprintf(msg, sizeof(msg), "soa busy (%s): array unchanged after resize", tag);
    check(soa_unchanged(&a, &snap, data0), msg);

    st = oarr_add_bases(2, &a);
    snprintf(msg, sizeof(msg), "soa busy (%s): add_bases to the current nact is OK", tag);
    check(st == OTI_OK && soa_unchanged(&a, &snap, data0), msg);

    nd_release(&extra);
    if (m2 != NULL){
        oti_meta_release(&m2);
    }
    check(extra.buf == NULL, "soa busy: extra released");

    st = oarr_add_bases(5, &a);
    snprintf(msg, sizeof(msg), "soa busy (%s): add_bases succeeds after release", tag);
    check(st == OTI_OK && oarr_nact(&a) == 5, msg);
    if (st == OTI_OK){
        // the old blocks keep their values at their new offsets: the real block and order 1 (bases 1-2)
        check(oarr_data(&a)[0] == 10.0 && oarr_data(&a)[1] == 11.0, "soa busy: real block kept");
    }
    oarr_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_view_as_res(void){

    oarr_t a = oarr_init();
    oarr_t b = oarr_init();
    oarr_t v = oarr_init();
    oarr_t snap;
    const coeff_t* data0;
    dhelpl_t dhl;
    int st;

    dhelp_load(NULL, &dhl);
    check(oarr_zeros_to(2, 3, 4, 2, &a) == OTI_OK, "view res: zeros a");
    check(oarr_zeros_to(2, 3, 4, 2, &b) == OTI_OK, "view res: zeros b");
    fill_soa(&a);
    fill_soa(&b);
    check(oarr_view_matrix(&a, 4, 3, &v) == OTI_OK, "view res: view_matrix");
    check(!oarr_owns(&v), "view res: view does not own");
    snap = v;
    data0 = oarr_data(&v);

    st = oarr_mul_OO_to(&a, &b, &v, dhl);   // shapes differ from the view's: a layout change
    check(st == VIEW_RES_STATUS, "view res: oarr_mul_OO_to(non-owning res) status");
    check(oarr_data(&v) == data0 && v.blocks.buf == snap.blocks.buf && v.meta == snap.meta
          && !oarr_owns(&v), "view res: view left as it was (no redirect to a new buffer)");
    check(soa_unchanged(&a, &a, oarr_data(&a)), "view res: a unchanged");

    oarr_free(&v);
    oarr_free(&a);
    oarr_free(&b);
    dhelp_free(&dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_aos_resize_busy(void){

    int kind;

    for (kind = 0; kind < 2; kind++){

        const char* tag = (kind == 0) ? "second reference" : "export";
        char msg[160];
        arro_t a = arro_init();
        ndarr_t extra;
        otinum_t* data0;
        int st;

        memset(&extra, 0, sizeof(extra));
        check(arro_zeros_to(3, 4, 2, &a) == OTI_OK, "aos busy: zeros_to");
        arro_data(&a)[5].re = 42.0;
        data0 = arro_data(&a);

        if (kind == 0){
            check(nd_view_retain(&a.elems, &extra) == OTI_OK, "aos busy: nd_view_retain");
        } else {
            check(nd_export(&a.elems, 1, &extra) == OTI_OK, "aos busy: nd_export");
        }

        st = arro_resize(5, 6, 2, &a);
        snprintf(msg, sizeof(msg), "aos busy (%s): arro_resize (new size) -> BUSY", tag);
        check(st == OTI_ERR_BUSY, msg);
        snprintf(msg, sizeof(msg), "aos busy (%s): array unchanged", tag);
        check(arro_data(&a) == data0 && arro_nrows(&a) == 3 && arro_ncols(&a) == 4
              && arro_data(&a)[5].re == 42.0, msg);
        snprintf(msg, sizeof(msg), "aos busy (%s): the extra reference still sees the elements", tag);
        check(((otinum_t*)extra.data) == data0, msg);

        nd_release(&extra);
        st = arro_resize(5, 6, 2, &a);
        snprintf(msg, sizeof(msg), "aos busy (%s): arro_resize succeeds after release", tag);
        check(st == OTI_OK && arro_nrows(&a) == 5 && arro_ncols(&a) == 6
              && arro_data(&a)[5].re == 42.0, msg);
        arro_free(&a);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_zero_skip_nonfinite(void){

    enum { NR = 128, NC = 96, NEL = NR * NC, CH = 4096 };
    int threads[3] = {1, 2, 4};
    coeff_t* got[3];
    dhelpl_t dhl;
    int t, i;
    int same = 1;
    int allnan = 1;
    int tail_ok = 1;

    dhelp_load(NULL, &dhl);

    for (t = 0; t < 3; t++){

        oarr_t a = oarr_init();
        oarr_t b = oarr_init();
        oarr_t r = oarr_init();
        int st;

        check(oarr_zeros_to(1, NR, NC, 1, &a) == OTI_OK, "zero skip: zeros a");
        check(oarr_zeros_to(1, NR, NC, 1, &b) == OTI_OK, "zero skip: zeros b");
        oarr_set_act_order(&a, 1);   // oarr_zeros_to() leaves act_order = 0: order 1 would be ignored
        oarr_set_act_order(&b, 1);
        for (i = 0; i < NEL; i++){
            oarr_data(&a)[i] = 1.0;                                  // real part
            oarr_data(&a)[oarr_bstride(&a) + i] = (i < CH) ? 0.0 : 1.0; // direction 1: zero over chunk 0
            oarr_data(&b)[i] = (i < CH) ? INFINITY : 1.0;            // real part: inf over chunk 0
            oarr_data(&b)[oarr_bstride(&b) + i] = 1.0;
        }

#ifdef _OPENMP
        omp_set_num_threads(threads[t]);
#endif
        st = oarr_mul_OO_to(&a, &b, &r, dhl);
        check(st == OTI_OK, "zero skip: mul_OO status");

        got[t] = (coeff_t*)malloc((size_t)(2 * NEL) * sizeof(coeff_t));
        check(got[t] != NULL, "zero skip: result copy");
        if (got[t] != NULL){
            for (i = 0; i < NEL; i++){
                got[t][i] = oarr_data(&r)[i];
                got[t][NEL + i] = oarr_data(&r)[oarr_bstride(&r) + i];
            }
        }
        oarr_free(&a);
        oarr_free(&b);
        oarr_free(&r);

    }
#ifdef _OPENMP
    omp_set_num_threads(omp_get_num_procs());
#endif

    if (got[0] != NULL && got[1] != NULL && got[2] != NULL){
        for (t = 1; t < 3; t++){
            if (memcmp(got[0], got[t], (size_t)(2 * NEL) * sizeof(coeff_t)) != 0){
                // nan compares unequal as a value, so compare per element: both nan or equal
                for (i = 0; i < 2 * NEL; i++){
                    if (!((isnan(got[0][i]) && isnan(got[t][i])) || got[0][i] == got[t][i])){
                        same = 0;
                    }
                }
            }
        }
        // 1.x with one thread: the block of A (direction 1) is not zero over the whole range, so no
        // skip: 0 * inf = nan in the first 4096 elements of the direction block, 2 afterwards; the real
        // block is inf over chunk 0 and 1 afterwards.
        for (i = 0; i < CH; i++){
            allnan = allnan && isnan(got[0][NEL + i]);
        }
        for (i = CH; i < NEL; i++){
            tail_ok = tail_ok && got[0][NEL + i] == 2.0 && got[0][i] == 1.0;
        }
        for (i = 0; i < CH; i++){
            tail_ok = tail_ok && isinf(got[0][i]);
        }
    } else {
        same = allnan = tail_ok = 0;
    }
    check(same, "zero skip: result identical at 1, 2 and 4 threads");
    check(allnan, "zero skip: 0 * inf = nan over the zero chunk (1.x one-thread value)");
    check(tail_ok, "zero skip: the rest of the result (inf, 1 and 2) as in 1.x");

    for (t = 0; t < 3; t++){
        free(got[t]);
    }
    dhelp_free(&dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_soa_busy(0);
    test_soa_busy(1);
    test_view_as_res();
    test_aos_resize_busy();
    test_zero_skip_nonfinite();

    if (n_failed != 0){
        fprintf(stderr, "%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("all checks passed\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
