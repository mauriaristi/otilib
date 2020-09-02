#ifndef OTI_ONUMM1N8_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N8_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n8_t feoarrm1n8_atanh(    feoarrm1n8_t* arr);
void      feoarrm1n8_atanh_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_asinh(    feoarrm1n8_t* arr);
void      feoarrm1n8_asinh_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_acosh(    feoarrm1n8_t* arr);
void      feoarrm1n8_acosh_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n8_t feoarrm1n8_tanh(     feoarrm1n8_t* arr);
void      feoarrm1n8_tanh_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_sinh(     feoarrm1n8_t* arr);
void      feoarrm1n8_sinh_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_cosh(     feoarrm1n8_t* arr);
void      feoarrm1n8_cosh_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n8_t feoarrm1n8_atan(     feoarrm1n8_t* arr);
void      feoarrm1n8_atan_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_asin(     feoarrm1n8_t* arr);
void      feoarrm1n8_asin_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_acos(     feoarrm1n8_t* arr);
void      feoarrm1n8_acos_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n8_t feoarrm1n8_tan(      feoarrm1n8_t* arr);
void      feoarrm1n8_tan_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_sin(      feoarrm1n8_t* arr);
void      feoarrm1n8_sin_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_cos(      feoarrm1n8_t* arr);
void      feoarrm1n8_cos_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n8_t feoarrm1n8_logb(     feoarrm1n8_t* arr, double base);
void      feoarrm1n8_logb_to(  feoarrm1n8_t* arr, double base, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_log10(    feoarrm1n8_t* arr);
void      feoarrm1n8_log10_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_log(      feoarrm1n8_t* arr);
void      feoarrm1n8_log_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_exp(      feoarrm1n8_t* arr);
void      feoarrm1n8_exp_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n8_t feoarrm1n8_cbrt(     feoarrm1n8_t* arr);
void      feoarrm1n8_cbrt_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_sqrt(     feoarrm1n8_t* arr);
void      feoarrm1n8_sqrt_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
feoarrm1n8_t feoarrm1n8_pow(      feoarrm1n8_t* arr, double e);
void      feoarrm1n8_pow_to(   feoarrm1n8_t* arr, double e, feoarrm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif