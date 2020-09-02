#ifndef OTI_ONUMM2N8_SCALAR_GAUSS_UTILS_H
#define OTI_ONUMM2N8_SCALAR_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void feonumm2n8_dimCheck(feonumm2n8_t* arr1,feonumm2n8_t* arr2);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active oti bases from num.

@param[in] num       Gauss scalar.
@param[in] list_vals List of bases active.
@param[in] dhl       Direction helper list.
******************************************************************************************************/
void feonumm2n8_get_active_bases(feonumm2n8_t* num, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif