
// ****************************************************************************************************
arrso_t arrso_erf(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_erf_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_atanh(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_atanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_asinh(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_asinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_acosh(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_acosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_tanh(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_tanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_cbrt(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_cbrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sqrt(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_sqrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_cosh(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_cosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sinh(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_sinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_asin(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_asin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_acos(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_acos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_atan(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_atan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_tan(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_tan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_cos(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_cos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sin(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_sin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_logb(arrso_t* arr, double base, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_logb_to(arr, base, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_log10(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_log10_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_log(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_log_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_exp(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_exp_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
arrso_t arrso_pow_soti(arrso_t* arr, sotinum_t* e, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_pow_soti_to(arr, e, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
arrso_t arrso_pow_arrso(arrso_t* arr, arrso_t* earr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_pow_arrso_to(arr, earr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t soti_pow_arrso(sotinum_t* a, arrso_t* earr, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(earr->nrows, earr->ncols, 0, 0, dhl);

    soti_pow_arrso_to(a, earr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_pow(arrso_t* arr, double e, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_pow_to(arr, e, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------








