

#*****************************************************************************************************
cdef __dot_product_FX(mdmatfe4 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between mdmatfe4 and other array.

  """
  #***************************************************************************************************
  cdef mdmat4      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe4    Frhs, Fres
  cdef mdnum4    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef mdnumfe4     frhs, fres
  # C- result holders
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe4: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr4_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr4_dotproduct_FF( &Flhs.arr, &Frhs.arr )
      res = mdnumfe4.create(&cfres)
    # end if 

  elif trhs is mdmat4:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      femdarr4_dotproduct_OF_to( &Orhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr4_dotproduct_OF( &Orhs.arr, &Flhs.arr)
      res = mdnumfe4.create(&cfres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      femdarr4_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = femdarr4_dotproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = mdnumfe4.create(&cfres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __dot_product_OX( mdmat4 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between mdmatfe4 and other array.

  """
  #***************************************************************************************************
  cdef mdmat4      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe4    Frhs, Fres
  cdef mdnum4    ores
  cdef coeff_t    rres
  cdef mdnumfe4     fres
  # C- result holders
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe4: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr4_dotproduct_OF_to( &Olhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr4_dotproduct_OF( &Olhs.arr, &Frhs.arr )
      res = mdnumfe4.create(&cfres)
    # end if 

  elif trhs is mdmat4:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr4_dotproduct_OO_to( &Olhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr4_dotproduct_OO( &Olhs.arr, &Orhs.arr)
      res = mdnum4.create(&cores)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      mdarr4_dotproduct_RO_to( &Rrhs.arr, &Olhs.arr, &ores.num)

    else:

      cores = mdarr4_dotproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = mdnum4.create(&cores)

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
  PURPOSE:  Vector dot product between mdmatfe4 and other array.

  """
  #***************************************************************************************************
  cdef mdmat4      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe4    Frhs, Fres
  cdef mdnum4    ores
  cdef coeff_t    rres
  cdef mdnumfe4     fres
  # C- result holders
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe4: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr4_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = femdarr4_dotproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = mdnumfe4.create(&cfres)
    # end if 

  elif trhs is mdmat4:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr4_dotproduct_RO_to( &Rlhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = mdarr4_dotproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = mdnum4.create(&cores)

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

