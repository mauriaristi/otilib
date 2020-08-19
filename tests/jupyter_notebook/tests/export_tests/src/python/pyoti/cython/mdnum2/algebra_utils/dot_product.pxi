

#*****************************************************************************************************
cdef __dot_product_FX(femdarr2_t Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between femdarr2_t and other array.

  """
  #***************************************************************************************************
  cdef mdarr2_t      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef femdarr2_t    Frhs, Fres
  cdef mdnum2_t    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef femdnum2_t     frhs, fres
  # C- result holders
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is femdarr2_t: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr2_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr2_dotproduct_FF( &Flhs.arr, &Frhs.arr )
      res = femdnum2_t.create(&cfres)
    # end if 

  elif trhs is mdarr2_t:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      femdarr2_dotproduct_OF_to( &Orhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr2_dotproduct_OF( &Orhs.arr, &Flhs.arr)
      res = femdnum2_t.create(&cfres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      femdarr2_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr2_dotproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = femdnum2_t.create(&cfres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __dot_product_OX( mdarr2_t Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between femdarr2_t and other array.

  """
  #***************************************************************************************************
  cdef mdarr2_t      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef femdarr2_t    Frhs, Fres
  cdef mdnum2_t    ores
  cdef coeff_t    rres
  cdef femdnum2_t     fres
  # C- result holders
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is femdarr2_t: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr2_dotproduct_OF_to( &Olhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr2_dotproduct_OF( &Olhs.arr, &Frhs.arr )
      res = femdnum2_t.create(&cfres)
    # end if 

  elif trhs is mdarr2_t:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr2_dotproduct_OO_to( &Olhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr2_dotproduct_OO( &Olhs.arr, &Orhs.arr)
      res = mdnum2_t.create(&cores)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      mdarr2_dotproduct_RO_to( &Rrhs.arr, &Olhs.arr, &ores.num)

    else:

      cores = mdarr2_dotproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = mdnum2_t.create(&cores)

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
  PURPOSE:  Vector dot product between femdarr2_t and other array.

  """
  #***************************************************************************************************
  cdef mdarr2_t      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef femdarr2_t    Frhs, Fres
  cdef mdnum2_t    ores
  cdef coeff_t    rres
  cdef femdnum2_t     fres
  # C- result holders
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is femdarr2_t: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr2_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr2_dotproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = femdnum2_t.create(&cfres)
    # end if 

  elif trhs is mdarr2_t:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr2_dotproduct_RO_to( &Rlhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr2_dotproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = mdnum2_t.create(&cores)

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

