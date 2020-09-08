

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
feonumm8n2_t feonumm8n2_neg(feonumm8n2_t* num){

    feonumm8n2_t res = feonumm8n2_empty_like( num);

    feonumm8n2_neg_to(num,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_neg_to(feonumm8n2_t* num, feonumm8n2_t* res){

    uint64_t i;
    
    // Check dimensions
    feonumm8n2_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        onumm8n2_neg_to( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sum_ff(feonumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform O + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_sum_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sum_of(onumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform o + O.
    feonumm8n2_t res;
    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_sum_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sum_rf(coeff_t lhs, feonumm8n2_t* rhs){
    
    // Perform r + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_sum_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void feonumm8n2_sum_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm8n2_dimCheck( lhs, rhs );
    feonumm8n2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm8n2_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_sum_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_sum_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sub_ff(feonumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform O + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_sub_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sub_of(onumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform o + O.
    feonumm8n2_t res;
    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_sub_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sub_fo(feonumm8n2_t* lhs, onumm8n2_t* rhs){
    
    // Perform o + O.
    feonumm8n2_t res;
    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_sub_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sub_rf(coeff_t lhs, feonumm8n2_t* rhs){
    
    // Perform r + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_sub_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_sub_fr(feonumm8n2_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_sub_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void feonumm8n2_sub_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm8n2_dimCheck( lhs, rhs );
    feonumm8n2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm8n2_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_sub_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_sub_fo_to(feonumm8n2_t* lhs, onumm8n2_t* rhs, feonumm8n2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm8n2_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_sub_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_sub_fr_to(feonumm8n2_t* lhs, coeff_t rhs, feonumm8n2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm8n2_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
feonumm8n2_t feonumm8n2_mul_ff(feonumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform O + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_mul_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_mul_of(onumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform o + O.
    feonumm8n2_t res;
    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_mul_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_mul_rf(coeff_t lhs, feonumm8n2_t* rhs){
    
    // Perform r + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_mul_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void feonumm8n2_mul_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm8n2_dimCheck( lhs, rhs );
    feonumm8n2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm8n2_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_mul_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_mul_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
feonumm8n2_t feonumm8n2_div_ff(feonumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform O + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_div_ff_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_div_of(onumm8n2_t* lhs, feonumm8n2_t* rhs){
    
    // Perform o + O.
    feonumm8n2_t res;
    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_div_of_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_div_fo(feonumm8n2_t* lhs, onumm8n2_t* rhs){
    
    // Perform o + O.
    feonumm8n2_t res;
    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_div_fo_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_div_rf(coeff_t lhs, feonumm8n2_t* rhs){
    
    // Perform r + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( rhs);

    feonumm8n2_div_rf_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n2_t feonumm8n2_div_fr(feonumm8n2_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    feonumm8n2_t res;

    res = feonumm8n2_empty_like( lhs);

    feonumm8n2_div_fr_to( lhs, rhs, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void feonumm8n2_div_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    feonumm8n2_dimCheck( lhs, rhs );
    feonumm8n2_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        onumm8n2_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_div_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_div_fo_to(feonumm8n2_t* lhs, onumm8n2_t* rhs, feonumm8n2_t* res){
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm8n2_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_div_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        onumm8n2_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm8n2_div_fr_to(feonumm8n2_t* lhs, coeff_t rhs, feonumm8n2_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    feonumm8n2_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        onumm8n2_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }

}
// ----------------------------------------------------------------------------------------------------

