// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm2n10_t oarrm2n10_dotproduct_OO(oarrm2n10_t* arr1, oarrm2n10_t* arr2){

    
    onumm2n10_t res = onumm2n10_init();

    oarrm2n10_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n10_t oarrm2n10_dotproduct_RO(darr_t* arr1, oarrm2n10_t* arr2){

    onumm2n10_t res = onumm2n10_init();

    oarrm2n10_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm2n10_t oarrm2n10_matmul_OO(oarrm2n10_t* arr1, oarrm2n10_t* arr2){

    oarrm2n10_t res = oarrm2n10_init();

    res = oarrm2n10_zeros(arr1->nrows, arr2->ncols);

    oarrm2n10_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm2n10_t oarrm2n10_matmul_OR(oarrm2n10_t* arr1, darr_t* arr2){
        
    oarrm2n10_t res = oarrm2n10_init();

    res = oarrm2n10_zeros(arr1->nrows, arr2->ncols);

    oarrm2n10_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm2n10_t oarrm2n10_matmul_RO(darr_t* arr1, oarrm2n10_t* arr2){
        
    oarrm2n10_t res = oarrm2n10_init();

    res = oarrm2n10_zeros(arr1->nrows, arr2->ncols);

    oarrm2n10_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm2n10_t oarrm2n10_transpose(oarrm2n10_t* arr1){
        
    oarrm2n10_t res = oarrm2n10_init();

    res = oarrm2n10_zeros(arr1->ncols, arr1->nrows);

    oarrm2n10_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm2n10_t oarrm2n10_invert(oarrm2n10_t* arr1){
    
    oarrm2n10_t res = oarrm2n10_init();

    res = oarrm2n10_zeros(arr1->ncols, arr1->nrows);

    oarrm2n10_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm2n10_t oarrm2n10_det(oarrm2n10_t* arr1){
    
    onumm2n10_t res = onumm2n10_init();

    oarrm2n10_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm2n10_t oarrm2n10_norm(oarrm2n10_t* arr1){
    
    onumm2n10_t res = onumm2n10_init();

    oarrm2n10_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n10_t oarrm2n10_pnorm(oarrm2n10_t* arr1, coeff_t p){
    
    onumm2n10_t res = onumm2n10_init();

    oarrm2n10_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

