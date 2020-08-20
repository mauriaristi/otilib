

// ****************************************************************************************************
femdnum4_t femdnum4_atanh(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);

    femdnum4_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_asinh(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);

    femdnum4_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_acosh(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);

    femdnum4_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_tanh(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);

    femdnum4_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_cosh(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sinh(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_asin(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_acos(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_atan(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_tan(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_cos(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sin(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_logb(femdnum4_t* num, double base){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_log10(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_log(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_exp(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_cbrt(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);

    femdnum4_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sqrt(femdnum4_t* num){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);
    
    femdnum4_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_pow(femdnum4_t* num, double e){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(num->nip);

    femdnum4_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_atanh_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_asinh_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_acosh_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_tanh_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_cosh_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sinh_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_asin_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_acos_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_atan_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_tan_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_cos_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sin_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_logb_to(femdnum4_t* num, double base, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_log10_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_log_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_exp_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_cbrt_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sqrt_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_pow_to(femdnum4_t* num, double e, femdnum4_t* res){

    uint64_t i;

    femdnum4_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum4_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t femdnum4_integrate_r(coeff_t num, femdnum4_t* w){

    mdnum4_t  res = mdnum4_init(); // res = 0.0

    femdnum4_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_integrate_r_to(coeff_t num, femdnum4_t* w, mdnum4_t* res){

    uint64_t i = 0;

    mdnum4_t tmp ;

    // res may not come as zero, Modify this?
    mdnum4_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum4_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum4_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t femdnum4_integrate_o(mdnum4_t* num, femdnum4_t* w){

    mdnum4_t  res = mdnum4_init(); // res = 0.0

    femdnum4_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_integrate_o_to(mdnum4_t* num, femdnum4_t* w, mdnum4_t* res){

    uint64_t i = 0;

    mdnum4_t tmp ;

    // res may not come as zero, Modify this?
    mdnum4_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum4_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum4_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t femdnum4_integrate_f(femdnum4_t* num, femdnum4_t* w){

    mdnum4_t  res = mdnum4_init(); // res = 0.0

    femdnum4_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_integrate_f_to(femdnum4_t* num, femdnum4_t* w, mdnum4_t* res){

    uint64_t i = 0;
    mdnum4_t tmp ;

    // Check dimensions.
    femdnum4_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum4_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum4_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum4_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t femdnum4_integrate(femdnum4_t* num, femdnum4_t* w){

    mdnum4_t  res = mdnum4_init(); // res = 0.0

    femdnum4_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_integrate_to(femdnum4_t* num, femdnum4_t* w, mdnum4_t* res){

    uint64_t i = 0;
    mdnum4_t tmp ;

    // Check dimensions.
    femdnum4_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum4_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum4_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum4_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------