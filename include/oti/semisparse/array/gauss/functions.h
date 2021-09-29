#ifndef OTI_SEMISPARSE_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_SEMISPARSE_ARRAY_GAUSS_FUNCTIONS_H






/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_atanh(    fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_atanh_to( fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_asinh(    fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_asinh_to( fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_acosh(    fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_acosh_to( fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_tanh(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_tanh_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_sinh(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_sinh_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_cosh(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_cosh_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_atan(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_atan_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_asin(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_asin_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_acos(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_acos_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_tan(      fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_tan_to(   fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_sin(      fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_sin_to(   fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_cos(      fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_cos_to(   fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_logb(     fearrsso_t* arr, double base,                 dhelpl_t dhl);
void      fearrsso_logb_to(  fearrsso_t* arr, double base, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_log10(    fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_log10_to( fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_log(      fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_log_to(   fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_exp(      fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_exp_to(   fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_cbrt(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_cbrt_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_sqrt(     fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_sqrt_to(  fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
fearrsso_t fearrsso_pow(      fearrsso_t* arr, double e,                    dhelpl_t dhl);
void      fearrsso_pow_to(   fearrsso_t* arr, double e, fearrsso_t* res,    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------










#endif