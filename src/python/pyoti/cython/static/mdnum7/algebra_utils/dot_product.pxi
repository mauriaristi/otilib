

#*****************************************************************************************************
cdef __dot_product_FX(mdmatfe7 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between mdmatfe7 and other array.

  """
  #***************************************************************************************************
  cdef mdmat7      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe7    Frhs, Fres
  cdef mdnum7    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef mdnumfe7     frhs, fres
  # C- result holders
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe7: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr7_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr7_dotproduct_FF( &Flhs.arr, &Frhs.arr )
      res = mdnumfe7.create(&cfres)
    # end if 

  elif trhs is mdmat7:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      femdarr7_dotproduct_OF_to( &Orhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr7_dotproduct_OF( &Orhs.arr, &Flhs.arr)
      res = mdnumfe7.create(&cfres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      femdarr7_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr7_dotproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = mdnumfe7.create(&cfres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __dot_product_OX( mdmat7 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between mdmatfe7 and other array.

  """
  #***************************************************************************************************
  cdef mdmat7      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe7    Frhs, Fres
  cdef mdnum7    ores
  cdef coeff_t    rres
  cdef mdnumfe7     fres
  # C- result holders
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe7: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr7_dotproduct_OF_to( &Olhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr7_dotproduct_OF( &Olhs.arr, &Frhs.arr )
      res = mdnumfe7.create(&cfres)
    # end if 

  elif trhs is mdmat7:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr7_dotproduct_OO_to( &Olhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr7_dotproduct_OO( &Olhs.arr, &Orhs.arr)
      res = mdnum7.create(&cores)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      mdarr7_dotproduct_RO_to( &Rrhs.arr, &Olhs.arr, &ores.num)

    else:

      cores = mdarr7_dotproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = mdnum7.create(&cores)

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
  PURPOSE:  Vector dot product between mdmatfe7 and other array.

  """
  #***************************************************************************************************
  cdef mdmat7      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe7    Frhs, Fres
  cdef mdnum7    ores
  cdef coeff_t    rres
  cdef mdnumfe7     fres
  # C- result holders
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe7: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr7_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr7_dotproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = mdnumfe7.create(&cfres)
    # end if 

  elif trhs is mdmat7:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr7_dotproduct_RO_to( &Rlhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr7_dotproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = mdnum7.create(&cores)

    # end if 
  # elif trhs is dmat:    # RR
  #   Rrhs = rhs
  #   if res_flag:

  #     rres = out
  #     darr_dotproduct_to( &Rrhs.arr, &Olhs.arr, &rres)

  #   else:

  #     rres = darr_dotproduct( &Rrhs.arr, &Olhs.arr)
  #     res = rres

  #   # end if 
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

