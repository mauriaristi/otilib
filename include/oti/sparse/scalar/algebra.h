#ifndef OTI_SPARSE_SCALAR_ALGEBRA_H
#define OTI_SPARSE_SCALAR_ALGEBRA_H

/**************************************************************************************************//**
@brief Divide two sparse oti numbers.

This function uses temporals 0 - 9.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_div_oo(sotinum_t* num, sotinum_t* den, dhelpl_t dhl);
sotinum_t soti_div_ro(coeff_t num, sotinum_t* den, dhelpl_t dhl);
sotinum_t soti_div_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);

void      soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
void      soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
void      soti_div_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply two sparse oti numbers.

This function uses temporals 0, 1, 2, 3, 4, 5.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_mul_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
sotinum_t soti_mul_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl);

sotinum_t soti_base_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
void      soti_mul_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
void      soti_mul_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief General multiplication function. Performs res = a*b + c,

This function uses temporals 0, 1, 2, 3, 4, 5.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_gem_oo_to(sotinum_t* a, sotinum_t* b, sotinum_t* c, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sub_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
sotinum_t soti_sub_ro( coeff_t val, sotinum_t* num, dhelpl_t dhl);
sotinum_t soti_sub_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);

sotinum_t soti_base_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
void      soti_sub_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
void      soti_sub_ro_to( coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
void      soti_sub_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sum_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
sotinum_t soti_sum_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl);

sotinum_t soti_base_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
void      soti_sum_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
void      soti_sum_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that negates an oti number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl);
void      soti_neg_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif