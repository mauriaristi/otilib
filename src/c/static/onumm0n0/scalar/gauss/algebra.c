

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm0n0_t feonumm0n0_neg(feonumm0n0_t* num){

    feonumm0n0_t res = feonumm0n0_empty_like( num);

    feonumm0n0_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_neg_to(feonumm0n0_t* num, feonumm0n0_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm0n0_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm0n0_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sum_ff(feonumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform O + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sum_of(onumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform o + O.
    feonumm0n0_t res;
    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sum_rf(coeff_t lhs, feonumm0n0_t* rhs){
    
    // Perform r + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm0n0_sum_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm0n0_dimCheck( lhs, rhs );
    feonumm0n0_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm0n0_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_sum_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_sum_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sub_ff(feonumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform O + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sub_of(onumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform o + O.
    feonumm0n0_t res;
    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sub_fo(feonumm0n0_t* lhs, onumm0n0_t* rhs){
    
    // Perform o + O.
    feonumm0n0_t res;
    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sub_rf(coeff_t lhs, feonumm0n0_t* rhs){
    
    // Perform r + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_sub_fr(feonumm0n0_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm0n0_sub_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm0n0_dimCheck( lhs, rhs );
    feonumm0n0_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm0n0_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_sub_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_sub_fo_to(feonumm0n0_t* lhs, onumm0n0_t* rhs, feonumm0n0_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm0n0_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_sub_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_sub_fr_to(feonumm0n0_t* lhs, coeff_t rhs, feonumm0n0_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm0n0_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm0n0_t feonumm0n0_mul_ff(feonumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform O + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_mul_of(onumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform o + O.
    feonumm0n0_t res;
    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_mul_rf(coeff_t lhs, feonumm0n0_t* rhs){
    
    // Perform r + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm0n0_mul_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm0n0_dimCheck( lhs, rhs );
    feonumm0n0_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm0n0_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_mul_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_mul_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm0n0_t feonumm0n0_div_ff(feonumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform O + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_div_of(onumm0n0_t* lhs, feonumm0n0_t* rhs){
    
    // Perform o + O.
    feonumm0n0_t res;
    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_div_fo(feonumm0n0_t* lhs, onumm0n0_t* rhs){
    
    // Perform o + O.
    feonumm0n0_t res;
    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_div_rf(coeff_t lhs, feonumm0n0_t* rhs){
    
    // Perform r + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( rhs);

    feonumm0n0_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feonumm0n0_div_fr(feonumm0n0_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm0n0_t res;

    res = feonumm0n0_empty_like( lhs);

    feonumm0n0_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm0n0_div_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm0n0_dimCheck( lhs, rhs );
    feonumm0n0_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm0n0_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_div_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_div_fo_to(feonumm0n0_t* lhs, onumm0n0_t* rhs, feonumm0n0_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm0n0_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_div_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm0n0_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_div_fr_to(feonumm0n0_t* lhs, coeff_t rhs, feonumm0n0_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm0n0_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm0n0_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

