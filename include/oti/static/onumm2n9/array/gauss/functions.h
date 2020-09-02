#ifndef OTI_ONUMM2N9_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N9_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n9_t feoarrm2n9_atanh(    feoarrm2n9_t* arr);
void      feoarrm2n9_atanh_to( feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_asinh(    feoarrm2n9_t* arr);
void      feoarrm2n9_asinh_to( feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_acosh(    feoarrm2n9_t* arr);
void      feoarrm2n9_acosh_to( feoarrm2n9_t* arr, feoarrm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n9_t feoarrm2n9_tanh(     feoarrm2n9_t* arr);
void      feoarrm2n9_tanh_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_sinh(     feoarrm2n9_t* arr);
void      feoarrm2n9_sinh_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_cosh(     feoarrm2n9_t* arr);
void      feoarrm2n9_cosh_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n9_t feoarrm2n9_atan(     feoarrm2n9_t* arr);
void      feoarrm2n9_atan_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_asin(     feoarrm2n9_t* arr);
void      feoarrm2n9_asin_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_acos(     feoarrm2n9_t* arr);
void      feoarrm2n9_acos_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n9_t feoarrm2n9_tan(      feoarrm2n9_t* arr);
void      feoarrm2n9_tan_to(   feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_sin(      feoarrm2n9_t* arr);
void      feoarrm2n9_sin_to(   feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_cos(      feoarrm2n9_t* arr);
void      feoarrm2n9_cos_to(   feoarrm2n9_t* arr, feoarrm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n9_t feoarrm2n9_logb(     feoarrm2n9_t* arr, double base);
void      feoarrm2n9_logb_to(  feoarrm2n9_t* arr, double base, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_log10(    feoarrm2n9_t* arr);
void      feoarrm2n9_log10_to( feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_log(      feoarrm2n9_t* arr);
void      feoarrm2n9_log_to(   feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_exp(      feoarrm2n9_t* arr);
void      feoarrm2n9_exp_to(   feoarrm2n9_t* arr, feoarrm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n9_t feoarrm2n9_cbrt(     feoarrm2n9_t* arr);
void      feoarrm2n9_cbrt_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_sqrt(     feoarrm2n9_t* arr);
void      feoarrm2n9_sqrt_to(  feoarrm2n9_t* arr, feoarrm2n9_t* res);
feoarrm2n9_t feoarrm2n9_pow(      feoarrm2n9_t* arr, double e);
void      feoarrm2n9_pow_to(   feoarrm2n9_t* arr, double e, feoarrm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif