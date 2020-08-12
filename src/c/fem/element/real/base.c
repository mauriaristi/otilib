
// Memory management.
// ****************************************************************************************************
int64_t elemd_free( elemd_t* elemd ) {

    int64_t derId;


    if (elemd->isInit != 0){
    
        // Free the integration point and integration weight arrays.
       
        fednum_free(&elemd->xi  ); 
        fednum_free(&elemd->eta );
        fednum_free(&elemd->zeta);

        fednum_free(&elemd->w   );
        
        // Loop through all derivatives
        for(derId = 0; derId<elemd->nder; derId++){
            
            // free every.
            fedarr_free(&elemd->p_evalBasis[derId]);

        }
    
        // Free pointer       
        free( elemd->p_evalBasis );

        // Reset all values.
        *elemd = elemd_init();

    }
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
elemd_t  elemd_init( void ){

    elemd_t res;

    res.nbasis      = 0;      ///< Number of basis - Number of degrees of freedom - Number of nodes.
    res.order       = 0;      ///< Maximum order of 
    res.geomBase    = 0;      ///< Geometric elemdent type - elLine, elTriangle, etc ...
    res.kind        = 0;      ///< Kind of elemdent: Affine - IsoParametric
    res.ndim        = 0;      ///< Number of dimensions of the elemdent. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    res.nip         = 0;      ///< Number of integration Points
    res.nder        = 0;      ///< Number of total derivatives in the problem.
    res.isInit      = 0;      ///< Initialization flag. byte 0: Started, Byte 1: Allocation.
    res.nDimAnalysis= 0;      ///< Number of dimensions of the analysis.
    res.xi   = fednum_init(); ///< Gauss scalar with the canonical   xi point coordinates.
    res.eta  = fednum_init(); ///< Gauss scalar with the canonical  eta point coordinates.
    res.zeta = fednum_init(); ///< Gauss scalar with the canonical zeta point coordinates.
    res.w    = fednum_init(); ///< Gauss scalar with the integration weights.
    res.p_evalBasis = NULL;   ///< (10) List of Gauss arrays (nbasis, 1) with the evaluated basis functions.
    
    return res;
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t elemd_start(elemd_t* elemd, uint64_t nbasis, int64_t geomBase,
                       int64_t  kind,   uint8_t  ndim){

    int64_t  derIdx;
    uint8_t  nder = 10;


    // Check first if the elemdent is already allocated.
    if( (elemd->isInit & 1) == 0 ){
   
        elemd->nbasis   = nbasis;
        elemd->nder     = nder;
        elemd->ndim     = ndim;
        elemd->kind     = kind;
        // elemd->f_basis  = basis_f;
        elemd->geomBase = geomBase;

        // Get the integration points and integration weights.
        // This function allocates memory.

        elemd->xi   = fednum_init();
        elemd->eta  = fednum_init();
        elemd->zeta = fednum_init();

        elemd->w    = fednum_init();
        
        elemd->p_evalBasis = (fedarr_t* ) malloc( elemd->nder * sizeof(fedarr_t  ) ) ;

        if( elemd->p_evalBasis == NULL ){
            printf("--- MemoryError ---\n");
            exit(1);
        }

        // Evaluate all basis functions at integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elemd->nder; derIdx++){

            // Allocate new array
            elemd->p_evalBasis[derIdx] = fedarr_init();

        }        
        
        elemd_raise_flag_start(elemd);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t elemd_end(elemd_t* elemd) {

    int64_t  derIdx;

    // Check first if the elemdent is already allocated.
    if ( elemd_is_started(elemd) && elemd_is_allocated(elemd) ){
   

        // Get the integration points and integration weights.
        // This function allocates memory.
        fednum_free(&elemd->xi  ); 
        fednum_free(&elemd->eta );
        fednum_free(&elemd->zeta);

        fednum_free(&elemd->w   );
        
        for(derIdx = 0; derIdx<elemd->nder; derIdx++){

            // Deallocate array
            fedarr_free(&elemd->p_evalBasis[derIdx]);

        }
        
        elemd_clear_flag_alloc(elemd);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t elemd_allocate(elemd_t* elemd, uint64_t intorder){


    int64_t  derIdx;
    // uint64_t basisId;

    // Check first if the elemdent is already Initialized.
    if( elemd_is_started(elemd) ) {
   
        elemd->order    = intorder;
        
        // Define the Gaussian integration point coordinates and weights.
        fem_intPts_real( elemd->order, elemd->geomBase, 
            &elemd->xi, &elemd->eta, &elemd->zeta, &elemd->w );
        
        elemd->nip = elemd->xi.nip;
        
        // Evaluate all basis functions at the integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elemd->nder; derIdx++){

            // Allocate new array
            elemd->p_evalBasis[derIdx] = fedarr_zeros( 1, elemd->nbasis, elemd->nip);

        }
        
        elemd_raise_flag_alloc(elemd);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline uint8_t elemd_is_started( elemd_t* elemd ){

    if (elemd->isInit & 1){
    
        return 1;
    
    }else{
    
        return 0;
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline uint8_t elemd_is_allocated( elemd_t* elemd ){
    
    if (elemd->isInit & 1<<2){
    
        return 1;
    
    }else{
    
        return 0;
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elemd_clear_flag_start(elemd_t* elemd ){
    
    // Lower flag of allocation.
    elemd->isInit = elemd->isInit & ( 255 ^ 1 ); 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elemd_clear_flag_alloc(elemd_t* elemd ){

    // Lower flag of start.
    elemd->isInit = elemd->isInit & ( 255 ^ (1<<2) ); 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void elemd_raise_flag_start(elemd_t* elemd ){
    
    elemd->isInit = elemd->isInit | 1 ;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void elemd_raise_flag_alloc(elemd_t* elemd ){

    elemd->isInit = elemd->isInit | 1<<2 ;

}
// ----------------------------------------------------------------------------------------------------









