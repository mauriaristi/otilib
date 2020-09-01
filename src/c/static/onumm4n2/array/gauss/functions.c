

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_atanh(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_asinh(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_acosh(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_tanh(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_cbrt(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sqrt(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_cosh(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sinh(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_asin(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_acos(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_atan(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_tan(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_cos(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sin(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_logb(feoarrm4n2_t* arr, double base){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_log10(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_log(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_exp(feoarrm4n2_t* arr){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_pow(feoarrm4n2_t* arr, double e){

    feoarrm4n2_t res = feoarrm4n2_init();

    res = feoarrm4n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_atanh_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_asinh_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_acosh_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_tanh_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_cbrt_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sqrt_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_cosh_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sinh_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_asin_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_acos_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_atan_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_tan_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_cos_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sin_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_logb_to(feoarrm4n2_t* arr, double base, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_log10_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_log_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_exp_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_pow_to(feoarrm4n2_t* arr, double e, feoarrm4n2_t* res){

    uint64_t i;

    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm4n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

