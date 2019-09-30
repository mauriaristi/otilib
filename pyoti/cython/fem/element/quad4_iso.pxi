# ****************************************************************************************************
int64_t fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,  ...
                                              void* other_data, darr_t* evalBasis)
    """
    fem_basisFunctions_N_QuadP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:

                           (3)* * * * *(2) 
                            *           *
                            *           *
                            *           *
                            *           *
                            *           *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

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

    """
    # ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i=0.0;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 3 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        xi  = darr_get_item_ij(coords,i,0);
        eta = darr_get_item_ij(coords,i,1);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0-xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0-xi); 

            }else if (basisDer == derNab){ 

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        darr_set_item_ij( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------
