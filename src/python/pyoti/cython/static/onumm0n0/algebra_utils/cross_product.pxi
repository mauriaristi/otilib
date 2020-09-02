

#*****************************************************************************************************
cdef __cross_product_FX(feomatm0n0 Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between feomatm0n0 and other array.

  """
  #***************************************************************************************************
  cdef omatm0n0      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feomatm0n0    Frhs, Fres
  cdef onumm0n0    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef feonumm0n0     frhs, fres
  # C- result holders
  cdef onumm0n0_t cores
  cdef feonumm0n0_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feomatm0n0: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm0n0_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm0n0_crossproduct_FF( &Flhs.arr, &Frhs.arr )
      res = feomatm0n0.create(&cFres)
    # end if 

  elif trhs is omatm0n0:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      feoarrm0n0_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = feoarrm0n0_crossproduct_OF( &Orhs.arr, &Flhs.arr)
      res = feomatm0n0.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      feoarrm0n0_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = feoarrm0n0_crossproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = feomatm0n0.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( omatm0n0 Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between feomatm0n0 and other array.

  """
  #***************************************************************************************************
  cdef omatm0n0      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feomatm0n0    Frhs, Fres
  cdef onumm0n0    ores
  cdef coeff_t    rres
  cdef feonumm0n0     fres
  # C- result holders
  cdef onumm0n0_t cores
  cdef feonumm0n0_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feomatm0n0: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm0n0_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm0n0_crossproduct_OF( &Olhs.arr, &Frhs.arr )
      res = feomatm0n0.create(&cFres)
    # end if 

  elif trhs is omatm0n0:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      oarrm0n0_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = oarrm0n0_crossproduct_OO( &Olhs.arr, &Orhs.arr)
      res = omatm0n0.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      oarrm0n0_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr)

    else:

      cOres = oarrm0n0_crossproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = omatm0n0.create(&cOres)

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
  PURPOSE:  Vector cross product between feomatm0n0 and other array.

  """
  #***************************************************************************************************
  cdef omatm0n0      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feomatm0n0    Frhs, Fres
  cdef onumm0n0    ores
  cdef coeff_t    rres
  cdef feonumm0n0     fres
  # C- result holders
  cdef onumm0n0_t cores
  cdef feonumm0n0_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feomatm0n0: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm0n0_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm0n0_crossproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = feomatm0n0.create(&cFres)
    # end if 

  elif trhs is omatm0n0:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      oarrm0n0_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = oarrm0n0_crossproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = omatm0n0.create(&cOres)

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

