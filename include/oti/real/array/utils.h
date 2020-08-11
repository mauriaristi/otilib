#ifndef OTI_REAL_UTILS_H
#define OTI_REAL_UTILS_H

/**************************************************************************************************//**
@brief Get the size of a slice.

@param[in] start Starting index of the slice.
@param[in] stop  Final index of the slice.
@param[in] step  Step of the slice.
******************************************************************************************************/ 
int64_t get_slice_size(int64_t start, int64_t stop, int64_t step);
// ----------------------------------------------------------------------------------------------------

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
void darr_set_slice_R( darr_t* arr, int64_t starti, int64_t stopi, int64_t stepi,
                       int64_t startj, int64_t stopj, int64_t stepj, darr_t* res   );
void darr_set_slice_r( coeff_t val, int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,darr_t* res   );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
******************************************************************************************************/ 
void darr_dimCheck_RR_samesize(darr_t* lhs, darr_t* rhs);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void darr_dimCheck_RR_elementwise(darr_t* lhs, darr_t* rhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void darr_dimCheck_RR_matmul( darr_t* lhs, darr_t* rhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] res Result
******************************************************************************************************/ 
void darr_dimCheck_R_squareness( darr_t* lhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] res Result
******************************************************************************************************/ 
void darr_dimCheck_R_transpose( darr_t* lhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------





#endif