#ifndef OTI_SPARSE_ARRAY_ALGEBRA_LU_H
#define OTI_SPARSE_ARRAY_ALGEBRA_LU_H

// ----------------------------------------------------------------------------------------------------
// OTI linear algebra on LAPACK: LU factorization, linear solves, and the dense packing helpers they use.
//
// Method (HYPAD LU): the real part is factorized with LAPACK (dgetrf), and every imaginary order is
// obtained by real triangular solves, order by order. No OTI division is ever performed. Pivoting is
// decided by the real part only, so a singular real part is reported as a failure (status > 0).
//
// Dense layout used by the packing helpers: order `ord` of an nrows x ncols array is stored in a
// column-major real buffer of shape nrows x (ncols * N_ord), N_ord = dhelp_ndirOrder(nbases, ord);
// column block d (columns d*ncols .. d*ncols+ncols-1) holds imaginary direction d.
//
// Status codes returned by the solvers (int):
//   0                        success.
//   > 0                      the real part is singular: U(k,k) = 0 for k = status (LAPACK info).
//   OTI_LINALG_ERR_SIZE      a dimension does not fit in the 32-bit LAPACK integers.
//   OTI_LINALG_ERR_MEMORY    a work buffer could not be allocated.
//   OTI_LINALG_ERR_PIVOT     pivot indices out of range (lu_solve).
// ----------------------------------------------------------------------------------------------------

/// Largest n for which inv / det use the closed forms (cofactors) instead of the LU path.
#ifndef _OTI_LINALG_CLOSED_FORM_MAX
#define _OTI_LINALG_CLOSED_FORM_MAX 3
#endif

#define OTI_LINALG_ERR_SIZE    (-1) ///< Dimension too large for the LAPACK interface.
#define OTI_LINALG_ERR_MEMORY  (-2) ///< Work buffer allocation failed.
#define OTI_LINALG_ERR_PIVOT   (-3) ///< Invalid pivot indices.

#define OTI_MASK_FULL          0    ///< Every entry.
#define OTI_MASK_STRICT_LOWER  1    ///< Entries with i > j.
#define OTI_MASK_UPPER         2    ///< Entries with i <= j.


// ****************************************************************************************************
// Packing helpers.
// ****************************************************************************************************

/**************************************************************************************************//**
@brief Highest imaginary basis present in an array (0 if the array is real).

@param[in] arr    Array.
@param[in] dhl    Direction helper list object.

@return Highest basis index m, such that every direction of order o has index < dhelp_ndirOrder(m, o).
******************************************************************************************************/
bases_t arrso_get_nbases(arrso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Copies the real part of an array into a column-major buffer.

@param[in]  arr   Array (nrows x ncols).
@param[out] buf   Buffer of at least nrows*ncols values. buf[i + j*nrows] = Re(arr[i,j]).
******************************************************************************************************/
void arrso_get_real_colmajor(arrso_t* arr, coeff_t* buf);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Copies the coefficients of order `ord` of an array into a column-major buffer.

buf[i + (d*ncols + j)*nrows] is the coefficient of direction d (order ord) of arr[i,j]. Directions not
present are written as zero.

@param[in]  arr     Array (nrows x ncols).
@param[in]  ord     Order (>= 1).
@param[in]  nbases  Number of bases: every direction index must be < dhelp_ndirOrder(nbases, ord).
@param[out] buf     Buffer of at least nrows * ncols * dhelp_ndirOrder(nbases, ord) values.
******************************************************************************************************/
void arrso_get_order_colmajor(arrso_t* arr, ord_t ord, bases_t nbases, coeff_t* buf);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Replaces the coefficients of order `ord` of the masked entries of an array from a buffer.

Inverse of arrso_get_order_colmajor. Exact zeros are skipped, so sparsity is kept. The other orders
and the real part of every entry are kept. Entries are reallocated when needed.

@param[in]    buf     Buffer, layout of arrso_get_order_colmajor.
@param[in]    ord     Order (>= 1, <= the truncation order supported by dhl).
@param[in]    nbases  Number of bases used to build buf.
@param[in]    mask    OTI_MASK_FULL, OTI_MASK_STRICT_LOWER or OTI_MASK_UPPER.
@param[inout] arr     Array whose entries are updated. Its entries must own their memory.
@param[in]    dhl     Direction helper list object.
******************************************************************************************************/
void arrso_set_order_colmajor(coeff_t* buf, ord_t ord, bases_t nbases, int mask, arrso_t* arr,
                              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Applies the LAPACK row interchanges of ipiv to an array: RES = P^T ARR.

Row k is swapped with row ipiv[k]-1, for k = 0 .. n-1, in that order (as LAPACK dlaswp).

@param[in]  arr    Array with n rows.
@param[in]  ipiv   Pivot indices, 1-based, length n (from arrso_lu_factor_to).
@param[out] res    Result, same shape as arr. May be arr itself.
@param[in]  dhl    Direction helper list object.
******************************************************************************************************/
void arrso_permute_rows_to(arrso_t* arr, int32_t* ipiv, arrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**
 * @name Triangular parts
 * @{
 */

/**************************************************************************************************//**
@brief Lower triangular part of an array; the other entries are set to zero.

Keeps the entries with i >= j (i > j if strict).

@param[in]  arr     Array.
@param[in]  strict  Nonzero to exclude the diagonal.
@param[out] res     Result, same shape as arr. May be arr itself.
@param[in]  dhl     Direction helper list object.
******************************************************************************************************/
void arrso_tril_to(arrso_t* arr, int strict, arrso_t* res, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Upper triangular part of an array; the other entries are set to zero.

Keeps the entries with i <= j (i < j if strict).

@param[in]  arr     Array.
@param[in]  strict  Nonzero to exclude the diagonal.
@param[out] res     Result, same shape as arr. May be arr itself.
@param[in]  dhl     Direction helper list object.
******************************************************************************************************/
void arrso_triu_to(arrso_t* arr, int strict, arrso_t* res, dhelpl_t dhl);

/** @} */
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
// Solvers.
// ****************************************************************************************************

/**************************************************************************************************//**
@brief Solves the OTI linear system K X = B (block solver on the real LU factors of K).

X_0 = K_r^-1 B_0; X_p = K_r^-1 ( B_p - sum_{i=1..p} K_i X_{p-i} ), all directions of an order in one
LAPACK dgetrs call. Cheaper than arrso_lu_factor_to + arrso_lu_solve_to for a single solve.

@param[in]  K      Square n x n array.
@param[in]  b      Right-hand side, n x m.
@param[out] x      Solution, n x m, allocated by the caller. Every coefficient is overwritten. May be
                   the same array as K or b (a temporary is used then).
@param[in]  dhl    Direction helper list object.

@return 0 on success; > 0 if the real part of K is singular (x is then filled with NaN); < 0 on a
        size or memory error (x filled with NaN). See the status codes at the top of this header.
******************************************************************************************************/
int     arrso_solve_to(arrso_t* K, arrso_t* b, arrso_t* x, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Allocating variant of arrso_solve_to.

@param[in]  K       Square n x n array.
@param[in]  b       Right-hand side, n x m.
@param[out] status  Status of arrso_solve_to (may be NULL).
@param[in]  dhl     Direction helper list object.

@return New n x m array, owned by the caller (free with arrso_free). NaN-filled on failure.
******************************************************************************************************/
arrso_t arrso_solve(arrso_t* K, arrso_t* b, int* status, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief OTI LU factorization with partial pivoting on the real part: A = P L U.

LU holds the factors in LAPACK layout: strictly lower part = L (unit diagonal not stored), upper
part with the diagonal = U, both OTI-valued. [L]_p, [U]_p follow from
X = L_r^-1 R_p U_r^-1, [U]_p = triu(X) U_r, [L]_p = L_r stril(X), with
R_p = [P^T A]_p - sum_{i=1..p-1} [L]_i [U]_{p-i}.

@param[in]  A      Square n x n array.
@param[out] LU     Factors, n x n, allocated by the caller. Every coefficient is overwritten. May be A
                   (a temporary is used then).
@param[out] ipiv   Pivot indices, 1-based as LAPACK, length n, caller-owned. Row k was interchanged
                   with row ipiv[k]-1.
@param[in]  dhl    Direction helper list object.

@return 0 on success. > 0 if the real part is singular: the real factors are written, the imaginary
        orders are left zero. < 0 on a size or memory error (LU untouched).
******************************************************************************************************/
int     arrso_lu_factor_to(arrso_t* A, arrso_t* LU, int32_t* ipiv, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Allocating variant of arrso_lu_factor_to.

@param[in]  A       Square n x n array.
@param[out] ipiv    Pivot indices, caller-owned, length n.
@param[out] status  Status of arrso_lu_factor_to (may be NULL).
@param[in]  dhl     Direction helper list object.

@return New n x n array with the packed factors, owned by the caller (free with arrso_free).
******************************************************************************************************/
arrso_t arrso_lu_factor(arrso_t* A, int32_t* ipiv, int* status, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Solves A X = B with the OTI factors of arrso_lu_factor_to.

Y_p = L_r^-1 ( [P^T B]_p - sum_{i=1..p} [L]_i Y_{p-i} ),
X_p = U_r^-1 ( Y_p       - sum_{i=1..p} [U]_i X_{p-i} ).

@param[in]  LU     Packed factors from arrso_lu_factor_to (n x n).
@param[in]  ipiv   Pivot indices from arrso_lu_factor_to (1-based, length n).
@param[in]  b      Right-hand side, n x m.
@param[out] x      Solution, n x m, allocated by the caller. Every coefficient is overwritten. May be
                   the same array as b or LU (a temporary is used then).
@param[in]  dhl    Direction helper list object.

@return 0 on success; OTI_LINALG_ERR_PIVOT for pivot indices out of 1..n; > 0 if a diagonal entry of
        Re(U) is exactly zero (index, 1-based); other negative codes as above. x is NaN-filled on
        failure.
******************************************************************************************************/
int     arrso_lu_solve_to(arrso_t* LU, int32_t* ipiv, arrso_t* b, arrso_t* x, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Allocating variant of arrso_lu_solve_to.

@param[in]  LU      Packed factors from arrso_lu_factor_to.
@param[in]  ipiv    Pivot indices from arrso_lu_factor_to.
@param[in]  b       Right-hand side, n x m.
@param[out] status  Status of arrso_lu_solve_to (may be NULL).
@param[in]  dhl     Direction helper list object.

@return New n x m array, owned by the caller (free with arrso_free). NaN-filled on failure.
******************************************************************************************************/
arrso_t arrso_lu_solve(arrso_t* LU, int32_t* ipiv, arrso_t* b, int* status, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Sets every entry of an array to NaN (real part), clearing its imaginary coefficients.

@param[inout] arr  Array.
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/
void arrso_set_nan(arrso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif
