

#*****************************************************************************************************
def e( hum_dir ,ord_t order = 0,bases_t nbases = 0):
  """
  PURPOSE:  To create a sotinum with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  global dhl

  cdef imdir_t indx_hd
  cdef ord_t order_hd
  cdef bases_t bases_hd
  cdef sotinum_t res
  
  [indx_hd, order_hd] = imdir(hum_dir)

  if order_hd <= order:

    res = soti_createReal(0.0, order, dhl)

    # Set the coefficient to 1.
    soti_set_item(1.0, indx_hd, order_hd, &res, dhl)

  else:

    res = soti_createReal(0.0, order_hd, dhl)

    # Set the coefficient to 1.
    soti_set_item(1.0, indx_hd, order_hd, &res, dhl) 

  return sotinum.create(&res)

#-----------------------------------------------------------------------------------------------------




