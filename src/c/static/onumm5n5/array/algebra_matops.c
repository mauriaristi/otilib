// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm5n5_t oarrm5n5_dotproduct_OO(oarrm5n5_t* arr1, oarrm5n5_t* arr2){

    
    onumm5n5_t res = onumm5n5_init();

    oarrm5n5_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n5_t oarrm5n5_dotproduct_RO(darr_t* arr1, oarrm5n5_t* arr2){

    onumm5n5_t res = onumm5n5_init();

    oarrm5n5_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm5n5_t oarrm5n5_matmul_OO(oarrm5n5_t* arr1, oarrm5n5_t* arr2){

    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr1->nrows, arr2->ncols);

    oarrm5n5_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm5n5_t oarrm5n5_matmul_OR(oarrm5n5_t* arr1, darr_t* arr2){
        
    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr1->nrows, arr2->ncols);

    oarrm5n5_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm5n5_t oarrm5n5_matmul_RO(darr_t* arr1, oarrm5n5_t* arr2){
        
    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr1->nrows, arr2->ncols);

    oarrm5n5_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm5n5_t oarrm5n5_transpose(oarrm5n5_t* arr1){
        
    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr1->ncols, arr1->nrows);

    oarrm5n5_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm5n5_t oarrm5n5_invert(oarrm5n5_t* arr1){
    
    oarrm5n5_t res = oarrm5n5_init();

    res = oarrm5n5_zeros(arr1->ncols, arr1->nrows);

    oarrm5n5_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm5n5_t oarrm5n5_det(oarrm5n5_t* arr1){
    
    onumm5n5_t res = onumm5n5_init();

    oarrm5n5_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm5n5_t oarrm5n5_norm(oarrm5n5_t* arr1){
    
    onumm5n5_t res = onumm5n5_init();

    oarrm5n5_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n5_t oarrm5n5_pnorm(oarrm5n5_t* arr1, coeff_t p){
    
    onumm5n5_t res = onumm5n5_init();

    oarrm5n5_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

