// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum2_t mdarr2_dotproduct_OO(mdarr2_t* arr1, mdarr2_t* arr2){

    
    mdnum2_t res = mdnum2_init();

    mdarr2_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t mdarr2_dotproduct_RO(darr_t* arr1, mdarr2_t* arr2){

    mdnum2_t res = mdnum2_init();

    mdarr2_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr2_t mdarr2_matmul_OO(mdarr2_t* arr1, mdarr2_t* arr2){

    mdarr2_t res = mdarr2_init();

    res = mdarr2_zeros(arr1->nrows, arr2->ncols);

    mdarr2_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr2_t mdarr2_matmul_OR(mdarr2_t* arr1, darr_t* arr2){
        
    mdarr2_t res = mdarr2_init();

    res = mdarr2_zeros(arr1->nrows, arr2->ncols);

    mdarr2_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr2_t mdarr2_matmul_RO(darr_t* arr1, mdarr2_t* arr2){
        
    mdarr2_t res = mdarr2_init();

    res = mdarr2_zeros(arr1->nrows, arr2->ncols);

    mdarr2_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr2_t mdarr2_transpose(mdarr2_t* arr1){
        
    mdarr2_t res = mdarr2_init();

    res = mdarr2_zeros(arr1->ncols, arr1->nrows);

    mdarr2_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr2_t mdarr2_invert(mdarr2_t* arr1){
    
    mdarr2_t res = mdarr2_init();

    res = mdarr2_zeros(arr1->ncols, arr1->nrows);

    mdarr2_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum2_t mdarr2_det(mdarr2_t* arr1){
    
    mdnum2_t res = mdnum2_init();

    mdarr2_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum2_t mdarr2_norm(mdarr2_t* arr1){
    
    mdnum2_t res = mdnum2_init();

    mdarr2_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t mdarr2_pnorm(mdarr2_t* arr1, coeff_t p){
    
    mdnum2_t res = mdnum2_init();

    mdarr2_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

