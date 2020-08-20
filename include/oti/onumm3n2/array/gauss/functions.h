#ifndef OTI_ONUMM3N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM3N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n2_t feoarrm3n2_atanh(    feoarrm3n2_t* arr);
void      feoarrm3n2_atanh_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_asinh(    feoarrm3n2_t* arr);
void      feoarrm3n2_asinh_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_acosh(    feoarrm3n2_t* arr);
void      feoarrm3n2_acosh_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n2_t feoarrm3n2_tanh(     feoarrm3n2_t* arr);
void      feoarrm3n2_tanh_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_sinh(     feoarrm3n2_t* arr);
void      feoarrm3n2_sinh_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_cosh(     feoarrm3n2_t* arr);
void      feoarrm3n2_cosh_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n2_t feoarrm3n2_atan(     feoarrm3n2_t* arr);
void      feoarrm3n2_atan_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_asin(     feoarrm3n2_t* arr);
void      feoarrm3n2_asin_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_acos(     feoarrm3n2_t* arr);
void      feoarrm3n2_acos_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n2_t feoarrm3n2_tan(      feoarrm3n2_t* arr);
void      feoarrm3n2_tan_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_sin(      feoarrm3n2_t* arr);
void      feoarrm3n2_sin_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_cos(      feoarrm3n2_t* arr);
void      feoarrm3n2_cos_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm3n2_t feoarrm3n2_logb(     feoarrm3n2_t* arr, double base);
void      feoarrm3n2_logb_to(  feoarrm3n2_t* arr, double base, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_log10(    feoarrm3n2_t* arr);
void      feoarrm3n2_log10_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_log(      feoarrm3n2_t* arr);
void      feoarrm3n2_log_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_exp(      feoarrm3n2_t* arr);
void      feoarrm3n2_exp_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n2_t feoarrm3n2_cbrt(     feoarrm3n2_t* arr);
void      feoarrm3n2_cbrt_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_sqrt(     feoarrm3n2_t* arr);
void      feoarrm3n2_sqrt_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
feoarrm3n2_t feoarrm3n2_pow(      feoarrm3n2_t* arr, double e);
void      feoarrm3n2_pow_to(   feoarrm3n2_t* arr, double e, feoarrm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif