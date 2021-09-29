

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
fessoti_t fessoti_neg(fessoti_t* num, dhelpl_t dhl){

    fessoti_t res = fessoti_empty_like( num, dhl);

    fessoti_neg_to(num,&res,dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_neg_to(fessoti_t* num, fessoti_t* res, dhelpl_t dhl){

    uint64_t i;
    
    // Check dimensions
    fessoti_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        ssoti_neg_to( &num->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------
















// 1.2. Addition.
// ****************************************************************************************************
fessoti_t fessoti_sum_ff(fessoti_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fessoti_t res;

    res = fessoti_empty_like( lhs, dhl);

    fessoti_sum_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fessoti_t fessoti_sum_of(semiotin_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fessoti_t res;
    res = fessoti_empty_like( rhs, dhl);

    fessoti_sum_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_sum_rf(coeff_t lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fessoti_t res;

    res = fessoti_empty_like( rhs, dhl);

    fessoti_sum_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void fessoti_sum_ff_to(fessoti_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fessoti_dimCheck( lhs, rhs );
    fessoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        ssoti_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_sum_of_to(semiotin_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_sum_rf_to(coeff_t lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------



















// 1.2. Subtraction.
// ****************************************************************************************************
fessoti_t fessoti_sub_ff(fessoti_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fessoti_t res;

    res = fessoti_empty_like( lhs, dhl);

    fessoti_sub_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_sub_of(semiotin_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fessoti_t res;
    res = fessoti_empty_like( rhs, dhl);

    fessoti_sub_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_sub_fo(fessoti_t* lhs, semiotin_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fessoti_t res;
    res = fessoti_empty_like( lhs, dhl);

    fessoti_sub_fo_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_sub_rf(coeff_t lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fessoti_t res;

    res = fessoti_empty_like( rhs, dhl);

    fessoti_sub_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_sub_fr(fessoti_t* lhs, coeff_t rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fessoti_t res;

    res = fessoti_empty_like( lhs, dhl);

    fessoti_sub_fr_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void fessoti_sub_ff_to(fessoti_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fessoti_dimCheck( lhs, rhs );
    fessoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        ssoti_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_sub_of_to(semiotin_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_sub_fo_to(fessoti_t* lhs, semiotin_t* rhs, fessoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        ssoti_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_sub_rf_to(coeff_t lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_sub_fr_to(fessoti_t* lhs, coeff_t rhs, fessoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        ssoti_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

























// 1.4. Multiplication.
// ****************************************************************************************************
fessoti_t fessoti_mul_ff(fessoti_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fessoti_t res;

    res = fessoti_empty_like( lhs, dhl);

    fessoti_mul_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_mul_of(semiotin_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fessoti_t res;
    res = fessoti_empty_like( rhs, dhl);

    fessoti_mul_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_mul_rf(coeff_t lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fessoti_t res;

    res = fessoti_empty_like( rhs, dhl);

    fessoti_mul_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void fessoti_mul_ff_to(fessoti_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fessoti_dimCheck( lhs, rhs );
    fessoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        ssoti_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_mul_of_to(semiotin_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_mul_rf_to(coeff_t lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------




























// 1.5. Division.
// ****************************************************************************************************
fessoti_t fessoti_div_ff(fessoti_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fessoti_t res;

    res = fessoti_empty_like( lhs, dhl);

    fessoti_div_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_div_of(semiotin_t* lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fessoti_t res;
    res = fessoti_empty_like( rhs, dhl);

    fessoti_div_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_div_fo(fessoti_t* lhs, semiotin_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fessoti_t res;
    res = fessoti_empty_like( lhs, dhl);

    fessoti_div_fo_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_div_rf(coeff_t lhs, fessoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fessoti_t res;

    res = fessoti_empty_like( rhs, dhl);

    fessoti_div_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_div_fr(fessoti_t* lhs, coeff_t rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fessoti_t res;

    res = fessoti_empty_like( lhs, dhl);

    fessoti_div_fr_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void fessoti_div_ff_to(fessoti_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fessoti_dimCheck( lhs, rhs );
    fessoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        ssoti_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_div_of_to(semiotin_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_div_fo_to(fessoti_t* lhs, semiotin_t* rhs, fessoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        ssoti_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_div_rf_to(coeff_t lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        ssoti_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_div_fr_to(fessoti_t* lhs, coeff_t rhs, fessoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fessoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        ssoti_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------






