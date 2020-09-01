#ifndef OTI_ONUMM5N5_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N5_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n5_t feonumm5n5_atanh(    feonumm5n5_t* num);
void     feonumm5n5_atanh_to( feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_asinh(    feonumm5n5_t* num);
void     feonumm5n5_asinh_to( feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_acosh(    feonumm5n5_t* num);
void     feonumm5n5_acosh_to( feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_tanh(     feonumm5n5_t* num);
void     feonumm5n5_tanh_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_cosh(     feonumm5n5_t* num);
void     feonumm5n5_cosh_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_sinh(     feonumm5n5_t* num);
void     feonumm5n5_sinh_to(  feonumm5n5_t* num, feonumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n5_t feonumm5n5_asin(     feonumm5n5_t* num);
void     feonumm5n5_asin_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_acos(     feonumm5n5_t* num);
void     feonumm5n5_acos_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_atan(     feonumm5n5_t* num);
void     feonumm5n5_atan_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_tan(      feonumm5n5_t* num);
void     feonumm5n5_tan_to(   feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_cos(      feonumm5n5_t* num);
void     feonumm5n5_cos_to(   feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_sin(      feonumm5n5_t* num);
void     feonumm5n5_sin_to(   feonumm5n5_t* num, feonumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n5_t feonumm5n5_logb(     feonumm5n5_t* num, double base);
void     feonumm5n5_logb_to(  feonumm5n5_t* num, double base, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_log10(    feonumm5n5_t* num);
void     feonumm5n5_log10_to( feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_log(      feonumm5n5_t* num);
void     feonumm5n5_log_to(   feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_exp(      feonumm5n5_t* num);
void     feonumm5n5_exp_to(   feonumm5n5_t* num, feonumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n5_t feonumm5n5_cbrt(     feonumm5n5_t* num);
void     feonumm5n5_cbrt_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_sqrt(     feonumm5n5_t* num);
void     feonumm5n5_sqrt_to(  feonumm5n5_t* num, feonumm5n5_t* res);

feonumm5n5_t feonumm5n5_pow(      feonumm5n5_t* num, double e);
void     feonumm5n5_pow_to(   feonumm5n5_t* num, double e, feonumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm5n5_t feonumm5n5_integrate(       feonumm5n5_t* num, feonumm5n5_t* w);
void      feonumm5n5_integrate_to(    feonumm5n5_t* num, feonumm5n5_t* w, onumm5n5_t* res);

onumm5n5_t feonumm5n5_integrate_f(     feonumm5n5_t* num, feonumm5n5_t* w);
void      feonumm5n5_integrate_f_to(  feonumm5n5_t* num, feonumm5n5_t* w, onumm5n5_t* res);

onumm5n5_t feonumm5n5_integrate_r(       coeff_t num, feonumm5n5_t* w);
void      feonumm5n5_integrate_r_to(    coeff_t num, feonumm5n5_t* w, onumm5n5_t* res);

onumm5n5_t feonumm5n5_integrate_o(    onumm5n5_t* num, feonumm5n5_t* w);
void      feonumm5n5_integrate_o_to( onumm5n5_t* num, feonumm5n5_t* w, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif