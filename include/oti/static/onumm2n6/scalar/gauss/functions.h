#ifndef OTI_ONUMM2N6_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N6_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n6_t feonumm2n6_atanh(    feonumm2n6_t* num);
void     feonumm2n6_atanh_to( feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_asinh(    feonumm2n6_t* num);
void     feonumm2n6_asinh_to( feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_acosh(    feonumm2n6_t* num);
void     feonumm2n6_acosh_to( feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_tanh(     feonumm2n6_t* num);
void     feonumm2n6_tanh_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_cosh(     feonumm2n6_t* num);
void     feonumm2n6_cosh_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_sinh(     feonumm2n6_t* num);
void     feonumm2n6_sinh_to(  feonumm2n6_t* num, feonumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n6_t feonumm2n6_asin(     feonumm2n6_t* num);
void     feonumm2n6_asin_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_acos(     feonumm2n6_t* num);
void     feonumm2n6_acos_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_atan(     feonumm2n6_t* num);
void     feonumm2n6_atan_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_tan(      feonumm2n6_t* num);
void     feonumm2n6_tan_to(   feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_cos(      feonumm2n6_t* num);
void     feonumm2n6_cos_to(   feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_sin(      feonumm2n6_t* num);
void     feonumm2n6_sin_to(   feonumm2n6_t* num, feonumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n6_t feonumm2n6_logb(     feonumm2n6_t* num, double base);
void     feonumm2n6_logb_to(  feonumm2n6_t* num, double base, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_log10(    feonumm2n6_t* num);
void     feonumm2n6_log10_to( feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_log(      feonumm2n6_t* num);
void     feonumm2n6_log_to(   feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_exp(      feonumm2n6_t* num);
void     feonumm2n6_exp_to(   feonumm2n6_t* num, feonumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n6_t feonumm2n6_cbrt(     feonumm2n6_t* num);
void     feonumm2n6_cbrt_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_sqrt(     feonumm2n6_t* num);
void     feonumm2n6_sqrt_to(  feonumm2n6_t* num, feonumm2n6_t* res);

feonumm2n6_t feonumm2n6_pow(      feonumm2n6_t* num, double e);
void     feonumm2n6_pow_to(   feonumm2n6_t* num, double e, feonumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n6_t feonumm2n6_integrate(       feonumm2n6_t* num, feonumm2n6_t* w);
void      feonumm2n6_integrate_to(    feonumm2n6_t* num, feonumm2n6_t* w, onumm2n6_t* res);

onumm2n6_t feonumm2n6_integrate_f(     feonumm2n6_t* num, feonumm2n6_t* w);
void      feonumm2n6_integrate_f_to(  feonumm2n6_t* num, feonumm2n6_t* w, onumm2n6_t* res);

onumm2n6_t feonumm2n6_integrate_r(       coeff_t num, feonumm2n6_t* w);
void      feonumm2n6_integrate_r_to(    coeff_t num, feonumm2n6_t* w, onumm2n6_t* res);

onumm2n6_t feonumm2n6_integrate_o(    onumm2n6_t* num, feonumm2n6_t* w);
void      feonumm2n6_integrate_o_to( onumm2n6_t* num, feonumm2n6_t* w, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif