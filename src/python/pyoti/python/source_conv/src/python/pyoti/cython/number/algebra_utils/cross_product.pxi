

#*****************************************************************************************************
cdef __cross_product_FX({fearr_pytype} Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between {fearr_pytype} and other array.

  """
  #***************************************************************************************************
  cdef {arr_pytype}      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef {fearr_pytype}    Frhs, Fres
  cdef {num_pytype}    orhs, ores
  cdef coeff_t    rrhs, rres
  cdef {fenum_pytype}     frhs, fres
  # C- result holders
  cdef {num_type} cores
  cdef {fenum_type}  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is {fearr_pytype}: # FF
    Frhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_crossproduct_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = {fearr_func}_crossproduct_FF( &Flhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create(&cFres)
    # end if 

  elif trhs is {arr_pytype}:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_crossproduct_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_crossproduct_OF( &Orhs.arr, &Flhs.arr)
      res = {fearr_pytype}.create(&cFres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_crossproduct_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_crossproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = {fearr_pytype}.create(&cFres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __cross_product_OX( {arr_pytype} Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector cross product between {fearr_pytype} and other array.

  """
  #***************************************************************************************************
  cdef {arr_pytype}      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef {fearr_pytype}    Frhs, Fres
  cdef {num_pytype}    ores
  cdef coeff_t    rres
  cdef {fenum_pytype}     fres
  # C- result holders
  cdef {num_type} cores
  cdef {fenum_type}  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is {fearr_pytype}: # OF
    Frhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_crossproduct_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = {fearr_func}_crossproduct_OF( &Olhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create(&cFres)
    # end if 

  elif trhs is {arr_pytype}:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      {arr_func}_crossproduct_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = {arr_func}_crossproduct_OO( &Olhs.arr, &Orhs.arr)
      res = {arr_pytype}.create(&cOres)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      {arr_func}_crossproduct_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr)

    else:

      cOres = {arr_func}_crossproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = {arr_pytype}.create(&cOres)

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
  PURPOSE:  Vector cross product between {fearr_pytype} and other array.

  """
  #***************************************************************************************************
  cdef {arr_pytype}      Orhs, Ores
  cdef dmat       Rrhs, Rres
  cdef {fearr_pytype}    Frhs, Fres
  cdef {num_pytype}    ores
  cdef coeff_t    rres
  cdef {fenum_pytype}     fres
  # C- result holders
  cdef {num_type} cores
  cdef {fenum_type}  cfres

  cdef uint8_t res_flag = 1
  cdef object res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   trhs is {fearr_pytype}: # RF
    Frhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_crossproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)

    else:

      cFres = {fearr_func}_crossproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create(&cFres)
    # end if 

  elif trhs is {arr_pytype}:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      {arr_func}_crossproduct_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr)

    else:

      cOres = {arr_func}_crossproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = {arr_pytype}.create(&cOres)

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

