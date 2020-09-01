#ifndef OTI_ONUMM4N5_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N5_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n5_t feonumm4n5_atanh(    feonumm4n5_t* num);
void     feonumm4n5_atanh_to( feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_asinh(    feonumm4n5_t* num);
void     feonumm4n5_asinh_to( feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_acosh(    feonumm4n5_t* num);
void     feonumm4n5_acosh_to( feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_tanh(     feonumm4n5_t* num);
void     feonumm4n5_tanh_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_cosh(     feonumm4n5_t* num);
void     feonumm4n5_cosh_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_sinh(     feonumm4n5_t* num);
void     feonumm4n5_sinh_to(  feonumm4n5_t* num, feonumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n5_t feonumm4n5_asin(     feonumm4n5_t* num);
void     feonumm4n5_asin_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_acos(     feonumm4n5_t* num);
void     feonumm4n5_acos_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_atan(     feonumm4n5_t* num);
void     feonumm4n5_atan_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_tan(      feonumm4n5_t* num);
void     feonumm4n5_tan_to(   feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_cos(      feonumm4n5_t* num);
void     feonumm4n5_cos_to(   feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_sin(      feonumm4n5_t* num);
void     feonumm4n5_sin_to(   feonumm4n5_t* num, feonumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n5_t feonumm4n5_logb(     feonumm4n5_t* num, double base);
void     feonumm4n5_logb_to(  feonumm4n5_t* num, double base, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_log10(    feonumm4n5_t* num);
void     feonumm4n5_log10_to( feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_log(      feonumm4n5_t* num);
void     feonumm4n5_log_to(   feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_exp(      feonumm4n5_t* num);
void     feonumm4n5_exp_to(   feonumm4n5_t* num, feonumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n5_t feonumm4n5_cbrt(     feonumm4n5_t* num);
void     feonumm4n5_cbrt_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_sqrt(     feonumm4n5_t* num);
void     feonumm4n5_sqrt_to(  feonumm4n5_t* num, feonumm4n5_t* res);

feonumm4n5_t feonumm4n5_pow(      feonumm4n5_t* num, double e);
void     feonumm4n5_pow_to(   feonumm4n5_t* num, double e, feonumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm4n5_t feonumm4n5_integrate(       feonumm4n5_t* num, feonumm4n5_t* w);
void      feonumm4n5_integrate_to(    feonumm4n5_t* num, feonumm4n5_t* w, onumm4n5_t* res);

onumm4n5_t feonumm4n5_integrate_f(     feonumm4n5_t* num, feonumm4n5_t* w);
void      feonumm4n5_integrate_f_to(  feonumm4n5_t* num, feonumm4n5_t* w, onumm4n5_t* res);

onumm4n5_t feonumm4n5_integrate_r(       coeff_t num, feonumm4n5_t* w);
void      feonumm4n5_integrate_r_to(    coeff_t num, feonumm4n5_t* w, onumm4n5_t* res);

onumm4n5_t feonumm4n5_integrate_o(    onumm4n5_t* num, feonumm4n5_t* w);
void      feonumm4n5_integrate_o_to( onumm4n5_t* num, feonumm4n5_t* w, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif