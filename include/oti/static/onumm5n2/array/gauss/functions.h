#ifndef OTI_ONUMM5N2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_ONUMM5N2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n2_t feoarrm5n2_atanh(    feoarrm5n2_t* arr);
void      feoarrm5n2_atanh_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_asinh(    feoarrm5n2_t* arr);
void      feoarrm5n2_asinh_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_acosh(    feoarrm5n2_t* arr);
void      feoarrm5n2_acosh_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n2_t feoarrm5n2_tanh(     feoarrm5n2_t* arr);
void      feoarrm5n2_tanh_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_sinh(     feoarrm5n2_t* arr);
void      feoarrm5n2_sinh_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_cosh(     feoarrm5n2_t* arr);
void      feoarrm5n2_cosh_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n2_t feoarrm5n2_atan(     feoarrm5n2_t* arr);
void      feoarrm5n2_atan_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_asin(     feoarrm5n2_t* arr);
void      feoarrm5n2_asin_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_acos(     feoarrm5n2_t* arr);
void      feoarrm5n2_acos_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n2_t feoarrm5n2_tan(      feoarrm5n2_t* arr);
void      feoarrm5n2_tan_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_sin(      feoarrm5n2_t* arr);
void      feoarrm5n2_sin_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_cos(      feoarrm5n2_t* arr);
void      feoarrm5n2_cos_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm5n2_t feoarrm5n2_logb(     feoarrm5n2_t* arr, double base);
void      feoarrm5n2_logb_to(  feoarrm5n2_t* arr, double base, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_log10(    feoarrm5n2_t* arr);
void      feoarrm5n2_log10_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_log(      feoarrm5n2_t* arr);
void      feoarrm5n2_log_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_exp(      feoarrm5n2_t* arr);
void      feoarrm5n2_exp_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n2_t feoarrm5n2_cbrt(     feoarrm5n2_t* arr);
void      feoarrm5n2_cbrt_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_sqrt(     feoarrm5n2_t* arr);
void      feoarrm5n2_sqrt_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
feoarrm5n2_t feoarrm5n2_pow(      feoarrm5n2_t* arr, double e);
void      feoarrm5n2_pow_to(   feoarrm5n2_t* arr, double e, feoarrm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif