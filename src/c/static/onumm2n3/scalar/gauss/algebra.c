

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm2n3_t feonumm2n3_neg(feonumm2n3_t* num){

    feonumm2n3_t res = feonumm2n3_empty_like( num);

    feonumm2n3_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_neg_to(feonumm2n3_t* num, feonumm2n3_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm2n3_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm2n3_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sum_ff(feonumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform O + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sum_of(onumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform o + O.
    feonumm2n3_t res;
    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sum_rf(coeff_t lhs, feonumm2n3_t* rhs){
    
    // Perform r + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm2n3_sum_ff_to(feonumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm2n3_dimCheck( lhs, rhs );
    feonumm2n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm2n3_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_sum_of_to(onumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_sum_rf_to(coeff_t lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sub_ff(feonumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform O + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sub_of(onumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform o + O.
    feonumm2n3_t res;
    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sub_fo(feonumm2n3_t* lhs, onumm2n3_t* rhs){
    
    // Perform o + O.
    feonumm2n3_t res;
    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sub_rf(coeff_t lhs, feonumm2n3_t* rhs){
    
    // Perform r + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_sub_fr(feonumm2n3_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm2n3_sub_ff_to(feonumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm2n3_dimCheck( lhs, rhs );
    feonumm2n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm2n3_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_sub_of_to(onumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_sub_fo_to(feonumm2n3_t* lhs, onumm2n3_t* rhs, feonumm2n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm2n3_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_sub_rf_to(coeff_t lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_sub_fr_to(feonumm2n3_t* lhs, coeff_t rhs, feonumm2n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm2n3_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm2n3_t feonumm2n3_mul_ff(feonumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform O + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_mul_of(onumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform o + O.
    feonumm2n3_t res;
    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_mul_rf(coeff_t lhs, feonumm2n3_t* rhs){
    
    // Perform r + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm2n3_mul_ff_to(feonumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm2n3_dimCheck( lhs, rhs );
    feonumm2n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm2n3_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_mul_of_to(onumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_mul_rf_to(coeff_t lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm2n3_t feonumm2n3_div_ff(feonumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform O + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_div_of(onumm2n3_t* lhs, feonumm2n3_t* rhs){
    
    // Perform o + O.
    feonumm2n3_t res;
    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_div_fo(feonumm2n3_t* lhs, onumm2n3_t* rhs){
    
    // Perform o + O.
    feonumm2n3_t res;
    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_div_rf(coeff_t lhs, feonumm2n3_t* rhs){
    
    // Perform r + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( rhs);

    feonumm2n3_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n3_t feonumm2n3_div_fr(feonumm2n3_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm2n3_t res;

    res = feonumm2n3_empty_like( lhs);

    feonumm2n3_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm2n3_div_ff_to(feonumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm2n3_dimCheck( lhs, rhs );
    feonumm2n3_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm2n3_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_div_of_to(onumm2n3_t* lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_div_fo_to(feonumm2n3_t* lhs, onumm2n3_t* rhs, feonumm2n3_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm2n3_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_div_rf_to(coeff_t lhs, feonumm2n3_t* rhs, feonumm2n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm2n3_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n3_div_fr_to(feonumm2n3_t* lhs, coeff_t rhs, feonumm2n3_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm2n3_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm2n3_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

