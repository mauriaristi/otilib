
# ****************************************************************************************************
cpdef tri3_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 3-node triangle 2D element (1st order).

  NODE NUMBERING:

  .. code-block::
  
      > (2)
      >  * *
      >  *   * 
      >  *     *  
      >  *       *
      >  *         *
      > (0)* * * * *(1)

  
  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  
  """ 
  N0 = 1.0 - xi - eta
  N1 = xi
  N2 = eta
  
  return [N0, N1, N2];

# ----------------------------------------------------------------------------------------------------
