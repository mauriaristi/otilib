#ifndef OTI_MDNUM4_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM4_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_atanh(    femdarr4_t* arr);
void      femdarr4_atanh_to( femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_asinh(    femdarr4_t* arr);
void      femdarr4_asinh_to( femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_acosh(    femdarr4_t* arr);
void      femdarr4_acosh_to( femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_tanh(     femdarr4_t* arr);
void      femdarr4_tanh_to(  femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_sinh(     femdarr4_t* arr);
void      femdarr4_sinh_to(  femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_cosh(     femdarr4_t* arr);
void      femdarr4_cosh_to(  femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_atan(     femdarr4_t* arr);
void      femdarr4_atan_to(  femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_asin(     femdarr4_t* arr);
void      femdarr4_asin_to(  femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_acos(     femdarr4_t* arr);
void      femdarr4_acos_to(  femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_tan(      femdarr4_t* arr);
void      femdarr4_tan_to(   femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_sin(      femdarr4_t* arr);
void      femdarr4_sin_to(   femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_cos(      femdarr4_t* arr);
void      femdarr4_cos_to(   femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_logb(     femdarr4_t* arr, double base);
void      femdarr4_logb_to(  femdarr4_t* arr, double base, femdarr4_t* res);
femdarr4_t femdarr4_log10(    femdarr4_t* arr);
void      femdarr4_log10_to( femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_log(      femdarr4_t* arr);
void      femdarr4_log_to(   femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_exp(      femdarr4_t* arr);
void      femdarr4_exp_to(   femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_cbrt(     femdarr4_t* arr);
void      femdarr4_cbrt_to(  femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_sqrt(     femdarr4_t* arr);
void      femdarr4_sqrt_to(  femdarr4_t* arr, femdarr4_t* res);
femdarr4_t femdarr4_pow(      femdarr4_t* arr, double e);
void      femdarr4_pow_to(   femdarr4_t* arr, double e, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif