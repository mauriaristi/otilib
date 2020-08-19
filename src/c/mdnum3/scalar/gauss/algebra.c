

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum3_t femdnum3_neg(femdnum3_t* num){

    femdnum3_t res = femdnum3_empty_like( num);

    femdnum3_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_neg_to(femdnum3_t* num, femdnum3_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum3_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum3_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum3_t femdnum3_sum_ff(femdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform O + O.
    femdnum3_t res;

    res = femdnum3_empty_like( lhs);

    femdnum3_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sum_of(mdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform o + O.
    femdnum3_t res;
    res = femdnum3_empty_like( rhs);

    femdnum3_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sum_rf(coeff_t lhs, femdnum3_t* rhs){
    
    // Perform r + O.
    femdnum3_t res;

    res = femdnum3_empty_like( rhs);

    femdnum3_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum3_sum_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum3_dimCheck( lhs, rhs );
    femdnum3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum3_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sum_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sum_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum3_t femdnum3_sub_ff(femdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform O + O.
    femdnum3_t res;

    res = femdnum3_empty_like( lhs);

    femdnum3_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sub_of(mdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform o + O.
    femdnum3_t res;
    res = femdnum3_empty_like( rhs);

    femdnum3_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sub_fo(femdnum3_t* lhs, mdnum3_t* rhs){
    
    // Perform o + O.
    femdnum3_t res;
    res = femdnum3_empty_like( lhs);

    femdnum3_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sub_rf(coeff_t lhs, femdnum3_t* rhs){
    
    // Perform r + O.
    femdnum3_t res;

    res = femdnum3_empty_like( rhs);

    femdnum3_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_sub_fr(femdnum3_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum3_t res;

    res = femdnum3_empty_like( lhs);

    femdnum3_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum3_sub_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum3_dimCheck( lhs, rhs );
    femdnum3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum3_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sub_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sub_fo_to(femdnum3_t* lhs, mdnum3_t* rhs, femdnum3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum3_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sub_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_sub_fr_to(femdnum3_t* lhs, coeff_t rhs, femdnum3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum3_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum3_t femdnum3_mul_ff(femdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform O + O.
    femdnum3_t res;

    res = femdnum3_empty_like( lhs);

    femdnum3_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_mul_of(mdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform o + O.
    femdnum3_t res;
    res = femdnum3_empty_like( rhs);

    femdnum3_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_mul_rf(coeff_t lhs, femdnum3_t* rhs){
    
    // Perform r + O.
    femdnum3_t res;

    res = femdnum3_empty_like( rhs);

    femdnum3_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum3_mul_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum3_dimCheck( lhs, rhs );
    femdnum3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum3_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_mul_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_mul_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum3_t femdnum3_div_ff(femdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform O + O.
    femdnum3_t res;

    res = femdnum3_empty_like( lhs);

    femdnum3_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_div_of(mdnum3_t* lhs, femdnum3_t* rhs){
    
    // Perform o + O.
    femdnum3_t res;
    res = femdnum3_empty_like( rhs);

    femdnum3_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_div_fo(femdnum3_t* lhs, mdnum3_t* rhs){
    
    // Perform o + O.
    femdnum3_t res;
    res = femdnum3_empty_like( lhs);

    femdnum3_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_div_rf(coeff_t lhs, femdnum3_t* rhs){
    
    // Perform r + O.
    femdnum3_t res;

    res = femdnum3_empty_like( rhs);

    femdnum3_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_div_fr(femdnum3_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum3_t res;

    res = femdnum3_empty_like( lhs);

    femdnum3_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum3_div_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum3_dimCheck( lhs, rhs );
    femdnum3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum3_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_div_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_div_fo_to(femdnum3_t* lhs, mdnum3_t* rhs, femdnum3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum3_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_div_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum3_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_div_fr_to(femdnum3_t* lhs, coeff_t rhs, femdnum3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum3_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

