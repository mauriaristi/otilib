#ifndef OTI_MDNUM1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_MDNUM1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_atanh(    femdnum1_t* num);
void     femdnum1_atanh_to( femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_asinh(    femdnum1_t* num);
void     femdnum1_asinh_to( femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_acosh(    femdnum1_t* num);
void     femdnum1_acosh_to( femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_tanh(     femdnum1_t* num);
void     femdnum1_tanh_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_cosh(     femdnum1_t* num);
void     femdnum1_cosh_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_sinh(     femdnum1_t* num);
void     femdnum1_sinh_to(  femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_asin(     femdnum1_t* num);
void     femdnum1_asin_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_acos(     femdnum1_t* num);
void     femdnum1_acos_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_atan(     femdnum1_t* num);
void     femdnum1_atan_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_tan(      femdnum1_t* num);
void     femdnum1_tan_to(   femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_cos(      femdnum1_t* num);
void     femdnum1_cos_to(   femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_sin(      femdnum1_t* num);
void     femdnum1_sin_to(   femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_logb(     femdnum1_t* num, double base);
void     femdnum1_logb_to(  femdnum1_t* num, double base, femdnum1_t* res);

femdnum1_t femdnum1_log10(    femdnum1_t* num);
void     femdnum1_log10_to( femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_log(      femdnum1_t* num);
void     femdnum1_log_to(   femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_exp(      femdnum1_t* num);
void     femdnum1_exp_to(   femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_cbrt(     femdnum1_t* num);
void     femdnum1_cbrt_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_sqrt(     femdnum1_t* num);
void     femdnum1_sqrt_to(  femdnum1_t* num, femdnum1_t* res);

femdnum1_t femdnum1_pow(      femdnum1_t* num, double e);
void     femdnum1_pow_to(   femdnum1_t* num, double e, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdnum1_t femdnum1_integrate(       femdnum1_t* num, femdnum1_t* w);
void      femdnum1_integrate_to(    femdnum1_t* num, femdnum1_t* w, mdnum1_t* res);

mdnum1_t femdnum1_integrate_f(     femdnum1_t* num, femdnum1_t* w);
void      femdnum1_integrate_f_to(  femdnum1_t* num, femdnum1_t* w, mdnum1_t* res);

mdnum1_t femdnum1_integrate_r(       coeff_t num, femdnum1_t* w);
void      femdnum1_integrate_r_to(    coeff_t num, femdnum1_t* w, mdnum1_t* res);

mdnum1_t femdnum1_integrate_o(    mdnum1_t* num, femdnum1_t* w);
void      femdnum1_integrate_o_to( mdnum1_t* num, femdnum1_t* w, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif