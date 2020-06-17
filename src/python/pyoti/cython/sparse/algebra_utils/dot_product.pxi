

#*****************************************************************************************************
cdef __dot_product_FX(matsofe Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between matsofe and other array.

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
      fearrso_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num, dhl)

    else:

      cfres = fearrso_dotproduct_FF( &Flhs.arr, &Frhs.arr , dhl)
      res = sotife.create(&cfres)
    # end if 

  elif trhs is matso:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      fearrso_dotproduct_OF_to( &Orhs.arr, &Flhs.arr, &fres.num, dhl)

    else:

      cfres = fearrso_dotproduct_OF( &Orhs.arr, &Flhs.arr, dhl)
      res = sotife.create(&cfres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      fearrso_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num, dhl)

    else:

      cfres = fearrso_dotproduct_RF( &Rrhs.arr, &Flhs.arr,  dhl)
      res = sotife.create(&cfres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __dot_product_OX( matso Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between matsofe and other array.

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
      fearrso_dotproduct_OF_to( &Olhs.arr, &Frhs.arr ,&fres.num, dhl)

    else:

      cfres = fearrso_dotproduct_OF( &Olhs.arr, &Frhs.arr , dhl)
      res = sotife.create(&cfres)
    # end if 

  elif trhs is matso:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      arrso_dotproduct_OO_to( &Olhs.arr, &Orhs.arr, &ores.num, dhl)

    else:

      cores = arrso_dotproduct_OO( &Olhs.arr, &Orhs.arr, dhl)
      res = sotinum.create(&cores)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      arrso_dotproduct_RO_to( &Rrhs.arr, &Olhs.arr, &ores.num, dhl)

    else:

      cores = arrso_dotproduct_RO( &Rrhs.arr, &Olhs.arr, dhl)
      res = sotinum.create(&cores)

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
  PURPOSE:  Vector dot product between matsofe and other array.

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
      fearrso_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num, dhl)

    else:

      cfres = fearrso_dotproduct_RF( &Rlhs.arr, &Frhs.arr , dhl)
      res = sotife.create(&cfres)
    # end if 

  elif trhs is matso:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      arrso_dotproduct_RO_to( &Rlhs.arr, &Orhs.arr, &ores.num, dhl)

    else:

      cores = arrso_dotproduct_RO( &Rlhs.arr, &Orhs.arr, dhl)
      res = sotinum.create(&cores)

    # end if 
  # elif trhs is dmat:    # RR
  #   Rrhs = rhs
  #   if res_flag:

  #     rres = out
  #     darr_dotproduct_to( &Rrhs.arr, &Olhs.arr, &rres, dhl)

  #   else:

  #     rres = darr_dotproduct( &Rrhs.arr, &Olhs.arr,  dhl)
  #     res = rres

  #   # end if 
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






