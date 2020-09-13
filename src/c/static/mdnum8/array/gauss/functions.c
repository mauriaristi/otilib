

// ****************************************************************************************************
femdarr8_t femdarr8_atanh(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr8_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_asinh(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr8_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_acosh(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr8_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_tanh(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr8_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_cbrt(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr8_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sqrt(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_cosh(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sinh(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_asin(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_acos(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_atan(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_tan(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_cos(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sin(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_logb(femdarr8_t* arr, double base){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_log10(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_log(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_exp(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_pow(femdarr8_t* arr, double e){

    femdarr8_t res = femdarr8_init();

    res = femdarr8_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr8_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_atanh_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_asinh_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_acosh_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_tanh_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_cbrt_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sqrt_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_cosh_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sinh_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_asin_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_acos_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_atan_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_tan_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_cos_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sin_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_logb_to(femdarr8_t* arr, double base, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_log10_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_log_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_exp_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_pow_to(femdarr8_t* arr, double e, femdarr8_t* res){

    uint64_t i;

    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr8_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

