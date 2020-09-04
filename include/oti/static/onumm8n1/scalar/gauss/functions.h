#ifndef OTI_ONUMM8N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM8N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n1_t feonumm8n1_atanh(    feonumm8n1_t* num);
void     feonumm8n1_atanh_to( feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_asinh(    feonumm8n1_t* num);
void     feonumm8n1_asinh_to( feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_acosh(    feonumm8n1_t* num);
void     feonumm8n1_acosh_to( feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_tanh(     feonumm8n1_t* num);
void     feonumm8n1_tanh_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_cosh(     feonumm8n1_t* num);
void     feonumm8n1_cosh_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_sinh(     feonumm8n1_t* num);
void     feonumm8n1_sinh_to(  feonumm8n1_t* num, feonumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n1_t feonumm8n1_asin(     feonumm8n1_t* num);
void     feonumm8n1_asin_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_acos(     feonumm8n1_t* num);
void     feonumm8n1_acos_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_atan(     feonumm8n1_t* num);
void     feonumm8n1_atan_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_tan(      feonumm8n1_t* num);
void     feonumm8n1_tan_to(   feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_cos(      feonumm8n1_t* num);
void     feonumm8n1_cos_to(   feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_sin(      feonumm8n1_t* num);
void     feonumm8n1_sin_to(   feonumm8n1_t* num, feonumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n1_t feonumm8n1_logb(     feonumm8n1_t* num, double base);
void     feonumm8n1_logb_to(  feonumm8n1_t* num, double base, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_log10(    feonumm8n1_t* num);
void     feonumm8n1_log10_to( feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_log(      feonumm8n1_t* num);
void     feonumm8n1_log_to(   feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_exp(      feonumm8n1_t* num);
void     feonumm8n1_exp_to(   feonumm8n1_t* num, feonumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n1_t feonumm8n1_cbrt(     feonumm8n1_t* num);
void     feonumm8n1_cbrt_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_sqrt(     feonumm8n1_t* num);
void     feonumm8n1_sqrt_to(  feonumm8n1_t* num, feonumm8n1_t* res);

feonumm8n1_t feonumm8n1_pow(      feonumm8n1_t* num, double e);
void     feonumm8n1_pow_to(   feonumm8n1_t* num, double e, feonumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm8n1_t feonumm8n1_integrate(       feonumm8n1_t* num, feonumm8n1_t* w);
void      feonumm8n1_integrate_to(    feonumm8n1_t* num, feonumm8n1_t* w, onumm8n1_t* res);

onumm8n1_t feonumm8n1_integrate_f(     feonumm8n1_t* num, feonumm8n1_t* w);
void      feonumm8n1_integrate_f_to(  feonumm8n1_t* num, feonumm8n1_t* w, onumm8n1_t* res);

onumm8n1_t feonumm8n1_integrate_r(       coeff_t num, feonumm8n1_t* w);
void      feonumm8n1_integrate_r_to(    coeff_t num, feonumm8n1_t* w, onumm8n1_t* res);

onumm8n1_t feonumm8n1_integrate_o(    onumm8n1_t* num, feonumm8n1_t* w);
void      feonumm8n1_integrate_o_to( onumm8n1_t* num, feonumm8n1_t* w, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif