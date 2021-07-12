#ifndef OTI_COMPLEX_ARRAY_GAUSS_ALGEBRA_H
#define OTI_COMPLEX_ARRAY_GAUSS_ALGEBRA_H






/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fecarr_t  fecarr_neg(    fecarr_t * arr                );
void      fecarr_neg_to( fecarr_t * arr, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fecarr_t  fecarr_sum_FF(   fecarr_t * lhs, fecarr_t * rhs                );
void      fecarr_sum_FF_to(fecarr_t * lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_sum_fF(    fecnum_t* lhs, fecarr_t * rhs                );
void      fecarr_sum_fF_to( fecnum_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_sum_RF(      carr_t* lhs, fecarr_t * rhs                );
void      fecarr_sum_RF_to(   carr_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_sum_rF(     ccoeff_t  lhs, fecarr_t * rhs                );
void      fecarr_sum_rF_to(  ccoeff_t  lhs, fecarr_t * rhs, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fecarr_t  fecarr_sub_FF(    fecarr_t * lhs, fecarr_t * rhs                );
void      fecarr_sub_FF_to( fecarr_t * lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_sub_fF(    fecnum_t* lhs, fecarr_t * rhs                 );
void      fecarr_sub_fF_to( fecnum_t* lhs, fecarr_t * rhs, fecarr_t * res );

fecarr_t  fecarr_sub_Ff(    fecarr_t * lhs, fecnum_t* rhs                 );
void      fecarr_sub_Ff_to( fecarr_t * lhs, fecnum_t* rhs, fecarr_t * res );

fecarr_t  fecarr_sub_RF(       carr_t* lhs, fecarr_t * rhs                );
void      fecarr_sub_RF_to(    carr_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_sub_FR(    fecarr_t * lhs,    carr_t* rhs                );
void      fecarr_sub_FR_to( fecarr_t * lhs,    carr_t* rhs, fecarr_t * res);

fecarr_t  fecarr_sub_rF(      ccoeff_t  lhs, fecarr_t * rhs                );
void      fecarr_sub_rF_to(    ccoeff_t lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_sub_Fr(    fecarr_t * lhs,   ccoeff_t  rhs                );
void      fecarr_sub_Fr_to( fecarr_t * lhs,   ccoeff_t  rhs, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fecarr_t  fecarr_mul_FF(   fecarr_t * lhs, fecarr_t * rhs                );
void      fecarr_mul_FF_to(fecarr_t * lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_mul_fF(    fecnum_t* lhs, fecarr_t * rhs                );
void      fecarr_mul_fF_to( fecnum_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_mul_RF(      carr_t* lhs, fecarr_t * rhs                );
void      fecarr_mul_RF_to(   carr_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_mul_rF(     ccoeff_t  lhs, fecarr_t * rhs                );
void      fecarr_mul_rF_to(  ccoeff_t  lhs, fecarr_t * rhs, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fecarr_t  fecarr_div_FF(    fecarr_t * lhs, fecarr_t * rhs                );
void      fecarr_div_FF_to( fecarr_t * lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_div_fF(     fecnum_t* lhs, fecarr_t * rhs                );
void      fecarr_div_fF_to(  fecnum_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_div_Ff(    fecarr_t* lhs,  fecnum_t* rhs                );
void      fecarr_div_Ff_to( fecarr_t* lhs,  fecnum_t* rhs, fecarr_t * res);

fecarr_t  fecarr_div_RF(       carr_t* lhs, fecarr_t * rhs                );
void      fecarr_div_RF_to(    carr_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_div_FR(    fecarr_t* lhs,    carr_t* rhs                );
void      fecarr_div_FR_to( fecarr_t* lhs,    carr_t* rhs, fecarr_t * res);

fecarr_t  fecarr_div_rF(      ccoeff_t  lhs, fecarr_t * rhs                );
void      fecarr_div_rF_to(    ccoeff_t lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_div_Fr(    fecarr_t* lhs,   ccoeff_t  rhs                );
void      fecarr_div_Fr_to( fecarr_t* lhs,   ccoeff_t  rhs, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
carr_t  fecarr_integrate(    fecarr_t* arr, fecnum_t* w              );
void    fecarr_integrate_to( fecarr_t* arr, fecnum_t* w, carr_t* res);
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
fecnum_t fecarr_dotproduct_FF(    fecarr_t* lhs, fecarr_t * rhs               );
void     fecarr_dotproduct_FF_to( fecarr_t* lhs, fecarr_t * rhs, fecnum_t* res);

fecnum_t fecarr_dotproduct_RF(       carr_t* lhs, fecarr_t * rhs               );
void     fecarr_dotproduct_RF_to(    carr_t* lhs, fecarr_t * rhs, fecnum_t* res);
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
fecarr_t  fecarr_matmul_FF(    fecarr_t* lhs, fecarr_t * rhs                );
void      fecarr_matmul_FF_to( fecarr_t* lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_matmul_RF(    carr_t*    lhs, fecarr_t * rhs                );
void      fecarr_matmul_RF_to( carr_t*    lhs, fecarr_t * rhs, fecarr_t * res);

fecarr_t  fecarr_matmul_FR(    fecarr_t* lhs, carr_t*    rhs                );
void      fecarr_matmul_FR_to( fecarr_t* lhs, carr_t*    rhs, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fecnum_t fecarr_det(   fecarr_t* arr               );
void     fecarr_det_to(fecarr_t* arr, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fecnum_t fecarr_norm(     fecarr_t* arr               );
void     fecarr_norm_to(  fecarr_t* arr, fecnum_t* res);

fecnum_t fecarr_pnorm(    fecarr_t* arr, ccoeff_t p               );
void     fecarr_pnorm_to( fecarr_t* arr, ccoeff_t p, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fecarr_t    fecarr_invert(    fecarr_t* arr                );
void        fecarr_invert_to( fecarr_t* arr, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fecarr_t    fecarr_transpose(   fecarr_t* arr                );
void        fecarr_transpose_to(fecarr_t* arr, fecarr_t * res);
// ----------------------------------------------------------------------------------------------------









#endif