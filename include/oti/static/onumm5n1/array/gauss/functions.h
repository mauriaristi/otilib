#ifndef OTI_ONUMM5N1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n1_t feoarrm5n1_atanh(    feoarrm5n1_t* arr);
void      feoarrm5n1_atanh_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_asinh(    feoarrm5n1_t* arr);
void      feoarrm5n1_asinh_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_acosh(    feoarrm5n1_t* arr);
void      feoarrm5n1_acosh_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n1_t feoarrm5n1_tanh(     feoarrm5n1_t* arr);
void      feoarrm5n1_tanh_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_sinh(     feoarrm5n1_t* arr);
void      feoarrm5n1_sinh_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_cosh(     feoarrm5n1_t* arr);
void      feoarrm5n1_cosh_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n1_t feoarrm5n1_atan(     feoarrm5n1_t* arr);
void      feoarrm5n1_atan_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_asin(     feoarrm5n1_t* arr);
void      feoarrm5n1_asin_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_acos(     feoarrm5n1_t* arr);
void      feoarrm5n1_acos_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n1_t feoarrm5n1_tan(      feoarrm5n1_t* arr);
void      feoarrm5n1_tan_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_sin(      feoarrm5n1_t* arr);
void      feoarrm5n1_sin_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_cos(      feoarrm5n1_t* arr);
void      feoarrm5n1_cos_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm5n1_t feoarrm5n1_logb(     feoarrm5n1_t* arr, double base);
void      feoarrm5n1_logb_to(  feoarrm5n1_t* arr, double base, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_log10(    feoarrm5n1_t* arr);
void      feoarrm5n1_log10_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_log(      feoarrm5n1_t* arr);
void      feoarrm5n1_log_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_exp(      feoarrm5n1_t* arr);
void      feoarrm5n1_exp_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n1_t feoarrm5n1_cbrt(     feoarrm5n1_t* arr);
void      feoarrm5n1_cbrt_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_sqrt(     feoarrm5n1_t* arr);
void      feoarrm5n1_sqrt_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
feoarrm5n1_t feoarrm5n1_pow(      feoarrm5n1_t* arr, double e);
void      feoarrm5n1_pow_to(   feoarrm5n1_t* arr, double e, feoarrm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif