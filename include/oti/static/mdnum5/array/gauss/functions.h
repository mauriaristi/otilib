#ifndef OTI_MDNUM5_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM5_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_atanh(    femdarr5_t* arr);
void      femdarr5_atanh_to( femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_asinh(    femdarr5_t* arr);
void      femdarr5_asinh_to( femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_acosh(    femdarr5_t* arr);
void      femdarr5_acosh_to( femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_tanh(     femdarr5_t* arr);
void      femdarr5_tanh_to(  femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_sinh(     femdarr5_t* arr);
void      femdarr5_sinh_to(  femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_cosh(     femdarr5_t* arr);
void      femdarr5_cosh_to(  femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_atan(     femdarr5_t* arr);
void      femdarr5_atan_to(  femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_asin(     femdarr5_t* arr);
void      femdarr5_asin_to(  femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_acos(     femdarr5_t* arr);
void      femdarr5_acos_to(  femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_tan(      femdarr5_t* arr);
void      femdarr5_tan_to(   femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_sin(      femdarr5_t* arr);
void      femdarr5_sin_to(   femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_cos(      femdarr5_t* arr);
void      femdarr5_cos_to(   femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_logb(     femdarr5_t* arr, double base);
void      femdarr5_logb_to(  femdarr5_t* arr, double base, femdarr5_t* res);
femdarr5_t femdarr5_log10(    femdarr5_t* arr);
void      femdarr5_log10_to( femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_log(      femdarr5_t* arr);
void      femdarr5_log_to(   femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_exp(      femdarr5_t* arr);
void      femdarr5_exp_to(   femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_cbrt(     femdarr5_t* arr);
void      femdarr5_cbrt_to(  femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_sqrt(     femdarr5_t* arr);
void      femdarr5_sqrt_to(  femdarr5_t* arr, femdarr5_t* res);
femdarr5_t femdarr5_pow(      femdarr5_t* arr, double e);
void      femdarr5_pow_to(   femdarr5_t* arr, double e, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif