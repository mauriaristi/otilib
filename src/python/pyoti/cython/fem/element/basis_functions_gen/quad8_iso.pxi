
# ****************************************************************************************************
cpdef quad8_iso( xi, eta, zeta):
  """
  Definition of basis functions for the serendipity quad (8-node) 2D element.

  NODE NUMBERING:

  .. code-block::

      >  (3)* *(6)* *(2) 
      >   *           *
      >   *           *
      >  (7)         (5)
      >   *           *
      >   *           *
      >  (0)* *(4)* *(1)

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.
  """ 

  N0 = -0.25*(1.0 - xi)*(1.0 - eta)*(1.0 + xi + eta)
  N1 = -0.25*(1.0 + xi)*(1.0 - eta)*(1.0 - xi + eta)
  N2 = -0.25*(1.0 + xi)*(1.0 + eta)*(1.0 - xi - eta)
  N3 = -0.25*(1.0 - xi)*(1.0 + eta)*(1.0 + xi - eta)
  N4 =  0.50*(1.0 - xi)*(1.0 + xi )*(1.0 - eta)
  N5 =  0.50*(1.0 + xi)*(1.0 + eta)*(1.0 - eta)
  N6 =  0.50*(1.0 - xi)*(1.0 + xi )*(1.0 + eta)
  N7 =  0.50*(1.0 - xi)*(1.0 + eta)*(1.0 - eta)

  return [ N0, N1, N2, N3, N4, N5, N6, N7]

# ----------------------------------------------------------------------------------------------------
