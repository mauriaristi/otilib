#ifndef OTI_COMPLEX_UTILS_H
#define OTI_COMPLEX_UTILS_H


/**************************************************************************************************//**
@brief Set slice to darr object.

@param[in]    arr    Value to set in res array.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
******************************************************************************************************/ 
void carr_set_slice_R( carr_t* arr, int64_t starti, int64_t stopi, int64_t stepi,
                       int64_t startj, int64_t stopj, int64_t stepj, carr_t* res   );
void carr_set_slice_r( coeff_t val, int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,carr_t* res   );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
******************************************************************************************************/ 
void carr_dimCheck_RR_samesize(carr_t* lhs, carr_t* rhs);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void carr_dimCheck_RR_elementwise(carr_t* lhs, carr_t* rhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void carr_dimCheck_RR_matmul( carr_t* lhs, carr_t* rhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] res Result
******************************************************************************************************/ 
void carr_dimCheck_R_squareness( carr_t* lhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] res Result
******************************************************************************************************/ 
void carr_dimCheck_R_transpose( carr_t* lhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

#endif