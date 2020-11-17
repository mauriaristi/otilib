


// ****************************************************************************************************
fecarr_t fecarr_atanh(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fecarr_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_asinh(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fecarr_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_acosh(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fecarr_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_tanh(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fecarr_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_cbrt(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fecarr_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sqrt(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_cosh(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sinh(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_asin(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_acos(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_atan(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_tan(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_cos(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sin(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_logb(fecarr_t* arr, double base){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_log10(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_log(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_exp(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);
    
    fecarr_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_pow(fecarr_t* arr, double e){

    fecarr_t res = fecarr_init();

    res = fecarr_zeros(arr->nrows, arr->ncols, arr->nip);

    fecarr_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------



















































// ****************************************************************************************************
void fecarr_atanh_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_asinh_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_acosh_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_tanh_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }



}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_cbrt_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sqrt_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_cosh_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sinh_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_asin_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_acos_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_atan_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_tan_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_cos_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sin_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_logb_to(fecarr_t* arr, double base, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_log10_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_log_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_exp_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_pow_to(fecarr_t* arr, double e, fecarr_t* res){

    uint64_t i;

    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        carr_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------




