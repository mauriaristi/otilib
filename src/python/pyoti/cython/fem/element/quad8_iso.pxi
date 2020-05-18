
# ****************************************************************************************************
cpdef quad8_iso( coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder):
  """
  Definition of basis functions for the serendipity quad (8-node) 2D element.

  NODE NUMBERING:
                         (3)* *(6)* *(2) 
                          *           *
                          *           *
                         (7)         (5)
                          *           *
                          *           *
                         (0)* *(4)* *(1)

  INPUTS:
    -> xi:  Xi  coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> chi: Chi coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

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

  cdef otinum xi  = xi_r  + e( 1, order = derOrder, nbases = 2)
  cdef otinum eta = eta_r + e( 2, order = derOrder, nbases = 2)

  cdef otinum N0 = -0.25*(1.0 - xi)*(1.0 - eta)*(1.0 + xi + eta)
  cdef otinum N1 = -0.25*(1.0 + xi)*(1.0 - eta)*(1.0 - xi + eta)
  cdef otinum N2 = -0.25*(1.0 + xi)*(1.0 + eta)*(1.0 - xi - eta)
  cdef otinum N3 = -0.25*(1.0 - xi)*(1.0 + eta)*(1.0 + xi - eta)
  cdef otinum N4 =  0.50*(1.0 - xi)*(1.0 + xi )*(1.0 - eta)
  cdef otinum N5 =  0.50*(1.0 + xi)*(1.0 + eta)*(1.0 - eta)
  cdef otinum N6 =  0.50*(1.0 - xi)*(1.0 + xi )*(1.0 + eta)
  cdef otinum N7 =  0.50*(1.0 - xi)*(1.0 + eta)*(1.0 - eta)

  return [ N0, N1, N2, N3, N4, N5, N6, N7]

# ----------------------------------------------------------------------------------------------------
