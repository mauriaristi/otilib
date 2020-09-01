// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm4n4_t oarrm4n4_dotproduct_OO(oarrm4n4_t* arr1, oarrm4n4_t* arr2){

    
    onumm4n4_t res = onumm4n4_init();

    oarrm4n4_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n4_t oarrm4n4_dotproduct_RO(darr_t* arr1, oarrm4n4_t* arr2){

    onumm4n4_t res = onumm4n4_init();

    oarrm4n4_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm4n4_t oarrm4n4_matmul_OO(oarrm4n4_t* arr1, oarrm4n4_t* arr2){

    oarrm4n4_t res = oarrm4n4_init();

    res = oarrm4n4_zeros(arr1->nrows, arr2->ncols);

    oarrm4n4_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm4n4_t oarrm4n4_matmul_OR(oarrm4n4_t* arr1, darr_t* arr2){
        
    oarrm4n4_t res = oarrm4n4_init();

    res = oarrm4n4_zeros(arr1->nrows, arr2->ncols);

    oarrm4n4_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm4n4_t oarrm4n4_matmul_RO(darr_t* arr1, oarrm4n4_t* arr2){
        
    oarrm4n4_t res = oarrm4n4_init();

    res = oarrm4n4_zeros(arr1->nrows, arr2->ncols);

    oarrm4n4_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm4n4_t oarrm4n4_transpose(oarrm4n4_t* arr1){
        
    oarrm4n4_t res = oarrm4n4_init();

    res = oarrm4n4_zeros(arr1->ncols, arr1->nrows);

    oarrm4n4_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm4n4_t oarrm4n4_invert(oarrm4n4_t* arr1){
    
    oarrm4n4_t res = oarrm4n4_init();

    res = oarrm4n4_zeros(arr1->ncols, arr1->nrows);

    oarrm4n4_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm4n4_t oarrm4n4_det(oarrm4n4_t* arr1){
    
    onumm4n4_t res = onumm4n4_init();

    oarrm4n4_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm4n4_t oarrm4n4_norm(oarrm4n4_t* arr1){
    
    onumm4n4_t res = onumm4n4_init();

    oarrm4n4_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n4_t oarrm4n4_pnorm(oarrm4n4_t* arr1, coeff_t p){
    
    onumm4n4_t res = onumm4n4_init();

    oarrm4n4_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

