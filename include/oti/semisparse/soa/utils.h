#ifndef OTI_SEMISPARSE_SOA_UTILS_H
#define OTI_SEMISPARSE_SOA_UTILS_H

// Semi-sparse SoA arrays: order and derivative plumbing, trunc_dot / trunc_sub / dot_product,
// rom_eval, interp1d, moving_average, inv_block (PLAN-semisparse-sparse-leveling.md, Phase 2).
//
// inv_block needs no kernel of its own: its block recurrence is oarrss_inv_to() (one LU of the real
// part, then one multi-RHS solve per order). Global-layout conventions are those of
// include/oti/semisparse/scalar/utils.h. Results over two operands use the union of their active
// sets and the larger truncation order, like every other semi-sparse binary operation.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     EXTRACTION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Extracts, in every element, the coefficients that contain a direction.
 *
 * Elementwise ssoti_extract_im_to() (same result as arrso_extract_im()): the result keeps the
 * active set, its truncation order is trc_order - order, and its real block is the direction's
 * block. Order 0 copies the array; a direction of order above act_order gives a real zero array.
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 */
void oarrss_extract_im_to(imdir_t idx, ord_t order, const oarrss_t* arr, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Extracts, in every element, the derivatives that contain a direction.
 *
 * Elementwise ssoti_extract_deriv_to() (same result as arrso_extract_deriv()).
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 */
void oarrss_extract_deriv_to(imdir_t idx, ord_t order, const oarrss_t* arr, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATED ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Truncated matrix product: the order (orda + ordb) part of A_orda B_ordb.
 *
 * res = sum over order-@p orda directions i of A and order-@p ordb directions j of B of
 * A_i B_j e(i * j), where A_0 / B_0 are the real blocks (the sparse csrmatrix_trunc_matmul(),
 * soti_trunc_gem_oo_to() per entry). Every other order of the result is zero; the result is over
 * the union of the active sets with the larger truncation order, and is zero when
 * orda + ordb exceeds it. One dgemm per order-@p orda direction of A, against all the order-@p ordb
 * blocks of B at once (they are contiguous), scattered through the local product table.
 *
 * @param[in]     orda Order taken from @p A.
 * @param[in]     A    Left matrix, nrows x ninner.
 * @param[in]     ordb Order taken from @p B.
 * @param[in]     B    Right matrix, ninner x ncols.
 * @param[in,out] res  Result, nrows x ncols; may alias @p A or @p B.
 * @param[in]     dhl  Direction helper list.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE for incompatible shapes or a LAPACK dimension overflow.
 */
int oarrss_trunc_matmul_OO_to(ord_t orda, const oarrss_t* A, ord_t ordb, const oarrss_t* B,
                              oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Truncated subtraction: keeps only the order-@p order part of A - B.
 *
 * Elementwise ssoti_trunc_sub_to() (same result as arrso_trunc_sub_OO_to()).
 *
 * @param[in]     order Order to keep.
 * @param[in]     A     First operand.
 * @param[in]     B     Second operand, same shape.
 * @param[in,out] res   Result; may alias either operand.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE when the shapes differ.
 */
int oarrss_trunc_sub_OO_to(ord_t order, const oarrss_t* A, const oarrss_t* B, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sum of elementwise products of two arrays with the same number of elements.
 *
 * res = sum_e A[e] B[e] over the column-major element index e (the vector dot product; for arrays
 * of equal shape, or vectors, this is the pairing arrso_dotproduct_OO() makes). Table-driven over
 * the union set: coefficient pair (i, j) contributes <A_i, B_j> to direction i * j.
 *
 * @param[in]     A   First operand.
 * @param[in]     B   Second operand, A->size == B->size.
 * @param[in,out] res Result scalar.
 * @param[in]     dhl Direction helper list.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE when the sizes differ.
 */
int oarrss_dot_product_OO_to(const oarrss_t* A, const oarrss_t* B, ssotinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ROM EVALUATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Evaluates the Taylor polynomial of every element at a perturbation of the active bases.
 *
 * Elementwise ssoti_rom_eval() (the values of arrso_taylor_integrate()). The result is real
 * (no bases, truncation order 0).
 *
 * @param[in]     arr    Array.
 * @param[in]     deltas Perturbation of each active base (local order), length arr->nbases.
 * @param[in,out] res    Real result, same shape; may alias @p arr.
 */
void oarrss_rom_eval_to(const oarrss_t* arr, const coeff_t* deltas, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     GLOBAL LAYOUTS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Writes every coefficient (or derivative) of an array in the layout of matso.get_all_ims().
 *
 * @p out is a C-ordered (C(nbasis+order, order), nrows, ncols) array: out[d, r, c] holds the
 * coefficient of global position d (see ssoti_get_all_ims_to()) of element (r, c). The function
 * zeroes @p out first. Directions of order above @p order or with a base above @p nbasis are
 * skipped.
 *
 * @param[in]  arr    Array.
 * @param[in]  nbasis Number of global bases of the layout.
 * @param[in]  order  Highest order of the layout.
 * @param[in]  derivs Nonzero to write derivatives.
 * @param[out] out    Layout, C(nbasis+order, order) * arr->size reals.
 */
void oarrss_get_all_ims_to(const oarrss_t* arr, bases_t nbasis, ord_t order, int derivs,
                           coeff_t* out);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Largest global base used by a nonzero order-@p p coefficient of any element.
 *
 * @param[in] p   Order, p >= 1.
 * @param[in] arr Array.
 *
 * @return The base label, or 0 when every order-@p p block is zero.
 */
bases_t oarrss_order_max_base(ord_t p, const oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes the order-@p p blocks of an array side by side in global index order.
 *
 * @p out is a row-major nrows x (ncols * width) matrix: out[r, c + ncols * g] is the coefficient
 * of element (r, c) along the order-p direction with global index g (the layout of the sparse
 * get_order_im_array()). The function zeroes @p out first; directions with g >= @p width are
 * skipped. Order 0 writes the real block (width 1).
 *
 * @param[in]  p     Order.
 * @param[in]  arr   Array.
 * @param[in]  width Number of global directions in @p out.
 * @param[out] out   Matrix, nrows * ncols * width reals.
 */
void oarrss_get_order_im_array_to(ord_t p, const oarrss_t* arr, ndir_t width, coeff_t* out);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds order-@p p coefficients given side by side in global index order to an array.
 *
 * The inverse layout of oarrss_get_order_im_array_to(): element (r, c) gets
 * in[r, c + ncols * g] added along the global direction (g, p). The active set grows by the bases
 * of every direction with a nonzero value, and the truncation order is raised to @p p when lower
 * (the sparse set_order_im_from_array()). Order 0 adds to the real block.
 *
 * @param[in]     p     Order.
 * @param[in]     in    Row-major nrows x (ncols * width) matrix.
 * @param[in]     width Number of global directions in @p in.
 * @param[in,out] arr   Array (must own its buffers when it has to grow).
 */
void oarrss_add_order_im_array(ord_t p, const coeff_t* in, ndir_t width, oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FILTERS AND INTERPOLATION     -----------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Moving-average filter over the flattened array, as the sparse moving_average().
 *
 * With n = arr->size and the window [k - l, k + r) (l = size - size/2 - 1, r = size - l), output
 * element k is (1/size) times the window sum, where the window positions outside [0, n) repeat the
 * first or last element. The filter is linear with real weights, so it is applied to every
 * direction block alike. The result is an n x 1 column over the same active set.
 *
 * @param[in]     arr  Array (flattened column-major).
 * @param[in]     size Window size, >= 1.
 * @param[in,out] res  Result, n x 1; must not alias @p arr.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE when size is 0.
 */
int oarrss_moving_average_to(const oarrss_t* arr, uint64_t size, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Linear 1-D interpolation of an OTI scalar, as the sparse interp1d().
 *
 * xvals and yvals are columns (element (i, 0)); the real parts of xvals must be strictly
 * increasing. Below the first or above the last real abscissa the result is the first or last
 * ordinate; otherwise it is m (x - x_i) + y_i with m = (y_{i+1} - y_i) / (x_{i+1} - x_i), in OTI
 * arithmetic, on the interval that brackets x.re.
 *
 * @param[in]     xvals Abscissas, n x 1 (n >= 1).
 * @param[in]     yvals Ordinates, at least n rows.
 * @param[in]     x     Point.
 * @param[in,out] res   Result; may alias @p x.
 * @param[in]     dhl   Direction helper list.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE when xvals is empty or yvals has fewer rows.
 */
int oarrss_interp1d_o_to(const oarrss_t* xvals, const oarrss_t* yvals, const ssotinum_t* x,
                         ssotinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise linear 1-D interpolation of an array (oarrss_interp1d_o_to() per element).
 *
 * @param[in]     xvals Abscissas, n x 1.
 * @param[in]     yvals Ordinates, at least n rows.
 * @param[in]     X     Points.
 * @param[in,out] res   Result, same shape as @p X; must not alias @p X.
 * @param[in]     dhl   Direction helper list.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE as oarrss_interp1d_o_to().
 */
int oarrss_interp1d_O_to(const oarrss_t* xvals, const oarrss_t* yvals, const oarrss_t* X,
                         oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------

#endif
