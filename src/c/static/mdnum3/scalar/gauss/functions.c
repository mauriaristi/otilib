

// ****************************************************************************************************
femdnum3_t femdnum3_atanh(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);

    femdnum3_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_asinh(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);

    femdnum3_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_acosh(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);

    femdnum3_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_tanh(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);

    femdnum3_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_cosh(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sinh(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_asin(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_acos(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_atan(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_tan(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_cos(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sin(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_logb(femdnum3_t* num, double base){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_log10(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_log(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_exp(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_cbrt(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);

    femdnum3_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sqrt(femdnum3_t* num){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);
    
    femdnum3_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_pow(femdnum3_t* num, double e){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(num->nip);

    femdnum3_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_atanh_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_asinh_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_acosh_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_tanh_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_cosh_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sinh_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_asin_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_acos_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_atan_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_tan_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_cos_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sin_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_logb_to(femdnum3_t* num, double base, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_log10_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_log_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_exp_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_cbrt_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sqrt_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_pow_to(femdnum3_t* num, double e, femdnum3_t* res){

    uint64_t i;

    femdnum3_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum3_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t femdnum3_integrate_r(coeff_t num, femdnum3_t* w){

    mdnum3_t  res = mdnum3_init(); // res = 0.0

    femdnum3_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_integrate_r_to(coeff_t num, femdnum3_t* w, mdnum3_t* res){

    uint64_t i = 0;

    mdnum3_t tmp ;

    // res may not come as zero, Modify this?
    mdnum3_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum3_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum3_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t femdnum3_integrate_o(mdnum3_t* num, femdnum3_t* w){

    mdnum3_t  res = mdnum3_init(); // res = 0.0

    femdnum3_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_integrate_o_to(mdnum3_t* num, femdnum3_t* w, mdnum3_t* res){

    uint64_t i = 0;

    mdnum3_t tmp ;

    // res may not come as zero, Modify this?
    mdnum3_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum3_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum3_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t femdnum3_integrate_f(femdnum3_t* num, femdnum3_t* w){

    mdnum3_t  res = mdnum3_init(); // res = 0.0

    femdnum3_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_integrate_f_to(femdnum3_t* num, femdnum3_t* w, mdnum3_t* res){

    uint64_t i = 0;
    mdnum3_t tmp ;

    // Check dimensions.
    femdnum3_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum3_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum3_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum3_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t femdnum3_integrate(femdnum3_t* num, femdnum3_t* w){

    mdnum3_t  res = mdnum3_init(); // res = 0.0

    femdnum3_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_integrate_to(femdnum3_t* num, femdnum3_t* w, mdnum3_t* res){

    uint64_t i = 0;
    mdnum3_t tmp ;

    // Check dimensions.
    femdnum3_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum3_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum3_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum3_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------