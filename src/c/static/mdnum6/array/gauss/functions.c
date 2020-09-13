

// ****************************************************************************************************
femdarr6_t femdarr6_atanh(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr6_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_asinh(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr6_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_acosh(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr6_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_tanh(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr6_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_cbrt(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr6_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sqrt(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_cosh(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sinh(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_asin(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_acos(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_atan(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_tan(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_cos(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sin(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_logb(femdarr6_t* arr, double base){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_log10(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_log(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_exp(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_pow(femdarr6_t* arr, double e){

    femdarr6_t res = femdarr6_init();

    res = femdarr6_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr6_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_atanh_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_asinh_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_acosh_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_tanh_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_cbrt_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sqrt_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_cosh_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sinh_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_asin_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_acos_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_atan_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_tan_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_cos_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sin_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_logb_to(femdarr6_t* arr, double base, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_log10_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_log_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_exp_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_pow_to(femdarr6_t* arr, double e, femdarr6_t* res){

    uint64_t i;

    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr6_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

