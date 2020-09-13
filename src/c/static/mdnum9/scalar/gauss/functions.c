

// ****************************************************************************************************
femdnum9_t femdnum9_atanh(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);

    femdnum9_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_asinh(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);

    femdnum9_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_acosh(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);

    femdnum9_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_tanh(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);

    femdnum9_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_cosh(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sinh(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_asin(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_acos(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_atan(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_tan(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_cos(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sin(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_logb(femdnum9_t* num, double base){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_log10(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_log(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_exp(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_cbrt(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);

    femdnum9_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sqrt(femdnum9_t* num){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);
    
    femdnum9_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_pow(femdnum9_t* num, double e){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty(num->nip);

    femdnum9_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_atanh_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_asinh_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_acosh_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_tanh_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_cosh_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sinh_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_asin_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_acos_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_atan_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_tan_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_cos_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sin_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_logb_to(femdnum9_t* num, double base, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_log10_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_log_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_exp_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_cbrt_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sqrt_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_pow_to(femdnum9_t* num, double e, femdnum9_t* res){

    uint64_t i;

    femdnum9_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum9_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum9_t femdnum9_integrate_r(coeff_t num, femdnum9_t* w){

    mdnum9_t  res = mdnum9_init(); // res = 0.0

    femdnum9_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_integrate_r_to(coeff_t num, femdnum9_t* w, mdnum9_t* res){

    uint64_t i = 0;

    mdnum9_t tmp ;

    // res may not come as zero, Modify this?
    mdnum9_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum9_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum9_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum9_t femdnum9_integrate_o(mdnum9_t* num, femdnum9_t* w){

    mdnum9_t  res = mdnum9_init(); // res = 0.0

    femdnum9_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_integrate_o_to(mdnum9_t* num, femdnum9_t* w, mdnum9_t* res){

    uint64_t i = 0;

    mdnum9_t tmp ;

    // res may not come as zero, Modify this?
    mdnum9_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum9_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum9_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum9_t femdnum9_integrate_f(femdnum9_t* num, femdnum9_t* w){

    mdnum9_t  res = mdnum9_init(); // res = 0.0

    femdnum9_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_integrate_f_to(femdnum9_t* num, femdnum9_t* w, mdnum9_t* res){

    uint64_t i = 0;
    mdnum9_t tmp ;

    // Check dimensions.
    femdnum9_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum9_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum9_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum9_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum9_t femdnum9_integrate(femdnum9_t* num, femdnum9_t* w){

    mdnum9_t  res = mdnum9_init(); // res = 0.0

    femdnum9_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_integrate_to(femdnum9_t* num, femdnum9_t* w, mdnum9_t* res){

    uint64_t i = 0;
    mdnum9_t tmp ;

    // Check dimensions.
    femdnum9_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum9_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum9_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum9_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------