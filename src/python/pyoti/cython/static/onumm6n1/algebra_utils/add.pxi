#*****************************************************************************************************
cdef object __add__FX__(feomatm6n1 Flhs, object rhs, object out = None):
  """
  PORPUSE: Addition between feomatm6n1 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm6n1    orhs, ores
  cdef onumm6n1_t cores

  cdef feonumm6n1     frhs, fres
  cdef feonumm6n1_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef omatm6n1      Orhs, Ores
  cdef oarrm6n1_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feomatm6n1    Frhs, Fres
  cdef feoarrm6n1_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm6n1:
    orhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_oF_to( &orhs.num, &Flhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_oF( &orhs.num, &Flhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == feonumm6n1:
    frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_fF_to( &frhs.num, &Flhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_fF( &frhs.num, &Flhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == feomatm6n1:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_FF( &Flhs.arr, &Frhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == omatm6n1:
    Orhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_OF( &Orhs.arr, &Flhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_RF( &Rrhs.arr, &Flhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_rF_to( rrhs, &Flhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_rF( rrhs, &Flhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__OX__(omatm6n1 Olhs, object rhs, object out = None):
  """
  PORPUSE: Addition between omatm6n1 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm6n1    orhs, ores
  cdef onumm6n1_t cores

  cdef feonumm6n1     frhs, fres
  cdef feonumm6n1_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef omatm6n1      Orhs, Ores
  cdef oarrm6n1_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feomatm6n1    Frhs, Fres
  cdef feoarrm6n1_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm6n1:
    orhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_oO_to( &orhs.num, &Olhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_oO( &orhs.num, &Olhs.arr )
      res = omatm6n1.create( &cOres )
    # end if
  elif trhs == feomatm6n1:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_OF_to( &Olhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_OF( &Olhs.arr, &Frhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == omatm6n1:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_OO_to( &Olhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_OO( &Olhs.arr, &Orhs.arr )
      res = omatm6n1.create( &cOres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_RO_to( &Rrhs.arr, &Olhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_RO( &Rrhs.arr, &Olhs.arr )
      res = omatm6n1.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_rO_to( rrhs, &Olhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_rO( rrhs, &Olhs.arr )
      res = omatm6n1.create( &cOres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(Olhs),trhs))
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
  cdef onumm6n1    orhs, ores
  cdef onumm6n1_t cores

  cdef feonumm6n1     frhs, fres
  cdef feonumm6n1_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef omatm6n1      Orhs, Ores
  cdef oarrm6n1_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feomatm6n1    Frhs, Fres
  cdef feoarrm6n1_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == feomatm6n1:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_RF_to( &Rlhs.arr, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_RF( &Rlhs.arr, &Frhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == omatm6n1:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_RO_to( &Rlhs.arr, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_RO( &Rlhs.arr, &Orhs.arr )
      res = omatm6n1.create( &cOres )
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
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__oX__(onumm6n1 olhs, object rhs, object out = None):
  """
  PORPUSE: Addition between onumm6n1 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm6n1    orhs, ores
  cdef onumm6n1_t cores

  cdef feonumm6n1     frhs, fres
  cdef feonumm6n1_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef omatm6n1      Orhs, Ores
  cdef oarrm6n1_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feomatm6n1    Frhs, Fres
  cdef feoarrm6n1_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm6n1:
    orhs = rhs
    if res_flag:
      ores = out
      onumm6n1_sum_oo_to( &olhs.num, &orhs.num, &ores.num )
    else:
      cores = onumm6n1_sum_oo( &olhs.num, &orhs.num )
      res = onumm6n1.create( &cores )
    # end if
  elif trhs == feonumm6n1:
    frhs = rhs
    if res_flag:
      fres = out
      feonumm6n1_sum_of_to( &olhs.num, &frhs.num, &fres.num )
    else:
      cfres = feonumm6n1_sum_of( &olhs.num, &frhs.num )
      res = feonumm6n1.create( &cfres )
    # end if
  elif trhs == feomatm6n1:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_oF_to( &olhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_oF( &olhs.num, &Frhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == omatm6n1:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_oO_to( &olhs.num, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_oO( &olhs.num, &Orhs.arr )
      res = omatm6n1.create( &cOres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      ores = out
      onumm6n1_sum_ro_to( rrhs, &olhs.num, &ores.num )
    else:
      cores = onumm6n1_sum_ro( rrhs, &olhs.num )
      res = onumm6n1.create( &cores )
    # end if
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__fX__(feonumm6n1 flhs, object rhs, object out = None):
  """
  PORPUSE: Addition between feonumm6n1 and object.

  """
  #***************************************************************************************************

  

  # Scalar types:
  cdef onumm6n1    orhs, ores
  cdef onumm6n1_t cores

  cdef feonumm6n1     frhs, fres
  cdef feonumm6n1_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef omatm6n1      Orhs, Ores
  cdef oarrm6n1_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feomatm6n1    Frhs, Fres
  cdef feoarrm6n1_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm6n1:
    orhs = rhs
    if res_flag:
      fres = out
      feonumm6n1_sum_of_to( &orhs.num, &flhs.num, &fres.num )
    else:
      cfres = feonumm6n1_sum_of( &orhs.num, &flhs.num )
      res = feonumm6n1.create( &cfres )
    # end if
  elif trhs == feonumm6n1:
    frhs = rhs
    if res_flag:
      fres = out
      feonumm6n1_sum_ff_to( &flhs.num, &frhs.num, &fres.num )
    else:
      cfres = feonumm6n1_sum_ff( &flhs.num, &frhs.num )
      res = feonumm6n1.create( &cfres )
    # end if
  elif trhs == feomatm6n1:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_fF_to( &flhs.num, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_fF( &flhs.num, &Frhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      fres = out
      feonumm6n1_sum_rf_to( rrhs, &flhs.num, &fres.num )
    else:
      cfres = feonumm6n1_sum_rf( rrhs, &flhs.num )
      res = feonumm6n1.create( &cfres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(flhs),trhs))
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
  cdef onumm6n1    orhs, ores
  cdef onumm6n1_t cores

  cdef feonumm6n1     frhs, fres
  cdef feonumm6n1_t  cfres

  cdef coeff_t    rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef omatm6n1      Orhs, Ores
  cdef oarrm6n1_t   cOres

  cdef dmat       Rrhs, Rres
  cdef darr_t    cRres

  cdef feomatm6n1    Frhs, Fres
  cdef feoarrm6n1_t cFres

  cdef uint8_t res_flag = 1
  cdef object  res = None

  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if

  if trhs == onumm6n1:
    orhs = rhs
    if res_flag:
      ores = out
      onumm6n1_sum_ro_to( rlhs, &orhs.num, &ores.num )
    else:
      cores = onumm6n1_sum_ro( rlhs, &orhs.num )
      res = onumm6n1.create( &cores )
    # end if
  elif trhs == feonumm6n1:
    frhs = rhs
    if res_flag:
      fres = out
      feonumm6n1_sum_rf_to( rlhs, &frhs.num, &fres.num )
    else:
      cfres = feonumm6n1_sum_rf( rlhs, &frhs.num )
      res = feonumm6n1.create( &cfres )
    # end if
  elif trhs == feomatm6n1:
    Frhs = rhs
    if res_flag:
      Fres = out
      feoarrm6n1_sum_rF_to( rlhs, &Frhs.arr, &Fres.arr )
    else:
      cFres = feoarrm6n1_sum_rF( rlhs, &Frhs.arr )
      res = feomatm6n1.create( &cFres )
    # end if
  elif trhs == omatm6n1:
    Orhs = rhs
    if res_flag:
      Ores = out
      oarrm6n1_sum_rO_to( rlhs, &Orhs.arr, &Ores.arr )
    else:
      cOres = oarrm6n1_sum_rO( rlhs, &Orhs.arr )
      res = omatm6n1.create( &cOres )
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
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------

