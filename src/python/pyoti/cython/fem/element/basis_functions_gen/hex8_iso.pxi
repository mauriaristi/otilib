
# ****************************************************************************************************
cpdef hex8_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 8-node brick 3D element (1st order). 
  Basis functions taken from Smith, I. "Programming the Finite Element Method" 5th ed. Wiley.

  NODE NUMBERING:                                                
                              zeta ^          4 y    
                                  |         / eta    
                                  |        /      
                                  |       /
                                  |      /       
                                  |     /        
                              (7)*|* * * (6)
                             * |  |      **
                            *     x     * *
                           *   |       *  *     
                         (4)* * * * *(5)  *      xi
                          *    |      * x-------->   
                          *   (3) - - * -(2)  
                          *   /       *  *
                          *  /        * *
                          * /         **    
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

  N0 =  0.125 * ( 1.0 - xi ) * ( 1.0 - eta ) * ( 1.0 - zeta ) # 1 -> (-1,-1,-1)
  N1 =  0.125 * ( 1.0 + xi ) * ( 1.0 - eta ) * ( 1.0 - zeta ) # 1 -> ( 1,-1,-1)
  N2 =  0.125 * ( 1.0 + xi ) * ( 1.0 + eta ) * ( 1.0 - zeta ) # 1 -> ( 1, 1,-1)
  N3 =  0.125 * ( 1.0 - xi ) * ( 1.0 + eta ) * ( 1.0 - zeta ) # 1 -> (-1, 1,-1)
  N4 =  0.125 * ( 1.0 - xi ) * ( 1.0 - eta ) * ( 1.0 + zeta ) # 1 -> (-1,-1, 1)
  N5 =  0.125 * ( 1.0 + xi ) * ( 1.0 - eta ) * ( 1.0 + zeta ) # 1 -> ( 1,-1, 1)
  N6 =  0.125 * ( 1.0 + xi ) * ( 1.0 + eta ) * ( 1.0 + zeta ) # 1 -> ( 1, 1, 1)
  N7 =  0.125 * ( 1.0 - xi ) * ( 1.0 + eta ) * ( 1.0 + zeta ) # 1 -> (-1, 1, 1)

  return [ N0, N1, N2, N3, N4, N5, N6, N7 ]
   
# ----------------------------------------------------------------------------------------------------
