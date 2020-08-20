#ifndef OTI_ONUMM2N5_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N5_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n5_t feoarrm2n5_atanh(    feoarrm2n5_t* arr);
void      feoarrm2n5_atanh_to( feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_asinh(    feoarrm2n5_t* arr);
void      feoarrm2n5_asinh_to( feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_acosh(    feoarrm2n5_t* arr);
void      feoarrm2n5_acosh_to( feoarrm2n5_t* arr, feoarrm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n5_t feoarrm2n5_tanh(     feoarrm2n5_t* arr);
void      feoarrm2n5_tanh_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_sinh(     feoarrm2n5_t* arr);
void      feoarrm2n5_sinh_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_cosh(     feoarrm2n5_t* arr);
void      feoarrm2n5_cosh_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n5_t feoarrm2n5_atan(     feoarrm2n5_t* arr);
void      feoarrm2n5_atan_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_asin(     feoarrm2n5_t* arr);
void      feoarrm2n5_asin_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_acos(     feoarrm2n5_t* arr);
void      feoarrm2n5_acos_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n5_t feoarrm2n5_tan(      feoarrm2n5_t* arr);
void      feoarrm2n5_tan_to(   feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_sin(      feoarrm2n5_t* arr);
void      feoarrm2n5_sin_to(   feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_cos(      feoarrm2n5_t* arr);
void      feoarrm2n5_cos_to(   feoarrm2n5_t* arr, feoarrm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n5_t feoarrm2n5_logb(     feoarrm2n5_t* arr, double base);
void      feoarrm2n5_logb_to(  feoarrm2n5_t* arr, double base, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_log10(    feoarrm2n5_t* arr);
void      feoarrm2n5_log10_to( feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_log(      feoarrm2n5_t* arr);
void      feoarrm2n5_log_to(   feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_exp(      feoarrm2n5_t* arr);
void      feoarrm2n5_exp_to(   feoarrm2n5_t* arr, feoarrm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n5_t feoarrm2n5_cbrt(     feoarrm2n5_t* arr);
void      feoarrm2n5_cbrt_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_sqrt(     feoarrm2n5_t* arr);
void      feoarrm2n5_sqrt_to(  feoarrm2n5_t* arr, feoarrm2n5_t* res);
feoarrm2n5_t feoarrm2n5_pow(      feoarrm2n5_t* arr, double e);
void      feoarrm2n5_pow_to(   feoarrm2n5_t* arr, double e, feoarrm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif