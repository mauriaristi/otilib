

// ****************************************************************************************************
femdnum1_t femdnum1_atanh(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);

    femdnum1_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_asinh(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);

    femdnum1_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_acosh(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);

    femdnum1_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_tanh(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);

    femdnum1_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_cosh(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sinh(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_asin(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_acos(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_atan(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_tan(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_cos(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sin(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_logb(femdnum1_t* num, double base){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_log10(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_log(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_exp(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_cbrt(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);

    femdnum1_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sqrt(femdnum1_t* num){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);
    
    femdnum1_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_pow(femdnum1_t* num, double e){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty(num->nip);

    femdnum1_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_atanh_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_asinh_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_acosh_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_tanh_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_cosh_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sinh_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_asin_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_acos_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_atan_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_tan_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_cos_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sin_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_logb_to(femdnum1_t* num, double base, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_log10_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_log_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_exp_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_cbrt_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sqrt_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_pow_to(femdnum1_t* num, double e, femdnum1_t* res){

    uint64_t i;

    femdnum1_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum1_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t femdnum1_integrate_r(coeff_t num, femdnum1_t* w){

    mdnum1_t  res = mdnum1_init(); // res = 0.0

    femdnum1_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_integrate_r_to(coeff_t num, femdnum1_t* w, mdnum1_t* res){

    uint64_t i = 0;

    mdnum1_t tmp ;

    // res may not come as zero, Modify this?
    mdnum1_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum1_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum1_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t femdnum1_integrate_o(mdnum1_t* num, femdnum1_t* w){

    mdnum1_t  res = mdnum1_init(); // res = 0.0

    femdnum1_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_integrate_o_to(mdnum1_t* num, femdnum1_t* w, mdnum1_t* res){

    uint64_t i = 0;

    mdnum1_t tmp ;

    // res may not come as zero, Modify this?
    mdnum1_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum1_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum1_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t femdnum1_integrate_f(femdnum1_t* num, femdnum1_t* w){

    mdnum1_t  res = mdnum1_init(); // res = 0.0

    femdnum1_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_integrate_f_to(femdnum1_t* num, femdnum1_t* w, mdnum1_t* res){

    uint64_t i = 0;
    mdnum1_t tmp ;

    // Check dimensions.
    femdnum1_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum1_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum1_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum1_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t femdnum1_integrate(femdnum1_t* num, femdnum1_t* w){

    mdnum1_t  res = mdnum1_init(); // res = 0.0

    femdnum1_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_integrate_to(femdnum1_t* num, femdnum1_t* w, mdnum1_t* res){

    uint64_t i = 0;
    mdnum1_t tmp ;

    // Check dimensions.
    femdnum1_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum1_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum1_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum1_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------