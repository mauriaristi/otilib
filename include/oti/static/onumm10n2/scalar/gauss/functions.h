#ifndef OTI_ONUMM10N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM10N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_atanh(    feonumm10n2_t* num);
void     feonumm10n2_atanh_to( feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_asinh(    feonumm10n2_t* num);
void     feonumm10n2_asinh_to( feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_acosh(    feonumm10n2_t* num);
void     feonumm10n2_acosh_to( feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_tanh(     feonumm10n2_t* num);
void     feonumm10n2_tanh_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_cosh(     feonumm10n2_t* num);
void     feonumm10n2_cosh_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sinh(     feonumm10n2_t* num);
void     feonumm10n2_sinh_to(  feonumm10n2_t* num, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_asin(     feonumm10n2_t* num);
void     feonumm10n2_asin_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_acos(     feonumm10n2_t* num);
void     feonumm10n2_acos_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_atan(     feonumm10n2_t* num);
void     feonumm10n2_atan_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_tan(      feonumm10n2_t* num);
void     feonumm10n2_tan_to(   feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_cos(      feonumm10n2_t* num);
void     feonumm10n2_cos_to(   feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sin(      feonumm10n2_t* num);
void     feonumm10n2_sin_to(   feonumm10n2_t* num, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_logb(     feonumm10n2_t* num, double base);
void     feonumm10n2_logb_to(  feonumm10n2_t* num, double base, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_log10(    feonumm10n2_t* num);
void     feonumm10n2_log10_to( feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_log(      feonumm10n2_t* num);
void     feonumm10n2_log_to(   feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_exp(      feonumm10n2_t* num);
void     feonumm10n2_exp_to(   feonumm10n2_t* num, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_cbrt(     feonumm10n2_t* num);
void     feonumm10n2_cbrt_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sqrt(     feonumm10n2_t* num);
void     feonumm10n2_sqrt_to(  feonumm10n2_t* num, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_pow(      feonumm10n2_t* num, double e);
void     feonumm10n2_pow_to(   feonumm10n2_t* num, double e, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm10n2_t feonumm10n2_integrate(       feonumm10n2_t* num, feonumm10n2_t* w);
void      feonumm10n2_integrate_to(    feonumm10n2_t* num, feonumm10n2_t* w, onumm10n2_t* res);

onumm10n2_t feonumm10n2_integrate_f(     feonumm10n2_t* num, feonumm10n2_t* w);
void      feonumm10n2_integrate_f_to(  feonumm10n2_t* num, feonumm10n2_t* w, onumm10n2_t* res);

onumm10n2_t feonumm10n2_integrate_r(       coeff_t num, feonumm10n2_t* w);
void      feonumm10n2_integrate_r_to(    coeff_t num, feonumm10n2_t* w, onumm10n2_t* res);

onumm10n2_t feonumm10n2_integrate_o(    onumm10n2_t* num, feonumm10n2_t* w);
void      feonumm10n2_integrate_o_to( onumm10n2_t* num, feonumm10n2_t* w, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif