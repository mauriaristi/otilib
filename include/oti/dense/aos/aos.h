#ifndef OTI_DENSE_AOS_H
#define OTI_DENSE_AOS_H

// Dense AoS arrays (arro_t): every element is an otinum_t with its own nact and orders, like
// arrso_t. Elements are row-major (element (i, j) at p_data[j + i*ncols]). Elementwise operations
// run the scalar kernels over the elements with OpenMP (per-thread workspaces, oti_ws()); linear
// algebra goes through the SoA layout (arro_to_oarr()). Conventions in
// include/oti/dense/scalar/base.h; `_to` variants: @p res may alias any input, and a scalar operand
// @p num may be an element of @p res or @p arr1 (it is copied first). Shape mismatches return
// DN_ERR_SIZE.

/**
 * @brief Dense OTI array, array of structures.
 *
 * There is no ownership flag: the array owns its elements and arro_free() releases them all.
 */
typedef struct {
    otinum_t* p_data; ///< Elements, row-major.
    uint64_t   nrows; ///< Number of rows.
    uint64_t   ncols; ///< Number of columns.
    uint64_t    size; ///< nrows * ncols.
} arro_t;             ///< Dense AoS OTI array type.

// -------------------------------------------------------------------------------------------------------


/**
 * @brief Empty 0 x 0 array.
 *
 * @return Array with no elements. arro_free() on it is a no-op.
 */
arro_t arro_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Makes an array an nrows x ncols array of real zeros (nact = 0).
 *
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order of every element.
 * @param[in,out] res       Array.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_zeros_to(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Gives an array a new shape, keeping the first min(size, new size) elements.
 *
 * Elements are stored row-major like arrso_t: element (i, j) is p_data[j + i*ncols].
 *
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order of added elements (real zeros).
 * @param[in,out] arr       Array.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases every element and the array, and resets it to arro_init().
 *
 * @param[in,out] arr Array. Safe on arro_init() and on an array left by a failed call.
 */
void arro_free(arro_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Copies an array into an existing one.
 *
 * @param[in]     arr1 Array to copy.
 * @param[in,out] res  Destination; may alias @p arr1 (no-op).
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_copy_to(const arro_t* arr1, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Element (i, j), by pointer.
 *
 * @param[in] i    Row.
 * @param[in] j    Column.
 * @param[in] arr1 Array.
 *
 * @return Pointer to the element inside the array (not a copy), or NULL when (i, j) is out of
 *         range. Valid until the array is resized or freed.
 */
const otinum_t* arro_get_item_ptr(uint64_t i, uint64_t j, const arro_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a copy of a scalar.
 *
 * @param[in]     num  Scalar.
 * @param[in]     i    Row.
 * @param[in]     j    Column.
 * @param[in,out] arr1 Array.
 *
 * @return DN_OK, DN_ERR_INDEX or DN_ERR_MEMORY.
 */
int arro_set_item(const otinum_t* num, uint64_t i, uint64_t j, arro_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a real value (keeping the element's truncation order).
 *
 * @param[in]     val  Real value.
 * @param[in]     i    Row.
 * @param[in]     j    Column.
 * @param[in,out] arr1 Array.
 *
 * @return DN_OK, or DN_ERR_INDEX.
 */
int arro_set_item_r(coeff_t val, uint64_t i, uint64_t j, arro_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a sparse array, element by element (every element gets its own nact).
 *
 * @param[in]     arr1 Sparse array.
 * @param[in,out] res  Dense AoS array.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, DN_ERR_INDEX or DN_ERR_MEMORY.
 */
int arro_from_arrso_to(const arrso_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts to a sparse array (element by element).
 *
 * @param[in] arr1 Array.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated sparse array. Caller must free via arrso_free(). The sparse
 *         constructors exit on an allocation failure, as everywhere in the sparse module.
 */
arrso_t arro_to_arrso(const arro_t* arr1, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts to a SoA array.
 *
 * nact is the largest element nact and the truncation order the largest element truncation order;
 * every element is zero-extended into that layout (column-major blocks).
 *
 * @param[in]     arr1 AoS array.
 * @param[in,out] res  SoA array; grown as needed.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_to_oarr(const arro_t* arr1, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a SoA array; every element gets the SoA nact and orders.
 *
 * @param[in]     arr1 SoA array.
 * @param[in,out] res  AoS array; resized as needed.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_from_oarr(const oarr_t* arr1, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 + arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sum_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num + arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sum_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val + arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sum_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num - arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val - arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - num.
 *
 * @param[in]     arr1 First array.
 * @param[in]     num  Scalar.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - val.
 *
 * @param[in]     arr1 First array.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 * arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_mul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num * arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_mul_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val * arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_mul_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num / arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val / arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / num.
 *
 * @param[in]     arr1 First array.
 * @param[in]     num  Scalar.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / val.
 *
 * @param[in]     arr1 First array.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise negation.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_neg_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise exp.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_exp_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_log_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log10.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_log10_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sqrt.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sqrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cbrt.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_cbrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sin.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cos.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_cos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tan.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_tan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asin.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_asin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acos.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_acos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atan.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_atan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sinh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cosh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_cosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tanh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_tanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asinh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_asinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acosh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_acosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atanh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_atanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise erf.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_erf_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise power with a real exponent.
 *
 * @param[in]     arr1 First array.
 * @param[in]     ex   Exponent.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_pow_to(const arro_t* arr1, coeff_t ex, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_truncate_im().
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_truncate_im_to(imdir_t idx, ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_truncate_order().
 *
 * @param[in]     order First order removed.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_truncate_order_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_get_order_im().
 *
 * @param[in]     order Order kept.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_get_order_im_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_compact().
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_compact_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Matrix product arr1 x arr2.
 *
 * Each output element accumulates products (nact and trc: the max over the operands).
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result, n x p; may alias an operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_matmul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Transpose.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias @p arr1.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_transpose_to(const arro_t* arr1, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Solves K X = B.
 *
 * Converts to SoA (arro_to_oarr()), solves with oarr_solve_to(), and converts back: every element
 * of the solution has the SoA nact and orders.
 *
 * @param[in]     K   Square matrix.
 * @param[in]     b   Right-hand sides.
 * @param[in,out] x   Solution; may alias an input.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/dense/soa/linalg.h).
 */
int arro_solve_to(const arro_t* K, const arro_t* b, arro_t* x, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Inverse of a square matrix.
 *
 * Through the SoA layout, like arro_solve_to().
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Inverse; may alias @p A.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/dense/soa/linalg.h).
 */
int arro_inv_to(const arro_t* A, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Determinant of a square matrix.
 *
 * Through the SoA layout, like arro_solve_to().
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Determinant.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/dense/soa/linalg.h).
 */
int arro_det_to(const arro_t* A, otinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
