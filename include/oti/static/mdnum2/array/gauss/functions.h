#ifndef OTI_MDNUM2_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM2_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_atanh(    femdarr2_t* arr);
void      femdarr2_atanh_to( femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_asinh(    femdarr2_t* arr);
void      femdarr2_asinh_to( femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_acosh(    femdarr2_t* arr);
void      femdarr2_acosh_to( femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_tanh(     femdarr2_t* arr);
void      femdarr2_tanh_to(  femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_sinh(     femdarr2_t* arr);
void      femdarr2_sinh_to(  femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_cosh(     femdarr2_t* arr);
void      femdarr2_cosh_to(  femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_atan(     femdarr2_t* arr);
void      femdarr2_atan_to(  femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_asin(     femdarr2_t* arr);
void      femdarr2_asin_to(  femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_acos(     femdarr2_t* arr);
void      femdarr2_acos_to(  femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_tan(      femdarr2_t* arr);
void      femdarr2_tan_to(   femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_sin(      femdarr2_t* arr);
void      femdarr2_sin_to(   femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_cos(      femdarr2_t* arr);
void      femdarr2_cos_to(   femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_logb(     femdarr2_t* arr, double base);
void      femdarr2_logb_to(  femdarr2_t* arr, double base, femdarr2_t* res);
femdarr2_t femdarr2_log10(    femdarr2_t* arr);
void      femdarr2_log10_to( femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_log(      femdarr2_t* arr);
void      femdarr2_log_to(   femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_exp(      femdarr2_t* arr);
void      femdarr2_exp_to(   femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_cbrt(     femdarr2_t* arr);
void      femdarr2_cbrt_to(  femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_sqrt(     femdarr2_t* arr);
void      femdarr2_sqrt_to(  femdarr2_t* arr, femdarr2_t* res);
femdarr2_t femdarr2_pow(      femdarr2_t* arr, double e);
void      femdarr2_pow_to(   femdarr2_t* arr, double e, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif