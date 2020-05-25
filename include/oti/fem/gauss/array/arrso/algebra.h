#ifndef OTI_FEM_GAUSS_ARRAY_ARRSO_ALGEBRA_H
#define OTI_FEM_GAUSS_ARRAY_ARRSO_ALGEBRA_H





/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_neg(    fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_neg_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_sum_FF(   fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sum_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sum_fF(    fesoti_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sum_fF_to( fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sum_OF(     arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sum_OF_to(  arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sum_RF(      darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sum_RF_to(   darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sum_oF(   sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sum_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sum_rF(     coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sum_rF_to(  coeff_t  lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_sub_FF(    fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_FF_to( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_fF(    fesoti_t* lhs, fearrso_t* rhs,                  dhelpl_t dhl);
void      fearrso_sub_fF_to( fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res,  dhelpl_t dhl);

fearrso_t fearrso_sub_Ff(    fearrso_t* lhs, fesoti_t* rhs,                  dhelpl_t dhl);
void      fearrso_sub_Ff_to( fearrso_t* lhs, fesoti_t* rhs, fearrso_t* res,  dhelpl_t dhl);

fearrso_t fearrso_sub_OF(      arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_OF_to(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_FO(    fearrso_t* lhs,   arrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_FO_to( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_RF(       darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_RF_to(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_FR(    fearrso_t* lhs,    darr_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_FR_to( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_oF(    sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_oF_to( sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_Fo(    fearrso_t* lhs, sotinum_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_Fo_to( fearrso_t* lhs, sotinum_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_rF(      coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_sub_rF_to(    coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_sub_Fr(    fearrso_t* lhs,   coeff_t  rhs,                 dhelpl_t dhl);
void      fearrso_sub_Fr_to( fearrso_t* lhs,   coeff_t  rhs, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_mul_FF(   fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_mul_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_mul_fF(    fesoti_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_mul_fF_to( fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_mul_OF(     arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_mul_OF_to(  arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_mul_RF(      darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_mul_RF_to(   darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_mul_oF(   sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_mul_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_mul_rF(     coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_mul_rF_to(  coeff_t  lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_div_FF(    fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_FF_to( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_fF(     fesoti_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_fF_to(  fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_Ff(    fearrso_t* lhs,  fesoti_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_Ff_to( fearrso_t* lhs,  fesoti_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_OF(      arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_OF_to(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_FO(    fearrso_t* lhs,   arrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_FO_to( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_RF(       darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_RF_to(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_FR(    fearrso_t* lhs,    darr_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_FR_to( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_oF(    sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_oF_to( sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_Fo(    fearrso_t* lhs, sotinum_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_Fo_to( fearrso_t* lhs, sotinum_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_rF(      coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_div_rF_to(    coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_div_Fr(    fearrso_t* lhs,   coeff_t  rhs,                 dhelpl_t dhl);
void      fearrso_div_Fr_to( fearrso_t* lhs,   coeff_t  rhs, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
arrso_t fearrso_integrate(    fearrso_t* arr, fesoti_t* w,               dhelpl_t dhl);
void    fearrso_integrate_to( fearrso_t* arr, fesoti_t* w, arrso_t* res, dhelpl_t dhl);
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
fearrso_t fearrso_matmul_FF(    fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_matmul_FF_to( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_matmul_OF(    arrso_t*   lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_matmul_OF_to( arrso_t*   lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_matmul_FO(    fearrso_t* lhs, arrso_t*   rhs,                 dhelpl_t dhl);
void      fearrso_matmul_FO_to( fearrso_t* lhs, arrso_t*   rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_matmul_RF(    darr_t*    lhs, fearrso_t* rhs,                 dhelpl_t dhl);
void      fearrso_matmul_RF_to( darr_t*    lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_matmul_FR(    fearrso_t* lhs, darr_t*    rhs,                 dhelpl_t dhl);
void      fearrso_matmul_FR_to( fearrso_t* lhs, darr_t*    rhs, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fesoti_t fearrso_det(   fearrso_t* arr,                dhelpl_t dhl);
void     fearrso_det_to(fearrso_t* arr, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fearrso_t   fearrso_invert(    fearrso_t* arr,                 dhelpl_t dhl);
void        fearrso_invert_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fearrso_t   fearrso_transpose(   fearrso_t* arr,                 dhelpl_t dhl);
void        fearrso_transpose_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------













#endif