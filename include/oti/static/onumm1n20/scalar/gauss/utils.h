#ifndef OTI_ONUMM1N20_SCALAR_GAUSS_UTILS_H
#define OTI_ONUMM1N20_SCALAR_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void feonumm1n20_dimCheck(feonumm1n20_t* arr1,feonumm1n20_t* arr2);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active oti bases from num.

@param[in] num       Gauss scalar.
@param[in] list_vals List of bases active.
@param[in] dhl       Direction helper list.
******************************************************************************************************/
void feonumm1n20_get_active_bases(feonumm1n20_t* num, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif