

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_atanh(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_asinh(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_acosh(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_tanh(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_cbrt(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_sqrt(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_cosh(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_sinh(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_asin(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_acos(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_atan(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_tan(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_cos(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_sin(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_logb(feoarrm5n1_t* arr, double base){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_log10(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_log(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_exp(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_pow(feoarrm5n1_t* arr, double e){

    feoarrm5n1_t res = feoarrm5n1_init();

    res = feoarrm5n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_atanh_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_asinh_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_acosh_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_tanh_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_cbrt_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_sqrt_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_cosh_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_sinh_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_asin_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_acos_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_atan_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_tan_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_cos_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_sin_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_logb_to(feoarrm5n1_t* arr, double base, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_log10_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_log_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_exp_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_pow_to(feoarrm5n1_t* arr, double e, feoarrm5n1_t* res){

    uint64_t i;

    feoarrm5n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm5n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

