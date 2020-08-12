

#*****************************************************************************************************
cdef __dot_product_FX(dmatfe Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between dmatfe and other array.

  """
  #***************************************************************************************************
  cdef dmat       Rrhs, Rres
  cdef dmatfe     Frhs, Fres
  cdef coeff_t    rrhs, rres
  cdef dnumfe     frhs, fres
  # C- result holders
  cdef fednum_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is dmatfe: # FF
    Frhs = rhs
    if res_flag:
      fres = out
      fedarr_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num)
    else:
      cfres = fedarr_dotproduct_FF( &Flhs.arr, &Frhs.arr )
      res = dnumfe.create(&cfres)
    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:
      fres = out
      fedarr_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num)
    else:
      cfres = fedarr_dotproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = dnumfe.create(&cfres)
    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef __dot_product_RX( dmat Rlhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between dmatfe and other array.

  """
  #***************************************************************************************************
  
  cdef dmat       Rrhs, Rres
  cdef dmatfe    Frhs, Fres
  
  cdef coeff_t    rres
  cdef dnumfe     fres
  # C- result holders  
  cdef fednum_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is dmatfe: # RF
    Frhs = rhs
    if res_flag:
      fres = out
      fedarr_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num)
    else:
      cfres = fedarr_dotproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = dnumfe.create(&cfres)
    # end if   
  elif trhs is dmat:    # RR
    Rrhs = rhs
    if res_flag:
      rres = out
      darr_dotproduct_RR_to( &Rrhs.arr, &Rlhs.arr, &rres)
    else:
      rres = darr_dotproduct_RR( &Rrhs.arr, &Rlhs.arr)
      res = rres
    # end if 
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






