#ifndef OTI_ONUMM1N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM1N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_atanh(    feoarrm1n2_t* arr);
void      feoarrm1n2_atanh_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_asinh(    feoarrm1n2_t* arr);
void      feoarrm1n2_asinh_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_acosh(    feoarrm1n2_t* arr);
void      feoarrm1n2_acosh_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_tanh(     feoarrm1n2_t* arr);
void      feoarrm1n2_tanh_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_sinh(     feoarrm1n2_t* arr);
void      feoarrm1n2_sinh_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_cosh(     feoarrm1n2_t* arr);
void      feoarrm1n2_cosh_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_atan(     feoarrm1n2_t* arr);
void      feoarrm1n2_atan_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_asin(     feoarrm1n2_t* arr);
void      feoarrm1n2_asin_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_acos(     feoarrm1n2_t* arr);
void      feoarrm1n2_acos_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_tan(      feoarrm1n2_t* arr);
void      feoarrm1n2_tan_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_sin(      feoarrm1n2_t* arr);
void      feoarrm1n2_sin_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_cos(      feoarrm1n2_t* arr);
void      feoarrm1n2_cos_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_logb(     feoarrm1n2_t* arr, double base);
void      feoarrm1n2_logb_to(  feoarrm1n2_t* arr, double base, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_log10(    feoarrm1n2_t* arr);
void      feoarrm1n2_log10_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_log(      feoarrm1n2_t* arr);
void      feoarrm1n2_log_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_exp(      feoarrm1n2_t* arr);
void      feoarrm1n2_exp_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_cbrt(     feoarrm1n2_t* arr);
void      feoarrm1n2_cbrt_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_sqrt(     feoarrm1n2_t* arr);
void      feoarrm1n2_sqrt_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
feoarrm1n2_t feoarrm1n2_pow(      feoarrm1n2_t* arr, double e);
void      feoarrm1n2_pow_to(   feoarrm1n2_t* arr, double e, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif