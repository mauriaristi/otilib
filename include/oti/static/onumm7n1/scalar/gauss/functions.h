#ifndef OTI_ONUMM7N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM7N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n1_t feonumm7n1_atanh(    feonumm7n1_t* num);
void     feonumm7n1_atanh_to( feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_asinh(    feonumm7n1_t* num);
void     feonumm7n1_asinh_to( feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_acosh(    feonumm7n1_t* num);
void     feonumm7n1_acosh_to( feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_tanh(     feonumm7n1_t* num);
void     feonumm7n1_tanh_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_cosh(     feonumm7n1_t* num);
void     feonumm7n1_cosh_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_sinh(     feonumm7n1_t* num);
void     feonumm7n1_sinh_to(  feonumm7n1_t* num, feonumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n1_t feonumm7n1_asin(     feonumm7n1_t* num);
void     feonumm7n1_asin_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_acos(     feonumm7n1_t* num);
void     feonumm7n1_acos_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_atan(     feonumm7n1_t* num);
void     feonumm7n1_atan_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_tan(      feonumm7n1_t* num);
void     feonumm7n1_tan_to(   feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_cos(      feonumm7n1_t* num);
void     feonumm7n1_cos_to(   feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_sin(      feonumm7n1_t* num);
void     feonumm7n1_sin_to(   feonumm7n1_t* num, feonumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n1_t feonumm7n1_logb(     feonumm7n1_t* num, double base);
void     feonumm7n1_logb_to(  feonumm7n1_t* num, double base, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_log10(    feonumm7n1_t* num);
void     feonumm7n1_log10_to( feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_log(      feonumm7n1_t* num);
void     feonumm7n1_log_to(   feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_exp(      feonumm7n1_t* num);
void     feonumm7n1_exp_to(   feonumm7n1_t* num, feonumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n1_t feonumm7n1_cbrt(     feonumm7n1_t* num);
void     feonumm7n1_cbrt_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_sqrt(     feonumm7n1_t* num);
void     feonumm7n1_sqrt_to(  feonumm7n1_t* num, feonumm7n1_t* res);

feonumm7n1_t feonumm7n1_pow(      feonumm7n1_t* num, double e);
void     feonumm7n1_pow_to(   feonumm7n1_t* num, double e, feonumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm7n1_t feonumm7n1_integrate(       feonumm7n1_t* num, feonumm7n1_t* w);
void      feonumm7n1_integrate_to(    feonumm7n1_t* num, feonumm7n1_t* w, onumm7n1_t* res);

onumm7n1_t feonumm7n1_integrate_f(     feonumm7n1_t* num, feonumm7n1_t* w);
void      feonumm7n1_integrate_f_to(  feonumm7n1_t* num, feonumm7n1_t* w, onumm7n1_t* res);

onumm7n1_t feonumm7n1_integrate_r(       coeff_t num, feonumm7n1_t* w);
void      feonumm7n1_integrate_r_to(    coeff_t num, feonumm7n1_t* w, onumm7n1_t* res);

onumm7n1_t feonumm7n1_integrate_o(    onumm7n1_t* num, feonumm7n1_t* w);
void      feonumm7n1_integrate_o_to( onumm7n1_t* num, feonumm7n1_t* w, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif