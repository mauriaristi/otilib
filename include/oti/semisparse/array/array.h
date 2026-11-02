#ifndef OTI_SEMISPARSE_ARRAY_H
#define OTI_SEMISPARSE_ARRAY_H

// Semi-sparse AoS arrays (arrss_t): every element is an ssotinum_t with its own active set, like
// arrso_t. Elements are row-major (element (i, j) at p_data[j + i*ncols]). Elementwise operations
// run the scalar kernels over the elements with OpenMP (per-thread workspaces, ssoti_ws()); linear
// algebra goes through the SoA layout. `_to` variants: @p res may alias any input.

/**
 * @brief Semi-sparse OTI array, array of structures.
 */
typedef struct {
    ssotinum_t* p_data; ///< Elements, row-major.
    uint64_t     nrows; ///< Number of rows.
    uint64_t     ncols; ///< Number of columns.
    uint64_t      size; ///< nrows * ncols.
    flag_t        flag; ///< Memory flag: 1 if the array owns its elements.
} arrss_t;            ///< Semi-sparse AoS OTI array type.

// -------------------------------------------------------------------------------------------------------


/**
 * @brief Empty 0 x 0 array.
 *
 *
 * @return Array with no elements. arrss_free() on it is a no-op.
 */
arrss_t arrss_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates an array of real zeros (no active bases).
 *
 * @param[in] nrows     Number of rows.
 * @param[in] ncols     Number of columns.
 * @param[in] trc_order Truncation order of every element.
 *
 * @return Newly allocated array. Caller must free via arrss_free().
 */
arrss_t arrss_zeros(uint64_t nrows, uint64_t ncols, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Gives an array a new shape, keeping the first min(size, new size) elements.
 *
 * Elements are stored row-major like arrso_t: element (i, j) is p_data[j + i*ncols].
 *
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order of added elements (real zeros).
 * @param[in,out] arr       Array (must own its memory).
 */
void arrss_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases every element and the array, and resets it to arrss_init().
 *
 * @param[in,out] arr Array.
 */
void arrss_free(arrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse AoS copy
 * @{
 */

/**
 * @brief Copies an array into an existing one.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Destination.
 */
void arrss_copy_to(const arrss_t* arr1, arrss_t* res);

/**
 * @brief Copies an array.
 *
 * @param[in] arr1 First array.
 *
 * @return Newly allocated copy. Caller must free via arrss_free().
 */
arrss_t arrss_copy(const arrss_t* arr1);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Element (i, j), by pointer.
 *
 * @param[in] i    Row.
 * @param[in] j    Column.
 * @param[in] arr1 First array.
 *
 * @return Pointer to the element inside the array (not a copy).
 */
const ssotinum_t* arrss_get_item_ptr(uint64_t i, uint64_t j, const arrss_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a copy of a scalar.
 *
 * @param[in]     num  Scalar.
 * @param[in]     i    Row.
 * @param[in]     j    Column.
 * @param[in,out] arr1 Array.
 */
void arrss_set_item(const ssotinum_t* num, uint64_t i, uint64_t j, arrss_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a real value.
 *
 * @param[in]     val  Real value.
 * @param[in]     i    Row.
 * @param[in]     j    Column.
 * @param[in,out] arr1 Array.
 */
void arrss_set_item_r(coeff_t val, uint64_t i, uint64_t j, arrss_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a sparse array (element by element).
 *
 * @param[in] arr1 Sparse array.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated array; every element keeps its own set. Caller must free via
 *         arrss_free().
 */
arrss_t arrss_from_arrso(const arrso_t* arr1, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts to a sparse array (element by element).
 *
 * @param[in]     arr1 First array.
 * @param[in]     dhl  Direction helper list.
 *
 * @return Newly allocated sparse array. Caller must free via arrso_free().
 */
arrso_t arrss_to_arrso(const arrss_t* arr1, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts to a SoA array over the union of the element sets.
 *
 * Every element is expanded into the union (oarrss_t layout, column-major blocks). The
 * truncation order is the largest element truncation order.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  SoA array; grown as needed.
 */
void arrss_to_oarrss(const arrss_t* arr1, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a SoA array; every element gets the SoA active set.
 *
 * @param[in]     arr1 SoA array.
 * @param[in,out] res  AoS array; resized as needed.
 */
void arrss_from_oarrss(const oarrss_t* arr1, arrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 + arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sum_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num + arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sum_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val + arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sum_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sub_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num - arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sub_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val - arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sub_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - num.
 *
 * @param[in]     arr1 First array.
 * @param[in]     num  Scalar.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sub_Oo_to(const arrss_t* arr1, const ssotinum_t* num, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - val.
 *
 * @param[in]     arr1 First array.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sub_Or_to(const arrss_t* arr1, coeff_t val, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 * arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_mul_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num * arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_mul_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val * arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_mul_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_div_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num / arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_div_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val / arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_div_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / num.
 *
 * @param[in]     arr1 First array.
 * @param[in]     num  Scalar.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_div_Oo_to(const arrss_t* arr1, const ssotinum_t* num, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / val.
 *
 * @param[in]     arr1 First array.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_div_Or_to(const arrss_t* arr1, coeff_t val, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise negation.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_neg_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise exp.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_exp_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_log_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log10.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_log10_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sqrt.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sqrt_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cbrt.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_cbrt_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sin.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sin_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cos.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_cos_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tan.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_tan_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asin.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_asin_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acos.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_acos_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atan.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_atan_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sinh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_sinh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cosh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_cosh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tanh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_tanh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asinh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_asinh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acosh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_acosh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atanh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_atanh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise erf.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_erf_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise power with a real exponent.
 *
 * @param[in]     arr1 First array.
 * @param[in]     ex   Exponent.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_pow_to(const arrss_t* arr1, coeff_t ex, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise ssoti_truncate_im().
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_truncate_im_to(imdir_t idx, ord_t order, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise ssoti_truncate_order().
 *
 * @param[in]     order First order removed.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_truncate_order_to(ord_t order, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise ssoti_get_order_im().
 *
 * @param[in]     order Order kept.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_get_order_im_to(ord_t order, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise ssoti_compact().
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_compact_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Matrix product arr1 x arr2.
 *
 * Each output element accumulates products, merging the element sets.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result, n x p; may alias an operand.
 * @param[in]     dhl  Direction helper list.
 */
void arrss_matmul_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Transpose.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias @p arr1.
 */
void arrss_transpose_to(const arrss_t* arr1, arrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Solves K X = B.
 *
 * Converts to SoA over the union of the element sets, solves with oarrss_solve_to(), and
 * converts back: every element of the solution has the union set.
 *
 * @param[in]     K   Square matrix.
 * @param[in]     b   Right-hand sides.
 * @param[in,out] x   Solution; may alias an input.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/semisparse/soa/linalg.h).
 */
int arrss_solve_to(const arrss_t* K, const arrss_t* b, arrss_t* x, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Inverse of a square matrix.
 *
 * Through the SoA layout, like arrss_solve_to().
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Inverse; may alias @p A.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/semisparse/soa/linalg.h).
 */
int arrss_inv_to(const arrss_t* A, arrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Determinant of a square matrix.
 *
 * Through the SoA layout, like arrss_solve_to().
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Determinant.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/semisparse/soa/linalg.h).
 */
int arrss_det_to(const arrss_t* A, ssotinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
