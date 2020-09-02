#ifndef OTI_ONUMM1N7_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N7_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n7_t feonumm1n7_atanh(    feonumm1n7_t* num);
void     feonumm1n7_atanh_to( feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_asinh(    feonumm1n7_t* num);
void     feonumm1n7_asinh_to( feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_acosh(    feonumm1n7_t* num);
void     feonumm1n7_acosh_to( feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_tanh(     feonumm1n7_t* num);
void     feonumm1n7_tanh_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_cosh(     feonumm1n7_t* num);
void     feonumm1n7_cosh_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_sinh(     feonumm1n7_t* num);
void     feonumm1n7_sinh_to(  feonumm1n7_t* num, feonumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n7_t feonumm1n7_asin(     feonumm1n7_t* num);
void     feonumm1n7_asin_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_acos(     feonumm1n7_t* num);
void     feonumm1n7_acos_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_atan(     feonumm1n7_t* num);
void     feonumm1n7_atan_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_tan(      feonumm1n7_t* num);
void     feonumm1n7_tan_to(   feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_cos(      feonumm1n7_t* num);
void     feonumm1n7_cos_to(   feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_sin(      feonumm1n7_t* num);
void     feonumm1n7_sin_to(   feonumm1n7_t* num, feonumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n7_t feonumm1n7_logb(     feonumm1n7_t* num, double base);
void     feonumm1n7_logb_to(  feonumm1n7_t* num, double base, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_log10(    feonumm1n7_t* num);
void     feonumm1n7_log10_to( feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_log(      feonumm1n7_t* num);
void     feonumm1n7_log_to(   feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_exp(      feonumm1n7_t* num);
void     feonumm1n7_exp_to(   feonumm1n7_t* num, feonumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n7_t feonumm1n7_cbrt(     feonumm1n7_t* num);
void     feonumm1n7_cbrt_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_sqrt(     feonumm1n7_t* num);
void     feonumm1n7_sqrt_to(  feonumm1n7_t* num, feonumm1n7_t* res);

feonumm1n7_t feonumm1n7_pow(      feonumm1n7_t* num, double e);
void     feonumm1n7_pow_to(   feonumm1n7_t* num, double e, feonumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n7_t feonumm1n7_integrate(       feonumm1n7_t* num, feonumm1n7_t* w);
void      feonumm1n7_integrate_to(    feonumm1n7_t* num, feonumm1n7_t* w, onumm1n7_t* res);

onumm1n7_t feonumm1n7_integrate_f(     feonumm1n7_t* num, feonumm1n7_t* w);
void      feonumm1n7_integrate_f_to(  feonumm1n7_t* num, feonumm1n7_t* w, onumm1n7_t* res);

onumm1n7_t feonumm1n7_integrate_r(       coeff_t num, feonumm1n7_t* w);
void      feonumm1n7_integrate_r_to(    coeff_t num, feonumm1n7_t* w, onumm1n7_t* res);

onumm1n7_t feonumm1n7_integrate_o(    onumm1n7_t* num, feonumm1n7_t* w);
void      feonumm1n7_integrate_o_to( onumm1n7_t* num, feonumm1n7_t* w, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif