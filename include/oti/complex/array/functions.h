#ifndef OTI_COMPLEX_FUNCTIONS_H
#define OTI_COMPLEX_FUNCTIONS_H

// Math functions.

carr_t carr_atanh(carr_t* arr);
void   carr_atanh_to(carr_t* arr, carr_t* res);

carr_t carr_asinh(carr_t* arr);
void   carr_asinh_to(carr_t* arr, carr_t* res);

carr_t carr_acosh(carr_t* arr);
void   carr_acosh_to(carr_t* arr, carr_t* res);

carr_t carr_tanh(carr_t* arr);
void   carr_tanh_to(carr_t* arr, carr_t* res);

carr_t carr_cbrt(carr_t* arr);
void   carr_cbrt_to(carr_t* arr, carr_t* res);

carr_t carr_sqrt(carr_t* arr);
void   carr_sqrt_to(carr_t* arr, carr_t* res);

carr_t carr_cosh(carr_t* arr);
void   carr_cosh_to(carr_t* arr, carr_t* res);

carr_t carr_sinh(carr_t* arr);
void   carr_sinh_to(carr_t* arr, carr_t* res);

carr_t carr_asin(carr_t* arr);
void   carr_asin_to(carr_t* arr, carr_t* res);

carr_t carr_acos(carr_t* arr);
void   carr_acos_to(carr_t* arr, carr_t* res);

carr_t carr_atan(carr_t* arr);
void   carr_atan_to(carr_t* arr, carr_t* res);

carr_t carr_tan(carr_t* arr);
void   carr_tan_to(carr_t* arr, carr_t* res);

carr_t carr_cos(carr_t* arr);
void   carr_cos_to(carr_t* arr, carr_t* res);

carr_t carr_sin(carr_t* arr );
void   carr_sin_to(carr_t* arr, carr_t* res);

carr_t carr_log(carr_t* arr);
void   carr_log_to(carr_t* arr, carr_t* res);

carr_t carr_exp(carr_t* arr);
void   carr_exp_to(carr_t* arr, carr_t* res);

carr_t carr_pow(carr_t* arr, ccoeff_t e);
void   carr_pow_to(carr_t* arr, ccoeff_t e, carr_t* res);

#endif