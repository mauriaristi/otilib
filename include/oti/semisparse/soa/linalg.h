#ifndef OTI_SEMISPARSE_SOA_LINALG_H
#define OTI_SEMISPARSE_SOA_LINALG_H

// Semi-sparse SoA linear algebra (PLAN-semisparse.md, Section 4.4).
//
// The real part is factored once (dgetrf). For each order p the order-p blocks of the solution
// solve K_re X_p = B_p - sum_{s=1..p} K_s X_{p-s} (products restricted to order p) with one
// multi-right-hand-side dgetrs over all order-p directions. This follows
// src/c/sparse/array/algebra_lu.c without its packing step.
//
// Every function returns a status: 0 on success; info > 0 from dgetrf when the real part is
// singular; or an OTI_LINALG_ERR_* code (< 0, include/oti/sparse/array/algebra_lu.h).


/**
 * @brief Factors a square matrix for oarrss_lu_solve().
 *
 * @param[in]  A  Square matrix.
 * @param[out] lu Factorization. Caller releases it with oarrss_lu_free() (also after a failure).
 *
 * @return Status (see file notes).
 */
int oarrss_lu_factor(const oarrss_t* A, oarrss_lu_t* lu);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases a factorization from oarrss_lu_factor().
 *
 * @param[in,out] lu Factorization; left empty.
 */
void oarrss_lu_free(oarrss_lu_t* lu);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Solves A X = B with a factorization from oarrss_lu_factor().
 *
 * The solution has the union of the active sets of A and B and the larger truncation order.
 *
 * @param[in]     lu  Factorization of A.
 * @param[in]     b   Right-hand sides, n x m.
 * @param[in,out] x   Solution, n x m; may alias @p b.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status (see file notes).
 */
int oarrss_lu_solve(const oarrss_lu_t* lu, const oarrss_t* b, oarrss_t* x, dhelpl_t dhl);
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
int oarrss_solve_to(const oarrss_t* K, const oarrss_t* b, oarrss_t* x, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Inverse of a square matrix (oarrss_solve_to() with the identity).
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Inverse; may alias @p A.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status (see file notes).
 */
int oarrss_inv_to(const oarrss_t* A, oarrss_t* res, dhelpl_t dhl);
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
int oarrss_det_to(const oarrss_t* A, ssotinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------

#endif
