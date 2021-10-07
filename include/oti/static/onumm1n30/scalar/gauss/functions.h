#ifndef OTI_ONUMM1N30_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N30_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n30_t feonumm1n30_atanh(    feonumm1n30_t* num);
void     feonumm1n30_atanh_to( feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_asinh(    feonumm1n30_t* num);
void     feonumm1n30_asinh_to( feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_acosh(    feonumm1n30_t* num);
void     feonumm1n30_acosh_to( feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_tanh(     feonumm1n30_t* num);
void     feonumm1n30_tanh_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_cosh(     feonumm1n30_t* num);
void     feonumm1n30_cosh_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_sinh(     feonumm1n30_t* num);
void     feonumm1n30_sinh_to(  feonumm1n30_t* num, feonumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n30_t feonumm1n30_asin(     feonumm1n30_t* num);
void     feonumm1n30_asin_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_acos(     feonumm1n30_t* num);
void     feonumm1n30_acos_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_atan(     feonumm1n30_t* num);
void     feonumm1n30_atan_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_tan(      feonumm1n30_t* num);
void     feonumm1n30_tan_to(   feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_cos(      feonumm1n30_t* num);
void     feonumm1n30_cos_to(   feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_sin(      feonumm1n30_t* num);
void     feonumm1n30_sin_to(   feonumm1n30_t* num, feonumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n30_t feonumm1n30_logb(     feonumm1n30_t* num, double base);
void     feonumm1n30_logb_to(  feonumm1n30_t* num, double base, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_log10(    feonumm1n30_t* num);
void     feonumm1n30_log10_to( feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_log(      feonumm1n30_t* num);
void     feonumm1n30_log_to(   feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_exp(      feonumm1n30_t* num);
void     feonumm1n30_exp_to(   feonumm1n30_t* num, feonumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n30_t feonumm1n30_cbrt(     feonumm1n30_t* num);
void     feonumm1n30_cbrt_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_sqrt(     feonumm1n30_t* num);
void     feonumm1n30_sqrt_to(  feonumm1n30_t* num, feonumm1n30_t* res);

feonumm1n30_t feonumm1n30_pow(      feonumm1n30_t* num, double e);
void     feonumm1n30_pow_to(   feonumm1n30_t* num, double e, feonumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n30_t feonumm1n30_integrate(       feonumm1n30_t* num, feonumm1n30_t* w);
void      feonumm1n30_integrate_to(    feonumm1n30_t* num, feonumm1n30_t* w, onumm1n30_t* res);

onumm1n30_t feonumm1n30_integrate_f(     feonumm1n30_t* num, feonumm1n30_t* w);
void      feonumm1n30_integrate_f_to(  feonumm1n30_t* num, feonumm1n30_t* w, onumm1n30_t* res);

onumm1n30_t feonumm1n30_integrate_r(       coeff_t num, feonumm1n30_t* w);
void      feonumm1n30_integrate_r_to(    coeff_t num, feonumm1n30_t* w, onumm1n30_t* res);

onumm1n30_t feonumm1n30_integrate_o(    onumm1n30_t* num, feonumm1n30_t* w);
void      feonumm1n30_integrate_o_to( onumm1n30_t* num, feonumm1n30_t* w, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

#endif