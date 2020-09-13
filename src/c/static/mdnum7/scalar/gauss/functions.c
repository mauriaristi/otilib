

// ****************************************************************************************************
femdnum7_t femdnum7_atanh(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);

    femdnum7_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_asinh(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);

    femdnum7_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_acosh(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);

    femdnum7_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_tanh(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);

    femdnum7_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_cosh(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sinh(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_asin(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_acos(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_atan(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_tan(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_cos(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sin(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_logb(femdnum7_t* num, double base){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_log10(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_log(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_exp(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_cbrt(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);

    femdnum7_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sqrt(femdnum7_t* num){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);
    
    femdnum7_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_pow(femdnum7_t* num, double e){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(num->nip);

    femdnum7_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_atanh_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_asinh_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_acosh_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_tanh_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_cosh_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sinh_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_asin_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_acos_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_atan_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_tan_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_cos_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sin_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_logb_to(femdnum7_t* num, double base, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_log10_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_log_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_exp_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_cbrt_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sqrt_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_pow_to(femdnum7_t* num, double e, femdnum7_t* res){

    uint64_t i;

    femdnum7_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum7_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t femdnum7_integrate_r(coeff_t num, femdnum7_t* w){

    mdnum7_t  res = mdnum7_init(); // res = 0.0

    femdnum7_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_integrate_r_to(coeff_t num, femdnum7_t* w, mdnum7_t* res){

    uint64_t i = 0;

    mdnum7_t tmp ;

    // res may not come as zero, Modify this?
    mdnum7_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum7_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum7_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t femdnum7_integrate_o(mdnum7_t* num, femdnum7_t* w){

    mdnum7_t  res = mdnum7_init(); // res = 0.0

    femdnum7_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_integrate_o_to(mdnum7_t* num, femdnum7_t* w, mdnum7_t* res){

    uint64_t i = 0;

    mdnum7_t tmp ;

    // res may not come as zero, Modify this?
    mdnum7_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum7_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum7_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t femdnum7_integrate_f(femdnum7_t* num, femdnum7_t* w){

    mdnum7_t  res = mdnum7_init(); // res = 0.0

    femdnum7_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_integrate_f_to(femdnum7_t* num, femdnum7_t* w, mdnum7_t* res){

    uint64_t i = 0;
    mdnum7_t tmp ;

    // Check dimensions.
    femdnum7_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum7_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum7_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum7_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t femdnum7_integrate(femdnum7_t* num, femdnum7_t* w){

    mdnum7_t  res = mdnum7_init(); // res = 0.0

    femdnum7_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_integrate_to(femdnum7_t* num, femdnum7_t* w, mdnum7_t* res){

    uint64_t i = 0;
    mdnum7_t tmp ;

    // Check dimensions.
    femdnum7_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum7_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum7_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum7_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------