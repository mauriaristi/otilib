#ifndef OTI_ONUMM1N20_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N20_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n20_t feonumm1n20_atanh(    feonumm1n20_t* num);
void     feonumm1n20_atanh_to( feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_asinh(    feonumm1n20_t* num);
void     feonumm1n20_asinh_to( feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_acosh(    feonumm1n20_t* num);
void     feonumm1n20_acosh_to( feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_tanh(     feonumm1n20_t* num);
void     feonumm1n20_tanh_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_cosh(     feonumm1n20_t* num);
void     feonumm1n20_cosh_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_sinh(     feonumm1n20_t* num);
void     feonumm1n20_sinh_to(  feonumm1n20_t* num, feonumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n20_t feonumm1n20_asin(     feonumm1n20_t* num);
void     feonumm1n20_asin_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_acos(     feonumm1n20_t* num);
void     feonumm1n20_acos_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_atan(     feonumm1n20_t* num);
void     feonumm1n20_atan_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_tan(      feonumm1n20_t* num);
void     feonumm1n20_tan_to(   feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_cos(      feonumm1n20_t* num);
void     feonumm1n20_cos_to(   feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_sin(      feonumm1n20_t* num);
void     feonumm1n20_sin_to(   feonumm1n20_t* num, feonumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n20_t feonumm1n20_logb(     feonumm1n20_t* num, double base);
void     feonumm1n20_logb_to(  feonumm1n20_t* num, double base, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_log10(    feonumm1n20_t* num);
void     feonumm1n20_log10_to( feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_log(      feonumm1n20_t* num);
void     feonumm1n20_log_to(   feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_exp(      feonumm1n20_t* num);
void     feonumm1n20_exp_to(   feonumm1n20_t* num, feonumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n20_t feonumm1n20_cbrt(     feonumm1n20_t* num);
void     feonumm1n20_cbrt_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_sqrt(     feonumm1n20_t* num);
void     feonumm1n20_sqrt_to(  feonumm1n20_t* num, feonumm1n20_t* res);

feonumm1n20_t feonumm1n20_pow(      feonumm1n20_t* num, double e);
void     feonumm1n20_pow_to(   feonumm1n20_t* num, double e, feonumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n20_t feonumm1n20_integrate(       feonumm1n20_t* num, feonumm1n20_t* w);
void      feonumm1n20_integrate_to(    feonumm1n20_t* num, feonumm1n20_t* w, onumm1n20_t* res);

onumm1n20_t feonumm1n20_integrate_f(     feonumm1n20_t* num, feonumm1n20_t* w);
void      feonumm1n20_integrate_f_to(  feonumm1n20_t* num, feonumm1n20_t* w, onumm1n20_t* res);

onumm1n20_t feonumm1n20_integrate_r(       coeff_t num, feonumm1n20_t* w);
void      feonumm1n20_integrate_r_to(    coeff_t num, feonumm1n20_t* w, onumm1n20_t* res);

onumm1n20_t feonumm1n20_integrate_o(    onumm1n20_t* num, feonumm1n20_t* w);
void      feonumm1n20_integrate_o_to( onumm1n20_t* num, feonumm1n20_t* w, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

#endif