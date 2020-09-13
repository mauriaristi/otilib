// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum9_t mdarr9_dotproduct_OO(mdarr9_t* arr1, mdarr9_t* arr2){

    
    mdnum9_t res = mdnum9_init();

    mdarr9_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum9_t mdarr9_dotproduct_RO(darr_t* arr1, mdarr9_t* arr2){

    mdnum9_t res = mdnum9_init();

    mdarr9_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr9_t mdarr9_matmul_OO(mdarr9_t* arr1, mdarr9_t* arr2){

    mdarr9_t res = mdarr9_init();

    res = mdarr9_zeros(arr1->nrows, arr2->ncols);

    mdarr9_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr9_t mdarr9_matmul_OR(mdarr9_t* arr1, darr_t* arr2){
        
    mdarr9_t res = mdarr9_init();

    res = mdarr9_zeros(arr1->nrows, arr2->ncols);

    mdarr9_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr9_t mdarr9_matmul_RO(darr_t* arr1, mdarr9_t* arr2){
        
    mdarr9_t res = mdarr9_init();

    res = mdarr9_zeros(arr1->nrows, arr2->ncols);

    mdarr9_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr9_t mdarr9_transpose(mdarr9_t* arr1){
        
    mdarr9_t res = mdarr9_init();

    res = mdarr9_zeros(arr1->ncols, arr1->nrows);

    mdarr9_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr9_t mdarr9_invert(mdarr9_t* arr1){
    
    mdarr9_t res = mdarr9_init();

    res = mdarr9_zeros(arr1->ncols, arr1->nrows);

    mdarr9_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum9_t mdarr9_det(mdarr9_t* arr1){
    
    mdnum9_t res = mdnum9_init();

    mdarr9_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum9_t mdarr9_norm(mdarr9_t* arr1){
    
    mdnum9_t res = mdnum9_init();

    mdarr9_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum9_t mdarr9_pnorm(mdarr9_t* arr1, coeff_t p){
    
    mdnum9_t res = mdnum9_init();

    mdarr9_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

