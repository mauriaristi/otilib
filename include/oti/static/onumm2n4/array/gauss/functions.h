#ifndef OTI_ONUMM2N4_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N4_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_atanh(    feoarrm2n4_t* arr);
void      feoarrm2n4_atanh_to( feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_asinh(    feoarrm2n4_t* arr);
void      feoarrm2n4_asinh_to( feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_acosh(    feoarrm2n4_t* arr);
void      feoarrm2n4_acosh_to( feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_tanh(     feoarrm2n4_t* arr);
void      feoarrm2n4_tanh_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_sinh(     feoarrm2n4_t* arr);
void      feoarrm2n4_sinh_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_cosh(     feoarrm2n4_t* arr);
void      feoarrm2n4_cosh_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_atan(     feoarrm2n4_t* arr);
void      feoarrm2n4_atan_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_asin(     feoarrm2n4_t* arr);
void      feoarrm2n4_asin_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_acos(     feoarrm2n4_t* arr);
void      feoarrm2n4_acos_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_tan(      feoarrm2n4_t* arr);
void      feoarrm2n4_tan_to(   feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_sin(      feoarrm2n4_t* arr);
void      feoarrm2n4_sin_to(   feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_cos(      feoarrm2n4_t* arr);
void      feoarrm2n4_cos_to(   feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_logb(     feoarrm2n4_t* arr, double base);
void      feoarrm2n4_logb_to(  feoarrm2n4_t* arr, double base, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_log10(    feoarrm2n4_t* arr);
void      feoarrm2n4_log10_to( feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_log(      feoarrm2n4_t* arr);
void      feoarrm2n4_log_to(   feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_exp(      feoarrm2n4_t* arr);
void      feoarrm2n4_exp_to(   feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_cbrt(     feoarrm2n4_t* arr);
void      feoarrm2n4_cbrt_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_sqrt(     feoarrm2n4_t* arr);
void      feoarrm2n4_sqrt_to(  feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_pow(      feoarrm2n4_t* arr, double e);
void      feoarrm2n4_pow_to(   feoarrm2n4_t* arr, double e, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif