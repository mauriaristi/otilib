
# ******************************************************************************************************
cpdef tri1_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 1 node triangle 2D element (0th order).

  NODE NUMBERING:

  .. code-block::

      >  *             |  *
      >  * *           |  * *
      >  *   *            *   * 
      >  *     *     <or> *     *  
      >  *  (0)  *        *       *
      >  *         *   |  *         *
      >  * * * * * * * | (0)* * * * * *
  
  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.
    
  """
  
  return point1_iso( xi, eta, zeta)

# ------------------------------------------------------------------------------------------------------