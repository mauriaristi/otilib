#ifndef OTI_ONUMM4N4_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N4_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n4_t feoarrm4n4_atanh(    feoarrm4n4_t* arr);
void      feoarrm4n4_atanh_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_asinh(    feoarrm4n4_t* arr);
void      feoarrm4n4_asinh_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_acosh(    feoarrm4n4_t* arr);
void      feoarrm4n4_acosh_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n4_t feoarrm4n4_tanh(     feoarrm4n4_t* arr);
void      feoarrm4n4_tanh_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_sinh(     feoarrm4n4_t* arr);
void      feoarrm4n4_sinh_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_cosh(     feoarrm4n4_t* arr);
void      feoarrm4n4_cosh_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n4_t feoarrm4n4_atan(     feoarrm4n4_t* arr);
void      feoarrm4n4_atan_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_asin(     feoarrm4n4_t* arr);
void      feoarrm4n4_asin_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_acos(     feoarrm4n4_t* arr);
void      feoarrm4n4_acos_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n4_t feoarrm4n4_tan(      feoarrm4n4_t* arr);
void      feoarrm4n4_tan_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_sin(      feoarrm4n4_t* arr);
void      feoarrm4n4_sin_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_cos(      feoarrm4n4_t* arr);
void      feoarrm4n4_cos_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm4n4_t feoarrm4n4_logb(     feoarrm4n4_t* arr, double base);
void      feoarrm4n4_logb_to(  feoarrm4n4_t* arr, double base, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_log10(    feoarrm4n4_t* arr);
void      feoarrm4n4_log10_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_log(      feoarrm4n4_t* arr);
void      feoarrm4n4_log_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_exp(      feoarrm4n4_t* arr);
void      feoarrm4n4_exp_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n4_t feoarrm4n4_cbrt(     feoarrm4n4_t* arr);
void      feoarrm4n4_cbrt_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_sqrt(     feoarrm4n4_t* arr);
void      feoarrm4n4_sqrt_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
feoarrm4n4_t feoarrm4n4_pow(      feoarrm4n4_t* arr, double e);
void      feoarrm4n4_pow_to(   feoarrm4n4_t* arr, double e, feoarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif