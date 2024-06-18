

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_atanh(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_asinh(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_acosh(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_tanh(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_cbrt(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_sqrt(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_cosh(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_sinh(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_asin(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_acos(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_atan(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_tan(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_cos(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_sin(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_logb(feoarrm1n3_t* arr, double base){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_log10(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_log(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_exp(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_pow(feoarrm1n3_t* arr, double e){

    feoarrm1n3_t res = feoarrm1n3_init();

    res = feoarrm1n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_atanh_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_asinh_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_acosh_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_tanh_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_cbrt_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_sqrt_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_cosh_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_sinh_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_asin_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_acos_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_atan_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_tan_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_cos_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_sin_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_logb_to(feoarrm1n3_t* arr, double base, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_log10_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_log_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_exp_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_pow_to(feoarrm1n3_t* arr, double e, feoarrm1n3_t* res){

    uint64_t i;

    feoarrm1n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n3_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

