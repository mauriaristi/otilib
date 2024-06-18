#ifndef OTI_ONUMM1N3_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N3_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n3_t feonumm1n3_atanh(    feonumm1n3_t* num);
void     feonumm1n3_atanh_to( feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_asinh(    feonumm1n3_t* num);
void     feonumm1n3_asinh_to( feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_acosh(    feonumm1n3_t* num);
void     feonumm1n3_acosh_to( feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_tanh(     feonumm1n3_t* num);
void     feonumm1n3_tanh_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_cosh(     feonumm1n3_t* num);
void     feonumm1n3_cosh_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_sinh(     feonumm1n3_t* num);
void     feonumm1n3_sinh_to(  feonumm1n3_t* num, feonumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n3_t feonumm1n3_asin(     feonumm1n3_t* num);
void     feonumm1n3_asin_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_acos(     feonumm1n3_t* num);
void     feonumm1n3_acos_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_atan(     feonumm1n3_t* num);
void     feonumm1n3_atan_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_tan(      feonumm1n3_t* num);
void     feonumm1n3_tan_to(   feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_cos(      feonumm1n3_t* num);
void     feonumm1n3_cos_to(   feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_sin(      feonumm1n3_t* num);
void     feonumm1n3_sin_to(   feonumm1n3_t* num, feonumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n3_t feonumm1n3_logb(     feonumm1n3_t* num, double base);
void     feonumm1n3_logb_to(  feonumm1n3_t* num, double base, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_log10(    feonumm1n3_t* num);
void     feonumm1n3_log10_to( feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_log(      feonumm1n3_t* num);
void     feonumm1n3_log_to(   feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_exp(      feonumm1n3_t* num);
void     feonumm1n3_exp_to(   feonumm1n3_t* num, feonumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n3_t feonumm1n3_cbrt(     feonumm1n3_t* num);
void     feonumm1n3_cbrt_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_sqrt(     feonumm1n3_t* num);
void     feonumm1n3_sqrt_to(  feonumm1n3_t* num, feonumm1n3_t* res);

feonumm1n3_t feonumm1n3_pow(      feonumm1n3_t* num, double e);
void     feonumm1n3_pow_to(   feonumm1n3_t* num, double e, feonumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm1n3_t feonumm1n3_integrate(       feonumm1n3_t* num, feonumm1n3_t* w);
void      feonumm1n3_integrate_to(    feonumm1n3_t* num, feonumm1n3_t* w, onumm1n3_t* res);

onumm1n3_t feonumm1n3_integrate_f(     feonumm1n3_t* num, feonumm1n3_t* w);
void      feonumm1n3_integrate_f_to(  feonumm1n3_t* num, feonumm1n3_t* w, onumm1n3_t* res);

onumm1n3_t feonumm1n3_integrate_r(       coeff_t num, feonumm1n3_t* w);
void      feonumm1n3_integrate_r_to(    coeff_t num, feonumm1n3_t* w, onumm1n3_t* res);

onumm1n3_t feonumm1n3_integrate_o(    onumm1n3_t* num, feonumm1n3_t* w);
void      feonumm1n3_integrate_o_to( onumm1n3_t* num, feonumm1n3_t* w, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif