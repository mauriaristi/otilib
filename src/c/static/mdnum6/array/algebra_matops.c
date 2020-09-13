// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
mdnum6_t mdarr6_dotproduct_OO(mdarr6_t* arr1, mdarr6_t* arr2){

    
    mdnum6_t res = mdnum6_init();

    mdarr6_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t mdarr6_dotproduct_RO(darr_t* arr1, mdarr6_t* arr2){

    mdnum6_t res = mdnum6_init();

    mdarr6_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
mdarr6_t mdarr6_matmul_OO(mdarr6_t* arr1, mdarr6_t* arr2){

    mdarr6_t res = mdarr6_init();

    res = mdarr6_zeros(arr1->nrows, arr2->ncols);

    mdarr6_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
mdarr6_t mdarr6_matmul_OR(mdarr6_t* arr1, darr_t* arr2){
        
    mdarr6_t res = mdarr6_init();

    res = mdarr6_zeros(arr1->nrows, arr2->ncols);

    mdarr6_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
mdarr6_t mdarr6_matmul_RO(darr_t* arr1, mdarr6_t* arr2){
        
    mdarr6_t res = mdarr6_init();

    res = mdarr6_zeros(arr1->nrows, arr2->ncols);

    mdarr6_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
mdarr6_t mdarr6_transpose(mdarr6_t* arr1){
        
    mdarr6_t res = mdarr6_init();

    res = mdarr6_zeros(arr1->ncols, arr1->nrows);

    mdarr6_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
mdarr6_t mdarr6_invert(mdarr6_t* arr1){
    
    mdarr6_t res = mdarr6_init();

    res = mdarr6_zeros(arr1->ncols, arr1->nrows);

    mdarr6_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
mdnum6_t mdarr6_det(mdarr6_t* arr1){
    
    mdnum6_t res = mdnum6_init();

    mdarr6_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
mdnum6_t mdarr6_norm(mdarr6_t* arr1){
    
    mdnum6_t res = mdnum6_init();

    mdarr6_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t mdarr6_pnorm(mdarr6_t* arr1, coeff_t p){
    
    mdnum6_t res = mdnum6_init();

    mdarr6_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

