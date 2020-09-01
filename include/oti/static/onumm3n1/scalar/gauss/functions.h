#ifndef OTI_ONUMM3N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n1_t feonumm3n1_atanh(    feonumm3n1_t* num);
void     feonumm3n1_atanh_to( feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_asinh(    feonumm3n1_t* num);
void     feonumm3n1_asinh_to( feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_acosh(    feonumm3n1_t* num);
void     feonumm3n1_acosh_to( feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_tanh(     feonumm3n1_t* num);
void     feonumm3n1_tanh_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_cosh(     feonumm3n1_t* num);
void     feonumm3n1_cosh_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_sinh(     feonumm3n1_t* num);
void     feonumm3n1_sinh_to(  feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n1_t feonumm3n1_asin(     feonumm3n1_t* num);
void     feonumm3n1_asin_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_acos(     feonumm3n1_t* num);
void     feonumm3n1_acos_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_atan(     feonumm3n1_t* num);
void     feonumm3n1_atan_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_tan(      feonumm3n1_t* num);
void     feonumm3n1_tan_to(   feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_cos(      feonumm3n1_t* num);
void     feonumm3n1_cos_to(   feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_sin(      feonumm3n1_t* num);
void     feonumm3n1_sin_to(   feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n1_t feonumm3n1_logb(     feonumm3n1_t* num, double base);
void     feonumm3n1_logb_to(  feonumm3n1_t* num, double base, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_log10(    feonumm3n1_t* num);
void     feonumm3n1_log10_to( feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_log(      feonumm3n1_t* num);
void     feonumm3n1_log_to(   feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_exp(      feonumm3n1_t* num);
void     feonumm3n1_exp_to(   feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n1_t feonumm3n1_cbrt(     feonumm3n1_t* num);
void     feonumm3n1_cbrt_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_sqrt(     feonumm3n1_t* num);
void     feonumm3n1_sqrt_to(  feonumm3n1_t* num, feonumm3n1_t* res);

feonumm3n1_t feonumm3n1_pow(      feonumm3n1_t* num, double e);
void     feonumm3n1_pow_to(   feonumm3n1_t* num, double e, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm3n1_t feonumm3n1_integrate(       feonumm3n1_t* num, feonumm3n1_t* w);
void      feonumm3n1_integrate_to(    feonumm3n1_t* num, feonumm3n1_t* w, onumm3n1_t* res);

onumm3n1_t feonumm3n1_integrate_f(     feonumm3n1_t* num, feonumm3n1_t* w);
void      feonumm3n1_integrate_f_to(  feonumm3n1_t* num, feonumm3n1_t* w, onumm3n1_t* res);

onumm3n1_t feonumm3n1_integrate_r(       coeff_t num, feonumm3n1_t* w);
void      feonumm3n1_integrate_r_to(    coeff_t num, feonumm3n1_t* w, onumm3n1_t* res);

onumm3n1_t feonumm3n1_integrate_o(    onumm3n1_t* num, feonumm3n1_t* w);
void      feonumm3n1_integrate_o_to( onumm3n1_t* num, feonumm3n1_t* w, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif