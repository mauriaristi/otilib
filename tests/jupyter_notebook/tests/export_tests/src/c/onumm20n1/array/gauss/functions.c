

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_atanh(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm20n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_asinh(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm20n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_acosh(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm20n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_tanh(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm20n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_cbrt(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm20n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_sqrt(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_cosh(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_sinh(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_asin(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_acos(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_atan(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_tan(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_cos(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_sin(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_logb(feoarrm20n1_t* arr, double base){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_log10(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_log(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_exp(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_pow(feoarrm20n1_t* arr, double e){

    feoarrm20n1_t res = feoarrm20n1_init();

    res = feoarrm20n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm20n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_atanh_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_asinh_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_acosh_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_tanh_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_cbrt_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_sqrt_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_cosh_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_sinh_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_asin_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_acos_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_atan_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_tan_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_cos_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_sin_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_logb_to(feoarrm20n1_t* arr, double base, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_log10_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_log_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_exp_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_pow_to(feoarrm20n1_t* arr, double e, feoarrm20n1_t* res){

    uint64_t i;

    feoarrm20n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm20n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

