
# ARRAY
#*****************************************************************************************************
cdef object __add__FX__(matsofe Flhs, object rhs, object out = None):
  """
  PORPUSE: Addition between matsofe and object.

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
      fearrso_sum_oF_to( &orhs.num, &Flhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sum_oF( &orhs.num, &Flhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == sotife:
    frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_fF_to( &frhs.num, &Flhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sum_fF( &frhs.num, &Flhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matsofe:
    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_FF_to( &Flhs.arr, &Frhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sum_FF( &Flhs.arr, &Frhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == matso:
    Orhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sum_OF( &Orhs.arr, &Flhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs == dmat:
    Rrhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sum_RF( &Rrhs.arr, &Flhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  elif trhs in number_types:
    rrhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_rF_to( rrhs, &Flhs.arr, &Fres.arr, dhl )
    else:
      cFres = fearrso_sum_rF( rrhs, &Flhs.arr, dhl )
      res = matsofe.create( &cFres )
    # end if
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(Flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if

#-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef object __add__FX__(matsofe Flhs, object rhs, object out = None):
#   """
#   PURPOSE:  Addition between matsofe and object.

#   """
#   #***************************************************************************************************

#   global dhl

#   # Scalar types
#   cdef sotinum    orhs, ores
#   cdef sotinum_t cores

#   cdef sotife     frhs, fres
#   cdef fesoti_t  cfres

#   cdef coeff_t    rrhs, rres
#   cdef coeff_t   crres

#   # Array types
#   cdef matso      Orhs, Ores
#   cdef arrso_t   cOres

#   cdef dmat       Rrhs, Rres
#   cdef darr_t    cRres

#   cdef matsofe    Frhs, Fres
#   cdef fearrso_t cFres

#   cdef uint8_t res_flag = 1
#   cdef object  res = None

#   trhs = type(rhs)

#   if out is None:
#     res_flag = 0
#   # end if 

#   if   trhs == sotinum:

#     orhs = rhs
#     if res_flag:
#       Fres = out
#       fearrso_sum_oF_to( &orhs.num, &Flhs.arr ,&Fres.arr, dhl)
#     else:
#       cFres = fearrso_sum_oF( &orhs.num, &Flhs.arr , dhl)
#       res = matsofe.create(&cFres)
#     # end if

#   elif trhs == sotife:

#     frhs = rhs
#     if res_flag:
#       Fres = out
#       fearrso_sum_fF_to( &frhs.num, &Flhs.arr, &Fres.arr, dhl)
#     else:      
#       cFres = fearrso_sum_fF( &frhs.num, &Flhs.arr, dhl)
#       res = matsofe.create(&cFres)
#     # end if

#   elif trhs == matso:

#     Orhs = rhs
#     if res_flag:
#       Fres = out
#       fearrso_sum_OF_to( &Orhs.arr, &Flhs.arr, &Fres.arr, dhl)
#     else:      
#       cFres = fearrso_sum_OF( &Orhs.arr, &Flhs.arr, dhl)
#       res = matsofe.create( &cFres )
#     # end if

#   elif trhs == matsofe:

#     Frhs = rhs
#     if res_flag:
#       Fres = out
#       fearrso_sum_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr, dhl)
#     else:      
#       cFres = fearrso_sum_FF( &Flhs.arr, &Frhs.arr, dhl)
#       res = matsofe.create(&cFres)
#     # end if

#   elif trhs == dmat:

#     Rrhs = rhs
#     if res_flag:
#       Fres = out
#       fearrso_sum_RF_to( &Rrhs.arr, &Flhs.arr, &Fres.arr, dhl)
#     else:      
#       cFres = fearrso_sum_RF( &Rrhs.arr, &Flhs.arr, dhl)
#       res = matsofe.create(&cFres)
#     # end if

#   elif trhs in number_types:

#     rrhs = rhs
#     if res_flag:
#       Fres = out
#       fearrso_sum_rF_to( rrhs, &Flhs.arr, &Fres.arr, dhl)
#     else:
#       cFres = fearrso_sum_rF( rrhs, &Flhs.arr, dhl)
#       res = matsofe.create(&cFres)
#     # end if

#   else:
#     raise TypeError("Unsupported add operation between {0} and {1}.".format(type(Flhs),trhs))
#   # end if

#   if res_flag == 0:
#     return res
#   # end if 

# #-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef object __add__OX__(matso Olhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between matso and an object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types
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
  cdef object res = None

  trhs = type(rhs)

  if out is None:

    res_flag = 0

  # end if 

  if   trhs == sotinum:

    orhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_oO_to( &orhs.num, &Olhs.arr ,&Ores.arr, dhl)
    else:
      cOres = arrso_sum_oO( &orhs.num, &Olhs.arr , dhl)
      res = matso.create(&cOres)
    # end if

  # elif trhs == sotife:

  #   Orhs = rhs
  #   if res_flag:
  #     Fres = out
  #     fesoti_sum_Of_to( &Orhs.arr, &flhs.num ,&Fres.arr, dhl)
  #   else:      
  #     cFres = fesoti_sum_Of( &Orhs.arr, &flhs.num, dhl)
  #     res = matsofe.create(&cFres)
  #   # end if

  elif trhs == matso:

    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_OO_to( &Olhs.arr, &Orhs.arr ,&Ores.arr, dhl)
    else:      
      cOres = arrso_sum_OO( &Orhs.arr, &Orhs.arr, dhl)
      res = matso.create( &cOres )
    # end if

  elif trhs == dmat:

    Rrhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_RO_to( &Rrhs.arr, &Olhs.arr ,&Ores.arr, dhl)
    else:      
      cOres = arrso_sum_RO( &Rrhs.arr, &Olhs.arr, dhl)
      res = matso.create(&cOres)
    # end if

  elif trhs == matsofe:

    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr, dhl)
    else:      
      cFres = fearrso_sum_OF( &Olhs.arr, &Frhs.arr, dhl)
      res = matsofe.create(&cFres)
    # end if

  elif trhs in number_types:

    rrhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_rO_to( rrhs, &Olhs.arr, &Ores.arr, dhl)
    else:
      cOres = arrso_sum_rO( rrhs, &Olhs.arr, dhl)
      res = matso.create(&cOres)
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
  PURPOSE:  Addition between sotinum and an object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types
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
  cdef object res = None

  trhs = type(rhs)

  if out is None:

    res_flag = 0

  # end if 

  # if   trhs == sotinum:

  #   orhs = rhs
  #   if res_flag:
  #     ores = out
  #     soti_sum_Ro_to( &Rlhs.arr, &orhs.num ,&ores.num, dhl)
  #   else:
  #     cores = soti_sum_Ro( &Rlhs.arr, &orhs.num , dhl)
  #     res = sotinum.create(&cores)
  #   # end if

  # elif trhs == sotife:

  #   frhs = rhs
  #   if res_flag:
  #     fres = out
  #     fesoti_sum_Rf_to( &Rlhs.arr, &frhs.num ,&fres.num, dhl)
  #   else:      
  #     cfres = fesoti_sum_Rf( &Rlhs.arr, &frhs.num, dhl)
  #     res = sotife.create(&cfres)
    # end if

  if trhs == matso:

    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_RO_to( &Rlhs.arr, &Orhs.arr ,&Ores.arr, dhl)
    else:      
      cOres = arrso_sum_RO( &Rlhs.arr, &Orhs.arr, dhl)
      res = matso.create(&cOres)
    # end if

  elif trhs == matsofe:

    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr, dhl)
    else:      
      cFres = fearrso_sum_RF( &Rlhs.arr, &Frhs.arr, dhl)
      res = matsofe.create(&cFres)
    # end if

  elif trhs == dmat:

    Rrhs = rhs
    if res_flag:
      Rres = out
      darr_sum_RR_to( &Rlhs.arr, &Rrhs.arr ,&Rres.arr)
    else:      
      cRres = darr_sum_RR( &Rlhs.arr, &Rrhs.arr)
      res = dmat.create(&cRres)
    # end if

  elif trhs in number_types:

    rrhs = rhs
    if res_flag:
      Rres = out
      darr_sum_rR_to( rrhs, &Rlhs.arr, &Rres.arr)
    else:      
      cRres = darr_sum_rR( rrhs, &Rlhs.arr)
      res = dmat.create(&cRres)
    # end if
    
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(Rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------












#    SCALAR


#*****************************************************************************************************
cdef object __add__fX__(sotife flhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between sotife and an object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types
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
  cdef object res = None

  trhs = type(rhs)

  if out is None:

    res_flag = 0

  # end if 

  if   trhs == sotinum:

    orhs = rhs
    if res_flag:
      fres = out
      fesoti_sum_of_to( &orhs.num, &flhs.num ,&fres.num, dhl)
    else:
      cfres = fesoti_sum_of( &orhs.num, &flhs.num , dhl)
      res = sotife.create(&cfres)
    # end if

  elif trhs == sotife:

    frhs = rhs
    if res_flag:
      fres = out
      fesoti_sum_ff_to( &flhs.num, &frhs.num ,&fres.num, dhl)
    else:      
      cfres = fesoti_sum_ff( &flhs.num, &frhs.num, dhl)
      res = sotife.create(&cfres)
    # end if

  # elif trhs == matso:

  #   Orhs = rhs
  #   if res_flag:
  #     Fres = out
  #     fesoti_sum_Of_to( &Orhs.arr, &flhs.num ,&Fres.arr, dhl)
  #   else:      
  #     cFres = fesoti_sum_Of( &Orhs.arr, &flhs.num, dhl)
  #     res = matsofe.create(&cFres)
  #   # end if

  # elif trhs == dmat:

  #   Rrhs = rhs
  #   if res_flag:
  #     Rres = out
  #     fesoti_sum_Rf_to( &Rrhs.arr, &flhs.num ,&Fres.arr, dhl)
  #   else:      
  #     cFres = fesoti_sum_Rf( &Rrhs.arr, &flhs.num, dhl)
  #     res = matsofe.create(&cFres)
  #   # end if

  elif trhs == matsofe:

    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_fF_to( &flhs.num, &Frhs.arr ,&Fres.arr, dhl)
    else:      
      cFres = fearrso_sum_fF( &flhs.num, &Frhs.arr, dhl)
      res = matsofe.create(&cFres)
    # end if

  elif trhs in number_types:

    rrhs = rhs
    if res_flag:
      fres = out
      fesoti_sum_rf_to( rrhs, &flhs.num, &fres.num, dhl)
    else:
      cfres = fesoti_sum_rf( rrhs, &flhs.num, dhl)
      res = sotinum.create(&cores)
    # end if

  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(flhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------










#*****************************************************************************************************
cdef object __add__oX__(sotinum olhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between sotinum and an object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types
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
  cdef object res = None

  trhs = type(rhs)

  if out is None:

    res_flag = 0

  # end if 

  if   trhs == sotinum:

    orhs = rhs
    if res_flag:
      ores = out
      soti_sum_oo_to( &olhs.num, &orhs.num ,&ores.num, dhl)
    else:
      cores = soti_sum_oo( &olhs.num, &orhs.num , dhl)
      res = sotinum.create(&cores)
    # end if

  elif trhs == sotife:

    frhs = rhs
    if res_flag:
      fres = out
      fesoti_sum_of_to( &olhs.num, &frhs.num ,&fres.num, dhl)
    else:      
      cfres = fesoti_sum_of( &olhs.num, &frhs.num, dhl)
      res = sotife.create(&cfres)
    # end if

  elif trhs == matso:

    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_oO_to( &olhs.num, &Orhs.arr ,&Ores.arr, dhl)
    else:      
      cOres = arrso_sum_oO( &olhs.num, &Orhs.arr, dhl)
      res = matso.create(&cOres)
    # end if

  elif trhs == matsofe:

    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_oF_to( &olhs.num, &Frhs.arr ,&Fres.arr, dhl)
    else:      
      cFres = fearrso_sum_oF( &olhs.num, &Frhs.arr, dhl)
      res = matsofe.create(&cFres)
    # end if

  # elif trhs == dmat:

  #   Rrhs = rhs
  #   if res_flag:
  #     Ores = out
  #     soti_sum_oR_to( &olhs.num, &Rrhs.arr ,&Ores.arr, dhl)
  #   else:      
  #     cOres = soti_sum_oR( &olhs.num, &Rrhs.arr, dhl)
  #     res = matso.create(&cOres)
  #   # end if

  elif trhs in number_types:

    rrhs = rhs
    if res_flag:
      ores = out
      soti_sum_ro_to( rrhs, &olhs.num, &ores.num, dhl)
    else:
      cores = soti_sum_ro( rrhs, &olhs.num, dhl)
      res = sotinum.create(&cores)
    # end if

  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(olhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __add__rX__(coeff_t rlhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between sotinum and an object.

  """
  #***************************************************************************************************

  global dhl

  # Scalar types
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
  cdef object res = None

  trhs = type(rhs)

  if out is None:

    res_flag = 0

  # end if 

  if   trhs == sotinum:

    orhs = rhs
    if res_flag:
      ores = out
      soti_sum_ro_to( rlhs, &orhs.num ,&ores.num, dhl)
    else:
      cores = soti_sum_ro( rlhs, &orhs.num , dhl)
      res = sotinum.create(&cores)
    # end if

  elif trhs == sotife:

    frhs = rhs
    if res_flag:
      fres = out
      fesoti_sum_rf_to( rlhs, &frhs.num ,&fres.num, dhl)
    else:      
      cfres = fesoti_sum_rf( rlhs, &frhs.num, dhl)
      res = sotife.create(&cfres)
    # end if

  elif trhs == matso:

    Orhs = rhs
    if res_flag:
      Ores = out
      arrso_sum_rO_to( rlhs, &Orhs.arr ,&Ores.arr, dhl)
    else:      
      cOres = arrso_sum_rO( rlhs, &Orhs.arr, dhl)
      res = matso.create(&cOres)
    # end if

  elif trhs == matsofe:

    Frhs = rhs
    if res_flag:
      Fres = out
      fearrso_sum_rF_to( rlhs, &Frhs.arr ,&Fres.arr, dhl)
    else:      
      cFres = fearrso_sum_rF( rlhs, &Frhs.arr, dhl)
      res = matsofe.create(&cFres)
    # end if

  elif trhs in number_types:

    rrhs = rhs
    res  = rlhs + rrhs
    
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(type(rlhs),trhs))
  # end if

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------
