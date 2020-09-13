#ifndef OTI_MDNUM10_ARRAY_FUNCTIONS_H
#define OTI_MDNUM10_ARRAY_FUNCTIONS_H

mdarr10_t mdarr10_atanh(   mdarr10_t* arr);
void    mdarr10_atanh_to(mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_asinh(   mdarr10_t* arr);
void    mdarr10_asinh_to(mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_acosh(   mdarr10_t* arr);
void    mdarr10_acosh_to(mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_tanh(    mdarr10_t* arr);
void    mdarr10_tanh_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_cbrt(    mdarr10_t* arr);
void    mdarr10_cbrt_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_sqrt(    mdarr10_t* arr);
void    mdarr10_sqrt_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_cosh(    mdarr10_t* arr);
void    mdarr10_cosh_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_sinh(    mdarr10_t* arr);
void    mdarr10_sinh_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_asin(    mdarr10_t* arr);
void    mdarr10_asin_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_acos(    mdarr10_t* arr);
void    mdarr10_acos_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_atan(    mdarr10_t* arr);
void    mdarr10_atan_to( mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_tan(     mdarr10_t* arr);
void    mdarr10_tan_to(  mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_cos(     mdarr10_t* arr);
void    mdarr10_cos_to(  mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_sin(     mdarr10_t* arr);
void    mdarr10_sin_to(  mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_logb(    mdarr10_t* arr, double base);
void    mdarr10_logb_to( mdarr10_t* arr, double base, mdarr10_t* res);

mdarr10_t mdarr10_log10(   mdarr10_t* arr);
void    mdarr10_log10_to(mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_log(     mdarr10_t* arr);
void    mdarr10_log_to(  mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_exp(     mdarr10_t* arr);
void    mdarr10_exp_to(  mdarr10_t* arr, mdarr10_t* res);

mdarr10_t mdarr10_pow(     mdarr10_t* arr, double e);
void    mdarr10_pow_to(  mdarr10_t* arr, double e, mdarr10_t* res);

#endif