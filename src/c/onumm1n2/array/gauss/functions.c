

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_atanh(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_asinh(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_acosh(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_tanh(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_cbrt(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_sqrt(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_cosh(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_sinh(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_asin(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_acos(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_atan(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_tan(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_cos(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_sin(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_logb(feoarrm1n2_t* arr, double base){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_log10(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_log(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_exp(feoarrm1n2_t* arr){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n2_t feoarrm1n2_pow(feoarrm1n2_t* arr, double e){

    feoarrm1n2_t res = feoarrm1n2_init();

    res = feoarrm1n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_atanh_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_asinh_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_acosh_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_tanh_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_cbrt_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_sqrt_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_cosh_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_sinh_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_asin_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_acos_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_atan_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_tan_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_cos_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_sin_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_logb_to(feoarrm1n2_t* arr, double base, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_log10_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_log_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_exp_to(feoarrm1n2_t* arr, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n2_pow_to(feoarrm1n2_t* arr, double e, feoarrm1n2_t* res){

    uint64_t i;

    feoarrm1n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

