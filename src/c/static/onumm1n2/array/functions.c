

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_atanh(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);

    oarrm1n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_asinh(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);

    oarrm1n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_acosh(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);

    oarrm1n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_tanh(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);

    oarrm1n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_cbrt(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);

    oarrm1n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_sqrt(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_cosh(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_sinh(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_asin(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_acos(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_atan(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_tan(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_cos(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_sin(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_logb(oarrm1n2_t* arr, double base){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_log10(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_log(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_exp(oarrm1n2_t* arr){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);
    
    oarrm1n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n2_t oarrm1n2_pow(oarrm1n2_t* arr, double e){

    oarrm1n2_t res = oarrm1n2_init();

    res = oarrm1n2_zeros(arr->nrows, arr->ncols);

    oarrm1n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

