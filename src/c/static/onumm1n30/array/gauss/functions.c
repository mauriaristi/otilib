

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_atanh(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n30_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_asinh(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n30_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_acosh(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n30_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_tanh(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n30_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_cbrt(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n30_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_sqrt(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_cosh(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_sinh(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_asin(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_acos(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_atan(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_tan(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_cos(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_sin(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_logb(feoarrm1n30_t* arr, double base){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_log10(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_log(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_exp(feoarrm1n30_t* arr){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n30_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n30_t feoarrm1n30_pow(feoarrm1n30_t* arr, double e){

    feoarrm1n30_t res = feoarrm1n30_init();

    res = feoarrm1n30_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n30_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_atanh_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_asinh_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_acosh_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_tanh_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_cbrt_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_sqrt_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_cosh_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_sinh_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_asin_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_acos_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_atan_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_tan_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_cos_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_sin_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_logb_to(feoarrm1n30_t* arr, double base, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_log10_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_log_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_exp_to(feoarrm1n30_t* arr, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n30_pow_to(feoarrm1n30_t* arr, double e, feoarrm1n30_t* res){

    uint64_t i;

    feoarrm1n30_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n30_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

