





































// Memory management.


// ****************************************************************************************************
int64_t elem_free( elem_t* elem ) {
    /*
    
    Free the elem object.

    */ 
    // ************************************************************************************************

    int64_t derId;

    // typedef struct elem_s{    
    //     // FEM Properties
    //     uint64_t          nbasis; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    //     uint64_t           order; ///< Maximum order of the Element.
    //     int64_t         geomBase; ///< Geometric element type - elLine, elTriangle, etc ...
    //     int64_t             kind; ///< Kind of element: Affine - IsoParametric
    //     uint8_t             ndim; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    //     uint64_t         nIntPts; ///< Number of integration Points
    //     uint8_t             nder; ///< Number of total derivatives in the problem.
    //     uint8_t           isInit; ///< Initialization flag. 0: Not initialized, 1: Initialized.
    //     uint8_t     nDimAnalysis; ///< Number of dimensions of the analysis.
    //     darr_t            intPts; ///< (nIntPts x ndim) Array with the integration point coordinates.
    //     darr_t            intWts; ///< (nIntPts x 1   ) Array with the integration weights.
    //     darr_t*      p_evalBasis; ///< (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    //     int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*); ///<  Interpolation function.
    //     // 
    // } elem_t;

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





elem_t  elem_init( void ){

    elem_t res;

    // typedef struct elem_s{    
    //     // FEM Properties
    //     uint64_t          nbasis;
    //     uint64_t           order;
    //     int64_t         geomBase;
    //     int64_t             kind;
    //     uint8_t             ndim;
    //     uint64_t         nIntPts;
    //     uint8_t             nder;
    //     uint8_t           isInit;
    //     uint8_t     nDimAnalysis;
    //     darr_t            intPts;
    //     darr_t            intWts;
    //     darr_t*      p_evalBasis;
    //     int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*);
    //     // 
    // } elem_t;

    res.nbasis      = 0; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    res.order       = 0; ///< Maximum order of 
    res.geomBase    = 0; ///< Geometric element type - elLine, elTriangle, etc ...
    res.kind        = 0; ///< Kind of element: Affine - IsoParametric
    res.ndim        = 0; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    res.nIntPts     = 0; ///< Number of integration Points
    res.nder        = 0; ///< Number of total derivatives in the problem.
    res.isInit      = 0; ///< Initialization flag. 0: Not initialized, 1: Initialized.
    res.nDimAnalysis= 0; ///< Number of dimensions of the analysis.
    res.intPts      = darr_init(); ///< (nIntPts x ndim) Array with the integration points coordinates.
    res.intWts      = darr_init(); ///< (nIntPts x 1   ) Array with the integration weights.
    res.p_evalBasis = NULL; ///< (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    res.f_basis     = NULL; ///<  Interpolation function.

    return res;
}
















// ****************************************************************************************************
int64_t elem_allocate(elem_t* elem, uint64_t nbasis, uint64_t order, int64_t geomBase,
                       int64_t  kind,   uint8_t  ndim,
              int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*)
    ) {
    /*
    fem_initElement(uint64_t order, elem_t* elem) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> order:    Order of polynomial.

        -> elem:   Address of the structure that holds the element information.


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************


    // typedef struct elem_s{    
    //     // FEM Properties
    //     uint64_t          nbasis;
    //     uint64_t           order;
    //     int64_t         geomBase;
    //     int64_t             kind;
    //     uint8_t             ndim;
    //     uint64_t         nIntPts;
    //     uint8_t             nder;
    //     uint8_t           isInit;
    //     uint8_t     nDimAnalysis;
    //     darr_t            intPts;
    //     darr_t            intWts;
    //     darr_t*      p_evalBasis;
    //     int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*);
    //     // 
    // } elem_t;

    int64_t  derIdx;
    uint64_t basisId;

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



    // Check first if the element is already allocated.
    if( elem->isInit == 0 ){
   
        
        // elem->nDimAnalysis = nDimAnalysis;
        elem->order    = order;
        elem->nbasis   = nbasis;
        elem->nder     = nder;
        elem->ndim     = ndim;
        elem->kind     = kind;
        elem->f_basis  = basis_f;
        elem->geomBase = geomBase;

        // Get the integration points and integration weights.
        // This function allocates memory.
        fem_integrationPoints(order, elem->geomBase, &elem->intPts, &elem->intWts);
        
        // printf("Here.\n");

        elem->nIntPts = elem->intPts.nrows;
        

        elem->p_evalBasis = (darr_t*  ) malloc( elem->nder*sizeof(darr_t  ) ) ;

        if( elem->p_evalBasis == NULL ){
            printf("--- MemoryError ---\n");
            exit(1);
        }        

        // Evaluate all basis functions at integration points.
        // Loop through all derivatives
        for(derIdx = 0; derIdx<elem->nder; derIdx++){

            // Allocate new array
            elem->p_evalBasis[derIdx] = darr_createEmpty(elem->nbasis, elem->nIntPts);

            // Evaluates all basis functions.
            // Loop through all basis functions.
            for(basisId = 0; basisId<elem->nbasis; basisId++){
                
                elem->f_basis(basisId, derIdx + derN, &elem->intPts, NULL, &elem->p_evalBasis[derIdx]);

            }

        }
        
        elem->isInit = 1; // Raise flag of allocation.

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



