

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum8_t femdnum8_neg(femdnum8_t* num){

    femdnum8_t res = femdnum8_empty_like( num);

    femdnum8_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_neg_to(femdnum8_t* num, femdnum8_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum8_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum8_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum8_t femdnum8_sum_ff(femdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform O + O.
    femdnum8_t res;

    res = femdnum8_empty_like( lhs);

    femdnum8_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sum_of(mdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform o + O.
    femdnum8_t res;
    res = femdnum8_empty_like( rhs);

    femdnum8_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sum_rf(coeff_t lhs, femdnum8_t* rhs){
    
    // Perform r + O.
    femdnum8_t res;

    res = femdnum8_empty_like( rhs);

    femdnum8_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum8_sum_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum8_dimCheck( lhs, rhs );
    femdnum8_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum8_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sum_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sum_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum8_t femdnum8_sub_ff(femdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform O + O.
    femdnum8_t res;

    res = femdnum8_empty_like( lhs);

    femdnum8_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sub_of(mdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform o + O.
    femdnum8_t res;
    res = femdnum8_empty_like( rhs);

    femdnum8_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sub_fo(femdnum8_t* lhs, mdnum8_t* rhs){
    
    // Perform o + O.
    femdnum8_t res;
    res = femdnum8_empty_like( lhs);

    femdnum8_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sub_rf(coeff_t lhs, femdnum8_t* rhs){
    
    // Perform r + O.
    femdnum8_t res;

    res = femdnum8_empty_like( rhs);

    femdnum8_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_sub_fr(femdnum8_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum8_t res;

    res = femdnum8_empty_like( lhs);

    femdnum8_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum8_sub_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum8_dimCheck( lhs, rhs );
    femdnum8_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum8_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sub_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sub_fo_to(femdnum8_t* lhs, mdnum8_t* rhs, femdnum8_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum8_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sub_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_sub_fr_to(femdnum8_t* lhs, coeff_t rhs, femdnum8_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum8_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum8_t femdnum8_mul_ff(femdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform O + O.
    femdnum8_t res;

    res = femdnum8_empty_like( lhs);

    femdnum8_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_mul_of(mdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform o + O.
    femdnum8_t res;
    res = femdnum8_empty_like( rhs);

    femdnum8_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_mul_rf(coeff_t lhs, femdnum8_t* rhs){
    
    // Perform r + O.
    femdnum8_t res;

    res = femdnum8_empty_like( rhs);

    femdnum8_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum8_mul_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum8_dimCheck( lhs, rhs );
    femdnum8_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum8_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_mul_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_mul_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum8_t femdnum8_div_ff(femdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform O + O.
    femdnum8_t res;

    res = femdnum8_empty_like( lhs);

    femdnum8_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_div_of(mdnum8_t* lhs, femdnum8_t* rhs){
    
    // Perform o + O.
    femdnum8_t res;
    res = femdnum8_empty_like( rhs);

    femdnum8_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_div_fo(femdnum8_t* lhs, mdnum8_t* rhs){
    
    // Perform o + O.
    femdnum8_t res;
    res = femdnum8_empty_like( lhs);

    femdnum8_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_div_rf(coeff_t lhs, femdnum8_t* rhs){
    
    // Perform r + O.
    femdnum8_t res;

    res = femdnum8_empty_like( rhs);

    femdnum8_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_div_fr(femdnum8_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum8_t res;

    res = femdnum8_empty_like( lhs);

    femdnum8_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum8_div_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum8_dimCheck( lhs, rhs );
    femdnum8_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum8_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_div_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_div_fo_to(femdnum8_t* lhs, mdnum8_t* rhs, femdnum8_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum8_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_div_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum8_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_div_fr_to(femdnum8_t* lhs, coeff_t rhs, femdnum8_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum8_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum8_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

