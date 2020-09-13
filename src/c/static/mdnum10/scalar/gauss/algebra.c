

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum10_t femdnum10_neg(femdnum10_t* num){

    femdnum10_t res = femdnum10_empty_like( num);

    femdnum10_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_neg_to(femdnum10_t* num, femdnum10_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum10_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum10_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum10_t femdnum10_sum_ff(femdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform O + O.
    femdnum10_t res;

    res = femdnum10_empty_like( lhs);

    femdnum10_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sum_of(mdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform o + O.
    femdnum10_t res;
    res = femdnum10_empty_like( rhs);

    femdnum10_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sum_rf(coeff_t lhs, femdnum10_t* rhs){
    
    // Perform r + O.
    femdnum10_t res;

    res = femdnum10_empty_like( rhs);

    femdnum10_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum10_sum_ff_to(femdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum10_dimCheck( lhs, rhs );
    femdnum10_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum10_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sum_of_to(mdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sum_rf_to(coeff_t lhs, femdnum10_t* rhs, femdnum10_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum10_t femdnum10_sub_ff(femdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform O + O.
    femdnum10_t res;

    res = femdnum10_empty_like( lhs);

    femdnum10_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sub_of(mdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform o + O.
    femdnum10_t res;
    res = femdnum10_empty_like( rhs);

    femdnum10_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sub_fo(femdnum10_t* lhs, mdnum10_t* rhs){
    
    // Perform o + O.
    femdnum10_t res;
    res = femdnum10_empty_like( lhs);

    femdnum10_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sub_rf(coeff_t lhs, femdnum10_t* rhs){
    
    // Perform r + O.
    femdnum10_t res;

    res = femdnum10_empty_like( rhs);

    femdnum10_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_sub_fr(femdnum10_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum10_t res;

    res = femdnum10_empty_like( lhs);

    femdnum10_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum10_sub_ff_to(femdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum10_dimCheck( lhs, rhs );
    femdnum10_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum10_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sub_of_to(mdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sub_fo_to(femdnum10_t* lhs, mdnum10_t* rhs, femdnum10_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum10_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sub_rf_to(coeff_t lhs, femdnum10_t* rhs, femdnum10_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_sub_fr_to(femdnum10_t* lhs, coeff_t rhs, femdnum10_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum10_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum10_t femdnum10_mul_ff(femdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform O + O.
    femdnum10_t res;

    res = femdnum10_empty_like( lhs);

    femdnum10_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_mul_of(mdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform o + O.
    femdnum10_t res;
    res = femdnum10_empty_like( rhs);

    femdnum10_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_mul_rf(coeff_t lhs, femdnum10_t* rhs){
    
    // Perform r + O.
    femdnum10_t res;

    res = femdnum10_empty_like( rhs);

    femdnum10_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum10_mul_ff_to(femdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum10_dimCheck( lhs, rhs );
    femdnum10_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum10_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_mul_of_to(mdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_mul_rf_to(coeff_t lhs, femdnum10_t* rhs, femdnum10_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum10_t femdnum10_div_ff(femdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform O + O.
    femdnum10_t res;

    res = femdnum10_empty_like( lhs);

    femdnum10_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_div_of(mdnum10_t* lhs, femdnum10_t* rhs){
    
    // Perform o + O.
    femdnum10_t res;
    res = femdnum10_empty_like( rhs);

    femdnum10_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_div_fo(femdnum10_t* lhs, mdnum10_t* rhs){
    
    // Perform o + O.
    femdnum10_t res;
    res = femdnum10_empty_like( lhs);

    femdnum10_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_div_rf(coeff_t lhs, femdnum10_t* rhs){
    
    // Perform r + O.
    femdnum10_t res;

    res = femdnum10_empty_like( rhs);

    femdnum10_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_div_fr(femdnum10_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum10_t res;

    res = femdnum10_empty_like( lhs);

    femdnum10_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum10_div_ff_to(femdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum10_dimCheck( lhs, rhs );
    femdnum10_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum10_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_div_of_to(mdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_div_fo_to(femdnum10_t* lhs, mdnum10_t* rhs, femdnum10_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum10_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_div_rf_to(coeff_t lhs, femdnum10_t* rhs, femdnum10_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum10_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_div_fr_to(femdnum10_t* lhs, coeff_t rhs, femdnum10_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum10_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum10_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

