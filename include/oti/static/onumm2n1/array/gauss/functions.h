#ifndef OTI_ONUMM2N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM2N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n1_t feoarrm2n1_atanh(    feoarrm2n1_t* arr);
void      feoarrm2n1_atanh_to( feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_asinh(    feoarrm2n1_t* arr);
void      feoarrm2n1_asinh_to( feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_acosh(    feoarrm2n1_t* arr);
void      feoarrm2n1_acosh_to( feoarrm2n1_t* arr, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n1_t feoarrm2n1_tanh(     feoarrm2n1_t* arr);
void      feoarrm2n1_tanh_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_sinh(     feoarrm2n1_t* arr);
void      feoarrm2n1_sinh_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_cosh(     feoarrm2n1_t* arr);
void      feoarrm2n1_cosh_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n1_t feoarrm2n1_atan(     feoarrm2n1_t* arr);
void      feoarrm2n1_atan_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_asin(     feoarrm2n1_t* arr);
void      feoarrm2n1_asin_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_acos(     feoarrm2n1_t* arr);
void      feoarrm2n1_acos_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n1_t feoarrm2n1_tan(      feoarrm2n1_t* arr);
void      feoarrm2n1_tan_to(   feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_sin(      feoarrm2n1_t* arr);
void      feoarrm2n1_sin_to(   feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_cos(      feoarrm2n1_t* arr);
void      feoarrm2n1_cos_to(   feoarrm2n1_t* arr, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n1_t feoarrm2n1_logb(     feoarrm2n1_t* arr, double base);
void      feoarrm2n1_logb_to(  feoarrm2n1_t* arr, double base, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_log10(    feoarrm2n1_t* arr);
void      feoarrm2n1_log10_to( feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_log(      feoarrm2n1_t* arr);
void      feoarrm2n1_log_to(   feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_exp(      feoarrm2n1_t* arr);
void      feoarrm2n1_exp_to(   feoarrm2n1_t* arr, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n1_t feoarrm2n1_cbrt(     feoarrm2n1_t* arr);
void      feoarrm2n1_cbrt_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_sqrt(     feoarrm2n1_t* arr);
void      feoarrm2n1_sqrt_to(  feoarrm2n1_t* arr, feoarrm2n1_t* res);
feoarrm2n1_t feoarrm2n1_pow(      feoarrm2n1_t* arr, double e);
void      feoarrm2n1_pow_to(   feoarrm2n1_t* arr, double e, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif