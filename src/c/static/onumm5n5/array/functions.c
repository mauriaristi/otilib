

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_atanh(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);

    oarrm5n5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_asinh(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);

    oarrm5n5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_acosh(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);

    oarrm5n5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_tanh(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);

    oarrm5n5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_cbrt(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);

    oarrm5n5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_sqrt(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_cosh(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_sinh(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_asin(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_acos(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_atan(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_tan(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_cos(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_sin(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_logb(oarrm5n5_t* arr, double base){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_log10(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_log(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_exp(oarrm5n5_t* arr){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);
    
    oarrm5n5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n5_t oarrm5n5_pow(oarrm5n5_t* arr, double e){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr->nrows, arr->ncols);

    oarrm5n5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------
