#ifndef OTI_ONUMM5N2_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N2_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n2_t feonumm5n2_atanh(    feonumm5n2_t* num);
void     feonumm5n2_atanh_to( feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_asinh(    feonumm5n2_t* num);
void     feonumm5n2_asinh_to( feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_acosh(    feonumm5n2_t* num);
void     feonumm5n2_acosh_to( feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_tanh(     feonumm5n2_t* num);
void     feonumm5n2_tanh_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_cosh(     feonumm5n2_t* num);
void     feonumm5n2_cosh_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_sinh(     feonumm5n2_t* num);
void     feonumm5n2_sinh_to(  feonumm5n2_t* num, feonumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n2_t feonumm5n2_asin(     feonumm5n2_t* num);
void     feonumm5n2_asin_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_acos(     feonumm5n2_t* num);
void     feonumm5n2_acos_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_atan(     feonumm5n2_t* num);
void     feonumm5n2_atan_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_tan(      feonumm5n2_t* num);
void     feonumm5n2_tan_to(   feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_cos(      feonumm5n2_t* num);
void     feonumm5n2_cos_to(   feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_sin(      feonumm5n2_t* num);
void     feonumm5n2_sin_to(   feonumm5n2_t* num, feonumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n2_t feonumm5n2_logb(     feonumm5n2_t* num, double base);
void     feonumm5n2_logb_to(  feonumm5n2_t* num, double base, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_log10(    feonumm5n2_t* num);
void     feonumm5n2_log10_to( feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_log(      feonumm5n2_t* num);
void     feonumm5n2_log_to(   feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_exp(      feonumm5n2_t* num);
void     feonumm5n2_exp_to(   feonumm5n2_t* num, feonumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n2_t feonumm5n2_cbrt(     feonumm5n2_t* num);
void     feonumm5n2_cbrt_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_sqrt(     feonumm5n2_t* num);
void     feonumm5n2_sqrt_to(  feonumm5n2_t* num, feonumm5n2_t* res);

feonumm5n2_t feonumm5n2_pow(      feonumm5n2_t* num, double e);
void     feonumm5n2_pow_to(   feonumm5n2_t* num, double e, feonumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
onumm5n2_t feonumm5n2_integrate(       feonumm5n2_t* num, feonumm5n2_t* w);
void      feonumm5n2_integrate_to(    feonumm5n2_t* num, feonumm5n2_t* w, onumm5n2_t* res);

onumm5n2_t feonumm5n2_integrate_f(     feonumm5n2_t* num, feonumm5n2_t* w);
void      feonumm5n2_integrate_f_to(  feonumm5n2_t* num, feonumm5n2_t* w, onumm5n2_t* res);

onumm5n2_t feonumm5n2_integrate_r(       coeff_t num, feonumm5n2_t* w);
void      feonumm5n2_integrate_r_to(    coeff_t num, feonumm5n2_t* w, onumm5n2_t* res);

onumm5n2_t feonumm5n2_integrate_o(    onumm5n2_t* num, feonumm5n2_t* w);
void      feonumm5n2_integrate_o_to( onumm5n2_t* num, feonumm5n2_t* w, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif