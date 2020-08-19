#ifndef OTI_MDNUM3_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM3_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_atanh(    femdarr3_t* arr);
void      femdarr3_atanh_to( femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_asinh(    femdarr3_t* arr);
void      femdarr3_asinh_to( femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_acosh(    femdarr3_t* arr);
void      femdarr3_acosh_to( femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_tanh(     femdarr3_t* arr);
void      femdarr3_tanh_to(  femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_sinh(     femdarr3_t* arr);
void      femdarr3_sinh_to(  femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_cosh(     femdarr3_t* arr);
void      femdarr3_cosh_to(  femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_atan(     femdarr3_t* arr);
void      femdarr3_atan_to(  femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_asin(     femdarr3_t* arr);
void      femdarr3_asin_to(  femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_acos(     femdarr3_t* arr);
void      femdarr3_acos_to(  femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_tan(      femdarr3_t* arr);
void      femdarr3_tan_to(   femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_sin(      femdarr3_t* arr);
void      femdarr3_sin_to(   femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_cos(      femdarr3_t* arr);
void      femdarr3_cos_to(   femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_logb(     femdarr3_t* arr, double base);
void      femdarr3_logb_to(  femdarr3_t* arr, double base, femdarr3_t* res);
femdarr3_t femdarr3_log10(    femdarr3_t* arr);
void      femdarr3_log10_to( femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_log(      femdarr3_t* arr);
void      femdarr3_log_to(   femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_exp(      femdarr3_t* arr);
void      femdarr3_exp_to(   femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_cbrt(     femdarr3_t* arr);
void      femdarr3_cbrt_to(  femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_sqrt(     femdarr3_t* arr);
void      femdarr3_sqrt_to(  femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_pow(      femdarr3_t* arr, double e);
void      femdarr3_pow_to(   femdarr3_t* arr, double e, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif