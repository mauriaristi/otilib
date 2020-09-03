

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_atanh(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    oarrm5n4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_asinh(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    oarrm5n4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_acosh(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    oarrm5n4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_tanh(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    oarrm5n4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_cbrt(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    oarrm5n4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_sqrt(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_cosh(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_sinh(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_asin(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_acos(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_atan(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_tan(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_cos(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_sin(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_logb(oarrm5n4_t* arr, double base){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_log10(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_log(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_exp(oarrm5n4_t* arr){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);
    
    oarrm5n4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t oarrm5n4_pow(oarrm5n4_t* arr, double e){

    oarrm5n4_t res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    oarrm5n4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------
