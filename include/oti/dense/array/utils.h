#ifndef OTI_DENSE_ARRAY_UTILS_H
#define OTI_DENSE_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Helper for elementwise array array multiplication (at least one is OTI).

Performs, acordingly, multiplication of elementwise multiplication:

     RES = LHS * RHS

@param[in] lhs Left hand side array of operation
@param[in] rhs OTI number.
@param[in] res OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void dhelp_oarr_mul_RI(oarr_t* lhs,   oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_mul_RR(oarr_t* lhs,   oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void dhelp_oarr_mul_II(oarr_t* lhs, ord_t ord_lhs, // Left  hand side.
	                   oarr_t* rhs, ord_t ord_rhs, // Right hand side.
	                   oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Helper for scalar - array multiplication.

@param[in] LHS Left hand side of the operation.
@param[in] RHS Right hand side of the operation.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void dhelp_oarr_mul_rR(otinum_t* lhs,   oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void dhelp_oarr_mul_rI(otinum_t* lhs,   oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_mul_Ri(  oarr_t* lhs, otinum_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_mul_iI(otinum_t* lhs, ord_t ord_lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Helper for matrix multiplication

@param[in] lhs Left hand side of the operation.
@param[in] ord_lhs Left hand side order.
@param[in] rhs Right hand side of the operation.
@param[in] ord_rhs Right hand side order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void dhelp_oarr_matmul_II(oarr_t* lhs, ord_t ord_lhs,  // Input 1
                          oarr_t* rhs, ord_t ord_rhs,  // Input 2
                          oarr_t* res,                 // Result
                          dhelpl_t dhl);
void dhelp_oarr_matmul_IR(oarr_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_matmul_RI(oarr_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_matmul_RR(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Helper for truncated operations.

@param[in] 
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oarr_trc_self_mul_r( darr_t* a, ord_t ord, oarr_t* res, dhelpl_t dhl);
void oarr_trc_self_sum(   oarr_t* arr, ord_t ord, oarr_t* res, dhelpl_t dhl );
void oarr_trc_mul(        oarr_t* arr1, ord_t ord1, oarr_t* arr2, ord_t ord2, oarr_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Helper for truncated multiplication.

@param[in] LHS Left hand side of the operation.
@param[in] RHS Right hand side of the operation.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oarr_trunc_mul( oarr_t* lhs, ord_t ord_lhs, // LHS
	                 oarr_t* rhs, ord_t ord_rhs, // RHS
	                 oarr_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------


#endif