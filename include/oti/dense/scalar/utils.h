#ifndef OTI_DENSE_SCALAR_UTILS_H
#define OTI_DENSE_SCALAR_UTILS_H


/**************************************************************************************************//**
@brief Convert dense oti number to cauchy riemann representation (dense form).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
darr_t oti_to_cr_dense(otinum_t* num,  dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




#endif