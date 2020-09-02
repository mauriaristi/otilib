#ifndef OTI_ONUMM1N6_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N6_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n6_t feonumm1n6_atanh(    feonumm1n6_t* num);
void     feonumm1n6_atanh_to( feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_asinh(    feonumm1n6_t* num);
void     feonumm1n6_asinh_to( feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_acosh(    feonumm1n6_t* num);
void     feonumm1n6_acosh_to( feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_tanh(     feonumm1n6_t* num);
void     feonumm1n6_tanh_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_cosh(     feonumm1n6_t* num);
void     feonumm1n6_cosh_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_sinh(     feonumm1n6_t* num);
void     feonumm1n6_sinh_to(  feonumm1n6_t* num, feonumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n6_t feonumm1n6_asin(     feonumm1n6_t* num);
void     feonumm1n6_asin_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_acos(     feonumm1n6_t* num);
void     feonumm1n6_acos_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_atan(     feonumm1n6_t* num);
void     feonumm1n6_atan_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_tan(      feonumm1n6_t* num);
void     feonumm1n6_tan_to(   feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_cos(      feonumm1n6_t* num);
void     feonumm1n6_cos_to(   feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_sin(      feonumm1n6_t* num);
void     feonumm1n6_sin_to(   feonumm1n6_t* num, feonumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n6_t feonumm1n6_logb(     feonumm1n6_t* num, double base);
void     feonumm1n6_logb_to(  feonumm1n6_t* num, double base, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_log10(    feonumm1n6_t* num);
void     feonumm1n6_log10_to( feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_log(      feonumm1n6_t* num);
void     feonumm1n6_log_to(   feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_exp(      feonumm1n6_t* num);
void     feonumm1n6_exp_to(   feonumm1n6_t* num, feonumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n6_t feonumm1n6_cbrt(     feonumm1n6_t* num);
void     feonumm1n6_cbrt_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_sqrt(     feonumm1n6_t* num);
void     feonumm1n6_sqrt_to(  feonumm1n6_t* num, feonumm1n6_t* res);

feonumm1n6_t feonumm1n6_pow(      feonumm1n6_t* num, double e);
void     feonumm1n6_pow_to(   feonumm1n6_t* num, double e, feonumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n6_t feonumm1n6_integrate(       feonumm1n6_t* num, feonumm1n6_t* w);
void      feonumm1n6_integrate_to(    feonumm1n6_t* num, feonumm1n6_t* w, onumm1n6_t* res);

onumm1n6_t feonumm1n6_integrate_f(     feonumm1n6_t* num, feonumm1n6_t* w);
void      feonumm1n6_integrate_f_to(  feonumm1n6_t* num, feonumm1n6_t* w, onumm1n6_t* res);

onumm1n6_t feonumm1n6_integrate_r(       coeff_t num, feonumm1n6_t* w);
void      feonumm1n6_integrate_r_to(    coeff_t num, feonumm1n6_t* w, onumm1n6_t* res);

onumm1n6_t feonumm1n6_integrate_o(    onumm1n6_t* num, feonumm1n6_t* w);
void      feonumm1n6_integrate_o_to( onumm1n6_t* num, feonumm1n6_t* w, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif