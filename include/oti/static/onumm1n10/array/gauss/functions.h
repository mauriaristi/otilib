#ifndef OTI_ONUMM1N10_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N10_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n10_t feoarrm1n10_atanh(    feoarrm1n10_t* arr);
void      feoarrm1n10_atanh_to( feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_asinh(    feoarrm1n10_t* arr);
void      feoarrm1n10_asinh_to( feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_acosh(    feoarrm1n10_t* arr);
void      feoarrm1n10_acosh_to( feoarrm1n10_t* arr, feoarrm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n10_t feoarrm1n10_tanh(     feoarrm1n10_t* arr);
void      feoarrm1n10_tanh_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_sinh(     feoarrm1n10_t* arr);
void      feoarrm1n10_sinh_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_cosh(     feoarrm1n10_t* arr);
void      feoarrm1n10_cosh_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n10_t feoarrm1n10_atan(     feoarrm1n10_t* arr);
void      feoarrm1n10_atan_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_asin(     feoarrm1n10_t* arr);
void      feoarrm1n10_asin_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_acos(     feoarrm1n10_t* arr);
void      feoarrm1n10_acos_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n10_t feoarrm1n10_tan(      feoarrm1n10_t* arr);
void      feoarrm1n10_tan_to(   feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_sin(      feoarrm1n10_t* arr);
void      feoarrm1n10_sin_to(   feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_cos(      feoarrm1n10_t* arr);
void      feoarrm1n10_cos_to(   feoarrm1n10_t* arr, feoarrm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n10_t feoarrm1n10_logb(     feoarrm1n10_t* arr, double base);
void      feoarrm1n10_logb_to(  feoarrm1n10_t* arr, double base, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_log10(    feoarrm1n10_t* arr);
void      feoarrm1n10_log10_to( feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_log(      feoarrm1n10_t* arr);
void      feoarrm1n10_log_to(   feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_exp(      feoarrm1n10_t* arr);
void      feoarrm1n10_exp_to(   feoarrm1n10_t* arr, feoarrm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n10_t feoarrm1n10_cbrt(     feoarrm1n10_t* arr);
void      feoarrm1n10_cbrt_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_sqrt(     feoarrm1n10_t* arr);
void      feoarrm1n10_sqrt_to(  feoarrm1n10_t* arr, feoarrm1n10_t* res);
feoarrm1n10_t feoarrm1n10_pow(      feoarrm1n10_t* arr, double e);
void      feoarrm1n10_pow_to(   feoarrm1n10_t* arr, double e, feoarrm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif