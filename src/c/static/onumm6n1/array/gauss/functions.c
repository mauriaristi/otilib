

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_atanh(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_asinh(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_acosh(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_tanh(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_cbrt(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_sqrt(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_cosh(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_sinh(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_asin(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_acos(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_atan(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_tan(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_cos(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_sin(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_logb(feoarrm6n1_t* arr, double base){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_log10(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_log(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_exp(feoarrm6n1_t* arr){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n1_t feoarrm6n1_pow(feoarrm6n1_t* arr, double e){

    feoarrm6n1_t res = feoarrm6n1_init();

    res = feoarrm6n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm6n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_atanh_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_asinh_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_acosh_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_tanh_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_cbrt_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_sqrt_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_cosh_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_sinh_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_asin_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_acos_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_atan_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_tan_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_cos_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_sin_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_logb_to(feoarrm6n1_t* arr, double base, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_log10_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_log_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_exp_to(feoarrm6n1_t* arr, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n1_pow_to(feoarrm6n1_t* arr, double e, feoarrm6n1_t* res){

    uint64_t i;

    feoarrm6n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm6n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

