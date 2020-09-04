

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_atanh(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_asinh(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_acosh(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_tanh(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_cbrt(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_sqrt(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_cosh(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_sinh(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_asin(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_acos(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_atan(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_tan(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_cos(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_sin(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_logb(feoarrm9n1_t* arr, double base){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_log10(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_log(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_exp(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_pow(feoarrm9n1_t* arr, double e){

    feoarrm9n1_t res = feoarrm9n1_init();

    res = feoarrm9n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_atanh_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_asinh_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_acosh_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_tanh_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_cbrt_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_sqrt_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_cosh_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_sinh_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_asin_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_acos_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_atan_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_tan_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_cos_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_sin_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_logb_to(feoarrm9n1_t* arr, double base, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_log10_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_log_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_exp_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_pow_to(feoarrm9n1_t* arr, double e, feoarrm9n1_t* res){

    uint64_t i;

    feoarrm9n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm9n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

