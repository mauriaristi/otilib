#ifndef OTI_ONUMM2N10_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N10_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_atanh(    feoarrm2n10_t* arr);
void      feoarrm2n10_atanh_to( feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_asinh(    feoarrm2n10_t* arr);
void      feoarrm2n10_asinh_to( feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_acosh(    feoarrm2n10_t* arr);
void      feoarrm2n10_acosh_to( feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_tanh(     feoarrm2n10_t* arr);
void      feoarrm2n10_tanh_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_sinh(     feoarrm2n10_t* arr);
void      feoarrm2n10_sinh_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_cosh(     feoarrm2n10_t* arr);
void      feoarrm2n10_cosh_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_atan(     feoarrm2n10_t* arr);
void      feoarrm2n10_atan_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_asin(     feoarrm2n10_t* arr);
void      feoarrm2n10_asin_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_acos(     feoarrm2n10_t* arr);
void      feoarrm2n10_acos_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_tan(      feoarrm2n10_t* arr);
void      feoarrm2n10_tan_to(   feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_sin(      feoarrm2n10_t* arr);
void      feoarrm2n10_sin_to(   feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_cos(      feoarrm2n10_t* arr);
void      feoarrm2n10_cos_to(   feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_logb(     feoarrm2n10_t* arr, double base);
void      feoarrm2n10_logb_to(  feoarrm2n10_t* arr, double base, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_log10(    feoarrm2n10_t* arr);
void      feoarrm2n10_log10_to( feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_log(      feoarrm2n10_t* arr);
void      feoarrm2n10_log_to(   feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_exp(      feoarrm2n10_t* arr);
void      feoarrm2n10_exp_to(   feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_cbrt(     feoarrm2n10_t* arr);
void      feoarrm2n10_cbrt_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_sqrt(     feoarrm2n10_t* arr);
void      feoarrm2n10_sqrt_to(  feoarrm2n10_t* arr, feoarrm2n10_t* res);
feoarrm2n10_t feoarrm2n10_pow(      feoarrm2n10_t* arr, double e);
void      feoarrm2n10_pow_to(   feoarrm2n10_t* arr, double e, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif