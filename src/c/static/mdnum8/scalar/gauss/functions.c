

// ****************************************************************************************************
femdnum8_t femdnum8_atanh(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);

    femdnum8_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_asinh(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);

    femdnum8_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_acosh(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);

    femdnum8_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_tanh(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);

    femdnum8_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_cosh(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sinh(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_asin(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_acos(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_atan(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_tan(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_cos(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sin(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_logb(femdnum8_t* num, double base){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_log10(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_log(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_exp(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_cbrt(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);

    femdnum8_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sqrt(femdnum8_t* num){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);
    
    femdnum8_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_pow(femdnum8_t* num, double e){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(num->nip);

    femdnum8_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_atanh_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_asinh_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_acosh_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_tanh_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_cosh_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sinh_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_asin_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_acos_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_atan_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_tan_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_cos_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sin_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_logb_to(femdnum8_t* num, double base, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_log10_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_log_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_exp_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_cbrt_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sqrt_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_pow_to(femdnum8_t* num, double e, femdnum8_t* res){

    uint64_t i;

    femdnum8_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum8_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t femdnum8_integrate_r(coeff_t num, femdnum8_t* w){

    mdnum8_t  res = mdnum8_init(); // res = 0.0

    femdnum8_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_integrate_r_to(coeff_t num, femdnum8_t* w, mdnum8_t* res){

    uint64_t i = 0;

    mdnum8_t tmp ;

    // res may not come as zero, Modify this?
    mdnum8_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum8_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum8_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t femdnum8_integrate_o(mdnum8_t* num, femdnum8_t* w){

    mdnum8_t  res = mdnum8_init(); // res = 0.0

    femdnum8_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_integrate_o_to(mdnum8_t* num, femdnum8_t* w, mdnum8_t* res){

    uint64_t i = 0;

    mdnum8_t tmp ;

    // res may not come as zero, Modify this?
    mdnum8_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum8_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum8_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t femdnum8_integrate_f(femdnum8_t* num, femdnum8_t* w){

    mdnum8_t  res = mdnum8_init(); // res = 0.0

    femdnum8_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_integrate_f_to(femdnum8_t* num, femdnum8_t* w, mdnum8_t* res){

    uint64_t i = 0;
    mdnum8_t tmp ;

    // Check dimensions.
    femdnum8_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum8_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum8_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum8_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t femdnum8_integrate(femdnum8_t* num, femdnum8_t* w){

    mdnum8_t  res = mdnum8_init(); // res = 0.0

    femdnum8_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_integrate_to(femdnum8_t* num, femdnum8_t* w, mdnum8_t* res){

    uint64_t i = 0;
    mdnum8_t tmp ;

    // Check dimensions.
    femdnum8_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum8_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum8_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum8_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------