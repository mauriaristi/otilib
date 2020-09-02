#ifndef OTI_MDNUM1_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_MDNUM1_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_atanh(    femdarr1_t* arr);
void      femdarr1_atanh_to( femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_asinh(    femdarr1_t* arr);
void      femdarr1_asinh_to( femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_acosh(    femdarr1_t* arr);
void      femdarr1_acosh_to( femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_tanh(     femdarr1_t* arr);
void      femdarr1_tanh_to(  femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_sinh(     femdarr1_t* arr);
void      femdarr1_sinh_to(  femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_cosh(     femdarr1_t* arr);
void      femdarr1_cosh_to(  femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_atan(     femdarr1_t* arr);
void      femdarr1_atan_to(  femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_asin(     femdarr1_t* arr);
void      femdarr1_asin_to(  femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_acos(     femdarr1_t* arr);
void      femdarr1_acos_to(  femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_tan(      femdarr1_t* arr);
void      femdarr1_tan_to(   femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_sin(      femdarr1_t* arr);
void      femdarr1_sin_to(   femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_cos(      femdarr1_t* arr);
void      femdarr1_cos_to(   femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_logb(     femdarr1_t* arr, double base);
void      femdarr1_logb_to(  femdarr1_t* arr, double base, femdarr1_t* res);
femdarr1_t femdarr1_log10(    femdarr1_t* arr);
void      femdarr1_log10_to( femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_log(      femdarr1_t* arr);
void      femdarr1_log_to(   femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_exp(      femdarr1_t* arr);
void      femdarr1_exp_to(   femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_cbrt(     femdarr1_t* arr);
void      femdarr1_cbrt_to(  femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_sqrt(     femdarr1_t* arr);
void      femdarr1_sqrt_to(  femdarr1_t* arr, femdarr1_t* res);
femdarr1_t femdarr1_pow(      femdarr1_t* arr, double e);
void      femdarr1_pow_to(   femdarr1_t* arr, double e, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif