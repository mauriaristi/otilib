// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum3_t mdarr3_dotproduct_OO(mdarr3_t* arr1, mdarr3_t* arr2){

    
    mdnum3_t res = mdnum3_init();

    mdarr3_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t mdarr3_dotproduct_RO(darr_t* arr1, mdarr3_t* arr2){

    mdnum3_t res = mdnum3_init();

    mdarr3_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr3_t mdarr3_matmul_OO(mdarr3_t* arr1, mdarr3_t* arr2){

    mdarr3_t res = mdarr3_init();

    res = mdarr3_zeros(arr1->nrows, arr2->ncols);

    mdarr3_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr3_t mdarr3_matmul_OR(mdarr3_t* arr1, darr_t* arr2){
        
    mdarr3_t res = mdarr3_init();

    res = mdarr3_zeros(arr1->nrows, arr2->ncols);

    mdarr3_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr3_t mdarr3_matmul_RO(darr_t* arr1, mdarr3_t* arr2){
        
    mdarr3_t res = mdarr3_init();

    res = mdarr3_zeros(arr1->nrows, arr2->ncols);

    mdarr3_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr3_t mdarr3_transpose(mdarr3_t* arr1){
        
    mdarr3_t res = mdarr3_init();

    res = mdarr3_zeros(arr1->ncols, arr1->nrows);

    mdarr3_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr3_t mdarr3_invert(mdarr3_t* arr1){
    
    mdarr3_t res = mdarr3_init();

    res = mdarr3_zeros(arr1->ncols, arr1->nrows);

    mdarr3_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum3_t mdarr3_det(mdarr3_t* arr1){
    
    mdnum3_t res = mdnum3_init();

    mdarr3_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum3_t mdarr3_norm(mdarr3_t* arr1){
    
    mdnum3_t res = mdnum3_init();

    mdarr3_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t mdarr3_pnorm(mdarr3_t* arr1, coeff_t p){
    
    mdnum3_t res = mdnum3_init();

    mdarr3_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

