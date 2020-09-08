#ifndef OTI_ONUMM7N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM7N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n2_t feoarrm7n2_atanh(    feoarrm7n2_t* arr);
void      feoarrm7n2_atanh_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_asinh(    feoarrm7n2_t* arr);
void      feoarrm7n2_asinh_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_acosh(    feoarrm7n2_t* arr);
void      feoarrm7n2_acosh_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n2_t feoarrm7n2_tanh(     feoarrm7n2_t* arr);
void      feoarrm7n2_tanh_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_sinh(     feoarrm7n2_t* arr);
void      feoarrm7n2_sinh_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_cosh(     feoarrm7n2_t* arr);
void      feoarrm7n2_cosh_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n2_t feoarrm7n2_atan(     feoarrm7n2_t* arr);
void      feoarrm7n2_atan_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_asin(     feoarrm7n2_t* arr);
void      feoarrm7n2_asin_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_acos(     feoarrm7n2_t* arr);
void      feoarrm7n2_acos_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n2_t feoarrm7n2_tan(      feoarrm7n2_t* arr);
void      feoarrm7n2_tan_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_sin(      feoarrm7n2_t* arr);
void      feoarrm7n2_sin_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_cos(      feoarrm7n2_t* arr);
void      feoarrm7n2_cos_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm7n2_t feoarrm7n2_logb(     feoarrm7n2_t* arr, double base);
void      feoarrm7n2_logb_to(  feoarrm7n2_t* arr, double base, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_log10(    feoarrm7n2_t* arr);
void      feoarrm7n2_log10_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_log(      feoarrm7n2_t* arr);
void      feoarrm7n2_log_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_exp(      feoarrm7n2_t* arr);
void      feoarrm7n2_exp_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm7n2_t feoarrm7n2_cbrt(     feoarrm7n2_t* arr);
void      feoarrm7n2_cbrt_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_sqrt(     feoarrm7n2_t* arr);
void      feoarrm7n2_sqrt_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
feoarrm7n2_t feoarrm7n2_pow(      feoarrm7n2_t* arr, double e);
void      feoarrm7n2_pow_to(   feoarrm7n2_t* arr, double e, feoarrm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif