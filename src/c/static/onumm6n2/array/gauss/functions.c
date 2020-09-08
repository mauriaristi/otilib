

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_atanh(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_asinh(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_acosh(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_tanh(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_cbrt(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_sqrt(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_cosh(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_sinh(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_asin(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_acos(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_atan(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_tan(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_cos(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_sin(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_logb(feoarrm6n2_t* arr, double base){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_log10(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_log(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_exp(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_pow(feoarrm6n2_t* arr, double e){

    feoarrm6n2_t res = feoarrm6n2_init();

    res = feoarrm6n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_atanh_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_asinh_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_acosh_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_tanh_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_cbrt_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_sqrt_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_cosh_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_sinh_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_asin_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_acos_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_atan_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_tan_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_cos_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_sin_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_logb_to(feoarrm6n2_t* arr, double base, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_log10_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_log_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_exp_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_pow_to(feoarrm6n2_t* arr, double e, feoarrm6n2_t* res){

    uint64_t i;

    feoarrm6n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

