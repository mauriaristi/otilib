#ifndef OTI_ONUMM4N5_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N5_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n5_t feoarrm4n5_atanh(    feoarrm4n5_t* arr);
void      feoarrm4n5_atanh_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_asinh(    feoarrm4n5_t* arr);
void      feoarrm4n5_asinh_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_acosh(    feoarrm4n5_t* arr);
void      feoarrm4n5_acosh_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n5_t feoarrm4n5_tanh(     feoarrm4n5_t* arr);
void      feoarrm4n5_tanh_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_sinh(     feoarrm4n5_t* arr);
void      feoarrm4n5_sinh_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_cosh(     feoarrm4n5_t* arr);
void      feoarrm4n5_cosh_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n5_t feoarrm4n5_atan(     feoarrm4n5_t* arr);
void      feoarrm4n5_atan_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_asin(     feoarrm4n5_t* arr);
void      feoarrm4n5_asin_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_acos(     feoarrm4n5_t* arr);
void      feoarrm4n5_acos_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n5_t feoarrm4n5_tan(      feoarrm4n5_t* arr);
void      feoarrm4n5_tan_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_sin(      feoarrm4n5_t* arr);
void      feoarrm4n5_sin_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_cos(      feoarrm4n5_t* arr);
void      feoarrm4n5_cos_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm4n5_t feoarrm4n5_logb(     feoarrm4n5_t* arr, double base);
void      feoarrm4n5_logb_to(  feoarrm4n5_t* arr, double base, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_log10(    feoarrm4n5_t* arr);
void      feoarrm4n5_log10_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_log(      feoarrm4n5_t* arr);
void      feoarrm4n5_log_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_exp(      feoarrm4n5_t* arr);
void      feoarrm4n5_exp_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n5_t feoarrm4n5_cbrt(     feoarrm4n5_t* arr);
void      feoarrm4n5_cbrt_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_sqrt(     feoarrm4n5_t* arr);
void      feoarrm4n5_sqrt_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
feoarrm4n5_t feoarrm4n5_pow(      feoarrm4n5_t* arr, double e);
void      feoarrm4n5_pow_to(   feoarrm4n5_t* arr, double e, feoarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif