// Tests of the LAPACK / BLAS C wrappers and the provider table (include/oti/core/lapack.h,
// src/c/core/lapack.c and lapack_provider.c; PLAN-ndarray-contracts.md 8 and 5.5).
//
// - Every wrapper against the linked provider (OpenBLAS or Accelerate): 32-bit integers, column-major
//   arrays, CHARACTER flags by address, negative increments for the level-1 routines that take them.
// - Both hidden-length conventions, with recording fake providers injected by
//   oti_lapack_provider_set(): END_SIZE_T must append one size_t 1 per CHARACTER argument in
//   argument order, NONE none.
// - The probe: vendor and convention equal the build-time values (lapack_config.h); name and caps are
//   printed. oti_lapack_lwork(), the int-limit hook, the provider rejections and the BLAS scopes.
#include <dlfcn.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oti/oti.h>
#include "oti/core/exec.h"
#include "oti/core/lapack_config.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

#define TOL 1e-12

static int n_failed = 0;


// *******************************************************************************************************
static void check_close(const char* label, double got, double expected){

    // isfinite first: a NaN would make the tolerance test below false and pass silently.
    if (!isfinite(got) || fabs(got - expected) > TOL * (1.0 + fabs(expected))){

        fprintf(stderr, "FAILED %s: got %.17g, expected %.17g\n", label, got, expected);
        n_failed++;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_getrf_getrs(void){

    // Column-major 4x4 matrix with a zero leading entry, so dgetrf must pivot.
    // Row-major view:
    //   [ 0  2  1  0 ]
    //   [ 1  0  0  3 ]
    //   [ 2  1  4  0 ]
    //   [ 0  1  0  5 ]
    double a[16] = { 0.0, 1.0, 2.0, 0.0,
                     2.0, 0.0, 1.0, 1.0,
                     1.0, 0.0, 4.0, 0.0,
                     0.0, 3.0, 0.0, 5.0 };
    double x_expected[4] = { 1.0, -2.0, 3.0, 0.5 };
    double b[4];
    int ipiv[4];
    int info = -1;
    int i, j;

    // b = A x_expected.
    for (i = 0; i < 4; i++){

        b[i] = 0.0;

        for (j = 0; j < 4; j++){
            b[i] += a[i + 4 * j] * x_expected[j];
        }

    }

    oti_dgetrf(4, 4, a, 4, ipiv, &info);

    if (info != 0){
        fprintf(stderr, "FAILED dgetrf: info = %d\n", info);
        n_failed++;
        return;
    }

    // Partial pivoting picks the largest entry of column 1 (row 3, value 2).
    if (ipiv[0] != 3){
        fprintf(stderr, "FAILED dgetrf pivot: ipiv[0] = %d, expected 3\n", ipiv[0]);
        n_failed++;
    }

    oti_dgetrs('N', 4, 1, a, 4, ipiv, b, 4, &info);

    if (info != 0){
        fprintf(stderr, "FAILED dgetrs: info = %d\n", info);
        n_failed++;
        return;
    }

    for (i = 0; i < 4; i++){
        check_close("dgetrs solution", b[i], x_expected[i]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_getrs_transposed_padded(void){

    // Same 4x4 matrix as test_getrf_getrs, stored with a padded leading dimension (lda = 6). The
    // padding rows hold a sentinel that LAPACK must not touch.
    //   [ 0  2  1  0 ]
    //   [ 1  0  0  3 ]
    //   [ 2  1  4  0 ]
    //   [ 0  1  0  5 ]
    const double a_rm[4][4] = { { 0.0, 2.0, 1.0, 0.0 },
                                { 1.0, 0.0, 0.0, 3.0 },
                                { 2.0, 1.0, 4.0, 0.0 },
                                { 0.0, 1.0, 0.0, 5.0 } };
    // Two right-hand sides (columns of X), stored with ldb = 5.
    const double x_expected[2][4] = { { 1.0, -2.0,  3.0, 0.5 },
                                      { 0.0,  1.0, -1.0, 2.0 } };
    const double sentinel = 99.0;
    double a[6 * 4];
    double b[5 * 2];
    int ipiv[4];
    int info = -1;
    int i, j, k;

    for (i = 0; i < 6 * 4; i++){
        a[i] = sentinel;
    }

    for (i = 0; i < 5 * 2; i++){
        b[i] = sentinel;
    }

    for (i = 0; i < 4; i++){

        for (j = 0; j < 4; j++){
            a[i + 6 * j] = a_rm[i][j];
        }

    }

    // B = A^T X, so that dgetrs('T') must recover X.
    for (k = 0; k < 2; k++){

        for (i = 0; i < 4; i++){

            b[i + 5 * k] = 0.0;

            for (j = 0; j < 4; j++){
                b[i + 5 * k] += a_rm[j][i] * x_expected[k][j];
            }

        }

    }

    oti_dgetrf(4, 4, a, 6, ipiv, &info);

    if (info != 0){
        fprintf(stderr, "FAILED dgetrf (lda = 6): info = %d\n", info);
        n_failed++;
        return;
    }

    oti_dgetrs('T', 4, 2, a, 6, ipiv, b, 5, &info);

    if (info != 0){
        fprintf(stderr, "FAILED dgetrs('T'): info = %d\n", info);
        n_failed++;
        return;
    }

    for (k = 0; k < 2; k++){

        for (i = 0; i < 4; i++){
            check_close("dgetrs('T') two rhs", b[i + 5 * k], x_expected[k][i]);
        }

        check_close("dgetrs ldb padding untouched", b[4 + 5 * k], sentinel);

    }

    for (j = 0; j < 4; j++){
        check_close("dgetrf lda padding untouched (row 5)", a[4 + 6 * j], sentinel);
        check_close("dgetrf lda padding untouched (row 6)", a[5 + 6 * j], sentinel);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_getrf_singular(void){

    // Rank-1 matrix: dgetrf must report a zero pivot (info > 0).
    double a[4] = { 1.0, 2.0, 2.0, 4.0 };
    int ipiv[2];
    int info = 0;

    oti_dgetrf(2, 2, a, 2, ipiv, &info);

    if (info <= 0){
        fprintf(stderr, "FAILED dgetrf singular: info = %d, expected > 0\n", info);
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_trsm_trmm(void){

    // Lower triangular L = [[2, 0], [1, 3]] (column-major), non-unit diagonal.
    double l[4] = { 2.0, 1.0, 0.0, 3.0 };
    // Two right-hand sides (columns): L X = B with X = [[2, -1], [1, 4]].
    double b[4] = { 4.0, 5.0, -2.0, 11.0 };
    double x_expected[4] = { 2.0, 1.0, -1.0, 4.0 };
    // Row vector for the right-side solve: y L = c with y = [1, 2] -> c = [4, 6].
    double c[2] = { 4.0, 6.0 };
    int i;

    oti_dtrsm('L', 'L', 'N', 'N', 2, 2, 1.0, l, 2, b, 2);

    for (i = 0; i < 4; i++){
        check_close("dtrsm left", b[i], x_expected[i]);
    }

    // Multiply back with alpha = 2: B = 2 L X.
    oti_dtrmm('L', 'L', 'N', 'N', 2, 2, 2.0, l, 2, b, 2);
    check_close("dtrmm left (0,0)", b[0],  8.0);
    check_close("dtrmm left (1,0)", b[1], 10.0);
    check_close("dtrmm left (0,1)", b[2], -4.0);
    check_close("dtrmm left (1,1)", b[3], 22.0);

    oti_dtrsm('R', 'L', 'N', 'N', 1, 2, 1.0, l, 2, c, 1);
    check_close("dtrsm right (0)", c[0], 1.0);
    check_close("dtrsm right (1)", c[1], 2.0);

    // Multiply back from the right: c = y L = [4, 6].
    oti_dtrmm('R', 'L', 'N', 'N', 1, 2, 1.0, l, 2, c, 1);
    check_close("dtrmm right (0)", c[0], 4.0);
    check_close("dtrmm right (1)", c[1], 6.0);

    // Transposed, unit diagonal: L1^T y = [3, 1] with L1 = [[1, 0], [1, 1]] -> y = [2, 1].
    c[0] = 3.0;
    c[1] = 1.0;
    oti_dtrsm('L', 'L', 'T', 'U', 2, 1, 1.0, l, 2, c, 2);
    check_close("dtrsm transposed unit (0)", c[0], 2.0);
    check_close("dtrsm transposed unit (1)", c[1], 1.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void store_op_matrix(double* dst, int ld, char trans, int op_rows, int op_cols,
                            const double* logical){

    // Fills dst (column-major, leading dimension ld) with the matrix BLAS must read so that
    // op(dst) equals the op_rows x op_cols row-major "logical" matrix.
    int i, j;

    if (trans == 'N'){

        for (j = 0; j < op_cols; j++){

            for (i = 0; i < op_rows; i++){
                dst[i + ld * j] = logical[i * op_cols + j];
            }

        }

    } else {

        for (j = 0; j < op_rows; j++){

            for (i = 0; i < op_cols; i++){
                dst[i + ld * j] = logical[j * op_cols + i];
            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void run_dgemm_case(const char* label, char transa, char transb, double alpha, double beta,
                           int nan_fill){

    // Non-square op(A) (m x k) times op(B) (k x n), checked against a naive triple loop. lda, ldb
    // and ldc are all padded beyond the minimum, and the ldc padding is checked untouched afterwards.
    const int m = 3, n = 2, k = 4;
    static const double logical_a[12] = { 1.0, 2.0, 3.0, 4.0,
                                          5.0, 6.0, 7.0, 8.0,
                                          9.0, 10.0, 11.0, 12.0 };
    static const double logical_b[8] = { 1.0, 2.0,
                                         3.0, 4.0,
                                         5.0, 6.0,
                                         7.0, 8.0 };
    static const double c_init[6] = { 100.0, 200.0, 300.0, 400.0, 500.0, 600.0 };
    const double sentinel = 12345.0;
    int a_rows = (transa == 'N') ? m : k;
    int a_cols = (transa == 'N') ? k : m;
    int b_rows = (transb == 'N') ? k : n;
    int b_cols = (transb == 'N') ? n : k;
    int lda = a_rows + 2;
    int ldb = b_rows + 2;
    int ldc = m + 2;
    double a_buf[80], b_buf[80], c_buf[40];
    double c_ref[6];
    char msg[128];
    int i, j, p;

    for (i = 0; i < lda * a_cols; i++){
        a_buf[i] = sentinel;
    }

    for (i = 0; i < ldb * b_cols; i++){
        b_buf[i] = sentinel;
    }

    for (j = 0; j < n; j++){

        for (i = 0; i < ldc; i++){
            c_buf[i + ldc * j] = (i < m) ? (nan_fill ? NAN : c_init[i * n + j]) : sentinel;
        }

    }

    store_op_matrix(a_buf, lda, transa, m, k, logical_a);
    store_op_matrix(b_buf, ldb, transb, k, n, logical_b);

    for (i = 0; i < m; i++){

        for (j = 0; j < n; j++){

            double sum = 0.0;

            for (p = 0; p < k; p++){
                sum += logical_a[i * k + p] * logical_b[p * n + j];
            }

            // beta == 0 must not read the (possibly NaN) initial C, matching the BLAS contract.
            c_ref[i * n + j] = (beta == 0.0) ? alpha * sum : alpha * sum + beta * c_init[i * n + j];

        }

    }

    oti_dgemm(transa, transb, m, n, k, alpha, a_buf, lda, b_buf, ldb, beta, c_buf, ldc);

    for (i = 0; i < m; i++){

        for (j = 0; j < n; j++){
            snprintf(msg, sizeof(msg), "dgemm %s (%d,%d)", label, i, j);
            check_close(msg, c_buf[i + ldc * j], c_ref[i * n + j]);
        }

    }

    for (j = 0; j < n; j++){
        snprintf(msg, sizeof(msg), "dgemm %s ldc padding untouched (col %d)", label, j);
        check_close(msg, c_buf[m + ldc * j], sentinel);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_dgemm(void){

    run_dgemm_case("NN", 'N', 'N', 1.0, 0.0, 1);
    run_dgemm_case("NT", 'N', 'T', 1.0, 0.0, 1);
    run_dgemm_case("TN", 'T', 'N', 1.0, 0.0, 1);
    run_dgemm_case("TT", 'T', 'T', 1.0, 0.0, 1);
    run_dgemm_case("beta1 accumulate", 'N', 'N', 1.0, 1.0, 0);
    run_dgemm_case("alpha=-1", 'N', 'N', -1.0, 0.0, 1);
    run_dgemm_case("alpha=-1 beta=1", 'T', 'N', -1.0, 1.0, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void check_int(const char* label, long long got, long long expected){

    if (got != expected){
        fprintf(stderr, "FAILED %s: got %lld, expected %lld\n", label, got, expected);
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_level1(void){

    double x[3] = { 1.0, 2.0, 3.0 };
    double y[3] = { 4.0, 5.0, 6.0 };
    double z[3];
    double v[3] = { -1.0, 2.0, -3.0 };
    double w[4] = { 1.0, -5.0, 5.0, 2.0 };
    double nrm[2] = { 3.0, 4.0 };

    check_close("ddot", oti_ddot(3, x, 1, y, 1), 32.0);
    // A negative increment: x points at the lowest address and is visited from its end (NumPy order
    // of the reversed vector x[::-1] = (3, 2, 1)).
    check_close("ddot incx = -1", oti_ddot(3, x, -1, y, 1), 28.0);
    check_close("ddot n = 0", oti_ddot(0, x, 1, y, 1), 0.0);
    check_close("ddot stride 2", oti_ddot(2, x, 2, y, 2), 1.0 * 4.0 + 3.0 * 6.0);

    oti_daxpy(3, 2.0, x, 1, y, 1);
    check_close("daxpy 0", y[0], 6.0);
    check_close("daxpy 2", y[2], 12.0);
    oti_daxpy(3, 1.0, x, -1, y, 1);                 // y += x[::-1]
    check_close("daxpy incx = -1 0", y[0], 9.0);
    check_close("daxpy incx = -1 2", y[2], 13.0);

    oti_dcopy(3, x, 1, z, -1);                      // z[::-1] = x
    check_close("dcopy incy = -1 0", z[0], 3.0);
    check_close("dcopy incy = -1 2", z[2], 1.0);

    oti_dswap(3, x, 1, z, 1);
    check_close("dswap x0", x[0], 3.0);
    check_close("dswap z0", z[0], 1.0);
    oti_dswap(3, x, -1, z, 1);                      // swap x[::-1] with z
    check_close("dswap incx = -1 x0", x[0], 3.0);
    check_close("dswap incx = -1 z0", z[0], 1.0);
    check_close("dswap incx = -1 x2", x[2], 1.0);

    oti_dscal(3, -2.0, v, 1);
    check_close("dscal 0", v[0], 2.0);
    check_close("dscal 2", v[2], 6.0);

    check_close("dnrm2", oti_dnrm2(2, nrm, 1), 5.0);
    check_close("dnrm2 n = 0", oti_dnrm2(0, nrm, 1), 0.0);
    check_close("dasum", oti_dasum(3, v, 1), 2.0 + 4.0 + 6.0);
    check_close("dasum stride 2", oti_dasum(2, w, 2), 6.0);

    // First occurrence of the largest |w_i| (1-based); 0 for n < 1 or incx <= 0 (no provider call).
    check_int("idamax", oti_idamax(4, w, 1), 2);
    check_int("idamax n = 0", oti_idamax(0, w, 1), 0);
    check_int("idamax incx = 0", oti_idamax(4, w, 0), 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_level2_3(void){

    // A = [[1, 2, 3], [4, 5, 6]] column-major (2 x 3), lda = 2.
    double a[6] = { 1.0, 4.0, 2.0, 5.0, 3.0, 6.0 };
    double x3[3] = { 1.0, 0.0, -1.0 };
    double x2[2] = { 1.0, 2.0 };
    double y2[2] = { NAN, NAN };
    double y3[3] = { 1.0, 1.0, 1.0 };
    double g[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    double c[4] = { NAN, NAN, -7.0, NAN };

    // beta = 0 must not read the NaN in y.
    oti_dgemv('N', 2, 3, 1.0, a, 2, x3, 1, 0.0, y2, 1);
    check_close("dgemv N 0", y2[0], -2.0);
    check_close("dgemv N 1", y2[1], -2.0);

    oti_dgemv('T', 2, 3, 2.0, a, 2, x2, 1, 1.0, y3, 1);
    check_close("dgemv T 0", y3[0], 1.0 + 2.0 * 9.0);
    check_close("dgemv T 2", y3[2], 1.0 + 2.0 * 15.0);

    oti_dger(2, 3, 1.0, x2, 1, x3, 1, g, 2);        // g = x2 x3^T
    check_close("dger (0,0)", g[0], 1.0);
    check_close("dger (1,0)", g[1], 2.0);
    check_close("dger (1,2)", g[5], -2.0);

    // Upper triangle of C = A A^T = [[14, 32], [32, 77]]; c[1] (strictly lower) is not referenced.
    oti_dsyrk('U', 'N', 2, 3, 1.0, a, 2, 0.0, c, 2);
    check_close("dsyrk (0,0)", c[0], 14.0);
    check_close("dsyrk (0,1)", c[2], 32.0);
    check_close("dsyrk (1,1)", c[3], 77.0);

    if (!isnan(c[1])){
        fprintf(stderr, "FAILED dsyrk wrote the lower triangle\n");
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_lapack_tier1(void){

    double a[4];
    double b[2];
    double work[1024];
    double s[4] = { 4.0, 2.0, 2.0, 3.0 };    // SPD [[4, 2], [2, 3]]
    double t[4] = { 1.0, 0.0, 2.0, 0.0 };    // upper [[1, 2], [0, 0]]: zero diagonal entry
    int ipiv[2];
    int info = -1;
    int lwork;

    // dgesv: [[2, 1], [1, 3]] x = [3, 5] -> x = [0.8, 1.4].
    a[0] = 2.0; a[1] = 1.0; a[2] = 1.0; a[3] = 3.0;
    b[0] = 3.0; b[1] = 5.0;
    oti_dgesv(2, 1, a, 2, ipiv, b, 2, &info);
    check_int("dgesv info", info, 0);
    check_close("dgesv x0", b[0], 0.8);
    check_close("dgesv x1", b[1], 1.4);

    // dgetri: inv([[4, 7], [2, 6]]) = [[0.6, -0.7], [-0.2, 0.4]], with a workspace query first.
    a[0] = 4.0; a[1] = 2.0; a[2] = 7.0; a[3] = 6.0;
    oti_dgetrf(2, 2, a, 2, ipiv, &info);
    check_int("dgetrf info", info, 0);
    oti_dgetri(2, a, 2, ipiv, work, -1, &info);
    check_int("dgetri query info", info, 0);
    check_int("dgetri lwork status", oti_lapack_lwork(work[0], 2, &lwork), OTI_OK);

    if (lwork < 2 || lwork > 1024){
        fprintf(stderr, "FAILED dgetri lwork = %d\n", lwork);
        n_failed++;
        lwork = 1024;
    }

    oti_dgetri(2, a, 2, ipiv, work, lwork, &info);
    check_int("dgetri info", info, 0);
    check_close("dgetri (0,0)", a[0], 0.6);
    check_close("dgetri (1,0)", a[1], -0.2);
    check_close("dgetri (0,1)", a[2], -0.7);
    check_close("dgetri (1,1)", a[3], 0.4);

    // dpotrf 'L': L = [[2, 0], [1, sqrt(2)]]; dpotrs solves [[4, 2], [2, 3]] x = [6, 5] -> [1, 1].
    oti_dpotrf('L', 2, s, 2, &info);
    check_int("dpotrf info", info, 0);
    check_close("dpotrf L00", s[0], 2.0);
    check_close("dpotrf L10", s[1], 1.0);
    check_close("dpotrf L11", s[3], sqrt(2.0));
    b[0] = 6.0; b[1] = 5.0;
    oti_dpotrs('L', 2, 1, s, 2, b, 2, &info);
    check_int("dpotrs info", info, 0);
    check_close("dpotrs x0", b[0], 1.0);
    check_close("dpotrs x1", b[1], 1.0);

    // Not positive definite: info > 0.
    a[0] = 1.0; a[1] = 2.0; a[2] = 2.0; a[3] = 1.0;
    oti_dpotrf('U', 2, a, 2, &info);

    if (info <= 0){
        fprintf(stderr, "FAILED dpotrf not PD: info = %d\n", info);
        n_failed++;
    }

    // dtrtrs: zero diagonal -> info = 2; then a regular upper solve [[1, 2], [0, 4]] x = [5, 8].
    b[0] = 1.0; b[1] = 1.0;
    oti_dtrtrs('U', 'N', 'N', 2, 1, t, 2, b, 2, &info);
    check_int("dtrtrs singular info", info, 2);
    t[3] = 4.0;
    b[0] = 5.0; b[1] = 8.0;
    oti_dtrtrs('U', 'N', 'N', 2, 1, t, 2, b, 2, &info);
    check_int("dtrtrs info", info, 0);
    check_close("dtrtrs x0", b[0], 1.0);
    check_close("dtrtrs x1", b[1], 2.0);
    // Transposed, unit diagonal: [[1, 0], [2, 1]] x = [1, 4] -> x = [1, 2].
    b[0] = 1.0; b[1] = 4.0;
    oti_dtrtrs('U', 'T', 'U', 2, 1, t, 2, b, 2, &info);
    check_int("dtrtrs T U info", info, 0);
    check_close("dtrtrs T U x1", b[1], 2.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_lapack_tier2(void){

    double a[6] = { 1.0, 1.0, 1.0, 0.0, 1.0, 2.0 };    // 3 x 2, columns (1,1,1) and (0,1,2)
    double q[6];
    double tau[2];
    double work[4096];
    double sv[3];
    double bls[3] = { 1.0, 2.0, 3.0 };                  // exactly 1 + 1 * t
    double sym[4] = { 2.0, 1.0, 1.0, 2.0 };
    double w[2];
    double gen[4] = { 0.0, -2.0, 1.0, -3.0 };           // [[0, 1], [-2, -3]]: eigenvalues -1, -2
    double wr[2], wi[2], dummy[1];
    double dg[4] = { 3.0, 0.0, 0.0, -2.0 };
    double u[4], vt[4];
    int iwork[64];
    int info = -1;
    int rank = -1;
    int i, j, k;

    // dgeqrf + dorgqr: Q (3 x 2) has orthonormal columns.
    memcpy(q, a, sizeof(q));
    oti_dgeqrf(3, 2, q, 3, tau, work, 256, &info);
    check_int("dgeqrf info", info, 0);
    oti_dorgqr(3, 2, 2, q, 3, tau, work, 256, &info);
    check_int("dorgqr info", info, 0);

    for (i = 0; i < 2; i++){

        for (j = 0; j < 2; j++){

            double d = 0.0;

            for (k = 0; k < 3; k++){
                d += q[k + 3 * i] * q[k + 3 * j];
            }

            check_close("dorgqr Q^T Q", d, i == j ? 1.0 : 0.0);

        }

    }

    // dgelsd: least squares of an exact line, after a workspace query (work[0], iwork[0]).
    memcpy(q, a, sizeof(q));
    oti_dgelsd(3, 2, 1, q, 3, bls, 3, sv, -1.0, &rank, work, -1, iwork, &info);
    check_int("dgelsd query info", info, 0);

    if (work[0] > 4096.0 || iwork[0] > 64){
        fprintf(stderr, "FAILED dgelsd workspace %g / %d too large for the test\n", work[0],
                iwork[0]);
        n_failed++;
        return;
    }

    oti_dgelsd(3, 2, 1, q, 3, bls, 3, sv, -1.0, &rank, work, 4096, iwork, &info);
    check_int("dgelsd info", info, 0);
    check_int("dgelsd rank", rank, 2);
    check_close("dgelsd x0", bls[0], 1.0);
    check_close("dgelsd x1", bls[1], 1.0);

    oti_dsyevd('N', 'L', 2, sym, 2, w, work, 256, iwork, 64, &info);
    check_int("dsyevd info", info, 0);
    check_close("dsyevd w0", w[0], 1.0);
    check_close("dsyevd w1", w[1], 3.0);

    oti_dgeev('N', 'N', 2, gen, 2, wr, wi, dummy, 1, dummy, 1, work, 256, &info);
    check_int("dgeev info", info, 0);
    check_close("dgeev product", wr[0] * wr[1], 2.0);
    check_close("dgeev sum", wr[0] + wr[1], -3.0);
    check_close("dgeev imag", fabs(wi[0]) + fabs(wi[1]), 0.0);

    oti_dgesdd('A', 2, 2, dg, 2, sv, u, 2, vt, 2, work, 256, iwork, &info);
    check_int("dgesdd info", info, 0);
    check_close("dgesdd s0", sv[0], 3.0);
    check_close("dgesdd s1", sv[1], 2.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_lwork_and_limits(void){

    int lwork = -7;

    check_int("lwork ceil", oti_lapack_lwork(10.2, 3, &lwork), OTI_OK);
    check_int("lwork ceil value", lwork, 11);
    check_int("lwork minimum", oti_lapack_lwork(2.0, 5, &lwork), OTI_OK);
    check_int("lwork minimum value", lwork, 5);
    check_int("lwork at least 1", oti_lapack_lwork(0.0, 0, &lwork), OTI_OK);
    check_int("lwork at least 1 value", lwork, 1);
    check_int("lwork INT_MAX", oti_lapack_lwork((double)INT_MAX, 1, &lwork), OTI_OK);
    check_int("lwork INT_MAX value", lwork, INT_MAX);
    lwork = -7;
    check_int("lwork NaN", oti_lapack_lwork(NAN, 1, &lwork), OTI_ERR_SIZE);
    check_int("lwork inf", oti_lapack_lwork(INFINITY, 1, &lwork), OTI_ERR_SIZE);
    check_int("lwork negative", oti_lapack_lwork(-1.0, 1, &lwork), OTI_ERR_SIZE);
    check_int("lwork above INT_MAX", oti_lapack_lwork((double)INT_MAX + 1.0, 1, &lwork),
              OTI_ERR_SIZE);
    check_int("lwork minimum above INT_MAX", oti_lapack_lwork(1.0, (int64_t)INT_MAX + 1, &lwork),
              OTI_ERR_SIZE);
    check_int("lwork untouched on failure", lwork, -7);

    check_int("fits_i64 INT_MAX", oti_lapack_fits_i64(INT_MAX), 1);
    check_int("fits_i64 -INT_MAX", oti_lapack_fits_i64(-(int64_t)INT_MAX), 1);
    check_int("fits_i64 INT_MIN", oti_lapack_fits_i64(INT_MIN), 0);
    check_int("fits_i64 INT_MAX + 1", oti_lapack_fits_i64((int64_t)INT_MAX + 1), 0);

    check_int("int limit default", oti_lapack_int_limit(), INT_MAX);
    oti_lapack_test_set_int_limit(7);
    check_int("int limit lowered", oti_lapack_int_limit(), 7);
    oti_lapack_test_set_int_limit(0);
    check_int("int limit restored", oti_lapack_int_limit(), INT_MAX);
    oti_lapack_test_set_int_limit(-3);
    check_int("int limit invalid", oti_lapack_int_limit(), INT_MAX);

}
// -------------------------------------------------------------------------------------------------------


// ------------------------------- Recording fake providers (both conventions) --------------------------

// Log of the last fake call: the CHARACTER flags and the hidden lengths it received.
static char   fk_chars[8];
static int    fk_nchars = 0;
static size_t fk_lens[8];
static int    fk_nlens = -1;
static int    fk_calls = 0;


// *******************************************************************************************************
static void fk_log(const char* flags, int nflags, const size_t* lens, int nlens){

    int i;

    fk_calls++;
    fk_nchars = nflags;
    fk_nlens  = nlens;

    for (i = 0; i < nflags; i++){
        fk_chars[i] = flags[i];
    }
    for (i = 0; i < nlens; i++){
        fk_lens[i] = lens[i];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dgetrs_fc(const char* t, const int* n, const int* r, const double* a, const int* la,
                         const int* p, double* b, const int* lb, int* info, size_t l1){

    size_t l[1];

    (void)n; (void)r; (void)a; (void)la; (void)p; (void)b; (void)lb;
    l[0] = l1;
    *info = 0;
    fk_log(t, 1, l, 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dgetrs_c(const char* t, const int* n, const int* r, const double* a, const int* la,
                        const int* p, double* b, const int* lb, int* info){

    (void)n; (void)r; (void)a; (void)la; (void)p; (void)b; (void)lb;
    *info = 0;
    fk_log(t, 1, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dtrxm_fc(const char* s, const char* u, const char* t, const char* d, const int* m,
                        const int* n, const double* al, const double* a, const int* la, double* b,
                        const int* lb, size_t l1, size_t l2, size_t l3, size_t l4){

    char f[4];
    size_t l[4];

    (void)m; (void)n; (void)al; (void)a; (void)la; (void)b; (void)lb;
    f[0] = *s; f[1] = *u; f[2] = *t; f[3] = *d;
    l[0] = l1; l[1] = l2; l[2] = l3; l[3] = l4;
    fk_log(f, 4, l, 4);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dtrxm_c(const char* s, const char* u, const char* t, const char* d, const int* m,
                       const int* n, const double* al, const double* a, const int* la, double* b,
                       const int* lb){

    char f[4];

    (void)m; (void)n; (void)al; (void)a; (void)la; (void)b; (void)lb;
    f[0] = *s; f[1] = *u; f[2] = *t; f[3] = *d;
    fk_log(f, 4, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dgemm_fc(const char* ta, const char* tb, const int* m, const int* n, const int* k,
                        const double* al, const double* a, const int* la, const double* b,
                        const int* lb, const double* be, double* c, const int* lc, size_t l1,
                        size_t l2){

    char f[2];
    size_t l[2];

    (void)m; (void)n; (void)k; (void)al; (void)a; (void)la; (void)b; (void)lb; (void)be; (void)c;
    (void)lc;
    f[0] = *ta; f[1] = *tb;
    l[0] = l1; l[1] = l2;
    fk_log(f, 2, l, 2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dgemm_c(const char* ta, const char* tb, const int* m, const int* n, const int* k,
                       const double* al, const double* a, const int* la, const double* b,
                       const int* lb, const double* be, double* c, const int* lc){

    char f[2];

    (void)m; (void)n; (void)k; (void)al; (void)a; (void)la; (void)b; (void)lb; (void)be; (void)c;
    (void)lc;
    f[0] = *ta; f[1] = *tb;
    fk_log(f, 2, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dgemv_fc(const char* t, const int* m, const int* n, const double* al, const double* a,
                        const int* la, const double* x, const int* ix, const double* be, double* y,
                        const int* iy, size_t l1){

    size_t l[1];

    (void)m; (void)n; (void)al; (void)a; (void)la; (void)x; (void)ix; (void)be; (void)y; (void)iy;
    l[0] = l1;
    fk_log(t, 1, l, 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dgemv_c(const char* t, const int* m, const int* n, const double* al, const double* a,
                       const int* la, const double* x, const int* ix, const double* be, double* y,
                       const int* iy){

    (void)m; (void)n; (void)al; (void)a; (void)la; (void)x; (void)ix; (void)be; (void)y; (void)iy;
    fk_log(t, 1, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dsyrk_fc(const char* u, const char* t, const int* n, const int* k, const double* al,
                        const double* a, const int* la, const double* be, double* c, const int* lc,
                        size_t l1, size_t l2){

    char f[2];
    size_t l[2];

    (void)n; (void)k; (void)al; (void)a; (void)la; (void)be; (void)c; (void)lc;
    f[0] = *u; f[1] = *t;
    l[0] = l1; l[1] = l2;
    fk_log(f, 2, l, 2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dsyrk_c(const char* u, const char* t, const int* n, const int* k, const double* al,
                       const double* a, const int* la, const double* be, double* c, const int* lc){

    char f[2];

    (void)n; (void)k; (void)al; (void)a; (void)la; (void)be; (void)c; (void)lc;
    f[0] = *u; f[1] = *t;
    fk_log(f, 2, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dpotrf_fc(const char* u, const int* n, double* a, const int* la, int* info, size_t l1){

    size_t l[1];

    (void)n; (void)a; (void)la;
    l[0] = l1;
    *info = 0;
    fk_log(u, 1, l, 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dpotrf_c(const char* u, const int* n, double* a, const int* la, int* info){

    (void)n; (void)a; (void)la;
    *info = 0;
    fk_log(u, 1, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dpotrs_fc(const char* u, const int* n, const int* r, const double* a, const int* la,
                         double* b, const int* lb, int* info, size_t l1){

    size_t l[1];

    (void)n; (void)r; (void)a; (void)la; (void)b; (void)lb;
    l[0] = l1;
    *info = 0;
    fk_log(u, 1, l, 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dpotrs_c(const char* u, const int* n, const int* r, const double* a, const int* la,
                        double* b, const int* lb, int* info){

    (void)n; (void)r; (void)a; (void)la; (void)b; (void)lb;
    *info = 0;
    fk_log(u, 1, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dtrtrs_fc(const char* u, const char* t, const char* d, const int* n, const int* r,
                         const double* a, const int* la, double* b, const int* lb, int* info,
                         size_t l1, size_t l2, size_t l3){

    char f[3];
    size_t l[3];

    (void)n; (void)r; (void)a; (void)la; (void)b; (void)lb;
    f[0] = *u; f[1] = *t; f[2] = *d;
    l[0] = l1; l[1] = l2; l[2] = l3;
    *info = 0;
    fk_log(f, 3, l, 3);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fk_dtrtrs_c(const char* u, const char* t, const char* d, const int* n, const int* r,
                        const double* a, const int* la, double* b, const int* lb, int* info){

    char f[3];

    (void)n; (void)r; (void)a; (void)la; (void)b; (void)lb;
    f[0] = *u; f[1] = *t; f[2] = *d;
    *info = 0;
    fk_log(f, 3, NULL, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks the log of the last fake call: flags in order, and the hidden lengths of the convention.
static void fk_expect(const char* label, const char* flags, int end_size_t){

    int n = (int)strlen(flags);
    int i;

    if (fk_calls != 1 || fk_nchars != n || memcmp(fk_chars, flags, (size_t)n) != 0){
        fprintf(stderr, "FAILED %s: calls %d, flags '%.*s', expected '%s'\n", label, fk_calls,
                fk_nchars, fk_chars, flags);
        n_failed++;
    }

    if (fk_nlens != (end_size_t ? n : 0)){
        fprintf(stderr, "FAILED %s: %d hidden lengths, expected %d\n", label, fk_nlens,
                end_size_t ? n : 0);
        n_failed++;
        return;
    }

    for (i = 0; i < fk_nlens; i++){
        if (fk_lens[i] != 1){
            fprintf(stderr, "FAILED %s: hidden length %d is %zu\n", label, i, fk_lens[i]);
            n_failed++;
        }
    }

    fk_calls = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Injects a fake provider of one convention (CHARACTER-taking slots replaced by recording fakes, the
// others kept from the default table) and checks every CHARACTER-taking wrapper.
static void run_fake_convention(int end_size_t){

    oti_lapack_provider_t t = *oti_lapack_provider();
    double a[4] = { 1.0, 0.0, 0.0, 1.0 };
    double b[4] = { 1.0, 1.0, 1.0, 1.0 };
    int ipiv[2] = { 1, 2 };
    int info = -1;
    const char* lbl = end_size_t ? "END_SIZE_T" : "NONE";
    char msg[96];

    t.struct_size       = (int32_t)sizeof(t);
    t.vendor            = OTI_LAPACK_VENDOR_HOST;
    t.strlen_convention = end_size_t ? OTI_STRLEN_END_SIZE_T : OTI_STRLEN_NONE;
    t.name              = NULL;
    t.set_threads_local = NULL;
    t.blas_set_threading = NULL;
    t.blas_get_threading = NULL;
    t.dgetrs = end_size_t ? (oti_lapack_fn)fk_dgetrs_fc : (oti_lapack_fn)fk_dgetrs_c;
    t.dtrsm  = end_size_t ? (oti_lapack_fn)fk_dtrxm_fc : (oti_lapack_fn)fk_dtrxm_c;
    t.dtrmm  = end_size_t ? (oti_lapack_fn)fk_dtrxm_fc : (oti_lapack_fn)fk_dtrxm_c;
    t.dgemm  = end_size_t ? (oti_lapack_fn)fk_dgemm_fc : (oti_lapack_fn)fk_dgemm_c;
    t.dgemv  = end_size_t ? (oti_lapack_fn)fk_dgemv_fc : (oti_lapack_fn)fk_dgemv_c;
    t.dsyrk  = end_size_t ? (oti_lapack_fn)fk_dsyrk_fc : (oti_lapack_fn)fk_dsyrk_c;
    t.dpotrf = end_size_t ? (oti_lapack_fn)fk_dpotrf_fc : (oti_lapack_fn)fk_dpotrf_c;
    t.dpotrs = end_size_t ? (oti_lapack_fn)fk_dpotrs_fc : (oti_lapack_fn)fk_dpotrs_c;
    t.dtrtrs = end_size_t ? (oti_lapack_fn)fk_dtrtrs_fc : (oti_lapack_fn)fk_dtrtrs_c;
    t.dgeqrf = NULL;    // tier 2 left out: the wrappers report INT_MIN

    check_int("provider_set fake", oti_lapack_provider_set(&t), OTI_OK);
    check_int("fake vendor", oti_lapack_provider()->vendor, OTI_LAPACK_VENDOR_HOST);
    check_int("fake caps", oti_blas_caps(), 0);

    if (oti_lapack_provider()->name == NULL){
        fprintf(stderr, "FAILED fake provider without a name\n");
        n_failed++;
    }

    fk_calls = 0;
    oti_dgetrs('T', 2, 1, a, 2, ipiv, b, 2, &info);
    snprintf(msg, sizeof(msg), "%s dgetrs", lbl);
    fk_expect(msg, "T", end_size_t);
    oti_dtrsm('R', 'U', 'T', 'N', 2, 2, 1.0, a, 2, b, 2);
    snprintf(msg, sizeof(msg), "%s dtrsm", lbl);
    fk_expect(msg, "RUTN", end_size_t);
    oti_dtrmm('L', 'L', 'N', 'U', 2, 2, 1.0, a, 2, b, 2);
    snprintf(msg, sizeof(msg), "%s dtrmm", lbl);
    fk_expect(msg, "LLNU", end_size_t);
    oti_dgemm('T', 'N', 2, 2, 2, 1.0, a, 2, b, 2, 0.0, b, 2);
    snprintf(msg, sizeof(msg), "%s dgemm", lbl);
    fk_expect(msg, "TN", end_size_t);
    oti_dgemv('T', 2, 2, 1.0, a, 2, b, 1, 0.0, b, 1);
    snprintf(msg, sizeof(msg), "%s dgemv", lbl);
    fk_expect(msg, "T", end_size_t);
    oti_dsyrk('L', 'T', 2, 2, 1.0, a, 2, 0.0, b, 2);
    snprintf(msg, sizeof(msg), "%s dsyrk", lbl);
    fk_expect(msg, "LT", end_size_t);
    oti_dpotrf('U', 2, a, 2, &info);
    snprintf(msg, sizeof(msg), "%s dpotrf", lbl);
    fk_expect(msg, "U", end_size_t);
    oti_dpotrs('L', 2, 1, a, 2, b, 2, &info);
    snprintf(msg, sizeof(msg), "%s dpotrs", lbl);
    fk_expect(msg, "L", end_size_t);
    oti_dtrtrs('L', 'T', 'U', 2, 1, a, 2, b, 2, &info);
    snprintf(msg, sizeof(msg), "%s dtrtrs", lbl);
    fk_expect(msg, "LTU", end_size_t);

    info = 0;
    oti_dgeqrf(2, 2, a, 2, b, b, 4, &info);
    check_int("tier-2 NULL slot info", info, INT_MIN);

    check_int("provider_set NULL", oti_lapack_provider_set(NULL), OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_provider_set(void){

    const oti_lapack_provider_t* def = oti_lapack_provider();
    oti_lapack_provider_t t = *def;
    int32_t caps = oti_blas_caps();

    run_fake_convention(1);
    run_fake_convention(0);

    if (oti_lapack_provider() != def || oti_blas_caps() != caps){
        fprintf(stderr, "FAILED provider_set(NULL) did not restore the default table\n");
        n_failed++;
    }

    // Rejections leave the current table unchanged.
    t.int_size = 8;
    check_int("reject int_size 8", oti_lapack_provider_set(&t), OTI_ERR_ARGUMENT);
    t.int_size = 4;
    t.dgetri = NULL;
    check_int("reject missing slot", oti_lapack_provider_set(&t), OTI_ERR_ARGUMENT);
    t.dgetri = def->dgetri;
    t.strlen_convention = 7;
    check_int("reject convention", oti_lapack_provider_set(&t), OTI_ERR_ARGUMENT);
    t.strlen_convention = def->strlen_convention;
    t.struct_size = (int32_t)sizeof(t) - 8;
    check_int("reject struct_size", oti_lapack_provider_set(&t), OTI_ERR_ARGUMENT);
    check_int("reject records last error", oti_ctx_last_error(NULL, NULL, NULL), OTI_ERR_ARGUMENT);
    oti_ctx_clear_error(NULL);

    if (oti_lapack_provider() != def){
        fprintf(stderr, "FAILED a rejected table replaced the provider\n");
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// ------------------------------- BLAS thread scopes (contracts 5.5) -----------------------------------

static int fk_local_value = 7;         // the fake per-thread count (single-threaded test only)
static int fk_local_sets = 0;
static int fk_accel_value = 0;
static int fk_accel_fail = 0;          // 1: BLASSetThreading returns -1 ("not supported")


// *******************************************************************************************************
static int fk_set_local(int n){

    int prev = fk_local_value;

    fk_local_value = n;
    fk_local_sets++;

    return prev;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int fk_accel_set(unsigned v){

    if (fk_accel_fail){
        return -1;
    }

    fk_accel_value = (int)v;

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static unsigned fk_accel_get(void){

    return (unsigned)fk_accel_value;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_scopes(void){

    oti_lapack_provider_t t = *oti_lapack_provider();
    oti_blas_scope_t s;

    t.struct_size        = (int32_t)sizeof(t);
    t.set_threads_local  = (oti_lapack_fn)fk_set_local;
    t.blas_set_threading = NULL;
    t.blas_get_threading = NULL;

    // LOCAL_THREADS: set 1, restore the previous value.
    check_int("scope local set", oti_lapack_provider_set(&t), OTI_OK);
    check_int("scope local caps", oti_blas_caps(), OTI_BLAS_CAP_LOCAL_THREADS);
    check_int("scope local enter", oti_blas_scope_enter(&s), 1);
    check_int("scope local kind", s.kind, OTI_BLAS_CAP_LOCAL_THREADS);
    check_int("scope local value inside", fk_local_value, 1);
    oti_blas_scope_exit(&s);
    check_int("scope local restored", fk_local_value, 7);
    check_int("scope local kind reset", s.kind, 0);
    check_int("scope local set calls", fk_local_sets, 2);

    // ACCEL_THREADING: probed with a test call; restored at exit.
    t.set_threads_local  = NULL;
    t.blas_set_threading = (oti_lapack_fn)fk_accel_set;
    t.blas_get_threading = (oti_lapack_fn)fk_accel_get;
    fk_accel_value = 0;
    fk_accel_fail  = 0;
    check_int("scope accel set", oti_lapack_provider_set(&t), OTI_OK);
    check_int("scope accel caps", oti_blas_caps(), OTI_BLAS_CAP_ACCEL_THREADING);
    check_int("scope accel enter", oti_blas_scope_enter(&s), 1);
    check_int("scope accel kind", s.kind, OTI_BLAS_CAP_ACCEL_THREADING);
    check_int("scope accel value inside", fk_accel_value, 1);
    oti_blas_scope_exit(&s);
    check_int("scope accel restored", fk_accel_value, 0);

    // A BLASSetThreading that starts failing at run time gives kind 0 (nothing to restore, [cL9]).
    fk_accel_fail = 1;
    check_int("scope accel failing enter", oti_blas_scope_enter(&s), 0);
    check_int("scope accel failing kind", s.kind, 0);
    oti_blas_scope_exit(&s);
    check_int("scope accel failing untouched", fk_accel_value, 0);

    // One that fails the probe's test call: no capability.
    check_int("scope accel probe-fail set", oti_lapack_provider_set(&t), OTI_OK);
    check_int("scope accel probe-fail caps", oti_blas_caps(), 0);
    fk_accel_fail = 0;

    // No capability: kind 0, enter returns 0.
    t.blas_set_threading = NULL;
    t.blas_get_threading = NULL;
    check_int("scope none set", oti_lapack_provider_set(&t), OTI_OK);
    check_int("scope none enter", oti_blas_scope_enter(&s), 0);
    check_int("scope none kind", s.kind, 0);
    oti_blas_scope_exit(&s);

    check_int("scope restore default", oti_lapack_provider_set(NULL), OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Chunk of the parallel-for-BLAS check: records the worker's thread-local BLAS count.
static int fk_chunk_dgemm(void* arg, int64_t chunk, int32_t worker){

    double* c = (double*)arg;
    double a[4] = { 1.0, 2.0, 3.0, 4.0 };

    (void)worker;
    oti_dgemm('N', 'N', 2, 2, 2, 1.0, a, 2, a, 2, 0.0, c + 4 * chunk, 2);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_parallel_for_blas(void){

    double c[4 * 8];
    int64_t i;

    // Batched dgemm through oti_parallel_for_blas with the real provider: correct on every path.
    check_int("parallel_for_blas status", oti_parallel_for_blas(NULL, 8, fk_chunk_dgemm, c), OTI_OK);

    for (i = 0; i < 8; i++){
        check_close("parallel_for_blas (0,0)", c[4 * i], 7.0);
        check_close("parallel_for_blas (1,1)", c[4 * i + 3], 22.0);
    }

}
// -------------------------------------------------------------------------------------------------------


// Thread-local fake of a LOCAL_THREADS provider, for oti_parallel_for_blas() (each worker its own).
static _Thread_local int fk_tl_value = 5;
static int fk_tl_ones = 0;        // calls that set 1 (scope enter)
static int fk_tl_restores = 0;    // calls that set anything else (scope exit)
static int fk_tl_bad = 0;         // chunks that ran with a BLAS count other than 1


// *******************************************************************************************************
static int fk_tl_set(int n){

    int prev = fk_tl_value;

    fk_tl_value = n;
    __atomic_add_fetch(n == 1 ? &fk_tl_ones : &fk_tl_restores, 1, __ATOMIC_RELAXED);

    return prev;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int fk_tl_chunk(void* arg, int64_t chunk, int32_t worker){

    (void)arg;
    (void)worker;

    if (fk_tl_value != 1){
        __atomic_add_fetch(&fk_tl_bad, 1, __ATOMIC_RELAXED);
    }

    return chunk == 5 ? OTI_ERR_SIZE : OTI_OK;   // a failing chunk: scopes still restored

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Contracts 5.5: with LOCAL_THREADS each worker of oti_parallel_for_blas() sets 1 before its first
// chunk and restores its previous value after its last, on every path (here a failing chunk).
static void test_parallel_for_blas_scopes(void){

    oti_lapack_provider_t t = *oti_lapack_provider();
    oti_ctx ctx;

    t.struct_size        = (int32_t)sizeof(t);
    t.set_threads_local  = (oti_lapack_fn)fk_tl_set;
    t.blas_set_threading = NULL;
    t.blas_get_threading = NULL;

    oti_ctx_init(&ctx);
    ctx.exec.nthreads = 2;
    check_int("pfb scopes provider", oti_lapack_provider_set(&t), OTI_OK);
    check_int("pfb scopes status", oti_parallel_for_blas(&ctx, 64, fk_tl_chunk, NULL), OTI_ERR_SIZE);
    check_int("pfb scopes chunks at 1 thread", fk_tl_bad, 0);
    check_int("pfb scopes enter == exit", fk_tl_restores, fk_tl_ones);
    check_int("pfb scopes caller restored", fk_tl_value, 5);
    oti_ctx_clear_error(&ctx);
    check_int("pfb scopes restore default", oti_lapack_provider_set(NULL), OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Prints the probe and checks it against the build-time configuration (contracts 8.3).
static void test_probe(void){

    const oti_lapack_provider_t* p = oti_lapack_provider();
    int32_t caps = oti_blas_caps();

    printf("LAPACK provider: %s\n", p->name != NULL ? p->name : "(null)");
    printf("  vendor %d (build-time %d), convention %d (build-time %d), caps 0x%x:%s%s%s%s\n",
           (int)p->vendor, OTI_LAPACK_VENDOR, (int)p->strlen_convention, OTI_LAPACK_STRLEN,
           (unsigned)caps, (caps & OTI_BLAS_CAP_LOCAL_THREADS) ? " LOCAL_THREADS" : "",
           (caps & OTI_BLAS_CAP_ACCEL_THREADING) ? " ACCEL_THREADING" : "",
           (caps & OTI_BLAS_CAP_SERIAL_BUILD) ? " SERIAL_BUILD" : "",
           (caps & OTI_BLAS_CAP_OMP_NESTED) ? " OMP_NESTED" : "");

    // A CMake misdetection would have linked the wrong symbols: the probe must agree. A GENERIC
    // build-time vendor may be refined to OpenBLAS by the probe (openblas_get_parallel found).
    if (!(p->vendor == OTI_LAPACK_VENDOR
          || (OTI_LAPACK_VENDOR == OTI_LAPACK_VENDOR_GENERIC
              && p->vendor == OTI_LAPACK_VENDOR_OPENBLAS))){
        fprintf(stderr, "FAILED probed vendor %d differs from the build-time vendor %d\n",
                (int)p->vendor, OTI_LAPACK_VENDOR);
        n_failed++;
    }

    check_int("probed convention", p->strlen_convention, OTI_LAPACK_STRLEN);
    check_int("probed int_size", p->int_size, 4);
    check_int("probed struct_size", p->struct_size, (long long)sizeof(oti_lapack_provider_t));
    check_int("caps equals table caps", caps, p->caps);

    if (p->dgetrf == NULL || p->dgemm == NULL || p->dgesdd == NULL){
        fprintf(stderr, "FAILED default table has NULL slots\n");
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A "provider" whose dgemm lives in this executable, which exports no capability symbol of its own
// (as a statically linked LAPACK with hidden symbols). Never called.
static void fk_exe_dgemm(void){
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Probes a provider loaded with dlopen(RTLD_LOCAL) (independently of the linked one) and checks that
// only its own image's capability symbols count (checker W2 finding 5). Skipped when absent.
static void probe_loaded(const char* path, int accelerate){

    oti_lapack_provider_t t = *oti_lapack_provider();
    void* h = path != NULL ? dlopen(path, RTLD_NOW | RTLD_LOCAL) : NULL;
    void* sym;
    oti_lapack_fn f;

    if (h == NULL){
        printf("  provenance: %s not loadable, skipped\n", path != NULL ? path : "(none)");
        return;
    }

    sym = dlsym(h, accelerate ? "dgemm$NEWLAPACK" : "dgemm_");

    if (sym == NULL || sizeof(sym) != sizeof(f)){
        printf("  provenance: no dgemm in %s, skipped\n", path);
        dlclose(h);
        return;
    }

    memcpy(&f, &sym, sizeof(f));
    t.dgemm             = f;
    t.vendor            = OTI_LAPACK_VENDOR_GENERIC;
    t.strlen_convention = OTI_STRLEN_END_SIZE_T;
    t.name              = "loaded provider";
    oti_lapack_test_probe(&t);
    printf("  provenance: %s -> vendor %d, caps 0x%x, %s\n", path, (int)t.vendor, (unsigned)t.caps,
           t.name != NULL ? t.name : "(null)");

    if (accelerate){
        check_int("loaded Accelerate vendor", t.vendor, OTI_LAPACK_VENDOR_ACCELERATE);
        check_int("loaded Accelerate: no OpenBLAS / MKL bits", t.caps & (OTI_BLAS_CAP_SERIAL_BUILD
                  | OTI_BLAS_CAP_OMP_NESTED | OTI_BLAS_CAP_LOCAL_THREADS), 0);
        check_int("loaded Accelerate: no set_threads_local", t.set_threads_local == NULL, 1);
        check_int("loaded Accelerate: name not OpenBLAS's", strstr(t.name, "OpenBLAS") == NULL, 1);
    } else {
        check_int("loaded OpenBLAS: no Accelerate bit", t.caps & OTI_BLAS_CAP_ACCEL_THREADING, 0);
        check_int("loaded OpenBLAS: no BLASSetThreading", t.blas_set_threading == NULL, 1);
        check_int("loaded OpenBLAS: its own name", strstr(t.name, "OpenBLAS") != NULL, 1);
    }

    dlclose(h);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checker W2 finding 5: capability symbols must belong to the provider's own image.
static void test_probe_provenance(void){

    oti_lapack_provider_t t = *oti_lapack_provider();
    const char* conda = getenv("CONDA_PREFIX");
    char path[4096];

    // The executable's own "provider": the linked BLAS (another image) exports openblas_* or
    // BLASSetThreading globally; none of them may be attributed to this provider.
    t.dgemm             = (oti_lapack_fn)fk_exe_dgemm;
    t.vendor            = OTI_LAPACK_VENDOR_GENERIC;
    t.strlen_convention = OTI_STRLEN_END_SIZE_T;
    t.name              = "exe provider";
    oti_lapack_test_probe(&t);
    check_int("hidden-symbol provider caps", t.caps, 0);
    check_int("hidden-symbol provider vendor", t.vendor, OTI_LAPACK_VENDOR_GENERIC);
    check_int("hidden-symbol provider slots", t.set_threads_local == NULL && t.blas_set_threading == NULL
              && t.blas_get_threading == NULL, 1);
    check_int("hidden-symbol provider name", strcmp(t.name, "exe provider"), 0);

    // Two independently loaded providers (whichever exist on this machine).
#if defined(__APPLE__)
    probe_loaded("/System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/"
                 "vecLib.framework/Versions/A/libBLAS.dylib", 1);
#endif

    if (conda != NULL && strlen(conda) < sizeof(path) - 32){
#if defined(__APPLE__)
        snprintf(path, sizeof(path), "%s/lib/libopenblas.dylib", conda);
#else
        snprintf(path, sizeof(path), "%s/lib/libopenblas.so", conda);
#endif
        probe_loaded(path, 0);
    } else {
        probe_loaded(NULL, 0);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// S28: the contention probe gives a finite, non-negative value, measured once (cached).
static void test_contention(void){

    double c1 = oti_blas_contention_ns();
    double c2 = oti_blas_contention_ns();

    printf("  BLAS contention: %.1f ns per small call\n", c1);

    if (!isfinite(c1) || c1 < 0.0 || c1 != c2){
        fprintf(stderr, "FAILED contention probe: %g then %g\n", c1, c2);
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    if (!oti_lapack_fits(4) || oti_lapack_fits((uint64_t)INT_MAX + 1)){
        fprintf(stderr, "FAILED oti_lapack_fits\n");
        n_failed++;
    }

    test_getrf_getrs();
    test_getrs_transposed_padded();
    test_getrf_singular();
    test_trsm_trmm();
    test_dgemm();
    test_level1();
    test_level2_3();
    test_lapack_tier1();
    test_lapack_tier2();
    test_lwork_and_limits();
    test_probe();
    test_provider_set();
    test_scopes();
    test_parallel_for_blas();
    test_parallel_for_blas_scopes();
    test_probe_provenance();
    test_contention();

    if (n_failed != 0){
        fprintf(stderr, "LAPACK wrapper tests: %d check(s) failed.\n", n_failed);
        return 1;
    }

    printf("LAPACK wrapper tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
