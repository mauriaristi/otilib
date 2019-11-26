
# ****************************************************************************************************
cpdef tri4_iso(ord_t derOrder, np.ndarray coords):
  """
  Definition of basis functions for the 4-node triangle (bubble) 2D element.

  NODE NUMBERING:
                         (2)
                          * *
                          *   * 
                          *     *  
                          *  (3)  *
                          *         *
                         (0)* * * * *(1)

  INPUTS:
    -> derOrder: Order of derivative sought for basis functions.
    -> coords:   Array (#N,Dim) with the coordinates to evaluate the basis functions.
    -> kwargs:   Dictionary with other data required to be evaluated.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

  """ 
  
  cdef np.ndarray coords_obj = coords.astype(object)
  cdef np.ndarray  xi = coords_obj[:,0] + se( 1, order= derOrder)
  cdef np.ndarray eta = coords_obj[:,1] + se( 2, order= derOrder)

  N0 = 1 -  xi - eta
  N1 =  xi
  N2 = eta
  N3 = ( 1 - xi**2 )*( 1 - eta**2 )
  
  return [N0, N1, N2, N3];
 
# ----------------------------------------------------------------------------------------------------
