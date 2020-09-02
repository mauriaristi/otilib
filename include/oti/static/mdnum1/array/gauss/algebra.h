#ifndef OTI_MDNUM1_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM1_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_neg(    femdarr1_t* arr);
void      femdarr1_neg_to( femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_sum_FF(   femdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sum_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sum_fF(    femdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sum_fF_to( femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sum_OF(     mdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sum_OF_to(  mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sum_RF(      darr_t* lhs, femdarr1_t* rhs);
void      femdarr1_sum_RF_to(   darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sum_oF(   mdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sum_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sum_rF(     coeff_t  lhs, femdarr1_t* rhs);
void      femdarr1_sum_rF_to(  coeff_t  lhs, femdarr1_t* rhs, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_sub_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sub_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_fF(    femdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sub_fF_to( femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_Ff(    femdarr1_t* lhs, femdnum1_t* rhs);
void      femdarr1_sub_Ff_to( femdarr1_t* lhs, femdnum1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_OF(      mdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sub_OF_to(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_FO(    femdarr1_t* lhs,   mdarr1_t* rhs);
void      femdarr1_sub_FO_to( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_RF(       darr_t* lhs, femdarr1_t* rhs);
void      femdarr1_sub_RF_to(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_FR(    femdarr1_t* lhs,    darr_t* rhs);
void      femdarr1_sub_FR_to( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_oF(    mdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_sub_oF_to( mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_Fo(    femdarr1_t* lhs, mdnum1_t* rhs);
void      femdarr1_sub_Fo_to( femdarr1_t* lhs, mdnum1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_rF(      coeff_t  lhs, femdarr1_t* rhs);
void      femdarr1_sub_rF_to(    coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_sub_Fr(    femdarr1_t* lhs,   coeff_t  rhs);
void      femdarr1_sub_Fr_to( femdarr1_t* lhs,   coeff_t  rhs, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_mul_FF(   femdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_mul_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_mul_fF(    femdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_mul_fF_to( femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_mul_OF(     mdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_mul_OF_to(  mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_mul_RF(      darr_t* lhs, femdarr1_t* rhs);
void      femdarr1_mul_RF_to(   darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_mul_oF(   mdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_mul_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_mul_rF(     coeff_t  lhs, femdarr1_t* rhs);
void      femdarr1_mul_rF_to(  coeff_t  lhs, femdarr1_t* rhs, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr1_t femdarr1_div_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_div_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_fF(     femdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_div_fF_to(  femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_Ff(    femdarr1_t* lhs,  femdnum1_t* rhs);
void      femdarr1_div_Ff_to( femdarr1_t* lhs,  femdnum1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_OF(      mdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_div_OF_to(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_FO(    femdarr1_t* lhs,   mdarr1_t* rhs);
void      femdarr1_div_FO_to( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_RF(       darr_t* lhs, femdarr1_t* rhs);
void      femdarr1_div_RF_to(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_FR(    femdarr1_t* lhs,    darr_t* rhs);
void      femdarr1_div_FR_to( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_oF(    mdnum1_t* lhs, femdarr1_t* rhs);
void      femdarr1_div_oF_to( mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_Fo(    femdarr1_t* lhs, mdnum1_t* rhs);
void      femdarr1_div_Fo_to( femdarr1_t* lhs, mdnum1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_rF(      coeff_t  lhs, femdarr1_t* rhs);
void      femdarr1_div_rF_to(    coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_div_Fr(    femdarr1_t* lhs,   coeff_t  rhs);
void      femdarr1_div_Fr_to( femdarr1_t* lhs,   coeff_t  rhs, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr1_t femdarr1_integrate(    femdarr1_t* arr, femdnum1_t* w);
void    femdarr1_integrate_to( femdarr1_t* arr, femdnum1_t* w, mdarr1_t* res);
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
femdnum1_t femdarr1_dotproduct_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
void     femdarr1_dotproduct_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdnum1_t* res);

femdnum1_t femdarr1_dotproduct_OF(      mdarr1_t* lhs, femdarr1_t* rhs);
void     femdarr1_dotproduct_OF_to(   mdarr1_t* lhs, femdarr1_t* rhs, femdnum1_t* res);

femdnum1_t femdarr1_dotproduct_RF(       darr_t* lhs, femdarr1_t* rhs);
void     femdarr1_dotproduct_RF_to(    darr_t* lhs, femdarr1_t* rhs, femdnum1_t* res);
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
femdarr1_t femdarr1_matmul_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
void      femdarr1_matmul_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_matmul_OF(    mdarr1_t*   lhs, femdarr1_t* rhs);
void      femdarr1_matmul_OF_to( mdarr1_t*   lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_matmul_FO(    femdarr1_t* lhs, mdarr1_t*   rhs);
void      femdarr1_matmul_FO_to( femdarr1_t* lhs, mdarr1_t*   rhs, femdarr1_t* res);

femdarr1_t femdarr1_matmul_RF(    darr_t*    lhs, femdarr1_t* rhs);
void      femdarr1_matmul_RF_to( darr_t*    lhs, femdarr1_t* rhs, femdarr1_t* res);

femdarr1_t femdarr1_matmul_FR(    femdarr1_t* lhs, darr_t*    rhs);
void      femdarr1_matmul_FR_to( femdarr1_t* lhs, darr_t*    rhs, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum1_t femdarr1_det(   femdarr1_t* arr);
void     femdarr1_det_to(femdarr1_t* arr, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdarr1_norm(     femdarr1_t* arr);
void     femdarr1_norm_to(  femdarr1_t* arr, femdnum1_t* res);

femdnum1_t femdarr1_pnorm(    femdarr1_t* arr, coeff_t p);
void     femdarr1_pnorm_to( femdarr1_t* arr, coeff_t p, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr1_t   femdarr1_invert(    femdarr1_t* arr);
void        femdarr1_invert_to( femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr1_t   femdarr1_transpose(   femdarr1_t* arr);
void        femdarr1_transpose_to(femdarr1_t* arr, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif