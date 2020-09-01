#ifndef OTI_ONUMM5N1_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N1_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_atanh(    feonumm5n1_t* num);
void     feonumm5n1_atanh_to( feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_asinh(    feonumm5n1_t* num);
void     feonumm5n1_asinh_to( feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_acosh(    feonumm5n1_t* num);
void     feonumm5n1_acosh_to( feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_tanh(     feonumm5n1_t* num);
void     feonumm5n1_tanh_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_cosh(     feonumm5n1_t* num);
void     feonumm5n1_cosh_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sinh(     feonumm5n1_t* num);
void     feonumm5n1_sinh_to(  feonumm5n1_t* num, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_asin(     feonumm5n1_t* num);
void     feonumm5n1_asin_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_acos(     feonumm5n1_t* num);
void     feonumm5n1_acos_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_atan(     feonumm5n1_t* num);
void     feonumm5n1_atan_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_tan(      feonumm5n1_t* num);
void     feonumm5n1_tan_to(   feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_cos(      feonumm5n1_t* num);
void     feonumm5n1_cos_to(   feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sin(      feonumm5n1_t* num);
void     feonumm5n1_sin_to(   feonumm5n1_t* num, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_logb(     feonumm5n1_t* num, double base);
void     feonumm5n1_logb_to(  feonumm5n1_t* num, double base, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_log10(    feonumm5n1_t* num);
void     feonumm5n1_log10_to( feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_log(      feonumm5n1_t* num);
void     feonumm5n1_log_to(   feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_exp(      feonumm5n1_t* num);
void     feonumm5n1_exp_to(   feonumm5n1_t* num, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_cbrt(     feonumm5n1_t* num);
void     feonumm5n1_cbrt_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sqrt(     feonumm5n1_t* num);
void     feonumm5n1_sqrt_to(  feonumm5n1_t* num, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_pow(      feonumm5n1_t* num, double e);
void     feonumm5n1_pow_to(   feonumm5n1_t* num, double e, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm5n1_t feonumm5n1_integrate(       feonumm5n1_t* num, feonumm5n1_t* w);
void      feonumm5n1_integrate_to(    feonumm5n1_t* num, feonumm5n1_t* w, onumm5n1_t* res);

onumm5n1_t feonumm5n1_integrate_f(     feonumm5n1_t* num, feonumm5n1_t* w);
void      feonumm5n1_integrate_f_to(  feonumm5n1_t* num, feonumm5n1_t* w, onumm5n1_t* res);

onumm5n1_t feonumm5n1_integrate_r(       coeff_t num, feonumm5n1_t* w);
void      feonumm5n1_integrate_r_to(    coeff_t num, feonumm5n1_t* w, onumm5n1_t* res);

onumm5n1_t feonumm5n1_integrate_o(    onumm5n1_t* num, feonumm5n1_t* w);
void      feonumm5n1_integrate_o_to( onumm5n1_t* num, feonumm5n1_t* w, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif