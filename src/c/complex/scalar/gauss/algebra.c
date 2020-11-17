

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
fecnum_t fecnum_neg(fecnum_t* num){

    fecnum_t res = fecnum_empty_like( num );

    fecnum_neg_to(num,&res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_neg_to(fecnum_t* num, fecnum_t* res){

    uint64_t i;
    
    // Check dimensions
    fecnum_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        res->p_data[i] = -num->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------
















// 1.2. Addition.
// ****************************************************************************************************
fecnum_t fecnum_sum_ff(fecnum_t* lhs, fecnum_t* rhs){
    
    // Perform O + O.
    fecnum_t res;

    res = fecnum_empty_like( lhs );

    fecnum_sum_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecnum_t fecnum_sum_rf(coeff_t lhs, fecnum_t* rhs){
    
    // Perform r + O.
    fecnum_t res;

    res = fecnum_empty_like( rhs );

    fecnum_sum_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void fecnum_sum_ff_to(fecnum_t* lhs, fecnum_t* rhs, fecnum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fecnum_dimCheck( lhs, rhs );
    fecnum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        res->p_data[i] = lhs->p_data[i] + rhs->p_data[i] ;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_sum_rf_to(coeff_t lhs, fecnum_t* rhs, fecnum_t* res){

    // Perform r + f.
    uint64_t i;

    // Check inputs:
    fecnum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){

        res->p_data[i] = lhs  + rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------



















// 1.2. Subtraction.
// ****************************************************************************************************
fecnum_t fecnum_sub_ff(fecnum_t* lhs, fecnum_t* rhs){
    
    // Perform O + O.
    fecnum_t res;

    res = fecnum_empty_like( lhs );

    fecnum_sub_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecnum_t fecnum_sub_rf(coeff_t lhs, fecnum_t* rhs){
    
    // Perform r + O.
    fecnum_t res;

    res = fecnum_empty_like( rhs );

    fecnum_sub_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecnum_t fecnum_sub_fr(fecnum_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    fecnum_t res;

    res = fecnum_empty_like( lhs );

    fecnum_sub_fr_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void fecnum_sub_ff_to(fecnum_t* lhs, fecnum_t* rhs, fecnum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fecnum_dimCheck( lhs, rhs );
    fecnum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){

        res->p_data[i] = lhs->p_data[i] - rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_sub_rf_to(coeff_t lhs, fecnum_t* rhs, fecnum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fecnum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){
        res->p_data[i] = lhs - rhs->p_data[i];
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_sub_fr_to(fecnum_t* lhs, coeff_t rhs, fecnum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fecnum_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){
        res->p_data[i] = lhs->p_data[i] - rhs;
    }

}
// ----------------------------------------------------------------------------------------------------

























// 1.4. Multiplication.
// ****************************************************************************************************
fecnum_t fecnum_mul_ff(fecnum_t* lhs, fecnum_t* rhs){
    
    // Perform O + O.
    fecnum_t res;

    res = fecnum_empty_like( lhs );

    fecnum_mul_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecnum_t fecnum_mul_rf(coeff_t lhs, fecnum_t* rhs){
    
    // Perform r + O.
    fecnum_t res;

    res = fecnum_empty_like( rhs );

    fecnum_mul_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void fecnum_mul_ff_to(fecnum_t* lhs, fecnum_t* rhs, fecnum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fecnum_dimCheck( lhs, rhs );
    fecnum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){

        res->p_data[i] = lhs->p_data[i] * rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_mul_rf_to(coeff_t lhs, fecnum_t* rhs, fecnum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fecnum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){

        res->p_data[i] = lhs * rhs->p_data[i];   

    }

}
// ----------------------------------------------------------------------------------------------------




























// 1.5. Division.
// ****************************************************************************************************
fecnum_t fecnum_div_ff(fecnum_t* lhs, fecnum_t* rhs){
    
    // Perform O + O.
    fecnum_t res;

    res = fecnum_empty_like( lhs );

    fecnum_div_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecnum_t fecnum_div_rf(coeff_t lhs, fecnum_t* rhs){
    
    // Perform r + O.
    fecnum_t res;

    res = fecnum_empty_like( rhs );

    fecnum_div_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecnum_t fecnum_div_fr(fecnum_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    fecnum_t res;

    res = fecnum_empty_like( lhs );

    fecnum_div_fr_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void fecnum_div_ff_to(fecnum_t* lhs, fecnum_t* rhs, fecnum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fecnum_dimCheck( lhs, rhs );
    fecnum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        res->p_data[i] = lhs->p_data[i] / rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_div_rf_to(coeff_t lhs, fecnum_t* rhs, fecnum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fecnum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        
        res->p_data[i] = lhs / rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_div_fr_to(fecnum_t* lhs, coeff_t rhs, fecnum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fecnum_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        
        res->p_data[i] = lhs->p_data[i] / rhs;

    }

}
// ----------------------------------------------------------------------------------------------------