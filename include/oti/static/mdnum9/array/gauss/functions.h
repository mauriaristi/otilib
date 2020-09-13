#ifndef OTI_MDNUM9_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM9_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_atanh(    femdarr9_t* arr);
void      femdarr9_atanh_to( femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_asinh(    femdarr9_t* arr);
void      femdarr9_asinh_to( femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_acosh(    femdarr9_t* arr);
void      femdarr9_acosh_to( femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_tanh(     femdarr9_t* arr);
void      femdarr9_tanh_to(  femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_sinh(     femdarr9_t* arr);
void      femdarr9_sinh_to(  femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_cosh(     femdarr9_t* arr);
void      femdarr9_cosh_to(  femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_atan(     femdarr9_t* arr);
void      femdarr9_atan_to(  femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_asin(     femdarr9_t* arr);
void      femdarr9_asin_to(  femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_acos(     femdarr9_t* arr);
void      femdarr9_acos_to(  femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_tan(      femdarr9_t* arr);
void      femdarr9_tan_to(   femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_sin(      femdarr9_t* arr);
void      femdarr9_sin_to(   femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_cos(      femdarr9_t* arr);
void      femdarr9_cos_to(   femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_logb(     femdarr9_t* arr, double base);
void      femdarr9_logb_to(  femdarr9_t* arr, double base, femdarr9_t* res);
femdarr9_t femdarr9_log10(    femdarr9_t* arr);
void      femdarr9_log10_to( femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_log(      femdarr9_t* arr);
void      femdarr9_log_to(   femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_exp(      femdarr9_t* arr);
void      femdarr9_exp_to(   femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_cbrt(     femdarr9_t* arr);
void      femdarr9_cbrt_to(  femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_sqrt(     femdarr9_t* arr);
void      femdarr9_sqrt_to(  femdarr9_t* arr, femdarr9_t* res);
femdarr9_t femdarr9_pow(      femdarr9_t* arr, double e);
void      femdarr9_pow_to(   femdarr9_t* arr, double e, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif