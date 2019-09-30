



#

cdef omat LineP1_basis_1Diso(uint8_t derOrder, dmat coords, other_data = None, dmat out = None ):
  """
   Definition of basis functions for the Line P1 1D element.


   NODE NUMBERING:


                          (0)* * * * *(1)

                          

   INPUTS:

       -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


       -> derOrder:   Maximum order of derivative to be computed.
       
       -> coords:     Pointer with the data in the transformed space:
                      [ [    xi_1   ],
                        [    xi_2   ],
                            ... 
                        [ xi_ncoord,] ]

       -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)

       -> other_data: Data that might be available for other computations.
   
   OUTPUTS: 

       -> evalBasis: Pointer with the result.
  """

  cdef omat coords_omat = omat(coords, order = derOrder, nbases = 1);
  
  # Perturb to get the corresponding derivaitve.
  xi = coords_omat + e( 1, order = derOrder )                    

  # Basis 0: 0.5*(1.0-xi)
  N0 = 0.5*(1.0-xi)

  # Basis 1: 0.5*(1.0+xi)
  N1 = 0.5*(1.0+xi)

  return [N0,N1];

#







