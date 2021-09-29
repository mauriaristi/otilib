


// ****************************************************************************************************
arrsso_t arrsso_atanh(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrsso_atanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_asinh(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrsso_asinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_acosh(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrsso_acosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_tanh(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrsso_tanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_cbrt(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrsso_cbrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sqrt(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_sqrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_cosh(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_cosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sinh(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_sinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_asin(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_asin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_acos(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_acos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_atan(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_atan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_tan(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_tan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_cos(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_cos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sin(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_sin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_logb(arrsso_t* arr, double base, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_logb_to(arr, base, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_log10(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_log10_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_log(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_log_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_exp(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrsso_exp_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
arrsso_t arrsso_pow(arrsso_t* arr, double e, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrsso_pow_to(arr, e, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------








