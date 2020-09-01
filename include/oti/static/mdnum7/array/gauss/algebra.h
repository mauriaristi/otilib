#ifndef OTI_MDNUM7_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM7_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_neg(    femdarr7_t* arr);
void      femdarr7_neg_to( femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_sum_FF(   femdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sum_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sum_fF(    femdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sum_fF_to( femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sum_OF(     mdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sum_OF_to(  mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sum_RF(      darr_t* lhs, femdarr7_t* rhs);
void      femdarr7_sum_RF_to(   darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sum_oF(   mdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sum_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sum_rF(     coeff_t  lhs, femdarr7_t* rhs);
void      femdarr7_sum_rF_to(  coeff_t  lhs, femdarr7_t* rhs, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_sub_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sub_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_fF(    femdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sub_fF_to( femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_Ff(    femdarr7_t* lhs, femdnum7_t* rhs);
void      femdarr7_sub_Ff_to( femdarr7_t* lhs, femdnum7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_OF(      mdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sub_OF_to(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_FO(    femdarr7_t* lhs,   mdarr7_t* rhs);
void      femdarr7_sub_FO_to( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_RF(       darr_t* lhs, femdarr7_t* rhs);
void      femdarr7_sub_RF_to(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_FR(    femdarr7_t* lhs,    darr_t* rhs);
void      femdarr7_sub_FR_to( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_oF(    mdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_sub_oF_to( mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_Fo(    femdarr7_t* lhs, mdnum7_t* rhs);
void      femdarr7_sub_Fo_to( femdarr7_t* lhs, mdnum7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_rF(      coeff_t  lhs, femdarr7_t* rhs);
void      femdarr7_sub_rF_to(    coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_sub_Fr(    femdarr7_t* lhs,   coeff_t  rhs);
void      femdarr7_sub_Fr_to( femdarr7_t* lhs,   coeff_t  rhs, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_mul_FF(   femdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_mul_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_mul_fF(    femdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_mul_fF_to( femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_mul_OF(     mdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_mul_OF_to(  mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_mul_RF(      darr_t* lhs, femdarr7_t* rhs);
void      femdarr7_mul_RF_to(   darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_mul_oF(   mdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_mul_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_mul_rF(     coeff_t  lhs, femdarr7_t* rhs);
void      femdarr7_mul_rF_to(  coeff_t  lhs, femdarr7_t* rhs, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr7_t femdarr7_div_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_div_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_fF(     femdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_div_fF_to(  femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_Ff(    femdarr7_t* lhs,  femdnum7_t* rhs);
void      femdarr7_div_Ff_to( femdarr7_t* lhs,  femdnum7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_OF(      mdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_div_OF_to(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_FO(    femdarr7_t* lhs,   mdarr7_t* rhs);
void      femdarr7_div_FO_to( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_RF(       darr_t* lhs, femdarr7_t* rhs);
void      femdarr7_div_RF_to(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_FR(    femdarr7_t* lhs,    darr_t* rhs);
void      femdarr7_div_FR_to( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_oF(    mdnum7_t* lhs, femdarr7_t* rhs);
void      femdarr7_div_oF_to( mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_Fo(    femdarr7_t* lhs, mdnum7_t* rhs);
void      femdarr7_div_Fo_to( femdarr7_t* lhs, mdnum7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_rF(      coeff_t  lhs, femdarr7_t* rhs);
void      femdarr7_div_rF_to(    coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_div_Fr(    femdarr7_t* lhs,   coeff_t  rhs);
void      femdarr7_div_Fr_to( femdarr7_t* lhs,   coeff_t  rhs, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr7_t femdarr7_integrate(    femdarr7_t* arr, femdnum7_t* w);
void    femdarr7_integrate_to( femdarr7_t* arr, femdnum7_t* w, mdarr7_t* res);
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
femdnum7_t femdarr7_dotproduct_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
void     femdarr7_dotproduct_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdnum7_t* res);

femdnum7_t femdarr7_dotproduct_OF(      mdarr7_t* lhs, femdarr7_t* rhs);
void     femdarr7_dotproduct_OF_to(   mdarr7_t* lhs, femdarr7_t* rhs, femdnum7_t* res);

femdnum7_t femdarr7_dotproduct_RF(       darr_t* lhs, femdarr7_t* rhs);
void     femdarr7_dotproduct_RF_to(    darr_t* lhs, femdarr7_t* rhs, femdnum7_t* res);
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
femdarr7_t femdarr7_matmul_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
void      femdarr7_matmul_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_matmul_OF(    mdarr7_t*   lhs, femdarr7_t* rhs);
void      femdarr7_matmul_OF_to( mdarr7_t*   lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_matmul_FO(    femdarr7_t* lhs, mdarr7_t*   rhs);
void      femdarr7_matmul_FO_to( femdarr7_t* lhs, mdarr7_t*   rhs, femdarr7_t* res);

femdarr7_t femdarr7_matmul_RF(    darr_t*    lhs, femdarr7_t* rhs);
void      femdarr7_matmul_RF_to( darr_t*    lhs, femdarr7_t* rhs, femdarr7_t* res);

femdarr7_t femdarr7_matmul_FR(    femdarr7_t* lhs, darr_t*    rhs);
void      femdarr7_matmul_FR_to( femdarr7_t* lhs, darr_t*    rhs, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum7_t femdarr7_det(   femdarr7_t* arr);
void     femdarr7_det_to(femdarr7_t* arr, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdarr7_norm(     femdarr7_t* arr);
void     femdarr7_norm_to(  femdarr7_t* arr, femdnum7_t* res);

femdnum7_t femdarr7_pnorm(    femdarr7_t* arr, coeff_t p);
void     femdarr7_pnorm_to( femdarr7_t* arr, coeff_t p, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr7_t   femdarr7_invert(    femdarr7_t* arr);
void        femdarr7_invert_to( femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr7_t   femdarr7_transpose(   femdarr7_t* arr);
void        femdarr7_transpose_to(femdarr7_t* arr, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif