
// Memory management.
// ****************************************************************************************************
int64_t elemso_free( elemso_t* elemso ) {

    int64_t derId;


    if (elemso->isInit != 0){
    
        // Free the integration point and integration weight arrays.
       
        fesoti_free(&elemso->xi  ); 
        fesoti_free(&elemso->eta );
        fesoti_free(&elemso->zeta);

        fesoti_free(&elemso->w   );
        
        // Loop through all derivatives
        for(derId = 0; derId<elemso->nder; derId++){
            
            // free every.
            fearrso_free(&elemso->p_evalBasis[derId]);

        }
    
        // Free pointer       
        free( elemso->p_evalBasis );

        // Reset all values.
        *elemso = elemso_init();

    }
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
elemso_t  elemso_init( void ){

    elemso_t res;

    res.nbasis      = 0;      ///< Number of basis - Number of degrees of freedom - Number of nodes.
    res.order       = 0;      ///< Maximum order of 
    res.geomBase    = 0;      ///< Geometric elemsoent type - elLine, elTriangle, etc ...
    res.kind        = 0;      ///< Kind of elemsoent: Affine - IsoParametric
    res.ndim        = 0;      ///< Number of dimensions of the elemsoent. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    res.nip         = 0;      ///< Number of integration Points
    res.nder        = 0;      ///< Number of total derivatives in the problem.
    res.isInit      = 0;      ///< Initialization flag. byte 0: Started, Byte 1: Allocation.
    res.nDimAnalysis= 0;      ///< Number of dimensions of the analysis.
    res.xi   = fesoti_init(); ///< Gauss scalar with the canonical   xi point coordinates.
    res.eta  = fesoti_init(); ///< Gauss scalar with the canonical  eta point coordinates.
    res.zeta = fesoti_init(); ///< Gauss scalar with the canonical zeta point coordinates.
    res.w    = fesoti_init(); ///< Gauss scalar with the integration weights.
    res.p_evalBasis = NULL;   ///< (10) List of Gauss arrays (nbasis, 1) with the evaluated basis functions.
    
    return res;
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t elemso_start(elemso_t* elemso, uint64_t nbasis, int64_t geomBase,
                       int64_t  kind,   uint8_t  ndim, dhelpl_t dhl){

    int64_t  derIdx;
    uint8_t  nder = 10;


    // Check first if the elemsoent is already allocated.
    if( (elemso->isInit & 1) == 0 ){
   
        elemso->nbasis   = nbasis;
        elemso->nder     = nder;
        elemso->ndim     = ndim;
        elemso->kind     = kind;
        // elemso->f_basis  = basis_f;
        elemso->geomBase = geomBase;

        // Get the integration points and integration weights.
        // This function allocates memory.

        elemso->xi   = fesoti_init();
        elemso->eta  = fesoti_init();
        elemso->zeta = fesoti_init();

        elemso->w    = fesoti_init();
        
        elemso->p_evalBasis = (fearrso_t* ) malloc( elemso->nder * sizeof(fearrso_t  ) ) ;

        if( elemso->p_evalBasis == NULL ){
            printf("--- MemoryError ---\n");
            exit(1);
        }

        // Evaluate all basis functions at integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elemso->nder; derIdx++){

            // Allocate new array
            elemso->p_evalBasis[derIdx] = fearrso_init();

        }        
        
        elemso_raise_flag_start(elemso);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t elemso_end(elemso_t* elemso) {

    int64_t  derIdx;

    // Check first if the elemsoent is already allocated.
    if ( elemso_is_started(elemso) && elemso_is_allocated(elemso) ){
   

        // Get the integration points and integration weights.
        // This function allocates memory.
        fesoti_free(&elemso->xi  ); 
        fesoti_free(&elemso->eta );
        fesoti_free(&elemso->zeta);

        fesoti_free(&elemso->w   );
        
        for(derIdx = 0; derIdx<elemso->nder; derIdx++){

            // Deallocate array
            fearrso_free(&elemso->p_evalBasis[derIdx]);

        }
        
        elemso_clear_flag_alloc(elemso);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t elemso_allocate(elemso_t* elemso, uint64_t intorder, bases_t bases, ord_t order, dhelpl_t dhl){


    int64_t  derIdx;
    // uint64_t basisId;

    // Check first if the elemsoent is already Initialized.
    if( elemso_is_started(elemso) ) {
   
        elemso->order    = intorder;
        
        // Define the Gaussian integration point coordinates and weights.
        fem_intPts_soti( elemso->order, elemso->geomBase, 
            &elemso->xi, &elemso->eta, &elemso->zeta, &elemso->w, dhl);
        
        elemso->nip = elemso->xi.nip;
        
        // Evaluate all basis functions at the integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elemso->nder; derIdx++){

            // Allocate new array
            elemso->p_evalBasis[derIdx] 
                           =   fearrso_zeros_bases( 1, elemso->nbasis, elemso->nip, 0, 0, dhl);

        }
        
        elemso_raise_flag_alloc(elemso);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline uint8_t elemso_is_started( elemso_t* elemso ){

    if (elemso->isInit & 1){
    
        return 1;
    
    }else{
    
        return 0;
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline uint8_t elemso_is_allocated( elemso_t* elemso ){
    
    if (elemso->isInit & 1<<2){
    
        return 1;
    
    }else{
    
        return 0;
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elemso_clear_flag_start(elemso_t* elemso ){
    
    // Lower flag of allocation.
    elemso->isInit = elemso->isInit & ( 255 ^ 1 ); 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elemso_clear_flag_alloc(elemso_t* elemso ){

    // Lower flag of start.
    elemso->isInit = elemso->isInit & ( 255 ^ (1<<2) ); 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elemso_raise_flag_start(elemso_t* elemso ){
    
    elemso->isInit = elemso->isInit | 1 ;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void elemso_raise_flag_alloc(elemso_t* elemso ){

    elemso->isInit = elemso->isInit | 1<<2 ;

}
// ----------------------------------------------------------------------------------------------------









