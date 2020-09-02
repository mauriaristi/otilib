

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_atanh(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n9_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_asinh(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n9_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_acosh(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n9_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_tanh(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n9_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_cbrt(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n9_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_sqrt(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_cosh(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_sinh(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_asin(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_acos(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_atan(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_tan(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_cos(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_sin(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_logb(feoarrm2n9_t* arr, double base){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_log10(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_log(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_exp(feoarrm2n9_t* arr){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n9_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n9_t feoarrm2n9_pow(feoarrm2n9_t* arr, double e){

    feoarrm2n9_t res = feoarrm2n9_init();

    res = feoarrm2n9_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n9_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_atanh_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_asinh_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_acosh_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_tanh_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_cbrt_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_sqrt_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_cosh_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_sinh_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_asin_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_acos_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_atan_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_tan_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_cos_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_sin_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_logb_to(feoarrm2n9_t* arr, double base, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_log10_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_log_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_exp_to(feoarrm2n9_t* arr, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n9_pow_to(feoarrm2n9_t* arr, double e, feoarrm2n9_t* res){

    uint64_t i;

    feoarrm2n9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n9_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

