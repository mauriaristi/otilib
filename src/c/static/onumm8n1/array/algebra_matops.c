// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm8n1_t oarrm8n1_dotproduct_OO(oarrm8n1_t* arr1, oarrm8n1_t* arr2){

    
    onumm8n1_t res = onumm8n1_init();

    oarrm8n1_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm8n1_t oarrm8n1_dotproduct_RO(darr_t* arr1, oarrm8n1_t* arr2){

    onumm8n1_t res = onumm8n1_init();

    oarrm8n1_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm8n1_t oarrm8n1_matmul_OO(oarrm8n1_t* arr1, oarrm8n1_t* arr2){

    oarrm8n1_t res = oarrm8n1_init();

    res = oarrm8n1_zeros(arr1->nrows, arr2->ncols);

    oarrm8n1_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm8n1_t oarrm8n1_matmul_OR(oarrm8n1_t* arr1, darr_t* arr2){
        
    oarrm8n1_t res = oarrm8n1_init();

    res = oarrm8n1_zeros(arr1->nrows, arr2->ncols);

    oarrm8n1_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm8n1_t oarrm8n1_matmul_RO(darr_t* arr1, oarrm8n1_t* arr2){
        
    oarrm8n1_t res = oarrm8n1_init();

    res = oarrm8n1_zeros(arr1->nrows, arr2->ncols);

    oarrm8n1_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm8n1_t oarrm8n1_transpose(oarrm8n1_t* arr1){
        
    oarrm8n1_t res = oarrm8n1_init();

    res = oarrm8n1_zeros(arr1->ncols, arr1->nrows);

    oarrm8n1_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm8n1_t oarrm8n1_invert(oarrm8n1_t* arr1){
    
    oarrm8n1_t res = oarrm8n1_init();

    res = oarrm8n1_zeros(arr1->ncols, arr1->nrows);

    oarrm8n1_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm8n1_t oarrm8n1_det(oarrm8n1_t* arr1){
    
    onumm8n1_t res = onumm8n1_init();

    oarrm8n1_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm8n1_t oarrm8n1_norm(oarrm8n1_t* arr1){
    
    onumm8n1_t res = onumm8n1_init();

    oarrm8n1_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm8n1_t oarrm8n1_pnorm(oarrm8n1_t* arr1, coeff_t p){
    
    onumm8n1_t res = onumm8n1_init();

    oarrm8n1_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

