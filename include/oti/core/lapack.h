#ifndef OTI_CORE_LAPACK_H
#define OTI_CORE_LAPACK_H

// ----------------------------------------------------------------------------------------------------
// C interface to the LAPACK / BLAS routines used by OTIlib.
//
// These functions are Fortran BIND(C) wrappers (src/fortran/core/oti_lapack.f90, library otilapack)
// around the LAPACK found by CMake. Never call LAPACK symbols (dgetrf_, ...) from C directly: the
// wrappers hide symbol-name and hidden string-length differences between compilers and vendors.
//
// All matrices are column-major. Integers are 32-bit (LP64 LAPACK); check sizes with
// oti_lapack_fits() before calling. Pivot indices are 1-based, as in LAPACK.
// ----------------------------------------------------------------------------------------------------

#include <limits.h>
#include <stdint.h>

/**************************************************************************************************//**
@brief Tells whether a dimension fits in the 32-bit integers of the LAPACK interface.

@param[in] n    Dimension (rows, columns, leading dimension or number of right-hand sides).

@return 1 if n <= INT_MAX, 0 otherwise.
******************************************************************************************************/
static inline int oti_lapack_fits(uint64_t n){
    return n <= (uint64_t)INT_MAX;
}
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief LU factorization with partial pivoting, A = P L U (LAPACK dgetrf).

On exit a holds L (unit diagonal not stored) below the diagonal and U on and above it.

@param[in]    m       Number of rows of a.
@param[in]    n       Number of columns of a.
@param[in,out] a      Column-major matrix, overwritten by its factors.
@param[in]    lda     Leading dimension of a (>= m).
@param[out]   ipiv    Pivot indices (1-based), length min(m,n). Row i was swapped with row ipiv[i].
@param[out]   info    0 on success; i > 0 if U(i,i) is exactly zero (singular); < 0 bad argument.
******************************************************************************************************/
void oti_dgetrf(int m, int n, double* a, int lda, int* ipiv, int* info);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Solves A X = B ('N') or A^T X = B ('T') with the factors of oti_dgetrf (LAPACK dgetrs).

@param[in]    trans   'N' or 'T'.
@param[in]    n       Order of a.
@param[in]    nrhs    Number of right-hand sides (columns of b).
@param[in]    a       Factors from oti_dgetrf.
@param[in]    lda     Leading dimension of a.
@param[in]    ipiv    Pivot indices from oti_dgetrf.
@param[in,out] b      Right-hand sides on entry, solutions on exit.
@param[in]    ldb     Leading dimension of b (>= n).
@param[out]   info    0 on success; < 0 bad argument.
******************************************************************************************************/
void oti_dgetrs(char trans, int n, int nrhs, const double* a, int lda, const int* ipiv,
                double* b, int ldb, int* info);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Triangular solve with multiple right-hand sides (BLAS dtrsm).

B = alpha op(A)^-1 B (side 'L') or B = alpha B op(A)^-1 (side 'R'), op(A) = A ('N') or A^T ('T').

@param[in]    side    'L' or 'R'.
@param[in]    uplo    'L' (A lower triangular) or 'U' (upper).
@param[in]    transa  'N' or 'T'.
@param[in]    diag    'U' (unit diagonal, not referenced) or 'N'.
@param[in]    m       Rows of b.
@param[in]    n       Columns of b.
@param[in]    alpha   Scalar factor.
@param[in]    a       Triangular matrix, order m (side 'L') or n (side 'R').
@param[in]    lda     Leading dimension of a.
@param[in,out] b      Right-hand sides on entry, solutions on exit.
@param[in]    ldb     Leading dimension of b (>= m).
******************************************************************************************************/
void oti_dtrsm(char side, char uplo, char transa, char diag, int m, int n, double alpha,
               const double* a, int lda, double* b, int ldb);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Triangular matrix product (BLAS dtrmm).

B = alpha op(A) B (side 'L') or B = alpha B op(A) (side 'R'). Arguments as in oti_dtrsm.

@param[in]    side    'L' or 'R'.
@param[in]    uplo    'L' or 'U'.
@param[in]    transa  'N' or 'T'.
@param[in]    diag    'U' or 'N'.
@param[in]    m       Rows of b.
@param[in]    n       Columns of b.
@param[in]    alpha   Scalar factor.
@param[in]    a       Triangular matrix.
@param[in]    lda     Leading dimension of a.
@param[in,out] b      Input matrix on entry, product on exit.
@param[in]    ldb     Leading dimension of b (>= m).
******************************************************************************************************/
void oti_dtrmm(char side, char uplo, char transa, char diag, int m, int n, double alpha,
               const double* a, int lda, double* b, int ldb);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief General matrix product (BLAS dgemm).

C = alpha op(A) op(B) + beta C, op(X) = X ('N') or X^T ('T'). op(A) is m x k, op(B) is k x n,
C is m x n.

@param[in]    transa  'N' or 'T', applied to a.
@param[in]    transb  'N' or 'T', applied to b.
@param[in]    m       Rows of op(A) and of c.
@param[in]    n       Columns of op(B) and of c.
@param[in]    k       Columns of op(A) and rows of op(B).
@param[in]    alpha   Scalar factor of op(A) op(B).
@param[in]    a       Column-major matrix, op(A) is m x k.
@param[in]    lda     Leading dimension of a (>= m if transa == 'N', >= k otherwise).
@param[in]    b       Column-major matrix, op(B) is k x n.
@param[in]    ldb     Leading dimension of b (>= k if transb == 'N', >= n otherwise).
@param[in]    beta    Scalar factor of c on entry. beta == 0 need not leave c initialized.
@param[in,out] c      Column-major matrix, m x n; overwritten by the result.
@param[in]    ldc     Leading dimension of c (>= m).
******************************************************************************************************/
void oti_dgemm(char transa, char transb, int m, int n, int k, double alpha, const double* a,
               int lda, const double* b, int ldb, double beta, double* c, int ldc);
// ----------------------------------------------------------------------------------------------------

#endif
