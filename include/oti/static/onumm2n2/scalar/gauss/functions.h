#ifndef OTI_ONUMM2N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n2_t feonumm2n2_atanh(    feonumm2n2_t* num);
void     feonumm2n2_atanh_to( feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_asinh(    feonumm2n2_t* num);
void     feonumm2n2_asinh_to( feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_acosh(    feonumm2n2_t* num);
void     feonumm2n2_acosh_to( feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_tanh(     feonumm2n2_t* num);
void     feonumm2n2_tanh_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_cosh(     feonumm2n2_t* num);
void     feonumm2n2_cosh_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_sinh(     feonumm2n2_t* num);
void     feonumm2n2_sinh_to(  feonumm2n2_t* num, feonumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n2_t feonumm2n2_asin(     feonumm2n2_t* num);
void     feonumm2n2_asin_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_acos(     feonumm2n2_t* num);
void     feonumm2n2_acos_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_atan(     feonumm2n2_t* num);
void     feonumm2n2_atan_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_tan(      feonumm2n2_t* num);
void     feonumm2n2_tan_to(   feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_cos(      feonumm2n2_t* num);
void     feonumm2n2_cos_to(   feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_sin(      feonumm2n2_t* num);
void     feonumm2n2_sin_to(   feonumm2n2_t* num, feonumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n2_t feonumm2n2_logb(     feonumm2n2_t* num, double base);
void     feonumm2n2_logb_to(  feonumm2n2_t* num, double base, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_log10(    feonumm2n2_t* num);
void     feonumm2n2_log10_to( feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_log(      feonumm2n2_t* num);
void     feonumm2n2_log_to(   feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_exp(      feonumm2n2_t* num);
void     feonumm2n2_exp_to(   feonumm2n2_t* num, feonumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n2_t feonumm2n2_cbrt(     feonumm2n2_t* num);
void     feonumm2n2_cbrt_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_sqrt(     feonumm2n2_t* num);
void     feonumm2n2_sqrt_to(  feonumm2n2_t* num, feonumm2n2_t* res);

feonumm2n2_t feonumm2n2_pow(      feonumm2n2_t* num, double e);
void     feonumm2n2_pow_to(   feonumm2n2_t* num, double e, feonumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm2n2_t feonumm2n2_integrate(       feonumm2n2_t* num, feonumm2n2_t* w);
void      feonumm2n2_integrate_to(    feonumm2n2_t* num, feonumm2n2_t* w, onumm2n2_t* res);

onumm2n2_t feonumm2n2_integrate_f(     feonumm2n2_t* num, feonumm2n2_t* w);
void      feonumm2n2_integrate_f_to(  feonumm2n2_t* num, feonumm2n2_t* w, onumm2n2_t* res);

onumm2n2_t feonumm2n2_integrate_r(       coeff_t num, feonumm2n2_t* w);
void      feonumm2n2_integrate_r_to(    coeff_t num, feonumm2n2_t* w, onumm2n2_t* res);

onumm2n2_t feonumm2n2_integrate_o(    onumm2n2_t* num, feonumm2n2_t* w);
void      feonumm2n2_integrate_o_to( onumm2n2_t* num, feonumm2n2_t* w, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif