

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_atanh(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_asinh(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_acosh(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_tanh(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_cbrt(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sqrt(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_cosh(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sinh(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_asin(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_acos(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_atan(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_tan(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_cos(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sin(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_logb(feoarrm0n0_t* arr, double base){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_log10(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_log(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_exp(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_pow(feoarrm0n0_t* arr, double e){

    feoarrm0n0_t res = feoarrm0n0_init();

    res = feoarrm0n0_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_atanh_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_asinh_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_acosh_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_tanh_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_cbrt_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sqrt_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_cosh_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sinh_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_asin_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_acos_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_atan_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_tan_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_cos_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sin_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_logb_to(feoarrm0n0_t* arr, double base, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_log10_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_log_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_exp_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_pow_to(feoarrm0n0_t* arr, double e, feoarrm0n0_t* res){

    uint64_t i;

    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm0n0_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

