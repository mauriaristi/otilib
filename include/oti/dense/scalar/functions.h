#ifndef OTI_DENSE_SCALAR_FUNCTIONS_H
#define OTI_DENSE_SCALAR_FUNCTIONS_H

// Dense scalar functions. Conventions in include/oti/dense/scalar/base.h.
//
// Every function is a truncated Taylor series in the imaginary part d = num - num.re,
// f(num) = sum_i f^(i)(re) / i! * d^i (same algorithm as soti_feval()). All powers of d share
// the input's layout (nact, trc), so only the same-layout kernel runs. The result has the input's
// nact and trc, and act_order = trc (0 for a real input).


/**
 * @name Dense Taylor series evaluation
 * @{
 */

/**
 * @brief Evaluates a function from its derivatives at the real part (allocating variant).
 *
 * @param[in] derivs Derivatives f(re), f'(re), ..., f^(trc)(re); num->trc_order + 1 values.
 * @param[in] num    Argument.
 * @param[in] dhl    Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_feval(const coeff_t* derivs, const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Evaluates a function from its derivatives into an existing number.
 *
 * @param[in]     derivs Derivatives f(re), ..., f^(trc)(re); num->trc_order + 1 values.
 * @param[in]     num    Argument.
 * @param[in,out] res    Result; may alias @p num.
 * @param[in]     dhl    Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_feval_to(const coeff_t* derivs, const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense exponential
 * @{
 */

/**
 * @brief Exponential of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_exp(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Exponential of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_exp_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense natural logarithm
 * @{
 */

/**
 * @brief Natural logarithm of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_log(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Natural logarithm of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_log_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense base-10 logarithm
 * @{
 */

/**
 * @brief Base-10 logarithm of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_log10(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Base-10 logarithm of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_log10_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense square root
 * @{
 */

/**
 * @brief Square root of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sqrt(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Square root of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sqrt_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense cube root
 * @{
 */

/**
 * @brief Cube root of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_cbrt(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Cube root of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_cbrt_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense sine
 * @{
 */

/**
 * @brief Sine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sin(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Sine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sin_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense cosine
 * @{
 */

/**
 * @brief Cosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_cos(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Cosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_cos_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense tangent
 * @{
 */

/**
 * @brief Tangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_tan(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Tangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_tan_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense arcsine
 * @{
 */

/**
 * @brief Arcsine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_asin(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Arcsine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_asin_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense arccosine
 * @{
 */

/**
 * @brief Arccosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_acos(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Arccosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_acos_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense arctangent
 * @{
 */

/**
 * @brief Arctangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_atan(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Arctangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_atan_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense hyperbolic sine
 * @{
 */

/**
 * @brief Hyperbolic sine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_sinh(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Hyperbolic sine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_sinh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense hyperbolic cosine
 * @{
 */

/**
 * @brief Hyperbolic cosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_cosh(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Hyperbolic cosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_cosh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense hyperbolic tangent
 * @{
 */

/**
 * @brief Hyperbolic tangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_tanh(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Hyperbolic tangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_tanh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense inverse hyperbolic sine
 * @{
 */

/**
 * @brief Inverse hyperbolic sine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_asinh(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Inverse hyperbolic sine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_asinh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense inverse hyperbolic cosine
 * @{
 */

/**
 * @brief Inverse hyperbolic cosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_acosh(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Inverse hyperbolic cosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_acosh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense inverse hyperbolic tangent
 * @{
 */

/**
 * @brief Inverse hyperbolic tangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_atanh(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Inverse hyperbolic tangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_atanh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense error function
 * @{
 */

/**
 * @brief Error function of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_erf(const otinum_t* num, dhelpl_t dhl);

/**
 * @brief Error function of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_erf_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense power
 * @{
 */

/**
 * @brief Power of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] e   Real exponent.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_pow(const otinum_t* num,coeff_t e, dhelpl_t dhl);

/**
 * @brief Power of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in]     e   Real exponent.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_pow_to(const otinum_t* num,coeff_t e, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense logarithm in a given base
 * @{
 */

/**
 * @brief Logarithm in a given base of a number (allocating variant).
 *
 * @param[in] num  Argument.
 * @param[in] base Logarithm base.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_logb(const otinum_t* num,coeff_t base, dhelpl_t dhl);

/**
 * @brief Logarithm in a given base of a number into an existing one.
 *
 * @param[in]     num  Argument.
 * @param[in]     base Logarithm base.
 * @param[in,out] res  Result; may alias @p num.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_logb_to(const otinum_t* num,coeff_t base, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


#endif
