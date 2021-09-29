




// Algebraic operations:
// Negation

// ****************************************************************************************************
void ssoti_neg_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
    ssoti_mul_ro_to(-1.0,num,res,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_abs_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    if (num->re < 0){
        
        ssoti_neg_to(num,res,dhl);

    } else {

        ssoti_copy_to(num,res,dhl);
    }

}
// ----------------------------------------------------------------------------------------------------














// Addition.

// ****************************************************************************************************
void ssoti_sum_oo_to(semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl){

    semiotin_t tmp;

    tmp = ssoti_base_sum( num1, num2, dhl);

    ssoti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sum_or_to(semiotin_t* num, coeff_t val, semiotin_t* res, dhelpl_t dhl){
    
    ssoti_sum_ro_to(val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sum_ro_to(coeff_t val, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
    ssoti_copy_to( num, res, dhl);

    res->re += val;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_trunc_sum_oo_to(ord_t ord, semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl){

    semiotin_t tmp;

    tmp = ssoti_base_trunc_sum( ord, num1, num2, dhl);

    ssoti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------













// Subtraction.

// ****************************************************************************************************
void ssoti_sub_oo_to(semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl){

    semiotin_t tmp;

    tmp = ssoti_base_sub( num1, num2, dhl);

    ssoti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sub_ro_to( coeff_t val, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    ssoti_neg_to(num,res,dhl);
    
    res->re += val;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sub_or_to(semiotin_t* num, coeff_t val, semiotin_t* res, dhelpl_t dhl){

    ssoti_sum_ro_to(-val,num,res,dhl);
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_trunc_sub_oo_to(ord_t ord, semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl){

    semiotin_t tmp;

    tmp = ssoti_base_trunc_sub( ord, num1, num2, dhl);

    ssoti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------












// Multiplication.

// ****************************************************************************************************
void ssoti_mul_oo_to(semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl){

    
    semiotin_t  tmp;

    tmp = ssoti_base_mul(num1,num2,dhl);

    ssoti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_mul_or_to( semiotin_t* num, coeff_t val, semiotin_t* res, dhelpl_t dhl){
    
    ssoti_mul_ro_to(val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_mul_ro_to(coeff_t val, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
    ord_t i;
    ndir_t j;

    ssoti_copy_to(num,res,dhl);

    res->re *= val;

    for ( i=0; i<res->act_order; i++){
        
        for ( j = 0; j<res->p_nnz[i]; j++){

            res->p_im[i][j] *= val;

        }

    }

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
void ssoti_gem_oo_to(semiotin_t* a, semiotin_t* b, semiotin_t* c, semiotin_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): res = a*b + c

    semiotin_t  tmp1, tmp2;

    tmp1 = ssoti_base_mul(    a, b, dhl);  // This is temporal 3, 4 or 5
    tmp2 = ssoti_base_sum( &tmp1, c, dhl); // this is temporal 7.

    ssoti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void ssoti_gem_or_to( semiotin_t* b, coeff_t a, semiotin_t* c, semiotin_t* res, dhelpl_t dhl){
    
    ssoti_gem_ro_to( a, b, c, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_gem_ro_to(coeff_t a, semiotin_t* b, semiotin_t* c, semiotin_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): res = a*b + c

    semiotin_t tmp1 = ssoti_get_tmp( 0, b->act_order, dhl);
    semiotin_t tmp2;

    ssoti_mul_ro_to( a, b, &tmp1, dhl); // This is temporal 10
    
    tmp2 = ssoti_base_sum( &tmp1, c, dhl); // this is temporal 7.

    ssoti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void ssoti_trunc_gem_oo_to(ord_t orda, semiotin_t* a, ord_t ordb, semiotin_t* b, semiotin_t* c,
                          semiotin_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): res = a*b + c

    semiotin_t  tmp1, tmp2;
    ord_t ord_res = orda + ordb;

    tmp1 = ssoti_base_trunc_mul(    orda, a, ordb, b, dhl);  // This is temporal 3, 4 or 5
    tmp2 = ssoti_base_trunc_sum( ord_res, &tmp1, c,   dhl); // this is temporal 7.

    ssoti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------



// Division.
// ****************************************************************************************************
void ssoti_div_ro_to(coeff_t num, semiotin_t* den, semiotin_t* res, dhelpl_t dhl){

    
    semiotin_t inv = ssoti_get_rtmp(6, den->trc_order, dhl);
    ssoti_pow_to( den, -1, &inv, dhl);
    ssoti_mul_ro_to(num,&inv,res,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_div_oo_to(semiotin_t* num, semiotin_t* den, semiotin_t* res, dhelpl_t dhl){

    semiotin_t inv = ssoti_get_rtmp(6, den->trc_order, dhl);
    
    ssoti_pow_to( den, -1.0, &inv, dhl);
    
    ssoti_mul_oo_to( num, &inv, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_div_or_to(semiotin_t* num, coeff_t val, semiotin_t* res, dhelpl_t dhl){

    ssoti_mul_ro_to(1.0/val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------



// Function evaluation.
// ****************************************************************************************************
void ssoti_feval_to(coeff_t* feval_re, semiotin_t* num, semiotin_t* res, dhelpl_t dhl ){
    
    semiotin_t tmp = ssoti_base_feval(feval_re, num, dhl);
    
    ssoti_copy_to( &tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------
