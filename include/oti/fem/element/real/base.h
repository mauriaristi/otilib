#ifndef OTI_FEM_ELEMENT_REAL_BASE_H
#define OTI_FEM_ELEMENT_REAL_BASE_H







/**************************************************************************************************//**
@brief Function to check wether an element object is started.

@param[in] elemd: Address of the element.
******************************************************************************************************/
uint8_t elemd_is_started(   elemd_t* elemd );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function to check wether an element object is allocated.

@param[in] elemd: Address of the element.
******************************************************************************************************/
uint8_t elemd_is_allocated( elemd_t* elemd );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Rise and clear functions of the 'start' flag.

@param[in] elemd: Address of the element.
******************************************************************************************************/
void elemd_clear_flag_start(elemd_t* elemd );
void elemd_raise_flag_start(elemd_t* elemd );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Rise and clear functions of the 'allocation' flag.  

@param[in] elemd: Address of the element.
******************************************************************************************************/
void elemd_clear_flag_alloc(elemd_t* elemd );
void elemd_raise_flag_alloc(elemd_t* elemd );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Frees memory of element. Does not frees all values of elements nor re-initialize.

@param[in] elemd: Address of the element.
******************************************************************************************************/
int64_t elemd_end(elemd_t* elemd);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Frees memory of an element structure.

@param[in] Address of the element. This element structure then results with ponters set to NULL and 
values set to 0.
******************************************************************************************************/
int64_t elemd_free( elemd_t* elemd );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Initialize the structure of an element. Sets pointers to NULL and values to 0.

******************************************************************************************************/ 
elemd_t  elemd_init( void );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Setup of an element structure. This defines the interpolation function, and other parameters
to be used.

@param[inout] elemd:     Address of the element structure (Must come after a call to elemd_init().
@param[in]  nbasis:   Number of basis of the element (Equivalent to the number of DOFs of the element)
@param[in]  geomBase: Defines the basic geometry of the element (Line, Triangle, quad, tetrahedra,etc).
@param[in]  kind:     Defines the kind of element Isoparametric or Affine.
@param[in]  ndim:     Number of dimensions of the element.
@param[in]  basis_f:  Pointer to function that defines the interpolation functions and its derivatives.
                      (deprecated).
******************************************************************************************************/ 
int64_t elemd_start( elemd_t* elemd, uint64_t nbasis, int64_t geomBase,
                      int64_t kind, uint8_t ndim );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Allocates memory for the element structure.

@param[inout] elemd: Address of the element structure. Must come after a call to elemd_start(...).
@param[in] intorder: Integration order, defines number of integration points for numerical integration.
******************************************************************************************************/ 
int64_t elemd_allocate(elemd_t* elemd, uint64_t intorder );
// ----------------------------------------------------------------------------------------------------




#endif