

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_atanh(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_asinh(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_acosh(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_tanh(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_cbrt(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_sqrt(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_cosh(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_sinh(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_asin(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_acos(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_atan(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_tan(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_cos(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_sin(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_logb(feoarrm3n5_t* arr, double base){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_log10(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_log(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_exp(feoarrm3n5_t* arr){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n5_t feoarrm3n5_pow(feoarrm3n5_t* arr, double e){

    feoarrm3n5_t res = feoarrm3n5_init();

    res = feoarrm3n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_atanh_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_asinh_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_acosh_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_tanh_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_cbrt_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_sqrt_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_cosh_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_sinh_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_asin_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_acos_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_atan_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_tan_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_cos_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_sin_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_logb_to(feoarrm3n5_t* arr, double base, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_log10_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_log_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_exp_to(feoarrm3n5_t* arr, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n5_pow_to(feoarrm3n5_t* arr, double e, feoarrm3n5_t* res){

    uint64_t i;

    feoarrm3n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n5_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

