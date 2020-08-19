#ifndef OTI_MDNUM3_SCALAR_GAUSS_UTILS_H
#define OTI_MDNUM3_SCALAR_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void femdnum3_dimCheck(femdnum3_t* arr1,femdnum3_t* arr2);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active oti bases from num.

@param[in] num       Gauss scalar.
@param[in] list_vals List of bases active.
@param[in] dhl       Direction helper list.
******************************************************************************************************/
void femdnum3_get_active(femdnum3_t* num, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif