#ifndef OTI_SEMISPARSE_GAUSS_H
#define OTI_SEMISPARSE_GAUSS_H

// Semi-sparse Gauss-point types, SoA batched over integration points (PLAN-semisparse-sparse-
// leveling.md, Phase 4).
//
// A feoarrss_t is an nrows x ncols OTI matrix evaluated at nip integration points. All points share
// one active set and one truncation order. The coefficients are one oarrss_t of shape
// nip x (nrows * ncols): entry (i, j) of point ip is element (ip, i + j * nrows) of it, so in every
// direction block the values are column-major over (ip, i, j), points fastest. Consequences:
//
// - Elementwise operations and elementary functions between Gauss values of the same shape are the
//   oarrss_t operations applied to the embedded arrays, one batched kernel per call.
// - One matrix entry over all points is one contiguous run of nip reals per direction.
// - A Gauss matrix times a plain matrix, a Gauss matrix dot a plain vector and the integration
//   sum_ip w_ip v_ip are single oarrss_t matrix products on reinterpreted shapes (no copies).
//
// A Gauss scalar is a 1 x 1 feoarrss_t. Functions returning a status return 0 on success, info > 0
// from dgetrf when the real part of a point's matrix is singular, or an OTI_LINALG_ERR_* code (< 0).
// Errors on shapes print a message and exit, as the oarrss_t functions do.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STRUCTURE     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct {
    oarrss_t   arr; ///< nip x (nrows * ncols) coefficients; entry (i, j) at ip is (ip, i + j*nrows).
    uint64_t nrows; ///< Rows of the matrix at each point.
    uint64_t ncols; ///< Columns of the matrix at each point.
    uint64_t   nip; ///< Number of integration points.
} feoarrss_t;       ///< Semi-sparse OTI matrix at Gauss integration points.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Returns an empty Gauss array (0 x 0 at 0 points, no buffers).
 *
 * @return Empty feoarrss_t; safe to pass to feoarrss_free() and to any _to function as output.
 */
feoarrss_t feoarrss_init(void);

/**
 * @brief Allocates a zero Gauss array.
 *
 * @param[in] bases     Sorted active global bases, length k (may be NULL when k == 0).
 * @param[in] k         Number of active bases.
 * @param[in] nrows     Rows of the matrix at each point.
 * @param[in] ncols     Columns of the matrix at each point.
 * @param[in] nip       Number of integration points.
 * @param[in] trc_order Truncation order.
 *
 * @return New feoarrss_t. Caller owns memory and must free via feoarrss_free().
 */
feoarrss_t feoarrss_zeros(const bases_t* bases, bases_t k, uint64_t nrows, uint64_t ncols,
                          uint64_t nip, ord_t trc_order);

/**
 * @brief Releases the buffers of a Gauss array and resets it to feoarrss_init().
 *
 * @param[in,out] fe Gauss array to free.
 */
void feoarrss_free(feoarrss_t* fe);

/**
 * @brief Copies a Gauss array into another one, reusing its buffers when large enough.
 *
 * @param[in]  fe  Source.
 * @param[out] res Destination (may alias @p fe).
 */
void feoarrss_copy_to(const feoarrss_t* fe, feoarrss_t* res);

/**
 * @brief Grows the active set and truncation order of a Gauss array in place.
 *
 * The union of the array's bases and @p bases becomes the active set; the truncation order becomes
 * the max of the current one and @p trc_order. Existing values are kept (zero-extended).
 *
 * @param[in]     bases     Sorted global bases to add, length k.
 * @param[in]     k         Number of bases to add.
 * @param[in]     trc_order Minimum truncation order.
 * @param[in,out] fe        Gauss array to grow.
 */
void feoarrss_grow(const bases_t* bases, bases_t k, ord_t trc_order, feoarrss_t* fe);

/**
 * @brief Sets the shape bookkeeping of a Gauss array from its embedded oarrss_t.
 *
 * Use after writing into fe->arr with an oarrss_t function: fe->arr must be nip x (nrows * ncols).
 *
 * @param[in]     nrows Rows at each point.
 * @param[in]     ncols Columns at each point.
 * @param[in]     nip   Number of integration points.
 * @param[in,out] fe    Gauss array to label.
 */
void feoarrss_set_shape(uint64_t nrows, uint64_t ncols, uint64_t nip, feoarrss_t* fe);
// -------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Extracts the matrix at one integration point.
 *
 * @param[in]  ip  Integration point, < fe->nip.
 * @param[in]  fe  Gauss array.
 * @param[out] res Plain nrows x ncols SoA array with the same active set and order.
 */
void feoarrss_get_ip_to(uint64_t ip, const feoarrss_t* fe, oarrss_t* res);

/**
 * @brief Overwrites the matrix at one integration point.
 *
 * The Gauss array's set and order grow to include @p val's (values at other points are kept).
 *
 * @param[in]     val Plain nrows x ncols SoA array.
 * @param[in]     ip  Integration point, < fe->nip.
 * @param[in,out] fe  Gauss array.
 */
void feoarrss_set_ip(const oarrss_t* val, uint64_t ip, feoarrss_t* fe);

/**
 * @brief Extracts a (strided) block of entries at every point.
 *
 * Rows i0, i0 + istep, ... (ni of them) and columns j0, j0 + jstep, ... (nj of them), as Python
 * slices give them (steps may be negative).
 *
 * @param[in]  fe    Gauss array.
 * @param[in]  i0    First row.
 * @param[in]  ni    Number of rows.
 * @param[in]  istep Row step.
 * @param[in]  j0    First column.
 * @param[in]  nj    Number of columns.
 * @param[in]  jstep Column step.
 * @param[out] res   Gauss array ni x nj at fe->nip points (may not alias @p fe).
 */
void feoarrss_get_slice_to(const feoarrss_t* fe, uint64_t i0, uint64_t ni, int64_t istep,
                           uint64_t j0, uint64_t nj, int64_t jstep, feoarrss_t* res);

/**
 * @brief Overwrites a (strided) block of entries at every point.
 *
 * @p val is ni x nj, or 1 x 1 (broadcast to the whole block), at fe->nip points. The Gauss array's
 * set and order grow to include @p val's.
 *
 * @param[in]     val   Gauss values (may not alias @p fe).
 * @param[in]     i0    First row.
 * @param[in]     ni    Number of rows.
 * @param[in]     istep Row step.
 * @param[in]     j0    First column.
 * @param[in]     nj    Number of columns.
 * @param[in]     jstep Column step.
 * @param[in,out] fe    Gauss array.
 */
void feoarrss_set_slice(const feoarrss_t* val, uint64_t i0, uint64_t ni, int64_t istep, uint64_t j0,
                        uint64_t nj, int64_t jstep, feoarrss_t* fe);

/**
 * @brief Overwrites one entry at one point with an OTI scalar, growing the set and order.
 *
 * @param[in]     num Value.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in]     ip  Integration point.
 * @param[in,out] fe  Gauss array.
 */
void feoarrss_set_ijk_o(const ssotinum_t* num, uint64_t i, uint64_t j, uint64_t ip,
                        feoarrss_t* fe);

/**
 * @brief Overwrites one entry at one point with a real value (its imaginary slots become zero).
 *
 * @param[in]     val Value.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in]     ip  Integration point.
 * @param[in,out] fe  Gauss array.
 */
void feoarrss_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarrss_t* fe);
// -------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     BROADCASTS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Repeats a plain SoA array at every integration point.
 *
 * @param[in]  arr Plain nrows x ncols array.
 * @param[in]  nip Number of integration points.
 * @param[out] res Gauss array nrows x ncols at nip points.
 */
void feoarrss_from_oarrss_to(const oarrss_t* arr, uint64_t nip, feoarrss_t* res);

/**
 * @brief Repeats a Gauss scalar over an nrows x ncols matrix at every point.
 *
 * @param[in]  num   Gauss scalar (1 x 1).
 * @param[in]  nrows Rows of the result.
 * @param[in]  ncols Columns of the result.
 * @param[out] res   Gauss array (may not alias @p num).
 */
