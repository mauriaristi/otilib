

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_atanh(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_asinh(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_acosh(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_tanh(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_cbrt(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sqrt(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_cosh(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sinh(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_asin(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_acos(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_atan(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_tan(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_cos(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sin(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_logb(feoarrm9n2_t* arr, double base){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_log10(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_log(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_exp(feoarrm9n2_t* arr){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_pow(feoarrm9n2_t* arr, double e){

    feoarrm9n2_t res = feoarrm9n2_init();

    res = feoarrm9n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_atanh_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_asinh_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_acosh_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_tanh_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_cbrt_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sqrt_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_cosh_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sinh_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_asin_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_acos_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_atan_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_tan_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_cos_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sin_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_logb_to(feoarrm9n2_t* arr, double base, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_log10_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_log_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_exp_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_pow_to(feoarrm9n2_t* arr, double e, feoarrm9n2_t* res){

    uint64_t i;

    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

