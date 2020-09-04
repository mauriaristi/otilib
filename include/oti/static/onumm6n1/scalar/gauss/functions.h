#ifndef OTI_ONUMM6N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM6N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n1_t feonumm6n1_atanh(    feonumm6n1_t* num);
void     feonumm6n1_atanh_to( feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_asinh(    feonumm6n1_t* num);
void     feonumm6n1_asinh_to( feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_acosh(    feonumm6n1_t* num);
void     feonumm6n1_acosh_to( feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_tanh(     feonumm6n1_t* num);
void     feonumm6n1_tanh_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_cosh(     feonumm6n1_t* num);
void     feonumm6n1_cosh_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_sinh(     feonumm6n1_t* num);
void     feonumm6n1_sinh_to(  feonumm6n1_t* num, feonumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n1_t feonumm6n1_asin(     feonumm6n1_t* num);
void     feonumm6n1_asin_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_acos(     feonumm6n1_t* num);
void     feonumm6n1_acos_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_atan(     feonumm6n1_t* num);
void     feonumm6n1_atan_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_tan(      feonumm6n1_t* num);
void     feonumm6n1_tan_to(   feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_cos(      feonumm6n1_t* num);
void     feonumm6n1_cos_to(   feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_sin(      feonumm6n1_t* num);
void     feonumm6n1_sin_to(   feonumm6n1_t* num, feonumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n1_t feonumm6n1_logb(     feonumm6n1_t* num, double base);
void     feonumm6n1_logb_to(  feonumm6n1_t* num, double base, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_log10(    feonumm6n1_t* num);
void     feonumm6n1_log10_to( feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_log(      feonumm6n1_t* num);
void     feonumm6n1_log_to(   feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_exp(      feonumm6n1_t* num);
void     feonumm6n1_exp_to(   feonumm6n1_t* num, feonumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n1_t feonumm6n1_cbrt(     feonumm6n1_t* num);
void     feonumm6n1_cbrt_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_sqrt(     feonumm6n1_t* num);
void     feonumm6n1_sqrt_to(  feonumm6n1_t* num, feonumm6n1_t* res);

feonumm6n1_t feonumm6n1_pow(      feonumm6n1_t* num, double e);
void     feonumm6n1_pow_to(   feonumm6n1_t* num, double e, feonumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm6n1_t feonumm6n1_integrate(       feonumm6n1_t* num, feonumm6n1_t* w);
void      feonumm6n1_integrate_to(    feonumm6n1_t* num, feonumm6n1_t* w, onumm6n1_t* res);

onumm6n1_t feonumm6n1_integrate_f(     feonumm6n1_t* num, feonumm6n1_t* w);
void      feonumm6n1_integrate_f_to(  feonumm6n1_t* num, feonumm6n1_t* w, onumm6n1_t* res);

onumm6n1_t feonumm6n1_integrate_r(       coeff_t num, feonumm6n1_t* w);
void      feonumm6n1_integrate_r_to(    coeff_t num, feonumm6n1_t* w, onumm6n1_t* res);

onumm6n1_t feonumm6n1_integrate_o(    onumm6n1_t* num, feonumm6n1_t* w);
void      feonumm6n1_integrate_o_to( onumm6n1_t* num, feonumm6n1_t* w, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif