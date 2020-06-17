

// 2. Array operations.


// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
arrso_t arrso_matmul_OO(arrso_t* arr1, arrso_t* arr2, dhelpl_t dhl){

    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr1->nrows, arr2->ncols, 0, 0, dhl);

    arrso_matmul_OO_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
arrso_t arrso_matmul_OR(arrso_t* arr1, darr_t* arr2, dhelpl_t dhl){
        
    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr1->nrows, arr2->ncols, 0, 0, dhl);

    arrso_matmul_OR_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
arrso_t arrso_matmul_RO(darr_t* arr1, arrso_t* arr2, dhelpl_t dhl){
        
    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr1->nrows, arr2->ncols, 0, 0, dhl);

    arrso_matmul_RO_to( arr1, arr2, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

















// 2.2. Transpose.
// ****************************************************************************************************
arrso_t arrso_transpose(arrso_t* arr1, dhelpl_t dhl){
        
    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr1->ncols, arr1->nrows, 0, 0, dhl);

    arrso_transpose_to( arr1, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------
















// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
sotinum_t arrso_dotproduct_OO(arrso_t* arr1, arrso_t* arr2,               dhelpl_t dhl){

    
    sotinum_t res = soti_init();

    arrso_dotproduct_OO_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t arrso_dotproduct_RO(darr_t* arr1, arrso_t* arr2,               dhelpl_t dhl){

    sotinum_t res = soti_init();

    arrso_dotproduct_RO_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------



// 2.3. Inversion.
// ****************************************************************************************************
arrso_t arrso_invert(arrso_t* arr1, dhelpl_t dhl){
    
    arrso_t res = arrso_init();

    res = arrso_zeros_bases(arr1->ncols, arr1->nrows, 0, 0, dhl);

    arrso_invert_to(arr1, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






















// 2.4. Determinant.

// ****************************************************************************************************
sotinum_t arrso_det(arrso_t* arr1, dhelpl_t dhl){
    
    sotinum_t res = soti_init();

    arrso_det_to(arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------










// 2.5. Norm.

// ****************************************************************************************************
sotinum_t arrso_norm(arrso_t* arr1, dhelpl_t dhl){
    
    sotinum_t res = soti_init();

    arrso_norm_to(arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t arrso_pnorm(arrso_t* arr1, coeff_t p, dhelpl_t dhl){
    
    sotinum_t res = soti_init();

    arrso_pnorm_to(arr1, p, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------





