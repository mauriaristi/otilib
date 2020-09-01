

#*****************************************************************************************************
cdef __cross_product_FX(mdmatfe3 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between mdmatfe3 and other array.

  """
  #***************************************************************************************************
  cdef mdmat3      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe3    Frhs, Fres
  cdef mdnum3    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef mdnumfe3     frhs, fres
  # C- result holders
  cdef mdnum3_t cores
  cdef femdnum3_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe3: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr3_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = femdarr3_crossproduct_FF( &Flhs.arr, &Frhs.arr )
      res = mdmatfe3.create(&cFres)
    # end if 

  elif trhs is mdmat3:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      femdarr3_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = femdarr3_crossproduct_OF( &Orhs.arr, &Flhs.arr)
      res = mdmatfe3.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      femdarr3_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = femdarr3_crossproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = mdmatfe3.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( mdmat3 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between mdmatfe3 and other array.

  """
  #***************************************************************************************************
  cdef mdmat3      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe3    Frhs, Fres
  cdef mdnum3    ores
  cdef coeff_t    rres
  cdef mdnumfe3     fres
  # C- result holders
  cdef mdnum3_t cores
  cdef femdnum3_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe3: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr3_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = femdarr3_crossproduct_OF( &Olhs.arr, &Frhs.arr )
      res = mdmatfe3.create(&cFres)
    # end if 

  elif trhs is mdmat3:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr3_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = mdarr3_crossproduct_OO( &Olhs.arr, &Orhs.arr)
      res = mdmat3.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      mdarr3_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr)

    else:

      cOres = mdarr3_crossproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = mdmat3.create(&cOres)

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
  PURPOSE:  Vector cross product between mdmatfe3 and other array.

  """
  #***************************************************************************************************
  cdef mdmat3      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef mdmatfe3    Frhs, Fres
  cdef mdnum3    ores
  cdef coeff_t    rres
  cdef mdnumfe3     fres
  # C- result holders
  cdef mdnum3_t cores
  cdef femdnum3_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is mdmatfe3: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      femdarr3_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = femdarr3_crossproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = mdmatfe3.create(&cFres)
    # end if 

  elif trhs is mdmat3:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      mdarr3_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = mdarr3_crossproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = mdmat3.create(&cOres)

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

