#ifndef OTI_ONUMM4N3_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N3_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n3_t feoarrm4n3_atanh(    feoarrm4n3_t* arr);
void      feoarrm4n3_atanh_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_asinh(    feoarrm4n3_t* arr);
void      feoarrm4n3_asinh_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_acosh(    feoarrm4n3_t* arr);
void      feoarrm4n3_acosh_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n3_t feoarrm4n3_tanh(     feoarrm4n3_t* arr);
void      feoarrm4n3_tanh_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_sinh(     feoarrm4n3_t* arr);
void      feoarrm4n3_sinh_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_cosh(     feoarrm4n3_t* arr);
void      feoarrm4n3_cosh_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n3_t feoarrm4n3_atan(     feoarrm4n3_t* arr);
void      feoarrm4n3_atan_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_asin(     feoarrm4n3_t* arr);
void      feoarrm4n3_asin_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_acos(     feoarrm4n3_t* arr);
void      feoarrm4n3_acos_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n3_t feoarrm4n3_tan(      feoarrm4n3_t* arr);
void      feoarrm4n3_tan_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_sin(      feoarrm4n3_t* arr);
void      feoarrm4n3_sin_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_cos(      feoarrm4n3_t* arr);
void      feoarrm4n3_cos_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm4n3_t feoarrm4n3_logb(     feoarrm4n3_t* arr, double base);
void      feoarrm4n3_logb_to(  feoarrm4n3_t* arr, double base, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_log10(    feoarrm4n3_t* arr);
void      feoarrm4n3_log10_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_log(      feoarrm4n3_t* arr);
void      feoarrm4n3_log_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_exp(      feoarrm4n3_t* arr);
void      feoarrm4n3_exp_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n3_t feoarrm4n3_cbrt(     feoarrm4n3_t* arr);
void      feoarrm4n3_cbrt_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_sqrt(     feoarrm4n3_t* arr);
void      feoarrm4n3_sqrt_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
feoarrm4n3_t feoarrm4n3_pow(      feoarrm4n3_t* arr, double e);
void      feoarrm4n3_pow_to(   feoarrm4n3_t* arr, double e, feoarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif