

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm20n1_t feonumm20n1_neg(feonumm20n1_t* num){

    feonumm20n1_t res = feonumm20n1_empty_like( num);

    feonumm20n1_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_neg_to(feonumm20n1_t* num, feonumm20n1_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm20n1_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm20n1_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sum_ff(feonumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform O + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sum_of(onumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform o + O.
    feonumm20n1_t res;
    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sum_rf(coeff_t lhs, feonumm20n1_t* rhs){
    
    // Perform r + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm20n1_sum_ff_to(feonumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm20n1_dimCheck( lhs, rhs );
    feonumm20n1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm20n1_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_sum_of_to(onumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_sum_rf_to(coeff_t lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sub_ff(feonumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform O + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sub_of(onumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform o + O.
    feonumm20n1_t res;
    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sub_fo(feonumm20n1_t* lhs, onumm20n1_t* rhs){
    
    // Perform o + O.
    feonumm20n1_t res;
    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sub_rf(coeff_t lhs, feonumm20n1_t* rhs){
    
    // Perform r + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_sub_fr(feonumm20n1_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm20n1_sub_ff_to(feonumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm20n1_dimCheck( lhs, rhs );
    feonumm20n1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm20n1_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_sub_of_to(onumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_sub_fo_to(feonumm20n1_t* lhs, onumm20n1_t* rhs, feonumm20n1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm20n1_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_sub_rf_to(coeff_t lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_sub_fr_to(feonumm20n1_t* lhs, coeff_t rhs, feonumm20n1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm20n1_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm20n1_t feonumm20n1_mul_ff(feonumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform O + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_mul_of(onumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform o + O.
    feonumm20n1_t res;
    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_mul_rf(coeff_t lhs, feonumm20n1_t* rhs){
    
    // Perform r + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm20n1_mul_ff_to(feonumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm20n1_dimCheck( lhs, rhs );
    feonumm20n1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm20n1_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_mul_of_to(onumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_mul_rf_to(coeff_t lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm20n1_t feonumm20n1_div_ff(feonumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform O + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_div_of(onumm20n1_t* lhs, feonumm20n1_t* rhs){
    
    // Perform o + O.
    feonumm20n1_t res;
    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_div_fo(feonumm20n1_t* lhs, onumm20n1_t* rhs){
    
    // Perform o + O.
    feonumm20n1_t res;
    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_div_rf(coeff_t lhs, feonumm20n1_t* rhs){
    
    // Perform r + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( rhs);

    feonumm20n1_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feonumm20n1_div_fr(feonumm20n1_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm20n1_t res;

    res = feonumm20n1_empty_like( lhs);

    feonumm20n1_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm20n1_div_ff_to(feonumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm20n1_dimCheck( lhs, rhs );
    feonumm20n1_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm20n1_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_div_of_to(onumm20n1_t* lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_div_fo_to(feonumm20n1_t* lhs, onumm20n1_t* rhs, feonumm20n1_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm20n1_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_div_rf_to(coeff_t lhs, feonumm20n1_t* rhs, feonumm20n1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm20n1_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm20n1_div_fr_to(feonumm20n1_t* lhs, coeff_t rhs, feonumm20n1_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm20n1_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm20n1_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

