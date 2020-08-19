// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
{num_type} {arr_func}_dotproduct_OO({arr_type}* arr1, {arr_type}* arr2){{

    
    {num_type} res = {num_func}_init();

    {arr_func}_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {arr_func}_dotproduct_RO(darr_t* arr1, {arr_type}* arr2){{

    {num_type} res = {num_func}_init();

    {arr_func}_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
{arr_type} {arr_func}_matmul_OO({arr_type}* arr1, {arr_type}* arr2){{

    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->nrows, arr2->ncols);

    {arr_func}_matmul_OO_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
{arr_type} {arr_func}_matmul_OR({arr_type}* arr1, darr_t* arr2){{
        
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->nrows, arr2->ncols);

    {arr_func}_matmul_OR_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
{arr_type} {arr_func}_matmul_RO(darr_t* arr1, {arr_type}* arr2){{
        
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->nrows, arr2->ncols);

    {arr_func}_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
{arr_type} {arr_type}ranspose({arr_type}* arr1){{
        
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->ncols, arr1->nrows);

    {arr_type}ranspose_to( arr1, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
{arr_type} {arr_func}_invert({arr_type}* arr1){{
    
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->ncols, arr1->nrows);

    {arr_func}_invert_to(arr1, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
{num_type} {arr_func}_det({arr_type}* arr1){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_det_to(arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
{num_type} {arr_func}_norm({arr_type}* arr1){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_norm_to(arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {arr_func}_pnorm({arr_type}* arr1, coeff_t p){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_pnorm_to(arr1, p, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

