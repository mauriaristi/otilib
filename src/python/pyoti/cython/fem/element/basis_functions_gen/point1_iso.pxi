
#*****************************************************************************************************
cpdef point1_iso( xi, eta, zeta):
  """
  Definition of basis functions for the 1 node point 0D element.  (0th order)

  NODE NUMBERING:
  
                         (0)

  INPUTS:
    -> xi:  Xi coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> zeta: zeta coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.
      
  """

  N0 = 0.0*xi+1.0
    
  return [N0,]

#-----------------------------------------------------------------------------------------------------

