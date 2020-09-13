

// ****************************************************************************************************
femdnum6_t femdnum6_atanh(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);

    femdnum6_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_asinh(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);

    femdnum6_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_acosh(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);

    femdnum6_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_tanh(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);

    femdnum6_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_cosh(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sinh(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_asin(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_acos(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_atan(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_tan(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_cos(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sin(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_logb(femdnum6_t* num, double base){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_log10(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_log(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_exp(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_cbrt(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);

    femdnum6_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sqrt(femdnum6_t* num){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);
    
    femdnum6_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_pow(femdnum6_t* num, double e){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(num->nip);

    femdnum6_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_atanh_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_asinh_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_acosh_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_tanh_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_cosh_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sinh_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_asin_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_acos_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_atan_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_tan_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_cos_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sin_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_logb_to(femdnum6_t* num, double base, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_log10_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_log_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_exp_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_cbrt_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sqrt_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_pow_to(femdnum6_t* num, double e, femdnum6_t* res){

    uint64_t i;

    femdnum6_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum6_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t femdnum6_integrate_r(coeff_t num, femdnum6_t* w){

    mdnum6_t  res = mdnum6_init(); // res = 0.0

    femdnum6_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_integrate_r_to(coeff_t num, femdnum6_t* w, mdnum6_t* res){

    uint64_t i = 0;

    mdnum6_t tmp ;

    // res may not come as zero, Modify this?
    mdnum6_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum6_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum6_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t femdnum6_integrate_o(mdnum6_t* num, femdnum6_t* w){

    mdnum6_t  res = mdnum6_init(); // res = 0.0

    femdnum6_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_integrate_o_to(mdnum6_t* num, femdnum6_t* w, mdnum6_t* res){

    uint64_t i = 0;

    mdnum6_t tmp ;

    // res may not come as zero, Modify this?
    mdnum6_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum6_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum6_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t femdnum6_integrate_f(femdnum6_t* num, femdnum6_t* w){

    mdnum6_t  res = mdnum6_init(); // res = 0.0

    femdnum6_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_integrate_f_to(femdnum6_t* num, femdnum6_t* w, mdnum6_t* res){

    uint64_t i = 0;
    mdnum6_t tmp ;

    // Check dimensions.
    femdnum6_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum6_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum6_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum6_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t femdnum6_integrate(femdnum6_t* num, femdnum6_t* w){

    mdnum6_t  res = mdnum6_init(); // res = 0.0

    femdnum6_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_integrate_to(femdnum6_t* num, femdnum6_t* w, mdnum6_t* res){

    uint64_t i = 0;
    mdnum6_t tmp ;

    // Check dimensions.
    femdnum6_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum6_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum6_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum6_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------