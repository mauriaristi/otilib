#ifndef OTI_MDNUM2_ARRAY_FUNCTIONS_H
#define OTI_MDNUM2_ARRAY_FUNCTIONS_H

mdarr2_t mdarr2_atanh(   mdarr2_t* arr);
void    mdarr2_atanh_to(mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_asinh(   mdarr2_t* arr);
void    mdarr2_asinh_to(mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_acosh(   mdarr2_t* arr);
void    mdarr2_acosh_to(mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_tanh(    mdarr2_t* arr);
void    mdarr2_tanh_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_cbrt(    mdarr2_t* arr);
void    mdarr2_cbrt_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_sqrt(    mdarr2_t* arr);
void    mdarr2_sqrt_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_cosh(    mdarr2_t* arr);
void    mdarr2_cosh_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_sinh(    mdarr2_t* arr);
void    mdarr2_sinh_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_asin(    mdarr2_t* arr);
void    mdarr2_asin_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_acos(    mdarr2_t* arr);
void    mdarr2_acos_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_atan(    mdarr2_t* arr);
void    mdarr2_atan_to( mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_tan(     mdarr2_t* arr);
void    mdarr2_tan_to(  mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_cos(     mdarr2_t* arr);
void    mdarr2_cos_to(  mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_sin(     mdarr2_t* arr);
void    mdarr2_sin_to(  mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_logb(    mdarr2_t* arr, double base);
void    mdarr2_logb_to( mdarr2_t* arr, double base, mdarr2_t* res);

mdarr2_t mdarr2_log10(   mdarr2_t* arr);
void    mdarr2_log10_to(mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_log(     mdarr2_t* arr);
void    mdarr2_log_to(  mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_exp(     mdarr2_t* arr);
void    mdarr2_exp_to(  mdarr2_t* arr, mdarr2_t* res);

mdarr2_t mdarr2_pow(     mdarr2_t* arr, double e);
void    mdarr2_pow_to(  mdarr2_t* arr, double e, mdarr2_t* res);

#endif