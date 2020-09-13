

#*****************************************************************************************************
cdef __dot_product_FX(mdmatfe10 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between mdmatfe10 and other array.

  """
  #***************************************************************************************************
  cdef mdmat10      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe10    Frhs, Fres
  cdef mdnum10    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef mdnumfe10     frhs, fres
  # C- result holders
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe10: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr10_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr10_dotproduct_FF( &Flhs.arr, &Frhs.arr )
      res = mdnumfe10.create(&cfres)
    # end if 

  elif trhs is mdmat10:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      femdarr10_dotproduct_OF_to( &Orhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr10_dotproduct_OF( &Orhs.arr, &Flhs.arr)
      res = mdnumfe10.create(&cfres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      femdarr10_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr10_dotproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = mdnumfe10.create(&cfres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __dot_product_OX( mdmat10 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between mdmatfe10 and other array.

  """
  #***************************************************************************************************
  cdef mdmat10      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe10    Frhs, Fres
  cdef mdnum10    ores
  cdef coeff_t    rres
  cdef mdnumfe10     fres
  # C- result holders
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe10: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr10_dotproduct_OF_to( &Olhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr10_dotproduct_OF( &Olhs.arr, &Frhs.arr )
      res = mdnumfe10.create(&cfres)
    # end if 

  elif trhs is mdmat10:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr10_dotproduct_OO_to( &Olhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr10_dotproduct_OO( &Olhs.arr, &Orhs.arr)
      res = mdnum10.create(&cores)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      mdarr10_dotproduct_RO_to( &Rrhs.arr, &Olhs.arr, &ores.num)

    else:

      cores = mdarr10_dotproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = mdnum10.create(&cores)

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
  PURPOSE:  Vector dot product between mdmatfe10 and other array.

  """
  #***************************************************************************************************
  cdef mdmat10      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe10    Frhs, Fres
  cdef mdnum10    ores
  cdef coeff_t    rres
  cdef mdnumfe10     fres
  # C- result holders
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe10: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr10_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr10_dotproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = mdnumfe10.create(&cfres)
    # end if 

  elif trhs is mdmat10:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr10_dotproduct_RO_to( &Rlhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr10_dotproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = mdnum10.create(&cores)

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

