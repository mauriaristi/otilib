#ifndef OTI_MDNUM3_ARRAY_FUNCTIONS_H
#define OTI_MDNUM3_ARRAY_FUNCTIONS_H

mdarr3_t mdarr3_atanh(   mdarr3_t* arr);
void    mdarr3_atanh_to(mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_asinh(   mdarr3_t* arr);
void    mdarr3_asinh_to(mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_acosh(   mdarr3_t* arr);
void    mdarr3_acosh_to(mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_tanh(    mdarr3_t* arr);
void    mdarr3_tanh_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_cbrt(    mdarr3_t* arr);
void    mdarr3_cbrt_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_sqrt(    mdarr3_t* arr);
void    mdarr3_sqrt_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_cosh(    mdarr3_t* arr);
void    mdarr3_cosh_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_sinh(    mdarr3_t* arr);
void    mdarr3_sinh_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_asin(    mdarr3_t* arr);
void    mdarr3_asin_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_acos(    mdarr3_t* arr);
void    mdarr3_acos_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_atan(    mdarr3_t* arr);
void    mdarr3_atan_to( mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_tan(     mdarr3_t* arr);
void    mdarr3_tan_to(  mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_cos(     mdarr3_t* arr);
void    mdarr3_cos_to(  mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_sin(     mdarr3_t* arr);
void    mdarr3_sin_to(  mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_logb(    mdarr3_t* arr, double base);
void    mdarr3_logb_to( mdarr3_t* arr, double base, mdarr3_t* res);

mdarr3_t mdarr3_log10(   mdarr3_t* arr);
void    mdarr3_log10_to(mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_log(     mdarr3_t* arr);
void    mdarr3_log_to(  mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_exp(     mdarr3_t* arr);
void    mdarr3_exp_to(  mdarr3_t* arr, mdarr3_t* res);

mdarr3_t mdarr3_pow(     mdarr3_t* arr, double e);
void    mdarr3_pow_to(  mdarr3_t* arr, double e, mdarr3_t* res);

#endif