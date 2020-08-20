#ifndef OTI_ONUMM2N5_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N5_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n5_t feonumm2n5_atanh(    feonumm2n5_t* num);
void     feonumm2n5_atanh_to( feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_asinh(    feonumm2n5_t* num);
void     feonumm2n5_asinh_to( feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_acosh(    feonumm2n5_t* num);
void     feonumm2n5_acosh_to( feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_tanh(     feonumm2n5_t* num);
void     feonumm2n5_tanh_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_cosh(     feonumm2n5_t* num);
void     feonumm2n5_cosh_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_sinh(     feonumm2n5_t* num);
void     feonumm2n5_sinh_to(  feonumm2n5_t* num, feonumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n5_t feonumm2n5_asin(     feonumm2n5_t* num);
void     feonumm2n5_asin_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_acos(     feonumm2n5_t* num);
void     feonumm2n5_acos_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_atan(     feonumm2n5_t* num);
void     feonumm2n5_atan_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_tan(      feonumm2n5_t* num);
void     feonumm2n5_tan_to(   feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_cos(      feonumm2n5_t* num);
void     feonumm2n5_cos_to(   feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_sin(      feonumm2n5_t* num);
void     feonumm2n5_sin_to(   feonumm2n5_t* num, feonumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n5_t feonumm2n5_logb(     feonumm2n5_t* num, double base);
void     feonumm2n5_logb_to(  feonumm2n5_t* num, double base, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_log10(    feonumm2n5_t* num);
void     feonumm2n5_log10_to( feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_log(      feonumm2n5_t* num);
void     feonumm2n5_log_to(   feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_exp(      feonumm2n5_t* num);
void     feonumm2n5_exp_to(   feonumm2n5_t* num, feonumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n5_t feonumm2n5_cbrt(     feonumm2n5_t* num);
void     feonumm2n5_cbrt_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_sqrt(     feonumm2n5_t* num);
void     feonumm2n5_sqrt_to(  feonumm2n5_t* num, feonumm2n5_t* res);

feonumm2n5_t feonumm2n5_pow(      feonumm2n5_t* num, double e);
void     feonumm2n5_pow_to(   feonumm2n5_t* num, double e, feonumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n5_t feonumm2n5_integrate(       feonumm2n5_t* num, feonumm2n5_t* w);
void      feonumm2n5_integrate_to(    feonumm2n5_t* num, feonumm2n5_t* w, onumm2n5_t* res);

onumm2n5_t feonumm2n5_integrate_f(     feonumm2n5_t* num, feonumm2n5_t* w);
void      feonumm2n5_integrate_f_to(  feonumm2n5_t* num, feonumm2n5_t* w, onumm2n5_t* res);

onumm2n5_t feonumm2n5_integrate_r(       coeff_t num, feonumm2n5_t* w);
void      feonumm2n5_integrate_r_to(    coeff_t num, feonumm2n5_t* w, onumm2n5_t* res);

onumm2n5_t feonumm2n5_integrate_o(    onumm2n5_t* num, feonumm2n5_t* w);
void      feonumm2n5_integrate_o_to( onumm2n5_t* num, feonumm2n5_t* w, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif