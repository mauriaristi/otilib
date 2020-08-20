// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum4_t mdarr4_dotproduct_OO(mdarr4_t* arr1, mdarr4_t* arr2){

    
    mdnum4_t res = mdnum4_init();

    mdarr4_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t mdarr4_dotproduct_RO(darr_t* arr1, mdarr4_t* arr2){

    mdnum4_t res = mdnum4_init();

    mdarr4_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr4_t mdarr4_matmul_OO(mdarr4_t* arr1, mdarr4_t* arr2){

    mdarr4_t res = mdarr4_init();

    res = mdarr4_zeros(arr1->nrows, arr2->ncols);

    mdarr4_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr4_t mdarr4_matmul_OR(mdarr4_t* arr1, darr_t* arr2){
        
    mdarr4_t res = mdarr4_init();

    res = mdarr4_zeros(arr1->nrows, arr2->ncols);

    mdarr4_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr4_t mdarr4_matmul_RO(darr_t* arr1, mdarr4_t* arr2){
        
    mdarr4_t res = mdarr4_init();

    res = mdarr4_zeros(arr1->nrows, arr2->ncols);

    mdarr4_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr4_t mdarr4_transpose(mdarr4_t* arr1){
        
    mdarr4_t res = mdarr4_init();

    res = mdarr4_zeros(arr1->ncols, arr1->nrows);

    mdarr4_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr4_t mdarr4_invert(mdarr4_t* arr1){
    
    mdarr4_t res = mdarr4_init();

    res = mdarr4_zeros(arr1->ncols, arr1->nrows);

    mdarr4_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum4_t mdarr4_det(mdarr4_t* arr1){
    
    mdnum4_t res = mdnum4_init();

    mdarr4_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum4_t mdarr4_norm(mdarr4_t* arr1){
    
    mdnum4_t res = mdnum4_init();

    mdarr4_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t mdarr4_pnorm(mdarr4_t* arr1, coeff_t p){
    
    mdnum4_t res = mdnum4_init();

    mdarr4_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

