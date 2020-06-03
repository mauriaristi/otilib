#ifndef OTI_FEM_element_BASE_H
#define OTI_FEM_element_BASE_H





/**************************************************************************************************//**
@brief Function to check wether an element object is started.

@param[in] elemso: Address of the element.
******************************************************************************************************/
uint8_t elemso_is_started(   elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function to check wether an element object is allocated.

@param[in] elemso: Address of the element.
******************************************************************************************************/
uint8_t elemso_is_allocated( elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Rise and clear functions of the 'start' flag.

@param[in] elemso: Address of the element.
******************************************************************************************************/
void elemso_clear_flag_start(elemso_t* elemso );
void elemso_raise_flag_start(elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Rise and clear functions of the 'allocation' flag.  

@param[in] elemso: Address of the element.
******************************************************************************************************/
void elemso_clear_flag_alloc(elemso_t* elemso );
void elemso_raise_flag_alloc(elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Frees memory of element. Does not frees all values of elements nor re-initialize.

@param[in] elemso: Address of the element.
******************************************************************************************************/
int64_t elemso_end(elemso_t* elemso);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Frees memory of an element structure.

@param[in] Address of the element. This element structure then results with ponters set to NULL and 
values set to 0.
******************************************************************************************************/
int64_t elemso_free( elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Initialize the structure of an element. Sets pointers to NULL and values to 0.

******************************************************************************************************/ 
elemso_t  elemso_init( void );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Setup of an element structure. This defines the interpolation function, and other parameters
to be used.

@param[inout] elemso:     Address of the element structure (Must come after a call to elemso_init().
@param[in]  nbasis:   Number of basis of the element (Equivalent to the number of DOFs of the element)
@param[in]  geomBase: Defines the basic geometry of the element (Line, Triangle, quad, tetrahedra,etc).
@param[in]  kind:     Defines the kind of element Isoparametric or Affine.
@param[in]  ndim:     Number of dimensions of the element.
@param[in]  basis_f:  Pointer to function that defines the interpolation functions and its derivatives.
                      (deprecated).
******************************************************************************************************/ 
// int64_t elemso_start(elemso_t* elemso, uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim,
//               int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*));
int64_t elemso_start( elemso_t* elemso, uint64_t nbasis, int64_t geomBase,
                      int64_t kind, uint8_t ndim, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Allocates memory for the element structure.

@param[inout] elemso: Address of the element structure. Must come after a call to elemso_start(...).
@param[in] intorder: Integration order, defines number of integration points for numerical integration.
******************************************************************************************************/ 
int64_t elemso_allocate(elemso_t* elemso, uint64_t intorder, bases_t bases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



#endif