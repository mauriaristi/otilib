#ifndef OTI_DENSE_ARRAY_ALGEBRA_MATOPS_H
#define OTI_DENSE_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief  Determinant of a 2D array. Must be square.

res = DET ( ARR )

@param[in] arr OTI array. Must be square
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oarr_det(oarr_t* arr, dhelpl_t dhl);
void     oarr_det_to(oarr_t* arr, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Transpose of a 2D array.

RES = TRANSPOSE( ARR )

@param[in] arr OTI array.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_transpose(oarr_t* arr, dhelpl_t dhl);
void   oarr_transpose_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Inverse operation of a 2D array. Array must be square.

RES = ARR^(-1)

@param[in] arr OTI array. Must be square.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_invert(oarr_t* arr, dhelpl_t dhl);
void   oarr_invert_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix multiplication of two 2D arrays.  At least one of LHS or RHS arrays must be OTI array.

RES = MATMUL(LHS, RHS)

@param[in] LHS OTI array
@param[in] RHS OTI array
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_matmul_OO(oarr_t* lhs, oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_matmul_OR(oarr_t* lhs, darr_t* rhs, dhelpl_t dhl);
oarr_t oarr_matmul_RO(darr_t* lhs, oarr_t* rhs, dhelpl_t dhl);

void   oarr_matmul_OO_to(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_matmul_OR_to(oarr_t* lhs, darr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_matmul_RO_to(darr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif