

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum4_t femdnum4_neg(femdnum4_t* num){

    femdnum4_t res = femdnum4_empty_like( num);

    femdnum4_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_neg_to(femdnum4_t* num, femdnum4_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum4_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum4_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum4_t femdnum4_sum_ff(femdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform O + O.
    femdnum4_t res;

    res = femdnum4_empty_like( lhs);

    femdnum4_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sum_of(mdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform o + O.
    femdnum4_t res;
    res = femdnum4_empty_like( rhs);

    femdnum4_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sum_rf(coeff_t lhs, femdnum4_t* rhs){
    
    // Perform r + O.
    femdnum4_t res;

    res = femdnum4_empty_like( rhs);

    femdnum4_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum4_sum_ff_to(femdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum4_dimCheck( lhs, rhs );
    femdnum4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum4_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sum_of_to(mdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sum_rf_to(coeff_t lhs, femdnum4_t* rhs, femdnum4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum4_t femdnum4_sub_ff(femdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform O + O.
    femdnum4_t res;

    res = femdnum4_empty_like( lhs);

    femdnum4_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sub_of(mdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform o + O.
    femdnum4_t res;
    res = femdnum4_empty_like( rhs);

    femdnum4_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sub_fo(femdnum4_t* lhs, mdnum4_t* rhs){
    
    // Perform o + O.
    femdnum4_t res;
    res = femdnum4_empty_like( lhs);

    femdnum4_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sub_rf(coeff_t lhs, femdnum4_t* rhs){
    
    // Perform r + O.
    femdnum4_t res;

    res = femdnum4_empty_like( rhs);

    femdnum4_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_sub_fr(femdnum4_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum4_t res;

    res = femdnum4_empty_like( lhs);

    femdnum4_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum4_sub_ff_to(femdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum4_dimCheck( lhs, rhs );
    femdnum4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum4_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sub_of_to(mdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sub_fo_to(femdnum4_t* lhs, mdnum4_t* rhs, femdnum4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum4_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sub_rf_to(coeff_t lhs, femdnum4_t* rhs, femdnum4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_sub_fr_to(femdnum4_t* lhs, coeff_t rhs, femdnum4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum4_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum4_t femdnum4_mul_ff(femdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform O + O.
    femdnum4_t res;

    res = femdnum4_empty_like( lhs);

    femdnum4_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_mul_of(mdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform o + O.
    femdnum4_t res;
    res = femdnum4_empty_like( rhs);

    femdnum4_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_mul_rf(coeff_t lhs, femdnum4_t* rhs){
    
    // Perform r + O.
    femdnum4_t res;

    res = femdnum4_empty_like( rhs);

    femdnum4_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum4_mul_ff_to(femdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum4_dimCheck( lhs, rhs );
    femdnum4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum4_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_mul_of_to(mdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_mul_rf_to(coeff_t lhs, femdnum4_t* rhs, femdnum4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum4_t femdnum4_div_ff(femdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform O + O.
    femdnum4_t res;

    res = femdnum4_empty_like( lhs);

    femdnum4_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_div_of(mdnum4_t* lhs, femdnum4_t* rhs){
    
    // Perform o + O.
    femdnum4_t res;
    res = femdnum4_empty_like( rhs);

    femdnum4_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_div_fo(femdnum4_t* lhs, mdnum4_t* rhs){
    
    // Perform o + O.
    femdnum4_t res;
    res = femdnum4_empty_like( lhs);

    femdnum4_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_div_rf(coeff_t lhs, femdnum4_t* rhs){
    
    // Perform r + O.
    femdnum4_t res;

    res = femdnum4_empty_like( rhs);

    femdnum4_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_div_fr(femdnum4_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum4_t res;

    res = femdnum4_empty_like( lhs);

    femdnum4_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum4_div_ff_to(femdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum4_dimCheck( lhs, rhs );
    femdnum4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum4_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_div_of_to(mdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_div_fo_to(femdnum4_t* lhs, mdnum4_t* rhs, femdnum4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum4_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_div_rf_to(coeff_t lhs, femdnum4_t* rhs, femdnum4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum4_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_div_fr_to(femdnum4_t* lhs, coeff_t rhs, femdnum4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum4_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

