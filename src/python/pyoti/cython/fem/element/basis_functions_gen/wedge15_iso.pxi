
# ****************************************************************************************************
cpdef wedge15_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 15-node wedge 3D element (2nd order). 
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
                |   (11)    */      (10)                         
                |   *     (14)        *                          
                |  *       /*           *                        
                | *       / *             *                      
               (3)* * * * * (9) * * * * * *(4)    [zeta +1]      
                *      /    *               *                    
                *     /     *               *                    
                *    /     (2)              *                    
                *   /      * *              *                    
                *  /      *    *            *                    
                * /      *      *           *                    
              (12) - - -*- - - - -*- - - -(13) -------------> xi 
                *      *           *        *                    
                *    (8)           (7)      *                    
                *    *                *     *                    
                *   *                  *    *                    
                *  *                     *  *                    
                * *                       * *                    
               (0)* * * * * *(6)* * * * * *(1)    [zeta -1]      

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

  # Define pseudo Area coordinates of the triangle side.
  # Vertex nodes:
  N_tri_1 = ( 2 * L1 - 1 ) * L1
  N_tri_2 = ( 2 * L2 - 1 ) * L2
  N_tri_3 = ( 2 * L3 - 1 ) * L3
  
  # Edge nodes:
  N_tri_4 = L1 * L2
  N_tri_5 = L2 * L3
  N_tri_6 = L3 * L1
    
  # Define some functions related to the prism side
  N_line_1 = ( 1 - zeta )
  N_line_2 = ( 1 + zeta )
  N_line_3 = 1 - zeta*zeta

  # Vertex nodes.
  N0  = 0.5 * ( N_tri_1 * N_line_1 - L1 * N_line_3)  # (  0,  0, -1 )
  N1  = 0.5 * ( N_tri_2 * N_line_1 - L2 * N_line_3)  # (  1,  0, -1 )
  N2  = 0.5 * ( N_tri_3 * N_line_1 - L3 * N_line_3)  # (  0,  1, -1 )

  N3  = 0.5 * ( N_tri_1 * N_line_2 - L1 * N_line_3)  # (  0,  0, +1 )
  N4  = 0.5 * ( N_tri_2 * N_line_2 - L2 * N_line_3)  # (  1,  0, +1 )
  N5  = 0.5 * ( N_tri_3 * N_line_2 - L3 * N_line_3)  # (  0,  1, +1 )

  # Triangle faces midsize nodes.
  N6  = 2 * N_tri_4 * N_line_1 # (  0.5,  0  , -1 )
  N7  = 2 * N_tri_5 * N_line_1 # (  0.5,  0.5, -1 )
  N8  = 2 * N_tri_6 * N_line_1 # (  0  ,  0.5, -1 )

  N9  = 2 * N_tri_4 * N_line_2 # (  0.5,  0  , +1 )
  N10 = 2 * N_tri_5 * N_line_2 # (  0.5,  0.5, +1 )
  N11 = 2 * N_tri_6 * N_line_2 # (  0  ,  0.5, +1 )

  # Rectangular face midsize nodes.
  N12 = L1 * N_line_3 # (  0,  0,  0 )
  N13 = L2 * N_line_3 # (  1,  0,  0 )
  N14 = L3 * N_line_3 # (  0,  1,  0 )

  

  return [ N0, N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, N12, N13, N14 ]
   
# ----------------------------------------------------------------------------------------------------
