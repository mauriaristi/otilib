

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_atanh(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_asinh(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_acosh(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_tanh(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_cbrt(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_sqrt(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_cosh(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_sinh(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_asin(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_acos(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_atan(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_tan(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_cos(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_sin(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_logb(feoarrm2n4_t* arr, double base){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_log10(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_log(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_exp(feoarrm2n4_t* arr){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n4_t feoarrm2n4_pow(feoarrm2n4_t* arr, double e){

    feoarrm2n4_t res = feoarrm2n4_init();

    res = feoarrm2n4_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_atanh_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_asinh_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_acosh_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_tanh_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_cbrt_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_sqrt_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_cosh_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_sinh_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_asin_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_acos_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_atan_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_tan_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_cos_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_sin_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_logb_to(feoarrm2n4_t* arr, double base, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_log10_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_log_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_exp_to(feoarrm2n4_t* arr, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n4_pow_to(feoarrm2n4_t* arr, double e, feoarrm2n4_t* res){

    uint64_t i;

    feoarrm2n4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n4_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

