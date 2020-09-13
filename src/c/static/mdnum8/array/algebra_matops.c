// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum8_t mdarr8_dotproduct_OO(mdarr8_t* arr1, mdarr8_t* arr2){

    
    mdnum8_t res = mdnum8_init();

    mdarr8_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t mdarr8_dotproduct_RO(darr_t* arr1, mdarr8_t* arr2){

    mdnum8_t res = mdnum8_init();

    mdarr8_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr8_t mdarr8_matmul_OO(mdarr8_t* arr1, mdarr8_t* arr2){

    mdarr8_t res = mdarr8_init();

    res = mdarr8_zeros(arr1->nrows, arr2->ncols);

    mdarr8_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr8_t mdarr8_matmul_OR(mdarr8_t* arr1, darr_t* arr2){
        
    mdarr8_t res = mdarr8_init();

    res = mdarr8_zeros(arr1->nrows, arr2->ncols);

    mdarr8_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr8_t mdarr8_matmul_RO(darr_t* arr1, mdarr8_t* arr2){
        
    mdarr8_t res = mdarr8_init();

    res = mdarr8_zeros(arr1->nrows, arr2->ncols);

    mdarr8_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr8_t mdarr8_transpose(mdarr8_t* arr1){
        
    mdarr8_t res = mdarr8_init();

    res = mdarr8_zeros(arr1->ncols, arr1->nrows);

    mdarr8_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr8_t mdarr8_invert(mdarr8_t* arr1){
    
    mdarr8_t res = mdarr8_init();

    res = mdarr8_zeros(arr1->ncols, arr1->nrows);

    mdarr8_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum8_t mdarr8_det(mdarr8_t* arr1){
    
    mdnum8_t res = mdnum8_init();

    mdarr8_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum8_t mdarr8_norm(mdarr8_t* arr1){
    
    mdnum8_t res = mdnum8_init();

    mdarr8_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t mdarr8_pnorm(mdarr8_t* arr1, coeff_t p){
    
    mdnum8_t res = mdnum8_init();

    mdarr8_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

