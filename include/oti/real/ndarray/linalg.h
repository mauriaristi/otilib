#ifndef OTI_REAL_NDARRAY_LINALG_H
#define OTI_REAL_NDARRAY_LINALG_H

// -------------------------------------------------------------------------------------------------------
// ndarray linear algebra, tier 1 (Phase 3, src/c/real/ndarray/linalg.c): LU, solve, inv, det,
// slogdet, Cholesky, triangular solve. Tier 2 (QR, lstsq, eigen, SVD) is a later phase.
//
// LU design (one design for solve, inv, det):
//   - The input is copied into a private F-order n x n factor buffer: a C-contiguous input is
//     memcpy'd and READ AS A^T in column major (no transpose pass), trans = 1; an F-contiguous input
//     is memcpy'd, trans = 0; any other layout is packed into F order in one strided pass, trans = 0.
//     With overwrite = 1 and a writeable C- or F-contiguous input the input itself is factored.
//   - solve: dgetrs with 'T' for trans = 1 (factors of A^T: (A^T)^T x = b), 'N' for trans = 0.
//   - inv: dgetri on the factor buffer gives (A^T)^-1 = (A^-1)^T for trans = 1, i.e. A^-1 in C
//     order with no transpose; for trans = 0 it is A^-1 in F order. It is then copied into the output
//     layout (memcpy when the orders match).
//   - Statuses: info > 0 from dgetrf (an EXACTLY zero pivot) is returned as a positive status by
//     solve and inv (LinAlgError); det and slogdet return OTI_OK with det = 0.0 and
//     slogdet = (0.0, -inf). A numerically singular matrix (tiny pivot) is not detected.
//   - Stacked inputs (..., n, n) loop over the batch axes with oti_parallel_for_blas().
//   - det = sign * exp(logabsdet), reconstructed from slogdet as NumPy does: the plain product of U's
//     diagonal would overflow for diag(1e200, 1e200, 1e-200, 1e-200), whose determinant is 1.0.
//   - Empty matrices: det of 0 x 0 is 1, slogdet (1, 0); solve / inv of 0 x 0 (or with k = 0
//     right-hand sides) give empty results WITHOUT any provider call; every leading dimension passed
//     to LAPACK is >= max(1, n), so no XERBLA is reachable.
//   - Workspace queries (lwork = -1) are converted with oti_lapack_lwork(); all sizes pass
//     oti_lapack_fits_i64(); buffers are charged with oti_ctx_check_temp().
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief LU factorization of a real n x n matrix, with its orientation.
 */
