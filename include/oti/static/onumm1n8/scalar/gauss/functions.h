#ifndef OTI_ONUMM1N8_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N8_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n8_t feonumm1n8_atanh(    feonumm1n8_t* num);
void     feonumm1n8_atanh_to( feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_asinh(    feonumm1n8_t* num);
void     feonumm1n8_asinh_to( feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_acosh(    feonumm1n8_t* num);
void     feonumm1n8_acosh_to( feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_tanh(     feonumm1n8_t* num);
void     feonumm1n8_tanh_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_cosh(     feonumm1n8_t* num);
void     feonumm1n8_cosh_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_sinh(     feonumm1n8_t* num);
void     feonumm1n8_sinh_to(  feonumm1n8_t* num, feonumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n8_t feonumm1n8_asin(     feonumm1n8_t* num);
void     feonumm1n8_asin_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_acos(     feonumm1n8_t* num);
void     feonumm1n8_acos_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_atan(     feonumm1n8_t* num);
void     feonumm1n8_atan_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_tan(      feonumm1n8_t* num);
void     feonumm1n8_tan_to(   feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_cos(      feonumm1n8_t* num);
void     feonumm1n8_cos_to(   feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_sin(      feonumm1n8_t* num);
void     feonumm1n8_sin_to(   feonumm1n8_t* num, feonumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n8_t feonumm1n8_logb(     feonumm1n8_t* num, double base);
void     feonumm1n8_logb_to(  feonumm1n8_t* num, double base, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_log10(    feonumm1n8_t* num);
void     feonumm1n8_log10_to( feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_log(      feonumm1n8_t* num);
void     feonumm1n8_log_to(   feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_exp(      feonumm1n8_t* num);
void     feonumm1n8_exp_to(   feonumm1n8_t* num, feonumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n8_t feonumm1n8_cbrt(     feonumm1n8_t* num);
void     feonumm1n8_cbrt_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_sqrt(     feonumm1n8_t* num);
void     feonumm1n8_sqrt_to(  feonumm1n8_t* num, feonumm1n8_t* res);

feonumm1n8_t feonumm1n8_pow(      feonumm1n8_t* num, double e);
void     feonumm1n8_pow_to(   feonumm1n8_t* num, double e, feonumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n8_t feonumm1n8_integrate(       feonumm1n8_t* num, feonumm1n8_t* w);
void      feonumm1n8_integrate_to(    feonumm1n8_t* num, feonumm1n8_t* w, onumm1n8_t* res);

onumm1n8_t feonumm1n8_integrate_f(     feonumm1n8_t* num, feonumm1n8_t* w);
void      feonumm1n8_integrate_f_to(  feonumm1n8_t* num, feonumm1n8_t* w, onumm1n8_t* res);

onumm1n8_t feonumm1n8_integrate_r(       coeff_t num, feonumm1n8_t* w);
void      feonumm1n8_integrate_r_to(    coeff_t num, feonumm1n8_t* w, onumm1n8_t* res);

onumm1n8_t feonumm1n8_integrate_o(    onumm1n8_t* num, feonumm1n8_t* w);
void      feonumm1n8_integrate_o_to( onumm1n8_t* num, feonumm1n8_t* w, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif