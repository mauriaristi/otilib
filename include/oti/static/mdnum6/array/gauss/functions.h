#ifndef OTI_MDNUM6_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM6_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_atanh(    femdarr6_t* arr);
void      femdarr6_atanh_to( femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_asinh(    femdarr6_t* arr);
void      femdarr6_asinh_to( femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_acosh(    femdarr6_t* arr);
void      femdarr6_acosh_to( femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_tanh(     femdarr6_t* arr);
void      femdarr6_tanh_to(  femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_sinh(     femdarr6_t* arr);
void      femdarr6_sinh_to(  femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_cosh(     femdarr6_t* arr);
void      femdarr6_cosh_to(  femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_atan(     femdarr6_t* arr);
void      femdarr6_atan_to(  femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_asin(     femdarr6_t* arr);
void      femdarr6_asin_to(  femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_acos(     femdarr6_t* arr);
void      femdarr6_acos_to(  femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_tan(      femdarr6_t* arr);
void      femdarr6_tan_to(   femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_sin(      femdarr6_t* arr);
void      femdarr6_sin_to(   femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_cos(      femdarr6_t* arr);
void      femdarr6_cos_to(   femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_logb(     femdarr6_t* arr, double base);
void      femdarr6_logb_to(  femdarr6_t* arr, double base, femdarr6_t* res);
femdarr6_t femdarr6_log10(    femdarr6_t* arr);
void      femdarr6_log10_to( femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_log(      femdarr6_t* arr);
void      femdarr6_log_to(   femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_exp(      femdarr6_t* arr);
void      femdarr6_exp_to(   femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_cbrt(     femdarr6_t* arr);
void      femdarr6_cbrt_to(  femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_sqrt(     femdarr6_t* arr);
void      femdarr6_sqrt_to(  femdarr6_t* arr, femdarr6_t* res);
femdarr6_t femdarr6_pow(      femdarr6_t* arr, double e);
void      femdarr6_pow_to(   femdarr6_t* arr, double e, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif