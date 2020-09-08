#ifndef OTI_ONUMM6N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM6N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_atanh(    feoarrm6n2_t* arr);
void      feoarrm6n2_atanh_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_asinh(    feoarrm6n2_t* arr);
void      feoarrm6n2_asinh_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_acosh(    feoarrm6n2_t* arr);
void      feoarrm6n2_acosh_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_tanh(     feoarrm6n2_t* arr);
void      feoarrm6n2_tanh_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_sinh(     feoarrm6n2_t* arr);
void      feoarrm6n2_sinh_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_cosh(     feoarrm6n2_t* arr);
void      feoarrm6n2_cosh_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_atan(     feoarrm6n2_t* arr);
void      feoarrm6n2_atan_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_asin(     feoarrm6n2_t* arr);
void      feoarrm6n2_asin_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_acos(     feoarrm6n2_t* arr);
void      feoarrm6n2_acos_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_tan(      feoarrm6n2_t* arr);
void      feoarrm6n2_tan_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_sin(      feoarrm6n2_t* arr);
void      feoarrm6n2_sin_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_cos(      feoarrm6n2_t* arr);
void      feoarrm6n2_cos_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_logb(     feoarrm6n2_t* arr, double base);
void      feoarrm6n2_logb_to(  feoarrm6n2_t* arr, double base, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_log10(    feoarrm6n2_t* arr);
void      feoarrm6n2_log10_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_log(      feoarrm6n2_t* arr);
void      feoarrm6n2_log_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_exp(      feoarrm6n2_t* arr);
void      feoarrm6n2_exp_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_cbrt(     feoarrm6n2_t* arr);
void      feoarrm6n2_cbrt_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_sqrt(     feoarrm6n2_t* arr);
void      feoarrm6n2_sqrt_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
feoarrm6n2_t feoarrm6n2_pow(      feoarrm6n2_t* arr, double e);
void      feoarrm6n2_pow_to(   feoarrm6n2_t* arr, double e, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif