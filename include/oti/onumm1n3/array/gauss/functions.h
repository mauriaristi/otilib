#ifndef OTI_ONUMM1N3_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N3_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n3_t feoarrm1n3_atanh(    feoarrm1n3_t* arr);
void      feoarrm1n3_atanh_to( feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_asinh(    feoarrm1n3_t* arr);
void      feoarrm1n3_asinh_to( feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_acosh(    feoarrm1n3_t* arr);
void      feoarrm1n3_acosh_to( feoarrm1n3_t* arr, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n3_t feoarrm1n3_tanh(     feoarrm1n3_t* arr);
void      feoarrm1n3_tanh_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_sinh(     feoarrm1n3_t* arr);
void      feoarrm1n3_sinh_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_cosh(     feoarrm1n3_t* arr);
void      feoarrm1n3_cosh_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n3_t feoarrm1n3_atan(     feoarrm1n3_t* arr);
void      feoarrm1n3_atan_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_asin(     feoarrm1n3_t* arr);
void      feoarrm1n3_asin_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_acos(     feoarrm1n3_t* arr);
void      feoarrm1n3_acos_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n3_t feoarrm1n3_tan(      feoarrm1n3_t* arr);
void      feoarrm1n3_tan_to(   feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_sin(      feoarrm1n3_t* arr);
void      feoarrm1n3_sin_to(   feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_cos(      feoarrm1n3_t* arr);
void      feoarrm1n3_cos_to(   feoarrm1n3_t* arr, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n3_t feoarrm1n3_logb(     feoarrm1n3_t* arr, double base);
void      feoarrm1n3_logb_to(  feoarrm1n3_t* arr, double base, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_log10(    feoarrm1n3_t* arr);
void      feoarrm1n3_log10_to( feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_log(      feoarrm1n3_t* arr);
void      feoarrm1n3_log_to(   feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_exp(      feoarrm1n3_t* arr);
void      feoarrm1n3_exp_to(   feoarrm1n3_t* arr, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n3_t feoarrm1n3_cbrt(     feoarrm1n3_t* arr);
void      feoarrm1n3_cbrt_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_sqrt(     feoarrm1n3_t* arr);
void      feoarrm1n3_sqrt_to(  feoarrm1n3_t* arr, feoarrm1n3_t* res);
feoarrm1n3_t feoarrm1n3_pow(      feoarrm1n3_t* arr, double e);
void      feoarrm1n3_pow_to(   feoarrm1n3_t* arr, double e, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif