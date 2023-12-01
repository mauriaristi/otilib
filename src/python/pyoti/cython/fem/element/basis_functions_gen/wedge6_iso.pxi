
# ****************************************************************************************************
cpdef wedge6_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 6-node wedge 3D element (1st order). 
  Basis functions taken from Zienkiewicz, "The Finite Element Method: Its Basis and
  Fundamentals Seventh Edition" 7th ed. Elsevier.
  
  NODE NUMBERING:   Node numbering corresponds to Abaqus numbering scheme.

                                    4 eta                        
                           (5)     /                             
                           * *    /                              
                ^ zeta    * *  * /                               
                |        *  *   *                                
                |       *   *  /  *                              
                |      *    * /    *                             
                |    *      */       *                         
                |   *       *         *                          
                |  *       /*           *                        
                | *       / *             *                      
               (3)* * * * * * * * * * * * *(4)    [zeta +1]      
                *      /    *               *                    
                *     /     *               *                    
                *    /     (2)              *                    
                *   /      * *              *                    
                *  /      *    *            *                    
                * /      *      *           *                    
                * - - - * - - - - *- - - - -* -------------> xi 
                *      *           *        *                    
                *     *              *      *                    
                *    *                *     *                    
                *   *                  *    *                    
                *  *                     *  *                    
                * *                       * *                    
               (0)* * * * * * * * * * * * *(1)    [zeta -1]      

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

  # Vertex nodes.

  # Define the Area coordinates of the triangle
  L1 = 1 - xi - eta
  L2 = xi
  L3 = eta

  # # Define some functions related to the prism side
  N_line_1 = ( 1 - zeta )
  N_line_2 = ( 1 + zeta )
  

  # Vertex nodes.
  N0  = 0.5 * ( L1 * N_line_1 )  # (  0,  0, -1 )
  N1  = 0.5 * ( L2 * N_line_1 )  # (  1,  0, -1 )
  N2  = 0.5 * ( L3 * N_line_1 )  # (  0,  1, -1 )

  N3  = 0.5 * ( L1 * N_line_2 )  # (  0,  0, +1 )
  N4  = 0.5 * ( L2 * N_line_2 )  # (  1,  0, +1 )
  N5  = 0.5 * ( L3 * N_line_2 )  # (  0,  1, +1 )

  
  return [ N0, N1, N2, N3, N4, N5 ]
   
# ----------------------------------------------------------------------------------------------------
