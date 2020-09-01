#ifndef OTI_MDNUM4_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM4_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_neg(    femdarr4_t* arr);
void      femdarr4_neg_to( femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_sum_FF(   femdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sum_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sum_fF(    femdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sum_fF_to( femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sum_OF(     mdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sum_OF_to(  mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sum_RF(      darr_t* lhs, femdarr4_t* rhs);
void      femdarr4_sum_RF_to(   darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sum_oF(   mdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sum_oF_to(mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sum_rF(     coeff_t  lhs, femdarr4_t* rhs);
void      femdarr4_sum_rF_to(  coeff_t  lhs, femdarr4_t* rhs, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_sub_FF(    femdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sub_FF_to( femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_fF(    femdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sub_fF_to( femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_Ff(    femdarr4_t* lhs, femdnum4_t* rhs);
void      femdarr4_sub_Ff_to( femdarr4_t* lhs, femdnum4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_OF(      mdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sub_OF_to(   mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_FO(    femdarr4_t* lhs,   mdarr4_t* rhs);
void      femdarr4_sub_FO_to( femdarr4_t* lhs,   mdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_RF(       darr_t* lhs, femdarr4_t* rhs);
void      femdarr4_sub_RF_to(    darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_FR(    femdarr4_t* lhs,    darr_t* rhs);
void      femdarr4_sub_FR_to( femdarr4_t* lhs,    darr_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_oF(    mdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_sub_oF_to( mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_Fo(    femdarr4_t* lhs, mdnum4_t* rhs);
void      femdarr4_sub_Fo_to( femdarr4_t* lhs, mdnum4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_rF(      coeff_t  lhs, femdarr4_t* rhs);
void      femdarr4_sub_rF_to(    coeff_t lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_sub_Fr(    femdarr4_t* lhs,   coeff_t  rhs);
void      femdarr4_sub_Fr_to( femdarr4_t* lhs,   coeff_t  rhs, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_mul_FF(   femdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_mul_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_mul_fF(    femdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_mul_fF_to( femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_mul_OF(     mdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_mul_OF_to(  mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_mul_RF(      darr_t* lhs, femdarr4_t* rhs);
void      femdarr4_mul_RF_to(   darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_mul_oF(   mdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_mul_oF_to(mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_mul_rF(     coeff_t  lhs, femdarr4_t* rhs);
void      femdarr4_mul_rF_to(  coeff_t  lhs, femdarr4_t* rhs, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr4_t femdarr4_div_FF(    femdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_div_FF_to( femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_fF(     femdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_div_fF_to(  femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_Ff(    femdarr4_t* lhs,  femdnum4_t* rhs);
void      femdarr4_div_Ff_to( femdarr4_t* lhs,  femdnum4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_OF(      mdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_div_OF_to(   mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_FO(    femdarr4_t* lhs,   mdarr4_t* rhs);
void      femdarr4_div_FO_to( femdarr4_t* lhs,   mdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_RF(       darr_t* lhs, femdarr4_t* rhs);
void      femdarr4_div_RF_to(    darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_FR(    femdarr4_t* lhs,    darr_t* rhs);
void      femdarr4_div_FR_to( femdarr4_t* lhs,    darr_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_oF(    mdnum4_t* lhs, femdarr4_t* rhs);
void      femdarr4_div_oF_to( mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_Fo(    femdarr4_t* lhs, mdnum4_t* rhs);
void      femdarr4_div_Fo_to( femdarr4_t* lhs, mdnum4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_rF(      coeff_t  lhs, femdarr4_t* rhs);
void      femdarr4_div_rF_to(    coeff_t lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_div_Fr(    femdarr4_t* lhs,   coeff_t  rhs);
void      femdarr4_div_Fr_to( femdarr4_t* lhs,   coeff_t  rhs, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr4_t femdarr4_integrate(    femdarr4_t* arr, femdnum4_t* w);
void    femdarr4_integrate_to( femdarr4_t* arr, femdnum4_t* w, mdarr4_t* res);
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
femdnum4_t femdarr4_dotproduct_FF(    femdarr4_t* lhs, femdarr4_t* rhs);
void     femdarr4_dotproduct_FF_to( femdarr4_t* lhs, femdarr4_t* rhs, femdnum4_t* res);

femdnum4_t femdarr4_dotproduct_OF(      mdarr4_t* lhs, femdarr4_t* rhs);
void     femdarr4_dotproduct_OF_to(   mdarr4_t* lhs, femdarr4_t* rhs, femdnum4_t* res);

femdnum4_t femdarr4_dotproduct_RF(       darr_t* lhs, femdarr4_t* rhs);
void     femdarr4_dotproduct_RF_to(    darr_t* lhs, femdarr4_t* rhs, femdnum4_t* res);
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
femdarr4_t femdarr4_matmul_FF(    femdarr4_t* lhs, femdarr4_t* rhs);
void      femdarr4_matmul_FF_to( femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_matmul_OF(    mdarr4_t*   lhs, femdarr4_t* rhs);
void      femdarr4_matmul_OF_to( mdarr4_t*   lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_matmul_FO(    femdarr4_t* lhs, mdarr4_t*   rhs);
void      femdarr4_matmul_FO_to( femdarr4_t* lhs, mdarr4_t*   rhs, femdarr4_t* res);

femdarr4_t femdarr4_matmul_RF(    darr_t*    lhs, femdarr4_t* rhs);
void      femdarr4_matmul_RF_to( darr_t*    lhs, femdarr4_t* rhs, femdarr4_t* res);

femdarr4_t femdarr4_matmul_FR(    femdarr4_t* lhs, darr_t*    rhs);
void      femdarr4_matmul_FR_to( femdarr4_t* lhs, darr_t*    rhs, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum4_t femdarr4_det(   femdarr4_t* arr);
void     femdarr4_det_to(femdarr4_t* arr, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdarr4_norm(     femdarr4_t* arr);
void     femdarr4_norm_to(  femdarr4_t* arr, femdnum4_t* res);

femdnum4_t femdarr4_pnorm(    femdarr4_t* arr, coeff_t p);
void     femdarr4_pnorm_to( femdarr4_t* arr, coeff_t p, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr4_t   femdarr4_invert(    femdarr4_t* arr);
void        femdarr4_invert_to( femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr4_t   femdarr4_transpose(   femdarr4_t* arr);
void        femdarr4_transpose_to(femdarr4_t* arr, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif