#ifndef OTI_ONUMM20N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM20N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm20n1_t feonumm20n1_atanh(    feonumm20n1_t* num);
void     feonumm20n1_atanh_to( feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_asinh(    feonumm20n1_t* num);
void     feonumm20n1_asinh_to( feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_acosh(    feonumm20n1_t* num);
void     feonumm20n1_acosh_to( feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_tanh(     feonumm20n1_t* num);
void     feonumm20n1_tanh_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_cosh(     feonumm20n1_t* num);
void     feonumm20n1_cosh_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_sinh(     feonumm20n1_t* num);
void     feonumm20n1_sinh_to(  feonumm20n1_t* num, feonumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm20n1_t feonumm20n1_asin(     feonumm20n1_t* num);
void     feonumm20n1_asin_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_acos(     feonumm20n1_t* num);
void     feonumm20n1_acos_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_atan(     feonumm20n1_t* num);
void     feonumm20n1_atan_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_tan(      feonumm20n1_t* num);
void     feonumm20n1_tan_to(   feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_cos(      feonumm20n1_t* num);
void     feonumm20n1_cos_to(   feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_sin(      feonumm20n1_t* num);
void     feonumm20n1_sin_to(   feonumm20n1_t* num, feonumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm20n1_t feonumm20n1_logb(     feonumm20n1_t* num, double base);
void     feonumm20n1_logb_to(  feonumm20n1_t* num, double base, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_log10(    feonumm20n1_t* num);
void     feonumm20n1_log10_to( feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_log(      feonumm20n1_t* num);
void     feonumm20n1_log_to(   feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_exp(      feonumm20n1_t* num);
void     feonumm20n1_exp_to(   feonumm20n1_t* num, feonumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm20n1_t feonumm20n1_cbrt(     feonumm20n1_t* num);
void     feonumm20n1_cbrt_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_sqrt(     feonumm20n1_t* num);
void     feonumm20n1_sqrt_to(  feonumm20n1_t* num, feonumm20n1_t* res);

feonumm20n1_t feonumm20n1_pow(      feonumm20n1_t* num, double e);
void     feonumm20n1_pow_to(   feonumm20n1_t* num, double e, feonumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm20n1_t feonumm20n1_integrate(       feonumm20n1_t* num, feonumm20n1_t* w);
void      feonumm20n1_integrate_to(    feonumm20n1_t* num, feonumm20n1_t* w, onumm20n1_t* res);

onumm20n1_t feonumm20n1_integrate_f(     feonumm20n1_t* num, feonumm20n1_t* w);
void      feonumm20n1_integrate_f_to(  feonumm20n1_t* num, feonumm20n1_t* w, onumm20n1_t* res);

onumm20n1_t feonumm20n1_integrate_r(       coeff_t num, feonumm20n1_t* w);
void      feonumm20n1_integrate_r_to(    coeff_t num, feonumm20n1_t* w, onumm20n1_t* res);

onumm20n1_t feonumm20n1_integrate_o(    onumm20n1_t* num, feonumm20n1_t* w);
void      feonumm20n1_integrate_o_to( onumm20n1_t* num, feonumm20n1_t* w, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif