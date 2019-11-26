
# ****************************************************************************************************
cpdef quad4_iso( ord_t derOrder, np.ndarray coords):
  """
  Definition of basis functions for the 4-node quad 2D element.

  NODE NUMBERING:
                          ^ 
                          | eta
                          |
                         (3)* * * * *(2) 
                          *           *
                          *           *
                          *           *
                          *           *
                          *           *    xi
                         (0)* * * * *(1) ----->

  INPUTS:
    -> derOrder: Order of derivative sought for basis functions.
    -> coords:   Array with the coordinates to evaluate the basis functions.
    -> kwargs:   Dictionary with other data required to be evaluated.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

  """
  
  cdef np.ndarray coords_obj = coords.astype(object)
  cdef np.ndarray xi  = coords_obj[:,0] + se( 1, order= derOrder)
  cdef np.ndarray eta = coords_obj[:,1] + se( 2, order= derOrder)

  N0 =  0.25*(1 - xi)*(1 - eta)
  N1 =  0.25*(1 + xi)*(1 - eta)
  N2 =  0.25*(1 + xi)*(1 + eta)
  N3 =  0.25*(1 - xi)*(1 + eta)

  return [N0,N1,N2,N3]
   
# ----------------------------------------------------------------------------------------------------
