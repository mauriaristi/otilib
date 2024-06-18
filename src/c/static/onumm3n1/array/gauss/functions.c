

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_atanh(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_asinh(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_acosh(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_tanh(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_cbrt(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_sqrt(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_cosh(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_sinh(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_asin(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_acos(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_atan(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_tan(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_cos(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_sin(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_logb(feoarrm3n1_t* arr, double base){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_log10(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_log(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_exp(feoarrm3n1_t* arr){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n1_t feoarrm3n1_pow(feoarrm3n1_t* arr, double e){

    feoarrm3n1_t res = feoarrm3n1_init();

    res = feoarrm3n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_atanh_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_asinh_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_acosh_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_tanh_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_cbrt_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_sqrt_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_cosh_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_sinh_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_asin_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_acos_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_atan_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_tan_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_cos_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_sin_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_logb_to(feoarrm3n1_t* arr, double base, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_log10_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_log_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_exp_to(feoarrm3n1_t* arr, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n1_pow_to(feoarrm3n1_t* arr, double e, feoarrm3n1_t* res){

    uint64_t i;

    feoarrm3n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

