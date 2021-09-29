




// ****************************************************************************************************
fearrsso_t fearrsso_atanh(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_atanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_asinh(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_asinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_acosh(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_acosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_tanh(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_tanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_cbrt(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_cbrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sqrt(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_sqrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_cosh(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_cosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sinh(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_sinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_asin(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_asin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_acos(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_acos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_atan(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_atan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_tan(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_tan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_cos(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_cos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sin(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_sin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_logb(fearrsso_t* arr, double base, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_logb_to(arr, base, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_log10(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_log10_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_log(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_log_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_exp(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_exp_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fearrsso_t fearrsso_pow(fearrsso_t* arr, double e, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    res = fearrsso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_pow_to(arr, e, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------



















































// ****************************************************************************************************
void fearrsso_atanh_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_atanh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_asinh_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_asinh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_acosh_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_acosh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_tanh_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_tanh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }



}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_cbrt_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_cbrt_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sqrt_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_sqrt_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_cosh_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_cosh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sinh_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_sinh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_asin_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_asin_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_acos_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_acos_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_atan_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_atan_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_tan_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_tan_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_cos_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_cos_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sin_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_sin_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_logb_to(fearrsso_t* arr, double base, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_logb_to(&arr->p_data[i], base, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_log10_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_log10_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_log_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_log_to(&arr->p_data[i], &res->p_data[i], dhl);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_exp_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_exp_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_pow_to(fearrsso_t* arr, double e, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrsso_pow_to(&arr->p_data[i], e, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


































