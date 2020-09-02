#ifndef OTI_ONUMM1N6_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N6_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n6_t feoarrm1n6_atanh(    feoarrm1n6_t* arr);
void      feoarrm1n6_atanh_to( feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_asinh(    feoarrm1n6_t* arr);
void      feoarrm1n6_asinh_to( feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_acosh(    feoarrm1n6_t* arr);
void      feoarrm1n6_acosh_to( feoarrm1n6_t* arr, feoarrm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n6_t feoarrm1n6_tanh(     feoarrm1n6_t* arr);
void      feoarrm1n6_tanh_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_sinh(     feoarrm1n6_t* arr);
void      feoarrm1n6_sinh_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_cosh(     feoarrm1n6_t* arr);
void      feoarrm1n6_cosh_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n6_t feoarrm1n6_atan(     feoarrm1n6_t* arr);
void      feoarrm1n6_atan_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_asin(     feoarrm1n6_t* arr);
void      feoarrm1n6_asin_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_acos(     feoarrm1n6_t* arr);
void      feoarrm1n6_acos_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n6_t feoarrm1n6_tan(      feoarrm1n6_t* arr);
void      feoarrm1n6_tan_to(   feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_sin(      feoarrm1n6_t* arr);
void      feoarrm1n6_sin_to(   feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_cos(      feoarrm1n6_t* arr);
void      feoarrm1n6_cos_to(   feoarrm1n6_t* arr, feoarrm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n6_t feoarrm1n6_logb(     feoarrm1n6_t* arr, double base);
void      feoarrm1n6_logb_to(  feoarrm1n6_t* arr, double base, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_log10(    feoarrm1n6_t* arr);
void      feoarrm1n6_log10_to( feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_log(      feoarrm1n6_t* arr);
void      feoarrm1n6_log_to(   feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_exp(      feoarrm1n6_t* arr);
void      feoarrm1n6_exp_to(   feoarrm1n6_t* arr, feoarrm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n6_t feoarrm1n6_cbrt(     feoarrm1n6_t* arr);
void      feoarrm1n6_cbrt_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_sqrt(     feoarrm1n6_t* arr);
void      feoarrm1n6_sqrt_to(  feoarrm1n6_t* arr, feoarrm1n6_t* res);
feoarrm1n6_t feoarrm1n6_pow(      feoarrm1n6_t* arr, double e);
void      feoarrm1n6_pow_to(   feoarrm1n6_t* arr, double e, feoarrm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif