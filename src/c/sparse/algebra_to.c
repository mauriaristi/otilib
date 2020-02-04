




// Algebraic operations:


// Negation

// ****************************************************************************************************
void soti_neg_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    soti_mul_ro_to(-1.0,num,res,dhl);

}
// ----------------------------------------------------------------------------------------------------









// Addition.

// ****************************************************************************************************
void soti_sum_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    sotinum_t tmp;

    tmp = soti_base_sum( num1, num2, dhl);

    soti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_sum_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    soti_copy_to( num, res, dhl);

    res->re += val;

}
// ----------------------------------------------------------------------------------------------------


















// Subtraction.

// ****************************************************************************************************
void soti_sub_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    sotinum_t tmp;

    tmp = soti_base_sub( num1, num2, dhl);

    soti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_sub_ro_to( coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    soti_neg_to(num,res,dhl);
    
    res->re += val;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sub_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl){

    soti_sum_ro_to(-val,num,res,dhl);
}
// ----------------------------------------------------------------------------------------------------











// Multiplication.

// ****************************************************************************************************
void soti_mul_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    
    sotinum_t  tmp;

    tmp = soti_base_mul(num1,num2,dhl);

    soti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_mul_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    ord_t i;
    ndir_t j;

    soti_copy_to(num,res,dhl);

    res->re *= val;

    for ( i=0; i<res->order; i++){
        
        for ( j = 0; j<res->p_nnz[i]; j++){

            res->p_im[i][j] *= val;

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_gem_oo_to(sotinum_t* a, sotinum_t* b, sotinum_t* c, sotinum_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): res = a*b + c

    sotinum_t  tmp1, tmp2;

    tmp1 = soti_base_mul(    a, b, dhl); // This is temporal 3, 4 or 5
    tmp2 = soti_base_sum( tmp1, c, dhl); // this is temporal 7.

    soti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

































// Division.

// ****************************************************************************************************
void soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl){

    
    sotinum_t inv = soti_get_rtmp(6, den->order, dhl);
    soti_pow_to( den, -1, &inv, dhl);
    soti_mul_ro_to(num,&inv,res,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl){

    sotinum_t inv = soti_get_rtmp(6, den->order, dhl);
    
    soti_pow_to( den, -1, &inv, dhl);
    
    soti_mul_oo_to( num, &inv, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_div_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl){

    soti_mul_ro_to(1.0/val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------




























// Function evaluation.

// ****************************************************************************************************
void soti_feval_to(coeff_t* feval_re, sotinum_t* num, sotinum_t* res, dhelpl_t dhl ){
    
    sotinum_t tmp = soti_base_feval(feval_re, num, dhl);
    
    soti_copy_to( &tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------











