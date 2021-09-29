#ifndef OTI_SEMISPARSE_SCALAR_ALGEBRA_H
#define OTI_SEMISPARSE_SCALAR_ALGEBRA_H

/**************************************************************************************************//**
@brief Divide two sparse oti numbers.

This function uses temporals 0 - 9.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_div_oo(semiotin_t* num, semiotin_t* den, dhelpl_t dhl);
semiotin_t ssoti_div_ro(   coeff_t num, semiotin_t* den, dhelpl_t dhl);
semiotin_t ssoti_div_or(semiotin_t* num,    coeff_t val, dhelpl_t dhl);

void      ssoti_div_oo_to(semiotin_t* num, semiotin_t* den, semiotin_t* res, dhelpl_t dhl);
void      ssoti_div_ro_to(coeff_t num, semiotin_t* den, semiotin_t* res, dhelpl_t dhl);
void      ssoti_div_or_to(semiotin_t* num, coeff_t val, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply two sparse oti numbers.

This function uses temporals 0, 1, 2, 3, 4, 5.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_mul_oo(   semiotin_t* num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_mul_ro(      coeff_t num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_mul_or(   semiotin_t* num1,    coeff_t num2,                 dhelpl_t dhl);

semiotin_t ssoti_base_mul( semiotin_t* num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_base_trunc_mul(ord_t ord1, semiotin_t* num1, ord_t ord2, semiotin_t* num2, dhelpl_t dhl);

void      ssoti_mul_oo_to(semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
void      ssoti_mul_ro_to(   coeff_t num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
void      ssoti_mul_or_to(semiotin_t* num1,    coeff_t num2, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief General multiplication function. Performs res = a*b + c,

This function uses temporals 0, 1, 2, 3, 4, 5.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_gem_oo_to( semiotin_t* a, semiotin_t* b, semiotin_t* c, semiotin_t* res, dhelpl_t dhl);
void ssoti_gem_or_to( semiotin_t* a,    coeff_t b, semiotin_t* c, semiotin_t* res, dhelpl_t dhl);
void ssoti_gem_ro_to(    coeff_t a, semiotin_t* b, semiotin_t* c, semiotin_t* res, dhelpl_t dhl);

void ssoti_trunc_gem_oo_to(ord_t orda, semiotin_t* a, ord_t ordb, semiotin_t* b, semiotin_t* c, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_sub_oo(    semiotin_t* num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_sub_ro(       coeff_t num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_sub_or(    semiotin_t* num1,    coeff_t num2,                 dhelpl_t dhl);

semiotin_t ssoti_base_sub(semiotin_t* num1, semiotin_t* num2, dhelpl_t dhl);

void      ssoti_sub_oo_to( semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
void      ssoti_sub_ro_to(    coeff_t num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
void      ssoti_sub_or_to( semiotin_t* num1,    coeff_t num2, semiotin_t* res, dhelpl_t dhl);

semiotin_t ssoti_base_trunc_sub(ord_t ord, semiotin_t* num1, semiotin_t* num2, dhelpl_t dhl);
void ssoti_trunc_sub_oo_to(ord_t ord, semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Add two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_sum_oo(    semiotin_t* num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_sum_ro(       coeff_t num1, semiotin_t* num2,                 dhelpl_t dhl);
semiotin_t ssoti_sum_or(    semiotin_t* num1,    coeff_t num2,                 dhelpl_t dhl);

semiotin_t ssoti_base_sum(  semiotin_t* num1, semiotin_t* num2, dhelpl_t dhl);

void      ssoti_sum_oo_to( semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
void      ssoti_sum_ro_to(    coeff_t num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
void      ssoti_sum_or_to( semiotin_t* num1,    coeff_t num2, semiotin_t* res, dhelpl_t dhl);

semiotin_t ssoti_base_trunc_sum(ord_t ord, semiotin_t* num1, semiotin_t* num2, dhelpl_t dhl);
void ssoti_trunc_sum_oo_to(ord_t ord, semiotin_t* num1, semiotin_t* num2, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that negates an oti number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_neg(semiotin_t* num, dhelpl_t dhl);
void      ssoti_neg_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Performs real absolute operation of the number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_abs(   semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_abs_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif