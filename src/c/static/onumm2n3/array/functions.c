

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_atanh(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);

    oarrm2n3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_asinh(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);

    oarrm2n3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_acosh(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);

    oarrm2n3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_tanh(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);

    oarrm2n3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_cbrt(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);

    oarrm2n3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_sqrt(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_cosh(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_sinh(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_asin(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_acos(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_atan(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_tan(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_cos(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_sin(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_logb(oarrm2n3_t* arr, double base){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_log10(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_log(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_exp(oarrm2n3_t* arr){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);
    
    oarrm2n3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n3_t oarrm2n3_pow(oarrm2n3_t* arr, double e){

    oarrm2n3_t res = oarrm2n3_init();

    res = oarrm2n3_zeros(arr->nrows, arr->ncols);

    oarrm2n3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

