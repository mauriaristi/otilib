#ifndef OTI_MDNUM9_ARRAY_FUNCTIONS_H
#define OTI_MDNUM9_ARRAY_FUNCTIONS_H

mdarr9_t mdarr9_atanh(   mdarr9_t* arr);
void    mdarr9_atanh_to(mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_asinh(   mdarr9_t* arr);
void    mdarr9_asinh_to(mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_acosh(   mdarr9_t* arr);
void    mdarr9_acosh_to(mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_tanh(    mdarr9_t* arr);
void    mdarr9_tanh_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_cbrt(    mdarr9_t* arr);
void    mdarr9_cbrt_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_sqrt(    mdarr9_t* arr);
void    mdarr9_sqrt_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_cosh(    mdarr9_t* arr);
void    mdarr9_cosh_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_sinh(    mdarr9_t* arr);
void    mdarr9_sinh_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_asin(    mdarr9_t* arr);
void    mdarr9_asin_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_acos(    mdarr9_t* arr);
void    mdarr9_acos_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_atan(    mdarr9_t* arr);
void    mdarr9_atan_to( mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_tan(     mdarr9_t* arr);
void    mdarr9_tan_to(  mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_cos(     mdarr9_t* arr);
void    mdarr9_cos_to(  mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_sin(     mdarr9_t* arr);
void    mdarr9_sin_to(  mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_logb(    mdarr9_t* arr, double base);
void    mdarr9_logb_to( mdarr9_t* arr, double base, mdarr9_t* res);

mdarr9_t mdarr9_log10(   mdarr9_t* arr);
void    mdarr9_log10_to(mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_log(     mdarr9_t* arr);
void    mdarr9_log_to(  mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_exp(     mdarr9_t* arr);
void    mdarr9_exp_to(  mdarr9_t* arr, mdarr9_t* res);

mdarr9_t mdarr9_pow(     mdarr9_t* arr, double e);
void    mdarr9_pow_to(  mdarr9_t* arr, double e, mdarr9_t* res);

#endif