

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum9_t femdnum9_neg(femdnum9_t* num){

    femdnum9_t res = femdnum9_empty_like( num);

    femdnum9_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_neg_to(femdnum9_t* num, femdnum9_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum9_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum9_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum9_t femdnum9_sum_ff(femdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform O + O.
    femdnum9_t res;

    res = femdnum9_empty_like( lhs);

    femdnum9_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sum_of(mdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform o + O.
    femdnum9_t res;
    res = femdnum9_empty_like( rhs);

    femdnum9_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sum_rf(coeff_t lhs, femdnum9_t* rhs){
    
    // Perform r + O.
    femdnum9_t res;

    res = femdnum9_empty_like( rhs);

    femdnum9_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum9_sum_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum9_dimCheck( lhs, rhs );
    femdnum9_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum9_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sum_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sum_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum9_t femdnum9_sub_ff(femdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform O + O.
    femdnum9_t res;

    res = femdnum9_empty_like( lhs);

    femdnum9_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sub_of(mdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform o + O.
    femdnum9_t res;
    res = femdnum9_empty_like( rhs);

    femdnum9_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sub_fo(femdnum9_t* lhs, mdnum9_t* rhs){
    
    // Perform o + O.
    femdnum9_t res;
    res = femdnum9_empty_like( lhs);

    femdnum9_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sub_rf(coeff_t lhs, femdnum9_t* rhs){
    
    // Perform r + O.
    femdnum9_t res;

    res = femdnum9_empty_like( rhs);

    femdnum9_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_sub_fr(femdnum9_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum9_t res;

    res = femdnum9_empty_like( lhs);

    femdnum9_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum9_sub_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum9_dimCheck( lhs, rhs );
    femdnum9_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum9_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sub_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sub_fo_to(femdnum9_t* lhs, mdnum9_t* rhs, femdnum9_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum9_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sub_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_sub_fr_to(femdnum9_t* lhs, coeff_t rhs, femdnum9_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum9_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum9_t femdnum9_mul_ff(femdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform O + O.
    femdnum9_t res;

    res = femdnum9_empty_like( lhs);

    femdnum9_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_mul_of(mdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform o + O.
    femdnum9_t res;
    res = femdnum9_empty_like( rhs);

    femdnum9_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_mul_rf(coeff_t lhs, femdnum9_t* rhs){
    
    // Perform r + O.
    femdnum9_t res;

    res = femdnum9_empty_like( rhs);

    femdnum9_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum9_mul_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum9_dimCheck( lhs, rhs );
    femdnum9_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum9_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_mul_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_mul_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum9_t femdnum9_div_ff(femdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform O + O.
    femdnum9_t res;

    res = femdnum9_empty_like( lhs);

    femdnum9_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_div_of(mdnum9_t* lhs, femdnum9_t* rhs){
    
    // Perform o + O.
    femdnum9_t res;
    res = femdnum9_empty_like( rhs);

    femdnum9_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_div_fo(femdnum9_t* lhs, mdnum9_t* rhs){
    
    // Perform o + O.
    femdnum9_t res;
    res = femdnum9_empty_like( lhs);

    femdnum9_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_div_rf(coeff_t lhs, femdnum9_t* rhs){
    
    // Perform r + O.
    femdnum9_t res;

    res = femdnum9_empty_like( rhs);

    femdnum9_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdnum9_div_fr(femdnum9_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum9_t res;

    res = femdnum9_empty_like( lhs);

    femdnum9_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum9_div_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum9_dimCheck( lhs, rhs );
    femdnum9_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum9_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_div_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_div_fo_to(femdnum9_t* lhs, mdnum9_t* rhs, femdnum9_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum9_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_div_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum9_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum9_div_fr_to(femdnum9_t* lhs, coeff_t rhs, femdnum9_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum9_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum9_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

