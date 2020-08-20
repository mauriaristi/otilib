#ifndef OTI_MDNUM4_ARRAY_FUNCTIONS_H
#define OTI_MDNUM4_ARRAY_FUNCTIONS_H

mdarr4_t mdarr4_atanh(   mdarr4_t* arr);
void    mdarr4_atanh_to(mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_asinh(   mdarr4_t* arr);
void    mdarr4_asinh_to(mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_acosh(   mdarr4_t* arr);
void    mdarr4_acosh_to(mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_tanh(    mdarr4_t* arr);
void    mdarr4_tanh_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_cbrt(    mdarr4_t* arr);
void    mdarr4_cbrt_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_sqrt(    mdarr4_t* arr);
void    mdarr4_sqrt_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_cosh(    mdarr4_t* arr);
void    mdarr4_cosh_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_sinh(    mdarr4_t* arr);
void    mdarr4_sinh_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_asin(    mdarr4_t* arr);
void    mdarr4_asin_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_acos(    mdarr4_t* arr);
void    mdarr4_acos_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_atan(    mdarr4_t* arr);
void    mdarr4_atan_to( mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_tan(     mdarr4_t* arr);
void    mdarr4_tan_to(  mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_cos(     mdarr4_t* arr);
void    mdarr4_cos_to(  mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_sin(     mdarr4_t* arr);
void    mdarr4_sin_to(  mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_logb(    mdarr4_t* arr, double base);
void    mdarr4_logb_to( mdarr4_t* arr, double base, mdarr4_t* res);

mdarr4_t mdarr4_log10(   mdarr4_t* arr);
void    mdarr4_log10_to(mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_log(     mdarr4_t* arr);
void    mdarr4_log_to(  mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_exp(     mdarr4_t* arr);
void    mdarr4_exp_to(  mdarr4_t* arr, mdarr4_t* res);

mdarr4_t mdarr4_pow(     mdarr4_t* arr, double e);
void    mdarr4_pow_to(  mdarr4_t* arr, double e, mdarr4_t* res);

#endif