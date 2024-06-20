
#*****************************************************************************************************
cpdef line2_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 2 node line 1D element (1st order).
 
  NODE NUMBERING:

  .. code-block::

      > (0)---------(1)

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: Evaluated basis functions at the given coordinates.

        Derivatives are returned in the following manner:

        # Real value.
        N       -> real direction -> [0] .
        
        # First order derivatives
        dN/dxi  -> e1 direction -> [1].
        dN/deta -> e2 direction -> [2].
        dN/dzeta -> e3 direction -> [3].

        # Second order derivatives:
        d2N/dxi  dxi  -> e11 direction -> [[1,2]].
        d2N/dxi  deta -> e12 direction -> [ 1,2 ].
        d2N/deta deta -> e22 direction -> [[2,2]].
        d2N/dxi  dzeta -> e13 direction -> [ 1,3 ].
        d2N/deta dzeta -> e23 direction -> [ 2,3 ].
        d2N/dzeta dzeta -> e33 direction -> [[3,2]].

        # etc...

  """
  
  N0 = 0.5 * (1.0 - xi)
  N1 = 0.5 * (1.0 + xi)
  
  return [ N0, N1 ]

#-----------------------------------------------------------------------------------------------------
