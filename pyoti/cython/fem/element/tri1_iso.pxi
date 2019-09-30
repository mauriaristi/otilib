
// ****************************************************************************************************
int64_t fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    NODE NUMBERING:
                            
                     *                    |           *
                     * *                  |           * *
                     *   *                            *   * 
                     *     *         <-- o r -->      *     *  
                     *  (0)  *                        *       *
                     *         *          |           *         *
                     * * * * * * *        |          (0)* * * * * *

    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0. (N1)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab     

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double  evalBasis_i=0.0;
    
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 1 ){
        return OTI_FEM_InvalidBaseId;
    }

    
    for(i=0; i<ncoords; i++){
                    
        // Detect which derivative is being computed
        if (basisDer == derN){

            evalBasis_i = 1.0; // N1 = xi

        } else{

            evalBasis_i = 0.0; // everything else (if asked).

        }

        darr_set_item_ij( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------