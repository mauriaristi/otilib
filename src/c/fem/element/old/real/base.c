
// Memory management.
// ****************************************************************************************************
int64_t elem_free( elem_t* elem ) {

    int64_t derId;


    if (elem->isInit != 0){
    
        // Free the integration point and integration weight arrays.
       
        darr_free(&elem->intPts);
        darr_free(&elem->intWts);
        
        // Loop through all derivatives
        for(derId = 0; derId<elem->nder; derId++){
            
            // free every.
            darr_free(&elem->p_evalBasis[derId]);

        }
    
        // Free pointer       
        free( elem->p_evalBasis );

        // Reset all values.
        *elem = elem_init();

    }
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
elem_t  elem_init( void ){

    elem_t res;

    res.nbasis      = 0; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    res.order       = 0; ///< Maximum order of 
    res.geomBase    = 0; ///< Geometric element type - elLine, elTriangle, etc ...
    res.kind        = 0; ///< Kind of element: Affine - IsoParametric
    res.ndim        = 0; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    res.nIntPts     = 0; ///< Number of integration Points
    res.nder        = 0; ///< Number of total derivatives in the problem.
    res.isInit      = 0; ///< Initialization flag. byte 0: Started, Byte 1: Allocation.
    res.nDimAnalysis= 0; ///< Number of dimensions of the analysis.
    res.intPts      = darr_init(); ///< (nIntPts x ndim) Array with the integration points coordinates.
    res.intWts      = darr_init(); ///< (nIntPts x 1   ) Array with the integration weights.
    res.p_evalBasis = NULL; ///< (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    // res.f_basis     = NULL; ///<  Interpolation function.

    return res;
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t elem_start(elem_t* elem, uint64_t nbasis, int64_t geomBase,
                       int64_t  kind,   uint8_t  ndim) {

    int64_t  derIdx;

    uint8_t nder;
    

    if ( ndim == 0 ){

        nder = 1;

    } else if( ndim == 1 ) {

        nder = 3;

    } else if (ndim == 2) {

        nder = 6;

    } else {

        nder = 10;

    }

    nder = 10;



    // Check first if the element is already allocated.
    if( (elem->isInit & 1) == 0 ){
   
        elem->nbasis   = nbasis;
        elem->nder     = nder;
        elem->ndim     = ndim;
        elem->kind     = kind;
        // elem->f_basis  = basis_f;
        elem->geomBase = geomBase;

        // Get the integration points and integration weights.
        // This function allocates memory.
        elem->intPts = darr_init();
        elem->intWts = darr_init();
        
        elem->p_evalBasis = (darr_t*  ) malloc( elem->nder*sizeof(darr_t  ) ) ;

        if( elem->p_evalBasis == NULL ){
            printf("--- MemoryError ---\n");
            exit(1);
        }        

        // Evaluate all basis functions at integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elem->nder; derIdx++){

            // Allocate new array
            elem->p_evalBasis[derIdx] = darr_init();

        }
        
        elem_raise_flag_start(elem);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t elem_end(elem_t* elem) {

    int64_t  derIdx;

    // Check first if the element is already allocated.
    if ( elem_is_started(elem) && elem_is_allocated(elem) ){
   

        // Get the integration points and integration weights.
        // This function allocates memory.
        darr_free(&elem->intPts);
        darr_free(&elem->intWts);
        
        for(derIdx = 0; derIdx<elem->nder; derIdx++){

            // Allocate new array
            darr_free(&elem->p_evalBasis[derIdx]);

        }
        
        elem_clear_flag_alloc(elem);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t elem_allocate(elem_t* elem, uint64_t intorder ) {


    int64_t  derIdx;
    // uint64_t basisId;

    // Check first if the element is already Initialized.
    if( elem_is_started(elem) ) {
   
        elem->order    = intorder;
        
        // Define the Gaussian integration point coordinates and weights.
        fem_integrationPoints(elem->order, elem->geomBase, &elem->intPts, &elem->intWts);
        
        elem->nIntPts = elem->intPts.nrows;
        
        // Evaluate all basis functions at the integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elem->nder; derIdx++){

            // Allocate new array
            elem->p_evalBasis[derIdx] = darr_zeros(elem->nbasis, elem->nIntPts);

            // Evaluate all basis functions.
            // Loop through all basis functions.
            // for(basisId = 0; basisId<elem->nbasis; basisId++){
            //     elem->f_basis(basisId, derIdx + derN, &elem->intPts, NULL, &elem->p_evalBasis[derIdx]);
            // }

        }
        
        elem_raise_flag_alloc(elem);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline uint8_t elem_is_started( elem_t* elem ){

    if (elem->isInit & 1){
    
        return 1;
    
    }else{
    
        return 0;
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline uint8_t elem_is_allocated( elem_t* elem ){
    
    if (elem->isInit & 1<<2){
    
        return 1;
    
    }else{
    
        return 0;
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elem_clear_flag_start(elem_t* elem ){
    
    // Lower flag of allocation.
    elem->isInit = elem->isInit & ( 255 ^ 1 ); 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elem_clear_flag_alloc(elem_t* elem ){

    // Lower flag of start.
    elem->isInit = elem->isInit & ( 255 ^ (1<<2) ); 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elem_raise_flag_start(elem_t* elem ){
    
    elem->isInit = elem->isInit | 1 ;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void elem_raise_flag_alloc(elem_t* elem ){

    elem->isInit = elem->isInit | 1<<2 ;

}
// ----------------------------------------------------------------------------------------------------









