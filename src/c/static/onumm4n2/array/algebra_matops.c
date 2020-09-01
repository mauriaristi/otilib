// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm4n2_t oarrm4n2_dotproduct_OO(oarrm4n2_t* arr1, oarrm4n2_t* arr2){

    
    onumm4n2_t res = onumm4n2_init();

    oarrm4n2_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n2_t oarrm4n2_dotproduct_RO(darr_t* arr1, oarrm4n2_t* arr2){

    onumm4n2_t res = onumm4n2_init();

    oarrm4n2_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm4n2_t oarrm4n2_matmul_OO(oarrm4n2_t* arr1, oarrm4n2_t* arr2){

    oarrm4n2_t res = oarrm4n2_init();

    res = oarrm4n2_zeros(arr1->nrows, arr2->ncols);

    oarrm4n2_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm4n2_t oarrm4n2_matmul_OR(oarrm4n2_t* arr1, darr_t* arr2){
        
    oarrm4n2_t res = oarrm4n2_init();

    res = oarrm4n2_zeros(arr1->nrows, arr2->ncols);

    oarrm4n2_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm4n2_t oarrm4n2_matmul_RO(darr_t* arr1, oarrm4n2_t* arr2){
        
    oarrm4n2_t res = oarrm4n2_init();

    res = oarrm4n2_zeros(arr1->nrows, arr2->ncols);

    oarrm4n2_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm4n2_t oarrm4n2_transpose(oarrm4n2_t* arr1){
        
    oarrm4n2_t res = oarrm4n2_init();

    res = oarrm4n2_zeros(arr1->ncols, arr1->nrows);

    oarrm4n2_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm4n2_t oarrm4n2_invert(oarrm4n2_t* arr1){
    
    oarrm4n2_t res = oarrm4n2_init();

    res = oarrm4n2_zeros(arr1->ncols, arr1->nrows);

    oarrm4n2_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm4n2_t oarrm4n2_det(oarrm4n2_t* arr1){
    
    onumm4n2_t res = onumm4n2_init();

    oarrm4n2_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm4n2_t oarrm4n2_norm(oarrm4n2_t* arr1){
    
    onumm4n2_t res = onumm4n2_init();

    oarrm4n2_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n2_t oarrm4n2_pnorm(oarrm4n2_t* arr1, coeff_t p){
    
    onumm4n2_t res = onumm4n2_init();

    oarrm4n2_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

