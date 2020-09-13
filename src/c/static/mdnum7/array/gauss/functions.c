

// ****************************************************************************************************
femdarr7_t femdarr7_atanh(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr7_atanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_asinh(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr7_asinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_acosh(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr7_acosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_tanh(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr7_tanh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_cbrt(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr7_cbrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sqrt(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_sqrt_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_cosh(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_cosh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sinh(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_sinh_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_asin(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_asin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_acos(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_acos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_atan(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_atan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_tan(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_tan_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_cos(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_cos_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sin(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_sin_to(arr, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_logb(femdarr7_t* arr, double base){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_logb_to(arr, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_log10(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_log10_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_log(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_log_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_exp(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_exp_to(arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_pow(femdarr7_t* arr, double e){

    femdarr7_t res = femdarr7_init();

    res = femdarr7_zeros(arr->nrows, arr->ncols, arr->nip);

    femdarr7_pow_to(arr, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_atanh_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_asinh_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_acosh_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_tanh_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_cbrt_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sqrt_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_cosh_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sinh_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_asin_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_asin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_acos_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_acos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_atan_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_atan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_tan_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_tan_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_cos_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_cos_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sin_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_sin_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_logb_to(femdarr7_t* arr, double base, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_log10_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_log10_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_log_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_log_to(&arr->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_exp_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_exp_to(&arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_pow_to(femdarr7_t* arr, double e, femdarr7_t* res){

    uint64_t i;

    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    for( i = 0; i<arr->nip; i++){
        
        mdarr7_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

