

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_atanh(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_asinh(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_acosh(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_tanh(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_cbrt(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sqrt(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_cosh(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sinh(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_asin(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_acos(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_atan(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_tan(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_cos(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sin(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_logb(feoarrm5n4_t* arr, double base){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_log10(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_log(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_exp(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_pow(feoarrm5n4_t* arr, double e){

    feoarrm5n4_t res = feoarrm5n4_init();

    res = feoarrm5n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_atanh_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_asinh_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_acosh_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_tanh_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_cbrt_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sqrt_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_cosh_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sinh_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_asin_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_acos_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_atan_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_tan_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_cos_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sin_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_logb_to(feoarrm5n4_t* arr, double base, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_log10_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_log_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_exp_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_pow_to(feoarrm5n4_t* arr, double e, feoarrm5n4_t* res){

    uint64_t i;

    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n4_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

