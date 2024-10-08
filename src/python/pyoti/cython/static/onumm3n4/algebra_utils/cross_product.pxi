

#*****************************************************************************************************
cdef __cross_product_FX(feomatm3n4 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between feomatm3n4 and other array.

  """
  #***************************************************************************************************
  cdef omatm3n4      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feomatm3n4    Frhs, Fres
  cdef onumm3n4    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef feonumm3n4     frhs, fres
  # C- result holders
  cdef onumm3n4_t cores
  cdef feonumm3n4_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feomatm3n4: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm3n4_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm3n4_crossproduct_FF( &Flhs.arr, &Frhs.arr )
      res = feomatm3n4.create(&cFres)
    # end if 

  elif trhs is omatm3n4:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      feoarrm3n4_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = feoarrm3n4_crossproduct_OF( &Orhs.arr, &Flhs.arr)
      res = feomatm3n4.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      feoarrm3n4_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = feoarrm3n4_crossproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = feomatm3n4.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( omatm3n4 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between feomatm3n4 and other array.

  """
  #***************************************************************************************************
  cdef omatm3n4      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feomatm3n4    Frhs, Fres
  cdef onumm3n4    ores
  cdef coeff_t    rres
  cdef feonumm3n4     fres
  # C- result holders
  cdef onumm3n4_t cores
  cdef feonumm3n4_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feomatm3n4: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm3n4_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm3n4_crossproduct_OF( &Olhs.arr, &Frhs.arr )
      res = feomatm3n4.create(&cFres)
    # end if 

  elif trhs is omatm3n4:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      oarrm3n4_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = oarrm3n4_crossproduct_OO( &Olhs.arr, &Orhs.arr)
      res = omatm3n4.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      oarrm3n4_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr)

    else:

      cOres = oarrm3n4_crossproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = omatm3n4.create(&cOres)

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
  PURPOSE:  Vector cross product between feomatm3n4 and other array.

  """
  #***************************************************************************************************
  cdef omatm3n4      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feomatm3n4    Frhs, Fres
  cdef onumm3n4    ores
  cdef coeff_t    rres
  cdef feonumm3n4     fres
  # C- result holders
  cdef onumm3n4_t cores
  cdef feonumm3n4_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feomatm3n4: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm3n4_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm3n4_crossproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = feomatm3n4.create(&cFres)
    # end if 

  elif trhs is omatm3n4:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      oarrm3n4_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = oarrm3n4_crossproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = omatm3n4.create(&cOres)

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

