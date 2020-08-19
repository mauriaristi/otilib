
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
{fearr_type} {fearr_func}_neg({fearr_type}* arr){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_neg_to( arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_neg_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){{

        {arr_func}_neg_to( &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
{fearr_type} {fearr_func}_sum_FF({fearr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sum_fF({fenum_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sum_OF({arr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sum_RF(darr_t* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sum_oF({num_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sum_rF(coeff_t lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sum_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sum_fF_to({fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sum_OF_to({arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sum_RF_to(darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sum_oF_to({num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sum_rF_to(coeff_t lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_FF({fearr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_fF({fenum_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_Ff({fearr_type}* lhs, {fenum_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_OF({arr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_FO({fearr_type}* lhs, {arr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_RF(darr_t* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_FR({fearr_type}* lhs, darr_t* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_oF({num_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_Fo({fearr_type}* lhs, {num_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_rF(coeff_t lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sub_Fr({fearr_type}* lhs, coeff_t rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_fF_to({fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_Ff_to({fearr_type}* lhs, {fenum_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_OF_to({arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_FO_to({fearr_type}* lhs, {arr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_RF_to(darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_FR_to({fearr_type}* lhs, darr_t* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_oF_to({num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_Fo_to({fearr_type}* lhs, {num_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_rF_to(coeff_t lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sub_Fr_to({fearr_type}* lhs, coeff_t rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
{fearr_type} {fearr_func}_mul_FF({fearr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_mul_fF({fenum_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_mul_OF({arr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_mul_RF(darr_t* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_mul_oF({num_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_mul_rF(coeff_t lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_mul_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_mul_fF_to({fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_mul_OF_to({arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_mul_RF_to(darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_mul_oF_to({num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_mul_rF_to(coeff_t lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
{fearr_type} {fearr_func}_div_FF({fearr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_div_FF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_Ff({fearr_type}* lhs, {fenum_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_fF({fenum_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_div_fF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_OF({arr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_div_OF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_FO({fearr_type}* lhs, {arr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_div_FO_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_RF(darr_t* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_div_RF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_FR({fearr_type}* lhs, darr_t* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_div_FR_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_oF({num_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_div_oF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_Fo({fearr_type}* lhs, {num_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_rF(coeff_t lhs, {fearr_type}* rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_div_rF_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_div_Fr({fearr_type}* lhs, coeff_t rhs){{

    {fearr_type} res;

    res = {fearr_func}_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    {fearr_func}_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_fF_to({fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_Ff_to({fearr_type}* lhs, {fenum_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_OF_to({arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_FO_to({fearr_type}* lhs, {arr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_RF_to(darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_FR_to({fearr_type}* lhs, darr_t* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_oF_to({num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_Fo_to({fearr_type}* lhs, {num_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_rF_to(coeff_t lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_div_Fr_to({fearr_type}* lhs, coeff_t rhs, {fearr_type}* res){{

    uint64_t i;

    // Check first dimensions.
    {fearr_func}_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){{

        {arr_func}_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {fearr_func}_integrate({fearr_type}* arr, {fenum_type}* w){{

    {arr_type}  res = {arr_func}_init();

    res = {arr_func}_zeros(arr->nrows, arr->ncols);

    {fearr_func}_integrate_to(arr, w, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_integrate_to({fearr_type}* arr, {fenum_type}* w, {arr_type}* res){{

    uint64_t i = 0;

    // Check dimensions.
    {fearr_func}_dimCheck_FfO_integrate( arr, w, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){{
        
        {arr_func}_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }}

}}
// ----------------------------------------------------------------------------------------------------

