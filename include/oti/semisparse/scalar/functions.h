#ifndef OTI_SEMISPARSE_SCALAR_FUNCTIONS_H
#define OTI_SEMISPARSE_SCALAR_FUNCTIONS_H

// Semi-sparse scalar functions. Conventions in include/oti/semisparse/scalar/base.h.
//
// Every function is a truncated Taylor series in the imaginary part d = num - num.re,
// f(num) = sum_i f^(i)(re) / i! * d^i (same algorithm as soti_feval()). All powers of d share
// the input's active set, so only the same-set kernel runs.


/**
 * @name Semi-sparse Taylor series evaluation
 * @{
 */

/**
 * @brief Evaluates a function from its derivatives at the real part (allocating variant).
 *
 * @param[in] derivs Derivatives f(re), f'(re), ..., f^(trc)(re); num->trc_order + 1 values.
 * @param[in] num    Argument.
 * @param[in] dhl    Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_feval(const coeff_t* derivs, const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Evaluates a function from its derivatives into an existing number.
 *
 * @param[in]     derivs Derivatives f(re), ..., f^(trc)(re); num->trc_order + 1 values.
 * @param[in]     num    Argument.
 * @param[in,out] res    Result; may alias @p num.
 * @param[in]     dhl    Direction helper list.
 */
void ssoti_feval_to(const coeff_t* derivs, const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse exponential
 * @{
 */

/**
 * @brief Exponential of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_exp(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Exponential of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_exp_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse natural logarithm
 * @{
 */

/**
 * @brief Natural logarithm of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_log(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Natural logarithm of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_log_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse base-10 logarithm
 * @{
 */

/**
 * @brief Base-10 logarithm of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_log10(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Base-10 logarithm of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_log10_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse square root
 * @{
 */

/**
 * @brief Square root of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sqrt(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Square root of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_sqrt_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse cube root
 * @{
 */

/**
 * @brief Cube root of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_cbrt(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Cube root of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_cbrt_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse sine
 * @{
 */

/**
 * @brief Sine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sin(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Sine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_sin_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse cosine
 * @{
 */

/**
 * @brief Cosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_cos(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Cosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_cos_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse tangent
 * @{
 */

/**
 * @brief Tangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_tan(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Tangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_tan_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse arcsine
 * @{
 */

/**
 * @brief Arcsine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_asin(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Arcsine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_asin_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse arccosine
 * @{
 */

/**
 * @brief Arccosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_acos(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Arccosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_acos_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse arctangent
 * @{
 */

/**
 * @brief Arctangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_atan(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Arctangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_atan_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse hyperbolic sine
 * @{
 */

/**
 * @brief Hyperbolic sine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_sinh(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Hyperbolic sine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_sinh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse hyperbolic cosine
 * @{
 */

/**
 * @brief Hyperbolic cosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_cosh(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Hyperbolic cosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_cosh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse hyperbolic tangent
 * @{
 */

/**
 * @brief Hyperbolic tangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_tanh(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Hyperbolic tangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_tanh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse inverse hyperbolic sine
 * @{
 */

/**
 * @brief Inverse hyperbolic sine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_asinh(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Inverse hyperbolic sine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_asinh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse inverse hyperbolic cosine
 * @{
 */

/**
 * @brief Inverse hyperbolic cosine of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_acosh(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Inverse hyperbolic cosine of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_acosh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse inverse hyperbolic tangent
 * @{
 */

/**
 * @brief Inverse hyperbolic tangent of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_atanh(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Inverse hyperbolic tangent of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_atanh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse error function
 * @{
 */

/**
 * @brief Error function of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_erf(const ssotinum_t* num, dhelpl_t dhl);

/**
 * @brief Error function of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_erf_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse power
 * @{
 */

/**
 * @brief Power of a number (allocating variant).
 *
 * @param[in] num Argument.
 * @param[in] e   Real exponent.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_pow(const ssotinum_t* num,coeff_t e, dhelpl_t dhl);

/**
 * @brief Power of a number into an existing one.
 *
 * @param[in]     num Argument.
 * @param[in]     e   Real exponent.
 * @param[in,out] res Result; may alias @p num.
 * @param[in]     dhl Direction helper list.
 */
void ssoti_pow_to(const ssotinum_t* num,coeff_t e, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse logarithm in a given base
 * @{
 */

/**
 * @brief Logarithm in a given base of a number (allocating variant).
 *
 * @param[in] num  Argument.
 * @param[in] base Logarithm base.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_logb(const ssotinum_t* num,coeff_t base, dhelpl_t dhl);

/**
 * @brief Logarithm in a given base of a number into an existing one.
 *
 * @param[in]     num  Argument.
 * @param[in]     base Logarithm base.
 * @param[in,out] res  Result; may alias @p num.
 * @param[in]     dhl  Direction helper list.
 */
void ssoti_logb_to(const ssotinum_t* num,coeff_t base, ssotinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


#endif
