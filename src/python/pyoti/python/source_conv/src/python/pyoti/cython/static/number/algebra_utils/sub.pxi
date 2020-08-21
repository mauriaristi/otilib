#*****************************************************************************************************
cdef object __sub__FX__({fearr_pytype} Flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between {fearr_pytype} and object.

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
      {fearr_func}_sub_Fo_to( &Flhs.arr, &orhs.num, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_Fo( &Flhs.arr, &orhs.num )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_Ff( &Flhs.arr, &frhs.num )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_FF( &Flhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_FO_to( &Flhs.arr, &Orhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_FO( &Flhs.arr, &Orhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_FR( &Flhs.arr, &Rrhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_Fr( &Flhs.arr, rrhs )
      res = {fearr_pytype}.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {{0}} and {{1}}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__OX__({arr_pytype} Olhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between {arr_pytype} and object.

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
      {arr_func}_sub_Oo_to( &Olhs.arr, &orhs.num, &Ores.arr )
    else:
      cOres = {arr_func}_sub_Oo( &Olhs.arr, &orhs.num )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_OF( &Olhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sub_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sub_OO( &Olhs.arr, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sub_OR_to( &Olhs.arr, &Rrhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sub_OR( &Olhs.arr, &Rrhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sub_Or_to( &Olhs.arr, rrhs, &Ores.arr )
    else:
      cOres = {arr_func}_sub_Or( &Olhs.arr, rrhs )
      res = {arr_pytype}.create( &cOres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {{0}} and {{1}}.".format(type(Olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__RX__(dmat Rlhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between dmat and object.

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
      {fearr_func}_sub_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_RF( &Rlhs.arr, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sub_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sub_RO( &Rlhs.arr, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_sub_RR_to( &Rlhs.arr, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_sub_RR( &Rlhs.arr, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Rres = out
      darr_sub_Rr_to( &Rlhs.arr, rrhs, &Rres.arr )
    else:
      cRres = darr_sub_Rr( &Rlhs.arr, rrhs )
      res = dmat.create( &cRres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {{0}} and {{1}}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__oX__({num_pytype} olhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between {num_pytype} and object.

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
      {num_func}_sub_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = {num_func}_sub_oo( &olhs.num, &orhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sub_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sub_of( &olhs.num, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_oF( &olhs.num, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sub_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sub_oO( &olhs.num, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      {num_func}_sub_or_to( &olhs.num, rrhs, &ores.num )
    else:
      cores = {num_func}_sub_or( &olhs.num, rrhs )
      res = {num_pytype}.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {{0}} and {{1}}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__fX__({fenum_pytype} flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between {fenum_pytype} and object.

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
      {fenum_func}_sub_fo_to( &flhs.num, &orhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sub_fo( &flhs.num, &orhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sub_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sub_ff( &flhs.num, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_fF( &flhs.num, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sub_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = {fenum_func}_sub_fr( &flhs.num, rrhs )
      res = {fenum_pytype}.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {{0}} and {{1}}.".format(type(flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__rX__(coeff_t rlhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between coeff_t and object.

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
      {num_func}_sub_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = {num_func}_sub_ro( rlhs, &orhs.num )
      res = {num_pytype}.create( &cores )
    # end if
  elif trhs == {fenum_pytype}:
    frhs = rhs
    if res_flag:
      fres = out
      {fenum_func}_sub_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = {fenum_func}_sub_rf( rlhs, &frhs.num )
      res = {fenum_pytype}.create( &cfres )
    # end if
  elif trhs == {fearr_pytype}:
    Frhs = rhs
    if res_flag:
      Fres = out
      {fearr_func}_sub_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = {fearr_func}_sub_rF( rlhs, &Frhs.arr )
      res = {fearr_pytype}.create( &cFres )
    # end if
  elif trhs == {arr_pytype}:
    Orhs = rhs
    if res_flag:
      Ores = out
      {arr_func}_sub_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = {arr_func}_sub_rO( rlhs, &Orhs.arr )
      res = {arr_pytype}.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_sub_rR_to( rlhs, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_sub_rR( rlhs, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    res = rlhs-rrhs
  else:
    raise TypeError("Unsupported sub operation between {{0}} and {{1}}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

