

// ****************************************************************************************************
femdarr2_t femdarr2_atanh(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr2_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_asinh(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr2_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_acosh(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr2_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_tanh(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr2_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_cbrt(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr2_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sqrt(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_cosh(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sinh(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_asin(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_acos(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_atan(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_tan(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_cos(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sin(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_logb(femdarr2_t* arr, double base){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_log10(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_log(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_exp(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_pow(femdarr2_t* arr, double e){

    femdarr2_t res = femdarr2_init();

    res = femdarr2_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr2_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_atanh_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_asinh_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_acosh_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_tanh_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_cbrt_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sqrt_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_cosh_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sinh_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_asin_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_acos_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_atan_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_tan_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_cos_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sin_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_logb_to(femdarr2_t* arr, double base, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_log10_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_log_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_exp_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_pow_to(femdarr2_t* arr, double e, femdarr2_t* res){

    uint64_t i;

    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr2_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

