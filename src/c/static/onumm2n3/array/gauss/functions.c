

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_atanh(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_asinh(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_acosh(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_tanh(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_cbrt(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_sqrt(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_cosh(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_sinh(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_asin(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_acos(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_atan(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_tan(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_cos(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_sin(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_logb(feoarrm2n3_t* arr, double base){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_log10(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_log(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_exp(feoarrm2n3_t* arr){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n3_t feoarrm2n3_pow(feoarrm2n3_t* arr, double e){

    feoarrm2n3_t res = feoarrm2n3_init();

    res = feoarrm2n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_atanh_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_asinh_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_acosh_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_tanh_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_cbrt_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_sqrt_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_cosh_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_sinh_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_asin_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_acos_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_atan_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_tan_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_cos_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_sin_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_logb_to(feoarrm2n3_t* arr, double base, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_log10_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_log_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_exp_to(feoarrm2n3_t* arr, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n3_pow_to(feoarrm2n3_t* arr, double e, feoarrm2n3_t* res){

    uint64_t i;

    feoarrm2n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n3_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

