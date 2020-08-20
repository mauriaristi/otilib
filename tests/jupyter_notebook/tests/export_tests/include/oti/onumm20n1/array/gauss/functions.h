#ifndef OTI_ONUMM20N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM20N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm20n1_t feoarrm20n1_atanh(    feoarrm20n1_t* arr);
void      feoarrm20n1_atanh_to( feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_asinh(    feoarrm20n1_t* arr);
void      feoarrm20n1_asinh_to( feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_acosh(    feoarrm20n1_t* arr);
void      feoarrm20n1_acosh_to( feoarrm20n1_t* arr, feoarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm20n1_t feoarrm20n1_tanh(     feoarrm20n1_t* arr);
void      feoarrm20n1_tanh_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_sinh(     feoarrm20n1_t* arr);
void      feoarrm20n1_sinh_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_cosh(     feoarrm20n1_t* arr);
void      feoarrm20n1_cosh_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm20n1_t feoarrm20n1_atan(     feoarrm20n1_t* arr);
void      feoarrm20n1_atan_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_asin(     feoarrm20n1_t* arr);
void      feoarrm20n1_asin_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_acos(     feoarrm20n1_t* arr);
void      feoarrm20n1_acos_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm20n1_t feoarrm20n1_tan(      feoarrm20n1_t* arr);
void      feoarrm20n1_tan_to(   feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_sin(      feoarrm20n1_t* arr);
void      feoarrm20n1_sin_to(   feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_cos(      feoarrm20n1_t* arr);
void      feoarrm20n1_cos_to(   feoarrm20n1_t* arr, feoarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm20n1_t feoarrm20n1_logb(     feoarrm20n1_t* arr, double base);
void      feoarrm20n1_logb_to(  feoarrm20n1_t* arr, double base, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_log10(    feoarrm20n1_t* arr);
void      feoarrm20n1_log10_to( feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_log(      feoarrm20n1_t* arr);
void      feoarrm20n1_log_to(   feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_exp(      feoarrm20n1_t* arr);
void      feoarrm20n1_exp_to(   feoarrm20n1_t* arr, feoarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm20n1_t feoarrm20n1_cbrt(     feoarrm20n1_t* arr);
void      feoarrm20n1_cbrt_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_sqrt(     feoarrm20n1_t* arr);
void      feoarrm20n1_sqrt_to(  feoarrm20n1_t* arr, feoarrm20n1_t* res);
feoarrm20n1_t feoarrm20n1_pow(      feoarrm20n1_t* arr, double e);
void      feoarrm20n1_pow_to(   feoarrm20n1_t* arr, double e, feoarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif