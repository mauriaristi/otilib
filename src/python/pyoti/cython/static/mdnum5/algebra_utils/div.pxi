#*****************************************************************************************************
cdef object __div__FX__(mdmatfe5 Flhs, object rhs, object out = None):
  """
  PORPUSE: Division between mdmatfe5 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum5    orhs, ores
  cdef mdnum5_t cores

  cdef mdnumfe5     frhs, fres
  cdef femdnum5_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdmat5      Orhs, Ores
  cdef mdarr5_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef mdmatfe5    Frhs, Fres
  cdef femdarr5_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum5:
    orhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_Fo_to( &Flhs.arr, &orhs.num, &Fres.arr )
    else:
      cFres = femdarr5_div_Fo( &Flhs.arr, &orhs.num )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdnumfe5:
    frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = femdarr5_div_Ff( &Flhs.arr, &frhs.num )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdmatfe5:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_FF( &Flhs.arr, &Frhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdmat5:
    Orhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_FO_to( &Flhs.arr, &Orhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_FO( &Flhs.arr, &Orhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_FR( &Flhs.arr, &Rrhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = femdarr5_div_Fr( &Flhs.arr, rrhs )
      res = mdmatfe5.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__OX__(mdmat5 Olhs, object rhs, object out = None):
  """
  PORPUSE: Division between mdmat5 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum5    orhs, ores
  cdef mdnum5_t cores

  cdef mdnumfe5     frhs, fres
  cdef femdnum5_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdmat5      Orhs, Ores
  cdef mdarr5_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef mdmatfe5    Frhs, Fres
  cdef femdarr5_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum5:
    orhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_Oo_to( &Olhs.arr, &orhs.num, &Ores.arr )
    else:
      cOres = mdarr5_div_Oo( &Olhs.arr, &orhs.num )
      res = mdmat5.create( &cOres )
    # end if
  elif trhs == mdmatfe5:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_OF( &Olhs.arr, &Frhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdmat5:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr5_div_OO( &Olhs.arr, &Orhs.arr )
      res = mdmat5.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_OR_to( &Olhs.arr, &Rrhs.arr, &Ores.arr )
    else:
      cOres = mdarr5_div_OR( &Olhs.arr, &Rrhs.arr )
      res = mdmat5.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_Or_to( &Olhs.arr, rrhs, &Ores.arr )
    else:
      cOres = mdarr5_div_Or( &Olhs.arr, rrhs )
      res = mdmat5.create( &cOres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(Olhs),trhs))
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
  cdef mdnum5    orhs, ores
  cdef mdnum5_t cores

  cdef mdnumfe5     frhs, fres
  cdef femdnum5_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdmat5      Orhs, Ores
  cdef mdarr5_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef mdmatfe5    Frhs, Fres
  cdef femdarr5_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdmatfe5:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_RF( &Rlhs.arr, &Frhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdmat5:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr5_div_RO( &Rlhs.arr, &Orhs.arr )
      res = mdmat5.create( &cOres )
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
cdef object __div__oX__(mdnum5 olhs, object rhs, object out = None):
  """
  PORPUSE: Division between mdnum5 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum5    orhs, ores
  cdef mdnum5_t cores

  cdef mdnumfe5     frhs, fres
  cdef femdnum5_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdmat5      Orhs, Ores
  cdef mdarr5_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef mdmatfe5    Frhs, Fres
  cdef femdarr5_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum5:
    orhs = rhs
    if res_flag:
      ores = out
      mdnum5_div_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = mdnum5_div_oo( &olhs.num, &orhs.num )
      res = mdnum5.create( &cores )
    # end if
  elif trhs == mdnumfe5:
    frhs = rhs
    if res_flag:
      fres = out
      femdnum5_div_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = femdnum5_div_of( &olhs.num, &frhs.num )
      res = mdnumfe5.create( &cfres )
    # end if
  elif trhs == mdmatfe5:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_oF( &olhs.num, &Frhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdmat5:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr5_div_oO( &olhs.num, &Orhs.arr )
      res = mdmat5.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      mdnum5_div_or_to( &olhs.num, rrhs, &ores.num )
    else:
      cores = mdnum5_div_or( &olhs.num, rrhs )
      res = mdnum5.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__fX__(mdnumfe5 flhs, object rhs, object out = None):
  """
  PORPUSE: Division between mdnumfe5 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum5    orhs, ores
  cdef mdnum5_t cores

  cdef mdnumfe5     frhs, fres
  cdef femdnum5_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdmat5      Orhs, Ores
  cdef mdarr5_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef mdmatfe5    Frhs, Fres
  cdef femdarr5_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum5:
    orhs = rhs
    if res_flag:
      fres = out
      femdnum5_div_fo_to( &flhs.num, &orhs.num, &fres.num )
    else:
      cfres = femdnum5_div_fo( &flhs.num, &orhs.num )
      res = mdnumfe5.create( &cfres )
    # end if
  elif trhs == mdnumfe5:
    frhs = rhs
    if res_flag:
      fres = out
      femdnum5_div_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = femdnum5_div_ff( &flhs.num, &frhs.num )
      res = mdnumfe5.create( &cfres )
    # end if
  elif trhs == mdmatfe5:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_fF( &flhs.num, &Frhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      femdnum5_div_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = femdnum5_div_fr( &flhs.num, rrhs )
      res = mdnumfe5.create( &cfres )
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
  cdef mdnum5    orhs, ores
  cdef mdnum5_t cores

  cdef mdnumfe5     frhs, fres
  cdef femdnum5_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdmat5      Orhs, Ores
  cdef mdarr5_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef mdmatfe5    Frhs, Fres
  cdef femdarr5_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum5:
    orhs = rhs
    if res_flag:
      ores = out
      mdnum5_div_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = mdnum5_div_ro( rlhs, &orhs.num )
      res = mdnum5.create( &cores )
    # end if
  elif trhs == mdnumfe5:
    frhs = rhs
    if res_flag:
      fres = out
      femdnum5_div_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = femdnum5_div_rf( rlhs, &frhs.num )
      res = mdnumfe5.create( &cfres )
    # end if
  elif trhs == mdmatfe5:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr5_div_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr5_div_rF( rlhs, &Frhs.arr )
      res = mdmatfe5.create( &cFres )
    # end if
  elif trhs == mdmat5:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr5_div_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr5_div_rO( rlhs, &Orhs.arr )
      res = mdmat5.create( &cOres )
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
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------
