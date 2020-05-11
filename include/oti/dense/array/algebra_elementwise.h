#ifndef OTI_DENSE_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_DENSE_ARRAY_ALGEBRA_ELEMENTWISE_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY OPERATIONS    --------------------------------------
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Negation of an OTI array

RES = - ARR

@param[in] arr OTI array
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_neg( oarr_t* arr, dhelpl_t dhl);
void   oarr_neg_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END ARRAY OPERATIONS    --------------------------------------
// ----------------------------------------------------------------------------------------------------












// ----------------------------------------------------------------------------------------------------
// -------------------------------------- ARRAY - ARRAY OPERATIONS ------------------------------------
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise matrix addition. At least one of the arrays is OTI.

Example:

RES = LHS / RHS

@param[in] LHS Left hand side array.
@param[in] RHS Right hand side array.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_sum_OO(oarr_t* lhs, oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_sum_RO(darr_t* lhs, oarr_t* rhs, dhelpl_t dhl);

void   oarr_sum_OO_to(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_sum_RO_to(darr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise matrix subtraction. At least one of the arrays is OTI.

Example:

RES = LHS - RHS

@param[in] LHS Left hand side array.
@param[in] RHS Right hand side array.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_sub_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
oarr_t oarr_sub_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
oarr_t oarr_sub_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);

void   oarr_sub_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
void   oarr_sub_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
void   oarr_sub_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise matrix multiplication. At least one of the arrays is OTI.

Example:

RES = LHS * RHS

@param[in] LHS Left hand side array.
@param[in] RHS Right hand side array.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_mul_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
oarr_t oarr_mul_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);

void   oarr_mul_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
void   oarr_mul_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise matrix division. At least one of the arrays is OTI.

Example:

RES = LHS / RHS

@param[in] LHS Left hand side array.
@param[in] RHS Right hand side array.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_div_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
oarr_t oarr_div_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
oarr_t oarr_div_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);

void   oarr_div_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
void   oarr_div_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
void   oarr_div_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------   END ARRAY - ARRAY OPERATIONS    ---------------------------------
// ----------------------------------------------------------------------------------------------------






















// ----------------------------------------------------------------------------------------------------
// ---------------------------------      SCALAR - ARRAY OPERATIONS      ------------------------------
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise addition by scalar (Either LHS or RHS is scalar, the other is an OTI array).

Example:

RES = LHS + rhs

@param[in] LHS OTI array / scalar.
@param[in] RHS OTI array / scalar.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_sum_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
oarr_t oarr_sum_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);

void   oarr_sum_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
void   oarr_sum_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise subtraction by scalar (Either LHS or RHS is scalar, the other is an OTI array).

Example:

RES = LHS - rhs

@param[in] LHS OTI array / scalar.
@param[in] RHS OTI array / scalar.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_sub_oO(otinum_t* lhs,   oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_sub_Oo(  oarr_t* lhs, otinum_t* rhs, dhelpl_t dhl);
oarr_t oarr_sub_rO(  coeff_t lhs,   oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_sub_Or(  oarr_t* lhs,   coeff_t rhs, dhelpl_t dhl);

void   oarr_sub_oO_to(otinum_t* lhs,   oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_sub_Oo_to(  oarr_t* lhs, otinum_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_sub_rO_to(  coeff_t lhs,   oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_sub_Or_to(  oarr_t* lhs,   coeff_t rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise multiplication by scalar.(Either LHS or RHS is scalar, the other is an OTI array)

Example: 

RES = LHS * rhs

@param[in] LHS OTI array / scalar.
@param[in] RHS OTI array / scalar.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_mul_oO(otinum_t* lhs, oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_mul_rO(  coeff_t lhs, oarr_t* rhs, dhelpl_t dhl);

void   oarr_mul_oO_to(otinum_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_mul_rO_to(  coeff_t lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise division (Either LHS or RHS is scalar, the other is an OTI array).

Example: 

RES = LHS / rhs

@param[in] LHS OTI array / scalar.
@param[in] RHS OTI array / scalar.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
oarr_t oarr_div_oO(otinum_t* lhs,   oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_div_Oo(  oarr_t* lhs, otinum_t* rhs, dhelpl_t dhl);
oarr_t oarr_div_rO(  coeff_t lhs,   oarr_t* rhs, dhelpl_t dhl);
oarr_t oarr_div_Or(  oarr_t* lhs,   coeff_t rhs, dhelpl_t dhl);

void   oarr_div_oO_to(otinum_t* lhs,   oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_div_Oo_to(  oarr_t* lhs, otinum_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_div_rO_to(  coeff_t lhs,   oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void   oarr_div_Or_to(  oarr_t* lhs,   coeff_t rhs, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------    END  SCALAR - ARRAY OPERATIONS      ------------------------------
// ----------------------------------------------------------------------------------------------------







#endif