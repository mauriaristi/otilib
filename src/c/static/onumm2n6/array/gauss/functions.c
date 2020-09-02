

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_atanh(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n6_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_asinh(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n6_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_acosh(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n6_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_tanh(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n6_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_cbrt(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n6_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_sqrt(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_cosh(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_sinh(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_asin(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_acos(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_atan(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_tan(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_cos(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_sin(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_logb(feoarrm2n6_t* arr, double base){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_log10(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_log(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_exp(feoarrm2n6_t* arr){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n6_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n6_t feoarrm2n6_pow(feoarrm2n6_t* arr, double e){

    feoarrm2n6_t res = feoarrm2n6_init();

    res = feoarrm2n6_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n6_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_atanh_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_asinh_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_acosh_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_tanh_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_cbrt_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_sqrt_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_cosh_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_sinh_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_asin_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_acos_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_atan_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_tan_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_cos_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_sin_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_logb_to(feoarrm2n6_t* arr, double base, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_log10_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_log_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_exp_to(feoarrm2n6_t* arr, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n6_pow_to(feoarrm2n6_t* arr, double e, feoarrm2n6_t* res){

    uint64_t i;

    feoarrm2n6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n6_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

