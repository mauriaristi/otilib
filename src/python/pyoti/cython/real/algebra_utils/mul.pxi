#*****************************************************************************************************
cdef object __mul__FX__(dmatfe Flhs, object rhs, object out = None):
  """
  PORPUSE: Multiplication between dmatfe and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef dnumfe     frhs, fres
  cdef fednum_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef dmatfe    Frhs, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if   trhs == dnumfe:
    frhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_fF_to( &frhs.num, &Flhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_fF( &frhs.num, &Flhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_FF( &Flhs.arr, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_RF( &Rrhs.arr, &Flhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_rF_to( rrhs, &Flhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_rF( rrhs, &Flhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported mul operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __mul__RX__(dmat Rlhs, object rhs, object out = None):
  """
  PORPUSE: Multiplication between dmat and object.

  """
  #***************************************************************************************************

  # Scalar types:
  cdef dnumfe     frhs, fres
  cdef fednum_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef dmatfe    Frhs, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_RF( &Rlhs.arr, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_mul_RR_to( &Rlhs.arr, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_mul_RR( &Rlhs.arr, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Rres = out
      darr_mul_rR_to( rrhs, &Rlhs.arr, &Rres.arr )
    else:
      cRres = darr_mul_rR( rrhs, &Rlhs.arr )
      res = dmat.create( &cRres )
    # end if
  else:
    raise TypeError("Unsupported mul operation between {0} and {1}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef object __mul__fX__(dnumfe flhs, object rhs, object out = None):
  """
  PORPUSE: Multiplication between dnumfe and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef dnumfe     frhs, fres
  cdef fednum_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef dmatfe    Frhs, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == dnumfe:
    frhs = rhs
    if res_flag:
      fres = out
      fednum_mul_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = fednum_mul_ff( &flhs.num, &frhs.num )
      res = dnumfe.create( &cfres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_fF( &flhs.num, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      fednum_mul_rf_to( rrhs, &flhs.num, &fres.num )
    else:
      cfres = fednum_mul_rf( rrhs, &flhs.num )
      res = dnumfe.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported mul operation between {0} and {1}.".format(type(flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __mul__rX__(coeff_t rlhs, object rhs, object out = None):
  """
  PORPUSE: Multiplication between coeff_t and object.

  """
  #***************************************************************************************************

  # Scalar types:
  cdef dnumfe     frhs, fres
  cdef fednum_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef dmatfe    Frhs, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == dnumfe:
    frhs = rhs
    if res_flag:
      fres = out
      fednum_mul_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = fednum_mul_rf( rlhs, &frhs.num )
      res = dnumfe.create( &cfres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_mul_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_mul_rF( rlhs, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_mul_rR_to( rlhs, &Rrhs.arr, &Rres.arr )
    else:
      cRres = darr_mul_rR( rlhs, &Rrhs.arr )
      res = dmat.create( &cRres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    res = rlhs+rrhs
  else:
    raise TypeError("Unsupported mul operation between {0} and {1}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


