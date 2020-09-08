// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm7n2_t oarrm7n2_dotproduct_OO(oarrm7n2_t* arr1, oarrm7n2_t* arr2){

    
    onumm7n2_t res = onumm7n2_init();

    oarrm7n2_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm7n2_t oarrm7n2_dotproduct_RO(darr_t* arr1, oarrm7n2_t* arr2){

    onumm7n2_t res = onumm7n2_init();

    oarrm7n2_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm7n2_t oarrm7n2_matmul_OO(oarrm7n2_t* arr1, oarrm7n2_t* arr2){

    oarrm7n2_t res = oarrm7n2_init();

    res = oarrm7n2_zeros(arr1->nrows, arr2->ncols);

    oarrm7n2_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm7n2_t oarrm7n2_matmul_OR(oarrm7n2_t* arr1, darr_t* arr2){
        
    oarrm7n2_t res = oarrm7n2_init();

    res = oarrm7n2_zeros(arr1->nrows, arr2->ncols);

    oarrm7n2_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm7n2_t oarrm7n2_matmul_RO(darr_t* arr1, oarrm7n2_t* arr2){
        
    oarrm7n2_t res = oarrm7n2_init();

    res = oarrm7n2_zeros(arr1->nrows, arr2->ncols);

    oarrm7n2_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm7n2_t oarrm7n2_transpose(oarrm7n2_t* arr1){
        
    oarrm7n2_t res = oarrm7n2_init();

    res = oarrm7n2_zeros(arr1->ncols, arr1->nrows);

    oarrm7n2_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm7n2_t oarrm7n2_invert(oarrm7n2_t* arr1){
    
    oarrm7n2_t res = oarrm7n2_init();

    res = oarrm7n2_zeros(arr1->ncols, arr1->nrows);

    oarrm7n2_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm7n2_t oarrm7n2_det(oarrm7n2_t* arr1){
    
    onumm7n2_t res = onumm7n2_init();

    oarrm7n2_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm7n2_t oarrm7n2_norm(oarrm7n2_t* arr1){
    
    onumm7n2_t res = onumm7n2_init();

    oarrm7n2_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm7n2_t oarrm7n2_pnorm(oarrm7n2_t* arr1, coeff_t p){
    
    onumm7n2_t res = onumm7n2_init();

    oarrm7n2_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

