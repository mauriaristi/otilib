#ifndef OTI_ONUMM5N3_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N3_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_atanh(    feonumm5n3_t* num);
void     feonumm5n3_atanh_to( feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_asinh(    feonumm5n3_t* num);
void     feonumm5n3_asinh_to( feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_acosh(    feonumm5n3_t* num);
void     feonumm5n3_acosh_to( feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_tanh(     feonumm5n3_t* num);
void     feonumm5n3_tanh_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_cosh(     feonumm5n3_t* num);
void     feonumm5n3_cosh_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sinh(     feonumm5n3_t* num);
void     feonumm5n3_sinh_to(  feonumm5n3_t* num, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_asin(     feonumm5n3_t* num);
void     feonumm5n3_asin_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_acos(     feonumm5n3_t* num);
void     feonumm5n3_acos_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_atan(     feonumm5n3_t* num);
void     feonumm5n3_atan_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_tan(      feonumm5n3_t* num);
void     feonumm5n3_tan_to(   feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_cos(      feonumm5n3_t* num);
void     feonumm5n3_cos_to(   feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sin(      feonumm5n3_t* num);
void     feonumm5n3_sin_to(   feonumm5n3_t* num, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_logb(     feonumm5n3_t* num, double base);
void     feonumm5n3_logb_to(  feonumm5n3_t* num, double base, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_log10(    feonumm5n3_t* num);
void     feonumm5n3_log10_to( feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_log(      feonumm5n3_t* num);
void     feonumm5n3_log_to(   feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_exp(      feonumm5n3_t* num);
void     feonumm5n3_exp_to(   feonumm5n3_t* num, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_cbrt(     feonumm5n3_t* num);
void     feonumm5n3_cbrt_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sqrt(     feonumm5n3_t* num);
void     feonumm5n3_sqrt_to(  feonumm5n3_t* num, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_pow(      feonumm5n3_t* num, double e);
void     feonumm5n3_pow_to(   feonumm5n3_t* num, double e, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm5n3_t feonumm5n3_integrate(       feonumm5n3_t* num, feonumm5n3_t* w);
void      feonumm5n3_integrate_to(    feonumm5n3_t* num, feonumm5n3_t* w, onumm5n3_t* res);

onumm5n3_t feonumm5n3_integrate_f(     feonumm5n3_t* num, feonumm5n3_t* w);
void      feonumm5n3_integrate_f_to(  feonumm5n3_t* num, feonumm5n3_t* w, onumm5n3_t* res);

onumm5n3_t feonumm5n3_integrate_r(       coeff_t num, feonumm5n3_t* w);
void      feonumm5n3_integrate_r_to(    coeff_t num, feonumm5n3_t* w, onumm5n3_t* res);

onumm5n3_t feonumm5n3_integrate_o(    onumm5n3_t* num, feonumm5n3_t* w);
void      feonumm5n3_integrate_o_to( onumm5n3_t* num, feonumm5n3_t* w, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif