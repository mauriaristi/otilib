

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_atanh(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_asinh(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_acosh(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_tanh(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_cbrt(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sqrt(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_cosh(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sinh(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_asin(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_acos(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_atan(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_tan(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_cos(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sin(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_logb(feoarrm5n3_t* arr, double base){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_log10(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_log(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_exp(feoarrm5n3_t* arr){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_pow(feoarrm5n3_t* arr, double e){

    feoarrm5n3_t res = feoarrm5n3_init();

    res = feoarrm5n3_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_atanh_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_asinh_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_acosh_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_tanh_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_cbrt_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sqrt_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_cosh_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sinh_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_asin_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_acos_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_atan_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_tan_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_cos_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sin_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_logb_to(feoarrm5n3_t* arr, double base, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_log10_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_log_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_exp_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_pow_to(feoarrm5n3_t* arr, double e, feoarrm5n3_t* res){

    uint64_t i;

    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n3_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

