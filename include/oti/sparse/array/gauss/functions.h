#ifndef OTI_SPARSE_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_SPARSE_ARRAY_GAUSS_FUNCTIONS_H






/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_atanh(    fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_atanh_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_asinh(    fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_asinh_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_acosh(    fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_acosh_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_tanh(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_tanh_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_sinh(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_sinh_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_cosh(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_cosh_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);


/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_atan(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_atan_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_asin(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_asin_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_acos(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_acos_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_tan(      fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_tan_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_sin(      fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_sin_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_cos(      fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_cos_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);


/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_logb(     fearrso_t* arr, double base,                 dhelpl_t dhl);
void      fearrso_logb_to(  fearrso_t* arr, double base, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_log10(    fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_log10_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_log(      fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_log_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_exp(      fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_exp_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_cbrt(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_cbrt_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_sqrt(     fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_sqrt_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_pow(      fearrso_t* arr, double e,                    dhelpl_t dhl);
void      fearrso_pow_to(   fearrso_t* arr, double e, fearrso_t* res,    dhelpl_t dhl);










#endif