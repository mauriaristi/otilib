#*****************************************************************************************************
cdef object __sub__FX__(matsofe Flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between matsofe and object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types:
  cdef sotinum    orhs, ores
  cdef sotinum_t cores

  cdef sotife     frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == sotinum:
    orhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_Fo_to( &Flhs.arr, &orhs.num, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_Fo( &Flhs.arr, &orhs.num, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == sotife:
    frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_Ff( &Flhs.arr, &frhs.num, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_FF( &Flhs.arr, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matso:
    Orhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_FO_to( &Flhs.arr, &Orhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_FO( &Flhs.arr, &Orhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_FR( &Flhs.arr, &Rrhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_Fr_to( &Flhs.arr, rrhs, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_Fr( &Flhs.arr, rrhs, dhl )
      res = matsofe.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __sub__OX__(matso Olhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between matso and object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types:
  cdef sotinum    orhs, ores
  cdef sotinum_t cores

  cdef sotife     frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == sotinum:
    orhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_Oo_to( &Olhs.arr, &orhs.num, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_Oo( &Olhs.arr, &orhs.num, dhl )
      res = matso.create( &cOres )
    # end if
  elif trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_OF( &Olhs.arr, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matso:
    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_OO( &Olhs.arr, &Orhs.arr, dhl )
      res = matso.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_OR_to( &Olhs.arr, &Rrhs.arr, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_OR( &Olhs.arr, &Rrhs.arr, dhl )
      res = matso.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_Or_to( &Olhs.arr, rrhs, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_Or( &Olhs.arr, rrhs, dhl )
      res = matso.create( &cOres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(Olhs),trhs))
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

  global dhl

  # Scalar types:
  cdef sotinum    orhs, ores
  cdef sotinum_t cores

  cdef sotife     frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_RF( &Rlhs.arr, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matso:
    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_RO( &Rlhs.arr, &Orhs.arr, dhl )
      res = matso.create( &cOres )
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
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __sub__oX__(sotinum olhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between sotinum and object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types:
  cdef sotinum    orhs, ores
  cdef sotinum_t cores

  cdef sotife     frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == sotinum:
    orhs = rhs
    if res_flag:
      ores = out
      soti_sub_oo_to( &olhs.num, &orhs.num, &ores.num, dhl )
    else:
      cores = soti_sub_oo( &olhs.num, &orhs.num, dhl )
      res = sotinum.create( &cores )
    # end if
  elif trhs == sotife:
    frhs = rhs
    if res_flag:
      fres = out
      fesoti_sub_of_to( &olhs.num, &frhs.num, &fres.num, dhl )
    else:
      cfres = fesoti_sub_of( &olhs.num, &frhs.num, dhl )
      res = sotife.create( &cfres )
    # end if
  elif trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_oF_to( &olhs.num, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_oF( &olhs.num, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matso:
    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_oO_to( &olhs.num, &Orhs.arr, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_oO( &olhs.num, &Orhs.arr, dhl )
      res = matso.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      soti_sub_or_to( &olhs.num, rrhs, &ores.num, dhl )
    else:
      cores = soti_sub_or( &olhs.num, rrhs, dhl )
      res = sotinum.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __sub__fX__(sotife flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between sotife and object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types:
  cdef sotinum    orhs, ores
  cdef sotinum_t cores

  cdef sotife     frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == sotinum:
    orhs = rhs
    if res_flag:
      fres = out
      fesoti_sub_fo_to( &flhs.num, &orhs.num, &fres.num, dhl )
    else:
      cfres = fesoti_sub_fo( &flhs.num, &orhs.num, dhl )
      res = sotife.create( &cfres )
    # end if
  elif trhs == sotife:
    frhs = rhs
    if res_flag:
      fres = out
      fesoti_sub_ff_to( &flhs.num, &frhs.num, &fres.num, dhl )
    else:
      cfres = fesoti_sub_ff( &flhs.num, &frhs.num, dhl )
      res = sotife.create( &cfres )
    # end if
  elif trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_fF_to( &flhs.num, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_fF( &flhs.num, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      fesoti_sub_fr_to( &flhs.num, rrhs, &fres.num, dhl )
    else:
      cfres = fesoti_sub_fr( &flhs.num, rrhs, dhl )
      res = sotife.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(flhs),trhs))
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

  global dhl

  # Scalar types:
  cdef sotinum    orhs, ores
  cdef sotinum_t cores

  cdef sotife     frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == sotinum:
    orhs = rhs
    if res_flag:
      ores = out
      soti_sub_ro_to( rlhs, &orhs.num, &ores.num, dhl )
    else:
      cores = soti_sub_ro( rlhs, &orhs.num, dhl )
      res = sotinum.create( &cores )
    # end if
  elif trhs == sotife:
    frhs = rhs
    if res_flag:
      fres = out
      fesoti_sub_rf_to( rlhs, &frhs.num, &fres.num, dhl )
    else:
      cfres = fesoti_sub_rf( rlhs, &frhs.num, dhl )
      res = sotife.create( &cfres )
    # end if
  elif trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sub_rF_to( rlhs, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sub_rF( rlhs, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matso:
    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sub_rO_to( rlhs, &Orhs.arr, &Ores.arr, dhl )
    else:
      cOres = arrso_sub_rO( rlhs, &Orhs.arr, dhl )
      res = matso.create( &cOres )
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
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


