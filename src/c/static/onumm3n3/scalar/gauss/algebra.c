

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm3n3_t feonumm3n3_neg(feonumm3n3_t* num){

    feonumm3n3_t res = feonumm3n3_empty_like( num);

    feonumm3n3_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_neg_to(feonumm3n3_t* num, feonumm3n3_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm3n3_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm3n3_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sum_ff(feonumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform O + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sum_of(onumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform o + O.
    feonumm3n3_t res;
    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sum_rf(coeff_t lhs, feonumm3n3_t* rhs){
    
    // Perform r + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm3n3_sum_ff_to(feonumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm3n3_dimCheck( lhs, rhs );
    feonumm3n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm3n3_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_sum_of_to(onumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_sum_rf_to(coeff_t lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sub_ff(feonumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform O + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sub_of(onumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform o + O.
    feonumm3n3_t res;
    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sub_fo(feonumm3n3_t* lhs, onumm3n3_t* rhs){
    
    // Perform o + O.
    feonumm3n3_t res;
    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sub_rf(coeff_t lhs, feonumm3n3_t* rhs){
    
    // Perform r + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_sub_fr(feonumm3n3_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm3n3_sub_ff_to(feonumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm3n3_dimCheck( lhs, rhs );
    feonumm3n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm3n3_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_sub_of_to(onumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_sub_fo_to(feonumm3n3_t* lhs, onumm3n3_t* rhs, feonumm3n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm3n3_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_sub_rf_to(coeff_t lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_sub_fr_to(feonumm3n3_t* lhs, coeff_t rhs, feonumm3n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm3n3_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm3n3_t feonumm3n3_mul_ff(feonumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform O + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_mul_of(onumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform o + O.
    feonumm3n3_t res;
    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_mul_rf(coeff_t lhs, feonumm3n3_t* rhs){
    
    // Perform r + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm3n3_mul_ff_to(feonumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm3n3_dimCheck( lhs, rhs );
    feonumm3n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm3n3_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_mul_of_to(onumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_mul_rf_to(coeff_t lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm3n3_t feonumm3n3_div_ff(feonumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform O + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_div_of(onumm3n3_t* lhs, feonumm3n3_t* rhs){
    
    // Perform o + O.
    feonumm3n3_t res;
    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_div_fo(feonumm3n3_t* lhs, onumm3n3_t* rhs){
    
    // Perform o + O.
    feonumm3n3_t res;
    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_div_rf(coeff_t lhs, feonumm3n3_t* rhs){
    
    // Perform r + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( rhs);

    feonumm3n3_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feonumm3n3_div_fr(feonumm3n3_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm3n3_t res;

    res = feonumm3n3_empty_like( lhs);

    feonumm3n3_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm3n3_div_ff_to(feonumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm3n3_dimCheck( lhs, rhs );
    feonumm3n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm3n3_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_div_of_to(onumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_div_fo_to(feonumm3n3_t* lhs, onumm3n3_t* rhs, feonumm3n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm3n3_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_div_rf_to(coeff_t lhs, feonumm3n3_t* rhs, feonumm3n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm3n3_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n3_div_fr_to(feonumm3n3_t* lhs, coeff_t rhs, feonumm3n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm3n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm3n3_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

