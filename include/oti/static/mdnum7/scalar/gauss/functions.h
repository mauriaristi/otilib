#ifndef OTI_MDNUM7_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM7_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_atanh(    femdnum7_t* num);
void     femdnum7_atanh_to( femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_asinh(    femdnum7_t* num);
void     femdnum7_asinh_to( femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_acosh(    femdnum7_t* num);
void     femdnum7_acosh_to( femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_tanh(     femdnum7_t* num);
void     femdnum7_tanh_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_cosh(     femdnum7_t* num);
void     femdnum7_cosh_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_sinh(     femdnum7_t* num);
void     femdnum7_sinh_to(  femdnum7_t* num, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_asin(     femdnum7_t* num);
void     femdnum7_asin_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_acos(     femdnum7_t* num);
void     femdnum7_acos_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_atan(     femdnum7_t* num);
void     femdnum7_atan_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_tan(      femdnum7_t* num);
void     femdnum7_tan_to(   femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_cos(      femdnum7_t* num);
void     femdnum7_cos_to(   femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_sin(      femdnum7_t* num);
void     femdnum7_sin_to(   femdnum7_t* num, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_logb(     femdnum7_t* num, double base);
void     femdnum7_logb_to(  femdnum7_t* num, double base, femdnum7_t* res);

femdnum7_t femdnum7_log10(    femdnum7_t* num);
void     femdnum7_log10_to( femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_log(      femdnum7_t* num);
void     femdnum7_log_to(   femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_exp(      femdnum7_t* num);
void     femdnum7_exp_to(   femdnum7_t* num, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_cbrt(     femdnum7_t* num);
void     femdnum7_cbrt_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_sqrt(     femdnum7_t* num);
void     femdnum7_sqrt_to(  femdnum7_t* num, femdnum7_t* res);

femdnum7_t femdnum7_pow(      femdnum7_t* num, double e);
void     femdnum7_pow_to(   femdnum7_t* num, double e, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum7_t femdnum7_integrate(       femdnum7_t* num, femdnum7_t* w);
void      femdnum7_integrate_to(    femdnum7_t* num, femdnum7_t* w, mdnum7_t* res);

mdnum7_t femdnum7_integrate_f(     femdnum7_t* num, femdnum7_t* w);
void      femdnum7_integrate_f_to(  femdnum7_t* num, femdnum7_t* w, mdnum7_t* res);

mdnum7_t femdnum7_integrate_r(       coeff_t num, femdnum7_t* w);
void      femdnum7_integrate_r_to(    coeff_t num, femdnum7_t* w, mdnum7_t* res);

mdnum7_t femdnum7_integrate_o(    mdnum7_t* num, femdnum7_t* w);
void      femdnum7_integrate_o_to( mdnum7_t* num, femdnum7_t* w, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif