
// Division.

// ****************************************************************************************************
sotinum_t soti_div_ro(coeff_t num, sotinum_t* den, dhelpl_t dhl){

    
    sotinum_t inv = soti_pow(den,-1,dhl);
    sotinum_t res = soti_mul_ro(num,&inv,dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_div_oo(sotinum_t* num, sotinum_t* den, dhelpl_t dhl){

    
    sotinum_t inv = soti_init();
    soti_pow_to(den,-1,&inv,dhl);
    sotinum_t res = soti_mul_oo(num,&inv,dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_div_or(sotinum_t* num, coeff_t val, dhelpl_t dhl){

    return soti_mul_ro(1.0/val,num,dhl);

}
// ----------------------------------------------------------------------------------------------------

<<<algebra_src>>>