// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm2n9_t oarrm2n9_dotproduct_OO(oarrm2n9_t* arr1, oarrm2n9_t* arr2){

    
    onumm2n9_t res = onumm2n9_init();

    oarrm2n9_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n9_t oarrm2n9_dotproduct_RO(darr_t* arr1, oarrm2n9_t* arr2){

    onumm2n9_t res = onumm2n9_init();

    oarrm2n9_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm2n9_t oarrm2n9_matmul_OO(oarrm2n9_t* arr1, oarrm2n9_t* arr2){

    oarrm2n9_t res = oarrm2n9_init();

    res = oarrm2n9_zeros(arr1->nrows, arr2->ncols);

    oarrm2n9_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm2n9_t oarrm2n9_matmul_OR(oarrm2n9_t* arr1, darr_t* arr2){
        
    oarrm2n9_t res = oarrm2n9_init();

    res = oarrm2n9_zeros(arr1->nrows, arr2->ncols);

    oarrm2n9_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm2n9_t oarrm2n9_matmul_RO(darr_t* arr1, oarrm2n9_t* arr2){
        
    oarrm2n9_t res = oarrm2n9_init();

    res = oarrm2n9_zeros(arr1->nrows, arr2->ncols);

    oarrm2n9_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm2n9_t oarrm2n9_transpose(oarrm2n9_t* arr1){
        
    oarrm2n9_t res = oarrm2n9_init();

    res = oarrm2n9_zeros(arr1->ncols, arr1->nrows);

    oarrm2n9_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm2n9_t oarrm2n9_invert(oarrm2n9_t* arr1){
    
    oarrm2n9_t res = oarrm2n9_init();

    res = oarrm2n9_zeros(arr1->ncols, arr1->nrows);

    oarrm2n9_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm2n9_t oarrm2n9_det(oarrm2n9_t* arr1){
    
    onumm2n9_t res = onumm2n9_init();

    oarrm2n9_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm2n9_t oarrm2n9_norm(oarrm2n9_t* arr1){
    
    onumm2n9_t res = onumm2n9_init();

    oarrm2n9_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n9_t oarrm2n9_pnorm(oarrm2n9_t* arr1, coeff_t p){
    
    onumm2n9_t res = onumm2n9_init();

    oarrm2n9_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

