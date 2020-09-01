

// ****************************************************************************************************
femdnum5_t femdnum5_atanh(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);

    femdnum5_atanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_asinh(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);

    femdnum5_asinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_acosh(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);

    femdnum5_acosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_tanh(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);

    femdnum5_tanh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_cosh(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_cosh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sinh(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_sinh_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_asin(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_asin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_acos(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_acos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_atan(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_atan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_tan(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_tan_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_cos(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_cos_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sin(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_sin_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_logb(femdnum5_t* num, double base){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_logb_to(num, base, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_log10(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_log10_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_log(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_log_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_exp(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_exp_to(num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_cbrt(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);

    femdnum5_cbrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sqrt(femdnum5_t* num){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);
    
    femdnum5_sqrt_to(num, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_pow(femdnum5_t* num, double e){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty(num->nip);

    femdnum5_pow_to(num, e, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_atanh_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_atanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_asinh_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_asinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_acosh_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_acosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_tanh_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_tanh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_cosh_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_cosh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sinh_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_sinh_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_asin_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_asin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_acos_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_acos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_atan_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_atan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_tan_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_tan_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_cos_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_cos_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sin_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_sin_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_logb_to(femdnum5_t* num, double base, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_logb_to(&num->p_data[i], base, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_log10_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_log10_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_log_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_log_to(&num->p_data[i], &res->p_data[i]);

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_exp_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_exp_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_cbrt_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_cbrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sqrt_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_sqrt_to(&num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_pow_to(femdnum5_t* num, double e, femdnum5_t* res){

    uint64_t i;

    femdnum5_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){
        
        mdnum5_pow_to(&num->p_data[i], e, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t femdnum5_integrate_r(coeff_t num, femdnum5_t* w){

    mdnum5_t  res = mdnum5_init(); // res = 0.0

    femdnum5_integrate_r_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_integrate_r_to(coeff_t num, femdnum5_t* w, mdnum5_t* res){

    uint64_t i = 0;

    mdnum5_t tmp ;

    // res may not come as zero, Modify this?
    mdnum5_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum5_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum5_mul_ro_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t femdnum5_integrate_o(mdnum5_t* num, femdnum5_t* w){

    mdnum5_t  res = mdnum5_init(); // res = 0.0

    femdnum5_integrate_o_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_integrate_o_to(mdnum5_t* num, femdnum5_t* w, mdnum5_t* res){

    uint64_t i = 0;

    mdnum5_t tmp ;

    // res may not come as zero, Modify this?
    mdnum5_set_r(0, &tmp);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){
        
        mdnum5_sum_oo_to(  &tmp, &w->p_data[i], &tmp);

    }

    mdnum5_mul_oo_to( num, &tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t femdnum5_integrate_f(femdnum5_t* num, femdnum5_t* w){

    mdnum5_t  res = mdnum5_init(); // res = 0.0

    femdnum5_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_integrate_f_to(femdnum5_t* num, femdnum5_t* w, mdnum5_t* res){

    uint64_t i = 0;
    mdnum5_t tmp ;

    // Check dimensions.
    femdnum5_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum5_set_r(0,&tmp);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum5_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum5_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t femdnum5_integrate(femdnum5_t* num, femdnum5_t* w){

    mdnum5_t  res = mdnum5_init(); // res = 0.0

    femdnum5_integrate_to(num, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_integrate_to(femdnum5_t* num, femdnum5_t* w, mdnum5_t* res){

    uint64_t i = 0;
    mdnum5_t tmp ;

    // Check dimensions.
    femdnum5_dimCheck( num, w);

    // res may not come as zero, Modify this?
    mdnum5_set_r(0,&tmp);

    // res may not come as zero, Modify this?

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){
        
        mdnum5_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp);

    }

    mdnum5_set_o(&tmp, res);
}
// ----------------------------------------------------------------------------------------------------