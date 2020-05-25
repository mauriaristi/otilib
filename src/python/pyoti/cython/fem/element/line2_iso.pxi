
#*****************************************************************************************************
cpdef line2_iso( coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder):
  """
  Definition of basis functions for the 2 node line 1D element (1st order).
 
  NODE NUMBERING:
  
                          (0)---------(1)

  INPUTS:
    -> xi:  Xi  coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> chi: Chi coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions at the given coordinates.

        Derivatives are returned in the following manner:

        # Real value.
        N       -> real direction -> [0] .
        
        # First order derivatives
        dN/dxi  -> e1 direction -> [1].
        dN/deta -> e2 direction -> [2].
        dN/dchi -> e3 direction -> [3].

        # Second order derivatives:
        d2N/dxi  dxi  -> e11 direction -> [[1,2]].
        d2N/dxi  deta -> e12 direction -> [ 1,2 ].
        d2N/deta deta -> e22 direction -> [[2,2]].
        d2N/dxi  dchi -> e13 direction -> [ 1,3 ].
        d2N/deta dchi -> e23 direction -> [ 2,3 ].
        d2N/dchi dchi -> e33 direction -> [[3,2]].

        # etc...

  """

  cdef otinum xi = xi_r + e( 1, order = derOrder)
  
  cdef otinum N0 = 0.5 * (1.0 - xi)
  cdef otinum N1 = 0.5 * (1.0 + xi)
  
  return [ N0, N1 ]

#-----------------------------------------------------------------------------------------------------
