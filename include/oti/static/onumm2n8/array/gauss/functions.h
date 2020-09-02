#ifndef OTI_ONUMM2N8_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N8_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_atanh(    feoarrm2n8_t* arr);
void      feoarrm2n8_atanh_to( feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_asinh(    feoarrm2n8_t* arr);
void      feoarrm2n8_asinh_to( feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_acosh(    feoarrm2n8_t* arr);
void      feoarrm2n8_acosh_to( feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_tanh(     feoarrm2n8_t* arr);
void      feoarrm2n8_tanh_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_sinh(     feoarrm2n8_t* arr);
void      feoarrm2n8_sinh_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_cosh(     feoarrm2n8_t* arr);
void      feoarrm2n8_cosh_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_atan(     feoarrm2n8_t* arr);
void      feoarrm2n8_atan_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_asin(     feoarrm2n8_t* arr);
void      feoarrm2n8_asin_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_acos(     feoarrm2n8_t* arr);
void      feoarrm2n8_acos_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_tan(      feoarrm2n8_t* arr);
void      feoarrm2n8_tan_to(   feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_sin(      feoarrm2n8_t* arr);
void      feoarrm2n8_sin_to(   feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_cos(      feoarrm2n8_t* arr);
void      feoarrm2n8_cos_to(   feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_logb(     feoarrm2n8_t* arr, double base);
void      feoarrm2n8_logb_to(  feoarrm2n8_t* arr, double base, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_log10(    feoarrm2n8_t* arr);
void      feoarrm2n8_log10_to( feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_log(      feoarrm2n8_t* arr);
void      feoarrm2n8_log_to(   feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_exp(      feoarrm2n8_t* arr);
void      feoarrm2n8_exp_to(   feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_cbrt(     feoarrm2n8_t* arr);
void      feoarrm2n8_cbrt_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_sqrt(     feoarrm2n8_t* arr);
void      feoarrm2n8_sqrt_to(  feoarrm2n8_t* arr, feoarrm2n8_t* res);
feoarrm2n8_t feoarrm2n8_pow(      feoarrm2n8_t* arr, double e);
void      feoarrm2n8_pow_to(   feoarrm2n8_t* arr, double e, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif