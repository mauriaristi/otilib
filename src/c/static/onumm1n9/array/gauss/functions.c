

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_atanh(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n9_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_asinh(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n9_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_acosh(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n9_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_tanh(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n9_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_cbrt(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n9_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_sqrt(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_cosh(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_sinh(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_asin(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_acos(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_atan(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_tan(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_cos(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_sin(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_logb(feoarrm1n9_t* arr, double base){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_log10(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_log(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_exp(feoarrm1n9_t* arr){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n9_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n9_t feoarrm1n9_pow(feoarrm1n9_t* arr, double e){

    feoarrm1n9_t res = feoarrm1n9_init();

    res = feoarrm1n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n9_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_atanh_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_asinh_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_acosh_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_tanh_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_cbrt_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_sqrt_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_cosh_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_sinh_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_asin_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_acos_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_atan_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_tan_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_cos_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_sin_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_logb_to(feoarrm1n9_t* arr, double base, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_log10_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_log_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_exp_to(feoarrm1n9_t* arr, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n9_pow_to(feoarrm1n9_t* arr, double e, feoarrm1n9_t* res){

    uint64_t i;

    feoarrm1n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n9_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

