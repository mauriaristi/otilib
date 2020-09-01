#ifndef OTI_ONUMM3N5_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N5_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_atanh(    feoarrm3n5_t* arr);
void      feoarrm3n5_atanh_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_asinh(    feoarrm3n5_t* arr);
void      feoarrm3n5_asinh_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_acosh(    feoarrm3n5_t* arr);
void      feoarrm3n5_acosh_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_tanh(     feoarrm3n5_t* arr);
void      feoarrm3n5_tanh_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_sinh(     feoarrm3n5_t* arr);
void      feoarrm3n5_sinh_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_cosh(     feoarrm3n5_t* arr);
void      feoarrm3n5_cosh_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_atan(     feoarrm3n5_t* arr);
void      feoarrm3n5_atan_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_asin(     feoarrm3n5_t* arr);
void      feoarrm3n5_asin_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_acos(     feoarrm3n5_t* arr);
void      feoarrm3n5_acos_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_tan(      feoarrm3n5_t* arr);
void      feoarrm3n5_tan_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_sin(      feoarrm3n5_t* arr);
void      feoarrm3n5_sin_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_cos(      feoarrm3n5_t* arr);
void      feoarrm3n5_cos_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_logb(     feoarrm3n5_t* arr, double base);
void      feoarrm3n5_logb_to(  feoarrm3n5_t* arr, double base, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_log10(    feoarrm3n5_t* arr);
void      feoarrm3n5_log10_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_log(      feoarrm3n5_t* arr);
void      feoarrm3n5_log_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_exp(      feoarrm3n5_t* arr);
void      feoarrm3n5_exp_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_cbrt(     feoarrm3n5_t* arr);
void      feoarrm3n5_cbrt_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_sqrt(     feoarrm3n5_t* arr);
void      feoarrm3n5_sqrt_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
feoarrm3n5_t feoarrm3n5_pow(      feoarrm3n5_t* arr, double e);
void      feoarrm3n5_pow_to(   feoarrm3n5_t* arr, double e, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif