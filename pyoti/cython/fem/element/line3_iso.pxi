
#*****************************************************************************************************
cpdef line3_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder):
  """
  Definition of basis functions for the P2 Line element.

  NODE NUMBERING:
  
                           (0)* *(2)* *(1)

  INPUTS:
    -> xi:  Xi coordinate for this element.
    -> eta: Eta coordinate for this element.
    -> chi: Chi coordinate for this element.
    -> derOrder: Order of derivative required.

  OUTPUTS: 
    -> [N0,N1,...]: Evaluated basis functions.

  """   

  cdef otinum xi = xi_r + e( 1, order = derOrder)

  cdef otinum N0 = -0.5 * xi * ( 1.0 - xi )
  cdef otinum N1 =  0.5 * xi * ( 1.0 + xi ) 
  cdef otinum N2 =  1.0 - xi * xi

  return [ N0, N1, N2 ]

#-----------------------------------------------------------------------------------------------------

