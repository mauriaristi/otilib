#ifndef OTI_ONUMM4N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n1_t feoarrm4n1_atanh(    feoarrm4n1_t* arr);
void      feoarrm4n1_atanh_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_asinh(    feoarrm4n1_t* arr);
void      feoarrm4n1_asinh_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_acosh(    feoarrm4n1_t* arr);
void      feoarrm4n1_acosh_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n1_t feoarrm4n1_tanh(     feoarrm4n1_t* arr);
void      feoarrm4n1_tanh_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_sinh(     feoarrm4n1_t* arr);
void      feoarrm4n1_sinh_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_cosh(     feoarrm4n1_t* arr);
void      feoarrm4n1_cosh_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n1_t feoarrm4n1_atan(     feoarrm4n1_t* arr);
void      feoarrm4n1_atan_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_asin(     feoarrm4n1_t* arr);
void      feoarrm4n1_asin_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_acos(     feoarrm4n1_t* arr);
void      feoarrm4n1_acos_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n1_t feoarrm4n1_tan(      feoarrm4n1_t* arr);
void      feoarrm4n1_tan_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_sin(      feoarrm4n1_t* arr);
void      feoarrm4n1_sin_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_cos(      feoarrm4n1_t* arr);
void      feoarrm4n1_cos_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm4n1_t feoarrm4n1_logb(     feoarrm4n1_t* arr, double base);
void      feoarrm4n1_logb_to(  feoarrm4n1_t* arr, double base, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_log10(    feoarrm4n1_t* arr);
void      feoarrm4n1_log10_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_log(      feoarrm4n1_t* arr);
void      feoarrm4n1_log_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_exp(      feoarrm4n1_t* arr);
void      feoarrm4n1_exp_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n1_t feoarrm4n1_cbrt(     feoarrm4n1_t* arr);
void      feoarrm4n1_cbrt_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_sqrt(     feoarrm4n1_t* arr);
void      feoarrm4n1_sqrt_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
feoarrm4n1_t feoarrm4n1_pow(      feoarrm4n1_t* arr, double e);
void      feoarrm4n1_pow_to(   feoarrm4n1_t* arr, double e, feoarrm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif