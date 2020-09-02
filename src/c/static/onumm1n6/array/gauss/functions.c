

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_atanh(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n6_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_asinh(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n6_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_acosh(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n6_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_tanh(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n6_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_cbrt(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n6_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_sqrt(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_cosh(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_sinh(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_asin(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_acos(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_atan(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_tan(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_cos(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_sin(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_logb(feoarrm1n6_t* arr, double base){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_log10(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_log(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_exp(feoarrm1n6_t* arr){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n6_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n6_t feoarrm1n6_pow(feoarrm1n6_t* arr, double e){

    feoarrm1n6_t res = feoarrm1n6_init();

    res = feoarrm1n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n6_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_atanh_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_asinh_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_acosh_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_tanh_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_cbrt_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_sqrt_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_cosh_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_sinh_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_asin_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_acos_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_atan_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_tan_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_cos_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_sin_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_logb_to(feoarrm1n6_t* arr, double base, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_log10_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_log_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_exp_to(feoarrm1n6_t* arr, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n6_pow_to(feoarrm1n6_t* arr, double e, feoarrm1n6_t* res){

    uint64_t i;

    feoarrm1n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n6_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

