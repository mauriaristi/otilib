

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum7_t femdnum7_neg(femdnum7_t* num){

    femdnum7_t res = femdnum7_empty_like( num);

    femdnum7_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_neg_to(femdnum7_t* num, femdnum7_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum7_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum7_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum7_t femdnum7_sum_ff(femdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform O + O.
    femdnum7_t res;

    res = femdnum7_empty_like( lhs);

    femdnum7_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sum_of(mdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform o + O.
    femdnum7_t res;
    res = femdnum7_empty_like( rhs);

    femdnum7_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sum_rf(coeff_t lhs, femdnum7_t* rhs){
    
    // Perform r + O.
    femdnum7_t res;

    res = femdnum7_empty_like( rhs);

    femdnum7_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum7_sum_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum7_dimCheck( lhs, rhs );
    femdnum7_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum7_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sum_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sum_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum7_t femdnum7_sub_ff(femdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform O + O.
    femdnum7_t res;

    res = femdnum7_empty_like( lhs);

    femdnum7_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sub_of(mdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform o + O.
    femdnum7_t res;
    res = femdnum7_empty_like( rhs);

    femdnum7_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sub_fo(femdnum7_t* lhs, mdnum7_t* rhs){
    
    // Perform o + O.
    femdnum7_t res;
    res = femdnum7_empty_like( lhs);

    femdnum7_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sub_rf(coeff_t lhs, femdnum7_t* rhs){
    
    // Perform r + O.
    femdnum7_t res;

    res = femdnum7_empty_like( rhs);

    femdnum7_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_sub_fr(femdnum7_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum7_t res;

    res = femdnum7_empty_like( lhs);

    femdnum7_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum7_sub_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum7_dimCheck( lhs, rhs );
    femdnum7_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum7_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sub_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sub_fo_to(femdnum7_t* lhs, mdnum7_t* rhs, femdnum7_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum7_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sub_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_sub_fr_to(femdnum7_t* lhs, coeff_t rhs, femdnum7_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum7_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum7_t femdnum7_mul_ff(femdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform O + O.
    femdnum7_t res;

    res = femdnum7_empty_like( lhs);

    femdnum7_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_mul_of(mdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform o + O.
    femdnum7_t res;
    res = femdnum7_empty_like( rhs);

    femdnum7_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_mul_rf(coeff_t lhs, femdnum7_t* rhs){
    
    // Perform r + O.
    femdnum7_t res;

    res = femdnum7_empty_like( rhs);

    femdnum7_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum7_mul_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum7_dimCheck( lhs, rhs );
    femdnum7_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum7_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_mul_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_mul_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum7_t femdnum7_div_ff(femdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform O + O.
    femdnum7_t res;

    res = femdnum7_empty_like( lhs);

    femdnum7_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_div_of(mdnum7_t* lhs, femdnum7_t* rhs){
    
    // Perform o + O.
    femdnum7_t res;
    res = femdnum7_empty_like( rhs);

    femdnum7_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_div_fo(femdnum7_t* lhs, mdnum7_t* rhs){
    
    // Perform o + O.
    femdnum7_t res;
    res = femdnum7_empty_like( lhs);

    femdnum7_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_div_rf(coeff_t lhs, femdnum7_t* rhs){
    
    // Perform r + O.
    femdnum7_t res;

    res = femdnum7_empty_like( rhs);

    femdnum7_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_div_fr(femdnum7_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum7_t res;

    res = femdnum7_empty_like( lhs);

    femdnum7_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum7_div_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum7_dimCheck( lhs, rhs );
    femdnum7_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum7_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_div_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_div_fo_to(femdnum7_t* lhs, mdnum7_t* rhs, femdnum7_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum7_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_div_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum7_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_div_fr_to(femdnum7_t* lhs, coeff_t rhs, femdnum7_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum7_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum7_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

