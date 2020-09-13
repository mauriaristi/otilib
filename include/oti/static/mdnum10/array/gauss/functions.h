#ifndef OTI_MDNUM10_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM10_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_atanh(    femdarr10_t* arr);
void      femdarr10_atanh_to( femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_asinh(    femdarr10_t* arr);
void      femdarr10_asinh_to( femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_acosh(    femdarr10_t* arr);
void      femdarr10_acosh_to( femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_tanh(     femdarr10_t* arr);
void      femdarr10_tanh_to(  femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_sinh(     femdarr10_t* arr);
void      femdarr10_sinh_to(  femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_cosh(     femdarr10_t* arr);
void      femdarr10_cosh_to(  femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_atan(     femdarr10_t* arr);
void      femdarr10_atan_to(  femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_asin(     femdarr10_t* arr);
void      femdarr10_asin_to(  femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_acos(     femdarr10_t* arr);
void      femdarr10_acos_to(  femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_tan(      femdarr10_t* arr);
void      femdarr10_tan_to(   femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_sin(      femdarr10_t* arr);
void      femdarr10_sin_to(   femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_cos(      femdarr10_t* arr);
void      femdarr10_cos_to(   femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_logb(     femdarr10_t* arr, double base);
void      femdarr10_logb_to(  femdarr10_t* arr, double base, femdarr10_t* res);
femdarr10_t femdarr10_log10(    femdarr10_t* arr);
void      femdarr10_log10_to( femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_log(      femdarr10_t* arr);
void      femdarr10_log_to(   femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_exp(      femdarr10_t* arr);
void      femdarr10_exp_to(   femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_cbrt(     femdarr10_t* arr);
void      femdarr10_cbrt_to(  femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_sqrt(     femdarr10_t* arr);
void      femdarr10_sqrt_to(  femdarr10_t* arr, femdarr10_t* res);
femdarr10_t femdarr10_pow(      femdarr10_t* arr, double e);
void      femdarr10_pow_to(   femdarr10_t* arr, double e, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif