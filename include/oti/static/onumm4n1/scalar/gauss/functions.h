#ifndef OTI_ONUMM4N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n1_t feonumm4n1_atanh(    feonumm4n1_t* num);
void     feonumm4n1_atanh_to( feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_asinh(    feonumm4n1_t* num);
void     feonumm4n1_asinh_to( feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_acosh(    feonumm4n1_t* num);
void     feonumm4n1_acosh_to( feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_tanh(     feonumm4n1_t* num);
void     feonumm4n1_tanh_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_cosh(     feonumm4n1_t* num);
void     feonumm4n1_cosh_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_sinh(     feonumm4n1_t* num);
void     feonumm4n1_sinh_to(  feonumm4n1_t* num, feonumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n1_t feonumm4n1_asin(     feonumm4n1_t* num);
void     feonumm4n1_asin_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_acos(     feonumm4n1_t* num);
void     feonumm4n1_acos_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_atan(     feonumm4n1_t* num);
void     feonumm4n1_atan_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_tan(      feonumm4n1_t* num);
void     feonumm4n1_tan_to(   feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_cos(      feonumm4n1_t* num);
void     feonumm4n1_cos_to(   feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_sin(      feonumm4n1_t* num);
void     feonumm4n1_sin_to(   feonumm4n1_t* num, feonumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n1_t feonumm4n1_logb(     feonumm4n1_t* num, double base);
void     feonumm4n1_logb_to(  feonumm4n1_t* num, double base, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_log10(    feonumm4n1_t* num);
void     feonumm4n1_log10_to( feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_log(      feonumm4n1_t* num);
void     feonumm4n1_log_to(   feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_exp(      feonumm4n1_t* num);
void     feonumm4n1_exp_to(   feonumm4n1_t* num, feonumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n1_t feonumm4n1_cbrt(     feonumm4n1_t* num);
void     feonumm4n1_cbrt_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_sqrt(     feonumm4n1_t* num);
void     feonumm4n1_sqrt_to(  feonumm4n1_t* num, feonumm4n1_t* res);

feonumm4n1_t feonumm4n1_pow(      feonumm4n1_t* num, double e);
void     feonumm4n1_pow_to(   feonumm4n1_t* num, double e, feonumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm4n1_t feonumm4n1_integrate(       feonumm4n1_t* num, feonumm4n1_t* w);
void      feonumm4n1_integrate_to(    feonumm4n1_t* num, feonumm4n1_t* w, onumm4n1_t* res);

onumm4n1_t feonumm4n1_integrate_f(     feonumm4n1_t* num, feonumm4n1_t* w);
void      feonumm4n1_integrate_f_to(  feonumm4n1_t* num, feonumm4n1_t* w, onumm4n1_t* res);

onumm4n1_t feonumm4n1_integrate_r(       coeff_t num, feonumm4n1_t* w);
void      feonumm4n1_integrate_r_to(    coeff_t num, feonumm4n1_t* w, onumm4n1_t* res);

onumm4n1_t feonumm4n1_integrate_o(    onumm4n1_t* num, feonumm4n1_t* w);
void      feonumm4n1_integrate_o_to( onumm4n1_t* num, feonumm4n1_t* w, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif