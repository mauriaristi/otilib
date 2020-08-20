#ifndef OTI_ONUMM3N3_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N3_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n3_t feoarrm3n3_atanh(    feoarrm3n3_t* arr);
void      feoarrm3n3_atanh_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_asinh(    feoarrm3n3_t* arr);
void      feoarrm3n3_asinh_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_acosh(    feoarrm3n3_t* arr);
void      feoarrm3n3_acosh_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n3_t feoarrm3n3_tanh(     feoarrm3n3_t* arr);
void      feoarrm3n3_tanh_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_sinh(     feoarrm3n3_t* arr);
void      feoarrm3n3_sinh_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_cosh(     feoarrm3n3_t* arr);
void      feoarrm3n3_cosh_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n3_t feoarrm3n3_atan(     feoarrm3n3_t* arr);
void      feoarrm3n3_atan_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_asin(     feoarrm3n3_t* arr);
void      feoarrm3n3_asin_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_acos(     feoarrm3n3_t* arr);
void      feoarrm3n3_acos_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n3_t feoarrm3n3_tan(      feoarrm3n3_t* arr);
void      feoarrm3n3_tan_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_sin(      feoarrm3n3_t* arr);
void      feoarrm3n3_sin_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_cos(      feoarrm3n3_t* arr);
void      feoarrm3n3_cos_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm3n3_t feoarrm3n3_logb(     feoarrm3n3_t* arr, double base);
void      feoarrm3n3_logb_to(  feoarrm3n3_t* arr, double base, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_log10(    feoarrm3n3_t* arr);
void      feoarrm3n3_log10_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_log(      feoarrm3n3_t* arr);
void      feoarrm3n3_log_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_exp(      feoarrm3n3_t* arr);
void      feoarrm3n3_exp_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n3_t feoarrm3n3_cbrt(     feoarrm3n3_t* arr);
void      feoarrm3n3_cbrt_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_sqrt(     feoarrm3n3_t* arr);
void      feoarrm3n3_sqrt_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
feoarrm3n3_t feoarrm3n3_pow(      feoarrm3n3_t* arr, double e);
void      feoarrm3n3_pow_to(   feoarrm3n3_t* arr, double e, feoarrm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif