#ifndef OTI_ONUMM3N4_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N4_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_atanh(    feonumm3n4_t* num);
void     feonumm3n4_atanh_to( feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_asinh(    feonumm3n4_t* num);
void     feonumm3n4_asinh_to( feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_acosh(    feonumm3n4_t* num);
void     feonumm3n4_acosh_to( feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_tanh(     feonumm3n4_t* num);
void     feonumm3n4_tanh_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_cosh(     feonumm3n4_t* num);
void     feonumm3n4_cosh_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sinh(     feonumm3n4_t* num);
void     feonumm3n4_sinh_to(  feonumm3n4_t* num, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_asin(     feonumm3n4_t* num);
void     feonumm3n4_asin_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_acos(     feonumm3n4_t* num);
void     feonumm3n4_acos_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_atan(     feonumm3n4_t* num);
void     feonumm3n4_atan_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_tan(      feonumm3n4_t* num);
void     feonumm3n4_tan_to(   feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_cos(      feonumm3n4_t* num);
void     feonumm3n4_cos_to(   feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sin(      feonumm3n4_t* num);
void     feonumm3n4_sin_to(   feonumm3n4_t* num, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_logb(     feonumm3n4_t* num, double base);
void     feonumm3n4_logb_to(  feonumm3n4_t* num, double base, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_log10(    feonumm3n4_t* num);
void     feonumm3n4_log10_to( feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_log(      feonumm3n4_t* num);
void     feonumm3n4_log_to(   feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_exp(      feonumm3n4_t* num);
void     feonumm3n4_exp_to(   feonumm3n4_t* num, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_cbrt(     feonumm3n4_t* num);
void     feonumm3n4_cbrt_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sqrt(     feonumm3n4_t* num);
void     feonumm3n4_sqrt_to(  feonumm3n4_t* num, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_pow(      feonumm3n4_t* num, double e);
void     feonumm3n4_pow_to(   feonumm3n4_t* num, double e, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm3n4_t feonumm3n4_integrate(       feonumm3n4_t* num, feonumm3n4_t* w);
void      feonumm3n4_integrate_to(    feonumm3n4_t* num, feonumm3n4_t* w, onumm3n4_t* res);

onumm3n4_t feonumm3n4_integrate_f(     feonumm3n4_t* num, feonumm3n4_t* w);
void      feonumm3n4_integrate_f_to(  feonumm3n4_t* num, feonumm3n4_t* w, onumm3n4_t* res);

onumm3n4_t feonumm3n4_integrate_r(       coeff_t num, feonumm3n4_t* w);
void      feonumm3n4_integrate_r_to(    coeff_t num, feonumm3n4_t* w, onumm3n4_t* res);

onumm3n4_t feonumm3n4_integrate_o(    onumm3n4_t* num, feonumm3n4_t* w);
void      feonumm3n4_integrate_o_to( onumm3n4_t* num, feonumm3n4_t* w, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif