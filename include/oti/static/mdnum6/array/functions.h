#ifndef OTI_MDNUM6_ARRAY_FUNCTIONS_H
#define OTI_MDNUM6_ARRAY_FUNCTIONS_H

mdarr6_t mdarr6_atanh(   mdarr6_t* arr);
void    mdarr6_atanh_to(mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_asinh(   mdarr6_t* arr);
void    mdarr6_asinh_to(mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_acosh(   mdarr6_t* arr);
void    mdarr6_acosh_to(mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_tanh(    mdarr6_t* arr);
void    mdarr6_tanh_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_cbrt(    mdarr6_t* arr);
void    mdarr6_cbrt_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_sqrt(    mdarr6_t* arr);
void    mdarr6_sqrt_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_cosh(    mdarr6_t* arr);
void    mdarr6_cosh_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_sinh(    mdarr6_t* arr);
void    mdarr6_sinh_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_asin(    mdarr6_t* arr);
void    mdarr6_asin_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_acos(    mdarr6_t* arr);
void    mdarr6_acos_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_atan(    mdarr6_t* arr);
void    mdarr6_atan_to( mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_tan(     mdarr6_t* arr);
void    mdarr6_tan_to(  mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_cos(     mdarr6_t* arr);
void    mdarr6_cos_to(  mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_sin(     mdarr6_t* arr);
void    mdarr6_sin_to(  mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_logb(    mdarr6_t* arr, double base);
void    mdarr6_logb_to( mdarr6_t* arr, double base, mdarr6_t* res);

mdarr6_t mdarr6_log10(   mdarr6_t* arr);
void    mdarr6_log10_to(mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_log(     mdarr6_t* arr);
void    mdarr6_log_to(  mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_exp(     mdarr6_t* arr);
void    mdarr6_exp_to(  mdarr6_t* arr, mdarr6_t* res);

mdarr6_t mdarr6_pow(     mdarr6_t* arr, double e);
void    mdarr6_pow_to(  mdarr6_t* arr, double e, mdarr6_t* res);

#endif