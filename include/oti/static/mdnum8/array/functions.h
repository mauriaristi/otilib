#ifndef OTI_MDNUM8_ARRAY_FUNCTIONS_H
#define OTI_MDNUM8_ARRAY_FUNCTIONS_H

mdarr8_t mdarr8_atanh(   mdarr8_t* arr);
void    mdarr8_atanh_to(mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_asinh(   mdarr8_t* arr);
void    mdarr8_asinh_to(mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_acosh(   mdarr8_t* arr);
void    mdarr8_acosh_to(mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_tanh(    mdarr8_t* arr);
void    mdarr8_tanh_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_cbrt(    mdarr8_t* arr);
void    mdarr8_cbrt_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_sqrt(    mdarr8_t* arr);
void    mdarr8_sqrt_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_cosh(    mdarr8_t* arr);
void    mdarr8_cosh_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_sinh(    mdarr8_t* arr);
void    mdarr8_sinh_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_asin(    mdarr8_t* arr);
void    mdarr8_asin_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_acos(    mdarr8_t* arr);
void    mdarr8_acos_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_atan(    mdarr8_t* arr);
void    mdarr8_atan_to( mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_tan(     mdarr8_t* arr);
void    mdarr8_tan_to(  mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_cos(     mdarr8_t* arr);
void    mdarr8_cos_to(  mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_sin(     mdarr8_t* arr);
void    mdarr8_sin_to(  mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_logb(    mdarr8_t* arr, double base);
void    mdarr8_logb_to( mdarr8_t* arr, double base, mdarr8_t* res);

mdarr8_t mdarr8_log10(   mdarr8_t* arr);
void    mdarr8_log10_to(mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_log(     mdarr8_t* arr);
void    mdarr8_log_to(  mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_exp(     mdarr8_t* arr);
void    mdarr8_exp_to(  mdarr8_t* arr, mdarr8_t* res);

mdarr8_t mdarr8_pow(     mdarr8_t* arr, double e);
void    mdarr8_pow_to(  mdarr8_t* arr, double e, mdarr8_t* res);

#endif