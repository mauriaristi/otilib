#ifndef OTI_ONUMM10N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM10N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n1_t feonumm10n1_atanh(    feonumm10n1_t* num);
void     feonumm10n1_atanh_to( feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_asinh(    feonumm10n1_t* num);
void     feonumm10n1_asinh_to( feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_acosh(    feonumm10n1_t* num);
void     feonumm10n1_acosh_to( feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_tanh(     feonumm10n1_t* num);
void     feonumm10n1_tanh_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_cosh(     feonumm10n1_t* num);
void     feonumm10n1_cosh_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_sinh(     feonumm10n1_t* num);
void     feonumm10n1_sinh_to(  feonumm10n1_t* num, feonumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n1_t feonumm10n1_asin(     feonumm10n1_t* num);
void     feonumm10n1_asin_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_acos(     feonumm10n1_t* num);
void     feonumm10n1_acos_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_atan(     feonumm10n1_t* num);
void     feonumm10n1_atan_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_tan(      feonumm10n1_t* num);
void     feonumm10n1_tan_to(   feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_cos(      feonumm10n1_t* num);
void     feonumm10n1_cos_to(   feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_sin(      feonumm10n1_t* num);
void     feonumm10n1_sin_to(   feonumm10n1_t* num, feonumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n1_t feonumm10n1_logb(     feonumm10n1_t* num, double base);
void     feonumm10n1_logb_to(  feonumm10n1_t* num, double base, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_log10(    feonumm10n1_t* num);
void     feonumm10n1_log10_to( feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_log(      feonumm10n1_t* num);
void     feonumm10n1_log_to(   feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_exp(      feonumm10n1_t* num);
void     feonumm10n1_exp_to(   feonumm10n1_t* num, feonumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n1_t feonumm10n1_cbrt(     feonumm10n1_t* num);
void     feonumm10n1_cbrt_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_sqrt(     feonumm10n1_t* num);
void     feonumm10n1_sqrt_to(  feonumm10n1_t* num, feonumm10n1_t* res);

feonumm10n1_t feonumm10n1_pow(      feonumm10n1_t* num, double e);
void     feonumm10n1_pow_to(   feonumm10n1_t* num, double e, feonumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm10n1_t feonumm10n1_integrate(       feonumm10n1_t* num, feonumm10n1_t* w);
void      feonumm10n1_integrate_to(    feonumm10n1_t* num, feonumm10n1_t* w, onumm10n1_t* res);

onumm10n1_t feonumm10n1_integrate_f(     feonumm10n1_t* num, feonumm10n1_t* w);
void      feonumm10n1_integrate_f_to(  feonumm10n1_t* num, feonumm10n1_t* w, onumm10n1_t* res);

onumm10n1_t feonumm10n1_integrate_r(       coeff_t num, feonumm10n1_t* w);
void      feonumm10n1_integrate_r_to(    coeff_t num, feonumm10n1_t* w, onumm10n1_t* res);

onumm10n1_t feonumm10n1_integrate_o(    onumm10n1_t* num, feonumm10n1_t* w);
void      feonumm10n1_integrate_o_to( onumm10n1_t* num, feonumm10n1_t* w, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif