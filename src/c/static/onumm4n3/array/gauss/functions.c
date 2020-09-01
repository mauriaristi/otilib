

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_atanh(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_asinh(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_acosh(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_tanh(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_cbrt(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_sqrt(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_cosh(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_sinh(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_asin(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_acos(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_atan(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_tan(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_cos(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_sin(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_logb(feoarrm4n3_t* arr, double base){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_log10(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_log(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_exp(feoarrm4n3_t* arr){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n3_t feoarrm4n3_pow(feoarrm4n3_t* arr, double e){

    feoarrm4n3_t res = feoarrm4n3_init();

    res = feoarrm4n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_atanh_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_asinh_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_acosh_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_tanh_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_cbrt_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_sqrt_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_cosh_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_sinh_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_asin_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_acos_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_atan_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_tan_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_cos_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_sin_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_logb_to(feoarrm4n3_t* arr, double base, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_log10_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_log_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_exp_to(feoarrm4n3_t* arr, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n3_pow_to(feoarrm4n3_t* arr, double e, feoarrm4n3_t* res){

    uint64_t i;

    feoarrm4n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n3_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

