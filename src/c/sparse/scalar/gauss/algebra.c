

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
fesoti_t fesoti_neg(fesoti_t* num, dhelpl_t dhl){

    fesoti_t res = fesoti_empty_like( num, dhl);

    fesoti_neg_to(num,&res,dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_neg_to(fesoti_t* num, fesoti_t* res, dhelpl_t dhl){

    uint64_t i;
    
    // Check dimensions
    fesoti_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        soti_neg_to( &num->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// 1.1. Negation.
// ****************************************************************************************************
fesoti_t fesoti_abs(fesoti_t* num, dhelpl_t dhl){

    fesoti_t res = fesoti_empty_like( num, dhl);

    fesoti_abs_to(num,&res,dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_abs_to(fesoti_t* num, fesoti_t* res, dhelpl_t dhl){

    uint64_t i;
    
    // Check dimensions
    fesoti_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        soti_abs_to( &num->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------













// 1.2. Addition.
// ****************************************************************************************************
fesoti_t fesoti_sum_ff(fesoti_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fesoti_t res;

    res = fesoti_empty_like( lhs, dhl);

    fesoti_sum_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fesoti_t fesoti_sum_of(sotinum_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fesoti_t res;
    res = fesoti_empty_like( rhs, dhl);

    fesoti_sum_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_sum_rf(coeff_t lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fesoti_t res;

    res = fesoti_empty_like( rhs, dhl);

    fesoti_sum_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void fesoti_sum_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fesoti_dimCheck( lhs, rhs );
    fesoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        soti_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_sum_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_sum_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------



















// 1.2. Subtraction.
// ****************************************************************************************************
fesoti_t fesoti_sub_ff(fesoti_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fesoti_t res;

    res = fesoti_empty_like( lhs, dhl);

    fesoti_sub_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_sub_of(sotinum_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fesoti_t res;
    res = fesoti_empty_like( rhs, dhl);

    fesoti_sub_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_sub_fo(fesoti_t* lhs, sotinum_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fesoti_t res;
    res = fesoti_empty_like( lhs, dhl);

    fesoti_sub_fo_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_sub_rf(coeff_t lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fesoti_t res;

    res = fesoti_empty_like( rhs, dhl);

    fesoti_sub_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_sub_fr(fesoti_t* lhs, coeff_t rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fesoti_t res;

    res = fesoti_empty_like( lhs, dhl);

    fesoti_sub_fr_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void fesoti_sub_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fesoti_dimCheck( lhs, rhs );
    fesoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        soti_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_sub_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_sub_fo_to(fesoti_t* lhs, sotinum_t* rhs, fesoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        soti_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_sub_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_sub_fr_to(fesoti_t* lhs, coeff_t rhs, fesoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        soti_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

























// 1.4. Multiplication.
// ****************************************************************************************************
fesoti_t fesoti_mul_ff(fesoti_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fesoti_t res;

    res = fesoti_empty_like( lhs, dhl);

    fesoti_mul_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_mul_of(sotinum_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fesoti_t res;
    res = fesoti_empty_like( rhs, dhl);

    fesoti_mul_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_mul_rf(coeff_t lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fesoti_t res;

    res = fesoti_empty_like( rhs, dhl);

    fesoti_mul_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void fesoti_mul_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fesoti_dimCheck( lhs, rhs );
    fesoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        soti_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_mul_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_mul_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------




























// 1.5. Division.
// ****************************************************************************************************
fesoti_t fesoti_div_ff(fesoti_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform O + O.
    fesoti_t res;

    res = fesoti_empty_like( lhs, dhl);

    fesoti_div_ff_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_div_of(sotinum_t* lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fesoti_t res;
    res = fesoti_empty_like( rhs, dhl);

    fesoti_div_of_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_div_fo(fesoti_t* lhs, sotinum_t* rhs, dhelpl_t dhl){
    
    // Perform o + O.
    fesoti_t res;
    res = fesoti_empty_like( lhs, dhl);

    fesoti_div_fo_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_div_rf(coeff_t lhs, fesoti_t* rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fesoti_t res;

    res = fesoti_empty_like( rhs, dhl);

    fesoti_div_rf_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_div_fr(fesoti_t* lhs, coeff_t rhs, dhelpl_t dhl){
    
    // Perform r + O.
    fesoti_t res;

    res = fesoti_empty_like( lhs, dhl);

    fesoti_div_fr_to( lhs, rhs, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void fesoti_div_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fesoti_dimCheck( lhs, rhs );
    fesoti_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        soti_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_div_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_div_fo_to(fesoti_t* lhs, sotinum_t* rhs, fesoti_t* res, dhelpl_t dhl){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        soti_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_div_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        soti_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_div_fr_to(fesoti_t* lhs, coeff_t rhs, fesoti_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fesoti_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        soti_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------






