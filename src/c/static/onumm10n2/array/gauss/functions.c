

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_atanh(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_asinh(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_acosh(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_tanh(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_cbrt(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_sqrt(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_cosh(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_sinh(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_asin(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_acos(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_atan(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_tan(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_cos(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_sin(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_logb(feoarrm10n2_t* arr, double base){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_log10(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_log(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_exp(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_pow(feoarrm10n2_t* arr, double e){

    feoarrm10n2_t res = feoarrm10n2_init();

    res = feoarrm10n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm10n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_atanh_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_asinh_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_acosh_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_tanh_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_cbrt_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_sqrt_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_cosh_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_sinh_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_asin_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_acos_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_atan_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_tan_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_cos_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_sin_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_logb_to(feoarrm10n2_t* arr, double base, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_log10_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_log_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_exp_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_pow_to(feoarrm10n2_t* arr, double e, feoarrm10n2_t* res){

    uint64_t i;

    feoarrm10n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm10n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

