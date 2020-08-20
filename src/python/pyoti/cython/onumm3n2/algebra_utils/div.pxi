#*****************************************************************************************************
cdef object __div__FX__(feoarrm3n2_t Flhs, object rhs, object out = None):
  """
  PORPUSE: Division between feoarrm3n2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm3n2_t    orhs, ores
  cdef onumm3n2_t cores

  cdef feonumm3n2_t     frhs, fres
  cdef feonumm3n2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef oarrm3n2_t      Orhs, Ores
  cdef oarrm3n2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feoarrm3n2_t    Frhs, Fres
  cdef feoarrm3n2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm3n2_t:
    orhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_Fo_to( &Flhs.arr, &orhs.num, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_Fo( &Flhs.arr, &orhs.num )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == feonumm3n2_t:
    frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_Ff( &Flhs.arr, &frhs.num )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == feoarrm3n2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_FF( &Flhs.arr, &Frhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == oarrm3n2_t:
    Orhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_FO_to( &Flhs.arr, &Orhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_FO( &Flhs.arr, &Orhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_FR( &Flhs.arr, &Rrhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_Fr( &Flhs.arr, rrhs )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__OX__(oarrm3n2_t Olhs, object rhs, object out = None):
  """
  PORPUSE: Division between oarrm3n2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm3n2_t    orhs, ores
  cdef onumm3n2_t cores

  cdef feonumm3n2_t     frhs, fres
  cdef feonumm3n2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef oarrm3n2_t      Orhs, Ores
  cdef oarrm3n2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feoarrm3n2_t    Frhs, Fres
  cdef feoarrm3n2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm3n2_t:
    orhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_Oo_to( &Olhs.arr, &orhs.num, &Ores.arr )
    else:
      cOres = oarrm3n2_div_Oo( &Olhs.arr, &orhs.num )
      res = oarrm3n2_t.create( &cOres )
    # end if
  elif trhs == feoarrm3n2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_OF( &Olhs.arr, &Frhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == oarrm3n2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm3n2_div_OO( &Olhs.arr, &Orhs.arr )
      res = oarrm3n2_t.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_OR_to( &Olhs.arr, &Rrhs.arr, &Ores.arr )
    else:
      cOres = oarrm3n2_div_OR( &Olhs.arr, &Rrhs.arr )
      res = oarrm3n2_t.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_Or_to( &Olhs.arr, rrhs, &Ores.arr )
    else:
      cOres = oarrm3n2_div_Or( &Olhs.arr, rrhs )
      res = oarrm3n2_t.create( &cOres )
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
  cdef onumm3n2_t    orhs, ores
  cdef onumm3n2_t cores

  cdef feonumm3n2_t     frhs, fres
  cdef feonumm3n2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef oarrm3n2_t      Orhs, Ores
  cdef oarrm3n2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feoarrm3n2_t    Frhs, Fres
  cdef feoarrm3n2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == feoarrm3n2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_RF( &Rlhs.arr, &Frhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == oarrm3n2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm3n2_div_RO( &Rlhs.arr, &Orhs.arr )
      res = oarrm3n2_t.create( &cOres )
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
cdef object __div__oX__(onumm3n2_t olhs, object rhs, object out = None):
  """
  PORPUSE: Division between onumm3n2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm3n2_t    orhs, ores
  cdef onumm3n2_t cores

  cdef feonumm3n2_t     frhs, fres
  cdef feonumm3n2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef oarrm3n2_t      Orhs, Ores
  cdef oarrm3n2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feoarrm3n2_t    Frhs, Fres
  cdef feoarrm3n2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm3n2_t:
    orhs = rhs
    if res_flag:
      ores = out
      onumm3n2_div_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = onumm3n2_div_oo( &olhs.num, &orhs.num )
      res = onumm3n2_t.create( &cores )
    # end if
  elif trhs == feonumm3n2_t:
    frhs = rhs
    if res_flag:
      fres = out
      feonumm3n2_div_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = feonumm3n2_div_of( &olhs.num, &frhs.num )
      res = feonumm3n2_t.create( &cfres )
    # end if
  elif trhs == feoarrm3n2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_oF( &olhs.num, &Frhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == oarrm3n2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm3n2_div_oO( &olhs.num, &Orhs.arr )
      res = oarrm3n2_t.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      onumm3n2_div_or_to( &olhs.num, rrhs, &ores.num )
    else:
      cores = onumm3n2_div_or( &olhs.num, rrhs )
      res = onumm3n2_t.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __div__fX__(feonumm3n2_t flhs, object rhs, object out = None):
  """
  PORPUSE: Division between feonumm3n2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm3n2_t    orhs, ores
  cdef onumm3n2_t cores

  cdef feonumm3n2_t     frhs, fres
  cdef feonumm3n2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef oarrm3n2_t      Orhs, Ores
  cdef oarrm3n2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feoarrm3n2_t    Frhs, Fres
  cdef feoarrm3n2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm3n2_t:
    orhs = rhs
    if res_flag:
      fres = out
      feonumm3n2_div_fo_to( &flhs.num, &orhs.num, &fres.num )
    else:
      cfres = feonumm3n2_div_fo( &flhs.num, &orhs.num )
      res = feonumm3n2_t.create( &cfres )
    # end if
  elif trhs == feonumm3n2_t:
    frhs = rhs
    if res_flag:
      fres = out
      feonumm3n2_div_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = feonumm3n2_div_ff( &flhs.num, &frhs.num )
      res = feonumm3n2_t.create( &cfres )
    # end if
  elif trhs == feoarrm3n2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_fF( &flhs.num, &Frhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      feonumm3n2_div_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = feonumm3n2_div_fr( &flhs.num, rrhs )
      res = feonumm3n2_t.create( &cfres )
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
  cdef onumm3n2_t    orhs, ores
  cdef onumm3n2_t cores

  cdef feonumm3n2_t     frhs, fres
  cdef feonumm3n2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef oarrm3n2_t      Orhs, Ores
  cdef oarrm3n2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feoarrm3n2_t    Frhs, Fres
  cdef feoarrm3n2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm3n2_t:
    orhs = rhs
    if res_flag:
      ores = out
      onumm3n2_div_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = onumm3n2_div_ro( rlhs, &orhs.num )
      res = onumm3n2_t.create( &cores )
    # end if
  elif trhs == feonumm3n2_t:
    frhs = rhs
    if res_flag:
      fres = out
      feonumm3n2_div_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = feonumm3n2_div_rf( rlhs, &frhs.num )
      res = feonumm3n2_t.create( &cfres )
    # end if
  elif trhs == feoarrm3n2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm3n2_div_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm3n2_div_rF( rlhs, &Frhs.arr )
      res = feoarrm3n2_t.create( &cFres )
    # end if
  elif trhs == oarrm3n2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm3n2_div_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm3n2_div_rO( rlhs, &Orhs.arr )
      res = oarrm3n2_t.create( &cOres )
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

