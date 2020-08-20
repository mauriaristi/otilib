// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm20n1_t oarrm20n1_dotproduct_OO(oarrm20n1_t* arr1, oarrm20n1_t* arr2){

    
    onumm20n1_t res = onumm20n1_init();

    oarrm20n1_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm20n1_t oarrm20n1_dotproduct_RO(darr_t* arr1, oarrm20n1_t* arr2){

    onumm20n1_t res = onumm20n1_init();

    oarrm20n1_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm20n1_t oarrm20n1_matmul_OO(oarrm20n1_t* arr1, oarrm20n1_t* arr2){

    oarrm20n1_t res = oarrm20n1_init();

    res = oarrm20n1_zeros(arr1->nrows, arr2->ncols);

    oarrm20n1_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm20n1_t oarrm20n1_matmul_OR(oarrm20n1_t* arr1, darr_t* arr2){
        
    oarrm20n1_t res = oarrm20n1_init();

    res = oarrm20n1_zeros(arr1->nrows, arr2->ncols);

    oarrm20n1_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm20n1_t oarrm20n1_matmul_RO(darr_t* arr1, oarrm20n1_t* arr2){
        
    oarrm20n1_t res = oarrm20n1_init();

    res = oarrm20n1_zeros(arr1->nrows, arr2->ncols);

    oarrm20n1_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm20n1_t oarrm20n1_transpose(oarrm20n1_t* arr1){
        
    oarrm20n1_t res = oarrm20n1_init();

    res = oarrm20n1_zeros(arr1->ncols, arr1->nrows);

    oarrm20n1_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm20n1_t oarrm20n1_invert(oarrm20n1_t* arr1){
    
    oarrm20n1_t res = oarrm20n1_init();

    res = oarrm20n1_zeros(arr1->ncols, arr1->nrows);

    oarrm20n1_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm20n1_t oarrm20n1_det(oarrm20n1_t* arr1){
    
    onumm20n1_t res = onumm20n1_init();

    oarrm20n1_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm20n1_t oarrm20n1_norm(oarrm20n1_t* arr1){
    
    onumm20n1_t res = onumm20n1_init();

    oarrm20n1_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm20n1_t oarrm20n1_pnorm(oarrm20n1_t* arr1, coeff_t p){
    
    onumm20n1_t res = onumm20n1_init();

    oarrm20n1_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

