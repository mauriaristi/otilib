// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum7_t mdarr7_dotproduct_OO(mdarr7_t* arr1, mdarr7_t* arr2){

    
    mdnum7_t res = mdnum7_init();

    mdarr7_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t mdarr7_dotproduct_RO(darr_t* arr1, mdarr7_t* arr2){

    mdnum7_t res = mdnum7_init();

    mdarr7_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr7_t mdarr7_matmul_OO(mdarr7_t* arr1, mdarr7_t* arr2){

    mdarr7_t res = mdarr7_init();

    res = mdarr7_zeros(arr1->nrows, arr2->ncols);

    mdarr7_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr7_t mdarr7_matmul_OR(mdarr7_t* arr1, darr_t* arr2){
        
    mdarr7_t res = mdarr7_init();

    res = mdarr7_zeros(arr1->nrows, arr2->ncols);

    mdarr7_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr7_t mdarr7_matmul_RO(darr_t* arr1, mdarr7_t* arr2){
        
    mdarr7_t res = mdarr7_init();

    res = mdarr7_zeros(arr1->nrows, arr2->ncols);

    mdarr7_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr7_t mdarr7_transpose(mdarr7_t* arr1){
        
    mdarr7_t res = mdarr7_init();

    res = mdarr7_zeros(arr1->ncols, arr1->nrows);

    mdarr7_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr7_t mdarr7_invert(mdarr7_t* arr1){
    
    mdarr7_t res = mdarr7_init();

    res = mdarr7_zeros(arr1->ncols, arr1->nrows);

    mdarr7_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum7_t mdarr7_det(mdarr7_t* arr1){
    
    mdnum7_t res = mdnum7_init();

    mdarr7_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum7_t mdarr7_norm(mdarr7_t* arr1){
    
    mdnum7_t res = mdnum7_init();

    mdarr7_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t mdarr7_pnorm(mdarr7_t* arr1, coeff_t p){
    
    mdnum7_t res = mdnum7_init();

    mdarr7_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

