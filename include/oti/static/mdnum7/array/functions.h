#ifndef OTI_MDNUM7_ARRAY_FUNCTIONS_H
#define OTI_MDNUM7_ARRAY_FUNCTIONS_H

mdarr7_t mdarr7_atanh(   mdarr7_t* arr);
void    mdarr7_atanh_to(mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_asinh(   mdarr7_t* arr);
void    mdarr7_asinh_to(mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_acosh(   mdarr7_t* arr);
void    mdarr7_acosh_to(mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_tanh(    mdarr7_t* arr);
void    mdarr7_tanh_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_cbrt(    mdarr7_t* arr);
void    mdarr7_cbrt_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_sqrt(    mdarr7_t* arr);
void    mdarr7_sqrt_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_cosh(    mdarr7_t* arr);
void    mdarr7_cosh_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_sinh(    mdarr7_t* arr);
void    mdarr7_sinh_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_asin(    mdarr7_t* arr);
void    mdarr7_asin_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_acos(    mdarr7_t* arr);
void    mdarr7_acos_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_atan(    mdarr7_t* arr);
void    mdarr7_atan_to( mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_tan(     mdarr7_t* arr);
void    mdarr7_tan_to(  mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_cos(     mdarr7_t* arr);
void    mdarr7_cos_to(  mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_sin(     mdarr7_t* arr);
void    mdarr7_sin_to(  mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_logb(    mdarr7_t* arr, double base);
void    mdarr7_logb_to( mdarr7_t* arr, double base, mdarr7_t* res);

mdarr7_t mdarr7_log10(   mdarr7_t* arr);
void    mdarr7_log10_to(mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_log(     mdarr7_t* arr);
void    mdarr7_log_to(  mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_exp(     mdarr7_t* arr);
void    mdarr7_exp_to(  mdarr7_t* arr, mdarr7_t* res);

mdarr7_t mdarr7_pow(     mdarr7_t* arr, double e);
void    mdarr7_pow_to(  mdarr7_t* arr, double e, mdarr7_t* res);

#endif