#ifndef OTI_SPARSE_CORE_BASE_H
#define OTI_SPARSE_CORE_BASE_H


void soticore_set_all_imidx( const bases_t* bases, soticore_t* obj,  dhelpl_t dhl);

/*****************************************************************************************************//**
@brief Set/unset memory ownership flags for the OTI core structure.

*********************************************************************************************************/
void soticore_set_memory_ownership(   soticore_t*  );
void soticore_unset_memory_ownership( soticore_t*  );
// -------------------------------------------------------------------------------------------------------

/*****************************************************************************************************//**
@brief Function that distributes memory along the different components of a sparse OTI core structure.

@param[in]     mem   Address of the allocated memory.
@param[inout]  res   Address of the resulting OTI structure that will be setup accordingly. Must Contain
                     the order (flags), nbases and ncoeffs already defined. Memory ownership flag set
                     OUTSIDE of this function.
@returns void* Address after OTI memory block was distributed.

*********************************************************************************************************/
void* soticore_distribute_memory( void* mem, soticore_t* res );
// -------------------------------------------------------------------------------------------------------

/*****************************************************************************************************//**
@brief Function that returns the size of memory to be allocated and distributed into a sparse OTI core
       type.

@param[in] nimdir Total number of coefficients for this number.
@param[in] nbases Number of bases of the number
@param[in] order Truncation/actual order of the oti number.

*********************************************************************************************************/
size_t soticore_memory_size( ndir_t nimdir, bases_t nbases, ord_t order);
// -------------------------------------------------------------------------------------------------------

/*****************************************************************************************************//**
@brief Initialization of a sparse OTI structure core type. This function prevents memory leaks from 
       uninitialized pointers in the structure.

*********************************************************************************************************/
soticore_t soticore_init(void);
void soticore_initialize(soticore_t* res);
// -------------------------------------------------------------------------------------------------------

#endif