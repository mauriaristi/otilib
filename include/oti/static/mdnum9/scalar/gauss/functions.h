#ifndef OTI_MDNUM9_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM9_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_atanh(    femdnum9_t* num);
void     femdnum9_atanh_to( femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_asinh(    femdnum9_t* num);
void     femdnum9_asinh_to( femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_acosh(    femdnum9_t* num);
void     femdnum9_acosh_to( femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_tanh(     femdnum9_t* num);
void     femdnum9_tanh_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_cosh(     femdnum9_t* num);
void     femdnum9_cosh_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_sinh(     femdnum9_t* num);
void     femdnum9_sinh_to(  femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_asin(     femdnum9_t* num);
void     femdnum9_asin_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_acos(     femdnum9_t* num);
void     femdnum9_acos_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_atan(     femdnum9_t* num);
void     femdnum9_atan_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_tan(      femdnum9_t* num);
void     femdnum9_tan_to(   femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_cos(      femdnum9_t* num);
void     femdnum9_cos_to(   femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_sin(      femdnum9_t* num);
void     femdnum9_sin_to(   femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_logb(     femdnum9_t* num, double base);
void     femdnum9_logb_to(  femdnum9_t* num, double base, femdnum9_t* res);

femdnum9_t femdnum9_log10(    femdnum9_t* num);
void     femdnum9_log10_to( femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_log(      femdnum9_t* num);
void     femdnum9_log_to(   femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_exp(      femdnum9_t* num);
void     femdnum9_exp_to(   femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_cbrt(     femdnum9_t* num);
void     femdnum9_cbrt_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_sqrt(     femdnum9_t* num);
void     femdnum9_sqrt_to(  femdnum9_t* num, femdnum9_t* res);

femdnum9_t femdnum9_pow(      femdnum9_t* num, double e);
void     femdnum9_pow_to(   femdnum9_t* num, double e, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum9_t femdnum9_integrate(       femdnum9_t* num, femdnum9_t* w);
void      femdnum9_integrate_to(    femdnum9_t* num, femdnum9_t* w, mdnum9_t* res);

mdnum9_t femdnum9_integrate_f(     femdnum9_t* num, femdnum9_t* w);
void      femdnum9_integrate_f_to(  femdnum9_t* num, femdnum9_t* w, mdnum9_t* res);

mdnum9_t femdnum9_integrate_r(       coeff_t num, femdnum9_t* w);
void      femdnum9_integrate_r_to(    coeff_t num, femdnum9_t* w, mdnum9_t* res);

mdnum9_t femdnum9_integrate_o(    mdnum9_t* num, femdnum9_t* w);
void      femdnum9_integrate_o_to( mdnum9_t* num, femdnum9_t* w, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif