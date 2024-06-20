
# ****************************************************************************************************
cpdef quad9_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 9-node quad 2D element (2nd order).

  NODE NUMBERING:
  
  .. code-block::

      > (3)* *(6)* *(2) 
      >  *           *
      >  *           *
      > (7)   (8)   (5)
      >  *           *
      >  *           *
      > (0)* *(4)* *(1)

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """ 

  N0 = 0.25 * ( xi ** 2 - xi ) * ( eta ** 2 - eta )
  N1 = 0.25 * ( xi ** 2 + xi ) * ( eta ** 2 - eta )
  N2 = 0.25 * ( xi ** 2 + xi ) * ( eta ** 2 + eta )
  N3 = 0.25 * ( xi ** 2 - xi ) * ( eta ** 2 + eta )
  N4 = 0.50 * ( 1.0 - xi ** 2) * ( eta ** 2 - eta )
  N5 = 0.50 * ( xi ** 2 + xi ) * ( 1.0 - eta ** 2 )
  N6 = 0.50 * ( 1.0 - xi ** 2) * ( eta ** 2 + eta )
  N7 = 0.50 * ( xi ** 2 - xi ) * ( 1.0 - eta ** 2 )
  N8 = 0.50 * ( 1.0 - xi ** 2) * ( 1.0 - eta ** 2 )

  return [ N0, N1, N2, N3, N4, N5, N6, N7, N8]

# ----------------------------------------------------------------------------------------------------
