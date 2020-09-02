

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_atanh(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n8_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_asinh(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n8_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_acosh(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n8_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_tanh(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n8_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_cbrt(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n8_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_sqrt(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_cosh(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_sinh(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_asin(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_acos(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_atan(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_tan(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_cos(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_sin(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_logb(feoarrm1n8_t* arr, double base){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_log10(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_log(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_exp(feoarrm1n8_t* arr){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n8_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n8_t feoarrm1n8_pow(feoarrm1n8_t* arr, double e){

    feoarrm1n8_t res = feoarrm1n8_init();

    res = feoarrm1n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n8_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_atanh_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_asinh_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_acosh_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_tanh_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_cbrt_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_sqrt_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_cosh_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_sinh_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_asin_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_acos_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_atan_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_tan_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_cos_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_sin_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_logb_to(feoarrm1n8_t* arr, double base, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_log10_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_log_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_exp_to(feoarrm1n8_t* arr, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n8_pow_to(feoarrm1n8_t* arr, double e, feoarrm1n8_t* res){

    uint64_t i;

    feoarrm1n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n8_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

