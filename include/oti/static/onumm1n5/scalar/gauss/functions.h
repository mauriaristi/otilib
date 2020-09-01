#ifndef OTI_ONUMM1N5_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N5_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n5_t feonumm1n5_atanh(    feonumm1n5_t* num);
void     feonumm1n5_atanh_to( feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_asinh(    feonumm1n5_t* num);
void     feonumm1n5_asinh_to( feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_acosh(    feonumm1n5_t* num);
void     feonumm1n5_acosh_to( feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_tanh(     feonumm1n5_t* num);
void     feonumm1n5_tanh_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_cosh(     feonumm1n5_t* num);
void     feonumm1n5_cosh_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_sinh(     feonumm1n5_t* num);
void     feonumm1n5_sinh_to(  feonumm1n5_t* num, feonumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n5_t feonumm1n5_asin(     feonumm1n5_t* num);
void     feonumm1n5_asin_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_acos(     feonumm1n5_t* num);
void     feonumm1n5_acos_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_atan(     feonumm1n5_t* num);
void     feonumm1n5_atan_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_tan(      feonumm1n5_t* num);
void     feonumm1n5_tan_to(   feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_cos(      feonumm1n5_t* num);
void     feonumm1n5_cos_to(   feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_sin(      feonumm1n5_t* num);
void     feonumm1n5_sin_to(   feonumm1n5_t* num, feonumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n5_t feonumm1n5_logb(     feonumm1n5_t* num, double base);
void     feonumm1n5_logb_to(  feonumm1n5_t* num, double base, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_log10(    feonumm1n5_t* num);
void     feonumm1n5_log10_to( feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_log(      feonumm1n5_t* num);
void     feonumm1n5_log_to(   feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_exp(      feonumm1n5_t* num);
void     feonumm1n5_exp_to(   feonumm1n5_t* num, feonumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n5_t feonumm1n5_cbrt(     feonumm1n5_t* num);
void     feonumm1n5_cbrt_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_sqrt(     feonumm1n5_t* num);
void     feonumm1n5_sqrt_to(  feonumm1n5_t* num, feonumm1n5_t* res);

feonumm1n5_t feonumm1n5_pow(      feonumm1n5_t* num, double e);
void     feonumm1n5_pow_to(   feonumm1n5_t* num, double e, feonumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n5_t feonumm1n5_integrate(       feonumm1n5_t* num, feonumm1n5_t* w);
void      feonumm1n5_integrate_to(    feonumm1n5_t* num, feonumm1n5_t* w, onumm1n5_t* res);

onumm1n5_t feonumm1n5_integrate_f(     feonumm1n5_t* num, feonumm1n5_t* w);
void      feonumm1n5_integrate_f_to(  feonumm1n5_t* num, feonumm1n5_t* w, onumm1n5_t* res);

onumm1n5_t feonumm1n5_integrate_r(       coeff_t num, feonumm1n5_t* w);
void      feonumm1n5_integrate_r_to(    coeff_t num, feonumm1n5_t* w, onumm1n5_t* res);

onumm1n5_t feonumm1n5_integrate_o(    onumm1n5_t* num, feonumm1n5_t* w);
void      feonumm1n5_integrate_o_to( onumm1n5_t* num, feonumm1n5_t* w, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif