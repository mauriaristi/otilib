// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm6n2_t oarrm6n2_dotproduct_OO(oarrm6n2_t* arr1, oarrm6n2_t* arr2){

    
    onumm6n2_t res = onumm6n2_init();

    oarrm6n2_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n2_t oarrm6n2_dotproduct_RO(darr_t* arr1, oarrm6n2_t* arr2){

    onumm6n2_t res = onumm6n2_init();

    oarrm6n2_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm6n2_t oarrm6n2_matmul_OO(oarrm6n2_t* arr1, oarrm6n2_t* arr2){

    oarrm6n2_t res = oarrm6n2_init();

    res = oarrm6n2_zeros(arr1->nrows, arr2->ncols);

    oarrm6n2_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm6n2_t oarrm6n2_matmul_OR(oarrm6n2_t* arr1, darr_t* arr2){
        
    oarrm6n2_t res = oarrm6n2_init();

    res = oarrm6n2_zeros(arr1->nrows, arr2->ncols);

    oarrm6n2_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm6n2_t oarrm6n2_matmul_RO(darr_t* arr1, oarrm6n2_t* arr2){
        
    oarrm6n2_t res = oarrm6n2_init();

    res = oarrm6n2_zeros(arr1->nrows, arr2->ncols);

    oarrm6n2_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm6n2_t oarrm6n2_transpose(oarrm6n2_t* arr1){
        
    oarrm6n2_t res = oarrm6n2_init();

    res = oarrm6n2_zeros(arr1->ncols, arr1->nrows);

    oarrm6n2_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm6n2_t oarrm6n2_invert(oarrm6n2_t* arr1){
    
    oarrm6n2_t res = oarrm6n2_init();

    res = oarrm6n2_zeros(arr1->ncols, arr1->nrows);

    oarrm6n2_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm6n2_t oarrm6n2_det(oarrm6n2_t* arr1){
    
    onumm6n2_t res = onumm6n2_init();

    oarrm6n2_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm6n2_t oarrm6n2_norm(oarrm6n2_t* arr1){
    
    onumm6n2_t res = onumm6n2_init();

    oarrm6n2_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n2_t oarrm6n2_pnorm(oarrm6n2_t* arr1, coeff_t p){
    
    onumm6n2_t res = onumm6n2_init();

    oarrm6n2_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

