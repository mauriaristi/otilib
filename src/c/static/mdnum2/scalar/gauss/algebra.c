

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum2_t femdnum2_neg(femdnum2_t* num){

    femdnum2_t res = femdnum2_empty_like( num);

    femdnum2_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_neg_to(femdnum2_t* num, femdnum2_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum2_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum2_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum2_t femdnum2_sum_ff(femdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform O + O.
    femdnum2_t res;

    res = femdnum2_empty_like( lhs);

    femdnum2_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sum_of(mdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform o + O.
    femdnum2_t res;
    res = femdnum2_empty_like( rhs);

    femdnum2_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sum_rf(coeff_t lhs, femdnum2_t* rhs){
    
    // Perform r + O.
    femdnum2_t res;

    res = femdnum2_empty_like( rhs);

    femdnum2_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum2_sum_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum2_dimCheck( lhs, rhs );
    femdnum2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum2_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sum_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sum_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum2_t femdnum2_sub_ff(femdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform O + O.
    femdnum2_t res;

    res = femdnum2_empty_like( lhs);

    femdnum2_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sub_of(mdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform o + O.
    femdnum2_t res;
    res = femdnum2_empty_like( rhs);

    femdnum2_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sub_fo(femdnum2_t* lhs, mdnum2_t* rhs){
    
    // Perform o + O.
    femdnum2_t res;
    res = femdnum2_empty_like( lhs);

    femdnum2_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sub_rf(coeff_t lhs, femdnum2_t* rhs){
    
    // Perform r + O.
    femdnum2_t res;

    res = femdnum2_empty_like( rhs);

    femdnum2_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_sub_fr(femdnum2_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum2_t res;

    res = femdnum2_empty_like( lhs);

    femdnum2_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum2_sub_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum2_dimCheck( lhs, rhs );
    femdnum2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum2_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sub_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sub_fo_to(femdnum2_t* lhs, mdnum2_t* rhs, femdnum2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum2_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sub_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_sub_fr_to(femdnum2_t* lhs, coeff_t rhs, femdnum2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum2_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum2_t femdnum2_mul_ff(femdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform O + O.
    femdnum2_t res;

    res = femdnum2_empty_like( lhs);

    femdnum2_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_mul_of(mdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform o + O.
    femdnum2_t res;
    res = femdnum2_empty_like( rhs);

    femdnum2_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_mul_rf(coeff_t lhs, femdnum2_t* rhs){
    
    // Perform r + O.
    femdnum2_t res;

    res = femdnum2_empty_like( rhs);

    femdnum2_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum2_mul_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum2_dimCheck( lhs, rhs );
    femdnum2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum2_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_mul_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_mul_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum2_t femdnum2_div_ff(femdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform O + O.
    femdnum2_t res;

    res = femdnum2_empty_like( lhs);

    femdnum2_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_div_of(mdnum2_t* lhs, femdnum2_t* rhs){
    
    // Perform o + O.
    femdnum2_t res;
    res = femdnum2_empty_like( rhs);

    femdnum2_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_div_fo(femdnum2_t* lhs, mdnum2_t* rhs){
    
    // Perform o + O.
    femdnum2_t res;
    res = femdnum2_empty_like( lhs);

    femdnum2_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_div_rf(coeff_t lhs, femdnum2_t* rhs){
    
    // Perform r + O.
    femdnum2_t res;

    res = femdnum2_empty_like( rhs);

    femdnum2_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_div_fr(femdnum2_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum2_t res;

    res = femdnum2_empty_like( lhs);

    femdnum2_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum2_div_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum2_dimCheck( lhs, rhs );
    femdnum2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum2_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_div_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_div_fo_to(femdnum2_t* lhs, mdnum2_t* rhs, femdnum2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum2_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_div_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum2_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_div_fr_to(femdnum2_t* lhs, coeff_t rhs, femdnum2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum2_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

