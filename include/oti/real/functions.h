#ifndef OTI_REAL_FUNCTIONS_H
#define OTI_REAL_FUNCTIONS_H

// Math functions.

darr_t darr_atanh(darr_t* arr);
void   darr_atanh_to(darr_t* arr, darr_t* res);

darr_t darr_asinh(darr_t* arr);
void   darr_asinh_to(darr_t* arr, darr_t* res);

darr_t darr_acosh(darr_t* arr);
void   darr_acosh_to(darr_t* arr, darr_t* res);

darr_t darr_tanh(darr_t* arr);
void   darr_tanh_to(darr_t* arr, darr_t* res);

darr_t darr_cbrt(darr_t* arr);
void darr_cbrt_to(darr_t* arr, darr_t* res);

darr_t darr_sqrt(darr_t* arr);
void   darr_sqrt_to(darr_t* arr, darr_t* res);

darr_t darr_cosh(darr_t* arr);
void   darr_cosh_to(darr_t* arr, darr_t* res);

darr_t darr_sinh(darr_t* arr);
void   darr_sinh_to(darr_t* arr, darr_t* res);

darr_t darr_asin(darr_t* arr);
void   darr_asin_to(darr_t* arr, darr_t* res);

darr_t darr_acos(darr_t* arr);
void   darr_acos_to(darr_t* arr, darr_t* res);

darr_t darr_atan(darr_t* arr);
void   darr_atan_to(darr_t* arr, darr_t* res);

darr_t darr_tan(darr_t* arr);
void   darr_tan_to(darr_t* arr, darr_t* res);

darr_t darr_cos(darr_t* arr);
void   darr_cos_to(darr_t* arr, darr_t* res);

darr_t darr_sin(darr_t* arr );
void   darr_sin_to(darr_t* arr, darr_t* res);

darr_t darr_logb(darr_t* arr, double base);
void   darr_logb_to(darr_t* arr, double base, darr_t* res);

darr_t darr_log10(darr_t* arr);
void   darr_log10_to(darr_t* arr, darr_t* res);

darr_t darr_log(darr_t* arr);
void   darr_log_to(darr_t* arr, darr_t* res);

darr_t darr_exp(darr_t* arr);
void   darr_exp_to(darr_t* arr, darr_t* res);

darr_t darr_pow(darr_t* arr, double e);
void   darr_pow_to(darr_t* arr, double e, darr_t* res);



#endif