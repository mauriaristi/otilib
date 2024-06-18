

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_atanh(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_asinh(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_acosh(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_tanh(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_cbrt(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_sqrt(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_cosh(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_sinh(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_asin(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_acos(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_atan(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_tan(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_cos(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_sin(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_logb(feoarrm2n1_t* arr, double base){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_log10(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_log(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_exp(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_pow(feoarrm2n1_t* arr, double e){

    feoarrm2n1_t res = feoarrm2n1_init();

    res = feoarrm2n1_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_atanh_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_asinh_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_acosh_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_tanh_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_cbrt_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_sqrt_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_cosh_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_sinh_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_asin_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_acos_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_atan_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_tan_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_cos_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_sin_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_logb_to(feoarrm2n1_t* arr, double base, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_log10_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_log_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_exp_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_pow_to(feoarrm2n1_t* arr, double e, feoarrm2n1_t* res){

    uint64_t i;

    feoarrm2n1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

