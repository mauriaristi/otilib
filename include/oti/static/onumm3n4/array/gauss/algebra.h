#ifndef OTI_ONUMM3N4_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM3N4_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_neg(    feoarrm3n4_t* arr);
void      feoarrm3n4_neg_to( feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_sum_FF(   feoarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sum_FF_to(feoarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sum_fF(    feonumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sum_fF_to( feonumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sum_OF(     oarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sum_OF_to(  oarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sum_RF(      darr_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sum_RF_to(   darr_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sum_oF(   onumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sum_oF_to(onumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sum_rF(     coeff_t  lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sum_rF_to(  coeff_t  lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_sub_FF(    feoarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sub_FF_to( feoarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_fF(    feonumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sub_fF_to( feonumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_Ff(    feoarrm3n4_t* lhs, feonumm3n4_t* rhs);
void      feoarrm3n4_sub_Ff_to( feoarrm3n4_t* lhs, feonumm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_OF(      oarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sub_OF_to(   oarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_FO(    feoarrm3n4_t* lhs,   oarrm3n4_t* rhs);
void      feoarrm3n4_sub_FO_to( feoarrm3n4_t* lhs,   oarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_RF(       darr_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sub_RF_to(    darr_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_FR(    feoarrm3n4_t* lhs,    darr_t* rhs);
void      feoarrm3n4_sub_FR_to( feoarrm3n4_t* lhs,    darr_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_oF(    onumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sub_oF_to( onumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_Fo(    feoarrm3n4_t* lhs, onumm3n4_t* rhs);
void      feoarrm3n4_sub_Fo_to( feoarrm3n4_t* lhs, onumm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_rF(      coeff_t  lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_sub_rF_to(    coeff_t lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_sub_Fr(    feoarrm3n4_t* lhs,   coeff_t  rhs);
void      feoarrm3n4_sub_Fr_to( feoarrm3n4_t* lhs,   coeff_t  rhs, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_mul_FF(   feoarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_mul_FF_to(feoarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_mul_fF(    feonumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_mul_fF_to( feonumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_mul_OF(     oarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_mul_OF_to(  oarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_mul_RF(      darr_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_mul_RF_to(   darr_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_mul_oF(   onumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_mul_oF_to(onumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_mul_rF(     coeff_t  lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_mul_rF_to(  coeff_t  lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n4_t feoarrm3n4_div_FF(    feoarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_div_FF_to( feoarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_fF(     feonumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_div_fF_to(  feonumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_Ff(    feoarrm3n4_t* lhs,  feonumm3n4_t* rhs);
void      feoarrm3n4_div_Ff_to( feoarrm3n4_t* lhs,  feonumm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_OF(      oarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_div_OF_to(   oarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_FO(    feoarrm3n4_t* lhs,   oarrm3n4_t* rhs);
void      feoarrm3n4_div_FO_to( feoarrm3n4_t* lhs,   oarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_RF(       darr_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_div_RF_to(    darr_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_FR(    feoarrm3n4_t* lhs,    darr_t* rhs);
void      feoarrm3n4_div_FR_to( feoarrm3n4_t* lhs,    darr_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_oF(    onumm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_div_oF_to( onumm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_Fo(    feoarrm3n4_t* lhs, onumm3n4_t* rhs);
void      feoarrm3n4_div_Fo_to( feoarrm3n4_t* lhs, onumm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_rF(      coeff_t  lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_div_rF_to(    coeff_t lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_div_Fr(    feoarrm3n4_t* lhs,   coeff_t  rhs);
void      feoarrm3n4_div_Fr_to( feoarrm3n4_t* lhs,   coeff_t  rhs, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm3n4_t feoarrm3n4_integrate(    feoarrm3n4_t* arr, feonumm3n4_t* w);
void    feoarrm3n4_integrate_to( feoarrm3n4_t* arr, feonumm3n4_t* w, oarrm3n4_t* res);
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
feonumm3n4_t feoarrm3n4_dotproduct_FF(    feoarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void     feoarrm3n4_dotproduct_FF_to( feoarrm3n4_t* lhs, feoarrm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feoarrm3n4_dotproduct_OF(      oarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void     feoarrm3n4_dotproduct_OF_to(   oarrm3n4_t* lhs, feoarrm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feoarrm3n4_dotproduct_RF(       darr_t* lhs, feoarrm3n4_t* rhs);
void     feoarrm3n4_dotproduct_RF_to(    darr_t* lhs, feoarrm3n4_t* rhs, feonumm3n4_t* res);
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
feoarrm3n4_t feoarrm3n4_matmul_FF(    feoarrm3n4_t* lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_matmul_FF_to( feoarrm3n4_t* lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_matmul_OF(    oarrm3n4_t*   lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_matmul_OF_to( oarrm3n4_t*   lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_matmul_FO(    feoarrm3n4_t* lhs, oarrm3n4_t*   rhs);
void      feoarrm3n4_matmul_FO_to( feoarrm3n4_t* lhs, oarrm3n4_t*   rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_matmul_RF(    darr_t*    lhs, feoarrm3n4_t* rhs);
void      feoarrm3n4_matmul_RF_to( darr_t*    lhs, feoarrm3n4_t* rhs, feoarrm3n4_t* res);

feoarrm3n4_t feoarrm3n4_matmul_FR(    feoarrm3n4_t* lhs, darr_t*    rhs);
void      feoarrm3n4_matmul_FR_to( feoarrm3n4_t* lhs, darr_t*    rhs, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm3n4_t feoarrm3n4_det(   feoarrm3n4_t* arr);
void     feoarrm3n4_det_to(feoarrm3n4_t* arr, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feoarrm3n4_norm(     feoarrm3n4_t* arr);
void     feoarrm3n4_norm_to(  feoarrm3n4_t* arr, feonumm3n4_t* res);

feonumm3n4_t feoarrm3n4_pnorm(    feoarrm3n4_t* arr, coeff_t p);
void     feoarrm3n4_pnorm_to( feoarrm3n4_t* arr, coeff_t p, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm3n4_t   feoarrm3n4_invert(    feoarrm3n4_t* arr);
void        feoarrm3n4_invert_to( feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm3n4_t   feoarrm3n4_transpose(   feoarrm3n4_t* arr);
void        feoarrm3n4_transpose_to(feoarrm3n4_t* arr, feoarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif