/* Tests of the sparse OTI linear algebra on LAPACK (oti/sparse/array/algebra_lu.h):
 * det / inv for n = 4 (LU path), lu_factor reconstruction, solve and lu_solve residuals, singular
 * real parts. */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <oti/oti.h>

#define TOL 1e-12

static int failures = 0;


/* max(a, |b|), propagating NaN (fmax would drop it and hide a non-finite coefficient). */
static double max_abs_nan(double a, double b){

    if (isnan(a) || isnan(b)){
        return NAN;
    }

    return fmax(a, fabs(b));
}


/* Largest absolute coefficient (real and imaginary) of a number; NaN if any coefficient is NaN. */
static double soti_max_abs(sotinum_t* num){

    double res = max_abs_nan(0.0, num->re);
    ord_t o;
    ndir_t k;

    for (o = 0; o < num->act_order; o++){
        for (k = 0; k < num->p_nnz[o]; k++){
            res = max_abs_nan(res, num->p_im[o][k]);
        }
    }

    return res;
}


/* Largest absolute coefficient of arr1 - arr2; NaN if any coefficient is NaN (comparisons with a
 * tolerance then fail). */
static double arrso_max_diff(arrso_t* arr1, arrso_t* arr2, dhelpl_t dhl){

    arrso_t diff = arrso_zeros_bases(arr1->nrows, arr1->ncols, 0, 0, dhl);
    double res = 0.0;
    uint64_t i;

    arrso_sub_OO_to(arr1, arr2, &diff, dhl);

    for (i = 0; i < diff.size; i++){
        res = max_abs_nan(res, soti_max_abs(&diff.p_data[i]));
    }

    arrso_free(&diff);

    return res;
}


static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        failures++;
    } else {
        printf("passed: %s\n", name);
    }
}


static void check_close(double got, double expected, const char* name){

    if (!(fabs(got - expected) <= TOL * fmax(1.0, fabs(expected)))){
        fprintf(stderr, "FAILED: %s: got %.17g, expected %.17g\n", name, got, expected);
        failures++;
    } else {
        printf("passed: %s\n", name);
    }
}


/* Dense OTI matrix, 2 bases, order 2, with a zero leading real entry (forces pivoting). */
static arrso_t dense_matrix(uint64_t n, uint64_t ncols, double shift, dhelpl_t dhl){

    arrso_t A = arrso_zeros_bases(n, ncols, 2, 2, dhl);
    uint64_t i, j;
    double v;

    for (i = 0; i < n; i++){
        for (j = 0; j < ncols; j++){

            sotinum_t* a = &A.p_data[j + i*ncols];

            v = sin(1.0 + 3.0*i + 7.0*j + shift);
            a->re = (i == j) ? 3.0 + v : v;

            soti_set_im_r(cos(2.0*i + j + shift),       0, 1, a, dhl);   /* e1    */
            soti_set_im_r(0.5*sin(i + 5.0*j + shift),   1, 1, a, dhl);   /* e2    */
            soti_set_im_r(0.25*cos(3.0*i - j + shift),  0, 2, a, dhl);   /* order 2, all directions */
            soti_set_im_r(0.3*sin(i*j + shift),         1, 2, a, dhl);
            soti_set_im_r(-0.2*cos(i + j + shift),      2, 2, a, dhl);
        }
    }

    A.p_data[0].re = 0.0;

    return A;
}


/* det and inv at n = 4 against hand values: A = rows 0 and 1 of an upper triangular T swapped,
 * T diagonal (1 + e1, 2, 3 - e1, 4), 1 basis, order 2.
 * det A = -det T = -(1 + e1) 2 (3 - e1) 4 = -24 - 16 e1 + 8 e1^2. */
static void test_det_inv_4x4(dhelpl_t dhl){

    arrso_t T  = arrso_zeros_bases(4, 4, 1, 2, dhl);
    arrso_t A  = arrso_zeros_bases(4, 4, 1, 2, dhl);
    arrso_t Ai = arrso_zeros_bases(4, 4, 0, 0, dhl);
    arrso_t I  = arrso_eye_bases(4, 0, 0, dhl);
    arrso_t AAi;
    int32_t perm[4] = {2, 2, 3, 4};
    sotinum_t det = soti_createEmpty(0, dhl);
    uint64_t i, j;
    int status;

    for (i = 0; i < 4; i++){
        for (j = i; j < 4; j++){
            sotinum_t* t = &T.p_data[j + i*4];
            t->re = (i == j) ? (double)(i + 1) : 0.5*(i + j) + 1.0;
            if (j > i){
                soti_set_im_r(0.1*(i + 2*j), 0, 1, t, dhl);
                soti_set_im_r(0.05*(j - i),  0, 2, t, dhl);
            }
        }
    }
    soti_set_im_r( 1.0, 0, 1, &T.p_data[0],  dhl);   /* 1 + e1 */
    soti_set_im_r(-1.0, 0, 1, &T.p_data[10], dhl);   /* 3 - e1 */

    arrso_permute_rows_to(&T, perm, &A, dhl);

    status = arrso_det_to(&A, &det, dhl);
    check(status == 0, "det 4x4 status");
    check_close(det.re,                         -24.0, "det 4x4 real");
    check_close(soti_get_im(0, 1, &det, dhl),   -16.0, "det 4x4 e1");
    check_close(soti_get_im(0, 2, &det, dhl),     8.0, "det 4x4 e1^2");

    status = arrso_invert_to(&A, &Ai, dhl);
    check(status == 0, "inv 4x4 status");
    AAi = arrso_matmul_OO(&A, &Ai, dhl);
    check(arrso_max_diff(&AAi, &I, dhl) < TOL, "inv 4x4: A inv(A) = I in every direction");

    arrso_free(&T);
    arrso_free(&A);
    arrso_free(&Ai);
    arrso_free(&AAi);
    arrso_free(&I);
    soti_free(&det);
}


/* lu_factor: P^T A = L U in every direction; solve residual and lu_solve = solve with 2 right-hand
 * sides; solve with the output aliasing the right-hand side. */
static void test_lu_solve(uint64_t n, dhelpl_t dhl){

    arrso_t A   = dense_matrix(n, n, 0.0, dhl);
    arrso_t b   = dense_matrix(n, 2, 0.7, dhl);
    arrso_t LU  = arrso_zeros_bases(n, n, 0, 0, dhl);
    arrso_t L   = arrso_zeros_bases(n, n, 0, 0, dhl);
    arrso_t U   = arrso_zeros_bases(n, n, 0, 0, dhl);
    arrso_t PA  = arrso_zeros_bases(n, n, 0, 0, dhl);
    arrso_t x1  = arrso_zeros_bases(n, 2, 0, 0, dhl);
    arrso_t x2  = arrso_zeros_bases(n, 2, 0, 0, dhl);
    arrso_t Lu, Ax;
    int32_t* ipiv = (int32_t*)malloc(n * sizeof(int32_t));
    uint64_t i;
    int status;
    char name[128];

    status = arrso_lu_factor_to(&A, &LU, ipiv, dhl);
    snprintf(name, sizeof(name), "lu_factor n=%llu status", (unsigned long long)n);
    check(status == 0, name);
    snprintf(name, sizeof(name), "lu_factor n=%llu pivots (zero leading entry)", (unsigned long long)n);
    check(ipiv[0] != 1, name);

    arrso_tril_to(&LU, 1, &L, dhl);
    for (i = 0; i < n; i++){
        L.p_data[i + i*n].re = 1.0;
    }
    arrso_triu_to(&LU, 0, &U, dhl);
    Lu = arrso_matmul_OO(&L, &U, dhl);
    arrso_permute_rows_to(&A, ipiv, &PA, dhl);
    snprintf(name, sizeof(name), "lu_factor n=%llu: P^T A = L U", (unsigned long long)n);
    check(arrso_max_diff(&Lu, &PA, dhl) < 1e-11, name);

    status = arrso_solve_to(&A, &b, &x1, dhl);
    Ax = arrso_matmul_OO(&A, &x1, dhl);
    snprintf(name, sizeof(name), "solve n=%llu: A x = b", (unsigned long long)n);
    check(status == 0 && arrso_max_diff(&Ax, &b, dhl) < 1e-11, name);

    status = arrso_lu_solve_to(&LU, ipiv, &b, &x2, dhl);
    snprintf(name, sizeof(name), "lu_solve n=%llu equals solve", (unsigned long long)n);
    check(status == 0 && arrso_max_diff(&x1, &x2, dhl) < 1e-11, name);

    /* Aliased output: x = solve(A, x). */
    arrso_copy_to(&b, &x2, dhl);
    status = arrso_solve_to(&A, &x2, &x2, dhl);
    snprintf(name, sizeof(name), "solve n=%llu aliased rhs", (unsigned long long)n);
    check(status == 0 && arrso_max_diff(&x1, &x2, dhl) < 1e-11, name);

    arrso_free(&A);
    arrso_free(&b);
    arrso_free(&LU);
    arrso_free(&L);
    arrso_free(&U);
    arrso_free(&PA);
    arrso_free(&x1);
    arrso_free(&x2);
    arrso_free(&Lu);
    arrso_free(&Ax);
    free(ipiv);
}


/* Singular real part: diag(e1, 1, 1, 1). inv and solve fail; det fails (known limitation). */
static void test_singular(dhelpl_t dhl){

    arrso_t A  = arrso_eye_bases(4, 1, 1, dhl);
    arrso_t Ai = arrso_zeros_bases(4, 4, 0, 0, dhl);
    sotinum_t det = soti_createEmpty(0, dhl);
    int status;

    A.p_data[0].re = 0.0;
    soti_set_im_r(1.0, 0, 1, &A.p_data[0], dhl);

    status = arrso_invert_to(&A, &Ai, dhl);
    check(status > 0 && isnan(Ai.p_data[0].re), "inv singular real part: status > 0, NaN");

    status = arrso_det_to(&A, &det, dhl);
    check(status > 0 && isnan(det.re), "det singular real part n=4: status > 0 (known limitation)");

    arrso_free(&A);
    arrso_free(&Ai);
    soti_free(&det);
}


int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);

    test_det_inv_4x4(dhl);
    test_lu_solve(4, dhl);
    test_lu_solve(7, dhl);
    test_singular(dhl);

    dhelp_free(&dhl);

    if (failures){
        fprintf(stderr, "%d sparse linalg test(s) failed.\n", failures);
        return 1;
    }

    printf("C sparse linalg tests passed successfully.\n");
    return 0;
}
