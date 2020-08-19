

#*****************************************************************************************************
cdef __cross_product_FX(matsofe Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between matsofe and other array.

  """
  #***************************************************************************************************
  cdef matso      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef matsofe    Frhs, Fres
  cdef sotinum    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef sotife     frhs, fres
  # C- result holders
  cdef sotinum_t cores
  cdef fesoti_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is matsofe: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      fearrso_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr, dhl)

    else:

      cFres = fearrso_crossproduct_FF( &Flhs.arr, &Frhs.arr , dhl)
      res = matsofe.create(&cFres)
    # end if 

  elif trhs is matso:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      fearrso_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_crossproduct_OF( &Orhs.arr, &Flhs.arr, dhl)
      res = matsofe.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      fearrso_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_crossproduct_RF( &Rrhs.arr, &Flhs.arr,  dhl)
      res = matsofe.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( matso Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between matsofe and other array.

  """
  #***************************************************************************************************
  cdef matso      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef matsofe    Frhs, Fres
  cdef sotinum    ores
  cdef coeff_t    rres
  cdef sotife     fres
  # C- result holders
  cdef sotinum_t cores
  cdef fesoti_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is matsofe: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      fearrso_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr, dhl)

    else:

      cFres = fearrso_crossproduct_OF( &Olhs.arr, &Frhs.arr , dhl)
      res = matsofe.create(&cFres)
    # end if 

  elif trhs is matso:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      arrso_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_crossproduct_OO( &Olhs.arr, &Orhs.arr, dhl)
      res = matso.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      arrso_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_crossproduct_RO( &Rrhs.arr, &Olhs.arr, dhl)
      res = matso.create(&cOres)

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
  PURPOSE:  Vector cross product between matsofe and other array.

  """
  #***************************************************************************************************
  cdef matso      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef matsofe    Frhs, Fres
  cdef sotinum    ores
  cdef coeff_t    rres
  cdef sotife     fres
  # C- result holders
  cdef sotinum_t cores
  cdef fesoti_t  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is matsofe: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      fearrso_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr, dhl)

    else:

      cFres = fearrso_crossproduct_RF( &Rlhs.arr, &Frhs.arr , dhl)
      res = matsofe.create(&cFres)
    # end if 

  elif trhs is matso:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      arrso_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_crossproduct_RO( &Rlhs.arr, &Orhs.arr, dhl)
      res = matso.create(&cOres)

    # end if 
  # elif trhs is dmat:    # RR
  #   Rrhs = rhs
  #   if res_flag:

  #     rRes = out
  #     darr_crossproduct_to( &Rrhs.arr, &Rlhs.arr, &rres, dhl)

  #   else:

  #     rRes = darr_crossproduct( &Rrhs.arr, &Rlhs.arr,  dhl)
  #     res = rRes

  #   # end if 
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






