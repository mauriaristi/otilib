#ifndef OTI_SPARSE_SCALAR_GAUSS_UTILS_H
#define OTI_SPARSE_SCALAR_GAUSS_UTILS_H



/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void fesoti_dimCheck(fesoti_t* arr1,fesoti_t* arr2);
// ----------------------------------------------------------------------------------------------------

void fesoti_get_active_bases(fesoti_t* num, imdir_t* list_vals, dhelpl_t dhl);



#endif