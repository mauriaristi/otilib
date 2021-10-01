// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm1n10_t oarrm1n10_dotproduct_OO(oarrm1n10_t* arr1, oarrm1n10_t* arr2){

    
    onumm1n10_t res = onumm1n10_init();

    oarrm1n10_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n10_t oarrm1n10_dotproduct_RO(darr_t* arr1, oarrm1n10_t* arr2){

    onumm1n10_t res = onumm1n10_init();

    oarrm1n10_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm1n10_t oarrm1n10_matmul_OO(oarrm1n10_t* arr1, oarrm1n10_t* arr2){

    oarrm1n10_t res = oarrm1n10_init();

    res = oarrm1n10_zeros(arr1->nrows, arr2->ncols);

    oarrm1n10_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm1n10_t oarrm1n10_matmul_OR(oarrm1n10_t* arr1, darr_t* arr2){
        
    oarrm1n10_t res = oarrm1n10_init();

    res = oarrm1n10_zeros(arr1->nrows, arr2->ncols);

    oarrm1n10_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm1n10_t oarrm1n10_matmul_RO(darr_t* arr1, oarrm1n10_t* arr2){
        
    oarrm1n10_t res = oarrm1n10_init();

    res = oarrm1n10_zeros(arr1->nrows, arr2->ncols);

    oarrm1n10_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm1n10_t oarrm1n10_transpose(oarrm1n10_t* arr1){
        
    oarrm1n10_t res = oarrm1n10_init();

    res = oarrm1n10_zeros(arr1->ncols, arr1->nrows);

    oarrm1n10_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm1n10_t oarrm1n10_invert(oarrm1n10_t* arr1){
    
    oarrm1n10_t res = oarrm1n10_init();

    res = oarrm1n10_zeros(arr1->ncols, arr1->nrows);

    oarrm1n10_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm1n10_t oarrm1n10_det(oarrm1n10_t* arr1){
    
    onumm1n10_t res = onumm1n10_init();

    oarrm1n10_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm1n10_t oarrm1n10_norm(oarrm1n10_t* arr1){
    
    onumm1n10_t res = onumm1n10_init();

    oarrm1n10_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n10_t oarrm1n10_pnorm(oarrm1n10_t* arr1, coeff_t p){
    
    onumm1n10_t res = onumm1n10_init();

    oarrm1n10_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

