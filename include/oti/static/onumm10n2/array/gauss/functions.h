#ifndef OTI_ONUMM10N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM10N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n2_t feoarrm10n2_atanh(    feoarrm10n2_t* arr);
void      feoarrm10n2_atanh_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_asinh(    feoarrm10n2_t* arr);
void      feoarrm10n2_asinh_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_acosh(    feoarrm10n2_t* arr);
void      feoarrm10n2_acosh_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n2_t feoarrm10n2_tanh(     feoarrm10n2_t* arr);
void      feoarrm10n2_tanh_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_sinh(     feoarrm10n2_t* arr);
void      feoarrm10n2_sinh_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_cosh(     feoarrm10n2_t* arr);
void      feoarrm10n2_cosh_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n2_t feoarrm10n2_atan(     feoarrm10n2_t* arr);
void      feoarrm10n2_atan_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_asin(     feoarrm10n2_t* arr);
void      feoarrm10n2_asin_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_acos(     feoarrm10n2_t* arr);
void      feoarrm10n2_acos_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n2_t feoarrm10n2_tan(      feoarrm10n2_t* arr);
void      feoarrm10n2_tan_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_sin(      feoarrm10n2_t* arr);
void      feoarrm10n2_sin_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_cos(      feoarrm10n2_t* arr);
void      feoarrm10n2_cos_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm10n2_t feoarrm10n2_logb(     feoarrm10n2_t* arr, double base);
void      feoarrm10n2_logb_to(  feoarrm10n2_t* arr, double base, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_log10(    feoarrm10n2_t* arr);
void      feoarrm10n2_log10_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_log(      feoarrm10n2_t* arr);
void      feoarrm10n2_log_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_exp(      feoarrm10n2_t* arr);
void      feoarrm10n2_exp_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm10n2_t feoarrm10n2_cbrt(     feoarrm10n2_t* arr);
void      feoarrm10n2_cbrt_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_sqrt(     feoarrm10n2_t* arr);
void      feoarrm10n2_sqrt_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
feoarrm10n2_t feoarrm10n2_pow(      feoarrm10n2_t* arr, double e);
void      feoarrm10n2_pow_to(   feoarrm10n2_t* arr, double e, feoarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif