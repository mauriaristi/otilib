

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_atanh(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_asinh(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_acosh(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_tanh(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_cbrt(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_sqrt(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_cosh(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_sinh(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_asin(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_acos(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_atan(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_tan(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_cos(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_sin(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_logb(feoarrm5n2_t* arr, double base){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_log10(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_log(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_exp(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_pow(feoarrm5n2_t* arr, double e){

    feoarrm5n2_t res = feoarrm5n2_init();

    res = feoarrm5n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_atanh_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_asinh_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_acosh_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_tanh_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_cbrt_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_sqrt_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_cosh_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_sinh_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_asin_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_acos_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_atan_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_tan_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_cos_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_sin_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_logb_to(feoarrm5n2_t* arr, double base, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_log10_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_log_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_exp_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_pow_to(feoarrm5n2_t* arr, double e, feoarrm5n2_t* res){

    uint64_t i;

    feoarrm5n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

