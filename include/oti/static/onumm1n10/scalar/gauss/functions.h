#ifndef OTI_ONUMM1N10_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N10_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_atanh(    feonumm1n10_t* num);
void     feonumm1n10_atanh_to( feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_asinh(    feonumm1n10_t* num);
void     feonumm1n10_asinh_to( feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_acosh(    feonumm1n10_t* num);
void     feonumm1n10_acosh_to( feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_tanh(     feonumm1n10_t* num);
void     feonumm1n10_tanh_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_cosh(     feonumm1n10_t* num);
void     feonumm1n10_cosh_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sinh(     feonumm1n10_t* num);
void     feonumm1n10_sinh_to(  feonumm1n10_t* num, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_asin(     feonumm1n10_t* num);
void     feonumm1n10_asin_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_acos(     feonumm1n10_t* num);
void     feonumm1n10_acos_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_atan(     feonumm1n10_t* num);
void     feonumm1n10_atan_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_tan(      feonumm1n10_t* num);
void     feonumm1n10_tan_to(   feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_cos(      feonumm1n10_t* num);
void     feonumm1n10_cos_to(   feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sin(      feonumm1n10_t* num);
void     feonumm1n10_sin_to(   feonumm1n10_t* num, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_logb(     feonumm1n10_t* num, double base);
void     feonumm1n10_logb_to(  feonumm1n10_t* num, double base, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_log10(    feonumm1n10_t* num);
void     feonumm1n10_log10_to( feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_log(      feonumm1n10_t* num);
void     feonumm1n10_log_to(   feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_exp(      feonumm1n10_t* num);
void     feonumm1n10_exp_to(   feonumm1n10_t* num, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_cbrt(     feonumm1n10_t* num);
void     feonumm1n10_cbrt_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sqrt(     feonumm1n10_t* num);
void     feonumm1n10_sqrt_to(  feonumm1n10_t* num, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_pow(      feonumm1n10_t* num, double e);
void     feonumm1n10_pow_to(   feonumm1n10_t* num, double e, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n10_t feonumm1n10_integrate(       feonumm1n10_t* num, feonumm1n10_t* w);
void      feonumm1n10_integrate_to(    feonumm1n10_t* num, feonumm1n10_t* w, onumm1n10_t* res);

onumm1n10_t feonumm1n10_integrate_f(     feonumm1n10_t* num, feonumm1n10_t* w);
void      feonumm1n10_integrate_f_to(  feonumm1n10_t* num, feonumm1n10_t* w, onumm1n10_t* res);

onumm1n10_t feonumm1n10_integrate_r(       coeff_t num, feonumm1n10_t* w);
void      feonumm1n10_integrate_r_to(    coeff_t num, feonumm1n10_t* w, onumm1n10_t* res);

onumm1n10_t feonumm1n10_integrate_o(    onumm1n10_t* num, feonumm1n10_t* w);
void      feonumm1n10_integrate_o_to( onumm1n10_t* num, feonumm1n10_t* w, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif