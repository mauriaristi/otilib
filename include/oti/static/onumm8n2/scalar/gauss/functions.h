#ifndef OTI_ONUMM8N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM8N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_atanh(    feonumm8n2_t* num);
void     feonumm8n2_atanh_to( feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_asinh(    feonumm8n2_t* num);
void     feonumm8n2_asinh_to( feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_acosh(    feonumm8n2_t* num);
void     feonumm8n2_acosh_to( feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_tanh(     feonumm8n2_t* num);
void     feonumm8n2_tanh_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_cosh(     feonumm8n2_t* num);
void     feonumm8n2_cosh_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sinh(     feonumm8n2_t* num);
void     feonumm8n2_sinh_to(  feonumm8n2_t* num, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_asin(     feonumm8n2_t* num);
void     feonumm8n2_asin_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_acos(     feonumm8n2_t* num);
void     feonumm8n2_acos_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_atan(     feonumm8n2_t* num);
void     feonumm8n2_atan_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_tan(      feonumm8n2_t* num);
void     feonumm8n2_tan_to(   feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_cos(      feonumm8n2_t* num);
void     feonumm8n2_cos_to(   feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sin(      feonumm8n2_t* num);
void     feonumm8n2_sin_to(   feonumm8n2_t* num, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_logb(     feonumm8n2_t* num, double base);
void     feonumm8n2_logb_to(  feonumm8n2_t* num, double base, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_log10(    feonumm8n2_t* num);
void     feonumm8n2_log10_to( feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_log(      feonumm8n2_t* num);
void     feonumm8n2_log_to(   feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_exp(      feonumm8n2_t* num);
void     feonumm8n2_exp_to(   feonumm8n2_t* num, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_cbrt(     feonumm8n2_t* num);
void     feonumm8n2_cbrt_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sqrt(     feonumm8n2_t* num);
void     feonumm8n2_sqrt_to(  feonumm8n2_t* num, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_pow(      feonumm8n2_t* num, double e);
void     feonumm8n2_pow_to(   feonumm8n2_t* num, double e, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm8n2_t feonumm8n2_integrate(       feonumm8n2_t* num, feonumm8n2_t* w);
void      feonumm8n2_integrate_to(    feonumm8n2_t* num, feonumm8n2_t* w, onumm8n2_t* res);

onumm8n2_t feonumm8n2_integrate_f(     feonumm8n2_t* num, feonumm8n2_t* w);
void      feonumm8n2_integrate_f_to(  feonumm8n2_t* num, feonumm8n2_t* w, onumm8n2_t* res);

onumm8n2_t feonumm8n2_integrate_r(       coeff_t num, feonumm8n2_t* w);
void      feonumm8n2_integrate_r_to(    coeff_t num, feonumm8n2_t* w, onumm8n2_t* res);

onumm8n2_t feonumm8n2_integrate_o(    onumm8n2_t* num, feonumm8n2_t* w);
void      feonumm8n2_integrate_o_to( onumm8n2_t* num, feonumm8n2_t* w, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif