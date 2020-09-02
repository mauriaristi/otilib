

// ****************************************************************************************************
femdarr1_t femdarr1_atanh(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr1_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_asinh(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr1_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_acosh(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr1_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_tanh(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr1_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_cbrt(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr1_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sqrt(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_cosh(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sinh(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_asin(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_acos(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_atan(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_tan(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_cos(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sin(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_logb(femdarr1_t* arr, double base){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_log10(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_log(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_exp(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_pow(femdarr1_t* arr, double e){

    femdarr1_t res = femdarr1_init();

    res = femdarr1_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr1_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_atanh_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_asinh_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_acosh_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_tanh_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_cbrt_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sqrt_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_cosh_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sinh_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_asin_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_acos_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_atan_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_tan_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_cos_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sin_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_logb_to(femdarr1_t* arr, double base, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_log10_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_log_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_exp_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_pow_to(femdarr1_t* arr, double e, femdarr1_t* res){

    uint64_t i;

    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr1_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

