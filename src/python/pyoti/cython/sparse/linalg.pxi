
include "algebra_utils/dot_product.pxi"
include "algebra_utils/interp1d.pxi"
# include "algebra_utils/cross_product.pxi"

#*****************************************************************************************************
cpdef interp1d(object x, matso xvals, matso yvals, object out = None):
  """
  PURPOSE:  Linear 1D interpolation.

  INPUTS:
    - x
    - xvals: Values of x for interpolation. THis array must come in ascending order with no 
             repetitions. Must be matso array
    - yvals: Values of y for the interpolation. Must be matso array.
    - out (optional, default=None): Output object to hold the interpolation result.
  """
  #***************************************************************************************************
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tx = type(x)

  _check_elementwise("interp1d", xvals, yvals)
  _check_out_shape("interp1d", out, _array_shape(x))
  _check_nip("interp1d", x, out)

  if out is None:
    res_flag = 0
  # end if 

  # supported types for xvals, yvals:
  #    - matso
  # supported types for val:
  #    - sotinum
  #    - sotife
  # Supported output types:
  #    - sotinum
  #    - sotife

  if   tx is sotinum:

    res = __interp1d_OOo( xvals, yvals, x, out = out)

  elif tx is sotife:

    res = __interp1d_OOf( xvals, yvals, x, out = out)

  elif tx is matso:

    res = __interp1d_OOO( xvals, yvals, x, out = out)

  else:

    raise TypeError("Unsupported type {0} in inter1d operation.".format(tx))

  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef moving_average(matso data, int size):
  """
  PURPOSE:  Perform a moving average filter in a 1-D vector by a given window size.
  
  INPUTS:
    - data: (matso array). Filter is performed in the flattened version of the array.
    - size: Integer that defines the window size.

  """
  #***************************************************************************************************
  cdef matso new_data
  cdef int npts
  cdef double factor
  cdef sotinum value
  cdef int k, j, startj, endj, starti, lefti, righti
  cdef int miss_strtj, miss_endj
  
  factor = 1.0/float(size)
  npts = data.size
  new_data = zeros(npts)

  starti = size//2 # mid point
  lefti = size - starti - 1
  righti = size-lefti
  
  for k in range(npts):

    startj = max(0,k-lefti)
    endj   = min(npts,k+righti)

    nmisstrtj = -min(0,k-lefti)
    nmisendj  =  max(npts,k+righti)-npts
    
    value = zero()

    if (nmisstrtj>0):

      value  = factor * ( data[ startj, 0 ] * nmisstrtj )

    # end if 

    if (nmisendj>0):

      j = endj-1
      value  = value + factor * ( data[      j, 0 ] * nmisendj )

    # end if 

    for j in range(startj,endj):
      value += data[j,0]*factor
    # end for 

    new_data[k,0] = value

  # end for
  return new_data

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dot_product(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product (For matrices, sum product).

  """
  #***************************************************************************************************
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)

  _check_same_size("dot_product", lhs, rhs, out)
  _check_out_shape("dot_product", out, None)

  if out is None:
    res_flag = 0
  # end if 

  # supported types for lhs and rhs:
  #    -  matso
  #    -  matsofe
  #    -  darr
  # Supported output types:
  #    - sotinum
  #    - sotife

  if   tlhs is matsofe:

    res = __dot_product_FX( lhs, rhs, out = out)

  elif tlhs is matso:

    res = __dot_product_OX( lhs, rhs, out = out)

  elif tlhs is dmat:
    
    res = __dot_product_RX( lhs, rhs, out = out)

  else:

    raise TypeError("Unsupported types {0}, {1} at dot_product operation.".format(tlhs,type(rhs)))

  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef cross_product(object lhs, object rhs, object out = None):
#   """
#   PURPOSE:  Vector cross product (only allows size-3 vectors).

#   """
#   #***************************************************************************************************
  
#   cdef uint8_t res_flag = 1
#   cdef object res = None

#   tlhs = type(lhs)

#   if out is None:
#     res_flag = 0
#   # end if 

#   # supported types for lhs and rhs:
#   #    -  matso
#   #    -  matsofe
#   #    -  darr
#   # Supported output types:
#   #    - sotinum
#   #    - sotife

#   if   tlhs is matsofe:

#     res = __cross_product_FX( lhs, rhs, out = out)

#   elif tlhs is matso:

#     res = __cross_product_OX( lhs, rhs, out = out)

#   elif tlhs is dmat:
    
#     res = __cross_product_RX( lhs, rhs, out = out)

#   else:

#     raise TypeError("Unsupported types {0}, {1} at Cross_product operation.".format(tlhs,type(rhs)))

#   # end if 

#   if res_flag == 0:
#     return res
#   # end if 

# #-----------------------------------------------------------------------------------------------------













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

  cdef csr_matrix  Slhs

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  _check_matmul("dot", lhs, rhs, out)

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

    elif trhs is dmat:    # FR

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

    elif trhs is dmat:    # OR
    
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

  elif tlhs is csr_matrix:

    # Slhs = lhs
    if   trhs is matso: # SO
      if res_flag:
        Ores = out
        csrmatrix_matmul_SO_to( lhs, rhs, Ores)
      else:
        res = csrmatrix_matmul_SO( lhs, rhs)
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

    elif trhs is dmat:    # RR
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

  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef trunc_dot(ord_t ordlhs, object lhs, ord_t ordrhs, object rhs, object out = None):
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

  cdef csr_matrix  Slhs

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  _check_matmul("trunc_dot", lhs, rhs, out)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if tlhs is csr_matrix:

    # Slhs = lhs
    if   trhs is matso: # SO
      if res_flag:
        Ores = out
        csrmatrix_trunc_matmul_SO_to( ordlhs, lhs, ordrhs, rhs, Ores)
      else:
        res = csrmatrix_trunc_matmul_SO( ordlhs, lhs, ordrhs, rhs)
      # end if 

    else:
      raise TypeError("Unsupported types at dot operation.")      
    # end if 
  else:
    raise TypeError("Unsupported types at dot operation.")

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

  shape = _array_shape(arr)

  if shape is not None:
    _check_out_shape("transpose", out, (shape[1], shape[0]))
  # end if

  _check_nip("transpose", arr, out)

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
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object _raise_linalg_status(str op, int status):
  """
  PURPOSE:  Raise the Python exception that matches a status of the C linear algebra functions
            (oti/sparse/array/algebra_lu.h). Status 0 (success) returns None.
  """
  #***************************************************************************************************

  if status == 0:
    return None
  elif status > 0:
    if op == "det":
      raise np.linalg.LinAlgError(
        "det: the real part of the matrix is singular. The determinant of an OTI matrix larger "
        "than {0}x{0} with a singular real part is not supported yet (known limitation)."
        .format(_OTI_LINALG_CLOSED_FORM_MAX))
    # end if
    # The closed forms (n <= 3) report 1 without a pivot position, so the row is not reported.
    raise np.linalg.LinAlgError("{0}: the real part of the matrix is singular.".format(op))
  elif status == OTI_LINALG_ERR_SIZE:
    raise ValueError("{0}: the matrix is too large for the 32-bit LAPACK interface.".format(op))
  elif status == OTI_LINALG_ERR_MEMORY:
    raise MemoryError("{0}: could not allocate the work buffers.".format(op))
  elif status == OTI_LINALG_ERR_PIVOT:
    raise ValueError("{0}: pivot indices out of range.".format(op))
  # end if

  raise RuntimeError("{0}: failed with status {1}.".format(op, status))

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef det(object arr, object out = None):
  """
  det(arr, out = None)

  Determinant of a square array.

  Up to 3x3 the closed forms are used. Larger OTI arrays use the LU factorization of the real part
  (LAPACK) and obtain every imaginary order by real triangular solves.

  :param arr: Square ``matso``, ``matsofe`` or ``dmat`` array.
  :param out: Optional result holder (``sotinum`` for ``matso``, ``sotife`` for ``matsofe``).

  :raises numpy.linalg.LinAlgError: an OTI array larger than 3x3 whose real part is singular (known
    limitation: the determinant exists but is not computed).
  """
  #***************************************************************************************************

  cdef matso      O
  cdef dmat       R
  cdef matsofe    F
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef sotife     fres
  cdef sotinum    ores
  cdef int       status

  cdef object res

  tarr = type(arr)

  _check_square("det", arr)
  _check_out_shape("det", out, None)
  _check_nip("det", arr, out)

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tarr is matsofe:
    
    F = arr
    if out is not None:
      fres = out
    else:
      cfres = fesoti_createEmpty_bases( F.arr.nip, 0, 0, dhl)
      fres = sotife.create(&cfres)
    # end if 
    status = fearrso_det_to( &F.arr, &fres.num, dhl)
    res = fres

  elif tarr is matso:
    
    O = arr
    if out is not None:
      ores = out
    else:
      cores = soti_init()
      ores = sotinum.create(&cores)
    # end if    
    status = arrso_det_to( &O.arr, &ores.num, dhl)
    res = ores

  elif tarr is dmat:
    
    if out is not None:
      raise TypeError("det of a real array returns a float; out= is not supported.")
    # end if

    R = arr
    return darr_det( &R.arr)

  else:
    raise TypeError("Unsupported types at det operation.")    
  # end if 

  _raise_linalg_status("det", status)

  if out is None:
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

  _check_out_shape("norm", out, None)
  _check_nip("norm", arr, out)

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
    
    if res_flag:
      raise TypeError("norm of a real array returns a float; out= is not supported.")
    # end if

    R = arr
    res = darr_pnorm( &R.arr, p)

  else:
    raise TypeError("Unsupported types at norm operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------









#*****************************************************************************************************
cpdef inv(object arr, object out = None):
  """
  inv(arr, out = None)

  Inverse of a square array.

  Up to 3x3 the closed forms are used. Larger OTI arrays are solved with A X = I on the LU factors
  of the real part (LAPACK), every imaginary order by real triangular solves.

  :param arr: Square ``matso``, ``matsofe`` or ``dmat`` array.
  :param out: Optional result holder of the same type and shape.

  :raises numpy.linalg.LinAlgError: the real part of the array is singular.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef matsofe    F, Fres
  cdef int       status

  tarr = type(arr)

  _check_square("inv", arr)
  _check_out_shape("inv", out, _array_shape(arr))
  _check_nip("inv", arr, out)

  # supported types:
  #    -  matso
  #    -  matsofe
  #    -  darr

  if   tarr is matsofe:    
    F = arr
    Fres = out if out is not None else zeros(F.shape, nip = F.arr.nip)
    status = fearrso_invert_to( &F.arr, &Fres.arr, dhl)
    _raise_linalg_status("inv", status)
    res = Fres
  elif tarr is matso:
    O = arr
    Ores = out if out is not None else zeros(O.shape)
    status = arrso_invert_to( &O.arr, &Ores.arr, dhl)
    _raise_linalg_status("inv", status)
    res = Ores
  elif tarr is dmat:    
    R = arr
    if out is not None:
      Rres = out
      darr_invert_to( &R.arr, &Rres.arr)
    else:
      cRres = darr_invert( &R.arr)
      res = dmat.create(&cRres)
    # end if 
  else:
    raise TypeError("Unsupported types at inverse operation.")    
  # end if 

  if out is None:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef inv_block(object arr, object out = None):
  """
  PURPOSE:   Matrix inverse using block solver.
  """
  #***************************************************************************************************

  cdef matso      O, Ores, tmp
  cdef arrso_t   cOres
  cdef csr_matrix  S, Sres
  # cdef dmat       R, Rres
  # cdef darr_t    cRres
  # cdef matsofe    F, Fres
  # cdef fearrso_t cFres

  cdef uint64_t i,j,k,l
  cdef ord_t ordi, ord_lhs, ord_rhs, Oord

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  _check_square("inv_block", arr)
  _check_out_shape("inv_block", out, _array_shape(arr))
  _check_nip("inv_block", arr, out)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  matso
  #    -  csr_matrix

  if   tarr is matso:    
    O = arr
    # Always work on a local array: the update below (Ores += ...) rebinds Ores, so it can not
    # write into `out` directly. The result is copied into `out` at the end.
    Ores = zeros(O.shape)

    inverse = np.linalg.inv(O.real)

    # Copy the inverse to the values of the inverse.
    for i in range(Ores.arr.nrows):
      for j in range(Ores.arr.ncols):
        k = j + i * Ores.arr.ncols
        arrso_set_item_ij_r( inverse[i,j], i, j, &Ores.arr, dhl)
      # end for
    # end for    

    Oord = O.order    
    tmp = O.copy()
    for ordi in range( 1, Oord + 1 ):
      
      tmp.set(0)

      for ord_rhs in range(ordi):

        ord_lhs = ordi - ord_rhs

        tmp -= dot( O.get_order_im(ord_lhs), Ores.get_order_im(ord_rhs))

      # end for 
      Ores += dot( Ores.get_order_im(0), tmp)
    # end for 

    if res_flag:
      out.set(Ores)
    # end if

    res = Ores
  else:
    raise TypeError("Unsupported types at Block-solver inverse operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------








#*****************************************************************************************************
cpdef solve(object K_in, matso b_in, matso out = None, solver = 'SuperLU', solver_args = {}):
  """
  u = solve(object K_in, matso b_in, matso out = None, solver = 'SuperLU', solver_args = {})
  
  Solves an OTI linear system of equations Ku = b.

  A dense ``matso`` K is solved in C: the real part is factorized once with LAPACK and every
  imaginary order follows by real solves with the same factors (block solver).

  :param K_in: Coefficient matrix. This must be a csr_matrix or matso array.

  :param b_in: right hand side vector. This must be a matso array.

  :param out: Optional result holder, same shape as b_in.

  :param solver: Optional string with the selected sparse solver, default 'SuperLU'. Only used
    when K_in is a csr_matrix (options: 'SuperLU', 'cholesky', 'spilu', 'umfpack').

  :param solver_args: Optional arguments of the sparse solver (csr_matrix only).

  :raises numpy.linalg.LinAlgError: a dense K_in whose real part is singular.
  """
  #***************************************************************************************************
  global dhl

  cdef matso      K, Ores
  cdef int       status
  cdef uint8_t res_flag = 1
  cdef object res

  tK = type(K_in)

  _check_square("solve", K_in)
  _check_matmul("solve", K_in, b_in, out)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  csr_matrix

  if   tK is matso:

    K = K_in
    Ores = out if res_flag else zeros(b_in.shape)
    status = arrso_solve_to( &K.arr, &b_in.arr, &Ores.arr, dhl)
    _raise_linalg_status("solve", status)
    res = Ores

  elif tK is csr_matrix:

    if res_flag:
      solve_sparse( K_in, b_in, out = out, solver=solver, solver_args=solver_args)
    else:      
      res = solve_sparse(K_in, b_in, out = None, solver=solver, solver_args=solver_args)
    # end if

  else:
    raise TypeError("Unsupported types at solve operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef lu_factor(matso A, matso out = None):
  """
  lu, piv = lu_factor(matso A, matso out = None)

  LU factorization with partial pivoting of an OTI array, A = P L U, as ``scipy.linalg.lu_factor``.

  Pivoting is decided by the real part (LAPACK ``dgetrf``); every imaginary order of L and U follows
  by real triangular solves, so no OTI division is performed.

  :param A: Square ``matso`` array.
  :param out: Optional ``matso`` holder for the factors, same shape as A. May be A itself.

  :return: ``(lu, piv)``. ``lu`` holds L below the diagonal (unit diagonal not stored) and U on and
    above it. ``piv`` (``int32``, 0-based): row i was interchanged with row ``piv[i]``.

  :raises numpy.linalg.LinAlgError: the real part of A is singular.

  Examples
  --------
  >>> import numpy as np, scipy.linalg
  >>> import pyoti.sparse as oti
  >>> A = oti.array([[0.0, 2.0, 1.0], [3.0, 1.0, 0.0], [1.0, 0.0, 4.0]])
  >>> A[0, 0] += oti.e(1, order=2)
  >>> lu, piv = oti.lu_factor(A)
  >>> piv
  array([1, 1, 2], dtype=int32)
  >>> np.allclose(lu.real, scipy.linalg.lu_factor(A.real)[0])   # real part as in SciPy
  True
  """
  #***************************************************************************************************
  global dhl

  cdef matso      LU
  cdef int       status
  cdef np.ndarray piv

  _check_square("lu_factor", A)
  _check_out_shape("lu_factor", out, A.shape)

  LU  = out if out is not None else zeros(A.shape)
  piv = np.empty(A.shape[0], dtype = np.int32)

  status = arrso_lu_factor_to( &A.arr, &LU.arr, <int32_t*> np.PyArray_DATA(piv), dhl)
  _raise_linalg_status("lu_factor", status)

  # LAPACK pivots are 1-based.
  piv -= 1

  return LU, piv

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef lu_solve(object lu_and_piv, matso b, matso out = None):
  """
  x = lu_solve(lu_and_piv, matso b, matso out = None)

  Solves A x = b with the factors of ``lu_factor``, as ``scipy.linalg.lu_solve``.

  :param lu_and_piv: ``(lu, piv)`` as returned by ``lu_factor``.
  :param b: Right-hand side, ``matso`` with as many rows as ``lu``.
  :param out: Optional result holder, same shape as b.

  :raises numpy.linalg.LinAlgError: a diagonal entry of the real part of U is zero.
  :raises ValueError: shapes do not match, or the pivot indices are out of range.

  Examples
  --------
  >>> import numpy as np
  >>> import pyoti.sparse as oti
  >>> A = oti.array([[0.0, 2.0, 1.0], [3.0, 1.0, 0.0], [1.0, 0.0, 4.0]])
  >>> A[0, 0] += oti.e(1, order=2)
  >>> b = oti.array([[1.0], [2.0], [3.0]])
  >>> x = oti.lu_solve(oti.lu_factor(A), b)
  >>> r = oti.dot(A, x) - b                       # residual, every order
  >>> all(np.abs(r.get_im(d)).max() < 1e-14 for d in (0, 1, [1, 1]))
  True
  """
  #***************************************************************************************************
  global dhl

  cdef matso      LU, Ores
  cdef int       status
  cdef np.ndarray ipiv

  LU, piv = lu_and_piv

  _check_square("lu_solve", LU)
  _check_matmul("lu_solve", LU, b, out)

  piv = np.asarray(piv)

  if piv.shape != (LU.shape[0],):
    raise ValueError("lu_solve: piv has shape {0}, expected ({1},).".format(piv.shape, LU.shape[0]))
  # end if

  # Validate before narrowing to int32: a cast would truncate fractions and wrap large integers.
  if not np.issubdtype(piv.dtype, np.integer):
    raise ValueError("lu_solve: piv must hold integers, got dtype {0}.".format(piv.dtype))
  # end if

  if piv.size > 0 and (piv.min() < 0 or piv.max() >= LU.shape[0]):
    raise ValueError("lu_solve: pivot indices out of range [0, {0}).".format(LU.shape[0]))
  # end if

  # 1-based pivots for LAPACK, in a fresh contiguous int32 array.
  ipiv = piv.astype(np.int32) + np.int32(1)

  Ores = out if out is not None else zeros(b.shape)

  status = arrso_lu_solve_to( &LU.arr, <int32_t*> np.PyArray_DATA(ipiv), &b.arr, &Ores.arr, dhl)
  _raise_linalg_status("lu_solve", status)

  if out is None:
    return Ores
  # end if

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef solve_sparse(csr_matrix K_in, matso b_in, matso out = None, solver = 'SuperLU', solver_args = {}):
  """
  Solve an OTI sparse linear system of equations.

  :param K_in:    csr_matrix of OTI numbers.
  
  :param b_in:    Right hand side of the equation 
  
  :param out:     Result holder. Default None (returns newly allocated array)
  
  :param solver:  Default 'SuperLU'. Other options include: 'cholesky', 'spilu' and 'umfpack'
  
  :param **kwargs Specific factorized solver.

  """
  #***************************************************************************************************
  global dhl

  cdef matso      O, Ores, Otmp, tmp, tmp2, tmp3
  cdef uint64_t i,j,k,l
  cdef ord_t ordi, ord_lhs, ord_rhs, Oord
  cdef uint8_t res_flag = 1

  if out is None:
    res_flag = 0
  # end if      
  
  if res_flag:
    Ores = out
  else:
    Ores = zeros(b_in.shape)
  # end if

  Kr_csc = K_in.real.tocsc()
  
  
  factorizer = None

  if solver == 'SuperLU' or solver == 'LU' or solver == 'lu' or solver == 'splu':
    
    from scipy.sparse.linalg import splu
    factorizer = splu
    solver_id = 1

  elif solver == 'ILU' or solver == 'ilu' or solver == 'spilu':
    
    from scipy.sparse.linalg import spilu
    factorizer = spilu
    solver_id = 1

  elif solver == 'cholesky' or solver == 'ch' or solver == 'CH':
    
    from sksparse.cholmod import cholesky
    factorizer = cholesky
    solver_id = 2

  elif solver == 'UMFPACK' or solver == 'umfpack' or solver == 'luumf':
    
    from scikits.umfpack import splu 
    factorizer = splu
    Kr_csc.indices = Kr_csc.indices.astype(np.int64)
    Kr_csc.indptr  = Kr_csc.indptr.astype(np.int64)
    solver_id = 1

  else:

    raise ValueError("Unsupported solver. Try solver = 'SuperLU', solver = 'cholesky' or solver = 'umfpack'" )

  # end if     



  # Factorize matrix. This is usually the most demanding step in the block solver approach.
  factor = factorizer(Kr_csc,**solver_args)

  del(Kr_csc) # Real matrix not needed anymore, freed to not use as much memory.

  # Get solve method.
  if solver_id == 2:
    # scikit-cholesky specific.
    solve = factor
  else:
    solve = factor.solve
  # end if 

  rhs = b_in.real
  # Solve the real system of equations:
  rhs = solve(rhs)



  # Solve the real coefficient
  for i in range(Ores.nrows):      
    for j in range(Ores.ncols):

      arrso_set_item_ij_r( rhs[i,j], i, j, &Ores.arr, dhl)

    # end for
  # end for
  
  Oord = max( K_in.order, b_in.order)
  tmp  = zeros( Ores.shape, order = Oord )
  tmp2 = zeros( Ores.shape, order = Oord )
  # print("Maximum order found -----  :",Oord)
  for ordi in range( 1, Oord + 1 ):
    #print("Block-Solver, solving :",ordi)
    #input()
    get_order_im( ordi, b_in, out=tmp )
    
    #input()
    # print("Starting for loop")
    # print("temp before:",tmp)
    for ord_rhs in range( ordi ):
      ord_lhs = ordi - ord_rhs
      # print("orders ( {0}x{1} ) :".format(ord_lhs,ord_rhs))
      
      # print(" -- before trunc_dot")
      # input()
      trunc_dot( ord_lhs, K_in, ord_rhs, Ores, out = tmp2 )
      # print(" -- trunc_dot run successfully")
      # print(" -- before trunc_sub")
      # input()
      trunc_sub(ordi, tmp, tmp2, out = tmp)
      # print(" -- trunc_sub run successfully")

    # end for 

    # print("temp after:",tmp)

    # Convert tmp to array (for specific order)
    rhs = get_order_im_array( ordi, tmp )
    # print("rhs before solution:\n",rhs)
    
    rhs = solve( rhs )
    
    # print("rhs after solution:\n",rhs)
    set_order_im_from_array( ordi, rhs, Ores)
    
  # end for 

  if res_flag == 0:

    return Ores

  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef solve_sparse_old(csr_matrix K_in, matso b_in, matso out = None, solver = 'SuperLU', solver_args = {}):
  """
  PURPOSE:   Solve an OTI sparse linear system of equations.

  INPUTS: 

        - K_in:    csr_matrix of OTI numbers.
  
        - b_in:    Right hand side of the equation 
  
        - out:     Result holder. Default None (returns newly allocated array)
  
        - solver:  Default 'SuperLU'
  
        - **kwargs Specific factorized solver.

  """
  #***************************************************************************************************
  global dhl

  cdef matso      O, Ores, Otmp
  cdef uint64_t i,j,k,l
  cdef ord_t ordi, ord_lhs, ord_rhs, Oord
  cdef uint8_t res_flag = 1

  if out is None:
    res_flag = 0
  # end if      
  
  if res_flag:
    Ores = out
  else:
    Ores = zeros(b_in.shape)
  # end if

  Kr_csc = K_in.real.tocsc()
  
  
  factorizer = None

  if solver == 'SuperLU' or solver == 'LU' or solver == 'lu' or solver == 'splu':
    
    from scipy.sparse.linalg import splu
    factorizer = splu
    solver_id = 1

  elif solver == 'ILU' or solver == 'ilu' or solver == 'spilu':
    
    from scipy.sparse.linalg import spilu
    factorizer = spilu
    solver_id = 1

  elif solver == 'cholesky' or solver == 'ch' or solver == 'CH':
    
    from sksparse.cholmod import cholesky
    factorizer = cholesky
    solver_id = 2

  elif solver == 'UMFPACK' or solver == 'umfpack' or solver == 'luumf':
    
    from scikits.umfpack import splu 
    factorizer = splu
    Kr_csc.indices = Kr_csc.indices.astype(np.int64)
    Kr_csc.indptr  = Kr_csc.indptr.astype(np.int64)
    solver_id = 1

  else:

    raise ValueError("Unsupported solver. Try solver = 'SuperLU', solver = 'cholesky' or solver = 'umfpack'" )

  # end if     



  # Factorize matrix. This is usually the most demanding step in the block solver approach.
  factor = factorizer(Kr_csc,**solver_args)

  del(Kr_csc) # Real matrix not needed anymore, freed to not use as much memory.

  # Get solve method.
  if solver_id == 2:
    # scikit-cholesky specific.
    solve = factor
  else:
    solve = factor.solve
  # end if 

  rhs = b_in.real
  # Solve the real system of equations:
  rhs = solve(rhs)


  # Solve the real coefficient
  for i in range(Ores.nrows):      
    for j in range(Ores.ncols):

      arrso_set_item_ij_r( rhs[i,j], i, j, &Ores.arr, dhl)

    # end for
  # end for
  
  Oord = max( K_in.order, b_in.order)

  for ordi in range( 1, Oord + 1 ):
    
    tmp = b_in.get_order_im( ordi )

    for ord_rhs in range( ordi ):

      ord_lhs = ordi - ord_rhs

      tmp -= dot( K_in.get_order_im( ord_lhs ), Ores.get_order_im( ord_rhs ) )

    # end for 
    
    # Convert tmp to array (for specific order)
    rhs = get_order_im_array( ordi, tmp )
    # print("RHS before:",rhs)
    rhs = solve( rhs )
    # print("RHS after:",rhs)
    set_order_im_from_array( ordi, rhs, Ores)

  # end for 

  if res_flag == 0:

    return Ores

  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef get_order_im_array(ord_t ordi, matso tmp):
  """
  PURPOSE:   Get a specific order array from a matso array.

  INPUTS:
    - ordi: Order to set the array.
    - tmp: matso array that receives the imaginary directions.

  OUTPUTS:
    Exports a numpy array of real coefficients that contains the coefficients of order ordi from tmp.
  """
  #***************************************************************************************************
  global dhl

  cdef np.ndarray res
  cdef sotinum_t otmp
  cdef bases_t* bases_list
  cdef ndir_t nnz
  cdef imdir_t maxidx = 0
  cdef uint64_t i,j,k

  for i in range(tmp.size):    
    otmp = tmp.arr.p_data[i]

    if otmp.act_order >= ordi:
      nnz = otmp.p_nnz[ordi-1]
      
      if nnz > 0:
        maxidx = max( maxidx, otmp.p_idx[ordi-1][nnz-1])
      # end if

    # end if 
  # end for

  # get maximum basis for this index:
  bases_list = dhelp_get_imdir( maxidx, ordi, dhl)

  maxidx = dhelp_ndirOrder( bases_list[ordi-1], ordi )

  res = np.zeros((tmp.nrows,tmp.ncols*maxidx), dtype = np.float64)

  for i in range(tmp.nrows):
    for j in range(tmp.ncols):

      otmp = tmp.arr.p_data[ j + i * tmp.ncols ]

      if otmp.act_order >= ordi:
        
        nnz = otmp.p_nnz[ordi-1]
        
        for k in range( nnz ):          
          res[ i, j + tmp.ncols * otmp.p_idx[ordi-1][k] ] = otmp.p_im[ordi-1][k]
        # end for

      # end if 
    # end for 
  # end for

  return res

#-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
cpdef set_order_im_from_array(ord_t ordi, np.ndarray arr, matso tmp):
  """
  PURPOSE:   Set a specific order from an array.

  INPUTS:
    - ordi: Order to set the array.
    - arr: Array to be set.
    - tmp: matso array that receives the imaginary directions.
  """
  #***************************************************************************************************
  global dhl

  cdef sotinum_t otmp
  cdef ndir_t nnz, nnz_set
  cdef coeff_t val
  cdef uint64_t i,j,k

  nnz = arr.shape[1]/tmp.ncols

  otmp = soti_get_tmp(5, ordi, dhl)

  # print("set_order_im_from_array ordi:", ordi)
  # print("settting arr.shape:", (arr.shape[0],arr.shape[1])," to tmp.shape",tmp)

  for i in range(tmp.nrows):
    
    for j in range(tmp.ncols):
      # print(' ----- position(',i,j,')')
      soti_set_r(0.0, &otmp, dhl)

      nnz_set = 0
        
      for k in range( nnz ):          
        
        val = arr[ i, j + tmp.ncols * k ] 
        
        if val != 0.0:

          otmp.p_idx[ordi-1][nnz_set]= k
          otmp.p_im[ordi-1][nnz_set] = val
          nnz_set += 1
          otmp.p_nnz[ordi-1] += 1
          otmp.act_order = ordi

        # end if

      # end for
      
      
      # soti_print(&otmp,dhl);

      tmp[i,j] = tmp[i,j] + sotinum.create( &otmp, FLAGS = 0)

    # end for 
  # end for
  # print('Exiting function')
#-----------------------------------------------------------------------------------------------------


