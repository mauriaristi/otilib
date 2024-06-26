#ifndef OTI_ONUMM3N2_SCALAR_GAUSS_UTILS_H
#define OTI_ONUMM3N2_SCALAR_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void feonumm3n2_dimCheck(feonumm3n2_t* arr1,feonumm3n2_t* arr2);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active oti bases from num.

@param[in] num       Gauss scalar.
@param[in] list_vals List of bases active.
@param[in] dhl       Direction helper list.
******************************************************************************************************/
void feonumm3n2_get_active_bases(feonumm3n2_t* num, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif