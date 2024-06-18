#ifndef OTI_ONUMM3N4_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N4_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_atanh(    feoarrm3n4_t* arr);
void      feoarrm3n4_atanh_to( feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_asinh(    feoarrm3n4_t* arr);
void      feoarrm3n4_asinh_to( feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_acosh(    feoarrm3n4_t* arr);
void      feoarrm3n4_acosh_to( feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_tanh(     feoarrm3n4_t* arr);
void      feoarrm3n4_tanh_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_sinh(     feoarrm3n4_t* arr);
void      feoarrm3n4_sinh_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_cosh(     feoarrm3n4_t* arr);
void      feoarrm3n4_cosh_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_atan(     feoarrm3n4_t* arr);
void      feoarrm3n4_atan_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_asin(     feoarrm3n4_t* arr);
void      feoarrm3n4_asin_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_acos(     feoarrm3n4_t* arr);
void      feoarrm3n4_acos_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_tan(      feoarrm3n4_t* arr);
void      feoarrm3n4_tan_to(   feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_sin(      feoarrm3n4_t* arr);
void      feoarrm3n4_sin_to(   feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_cos(      feoarrm3n4_t* arr);
void      feoarrm3n4_cos_to(   feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_logb(     feoarrm3n4_t* arr, double base);
void      feoarrm3n4_logb_to(  feoarrm3n4_t* arr, double base, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_log10(    feoarrm3n4_t* arr);
void      feoarrm3n4_log10_to( feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_log(      feoarrm3n4_t* arr);
void      feoarrm3n4_log_to(   feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_exp(      feoarrm3n4_t* arr);
void      feoarrm3n4_exp_to(   feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_cbrt(     feoarrm3n4_t* arr);
void      feoarrm3n4_cbrt_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_sqrt(     feoarrm3n4_t* arr);
void      feoarrm3n4_sqrt_to(  feoarrm3n4_t* arr, feoarrm3n4_t* res);
feoarrm3n4_t feoarrm3n4_pow(      feoarrm3n4_t* arr, double e);
void      feoarrm3n4_pow_to(   feoarrm3n4_t* arr, double e, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif