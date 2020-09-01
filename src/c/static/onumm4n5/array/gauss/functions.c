

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_atanh(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_asinh(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_acosh(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_tanh(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_cbrt(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_sqrt(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_cosh(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_sinh(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_asin(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_acos(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_atan(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_tan(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_cos(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_sin(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_logb(feoarrm4n5_t* arr, double base){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_log10(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_log(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_exp(feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_pow(feoarrm4n5_t* arr, double e){

    feoarrm4n5_t res = feoarrm4n5_init();

    res = feoarrm4n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_atanh_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_asinh_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_acosh_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_tanh_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_cbrt_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_sqrt_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_cosh_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_sinh_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_asin_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_acos_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_atan_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_tan_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_cos_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_sin_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_logb_to(feoarrm4n5_t* arr, double base, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_log10_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_log_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_exp_to(feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_pow_to(feoarrm4n5_t* arr, double e, feoarrm4n5_t* res){

    uint64_t i;

    feoarrm4n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n5_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

