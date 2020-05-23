#ifndef OTI_FEM_ELEMENT_BASE_H
#define OTI_FEM_ELEMENT_BASE_H








/**************************************************************************************************//**
@brief Function to check wether an element object is started.

@param[in] elem: Address of the element.
******************************************************************************************************/
uint8_t elem_is_started(   elem_t* elem );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function to check wether an element object is allocated.

@param[in] elem: Address of the element.
******************************************************************************************************/
uint8_t elem_is_allocated( elem_t* elem );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Rise and clear functions of the 'start' flag.

@param[in] elem: Address of the element.
******************************************************************************************************/
void elem_clear_flag_start(elem_t* elem );
void elem_raise_flag_start(elem_t* elem );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Rise and clear functions of the 'allocation' flag.  

@param[in] elem: Address of the element.
******************************************************************************************************/
void elem_clear_flag_alloc(elem_t* elem );
void elem_raise_flag_alloc(elem_t* elem );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Frees memory of element. Does not frees all values of elements nor re-initialize.

@param[in] elem: Address of the element.
******************************************************************************************************/
int64_t elem_end(elem_t* elem);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Frees memory of an element structure.

@param[in] Address of the element. This element structure then results with ponters set to NULL and 
values set to 0.
******************************************************************************************************/
int64_t elem_free( elem_t* elem );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Initialize the structure of an element. Sets pointers to NULL and values to 0.

******************************************************************************************************/ 
elem_t  elem_init( void );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Setup of an element structure. This defines the interpolation function, and other parameters
to be used.

@param[inout] elem:     Address of the element structure (Must come after a call to elem_init().
@param[in]  nbasis:   Number of basis of the element (Equivalent to the number of DOFs of the element)
@param[in]  geomBase: Defines the basic geometry of the element (Line, Triangle, quad, tetrahedra,etc).
@param[in]  kind:     Defines the kind of element Isoparametric or Affine.
@param[in]  ndim:     Number of dimensions of the element.
@param[in]  basis_f:  Pointer to function that defines the interpolation functions and its derivatives.
                      (deprecated).
******************************************************************************************************/ 
// int64_t elem_start(elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim,
//               int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*));
int64_t elem_start(elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Allocates memory for the element structure.

@param[inout] elem: Address of the element structure. Must come after a call to elem_start(...).
@param[in] intorder: Integration order, defines number of integration points for numerical integration.
******************************************************************************************************/ 
int64_t elem_allocate(elem_t* elem, uint64_t intorder );
// ----------------------------------------------------------------------------------------------------



#endif