

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum6_t femdnum6_neg(femdnum6_t* num){

    femdnum6_t res = femdnum6_empty_like( num);

    femdnum6_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_neg_to(femdnum6_t* num, femdnum6_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum6_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum6_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum6_t femdnum6_sum_ff(femdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform O + O.
    femdnum6_t res;

    res = femdnum6_empty_like( lhs);

    femdnum6_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sum_of(mdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform o + O.
    femdnum6_t res;
    res = femdnum6_empty_like( rhs);

    femdnum6_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sum_rf(coeff_t lhs, femdnum6_t* rhs){
    
    // Perform r + O.
    femdnum6_t res;

    res = femdnum6_empty_like( rhs);

    femdnum6_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum6_sum_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum6_dimCheck( lhs, rhs );
    femdnum6_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum6_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sum_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sum_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum6_t femdnum6_sub_ff(femdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform O + O.
    femdnum6_t res;

    res = femdnum6_empty_like( lhs);

    femdnum6_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sub_of(mdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform o + O.
    femdnum6_t res;
    res = femdnum6_empty_like( rhs);

    femdnum6_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sub_fo(femdnum6_t* lhs, mdnum6_t* rhs){
    
    // Perform o + O.
    femdnum6_t res;
    res = femdnum6_empty_like( lhs);

    femdnum6_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sub_rf(coeff_t lhs, femdnum6_t* rhs){
    
    // Perform r + O.
    femdnum6_t res;

    res = femdnum6_empty_like( rhs);

    femdnum6_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_sub_fr(femdnum6_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum6_t res;

    res = femdnum6_empty_like( lhs);

    femdnum6_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum6_sub_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum6_dimCheck( lhs, rhs );
    femdnum6_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum6_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sub_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sub_fo_to(femdnum6_t* lhs, mdnum6_t* rhs, femdnum6_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum6_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sub_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_sub_fr_to(femdnum6_t* lhs, coeff_t rhs, femdnum6_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum6_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum6_t femdnum6_mul_ff(femdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform O + O.
    femdnum6_t res;

    res = femdnum6_empty_like( lhs);

    femdnum6_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_mul_of(mdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform o + O.
    femdnum6_t res;
    res = femdnum6_empty_like( rhs);

    femdnum6_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_mul_rf(coeff_t lhs, femdnum6_t* rhs){
    
    // Perform r + O.
    femdnum6_t res;

    res = femdnum6_empty_like( rhs);

    femdnum6_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum6_mul_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum6_dimCheck( lhs, rhs );
    femdnum6_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum6_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_mul_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_mul_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum6_t femdnum6_div_ff(femdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform O + O.
    femdnum6_t res;

    res = femdnum6_empty_like( lhs);

    femdnum6_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_div_of(mdnum6_t* lhs, femdnum6_t* rhs){
    
    // Perform o + O.
    femdnum6_t res;
    res = femdnum6_empty_like( rhs);

    femdnum6_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_div_fo(femdnum6_t* lhs, mdnum6_t* rhs){
    
    // Perform o + O.
    femdnum6_t res;
    res = femdnum6_empty_like( lhs);

    femdnum6_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_div_rf(coeff_t lhs, femdnum6_t* rhs){
    
    // Perform r + O.
    femdnum6_t res;

    res = femdnum6_empty_like( rhs);

    femdnum6_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_div_fr(femdnum6_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum6_t res;

    res = femdnum6_empty_like( lhs);

    femdnum6_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum6_div_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum6_dimCheck( lhs, rhs );
    femdnum6_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum6_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_div_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_div_fo_to(femdnum6_t* lhs, mdnum6_t* rhs, femdnum6_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum6_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_div_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum6_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_div_fr_to(femdnum6_t* lhs, coeff_t rhs, femdnum6_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum6_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum6_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

