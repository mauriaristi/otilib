// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm10n1_t oarrm10n1_dotproduct_OO(oarrm10n1_t* arr1, oarrm10n1_t* arr2){

    
    onumm10n1_t res = onumm10n1_init();

    oarrm10n1_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm10n1_t oarrm10n1_dotproduct_RO(darr_t* arr1, oarrm10n1_t* arr2){

    onumm10n1_t res = onumm10n1_init();

    oarrm10n1_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm10n1_t oarrm10n1_matmul_OO(oarrm10n1_t* arr1, oarrm10n1_t* arr2){

    oarrm10n1_t res = oarrm10n1_init();

    res = oarrm10n1_zeros(arr1->nrows, arr2->ncols);

    oarrm10n1_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm10n1_t oarrm10n1_matmul_OR(oarrm10n1_t* arr1, darr_t* arr2){
        
    oarrm10n1_t res = oarrm10n1_init();

    res = oarrm10n1_zeros(arr1->nrows, arr2->ncols);

    oarrm10n1_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm10n1_t oarrm10n1_matmul_RO(darr_t* arr1, oarrm10n1_t* arr2){
        
    oarrm10n1_t res = oarrm10n1_init();

    res = oarrm10n1_zeros(arr1->nrows, arr2->ncols);

    oarrm10n1_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm10n1_t oarrm10n1_transpose(oarrm10n1_t* arr1){
        
    oarrm10n1_t res = oarrm10n1_init();

    res = oarrm10n1_zeros(arr1->ncols, arr1->nrows);

    oarrm10n1_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm10n1_t oarrm10n1_invert(oarrm10n1_t* arr1){
    
    oarrm10n1_t res = oarrm10n1_init();

    res = oarrm10n1_zeros(arr1->ncols, arr1->nrows);

    oarrm10n1_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm10n1_t oarrm10n1_det(oarrm10n1_t* arr1){
    
    onumm10n1_t res = onumm10n1_init();

    oarrm10n1_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm10n1_t oarrm10n1_norm(oarrm10n1_t* arr1){
    
    onumm10n1_t res = onumm10n1_init();

    oarrm10n1_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm10n1_t oarrm10n1_pnorm(oarrm10n1_t* arr1, coeff_t p){
    
    onumm10n1_t res = onumm10n1_init();

    oarrm10n1_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

