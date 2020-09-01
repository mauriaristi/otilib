// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm1n3_t oarrm1n3_dotproduct_OO(oarrm1n3_t* arr1, oarrm1n3_t* arr2){

    
    onumm1n3_t res = onumm1n3_init();

    oarrm1n3_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n3_t oarrm1n3_dotproduct_RO(darr_t* arr1, oarrm1n3_t* arr2){

    onumm1n3_t res = onumm1n3_init();

    oarrm1n3_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm1n3_t oarrm1n3_matmul_OO(oarrm1n3_t* arr1, oarrm1n3_t* arr2){

    oarrm1n3_t res = oarrm1n3_init();

    res = oarrm1n3_zeros(arr1->nrows, arr2->ncols);

    oarrm1n3_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm1n3_t oarrm1n3_matmul_OR(oarrm1n3_t* arr1, darr_t* arr2){
        
    oarrm1n3_t res = oarrm1n3_init();

    res = oarrm1n3_zeros(arr1->nrows, arr2->ncols);

    oarrm1n3_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm1n3_t oarrm1n3_matmul_RO(darr_t* arr1, oarrm1n3_t* arr2){
        
    oarrm1n3_t res = oarrm1n3_init();

    res = oarrm1n3_zeros(arr1->nrows, arr2->ncols);

    oarrm1n3_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm1n3_t oarrm1n3_transpose(oarrm1n3_t* arr1){
        
    oarrm1n3_t res = oarrm1n3_init();

    res = oarrm1n3_zeros(arr1->ncols, arr1->nrows);

    oarrm1n3_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm1n3_t oarrm1n3_invert(oarrm1n3_t* arr1){
    
    oarrm1n3_t res = oarrm1n3_init();

    res = oarrm1n3_zeros(arr1->ncols, arr1->nrows);

    oarrm1n3_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm1n3_t oarrm1n3_det(oarrm1n3_t* arr1){
    
    onumm1n3_t res = onumm1n3_init();

    oarrm1n3_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm1n3_t oarrm1n3_norm(oarrm1n3_t* arr1){
    
    onumm1n3_t res = onumm1n3_init();

    oarrm1n3_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n3_t oarrm1n3_pnorm(oarrm1n3_t* arr1, coeff_t p){
    
    onumm1n3_t res = onumm1n3_init();

    oarrm1n3_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

