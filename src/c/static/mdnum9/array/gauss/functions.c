

// ****************************************************************************************************
femdarr9_t femdarr9_atanh(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr9_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_asinh(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr9_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_acosh(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr9_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_tanh(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr9_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_cbrt(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr9_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sqrt(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_cosh(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sinh(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_asin(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_acos(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_atan(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_tan(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_cos(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sin(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_logb(femdarr9_t* arr, double base){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_log10(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_log(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_exp(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_pow(femdarr9_t* arr, double e){

    femdarr9_t res = femdarr9_init();

    res = femdarr9_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr9_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_atanh_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_asinh_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_acosh_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_tanh_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_cbrt_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sqrt_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_cosh_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sinh_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_asin_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_acos_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_atan_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_tan_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_cos_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sin_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_logb_to(femdarr9_t* arr, double base, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_log10_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_log_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_exp_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_pow_to(femdarr9_t* arr, double e, femdarr9_t* res){

    uint64_t i;

    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr9_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

