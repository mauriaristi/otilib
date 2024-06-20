
# ****************************************************************************************************
cpdef tet4_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 4-node tetrahedron 3D element (1st order).
  
  NODE NUMBERING:

  .. code-block::
  
      >  ^ eta
      >  |         4
      >  |        / zeta
      >  |       /
      >  |      /
      > (2)* * (3)
      >  * *  /  *
      >  *   *    *
      >  *  /  *   *
      >  *       *  *
      >  */        * *
      > (0)* * * * *(1)------> xi

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """ 

  N0 = 1.0 - xi - eta - zeta
  N1 = xi 
  N2 = eta
  N3 = zeta
  
  return [N0, N1, N2, N3]
# ----------------------------------------------------------------------------------------------------