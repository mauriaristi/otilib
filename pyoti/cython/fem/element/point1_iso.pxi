
#*****************************************************************************************************
cpdef point1_iso( ord_t derOrder, np.ndarray coords):
  """
  Definition of basis functions for the point "0D" element.

  NODE NUMBERING:
                         (0)

  INPUTS:
    -> derOrder: Order of derivative sought for basis functions.
    -> coords:   Array with the coordinates to evaluate the basis functions.
    -> kwargs:   Dictionary with other data required to be evaluated.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.
      
  """
  # Create full of Nones.
  N0 = np.empty((coords.shape[0],3),dtype=object)
  
  for i in range(N0.shape[0]):
    for j in range(N0.shape[1]):
      
      N0[i,j] = sotinum(1.0)
      
    # end for 
  # end for
  
  return [N0,]

#-----------------------------------------------------------------------------------------------------

