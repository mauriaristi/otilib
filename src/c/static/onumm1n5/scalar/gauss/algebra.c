

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm1n5_t feonumm1n5_neg(feonumm1n5_t* num){

    feonumm1n5_t res = feonumm1n5_empty_like( num);

    feonumm1n5_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_neg_to(feonumm1n5_t* num, feonumm1n5_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm1n5_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm1n5_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sum_ff(feonumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform O + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sum_of(onumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform o + O.
    feonumm1n5_t res;
    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sum_rf(coeff_t lhs, feonumm1n5_t* rhs){
    
    // Perform r + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm1n5_sum_ff_to(feonumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm1n5_dimCheck( lhs, rhs );
    feonumm1n5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm1n5_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_sum_of_to(onumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_sum_rf_to(coeff_t lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sub_ff(feonumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform O + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sub_of(onumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform o + O.
    feonumm1n5_t res;
    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sub_fo(feonumm1n5_t* lhs, onumm1n5_t* rhs){
    
    // Perform o + O.
    feonumm1n5_t res;
    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sub_rf(coeff_t lhs, feonumm1n5_t* rhs){
    
    // Perform r + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_sub_fr(feonumm1n5_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm1n5_sub_ff_to(feonumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm1n5_dimCheck( lhs, rhs );
    feonumm1n5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm1n5_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_sub_of_to(onumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_sub_fo_to(feonumm1n5_t* lhs, onumm1n5_t* rhs, feonumm1n5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm1n5_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_sub_rf_to(coeff_t lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_sub_fr_to(feonumm1n5_t* lhs, coeff_t rhs, feonumm1n5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm1n5_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm1n5_t feonumm1n5_mul_ff(feonumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform O + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_mul_of(onumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform o + O.
    feonumm1n5_t res;
    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_mul_rf(coeff_t lhs, feonumm1n5_t* rhs){
    
    // Perform r + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm1n5_mul_ff_to(feonumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm1n5_dimCheck( lhs, rhs );
    feonumm1n5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm1n5_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_mul_of_to(onumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_mul_rf_to(coeff_t lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm1n5_t feonumm1n5_div_ff(feonumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform O + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_div_of(onumm1n5_t* lhs, feonumm1n5_t* rhs){
    
    // Perform o + O.
    feonumm1n5_t res;
    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_div_fo(feonumm1n5_t* lhs, onumm1n5_t* rhs){
    
    // Perform o + O.
    feonumm1n5_t res;
    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_div_rf(coeff_t lhs, feonumm1n5_t* rhs){
    
    // Perform r + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( rhs);

    feonumm1n5_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n5_t feonumm1n5_div_fr(feonumm1n5_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm1n5_t res;

    res = feonumm1n5_empty_like( lhs);

    feonumm1n5_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm1n5_div_ff_to(feonumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm1n5_dimCheck( lhs, rhs );
    feonumm1n5_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm1n5_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_div_of_to(onumm1n5_t* lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_div_fo_to(feonumm1n5_t* lhs, onumm1n5_t* rhs, feonumm1n5_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm1n5_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_div_rf_to(coeff_t lhs, feonumm1n5_t* rhs, feonumm1n5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm1n5_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n5_div_fr_to(feonumm1n5_t* lhs, coeff_t rhs, feonumm1n5_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm1n5_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm1n5_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

