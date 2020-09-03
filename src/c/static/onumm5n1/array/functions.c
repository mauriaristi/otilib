

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_atanh(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);

    oarrm5n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_asinh(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);

    oarrm5n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_acosh(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);

    oarrm5n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_tanh(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);

    oarrm5n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_cbrt(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);

    oarrm5n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_sqrt(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_cosh(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_sinh(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_asin(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_acos(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_atan(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_tan(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_cos(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_sin(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_logb(oarrm5n1_t* arr, double base){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_log10(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_log(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_exp(oarrm5n1_t* arr){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);
    
    oarrm5n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n1_t oarrm5n1_pow(oarrm5n1_t* arr, double e){

    oarrm5n1_t res = oarrm5n1_init();

    res = oarrm5n1_zeros(arr->nrows, arr->ncols);

    oarrm5n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------
