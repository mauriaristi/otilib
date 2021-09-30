#ifndef OTI_SEMISPARSE_SCALAR_BASE_H
#define OTI_SEMISPARSE_SCALAR_BASE_H


/**************************************************************************************************//**
@brief Perform a taylor series integration according to the OTI imaginary directions.

@param[in]  deltas Array with the deltas for every imaginary basis.
@param[in]  num   OTI number to Taylor-integrate.
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
semiotin_t ssoti_taylor_integrate(    coeff_t* deltas, semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_taylor_integrate_to( coeff_t* deltas, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate everything but the coefficeints at a given order.

@param[in]  ord   Order of imaginary direction to extract.
@param[in]  num   OTI number to truncate direction
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
semiotin_t ssoti_get_order_im(    ord_t order, semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_get_order_im_to( ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate an imaginary direction.

@param[in]  num   OTI number to truncate direction
@param[in]  idx   Index of imaginary direction to extract.
@param[in]  ord   Order of imaginary direction to extract.
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
semiotin_t ssoti_truncate_im(    imdir_t idx, ord_t order, semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_truncate_im_to( imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract derivative from an OTI number as an oti number.

@param[in]  idx   Index of imaginary direction to extract.
@param[in]  ord   Order of imaginary direction to extract.
@param[in]  num   OTI number to extract direction
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
semiotin_t ssoti_extract_deriv(   imdir_t idx, ord_t ord, semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_extract_deriv_to(imdir_t idx, ord_t ord, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract imaginary direction as an OTI number.

@param[in]  idx   Index of imaginary direction to extract.
@param[in]  ord   Order of imaginary direction to extract.
@param[in]  num   OTI number to extract direction
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
semiotin_t ssoti_extract_im(   imdir_t idx, ord_t ord, semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_extract_im_to(imdir_t idx, ord_t ord, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function utilities to read and save OTI numbers.

******************************************************************************************************/
void*     ssoti_read_from_mem_to( void* mem,       semiotin_t* dst, dhelpl_t dhl);
void      ssoti_save_to_mem(      semiotin_t* num,  void* mem,      dhelpl_t dhl);
uint64_t  ssoti_get_memsize_save( semiotin_t* num,                  dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function that distribute memory along the different components of an OTI number.

@param[in]  mem   Addres of the allocated memory.
@param[in]  p_nnz List of values corresponding to the allocation size per element.
@param[in]  order OTI Truncation order.
@param[in]  flag  Memory flag. flag=1 means memory is owned by the respective sotinum, otherwise flag=0.
@param[in]  res   Addres of the resulting OTI number that will be distributed accordingly.
@param[out] void* Address after every item was distributed.
******************************************************************************************************/
void* ssoti_distribute_memory(void* mem, const ndir_t* p_nnz, ord_t order, flag_t flag, semiotin_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that compares memory from two oti numbers and determines weather if memory reallocation 
       is necessary if src is will be copied to dest.

@param[in] src   Address of the source oti number.
@param[in] dest  Address of the destination oti number.
******************************************************************************************************/
uint8_t ssoti_requiresrealloc(semiotin_t* src, semiotin_t* dest);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of a sparse oti type. This function prevents memory leaks from uninitialized 
       pointers.

******************************************************************************************************/
semiotin_t ssoti_init(void);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Copy information from src to dest. Does not check if memory needs to be reallocated.
Useful when copying data to a temporal sotinum.

dest = src

@param[in] src  Oti number.
@param[in] dest Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void ssoti_set_o( semiotin_t* src, semiotin_t* dest, dhelpl_t dhl);
void ssoti_set_r(    coeff_t src, semiotin_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy information from src to dest only with orders ord or greater. Does not check if memory 
needs to be reallocated. Useful when copying data to a temporal sotinum.

@param[in] src Oti number.
@param[in] ord Order.
@param[in] dest Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void ssoti_set_trunc( semiotin_t* src, ord_t ord, semiotin_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Set the derivative corresponding to the index and order.

@param[in] coef Derivative to be set.
@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_set_deriv_r(   coeff_t  coef, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl);
void ssoti_set_deriv_o( semiotin_t* coef, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the derivative corresponding to the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t   ssoti_get_deriv(    imdir_t idx, ord_t order, semiotin_t* num,                 dhelpl_t dhl);
semiotin_t ssoti_get_deriv_o(  imdir_t idx, ord_t order, semiotin_t* num,                 dhelpl_t dhl);
void      ssoti_get_deriv_to( imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Generate a temporal sparse otinum with the allocated data in the direction helper.

@param[in] ntmp Number of temporal array to be retreived.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_get_tmp(ndir_t ntmp, ord_t trc_order, dhelpl_t dhl);
semiotin_t ssoti_get_rtmp(ndir_t ntmp, ord_t trc_order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Function that inserts the corresponding value in the arrays defining the oti number. If the 
array requires reallocation, it performs the reallocation in memory. This function preserves the order
of the indices.

@param[in] val Value to be set.
@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[inout] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_insert_item(ndir_t pos, coeff_t val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that sets the specified item value.

@param[in] val Value to be set.
@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[inout] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_set_item(   coeff_t val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl);
void ssoti_set_im_r(   coeff_t val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl);
void ssoti_set_im_o(semiotin_t* val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that gets the specified imaginary direction.

@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t ssoti_get_item(    imdir_t idx, ord_t order, semiotin_t* num,                 dhelpl_t dhl);
coeff_t ssoti_get_im(      imdir_t idx, ord_t order, semiotin_t* num,                 dhelpl_t dhl);
semiotin_t ssoti_get_im_o(  imdir_t idx, ord_t order, semiotin_t* num,                 dhelpl_t dhl);
void    ssoti_get_im_to_o( imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
void    ssoti_get_im_to_r( imdir_t idx, ord_t order, semiotin_t* num,   coeff_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy to another (new) sparse oti elements.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_copy(             semiotin_t* num,                  dhelpl_t dhl);
void      ssoti_copy_to(          semiotin_t* src, semiotin_t* dest, dhelpl_t dhl);
void      ssoti_copy_nomemchk_to( semiotin_t* src, semiotin_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Print function for oti numbers

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_print(semiotin_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory allocated for the given OTI number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_free(semiotin_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a new oti number with reserved memory and given real coefficient. 

@param[in] num Real coefficient of the OTI number.
@param[in] nbases Number of bases.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_createReal_bases(  coeff_t num, bases_t nbases, ord_t order, dhelpl_t dhl);
semiotin_t ssoti_createEmpty_bases(              bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a new oti number with a real coefficient given by the input parameter as well as 
the truncation order.  

@param[in] num Real coefficient of the OTI number.
@param[in] nbases Truncation order.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_createReal(coeff_t num, bases_t tot_nbases, ord_t trc_order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a new sparse oti number in memory. Creation follows the standard memory sizes as 
indicated in dhl.

The number is created with a non-zero real coefficient (which is initialized to zero) and memory is 
allocated according to the pair tot_nbases and trc_order.

@param[in] tot_nbases Total number of bases to allocate.
@param[in] trc_order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_createEmpty( bases_t tot_nbases, ord_t trc_order, dhelpl_t dhl); 
semiotin_t ssoti_createEmpty_like( semiotin_t* other, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a new sparse oti number in memory using a specified allocated size.

@param[in] nnz Array of length order containing the sizes per order to be allocated.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_createEmpty_predef( bases_t nbases, ord_t trc_order, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Removes all imaginary directions with orders ranging from ord_start up to ord_end. This function
checks that the orders are within the bounds of the OTI number order

@param[in] ord_start Starting order of im. directions to be removed from the number.
@param[in] ord_end Ending order of im. directions to be removed from the number.
@param[in] num OTI number to be operated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void ssoti_reset_orders(ord_t ord_start, ord_t ord_end, semiotin_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif