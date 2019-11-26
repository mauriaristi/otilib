
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
  cdef omat coords_omat = omat(coords, order= derOrder, nbases= nbases)
  
  cdef omat  xi = coords_omat[:,0] + e(1, order= derOrder, nbases= nbases)
  cdef omat eta = coords_omat[:,1] + e(2, order= derOrder, nbases= nbases)

  N0 = 2*eta**2+ 4*eta* xi - 3*eta + 2* xi**2 - 3* xi + 1.0
  N1 = 2* xi**2- xi
  N2 = 2*eta**2-eta
  N3 = 4*(  xi -  xi**2 - eta*xi)
  N4 = 4*eta*xi 
  N5 = 4*( eta - eta**2 - eta*xi)

  return [N0, N1, N2, N3, N4, N5]   
# ----------------------------------------------------------------------------------------------------