void feoarrss_bcast_to(const feoarrss_t* num, uint64_t nrows, uint64_t ncols, feoarrss_t* res);
// -------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LINEAR ALGEBRA     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Transposes the matrix at every point.
 *
 * @param[in]  fe  Gauss array nrows x ncols.
 * @param[out] res Gauss array ncols x nrows (may alias @p fe).
 */
void feoarrss_transpose_to(const feoarrss_t* fe, feoarrss_t* res);

/**
 * @name Per-point matrix products
 * res_ip = a_ip b_ip at every point; F is a Gauss array, O a plain array (the same at every point).
 * All results may alias an operand. Return 0 or an OTI_LINALG_ERR_* code.
 * @{
 */

/**
 * @brief Gauss times Gauss.
 *
 * @param[in]  a   Gauss array n x q.
 * @param[in]  b   Gauss array q x m at the same number of points.
 * @param[out] res Gauss array n x m.
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_matmul_FF_to(const feoarrss_t* a, const feoarrss_t* b, feoarrss_t* res, dhelpl_t dhl);

/**
 * @brief Gauss times plain (one oarrss_t product on the reinterpreted nip*n x q array).
 *
 * @param[in]  a   Gauss array n x q.
 * @param[in]  b   Plain array q x m.
 * @param[out] res Gauss array n x m.
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_matmul_FO_to(const feoarrss_t* a, const oarrss_t* b, feoarrss_t* res, dhelpl_t dhl);

/**
 * @brief Plain times Gauss (through transposes: (a b_ip)^T = b_ip^T a^T).
 *
 * @param[in]  a   Plain array n x q.
 * @param[in]  b   Gauss array q x m.
 * @param[out] res Gauss array n x m.
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_matmul_OF_to(const oarrss_t* a, const feoarrss_t* b, feoarrss_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------

/**
 * @name Per-point dot products (sum of elementwise products)
 * res_ip = sum_e a_ip[e] b[e], over the column-major entries of equally sized operands.
 * @{
 */

/**
 * @brief Gauss dot plain: one oarrss_t product a.arr (nip x N) times b as an N x 1 vector.
 *
 * @param[in]  a   Gauss array with N entries per point.
 * @param[in]  b   Plain array with N entries.
 * @param[out] res Gauss scalar (may alias @p a).
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_dot_product_FO_to(const feoarrss_t* a, const oarrss_t* b, feoarrss_t* res,
                               dhelpl_t dhl);

/**
 * @brief Gauss dot Gauss.
 *
 * @param[in]  a   Gauss array with N entries per point.
 * @param[in]  b   Gauss array with N entries per point, same number of points.
 * @param[out] res Gauss scalar (may alias an operand).
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_dot_product_FF_to(const feoarrss_t* a, const feoarrss_t* b, feoarrss_t* res,
                               dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Gauss integration: res = sum_ip w_ip val_ip (one product w^T val.arr).
 *
 * @param[in]  val Gauss array nrows x ncols.
 * @param[in]  w   Gauss scalar (weights, possibly OTI) at the same number of points.
 * @param[out] res Plain nrows x ncols array.
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_integrate_to(const feoarrss_t* val, const feoarrss_t* w, oarrss_t* res, dhelpl_t dhl);

/**
 * @brief Determinant at every point.
 *
 * Closed forms for n <= 3 (batched over the points); LU per point for larger n.
 *
 * @param[in]  fe  Gauss array n x n.
 * @param[out] res Gauss scalar (may alias @p fe).
 * @param[in]  dhl Direction helper.
 *
 * @return Status (n > 3: singular real part of some point, or a size error).
 */
int feoarrss_det_to(const feoarrss_t* fe, feoarrss_t* res, dhelpl_t dhl);

/**
 * @brief Inverse at every point.
 *
 * Closed forms for n <= 3 (batched); LU per point for larger n. The real part of every point's
 * matrix must be nonsingular (for n <= 3, a zero real determinant gives inf/nan coefficients, as
 * the real division does; for n > 3 the status reports it).
 *
 * @param[in]  fe  Gauss array n x n.
 * @param[out] res Gauss array n x n (may alias @p fe).
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int feoarrss_inv_to(const feoarrss_t* fe, feoarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
