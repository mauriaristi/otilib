#ifndef OTI_{module_name_upper}_SCALAR_GAUSS_UTILS_H
#define OTI_{module_name_upper}_SCALAR_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Dimension checker. Checks that both elements have the same number of integration points.

@param[in] num1 Gauss scalar 1.
@param[in] num2 Gauss scalar 2.
******************************************************************************************************/
void {fenum_func}_dimCheck({fenum_type}* arr1,{fenum_type}* arr2);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active oti bases from num.

@param[in] num       Gauss scalar.
@param[in] list_vals List of bases active.
@param[in] dhl       Direction helper list.
******************************************************************************************************/
void {fenum_func}_get_active_bases({fenum_type}* num, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif