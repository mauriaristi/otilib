#ifndef OTI_ONUMM2N4_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N4_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_atanh(    feonumm2n4_t* num);
void     feonumm2n4_atanh_to( feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_asinh(    feonumm2n4_t* num);
void     feonumm2n4_asinh_to( feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_acosh(    feonumm2n4_t* num);
void     feonumm2n4_acosh_to( feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_tanh(     feonumm2n4_t* num);
void     feonumm2n4_tanh_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_cosh(     feonumm2n4_t* num);
void     feonumm2n4_cosh_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sinh(     feonumm2n4_t* num);
void     feonumm2n4_sinh_to(  feonumm2n4_t* num, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_asin(     feonumm2n4_t* num);
void     feonumm2n4_asin_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_acos(     feonumm2n4_t* num);
void     feonumm2n4_acos_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_atan(     feonumm2n4_t* num);
void     feonumm2n4_atan_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_tan(      feonumm2n4_t* num);
void     feonumm2n4_tan_to(   feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_cos(      feonumm2n4_t* num);
void     feonumm2n4_cos_to(   feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sin(      feonumm2n4_t* num);
void     feonumm2n4_sin_to(   feonumm2n4_t* num, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_logb(     feonumm2n4_t* num, double base);
void     feonumm2n4_logb_to(  feonumm2n4_t* num, double base, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_log10(    feonumm2n4_t* num);
void     feonumm2n4_log10_to( feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_log(      feonumm2n4_t* num);
void     feonumm2n4_log_to(   feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_exp(      feonumm2n4_t* num);
void     feonumm2n4_exp_to(   feonumm2n4_t* num, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_cbrt(     feonumm2n4_t* num);
void     feonumm2n4_cbrt_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sqrt(     feonumm2n4_t* num);
void     feonumm2n4_sqrt_to(  feonumm2n4_t* num, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_pow(      feonumm2n4_t* num, double e);
void     feonumm2n4_pow_to(   feonumm2n4_t* num, double e, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n4_t feonumm2n4_integrate(       feonumm2n4_t* num, feonumm2n4_t* w);
void      feonumm2n4_integrate_to(    feonumm2n4_t* num, feonumm2n4_t* w, onumm2n4_t* res);

onumm2n4_t feonumm2n4_integrate_f(     feonumm2n4_t* num, feonumm2n4_t* w);
void      feonumm2n4_integrate_f_to(  feonumm2n4_t* num, feonumm2n4_t* w, onumm2n4_t* res);

onumm2n4_t feonumm2n4_integrate_r(       coeff_t num, feonumm2n4_t* w);
void      feonumm2n4_integrate_r_to(    coeff_t num, feonumm2n4_t* w, onumm2n4_t* res);

onumm2n4_t feonumm2n4_integrate_o(    onumm2n4_t* num, feonumm2n4_t* w);
void      feonumm2n4_integrate_o_to( onumm2n4_t* num, feonumm2n4_t* w, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif