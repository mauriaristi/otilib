
# ****************************************************************************************************
cpdef hex20_iso( coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder):
  """
  Definition of basis functions for the 20-node brick 3D element (2nd order). 
  Basis functions taken from Smith, I. "Programming the Finite Element Method" 5th ed. Wiley.
  
  NODE NUMBERING:   Node numbering corresponds to GMSH 4 numbering scheme.                                       

                                                4
                                               /
                             ^ chi            /  eta
                             |               /
                             |              /
                             |             /                    
                             |            /
                             |           /
                   (7)* * * *|* (19)* * * * * *(6) 
                   *         |                 **
                  * |        |        /       * *
                 *           |               *  *
                *   |        |      /       *   *
              (17)           x           (18)   *
              *     |             /       *     *
             *     (15)          x       *     (14)
            *       |                   *       *
           *                           *        *
          *         |                 *         *
        (4)* * * * * (16)* * * * * *(5)         *
         *          |                *      x -------------> xi    
         *                           *          *
         *          |                *          *
         *         (3)----------(13)-*---------(2)
         *         /                 *        *
         *        /                  *       *
        (10)     /                  (12)    *
         *      /                    *     *
         *    (9)                    *   (11)
         *    /                      *   *
         *   /                       *  *
         *  /                        * *
         * /                         **   
        (0)* * * * * *(8)* * * * * *(1) 

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
  
  cdef sotinum xi  = xi_r  + e( 1, order = derOrder, nbases = 3)
  cdef sotinum eta = eta_r + e( 2, order = derOrder, nbases = 3)
  cdef sotinum chi = chi_r + e( 3, order = derOrder, nbases = 3)

  # Vertex nodes.
  cdef sotinum N0 = 0.125 * ( 1.0 - xi ) * ( 1.0 - eta ) * ( 1.0 - chi ) * (-xi - eta - chi - 2.0 ) #(-1,-1,-1)
  cdef sotinum N1 = 0.125 * ( 1.0 + xi ) * ( 1.0 - eta ) * ( 1.0 - chi ) * ( xi - eta - chi - 2.0 ) #( 1,-1,-1)
  cdef sotinum N2 = 0.125 * ( 1.0 + xi ) * ( 1.0 + eta ) * ( 1.0 - chi ) * ( xi + eta - chi - 2.0 ) #( 1, 1,-1)
  cdef sotinum N3 = 0.125 * ( 1.0 - xi ) * ( 1.0 + eta ) * ( 1.0 - chi ) * (-xi + eta - chi - 2.0 ) #(-1, 1,-1)
  cdef sotinum N4 = 0.125 * ( 1.0 - xi ) * ( 1.0 - eta ) * ( 1.0 + chi ) * (-xi - eta + chi - 2.0 ) #(-1, 1, 1)
  cdef sotinum N5 = 0.125 * ( 1.0 + xi ) * ( 1.0 - eta ) * ( 1.0 + chi ) * ( xi - eta + chi - 2.0 ) #( 1,-1, 1)
  cdef sotinum N6 = 0.125 * ( 1.0 + xi ) * ( 1.0 + eta ) * ( 1.0 + chi ) * ( xi + eta + chi - 2.0 ) #( 1, 1, 1)
  cdef sotinum N7 = 0.125 * ( 1.0 - xi ) * ( 1.0 + eta ) * ( 1.0 + chi ) * (-xi + eta + chi - 2.0 ) #(-1, 1, 1)

  # Edge nodes
  cdef sotinum N8 = 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 - eta      ) * ( 1.0 - chi      )
  cdef sotinum N9 = 0.250 * ( 1.0 - xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 - chi      )
  cdef sotinum N10= 0.250 * ( 1.0 - xi      ) * ( 1.0 - eta      ) * ( 1.0 - chi ** 2 )
  cdef sotinum N11= 0.250 * ( 1.0 + xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 - chi      )
  cdef sotinum N12= 0.250 * ( 1.0 + xi      ) * ( 1.0 - eta      ) * ( 1.0 - chi ** 2 )
  cdef sotinum N13= 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 + eta      ) * ( 1.0 - chi      )
  cdef sotinum N14= 0.250 * ( 1.0 + xi      ) * ( 1.0 + eta      ) * ( 1.0 - chi ** 2 )
  cdef sotinum N15= 0.250 * ( 1.0 - xi      ) * ( 1.0 + eta      ) * ( 1.0 - chi ** 2 )
  cdef sotinum N16= 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 - eta      ) * ( 1.0 + chi      )
  cdef sotinum N17= 0.250 * ( 1.0 - xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 + chi      )
  cdef sotinum N18= 0.250 * ( 1.0 + xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 + chi      )
  cdef sotinum N19= 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 + eta      ) * ( 1.0 + chi      )

  return [ N0, N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, N12, N13, N14, N15, N16, N17, N18, N19 ]
   
# ----------------------------------------------------------------------------------------------------
