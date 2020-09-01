#ifndef OTI_MDNUM4_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM4_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_atanh(    femdnum4_t* num);
void     femdnum4_atanh_to( femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_asinh(    femdnum4_t* num);
void     femdnum4_asinh_to( femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_acosh(    femdnum4_t* num);
void     femdnum4_acosh_to( femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_tanh(     femdnum4_t* num);
void     femdnum4_tanh_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_cosh(     femdnum4_t* num);
void     femdnum4_cosh_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_sinh(     femdnum4_t* num);
void     femdnum4_sinh_to(  femdnum4_t* num, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_asin(     femdnum4_t* num);
void     femdnum4_asin_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_acos(     femdnum4_t* num);
void     femdnum4_acos_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_atan(     femdnum4_t* num);
void     femdnum4_atan_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_tan(      femdnum4_t* num);
void     femdnum4_tan_to(   femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_cos(      femdnum4_t* num);
void     femdnum4_cos_to(   femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_sin(      femdnum4_t* num);
void     femdnum4_sin_to(   femdnum4_t* num, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_logb(     femdnum4_t* num, double base);
void     femdnum4_logb_to(  femdnum4_t* num, double base, femdnum4_t* res);

femdnum4_t femdnum4_log10(    femdnum4_t* num);
void     femdnum4_log10_to( femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_log(      femdnum4_t* num);
void     femdnum4_log_to(   femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_exp(      femdnum4_t* num);
void     femdnum4_exp_to(   femdnum4_t* num, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_cbrt(     femdnum4_t* num);
void     femdnum4_cbrt_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_sqrt(     femdnum4_t* num);
void     femdnum4_sqrt_to(  femdnum4_t* num, femdnum4_t* res);

femdnum4_t femdnum4_pow(      femdnum4_t* num, double e);
void     femdnum4_pow_to(   femdnum4_t* num, double e, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum4_t femdnum4_integrate(       femdnum4_t* num, femdnum4_t* w);
void      femdnum4_integrate_to(    femdnum4_t* num, femdnum4_t* w, mdnum4_t* res);

mdnum4_t femdnum4_integrate_f(     femdnum4_t* num, femdnum4_t* w);
void      femdnum4_integrate_f_to(  femdnum4_t* num, femdnum4_t* w, mdnum4_t* res);

mdnum4_t femdnum4_integrate_r(       coeff_t num, femdnum4_t* w);
void      femdnum4_integrate_r_to(    coeff_t num, femdnum4_t* w, mdnum4_t* res);

mdnum4_t femdnum4_integrate_o(    mdnum4_t* num, femdnum4_t* w);
void      femdnum4_integrate_o_to( mdnum4_t* num, femdnum4_t* w, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif