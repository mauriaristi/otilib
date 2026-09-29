#ifndef OTI_SEMISPARSE_SCALAR_ALGEBRA_H
#define OTI_SEMISPARSE_SCALAR_ALGEBRA_H

// Semi-sparse scalar algebra. Conventions in include/oti/semisparse/scalar/base.h.
//
// The result of an operation between two numbers has the union of their active sets and the
// larger of their truncation orders (as sotinum_t). Operands with different sets or a lower
// truncation order are zero-extended (one is a leading part of the union) or remapped into the
// union, then the same-set kernel runs.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ADDITION     ----------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Semi-sparse addition variants
 * @{
 */

/**
 * @brief Adds two numbers (allocating variant).
 *
 * @param[in] num1 First operand.
 * @param[in] num2 Second operand.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sum_oo(const ssotinum_t* num1, const ssotinum_t* num2, dhelpl_t dhl);

/**
 * @brief Adds a real to a number (allocating variant).
 *
 * @param[in] num1 Number.
 * @param[in] val  Real value.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sum_or(const ssotinum_t* num1, coeff_t val, dhelpl_t dhl);

/**
 * @brief Adds two numbers into an existing one.
 *
 * @param[in]     num1 First operand.
 * @param[in]     num2 Second operand.
 * @param[in,out] res  Result; may alias either operand.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_sum_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, ssotinum_t* res,
                     dhelpl_t dhl);

/**
 * @brief Adds a real to a number into an existing one.
 *
 * @param[in]     num1 Number.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_sum_or_to(const ssotinum_t* num1, coeff_t val, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse subtraction variants
 * @{
 */

/**
 * @brief Subtracts two numbers, num1 - num2 (allocating variant).
 *
 * @param[in] num1 First operand.
 * @param[in] num2 Second operand.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sub_oo(const ssotinum_t* num1, const ssotinum_t* num2, dhelpl_t dhl);

/**
 * @brief Subtracts a real from a number, num1 - val (allocating variant).
 *
 * @param[in] num1 Number.
 * @param[in] val  Real value.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sub_or(const ssotinum_t* num1, coeff_t val, dhelpl_t dhl);

/**
 * @brief Subtracts a number from a real, val - num1 (allocating variant).
 *
 * @param[in] val  Real value.
 * @param[in] num1 Number.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sub_ro(coeff_t val, const ssotinum_t* num1, dhelpl_t dhl);

/**
 * @brief Subtracts two numbers into an existing one.
 *
 * @param[in]     num1 First operand.
 * @param[in]     num2 Second operand.
 * @param[in,out] res  Result; may alias either operand.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_sub_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, ssotinum_t* res,
                     dhelpl_t dhl);

/**
 * @brief Subtracts a real from a number into an existing one.
 *
 * @param[in]     num1 Number.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_sub_or_to(const ssotinum_t* num1, coeff_t val, ssotinum_t* res, dhelpl_t dhl);

/**
 * @brief Subtracts a number from a real into an existing one.
 *
 * @param[in]     val  Real value.
 * @param[in]     num1 Number.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_sub_ro_to(coeff_t val, const ssotinum_t* num1, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse negation
 * @{
 */

/**
 * @brief Negates a number (allocating variant).
 *
 * @param[in] num Number.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_neg(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Negates a number into an existing one.
 *
 * @param[in]     num Number.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_neg_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MULTIPLICATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Semi-sparse multiplication variants
 * @{
 */

/**
 * @brief Multiplies two numbers (allocating variant).
 *
 * @param[in] num1 First operand.
 * @param[in] num2 Second operand.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_mul_oo(const ssotinum_t* num1, const ssotinum_t* num2, dhelpl_t dhl);

/**
 * @brief Multiplies a number by a real (allocating variant).
 *
 * @param[in] num1 Number.
 * @param[in] val  Real value.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_mul_or(const ssotinum_t* num1, coeff_t val, dhelpl_t dhl);

/**
 * @brief Multiplies two numbers into an existing one.
 *
 * @param[in]     num1 First operand.
 * @param[in]     num2 Second operand.
 * @param[in,out] res  Result; may alias either operand.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_mul_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, ssotinum_t* res,
                     dhelpl_t dhl);

/**
 * @brief Multiplies a number by a real into an existing one.
 *
 * @param[in]     num1 Number.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias @p num1.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_mul_or_to(const ssotinum_t* num1, coeff_t val, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse fused multiply-add
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
 */
void ssoti_gem_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, const ssotinum_t* num3,
                     ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     DIVISION     ----------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Semi-sparse division variants
 * num / den is num * den^-1, with den^-1 from ssoti_pow().
 * @{
 */

/**
 * @brief Divides two numbers (allocating variant).
 *
 * @param[in] num Numerator.
 * @param[in] den Denominator.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_div_oo(const ssotinum_t* num, const ssotinum_t* den, dhelpl_t dhl);

/**
 * @brief Divides a real by a number (allocating variant).
 *
 * @param[in] val Numerator.
 * @param[in] den Denominator.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_div_ro(coeff_t val, const ssotinum_t* den, dhelpl_t dhl);

/**
 * @brief Divides a number by a real (allocating variant).
 *
 * @param[in] num Numerator.
 * @param[in] val Denominator.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_div_or(const ssotinum_t* num, coeff_t val, dhelpl_t dhl);

/**
 * @brief Divides two numbers into an existing one.
 *
 * @param[in]     num Numerator.
 * @param[in]     den Denominator.
 * @param[in,out] res Result; may alias either operand.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_div_oo_to(const ssotinum_t* num, const ssotinum_t* den, ssotinum_t* res,
                     dhelpl_t dhl);

/**
 * @brief Divides a real by a number into an existing one.
 *
 * @param[in]     val Numerator.
 * @param[in]     den Denominator.
 * @param[in,out] res Result; may alias @p den.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_div_ro_to(coeff_t val, const ssotinum_t* den, ssotinum_t* res, dhelpl_t dhl);

/**
 * @brief Divides a number by a real into an existing one.
 *
 * @param[in]     num Numerator.
 * @param[in]     val Denominator.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_div_or_to(const ssotinum_t* num, coeff_t val, ssotinum_t* res, dhelpl_t dhl);

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
 * layout of ssotinum_t over the same k bases at truncation order @p trc. Used by ssoti_mul_oo(),
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
void ssoti_kernel_mul_acc(const coeff_t* a_im, ord_t alo, ord_t ahi,
                          const coeff_t* b_im, ord_t blo, ord_t bhi,
                          bases_t k, ord_t trc, coeff_t* res_im, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes the coefficients of a number in the layout of a larger active set.
 *
 * The target set must contain the number's set; @p pos is the position of each of the number's
 * bases in it (from sshelp_union_bases()). Orders 1..trc are written; orders above the number's
 * truncation order, and directions it does not have, are zero.
 *
 * @param[in]  num    Number.
 * @param[in]  pos    Target position of each base of @p num, length num->nbases.
 * @param[in]  ku     Number of bases of the target set.
 * @param[in]  trc    Truncation order of the target layout.
 * @param[out] dst_im Target buffer, sshelp_ndir_total(ku, trc) coefficients. Must not alias
 *                    num->p_im.
 */
void ssoti_kernel_expand(const ssotinum_t* num, const bases_t* pos, bases_t ku, ord_t trc,
                         coeff_t* dst_im);
// -------------------------------------------------------------------------------------------------------

#endif
