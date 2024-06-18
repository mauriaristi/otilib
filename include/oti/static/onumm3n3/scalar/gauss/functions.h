#ifndef OTI_ONUMM3N3_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N3_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n3_t feonumm3n3_atanh(    feonumm3n3_t* num);
void     feonumm3n3_atanh_to( feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_asinh(    feonumm3n3_t* num);
void     feonumm3n3_asinh_to( feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_acosh(    feonumm3n3_t* num);
void     feonumm3n3_acosh_to( feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_tanh(     feonumm3n3_t* num);
void     feonumm3n3_tanh_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_cosh(     feonumm3n3_t* num);
void     feonumm3n3_cosh_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_sinh(     feonumm3n3_t* num);
void     feonumm3n3_sinh_to(  feonumm3n3_t* num, feonumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n3_t feonumm3n3_asin(     feonumm3n3_t* num);
void     feonumm3n3_asin_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_acos(     feonumm3n3_t* num);
void     feonumm3n3_acos_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_atan(     feonumm3n3_t* num);
void     feonumm3n3_atan_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_tan(      feonumm3n3_t* num);
void     feonumm3n3_tan_to(   feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_cos(      feonumm3n3_t* num);
void     feonumm3n3_cos_to(   feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_sin(      feonumm3n3_t* num);
void     feonumm3n3_sin_to(   feonumm3n3_t* num, feonumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n3_t feonumm3n3_logb(     feonumm3n3_t* num, double base);
void     feonumm3n3_logb_to(  feonumm3n3_t* num, double base, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_log10(    feonumm3n3_t* num);
void     feonumm3n3_log10_to( feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_log(      feonumm3n3_t* num);
void     feonumm3n3_log_to(   feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_exp(      feonumm3n3_t* num);
void     feonumm3n3_exp_to(   feonumm3n3_t* num, feonumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n3_t feonumm3n3_cbrt(     feonumm3n3_t* num);
void     feonumm3n3_cbrt_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_sqrt(     feonumm3n3_t* num);
void     feonumm3n3_sqrt_to(  feonumm3n3_t* num, feonumm3n3_t* res);

feonumm3n3_t feonumm3n3_pow(      feonumm3n3_t* num, double e);
void     feonumm3n3_pow_to(   feonumm3n3_t* num, double e, feonumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm3n3_t feonumm3n3_integrate(       feonumm3n3_t* num, feonumm3n3_t* w);
void      feonumm3n3_integrate_to(    feonumm3n3_t* num, feonumm3n3_t* w, onumm3n3_t* res);

onumm3n3_t feonumm3n3_integrate_f(     feonumm3n3_t* num, feonumm3n3_t* w);
void      feonumm3n3_integrate_f_to(  feonumm3n3_t* num, feonumm3n3_t* w, onumm3n3_t* res);

onumm3n3_t feonumm3n3_integrate_r(       coeff_t num, feonumm3n3_t* w);
void      feonumm3n3_integrate_r_to(    coeff_t num, feonumm3n3_t* w, onumm3n3_t* res);

onumm3n3_t feonumm3n3_integrate_o(    onumm3n3_t* num, feonumm3n3_t* w);
void      feonumm3n3_integrate_o_to( onumm3n3_t* num, feonumm3n3_t* w, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif