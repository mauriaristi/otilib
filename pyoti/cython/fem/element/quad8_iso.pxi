

// ****************************************************************************************************
int64_t fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_QuadSerendP2_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the serendipity 2D element.


    NODE NUMBERING:

                           (3)* *(6)* *(2) 
                            *           *
                            *           *
                           (7)         (5)
                            *           *
                            *           *
                           (0)* *(4)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, ..., 8. (N1, ..., N8)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN    , derNa  , derNaa
                        derNb   , derNab , derNbb
                        derNc   , derNac , 
                        derNbc  , derNcc ,  
                        

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     (ncoords x ndim) array with the  data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    SOURCE:
        
        -> http://www.pckingsford.com/cykchee/phd/chD.pdf

    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i=0.0;

    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 7 ){
        printf("--- InvalidBaseId ---");
        exit(1);
        // return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        xi  = darr_get_item_ij(coords,i,0);
        eta = darr_get_item_ij(coords,i,1);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0-eta)*(1.+xi+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(-1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1-2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0-eta)*(1.-xi+eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(-1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1-2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0+eta)*(1.-xi-eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1+2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0+eta)*(1.+xi-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1+2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  else if (basisId == 4){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = xi*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = (eta - 1.); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i = xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 5){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0+xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -eta*(1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = -(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 6){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-xi*(1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = -(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i =-xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 7){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  eta*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = (xi-1.); 

            }else if (basisDer == derNab){

                evalBasis_i = eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }

        darr_set_item_ij( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------
