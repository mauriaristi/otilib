#ifndef OTI_ONUMM5N4_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N4_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n4_t feoarrm5n4_atanh(    feoarrm5n4_t* arr);
void      feoarrm5n4_atanh_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_asinh(    feoarrm5n4_t* arr);
void      feoarrm5n4_asinh_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_acosh(    feoarrm5n4_t* arr);
void      feoarrm5n4_acosh_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n4_t feoarrm5n4_tanh(     feoarrm5n4_t* arr);
void      feoarrm5n4_tanh_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_sinh(     feoarrm5n4_t* arr);
void      feoarrm5n4_sinh_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_cosh(     feoarrm5n4_t* arr);
void      feoarrm5n4_cosh_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n4_t feoarrm5n4_atan(     feoarrm5n4_t* arr);
void      feoarrm5n4_atan_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_asin(     feoarrm5n4_t* arr);
void      feoarrm5n4_asin_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_acos(     feoarrm5n4_t* arr);
void      feoarrm5n4_acos_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n4_t feoarrm5n4_tan(      feoarrm5n4_t* arr);
void      feoarrm5n4_tan_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_sin(      feoarrm5n4_t* arr);
void      feoarrm5n4_sin_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_cos(      feoarrm5n4_t* arr);
void      feoarrm5n4_cos_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm5n4_t feoarrm5n4_logb(     feoarrm5n4_t* arr, double base);
void      feoarrm5n4_logb_to(  feoarrm5n4_t* arr, double base, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_log10(    feoarrm5n4_t* arr);
void      feoarrm5n4_log10_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_log(      feoarrm5n4_t* arr);
void      feoarrm5n4_log_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_exp(      feoarrm5n4_t* arr);
void      feoarrm5n4_exp_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n4_t feoarrm5n4_cbrt(     feoarrm5n4_t* arr);
void      feoarrm5n4_cbrt_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_sqrt(     feoarrm5n4_t* arr);
void      feoarrm5n4_sqrt_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
feoarrm5n4_t feoarrm5n4_pow(      feoarrm5n4_t* arr, double e);
void      feoarrm5n4_pow_to(   feoarrm5n4_t* arr, double e, feoarrm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif