#ifndef OTI_ONUMM1N20_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N20_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n20_t feoarrm1n20_atanh(    feoarrm1n20_t* arr);
void      feoarrm1n20_atanh_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_asinh(    feoarrm1n20_t* arr);
void      feoarrm1n20_asinh_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_acosh(    feoarrm1n20_t* arr);
void      feoarrm1n20_acosh_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n20_t feoarrm1n20_tanh(     feoarrm1n20_t* arr);
void      feoarrm1n20_tanh_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_sinh(     feoarrm1n20_t* arr);
void      feoarrm1n20_sinh_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_cosh(     feoarrm1n20_t* arr);
void      feoarrm1n20_cosh_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n20_t feoarrm1n20_atan(     feoarrm1n20_t* arr);
void      feoarrm1n20_atan_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_asin(     feoarrm1n20_t* arr);
void      feoarrm1n20_asin_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_acos(     feoarrm1n20_t* arr);
void      feoarrm1n20_acos_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n20_t feoarrm1n20_tan(      feoarrm1n20_t* arr);
void      feoarrm1n20_tan_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_sin(      feoarrm1n20_t* arr);
void      feoarrm1n20_sin_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_cos(      feoarrm1n20_t* arr);
void      feoarrm1n20_cos_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n20_t feoarrm1n20_logb(     feoarrm1n20_t* arr, double base);
void      feoarrm1n20_logb_to(  feoarrm1n20_t* arr, double base, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_log10(    feoarrm1n20_t* arr);
void      feoarrm1n20_log10_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_log(      feoarrm1n20_t* arr);
void      feoarrm1n20_log_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_exp(      feoarrm1n20_t* arr);
void      feoarrm1n20_exp_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n20_t feoarrm1n20_cbrt(     feoarrm1n20_t* arr);
void      feoarrm1n20_cbrt_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_sqrt(     feoarrm1n20_t* arr);
void      feoarrm1n20_sqrt_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
feoarrm1n20_t feoarrm1n20_pow(      feoarrm1n20_t* arr, double e);
void      feoarrm1n20_pow_to(   feoarrm1n20_t* arr, double e, feoarrm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

#endif