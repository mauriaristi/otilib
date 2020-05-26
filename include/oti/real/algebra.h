#ifndef OTI_REAL_ALGEBRA_H
#define OTI_REAL_ALGEBRA_H



/**************************************************************************************************//**
@brief Negate an array. 

@param[in]    arr: Array.
@param[inout] res: Resulting array.
******************************************************************************************************/
darr_t darr_neg(    darr_t* arr              );

void   darr_neg_to( darr_t* arr, darr_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise division of arrays. Must have same dimensions. 

RES = LHS / RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] res: Resulting array.
******************************************************************************************************/
darr_t darr_div_RR(    darr_t* lhs, darr_t* rhs              );
darr_t darr_div_Rr(    darr_t* lhs, coeff_t rhs              );
darr_t darr_div_rR(    coeff_t lhs, darr_t* rhs              );

void   darr_div_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
void   darr_div_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res );
void   darr_div_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise multiplication of arrays. Must have same dimensions. 

RES = LHS * RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] res: Resulting array.
******************************************************************************************************/
darr_t darr_mul_RR(    darr_t* lhs, darr_t* rhs              );
darr_t darr_mul_rR(    coeff_t lhs, darr_t* rhs              );

void   darr_mul_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
void   darr_mul_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );

void darr_mul_and_selfsum_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res);
void darr_mul_and_selfsum_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise subtraction of arrays. Must have same dimensions. 

RES = LHS - RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_sub_RR(    darr_t* lhs, darr_t* rhs             );
void   darr_sub_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res);

darr_t darr_sub_Rr(darr_t* lhs, coeff_t rhs);
darr_t darr_sub_rR(coeff_t lhs, darr_t* rhs);

void darr_sub_Rr_to(darr_t* lhs, coeff_t rhs, darr_t* res);
void darr_sub_rR_to(coeff_t lhs, darr_t* rhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise addition of arrays. Must have same dimensions. 

RES = LHS + RHS

@param[in] lhs: Left hand side of the operation.
@param[in] rhs: Right hand side of the operation.
@param[inout] res: Resulting array.
******************************************************************************************************/
darr_t darr_sum_RR(    darr_t* lhs, darr_t* rhs              );
void   darr_sum_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );

darr_t darr_sum_rR(    coeff_t lhs, darr_t* rhs              );
void   darr_sum_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
// ----------------------------------------------------------------------------------------------------





/**************************************************************************************************//**
@brief Matrix multiplication between two arrays.

@param[in] lhs Left hand side array.
@param[in] rhs Right hand side array.
@param[inout] res: Resulting array.
******************************************************************************************************/
void darr_matmul_and_selfsum_RR_to(darr_t* lhs, darr_t* rhs, darr_t* res );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication between two arrays.

RES = MATMUL ( LHS, RHS ) 

@param[in] lhs Left hand side array.
@param[in] rhs Right hand side array.
@param[inout] res: Resulting array.
******************************************************************************************************/
darr_t darr_matmul(    darr_t* lhs, darr_t* rhs               );
void   darr_matmul_to( darr_t* lhs, darr_t* rhs, darr_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Transpose operation of a 2D array

RES = TRANSPOSE ( ARR )

@param[in] arr 2D array.
@param[inout] aRes: Resulting array.
******************************************************************************************************/
darr_t darr_transpose(    darr_t* arr             );
void   darr_transpose_to( darr_t* arr, darr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief 2D matrix invert operation

RES = ARR ^ (-1)

@param[in] arr Array to be inverted. Must be square.
@param[inout] res: Resulting array.
******************************************************************************************************/
darr_t darr_invert(    darr_t* arr             );
void   darr_invert_to( darr_t* arr, darr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Determinant of a 2D arrat.

res = DET( ARR )

@param[in] arr Array to compute determinant. Must be square.
******************************************************************************************************/
coeff_t darr_det( darr_t* arr );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Norm of an array.

res = Norm( ARR )

@param[in] arr Array to compute norm.
@param[in] p   Value that defines the norm.
******************************************************************************************************/
coeff_t darr_pnorm( darr_t* arr, coeff_t p );
coeff_t darr_norm(  darr_t* arr );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise recursive negation of array type.

RES = - RES

@param[inout] res: Resulting array.
******************************************************************************************************/
void darr_self_neg(  darr_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise recursive addition of array type.

RES = RES + RHS
@param[in] RHS
@param[inout] aRes: Resulting array.
******************************************************************************************************/
void darr_self_sum_R( darr_t* rhs, darr_t* res );
void darr_self_sum_r( coeff_t rhs, darr_t* res );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise recursive subtraction of array type.

RES = RES - RHS

@param[in] 
@param[inout] aRes: Resulting array.
******************************************************************************************************/
void darr_self_sub_R(darr_t* rhs, darr_t* res);
void darr_self_sub_r(coeff_t rhs, darr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise recursive multiplication of array type. 

RES = RES * RHS

@param[in] rhs
@param[inout] aRes: Resulting array.
******************************************************************************************************/
void darr_self_mul_R( darr_t* rhs, darr_t* res );
void darr_self_mul_r( coeff_t rhs, darr_t* res );
// ----------------------------------------------------------------------------------------------------





#endif