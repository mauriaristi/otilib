#ifndef OTI_MDNUM5_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM5_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_atanh(    femdnum5_t* num);
void     femdnum5_atanh_to( femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_asinh(    femdnum5_t* num);
void     femdnum5_asinh_to( femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_acosh(    femdnum5_t* num);
void     femdnum5_acosh_to( femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_tanh(     femdnum5_t* num);
void     femdnum5_tanh_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_cosh(     femdnum5_t* num);
void     femdnum5_cosh_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_sinh(     femdnum5_t* num);
void     femdnum5_sinh_to(  femdnum5_t* num, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_asin(     femdnum5_t* num);
void     femdnum5_asin_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_acos(     femdnum5_t* num);
void     femdnum5_acos_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_atan(     femdnum5_t* num);
void     femdnum5_atan_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_tan(      femdnum5_t* num);
void     femdnum5_tan_to(   femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_cos(      femdnum5_t* num);
void     femdnum5_cos_to(   femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_sin(      femdnum5_t* num);
void     femdnum5_sin_to(   femdnum5_t* num, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_logb(     femdnum5_t* num, double base);
void     femdnum5_logb_to(  femdnum5_t* num, double base, femdnum5_t* res);

femdnum5_t femdnum5_log10(    femdnum5_t* num);
void     femdnum5_log10_to( femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_log(      femdnum5_t* num);
void     femdnum5_log_to(   femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_exp(      femdnum5_t* num);
void     femdnum5_exp_to(   femdnum5_t* num, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_cbrt(     femdnum5_t* num);
void     femdnum5_cbrt_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_sqrt(     femdnum5_t* num);
void     femdnum5_sqrt_to(  femdnum5_t* num, femdnum5_t* res);

femdnum5_t femdnum5_pow(      femdnum5_t* num, double e);
void     femdnum5_pow_to(   femdnum5_t* num, double e, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum5_t femdnum5_integrate(       femdnum5_t* num, femdnum5_t* w);
void      femdnum5_integrate_to(    femdnum5_t* num, femdnum5_t* w, mdnum5_t* res);

mdnum5_t femdnum5_integrate_f(     femdnum5_t* num, femdnum5_t* w);
void      femdnum5_integrate_f_to(  femdnum5_t* num, femdnum5_t* w, mdnum5_t* res);

mdnum5_t femdnum5_integrate_r(       coeff_t num, femdnum5_t* w);
void      femdnum5_integrate_r_to(    coeff_t num, femdnum5_t* w, mdnum5_t* res);

mdnum5_t femdnum5_integrate_o(    mdnum5_t* num, femdnum5_t* w);
void      femdnum5_integrate_o_to( mdnum5_t* num, femdnum5_t* w, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif