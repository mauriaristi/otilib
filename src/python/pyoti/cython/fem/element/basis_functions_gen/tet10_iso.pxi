
# ****************************************************************************************************
cpdef tet10_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 4-node tetrahedron 3D element (2nd order).
  
  NODE NUMBERING:

  .. code-block::

      >  ^ eta
      >  |                         4
      >  |                        / zeta
      >  |                       /
      >  |                      /
      >  |                     /
      >  |                    /
      >  |                   /
      >  |                  /
      > (2)******(9)******(3)
      >  * *              / *                  
      >  *   *               *                 
      >  *     *        /     *                
      >  *       *             *               
      >  *         *  /         *              
      >  *           *           *             
      >  *          /  *          *            
      >  *               *         *           
      > (6)      (7)      (5)      (8)         
      >  *                   *       *         
      >  *      /              *      *        
      >  *                       *     *       
      >  *    /                    *    *      
      >  *                           *   *     
      >  *  /                          *  *    
      >  *                               * *   
      >  */                                **  
      > (0)* * * * * * *(4)* * * * * * * * *(1)------> xi

  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """ 

  L0 = 1.0 - xi - eta - zeta # 
  L1 = xi                   # 
  L2 = eta                  # 
  L3 = zeta                  # 

  N0 = 2.0 * L0 * L0 - L0   #
  N1 = 2.0 * L1 * L1 - L1   #
  N2 = 2.0 * L2 * L2 - L2   #
  N3 = 2.0 * L3 * L3 - L3   #

  N4 = 4.0 * L0 * L1        #
  N5 = 4.0 * L1 * L2        #
  N6 = 4.0 * L0 * L2        #
  N7 = 4.0 * L0 * L3        #
  N8 = 4.0 * L1 * L3        #
  N9 = 4.0 * L2 * L3        #
  
  return [N0, N1, N2, N3, N4, N5, N6, N7, N8, N9]
# ----------------------------------------------------------------------------------------------------