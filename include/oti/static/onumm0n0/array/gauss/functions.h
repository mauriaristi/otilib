#ifndef OTI_ONUMM0N0_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM0N0_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_atanh(    feoarrm0n0_t* arr);
void      feoarrm0n0_atanh_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_asinh(    feoarrm0n0_t* arr);
void      feoarrm0n0_asinh_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_acosh(    feoarrm0n0_t* arr);
void      feoarrm0n0_acosh_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_tanh(     feoarrm0n0_t* arr);
void      feoarrm0n0_tanh_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_sinh(     feoarrm0n0_t* arr);
void      feoarrm0n0_sinh_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_cosh(     feoarrm0n0_t* arr);
void      feoarrm0n0_cosh_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_atan(     feoarrm0n0_t* arr);
void      feoarrm0n0_atan_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_asin(     feoarrm0n0_t* arr);
void      feoarrm0n0_asin_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_acos(     feoarrm0n0_t* arr);
void      feoarrm0n0_acos_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_tan(      feoarrm0n0_t* arr);
void      feoarrm0n0_tan_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_sin(      feoarrm0n0_t* arr);
void      feoarrm0n0_sin_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_cos(      feoarrm0n0_t* arr);
void      feoarrm0n0_cos_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_logb(     feoarrm0n0_t* arr, double base);
void      feoarrm0n0_logb_to(  feoarrm0n0_t* arr, double base, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_log10(    feoarrm0n0_t* arr);
void      feoarrm0n0_log10_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_log(      feoarrm0n0_t* arr);
void      feoarrm0n0_log_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_exp(      feoarrm0n0_t* arr);
void      feoarrm0n0_exp_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_cbrt(     feoarrm0n0_t* arr);
void      feoarrm0n0_cbrt_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_sqrt(     feoarrm0n0_t* arr);
void      feoarrm0n0_sqrt_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
feoarrm0n0_t feoarrm0n0_pow(      feoarrm0n0_t* arr, double e);
void      feoarrm0n0_pow_to(   feoarrm0n0_t* arr, double e, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif