
# ****************************************************************************************************
cpdef tri4_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 4-node triangle 2D element (bubble triangle).

  NODE NUMBERING:
                          (2)
                           * *
                           *   * 
                           *     *  
                           *  (3)  *
                           *         *
                          (0)* * * * *(1)

  INPUTS:
    -> xi:  Xi  coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> zeta: zeta coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

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

  N0 = 1.0 -  xi - eta
  N1 = xi
  N2 = eta
  N3 = ( 1.0 - xi ** 2 )*( 1.0 - eta ** 2 )
  
  return [N0, N1, N2, N3];
 
# ----------------------------------------------------------------------------------------------------
