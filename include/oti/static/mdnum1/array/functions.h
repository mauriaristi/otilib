#ifndef OTI_MDNUM1_ARRAY_FUNCTIONS_H
#define OTI_MDNUM1_ARRAY_FUNCTIONS_H

mdarr1_t mdarr1_atanh(   mdarr1_t* arr);
void    mdarr1_atanh_to(mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_asinh(   mdarr1_t* arr);
void    mdarr1_asinh_to(mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_acosh(   mdarr1_t* arr);
void    mdarr1_acosh_to(mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_tanh(    mdarr1_t* arr);
void    mdarr1_tanh_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_cbrt(    mdarr1_t* arr);
void    mdarr1_cbrt_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_sqrt(    mdarr1_t* arr);
void    mdarr1_sqrt_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_cosh(    mdarr1_t* arr);
void    mdarr1_cosh_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_sinh(    mdarr1_t* arr);
void    mdarr1_sinh_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_asin(    mdarr1_t* arr);
void    mdarr1_asin_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_acos(    mdarr1_t* arr);
void    mdarr1_acos_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_atan(    mdarr1_t* arr);
void    mdarr1_atan_to( mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_tan(     mdarr1_t* arr);
void    mdarr1_tan_to(  mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_cos(     mdarr1_t* arr);
void    mdarr1_cos_to(  mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_sin(     mdarr1_t* arr);
void    mdarr1_sin_to(  mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_logb(    mdarr1_t* arr, double base);
void    mdarr1_logb_to( mdarr1_t* arr, double base, mdarr1_t* res);

mdarr1_t mdarr1_log10(   mdarr1_t* arr);
void    mdarr1_log10_to(mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_log(     mdarr1_t* arr);
void    mdarr1_log_to(  mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_exp(     mdarr1_t* arr);
void    mdarr1_exp_to(  mdarr1_t* arr, mdarr1_t* res);

mdarr1_t mdarr1_pow(     mdarr1_t* arr, double e);
void    mdarr1_pow_to(  mdarr1_t* arr, double e, mdarr1_t* res);

#endif