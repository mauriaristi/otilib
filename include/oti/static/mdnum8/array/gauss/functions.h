#ifndef OTI_MDNUM8_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM8_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_atanh(    femdarr8_t* arr);
void      femdarr8_atanh_to( femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_asinh(    femdarr8_t* arr);
void      femdarr8_asinh_to( femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_acosh(    femdarr8_t* arr);
void      femdarr8_acosh_to( femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_tanh(     femdarr8_t* arr);
void      femdarr8_tanh_to(  femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_sinh(     femdarr8_t* arr);
void      femdarr8_sinh_to(  femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_cosh(     femdarr8_t* arr);
void      femdarr8_cosh_to(  femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_atan(     femdarr8_t* arr);
void      femdarr8_atan_to(  femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_asin(     femdarr8_t* arr);
void      femdarr8_asin_to(  femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_acos(     femdarr8_t* arr);
void      femdarr8_acos_to(  femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_tan(      femdarr8_t* arr);
void      femdarr8_tan_to(   femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_sin(      femdarr8_t* arr);
void      femdarr8_sin_to(   femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_cos(      femdarr8_t* arr);
void      femdarr8_cos_to(   femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_logb(     femdarr8_t* arr, double base);
void      femdarr8_logb_to(  femdarr8_t* arr, double base, femdarr8_t* res);
femdarr8_t femdarr8_log10(    femdarr8_t* arr);
void      femdarr8_log10_to( femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_log(      femdarr8_t* arr);
void      femdarr8_log_to(   femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_exp(      femdarr8_t* arr);
void      femdarr8_exp_to(   femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_cbrt(     femdarr8_t* arr);
void      femdarr8_cbrt_to(  femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_sqrt(     femdarr8_t* arr);
void      femdarr8_sqrt_to(  femdarr8_t* arr, femdarr8_t* res);
femdarr8_t femdarr8_pow(      femdarr8_t* arr, double e);
void      femdarr8_pow_to(   femdarr8_t* arr, double e, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif