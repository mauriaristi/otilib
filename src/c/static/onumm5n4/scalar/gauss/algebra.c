

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm5n4_t feonumm5n4_neg(feonumm5n4_t* num){

    feonumm5n4_t res = feonumm5n4_empty_like( num);

    feonumm5n4_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_neg_to(feonumm5n4_t* num, feonumm5n4_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm5n4_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm5n4_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sum_ff(feonumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform O + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sum_of(onumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform o + O.
    feonumm5n4_t res;
    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sum_rf(coeff_t lhs, feonumm5n4_t* rhs){
    
    // Perform r + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm5n4_sum_ff_to(feonumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm5n4_dimCheck( lhs, rhs );
    feonumm5n4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm5n4_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_sum_of_to(onumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_sum_rf_to(coeff_t lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sub_ff(feonumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform O + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sub_of(onumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform o + O.
    feonumm5n4_t res;
    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sub_fo(feonumm5n4_t* lhs, onumm5n4_t* rhs){
    
    // Perform o + O.
    feonumm5n4_t res;
    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sub_rf(coeff_t lhs, feonumm5n4_t* rhs){
    
    // Perform r + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_sub_fr(feonumm5n4_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm5n4_sub_ff_to(feonumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm5n4_dimCheck( lhs, rhs );
    feonumm5n4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm5n4_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_sub_of_to(onumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_sub_fo_to(feonumm5n4_t* lhs, onumm5n4_t* rhs, feonumm5n4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm5n4_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_sub_rf_to(coeff_t lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_sub_fr_to(feonumm5n4_t* lhs, coeff_t rhs, feonumm5n4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm5n4_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm5n4_t feonumm5n4_mul_ff(feonumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform O + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_mul_of(onumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform o + O.
    feonumm5n4_t res;
    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_mul_rf(coeff_t lhs, feonumm5n4_t* rhs){
    
    // Perform r + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm5n4_mul_ff_to(feonumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm5n4_dimCheck( lhs, rhs );
    feonumm5n4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm5n4_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_mul_of_to(onumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_mul_rf_to(coeff_t lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm5n4_t feonumm5n4_div_ff(feonumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform O + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_div_of(onumm5n4_t* lhs, feonumm5n4_t* rhs){
    
    // Perform o + O.
    feonumm5n4_t res;
    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_div_fo(feonumm5n4_t* lhs, onumm5n4_t* rhs){
    
    // Perform o + O.
    feonumm5n4_t res;
    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_div_rf(coeff_t lhs, feonumm5n4_t* rhs){
    
    // Perform r + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( rhs);

    feonumm5n4_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feonumm5n4_div_fr(feonumm5n4_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm5n4_t res;

    res = feonumm5n4_empty_like( lhs);

    feonumm5n4_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm5n4_div_ff_to(feonumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm5n4_dimCheck( lhs, rhs );
    feonumm5n4_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm5n4_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_div_of_to(onumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_div_fo_to(feonumm5n4_t* lhs, onumm5n4_t* rhs, feonumm5n4_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm5n4_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_div_rf_to(coeff_t lhs, feonumm5n4_t* rhs, feonumm5n4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm5n4_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm5n4_div_fr_to(feonumm5n4_t* lhs, coeff_t rhs, feonumm5n4_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm5n4_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm5n4_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

