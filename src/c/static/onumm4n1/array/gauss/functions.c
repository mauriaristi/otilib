

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_atanh(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_asinh(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_acosh(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_tanh(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_cbrt(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_sqrt(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_cosh(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_sinh(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_asin(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_acos(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_atan(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_tan(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_cos(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_sin(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_logb(feoarrm4n1_t* arr, double base){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_log10(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_log(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_exp(feoarrm4n1_t* arr){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n1_t feoarrm4n1_pow(feoarrm4n1_t* arr, double e){

    feoarrm4n1_t res = feoarrm4n1_init();

    res = feoarrm4n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_atanh_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_asinh_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_acosh_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_tanh_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_cbrt_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_sqrt_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_cosh_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_sinh_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_asin_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_acos_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_atan_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_tan_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_cos_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_sin_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_logb_to(feoarrm4n1_t* arr, double base, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_log10_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_log_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_exp_to(feoarrm4n1_t* arr, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n1_pow_to(feoarrm4n1_t* arr, double e, feoarrm4n1_t* res){

    uint64_t i;

    feoarrm4n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

