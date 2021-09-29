#ifndef OTI_SEMISPARSE_ARRAY_ALGEBRA_MATOPS_H
#define OTI_SEMISPARSE_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
semiotin_t arrsso_dotproduct_OO(    arrsso_t* lhs, arrsso_t* rhs,                 dhelpl_t dhl);
void      arrsso_dotproduct_OO_to( arrsso_t* lhs, arrsso_t* rhs, semiotin_t* res, dhelpl_t dhl);

semiotin_t arrsso_dotproduct_RO(     darr_t* lhs, arrsso_t* rhs,                 dhelpl_t dhl);
void      arrsso_dotproduct_RO_to(  darr_t* lhs, arrsso_t* rhs, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_matmul_OO(    arrsso_t* lhs, arrsso_t* rhs,               dhelpl_t dhl);
arrsso_t arrsso_matmul_OR(    arrsso_t* lhs,  darr_t* rhs,               dhelpl_t dhl);
arrsso_t arrsso_matmul_RO(     darr_t* lhs, arrsso_t* rhs,               dhelpl_t dhl);

void    arrsso_matmul_OO_to( arrsso_t* lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void    arrsso_matmul_OR_to( arrsso_t* lhs,  darr_t* rhs, arrsso_t* res, dhelpl_t dhl);
void    arrsso_matmul_RO_to(  darr_t* lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_transpose(    arrsso_t* arr1,               dhelpl_t dhl);
void    arrsso_transpose_to( arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_invert(    arrsso_t* arr1,               dhelpl_t dhl);
void    arrsso_invert_to( arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
semiotin_t arrsso_det(    arrsso_t* arr1,                 dhelpl_t dhl);
void      arrsso_det_to( arrsso_t* arr1, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
semiotin_t arrsso_norm(    arrsso_t* arr1,                  dhelpl_t dhl);
void      arrsso_norm_to( arrsso_t* arr1,  semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
semiotin_t arrsso_pnorm(    arrsso_t* arr1, coeff_t p,                 dhelpl_t dhl);
void      arrsso_pnorm_to( arrsso_t* arr1, coeff_t p, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif