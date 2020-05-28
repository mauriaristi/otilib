
# ****************************************************************************************************
cpdef tet10_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 4-node tetrahedron 3D element (2nd order).
  
  NODE NUMBERING:

               ^ eta
               |                         4
               |                        / zeta
               |                       /
               |                      /
               |                     /
               |                    /
               |                   /
               |                  /
              (2)******(9)******(3)
               * *              / *                  
               *   *               *                 
               *     *        /     *                
               *       *             *               
               *         *  /         *              
               *           *           *             
               *          /  *          *            
               *               *         *           
              (6)      (7)      (5)      (8)         
               *                   *       *         
               *      /              *      *        
               *                       *     *       
               *    /                    *    *      
               *                           *   *     
               *  /                          *  *    
               *                               * *   
               */                                **  
              (0)* * * * * * *(4)* * * * * * * * *(1)------> xi

  INPUTS:
    -> xi:  Xi  coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> zeta: zeta coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

        Derivatives are returned in the following manner:

        # Real value.
        N       -> real direction -> [0].
        
        xi  -> xi_r  + e1
        eta -> eta_r + e2
        zeta -> zeta_r + e3

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