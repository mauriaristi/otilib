#ifndef OTI_ONUMM5N4_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N4_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n4_t feonumm5n4_atanh(    feonumm5n4_t* num);
void     feonumm5n4_atanh_to( feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_asinh(    feonumm5n4_t* num);
void     feonumm5n4_asinh_to( feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_acosh(    feonumm5n4_t* num);
void     feonumm5n4_acosh_to( feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_tanh(     feonumm5n4_t* num);
void     feonumm5n4_tanh_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_cosh(     feonumm5n4_t* num);
void     feonumm5n4_cosh_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_sinh(     feonumm5n4_t* num);
void     feonumm5n4_sinh_to(  feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n4_t feonumm5n4_asin(     feonumm5n4_t* num);
void     feonumm5n4_asin_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_acos(     feonumm5n4_t* num);
void     feonumm5n4_acos_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_atan(     feonumm5n4_t* num);
void     feonumm5n4_atan_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_tan(      feonumm5n4_t* num);
void     feonumm5n4_tan_to(   feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_cos(      feonumm5n4_t* num);
void     feonumm5n4_cos_to(   feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_sin(      feonumm5n4_t* num);
void     feonumm5n4_sin_to(   feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n4_t feonumm5n4_logb(     feonumm5n4_t* num, double base);
void     feonumm5n4_logb_to(  feonumm5n4_t* num, double base, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_log10(    feonumm5n4_t* num);
void     feonumm5n4_log10_to( feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_log(      feonumm5n4_t* num);
void     feonumm5n4_log_to(   feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_exp(      feonumm5n4_t* num);
void     feonumm5n4_exp_to(   feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n4_t feonumm5n4_cbrt(     feonumm5n4_t* num);
void     feonumm5n4_cbrt_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_sqrt(     feonumm5n4_t* num);
void     feonumm5n4_sqrt_to(  feonumm5n4_t* num, feonumm5n4_t* res);

feonumm5n4_t feonumm5n4_pow(      feonumm5n4_t* num, double e);
void     feonumm5n4_pow_to(   feonumm5n4_t* num, double e, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm5n4_t feonumm5n4_integrate(       feonumm5n4_t* num, feonumm5n4_t* w);
void      feonumm5n4_integrate_to(    feonumm5n4_t* num, feonumm5n4_t* w, onumm5n4_t* res);

onumm5n4_t feonumm5n4_integrate_f(     feonumm5n4_t* num, feonumm5n4_t* w);
void      feonumm5n4_integrate_f_to(  feonumm5n4_t* num, feonumm5n4_t* w, onumm5n4_t* res);

onumm5n4_t feonumm5n4_integrate_r(       coeff_t num, feonumm5n4_t* w);
void      feonumm5n4_integrate_r_to(    coeff_t num, feonumm5n4_t* w, onumm5n4_t* res);

onumm5n4_t feonumm5n4_integrate_o(    onumm5n4_t* num, feonumm5n4_t* w);
void      feonumm5n4_integrate_o_to( onumm5n4_t* num, feonumm5n4_t* w, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif