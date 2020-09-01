#ifndef OTI_ONUMM3N5_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N5_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n5_t feonumm3n5_atanh(    feonumm3n5_t* num);
void     feonumm3n5_atanh_to( feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_asinh(    feonumm3n5_t* num);
void     feonumm3n5_asinh_to( feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_acosh(    feonumm3n5_t* num);
void     feonumm3n5_acosh_to( feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_tanh(     feonumm3n5_t* num);
void     feonumm3n5_tanh_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_cosh(     feonumm3n5_t* num);
void     feonumm3n5_cosh_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_sinh(     feonumm3n5_t* num);
void     feonumm3n5_sinh_to(  feonumm3n5_t* num, feonumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n5_t feonumm3n5_asin(     feonumm3n5_t* num);
void     feonumm3n5_asin_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_acos(     feonumm3n5_t* num);
void     feonumm3n5_acos_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_atan(     feonumm3n5_t* num);
void     feonumm3n5_atan_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_tan(      feonumm3n5_t* num);
void     feonumm3n5_tan_to(   feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_cos(      feonumm3n5_t* num);
void     feonumm3n5_cos_to(   feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_sin(      feonumm3n5_t* num);
void     feonumm3n5_sin_to(   feonumm3n5_t* num, feonumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n5_t feonumm3n5_logb(     feonumm3n5_t* num, double base);
void     feonumm3n5_logb_to(  feonumm3n5_t* num, double base, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_log10(    feonumm3n5_t* num);
void     feonumm3n5_log10_to( feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_log(      feonumm3n5_t* num);
void     feonumm3n5_log_to(   feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_exp(      feonumm3n5_t* num);
void     feonumm3n5_exp_to(   feonumm3n5_t* num, feonumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n5_t feonumm3n5_cbrt(     feonumm3n5_t* num);
void     feonumm3n5_cbrt_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_sqrt(     feonumm3n5_t* num);
void     feonumm3n5_sqrt_to(  feonumm3n5_t* num, feonumm3n5_t* res);

feonumm3n5_t feonumm3n5_pow(      feonumm3n5_t* num, double e);
void     feonumm3n5_pow_to(   feonumm3n5_t* num, double e, feonumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm3n5_t feonumm3n5_integrate(       feonumm3n5_t* num, feonumm3n5_t* w);
void      feonumm3n5_integrate_to(    feonumm3n5_t* num, feonumm3n5_t* w, onumm3n5_t* res);

onumm3n5_t feonumm3n5_integrate_f(     feonumm3n5_t* num, feonumm3n5_t* w);
void      feonumm3n5_integrate_f_to(  feonumm3n5_t* num, feonumm3n5_t* w, onumm3n5_t* res);

onumm3n5_t feonumm3n5_integrate_r(       coeff_t num, feonumm3n5_t* w);
void      feonumm3n5_integrate_r_to(    coeff_t num, feonumm3n5_t* w, onumm3n5_t* res);

onumm3n5_t feonumm3n5_integrate_o(    onumm3n5_t* num, feonumm3n5_t* w);
void      feonumm3n5_integrate_o_to( onumm3n5_t* num, feonumm3n5_t* w, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif