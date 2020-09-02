#ifndef OTI_ONUMM2N10_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N10_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_neg(    feoarrm2n10_t* arr);
void      feoarrm2n10_neg_to( feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_sum_FF(   feoarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sum_FF_to(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sum_fF(    feonumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sum_fF_to( feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sum_OF(     oarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sum_OF_to(  oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sum_RF(      darr_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sum_RF_to(   darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sum_oF(   onumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sum_oF_to(onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sum_rF(     coeff_t  lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sum_rF_to(  coeff_t  lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_sub_FF(    feoarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sub_FF_to( feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_fF(    feonumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sub_fF_to( feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_Ff(    feoarrm2n10_t* lhs, feonumm2n10_t* rhs);
void      feoarrm2n10_sub_Ff_to( feoarrm2n10_t* lhs, feonumm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_OF(      oarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sub_OF_to(   oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_FO(    feoarrm2n10_t* lhs,   oarrm2n10_t* rhs);
void      feoarrm2n10_sub_FO_to( feoarrm2n10_t* lhs,   oarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_RF(       darr_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sub_RF_to(    darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_FR(    feoarrm2n10_t* lhs,    darr_t* rhs);
void      feoarrm2n10_sub_FR_to( feoarrm2n10_t* lhs,    darr_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_oF(    onumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sub_oF_to( onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_Fo(    feoarrm2n10_t* lhs, onumm2n10_t* rhs);
void      feoarrm2n10_sub_Fo_to( feoarrm2n10_t* lhs, onumm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_rF(      coeff_t  lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_sub_rF_to(    coeff_t lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_sub_Fr(    feoarrm2n10_t* lhs,   coeff_t  rhs);
void      feoarrm2n10_sub_Fr_to( feoarrm2n10_t* lhs,   coeff_t  rhs, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_mul_FF(   feoarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_mul_FF_to(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_mul_fF(    feonumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_mul_fF_to( feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_mul_OF(     oarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_mul_OF_to(  oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_mul_RF(      darr_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_mul_RF_to(   darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_mul_oF(   onumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_mul_oF_to(onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_mul_rF(     coeff_t  lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_mul_rF_to(  coeff_t  lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n10_t feoarrm2n10_div_FF(    feoarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_div_FF_to( feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_fF(     feonumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_div_fF_to(  feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_Ff(    feoarrm2n10_t* lhs,  feonumm2n10_t* rhs);
void      feoarrm2n10_div_Ff_to( feoarrm2n10_t* lhs,  feonumm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_OF(      oarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_div_OF_to(   oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_FO(    feoarrm2n10_t* lhs,   oarrm2n10_t* rhs);
void      feoarrm2n10_div_FO_to( feoarrm2n10_t* lhs,   oarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_RF(       darr_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_div_RF_to(    darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_FR(    feoarrm2n10_t* lhs,    darr_t* rhs);
void      feoarrm2n10_div_FR_to( feoarrm2n10_t* lhs,    darr_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_oF(    onumm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_div_oF_to( onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_Fo(    feoarrm2n10_t* lhs, onumm2n10_t* rhs);
void      feoarrm2n10_div_Fo_to( feoarrm2n10_t* lhs, onumm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_rF(      coeff_t  lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_div_rF_to(    coeff_t lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_div_Fr(    feoarrm2n10_t* lhs,   coeff_t  rhs);
void      feoarrm2n10_div_Fr_to( feoarrm2n10_t* lhs,   coeff_t  rhs, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm2n10_t feoarrm2n10_integrate(    feoarrm2n10_t* arr, feonumm2n10_t* w);
void    feoarrm2n10_integrate_to( feoarrm2n10_t* arr, feonumm2n10_t* w, oarrm2n10_t* res);
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
feonumm2n10_t feoarrm2n10_dotproduct_FF(    feoarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void     feoarrm2n10_dotproduct_FF_to( feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feoarrm2n10_dotproduct_OF(      oarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void     feoarrm2n10_dotproduct_OF_to(   oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feoarrm2n10_dotproduct_RF(       darr_t* lhs, feoarrm2n10_t* rhs);
void     feoarrm2n10_dotproduct_RF_to(    darr_t* lhs, feoarrm2n10_t* rhs, feonumm2n10_t* res);
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
feoarrm2n10_t feoarrm2n10_matmul_FF(    feoarrm2n10_t* lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_matmul_FF_to( feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_matmul_OF(    oarrm2n10_t*   lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_matmul_OF_to( oarrm2n10_t*   lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_matmul_FO(    feoarrm2n10_t* lhs, oarrm2n10_t*   rhs);
void      feoarrm2n10_matmul_FO_to( feoarrm2n10_t* lhs, oarrm2n10_t*   rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_matmul_RF(    darr_t*    lhs, feoarrm2n10_t* rhs);
void      feoarrm2n10_matmul_RF_to( darr_t*    lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res);

feoarrm2n10_t feoarrm2n10_matmul_FR(    feoarrm2n10_t* lhs, darr_t*    rhs);
void      feoarrm2n10_matmul_FR_to( feoarrm2n10_t* lhs, darr_t*    rhs, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm2n10_t feoarrm2n10_det(   feoarrm2n10_t* arr);
void     feoarrm2n10_det_to(feoarrm2n10_t* arr, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feoarrm2n10_norm(     feoarrm2n10_t* arr);
void     feoarrm2n10_norm_to(  feoarrm2n10_t* arr, feonumm2n10_t* res);

feonumm2n10_t feoarrm2n10_pnorm(    feoarrm2n10_t* arr, coeff_t p);
void     feoarrm2n10_pnorm_to( feoarrm2n10_t* arr, coeff_t p, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm2n10_t   feoarrm2n10_invert(    feoarrm2n10_t* arr);
void        feoarrm2n10_invert_to( feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm2n10_t   feoarrm2n10_transpose(   feoarrm2n10_t* arr);
void        feoarrm2n10_transpose_to(feoarrm2n10_t* arr, feoarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif