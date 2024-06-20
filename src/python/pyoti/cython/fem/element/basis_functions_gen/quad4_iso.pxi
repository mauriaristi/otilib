
# ****************************************************************************************************
cpdef quad4_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 4-node quad 2D element (1st order).This element works for both 
  the first order quad and first order serendipity quad element.

  NODE NUMBERING:

  .. code-block::

      >        ^ eta 
      >        |
      >        |
      > (3)* * * * *(2) 
      >  *           *
      >  *           *        xi
      >  *           * ------->
      >  *           *
      >  *           * 
      > (0)* * * * *(1)

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """
  N0 = 0.25*(1.0 - xi)*(1.0 - eta)
  N1 = 0.25*(1.0 + xi)*(1.0 - eta)
  N2 = 0.25*(1.0 + xi)*(1.0 + eta)
  N3 = 0.25*(1.0 - xi)*(1.0 + eta)

  return [ N0, N1, N2, N3 ]
   
# ----------------------------------------------------------------------------------------------------
