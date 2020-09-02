// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum1_t mdarr1_dotproduct_OO(mdarr1_t* arr1, mdarr1_t* arr2){

    
    mdnum1_t res = mdnum1_init();

    mdarr1_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t mdarr1_dotproduct_RO(darr_t* arr1, mdarr1_t* arr2){

    mdnum1_t res = mdnum1_init();

    mdarr1_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr1_t mdarr1_matmul_OO(mdarr1_t* arr1, mdarr1_t* arr2){

    mdarr1_t res = mdarr1_init();

    res = mdarr1_zeros(arr1->nrows, arr2->ncols);

    mdarr1_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr1_t mdarr1_matmul_OR(mdarr1_t* arr1, darr_t* arr2){
        
    mdarr1_t res = mdarr1_init();

    res = mdarr1_zeros(arr1->nrows, arr2->ncols);

    mdarr1_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr1_t mdarr1_matmul_RO(darr_t* arr1, mdarr1_t* arr2){
        
    mdarr1_t res = mdarr1_init();

    res = mdarr1_zeros(arr1->nrows, arr2->ncols);

    mdarr1_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr1_t mdarr1_transpose(mdarr1_t* arr1){
        
    mdarr1_t res = mdarr1_init();

    res = mdarr1_zeros(arr1->ncols, arr1->nrows);

    mdarr1_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr1_t mdarr1_invert(mdarr1_t* arr1){
    
    mdarr1_t res = mdarr1_init();

    res = mdarr1_zeros(arr1->ncols, arr1->nrows);

    mdarr1_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum1_t mdarr1_det(mdarr1_t* arr1){
    
    mdnum1_t res = mdnum1_init();

    mdarr1_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum1_t mdarr1_norm(mdarr1_t* arr1){
    
    mdnum1_t res = mdnum1_init();

    mdarr1_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t mdarr1_pnorm(mdarr1_t* arr1, coeff_t p){
    
    mdnum1_t res = mdnum1_init();

    mdarr1_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

