#ifndef OTI_DENSE_SCALAR_ALGEBRA_H
#define OTI_DENSE_SCALAR_ALGEBRA_H

// Dense scalar algebra. Conventions in include/oti/dense/scalar/base.h.
//
// The result of an operation between two numbers has nact = max(nact_1, nact_2) and the larger of
// their truncation orders (as sotinum_t). An operand with a smaller nact or a lower truncation order
// is a prefix of that layout. The public kernels below take one layout (one k): callers either
// zero-extend such an operand with oti_kernel_expand() into a call-local buffer, or use private
// kernels that take one nact per operand and read it in place at its own offsets. act_order rules
// are listed in include/oti/dense/scalar/base.h.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ADDITION     ----------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense addition variants
 * @{
 */

/**
 * @brief Adds two numbers (allocating variant).
 *
 * @param[in] num1 First operand.
 * @param[in] num2 Second operand.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sum_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl);

/**
 * @brief Adds a real to a number (allocating variant).
 *
 * @param[in] num1 Number.
 * @param[in] val  Real value.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sum_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl);

/**
 * @brief Adds two numbers into an existing one.
 *
 * @param[in]     num1 First operand.
 * @param[in]     num2 Second operand.
 * @param[in,out] res  Result; may alias either operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sum_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res,
                  dhelpl_t dhl);

/**
 * @brief Adds a real to a number into an existing one.
 *
 * @param[in]     num1 Number.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sum_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense subtraction variants
 * @{
 */

/**
 * @brief Subtracts two numbers, num1 - num2 (allocating variant).
 *
 * @param[in] num1 First operand.
 * @param[in] num2 Second operand.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sub_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl);

/**
 * @brief Subtracts a real from a number, num1 - val (allocating variant).
 *
 * @param[in] num1 Number.
 * @param[in] val  Real value.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sub_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl);

/**
 * @brief Subtracts a number from a real, val - num1 (allocating variant).
 *
 * @param[in] val  Real value.
 * @param[in] num1 Number.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sub_ro(coeff_t val, const otinum_t* num1, dhelpl_t dhl);

/**
 * @brief Subtracts two numbers into an existing one.
 *
 * @param[in]     num1 First operand.
 * @param[in]     num2 Second operand.
 * @param[in,out] res  Result; may alias either operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sub_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res,
                  dhelpl_t dhl);

/**
 * @brief Subtracts a real from a number into an existing one.
 *
 * @param[in]     num1 Number.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sub_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl);

/**
 * @brief Subtracts a number from a real into an existing one.
 *
 * @param[in]     val  Real value.
 * @param[in]     num1 Number.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sub_ro_to(coeff_t val, const otinum_t* num1, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense negation
 * @{
 */

/**
 * @brief Negates a number (allocating variant).
 *
 * @param[in] num Number.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_neg(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Negates a number into an existing one.
 *
 * @param[in]     num Number.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_neg_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MULTIPLICATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense multiplication variants
 * @{
 */

/**
 * @brief Multiplies two numbers (allocating variant).
 *
 * @param[in] num1 First operand.
 * @param[in] num2 Second operand.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_mul_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl);

/**
 * @brief Multiplies a number by a real (allocating variant).
 *
 * @param[in] num1 Number.
 * @param[in] val  Real value.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_mul_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl);

/**
 * @brief Multiplies two numbers into an existing one.
 *
 * @param[in]     num1 First operand.
 * @param[in]     num2 Second operand.
 * @param[in,out] res  Result; may alias either operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_mul_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res,
                  dhelpl_t dhl);

/**
 * @brief Multiplies a number by a real into an existing one.
 *
 * @param[in]     num1 Number.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_mul_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense fused multiply-add
 * @{
 */

/**
 * @brief Computes res = num1 * num2 + num3.
 *
 * @param[in]     num1 First factor.
 * @param[in]     num2 Second factor.
 * @param[in]     num3 Addend.
 * @param[in,out] res  Result; may alias any input.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_gem_oo_to(const otinum_t* num1, const otinum_t* num2, const otinum_t* num3,
                  otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     DIVISION     ----------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense division variants
 * num / den is num * den^-1, with den^-1 from oti_pow().
 * @{
 */

/**
 * @brief Divides two numbers (allocating variant).
 *
 * @param[in] num Numerator.
 * @param[in] den Denominator.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_div_oo(const otinum_t* num, const otinum_t* den, dhelpl_t dhl);

/**
 * @brief Divides a real by a number (allocating variant).
 *
 * @param[in] val Numerator.
 * @param[in] den Denominator.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_div_ro(coeff_t val, const otinum_t* den, dhelpl_t dhl);

/**
 * @brief Divides a number by a real (allocating variant).
 *
 * @param[in] num Numerator.
 * @param[in] val Denominator.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_div_or(const otinum_t* num, coeff_t val, dhelpl_t dhl);

/**
 * @brief Divides two numbers into an existing one.
 *
 * @param[in]     num Numerator.
 * @param[in]     den Denominator.
 * @param[in,out] res Result; may alias either operand.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_div_oo_to(const otinum_t* num, const otinum_t* den, otinum_t* res,
                  dhelpl_t dhl);

/**
 * @brief Divides a real by a number into an existing one.
 *
 * @param[in]     val Numerator.
 * @param[in]     den Denominator.
 * @param[in,out] res Result; may alias @p den.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_div_ro_to(coeff_t val, const otinum_t* den, otinum_t* res, dhelpl_t dhl);

/**
 * @brief Divides a number by a real into an existing one.
 *
 * @param[in]     num Numerator.
 * @param[in]     val Denominator.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_div_or_to(const otinum_t* num, coeff_t val, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     RAW KERNELS     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Same-set dense product of coefficient buffers, restricted to an order window.
 *
 * Accumulates into @p res_im every product a_p * b_q with p in [alo, ahi], q in [blo, bhi],
 * p + q <= trc (imaginary x imaginary only; real parts are the caller's). All buffers use the
 * layout of otinum_t over the same k bases at truncation order @p trc. Used by oti_mul_oo(),
 * the feval series and the array kernels.
 *
 * @param[in]     a_im   First operand, orders 1..trc.
 * @param[in]     alo    Lowest order of @p a_im to use (>= 1).
 * @param[in]     ahi    Highest order of @p a_im to use.
 * @param[in]     b_im   Second operand, orders 1..trc.
 * @param[in]     blo    Lowest order of @p b_im to use (>= 1).
 * @param[in]     bhi    Highest order of @p b_im to use.
 * @param[in]     k      Number of bases.
 * @param[in]     trc    Truncation order of the buffers.
 * @param[in,out] res_im Accumulator, orders 1..trc. Must not alias @p a_im or @p b_im.
 * @param[in]     dhl    Direction helper list.
 */
void oti_kernel_mul_acc(const coeff_t* a_im, ord_t alo, ord_t ahi,
                        const coeff_t* b_im, ord_t blo, ord_t bhi,
                        bases_t k, ord_t trc, coeff_t* res_im, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes the coefficients of a number in the layout of a larger (nact, trc).
 *
 * Zero-extension: the number's order-p block (over num->nact bases) is copied to the start of the
 * target's order-p block (over @p ku bases), the rest of the target is zero. Orders 1..trc are
 * written; orders above the number's truncation order are zero.
 *
 * @param[in]  num    Number, with num->nact <= @p ku.
 * @param[in]  ku     Number of bases of the target layout.
 * @param[in]  trc    Truncation order of the target layout.
 * @param[out] dst_im Target buffer, sshelp_ndir_total(ku, trc) coefficients. Must not alias
 *                    num->p_im.
 */
void oti_kernel_expand(const otinum_t* num, bases_t ku, ord_t trc, coeff_t* dst_im);
// -------------------------------------------------------------------------------------------------------

#endif
