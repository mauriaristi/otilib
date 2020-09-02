#ifndef OTI_ONUMM0N0_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM0N0_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_neg(    feoarrm0n0_t* arr);
void      feoarrm0n0_neg_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_sum_FF(   feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sum_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sum_fF(    feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sum_fF_to( feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sum_OF(     oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sum_OF_to(  oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sum_RF(      darr_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sum_RF_to(   darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sum_oF(   onumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sum_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sum_rF(     coeff_t  lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sum_rF_to(  coeff_t  lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_sub_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sub_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_fF(    feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sub_fF_to( feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_Ff(    feoarrm0n0_t* lhs, feonumm0n0_t* rhs);
void      feoarrm0n0_sub_Ff_to( feoarrm0n0_t* lhs, feonumm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_OF(      oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sub_OF_to(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_FO(    feoarrm0n0_t* lhs,   oarrm0n0_t* rhs);
void      feoarrm0n0_sub_FO_to( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_RF(       darr_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sub_RF_to(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_FR(    feoarrm0n0_t* lhs,    darr_t* rhs);
void      feoarrm0n0_sub_FR_to( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_oF(    onumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sub_oF_to( onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_Fo(    feoarrm0n0_t* lhs, onumm0n0_t* rhs);
void      feoarrm0n0_sub_Fo_to( feoarrm0n0_t* lhs, onumm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_rF(      coeff_t  lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_sub_rF_to(    coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_sub_Fr(    feoarrm0n0_t* lhs,   coeff_t  rhs);
void      feoarrm0n0_sub_Fr_to( feoarrm0n0_t* lhs,   coeff_t  rhs, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_mul_FF(   feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_mul_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_mul_fF(    feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_mul_fF_to( feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_mul_OF(     oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_mul_OF_to(  oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_mul_RF(      darr_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_mul_RF_to(   darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_mul_oF(   onumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_mul_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_mul_rF(     coeff_t  lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_mul_rF_to(  coeff_t  lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm0n0_t feoarrm0n0_div_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_div_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_fF(     feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_div_fF_to(  feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_Ff(    feoarrm0n0_t* lhs,  feonumm0n0_t* rhs);
void      feoarrm0n0_div_Ff_to( feoarrm0n0_t* lhs,  feonumm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_OF(      oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_div_OF_to(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_FO(    feoarrm0n0_t* lhs,   oarrm0n0_t* rhs);
void      feoarrm0n0_div_FO_to( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_RF(       darr_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_div_RF_to(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_FR(    feoarrm0n0_t* lhs,    darr_t* rhs);
void      feoarrm0n0_div_FR_to( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_oF(    onumm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_div_oF_to( onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_Fo(    feoarrm0n0_t* lhs, onumm0n0_t* rhs);
void      feoarrm0n0_div_Fo_to( feoarrm0n0_t* lhs, onumm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_rF(      coeff_t  lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_div_rF_to(    coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_div_Fr(    feoarrm0n0_t* lhs,   coeff_t  rhs);
void      feoarrm0n0_div_Fr_to( feoarrm0n0_t* lhs,   coeff_t  rhs, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm0n0_t feoarrm0n0_integrate(    feoarrm0n0_t* arr, feonumm0n0_t* w);
void    feoarrm0n0_integrate_to( feoarrm0n0_t* arr, feonumm0n0_t* w, oarrm0n0_t* res);
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
feonumm0n0_t feoarrm0n0_dotproduct_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void     feoarrm0n0_dotproduct_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feoarrm0n0_dotproduct_OF(      oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void     feoarrm0n0_dotproduct_OF_to(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feoarrm0n0_dotproduct_RF(       darr_t* lhs, feoarrm0n0_t* rhs);
void     feoarrm0n0_dotproduct_RF_to(    darr_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res);
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
feoarrm0n0_t feoarrm0n0_matmul_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_matmul_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_matmul_OF(    oarrm0n0_t*   lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_matmul_OF_to( oarrm0n0_t*   lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_matmul_FO(    feoarrm0n0_t* lhs, oarrm0n0_t*   rhs);
void      feoarrm0n0_matmul_FO_to( feoarrm0n0_t* lhs, oarrm0n0_t*   rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_matmul_RF(    darr_t*    lhs, feoarrm0n0_t* rhs);
void      feoarrm0n0_matmul_RF_to( darr_t*    lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);

feoarrm0n0_t feoarrm0n0_matmul_FR(    feoarrm0n0_t* lhs, darr_t*    rhs);
void      feoarrm0n0_matmul_FR_to( feoarrm0n0_t* lhs, darr_t*    rhs, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm0n0_t feoarrm0n0_det(   feoarrm0n0_t* arr);
void     feoarrm0n0_det_to(feoarrm0n0_t* arr, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feoarrm0n0_norm(     feoarrm0n0_t* arr);
void     feoarrm0n0_norm_to(  feoarrm0n0_t* arr, feonumm0n0_t* res);

feonumm0n0_t feoarrm0n0_pnorm(    feoarrm0n0_t* arr, coeff_t p);
void     feoarrm0n0_pnorm_to( feoarrm0n0_t* arr, coeff_t p, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm0n0_t   feoarrm0n0_invert(    feoarrm0n0_t* arr);
void        feoarrm0n0_invert_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm0n0_t   feoarrm0n0_transpose(   feoarrm0n0_t* arr);
void        feoarrm0n0_transpose_to(feoarrm0n0_t* arr, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif