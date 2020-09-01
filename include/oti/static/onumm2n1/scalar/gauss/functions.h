#ifndef OTI_ONUMM2N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n1_t feonumm2n1_atanh(    feonumm2n1_t* num);
void     feonumm2n1_atanh_to( feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_asinh(    feonumm2n1_t* num);
void     feonumm2n1_asinh_to( feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_acosh(    feonumm2n1_t* num);
void     feonumm2n1_acosh_to( feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_tanh(     feonumm2n1_t* num);
void     feonumm2n1_tanh_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_cosh(     feonumm2n1_t* num);
void     feonumm2n1_cosh_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_sinh(     feonumm2n1_t* num);
void     feonumm2n1_sinh_to(  feonumm2n1_t* num, feonumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n1_t feonumm2n1_asin(     feonumm2n1_t* num);
void     feonumm2n1_asin_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_acos(     feonumm2n1_t* num);
void     feonumm2n1_acos_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_atan(     feonumm2n1_t* num);
void     feonumm2n1_atan_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_tan(      feonumm2n1_t* num);
void     feonumm2n1_tan_to(   feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_cos(      feonumm2n1_t* num);
void     feonumm2n1_cos_to(   feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_sin(      feonumm2n1_t* num);
void     feonumm2n1_sin_to(   feonumm2n1_t* num, feonumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n1_t feonumm2n1_logb(     feonumm2n1_t* num, double base);
void     feonumm2n1_logb_to(  feonumm2n1_t* num, double base, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_log10(    feonumm2n1_t* num);
void     feonumm2n1_log10_to( feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_log(      feonumm2n1_t* num);
void     feonumm2n1_log_to(   feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_exp(      feonumm2n1_t* num);
void     feonumm2n1_exp_to(   feonumm2n1_t* num, feonumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n1_t feonumm2n1_cbrt(     feonumm2n1_t* num);
void     feonumm2n1_cbrt_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_sqrt(     feonumm2n1_t* num);
void     feonumm2n1_sqrt_to(  feonumm2n1_t* num, feonumm2n1_t* res);

feonumm2n1_t feonumm2n1_pow(      feonumm2n1_t* num, double e);
void     feonumm2n1_pow_to(   feonumm2n1_t* num, double e, feonumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n1_t feonumm2n1_integrate(       feonumm2n1_t* num, feonumm2n1_t* w);
void      feonumm2n1_integrate_to(    feonumm2n1_t* num, feonumm2n1_t* w, onumm2n1_t* res);

onumm2n1_t feonumm2n1_integrate_f(     feonumm2n1_t* num, feonumm2n1_t* w);
void      feonumm2n1_integrate_f_to(  feonumm2n1_t* num, feonumm2n1_t* w, onumm2n1_t* res);

onumm2n1_t feonumm2n1_integrate_r(       coeff_t num, feonumm2n1_t* w);
void      feonumm2n1_integrate_r_to(    coeff_t num, feonumm2n1_t* w, onumm2n1_t* res);

onumm2n1_t feonumm2n1_integrate_o(    onumm2n1_t* num, feonumm2n1_t* w);
void      feonumm2n1_integrate_o_to( onumm2n1_t* num, feonumm2n1_t* w, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif