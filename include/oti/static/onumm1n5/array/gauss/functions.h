#ifndef OTI_ONUMM1N5_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N5_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n5_t feoarrm1n5_atanh(    feoarrm1n5_t* arr);
void      feoarrm1n5_atanh_to( feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_asinh(    feoarrm1n5_t* arr);
void      feoarrm1n5_asinh_to( feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_acosh(    feoarrm1n5_t* arr);
void      feoarrm1n5_acosh_to( feoarrm1n5_t* arr, feoarrm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n5_t feoarrm1n5_tanh(     feoarrm1n5_t* arr);
void      feoarrm1n5_tanh_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_sinh(     feoarrm1n5_t* arr);
void      feoarrm1n5_sinh_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_cosh(     feoarrm1n5_t* arr);
void      feoarrm1n5_cosh_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n5_t feoarrm1n5_atan(     feoarrm1n5_t* arr);
void      feoarrm1n5_atan_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_asin(     feoarrm1n5_t* arr);
void      feoarrm1n5_asin_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_acos(     feoarrm1n5_t* arr);
void      feoarrm1n5_acos_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n5_t feoarrm1n5_tan(      feoarrm1n5_t* arr);
void      feoarrm1n5_tan_to(   feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_sin(      feoarrm1n5_t* arr);
void      feoarrm1n5_sin_to(   feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_cos(      feoarrm1n5_t* arr);
void      feoarrm1n5_cos_to(   feoarrm1n5_t* arr, feoarrm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n5_t feoarrm1n5_logb(     feoarrm1n5_t* arr, double base);
void      feoarrm1n5_logb_to(  feoarrm1n5_t* arr, double base, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_log10(    feoarrm1n5_t* arr);
void      feoarrm1n5_log10_to( feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_log(      feoarrm1n5_t* arr);
void      feoarrm1n5_log_to(   feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_exp(      feoarrm1n5_t* arr);
void      feoarrm1n5_exp_to(   feoarrm1n5_t* arr, feoarrm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n5_t feoarrm1n5_cbrt(     feoarrm1n5_t* arr);
void      feoarrm1n5_cbrt_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_sqrt(     feoarrm1n5_t* arr);
void      feoarrm1n5_sqrt_to(  feoarrm1n5_t* arr, feoarrm1n5_t* res);
feoarrm1n5_t feoarrm1n5_pow(      feoarrm1n5_t* arr, double e);
void      feoarrm1n5_pow_to(   feoarrm1n5_t* arr, double e, feoarrm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif