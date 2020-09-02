// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm0n0_t oarrm0n0_dotproduct_OO(oarrm0n0_t* arr1, oarrm0n0_t* arr2){

    
    onumm0n0_t res = onumm0n0_init();

    oarrm0n0_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm0n0_t oarrm0n0_dotproduct_RO(darr_t* arr1, oarrm0n0_t* arr2){

    onumm0n0_t res = onumm0n0_init();

    oarrm0n0_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_matmul_OO(oarrm0n0_t* arr1, oarrm0n0_t* arr2){

    oarrm0n0_t res = oarrm0n0_init();

    res = oarrm0n0_zeros(arr1->nrows, arr2->ncols);

    oarrm0n0_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_matmul_OR(oarrm0n0_t* arr1, darr_t* arr2){
        
    oarrm0n0_t res = oarrm0n0_init();

    res = oarrm0n0_zeros(arr1->nrows, arr2->ncols);

    oarrm0n0_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_matmul_RO(darr_t* arr1, oarrm0n0_t* arr2){
        
    oarrm0n0_t res = oarrm0n0_init();

    res = oarrm0n0_zeros(arr1->nrows, arr2->ncols);

    oarrm0n0_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_transpose(oarrm0n0_t* arr1){
        
    oarrm0n0_t res = oarrm0n0_init();

    res = oarrm0n0_zeros(arr1->ncols, arr1->nrows);

    oarrm0n0_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_invert(oarrm0n0_t* arr1){
    
    oarrm0n0_t res = oarrm0n0_init();

    res = oarrm0n0_zeros(arr1->ncols, arr1->nrows);

    oarrm0n0_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm0n0_t oarrm0n0_det(oarrm0n0_t* arr1){
    
    onumm0n0_t res = onumm0n0_init();

    oarrm0n0_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm0n0_t oarrm0n0_norm(oarrm0n0_t* arr1){
    
    onumm0n0_t res = onumm0n0_init();

    oarrm0n0_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm0n0_t oarrm0n0_pnorm(oarrm0n0_t* arr1, coeff_t p){
    
    onumm0n0_t res = onumm0n0_init();

    oarrm0n0_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

