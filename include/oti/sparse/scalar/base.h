#ifndef OTI_SPARSE_SCALAR_BASE_H
#define OTI_SPARSE_SCALAR_BASE_H


/**************************************************************************************************//**
@brief Perform a taylor series integration according to the OTI imaginary directions.

@param[in]  deltas Array with the deltas for every imaginary basis.
@param[in]  num   OTI number to Taylor-integrate.
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
sotinum_t soti_taylor_integrate(    coeff_t* deltas, sotinum_t* num,                 dhelpl_t dhl);
void      soti_taylor_integrate_to( coeff_t* deltas, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate everything but the coefficeints at a given order.

@param[in]  ord   Order of imaginary direction to extract.
@param[in]  num   OTI number to truncate direction
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
sotinum_t soti_get_order_im(    ord_t order, sotinum_t* num,                 dhelpl_t dhl);
void      soti_get_order_im_to( ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate an imaginary direction.

@param[in]  num   OTI number to truncate direction
@param[in]  idx   Index of imaginary direction to extract.
@param[in]  ord   Order of imaginary direction to extract.
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
sotinum_t soti_truncate_im(    imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
void      soti_truncate_im_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**
 * @name Sparse OTI Order Truncation Variants
 * Functions that remove all terms of a given order and higher from a sparse OTI number.
 * @{
 */

/**
 * @brief Truncates all terms of order @p ord and higher (allocating variant).
 *
 * The real part is the term of order zero, so it is treated like any other order: @p ord = 0
 * removes every term, including the real part, and the result is zero with truncation order 0.
 * For @p ord >= 1 the real part and all imaginary directions of order 1 to @p ord - 1 are kept,
 * and the result has the truncation order of @p num.
 *
 * @param[in] ord  Lowest order to remove. Terms of order 0 to @p ord - 1 are kept.
 * @param[in] num  OTI number to truncate. Must not be NULL.
 * @param[in] dhl  Direction helper list object.
 *
 * @return Newly allocated sotinum_t holding the truncated number. Caller owns memory and must free
 *         via soti_free().
 *
 * @note The active order of @p num is changed temporarily during the call and restored before
 *       returning, so @p num must not be accessed concurrently from another thread.
 *
 * @see soti_truncate_order_to() for the existing-destination variant.
 */
sotinum_t soti_truncate_order(    ord_t ord, sotinum_t* num,                 dhelpl_t dhl );

/**
 * @brief Truncates all terms of order @p ord and higher into an existing destination.
 *
 * Same semantics as soti_truncate_order(): @p ord = 0 sets @p res to zero, including its real
 * part, and leaves the truncation order of @p res unchanged; for @p ord >= 1 the real part and all
 * imaginary directions of order 1 to @p ord - 1 are copied into @p res.
 *
 * @param[in]     ord  Lowest order to remove. Terms of order 0 to @p ord - 1 are kept.
 * @param[in]     num  OTI number to truncate. Must not be NULL.
 * @param[in,out] res  Destination for the truncated number. Must be initialized (e.g. via
 *                     soti_init()).
 * @param[in]     dhl  Direction helper list object.
 *
 * @note For @p ord >= 1, if @p res lacks the capacity to hold the result, its memory is freed and
 *       reallocated. This requires @p res to own its memory (nonzero flag); a non-owning @p res
 *       without enough capacity terminates the program.
 * @note The active order of @p num is changed temporarily during the call and restored before
 *       returning, so @p num must not be accessed concurrently from another thread.
 *
 * @see soti_truncate_order() for the allocating variant.
 */
void      soti_truncate_order_to( ord_t ord, sotinum_t* num, sotinum_t* res, dhelpl_t dhl );

/** @} */
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract derivative from an OTI number as an oti number.

@param[in]  idx   Index of imaginary direction to extract.
@param[in]  ord   Order of imaginary direction to extract.
@param[in]  num   OTI number to extract direction
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
sotinum_t soti_extract_deriv(   imdir_t idx, ord_t ord, sotinum_t* num,                 dhelpl_t dhl);
void      soti_extract_deriv_to(imdir_t idx, ord_t ord, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract imaginary direction as an OTI number.

@param[in]  idx   Index of imaginary direction to extract.
@param[in]  ord   Order of imaginary direction to extract.
@param[in]  num   OTI number to extract direction
@param[in]  res   Addres of the resulting OTI number that will hold result.
@param[in]  dhl   Direction helper list.
******************************************************************************************************/
sotinum_t soti_extract_im(   imdir_t idx, ord_t ord, sotinum_t* num,                 dhelpl_t dhl);
void      soti_extract_im_to(imdir_t idx, ord_t ord, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function utilities to read and save OTI numbers.

******************************************************************************************************/
void*     soti_read_from_mem_to( void* mem,       sotinum_t* dst, dhelpl_t dhl);
void      soti_save_to_mem(      sotinum_t* num,  void* mem,      dhelpl_t dhl);
uint64_t  soti_get_memsize_save( sotinum_t* num,                  dhelpl_t dhl);
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
void* soti_distribute_memory(void* mem, const ndir_t* p_nnz, ord_t order, flag_t flag, sotinum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that returns the size of memory to be allocated and distributed into a sparse OTI type.

@param[in] p_nnz List of number of non zeros for each order.
@param[in] order Truncation order of the oti number.
******************************************************************************************************/
size_t soti_memory_size( const ndir_t* p_nnz, ord_t order);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that compares memory from two oti numbers and determines weather if memory reallocation 
       is necessary if src is will be copied to dest.

@param[in] src   Address of the source oti number.
@param[in] dest  Address of the destination oti number.
******************************************************************************************************/
uint8_t soti_requiresrealloc(sotinum_t* src, sotinum_t* dest);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of a sparse oti type. This function prevents memory leaks from uninitialized 
       pointers.

******************************************************************************************************/
sotinum_t soti_init(void);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Copy information from src to dest. Does not check if memory needs to be reallocated.
Useful when copying data to a temporal sotinum.

dest = src

@param[in] src  Oti number.
@param[in] dest Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_set_o( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
void soti_set_r(    coeff_t src, sotinum_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy information from src to dest only with orders ord or greater. Does not check if memory 
needs to be reallocated. Useful when copying data to a temporal sotinum.

@param[in] src Oti number.
@param[in] ord Order.
@param[in] dest Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_set_trunc( sotinum_t* src, ord_t ord, sotinum_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Set the derivative corresponding to the index and order.

@param[in] coef Derivative to be set.
@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_set_deriv_r(   coeff_t  coef, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
void soti_set_deriv_o( sotinum_t* coef, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the derivative corresponding to the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t   soti_get_deriv(    imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
sotinum_t soti_get_deriv_o(  imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
void      soti_get_deriv_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Generate a temporal sparse otinum with the allocated data in the direction helper.

@param[in] ntmp Number of temporal array to be retreived.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_get_tmp( ndir_t ntmp, ord_t order, dhelpl_t dhl);
sotinum_t soti_get_rtmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);
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
void soti_insert_item(ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that sets the specified item value.

@param[in] val Value to be set.
@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[inout] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_set_item(   coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
void soti_set_im_r(   coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
void soti_set_im_o(sotinum_t* val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that gets the specified imaginary direction.

@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t soti_get_item(    imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
coeff_t soti_get_im(      imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
sotinum_t soti_get_im_o(  imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
void    soti_get_im_to_o( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
void    soti_get_im_to_r( imdir_t idx, ord_t order, sotinum_t* num,   coeff_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy to another (new) sparse oti elements.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_copy(             sotinum_t* num,                  dhelpl_t dhl);
void      soti_copy_to(          sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
void      soti_copy_nomemchk_to( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Print function for oti numbers

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_print(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory allocated for the given OTI number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_free(sotinum_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a new oti number with reserved memory and given real coefficient. 

@param[in] num Real coefficient of the OTI number.
@param[in] nbases Number of bases.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createReal_bases(  coeff_t num, bases_t nbases, ord_t order, dhelpl_t dhl);
sotinum_t soti_createEmpty_bases(              bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a new oti number with a real coefficient given by the input parameter and 

@param[in] num Real coefficient of the OTI number.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a new sparse oti number in memory. Creation follows the standard memory sizes as 
indicated in dhl.

The number is created with a non-zero real coefficient (which is not initialized) and the creation in 
memory of the other elements correspond to zero value coefficients in the imaginary directions.

@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl); 
sotinum_t soti_createEmpty_like( sotinum_t* other, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a new sparse oti number in memory using a specified allocated size.

@param[in] nnz Array of length order containing the sizes per order to be allocated.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Removes all imaginary directions with orders ranging from ord_start up to ord_end. This function
checks that the orders are within the bounds of the OTI number order

@param[in] ord_start Starting order of im. directions to be removed from the number.
@param[in] ord_end Ending order of im. directions to be removed from the number.
@param[in] num OTI number to be operated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_reset_orders(ord_t ord_start, ord_t ord_end, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif