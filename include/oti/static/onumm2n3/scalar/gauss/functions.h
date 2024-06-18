#ifndef OTI_ONUMM2N3_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N3_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n3_t feonumm2n3_atanh(    feonumm2n3_t* num);
void     feonumm2n3_atanh_to( feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_asinh(    feonumm2n3_t* num);
void     feonumm2n3_asinh_to( feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_acosh(    feonumm2n3_t* num);
void     feonumm2n3_acosh_to( feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_tanh(     feonumm2n3_t* num);
void     feonumm2n3_tanh_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_cosh(     feonumm2n3_t* num);
void     feonumm2n3_cosh_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_sinh(     feonumm2n3_t* num);
void     feonumm2n3_sinh_to(  feonumm2n3_t* num, feonumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n3_t feonumm2n3_asin(     feonumm2n3_t* num);
void     feonumm2n3_asin_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_acos(     feonumm2n3_t* num);
void     feonumm2n3_acos_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_atan(     feonumm2n3_t* num);
void     feonumm2n3_atan_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_tan(      feonumm2n3_t* num);
void     feonumm2n3_tan_to(   feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_cos(      feonumm2n3_t* num);
void     feonumm2n3_cos_to(   feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_sin(      feonumm2n3_t* num);
void     feonumm2n3_sin_to(   feonumm2n3_t* num, feonumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n3_t feonumm2n3_logb(     feonumm2n3_t* num, double base);
void     feonumm2n3_logb_to(  feonumm2n3_t* num, double base, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_log10(    feonumm2n3_t* num);
void     feonumm2n3_log10_to( feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_log(      feonumm2n3_t* num);
void     feonumm2n3_log_to(   feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_exp(      feonumm2n3_t* num);
void     feonumm2n3_exp_to(   feonumm2n3_t* num, feonumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n3_t feonumm2n3_cbrt(     feonumm2n3_t* num);
void     feonumm2n3_cbrt_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_sqrt(     feonumm2n3_t* num);
void     feonumm2n3_sqrt_to(  feonumm2n3_t* num, feonumm2n3_t* res);

feonumm2n3_t feonumm2n3_pow(      feonumm2n3_t* num, double e);
void     feonumm2n3_pow_to(   feonumm2n3_t* num, double e, feonumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n3_t feonumm2n3_integrate(       feonumm2n3_t* num, feonumm2n3_t* w);
void      feonumm2n3_integrate_to(    feonumm2n3_t* num, feonumm2n3_t* w, onumm2n3_t* res);

onumm2n3_t feonumm2n3_integrate_f(     feonumm2n3_t* num, feonumm2n3_t* w);
void      feonumm2n3_integrate_f_to(  feonumm2n3_t* num, feonumm2n3_t* w, onumm2n3_t* res);

onumm2n3_t feonumm2n3_integrate_r(       coeff_t num, feonumm2n3_t* w);
void      feonumm2n3_integrate_r_to(    coeff_t num, feonumm2n3_t* w, onumm2n3_t* res);

onumm2n3_t feonumm2n3_integrate_o(    onumm2n3_t* num, feonumm2n3_t* w);
void      feonumm2n3_integrate_o_to( onumm2n3_t* num, feonumm2n3_t* w, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif