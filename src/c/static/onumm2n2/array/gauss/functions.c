

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_atanh(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_asinh(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_acosh(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_tanh(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_cbrt(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_sqrt(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_cosh(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_sinh(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_asin(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_acos(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_atan(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_tan(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_cos(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_sin(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_logb(feoarrm2n2_t* arr, double base){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_log10(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_log(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_exp(feoarrm2n2_t* arr){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n2_t feoarrm2n2_pow(feoarrm2n2_t* arr, double e){

    feoarrm2n2_t res = feoarrm2n2_init();

    res = feoarrm2n2_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_atanh_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_asinh_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_acosh_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_tanh_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_cbrt_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_sqrt_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_cosh_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_sinh_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_asin_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_acos_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_atan_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_tan_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_cos_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_sin_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_logb_to(feoarrm2n2_t* arr, double base, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_log10_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_log_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_exp_to(feoarrm2n2_t* arr, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n2_pow_to(feoarrm2n2_t* arr, double e, feoarrm2n2_t* res){

    uint64_t i;

    feoarrm2n2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

