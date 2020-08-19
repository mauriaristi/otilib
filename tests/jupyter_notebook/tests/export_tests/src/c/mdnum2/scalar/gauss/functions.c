

// ****************************************************************************************************
femdnum2_t femdnum2_atanh(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);

    femdnum2_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_asinh(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);

    femdnum2_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_acosh(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);

    femdnum2_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_tanh(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);

    femdnum2_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_cosh(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sinh(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_asin(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_acos(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_atan(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_tan(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_cos(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sin(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_logb(femdnum2_t* num, double base){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_log10(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_log(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_exp(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_cbrt(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);

    femdnum2_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sqrt(femdnum2_t* num){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);
    
    femdnum2_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_pow(femdnum2_t* num, double e){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(num->nip);

    femdnum2_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_atanh_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_asinh_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_acosh_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_tanh_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_cosh_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sinh_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_asin_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_acos_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_atan_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_tan_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_cos_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sin_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_logb_to(femdnum2_t* num, double base, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_log10_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_log_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_exp_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_cbrt_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sqrt_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_pow_to(femdnum2_t* num, double e, femdnum2_t* res){

    uint64_t i;

    femdnum2_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum2_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t femdnum2_integrate_r(coeff_t num, femdnum2_t* w){

    mdnum2_t  res = mdnum2_init(); // res = 0.0

    femdnum2_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_integrate_r_to(coeff_t num, femdnum2_t* w, mdnum2_t* res){

    uint64_t i = 0;

    mdnum2_t tmp = mdnum2_get_tmp( 1, femdnum2_get_order( w ));

    // res may not come as zero, Modify this?
    mdnum2_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum2_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum2_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t femdnum2_integrate_o(mdnum2_t* num, femdnum2_t* w){

    mdnum2_t  res = mdnum2_init(); // res = 0.0

    femdnum2_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_integrate_o_to(mdnum2_t* num, femdnum2_t* w, mdnum2_t* res){

    uint64_t i = 0;

    mdnum2_t tmp = mdnum2_get_tmp( 1, femdnum2_get_order( w ));

    // res may not come as zero, Modify this?
    mdnum2_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum2_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum2_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t femdnum2_integrate_f(femdnum2_t* num, femdnum2_t* w){

    mdnum2_t  res = mdnum2_init(); // res = 0.0

    femdnum2_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_integrate_f_to(femdnum2_t* num, femdnum2_t* w, mdnum2_t* res){

    uint64_t i = 0;
    mdnum2_t tmp = mdnum2_get_tmp( 1, femdnum2_get_order( w ));

    // Check dimensions.
    femdnum2_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum2_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum2_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum2_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t femdnum2_integrate(femdnum2_t* num, femdnum2_t* w){

    mdnum2_t  res = mdnum2_init(); // res = 0.0

    femdnum2_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_integrate_to(femdnum2_t* num, femdnum2_t* w, mdnum2_t* res){

    uint64_t i = 0;
    mdnum2_t tmp = mdnum2_get_tmp( 1, femdnum2_get_order( w ));

    // Check dimensions.
    femdnum2_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum2_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum2_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum2_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------