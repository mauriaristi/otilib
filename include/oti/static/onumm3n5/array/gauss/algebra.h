#ifndef OTI_ONUMM3N5_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM3N5_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_neg(    feoarrm3n5_t* arr);
void      feoarrm3n5_neg_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_sum_FF(   feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sum_FF_to(feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sum_fF(    feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sum_fF_to( feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sum_OF(     oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sum_OF_to(  oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sum_RF(      darr_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sum_RF_to(   darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sum_oF(   onumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sum_oF_to(onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sum_rF(     coeff_t  lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sum_rF_to(  coeff_t  lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_sub_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sub_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_fF(    feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sub_fF_to( feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_Ff(    feoarrm3n5_t* lhs, feonumm3n5_t* rhs);
void      feoarrm3n5_sub_Ff_to( feoarrm3n5_t* lhs, feonumm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_OF(      oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sub_OF_to(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_FO(    feoarrm3n5_t* lhs,   oarrm3n5_t* rhs);
void      feoarrm3n5_sub_FO_to( feoarrm3n5_t* lhs,   oarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_RF(       darr_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sub_RF_to(    darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_FR(    feoarrm3n5_t* lhs,    darr_t* rhs);
void      feoarrm3n5_sub_FR_to( feoarrm3n5_t* lhs,    darr_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_oF(    onumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sub_oF_to( onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_Fo(    feoarrm3n5_t* lhs, onumm3n5_t* rhs);
void      feoarrm3n5_sub_Fo_to( feoarrm3n5_t* lhs, onumm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_rF(      coeff_t  lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_sub_rF_to(    coeff_t lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_sub_Fr(    feoarrm3n5_t* lhs,   coeff_t  rhs);
void      feoarrm3n5_sub_Fr_to( feoarrm3n5_t* lhs,   coeff_t  rhs, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_mul_FF(   feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_mul_FF_to(feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_mul_fF(    feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_mul_fF_to( feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_mul_OF(     oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_mul_OF_to(  oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_mul_RF(      darr_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_mul_RF_to(   darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_mul_oF(   onumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_mul_oF_to(onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_mul_rF(     coeff_t  lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_mul_rF_to(  coeff_t  lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm3n5_t feoarrm3n5_div_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_div_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_fF(     feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_div_fF_to(  feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_Ff(    feoarrm3n5_t* lhs,  feonumm3n5_t* rhs);
void      feoarrm3n5_div_Ff_to( feoarrm3n5_t* lhs,  feonumm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_OF(      oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_div_OF_to(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_FO(    feoarrm3n5_t* lhs,   oarrm3n5_t* rhs);
void      feoarrm3n5_div_FO_to( feoarrm3n5_t* lhs,   oarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_RF(       darr_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_div_RF_to(    darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_FR(    feoarrm3n5_t* lhs,    darr_t* rhs);
void      feoarrm3n5_div_FR_to( feoarrm3n5_t* lhs,    darr_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_oF(    onumm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_div_oF_to( onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_Fo(    feoarrm3n5_t* lhs, onumm3n5_t* rhs);
void      feoarrm3n5_div_Fo_to( feoarrm3n5_t* lhs, onumm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_rF(      coeff_t  lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_div_rF_to(    coeff_t lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_div_Fr(    feoarrm3n5_t* lhs,   coeff_t  rhs);
void      feoarrm3n5_div_Fr_to( feoarrm3n5_t* lhs,   coeff_t  rhs, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm3n5_t feoarrm3n5_integrate(    feoarrm3n5_t* arr, feonumm3n5_t* w);
void    feoarrm3n5_integrate_to( feoarrm3n5_t* arr, feonumm3n5_t* w, oarrm3n5_t* res);
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
feonumm3n5_t feoarrm3n5_dotproduct_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void     feoarrm3n5_dotproduct_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feonumm3n5_t* res);

feonumm3n5_t feoarrm3n5_dotproduct_OF(      oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void     feoarrm3n5_dotproduct_OF_to(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feonumm3n5_t* res);

feonumm3n5_t feoarrm3n5_dotproduct_RF(       darr_t* lhs, feoarrm3n5_t* rhs);
void     feoarrm3n5_dotproduct_RF_to(    darr_t* lhs, feoarrm3n5_t* rhs, feonumm3n5_t* res);
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
feoarrm3n5_t feoarrm3n5_matmul_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_matmul_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_matmul_OF(    oarrm3n5_t*   lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_matmul_OF_to( oarrm3n5_t*   lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_matmul_FO(    feoarrm3n5_t* lhs, oarrm3n5_t*   rhs);
void      feoarrm3n5_matmul_FO_to( feoarrm3n5_t* lhs, oarrm3n5_t*   rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_matmul_RF(    darr_t*    lhs, feoarrm3n5_t* rhs);
void      feoarrm3n5_matmul_RF_to( darr_t*    lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);

feoarrm3n5_t feoarrm3n5_matmul_FR(    feoarrm3n5_t* lhs, darr_t*    rhs);
void      feoarrm3n5_matmul_FR_to( feoarrm3n5_t* lhs, darr_t*    rhs, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm3n5_t feoarrm3n5_det(   feoarrm3n5_t* arr);
void     feoarrm3n5_det_to(feoarrm3n5_t* arr, feonumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n5_t feoarrm3n5_norm(     feoarrm3n5_t* arr);
void     feoarrm3n5_norm_to(  feoarrm3n5_t* arr, feonumm3n5_t* res);

feonumm3n5_t feoarrm3n5_pnorm(    feoarrm3n5_t* arr, coeff_t p);
void     feoarrm3n5_pnorm_to( feoarrm3n5_t* arr, coeff_t p, feonumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm3n5_t   feoarrm3n5_invert(    feoarrm3n5_t* arr);
void        feoarrm3n5_invert_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm3n5_t   feoarrm3n5_transpose(   feoarrm3n5_t* arr);
void        feoarrm3n5_transpose_to(feoarrm3n5_t* arr, feoarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif