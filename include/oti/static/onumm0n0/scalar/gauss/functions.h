#ifndef OTI_ONUMM0N0_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM0N0_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_atanh(    feonumm0n0_t* num);
void     feonumm0n0_atanh_to( feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_asinh(    feonumm0n0_t* num);
void     feonumm0n0_asinh_to( feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_acosh(    feonumm0n0_t* num);
void     feonumm0n0_acosh_to( feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_tanh(     feonumm0n0_t* num);
void     feonumm0n0_tanh_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_cosh(     feonumm0n0_t* num);
void     feonumm0n0_cosh_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sinh(     feonumm0n0_t* num);
void     feonumm0n0_sinh_to(  feonumm0n0_t* num, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_asin(     feonumm0n0_t* num);
void     feonumm0n0_asin_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_acos(     feonumm0n0_t* num);
void     feonumm0n0_acos_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_atan(     feonumm0n0_t* num);
void     feonumm0n0_atan_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_tan(      feonumm0n0_t* num);
void     feonumm0n0_tan_to(   feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_cos(      feonumm0n0_t* num);
void     feonumm0n0_cos_to(   feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sin(      feonumm0n0_t* num);
void     feonumm0n0_sin_to(   feonumm0n0_t* num, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_logb(     feonumm0n0_t* num, double base);
void     feonumm0n0_logb_to(  feonumm0n0_t* num, double base, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_log10(    feonumm0n0_t* num);
void     feonumm0n0_log10_to( feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_log(      feonumm0n0_t* num);
void     feonumm0n0_log_to(   feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_exp(      feonumm0n0_t* num);
void     feonumm0n0_exp_to(   feonumm0n0_t* num, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_cbrt(     feonumm0n0_t* num);
void     feonumm0n0_cbrt_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sqrt(     feonumm0n0_t* num);
void     feonumm0n0_sqrt_to(  feonumm0n0_t* num, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_pow(      feonumm0n0_t* num, double e);
void     feonumm0n0_pow_to(   feonumm0n0_t* num, double e, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm0n0_t feonumm0n0_integrate(       feonumm0n0_t* num, feonumm0n0_t* w);
void      feonumm0n0_integrate_to(    feonumm0n0_t* num, feonumm0n0_t* w, onumm0n0_t* res);

onumm0n0_t feonumm0n0_integrate_f(     feonumm0n0_t* num, feonumm0n0_t* w);
void      feonumm0n0_integrate_f_to(  feonumm0n0_t* num, feonumm0n0_t* w, onumm0n0_t* res);

onumm0n0_t feonumm0n0_integrate_r(       coeff_t num, feonumm0n0_t* w);
void      feonumm0n0_integrate_r_to(    coeff_t num, feonumm0n0_t* w, onumm0n0_t* res);

onumm0n0_t feonumm0n0_integrate_o(    onumm0n0_t* num, feonumm0n0_t* w);
void      feonumm0n0_integrate_o_to( onumm0n0_t* num, feonumm0n0_t* w, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif