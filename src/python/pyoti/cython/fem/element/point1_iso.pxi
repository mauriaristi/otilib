
#*****************************************************************************************************
cpdef point1_iso( coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder):
  """
  Definition of basis functions for the 1 node point 0D element.  (0th order)

  NODE NUMBERING:
  
                         (0)

  INPUTS:
    -> xi:  Xi coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> chi: Chi coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.
      
  """

  cdef otinum N0 = 1.0 + 0.0*e( 1, order = derOrder)
    
  return [N0,]

#-----------------------------------------------------------------------------------------------------

