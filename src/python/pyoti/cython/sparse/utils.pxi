

#*****************************************************************************************************
def e( hum_dir ,ord_t order = 0, bases_t nbases = 0):
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



#*****************************************************************************************************
def get_deriv(np.ndarray inarr, hum_dir):
  """
  PURPOSE:  Return the derivative selected from a numpy array of sotinums.

  """
  #***************************************************************************************************

  cdef uint64_t i,j,k,ZERO=0,ONE=1,TWO=2
  cdef np.ndarray out = np.empty_like( inarr, dtype= np.float64 )
  shape = inarr.shape


  if inarr.ndim == 1:
    for i in range(shape[ZERO]):
      out[i] = inarr[i].get_deriv(hum_dir)
    # end for 
  elif inarr.ndim == 2:
    for i in range(shape[ZERO]):
      for j in range(shape[ONE]):
        out[i,j] = inarr[i,j].get_deriv(hum_dir)
      # end for 
    # end for 
  elif inarr.ndim == 3:
    for i in range(shape[ZERO]):
      for j in range(shape[ONE]):
        for k in range(shape[TWO]):
          out[i,j,k] = inarr[i,j,k].get_deriv(hum_dir)
        # end for 
      # end for 
    # end for 
  else:
    raise IndexError("Cant handle arrays with more than 3 dimensions")
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------
