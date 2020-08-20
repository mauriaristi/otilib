

#*****************************************************************************************************
cdef __cross_product_FX(feoarrm2n5_t Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between feoarrm2n5_t and other array.

  """
  #***************************************************************************************************
  cdef oarrm2n5_t      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feoarrm2n5_t    Frhs, Fres
  cdef onumm2n5_t    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef feonumm2n5_t     frhs, fres
  # C- result holders
  cdef onumm2n5_t cores
  cdef feonumm2n5_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feoarrm2n5_t: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm2n5_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm2n5_crossproduct_FF( &Flhs.arr, &Frhs.arr )
      res = feoarrm2n5_t.create(&cFres)
    # end if 

  elif trhs is oarrm2n5_t:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      feoarrm2n5_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = feoarrm2n5_crossproduct_OF( &Orhs.arr, &Flhs.arr)
      res = feoarrm2n5_t.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      feoarrm2n5_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = feoarrm2n5_crossproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = feoarrm2n5_t.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( oarrm2n5_t Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between feoarrm2n5_t and other array.

  """
  #***************************************************************************************************
  cdef oarrm2n5_t      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feoarrm2n5_t    Frhs, Fres
  cdef onumm2n5_t    ores
  cdef coeff_t    rres
  cdef feonumm2n5_t     fres
  # C- result holders
  cdef onumm2n5_t cores
  cdef feonumm2n5_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feoarrm2n5_t: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm2n5_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm2n5_crossproduct_OF( &Olhs.arr, &Frhs.arr )
      res = feoarrm2n5_t.create(&cFres)
    # end if 

  elif trhs is oarrm2n5_t:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      oarrm2n5_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = oarrm2n5_crossproduct_OO( &Olhs.arr, &Orhs.arr)
      res = oarrm2n5_t.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      oarrm2n5_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr)

    else:

      cOres = oarrm2n5_crossproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = oarrm2n5_t.create(&cOres)

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
  PURPOSE:  Vector cross product between feoarrm2n5_t and other array.

  """
  #***************************************************************************************************
  cdef oarrm2n5_t      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef feoarrm2n5_t    Frhs, Fres
  cdef onumm2n5_t    ores
  cdef coeff_t    rres
  cdef feonumm2n5_t     fres
  # C- result holders
  cdef onumm2n5_t cores
  cdef feonumm2n5_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is feoarrm2n5_t: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      feoarrm2n5_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = feoarrm2n5_crossproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = feoarrm2n5_t.create(&cFres)
    # end if 

  elif trhs is oarrm2n5_t:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      oarrm2n5_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = oarrm2n5_crossproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = oarrm2n5_t.create(&cOres)

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

