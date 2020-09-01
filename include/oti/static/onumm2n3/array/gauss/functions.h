#ifndef OTI_ONUMM2N3_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N3_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_atanh(    feoarrm2n3_t* arr);
void      feoarrm2n3_atanh_to( feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_asinh(    feoarrm2n3_t* arr);
void      feoarrm2n3_asinh_to( feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_acosh(    feoarrm2n3_t* arr);
void      feoarrm2n3_acosh_to( feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_tanh(     feoarrm2n3_t* arr);
void      feoarrm2n3_tanh_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_sinh(     feoarrm2n3_t* arr);
void      feoarrm2n3_sinh_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_cosh(     feoarrm2n3_t* arr);
void      feoarrm2n3_cosh_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_atan(     feoarrm2n3_t* arr);
void      feoarrm2n3_atan_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_asin(     feoarrm2n3_t* arr);
void      feoarrm2n3_asin_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_acos(     feoarrm2n3_t* arr);
void      feoarrm2n3_acos_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_tan(      feoarrm2n3_t* arr);
void      feoarrm2n3_tan_to(   feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_sin(      feoarrm2n3_t* arr);
void      feoarrm2n3_sin_to(   feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_cos(      feoarrm2n3_t* arr);
void      feoarrm2n3_cos_to(   feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_logb(     feoarrm2n3_t* arr, double base);
void      feoarrm2n3_logb_to(  feoarrm2n3_t* arr, double base, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_log10(    feoarrm2n3_t* arr);
void      feoarrm2n3_log10_to( feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_log(      feoarrm2n3_t* arr);
void      feoarrm2n3_log_to(   feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_exp(      feoarrm2n3_t* arr);
void      feoarrm2n3_exp_to(   feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_cbrt(     feoarrm2n3_t* arr);
void      feoarrm2n3_cbrt_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_sqrt(     feoarrm2n3_t* arr);
void      feoarrm2n3_sqrt_to(  feoarrm2n3_t* arr, feoarrm2n3_t* res);
feoarrm2n3_t feoarrm2n3_pow(      feoarrm2n3_t* arr, double e);
void      feoarrm2n3_pow_to(   feoarrm2n3_t* arr, double e, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif