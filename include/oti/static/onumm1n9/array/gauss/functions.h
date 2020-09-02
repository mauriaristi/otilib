#ifndef OTI_ONUMM1N9_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N9_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n9_t feoarrm1n9_atanh(    feoarrm1n9_t* arr);
void      feoarrm1n9_atanh_to( feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_asinh(    feoarrm1n9_t* arr);
void      feoarrm1n9_asinh_to( feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_acosh(    feoarrm1n9_t* arr);
void      feoarrm1n9_acosh_to( feoarrm1n9_t* arr, feoarrm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n9_t feoarrm1n9_tanh(     feoarrm1n9_t* arr);
void      feoarrm1n9_tanh_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_sinh(     feoarrm1n9_t* arr);
void      feoarrm1n9_sinh_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_cosh(     feoarrm1n9_t* arr);
void      feoarrm1n9_cosh_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n9_t feoarrm1n9_atan(     feoarrm1n9_t* arr);
void      feoarrm1n9_atan_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_asin(     feoarrm1n9_t* arr);
void      feoarrm1n9_asin_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_acos(     feoarrm1n9_t* arr);
void      feoarrm1n9_acos_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n9_t feoarrm1n9_tan(      feoarrm1n9_t* arr);
void      feoarrm1n9_tan_to(   feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_sin(      feoarrm1n9_t* arr);
void      feoarrm1n9_sin_to(   feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_cos(      feoarrm1n9_t* arr);
void      feoarrm1n9_cos_to(   feoarrm1n9_t* arr, feoarrm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n9_t feoarrm1n9_logb(     feoarrm1n9_t* arr, double base);
void      feoarrm1n9_logb_to(  feoarrm1n9_t* arr, double base, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_log10(    feoarrm1n9_t* arr);
void      feoarrm1n9_log10_to( feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_log(      feoarrm1n9_t* arr);
void      feoarrm1n9_log_to(   feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_exp(      feoarrm1n9_t* arr);
void      feoarrm1n9_exp_to(   feoarrm1n9_t* arr, feoarrm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n9_t feoarrm1n9_cbrt(     feoarrm1n9_t* arr);
void      feoarrm1n9_cbrt_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_sqrt(     feoarrm1n9_t* arr);
void      feoarrm1n9_sqrt_to(  feoarrm1n9_t* arr, feoarrm1n9_t* res);
feoarrm1n9_t feoarrm1n9_pow(      feoarrm1n9_t* arr, double e);
void      feoarrm1n9_pow_to(   feoarrm1n9_t* arr, double e, feoarrm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif