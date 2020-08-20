

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_atanh(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_asinh(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_acosh(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_tanh(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_cbrt(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sqrt(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_cosh(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sinh(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_asin(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_acos(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_atan(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_tan(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_cos(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sin(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_logb(feoarrm3n3_t* arr, double base){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_log10(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_log(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_exp(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_pow(feoarrm3n3_t* arr, double e){

    feoarrm3n3_t res = feoarrm3n3_init();

    res = feoarrm3n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_atanh_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_asinh_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_acosh_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_tanh_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_cbrt_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sqrt_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_cosh_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sinh_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_asin_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_acos_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_atan_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_tan_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_cos_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sin_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_logb_to(feoarrm3n3_t* arr, double base, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_log10_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_log_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_exp_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_pow_to(feoarrm3n3_t* arr, double e, feoarrm3n3_t* res){

    uint64_t i;

    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n3_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

