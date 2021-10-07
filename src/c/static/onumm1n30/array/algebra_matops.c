// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm1n30_t oarrm1n30_dotproduct_OO(oarrm1n30_t* arr1, oarrm1n30_t* arr2){

    
    onumm1n30_t res = onumm1n30_init();

    oarrm1n30_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n30_t oarrm1n30_dotproduct_RO(darr_t* arr1, oarrm1n30_t* arr2){

    onumm1n30_t res = onumm1n30_init();

    oarrm1n30_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm1n30_t oarrm1n30_matmul_OO(oarrm1n30_t* arr1, oarrm1n30_t* arr2){

    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr1->nrows, arr2->ncols);

    oarrm1n30_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm1n30_t oarrm1n30_matmul_OR(oarrm1n30_t* arr1, darr_t* arr2){
        
    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr1->nrows, arr2->ncols);

    oarrm1n30_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm1n30_t oarrm1n30_matmul_RO(darr_t* arr1, oarrm1n30_t* arr2){
        
    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr1->nrows, arr2->ncols);

    oarrm1n30_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm1n30_t oarrm1n30_transpose(oarrm1n30_t* arr1){
        
    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr1->ncols, arr1->nrows);

    oarrm1n30_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm1n30_t oarrm1n30_invert(oarrm1n30_t* arr1){
    
    oarrm1n30_t res = oarrm1n30_init();

    res = oarrm1n30_zeros(arr1->ncols, arr1->nrows);

    oarrm1n30_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm1n30_t oarrm1n30_det(oarrm1n30_t* arr1){
    
    onumm1n30_t res = onumm1n30_init();

    oarrm1n30_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm1n30_t oarrm1n30_norm(oarrm1n30_t* arr1){
    
    onumm1n30_t res = onumm1n30_init();

    oarrm1n30_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n30_t oarrm1n30_pnorm(oarrm1n30_t* arr1, coeff_t p){
    
    onumm1n30_t res = onumm1n30_init();

    oarrm1n30_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

