#ifndef OTI_ONUMM7N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM7N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n2_t feonumm7n2_atanh(    feonumm7n2_t* num);
void     feonumm7n2_atanh_to( feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_asinh(    feonumm7n2_t* num);
void     feonumm7n2_asinh_to( feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_acosh(    feonumm7n2_t* num);
void     feonumm7n2_acosh_to( feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_tanh(     feonumm7n2_t* num);
void     feonumm7n2_tanh_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_cosh(     feonumm7n2_t* num);
void     feonumm7n2_cosh_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_sinh(     feonumm7n2_t* num);
void     feonumm7n2_sinh_to(  feonumm7n2_t* num, feonumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n2_t feonumm7n2_asin(     feonumm7n2_t* num);
void     feonumm7n2_asin_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_acos(     feonumm7n2_t* num);
void     feonumm7n2_acos_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_atan(     feonumm7n2_t* num);
void     feonumm7n2_atan_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_tan(      feonumm7n2_t* num);
void     feonumm7n2_tan_to(   feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_cos(      feonumm7n2_t* num);
void     feonumm7n2_cos_to(   feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_sin(      feonumm7n2_t* num);
void     feonumm7n2_sin_to(   feonumm7n2_t* num, feonumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n2_t feonumm7n2_logb(     feonumm7n2_t* num, double base);
void     feonumm7n2_logb_to(  feonumm7n2_t* num, double base, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_log10(    feonumm7n2_t* num);
void     feonumm7n2_log10_to( feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_log(      feonumm7n2_t* num);
void     feonumm7n2_log_to(   feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_exp(      feonumm7n2_t* num);
void     feonumm7n2_exp_to(   feonumm7n2_t* num, feonumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm7n2_t feonumm7n2_cbrt(     feonumm7n2_t* num);
void     feonumm7n2_cbrt_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_sqrt(     feonumm7n2_t* num);
void     feonumm7n2_sqrt_to(  feonumm7n2_t* num, feonumm7n2_t* res);

feonumm7n2_t feonumm7n2_pow(      feonumm7n2_t* num, double e);
void     feonumm7n2_pow_to(   feonumm7n2_t* num, double e, feonumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm7n2_t feonumm7n2_integrate(       feonumm7n2_t* num, feonumm7n2_t* w);
void      feonumm7n2_integrate_to(    feonumm7n2_t* num, feonumm7n2_t* w, onumm7n2_t* res);

onumm7n2_t feonumm7n2_integrate_f(     feonumm7n2_t* num, feonumm7n2_t* w);
void      feonumm7n2_integrate_f_to(  feonumm7n2_t* num, feonumm7n2_t* w, onumm7n2_t* res);

onumm7n2_t feonumm7n2_integrate_r(       coeff_t num, feonumm7n2_t* w);
void      feonumm7n2_integrate_r_to(    coeff_t num, feonumm7n2_t* w, onumm7n2_t* res);

onumm7n2_t feonumm7n2_integrate_o(    onumm7n2_t* num, feonumm7n2_t* w);
void      feonumm7n2_integrate_o_to( onumm7n2_t* num, feonumm7n2_t* w, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif