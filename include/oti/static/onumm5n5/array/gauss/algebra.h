#ifndef OTI_ONUMM5N5_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM5N5_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_neg(    feoarrm5n5_t* arr);
void      feoarrm5n5_neg_to( feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_sum_FF(   feoarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sum_FF_to(feoarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sum_fF(    feonumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sum_fF_to( feonumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sum_OF(     oarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sum_OF_to(  oarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sum_RF(      darr_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sum_RF_to(   darr_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sum_oF(   onumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sum_oF_to(onumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sum_rF(     coeff_t  lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sum_rF_to(  coeff_t  lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_sub_FF(    feoarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sub_FF_to( feoarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_fF(    feonumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sub_fF_to( feonumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_Ff(    feoarrm5n5_t* lhs, feonumm5n5_t* rhs);
void      feoarrm5n5_sub_Ff_to( feoarrm5n5_t* lhs, feonumm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_OF(      oarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sub_OF_to(   oarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_FO(    feoarrm5n5_t* lhs,   oarrm5n5_t* rhs);
void      feoarrm5n5_sub_FO_to( feoarrm5n5_t* lhs,   oarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_RF(       darr_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sub_RF_to(    darr_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_FR(    feoarrm5n5_t* lhs,    darr_t* rhs);
void      feoarrm5n5_sub_FR_to( feoarrm5n5_t* lhs,    darr_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_oF(    onumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sub_oF_to( onumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_Fo(    feoarrm5n5_t* lhs, onumm5n5_t* rhs);
void      feoarrm5n5_sub_Fo_to( feoarrm5n5_t* lhs, onumm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_rF(      coeff_t  lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_sub_rF_to(    coeff_t lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_sub_Fr(    feoarrm5n5_t* lhs,   coeff_t  rhs);
void      feoarrm5n5_sub_Fr_to( feoarrm5n5_t* lhs,   coeff_t  rhs, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_mul_FF(   feoarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_mul_FF_to(feoarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_mul_fF(    feonumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_mul_fF_to( feonumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_mul_OF(     oarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_mul_OF_to(  oarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_mul_RF(      darr_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_mul_RF_to(   darr_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_mul_oF(   onumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_mul_oF_to(onumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_mul_rF(     coeff_t  lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_mul_rF_to(  coeff_t  lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n5_t feoarrm5n5_div_FF(    feoarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_div_FF_to( feoarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_fF(     feonumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_div_fF_to(  feonumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_Ff(    feoarrm5n5_t* lhs,  feonumm5n5_t* rhs);
void      feoarrm5n5_div_Ff_to( feoarrm5n5_t* lhs,  feonumm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_OF(      oarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_div_OF_to(   oarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_FO(    feoarrm5n5_t* lhs,   oarrm5n5_t* rhs);
void      feoarrm5n5_div_FO_to( feoarrm5n5_t* lhs,   oarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_RF(       darr_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_div_RF_to(    darr_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_FR(    feoarrm5n5_t* lhs,    darr_t* rhs);
void      feoarrm5n5_div_FR_to( feoarrm5n5_t* lhs,    darr_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_oF(    onumm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_div_oF_to( onumm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_Fo(    feoarrm5n5_t* lhs, onumm5n5_t* rhs);
void      feoarrm5n5_div_Fo_to( feoarrm5n5_t* lhs, onumm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_rF(      coeff_t  lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_div_rF_to(    coeff_t lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_div_Fr(    feoarrm5n5_t* lhs,   coeff_t  rhs);
void      feoarrm5n5_div_Fr_to( feoarrm5n5_t* lhs,   coeff_t  rhs, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm5n5_t feoarrm5n5_integrate(    feoarrm5n5_t* arr, feonumm5n5_t* w);
void    feoarrm5n5_integrate_to( feoarrm5n5_t* arr, feonumm5n5_t* w, oarrm5n5_t* res);
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
feonumm5n5_t feoarrm5n5_dotproduct_FF(    feoarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void     feoarrm5n5_dotproduct_FF_to( feoarrm5n5_t* lhs, feoarrm5n5_t* rhs, feonumm5n5_t* res);

feonumm5n5_t feoarrm5n5_dotproduct_OF(      oarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void     feoarrm5n5_dotproduct_OF_to(   oarrm5n5_t* lhs, feoarrm5n5_t* rhs, feonumm5n5_t* res);

feonumm5n5_t feoarrm5n5_dotproduct_RF(       darr_t* lhs, feoarrm5n5_t* rhs);
void     feoarrm5n5_dotproduct_RF_to(    darr_t* lhs, feoarrm5n5_t* rhs, feonumm5n5_t* res);
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
feoarrm5n5_t feoarrm5n5_matmul_FF(    feoarrm5n5_t* lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_matmul_FF_to( feoarrm5n5_t* lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_matmul_OF(    oarrm5n5_t*   lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_matmul_OF_to( oarrm5n5_t*   lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_matmul_FO(    feoarrm5n5_t* lhs, oarrm5n5_t*   rhs);
void      feoarrm5n5_matmul_FO_to( feoarrm5n5_t* lhs, oarrm5n5_t*   rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_matmul_RF(    darr_t*    lhs, feoarrm5n5_t* rhs);
void      feoarrm5n5_matmul_RF_to( darr_t*    lhs, feoarrm5n5_t* rhs, feoarrm5n5_t* res);

feoarrm5n5_t feoarrm5n5_matmul_FR(    feoarrm5n5_t* lhs, darr_t*    rhs);
void      feoarrm5n5_matmul_FR_to( feoarrm5n5_t* lhs, darr_t*    rhs, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm5n5_t feoarrm5n5_det(   feoarrm5n5_t* arr);
void     feoarrm5n5_det_to(feoarrm5n5_t* arr, feonumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n5_t feoarrm5n5_norm(     feoarrm5n5_t* arr);
void     feoarrm5n5_norm_to(  feoarrm5n5_t* arr, feonumm5n5_t* res);

feonumm5n5_t feoarrm5n5_pnorm(    feoarrm5n5_t* arr, coeff_t p);
void     feoarrm5n5_pnorm_to( feoarrm5n5_t* arr, coeff_t p, feonumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm5n5_t   feoarrm5n5_invert(    feoarrm5n5_t* arr);
void        feoarrm5n5_invert_to( feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm5n5_t   feoarrm5n5_transpose(   feoarrm5n5_t* arr);
void        feoarrm5n5_transpose_to(feoarrm5n5_t* arr, feoarrm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif