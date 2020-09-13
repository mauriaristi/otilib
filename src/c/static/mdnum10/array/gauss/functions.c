

// ****************************************************************************************************
femdarr10_t femdarr10_atanh(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr10_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_asinh(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr10_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_acosh(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr10_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_tanh(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr10_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_cbrt(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr10_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sqrt(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_cosh(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sinh(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_asin(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_acos(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_atan(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_tan(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_cos(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sin(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_logb(femdarr10_t* arr, double base){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_log10(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_log(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_exp(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_pow(femdarr10_t* arr, double e){

    femdarr10_t res = femdarr10_init();

    res = femdarr10_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr10_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_atanh_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_asinh_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_acosh_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_tanh_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_cbrt_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sqrt_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_cosh_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sinh_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_asin_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_acos_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_atan_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_tan_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_cos_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sin_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_logb_to(femdarr10_t* arr, double base, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_log10_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_log_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_exp_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_pow_to(femdarr10_t* arr, double e, femdarr10_t* res){

    uint64_t i;

    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr10_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

