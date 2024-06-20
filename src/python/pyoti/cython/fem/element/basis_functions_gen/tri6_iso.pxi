
# ****************************************************************************************************
cpdef tri6_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 6-node triangle 2D element (2nd order).
  
  NODE NUMBERING:

  .. code-block::
  
      > (2)
      >  * *
      >  *   * 
      > (5)   (4) 
      >  *       *
      >  *         *
      > (0)* *(3)* *(1)

  
  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """ 

  N0 = 2.0 * eta ** 2 +  4.0 * eta * xi - 3.0 * eta + 2.0 * xi ** 2 - 3.0 * xi + 1.0
  N1 = 2.0 *  xi ** 2 - xi
  N2 = 2.0 * eta ** 2 - eta
  N3 = 4.0 * (  xi  -   xi ** 2 - eta * xi)
  N4 = 4.0 * eta * xi   
  N5 = 4.0 * ( eta  -  eta**2 - eta * xi)

  return [N0, N1, N2, N3, N4, N5]   
# ----------------------------------------------------------------------------------------------------