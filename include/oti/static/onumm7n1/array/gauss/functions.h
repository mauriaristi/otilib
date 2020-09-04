#ifndef OTI_ONUMM7N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM7N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n1_t feoarrm7n1_atanh(    feoarrm7n1_t* arr);
void      feoarrm7n1_atanh_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_asinh(    feoarrm7n1_t* arr);
void      feoarrm7n1_asinh_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_acosh(    feoarrm7n1_t* arr);
void      feoarrm7n1_acosh_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n1_t feoarrm7n1_tanh(     feoarrm7n1_t* arr);
void      feoarrm7n1_tanh_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_sinh(     feoarrm7n1_t* arr);
void      feoarrm7n1_sinh_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_cosh(     feoarrm7n1_t* arr);
void      feoarrm7n1_cosh_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n1_t feoarrm7n1_atan(     feoarrm7n1_t* arr);
void      feoarrm7n1_atan_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_asin(     feoarrm7n1_t* arr);
void      feoarrm7n1_asin_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_acos(     feoarrm7n1_t* arr);
void      feoarrm7n1_acos_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n1_t feoarrm7n1_tan(      feoarrm7n1_t* arr);
void      feoarrm7n1_tan_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_sin(      feoarrm7n1_t* arr);
void      feoarrm7n1_sin_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_cos(      feoarrm7n1_t* arr);
void      feoarrm7n1_cos_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm7n1_t feoarrm7n1_logb(     feoarrm7n1_t* arr, double base);
void      feoarrm7n1_logb_to(  feoarrm7n1_t* arr, double base, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_log10(    feoarrm7n1_t* arr);
void      feoarrm7n1_log10_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_log(      feoarrm7n1_t* arr);
void      feoarrm7n1_log_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_exp(      feoarrm7n1_t* arr);
void      feoarrm7n1_exp_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n1_t feoarrm7n1_cbrt(     feoarrm7n1_t* arr);
void      feoarrm7n1_cbrt_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_sqrt(     feoarrm7n1_t* arr);
void      feoarrm7n1_sqrt_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
feoarrm7n1_t feoarrm7n1_pow(      feoarrm7n1_t* arr, double e);
void      feoarrm7n1_pow_to(   feoarrm7n1_t* arr, double e, feoarrm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif