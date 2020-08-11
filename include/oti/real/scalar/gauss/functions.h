#ifndef OTI_REAL_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_REAL_SCALAR_GAUSS_FUNCTIONS_H


/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_atanh(    fednum_t* num                );
void     fednum_atanh_to( fednum_t* num, fednum_t* res );

fednum_t fednum_asinh(    fednum_t* num                );
void     fednum_asinh_to( fednum_t* num, fednum_t* res );

fednum_t fednum_acosh(    fednum_t* num                );
void     fednum_acosh_to( fednum_t* num, fednum_t* res );

fednum_t fednum_tanh(     fednum_t* num                );
void     fednum_tanh_to(  fednum_t* num, fednum_t* res );

fednum_t fednum_cosh(     fednum_t* num                );
void     fednum_cosh_to(  fednum_t* num, fednum_t* res );

fednum_t fednum_sinh(     fednum_t* num                );
void     fednum_sinh_to(  fednum_t* num, fednum_t* res );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_asin(     fednum_t* num                );
void     fednum_asin_to(  fednum_t* num, fednum_t* res );

fednum_t fednum_acos(     fednum_t* num                );
void     fednum_acos_to(  fednum_t* num, fednum_t* res );

fednum_t fednum_atan(     fednum_t* num                );
void     fednum_atan_to(  fednum_t* num, fednum_t* res );

fednum_t fednum_tan(      fednum_t* num                );
void     fednum_tan_to(   fednum_t* num, fednum_t* res );

fednum_t fednum_cos(      fednum_t* num                );
void     fednum_cos_to(   fednum_t* num, fednum_t* res );

fednum_t fednum_sin(      fednum_t* num                );
void     fednum_sin_to(   fednum_t* num, fednum_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_logb(     fednum_t* num, double base                );
void     fednum_logb_to(  fednum_t* num, double base, fednum_t* res );

fednum_t fednum_log10(    fednum_t* num                             );
void     fednum_log10_to( fednum_t* num, fednum_t* res              );

fednum_t fednum_log(      fednum_t* num                             );
void     fednum_log_to(   fednum_t* num, fednum_t* res              );

fednum_t fednum_exp(      fednum_t* num                             );
void     fednum_exp_to(   fednum_t* num, fednum_t* res              );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_cbrt(     fednum_t* num                          );
void     fednum_cbrt_to(  fednum_t* num, fednum_t* res           );

fednum_t fednum_sqrt(     fednum_t* num                          );
void     fednum_sqrt_to(  fednum_t* num, fednum_t* res           );

fednum_t fednum_pow(      fednum_t* num, double e                );
void     fednum_pow_to(   fednum_t* num, double e, fednum_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
******************************************************************************************************/
coeff_t   fednum_integrate(       fednum_t* num, fednum_t* w                 );
void      fednum_integrate_to(    fednum_t* num, fednum_t* w, coeff_t  * res );

coeff_t   fednum_integrate_f(     fednum_t* num, fednum_t* w                 );
void      fednum_integrate_f_to(  fednum_t* num, fednum_t* w, coeff_t  * res );

coeff_t   fednum_integrate_r(       coeff_t num, fednum_t* w                 );
void      fednum_integrate_r_to(    coeff_t num, fednum_t* w, coeff_t  * res );
// ----------------------------------------------------------------------------------------------------



#endif