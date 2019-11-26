
# ******************************************************************************************************
cpdef tri1_iso( ord_t derOrder, np.ndarray coords):
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
    -> derOrder: Order of derivative sought for basis functions.
    -> coords:   Array with the coordinates to evaluate the basis functions.
    -> kwargs:   Dictionary with other data required to be evaluated.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

  """
   
  return point1_iso(derOrder,coords)[:,:1]

# ------------------------------------------------------------------------------------------------------