#ifndef OTI_SEMISPARSE_SOA_ALGEBRA_H
#define OTI_SEMISPARSE_SOA_ALGEBRA_H

// Semi-sparse SoA arrays: elementwise algebra, functions, matrix products and kernels.
// Conventions in include/oti/semisparse/soa/base.h. Array operations only have `_to` variants: pass
// an oarrss_init() array as @p res to allocate. Operand kinds in the suffix: O = oarrss_t array,
// o = ssotinum_t scalar, r = real. Elementwise operations need equal shapes (a scalar or real
// operand is broadcast).


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     KERNELS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Elementwise block product accumulated over an order window, for an element range.
 *
 * Blocks are laid out as in oarrss_t over k bases at truncation order @p trc, each @p m reals
 * long; order 0 is block 0. For every p in [alo, ahi], q in [blo, bhi] with p + q <= trc and every
 * direction pair, accumulates A_i[e] * B_j[e] into the product block, for e in [e0, e1). Only
 * elements in that range are touched, so threads given disjoint ranges never write the same
 * memory.
 *
 * @param[in]     A   First operand blocks.
 * @param[in]     alo Lowest order of @p A to use (0 = real block).
 * @param[in]     ahi Highest order of @p A to use.
 * @param[in]     B   Second operand blocks.
 * @param[in]     blo Lowest order of @p B to use.
 * @param[in]     bhi Highest order of @p B to use.
 * @param[in]     k   Number of bases.
 * @param[in]     trc Truncation order of the layout.
 * @param[in]     m   Block length (array size).
 * @param[in]     e0  First element.
 * @param[in]     e1  One past the last element.
 * @param[in,out] R   Accumulator blocks. Must not alias @p A or @p B.
 * @param[in]     dhl Direction helper list.
 */
void oarrss_kernel_mul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                           ord_t bhi, bases_t k, ord_t trc, uint64_t m, uint64_t e0, uint64_t e1,
                           coeff_t* R, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Matrix block product accumulated over an order window.
 *
 * Blocks of @p A are nrows x ninner and blocks of @p B are ninner x ncols, column-major, laid out
 * as in oarrss_t over k bases at truncation order @p trc (order 0 = block 0). Accumulates
 * A_i x B_j into the product block of @p R (nrows x ncols) for every direction pair with p in
 * [alo, ahi], q in [blo, bhi], p + q <= trc. A_i x [all order-q blocks of B] is one oti_dgemm;
 * the result goes to @p work and is scatter-added.
 *
 * @param[in]     A      First operand blocks.
 * @param[in]     alo    Lowest order of @p A to use (0 = real block).
 * @param[in]     ahi    Highest order of @p A to use.
 * @param[in]     B      Second operand blocks.
 * @param[in]     blo    Lowest order of @p B to use.
 * @param[in]     bhi    Highest order of @p B to use.
 * @param[in]     k      Number of bases.
 * @param[in]     trc    Truncation order of the layout.
 * @param[in]     nrows  Rows of @p A and @p R.
 * @param[in]     ninner Columns of @p A, rows of @p B.
 * @param[in]     ncols  Columns of @p B and @p R.
 * @param[in]     alpha  Scale of the products.
 * @param[in,out] R      Accumulator blocks. Must not overlap the blocks of @p A or @p B that are
 *                       read (orders in the windows); oarrss_lu_solve() passes @p B == @p R with
 *                       disjoint order windows.
 * @param[out]    work   Scratch, nrows * ncols * max_q N_q(k) reals.
 * @param[in]     dhl    Direction helper list.
 *
 * @return 0, or OTI_LINALG_ERR_SIZE if a dimension does not fit the LAPACK integers.
 */
int oarrss_kernel_matmul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                             ord_t bhi, bases_t k, ord_t trc, uint64_t nrows, uint64_t ninner,
                             uint64_t ncols, coeff_t alpha, coeff_t* R, coeff_t* work,
                             dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ELEMENTWISE     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Elementwise arr1 + arr2.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     arr2 Second operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sum_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num + arr1.
 *
 * @param[in]     num  Scalar operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sum_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val + arr1.
 *
 * @param[in]     val  Real operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sum_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - arr2.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     arr2 Second operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sub_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num - arr1.
 *
 * @param[in]     num  Scalar operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sub_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val - arr1.
 *
 * @param[in]     val  Real operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sub_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - num.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     num  Scalar operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sub_Oo_to(const oarrss_t* arr1, const ssotinum_t* num, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - val.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     val  Real operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sub_Or_to(const oarrss_t* arr1, coeff_t val, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 * arr2.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     arr2 Second operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_mul_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num * arr1.
 *
 * @param[in]     num  Scalar operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_mul_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val * arr1.
 *
 * @param[in]     val  Real operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_mul_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / arr2.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     arr2 Second operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_div_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num / arr1.
 *
 * @param[in]     num  Scalar operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_div_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val / arr1.
 *
 * @param[in]     val  Real operand.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_div_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / num.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     num  Scalar operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_div_Oo_to(const oarrss_t* arr1, const ssotinum_t* num, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / val.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     val  Real operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_div_Or_to(const oarrss_t* arr1, coeff_t val, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise negation.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_neg_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FUNCTIONS     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Evaluates a function elementwise from per-element derivatives.
 *
 * Truncated Taylor series of every element about its real part, as ssoti_feval(). The
 * powers of the imaginary part are computed with oarrss_kernel_mul_acc() over all elements.
 * 
 * @param[in]     derivs Derivatives per element: derivs[i*size + e] = f^(i)(re_e), i = 0..trc.
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_feval_to(const coeff_t* derivs, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise exp.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_exp_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_log_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log10.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_log10_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sqrt.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sqrt_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cbrt.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_cbrt_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sin.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sin_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cos.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_cos_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tan.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_tan_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asin.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_asin_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acos.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_acos_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atan.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_atan_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sinh.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_sinh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cosh.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_cosh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tanh.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_tanh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asinh.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_asinh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acosh.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_acosh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atanh.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_atanh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise erf.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_erf_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise power with a real exponent.
 *
 * @param[in]     arr1 First operand.
 * @param[in]     e    Real exponent.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_pow_to(const oarrss_t* arr1, coeff_t e, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MATRIX PRODUCTS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Matrix product arr1 x arr2.
 *
 * @p arr1 is n x m and @p arr2 is m x p. Uses oarrss_kernel_matmul_acc() (BLAS dgemm).
 * 
 * @param[in]     arr1 First operand.
 * @param[in]     arr2 Second operand.
 * @param[in,out] res  Result, n x p; may alias an operand.
 * @param[in]     dhl  Direction helper list.
 * 
 * @return 0, OTI_LINALG_ERR_SIZE (dimensions do not match or do not fit the LAPACK integers).
 */
int oarrss_matmul_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Transpose.
 *
 * @param[in]     arr1 First operand.
 * @param[in,out] res  Result; may alias @p arr1.
 * @param[in]     dhl  Direction helper list.
 */
void oarrss_transpose_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
