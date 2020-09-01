#ifndef OTI_MDNUM7_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM7_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdarr7_dotproduct_OO(    mdarr7_t* lhs, mdarr7_t* rhs);
void      mdarr7_dotproduct_OO_to( mdarr7_t* lhs, mdarr7_t* rhs, mdnum7_t* res);

mdnum7_t mdarr7_dotproduct_RO(     darr_t* lhs, mdarr7_t* rhs);
void      mdarr7_dotproduct_RO_to(  darr_t* lhs, mdarr7_t* rhs, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr7_t mdarr7_matmul_OO(    mdarr7_t* lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_matmul_OR(    mdarr7_t* lhs,  darr_t* rhs);
mdarr7_t mdarr7_matmul_RO(     darr_t* lhs, mdarr7_t* rhs);

void    mdarr7_matmul_OO_to( mdarr7_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
void    mdarr7_matmul_OR_to( mdarr7_t* lhs,  darr_t* rhs, mdarr7_t* res);
void    mdarr7_matmul_RO_to(  darr_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr7_t mdarr7_transpose(    mdarr7_t* arr1);
void    mdarr7_transpose_to( mdarr7_t* arr1, mdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr7_t mdarr7_invert(    mdarr7_t* arr1);
void    mdarr7_invert_to( mdarr7_t* arr1, mdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdarr7_det(    mdarr7_t* arr1);
void      mdarr7_det_to( mdarr7_t* arr1, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdarr7_norm(    mdarr7_t* arr1);
void      mdarr7_norm_to( mdarr7_t* arr1,  mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdarr7_pnorm(    mdarr7_t* arr1, coeff_t p);
void      mdarr7_pnorm_to( mdarr7_t* arr1, coeff_t p, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif