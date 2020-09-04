// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm6n1_t oarrm6n1_dotproduct_OO(oarrm6n1_t* arr1, oarrm6n1_t* arr2){

    
    onumm6n1_t res = onumm6n1_init();

    oarrm6n1_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n1_t oarrm6n1_dotproduct_RO(darr_t* arr1, oarrm6n1_t* arr2){

    onumm6n1_t res = onumm6n1_init();

    oarrm6n1_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm6n1_t oarrm6n1_matmul_OO(oarrm6n1_t* arr1, oarrm6n1_t* arr2){

    oarrm6n1_t res = oarrm6n1_init();

    res = oarrm6n1_zeros(arr1->nrows, arr2->ncols);

    oarrm6n1_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm6n1_t oarrm6n1_matmul_OR(oarrm6n1_t* arr1, darr_t* arr2){
        
    oarrm6n1_t res = oarrm6n1_init();

    res = oarrm6n1_zeros(arr1->nrows, arr2->ncols);

    oarrm6n1_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm6n1_t oarrm6n1_matmul_RO(darr_t* arr1, oarrm6n1_t* arr2){
        
    oarrm6n1_t res = oarrm6n1_init();

    res = oarrm6n1_zeros(arr1->nrows, arr2->ncols);

    oarrm6n1_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm6n1_t oarrm6n1_transpose(oarrm6n1_t* arr1){
        
    oarrm6n1_t res = oarrm6n1_init();

    res = oarrm6n1_zeros(arr1->ncols, arr1->nrows);

    oarrm6n1_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm6n1_t oarrm6n1_invert(oarrm6n1_t* arr1){
    
    oarrm6n1_t res = oarrm6n1_init();

    res = oarrm6n1_zeros(arr1->ncols, arr1->nrows);

    oarrm6n1_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm6n1_t oarrm6n1_det(oarrm6n1_t* arr1){
    
    onumm6n1_t res = onumm6n1_init();

    oarrm6n1_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm6n1_t oarrm6n1_norm(oarrm6n1_t* arr1){
    
    onumm6n1_t res = onumm6n1_init();

    oarrm6n1_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n1_t oarrm6n1_pnorm(oarrm6n1_t* arr1, coeff_t p){
    
    onumm6n1_t res = onumm6n1_init();

    oarrm6n1_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

