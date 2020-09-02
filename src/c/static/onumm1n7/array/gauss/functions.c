

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_atanh(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n7_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_asinh(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n7_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_acosh(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n7_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_tanh(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n7_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_cbrt(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n7_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_sqrt(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_cosh(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_sinh(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_asin(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_acos(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_atan(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_tan(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_cos(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_sin(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_logb(feoarrm1n7_t* arr, double base){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_log10(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_log(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_exp(feoarrm1n7_t* arr){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n7_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n7_t feoarrm1n7_pow(feoarrm1n7_t* arr, double e){

    feoarrm1n7_t res = feoarrm1n7_init();

    res = feoarrm1n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm1n7_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_atanh_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_asinh_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_acosh_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_tanh_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_cbrt_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_sqrt_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_cosh_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_sinh_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_asin_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_acos_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_atan_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_tan_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_cos_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_sin_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_logb_to(feoarrm1n7_t* arr, double base, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_log10_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_log_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_exp_to(feoarrm1n7_t* arr, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n7_pow_to(feoarrm1n7_t* arr, double e, feoarrm1n7_t* res){

    uint64_t i;

    feoarrm1n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm1n7_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

