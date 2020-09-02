#ifndef OTI_ONUMM2N9_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N9_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_atanh(    feonumm2n9_t* num);
void     feonumm2n9_atanh_to( feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_asinh(    feonumm2n9_t* num);
void     feonumm2n9_asinh_to( feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_acosh(    feonumm2n9_t* num);
void     feonumm2n9_acosh_to( feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_tanh(     feonumm2n9_t* num);
void     feonumm2n9_tanh_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_cosh(     feonumm2n9_t* num);
void     feonumm2n9_cosh_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sinh(     feonumm2n9_t* num);
void     feonumm2n9_sinh_to(  feonumm2n9_t* num, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_asin(     feonumm2n9_t* num);
void     feonumm2n9_asin_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_acos(     feonumm2n9_t* num);
void     feonumm2n9_acos_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_atan(     feonumm2n9_t* num);
void     feonumm2n9_atan_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_tan(      feonumm2n9_t* num);
void     feonumm2n9_tan_to(   feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_cos(      feonumm2n9_t* num);
void     feonumm2n9_cos_to(   feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sin(      feonumm2n9_t* num);
void     feonumm2n9_sin_to(   feonumm2n9_t* num, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_logb(     feonumm2n9_t* num, double base);
void     feonumm2n9_logb_to(  feonumm2n9_t* num, double base, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_log10(    feonumm2n9_t* num);
void     feonumm2n9_log10_to( feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_log(      feonumm2n9_t* num);
void     feonumm2n9_log_to(   feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_exp(      feonumm2n9_t* num);
void     feonumm2n9_exp_to(   feonumm2n9_t* num, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_cbrt(     feonumm2n9_t* num);
void     feonumm2n9_cbrt_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sqrt(     feonumm2n9_t* num);
void     feonumm2n9_sqrt_to(  feonumm2n9_t* num, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_pow(      feonumm2n9_t* num, double e);
void     feonumm2n9_pow_to(   feonumm2n9_t* num, double e, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n9_t feonumm2n9_integrate(       feonumm2n9_t* num, feonumm2n9_t* w);
void      feonumm2n9_integrate_to(    feonumm2n9_t* num, feonumm2n9_t* w, onumm2n9_t* res);

onumm2n9_t feonumm2n9_integrate_f(     feonumm2n9_t* num, feonumm2n9_t* w);
void      feonumm2n9_integrate_f_to(  feonumm2n9_t* num, feonumm2n9_t* w, onumm2n9_t* res);

onumm2n9_t feonumm2n9_integrate_r(       coeff_t num, feonumm2n9_t* w);
void      feonumm2n9_integrate_r_to(    coeff_t num, feonumm2n9_t* w, onumm2n9_t* res);

onumm2n9_t feonumm2n9_integrate_o(    onumm2n9_t* num, feonumm2n9_t* w);
void      feonumm2n9_integrate_o_to( onumm2n9_t* num, feonumm2n9_t* w, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif