

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_atanh(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_asinh(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_acosh(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_tanh(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_cbrt(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_sqrt(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_cosh(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_sinh(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_asin(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_acos(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_atan(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_tan(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_cos(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_sin(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_logb(feoarrm3n2_t* arr, double base){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_log10(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_log(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_exp(feoarrm3n2_t* arr){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n2_t feoarrm3n2_pow(feoarrm3n2_t* arr, double e){

    feoarrm3n2_t res = feoarrm3n2_init();

    res = feoarrm3n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_atanh_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_asinh_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_acosh_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_tanh_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_cbrt_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_sqrt_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_cosh_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_sinh_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_asin_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_acos_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_atan_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_tan_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_cos_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_sin_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_logb_to(feoarrm3n2_t* arr, double base, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_log10_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_log_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_exp_to(feoarrm3n2_t* arr, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n2_pow_to(feoarrm3n2_t* arr, double e, feoarrm3n2_t* res){

    uint64_t i;

    feoarrm3n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm3n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

