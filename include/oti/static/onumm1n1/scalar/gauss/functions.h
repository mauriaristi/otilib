#ifndef OTI_ONUMM1N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n1_t feonumm1n1_atanh(    feonumm1n1_t* num);
void     feonumm1n1_atanh_to( feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_asinh(    feonumm1n1_t* num);
void     feonumm1n1_asinh_to( feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_acosh(    feonumm1n1_t* num);
void     feonumm1n1_acosh_to( feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_tanh(     feonumm1n1_t* num);
void     feonumm1n1_tanh_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_cosh(     feonumm1n1_t* num);
void     feonumm1n1_cosh_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_sinh(     feonumm1n1_t* num);
void     feonumm1n1_sinh_to(  feonumm1n1_t* num, feonumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n1_t feonumm1n1_asin(     feonumm1n1_t* num);
void     feonumm1n1_asin_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_acos(     feonumm1n1_t* num);
void     feonumm1n1_acos_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_atan(     feonumm1n1_t* num);
void     feonumm1n1_atan_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_tan(      feonumm1n1_t* num);
void     feonumm1n1_tan_to(   feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_cos(      feonumm1n1_t* num);
void     feonumm1n1_cos_to(   feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_sin(      feonumm1n1_t* num);
void     feonumm1n1_sin_to(   feonumm1n1_t* num, feonumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n1_t feonumm1n1_logb(     feonumm1n1_t* num, double base);
void     feonumm1n1_logb_to(  feonumm1n1_t* num, double base, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_log10(    feonumm1n1_t* num);
void     feonumm1n1_log10_to( feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_log(      feonumm1n1_t* num);
void     feonumm1n1_log_to(   feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_exp(      feonumm1n1_t* num);
void     feonumm1n1_exp_to(   feonumm1n1_t* num, feonumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n1_t feonumm1n1_cbrt(     feonumm1n1_t* num);
void     feonumm1n1_cbrt_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_sqrt(     feonumm1n1_t* num);
void     feonumm1n1_sqrt_to(  feonumm1n1_t* num, feonumm1n1_t* res);

feonumm1n1_t feonumm1n1_pow(      feonumm1n1_t* num, double e);
void     feonumm1n1_pow_to(   feonumm1n1_t* num, double e, feonumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n1_t feonumm1n1_integrate(       feonumm1n1_t* num, feonumm1n1_t* w);
void      feonumm1n1_integrate_to(    feonumm1n1_t* num, feonumm1n1_t* w, onumm1n1_t* res);

onumm1n1_t feonumm1n1_integrate_f(     feonumm1n1_t* num, feonumm1n1_t* w);
void      feonumm1n1_integrate_f_to(  feonumm1n1_t* num, feonumm1n1_t* w, onumm1n1_t* res);

onumm1n1_t feonumm1n1_integrate_r(       coeff_t num, feonumm1n1_t* w);
void      feonumm1n1_integrate_r_to(    coeff_t num, feonumm1n1_t* w, onumm1n1_t* res);

onumm1n1_t feonumm1n1_integrate_o(    onumm1n1_t* num, feonumm1n1_t* w);
void      feonumm1n1_integrate_o_to( onumm1n1_t* num, feonumm1n1_t* w, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif