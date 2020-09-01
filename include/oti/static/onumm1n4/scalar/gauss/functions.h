#ifndef OTI_ONUMM1N4_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N4_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n4_t feonumm1n4_atanh(    feonumm1n4_t* num);
void     feonumm1n4_atanh_to( feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_asinh(    feonumm1n4_t* num);
void     feonumm1n4_asinh_to( feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_acosh(    feonumm1n4_t* num);
void     feonumm1n4_acosh_to( feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_tanh(     feonumm1n4_t* num);
void     feonumm1n4_tanh_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_cosh(     feonumm1n4_t* num);
void     feonumm1n4_cosh_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_sinh(     feonumm1n4_t* num);
void     feonumm1n4_sinh_to(  feonumm1n4_t* num, feonumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n4_t feonumm1n4_asin(     feonumm1n4_t* num);
void     feonumm1n4_asin_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_acos(     feonumm1n4_t* num);
void     feonumm1n4_acos_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_atan(     feonumm1n4_t* num);
void     feonumm1n4_atan_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_tan(      feonumm1n4_t* num);
void     feonumm1n4_tan_to(   feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_cos(      feonumm1n4_t* num);
void     feonumm1n4_cos_to(   feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_sin(      feonumm1n4_t* num);
void     feonumm1n4_sin_to(   feonumm1n4_t* num, feonumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n4_t feonumm1n4_logb(     feonumm1n4_t* num, double base);
void     feonumm1n4_logb_to(  feonumm1n4_t* num, double base, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_log10(    feonumm1n4_t* num);
void     feonumm1n4_log10_to( feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_log(      feonumm1n4_t* num);
void     feonumm1n4_log_to(   feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_exp(      feonumm1n4_t* num);
void     feonumm1n4_exp_to(   feonumm1n4_t* num, feonumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n4_t feonumm1n4_cbrt(     feonumm1n4_t* num);
void     feonumm1n4_cbrt_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_sqrt(     feonumm1n4_t* num);
void     feonumm1n4_sqrt_to(  feonumm1n4_t* num, feonumm1n4_t* res);

feonumm1n4_t feonumm1n4_pow(      feonumm1n4_t* num, double e);
void     feonumm1n4_pow_to(   feonumm1n4_t* num, double e, feonumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n4_t feonumm1n4_integrate(       feonumm1n4_t* num, feonumm1n4_t* w);
void      feonumm1n4_integrate_to(    feonumm1n4_t* num, feonumm1n4_t* w, onumm1n4_t* res);

onumm1n4_t feonumm1n4_integrate_f(     feonumm1n4_t* num, feonumm1n4_t* w);
void      feonumm1n4_integrate_f_to(  feonumm1n4_t* num, feonumm1n4_t* w, onumm1n4_t* res);

onumm1n4_t feonumm1n4_integrate_r(       coeff_t num, feonumm1n4_t* w);
void      feonumm1n4_integrate_r_to(    coeff_t num, feonumm1n4_t* w, onumm1n4_t* res);

onumm1n4_t feonumm1n4_integrate_o(    onumm1n4_t* num, feonumm1n4_t* w);
void      feonumm1n4_integrate_o_to( onumm1n4_t* num, feonumm1n4_t* w, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif