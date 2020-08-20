

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_atanh(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_asinh(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_acosh(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_tanh(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_cbrt(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_sqrt(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_cosh(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_sinh(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_asin(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_acos(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_atan(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_tan(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_cos(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_sin(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_logb(feoarrm1n5_t* arr, double base){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_log10(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_log(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_exp(feoarrm1n5_t* arr){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n5_t feoarrm1n5_pow(feoarrm1n5_t* arr, double e){

    feoarrm1n5_t res = feoarrm1n5_init();

    res = feoarrm1n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_atanh_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_asinh_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_acosh_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_tanh_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_cbrt_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_sqrt_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_cosh_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_sinh_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_asin_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_acos_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_atan_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_tan_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_cos_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_sin_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_logb_to(feoarrm1n5_t* arr, double base, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_log10_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_log_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_exp_to(feoarrm1n5_t* arr, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n5_pow_to(feoarrm1n5_t* arr, double e, feoarrm1n5_t* res){

    uint64_t i;

    feoarrm1n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n5_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

