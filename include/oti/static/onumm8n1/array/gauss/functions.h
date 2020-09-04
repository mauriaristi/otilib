#ifndef OTI_ONUMM8N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM8N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_atanh(    feoarrm8n1_t* arr);
void      feoarrm8n1_atanh_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_asinh(    feoarrm8n1_t* arr);
void      feoarrm8n1_asinh_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_acosh(    feoarrm8n1_t* arr);
void      feoarrm8n1_acosh_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_tanh(     feoarrm8n1_t* arr);
void      feoarrm8n1_tanh_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_sinh(     feoarrm8n1_t* arr);
void      feoarrm8n1_sinh_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_cosh(     feoarrm8n1_t* arr);
void      feoarrm8n1_cosh_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_atan(     feoarrm8n1_t* arr);
void      feoarrm8n1_atan_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_asin(     feoarrm8n1_t* arr);
void      feoarrm8n1_asin_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_acos(     feoarrm8n1_t* arr);
void      feoarrm8n1_acos_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_tan(      feoarrm8n1_t* arr);
void      feoarrm8n1_tan_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_sin(      feoarrm8n1_t* arr);
void      feoarrm8n1_sin_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_cos(      feoarrm8n1_t* arr);
void      feoarrm8n1_cos_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_logb(     feoarrm8n1_t* arr, double base);
void      feoarrm8n1_logb_to(  feoarrm8n1_t* arr, double base, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_log10(    feoarrm8n1_t* arr);
void      feoarrm8n1_log10_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_log(      feoarrm8n1_t* arr);
void      feoarrm8n1_log_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_exp(      feoarrm8n1_t* arr);
void      feoarrm8n1_exp_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_cbrt(     feoarrm8n1_t* arr);
void      feoarrm8n1_cbrt_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_sqrt(     feoarrm8n1_t* arr);
void      feoarrm8n1_sqrt_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_pow(      feoarrm8n1_t* arr, double e);
void      feoarrm8n1_pow_to(   feoarrm8n1_t* arr, double e, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif