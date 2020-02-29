
# ******************************************************************************************************
cpdef tri1_iso( coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder ):
  """
  Definition of basis functions for the 0 node triangle, element.

  NODE NUMBERING:
                          
                   *                    |           *
                   * *                  |           * *
                   *   *                            *   * 
                   *     *         <-- o r -->      *     *  
                   *  (0)  *                        *       *
                   *         *          |           *         *
                   * * * * * * *        |          (0)* * * * * *
  INPUTS:
    -> xi:  Xi coordinate for this element.
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
   
  return point1_iso(derOrder,coords)

# ------------------------------------------------------------------------------------------------------