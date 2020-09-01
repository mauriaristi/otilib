#ifndef OTI_ONUMM5N3_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N3_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_atanh(    feoarrm5n3_t* arr);
void      feoarrm5n3_atanh_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_asinh(    feoarrm5n3_t* arr);
void      feoarrm5n3_asinh_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_acosh(    feoarrm5n3_t* arr);
void      feoarrm5n3_acosh_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_tanh(     feoarrm5n3_t* arr);
void      feoarrm5n3_tanh_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_sinh(     feoarrm5n3_t* arr);
void      feoarrm5n3_sinh_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_cosh(     feoarrm5n3_t* arr);
void      feoarrm5n3_cosh_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_atan(     feoarrm5n3_t* arr);
void      feoarrm5n3_atan_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_asin(     feoarrm5n3_t* arr);
void      feoarrm5n3_asin_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_acos(     feoarrm5n3_t* arr);
void      feoarrm5n3_acos_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_tan(      feoarrm5n3_t* arr);
void      feoarrm5n3_tan_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_sin(      feoarrm5n3_t* arr);
void      feoarrm5n3_sin_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_cos(      feoarrm5n3_t* arr);
void      feoarrm5n3_cos_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_logb(     feoarrm5n3_t* arr, double base);
void      feoarrm5n3_logb_to(  feoarrm5n3_t* arr, double base, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_log10(    feoarrm5n3_t* arr);
void      feoarrm5n3_log10_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_log(      feoarrm5n3_t* arr);
void      feoarrm5n3_log_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_exp(      feoarrm5n3_t* arr);
void      feoarrm5n3_exp_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_cbrt(     feoarrm5n3_t* arr);
void      feoarrm5n3_cbrt_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_sqrt(     feoarrm5n3_t* arr);
void      feoarrm5n3_sqrt_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
feoarrm5n3_t feoarrm5n3_pow(      feoarrm5n3_t* arr, double e);
void      feoarrm5n3_pow_to(   feoarrm5n3_t* arr, double e, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif