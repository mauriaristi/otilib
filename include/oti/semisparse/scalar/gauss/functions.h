#ifndef OTI_SEMISPARSE_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_SEMISPARSE_SCALAR_GAUSS_FUNCTIONS_H







/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_atanh(    fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_atanh_to( fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_asinh(    fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_asinh_to( fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_acosh(    fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_acosh_to( fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_tanh(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_tanh_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_cosh(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_cosh_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_sinh(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_sinh_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_asin(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_asin_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_acos(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_acos_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_atan(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_atan_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_tan(      fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_tan_to(   fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_cos(      fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_cos_to(   fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_sin(      fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_sin_to(   fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_logb(     fessoti_t* num, double base,                dhelpl_t dhl);
void     fessoti_logb_to(  fessoti_t* num, double base, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_log10(    fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_log10_to( fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_log(      fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_log_to(   fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_exp(      fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_exp_to(   fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_cbrt(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_cbrt_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_sqrt(     fessoti_t* num,                             dhelpl_t dhl);
void     fessoti_sqrt_to(  fessoti_t* num, fessoti_t* res,              dhelpl_t dhl);

fessoti_t fessoti_pow(      fessoti_t* num, double e,                   dhelpl_t dhl);
void     fessoti_pow_to(   fessoti_t* num, double e, fessoti_t* res,    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
semiotin_t fessoti_integrate(       fessoti_t* num, fessoti_t* w,                 dhelpl_t dhl);
void      fessoti_integrate_to(    fessoti_t* num, fessoti_t* w, semiotin_t* res, dhelpl_t dhl);

semiotin_t fessoti_integrate_f(     fessoti_t* num, fessoti_t* w,                 dhelpl_t dhl);
void      fessoti_integrate_f_to(  fessoti_t* num, fessoti_t* w, semiotin_t* res, dhelpl_t dhl);

semiotin_t fessoti_integrate_r(       coeff_t num, fessoti_t* w,                 dhelpl_t dhl);
void      fessoti_integrate_r_to(    coeff_t num, fessoti_t* w, semiotin_t* res, dhelpl_t dhl);

semiotin_t fessoti_integrate_o(    semiotin_t* num, fessoti_t* w,                 dhelpl_t dhl);
void      fessoti_integrate_o_to( semiotin_t* num, fessoti_t* w, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




#endif