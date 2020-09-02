#ifndef OTI_ONUMM2N10_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N10_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_atanh(    feonumm2n10_t* num);
void     feonumm2n10_atanh_to( feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_asinh(    feonumm2n10_t* num);
void     feonumm2n10_asinh_to( feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_acosh(    feonumm2n10_t* num);
void     feonumm2n10_acosh_to( feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_tanh(     feonumm2n10_t* num);
void     feonumm2n10_tanh_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_cosh(     feonumm2n10_t* num);
void     feonumm2n10_cosh_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sinh(     feonumm2n10_t* num);
void     feonumm2n10_sinh_to(  feonumm2n10_t* num, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_asin(     feonumm2n10_t* num);
void     feonumm2n10_asin_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_acos(     feonumm2n10_t* num);
void     feonumm2n10_acos_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_atan(     feonumm2n10_t* num);
void     feonumm2n10_atan_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_tan(      feonumm2n10_t* num);
void     feonumm2n10_tan_to(   feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_cos(      feonumm2n10_t* num);
void     feonumm2n10_cos_to(   feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sin(      feonumm2n10_t* num);
void     feonumm2n10_sin_to(   feonumm2n10_t* num, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_logb(     feonumm2n10_t* num, double base);
void     feonumm2n10_logb_to(  feonumm2n10_t* num, double base, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_log10(    feonumm2n10_t* num);
void     feonumm2n10_log10_to( feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_log(      feonumm2n10_t* num);
void     feonumm2n10_log_to(   feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_exp(      feonumm2n10_t* num);
void     feonumm2n10_exp_to(   feonumm2n10_t* num, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_cbrt(     feonumm2n10_t* num);
void     feonumm2n10_cbrt_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sqrt(     feonumm2n10_t* num);
void     feonumm2n10_sqrt_to(  feonumm2n10_t* num, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_pow(      feonumm2n10_t* num, double e);
void     feonumm2n10_pow_to(   feonumm2n10_t* num, double e, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n10_t feonumm2n10_integrate(       feonumm2n10_t* num, feonumm2n10_t* w);
void      feonumm2n10_integrate_to(    feonumm2n10_t* num, feonumm2n10_t* w, onumm2n10_t* res);

onumm2n10_t feonumm2n10_integrate_f(     feonumm2n10_t* num, feonumm2n10_t* w);
void      feonumm2n10_integrate_f_to(  feonumm2n10_t* num, feonumm2n10_t* w, onumm2n10_t* res);

onumm2n10_t feonumm2n10_integrate_r(       coeff_t num, feonumm2n10_t* w);
void      feonumm2n10_integrate_r_to(    coeff_t num, feonumm2n10_t* w, onumm2n10_t* res);

onumm2n10_t feonumm2n10_integrate_o(    onumm2n10_t* num, feonumm2n10_t* w);
void      feonumm2n10_integrate_o_to( onumm2n10_t* num, feonumm2n10_t* w, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif