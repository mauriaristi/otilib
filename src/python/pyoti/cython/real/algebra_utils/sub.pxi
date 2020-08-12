#*****************************************************************************************************
cdef object __sub__FX__(dmatfe Flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between dmatfe and object.

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
      fedarr_sub_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = fedarr_sub_Ff( &Flhs.arr, &frhs.num )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_sub_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_sub_FF( &Flhs.arr, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      fedarr_sub_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = fedarr_sub_FR( &Flhs.arr, &Rrhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      fedarr_sub_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = fedarr_sub_Fr( &Flhs.arr, rrhs )
      res = dmatfe.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(Flhs),trhs))
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
      fedarr_sub_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_sub_RF( &Rlhs.arr, &Frhs.arr )
      res = dmatfe.create( &cFres )
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
cdef object __sub__fX__(dnumfe flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between dnumfe and object.

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
      fednum_sub_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = fednum_sub_ff( &flhs.num, &frhs.num )
      res = dnumfe.create( &cfres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_sub_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_sub_fF( &flhs.num, &Frhs.arr )
      res = dmatfe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      fednum_sub_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = fednum_sub_fr( &flhs.num, rrhs )
      res = dnumfe.create( &cfres )
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
      fednum_sub_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = fednum_sub_rf( rlhs, &frhs.num )
      res = dnumfe.create( &cfres )
    # end if
  elif trhs == dmatfe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fedarr_sub_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = fedarr_sub_rF( rlhs, &Frhs.arr )
      res = dmatfe.create( &cFres )
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


