#ifndef OTI_ONUMM1N7_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N7_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n7_t feoarrm1n7_atanh(    feoarrm1n7_t* arr);
void      feoarrm1n7_atanh_to( feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_asinh(    feoarrm1n7_t* arr);
void      feoarrm1n7_asinh_to( feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_acosh(    feoarrm1n7_t* arr);
void      feoarrm1n7_acosh_to( feoarrm1n7_t* arr, feoarrm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n7_t feoarrm1n7_tanh(     feoarrm1n7_t* arr);
void      feoarrm1n7_tanh_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_sinh(     feoarrm1n7_t* arr);
void      feoarrm1n7_sinh_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_cosh(     feoarrm1n7_t* arr);
void      feoarrm1n7_cosh_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n7_t feoarrm1n7_atan(     feoarrm1n7_t* arr);
void      feoarrm1n7_atan_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_asin(     feoarrm1n7_t* arr);
void      feoarrm1n7_asin_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_acos(     feoarrm1n7_t* arr);
void      feoarrm1n7_acos_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n7_t feoarrm1n7_tan(      feoarrm1n7_t* arr);
void      feoarrm1n7_tan_to(   feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_sin(      feoarrm1n7_t* arr);
void      feoarrm1n7_sin_to(   feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_cos(      feoarrm1n7_t* arr);
void      feoarrm1n7_cos_to(   feoarrm1n7_t* arr, feoarrm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n7_t feoarrm1n7_logb(     feoarrm1n7_t* arr, double base);
void      feoarrm1n7_logb_to(  feoarrm1n7_t* arr, double base, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_log10(    feoarrm1n7_t* arr);
void      feoarrm1n7_log10_to( feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_log(      feoarrm1n7_t* arr);
void      feoarrm1n7_log_to(   feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_exp(      feoarrm1n7_t* arr);
void      feoarrm1n7_exp_to(   feoarrm1n7_t* arr, feoarrm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n7_t feoarrm1n7_cbrt(     feoarrm1n7_t* arr);
void      feoarrm1n7_cbrt_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_sqrt(     feoarrm1n7_t* arr);
void      feoarrm1n7_sqrt_to(  feoarrm1n7_t* arr, feoarrm1n7_t* res);
feoarrm1n7_t feoarrm1n7_pow(      feoarrm1n7_t* arr, double e);
void      feoarrm1n7_pow_to(   feoarrm1n7_t* arr, double e, feoarrm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif