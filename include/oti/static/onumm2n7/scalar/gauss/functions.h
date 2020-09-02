#ifndef OTI_ONUMM2N7_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N7_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_atanh(    feonumm2n7_t* num);
void     feonumm2n7_atanh_to( feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_asinh(    feonumm2n7_t* num);
void     feonumm2n7_asinh_to( feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_acosh(    feonumm2n7_t* num);
void     feonumm2n7_acosh_to( feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_tanh(     feonumm2n7_t* num);
void     feonumm2n7_tanh_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_cosh(     feonumm2n7_t* num);
void     feonumm2n7_cosh_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sinh(     feonumm2n7_t* num);
void     feonumm2n7_sinh_to(  feonumm2n7_t* num, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_asin(     feonumm2n7_t* num);
void     feonumm2n7_asin_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_acos(     feonumm2n7_t* num);
void     feonumm2n7_acos_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_atan(     feonumm2n7_t* num);
void     feonumm2n7_atan_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_tan(      feonumm2n7_t* num);
void     feonumm2n7_tan_to(   feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_cos(      feonumm2n7_t* num);
void     feonumm2n7_cos_to(   feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sin(      feonumm2n7_t* num);
void     feonumm2n7_sin_to(   feonumm2n7_t* num, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_logb(     feonumm2n7_t* num, double base);
void     feonumm2n7_logb_to(  feonumm2n7_t* num, double base, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_log10(    feonumm2n7_t* num);
void     feonumm2n7_log10_to( feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_log(      feonumm2n7_t* num);
void     feonumm2n7_log_to(   feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_exp(      feonumm2n7_t* num);
void     feonumm2n7_exp_to(   feonumm2n7_t* num, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_cbrt(     feonumm2n7_t* num);
void     feonumm2n7_cbrt_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sqrt(     feonumm2n7_t* num);
void     feonumm2n7_sqrt_to(  feonumm2n7_t* num, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_pow(      feonumm2n7_t* num, double e);
void     feonumm2n7_pow_to(   feonumm2n7_t* num, double e, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n7_t feonumm2n7_integrate(       feonumm2n7_t* num, feonumm2n7_t* w);
void      feonumm2n7_integrate_to(    feonumm2n7_t* num, feonumm2n7_t* w, onumm2n7_t* res);

onumm2n7_t feonumm2n7_integrate_f(     feonumm2n7_t* num, feonumm2n7_t* w);
void      feonumm2n7_integrate_f_to(  feonumm2n7_t* num, feonumm2n7_t* w, onumm2n7_t* res);

onumm2n7_t feonumm2n7_integrate_r(       coeff_t num, feonumm2n7_t* w);
void      feonumm2n7_integrate_r_to(    coeff_t num, feonumm2n7_t* w, onumm2n7_t* res);

onumm2n7_t feonumm2n7_integrate_o(    onumm2n7_t* num, feonumm2n7_t* w);
void      feonumm2n7_integrate_o_to( onumm2n7_t* num, feonumm2n7_t* w, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif