#ifndef OTI_ONUMM1N30_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N30_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n30_t feoarrm1n30_atanh(    feoarrm1n30_t* arr);
void      feoarrm1n30_atanh_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_asinh(    feoarrm1n30_t* arr);
void      feoarrm1n30_asinh_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_acosh(    feoarrm1n30_t* arr);
void      feoarrm1n30_acosh_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n30_t feoarrm1n30_tanh(     feoarrm1n30_t* arr);
void      feoarrm1n30_tanh_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_sinh(     feoarrm1n30_t* arr);
void      feoarrm1n30_sinh_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_cosh(     feoarrm1n30_t* arr);
void      feoarrm1n30_cosh_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n30_t feoarrm1n30_atan(     feoarrm1n30_t* arr);
void      feoarrm1n30_atan_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_asin(     feoarrm1n30_t* arr);
void      feoarrm1n30_asin_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_acos(     feoarrm1n30_t* arr);
void      feoarrm1n30_acos_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n30_t feoarrm1n30_tan(      feoarrm1n30_t* arr);
void      feoarrm1n30_tan_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_sin(      feoarrm1n30_t* arr);
void      feoarrm1n30_sin_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_cos(      feoarrm1n30_t* arr);
void      feoarrm1n30_cos_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n30_t feoarrm1n30_logb(     feoarrm1n30_t* arr, double base);
void      feoarrm1n30_logb_to(  feoarrm1n30_t* arr, double base, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_log10(    feoarrm1n30_t* arr);
void      feoarrm1n30_log10_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_log(      feoarrm1n30_t* arr);
void      feoarrm1n30_log_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_exp(      feoarrm1n30_t* arr);
void      feoarrm1n30_exp_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n30_t feoarrm1n30_cbrt(     feoarrm1n30_t* arr);
void      feoarrm1n30_cbrt_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_sqrt(     feoarrm1n30_t* arr);
void      feoarrm1n30_sqrt_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
feoarrm1n30_t feoarrm1n30_pow(      feoarrm1n30_t* arr, double e);
void      feoarrm1n30_pow_to(   feoarrm1n30_t* arr, double e, feoarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

#endif