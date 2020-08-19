#*****************************************************************************************************
cdef object __div__FX__({fearr_pytype} Flhs, object rhs, object out = None):
  """
  PORPUSE: Division between {fearr_pytype} and object.

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
      {fearr_func}_div_Fo_to( &Flhs.arr, &orhs.num, &Fres.arr )
    else:
      cFres = {fearr_func}_div_Fo( &Flhs.arr, &orhs.num )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = {fearr_func}_div_Ff( &Flhs.arr, &frhs.num )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_FF( &Flhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_FO_to( &Flhs.arr, &Orhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_FO( &Flhs.arr, &Orhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_FR( &Flhs.arr, &Rrhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = {fearr_func}_div_Fr( &Flhs.arr, rrhs )
      res = {fearr_pytype}.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {{0}} and {{1}}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__OX__({arr_pytype} Olhs, object rhs, object out = None):
  """
  PORPUSE: Division between {arr_pytype} and object.

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
      {arr_func}_div_Oo_to( &Olhs.arr, &orhs.num, &Ores.arr )
    else:
      cOres = {arr_func}_div_Oo( &Olhs.arr, &orhs.num )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_OF( &Olhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_div_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_div_OO( &Olhs.arr, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_div_OR_to( &Olhs.arr, &Rrhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_div_OR( &Olhs.arr, &Rrhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_div_Or_to( &Olhs.arr, rrhs, &Ores.arr )
    else:
      cOres = {arr_func}_div_Or( &Olhs.arr, rrhs )
      res = {arr_pytype}.create( &cOres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {{0}} and {{1}}.".format(type(Olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__RX__(dmat Rlhs, object rhs, object out = None):
  """
  PORPUSE: Division between dmat and object.

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
      {fearr_func}_div_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_RF( &Rlhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_div_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_div_RO( &Rlhs.arr, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_div_RR_to( &Rlhs.arr, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_div_RR( &Rlhs.arr, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Rres = out
      darr_div_Rr_to( &Rlhs.arr, rrhs, &Rres.arr )
    else:
      cRres = darr_div_Rr( &Rlhs.arr, rrhs )
      res = dmat.create( &cRres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {{0}} and {{1}}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__oX__({num_pytype} olhs, object rhs, object out = None):
  """
  PORPUSE: Division between {num_pytype} and object.

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
      {num_func}_div_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = {num_func}_div_oo( &olhs.num, &orhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_div_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_div_of( &olhs.num, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_oF( &olhs.num, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_div_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_div_oO( &olhs.num, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      {num_func}_div_or_to( &olhs.num, rrhs, &ores.num )
    else:
      cores = {num_func}_div_or( &olhs.num, rrhs )
      res = {num_pytype}.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported div operation between {{0}} and {{1}}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__fX__({fenum_pytype} flhs, object rhs, object out = None):
  """
  PORPUSE: Division between {fenum_pytype} and object.

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
      {fenum_func}_div_fo_to( &flhs.num, &orhs.num, &fres.num )
    else:
      cfres = {fenum_func}_div_fo( &flhs.num, &orhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_div_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_div_ff( &flhs.num, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_fF( &flhs.num, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_div_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = {fenum_func}_div_fr( &flhs.num, rrhs )
      res = {fenum_pytype}.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {{0}} and {{1}}.".format(type(flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__rX__(coeff_t rlhs, object rhs, object out = None):
  """
  PORPUSE: Division between coeff_t and object.

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
      {num_func}_div_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = {num_func}_div_ro( rlhs, &orhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_div_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_div_rf( rlhs, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_div_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_div_rF( rlhs, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_div_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_div_rO( rlhs, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_div_rR_to( rlhs, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_div_rR( rlhs, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    res = rlhs/rrhs
  else:
    raise TypeError("Unsupported div operation between {{0}} and {{1}}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

