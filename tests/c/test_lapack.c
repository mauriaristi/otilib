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
int main(void){

    if (!oti_lapack_fits(4) || oti_lapack_fits((uint64_t)INT_MAX + 1)){
        fprintf(stderr, "FAILED oti_lapack_fits\n");
        n_failed++;
    }

    test_getrf_getrs();
    test_getrs_transposed_padded();
    test_getrf_singular();
    test_trsm_trmm();

    if (n_failed != 0){
        fprintf(stderr, "LAPACK wrapper tests: %d check(s) failed.\n", n_failed);
        return 1;
    }

    printf("LAPACK wrapper tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
