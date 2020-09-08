

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_atanh(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_asinh(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_acosh(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_tanh(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_cbrt(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_sqrt(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_cosh(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_sinh(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_asin(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_acos(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_atan(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_tan(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_cos(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_sin(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_logb(feoarrm8n2_t* arr, double base){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_log10(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_log(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_exp(feoarrm8n2_t* arr){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n2_t feoarrm8n2_pow(feoarrm8n2_t* arr, double e){

    feoarrm8n2_t res = feoarrm8n2_init();

    res = feoarrm8n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_atanh_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_asinh_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_acosh_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_tanh_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_cbrt_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_sqrt_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_cosh_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_sinh_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_asin_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_acos_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_atan_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_tan_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_cos_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_sin_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_logb_to(feoarrm8n2_t* arr, double base, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_log10_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_log_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_exp_to(feoarrm8n2_t* arr, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_pow_to(feoarrm8n2_t* arr, double e, feoarrm8n2_t* res){

    uint64_t i;

    feoarrm8n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

