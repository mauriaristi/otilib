#ifndef OTI_ONUMM9N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM9N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n1_t feoarrm9n1_atanh(    feoarrm9n1_t* arr);
void      feoarrm9n1_atanh_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_asinh(    feoarrm9n1_t* arr);
void      feoarrm9n1_asinh_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_acosh(    feoarrm9n1_t* arr);
void      feoarrm9n1_acosh_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n1_t feoarrm9n1_tanh(     feoarrm9n1_t* arr);
void      feoarrm9n1_tanh_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_sinh(     feoarrm9n1_t* arr);
void      feoarrm9n1_sinh_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_cosh(     feoarrm9n1_t* arr);
void      feoarrm9n1_cosh_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n1_t feoarrm9n1_atan(     feoarrm9n1_t* arr);
void      feoarrm9n1_atan_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_asin(     feoarrm9n1_t* arr);
void      feoarrm9n1_asin_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_acos(     feoarrm9n1_t* arr);
void      feoarrm9n1_acos_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n1_t feoarrm9n1_tan(      feoarrm9n1_t* arr);
void      feoarrm9n1_tan_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_sin(      feoarrm9n1_t* arr);
void      feoarrm9n1_sin_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_cos(      feoarrm9n1_t* arr);
void      feoarrm9n1_cos_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm9n1_t feoarrm9n1_logb(     feoarrm9n1_t* arr, double base);
void      feoarrm9n1_logb_to(  feoarrm9n1_t* arr, double base, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_log10(    feoarrm9n1_t* arr);
void      feoarrm9n1_log10_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_log(      feoarrm9n1_t* arr);
void      feoarrm9n1_log_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_exp(      feoarrm9n1_t* arr);
void      feoarrm9n1_exp_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n1_t feoarrm9n1_cbrt(     feoarrm9n1_t* arr);
void      feoarrm9n1_cbrt_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_sqrt(     feoarrm9n1_t* arr);
void      feoarrm9n1_sqrt_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
feoarrm9n1_t feoarrm9n1_pow(      feoarrm9n1_t* arr, double e);
void      feoarrm9n1_pow_to(   feoarrm9n1_t* arr, double e, feoarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif