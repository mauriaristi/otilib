




// Algebraic operations:
// Negation

// ****************************************************************************************************
void soti_neg_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    soti_mul_ro_to(-1.0,num,res,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_abs_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    if (num->re < 0){
        
        soti_neg_to(num,res,dhl);

    } else {

        soti_copy_to(num,res,dhl);
    }

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
void soti_sum_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl){
    
    soti_sum_ro_to(val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sum_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    soti_copy_to( num, res, dhl);

    res->re += val;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_trunc_sum_oo_to(ord_t ord, sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    sotinum_t tmp;

    tmp = soti_base_trunc_sum( ord, num1, num2, dhl);

    soti_copy_to(&tmp, res, dhl);

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

// ****************************************************************************************************
void soti_trunc_sub_oo_to(ord_t ord, sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    sotinum_t tmp;

    tmp = soti_base_trunc_sub( ord, num1, num2, dhl);

    soti_copy_to(&tmp, res, dhl);

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
void soti_mul_or_to( sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl){
    
    soti_mul_ro_to(val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_mul_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    ord_t i;
    ndir_t j;

    soti_copy_to(num,res,dhl);

    res->re *= val;

    for ( i=0; i<res->act_order; i++){
        
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

    tmp1 = soti_base_mul(    a, b, dhl);  // This is temporal 3, 4 or 5
    tmp2 = soti_base_sum( &tmp1, c, dhl); // this is temporal 7.

    soti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_gem_or_to( sotinum_t* b, coeff_t a, sotinum_t* c, sotinum_t* res, dhelpl_t dhl){
    
    soti_gem_ro_to( a, b, c, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_gem_ro_to(coeff_t a, sotinum_t* b, sotinum_t* c, sotinum_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): res = a*b + c

    sotinum_t tmp1 = soti_get_tmp( 0, b->act_order, dhl);
    sotinum_t tmp2;

    soti_mul_ro_to( a, b, &tmp1, dhl); // This is temporal 10
    
    tmp2 = soti_base_sum( &tmp1, c, dhl); // this is temporal 7.

    soti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void soti_trunc_gem_oo_to(ord_t orda, sotinum_t* a, ord_t ordb, sotinum_t* b, sotinum_t* c,
                          sotinum_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): res = a*b + c

    sotinum_t  tmp1, tmp2;
    ord_t ord_res = orda + ordb;
    // printf("Before base_trunc_mul\n");
    tmp1 = soti_base_trunc_mul(    orda, a, ordb, b, dhl);  // This is temporal 3, 4 or 5
    // printf("-----> base_trunc_mul Ok\n");
    // printf("Before base_trunc_sum\n");
    tmp2 = soti_base_trunc_sum( ord_res, &tmp1, c,   dhl); // this is temporal 7.
    // printf("-----> base_trunc_sum Ok\n");
    soti_copy_to(&tmp2, res, dhl);

}
// ----------------------------------------------------------------------------------------------------



// Division.
// ****************************************************************************************************
void soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl){

    
    sotinum_t inv = soti_get_rtmp(6, den->trc_order, dhl);
    soti_pow_to( den, -1, &inv, dhl);
    soti_mul_ro_to(num,&inv,res,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl){

    sotinum_t inv = soti_get_rtmp(6, den->trc_order, dhl);
    
    soti_pow_to( den, -1.0, &inv, dhl);
    
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
