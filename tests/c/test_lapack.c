// Tests of the LAPACK / BLAS wrappers (include/oti/core/lapack.h, library otilapack).
//
// Checks that the Fortran BIND(C) wrappers reach the LAPACK found by CMake with the right argument
// passing: 32-bit integers, column-major arrays, CHARACTER flags passed by value.
#include <math.h>
#include <stdio.h>
#include <oti/oti.h>

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

    if (n_failed != 0){
        fprintf(stderr, "LAPACK wrapper tests: %d check(s) failed.\n", n_failed);
        return 1;
    }

    printf("LAPACK wrapper tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