typedef struct {
    ndarr_t  lu;    ///< F-order n x n factors: retained private buffer, or (overwrite) the input itself
                    ///< (retained when the input has a control block, else a temporary).
    int*     ipiv;  ///< 1-based pivots from dgetrf, length n; owned (malloc), freed by nd_lu_free().
    int64_t  n;     ///< Order of the matrix.
    int32_t  trans; ///< 0: factors of A; 1: factors of A^T (a C-order input read as A^T).
    int32_t  info;  ///< dgetrf info: 0, or i > 0 when U(i, i) is exactly zero.
} nd_lu_t;

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @name LU factorization
 * @{
 */

/**
 * @brief Makes an empty factorization (safe to free).
 *
 * @param[out] lu Factorization to initialize.
 */
void nd_lu_init(nd_lu_t* lu);

/**
 * @brief Factors a square matrix (dgetrf), with the orientation rules above.
 *
 * @param[in,out] ctx       Context, or NULL.
 * @param[in,out] a         2-D OTI_F64 n x n. Overwritten (unspecified) only with overwrite = 1.
 * @param[in]     overwrite 1 to factor @p a in place when it is writeable and C- or F-contiguous.
 * @param[out]    lu        Factorization; must be empty (nd_lu_init()) on entry.
 *
 * @return OTI_OK; info > 0 (exactly singular: lu is complete and usable by nd_det(), not by solves);
 *         OTI_ERR_SHAPE (not square 2-D); OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY; OTI_ERR_BUSY
 *         (overwrite = 1 and the input's buffer is growing, so it cannot be retained). On a negative
 *         status @p lu is left empty. Caller must free @p lu via nd_lu_free() in every case.
 */
int nd_lu_factor(oti_ctx* ctx, ndarr_t* a, int32_t overwrite, nd_lu_t* lu);

/**
 * @brief Solves A x = b with a factorization (dgetrs, 'T' when lu->trans is 1).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     lu  Factorization with info == 0.
 * @param[in]     b   OTI_F64, shape (n,) or (n, k).
 * @param[out]    res New retained array of b's shape (F-order for 2-D).
 *
 * @return OTI_OK; lu->info when it is > 0 (nothing solved); OTI_ERR_SHAPE; OTI_ERR_DTYPE;
 *         OTI_ERR_SIZE; OTI_ERR_MEMORY. Caller must release @p res via nd_release().
 */
int nd_lu_solve(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* res);

/**
 * @brief Frees a factorization (releases lu->lu, frees ipiv) and makes it empty.
 *
 * @param[in,out] lu Factorization; NULL is allowed.
 */
void nd_lu_free(nd_lu_t* lu);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Solve, inverse, determinant
 * Inputs are never modified. Stacked (..., n, n) inputs are supported.
 * @{
 */

/**
 * @brief Solves a x = b (numpy.linalg.solve, NumPy 2 rules: b of ndim 1 is a vector, otherwise
 *        (..., n, k) broadcasting against a's batch axes).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64 (..., n, n).
 * @param[in]     b   OTI_F64 (n,) or (..., n, k).
 * @param[out]    res New retained array.
 *
 * @return OTI_OK; info > 0 for the first singular matrix of the batch (in C order of the batch);
 *         OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY. Caller must release @p res via
 *         nd_release().
 */
int nd_solve(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res);

/**
 * @brief Inverse (numpy.linalg.inv).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64 (..., n, n).
 * @param[out]    res New retained array, same layout family as a (C for a C-contiguous a, else F).
 *
 * @return As nd_solve(). Caller must release @p res via nd_release().
 */
int nd_inv(oti_ctx* ctx, const ndarr_t* a, ndarr_t* res);

/**
 * @brief Determinant (numpy.linalg.det): sign * exp(logabsdet) from the slogdet of the LU factors.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64 (..., n, n).
 * @param[out]    res New retained array of shape (...) (rank 0 for one matrix). 0.0 for an exactly
 *                    singular matrix; 1.0 for 0 x 0.
 *
 * @return OTI_OK (also for singular matrices); OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE;
 *         OTI_ERR_MEMORY. Caller must release @p res via nd_release().
 */
int nd_det(oti_ctx* ctx, const ndarr_t* a, ndarr_t* res);

/**
 * @brief Sign and log of the absolute determinant (numpy.linalg.slogdet).
 *
 * logabs is the sum of log|u_ii| in index order; sign is +-1.0 (0.0 with logabs = -inf for an exactly
 * singular matrix; 1.0 and 0.0 for 0 x 0).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     a      OTI_F64 (..., n, n).
 * @param[out]    sign   New retained array of shape (...).
 * @param[out]    logabs New retained array of shape (...).
 *
 * @return As nd_det(). Caller must release both via nd_release(); on failure both are empty.
 */
int nd_slogdet(oti_ctx* ctx, const ndarr_t* a, ndarr_t* sign, ndarr_t* logabs);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Cholesky and triangular solves
 * @{
 */

/**
 * @brief Cholesky factor (dpotrf; numpy.linalg.cholesky): lower L with A = L L^T, or upper U with
 *        A = U^T U; the other triangle is zeroed. Only the chosen triangle of @p a is read.
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     a     OTI_F64 (..., n, n).
 * @param[in]     lower 1 for L, 0 for U.
 * @param[out]    res   New retained array.
 *
 * @return OTI_OK; OTI_ERR_NOTPD (dpotrf info > 0); OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE;
 *         OTI_ERR_MEMORY. Caller must release @p res via nd_release().
 */
int nd_cholesky(oti_ctx* ctx, const ndarr_t* a, int32_t lower, ndarr_t* res);

/**
 * @brief Solves A x = b from a Cholesky factor (dpotrs; scipy.linalg.cho_solve).
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     c     OTI_F64 n x n factor from nd_cholesky().
 * @param[in]     lower 1 if @p c is lower (L), 0 if upper (U).
 * @param[in]     b     OTI_F64 (n,) or (n, k).
 * @param[out]    res   New retained array of b's shape.
 *
 * @return OTI_OK; OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY. Caller must release
 *         @p res via nd_release().
 */
int nd_cho_solve(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* res);

/**
 * @brief Solves op(T) x = b with a triangular T (dtrtrs; scipy.linalg.solve_triangular).
 *
 * @param[in,out] ctx           Context, or NULL.
 * @param[in]     t             OTI_F64 n x n; only the chosen triangle is read.
 * @param[in]     b             OTI_F64 (n,) or (n, k).
 * @param[in]     lower         1 for lower, 0 for upper.
 * @param[in]     trans         1 to solve T^T x = b.
 * @param[in]     unit_diagonal 1 to take the diagonal as ones (not read).
 * @param[out]    res           New retained array of b's shape.
 *
 * @return OTI_OK; info > 0 (exactly zero diagonal entry); OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE;
 *         OTI_ERR_MEMORY. Caller must release @p res via nd_release().
 */
int nd_solve_triangular(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                        int32_t trans, int32_t unit_diagonal, ndarr_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
