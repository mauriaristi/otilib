#ifndef OTI_MDNUM5_ARRAY_FUNCTIONS_H
#define OTI_MDNUM5_ARRAY_FUNCTIONS_H

mdarr5_t mdarr5_atanh(   mdarr5_t* arr);
void    mdarr5_atanh_to(mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_asinh(   mdarr5_t* arr);
void    mdarr5_asinh_to(mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_acosh(   mdarr5_t* arr);
void    mdarr5_acosh_to(mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_tanh(    mdarr5_t* arr);
void    mdarr5_tanh_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_cbrt(    mdarr5_t* arr);
void    mdarr5_cbrt_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_sqrt(    mdarr5_t* arr);
void    mdarr5_sqrt_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_cosh(    mdarr5_t* arr);
void    mdarr5_cosh_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_sinh(    mdarr5_t* arr);
void    mdarr5_sinh_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_asin(    mdarr5_t* arr);
void    mdarr5_asin_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_acos(    mdarr5_t* arr);
void    mdarr5_acos_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_atan(    mdarr5_t* arr);
void    mdarr5_atan_to( mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_tan(     mdarr5_t* arr);
void    mdarr5_tan_to(  mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_cos(     mdarr5_t* arr);
void    mdarr5_cos_to(  mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_sin(     mdarr5_t* arr);
void    mdarr5_sin_to(  mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_logb(    mdarr5_t* arr, double base);
void    mdarr5_logb_to( mdarr5_t* arr, double base, mdarr5_t* res);

mdarr5_t mdarr5_log10(   mdarr5_t* arr);
void    mdarr5_log10_to(mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_log(     mdarr5_t* arr);
void    mdarr5_log_to(  mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_exp(     mdarr5_t* arr);
void    mdarr5_exp_to(  mdarr5_t* arr, mdarr5_t* res);

mdarr5_t mdarr5_pow(     mdarr5_t* arr, double e);
void    mdarr5_pow_to(  mdarr5_t* arr, double e, mdarr5_t* res);

#endif