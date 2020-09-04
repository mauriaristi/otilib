#ifndef OTI_ONUMM6N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM6N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n1_t feoarrm6n1_atanh(    feoarrm6n1_t* arr);
void      feoarrm6n1_atanh_to( feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_asinh(    feoarrm6n1_t* arr);
void      feoarrm6n1_asinh_to( feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_acosh(    feoarrm6n1_t* arr);
void      feoarrm6n1_acosh_to( feoarrm6n1_t* arr, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n1_t feoarrm6n1_tanh(     feoarrm6n1_t* arr);
void      feoarrm6n1_tanh_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_sinh(     feoarrm6n1_t* arr);
void      feoarrm6n1_sinh_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_cosh(     feoarrm6n1_t* arr);
void      feoarrm6n1_cosh_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n1_t feoarrm6n1_atan(     feoarrm6n1_t* arr);
void      feoarrm6n1_atan_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_asin(     feoarrm6n1_t* arr);
void      feoarrm6n1_asin_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_acos(     feoarrm6n1_t* arr);
void      feoarrm6n1_acos_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n1_t feoarrm6n1_tan(      feoarrm6n1_t* arr);
void      feoarrm6n1_tan_to(   feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_sin(      feoarrm6n1_t* arr);
void      feoarrm6n1_sin_to(   feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_cos(      feoarrm6n1_t* arr);
void      feoarrm6n1_cos_to(   feoarrm6n1_t* arr, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm6n1_t feoarrm6n1_logb(     feoarrm6n1_t* arr, double base);
void      feoarrm6n1_logb_to(  feoarrm6n1_t* arr, double base, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_log10(    feoarrm6n1_t* arr);
void      feoarrm6n1_log10_to( feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_log(      feoarrm6n1_t* arr);
void      feoarrm6n1_log_to(   feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_exp(      feoarrm6n1_t* arr);
void      feoarrm6n1_exp_to(   feoarrm6n1_t* arr, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n1_t feoarrm6n1_cbrt(     feoarrm6n1_t* arr);
void      feoarrm6n1_cbrt_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_sqrt(     feoarrm6n1_t* arr);
void      feoarrm6n1_sqrt_to(  feoarrm6n1_t* arr, feoarrm6n1_t* res);
feoarrm6n1_t feoarrm6n1_pow(      feoarrm6n1_t* arr, double e);
void      feoarrm6n1_pow_to(   feoarrm6n1_t* arr, double e, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif