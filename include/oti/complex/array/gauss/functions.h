#ifndef OTI_COMPLEX_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_COMPLEX_ARRAY_GAUSS_FUNCTIONS_H




/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_atanh(    fedarr_t* arr               );
void      fedarr_atanh_to( fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_asinh(    fedarr_t* arr               );
void      fedarr_asinh_to( fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_acosh(    fedarr_t* arr               );
void      fedarr_acosh_to( fedarr_t* arr, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_tanh(     fedarr_t* arr               );
void      fedarr_tanh_to(  fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_sinh(     fedarr_t* arr               );
void      fedarr_sinh_to(  fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_cosh(     fedarr_t* arr               );
void      fedarr_cosh_to(  fedarr_t* arr, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_atan(     fedarr_t* arr               );
void      fedarr_atan_to(  fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_asin(     fedarr_t* arr               );
void      fedarr_asin_to(  fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_acos(     fedarr_t* arr               );
void      fedarr_acos_to(  fedarr_t* arr, fedarr_t* res);

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_tan(      fedarr_t* arr               );
void      fedarr_tan_to(   fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_sin(      fedarr_t* arr               );
void      fedarr_sin_to(   fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_cos(      fedarr_t* arr               );
void      fedarr_cos_to(   fedarr_t* arr, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_logb(     fedarr_t* arr, double base               );
void      fedarr_logb_to(  fedarr_t* arr, double base, fedarr_t* res);
fedarr_t  fedarr_log10(    fedarr_t* arr               );
void      fedarr_log10_to( fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_log(      fedarr_t* arr               );
void      fedarr_log_to(   fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_exp(      fedarr_t* arr               );
void      fedarr_exp_to(   fedarr_t* arr, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_cbrt(     fedarr_t* arr               );
void      fedarr_cbrt_to(  fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_sqrt(     fedarr_t* arr               );
void      fedarr_sqrt_to(  fedarr_t* arr, fedarr_t* res);
fedarr_t  fedarr_pow(      fedarr_t* arr, double e               );
void      fedarr_pow_to(   fedarr_t* arr, double e, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------





#endif