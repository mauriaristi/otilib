


#*****************************************************************************************************
cpdef dot(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Matrix inner product (standard matrix multiplication).
  """
  #***************************************************************************************************

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
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tlhs is matsofe:
    
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
cpdef inv(object arr, object out = None):
  """
  PURPOSE:   Matrix inverse. Only supported up to 3x3 matrices.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef arrso_t   cOres
  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef matsofe    F, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tarr is matsofe:
    
    F = arr


    if res_flag:

      Fres = out

      fearrso_invert_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_invert( &F.arr, dhl)

      res = matsofe.create(&cFres)

    # end if 

  elif tarr is matso:

    O = arr

    if res_flag:

      Ores = out

      arrso_invert_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_invert( &O.arr,  dhl)

      res = matso.create(&cOres)

    # end if    

  elif tarr is dmat:
    
    R = arr

    if res_flag:

      Rres = out

      darr_invert_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_invert( &R.arr)

      res = dmat.create(&cRres)

    # end if 

  else:

    raise TypeError("Unsupported types at inverse operation.")
    
    # return NotImplemented

  # end if 

  if res_flag == 0:

    return res

  # end if 

#-----------------------------------------------------------------------------------------------------














#*****************************************************************************************************
cpdef transpose(object arr, object out = None):
  """
  PURPOSE:  Matrix transpose
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef arrso_t   cOres
  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef matsofe    F, Fres
  cdef fearrso_t cFres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tarr is matsofe:
    
    F = arr

    if res_flag:

      Fres = out

      fearrso_transpose_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_transpose( &F.arr, dhl)

      res = matsofe.create(&cFres)

    # end if 

  elif tarr is matso:

    O = arr

    if res_flag:

      Ores = out

      arrso_transpose_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_transpose( &O.arr,  dhl)

      res = matso.create(&cOres)

    # end if    

  elif tarr is dmat:
    
    R = arr

    if res_flag:

      Rres = out

      darr_transpose_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_transpose( &R.arr)

      res = dmat.create(&cRres)

    # end if 

  else:

    raise TypeError("Unsupported types at transpose operation.")
    
    # return NotImplemented

  # end if 

  if res_flag == 0:

    return res

  # end if 

#-----------------------------------------------------------------------------------------------------














#*****************************************************************************************************
cpdef det(object arr, object out = None):
  """
  PURPOSE:  Matrix determinant.
  """
  #***************************************************************************************************

  cdef matso      O
  cdef dmat       R
  cdef matsofe    F
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef sotife     fres
  cdef sotinum    ores

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tarr is matsofe:
    
    F = arr

    if res_flag:

      fres = out
      fearrso_det_to( &F.arr, &fres.num, dhl)

    else:

      cfres = fearrso_det( &F.arr, dhl)
      res = sotife.create(&cfres)

    # end if 

  elif tarr is matso:

    O = arr

    if res_flag:
      
      ores = out
      arrso_det_to( &O.arr, &ores.num, dhl)

    else:

      cores = arrso_det( &O.arr,  dhl)
      res = sotinum.create(&cores)

    # end if    

  elif tarr is dmat:
    
    R = arr
    crres = darr_det( &R.arr)

    if res_flag:
      out = crres
    else:
      res = crres
    # end if 

  else:
    raise TypeError("Unsupported types at det operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef norm(object arr, coeff_t p = 2.0, object out = None):
  """
  PURPOSE:  Matrix norm
  """
  #***************************************************************************************************

  cdef matso      O
  cdef dmat       R
  cdef matsofe    F
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef sotife     fres
  cdef sotinum    ores

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tarr is matsofe:
    
    F = arr

    if res_flag:

      fres = out

      fearrso_pnorm_to( &F.arr, p, &fres.num, dhl)

    else:

      cfres = fearrso_pnorm( &F.arr, p, dhl)

      res = sotife.create(&cfres)

    # end if 

  elif tarr is matso:

    O = arr

    if res_flag:

      ores = out

      arrso_pnorm_to( &O.arr, p, &ores.num, dhl)

    else:

      cores = arrso_pnorm( &O.arr, p, dhl)

      res = sotinum.create(&cores)

    # end if    

  elif tarr is dmat:
    
    R = arr

    crres = darr_pnorm( &R.arr, p)

    if res_flag:

      out = crres

    else:

      res = crres

    # end if 

  else:

    raise TypeError("Unsupported types at det operation.")

  # end if 

  if res_flag == 0:

    return res

  # end if 

#-----------------------------------------------------------------------------------------------------