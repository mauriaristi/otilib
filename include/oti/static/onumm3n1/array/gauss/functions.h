#ifndef OTI_ONUMM3N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n1_t feoarrm3n1_atanh(    feoarrm3n1_t* arr);
void      feoarrm3n1_atanh_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_asinh(    feoarrm3n1_t* arr);
void      feoarrm3n1_asinh_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_acosh(    feoarrm3n1_t* arr);
void      feoarrm3n1_acosh_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n1_t feoarrm3n1_tanh(     feoarrm3n1_t* arr);
void      feoarrm3n1_tanh_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_sinh(     feoarrm3n1_t* arr);
void      feoarrm3n1_sinh_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_cosh(     feoarrm3n1_t* arr);
void      feoarrm3n1_cosh_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n1_t feoarrm3n1_atan(     feoarrm3n1_t* arr);
void      feoarrm3n1_atan_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_asin(     feoarrm3n1_t* arr);
void      feoarrm3n1_asin_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_acos(     feoarrm3n1_t* arr);
void      feoarrm3n1_acos_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n1_t feoarrm3n1_tan(      feoarrm3n1_t* arr);
void      feoarrm3n1_tan_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_sin(      feoarrm3n1_t* arr);
void      feoarrm3n1_sin_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_cos(      feoarrm3n1_t* arr);
void      feoarrm3n1_cos_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm3n1_t feoarrm3n1_logb(     feoarrm3n1_t* arr, double base);
void      feoarrm3n1_logb_to(  feoarrm3n1_t* arr, double base, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_log10(    feoarrm3n1_t* arr);
void      feoarrm3n1_log10_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_log(      feoarrm3n1_t* arr);
void      feoarrm3n1_log_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_exp(      feoarrm3n1_t* arr);
void      feoarrm3n1_exp_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n1_t feoarrm3n1_cbrt(     feoarrm3n1_t* arr);
void      feoarrm3n1_cbrt_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_sqrt(     feoarrm3n1_t* arr);
void      feoarrm3n1_sqrt_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
feoarrm3n1_t feoarrm3n1_pow(      feoarrm3n1_t* arr, double e);
void      feoarrm3n1_pow_to(   feoarrm3n1_t* arr, double e, feoarrm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif