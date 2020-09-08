

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_atanh(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_asinh(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_acosh(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_tanh(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_cbrt(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sqrt(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_cosh(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sinh(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_asin(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_acos(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_atan(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_tan(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_cos(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sin(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_logb(feoarrm7n2_t* arr, double base){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_log10(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_log(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_exp(feoarrm7n2_t* arr){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_pow(feoarrm7n2_t* arr, double e){

    feoarrm7n2_t res = feoarrm7n2_init();

    res = feoarrm7n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_atanh_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_asinh_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_acosh_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_tanh_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_cbrt_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sqrt_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_cosh_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sinh_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_asin_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_acos_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_atan_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_tan_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_cos_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sin_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_logb_to(feoarrm7n2_t* arr, double base, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_log10_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_log_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_exp_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_pow_to(feoarrm7n2_t* arr, double e, feoarrm7n2_t* res){

    uint64_t i;

    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

