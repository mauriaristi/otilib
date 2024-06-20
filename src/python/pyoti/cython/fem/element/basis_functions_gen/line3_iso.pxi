
#*****************************************************************************************************
cpdef line3_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 3 node Line 1D element (2nd order).

  NODE NUMBERING:

  .. code-block::

      > (0)---(2)---(1)
  
  :param xi:  Xi  coordinate for this element.
  :param eta: Eta coordinate for this element.
  :param zeta: zeta coordinate for this element.

  :returns: [N0,N1,...]: List of evaluated basis functions.

  """   
  
  N0 = -0.5 * xi * ( 1.0 - xi )
  N1 =  0.5 * xi * ( 1.0 + xi ) 
  N2 =  1.0 - xi * xi

  return [ N0, N1, N2 ]

#-----------------------------------------------------------------------------------------------------

