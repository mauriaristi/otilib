#ifndef OTI_MDNUM10_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM10_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_atanh(    femdnum10_t* num);
void     femdnum10_atanh_to( femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_asinh(    femdnum10_t* num);
void     femdnum10_asinh_to( femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_acosh(    femdnum10_t* num);
void     femdnum10_acosh_to( femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_tanh(     femdnum10_t* num);
void     femdnum10_tanh_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_cosh(     femdnum10_t* num);
void     femdnum10_cosh_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_sinh(     femdnum10_t* num);
void     femdnum10_sinh_to(  femdnum10_t* num, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_asin(     femdnum10_t* num);
void     femdnum10_asin_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_acos(     femdnum10_t* num);
void     femdnum10_acos_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_atan(     femdnum10_t* num);
void     femdnum10_atan_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_tan(      femdnum10_t* num);
void     femdnum10_tan_to(   femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_cos(      femdnum10_t* num);
void     femdnum10_cos_to(   femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_sin(      femdnum10_t* num);
void     femdnum10_sin_to(   femdnum10_t* num, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_logb(     femdnum10_t* num, double base);
void     femdnum10_logb_to(  femdnum10_t* num, double base, femdnum10_t* res);

femdnum10_t femdnum10_log10(    femdnum10_t* num);
void     femdnum10_log10_to( femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_log(      femdnum10_t* num);
void     femdnum10_log_to(   femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_exp(      femdnum10_t* num);
void     femdnum10_exp_to(   femdnum10_t* num, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_cbrt(     femdnum10_t* num);
void     femdnum10_cbrt_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_sqrt(     femdnum10_t* num);
void     femdnum10_sqrt_to(  femdnum10_t* num, femdnum10_t* res);

femdnum10_t femdnum10_pow(      femdnum10_t* num, double e);
void     femdnum10_pow_to(   femdnum10_t* num, double e, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum10_t femdnum10_integrate(       femdnum10_t* num, femdnum10_t* w);
void      femdnum10_integrate_to(    femdnum10_t* num, femdnum10_t* w, mdnum10_t* res);

mdnum10_t femdnum10_integrate_f(     femdnum10_t* num, femdnum10_t* w);
void      femdnum10_integrate_f_to(  femdnum10_t* num, femdnum10_t* w, mdnum10_t* res);

mdnum10_t femdnum10_integrate_r(       coeff_t num, femdnum10_t* w);
void      femdnum10_integrate_r_to(    coeff_t num, femdnum10_t* w, mdnum10_t* res);

mdnum10_t femdnum10_integrate_o(    mdnum10_t* num, femdnum10_t* w);
void      femdnum10_integrate_o_to( mdnum10_t* num, femdnum10_t* w, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif