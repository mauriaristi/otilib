#ifndef OTI_ONUMM9N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM9N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_atanh(    feonumm9n2_t* num);
void     feonumm9n2_atanh_to( feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_asinh(    feonumm9n2_t* num);
void     feonumm9n2_asinh_to( feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_acosh(    feonumm9n2_t* num);
void     feonumm9n2_acosh_to( feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_tanh(     feonumm9n2_t* num);
void     feonumm9n2_tanh_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_cosh(     feonumm9n2_t* num);
void     feonumm9n2_cosh_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sinh(     feonumm9n2_t* num);
void     feonumm9n2_sinh_to(  feonumm9n2_t* num, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_asin(     feonumm9n2_t* num);
void     feonumm9n2_asin_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_acos(     feonumm9n2_t* num);
void     feonumm9n2_acos_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_atan(     feonumm9n2_t* num);
void     feonumm9n2_atan_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_tan(      feonumm9n2_t* num);
void     feonumm9n2_tan_to(   feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_cos(      feonumm9n2_t* num);
void     feonumm9n2_cos_to(   feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sin(      feonumm9n2_t* num);
void     feonumm9n2_sin_to(   feonumm9n2_t* num, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_logb(     feonumm9n2_t* num, double base);
void     feonumm9n2_logb_to(  feonumm9n2_t* num, double base, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_log10(    feonumm9n2_t* num);
void     feonumm9n2_log10_to( feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_log(      feonumm9n2_t* num);
void     feonumm9n2_log_to(   feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_exp(      feonumm9n2_t* num);
void     feonumm9n2_exp_to(   feonumm9n2_t* num, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_cbrt(     feonumm9n2_t* num);
void     feonumm9n2_cbrt_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sqrt(     feonumm9n2_t* num);
void     feonumm9n2_sqrt_to(  feonumm9n2_t* num, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_pow(      feonumm9n2_t* num, double e);
void     feonumm9n2_pow_to(   feonumm9n2_t* num, double e, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm9n2_t feonumm9n2_integrate(       feonumm9n2_t* num, feonumm9n2_t* w);
void      feonumm9n2_integrate_to(    feonumm9n2_t* num, feonumm9n2_t* w, onumm9n2_t* res);

onumm9n2_t feonumm9n2_integrate_f(     feonumm9n2_t* num, feonumm9n2_t* w);
void      feonumm9n2_integrate_f_to(  feonumm9n2_t* num, feonumm9n2_t* w, onumm9n2_t* res);

onumm9n2_t feonumm9n2_integrate_r(       coeff_t num, feonumm9n2_t* w);
void      feonumm9n2_integrate_r_to(    coeff_t num, feonumm9n2_t* w, onumm9n2_t* res);

onumm9n2_t feonumm9n2_integrate_o(    onumm9n2_t* num, feonumm9n2_t* w);
void      feonumm9n2_integrate_o_to( onumm9n2_t* num, feonumm9n2_t* w, onumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif