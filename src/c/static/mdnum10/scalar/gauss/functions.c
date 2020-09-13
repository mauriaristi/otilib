

// ****************************************************************************************************
femdnum10_t femdnum10_atanh(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);

    femdnum10_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_asinh(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);

    femdnum10_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_acosh(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);

    femdnum10_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_tanh(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);

    femdnum10_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_cosh(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sinh(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_asin(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_acos(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_atan(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_tan(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_cos(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sin(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_logb(femdnum10_t* num, double base){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_log10(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_log(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_exp(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_cbrt(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);

    femdnum10_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sqrt(femdnum10_t* num){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);
    
    femdnum10_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_pow(femdnum10_t* num, double e){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(num->nip);

    femdnum10_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_atanh_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_asinh_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_acosh_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_tanh_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_cosh_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sinh_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_asin_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_acos_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_atan_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_tan_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_cos_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sin_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_logb_to(femdnum10_t* num, double base, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_log10_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_log_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_exp_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_cbrt_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sqrt_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_pow_to(femdnum10_t* num, double e, femdnum10_t* res){

    uint64_t i;

    femdnum10_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum10_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum10_t femdnum10_integrate_r(coeff_t num, femdnum10_t* w){

    mdnum10_t  res = mdnum10_init(); // res = 0.0

    femdnum10_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_integrate_r_to(coeff_t num, femdnum10_t* w, mdnum10_t* res){

    uint64_t i = 0;

    mdnum10_t tmp ;

    // res may not come as zero, Modify this?
    mdnum10_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum10_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum10_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum10_t femdnum10_integrate_o(mdnum10_t* num, femdnum10_t* w){

    mdnum10_t  res = mdnum10_init(); // res = 0.0

    femdnum10_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_integrate_o_to(mdnum10_t* num, femdnum10_t* w, mdnum10_t* res){

    uint64_t i = 0;

    mdnum10_t tmp ;

    // res may not come as zero, Modify this?
    mdnum10_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum10_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum10_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum10_t femdnum10_integrate_f(femdnum10_t* num, femdnum10_t* w){

    mdnum10_t  res = mdnum10_init(); // res = 0.0

    femdnum10_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_integrate_f_to(femdnum10_t* num, femdnum10_t* w, mdnum10_t* res){

    uint64_t i = 0;
    mdnum10_t tmp ;

    // Check dimensions.
    femdnum10_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum10_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum10_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum10_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum10_t femdnum10_integrate(femdnum10_t* num, femdnum10_t* w){

    mdnum10_t  res = mdnum10_init(); // res = 0.0

    femdnum10_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_integrate_to(femdnum10_t* num, femdnum10_t* w, mdnum10_t* res){

    uint64_t i = 0;
    mdnum10_t tmp ;

    // Check dimensions.
    femdnum10_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum10_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum10_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum10_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------