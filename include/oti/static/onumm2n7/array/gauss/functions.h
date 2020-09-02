#ifndef OTI_ONUMM2N7_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N7_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n7_t feoarrm2n7_atanh(    feoarrm2n7_t* arr);
void      feoarrm2n7_atanh_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_asinh(    feoarrm2n7_t* arr);
void      feoarrm2n7_asinh_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_acosh(    feoarrm2n7_t* arr);
void      feoarrm2n7_acosh_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n7_t feoarrm2n7_tanh(     feoarrm2n7_t* arr);
void      feoarrm2n7_tanh_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_sinh(     feoarrm2n7_t* arr);
void      feoarrm2n7_sinh_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_cosh(     feoarrm2n7_t* arr);
void      feoarrm2n7_cosh_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n7_t feoarrm2n7_atan(     feoarrm2n7_t* arr);
void      feoarrm2n7_atan_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_asin(     feoarrm2n7_t* arr);
void      feoarrm2n7_asin_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_acos(     feoarrm2n7_t* arr);
void      feoarrm2n7_acos_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n7_t feoarrm2n7_tan(      feoarrm2n7_t* arr);
void      feoarrm2n7_tan_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_sin(      feoarrm2n7_t* arr);
void      feoarrm2n7_sin_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_cos(      feoarrm2n7_t* arr);
void      feoarrm2n7_cos_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n7_t feoarrm2n7_logb(     feoarrm2n7_t* arr, double base);
void      feoarrm2n7_logb_to(  feoarrm2n7_t* arr, double base, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_log10(    feoarrm2n7_t* arr);
void      feoarrm2n7_log10_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_log(      feoarrm2n7_t* arr);
void      feoarrm2n7_log_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_exp(      feoarrm2n7_t* arr);
void      feoarrm2n7_exp_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n7_t feoarrm2n7_cbrt(     feoarrm2n7_t* arr);
void      feoarrm2n7_cbrt_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_sqrt(     feoarrm2n7_t* arr);
void      feoarrm2n7_sqrt_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
feoarrm2n7_t feoarrm2n7_pow(      feoarrm2n7_t* arr, double e);
void      feoarrm2n7_pow_to(   feoarrm2n7_t* arr, double e, feoarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif