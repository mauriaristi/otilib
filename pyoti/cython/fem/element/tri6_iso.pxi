
# ****************************************************************************************************
cpdef tri6_iso(ord_t derOrder, np.ndarray coords):
  """
  Definition of basis functions for the 6-node triangle 2D element.
  
  NODE NUMBERING:
                          (2)
                           * *
                           *   * 
                          (5)   (4) 
                           *       *
                           *         *
                          (0)* *(3)* *(1)

  INPUTS:
    -> derOrder: Order of derivative sought for basis functions.
    -> coords:   Array with the coordinates to evaluate the basis functions.
    -> kwargs:   Dictionary with other data required to be evaluated.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

  """ 

  cdef bases_t nbases  = 2
  # cdef np.ndarray coords_omat = omat(coords, order= derOrder, nbases= nbases)
  
  cdef np.ndarray  xi = coords[:,0] + se(1, order= derOrder)
  cdef np.ndarray eta = coords[:,1] + se(2, order= derOrder)

  N0 = 2*eta**2+ 4*eta* xi - 3*eta + 2* xi**2 - 3* xi + 1.0
  N1 = 2* xi**2- xi
  N2 = 2*eta**2-eta
  N3 = 4*(  xi -  xi**2 - eta*xi)
  N4 = 4*eta*xi 
  N5 = 4*( eta - eta**2 - eta*xi)

  return [N0, N1, N2, N3, N4, N5]   
# ----------------------------------------------------------------------------------------------------