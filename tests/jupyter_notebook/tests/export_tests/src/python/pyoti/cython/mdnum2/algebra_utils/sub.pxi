#*****************************************************************************************************
cdef object __sub__FX__(femdarr2_t Flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between femdarr2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum2_t    orhs, ores
  cdef mdnum2_t cores

  cdef femdnum2_t     frhs, fres
  cdef femdnum2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdarr2_t      Orhs, Ores
  cdef mdarr2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef femdarr2_t    Frhs, Fres
  cdef femdarr2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum2_t:
    orhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_Fo_to( &Flhs.arr, &orhs.num, &Fres.arr )
    else:
      cFres = femdarr2_sub_Fo( &Flhs.arr, &orhs.num )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == femdnum2_t:
    frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_Ff_to( &Flhs.arr, &frhs.num, &Fres.arr )
    else:
      cFres = femdarr2_sub_Ff( &Flhs.arr, &frhs.num )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == femdarr2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_FF( &Flhs.arr, &Frhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == mdarr2_t:
    Orhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_FO_to( &Flhs.arr, &Orhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_FO( &Flhs.arr, &Orhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_FR_to( &Flhs.arr, &Rrhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_FR( &Flhs.arr, &Rrhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_Fr_to( &Flhs.arr, rrhs, &Fres.arr )
    else:
      cFres = femdarr2_sub_Fr( &Flhs.arr, rrhs )
      res = femdarr2_t.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__OX__(mdarr2_t Olhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between mdarr2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum2_t    orhs, ores
  cdef mdnum2_t cores

  cdef femdnum2_t     frhs, fres
  cdef femdnum2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdarr2_t      Orhs, Ores
  cdef mdarr2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef femdarr2_t    Frhs, Fres
  cdef femdarr2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum2_t:
    orhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_Oo_to( &Olhs.arr, &orhs.num, &Ores.arr )
    else:
      cOres = mdarr2_sub_Oo( &Olhs.arr, &orhs.num )
      res = mdarr2_t.create( &cOres )
    # end if
  elif trhs == femdarr2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_OF( &Olhs.arr, &Frhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == mdarr2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr2_sub_OO( &Olhs.arr, &Orhs.arr )
      res = mdarr2_t.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_OR_to( &Olhs.arr, &Rrhs.arr, &Ores.arr )
    else:
      cOres = mdarr2_sub_OR( &Olhs.arr, &Rrhs.arr )
      res = mdarr2_t.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_Or_to( &Olhs.arr, rrhs, &Ores.arr )
    else:
      cOres = mdarr2_sub_Or( &Olhs.arr, rrhs )
      res = mdarr2_t.create( &cOres )
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

  

  # Scalar types:
  cdef mdnum2_t    orhs, ores
  cdef mdnum2_t cores

  cdef femdnum2_t     frhs, fres
  cdef femdnum2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdarr2_t      Orhs, Ores
  cdef mdarr2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef femdarr2_t    Frhs, Fres
  cdef femdarr2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == femdarr2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_RF( &Rlhs.arr, &Frhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == mdarr2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr2_sub_RO( &Rlhs.arr, &Orhs.arr )
      res = mdarr2_t.create( &cOres )
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
cdef object __sub__oX__(mdnum2_t olhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between mdnum2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum2_t    orhs, ores
  cdef mdnum2_t cores

  cdef femdnum2_t     frhs, fres
  cdef femdnum2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdarr2_t      Orhs, Ores
  cdef mdarr2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef femdarr2_t    Frhs, Fres
  cdef femdarr2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum2_t:
    orhs = rhs
    if res_flag:
      ores = out
      mdnum2_sub_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = mdnum2_sub_oo( &olhs.num, &orhs.num )
      res = mdnum2_t.create( &cores )
    # end if
  elif trhs == femdnum2_t:
    frhs = rhs
    if res_flag:
      fres = out
      femdnum2_sub_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = femdnum2_sub_of( &olhs.num, &frhs.num )
      res = femdnum2_t.create( &cfres )
    # end if
  elif trhs == femdarr2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_oF( &olhs.num, &Frhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == mdarr2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr2_sub_oO( &olhs.num, &Orhs.arr )
      res = mdarr2_t.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      mdnum2_sub_or_to( &olhs.num, rrhs, &ores.num )
    else:
      cores = mdnum2_sub_or( &olhs.num, rrhs )
      res = mdnum2_t.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __sub__fX__(femdnum2_t flhs, object rhs, object out = None):
  """
  PORPUSE: Subtraction between femdnum2_t and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef mdnum2_t    orhs, ores
  cdef mdnum2_t cores

  cdef femdnum2_t     frhs, fres
  cdef femdnum2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdarr2_t      Orhs, Ores
  cdef mdarr2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef femdarr2_t    Frhs, Fres
  cdef femdarr2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum2_t:
    orhs = rhs
    if res_flag:
      fres = out
      femdnum2_sub_fo_to( &flhs.num, &orhs.num, &fres.num )
    else:
      cfres = femdnum2_sub_fo( &flhs.num, &orhs.num )
      res = femdnum2_t.create( &cfres )
    # end if
  elif trhs == femdnum2_t:
    frhs = rhs
    if res_flag:
      fres = out
      femdnum2_sub_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = femdnum2_sub_ff( &flhs.num, &frhs.num )
      res = femdnum2_t.create( &cfres )
    # end if
  elif trhs == femdarr2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_fF( &flhs.num, &Frhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      femdnum2_sub_fr_to( &flhs.num, rrhs, &fres.num )
    else:
      cfres = femdnum2_sub_fr( &flhs.num, rrhs )
      res = femdnum2_t.create( &cfres )
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
  cdef mdnum2_t    orhs, ores
  cdef mdnum2_t cores

  cdef femdnum2_t     frhs, fres
  cdef femdnum2_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef mdarr2_t      Orhs, Ores
  cdef mdarr2_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef femdarr2_t    Frhs, Fres
  cdef femdarr2_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == mdnum2_t:
    orhs = rhs
    if res_flag:
      ores = out
      mdnum2_sub_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = mdnum2_sub_ro( rlhs, &orhs.num )
      res = mdnum2_t.create( &cores )
    # end if
  elif trhs == femdnum2_t:
    frhs = rhs
    if res_flag:
      fres = out
      femdnum2_sub_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = femdnum2_sub_rf( rlhs, &frhs.num )
      res = femdnum2_t.create( &cfres )
    # end if
  elif trhs == femdarr2_t:
    Frhs = rhs
    if res_flag:
      Fres = out
      femdarr2_sub_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = femdarr2_sub_rF( rlhs, &Frhs.arr )
      res = femdarr2_t.create( &cFres )
    # end if
  elif trhs == mdarr2_t:
    Orhs = rhs
    if res_flag:
      Ores = out
      mdarr2_sub_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = mdarr2_sub_rO( rlhs, &Orhs.arr )
      res = mdarr2_t.create( &cOres )
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

