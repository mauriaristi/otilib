#ifndef OTI_DENSE_SOA_LINALG_H
#define OTI_DENSE_SOA_LINALG_H

// Dense SoA linear algebra (PLAN-dense-update.md, WP3; the semi-sparse algorithm of
// src/c/semisparse/soa/linalg.c).
//
// The real part is factored once (dgetrf). For each order p the order-p blocks of the solution
// solve K_re X_p = B_p - sum_{s=1..p} K_s X_{p-s} (products restricted to order p) with one
// multi-right-hand-side dgetrs over all order-p directions. This follows
// src/c/sparse/array/algebra_lu.c without its packing step.
//
// Every function returns a status and never calls exit(): DN_OK on success; info > 0 from dgetrf
// when the real part is singular (at any n: there is no closed-form fallback); or a DN_ERR_* code
// (< 0; DN_ERR_SIZE, DN_ERR_MEMORY and DN_ERR_PIVOT equal OTI_LINALG_ERR_*). Every int passed to an
// oti_d* wrapper goes through oti_lapack_fits(), and work-buffer byte counts are checked for size_t
// overflow before malloc. The global truncation order is never read: no set_trunc_order() needed.


/**
 * @brief Factors a square matrix for oarr_lu_solve().
 *
 * @param[in]  A  Square matrix.
 * @param[out] lu Factorization, overwritten without being freed (pass a new or oarr_lu_free()'d
 *                one). Caller releases it with oarr_lu_free() (also after a failure).
 *
 * @return Status (see file notes).
 */
int oarr_lu_factor(const oarr_t* A, oarr_lu_t* lu);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases a factorization from oarr_lu_factor().
 *
 * @param[in,out] lu Factorization; left empty.
 */
void oarr_lu_free(oarr_lu_t* lu);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Solves A X = B with a factorization from oarr_lu_factor().
 *
 * The solution has nact = max(nact_A, nact_b) and the larger truncation order. A factorization of a
 * singular matrix (oarr_lu_factor() returned info > 0) gives info > 0 again (the first zero pivot,
 * 1-based) and leaves @p x untouched, never NaNs with DN_OK.
 *
 * @param[in]     lu  Factorization of A.
 * @param[in]     b   Right-hand sides, n x m.
 * @param[in,out] x   Solution, n x m; may alias @p b.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status (see file notes).
 */
int oarr_lu_solve(const oarr_lu_t* lu, const oarr_t* b, oarr_t* x, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Solves K X = B.
 *
 * @param[in]     K   Square matrix.
 * @param[in]     b   Right-hand sides, n x m.
 * @param[in,out] x   Solution, n x m; may alias @p K or @p b.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status (see file notes).
 */
int oarr_solve_to(const oarr_t* K, const oarr_t* b, oarr_t* x, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Inverse of a square matrix (oarr_solve_to() with the identity).
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Inverse; may alias @p A.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status (see file notes).
 */
int oarr_inv_to(const oarr_t* A, oarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Determinant of a square matrix.
 *
 * With A = A_re (I + M), M = A_re^-1 (A - A_re) has no real part, so
 * det A = det(A_re) exp(sum_{m=1..trc} (-1)^(m+1) tr(M^m) / m); the series is exact at the
 * truncation order.
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Determinant.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status (see file notes).
 */
int oarr_det_to(const oarr_t* A, otinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------

#endif
