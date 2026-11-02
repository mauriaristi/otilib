/* Confirming checks for the adversarial review of src/c/semisparse/{scalar/memory,scalar/algebra,
 * scalar/functions,soa/kernels,soa/linalg}.c, src/c/semisparse/array/array.c and
 * src/c/core/semisparse_helper.c (round 1, see /tmp/sscore_review.md), and of
 * src/c/semisparse/{soa/base,soa/algebra}.c and src/c/semisparse/scalar/base.c (round 2, see
 * /tmp/sscore_review2.md).
 *
 * Round 1 finding: oarrss_lu_solve() (src/c/semisparse/soa/linalg.c) conflated "the scratch buffer
 * allocation failed" with "the operand's own buffer is NULL because it is a legitimately empty
 * (zero-sized) array" (oarrss_zeros() sets p_data = NULL whenever nbytes == 0, e.g. for a 0-row or
 * 0-column matrix). Solving a 0x0 (or any n == 0) system spuriously returned OTI_LINALG_ERR_MEMORY
 * instead of the trivial empty solution. Since fixed; these checks now pass.
 *
 * Round 2 finding: oarrss_truncate_order_to() (src/c/semisparse/soa/base.c) shrinks trc_order to
 * order-1 instead of keeping it (zeroing the removed orders in place), unlike its scalar
 * counterpart ssoti_truncate_order_to() and its own documented contract ("array version of
 * ssoti_truncate_order()"). See test_truncate_order_keeps_trc_order() below. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <oti/oti.h>

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
/* oarrss_lu_solve()/oarrss_solve_to() on a 0x0 matrix: oarrss_zeros() legitimately leaves p_data
 * NULL for a zero-sized array (src/c/semisparse/soa/base.c, oarrss_zeros(): "p_data = (nbytes > 0)
 * ? calloc(...) : NULL"). oarrss_lu_solve() (src/c/semisparse/soa/linalg.c:144) then reads that
 * NULL through `Au = A->p_data` (since A->nbases == nu == 0, the "own the union" branch) and
 * reports it as an allocation failure: `if (X == NULL || work == NULL || Au == NULL){ status =
 * OTI_LINALG_ERR_MEMORY; ... }`. A 0x0 linear system has the trivial empty solution and should
 * report status 0, matching oarrss_det_to()'s own explicit `n == 0` early return (which does not
 * have this problem). Suggested fix: check `A->nrows == 0` (or `Au == NULL && sa > 0`) instead of
 * treating any NULL Au as an out-of-memory condition. */
static void test_lu_solve_empty_matrix(dhelpl_t dhl){

    oarrss_t K = oarrss_zeros(NULL, 0, 0, 0, 5);
    oarrss_t b = oarrss_zeros(NULL, 0, 0, 3, 5);
    oarrss_t x = oarrss_init();
    int status;

    check(K.p_data == NULL, "setup: oarrss_zeros(0x0) legitimately leaves p_data NULL");

    status = oarrss_solve_to(&K, &b, &x, dhl);

    check(status == 0,
        "oarrss_solve_to on a 0x0 matrix returns OK, not OTI_LINALG_ERR_MEMORY (-2)");
    check(x.nrows == 0 && x.ncols == 3, "oarrss_solve_to on a 0x0 matrix gives a 0x3 solution");

    oarrss_free(&K);
    oarrss_free(&b);
    oarrss_free(&x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Same root cause through oarrss_inv_to() (A^-1 of a 0x0 matrix is the 0x0 matrix, det 1). */
static void test_inv_empty_matrix(dhelpl_t dhl){

    oarrss_t K = oarrss_zeros(NULL, 0, 0, 0, 5);
    oarrss_t res = oarrss_init();
    int status;

    status = oarrss_inv_to(&K, &res, dhl);

    check(status == 0, "oarrss_inv_to on a 0x0 matrix returns OK, not OTI_LINALG_ERR_MEMORY (-2)");
    check(res.nrows == 0 && res.ncols == 0, "oarrss_inv_to on a 0x0 matrix gives a 0x0 result");

    oarrss_free(&K);
    oarrss_free(&res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Sanity check that oarrss_det_to (which has its own explicit n == 0 early return) does NOT share
 * this bug, for contrast. */
static void test_det_empty_matrix(dhelpl_t dhl){

    oarrss_t K = oarrss_zeros(NULL, 0, 0, 0, 5);
    ssotinum_t det = ssoti_init();
    int status;

    status = oarrss_det_to(&K, &det, dhl);

    check(status == 0, "oarrss_det_to on a 0x0 matrix returns OK");
    check(det.re == 1.0, "oarrss_det_to on a 0x0 matrix is 1 (empty product), by convention");

    ssoti_free(&det);
    oarrss_free(&K);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* oarrss_truncate_order_to() must keep trc_order (zeroing orders >= `order` and lowering act_order,
 * same as ssoti_truncate_order_to() and the documented "array version of ssoti_truncate_order()"
 * contract in include/oti/semisparse/soa/base.h), not shrink it to order-1. Confirmed by comparing
 * against ssoti_truncate_order() applied directly to the same element, and by checking that the
 * truncated-away order-4 coefficient is still reachable (as a zero) at the array's own trc_order. */
static void test_truncate_order_keeps_trc_order(void){

    bases_t bases[2] = {1, 2};
    oarrss_t A = oarrss_zeros(bases, 2, 2, 2, 5);
    oarrss_t res = oarrss_init();
    ssotinum_t elem, expected;
    bases_t g4[4] = {1, 1, 2, 2};
    imdir_t gidx4;

    oarrss_set_item_r(1.0, 0, 0, &A);

    {
        bases_t g1[1] = {1};
        imdir_t gidx1 = sshelp_global_rank(g1, 1);
        ssotinum_t e = oarrss_get_item(0, 0, &A);
        ssoti_set_item(0.5, gidx1, 1, &e);
        oarrss_set_item(&e, 0, 0, &A);
        ssoti_free(&e);
    }

    gidx4 = sshelp_global_rank(g4, 4);
    {
        ssotinum_t e = oarrss_get_item(0, 0, &A);
        ssoti_set_item(0.3, gidx4, 4, &e);
        oarrss_set_item(&e, 0, 0, &A);
        ssoti_free(&e);
    }

    elem = oarrss_get_item(0, 0, &A);
    expected = ssoti_truncate_order(3, &elem);

    check(expected.trc_order == A.trc_order,
        "setup: the scalar reference keeps trc_order (ssoti_truncate_order_to's own contract)");

    oarrss_truncate_order_to(3, &A, &res);

    check(res.trc_order == A.trc_order,
        "oarrss_truncate_order_to keeps trc_order (matches ssoti_truncate_order_to / its own doc)");
    check(res.act_order <= 2, "oarrss_truncate_order_to lowers act_order to at most order - 1");

    {
        ssotinum_t e = oarrss_get_item(0, 0, &res);

        check(e.trc_order == A.trc_order,
            "oarrss_truncate_order_to result element keeps trc_order");
        check(ssoti_get_item(gidx4, 4, &e) == 0.0,
            "oarrss_truncate_order_to zeroes the truncated order-4 direction");
        ssoti_free(&e);
    }

    ssoti_free(&elem);
    ssoti_free(&expected);
    oarrss_free(&A);
    oarrss_free(&res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);

    test_lu_solve_empty_matrix(dhl);
    test_inv_empty_matrix(dhl);
    test_det_empty_matrix(dhl);
    test_truncate_order_keeps_trc_order();

    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse review check(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse review checks passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
