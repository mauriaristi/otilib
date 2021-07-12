#ifndef OTI_COMPLEX_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_COMPLEX_SCALAR_GAUSS_FUNCTIONS_H


/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_atanh(    fecnum_t* num                );
void     fecnum_atanh_to( fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_asinh(    fecnum_t* num                );
void     fecnum_asinh_to( fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_acosh(    fecnum_t* num                );
void     fecnum_acosh_to( fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_tanh(     fecnum_t* num                );
void     fecnum_tanh_to(  fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_cosh(     fecnum_t* num                );
void     fecnum_cosh_to(  fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_sinh(     fecnum_t* num                );
void     fecnum_sinh_to(  fecnum_t* num, fecnum_t* res );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_asin(     fecnum_t* num                );
void     fecnum_asin_to(  fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_acos(     fecnum_t* num                );
void     fecnum_acos_to(  fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_atan(     fecnum_t* num                );
void     fecnum_atan_to(  fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_tan(      fecnum_t* num                );
void     fecnum_tan_to(   fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_cos(      fecnum_t* num                );
void     fecnum_cos_to(   fecnum_t* num, fecnum_t* res );

fecnum_t fecnum_sin(      fecnum_t* num                );
void     fecnum_sin_to(   fecnum_t* num, fecnum_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_logb(     fecnum_t* num, double base                );
void     fecnum_logb_to(  fecnum_t* num, double base, fecnum_t* res );

fecnum_t fecnum_log10(    fecnum_t* num                             );
void     fecnum_log10_to( fecnum_t* num, fecnum_t* res              );

fecnum_t fecnum_log(      fecnum_t* num                             );
void     fecnum_log_to(   fecnum_t* num, fecnum_t* res              );

fecnum_t fecnum_exp(      fecnum_t* num                             );
void     fecnum_exp_to(   fecnum_t* num, fecnum_t* res              );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_cbrt(     fecnum_t* num                          );
void     fecnum_cbrt_to(  fecnum_t* num, fecnum_t* res           );

fecnum_t fecnum_sqrt(     fecnum_t* num                          );
void     fecnum_sqrt_to(  fecnum_t* num, fecnum_t* res           );

fecnum_t fecnum_pow(      fecnum_t* num, double e                );
void     fecnum_pow_to(   fecnum_t* num, double e, fecnum_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
******************************************************************************************************/
ccoeff_t   fecnum_integrate(       fecnum_t* num, fecnum_t* w                 );
void      fecnum_integrate_to(    fecnum_t* num, fecnum_t* w, ccoeff_t  * res );

ccoeff_t   fecnum_integrate_f(     fecnum_t* num, fecnum_t* w                 );
void      fecnum_integrate_f_to(  fecnum_t* num, fecnum_t* w, ccoeff_t  * res );

ccoeff_t   fecnum_integrate_r(       ccoeff_t num, fecnum_t* w                 );
void      fecnum_integrate_r_to(    ccoeff_t num, fecnum_t* w, ccoeff_t  * res );
// ----------------------------------------------------------------------------------------------------



#endif