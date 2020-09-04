#ifndef OTI_ONUMM10N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM10N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n1_t feoarrm10n1_atanh(    feoarrm10n1_t* arr);
void      feoarrm10n1_atanh_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_asinh(    feoarrm10n1_t* arr);
void      feoarrm10n1_asinh_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_acosh(    feoarrm10n1_t* arr);
void      feoarrm10n1_acosh_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n1_t feoarrm10n1_tanh(     feoarrm10n1_t* arr);
void      feoarrm10n1_tanh_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_sinh(     feoarrm10n1_t* arr);
void      feoarrm10n1_sinh_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_cosh(     feoarrm10n1_t* arr);
void      feoarrm10n1_cosh_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n1_t feoarrm10n1_atan(     feoarrm10n1_t* arr);
void      feoarrm10n1_atan_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_asin(     feoarrm10n1_t* arr);
void      feoarrm10n1_asin_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_acos(     feoarrm10n1_t* arr);
void      feoarrm10n1_acos_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n1_t feoarrm10n1_tan(      feoarrm10n1_t* arr);
void      feoarrm10n1_tan_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_sin(      feoarrm10n1_t* arr);
void      feoarrm10n1_sin_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_cos(      feoarrm10n1_t* arr);
void      feoarrm10n1_cos_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm10n1_t feoarrm10n1_logb(     feoarrm10n1_t* arr, double base);
void      feoarrm10n1_logb_to(  feoarrm10n1_t* arr, double base, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_log10(    feoarrm10n1_t* arr);
void      feoarrm10n1_log10_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_log(      feoarrm10n1_t* arr);
void      feoarrm10n1_log_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_exp(      feoarrm10n1_t* arr);
void      feoarrm10n1_exp_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n1_t feoarrm10n1_cbrt(     feoarrm10n1_t* arr);
void      feoarrm10n1_cbrt_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_sqrt(     feoarrm10n1_t* arr);
void      feoarrm10n1_sqrt_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
feoarrm10n1_t feoarrm10n1_pow(      feoarrm10n1_t* arr, double e);
void      feoarrm10n1_pow_to(   feoarrm10n1_t* arr, double e, feoarrm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif