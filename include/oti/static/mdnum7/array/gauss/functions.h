#ifndef OTI_MDNUM7_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM7_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_atanh(    femdarr7_t* arr);
void      femdarr7_atanh_to( femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_asinh(    femdarr7_t* arr);
void      femdarr7_asinh_to( femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_acosh(    femdarr7_t* arr);
void      femdarr7_acosh_to( femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_tanh(     femdarr7_t* arr);
void      femdarr7_tanh_to(  femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_sinh(     femdarr7_t* arr);
void      femdarr7_sinh_to(  femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_cosh(     femdarr7_t* arr);
void      femdarr7_cosh_to(  femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_atan(     femdarr7_t* arr);
void      femdarr7_atan_to(  femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_asin(     femdarr7_t* arr);
void      femdarr7_asin_to(  femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_acos(     femdarr7_t* arr);
void      femdarr7_acos_to(  femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_tan(      femdarr7_t* arr);
void      femdarr7_tan_to(   femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_sin(      femdarr7_t* arr);
void      femdarr7_sin_to(   femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_cos(      femdarr7_t* arr);
void      femdarr7_cos_to(   femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_logb(     femdarr7_t* arr, double base);
void      femdarr7_logb_to(  femdarr7_t* arr, double base, femdarr7_t* res);
femdarr7_t femdarr7_log10(    femdarr7_t* arr);
void      femdarr7_log10_to( femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_log(      femdarr7_t* arr);
void      femdarr7_log_to(   femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_exp(      femdarr7_t* arr);
void      femdarr7_exp_to(   femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_cbrt(     femdarr7_t* arr);
void      femdarr7_cbrt_to(  femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_sqrt(     femdarr7_t* arr);
void      femdarr7_sqrt_to(  femdarr7_t* arr, femdarr7_t* res);
femdarr7_t femdarr7_pow(      femdarr7_t* arr, double e);
void      femdarr7_pow_to(   femdarr7_t* arr, double e, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif