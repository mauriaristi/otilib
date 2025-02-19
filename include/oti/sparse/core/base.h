#ifndef OTI_SPARSE_CORE_BASE_H
#define OTI_SPARSE_CORE_BASE_H


/*****************************************************************************************************//**
@brief Set all imaginary indices.

@param[in] bases: List of the bases to be set.
@param[inout] obj: soticore object to be set from the bases definition.

*********************************************************************************************************/
void soticore_set_all_imidx( const bases_t* bases, soticore_t* obj,  dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------

/*****************************************************************************************************//**
@brief Initializes a soticore structre. This Nullyfies all pointers, making it "safe" to avoid accessing
wrong memory addresses.

Usage: When declaring a soticore structure. 

       soticore_t num = soticore_init();

In case you need this to behave as a real number, the initializer function must be used afterwards. 

       soticore_t num = soticore_init();
       soticore_initialize( &num );


*********************************************************************************************************/
soticore_t soticore_init(void);
// -------------------------------------------------------------------------------------------------------

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
void soticore_initialize(soticore_t* res);
// -------------------------------------------------------------------------------------------------------

#endif