#ifndef OTI_ONUMM4N3_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N3_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_atanh(    feonumm4n3_t* num);
void     feonumm4n3_atanh_to( feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_asinh(    feonumm4n3_t* num);
void     feonumm4n3_asinh_to( feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_acosh(    feonumm4n3_t* num);
void     feonumm4n3_acosh_to( feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_tanh(     feonumm4n3_t* num);
void     feonumm4n3_tanh_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_cosh(     feonumm4n3_t* num);
void     feonumm4n3_cosh_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sinh(     feonumm4n3_t* num);
void     feonumm4n3_sinh_to(  feonumm4n3_t* num, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_asin(     feonumm4n3_t* num);
void     feonumm4n3_asin_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_acos(     feonumm4n3_t* num);
void     feonumm4n3_acos_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_atan(     feonumm4n3_t* num);
void     feonumm4n3_atan_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_tan(      feonumm4n3_t* num);
void     feonumm4n3_tan_to(   feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_cos(      feonumm4n3_t* num);
void     feonumm4n3_cos_to(   feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sin(      feonumm4n3_t* num);
void     feonumm4n3_sin_to(   feonumm4n3_t* num, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_logb(     feonumm4n3_t* num, double base);
void     feonumm4n3_logb_to(  feonumm4n3_t* num, double base, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_log10(    feonumm4n3_t* num);
void     feonumm4n3_log10_to( feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_log(      feonumm4n3_t* num);
void     feonumm4n3_log_to(   feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_exp(      feonumm4n3_t* num);
void     feonumm4n3_exp_to(   feonumm4n3_t* num, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_cbrt(     feonumm4n3_t* num);
void     feonumm4n3_cbrt_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sqrt(     feonumm4n3_t* num);
void     feonumm4n3_sqrt_to(  feonumm4n3_t* num, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_pow(      feonumm4n3_t* num, double e);
void     feonumm4n3_pow_to(   feonumm4n3_t* num, double e, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm4n3_t feonumm4n3_integrate(       feonumm4n3_t* num, feonumm4n3_t* w);
void      feonumm4n3_integrate_to(    feonumm4n3_t* num, feonumm4n3_t* w, onumm4n3_t* res);

onumm4n3_t feonumm4n3_integrate_f(     feonumm4n3_t* num, feonumm4n3_t* w);
void      feonumm4n3_integrate_f_to(  feonumm4n3_t* num, feonumm4n3_t* w, onumm4n3_t* res);

onumm4n3_t feonumm4n3_integrate_r(       coeff_t num, feonumm4n3_t* w);
void      feonumm4n3_integrate_r_to(    coeff_t num, feonumm4n3_t* w, onumm4n3_t* res);

onumm4n3_t feonumm4n3_integrate_o(    onumm4n3_t* num, feonumm4n3_t* w);
void      feonumm4n3_integrate_o_to( onumm4n3_t* num, feonumm4n3_t* w, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif