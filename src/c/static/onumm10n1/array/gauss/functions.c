

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_atanh(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_asinh(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_acosh(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_tanh(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_cbrt(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_sqrt(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_cosh(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_sinh(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_asin(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_acos(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_atan(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_tan(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_cos(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_sin(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_logb(feoarrm10n1_t* arr, double base){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_log10(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_log(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_exp(feoarrm10n1_t* arr){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n1_t feoarrm10n1_pow(feoarrm10n1_t* arr, double e){

    feoarrm10n1_t res = feoarrm10n1_init();

    res = feoarrm10n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_atanh_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_asinh_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_acosh_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_tanh_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_cbrt_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_sqrt_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_cosh_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_sinh_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_asin_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_acos_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_atan_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_tan_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_cos_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_sin_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_logb_to(feoarrm10n1_t* arr, double base, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_log10_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_log_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_exp_to(feoarrm10n1_t* arr, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n1_pow_to(feoarrm10n1_t* arr, double e, feoarrm10n1_t* res){

    uint64_t i;

    feoarrm10n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

