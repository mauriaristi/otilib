#ifndef OTI_COMPLEX_ALGEBRA_H
#define OTI_COMPLEX_ALGEBRA_H



/**************************************************************************************************//**
@brief Negate an array. 

@param[in]    arr: Array.
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_neg(    carr_t* arr              );

void   carr_neg_to( carr_t* arr, carr_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise division of arrays. Must have same dimensions. 

RES = LHS / RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_div_RR(    carr_t* lhs, carr_t* rhs              );
carr_t carr_div_Rr(    carr_t* lhs, ccoeff_t rhs              );
carr_t carr_div_rR(    ccoeff_t lhs, carr_t* rhs              );

void   carr_div_RR_to( carr_t* lhs, carr_t* rhs, carr_t* res );
void   carr_div_Rr_to( carr_t* lhs, ccoeff_t rhs, carr_t* res );
void   carr_div_rR_to( ccoeff_t lhs, carr_t* rhs, carr_t* res );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise multiplication of arrays. Must have same dimensions. 

RES = LHS * RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_mul_RR(    carr_t* lhs, carr_t* rhs              );
void   carr_mul_RR_to( carr_t* lhs, carr_t* rhs, carr_t* res );

carr_t carr_mul_rR(    ccoeff_t lhs, carr_t* rhs              );
void   carr_mul_rR_to( ccoeff_t lhs, carr_t* rhs, carr_t* res );

carr_t carr_mul_Rr(    carr_t* lhs, ccoeff_t rhs              );
void   carr_mul_Rr_to( carr_t* lhs, ccoeff_t rhs, carr_t* res );

void carr_mul_and_selfsum_RR_to( carr_t* lhs, carr_t* rhs, carr_t* res);
void carr_mul_and_selfsum_rR_to( ccoeff_t lhs, carr_t* rhs, carr_t* res);
void carr_mul_and_selfsum_Rr_to( carr_t* lhs, ccoeff_t rhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise subtraction of arrays. Must have same dimensions. 

RES = LHS - RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
carr_t carr_sub_RR(    carr_t* lhs, carr_t* rhs             );
void   carr_sub_RR_to( carr_t* lhs, carr_t* rhs, carr_t* res);

carr_t carr_sub_Rr(carr_t* lhs, ccoeff_t rhs);
carr_t carr_sub_rR(ccoeff_t lhs, carr_t* rhs);

void carr_sub_Rr_to(carr_t* lhs, ccoeff_t rhs, carr_t* res);
void carr_sub_rR_to(ccoeff_t lhs, carr_t* rhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise addition of arrays. Must have same dimensions. 

RES = LHS + RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_sum_RR(    carr_t* lhs, carr_t* rhs              );
void   carr_sum_RR_to( carr_t* lhs, carr_t* rhs, carr_t* res );

carr_t carr_sum_rR(    ccoeff_t lhs, carr_t* rhs              );
void   carr_sum_rR_to( ccoeff_t lhs, carr_t* rhs, carr_t* res );

carr_t carr_sum_Rr(    carr_t* lhs, ccoeff_t rhs              );
void   carr_sum_Rr_to( carr_t* lhs, ccoeff_t rhs, carr_t* res );
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] res    result.
******************************************************************************************************/ 
ccoeff_t carr_dotproduct_RR(    carr_t* lhs, carr_t* rh              );
void    carr_dotproduct_RR_to( carr_t* lhs, carr_t* rh, ccoeff_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix multiplication between two arrays.

@param[in] lhs Left hand side array.
@param[in] rhs Right hand side array.
@param[inout] res: Resulting array.
******************************************************************************************************/
void carr_matmul_and_selfsum_RR_to(carr_t* lhs, carr_t* rhs, carr_t* res );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication between two arrays.

RES = MATMUL ( LHS, RHS ) 

@param[in] lhs Left hand side array.
@param[in] rhs Right hand side array.
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_matmul(    carr_t* lhs, carr_t* rhs               );
void   carr_matmul_to( carr_t* lhs, carr_t* rhs, carr_t* res );

carr_t carr_matmul_RR(    carr_t* lhs, carr_t* rhs               );
void   carr_matmul_RR_to( carr_t* lhs, carr_t* rhs, carr_t* res );

// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Transpose operation of a 2D array

RES = TRANSPOSE ( ARR )

@param[in] arr 2D array.
@param[inout] aRes: Resulting array.
******************************************************************************************************/
carr_t carr_transpose(    carr_t* arr             );
void   carr_transpose_to( carr_t* arr, carr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief 2D matrix invert operation

RES = ARR ^ (-1)

@param[in] arr Array to be inverted. Must be square.
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_invert(    carr_t* arr             );
void   carr_invert_to( carr_t* arr, carr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Determinant of a 2D arrat.

res = DET( ARR )

@param[in] arr Array to compute determinant. Must be square.
******************************************************************************************************/
ccoeff_t carr_det( carr_t* arr );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Norm of an array.

res = norm( ARR )

@param[in] arr Array to compute norm.
@param[in] p   Value that defines the norm.
******************************************************************************************************/
ccoeff_t carr_pnorm( carr_t* arr, ccoeff_t p );
ccoeff_t carr_norm(  carr_t* arr );

void carr_pnorm_to( carr_t* arr1, ccoeff_t p, ccoeff_t* res );
void carr_norm_to( carr_t* arr1, ccoeff_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise recursive negation of array type.

RES = - RES

@param[inout] res: Resulting array.
******************************************************************************************************/
void carr_self_neg(  carr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise recursive addition of array type.

RES = RES + RHS
@param[in] RHS
@param[inout] aRes: Resulting array.
******************************************************************************************************/
void carr_self_sum_R( carr_t* rhs, carr_t* res );
void carr_self_sum_r( ccoeff_t rhs, carr_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise recursive subtraction of array type.

RES = RES - RHS

@param[in] 
@param[inout] aRes: Resulting array.
******************************************************************************************************/
void carr_self_sub_R(carr_t* rhs, carr_t* res);
void carr_self_sub_r(ccoeff_t rhs, carr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise recursive multiplication of array type. 

RES = RES * RHS

@param[in] rhs
@param[inout] aRes: Resulting array.
******************************************************************************************************/
void carr_self_mul_R( carr_t* rhs, carr_t* res );
void carr_self_mul_r( ccoeff_t rhs, carr_t* res );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief General multiplication. 

RES = ARR1 * ARR2 + ARR3

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[inout] res: Resulting array.
******************************************************************************************************/
carr_t carr_gem_RR(   carr_t* arr1, carr_t* arr2, carr_t* arr3             );
carr_t carr_gem_rR(   ccoeff_t arr1, carr_t* arr2, carr_t* arr3             );

void   carr_gem_RR_to(carr_t* arr1, carr_t* arr2, carr_t* arr3, carr_t* res);
void   carr_gem_rR_to(ccoeff_t arr1, carr_t* arr2, carr_t* arr3, carr_t* res);
// ----------------------------------------------------------------------------------------------------




#endif