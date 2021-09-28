

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_atanh(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_asinh(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_acosh(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_tanh(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_cbrt(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_sqrt(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_cosh(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_sinh(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_asin(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_acos(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_atan(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_tan(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_cos(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_sin(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_logb(feoarrm2n5_t* arr, double base){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_log10(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_log(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_exp(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_pow(feoarrm2n5_t* arr, double e){

    feoarrm2n5_t res = feoarrm2n5_init();

    res = feoarrm2n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_atanh_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_asinh_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_acosh_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_tanh_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_cbrt_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_sqrt_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_cosh_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_sinh_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_asin_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_acos_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_atan_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_tan_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_cos_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_sin_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_logb_to(feoarrm2n5_t* arr, double base, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_log10_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_log_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_exp_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_pow_to(feoarrm2n5_t* arr, double e, feoarrm2n5_t* res){

    uint64_t i;

    feoarrm2n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n5_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

