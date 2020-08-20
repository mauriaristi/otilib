

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_atanh(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n10_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_asinh(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n10_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_acosh(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n10_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_tanh(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n10_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_cbrt(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n10_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_sqrt(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_cosh(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_sinh(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_asin(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_acos(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_atan(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_tan(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_cos(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_sin(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_logb(feoarrm1n10_t* arr, double base){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_log10(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_log(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_exp(feoarrm1n10_t* arr){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n10_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n10_t feoarrm1n10_pow(feoarrm1n10_t* arr, double e){

    feoarrm1n10_t res = feoarrm1n10_init();

    res = feoarrm1n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n10_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_atanh_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_asinh_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_acosh_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_tanh_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_cbrt_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_sqrt_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_cosh_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_sinh_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_asin_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_acos_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_atan_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_tan_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_cos_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_sin_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_logb_to(feoarrm1n10_t* arr, double base, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_log10_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_log_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_exp_to(feoarrm1n10_t* arr, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n10_pow_to(feoarrm1n10_t* arr, double e, feoarrm1n10_t* res){

    uint64_t i;

    feoarrm1n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n10_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

