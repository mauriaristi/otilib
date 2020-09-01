

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_atanh(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_asinh(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_acosh(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_tanh(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_cbrt(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_sqrt(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_cosh(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_sinh(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_asin(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_acos(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_atan(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_tan(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_cos(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_sin(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_logb(feoarrm5n5_t* arr, double base){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_log10(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_log(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_exp(feoarrm5n5_t* arr){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n5_t feoarrm5n5_pow(feoarrm5n5_t* arr, double e){

    feoarrm5n5_t res = feoarrm5n5_init();

    res = feoarrm5n5_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_atanh_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_asinh_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_acosh_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_tanh_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_cbrt_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_sqrt_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_cosh_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_sinh_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_asin_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_acos_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_atan_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_tan_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_cos_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_sin_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_logb_to(feoarrm5n5_t* arr, double base, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_log10_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_log_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_exp_to(feoarrm5n5_t* arr, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n5_pow_to(feoarrm5n5_t* arr, double e, feoarrm5n5_t* res){

    uint64_t i;

    feoarrm5n5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n5_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

