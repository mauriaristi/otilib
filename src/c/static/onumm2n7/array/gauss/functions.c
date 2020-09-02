

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_atanh(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n7_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_asinh(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n7_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_acosh(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n7_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_tanh(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n7_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_cbrt(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n7_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_sqrt(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_cosh(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_sinh(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_asin(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_acos(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_atan(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_tan(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_cos(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_sin(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_logb(feoarrm2n7_t* arr, double base){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_log10(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_log(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_exp(feoarrm2n7_t* arr){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n7_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n7_t feoarrm2n7_pow(feoarrm2n7_t* arr, double e){

    feoarrm2n7_t res = feoarrm2n7_init();

    res = feoarrm2n7_zeros(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n7_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_atanh_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_asinh_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_acosh_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_tanh_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_cbrt_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_sqrt_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_cosh_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_sinh_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_asin_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_acos_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_atan_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_tan_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_cos_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_sin_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_logb_to(feoarrm2n7_t* arr, double base, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_log10_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_log_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_exp_to(feoarrm2n7_t* arr, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n7_pow_to(feoarrm2n7_t* arr, double e, feoarrm2n7_t* res){

    uint64_t i;

    feoarrm2n7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        oarrm2n7_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

