#ifndef OTI_ONUMM2N8_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N8_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n8_t feonumm2n8_atanh(    feonumm2n8_t* num);
void     feonumm2n8_atanh_to( feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_asinh(    feonumm2n8_t* num);
void     feonumm2n8_asinh_to( feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_acosh(    feonumm2n8_t* num);
void     feonumm2n8_acosh_to( feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_tanh(     feonumm2n8_t* num);
void     feonumm2n8_tanh_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_cosh(     feonumm2n8_t* num);
void     feonumm2n8_cosh_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_sinh(     feonumm2n8_t* num);
void     feonumm2n8_sinh_to(  feonumm2n8_t* num, feonumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n8_t feonumm2n8_asin(     feonumm2n8_t* num);
void     feonumm2n8_asin_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_acos(     feonumm2n8_t* num);
void     feonumm2n8_acos_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_atan(     feonumm2n8_t* num);
void     feonumm2n8_atan_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_tan(      feonumm2n8_t* num);
void     feonumm2n8_tan_to(   feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_cos(      feonumm2n8_t* num);
void     feonumm2n8_cos_to(   feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_sin(      feonumm2n8_t* num);
void     feonumm2n8_sin_to(   feonumm2n8_t* num, feonumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n8_t feonumm2n8_logb(     feonumm2n8_t* num, double base);
void     feonumm2n8_logb_to(  feonumm2n8_t* num, double base, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_log10(    feonumm2n8_t* num);
void     feonumm2n8_log10_to( feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_log(      feonumm2n8_t* num);
void     feonumm2n8_log_to(   feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_exp(      feonumm2n8_t* num);
void     feonumm2n8_exp_to(   feonumm2n8_t* num, feonumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n8_t feonumm2n8_cbrt(     feonumm2n8_t* num);
void     feonumm2n8_cbrt_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_sqrt(     feonumm2n8_t* num);
void     feonumm2n8_sqrt_to(  feonumm2n8_t* num, feonumm2n8_t* res);

feonumm2n8_t feonumm2n8_pow(      feonumm2n8_t* num, double e);
void     feonumm2n8_pow_to(   feonumm2n8_t* num, double e, feonumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n8_t feonumm2n8_integrate(       feonumm2n8_t* num, feonumm2n8_t* w);
void      feonumm2n8_integrate_to(    feonumm2n8_t* num, feonumm2n8_t* w, onumm2n8_t* res);

onumm2n8_t feonumm2n8_integrate_f(     feonumm2n8_t* num, feonumm2n8_t* w);
void      feonumm2n8_integrate_f_to(  feonumm2n8_t* num, feonumm2n8_t* w, onumm2n8_t* res);

onumm2n8_t feonumm2n8_integrate_r(       coeff_t num, feonumm2n8_t* w);
void      feonumm2n8_integrate_r_to(    coeff_t num, feonumm2n8_t* w, onumm2n8_t* res);

onumm2n8_t feonumm2n8_integrate_o(    onumm2n8_t* num, feonumm2n8_t* w);
void      feonumm2n8_integrate_o_to( onumm2n8_t* num, feonumm2n8_t* w, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif