#ifndef OTI_ONUMM6N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM6N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_atanh(    feonumm6n2_t* num);
void     feonumm6n2_atanh_to( feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_asinh(    feonumm6n2_t* num);
void     feonumm6n2_asinh_to( feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_acosh(    feonumm6n2_t* num);
void     feonumm6n2_acosh_to( feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_tanh(     feonumm6n2_t* num);
void     feonumm6n2_tanh_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_cosh(     feonumm6n2_t* num);
void     feonumm6n2_cosh_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sinh(     feonumm6n2_t* num);
void     feonumm6n2_sinh_to(  feonumm6n2_t* num, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_asin(     feonumm6n2_t* num);
void     feonumm6n2_asin_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_acos(     feonumm6n2_t* num);
void     feonumm6n2_acos_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_atan(     feonumm6n2_t* num);
void     feonumm6n2_atan_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_tan(      feonumm6n2_t* num);
void     feonumm6n2_tan_to(   feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_cos(      feonumm6n2_t* num);
void     feonumm6n2_cos_to(   feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sin(      feonumm6n2_t* num);
void     feonumm6n2_sin_to(   feonumm6n2_t* num, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_logb(     feonumm6n2_t* num, double base);
void     feonumm6n2_logb_to(  feonumm6n2_t* num, double base, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_log10(    feonumm6n2_t* num);
void     feonumm6n2_log10_to( feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_log(      feonumm6n2_t* num);
void     feonumm6n2_log_to(   feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_exp(      feonumm6n2_t* num);
void     feonumm6n2_exp_to(   feonumm6n2_t* num, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_cbrt(     feonumm6n2_t* num);
void     feonumm6n2_cbrt_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sqrt(     feonumm6n2_t* num);
void     feonumm6n2_sqrt_to(  feonumm6n2_t* num, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_pow(      feonumm6n2_t* num, double e);
void     feonumm6n2_pow_to(   feonumm6n2_t* num, double e, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm6n2_t feonumm6n2_integrate(       feonumm6n2_t* num, feonumm6n2_t* w);
void      feonumm6n2_integrate_to(    feonumm6n2_t* num, feonumm6n2_t* w, onumm6n2_t* res);

onumm6n2_t feonumm6n2_integrate_f(     feonumm6n2_t* num, feonumm6n2_t* w);
void      feonumm6n2_integrate_f_to(  feonumm6n2_t* num, feonumm6n2_t* w, onumm6n2_t* res);

onumm6n2_t feonumm6n2_integrate_r(       coeff_t num, feonumm6n2_t* w);
void      feonumm6n2_integrate_r_to(    coeff_t num, feonumm6n2_t* w, onumm6n2_t* res);

onumm6n2_t feonumm6n2_integrate_o(    onumm6n2_t* num, feonumm6n2_t* w);
void      feonumm6n2_integrate_o_to( onumm6n2_t* num, feonumm6n2_t* w, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif