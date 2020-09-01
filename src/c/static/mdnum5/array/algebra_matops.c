// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum5_t mdarr5_dotproduct_OO(mdarr5_t* arr1, mdarr5_t* arr2){

    
    mdnum5_t res = mdnum5_init();

    mdarr5_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t mdarr5_dotproduct_RO(darr_t* arr1, mdarr5_t* arr2){

    mdnum5_t res = mdnum5_init();

    mdarr5_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr5_t mdarr5_matmul_OO(mdarr5_t* arr1, mdarr5_t* arr2){

    mdarr5_t res = mdarr5_init();

    res = mdarr5_zeros(arr1->nrows, arr2->ncols);

    mdarr5_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr5_t mdarr5_matmul_OR(mdarr5_t* arr1, darr_t* arr2){
        
    mdarr5_t res = mdarr5_init();

    res = mdarr5_zeros(arr1->nrows, arr2->ncols);

    mdarr5_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr5_t mdarr5_matmul_RO(darr_t* arr1, mdarr5_t* arr2){
        
    mdarr5_t res = mdarr5_init();

    res = mdarr5_zeros(arr1->nrows, arr2->ncols);

    mdarr5_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr5_t mdarr5_transpose(mdarr5_t* arr1){
        
    mdarr5_t res = mdarr5_init();

    res = mdarr5_zeros(arr1->ncols, arr1->nrows);

    mdarr5_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr5_t mdarr5_invert(mdarr5_t* arr1){
    
    mdarr5_t res = mdarr5_init();

    res = mdarr5_zeros(arr1->ncols, arr1->nrows);

    mdarr5_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum5_t mdarr5_det(mdarr5_t* arr1){
    
    mdnum5_t res = mdnum5_init();

    mdarr5_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum5_t mdarr5_norm(mdarr5_t* arr1){
    
    mdnum5_t res = mdnum5_init();

    mdarr5_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t mdarr5_pnorm(mdarr5_t* arr1, coeff_t p){
    
    mdnum5_t res = mdnum5_init();

    mdarr5_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

