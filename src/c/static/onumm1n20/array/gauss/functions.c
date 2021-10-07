

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_atanh(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n20_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_asinh(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n20_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_acosh(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n20_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_tanh(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n20_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_cbrt(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n20_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_sqrt(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_cosh(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_sinh(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_asin(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_acos(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_atan(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_tan(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_cos(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_sin(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_logb(feoarrm1n20_t* arr, double base){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_log10(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_log(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_exp(feoarrm1n20_t* arr){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n20_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n20_t feoarrm1n20_pow(feoarrm1n20_t* arr, double e){

    feoarrm1n20_t res = feoarrm1n20_init();

    res = feoarrm1n20_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n20_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_atanh_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_asinh_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_acosh_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_tanh_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_cbrt_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_sqrt_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_cosh_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_sinh_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_asin_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_acos_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_atan_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_tan_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_cos_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_sin_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_logb_to(feoarrm1n20_t* arr, double base, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_log10_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_log_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_exp_to(feoarrm1n20_t* arr, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n20_pow_to(feoarrm1n20_t* arr, double e, feoarrm1n20_t* res){

    uint64_t i;

    feoarrm1n20_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n20_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

