

// ****************************************************************************************************
femdarr4_t femdarr4_atanh(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr4_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_asinh(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr4_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_acosh(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr4_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_tanh(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr4_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_cbrt(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr4_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sqrt(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_cosh(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sinh(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_asin(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_acos(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_atan(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_tan(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_cos(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sin(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_logb(femdarr4_t* arr, double base){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_log10(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_log(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_exp(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_pow(femdarr4_t* arr, double e){

    femdarr4_t res = femdarr4_init();

    res = femdarr4_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr4_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_atanh_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_asinh_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_acosh_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_tanh_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_cbrt_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sqrt_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_cosh_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sinh_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_asin_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_acos_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_atan_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_tan_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_cos_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sin_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_logb_to(femdarr4_t* arr, double base, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_log10_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_log_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_exp_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_pow_to(femdarr4_t* arr, double e, femdarr4_t* res){

    uint64_t i;

    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr4_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

