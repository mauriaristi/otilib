#ifndef OTI_ONUMM9N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM9N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n1_t feonumm9n1_atanh(    feonumm9n1_t* num);
void     feonumm9n1_atanh_to( feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_asinh(    feonumm9n1_t* num);
void     feonumm9n1_asinh_to( feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_acosh(    feonumm9n1_t* num);
void     feonumm9n1_acosh_to( feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_tanh(     feonumm9n1_t* num);
void     feonumm9n1_tanh_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_cosh(     feonumm9n1_t* num);
void     feonumm9n1_cosh_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_sinh(     feonumm9n1_t* num);
void     feonumm9n1_sinh_to(  feonumm9n1_t* num, feonumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n1_t feonumm9n1_asin(     feonumm9n1_t* num);
void     feonumm9n1_asin_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_acos(     feonumm9n1_t* num);
void     feonumm9n1_acos_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_atan(     feonumm9n1_t* num);
void     feonumm9n1_atan_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_tan(      feonumm9n1_t* num);
void     feonumm9n1_tan_to(   feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_cos(      feonumm9n1_t* num);
void     feonumm9n1_cos_to(   feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_sin(      feonumm9n1_t* num);
void     feonumm9n1_sin_to(   feonumm9n1_t* num, feonumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n1_t feonumm9n1_logb(     feonumm9n1_t* num, double base);
void     feonumm9n1_logb_to(  feonumm9n1_t* num, double base, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_log10(    feonumm9n1_t* num);
void     feonumm9n1_log10_to( feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_log(      feonumm9n1_t* num);
void     feonumm9n1_log_to(   feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_exp(      feonumm9n1_t* num);
void     feonumm9n1_exp_to(   feonumm9n1_t* num, feonumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n1_t feonumm9n1_cbrt(     feonumm9n1_t* num);
void     feonumm9n1_cbrt_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_sqrt(     feonumm9n1_t* num);
void     feonumm9n1_sqrt_to(  feonumm9n1_t* num, feonumm9n1_t* res);

feonumm9n1_t feonumm9n1_pow(      feonumm9n1_t* num, double e);
void     feonumm9n1_pow_to(   feonumm9n1_t* num, double e, feonumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm9n1_t feonumm9n1_integrate(       feonumm9n1_t* num, feonumm9n1_t* w);
void      feonumm9n1_integrate_to(    feonumm9n1_t* num, feonumm9n1_t* w, onumm9n1_t* res);

onumm9n1_t feonumm9n1_integrate_f(     feonumm9n1_t* num, feonumm9n1_t* w);
void      feonumm9n1_integrate_f_to(  feonumm9n1_t* num, feonumm9n1_t* w, onumm9n1_t* res);

onumm9n1_t feonumm9n1_integrate_r(       coeff_t num, feonumm9n1_t* w);
void      feonumm9n1_integrate_r_to(    coeff_t num, feonumm9n1_t* w, onumm9n1_t* res);

onumm9n1_t feonumm9n1_integrate_o(    onumm9n1_t* num, feonumm9n1_t* w);
void      feonumm9n1_integrate_o_to( onumm9n1_t* num, feonumm9n1_t* w, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif