# ****************************************************************************************************
cpdef hex20_iso( coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder):
  """
  Function to create the additional nodal coordinates from an 8-node brick 3D element (1st order). 
  
  For this case create nodes (9) - (19)

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
    -> 

  """
  
  

  return 
   
# ----------------------------------------------------------------------------------------------------