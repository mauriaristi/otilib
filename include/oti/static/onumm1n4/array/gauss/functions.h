#ifndef OTI_ONUMM1N4_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N4_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n4_t feoarrm1n4_atanh(    feoarrm1n4_t* arr);
void      feoarrm1n4_atanh_to( feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_asinh(    feoarrm1n4_t* arr);
void      feoarrm1n4_asinh_to( feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_acosh(    feoarrm1n4_t* arr);
void      feoarrm1n4_acosh_to( feoarrm1n4_t* arr, feoarrm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n4_t feoarrm1n4_tanh(     feoarrm1n4_t* arr);
void      feoarrm1n4_tanh_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_sinh(     feoarrm1n4_t* arr);
void      feoarrm1n4_sinh_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_cosh(     feoarrm1n4_t* arr);
void      feoarrm1n4_cosh_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n4_t feoarrm1n4_atan(     feoarrm1n4_t* arr);
void      feoarrm1n4_atan_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_asin(     feoarrm1n4_t* arr);
void      feoarrm1n4_asin_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_acos(     feoarrm1n4_t* arr);
void      feoarrm1n4_acos_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n4_t feoarrm1n4_tan(      feoarrm1n4_t* arr);
void      feoarrm1n4_tan_to(   feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_sin(      feoarrm1n4_t* arr);
void      feoarrm1n4_sin_to(   feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_cos(      feoarrm1n4_t* arr);
void      feoarrm1n4_cos_to(   feoarrm1n4_t* arr, feoarrm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n4_t feoarrm1n4_logb(     feoarrm1n4_t* arr, double base);
void      feoarrm1n4_logb_to(  feoarrm1n4_t* arr, double base, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_log10(    feoarrm1n4_t* arr);
void      feoarrm1n4_log10_to( feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_log(      feoarrm1n4_t* arr);
void      feoarrm1n4_log_to(   feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_exp(      feoarrm1n4_t* arr);
void      feoarrm1n4_exp_to(   feoarrm1n4_t* arr, feoarrm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n4_t feoarrm1n4_cbrt(     feoarrm1n4_t* arr);
void      feoarrm1n4_cbrt_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_sqrt(     feoarrm1n4_t* arr);
void      feoarrm1n4_sqrt_to(  feoarrm1n4_t* arr, feoarrm1n4_t* res);
feoarrm1n4_t feoarrm1n4_pow(      feoarrm1n4_t* arr, double e);
void      feoarrm1n4_pow_to(   feoarrm1n4_t* arr, double e, feoarrm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif