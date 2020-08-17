
// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
{fenum_type} {fenum_func}_neg({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_empty_like( num);

    {fenum_func}_neg_to(num,&res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_neg_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;
    
    // Check dimensions
    {fenum_func}_dimCheck(num,res);

    for ( i = 0; i < num->nip; i++){{    
        {num_func}_neg_to( &num->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
{fenum_type} {fenum_func}_sum_ff({fenum_type}* lhs, {fenum_type}* rhs){{
    
    // Perform O + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_sum_ff_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sum_of({num_type}* lhs, {fenum_type}* rhs){{
    
    // Perform o + O.
    {fenum_type} res;
    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_sum_of_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sum_rf(coeff_t lhs, {fenum_type}* rhs){{
    
    // Perform r + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_sum_rf_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void {fenum_func}_sum_ff_to({fenum_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    {fenum_func}_dimCheck( lhs, rhs );
    {fenum_func}_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_sum_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sum_of_to({num_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_sum_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sum_rf_to(coeff_t lhs, {fenum_type}* rhs, {fenum_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_sum_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
{fenum_type} {fenum_func}_sub_ff({fenum_type}* lhs, {fenum_type}* rhs){{
    
    // Perform O + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_sub_ff_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sub_of({num_type}* lhs, {fenum_type}* rhs){{
    
    // Perform o + O.
    {fenum_type} res;
    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_sub_of_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sub_fo({fenum_type}* lhs, {num_type}* rhs){{
    
    // Perform o + O.
    {fenum_type} res;
    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_sub_fo_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sub_rf(coeff_t lhs, {fenum_type}* rhs){{
    
    // Perform r + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_sub_rf_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sub_fr({fenum_type}* lhs, coeff_t rhs){{
    
    // Perform r + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_sub_fr_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.2. Subtraction.
// ****************************************************************************************************
void {fenum_func}_sub_ff_to({fenum_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    {fenum_func}_dimCheck( lhs, rhs );
    {fenum_func}_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_sub_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sub_of_to({num_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_sub_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sub_fo_to({fenum_type}* lhs, {num_type}* rhs, {fenum_type}* res){{
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_sub_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sub_rf_to(coeff_t lhs, {fenum_type}* rhs, {fenum_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_sub_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sub_fr_to({fenum_type}* lhs, coeff_t rhs, {fenum_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_sub_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
{fenum_type} {fenum_func}_mul_ff({fenum_type}* lhs, {fenum_type}* rhs){{
    
    // Perform O + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_mul_ff_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_mul_of({num_type}* lhs, {fenum_type}* rhs){{
    
    // Perform o + O.
    {fenum_type} res;
    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_mul_of_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_mul_rf(coeff_t lhs, {fenum_type}* rhs){{
    
    // Perform r + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_mul_rf_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void {fenum_func}_mul_ff_to({fenum_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    {fenum_func}_dimCheck( lhs, rhs );
    {fenum_func}_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{

        {num_func}_mul_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_mul_of_to({num_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_mul_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_mul_rf_to(coeff_t lhs, {fenum_type}* rhs, {fenum_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_mul_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
{fenum_type} {fenum_func}_div_ff({fenum_type}* lhs, {fenum_type}* rhs){{
    
    // Perform O + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_div_ff_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_div_of({num_type}* lhs, {fenum_type}* rhs){{
    
    // Perform o + O.
    {fenum_type} res;
    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_div_of_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_div_fo({fenum_type}* lhs, {num_type}* rhs){{
    
    // Perform o + O.
    {fenum_type} res;
    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_div_fo_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_div_rf(coeff_t lhs, {fenum_type}* rhs){{
    
    // Perform r + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( rhs);

    {fenum_func}_div_rf_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_div_fr({fenum_type}* lhs, coeff_t rhs){{
    
    // Perform r + O.
    {fenum_type} res;

    res = {fenum_func}_empty_like( lhs);

    {fenum_func}_div_fr_to( lhs, rhs, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division.
// ****************************************************************************************************
void {fenum_func}_div_ff_to({fenum_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs to have same number of integration points:
    {fenum_func}_dimCheck( lhs, rhs );
    {fenum_func}_dimCheck( rhs, res );

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_div_oo_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_div_of_to({num_type}* lhs, {fenum_type}* rhs, {fenum_type}* res){{
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_div_oo_to( lhs, &rhs->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_div_fo_to({fenum_type}* lhs, {num_type}* rhs, {fenum_type}* res){{
    
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_div_oo_to( &lhs->p_data[i],  rhs, &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_div_rf_to(coeff_t lhs, {fenum_type}* rhs, {fenum_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(rhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < rhs->nip; i++){{
        {num_func}_div_ro_to(lhs, &rhs->p_data[i], &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_div_fr_to({fenum_type}* lhs, coeff_t rhs, {fenum_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {fenum_func}_dimCheck(lhs,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < lhs->nip; i++){{
        {num_func}_div_or_to(&lhs->p_data[i], rhs, &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------