
// void {fearr_func}_dimCheck_FF_elementwise({fearr_type}* arr1, {fearr_type}* arr2, {fearr_type}* res);
// void {fearr_func}_dimCheck_OF_elementwise(  {arr_type}* arr1, {fearr_type}* arr2, {fearr_type}* res);
// void {fearr_func}_dimCheck_RF_elementwise(   darr_t* arr1, {fearr_type}* arr2, {fearr_type}* res);
// void {fearr_func}_dimCheck_FF_matmul( {fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);
// void {fearr_func}_dimCheck_OF_matmul(   {arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);
// void {fearr_func}_dimCheck_RF_matmul(    darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res);
// void {fearr_func}_dimCheck_FO_matmul( {fearr_type}* lhs,   {arr_type}* rhs, {fearr_type}* res);
// void {fearr_func}_dimCheck_FR_matmul( {fearr_type}* lhs,    darr_t* rhs, {fearr_type}* res);
// void {fearr_func}_dimCheck_F_squareness( {fearr_type}* arr1, {fearr_type}* res);
// void {fearr_func}_dimCheck_F_transpose( {fearr_type}* arr1, {fearr_type}* res);

// ****************************************************************************************************
{fenum_type} {fearr_func}_dotproduct_FF({fearr_type}* lhs, {fearr_type}* rhs){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty( rhs->nip);

    {fearr_func}_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_dotproduct_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fenum_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){{

        {arr_func}_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fearr_func}_dotproduct_OF({arr_type}* lhs, {fearr_type}* rhs){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty( rhs->nip);

    {fearr_func}_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_dotproduct_OF_to( {arr_type}* lhs, {fearr_type}* rhs, {fenum_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){{

        {arr_func}_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fearr_func}_dotproduct_RF( darr_t* lhs, {fearr_type}* rhs){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty( rhs->nip);

    {fearr_func}_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_dotproduct_RF_to( darr_t* lhs, {fearr_type}* rhs, {fenum_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){{

        {arr_func}_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_matmul_FF({fearr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res = {fearr_func}_init();

    // Check dimensions.
    res = {fearr_func}_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    {fearr_func}_matmul_FF_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_matmul_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){{

        {arr_func}_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_matmul_OF({arr_type}* lhs, {fearr_type}* rhs){{

    {fearr_type} res = {fearr_func}_init();

    // Check dimensions.
    res = {fearr_func}_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_matmul_OF_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_matmul_OF_to({arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){{

        {arr_func}_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_matmul_FO({fearr_type}* lhs, {arr_type}* rhs){{

    {fearr_type} res = {fearr_func}_init();

    // Check dimensions.
    res = {fearr_func}_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    {fearr_func}_matmul_FO_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_matmul_FO_to({fearr_type}* lhs, {arr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){{

        {arr_func}_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_matmul_RF(darr_t* lhs, {fearr_type}* rhs){{

    {fearr_type} res = {fearr_func}_init();

    // Check dimensions.
    res = {fearr_func}_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    {fearr_func}_matmul_RF_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_matmul_RF_to(darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){{

        {arr_func}_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_matmul_FR({fearr_type}* lhs, darr_t* rhs){{

    {fearr_type} res = {fearr_func}_init();

    // Check dimensions.
    res = {fearr_func}_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    {fearr_func}_matmul_FR_to( lhs, rhs, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_matmul_FR_to({fearr_type}* lhs, darr_t* rhs, {fearr_type}* res){{

    uint64_t i;

    // Check Dimensions
    {fearr_func}_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){{

        {arr_func}_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fearr_func}_norm({fearr_type}* arr){{
    
    {fenum_type} res = {fenum_func}_init();

    
    res = {fenum_func}_createEmpty( arr->nip);

    {fearr_func}_norm_to( arr, &res );
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_norm_to({fearr_type}* arr, {fenum_type}* res){{
    
    uint64_t i;
    
    // Check dimensions (squareness)
    {fearr_func}_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){{

        {arr_func}_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fearr_func}_pnorm({fearr_type}* arr, coeff_t p){{
    
    {fenum_type} res = {fenum_func}_init();

    
    res = {fenum_func}_createEmpty( arr->nip);

    {fearr_func}_pnorm_to( arr, p, &res );
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_pnorm_to({fearr_type}* arr, coeff_t p, {fenum_type}* res){{
    
    uint64_t i;
    
    // Check dimensions (squareness)
    {fearr_func}_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){{

        {arr_func}_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fearr_func}_det({fearr_type}* arr){{
    
    {fenum_type} res = {fenum_func}_init();

    
    res = {fenum_func}_createEmpty( arr->nip);

    {fearr_func}_det_to( arr, &res );
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_det_to({fearr_type}* arr, {fenum_type}* res){{
    
    uint64_t i;
    
    // Check dimensions (squareness)
    {fearr_func}_dimCheck_F_squareness( arr, arr);
    {fearr_func}_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){{
        
        {arr_func}_det_to( &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_invert({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    // Should it copy offsets too?
    res = {fearr_func}_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_invert_to( arr, &res );

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_invert_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // Check dimensions (must be square and equal).
    {fearr_func}_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){{

        {arr_func}_invert_to( &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_type}ranspose({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    // Should it copy offsets?
    res = {fearr_func}_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    {fearr_type}ranspose_to( arr, &res );

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_type}ranspose_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // Check dimensions.
    {fearr_func}_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){{

        {arr_type}ranspose_to( &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

