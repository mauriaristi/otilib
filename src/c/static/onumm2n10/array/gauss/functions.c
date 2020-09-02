

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_atanh(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_asinh(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_acosh(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_tanh(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_cbrt(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sqrt(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_cosh(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sinh(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_asin(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_acos(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_atan(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_tan(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_cos(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sin(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_logb(feoarrm2n10_t* arr, double base){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_log10(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_log(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_exp(feoarrm2n10_t* arr){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n10_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_pow(feoarrm2n10_t* arr, double e){

    feoarrm2n10_t res = feoarrm2n10_init();

    res = feoarrm2n10_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_atanh_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_asinh_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_acosh_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_tanh_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_cbrt_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sqrt_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_cosh_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sinh_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_asin_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_acos_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_atan_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_tan_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_cos_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sin_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_logb_to(feoarrm2n10_t* arr, double base, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_log10_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_log_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_exp_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_pow_to(feoarrm2n10_t* arr, double e, feoarrm2n10_t* res){

    uint64_t i;

    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n10_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

