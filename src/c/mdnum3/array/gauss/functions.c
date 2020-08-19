

// ****************************************************************************************************
femdarr3_t femdarr3_atanh(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr3_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_asinh(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr3_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_acosh(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr3_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_tanh(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr3_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_cbrt(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr3_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sqrt(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_cosh(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sinh(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_asin(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_acos(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_atan(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_tan(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_cos(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sin(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_logb(femdarr3_t* arr, double base){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_log10(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_log(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_exp(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_pow(femdarr3_t* arr, double e){

    femdarr3_t res = femdarr3_init();

    res = femdarr3_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr3_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_atanh_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_asinh_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_acosh_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_tanh_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_cbrt_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sqrt_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_cosh_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sinh_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_asin_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_acos_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_atan_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_tan_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_cos_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sin_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_logb_to(femdarr3_t* arr, double base, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_log10_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_log_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_exp_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_pow_to(femdarr3_t* arr, double e, femdarr3_t* res){

    uint64_t i;

    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr3_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

