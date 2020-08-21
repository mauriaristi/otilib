#ifndef OTI_SPARSE_SCALAR_ALGEBRA_H
#define OTI_SPARSE_SCALAR_ALGEBRA_H


sotinum_t soti_abs(sotinum_t* num, dhelpl_t dhl);
sotinum_t soti_div_ro(coeff_t num, sotinum_t* den, dhelpl_t dhl);
sotinum_t soti_div_oo(sotinum_t* num, sotinum_t* den, dhelpl_t dhl);
sotinum_t soti_div_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);
void soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
void soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
void soti_div_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
void soti_abs_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);


<<<algebra_include>>>



#endif