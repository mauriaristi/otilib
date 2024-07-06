

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_atanh(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);

    oarrm1n30_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_asinh(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);

    oarrm1n30_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_acosh(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);

    oarrm1n30_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_tanh(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);

    oarrm1n30_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_cbrt(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);

    oarrm1n30_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_sqrt(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_cosh(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_sinh(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_asin(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_acos(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_atan(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_tan(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_cos(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_sin(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_logb(oarrm1n30_t* arr, double base){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_log10(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_log(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_exp(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);
    
    oarrm1n30_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_pow(oarrm1n30_t* arr, double e){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr->nrows, arr->ncols);

    oarrm1n30_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------
