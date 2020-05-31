


#*****************************************************************************************************
cpdef add(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between two objects.
  """
  #***************************************************************************************************
  # Scalar types
  cdef sotinum    olhs, orhs, ores
  cdef sotinum_t cores

  cdef sotife     flhs, frhs, fres
  cdef fesoti_t  cfres

  cdef coeff_t    rlhs, rrhs, rres
  cdef coeff_t   crres

  # Array types
  cdef matso      Olhs, Orhs, Ores
  cdef arrso_t   cOres

  cdef dmat       Rlhs, Rrhs, Rres
  cdef darr_t    cRres

  cdef matsofe    Flhs, Frhs, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  sotinum
  #    -  real
  #    -  sotife
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tlhs is sotinum:
    olhs = lhs
    if   trhs is sotinum:      # oo -> o
      orhs = rhs
      if res_flag:
        ores = out
        soti_sum_oo_to( &olhs.num, &orhs.num ,&ores.num, dhl)
      else:
        cores = soti_sum_oo( &olhs.num, &orhs.num , dhl)
        res = sotinum.create(&cores)
      # end if
    elif trhs is sotife:       # of -> f
      frhs = rhs
      if res_flag:
        fres = out
        fesoti_sum_of_to( &olhs.num, &frhs.num ,&fres.num, dhl)
      else:
        cfres = fesoti_sum_of( &olhs.num, &frhs.num , dhl)
        res = sotife.create(&cfres)
      # end if
    elif trhs is matso:        # oO -> O
      Orhs = rhs
      if res_flag:
        Ores = out
        arrso_sum_oO_to( &olhs.num, &Orhs.arr ,&Ores.arr, dhl)
      else:
        cOres = arrso_sum_oO( &olhs.num, &Orhs.num , dhl)
        res = matso.create(&cOres)
      # end if
    elif trhs is matsofe:      # oF -> F
      Frhs = rhs
      if res_flag:
        Fres = out
        fearrso_sum_oF_to( &olhs.num, &Frhs.arr ,&Fres.arr, dhl)
      else:
        cFres = fearrso_sum_oF( &olhs.num, &Frhs.num , dhl)
        res = matsofe.create(&cFres)
      # end if
    # elif trhs is dmat:         # oR -> O
    #   if res_flag:
    #   else:
    #   # end if
    elif trhs in number_types: # or -> o
      rrhs = rhs
      if res_flag:
        ores = out
        soti_sum_ro_to( rrhs, &olhs.num ,&ores.num, dhl)
      else:
        cores = soti_sum_ro( rrhs, &orhs.num , dhl)
        res = sotinum.create(&cores)
      # end if
    else:
      raise TypeError("Unsupported types at add operation.")
    # end if 

  elif tlhs is sotife:
    flhs = lhs
    if   trhs is sotinum:      # fo -> f
      orhs = rhs
      if res_flag:
        fres = out
        fesoti_sum_of_to( &olhs.num, &orhs.num ,&ores.num, dhl)
      else:
        cores = soti_sum_oo( &olhs.num, &orhs.num , dhl)
        res = sotinum.create(&cores)
      # end if
    elif trhs is sotife:       # ff -> f
      frhs = rhs
      if res_flag:
        fres = out
        fesoti_sum_of_to( &olhs.num, &frhs.num ,&fres.num, dhl)
      else:
        cfres = fesoti_sum_of( &olhs.num, &frhs.num , dhl)
        res = sotife.create(&cfres)
      # end if
    elif trhs is matso:        # fO -> F
      Orhs = rhs
      if res_flag:
        Fres = out
        arrso_sum_oO_to( &olhs.num, &Orhs.arr ,&Ores.arr, dhl)
      else:
        cOres = arrso_sum_oO( &olhs.num, &Orhs.num , dhl)
        res = matso.create(&cOres)
      # end if
    elif trhs is matsofe:      # fF -> F
      Frhs = rhs
      if res_flag:
        Fres = out
        fearrso_sum_oF_to( &olhs.num, &Frhs.arr ,&Fres.arr, dhl)
      else:
        cFres = fearrso_sum_oF( &olhs.num, &Frhs.num , dhl)
        res = matsofe.create(&cFres)
      # end if
    # elif trhs is dmat:         # fR -> F
    #   if res_flag:
    #   else:
    #   # end if
    elif trhs in number_types: # fr -> f
      rrhs = rhs
      if res_flag:
        fres = out
        fesoti_sum_rf_to( rrhs, &flhs.num ,&ores.num, dhl)
      else:
        cfres = fesoti_sum_rf( rrhs, &frhs.num , dhl)
        res = sotinum.create(&cores)
      # end if
    else:
      raise TypeError("Unsupported types at add operation.")
    # end if 

  elif tlhs is matsofe:
  elif tlhs is matsofe:
  elif tlhs is matsofe:
  elif tlhs is matsofe:
    
    Flhs = lhs

    if   trhs is matsofe: # FF

      Frhs = rhs

      if res_flag:

        Fres = out

        fearrso_matmul_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr, dhl)

      else:

        cFres = fearrso_matmul_FF( &Flhs.arr, &Frhs.arr , dhl)

        res = matsofe.create(&cFres)

      # end if 

    elif trhs is matso:   # FO

      Orhs = rhs

      if res_flag:

        Fres = out

        fearrso_matmul_FO_to( &Flhs.arr, &Orhs.arr ,&Fres.arr, dhl)

      else:

        cFres = fearrso_matmul_FO( &Flhs.arr, &Orhs.arr , dhl)

        res = matsofe.create(&cFres)

      # end if 


    elif tlhs is dmat:    # FR

      Rrhs = rhs

      if res_flag:

        Fres = out

        fearrso_matmul_FR_to( &Flhs.arr, &Rrhs.arr ,&Fres.arr, dhl)

      else:

        cFres = fearrso_matmul_FR( &Flhs.arr, &Rrhs.arr , dhl)

        res = matsofe.create(&cFres)

      # end if 

    else:

      raise TypeError("Unsupported types at dot operation.")
      
    # end if 

  elif tlhs is matso:

    Olhs = lhs

    if   trhs is matsofe: # OF

      Frhs = rhs

      if res_flag:

        Fres = out

        fearrso_matmul_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr, dhl)

      else:

        cFres = fearrso_matmul_OF( &Olhs.arr, &Frhs.arr , dhl)

        res = matsofe.create(&cFres)

      # end if 

    elif trhs is matso:   # OO
    
      Orhs = rhs

      if res_flag:

        Ores = out

        arrso_matmul_OO_to( &Olhs.arr, &Orhs.arr ,&Ores.arr, dhl)

      else:

        cOres = arrso_matmul_OO( &Olhs.arr, &Orhs.arr , dhl)

        res = matso.create(&cOres)

      # end if 

    elif tlhs is dmat:    # OR
    
      Rrhs = rhs

      if res_flag:

        Ores = out

        arrso_matmul_OR_to( &Olhs.arr, &Rrhs.arr ,&Ores.arr, dhl)

      else:

        cOres = arrso_matmul_OR( &Olhs.arr, &Rrhs.arr , dhl)

        res = matso.create(&cOres)

      # end if 

    else:

      raise TypeError("Unsupported types at dot operation.")
      
    # end if    

  elif tlhs is dmat:
    
    Rlhs = lhs

    if   trhs is matsofe: # RF

      Frhs = rhs

      if res_flag:

        Fres = out

        fearrso_matmul_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr, dhl)

      else:

        cFres = fearrso_matmul_RF( &Rlhs.arr, &Frhs.arr , dhl)

        res = matsofe.create(&cFres)

      # end if 

    elif trhs is matso:   # RO

      Orhs = rhs

      if res_flag:

        Ores = out

        arrso_matmul_RO_to( &Rlhs.arr, &Orhs.arr ,&Ores.arr, dhl)

      else:

        cOres = arrso_matmul_RO( &Rlhs.arr, &Orhs.arr , dhl)

        res = matso.create(&cOres)

      # end if 

    elif tlhs is dmat:    # RR

      Rrhs = rhs

      if res_flag:

        Rres = out

        darr_matmul_to( &Rlhs.arr, &Rrhs.arr , &Rres.arr)

      else:

        cRres = darr_matmul( &Rlhs.arr, &Rrhs.arr)

        res = dmat.create(&cRres)
   
      # end if 
    
    else:

      raise TypeError("Unsupported types at dot operation.")
      
    # end if 

  else:

    raise TypeError("Unsupported types at dot operation.")
    
    # return NotImplemented

  # end if 

  if res_flag == 0:

    return res

  # end if 
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sub(object lhs, object rhs, object out = None):
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef mul(object lhs, object rhs, object out = None):
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef div(object lhs, object rhs, object out = None):
#-----------------------------------------------------------------------------------------------------


