#ifndef OTI_ONUMM2N6_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N6_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n6_t feoarrm2n6_atanh(    feoarrm2n6_t* arr);
void      feoarrm2n6_atanh_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_asinh(    feoarrm2n6_t* arr);
void      feoarrm2n6_asinh_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_acosh(    feoarrm2n6_t* arr);
void      feoarrm2n6_acosh_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n6_t feoarrm2n6_tanh(     feoarrm2n6_t* arr);
void      feoarrm2n6_tanh_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_sinh(     feoarrm2n6_t* arr);
void      feoarrm2n6_sinh_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_cosh(     feoarrm2n6_t* arr);
void      feoarrm2n6_cosh_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n6_t feoarrm2n6_atan(     feoarrm2n6_t* arr);
void      feoarrm2n6_atan_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_asin(     feoarrm2n6_t* arr);
void      feoarrm2n6_asin_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_acos(     feoarrm2n6_t* arr);
void      feoarrm2n6_acos_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n6_t feoarrm2n6_tan(      feoarrm2n6_t* arr);
void      feoarrm2n6_tan_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_sin(      feoarrm2n6_t* arr);
void      feoarrm2n6_sin_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_cos(      feoarrm2n6_t* arr);
void      feoarrm2n6_cos_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n6_t feoarrm2n6_logb(     feoarrm2n6_t* arr, double base);
void      feoarrm2n6_logb_to(  feoarrm2n6_t* arr, double base, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_log10(    feoarrm2n6_t* arr);
void      feoarrm2n6_log10_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_log(      feoarrm2n6_t* arr);
void      feoarrm2n6_log_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_exp(      feoarrm2n6_t* arr);
void      feoarrm2n6_exp_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n6_t feoarrm2n6_cbrt(     feoarrm2n6_t* arr);
void      feoarrm2n6_cbrt_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_sqrt(     feoarrm2n6_t* arr);
void      feoarrm2n6_sqrt_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
feoarrm2n6_t feoarrm2n6_pow(      feoarrm2n6_t* arr, double e);
void      feoarrm2n6_pow_to(   feoarrm2n6_t* arr, double e, feoarrm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif