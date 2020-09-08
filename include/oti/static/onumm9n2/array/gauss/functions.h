#ifndef OTI_ONUMM9N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM9N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n2_t feoarrm9n2_atanh(    feoarrm9n2_t* arr);
void      feoarrm9n2_atanh_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_asinh(    feoarrm9n2_t* arr);
void      feoarrm9n2_asinh_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_acosh(    feoarrm9n2_t* arr);
void      feoarrm9n2_acosh_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n2_t feoarrm9n2_tanh(     feoarrm9n2_t* arr);
void      feoarrm9n2_tanh_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_sinh(     feoarrm9n2_t* arr);
void      feoarrm9n2_sinh_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_cosh(     feoarrm9n2_t* arr);
void      feoarrm9n2_cosh_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n2_t feoarrm9n2_atan(     feoarrm9n2_t* arr);
void      feoarrm9n2_atan_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_asin(     feoarrm9n2_t* arr);
void      feoarrm9n2_asin_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_acos(     feoarrm9n2_t* arr);
void      feoarrm9n2_acos_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n2_t feoarrm9n2_tan(      feoarrm9n2_t* arr);
void      feoarrm9n2_tan_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_sin(      feoarrm9n2_t* arr);
void      feoarrm9n2_sin_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_cos(      feoarrm9n2_t* arr);
void      feoarrm9n2_cos_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm9n2_t feoarrm9n2_logb(     feoarrm9n2_t* arr, double base);
void      feoarrm9n2_logb_to(  feoarrm9n2_t* arr, double base, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_log10(    feoarrm9n2_t* arr);
void      feoarrm9n2_log10_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_log(      feoarrm9n2_t* arr);
void      feoarrm9n2_log_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_exp(      feoarrm9n2_t* arr);
void      feoarrm9n2_exp_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm9n2_t feoarrm9n2_cbrt(     feoarrm9n2_t* arr);
void      feoarrm9n2_cbrt_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_sqrt(     feoarrm9n2_t* arr);
void      feoarrm9n2_sqrt_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
feoarrm9n2_t feoarrm9n2_pow(      feoarrm9n2_t* arr, double e);
void      feoarrm9n2_pow_to(   feoarrm9n2_t* arr, double e, feoarrm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif