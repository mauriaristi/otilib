#ifndef OTI_ONUMM4N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM4N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n2_t feoarrm4n2_atanh(    feoarrm4n2_t* arr);
void      feoarrm4n2_atanh_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_asinh(    feoarrm4n2_t* arr);
void      feoarrm4n2_asinh_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_acosh(    feoarrm4n2_t* arr);
void      feoarrm4n2_acosh_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n2_t feoarrm4n2_tanh(     feoarrm4n2_t* arr);
void      feoarrm4n2_tanh_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_sinh(     feoarrm4n2_t* arr);
void      feoarrm4n2_sinh_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_cosh(     feoarrm4n2_t* arr);
void      feoarrm4n2_cosh_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n2_t feoarrm4n2_atan(     feoarrm4n2_t* arr);
void      feoarrm4n2_atan_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_asin(     feoarrm4n2_t* arr);
void      feoarrm4n2_asin_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_acos(     feoarrm4n2_t* arr);
void      feoarrm4n2_acos_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n2_t feoarrm4n2_tan(      feoarrm4n2_t* arr);
void      feoarrm4n2_tan_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_sin(      feoarrm4n2_t* arr);
void      feoarrm4n2_sin_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_cos(      feoarrm4n2_t* arr);
void      feoarrm4n2_cos_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm4n2_t feoarrm4n2_logb(     feoarrm4n2_t* arr, double base);
void      feoarrm4n2_logb_to(  feoarrm4n2_t* arr, double base, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_log10(    feoarrm4n2_t* arr);
void      feoarrm4n2_log10_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_log(      feoarrm4n2_t* arr);
void      feoarrm4n2_log_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_exp(      feoarrm4n2_t* arr);
void      feoarrm4n2_exp_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm4n2_t feoarrm4n2_cbrt(     feoarrm4n2_t* arr);
void      feoarrm4n2_cbrt_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_sqrt(     feoarrm4n2_t* arr);
void      feoarrm4n2_sqrt_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
feoarrm4n2_t feoarrm4n2_pow(      feoarrm4n2_t* arr, double e);
void      feoarrm4n2_pow_to(   feoarrm4n2_t* arr, double e, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif