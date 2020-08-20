#ifndef OTI_ONUMM4N4_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N4_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n4_t feonumm4n4_atanh(    feonumm4n4_t* num);
void     feonumm4n4_atanh_to( feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_asinh(    feonumm4n4_t* num);
void     feonumm4n4_asinh_to( feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_acosh(    feonumm4n4_t* num);
void     feonumm4n4_acosh_to( feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_tanh(     feonumm4n4_t* num);
void     feonumm4n4_tanh_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_cosh(     feonumm4n4_t* num);
void     feonumm4n4_cosh_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_sinh(     feonumm4n4_t* num);
void     feonumm4n4_sinh_to(  feonumm4n4_t* num, feonumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n4_t feonumm4n4_asin(     feonumm4n4_t* num);
void     feonumm4n4_asin_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_acos(     feonumm4n4_t* num);
void     feonumm4n4_acos_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_atan(     feonumm4n4_t* num);
void     feonumm4n4_atan_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_tan(      feonumm4n4_t* num);
void     feonumm4n4_tan_to(   feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_cos(      feonumm4n4_t* num);
void     feonumm4n4_cos_to(   feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_sin(      feonumm4n4_t* num);
void     feonumm4n4_sin_to(   feonumm4n4_t* num, feonumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n4_t feonumm4n4_logb(     feonumm4n4_t* num, double base);
void     feonumm4n4_logb_to(  feonumm4n4_t* num, double base, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_log10(    feonumm4n4_t* num);
void     feonumm4n4_log10_to( feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_log(      feonumm4n4_t* num);
void     feonumm4n4_log_to(   feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_exp(      feonumm4n4_t* num);
void     feonumm4n4_exp_to(   feonumm4n4_t* num, feonumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n4_t feonumm4n4_cbrt(     feonumm4n4_t* num);
void     feonumm4n4_cbrt_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_sqrt(     feonumm4n4_t* num);
void     feonumm4n4_sqrt_to(  feonumm4n4_t* num, feonumm4n4_t* res);

feonumm4n4_t feonumm4n4_pow(      feonumm4n4_t* num, double e);
void     feonumm4n4_pow_to(   feonumm4n4_t* num, double e, feonumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm4n4_t feonumm4n4_integrate(       feonumm4n4_t* num, feonumm4n4_t* w);
void      feonumm4n4_integrate_to(    feonumm4n4_t* num, feonumm4n4_t* w, onumm4n4_t* res);

onumm4n4_t feonumm4n4_integrate_f(     feonumm4n4_t* num, feonumm4n4_t* w);
void      feonumm4n4_integrate_f_to(  feonumm4n4_t* num, feonumm4n4_t* w, onumm4n4_t* res);

onumm4n4_t feonumm4n4_integrate_r(       coeff_t num, feonumm4n4_t* w);
void      feonumm4n4_integrate_r_to(    coeff_t num, feonumm4n4_t* w, onumm4n4_t* res);

onumm4n4_t feonumm4n4_integrate_o(    onumm4n4_t* num, feonumm4n4_t* w);
void      feonumm4n4_integrate_o_to( onumm4n4_t* num, feonumm4n4_t* w, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif