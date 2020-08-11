

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
fednum_t fednum_neg(fednum_t* num){

    fednum_t res = fednum_empty_like( num );

    fednum_neg_to(num,&res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_neg_to(fednum_t* num, fednum_t* res){

    uint64_t i;
    
    // Check dimensions
    fednum_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){
    
        res->p_data[i] = -num->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------
















// 1.2. Addition.
// ****************************************************************************************************
fednum_t fednum_sum_ff(fednum_t* lhs, fednum_t* rhs){
    
    // Perform O + O.
    fednum_t res;

    res = fednum_empty_like( lhs );

    fednum_sum_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fednum_t fednum_sum_rf(coeff_t lhs, fednum_t* rhs){
    
    // Perform r + O.
    fednum_t res;

    res = fednum_empty_like( rhs );

    fednum_sum_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void fednum_sum_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fednum_dimCheck( lhs, rhs );
    fednum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        res->p_data[i] = lhs->p_data[i] + rhs->p_data[i] ;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_sum_rf_to(coeff_t lhs, fednum_t* rhs, fednum_t* res){

    // Perform r + f.
    uint64_t i;

    // Check inputs:
    fednum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){

        res->p_data[i] = lhs  + rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------



















// 1.2. Subtraction.
// ****************************************************************************************************
fednum_t fednum_sub_ff(fednum_t* lhs, fednum_t* rhs){
    
    // Perform O + O.
    fednum_t res;

    res = fednum_empty_like( lhs );

    fednum_sub_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fednum_t fednum_sub_rf(coeff_t lhs, fednum_t* rhs){
    
    // Perform r + O.
    fednum_t res;

    res = fednum_empty_like( rhs );

    fednum_sub_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fednum_t fednum_sub_fr(fednum_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    fednum_t res;

    res = fednum_empty_like( lhs );

    fednum_sub_fr_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void fednum_sub_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fednum_dimCheck( lhs, rhs );
    fednum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){

        res->p_data[i] = lhs->p_data[i] - rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_sub_rf_to(coeff_t lhs, fednum_t* rhs, fednum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fednum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){
        res->p_data[i] = lhs - rhs->p_data[i];
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_sub_fr_to(fednum_t* lhs, coeff_t rhs, fednum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fednum_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){
        res->p_data[i] = lhs->p_data[i] - rhs;
    }

}
// ----------------------------------------------------------------------------------------------------

























// 1.4. Multiplication.
// ****************************************************************************************************
fednum_t fednum_mul_ff(fednum_t* lhs, fednum_t* rhs){
    
    // Perform O + O.
    fednum_t res;

    res = fednum_empty_like( lhs );

    fednum_mul_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fednum_t fednum_mul_rf(coeff_t lhs, fednum_t* rhs){
    
    // Perform r + O.
    fednum_t res;

    res = fednum_empty_like( rhs );

    fednum_mul_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void fednum_mul_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fednum_dimCheck( lhs, rhs );
    fednum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){

        res->p_data[i] = lhs->p_data[i] * rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_mul_rf_to(coeff_t lhs, fednum_t* rhs, fednum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fednum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->nip; i++){

        res->p_data[i] = lhs * rhs->p_data[i];   

    }

}
// ----------------------------------------------------------------------------------------------------




























// 1.5. Division.
// ****************************************************************************************************
fednum_t fednum_div_ff(fednum_t* lhs, fednum_t* rhs){
    
    // Perform O + O.
    fednum_t res;

    res = fednum_empty_like( lhs );

    fednum_div_ff_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fednum_t fednum_div_rf(coeff_t lhs, fednum_t* rhs){
    
    // Perform r + O.
    fednum_t res;

    res = fednum_empty_like( rhs );

    fednum_div_rf_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fednum_t fednum_div_fr(fednum_t* lhs, coeff_t rhs){
    
    // Perform r + O.
    fednum_t res;

    res = fednum_empty_like( lhs );

    fednum_div_fr_to( lhs, rhs, &res );

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void fednum_div_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res){
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    fednum_dimCheck( lhs, rhs );
    fednum_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){

        res->p_data[i] = lhs->p_data[i] / rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_div_rf_to(coeff_t lhs, fednum_t* rhs, fednum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fednum_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){
        
        res->p_data[i] = lhs / rhs->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_div_fr_to(fednum_t* lhs, coeff_t rhs, fednum_t* res){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    fednum_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){
        
        res->p_data[i] = lhs->p_data[i] / rhs;

    }

}
// ----------------------------------------------------------------------------------------------------