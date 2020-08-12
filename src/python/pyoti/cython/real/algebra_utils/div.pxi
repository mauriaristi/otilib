#*****************************************************************************************************
cdef object __div__FX__(dmatfe Flhs, object rhs, object out = None):
  """
  PORPUSE: Division between dmatfe and object.

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
      Fres = out
      fedarr_div_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = fedarr_div_Ff( &Flhs.arr, &frhs.num )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_div_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_div_FF( &Flhs.arr, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      fedarr_div_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = fedarr_div_FR( &Flhs.arr, &Rrhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      fedarr_div_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = fedarr_div_Fr( &Flhs.arr, rrhs )
      res = dmatfe.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(Flhs),trhs))
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
      fedarr_div_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_div_RF( &Rlhs.arr, &Frhs.arr )
      res = dmatfe.create( &cFres )
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
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __div__fX__(dnumfe flhs, object rhs, object out = None):
  """
  PORPUSE: Division between dnumfe and object.

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
      fednum_div_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = fednum_div_ff( &flhs.num, &frhs.num )
      res = dnumfe.create( &cfres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_div_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_div_fF( &flhs.num, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      fednum_div_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = fednum_div_fr( &flhs.num, rrhs )
      res = dnumfe.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(flhs),trhs))
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
      fednum_div_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = fednum_div_rf( rlhs, &frhs.num )
      res = dnumfe.create( &cfres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_div_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_div_rF( rlhs, &Frhs.arr )
      res = dmatfe.create( &cFres )
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
    res = rlhs-rrhs
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


