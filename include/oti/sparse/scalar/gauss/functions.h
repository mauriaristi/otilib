#ifndef OTI_SPARSE_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_SPARSE_SCALAR_GAUSS_FUNCTIONS_H







/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_atanh(    fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_atanh_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_asinh(    fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_asinh_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_acosh(    fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_acosh_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_tanh(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_tanh_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_cosh(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_cosh_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_sinh(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_sinh_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_asin(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_asin_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_acos(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_acos_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_atan(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_atan_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_tan(      fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_tan_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_cos(      fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_cos_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_sin(      fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_sin_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_logb(     fesoti_t* num, double base,                dhelpl_t dhl);
void     fesoti_logb_to(  fesoti_t* num, double base, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_log10(    fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_log10_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_log(      fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_log_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_exp(      fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_exp_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_cbrt(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_cbrt_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_sqrt(     fesoti_t* num,                             dhelpl_t dhl);
void     fesoti_sqrt_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);

fesoti_t fesoti_pow(      fesoti_t* num, double e,                   dhelpl_t dhl);
void     fesoti_pow_to(   fesoti_t* num, double e, fesoti_t* res,    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{i=1}^{i=nip} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
sotinum_t fesoti_integrate(    fesoti_t* num, fesoti_t* w,                 dhelpl_t dhl);
void      fesoti_integrate_to( fesoti_t* num, fesoti_t* w, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




#endif