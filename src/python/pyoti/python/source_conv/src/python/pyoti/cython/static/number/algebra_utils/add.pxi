#*****************************************************************************************************
cdef object __add__FX__({fearr_pytype} Flhs, object rhs, object out = None):
  """
  PORPUSE: Addition between {fearr_pytype} and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef {num_pytype}    orhs, ores
  cdef {num_type} cores

  cdef {fenum_pytype}     frhs, fres
  cdef {fenum_type}  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef {arr_pytype}      Orhs, Ores
  cdef {arr_type}   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef {fearr_pytype}    Frhs, Fres
  cdef {fearr_type} cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == {num_pytype}:
    orhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_oF_to( &orhs.num, &Flhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_oF( &orhs.num, &Flhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_fF_to( &frhs.num, &Flhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_fF( &frhs.num, &Flhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_FF( &Flhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_OF( &Orhs.arr, &Flhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_RF( &Rrhs.arr, &Flhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_rF_to( rrhs, &Flhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_rF( rrhs, &Flhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {{0}} and {{1}}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__OX__({arr_pytype} Olhs, object rhs, object out = None):
  """
  PORPUSE: Addition between {arr_pytype} and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef {num_pytype}    orhs, ores
  cdef {num_type} cores

  cdef {fenum_pytype}     frhs, fres
  cdef {fenum_type}  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef {arr_pytype}      Orhs, Ores
  cdef {arr_type}   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef {fearr_pytype}    Frhs, Fres
  cdef {fearr_type} cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == {num_pytype}:
    orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_oO_to( &orhs.num, &Olhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_oO( &orhs.num, &Olhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_OF( &Olhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_OO( &Olhs.arr, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_RO( &Rrhs.arr, &Olhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_rO_to( rrhs, &Olhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_rO( rrhs, &Olhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {{0}} and {{1}}.".format(type(Olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__RX__(dmat Rlhs, object rhs, object out = None):
  """
  PORPUSE: Addition between dmat and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef {num_pytype}    orhs, ores
  cdef {num_type} cores

  cdef {fenum_pytype}     frhs, fres
  cdef {fenum_type}  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef {arr_pytype}      Orhs, Ores
  cdef {arr_type}   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef {fearr_pytype}    Frhs, Fres
  cdef {fearr_type} cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_RF( &Rlhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_RO( &Rlhs.arr, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_sum_RR_to( &Rlhs.arr, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_sum_RR( &Rlhs.arr, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Rres = out
      darr_sum_rR_to( rrhs, &Rlhs.arr, &Rres.arr )
    else:
      cRres = darr_sum_rR( rrhs, &Rlhs.arr )
      res = dmat.create( &cRres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {{0}} and {{1}}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__oX__({num_pytype} olhs, object rhs, object out = None):
  """
  PORPUSE: Addition between {num_pytype} and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef {num_pytype}    orhs, ores
  cdef {num_type} cores

  cdef {fenum_pytype}     frhs, fres
  cdef {fenum_type}  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef {arr_pytype}      Orhs, Ores
  cdef {arr_type}   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef {fearr_pytype}    Frhs, Fres
  cdef {fearr_type} cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == {num_pytype}:
    orhs = rhs
    if res_flag:
      ores = out
      {num_func}_sum_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = {num_func}_sum_oo( &olhs.num, &orhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sum_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sum_of( &olhs.num, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_oF( &olhs.num, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_oO( &olhs.num, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      {num_func}_sum_ro_to( rrhs, &olhs.num, &ores.num )
    else:
      cores = {num_func}_sum_ro( rrhs, &olhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported add operation between {{0}} and {{1}}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__fX__({fenum_pytype} flhs, object rhs, object out = None):
  """
  PORPUSE: Addition between {fenum_pytype} and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef {num_pytype}    orhs, ores
  cdef {num_type} cores

  cdef {fenum_pytype}     frhs, fres
  cdef {fenum_type}  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef {arr_pytype}      Orhs, Ores
  cdef {arr_type}   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef {fearr_pytype}    Frhs, Fres
  cdef {fearr_type} cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == {num_pytype}:
    orhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sum_of_to( &orhs.num, &flhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sum_of( &orhs.num, &flhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sum_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sum_ff( &flhs.num, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_fF( &flhs.num, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sum_rf_to( rrhs, &flhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sum_rf( rrhs, &flhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {{0}} and {{1}}.".format(type(flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__rX__(coeff_t rlhs, object rhs, object out = None):
  """
  PORPUSE: Addition between coeff_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef {num_pytype}    orhs, ores
  cdef {num_type} cores

  cdef {fenum_pytype}     frhs, fres
  cdef {fenum_type}  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef {arr_pytype}      Orhs, Ores
  cdef {arr_type}   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef {fearr_pytype}    Frhs, Fres
  cdef {fearr_type} cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == {num_pytype}:
    orhs = rhs
    if res_flag:
      ores = out
      {num_func}_sum_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = {num_func}_sum_ro( rlhs, &orhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sum_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sum_rf( rlhs, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sum_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sum_rF( rlhs, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sum_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sum_rO( rlhs, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_sum_rR_to( rlhs, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_sum_rR( rlhs, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    res = rlhs+rrhs
  else:
    raise TypeError("Unsupported add operation between {{0}} and {{1}}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

