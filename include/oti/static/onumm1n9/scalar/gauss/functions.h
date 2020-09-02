#ifndef OTI_ONUMM1N9_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N9_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n9_t feonumm1n9_atanh(    feonumm1n9_t* num);
void     feonumm1n9_atanh_to( feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_asinh(    feonumm1n9_t* num);
void     feonumm1n9_asinh_to( feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_acosh(    feonumm1n9_t* num);
void     feonumm1n9_acosh_to( feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_tanh(     feonumm1n9_t* num);
void     feonumm1n9_tanh_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_cosh(     feonumm1n9_t* num);
void     feonumm1n9_cosh_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_sinh(     feonumm1n9_t* num);
void     feonumm1n9_sinh_to(  feonumm1n9_t* num, feonumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n9_t feonumm1n9_asin(     feonumm1n9_t* num);
void     feonumm1n9_asin_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_acos(     feonumm1n9_t* num);
void     feonumm1n9_acos_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_atan(     feonumm1n9_t* num);
void     feonumm1n9_atan_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_tan(      feonumm1n9_t* num);
void     feonumm1n9_tan_to(   feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_cos(      feonumm1n9_t* num);
void     feonumm1n9_cos_to(   feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_sin(      feonumm1n9_t* num);
void     feonumm1n9_sin_to(   feonumm1n9_t* num, feonumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n9_t feonumm1n9_logb(     feonumm1n9_t* num, double base);
void     feonumm1n9_logb_to(  feonumm1n9_t* num, double base, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_log10(    feonumm1n9_t* num);
void     feonumm1n9_log10_to( feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_log(      feonumm1n9_t* num);
void     feonumm1n9_log_to(   feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_exp(      feonumm1n9_t* num);
void     feonumm1n9_exp_to(   feonumm1n9_t* num, feonumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n9_t feonumm1n9_cbrt(     feonumm1n9_t* num);
void     feonumm1n9_cbrt_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_sqrt(     feonumm1n9_t* num);
void     feonumm1n9_sqrt_to(  feonumm1n9_t* num, feonumm1n9_t* res);

feonumm1n9_t feonumm1n9_pow(      feonumm1n9_t* num, double e);
void     feonumm1n9_pow_to(   feonumm1n9_t* num, double e, feonumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n9_t feonumm1n9_integrate(       feonumm1n9_t* num, feonumm1n9_t* w);
void      feonumm1n9_integrate_to(    feonumm1n9_t* num, feonumm1n9_t* w, onumm1n9_t* res);

onumm1n9_t feonumm1n9_integrate_f(     feonumm1n9_t* num, feonumm1n9_t* w);
void      feonumm1n9_integrate_f_to(  feonumm1n9_t* num, feonumm1n9_t* w, onumm1n9_t* res);

onumm1n9_t feonumm1n9_integrate_r(       coeff_t num, feonumm1n9_t* w);
void      feonumm1n9_integrate_r_to(    coeff_t num, feonumm1n9_t* w, onumm1n9_t* res);

onumm1n9_t feonumm1n9_integrate_o(    onumm1n9_t* num, feonumm1n9_t* w);
void      feonumm1n9_integrate_o_to( onumm1n9_t* num, feonumm1n9_t* w, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif