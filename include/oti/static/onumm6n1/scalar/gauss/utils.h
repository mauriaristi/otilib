#ifndef OTI_ONUMM6N1_SCALAR_GAUSS_UTILS_H
#define OTI_ONUMM6N1_SCALAR_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void feonumm6n1_dimCheck(feonumm6n1_t* arr1,feonumm6n1_t* arr2);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active oti bases from num.

@param[in] num       Gauss scalar.
@param[in] list_vals List of bases active.
@param[in] dhl       Direction helper list.
******************************************************************************************************/
void feonumm6n1_get_active_bases(feonumm6n1_t* num, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif