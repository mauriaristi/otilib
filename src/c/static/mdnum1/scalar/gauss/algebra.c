

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum1_t femdnum1_neg(femdnum1_t* num){

    femdnum1_t res = femdnum1_empty_like( num);

    femdnum1_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_neg_to(femdnum1_t* num, femdnum1_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum1_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum1_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum1_t femdnum1_sum_ff(femdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform O + O.
    femdnum1_t res;

    res = femdnum1_empty_like( lhs);

    femdnum1_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sum_of(mdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform o + O.
    femdnum1_t res;
    res = femdnum1_empty_like( rhs);

    femdnum1_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sum_rf(coeff_t lhs, femdnum1_t* rhs){
    
    // Perform r + O.
    femdnum1_t res;

    res = femdnum1_empty_like( rhs);

    femdnum1_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum1_sum_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum1_dimCheck( lhs, rhs );
    femdnum1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum1_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sum_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sum_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum1_t femdnum1_sub_ff(femdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform O + O.
    femdnum1_t res;

    res = femdnum1_empty_like( lhs);

    femdnum1_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sub_of(mdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform o + O.
    femdnum1_t res;
    res = femdnum1_empty_like( rhs);

    femdnum1_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sub_fo(femdnum1_t* lhs, mdnum1_t* rhs){
    
    // Perform o + O.
    femdnum1_t res;
    res = femdnum1_empty_like( lhs);

    femdnum1_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sub_rf(coeff_t lhs, femdnum1_t* rhs){
    
    // Perform r + O.
    femdnum1_t res;

    res = femdnum1_empty_like( rhs);

    femdnum1_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_sub_fr(femdnum1_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum1_t res;

    res = femdnum1_empty_like( lhs);

    femdnum1_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum1_sub_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum1_dimCheck( lhs, rhs );
    femdnum1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum1_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sub_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sub_fo_to(femdnum1_t* lhs, mdnum1_t* rhs, femdnum1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum1_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sub_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_sub_fr_to(femdnum1_t* lhs, coeff_t rhs, femdnum1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum1_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum1_t femdnum1_mul_ff(femdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform O + O.
    femdnum1_t res;

    res = femdnum1_empty_like( lhs);

    femdnum1_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_mul_of(mdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform o + O.
    femdnum1_t res;
    res = femdnum1_empty_like( rhs);

    femdnum1_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_mul_rf(coeff_t lhs, femdnum1_t* rhs){
    
    // Perform r + O.
    femdnum1_t res;

    res = femdnum1_empty_like( rhs);

    femdnum1_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum1_mul_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum1_dimCheck( lhs, rhs );
    femdnum1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum1_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_mul_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_mul_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum1_t femdnum1_div_ff(femdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform O + O.
    femdnum1_t res;

    res = femdnum1_empty_like( lhs);

    femdnum1_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_div_of(mdnum1_t* lhs, femdnum1_t* rhs){
    
    // Perform o + O.
    femdnum1_t res;
    res = femdnum1_empty_like( rhs);

    femdnum1_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_div_fo(femdnum1_t* lhs, mdnum1_t* rhs){
    
    // Perform o + O.
    femdnum1_t res;
    res = femdnum1_empty_like( lhs);

    femdnum1_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_div_rf(coeff_t lhs, femdnum1_t* rhs){
    
    // Perform r + O.
    femdnum1_t res;

    res = femdnum1_empty_like( rhs);

    femdnum1_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdnum1_div_fr(femdnum1_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum1_t res;

    res = femdnum1_empty_like( lhs);

    femdnum1_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum1_div_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum1_dimCheck( lhs, rhs );
    femdnum1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum1_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_div_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_div_fo_to(femdnum1_t* lhs, mdnum1_t* rhs, femdnum1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum1_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_div_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum1_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum1_div_fr_to(femdnum1_t* lhs, coeff_t rhs, femdnum1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum1_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

