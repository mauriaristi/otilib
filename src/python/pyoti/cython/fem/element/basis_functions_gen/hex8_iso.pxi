
# ****************************************************************************************************
cpdef hex8_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 8-node brick 3D element (1st order). 
  Basis functions taken from Smith, I. "Programming the Finite Element Method" 5th ed. Wiley.

  NODE NUMBERING:     

  .. code-block::

      >     zeta ^          4     
      >          |         / eta    
      >          |        /      
      >          |       /
      >          |      /       
      >          |     /        
      >      (7)*|* * * (6)
      >     * |  |      **
      >    *     x     * *
      >   *   |       *  *     
      > (4)* * * * *(5)  *      xi
      >  *    |      * x-------->   
      >  *   (3) - - * -(2)  
      >  *   /       *  *
      >  *  /        * *
      >  * /         **    
      > (0)* * * * *(1) 

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: Evaluated basis functions.

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
