#ifndef OTI_MDNUM8_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM8_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_atanh(    femdnum8_t* num);
void     femdnum8_atanh_to( femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_asinh(    femdnum8_t* num);
void     femdnum8_asinh_to( femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_acosh(    femdnum8_t* num);
void     femdnum8_acosh_to( femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_tanh(     femdnum8_t* num);
void     femdnum8_tanh_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_cosh(     femdnum8_t* num);
void     femdnum8_cosh_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_sinh(     femdnum8_t* num);
void     femdnum8_sinh_to(  femdnum8_t* num, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_asin(     femdnum8_t* num);
void     femdnum8_asin_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_acos(     femdnum8_t* num);
void     femdnum8_acos_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_atan(     femdnum8_t* num);
void     femdnum8_atan_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_tan(      femdnum8_t* num);
void     femdnum8_tan_to(   femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_cos(      femdnum8_t* num);
void     femdnum8_cos_to(   femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_sin(      femdnum8_t* num);
void     femdnum8_sin_to(   femdnum8_t* num, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_logb(     femdnum8_t* num, double base);
void     femdnum8_logb_to(  femdnum8_t* num, double base, femdnum8_t* res);

femdnum8_t femdnum8_log10(    femdnum8_t* num);
void     femdnum8_log10_to( femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_log(      femdnum8_t* num);
void     femdnum8_log_to(   femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_exp(      femdnum8_t* num);
void     femdnum8_exp_to(   femdnum8_t* num, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_cbrt(     femdnum8_t* num);
void     femdnum8_cbrt_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_sqrt(     femdnum8_t* num);
void     femdnum8_sqrt_to(  femdnum8_t* num, femdnum8_t* res);

femdnum8_t femdnum8_pow(      femdnum8_t* num, double e);
void     femdnum8_pow_to(   femdnum8_t* num, double e, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum8_t femdnum8_integrate(       femdnum8_t* num, femdnum8_t* w);
void      femdnum8_integrate_to(    femdnum8_t* num, femdnum8_t* w, mdnum8_t* res);

mdnum8_t femdnum8_integrate_f(     femdnum8_t* num, femdnum8_t* w);
void      femdnum8_integrate_f_to(  femdnum8_t* num, femdnum8_t* w, mdnum8_t* res);

mdnum8_t femdnum8_integrate_r(       coeff_t num, femdnum8_t* w);
void      femdnum8_integrate_r_to(    coeff_t num, femdnum8_t* w, mdnum8_t* res);

mdnum8_t femdnum8_integrate_o(    mdnum8_t* num, femdnum8_t* w);
void      femdnum8_integrate_o_to( mdnum8_t* num, femdnum8_t* w, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif