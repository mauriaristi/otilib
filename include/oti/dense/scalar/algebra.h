#ifndef OTI_DENSE_SCALAR_ALGEBRA_H
#define OTI_DENSE_SCALAR_ALGEBRA_H

/**************************************************************************************************//**
@brief Negate an oti numbers.

@param[in] num1 Oti number
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_neg(otinum_t* num1, dhelpl_t dhl);
void     oti_neg_to(otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief subtract two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sub_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
otinum_t oti_sub_or(otinum_t* num1, coeff_t a, dhelpl_t dhl);
otinum_t oti_sub_ro(coeff_t a, otinum_t* num2, dhelpl_t dhl);

void     oti_sub_or_to(otinum_t* num1, coeff_t a, otinum_t* res, dhelpl_t dhl);
void     oti_sub_ro_to(coeff_t a, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
void     oti_sub_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Division between two oti numbers.

@param[in] num Oti number
@param[in] den Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_div_oo(otinum_t* num, otinum_t* den, dhelpl_t dhl );
otinum_t oti_div_ro(coeff_t num, otinum_t* den, dhelpl_t dhl );
otinum_t oti_div_or(otinum_t* num, coeff_t den, dhelpl_t dhl );

void     oti_div_or_to(otinum_t* num, coeff_t den, otinum_t* res, dhelpl_t dhl );
void     oti_div_ro_to(coeff_t num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
void     oti_div_oo_to(otinum_t* num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication between two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_mul_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
otinum_t oti_mul_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl);

void     oti_mul_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
void     oti_mul_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition of two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sum_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
otinum_t oti_sum_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl);

void     oti_sum_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
void     oti_sum_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





#endif