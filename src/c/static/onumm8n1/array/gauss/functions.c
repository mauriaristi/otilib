

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_atanh(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_asinh(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_acosh(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_tanh(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_cbrt(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_sqrt(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_cosh(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_sinh(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_asin(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_acos(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_atan(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_tan(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_cos(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_sin(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_logb(feoarrm8n1_t* arr, double base){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_log10(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_log(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_exp(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_pow(feoarrm8n1_t* arr, double e){

    feoarrm8n1_t res = feoarrm8n1_init();

    res = feoarrm8n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm8n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_atanh_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_asinh_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_acosh_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_tanh_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_cbrt_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_sqrt_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_cosh_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_sinh_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_asin_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_acos_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_atan_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_tan_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_cos_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_sin_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_logb_to(feoarrm8n1_t* arr, double base, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_log10_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_log_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_exp_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_pow_to(feoarrm8n1_t* arr, double e, feoarrm8n1_t* res){

    uint64_t i;

    feoarrm8n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm8n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

