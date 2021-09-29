// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
semiotin_t arrsso_dotproduct_OO(arrsso_t* arr1, arrsso_t* arr2,               dhelpl_t dhl){

    
    semiotin_t res = ssoti_init();

    arrsso_dotproduct_OO_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t arrsso_dotproduct_RO(darr_t* arr1, arrsso_t* arr2,               dhelpl_t dhl){

    semiotin_t res = ssoti_init();

    arrsso_dotproduct_RO_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


















// 2. Array operations.


// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
arrsso_t arrsso_matmul_OO(arrsso_t* arr1, arrsso_t* arr2, dhelpl_t dhl){

    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr1->nrows, arr2->ncols, 0, 0, dhl);

    arrsso_matmul_OO_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
arrsso_t arrsso_matmul_OR(arrsso_t* arr1, darr_t* arr2, dhelpl_t dhl){
        
    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr1->nrows, arr2->ncols, 0, 0, dhl);

    arrsso_matmul_OR_to( arr1, arr2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
arrsso_t arrsso_matmul_RO(darr_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
        
    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr1->nrows, arr2->ncols, 0, 0, dhl);

    arrsso_matmul_RO_to( arr1, arr2, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

















// 2.2. Transpose.
// ****************************************************************************************************
arrsso_t arrsso_transpose(arrsso_t* arr1, dhelpl_t dhl){
        
    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr1->ncols, arr1->nrows, 0, 0, dhl);

    arrsso_transpose_to( arr1, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------




















// 2.3. Inversion.
// ****************************************************************************************************
arrsso_t arrsso_invert(arrsso_t* arr1, dhelpl_t dhl){
    
    arrsso_t res = arrsso_init();

    res = arrsso_zeros_bases(arr1->ncols, arr1->nrows, 0, 0, dhl);

    arrsso_invert_to(arr1, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






















// 2.4. Determinant.

// ****************************************************************************************************
semiotin_t arrsso_det(arrsso_t* arr1, dhelpl_t dhl){
    
    semiotin_t res = ssoti_init();

    arrsso_det_to(arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------










// 2.5. Norm.

// ****************************************************************************************************
semiotin_t arrsso_norm(arrsso_t* arr1, dhelpl_t dhl){
    
    semiotin_t res = ssoti_init();

    arrsso_norm_to(arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t arrsso_pnorm(arrsso_t* arr1, coeff_t p, dhelpl_t dhl){
    
    semiotin_t res = ssoti_init();

    arrsso_pnorm_to(arr1, p, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------





