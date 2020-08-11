


// ****************************************************************************************************
fedarr_t fedarr_atanh(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fedarr_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_asinh(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fedarr_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_acosh(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fedarr_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_tanh(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fedarr_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_cbrt(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fedarr_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sqrt(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_cosh(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sinh(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_asin(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_acos(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_atan(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_tan(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_cos(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sin(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_logb(fedarr_t* arr, double base){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_log10(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_log(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_exp(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fedarr_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_pow(fedarr_t* arr, double e){

    fedarr_t res = fedarr_init();

    res = fedarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fedarr_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------



















































// ****************************************************************************************************
void fedarr_atanh_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_asinh_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_acosh_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_tanh_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }



}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_cbrt_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sqrt_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_cosh_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sinh_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_asin_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_acos_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_atan_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_tan_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_cos_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sin_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_logb_to(fedarr_t* arr, double base, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_log10_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_log_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_exp_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_pow_to(fedarr_t* arr, double e, fedarr_t* res){

    uint64_t i;

    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        darr_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------




