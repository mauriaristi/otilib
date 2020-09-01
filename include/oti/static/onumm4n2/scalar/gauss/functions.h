#ifndef OTI_ONUMM4N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n2_t feonumm4n2_atanh(    feonumm4n2_t* num);
void     feonumm4n2_atanh_to( feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_asinh(    feonumm4n2_t* num);
void     feonumm4n2_asinh_to( feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_acosh(    feonumm4n2_t* num);
void     feonumm4n2_acosh_to( feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_tanh(     feonumm4n2_t* num);
void     feonumm4n2_tanh_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_cosh(     feonumm4n2_t* num);
void     feonumm4n2_cosh_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_sinh(     feonumm4n2_t* num);
void     feonumm4n2_sinh_to(  feonumm4n2_t* num, feonumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n2_t feonumm4n2_asin(     feonumm4n2_t* num);
void     feonumm4n2_asin_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_acos(     feonumm4n2_t* num);
void     feonumm4n2_acos_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_atan(     feonumm4n2_t* num);
void     feonumm4n2_atan_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_tan(      feonumm4n2_t* num);
void     feonumm4n2_tan_to(   feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_cos(      feonumm4n2_t* num);
void     feonumm4n2_cos_to(   feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_sin(      feonumm4n2_t* num);
void     feonumm4n2_sin_to(   feonumm4n2_t* num, feonumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n2_t feonumm4n2_logb(     feonumm4n2_t* num, double base);
void     feonumm4n2_logb_to(  feonumm4n2_t* num, double base, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_log10(    feonumm4n2_t* num);
void     feonumm4n2_log10_to( feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_log(      feonumm4n2_t* num);
void     feonumm4n2_log_to(   feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_exp(      feonumm4n2_t* num);
void     feonumm4n2_exp_to(   feonumm4n2_t* num, feonumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n2_t feonumm4n2_cbrt(     feonumm4n2_t* num);
void     feonumm4n2_cbrt_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_sqrt(     feonumm4n2_t* num);
void     feonumm4n2_sqrt_to(  feonumm4n2_t* num, feonumm4n2_t* res);

feonumm4n2_t feonumm4n2_pow(      feonumm4n2_t* num, double e);
void     feonumm4n2_pow_to(   feonumm4n2_t* num, double e, feonumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm4n2_t feonumm4n2_integrate(       feonumm4n2_t* num, feonumm4n2_t* w);
void      feonumm4n2_integrate_to(    feonumm4n2_t* num, feonumm4n2_t* w, onumm4n2_t* res);

onumm4n2_t feonumm4n2_integrate_f(     feonumm4n2_t* num, feonumm4n2_t* w);
void      feonumm4n2_integrate_f_to(  feonumm4n2_t* num, feonumm4n2_t* w, onumm4n2_t* res);

onumm4n2_t feonumm4n2_integrate_r(       coeff_t num, feonumm4n2_t* w);
void      feonumm4n2_integrate_r_to(    coeff_t num, feonumm4n2_t* w, onumm4n2_t* res);

onumm4n2_t feonumm4n2_integrate_o(    onumm4n2_t* num, feonumm4n2_t* w);
void      feonumm4n2_integrate_o_to( onumm4n2_t* num, feonumm4n2_t* w, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif