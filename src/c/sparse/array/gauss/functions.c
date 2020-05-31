




// ****************************************************************************************************
fearrso_t fearrso_atanh(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrso_atanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_asinh(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrso_asinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_acosh(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrso_acosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_tanh(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrso_tanh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_cbrt(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrso_cbrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sqrt(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_sqrt_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_cosh(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_cosh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sinh(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_sinh_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_asin(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_asin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_acos(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_acos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_atan(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_atan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_tan(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_tan_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_cos(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_cos_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sin(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_sin_to(arr, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_logb(fearrso_t* arr, double base, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_logb_to(arr, base, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_log10(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_log10_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_log(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_log_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_exp(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrso_exp_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fearrso_t fearrso_pow(fearrso_t* arr, double e, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    res = fearrso_zeros_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrso_pow_to(arr, e, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------



















































// ****************************************************************************************************
void fearrso_atanh_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_atanh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_asinh_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_asinh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_acosh_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_acosh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_tanh_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_tanh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }



}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_cbrt_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_cbrt_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sqrt_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_sqrt_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_cosh_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_cosh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sinh_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_sinh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_asin_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_asin_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_acos_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_acos_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_atan_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_atan_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_tan_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_tan_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_cos_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_cos_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sin_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_sin_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_logb_to(fearrso_t* arr, double base, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_logb_to(&arr->p_data[i], base, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_log10_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_log10_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_log_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_log_to(&arr->p_data[i], &res->p_data[i], dhl);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_exp_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_exp_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrso_pow_to(fearrso_t* arr, double e, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        arrso_pow_to(&arr->p_data[i], e, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


































