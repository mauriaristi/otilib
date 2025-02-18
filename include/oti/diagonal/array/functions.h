#ifndef OTI_SPARSE_ARRAY_FUNCTIONS_H
#define OTI_SPARSE_ARRAY_FUNCTIONS_H


arrso_t arrso_erf(   arrso_t* arr,               dhelpl_t dhl);
void    arrso_erf_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_atanh(   arrso_t* arr,               dhelpl_t dhl);
void    arrso_atanh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_asinh(   arrso_t* arr,               dhelpl_t dhl);
void    arrso_asinh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_acosh(   arrso_t* arr,               dhelpl_t dhl);
void    arrso_acosh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_tanh(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_tanh_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_cbrt(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_cbrt_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_sqrt(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_sqrt_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_cosh(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_cosh_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_sinh(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_sinh_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_asin(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_asin_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_acos(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_acos_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_atan(    arrso_t* arr,               dhelpl_t dhl);
void    arrso_atan_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_tan(     arrso_t* arr,               dhelpl_t dhl);
void    arrso_tan_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_cos(     arrso_t* arr,               dhelpl_t dhl);
void    arrso_cos_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_sin(     arrso_t* arr,               dhelpl_t dhl);
void    arrso_sin_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_logb(    arrso_t* arr, double base,               dhelpl_t dhl);
void    arrso_logb_to( arrso_t* arr, double base, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_log10(   arrso_t* arr,               dhelpl_t dhl);
void    arrso_log10_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_log(     arrso_t* arr,               dhelpl_t dhl);
void    arrso_log_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_exp(     arrso_t* arr,               dhelpl_t dhl);
void    arrso_exp_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_pow(     arrso_t* arr, double e,               dhelpl_t dhl);
void    arrso_pow_to(  arrso_t* arr, double e, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_pow_soti(   arrso_t* arr, sotinum_t* e,               dhelpl_t dhl);
void    arrso_pow_soti_to(arrso_t* arr, sotinum_t* e, arrso_t* res, dhelpl_t dhl);

arrso_t arrso_pow_arrso(     arrso_t* arr, arrso_t* earr,               dhelpl_t dhl);
void    arrso_pow_arrso_to(  arrso_t* arr, arrso_t* earr, arrso_t* res, dhelpl_t dhl);

arrso_t soti_pow_arrso(      sotinum_t* a, arrso_t* earr,               dhelpl_t dhl);
void    soti_pow_arrso_to(   sotinum_t* a, arrso_t* earr, arrso_t* res, dhelpl_t dhl);




















#endif