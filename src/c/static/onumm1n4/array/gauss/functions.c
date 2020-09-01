

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_atanh(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_asinh(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_acosh(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_tanh(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_cbrt(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_sqrt(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_cosh(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_sinh(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_asin(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_acos(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_atan(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_tan(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_cos(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_sin(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_logb(feoarrm1n4_t* arr, double base){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_log10(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_log(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_exp(feoarrm1n4_t* arr){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n4_t feoarrm1n4_pow(feoarrm1n4_t* arr, double e){

    feoarrm1n4_t res = feoarrm1n4_init();

    res = feoarrm1n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_atanh_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_asinh_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_acosh_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_tanh_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_cbrt_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_sqrt_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_cosh_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_sinh_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_asin_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_acos_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_atan_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_tan_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_cos_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_sin_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_logb_to(feoarrm1n4_t* arr, double base, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_log10_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_log_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_exp_to(feoarrm1n4_t* arr, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n4_pow_to(feoarrm1n4_t* arr, double e, feoarrm1n4_t* res){

    uint64_t i;

    feoarrm1n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n4_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

