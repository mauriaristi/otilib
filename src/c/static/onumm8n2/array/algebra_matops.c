// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
onumm8n2_t oarrm8n2_dotproduct_OO(oarrm8n2_t* arr1, oarrm8n2_t* arr2){

    
    onumm8n2_t res = onumm8n2_init();

    oarrm8n2_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm8n2_t oarrm8n2_dotproduct_RO(darr_t* arr1, oarrm8n2_t* arr2){

    onumm8n2_t res = onumm8n2_init();

    oarrm8n2_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarrm8n2_t oarrm8n2_matmul_OO(oarrm8n2_t* arr1, oarrm8n2_t* arr2){

    oarrm8n2_t res = oarrm8n2_init();

    res = oarrm8n2_zeros(arr1->nrows, arr2->ncols);

    oarrm8n2_matmul_OO_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarrm8n2_t oarrm8n2_matmul_OR(oarrm8n2_t* arr1, darr_t* arr2){
        
    oarrm8n2_t res = oarrm8n2_init();

    res = oarrm8n2_zeros(arr1->nrows, arr2->ncols);

    oarrm8n2_matmul_OR_to( arr1, arr2, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarrm8n2_t oarrm8n2_matmul_RO(darr_t* arr1, oarrm8n2_t* arr2){
        
    oarrm8n2_t res = oarrm8n2_init();

    res = oarrm8n2_zeros(arr1->nrows, arr2->ncols);

    oarrm8n2_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
oarrm8n2_t oarrm8n2_transpose(oarrm8n2_t* arr1){
        
    oarrm8n2_t res = oarrm8n2_init();

    res = oarrm8n2_zeros(arr1->ncols, arr1->nrows);

    oarrm8n2_transpose_to( arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
oarrm8n2_t oarrm8n2_invert(oarrm8n2_t* arr1){
    
    oarrm8n2_t res = oarrm8n2_init();

    res = oarrm8n2_zeros(arr1->ncols, arr1->nrows);

    oarrm8n2_invert_to(arr1, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
onumm8n2_t oarrm8n2_det(oarrm8n2_t* arr1){
    
    onumm8n2_t res = onumm8n2_init();

    oarrm8n2_det_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.

// ****************************************************************************************************
onumm8n2_t oarrm8n2_norm(oarrm8n2_t* arr1){
    
    onumm8n2_t res = onumm8n2_init();

    oarrm8n2_norm_to(arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm8n2_t oarrm8n2_pnorm(oarrm8n2_t* arr1, coeff_t p){
    
    onumm8n2_t res = onumm8n2_init();

    oarrm8n2_pnorm_to(arr1, p, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

