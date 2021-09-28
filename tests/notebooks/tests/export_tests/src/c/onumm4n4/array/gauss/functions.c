

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_atanh(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_asinh(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_acosh(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_tanh(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_cbrt(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sqrt(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_cosh(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sinh(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_asin(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_acos(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_atan(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_tan(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_cos(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sin(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_logb(feoarrm4n4_t* arr, double base){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_log10(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_log(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_exp(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_pow(feoarrm4n4_t* arr, double e){

    feoarrm4n4_t res = feoarrm4n4_init();

    res = feoarrm4n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_atanh_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_asinh_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_acosh_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_tanh_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_cbrt_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sqrt_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_cosh_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sinh_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_asin_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_acos_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_atan_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_tan_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_cos_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sin_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_logb_to(feoarrm4n4_t* arr, double base, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_log10_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_log_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_exp_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_pow_to(feoarrm4n4_t* arr, double e, feoarrm4n4_t* res){

    uint64_t i;

    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n4_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

