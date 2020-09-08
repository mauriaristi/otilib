#ifndef OTI_ONUMM8N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM8N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n2_t feoarrm8n2_atanh(    feoarrm8n2_t* arr);
void      feoarrm8n2_atanh_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_asinh(    feoarrm8n2_t* arr);
void      feoarrm8n2_asinh_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_acosh(    feoarrm8n2_t* arr);
void      feoarrm8n2_acosh_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n2_t feoarrm8n2_tanh(     feoarrm8n2_t* arr);
void      feoarrm8n2_tanh_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_sinh(     feoarrm8n2_t* arr);
void      feoarrm8n2_sinh_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_cosh(     feoarrm8n2_t* arr);
void      feoarrm8n2_cosh_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n2_t feoarrm8n2_atan(     feoarrm8n2_t* arr);
void      feoarrm8n2_atan_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_asin(     feoarrm8n2_t* arr);
void      feoarrm8n2_asin_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_acos(     feoarrm8n2_t* arr);
void      feoarrm8n2_acos_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n2_t feoarrm8n2_tan(      feoarrm8n2_t* arr);
void      feoarrm8n2_tan_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_sin(      feoarrm8n2_t* arr);
void      feoarrm8n2_sin_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_cos(      feoarrm8n2_t* arr);
void      feoarrm8n2_cos_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm8n2_t feoarrm8n2_logb(     feoarrm8n2_t* arr, double base);
void      feoarrm8n2_logb_to(  feoarrm8n2_t* arr, double base, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_log10(    feoarrm8n2_t* arr);
void      feoarrm8n2_log10_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_log(      feoarrm8n2_t* arr);
void      feoarrm8n2_log_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_exp(      feoarrm8n2_t* arr);
void      feoarrm8n2_exp_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n2_t feoarrm8n2_cbrt(     feoarrm8n2_t* arr);
void      feoarrm8n2_cbrt_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_sqrt(     feoarrm8n2_t* arr);
void      feoarrm8n2_sqrt_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
feoarrm8n2_t feoarrm8n2_pow(      feoarrm8n2_t* arr, double e);
void      feoarrm8n2_pow_to(   feoarrm8n2_t* arr, double e, feoarrm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif