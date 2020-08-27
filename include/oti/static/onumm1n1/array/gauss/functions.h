#ifndef OTI_ONUMM1N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n1_t feoarrm1n1_atanh(    feoarrm1n1_t* arr);
void      feoarrm1n1_atanh_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_asinh(    feoarrm1n1_t* arr);
void      feoarrm1n1_asinh_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_acosh(    feoarrm1n1_t* arr);
void      feoarrm1n1_acosh_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n1_t feoarrm1n1_tanh(     feoarrm1n1_t* arr);
void      feoarrm1n1_tanh_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_sinh(     feoarrm1n1_t* arr);
void      feoarrm1n1_sinh_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_cosh(     feoarrm1n1_t* arr);
void      feoarrm1n1_cosh_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n1_t feoarrm1n1_atan(     feoarrm1n1_t* arr);
void      feoarrm1n1_atan_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_asin(     feoarrm1n1_t* arr);
void      feoarrm1n1_asin_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_acos(     feoarrm1n1_t* arr);
void      feoarrm1n1_acos_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n1_t feoarrm1n1_tan(      feoarrm1n1_t* arr);
void      feoarrm1n1_tan_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_sin(      feoarrm1n1_t* arr);
void      feoarrm1n1_sin_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_cos(      feoarrm1n1_t* arr);
void      feoarrm1n1_cos_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n1_t feoarrm1n1_logb(     feoarrm1n1_t* arr, double base);
void      feoarrm1n1_logb_to(  feoarrm1n1_t* arr, double base, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_log10(    feoarrm1n1_t* arr);
void      feoarrm1n1_log10_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_log(      feoarrm1n1_t* arr);
void      feoarrm1n1_log_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_exp(      feoarrm1n1_t* arr);
void      feoarrm1n1_exp_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n1_t feoarrm1n1_cbrt(     feoarrm1n1_t* arr);
void      feoarrm1n1_cbrt_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_sqrt(     feoarrm1n1_t* arr);
void      feoarrm1n1_sqrt_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
feoarrm1n1_t feoarrm1n1_pow(      feoarrm1n1_t* arr, double e);
void      feoarrm1n1_pow_to(   feoarrm1n1_t* arr, double e, feoarrm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif