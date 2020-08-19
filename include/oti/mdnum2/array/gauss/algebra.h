#ifndef OTI_MDNUM2_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM2_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_neg(    femdarr2_t* arr);
void      femdarr2_neg_to( femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_sum_FF(   femdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sum_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sum_fF(    femdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sum_fF_to( femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sum_OF(     mdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sum_OF_to(  mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sum_RF(      darr_t* lhs, femdarr2_t* rhs);
void      femdarr2_sum_RF_to(   darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sum_oF(   mdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sum_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sum_rF(     coeff_t  lhs, femdarr2_t* rhs);
void      femdarr2_sum_rF_to(  coeff_t  lhs, femdarr2_t* rhs, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_sub_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sub_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_fF(    femdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sub_fF_to( femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_Ff(    femdarr2_t* lhs, femdnum2_t* rhs);
void      femdarr2_sub_Ff_to( femdarr2_t* lhs, femdnum2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_OF(      mdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sub_OF_to(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_FO(    femdarr2_t* lhs,   mdarr2_t* rhs);
void      femdarr2_sub_FO_to( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_RF(       darr_t* lhs, femdarr2_t* rhs);
void      femdarr2_sub_RF_to(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_FR(    femdarr2_t* lhs,    darr_t* rhs);
void      femdarr2_sub_FR_to( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_oF(    mdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_sub_oF_to( mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_Fo(    femdarr2_t* lhs, mdnum2_t* rhs);
void      femdarr2_sub_Fo_to( femdarr2_t* lhs, mdnum2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_rF(      coeff_t  lhs, femdarr2_t* rhs);
void      femdarr2_sub_rF_to(    coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_sub_Fr(    femdarr2_t* lhs,   coeff_t  rhs);
void      femdarr2_sub_Fr_to( femdarr2_t* lhs,   coeff_t  rhs, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_mul_FF(   femdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_mul_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_mul_fF(    femdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_mul_fF_to( femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_mul_OF(     mdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_mul_OF_to(  mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_mul_RF(      darr_t* lhs, femdarr2_t* rhs);
void      femdarr2_mul_RF_to(   darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_mul_oF(   mdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_mul_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_mul_rF(     coeff_t  lhs, femdarr2_t* rhs);
void      femdarr2_mul_rF_to(  coeff_t  lhs, femdarr2_t* rhs, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr2_t femdarr2_div_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_div_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_fF(     femdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_div_fF_to(  femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_Ff(    femdarr2_t* lhs,  femdnum2_t* rhs);
void      femdarr2_div_Ff_to( femdarr2_t* lhs,  femdnum2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_OF(      mdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_div_OF_to(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_FO(    femdarr2_t* lhs,   mdarr2_t* rhs);
void      femdarr2_div_FO_to( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_RF(       darr_t* lhs, femdarr2_t* rhs);
void      femdarr2_div_RF_to(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_FR(    femdarr2_t* lhs,    darr_t* rhs);
void      femdarr2_div_FR_to( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_oF(    mdnum2_t* lhs, femdarr2_t* rhs);
void      femdarr2_div_oF_to( mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_Fo(    femdarr2_t* lhs, mdnum2_t* rhs);
void      femdarr2_div_Fo_to( femdarr2_t* lhs, mdnum2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_rF(      coeff_t  lhs, femdarr2_t* rhs);
void      femdarr2_div_rF_to(    coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_div_Fr(    femdarr2_t* lhs,   coeff_t  rhs);
void      femdarr2_div_Fr_to( femdarr2_t* lhs,   coeff_t  rhs, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr2_t femdarr2_integrate(    femdarr2_t* arr, femdnum2_t* w);
void    femdarr2_integrate_to( femdarr2_t* arr, femdnum2_t* w, mdarr2_t* res);
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
femdnum2_t femdarr2_dotproduct_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
void     femdarr2_dotproduct_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdnum2_t* res);

femdnum2_t femdarr2_dotproduct_OF(      mdarr2_t* lhs, femdarr2_t* rhs);
void     femdarr2_dotproduct_OF_to(   mdarr2_t* lhs, femdarr2_t* rhs, femdnum2_t* res);

femdnum2_t femdarr2_dotproduct_RF(       darr_t* lhs, femdarr2_t* rhs);
void     femdarr2_dotproduct_RF_to(    darr_t* lhs, femdarr2_t* rhs, femdnum2_t* res);
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
femdarr2_t femdarr2_matmul_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
void      femdarr2_matmul_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_matmul_OF(    mdarr2_t*   lhs, femdarr2_t* rhs);
void      femdarr2_matmul_OF_to( mdarr2_t*   lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_matmul_FO(    femdarr2_t* lhs, mdarr2_t*   rhs);
void      femdarr2_matmul_FO_to( femdarr2_t* lhs, mdarr2_t*   rhs, femdarr2_t* res);

femdarr2_t femdarr2_matmul_RF(    darr_t*    lhs, femdarr2_t* rhs);
void      femdarr2_matmul_RF_to( darr_t*    lhs, femdarr2_t* rhs, femdarr2_t* res);

femdarr2_t femdarr2_matmul_FR(    femdarr2_t* lhs, darr_t*    rhs);
void      femdarr2_matmul_FR_to( femdarr2_t* lhs, darr_t*    rhs, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum2_t femdarr2_det(   femdarr2_t* arr);
void     femdarr2_det_to(femdarr2_t* arr, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdarr2_norm(     femdarr2_t* arr);
void     femdarr2_norm_to(  femdarr2_t* arr, femdnum2_t* res);

femdnum2_t femdarr2_pnorm(    femdarr2_t* arr, coeff_t p);
void     femdarr2_pnorm_to( femdarr2_t* arr, coeff_t p, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr2_t   femdarr2_invert(    femdarr2_t* arr);
void        femdarr2_invert_to( femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr2_t   femdarr2_transpose(   femdarr2_t* arr);
void        femdarr2_transpose_to(femdarr2_t* arr, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif