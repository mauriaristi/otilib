

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
femdnum5_t femdnum5_neg(femdnum5_t* num){

    femdnum5_t res = femdnum5_empty_like( num);

    femdnum5_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_neg_to(femdnum5_t* num, femdnum5_t* res){

    uint64_t i;
    
    // Check dimensions
    femdnum5_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        mdnum5_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
femdnum5_t femdnum5_sum_ff(femdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform O + O.
    femdnum5_t res;

    res = femdnum5_empty_like( lhs);

    femdnum5_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sum_of(mdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform o + O.
    femdnum5_t res;
    res = femdnum5_empty_like( rhs);

    femdnum5_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sum_rf(coeff_t lhs, femdnum5_t* rhs){
    
    // Perform r + O.
    femdnum5_t res;

    res = femdnum5_empty_like( rhs);

    femdnum5_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void femdnum5_sum_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum5_dimCheck( lhs, rhs );
    femdnum5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum5_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sum_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sum_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
femdnum5_t femdnum5_sub_ff(femdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform O + O.
    femdnum5_t res;

    res = femdnum5_empty_like( lhs);

    femdnum5_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sub_of(mdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform o + O.
    femdnum5_t res;
    res = femdnum5_empty_like( rhs);

    femdnum5_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sub_fo(femdnum5_t* lhs, mdnum5_t* rhs){
    
    // Perform o + O.
    femdnum5_t res;
    res = femdnum5_empty_like( lhs);

    femdnum5_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sub_rf(coeff_t lhs, femdnum5_t* rhs){
    
    // Perform r + O.
    femdnum5_t res;

    res = femdnum5_empty_like( rhs);

    femdnum5_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_sub_fr(femdnum5_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum5_t res;

    res = femdnum5_empty_like( lhs);

    femdnum5_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void femdnum5_sub_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum5_dimCheck( lhs, rhs );
    femdnum5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum5_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sub_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sub_fo_to(femdnum5_t* lhs, mdnum5_t* rhs, femdnum5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum5_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sub_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_sub_fr_to(femdnum5_t* lhs, coeff_t rhs, femdnum5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum5_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
femdnum5_t femdnum5_mul_ff(femdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform O + O.
    femdnum5_t res;

    res = femdnum5_empty_like( lhs);

    femdnum5_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_mul_of(mdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform o + O.
    femdnum5_t res;
    res = femdnum5_empty_like( rhs);

    femdnum5_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_mul_rf(coeff_t lhs, femdnum5_t* rhs){
    
    // Perform r + O.
    femdnum5_t res;

    res = femdnum5_empty_like( rhs);

    femdnum5_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void femdnum5_mul_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum5_dimCheck( lhs, rhs );
    femdnum5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum5_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_mul_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_mul_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
femdnum5_t femdnum5_div_ff(femdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform O + O.
    femdnum5_t res;

    res = femdnum5_empty_like( lhs);

    femdnum5_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_div_of(mdnum5_t* lhs, femdnum5_t* rhs){
    
    // Perform o + O.
    femdnum5_t res;
    res = femdnum5_empty_like( rhs);

    femdnum5_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_div_fo(femdnum5_t* lhs, mdnum5_t* rhs){
    
    // Perform o + O.
    femdnum5_t res;
    res = femdnum5_empty_like( lhs);

    femdnum5_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_div_rf(coeff_t lhs, femdnum5_t* rhs){
    
    // Perform r + O.
    femdnum5_t res;

    res = femdnum5_empty_like( rhs);

    femdnum5_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdnum5_div_fr(femdnum5_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    femdnum5_t res;

    res = femdnum5_empty_like( lhs);

    femdnum5_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void femdnum5_div_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    femdnum5_dimCheck( lhs, rhs );
    femdnum5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        mdnum5_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_div_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_div_fo_to(femdnum5_t* lhs, mdnum5_t* rhs, femdnum5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum5_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_div_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        mdnum5_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum5_div_fr_to(femdnum5_t* lhs, coeff_t rhs, femdnum5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    femdnum5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        mdnum5_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

