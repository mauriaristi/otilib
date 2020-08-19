#ifndef OTI_MDNUM2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_atanh(    femdnum2_t* num);
void     femdnum2_atanh_to( femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_asinh(    femdnum2_t* num);
void     femdnum2_asinh_to( femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_acosh(    femdnum2_t* num);
void     femdnum2_acosh_to( femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_tanh(     femdnum2_t* num);
void     femdnum2_tanh_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_cosh(     femdnum2_t* num);
void     femdnum2_cosh_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_sinh(     femdnum2_t* num);
void     femdnum2_sinh_to(  femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_asin(     femdnum2_t* num);
void     femdnum2_asin_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_acos(     femdnum2_t* num);
void     femdnum2_acos_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_atan(     femdnum2_t* num);
void     femdnum2_atan_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_tan(      femdnum2_t* num);
void     femdnum2_tan_to(   femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_cos(      femdnum2_t* num);
void     femdnum2_cos_to(   femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_sin(      femdnum2_t* num);
void     femdnum2_sin_to(   femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_logb(     femdnum2_t* num, double base);
void     femdnum2_logb_to(  femdnum2_t* num, double base, femdnum2_t* res);

femdnum2_t femdnum2_log10(    femdnum2_t* num);
void     femdnum2_log10_to( femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_log(      femdnum2_t* num);
void     femdnum2_log_to(   femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_exp(      femdnum2_t* num);
void     femdnum2_exp_to(   femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_cbrt(     femdnum2_t* num);
void     femdnum2_cbrt_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_sqrt(     femdnum2_t* num);
void     femdnum2_sqrt_to(  femdnum2_t* num, femdnum2_t* res);

femdnum2_t femdnum2_pow(      femdnum2_t* num, double e);
void     femdnum2_pow_to(   femdnum2_t* num, double e, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum2_t femdnum2_integrate(       femdnum2_t* num, femdnum2_t* w);
void      femdnum2_integrate_to(    femdnum2_t* num, femdnum2_t* w, mdnum2_t* res);

mdnum2_t femdnum2_integrate_f(     femdnum2_t* num, femdnum2_t* w);
void      femdnum2_integrate_f_to(  femdnum2_t* num, femdnum2_t* w, mdnum2_t* res);

mdnum2_t femdnum2_integrate_r(       coeff_t num, femdnum2_t* w);
void      femdnum2_integrate_r_to(    coeff_t num, femdnum2_t* w, mdnum2_t* res);

mdnum2_t femdnum2_integrate_o(    mdnum2_t* num, femdnum2_t* w);
void      femdnum2_integrate_o_to( mdnum2_t* num, femdnum2_t* w, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif