#ifndef OTI_FEM_FUNCTIONS_H
#define OTI_FEM_FUNCTIONS_H



// /**************************************************************************************************//**
// @brief    Define a constant function from a real number.
// 
// @param[in]    p_arr1:     (1 x nbasis) otinum values of the function.
// @param[in]    derIndx:    Basis Id that defines this function.
// @param[in]    elem:       Element that interpolates the data.
// @param[inout] res:   (1 x 1) Address of the array that holds the result.
// @param[in]    dhl:       Direction helper
// @param[out]  Error code. 0 Success. See include/oti/fem/enums.h for more error codes.
// ******************************************************************************************************/
// int64_t fem_defFunctFrom_otiFunc(oarr_t* arr1, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
//     dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief    Define a constant function from a real number.
// 
// @param[in]    num:        otinum value of the constant function.
// @param[in]    derIndx:    Basis Id that defines this function.
// @param[in]    elem:       Element that interpolates the data.
// @param[inout] res:   (1 x 1) Address of the array that holds the result.
// @param[in]    dhl:       Direction helper.
// @param[out]  Error code. 0 Success. See include/oti/fem/enums.h for more error codes.
// ******************************************************************************************************/
// int64_t fem_defFunctFrom_oti(otinum_t* num, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
//     dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief    Define a constant function from a real number.
// 
// @param[in]    num:        Real value of the constant function.
// @param[in]    derIndx:    Basis Id that defines this function.
// @param[in]    elem:       Element that interpolates the data.
// @param[inout] res:   (1 x 1) Address of the array that holds the result.
// @param[in]    dhl:       Direction helper.
// @param[out]  Error code. 0 Success. See include/oti/fem/enums.h for more error codes.
// @param[in]
// ******************************************************************************************************/
// int64_t fem_defFunctFrom_R(coeff_t num, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
//     dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief 
// 
// @param[in]
// ******************************************************************************************************/
// int64_t fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief 
// 
// @param[in]
// ******************************************************************************************************/
// int64_t fem_computeJacobian( elemProps_t* elem, oarr_t* xcoords, oarr_t* ycoords,
//                                oarr_t* zcoords, dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief 
// 
// @param[in]
// ******************************************************************************************************/
// int64_t fem_unInitElement(elemProps_t* elem);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief 
// 
// @param[in]
// ******************************************************************************************************/
// int64_t fem_initElement(uint64_t order, uint8_t otiorder,uint8_t nDimAnalysis, elemProps_t* elem);
// // ----------------------------------------------------------------------------------------------------
// 
// 
// /**************************************************************************************************//**
// @brief 
// 
// @param[in]
// ******************************************************************************************************/
// int64_t fem_integrateSOTIfunct(oarr_t* f_eval, darr_t* weights, otinum_t* res,
//                                  dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------
// 
// 






#endif
