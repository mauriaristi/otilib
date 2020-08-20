#ifndef OTI_MDNUM5_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM5_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_neg(    femdarr5_t* arr);
void      femdarr5_neg_to( femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_sum_FF(   femdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sum_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sum_fF(    femdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sum_fF_to( femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sum_OF(     mdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sum_OF_to(  mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sum_RF(      darr_t* lhs, femdarr5_t* rhs);
void      femdarr5_sum_RF_to(   darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sum_oF(   mdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sum_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sum_rF(     coeff_t  lhs, femdarr5_t* rhs);
void      femdarr5_sum_rF_to(  coeff_t  lhs, femdarr5_t* rhs, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_sub_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sub_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_fF(    femdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sub_fF_to( femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_Ff(    femdarr5_t* lhs, femdnum5_t* rhs);
void      femdarr5_sub_Ff_to( femdarr5_t* lhs, femdnum5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_OF(      mdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sub_OF_to(   mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_FO(    femdarr5_t* lhs,   mdarr5_t* rhs);
void      femdarr5_sub_FO_to( femdarr5_t* lhs,   mdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_RF(       darr_t* lhs, femdarr5_t* rhs);
void      femdarr5_sub_RF_to(    darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_FR(    femdarr5_t* lhs,    darr_t* rhs);
void      femdarr5_sub_FR_to( femdarr5_t* lhs,    darr_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_oF(    mdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_sub_oF_to( mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_Fo(    femdarr5_t* lhs, mdnum5_t* rhs);
void      femdarr5_sub_Fo_to( femdarr5_t* lhs, mdnum5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_rF(      coeff_t  lhs, femdarr5_t* rhs);
void      femdarr5_sub_rF_to(    coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_sub_Fr(    femdarr5_t* lhs,   coeff_t  rhs);
void      femdarr5_sub_Fr_to( femdarr5_t* lhs,   coeff_t  rhs, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_mul_FF(   femdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_mul_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_mul_fF(    femdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_mul_fF_to( femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_mul_OF(     mdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_mul_OF_to(  mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_mul_RF(      darr_t* lhs, femdarr5_t* rhs);
void      femdarr5_mul_RF_to(   darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_mul_oF(   mdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_mul_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_mul_rF(     coeff_t  lhs, femdarr5_t* rhs);
void      femdarr5_mul_rF_to(  coeff_t  lhs, femdarr5_t* rhs, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr5_t femdarr5_div_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_div_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_fF(     femdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_div_fF_to(  femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_Ff(    femdarr5_t* lhs,  femdnum5_t* rhs);
void      femdarr5_div_Ff_to( femdarr5_t* lhs,  femdnum5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_OF(      mdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_div_OF_to(   mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_FO(    femdarr5_t* lhs,   mdarr5_t* rhs);
void      femdarr5_div_FO_to( femdarr5_t* lhs,   mdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_RF(       darr_t* lhs, femdarr5_t* rhs);
void      femdarr5_div_RF_to(    darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_FR(    femdarr5_t* lhs,    darr_t* rhs);
void      femdarr5_div_FR_to( femdarr5_t* lhs,    darr_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_oF(    mdnum5_t* lhs, femdarr5_t* rhs);
void      femdarr5_div_oF_to( mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_Fo(    femdarr5_t* lhs, mdnum5_t* rhs);
void      femdarr5_div_Fo_to( femdarr5_t* lhs, mdnum5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_rF(      coeff_t  lhs, femdarr5_t* rhs);
void      femdarr5_div_rF_to(    coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_div_Fr(    femdarr5_t* lhs,   coeff_t  rhs);
void      femdarr5_div_Fr_to( femdarr5_t* lhs,   coeff_t  rhs, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr5_t femdarr5_integrate(    femdarr5_t* arr, femdnum5_t* w);
void    femdarr5_integrate_to( femdarr5_t* arr, femdnum5_t* w, mdarr5_t* res);
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
femdnum5_t femdarr5_dotproduct_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
void     femdarr5_dotproduct_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdnum5_t* res);

femdnum5_t femdarr5_dotproduct_OF(      mdarr5_t* lhs, femdarr5_t* rhs);
void     femdarr5_dotproduct_OF_to(   mdarr5_t* lhs, femdarr5_t* rhs, femdnum5_t* res);

femdnum5_t femdarr5_dotproduct_RF(       darr_t* lhs, femdarr5_t* rhs);
void     femdarr5_dotproduct_RF_to(    darr_t* lhs, femdarr5_t* rhs, femdnum5_t* res);
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
femdarr5_t femdarr5_matmul_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
void      femdarr5_matmul_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_matmul_OF(    mdarr5_t*   lhs, femdarr5_t* rhs);
void      femdarr5_matmul_OF_to( mdarr5_t*   lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_matmul_FO(    femdarr5_t* lhs, mdarr5_t*   rhs);
void      femdarr5_matmul_FO_to( femdarr5_t* lhs, mdarr5_t*   rhs, femdarr5_t* res);

femdarr5_t femdarr5_matmul_RF(    darr_t*    lhs, femdarr5_t* rhs);
void      femdarr5_matmul_RF_to( darr_t*    lhs, femdarr5_t* rhs, femdarr5_t* res);

femdarr5_t femdarr5_matmul_FR(    femdarr5_t* lhs, darr_t*    rhs);
void      femdarr5_matmul_FR_to( femdarr5_t* lhs, darr_t*    rhs, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum5_t femdarr5_det(   femdarr5_t* arr);
void     femdarr5_det_to(femdarr5_t* arr, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdarr5_norm(     femdarr5_t* arr);
void     femdarr5_norm_to(  femdarr5_t* arr, femdnum5_t* res);

femdnum5_t femdarr5_pnorm(    femdarr5_t* arr, coeff_t p);
void     femdarr5_pnorm_to( femdarr5_t* arr, coeff_t p, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr5_t   femdarr5_invert(    femdarr5_t* arr);
void        femdarr5_invert_to( femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr5_t   femdarr5_transpose(   femdarr5_t* arr);
void        femdarr5_transpose_to(femdarr5_t* arr, femdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif