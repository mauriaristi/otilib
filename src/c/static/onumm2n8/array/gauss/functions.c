

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_atanh(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n8_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_asinh(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n8_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_acosh(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n8_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_tanh(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n8_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_cbrt(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n8_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_sqrt(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_cosh(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_sinh(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_asin(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_acos(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_atan(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_tan(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_cos(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_sin(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_logb(feoarrm2n8_t* arr, double base){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_log10(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_log(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_exp(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_pow(feoarrm2n8_t* arr, double e){

    feoarrm2n8_t res = feoarrm2n8_init();

    res = feoarrm2n8_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n8_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_atanh_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_asinh_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_acosh_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_tanh_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_cbrt_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_sqrt_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_cosh_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_sinh_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_asin_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_acos_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_atan_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_tan_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_cos_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_sin_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_logb_to(feoarrm2n8_t* arr, double base, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_log10_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_log_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_exp_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_pow_to(feoarrm2n8_t* arr, double e, feoarrm2n8_t* res){

    uint64_t i;

    feoarrm2n8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n8_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

