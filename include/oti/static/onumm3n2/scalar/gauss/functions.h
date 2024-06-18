#ifndef OTI_ONUMM3N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_atanh(    feonumm3n2_t* num);
void     feonumm3n2_atanh_to( feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_asinh(    feonumm3n2_t* num);
void     feonumm3n2_asinh_to( feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_acosh(    feonumm3n2_t* num);
void     feonumm3n2_acosh_to( feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_tanh(     feonumm3n2_t* num);
void     feonumm3n2_tanh_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_cosh(     feonumm3n2_t* num);
void     feonumm3n2_cosh_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sinh(     feonumm3n2_t* num);
void     feonumm3n2_sinh_to(  feonumm3n2_t* num, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_asin(     feonumm3n2_t* num);
void     feonumm3n2_asin_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_acos(     feonumm3n2_t* num);
void     feonumm3n2_acos_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_atan(     feonumm3n2_t* num);
void     feonumm3n2_atan_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_tan(      feonumm3n2_t* num);
void     feonumm3n2_tan_to(   feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_cos(      feonumm3n2_t* num);
void     feonumm3n2_cos_to(   feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sin(      feonumm3n2_t* num);
void     feonumm3n2_sin_to(   feonumm3n2_t* num, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_logb(     feonumm3n2_t* num, double base);
void     feonumm3n2_logb_to(  feonumm3n2_t* num, double base, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_log10(    feonumm3n2_t* num);
void     feonumm3n2_log10_to( feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_log(      feonumm3n2_t* num);
void     feonumm3n2_log_to(   feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_exp(      feonumm3n2_t* num);
void     feonumm3n2_exp_to(   feonumm3n2_t* num, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_cbrt(     feonumm3n2_t* num);
void     feonumm3n2_cbrt_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sqrt(     feonumm3n2_t* num);
void     feonumm3n2_sqrt_to(  feonumm3n2_t* num, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_pow(      feonumm3n2_t* num, double e);
void     feonumm3n2_pow_to(   feonumm3n2_t* num, double e, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm3n2_t feonumm3n2_integrate(       feonumm3n2_t* num, feonumm3n2_t* w);
void      feonumm3n2_integrate_to(    feonumm3n2_t* num, feonumm3n2_t* w, onumm3n2_t* res);

onumm3n2_t feonumm3n2_integrate_f(     feonumm3n2_t* num, feonumm3n2_t* w);
void      feonumm3n2_integrate_f_to(  feonumm3n2_t* num, feonumm3n2_t* w, onumm3n2_t* res);

onumm3n2_t feonumm3n2_integrate_r(       coeff_t num, feonumm3n2_t* w);
void      feonumm3n2_integrate_r_to(    coeff_t num, feonumm3n2_t* w, onumm3n2_t* res);

onumm3n2_t feonumm3n2_integrate_o(    onumm3n2_t* num, feonumm3n2_t* w);
void      feonumm3n2_integrate_o_to( onumm3n2_t* num, feonumm3n2_t* w, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif