

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_atanh(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_asinh(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_acosh(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_tanh(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_cbrt(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_sqrt(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_cosh(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_sinh(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_asin(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_acos(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_atan(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_tan(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_cos(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_sin(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_logb(feoarrm7n1_t* arr, double base){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_log10(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_log(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_exp(feoarrm7n1_t* arr){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm7n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n1_t feoarrm7n1_pow(feoarrm7n1_t* arr, double e){

    feoarrm7n1_t res = feoarrm7n1_init();

    res = feoarrm7n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_atanh_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_asinh_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_acosh_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_tanh_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_cbrt_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_sqrt_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_cosh_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_sinh_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_asin_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_acos_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_atan_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_tan_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_cos_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_sin_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_logb_to(feoarrm7n1_t* arr, double base, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_log10_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_log_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_exp_to(feoarrm7n1_t* arr, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n1_pow_to(feoarrm7n1_t* arr, double e, feoarrm7n1_t* res){

    uint64_t i;

    feoarrm7n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm7n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

