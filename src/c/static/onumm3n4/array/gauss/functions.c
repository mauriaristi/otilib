

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_atanh(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_asinh(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_acosh(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_tanh(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_cbrt(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_sqrt(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_cosh(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_sinh(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_asin(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_acos(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_atan(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_tan(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_cos(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_sin(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_logb(feoarrm3n4_t* arr, double base){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_log10(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_log(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_exp(feoarrm3n4_t* arr){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n4_t feoarrm3n4_pow(feoarrm3n4_t* arr, double e){

    feoarrm3n4_t res = feoarrm3n4_init();

    res = feoarrm3n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_atanh_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_asinh_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_acosh_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_tanh_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_cbrt_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_sqrt_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_cosh_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_sinh_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_asin_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_acos_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_atan_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_tan_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_cos_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_sin_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_logb_to(feoarrm3n4_t* arr, double base, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_log10_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_log_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_exp_to(feoarrm3n4_t* arr, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n4_pow_to(feoarrm3n4_t* arr, double e, feoarrm3n4_t* res){

    uint64_t i;

    feoarrm3n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n4_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

