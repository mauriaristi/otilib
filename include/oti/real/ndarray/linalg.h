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
//   - Stacked inputs (..., n, n) loop over the batch axes with oti_parallel_for_blas(); a stack's
//     factors are compact per-matrix F blocks of one buffer with one ipiv array (S29).
//   - The _to forms (S29) write an existing `out` of exactly the result shape: in place when each
//     result matrix is 'N'-usable (stride 1 down a column, column stride >= n), else through a
//     per-matrix F temporary. out may be b itself (then nothing is copied before the solve); a
//     partial overlap of out with b goes through a snapshot of b; out overlapping a factor that is
//     read in place (nd_cho_solve_to, nd_solve_triangular_to) makes a private copy of the factor.
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
    ndarr_t  lu;     ///< Factors, shape (..., n, n), every matrix F (column stride n): a retained
                     ///< private buffer of compact per-matrix F blocks, or (overwrite) a view of the
                     ///< input (retained when the input has a control block, else a temporary).
    int*     ipiv;   ///< 1-based pivots from dgetrf, nbatch * n (matrix i at ipiv + i * n); owned
                     ///< (malloc), freed by nd_lu_free().
    int64_t  n;      ///< Order of the matrices.
    int32_t  trans;  ///< 0: factors of A; 1: factors of A^T (C-order matrices read as A^T); shared by
                     ///< every matrix of a stack.
    int32_t  info;   ///< First positive dgetrf info in C order of the batch (U(i, i) exactly zero), else
                     ///< 0.
    int64_t  nbatch; ///< Number of matrices (product of the batch extents; 1 for a 2-D input).
    int*     infos;  ///< dgetrf info of every matrix, nbatch entries; owned (malloc), freed by
                     ///< nd_lu_free().
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
 * @brief Factors a square matrix or a stack (..., n, n) of them (dgetrf), with the orientation rules
 *        above.
 *
 * @param[in,out] ctx       Context, or NULL.
 * @param[in,out] a         OTI_F64 (..., n, n). Overwritten (unspecified) only with overwrite = 1.
 * @param[in]     overwrite 1 to factor @p a in place when it is writeable, every matrix is C- or
 *                          F-contiguous and the array has no internal overlap.
 * @param[out]    lu        Factorization; overwritten without being freed (nd_lu_init() first).
 *
 * @return OTI_OK; the first positive info in C order of the batch (exactly singular: lu is complete,
 *         lu->infos says which matrices; usable by determinants, not by solves); OTI_ERR_SHAPE (not a
 *         stack of square matrices); OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY; OTI_ERR_BUSY
 *         (overwrite = 1 and the input's buffer is growing, so it cannot be retained). On a negative
 *         status @p lu is left empty. Caller must free @p lu via nd_lu_free() in every case.
 */
int nd_lu_factor(oti_ctx* ctx, ndarr_t* a, int32_t overwrite, nd_lu_t* lu);

/**
 * @brief Solves A x = b with a factorization (dgetrs, 'T' when lu->trans is 1), NumPy 2 rules: b of
 *        ndim 1 is one vector (n,), otherwise (..., n, k) broadcasting against the factors' batch.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     lu  Factorization with info == 0.
 * @param[in]     b   OTI_F64 (n,) or (..., n, k).
 * @param[out]    res New retained array (per-matrix F blocks; a vector result is C-contiguous).
 *
 * @return OTI_OK; lu->info when it is > 0 (nothing solved); OTI_ERR_SHAPE; OTI_ERR_DTYPE;
 *         OTI_ERR_SIZE; OTI_ERR_MEMORY. Caller must release @p res via nd_release().
 */
int nd_lu_solve(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* res);

/**
 * @brief nd_lu_solve() into an existing output (S29): in place when out's matrices are 'N'-usable;
 *        b == out solves in place with no copy.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     lu  Factorization with info == 0.
 * @param[in]     b   OTI_F64 (n,) or (..., n, k).
 * @param[in,out] out Writeable OTI_F64 of exactly the result shape, free of internal overlap; may be
 *                    (or overlap) b; must not overlap lu->lu.
 *
 * @return As nd_lu_solve(), plus OTI_ERR_READONLY and OTI_ERR_LAYOUT (internal overlap of out, or out
 *         overlapping the factors). On failure out holds unspecified values.
 */
int nd_lu_solve_to(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* out);

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
 * @brief nd_solve() into an existing output (S29; the Fortran _into forms).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64 (..., n, n); may overlap out (it is factored into a private buffer
 *                    first).
 * @param[in]     b   OTI_F64 (n,) or (..., n, k); may be (or overlap) out.
 * @param[in,out] out Writeable OTI_F64 of exactly the result shape, free of internal overlap.
 *
 * @return As nd_solve(), plus OTI_ERR_READONLY and OTI_ERR_LAYOUT (internal overlap of out).
 */
int nd_solve_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out);

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
 * @param[in]     b     OTI_F64 (n,) or (..., n, k) (a stack of right-hand sides).
 * @param[out]    res   New retained array of b's shape (per-matrix F blocks).
 *
 * @return OTI_OK; OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY. Caller must release
 *         @p res via nd_release().
 */
int nd_cho_solve(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* res);

/**
 * @brief nd_cho_solve() into an existing output (S29).
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     c     OTI_F64 n x n factor; may overlap out (then it is copied first).
 * @param[in]     lower 1 if @p c is lower (L), 0 if upper (U).
 * @param[in]     b     OTI_F64 (n,) or (..., n, k); may be (or overlap) out.
 * @param[in,out] out   Writeable OTI_F64 of b's shape, free of internal overlap.
 *
 * @return As nd_cho_solve(), plus OTI_ERR_READONLY and OTI_ERR_LAYOUT (internal overlap of out).
 */
int nd_cho_solve_to(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* out);

/**
 * @brief Solves op(T) x = b with a triangular T (dtrtrs; scipy.linalg.solve_triangular).
 *
 * @param[in,out] ctx           Context, or NULL.
 * @param[in]     t             OTI_F64 n x n; only the chosen triangle is read.
 * @param[in]     b             OTI_F64 (n,) or (..., n, k) (a stack of right-hand sides).
 * @param[in]     lower         1 for lower, 0 for upper.
 * @param[in]     trans         1 to solve T^T x = b.
 * @param[in]     unit_diagonal 1 to take the diagonal as ones (not read).
 * @param[out]    res           New retained array of b's shape (per-matrix F blocks).
 *
 * @return OTI_OK; info > 0 (exactly zero diagonal entry); OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE;
 *         OTI_ERR_MEMORY. Caller must release @p res via nd_release().
 */
int nd_solve_triangular(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                        int32_t trans, int32_t unit_diagonal, ndarr_t* res);

/**
 * @brief nd_solve_triangular() into an existing output (S29).
 *
 * @param[in,out] ctx           Context, or NULL.
 * @param[in]     t             OTI_F64 n x n; may overlap out (then it is copied first).
 * @param[in]     b             OTI_F64 (n,) or (..., n, k); may be (or overlap) out.
 * @param[in]     lower         1 for lower, 0 for upper.
 * @param[in]     trans         1 to solve T^T x = b.
 * @param[in]     unit_diagonal 1 to take the diagonal as ones.
 * @param[in,out] out           Writeable OTI_F64 of b's shape, free of internal overlap.
 *
 * @return As nd_solve_triangular(), plus OTI_ERR_READONLY and OTI_ERR_LAYOUT (internal overlap of
 *         out). On info > 0 out holds unspecified values.
 */
int nd_solve_triangular_to(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                           int32_t trans, int32_t unit_diagonal, ndarr_t* out);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
