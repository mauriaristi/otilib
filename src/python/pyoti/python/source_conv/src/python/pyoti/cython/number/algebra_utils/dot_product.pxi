

#*****************************************************************************************************
cdef __dot_product_FX({fearr_pytype} Flhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between {fearr_pytype} and other array.

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
      {fearr_func}_dotproduct_FF_to( &Flhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = {fearr_func}_dotproduct_FF( &Flhs.arr, &Frhs.arr )
      res = {fenum_pytype}.create(&cfres)
    # end if 

  elif trhs is {arr_pytype}:   # FO
    Orhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_dotproduct_OF_to( &Orhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = {fearr_func}_dotproduct_OF( &Orhs.arr, &Flhs.arr)
      res = {fenum_pytype}.create(&cfres)

    # end if 
  elif trhs is dmat:    # FR
    Rrhs = rhs
    if res_flag:

      fres = out
      {fearr_func}_dotproduct_RF_to( &Rrhs.arr, &Flhs.arr, &fres.num)

    else:

      cfres = {fearr_func}_dotproduct_RF( &Rrhs.arr, &Flhs.arr)
      res = {fenum_pytype}.create(&cfres)

    # end if
  else:
    raise TypeError("Unsupported types at dot_product operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef __dot_product_OX( {arr_pytype} Olhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product between {fearr_pytype} and other array.

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
      {fearr_func}_dotproduct_OF_to( &Olhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = {fearr_func}_dotproduct_OF( &Olhs.arr, &Frhs.arr )
      res = {fenum_pytype}.create(&cfres)
    # end if 

  elif trhs is {arr_pytype}:   # OO
    Orhs = rhs
    if res_flag:

      ores = out
      {arr_func}_dotproduct_OO_to( &Olhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = {arr_func}_dotproduct_OO( &Olhs.arr, &Orhs.arr)
      res = {num_pytype}.create(&cores)

    # end if 
  elif trhs is dmat:    # OR
    Rrhs = rhs
    if res_flag:

      ores = out
      {arr_func}_dotproduct_RO_to( &Rrhs.arr, &Olhs.arr, &ores.num)

    else:

      cores = {arr_func}_dotproduct_RO( &Rrhs.arr, &Olhs.arr)
      res = {num_pytype}.create(&cores)

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
  PURPOSE:  Vector dot product between {fearr_pytype} and other array.

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
      {fearr_func}_dotproduct_RF_to( &Rlhs.arr, &Frhs.arr ,&fres.num)

    else:

      cfres = {fearr_func}_dotproduct_RF( &Rlhs.arr, &Frhs.arr )
      res = {fenum_pytype}.create(&cfres)
    # end if 

  elif trhs is {arr_pytype}:   # RO
    Orhs = rhs
    if res_flag:

      ores = out
      {arr_func}_dotproduct_RO_to( &Rlhs.arr, &Orhs.arr, &ores.num)

    else:

      cores = {arr_func}_dotproduct_RO( &Rlhs.arr, &Orhs.arr)
      res = {num_pytype}.create(&cores)

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

