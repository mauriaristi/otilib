




# Creation functions.




#*****************************************************************************************************
def e( hum_dir ,ord_t order = 0,bases_t nbases = 0):
  """
  PURPOSE:  To create an OTI number with value 1 at the specified
            direction, in a human friendly manner.

  """
  #***************************************************************************************************
  
  global dhl

  cdef imdir_t indx_hd
  cdef ord_t order_hd
  cdef bases_t bases_hd
  cdef otinum_t res


  # Get the index and order of the human direction.
  [indx_hd, order_hd] = imdir(hum_dir)
  
  # Het the number of bases of the 
  bases_hd = (dhelp_get_imdir( indx_hd, order_hd, dhl))[order_hd-1]
  
  res = oti_createZero(max(bases_hd,nbases), max(order_hd,order), dhl)

  # Set the coefficient to 1.
  oti_setIm_IdxOrd(1.0,indx_hd,order_hd,&res,dhl)    

  return otinum.create(&res)

#-----------------------------------------------------------------------------------------------------

