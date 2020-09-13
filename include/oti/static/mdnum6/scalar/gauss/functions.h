#ifndef OTI_MDNUM6_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM6_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_atanh(    femdnum6_t* num);
void     femdnum6_atanh_to( femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_asinh(    femdnum6_t* num);
void     femdnum6_asinh_to( femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_acosh(    femdnum6_t* num);
void     femdnum6_acosh_to( femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_tanh(     femdnum6_t* num);
void     femdnum6_tanh_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_cosh(     femdnum6_t* num);
void     femdnum6_cosh_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_sinh(     femdnum6_t* num);
void     femdnum6_sinh_to(  femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_asin(     femdnum6_t* num);
void     femdnum6_asin_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_acos(     femdnum6_t* num);
void     femdnum6_acos_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_atan(     femdnum6_t* num);
void     femdnum6_atan_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_tan(      femdnum6_t* num);
void     femdnum6_tan_to(   femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_cos(      femdnum6_t* num);
void     femdnum6_cos_to(   femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_sin(      femdnum6_t* num);
void     femdnum6_sin_to(   femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_logb(     femdnum6_t* num, double base);
void     femdnum6_logb_to(  femdnum6_t* num, double base, femdnum6_t* res);

femdnum6_t femdnum6_log10(    femdnum6_t* num);
void     femdnum6_log10_to( femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_log(      femdnum6_t* num);
void     femdnum6_log_to(   femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_exp(      femdnum6_t* num);
void     femdnum6_exp_to(   femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_cbrt(     femdnum6_t* num);
void     femdnum6_cbrt_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_sqrt(     femdnum6_t* num);
void     femdnum6_sqrt_to(  femdnum6_t* num, femdnum6_t* res);

femdnum6_t femdnum6_pow(      femdnum6_t* num, double e);
void     femdnum6_pow_to(   femdnum6_t* num, double e, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum6_t femdnum6_integrate(       femdnum6_t* num, femdnum6_t* w);
void      femdnum6_integrate_to(    femdnum6_t* num, femdnum6_t* w, mdnum6_t* res);

mdnum6_t femdnum6_integrate_f(     femdnum6_t* num, femdnum6_t* w);
void      femdnum6_integrate_f_to(  femdnum6_t* num, femdnum6_t* w, mdnum6_t* res);

mdnum6_t femdnum6_integrate_r(       coeff_t num, femdnum6_t* w);
void      femdnum6_integrate_r_to(    coeff_t num, femdnum6_t* w, mdnum6_t* res);

mdnum6_t femdnum6_integrate_o(    mdnum6_t* num, femdnum6_t* w);
void      femdnum6_integrate_o_to( mdnum6_t* num, femdnum6_t* w, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif