

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_atanh(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_asinh(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_acosh(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_tanh(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_cbrt(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_sqrt(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_cosh(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_sinh(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_asin(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_acos(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_atan(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_tan(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_cos(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_sin(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_logb(feoarrm1n1_t* arr, double base){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_log10(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_log(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_exp(feoarrm1n1_t* arr){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n1_t feoarrm1n1_pow(feoarrm1n1_t* arr, double e){

    feoarrm1n1_t res = feoarrm1n1_init();

    res = feoarrm1n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_atanh_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_asinh_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_acosh_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_tanh_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_cbrt_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_sqrt_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_cosh_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_sinh_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_asin_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_acos_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_atan_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_tan_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_cos_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_sin_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_logb_to(feoarrm1n1_t* arr, double base, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_log10_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_log_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_exp_to(feoarrm1n1_t* arr, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n1_pow_to(feoarrm1n1_t* arr, double e, feoarrm1n1_t* res){

    uint64_t i;

    feoarrm1n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

