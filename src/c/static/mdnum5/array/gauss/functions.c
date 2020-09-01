

// ****************************************************************************************************
femdarr5_t femdarr5_atanh(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr5_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_asinh(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr5_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_acosh(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr5_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_tanh(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr5_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_cbrt(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr5_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sqrt(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_cosh(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sinh(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_asin(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_acos(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_atan(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_tan(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_cos(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sin(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_logb(femdarr5_t* arr, double base){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_log10(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_log(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_exp(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_pow(femdarr5_t* arr, double e){

    femdarr5_t res = femdarr5_init();

    res = femdarr5_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr5_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_atanh_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_asinh_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_acosh_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_tanh_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_cbrt_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sqrt_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_cosh_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sinh_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_asin_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_acos_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_atan_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_tan_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_cos_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sin_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_logb_to(femdarr5_t* arr, double base, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_log10_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_log_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_exp_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_pow_to(femdarr5_t* arr, double e, femdarr5_t* res){

    uint64_t i;

    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr5_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

