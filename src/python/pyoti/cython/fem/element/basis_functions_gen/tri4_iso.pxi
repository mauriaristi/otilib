
# ****************************************************************************************************
cpdef tri4_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 4-node triangle 2D element (bubble triangle).

  NODE NUMBERING:

  .. code-block::
  
      > (2)
      >  * *
      >  *   * 
      >  *     *  
      >  *  (3)  *
      >  *         *
      > (0)* * * * *(1)

  
  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """ 

  N0 = 1.0 -  xi - eta
  N1 = xi
  N2 = eta
  N3 = ( 1.0 - xi ** 2 )*( 1.0 - eta ** 2 )
  
  return [N0, N1, N2, N3];
 
# ----------------------------------------------------------------------------------------------------
