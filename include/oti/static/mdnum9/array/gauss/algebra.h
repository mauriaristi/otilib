#ifndef OTI_MDNUM9_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM9_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_neg(    femdarr9_t* arr);
void      femdarr9_neg_to( femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_sum_FF(   femdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sum_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sum_fF(    femdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sum_fF_to( femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sum_OF(     mdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sum_OF_to(  mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sum_RF(      darr_t* lhs, femdarr9_t* rhs);
void      femdarr9_sum_RF_to(   darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sum_oF(   mdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sum_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sum_rF(     coeff_t  lhs, femdarr9_t* rhs);
void      femdarr9_sum_rF_to(  coeff_t  lhs, femdarr9_t* rhs, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_sub_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sub_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_fF(    femdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sub_fF_to( femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_Ff(    femdarr9_t* lhs, femdnum9_t* rhs);
void      femdarr9_sub_Ff_to( femdarr9_t* lhs, femdnum9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_OF(      mdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sub_OF_to(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_FO(    femdarr9_t* lhs,   mdarr9_t* rhs);
void      femdarr9_sub_FO_to( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_RF(       darr_t* lhs, femdarr9_t* rhs);
void      femdarr9_sub_RF_to(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_FR(    femdarr9_t* lhs,    darr_t* rhs);
void      femdarr9_sub_FR_to( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_oF(    mdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_sub_oF_to( mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_Fo(    femdarr9_t* lhs, mdnum9_t* rhs);
void      femdarr9_sub_Fo_to( femdarr9_t* lhs, mdnum9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_rF(      coeff_t  lhs, femdarr9_t* rhs);
void      femdarr9_sub_rF_to(    coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_sub_Fr(    femdarr9_t* lhs,   coeff_t  rhs);
void      femdarr9_sub_Fr_to( femdarr9_t* lhs,   coeff_t  rhs, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_mul_FF(   femdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_mul_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_mul_fF(    femdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_mul_fF_to( femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_mul_OF(     mdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_mul_OF_to(  mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_mul_RF(      darr_t* lhs, femdarr9_t* rhs);
void      femdarr9_mul_RF_to(   darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_mul_oF(   mdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_mul_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_mul_rF(     coeff_t  lhs, femdarr9_t* rhs);
void      femdarr9_mul_rF_to(  coeff_t  lhs, femdarr9_t* rhs, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr9_t femdarr9_div_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_div_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_fF(     femdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_div_fF_to(  femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_Ff(    femdarr9_t* lhs,  femdnum9_t* rhs);
void      femdarr9_div_Ff_to( femdarr9_t* lhs,  femdnum9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_OF(      mdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_div_OF_to(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_FO(    femdarr9_t* lhs,   mdarr9_t* rhs);
void      femdarr9_div_FO_to( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_RF(       darr_t* lhs, femdarr9_t* rhs);
void      femdarr9_div_RF_to(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_FR(    femdarr9_t* lhs,    darr_t* rhs);
void      femdarr9_div_FR_to( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_oF(    mdnum9_t* lhs, femdarr9_t* rhs);
void      femdarr9_div_oF_to( mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_Fo(    femdarr9_t* lhs, mdnum9_t* rhs);
void      femdarr9_div_Fo_to( femdarr9_t* lhs, mdnum9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_rF(      coeff_t  lhs, femdarr9_t* rhs);
void      femdarr9_div_rF_to(    coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_div_Fr(    femdarr9_t* lhs,   coeff_t  rhs);
void      femdarr9_div_Fr_to( femdarr9_t* lhs,   coeff_t  rhs, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr9_t femdarr9_integrate(    femdarr9_t* arr, femdnum9_t* w);
void    femdarr9_integrate_to( femdarr9_t* arr, femdnum9_t* w, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

// VECTOR ALGEBRA

/**************************************************************************************************//**
@brief Dot product between two vectors

RES = DOT_PRODUCT( LHS, RHS )

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum9_t femdarr9_dotproduct_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
void     femdarr9_dotproduct_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdnum9_t* res);

femdnum9_t femdarr9_dotproduct_OF(      mdarr9_t* lhs, femdarr9_t* rhs);
void     femdarr9_dotproduct_OF_to(   mdarr9_t* lhs, femdarr9_t* rhs, femdnum9_t* res);

femdnum9_t femdarr9_dotproduct_RF(       darr_t* lhs, femdarr9_t* rhs);
void     femdarr9_dotproduct_RF_to(    darr_t* lhs, femdarr9_t* rhs, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

// MATRIX ALGEBRA.

/**************************************************************************************************//**
@brief Matrix multiplication

RES = MATMUL( LHS, RHS )

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr9_t femdarr9_matmul_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
void      femdarr9_matmul_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_matmul_OF(    mdarr9_t*   lhs, femdarr9_t* rhs);
void      femdarr9_matmul_OF_to( mdarr9_t*   lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_matmul_FO(    femdarr9_t* lhs, mdarr9_t*   rhs);
void      femdarr9_matmul_FO_to( femdarr9_t* lhs, mdarr9_t*   rhs, femdarr9_t* res);

femdarr9_t femdarr9_matmul_RF(    darr_t*    lhs, femdarr9_t* rhs);
void      femdarr9_matmul_RF_to( darr_t*    lhs, femdarr9_t* rhs, femdarr9_t* res);

femdarr9_t femdarr9_matmul_FR(    femdarr9_t* lhs, darr_t*    rhs);
void      femdarr9_matmul_FR_to( femdarr9_t* lhs, darr_t*    rhs, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum9_t femdarr9_det(   femdarr9_t* arr);
void     femdarr9_det_to(femdarr9_t* arr, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdarr9_norm(     femdarr9_t* arr);
void     femdarr9_norm_to(  femdarr9_t* arr, femdnum9_t* res);

femdnum9_t femdarr9_pnorm(    femdarr9_t* arr, coeff_t p);
void     femdarr9_pnorm_to( femdarr9_t* arr, coeff_t p, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr9_t   femdarr9_invert(    femdarr9_t* arr);
void        femdarr9_invert_to( femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr9_t   femdarr9_transpose(   femdarr9_t* arr);
void        femdarr9_transpose_to(femdarr9_t* arr, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif