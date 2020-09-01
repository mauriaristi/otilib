#ifndef OTI_ONUMM5N5_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N5_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_atanh(    feoarrm5n5_t* arr);
void      feoarrm5n5_atanh_to( feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_asinh(    feoarrm5n5_t* arr);
void      feoarrm5n5_asinh_to( feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_acosh(    feoarrm5n5_t* arr);
void      feoarrm5n5_acosh_to( feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_tanh(     feoarrm5n5_t* arr);
void      feoarrm5n5_tanh_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_sinh(     feoarrm5n5_t* arr);
void      feoarrm5n5_sinh_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_cosh(     feoarrm5n5_t* arr);
void      feoarrm5n5_cosh_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_atan(     feoarrm5n5_t* arr);
void      feoarrm5n5_atan_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_asin(     feoarrm5n5_t* arr);
void      feoarrm5n5_asin_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_acos(     feoarrm5n5_t* arr);
void      feoarrm5n5_acos_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_tan(      feoarrm5n5_t* arr);
void      feoarrm5n5_tan_to(   feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_sin(      feoarrm5n5_t* arr);
void      feoarrm5n5_sin_to(   feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_cos(      feoarrm5n5_t* arr);
void      feoarrm5n5_cos_to(   feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_logb(     feoarrm5n5_t* arr, double base);
void      feoarrm5n5_logb_to(  feoarrm5n5_t* arr, double base, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_log10(    feoarrm5n5_t* arr);
void      feoarrm5n5_log10_to( feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_log(      feoarrm5n5_t* arr);
void      feoarrm5n5_log_to(   feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_exp(      feoarrm5n5_t* arr);
void      feoarrm5n5_exp_to(   feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_cbrt(     feoarrm5n5_t* arr);
void      feoarrm5n5_cbrt_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_sqrt(     feoarrm5n5_t* arr);
void      feoarrm5n5_sqrt_to(  feoarrm5n5_t* arr, feoarrm5n5_t* res);
feoarrm5n5_t feoarrm5n5_pow(      feoarrm5n5_t* arr, double e);
void      feoarrm5n5_pow_to(   feoarrm5n5_t* arr, double e, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif