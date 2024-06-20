
# ****************************************************************************************************
cpdef hex20_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 20-node brick 3D element (2nd order). 
  Basis functions taken from Smith, I. "Programming the Finite Element Method" 5th ed. Wiley.
  
  NODE NUMBERING:   Node numbering corresponds to GMSH 4 numbering scheme.         

  .. code-block::

      >                                         4
      >                                         /
      >                       ^ zeta           /  eta
      >                       |               /
      >                       |              /
      >                       |             /                    
      >                       |            /
      >                       |           /
      >             (7)* * * *|* (19)* * * * * *(6) 
      >             *         |                 **
      >            * |        |        /       * *
      >           *           |               *  *
      >          *   |        |      /       *   *
      >        (17)           x           (18)   *
      >        *     |             /       *     *
      >       *     (15)          x       *     (14)
      >      *       |                   *       *
      >     *                           *        *
      >    *         |                 *         *
      >  (4)* * * * * (16)* * * * * *(5)         *
      >   *          |                *      x -------------> xi    
      >   *                           *          *
      >   *          |                *          *
      >   *         (3)----------(13)-*---------(2)
      >   *         /                 *        *
      >   *        /                  *       *
      >  (10)     /                  (12)    *
      >   *      /                    *     *
      >   *    (9)                    *   (11)
      >   *    /                      *   *
      >   *   /                       *  *
      >   *  /                        * *
      >   * /                         **   
      >  (0)* * * * * *(8)* * * * * *(1) 

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: Evaluated basis functions.

  """

  # Vertex nodes.
  N0 = 0.125 * ( 1.0 - xi ) * ( 1.0 - eta ) * ( 1.0 - zeta ) * (-xi - eta - zeta - 2.0 ) #(-1,-1,-1)
  N1 = 0.125 * ( 1.0 + xi ) * ( 1.0 - eta ) * ( 1.0 - zeta ) * ( xi - eta - zeta - 2.0 ) #( 1,-1,-1)
  N2 = 0.125 * ( 1.0 + xi ) * ( 1.0 + eta ) * ( 1.0 - zeta ) * ( xi + eta - zeta - 2.0 ) #( 1, 1,-1)
  N3 = 0.125 * ( 1.0 - xi ) * ( 1.0 + eta ) * ( 1.0 - zeta ) * (-xi + eta - zeta - 2.0 ) #(-1, 1,-1)
  N4 = 0.125 * ( 1.0 - xi ) * ( 1.0 - eta ) * ( 1.0 + zeta ) * (-xi - eta + zeta - 2.0 ) #(-1, 1, 1)
  N5 = 0.125 * ( 1.0 + xi ) * ( 1.0 - eta ) * ( 1.0 + zeta ) * ( xi - eta + zeta - 2.0 ) #( 1,-1, 1)
  N6 = 0.125 * ( 1.0 + xi ) * ( 1.0 + eta ) * ( 1.0 + zeta ) * ( xi + eta + zeta - 2.0 ) #( 1, 1, 1)
  N7 = 0.125 * ( 1.0 - xi ) * ( 1.0 + eta ) * ( 1.0 + zeta ) * (-xi + eta + zeta - 2.0 ) #(-1, 1, 1)

  # Edge nodes
  N8 = 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 - eta      ) * ( 1.0 - zeta      )
  N9 = 0.250 * ( 1.0 - xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 - zeta      )
  N10= 0.250 * ( 1.0 - xi      ) * ( 1.0 - eta      ) * ( 1.0 - zeta ** 2 )
  N11= 0.250 * ( 1.0 + xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 - zeta      )
  N12= 0.250 * ( 1.0 + xi      ) * ( 1.0 - eta      ) * ( 1.0 - zeta ** 2 )
  N13= 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 + eta      ) * ( 1.0 - zeta      )
  N14= 0.250 * ( 1.0 + xi      ) * ( 1.0 + eta      ) * ( 1.0 - zeta ** 2 )
  N15= 0.250 * ( 1.0 - xi      ) * ( 1.0 + eta      ) * ( 1.0 - zeta ** 2 )
  N16= 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 - eta      ) * ( 1.0 + zeta      )
  N17= 0.250 * ( 1.0 - xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 + zeta      )
  N18= 0.250 * ( 1.0 + xi      ) * ( 1.0 - eta ** 2 ) * ( 1.0 + zeta      )
  N19= 0.250 * ( 1.0 - xi ** 2 ) * ( 1.0 + eta      ) * ( 1.0 + zeta      )

  return [ N0, N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, N12, N13, N14, N15, N16, N17, N18, N19 ]
   
# ----------------------------------------------------------------------------------------------------
