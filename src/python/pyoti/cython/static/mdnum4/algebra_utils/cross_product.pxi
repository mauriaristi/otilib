

#*****************************************************************************************************
cdef __cross_product_FX(mdmatfe4 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between mdmatfe4 and other array.

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
      femdarr4_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = femdarr4_crossproduct_FF( &Flhs.arr, &Frhs.arr )
      res = mdmatfe4.create(&cFres)
    # end if 

  elif trhs is mdmat4:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      femdarr4_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = femdarr4_crossproduct_OF( &Orhs.arr, &Flhs.arr)
      res = mdmatfe4.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      femdarr4_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = femdarr4_crossproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = mdmatfe4.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( mdmat4 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between mdmatfe4 and other array.

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
      femdarr4_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = femdarr4_crossproduct_OF( &Olhs.arr, &Frhs.arr )
      res = mdmatfe4.create(&cFres)
    # end if 

  elif trhs is mdmat4:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr4_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = mdarr4_crossproduct_OO( &Olhs.arr, &Orhs.arr)
      res = mdmat4.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      mdarr4_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr)

    else:

      cOres = mdarr4_crossproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = mdmat4.create(&cOres)

    # end if 

  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_RX( dmat Rlhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between mdmatfe4 and other array.

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
      femdarr4_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = femdarr4_crossproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = mdmatfe4.create(&cFres)
    # end if 

  elif trhs is mdmat4:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr4_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = mdarr4_crossproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = mdmat4.create(&cOres)

    # end if 
  # elif trhs is dmat:    # RR
  #   Rrhs = rhs
  #   if res_flag:

  #     rRes = out
  #     darr_crossproduct_to( &Rrhs.arr, &Rlhs.arr, &rres)

  #   else:

  #     rRes = darr_crossproduct( &Rrhs.arr, &Rlhs.arr)
  #     res = rRes

  #   # end if 
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

