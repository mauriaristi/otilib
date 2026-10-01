#ifndef OTI_DENSE_GAUSS_H
#define OTI_DENSE_GAUSS_H

// Dense Gauss-point types, SoA batched over integration points (PLAN-dense-update.md, WP6; the
// layout of src/c/semisparse/gauss/gauss.c).
//
// A feoarr_t is an nrows x ncols OTI matrix evaluated at nip integration points. All points share
// one nact and one truncation order. The coefficients are one oarr_t of shape
// nip x (nrows * ncols): entry (i, j) of point ip is element (ip, i + j * nrows) of it, so in every
// direction block the values are column-major over (ip, i, j), points fastest. Consequences:
//
// - Elementwise operations and elementary functions between Gauss values of the same shape are the
//   oarr_t operations applied to the embedded arrays, one batched kernel per call.
// - One matrix entry over all points is one contiguous run of nip reals per direction.
// - A Gauss matrix times a plain matrix, a Gauss matrix dot a plain vector and the integration
//   sum_ip w_ip v_ip are single oarr_t matrix products on reinterpreted shapes (no copies).
//
// A Gauss scalar (feotinum_t) is a 1 x 1 feoarr_t. Every function that can fail returns a status and
// never exits: DN_OK, info > 0 from dgetrf when the real part of a point's matrix is singular, or a
// DN_ERR_* code (< 0; DN_ERR_SIZE for incompatible shapes).

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STRUCTURE     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct {
    oarr_t     arr; ///< nip x (nrows * ncols) coefficients; entry (i, j) at ip is (ip, i + j*nrows).
    uint64_t nrows; ///< Rows of the matrix at each point.
    uint64_t ncols; ///< Columns of the matrix at each point.
    uint64_t   nip; ///< Number of integration points.
} feoarr_t;         ///< Dense OTI matrix at Gauss integration points ("fearr").

typedef feoarr_t feotinum_t; ///< Dense OTI scalar at Gauss integration points ("fenum"): 1 x 1.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Returns an empty Gauss array (0 x 0 at 0 points, no buffers).
 *
 * @return Empty feoarr_t; safe to pass to fearr_free() and to any _to function as output.
 */
feoarr_t fearr_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Makes a Gauss array a zero nrows x ncols array at nip points over bases 1..nact.
 *
 * @param[in]     nact      Number of active bases.
 * @param[in]     nrows     Rows of the matrix at each point.
 * @param[in]     ncols     Columns of the matrix at each point.
 * @param[in]     nip       Number of integration points.
 * @param[in]     trc_order Truncation order.
 * @param[in,out] res       Gauss array; its buffer is reused when large enough. Caller releases it
 *                          with fearr_free().
 *
 * @return DN_OK, DN_ERR_INDEX (trc above _MAXORDER_OTI), or DN_ERR_MEMORY.
 */
int fearr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, uint64_t nip, ord_t trc_order,
                   feoarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the buffers of a Gauss array and resets it to fearr_init().
 *
 * @param[in,out] fe Gauss array to free.
 */
void fearr_free(feoarr_t* fe);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Copies a Gauss array into another one, reusing its buffers when large enough.
 *
 * @param[in]  fe  Source.
 * @param[out] res Destination (may alias @p fe).
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_copy_to(const feoarr_t* fe, feoarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Grows the nact and truncation order of a Gauss array in place.
 *
 * nact becomes max(fe nact, @p nact) and the truncation order max(fe trc, @p trc_order). Existing
 * values are kept (zero-extended).
 *
 * @param[in]     nact      Minimum number of active bases.
 * @param[in]     trc_order Minimum truncation order.
 * @param[in,out] fe        Gauss array to grow.
 *
 * @return DN_OK, DN_ERR_INDEX (trc above _MAXORDER_OTI), or DN_ERR_MEMORY.
 */
int fearr_grow(bases_t nact, ord_t trc_order, feoarr_t* fe);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets the shape bookkeeping of a Gauss array from its embedded oarr_t.
 *
 * Use after writing into fe->arr with an oarr_t function: fe->arr must be nip x (nrows * ncols).
 *
 * @param[in]     nrows Rows at each point.
 * @param[in]     ncols Columns at each point.
 * @param[in]     nip   Number of integration points.
 * @param[in,out] fe    Gauss array to label.
 *
 * @return DN_OK, or DN_ERR_SIZE when fe->arr is not nip x (nrows * ncols).
 */
int fearr_set_shape(uint64_t nrows, uint64_t ncols, uint64_t nip, feoarr_t* fe);
// -------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Extracts the matrix at one integration point.
 *
 * @param[in]  ip  Integration point, < fe->nip.
 * @param[in]  fe  Gauss array.
 * @param[out] res Plain nrows x ncols SoA array with the same nact and orders. Must not be
 *                 &fe->arr (DN_ERR_ARGUMENT).
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_get_ip_to(uint64_t ip, const feoarr_t* fe, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Overwrites the matrix at one integration point.
 *
 * The Gauss array's nact and order grow to @p val's when larger (values at other points are kept).
 *
 * @param[in]     val Plain nrows x ncols SoA array. Must not be &fe->arr (DN_ERR_ARGUMENT).
 * @param[in]     ip  Integration point, < fe->nip.
 * @param[in,out] fe  Gauss array.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_set_ip(const oarr_t* val, uint64_t ip, feoarr_t* fe);
// -------------------------------------------------------------------------------------------------------


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
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_get_slice_to(const feoarr_t* fe, uint64_t i0, uint64_t ni, int64_t istep,
                       uint64_t j0, uint64_t nj, int64_t jstep, feoarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Overwrites a (strided) block of entries at every point.
 *
 * @p val is ni x nj, or 1 x 1 (broadcast to the whole block), at fe->nip points. The Gauss array's
 * nact and order grow to @p val's when larger.
 *
 * @param[in]     val   Gauss values (may not alias @p fe).
 * @param[in]     i0    First row.
 * @param[in]     ni    Number of rows.
 * @param[in]     istep Row step.
 * @param[in]     j0    First column.
 * @param[in]     nj    Number of columns.
 * @param[in]     jstep Column step.
 * @param[in,out] fe    Gauss array.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_set_slice(const feoarr_t* val, uint64_t i0, uint64_t ni, int64_t istep, uint64_t j0,
                    uint64_t nj, int64_t jstep, feoarr_t* fe);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Overwrites one entry at one point with an OTI scalar, growing nact and the order.
 *
 * @param[in]     num Value.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in]     ip  Integration point.
 * @param[in,out] fe  Gauss array.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_set_ijk_o(const otinum_t* num, uint64_t i, uint64_t j, uint64_t ip,
                    feoarr_t* fe);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Overwrites one entry at one point with a real value (its imaginary slots become zero).
 *
 * @param[in]     val Value.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in]     ip  Integration point.
 * @param[in,out] fe  Gauss array.
 *
 * @return DN_OK, or DN_ERR_INDEX.
 */
int fearr_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarr_t* fe);
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
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_from_oarr_to(const oarr_t* arr, uint64_t nip, feoarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Repeats a Gauss scalar over an nrows x ncols matrix at every point.
 *
 * @param[in]  num   Gauss scalar (1 x 1).
 * @param[in]  nrows Rows of the result.
 * @param[in]  ncols Columns of the result.
 * @param[out] res   Gauss array (may not alias @p num).
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_bcast_to(const feoarr_t* num, uint64_t nrows, uint64_t ncols, feoarr_t* res);
// -------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LINEAR ALGEBRA     ----------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Transposes the matrix at every point.
 *
 * @param[in]  fe  Gauss array nrows x ncols.
 * @param[out] res Gauss array ncols x nrows (may alias @p fe).
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int fearr_transpose_to(const feoarr_t* fe, feoarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Per-point matrix products
 * res_ip = a_ip b_ip at every point; F is a Gauss array, O a plain array (the same at every point).
 * All results may alias an operand. Return DN_OK or a DN_ERR_* code.
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
int fearr_matmul_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Gauss times plain (one oarr_t product on the reinterpreted nip*n x q array).
 *
 * @param[in]  a   Gauss array n x q.
 * @param[in]  b   Plain array q x m.
 * @param[out] res Gauss array n x m.
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int fearr_matmul_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


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
int fearr_matmul_OF_to(const oarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Per-point dot products (sum of elementwise products)
 * res_ip = sum_e a_ip[e] b[e], over the column-major entries of equally sized operands.
 * @{
 */

/**
 * @brief Gauss dot plain: one oarr_t product a.arr (nip x N) times b as an N x 1 vector.
 *
 * @param[in]  a   Gauss array with N entries per point.
 * @param[in]  b   Plain array with N entries.
 * @param[out] res Gauss scalar (may alias @p a).
 * @param[in]  dhl Direction helper.
 *
 * @return Status.
 */
int fearr_dot_product_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res,
                            dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


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
int fearr_dot_product_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res,
                            dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


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
int fearr_integrate_to(const feoarr_t* val, const feoarr_t* w, oarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


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
int fearr_det_to(const feoarr_t* fe, feoarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


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
int fearr_inv_to(const feoarr_t* fe, feoarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
