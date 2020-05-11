#ifndef OTI_DENSE_ARRAY_FUNCTIONS_H
#define OTI_DENSE_ARRAY_FUNCTIONS_H

/**************************************************************************************************//**
@brief  Function evaluation of OTI numbers.

RES = FEVAL( RE, ARR)

@param[in] re  List of real arrays containing the derivatives of a function.
@param[in] arr OTI array. Must be square
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_feval(    darr_t* re, oarr_t* arr,              dhelpl_t dhl );
void   oarr_feval_to( darr_t* re, oarr_t* arr, oarr_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

#endif