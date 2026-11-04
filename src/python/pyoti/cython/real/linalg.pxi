
include "algebra_utils/dot_product.pxi"
# include "algebra_utils/cross_product.pxi"

#*****************************************************************************************************
cpdef dot_product(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Vector dot product (For matrices, sum product).

  """
  #***************************************************************************************************
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)

  if out is None:
    res_flag = 0
  # end if 

  # supported types for lhs and rhs:
  #    -  matso
  #    -  dmatfe
  #    -  darr
  # Supported output types:
  #    - sotinum
  #    - dnumfe

  if   tlhs is dmatfe:
    res = __dot_product_FX( lhs, rhs, out = out)
  elif tlhs is dmat:    
    res = __dot_product_RX( lhs, rhs, out = out)
  else:
    raise TypeError("Unsupported types {0}, {1} at dot_product operation.".format(tlhs,type(rhs)))
  # end if 

  if res_flag == 0:
    return res
  # end if 

  return out

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
#   #    -  dmatfe
#   #    -  darr
#   # Supported output types:
#   #    - sotinum
#   #    - dnumfe

#   if   tlhs is dmatfe:
#     res = __cross_product_FX( lhs, rhs, out = out)
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
cdef object _dmat_dot(dmat A, dmat B, object out):
  """
  PURPOSE:  dot of two dmat with NumPy's shape rules for the logical shapes (11.3, rule I3):
              - 1-D . 1-D: the inner product, a float;
              - 2-D . 1-D: (m,); 1-D . 2-D: (n,); 2-D . 2-D: (m, k);
              - a 0-D operand multiplies (numpy.dot with a scalar).
            The 2-D C struct stores a 1-D (n,) as n x 1, so a 1-D left operand is read as the 1 x n
            row over the same memory, and a (n,) result of a row product is stored n x 1.
  """
  #***************************************************************************************************

  cdef darr_t a, b, cres, o
  cdef dmat Rres
  cdef uint64_t t
  cdef uint8_t kind = 0
  cdef coeff_t x
  cdef int swap_result = 0
  cdef tuple rshape

  if A._lk == 2:

    if out is not None:

      raise ValueError("out= is not supported for the product with a 0-d matrix")

    # end if

    return (<double*>A.nd.data)[0] * B

  elif B._lk == 2:

    if out is not None:

      raise ValueError("out= is not supported for the product with a 0-d matrix")

    # end if

    return A * (<double*>B.nd.data)[0]

  # end if

  A._sync()
  B._sync()

  a = A.arr
  b = B.arr

  if A._lk == 1:

    if B._lk == 1:

      # inner product
      if a.nrows != b.nrows:

        raise ValueError("shapes {} and {} not aligned: {} (dim 0) != {} (dim 0)".format(
                         A.shape, B.shape, a.nrows, b.nrows))

      # end if

      if out is not None:

        raise ValueError("out= is not supported for the inner product of two 1-d matrices")

      # end if

      t = a.nrows
      a.nrows = 1
      a.ncols = t
      cres = darr_matmul(&a, &b)
      x = cres.p_data[0]
      darr_free(&cres)

      return x

    # end if

    # (m,) . (m, n) -> (n,): the row x B, stored n x 1
    if a.nrows != b.nrows:

      raise ValueError("shapes {} and {} not aligned: {} (dim 0) != {} (dim 0)".format(
                       A.shape, B.shape, a.nrows, b.nrows))

    # end if

    t = a.nrows
    a.nrows = 1
    a.ncols = t
    kind = 1
    swap_result = 1

  elif B._lk == 1:

    # (m, n) . (n,) -> (m,)
    if a.ncols != b.nrows:

      raise ValueError("shapes {} and {} not aligned: {} (dim 1) != {} (dim 0)".format(
                       A.shape, B.shape, a.ncols, b.nrows))

    # end if

    kind = 1

  elif a.ncols != b.nrows:

    raise ValueError("shapes {} and {} not aligned: {} (dim 1) != {} (dim 0)".format(
                     A.shape, B.shape, a.ncols, b.nrows))

  # end if

  if out is not None:

    if kind == 1:

      rshape = (b.ncols if swap_result else a.nrows,)

    else:

      rshape = (a.nrows, b.ncols)

    # end if

    Rres = _dmat_out_shape(out, rshape)
    Rres._check_out()
    o = Rres.arr

    if swap_result:

      t = o.nrows
      o.nrows = o.ncols
      o.ncols = t

    # end if

    darr_matmul_to(&a, &b, &o)

    return out

  # end if

  cres = darr_matmul(&a, &b)

  if swap_result:

    t = cres.nrows
    cres.nrows = cres.ncols
    cres.ncols = t

  # end if

  return _dmat_k(dmat.create(&cres), kind)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dot(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Matrix inner product (standard matrix multiplication).
  """
  #***************************************************************************************************

  cdef dmat       Rlhs, Rrhs, Rres
  cdef darr_t    cRres
  cdef dmatfe    Flhs, Frhs, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  dmatfe
  #    -  darr

  if   tlhs is dmatfe:
    
    Flhs = lhs
    if   trhs is dmatfe: # FF
      Frhs = rhs
      if res_flag:
        Fres = out
        fedarr_matmul_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)
      else:
        cFres = fedarr_matmul_FF( &Flhs.arr, &Frhs.arr )
        res = dmatfe.create(&cFres)
      # end if 

    elif trhs is dmat:    # FR

      Rrhs = rhs
      Rrhs._sync()
      if res_flag:
        Fres = out
        fedarr_matmul_FR_to( &Flhs.arr, &Rrhs.arr ,&Fres.arr)
      else:
        cFres = fedarr_matmul_FR( &Flhs.arr, &Rrhs.arr )
        res = dmatfe.create(&cFres)
      # end if 

    else:
      raise TypeError("Unsupported types at dot operation.")      
    # end if 

  elif tlhs is dmat:
    
    Rlhs = lhs
    Rlhs._sync()
    if   trhs is dmatfe: # RF
      Frhs = rhs
      if res_flag:
        Fres = out
        fedarr_matmul_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)
      else:
        cFres = fedarr_matmul_RF( &Rlhs.arr, &Frhs.arr )
        res = dmatfe.create(&cFres)
      # end if

    elif trhs is dmat:    # RR
      Rrhs = rhs
      res = _dmat_dot(Rlhs, Rrhs, out)
      if res_flag:
        res = None
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

  return out

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef transpose(object arr, object out = None):
  """
  PURPOSE:  Matrix transpose
  """
  #***************************************************************************************************

  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef dmatfe    F, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  matso
  #    -  dmatfe
  #    -  darr

  if   tarr is dmatfe:
    
    F = arr
    if res_flag:
      Fres = out
      fedarr_transpose_to( &F.arr, &Fres.arr)
    else:
      cFres = fedarr_transpose( &F.arr)
      res = dmatfe.create(&cFres)
    # end if 

  elif tarr is dmat:
    R = arr
    R._sync()
    if R._lk != 0:
      # transpose() of a 1-D or 0-D matrix is the matrix itself (as NumPy): a copy here, or out.
      if res_flag:
        Rres = _dmat_out(out, R)
        Rres._check_out()
        darr_copy_to( &R.arr, &Rres.arr)
      else:
        res = R.copy()
      # end if
    elif res_flag:
      Rres = _dmat_out_shape(out, (R.nd.shape[1], R.nd.shape[0]))
      Rres._check_out()
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

  return out

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef int _check_square(uint8_t lk, uint64_t nrows, uint64_t ncols) except -1:
  """
  PURPOSE:  inv / det / solve need a square matrix. The C routines answer a non-square matrix with exit():
            the shape is checked here and NumPy's text and type (numpy.linalg.LinAlgError, a ValueError
            subclass) are raised: one table for the four algebras (build-orch/w4-notes/py-ss.md).
  """
  #***************************************************************************************************

  if lk == 2:

    raise np.linalg.LinAlgError("0-dimensional array given. Array must be at least two-dimensional")

  elif lk == 1:

    raise np.linalg.LinAlgError("1-dimensional array given. Array must be at least two-dimensional")

  elif nrows != ncols:

    raise np.linalg.LinAlgError("Last 2 dimensions of the array must be square")

  # end if

  return 0

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef det(object arr, object out = None):
  """
  PURPOSE:  Matrix determinant.
  """
  #***************************************************************************************************

  cdef dmat       R
  cdef dmatfe     F
  cdef coeff_t   crres
  cdef fednum_t  cfres
  cdef dnumfe     fres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  dmatfe
  #    -  darr

  if   tarr is dmatfe:
    
    F = arr
    _check_square(0, F.arr.nrows, F.arr.ncols)
    if res_flag:
      fres = out
      fedarr_det_to( &F.arr, &fres.num)
    else:
      cfres = fedarr_det( &F.arr)
      res = dnumfe.create(&cfres)
    # end if 

  elif tarr is dmat:
    
    R = arr
    _check_square(R._lk, R.nd.shape[0], R.nd.shape[1])
    R._sync()
    crres = darr_det( &R.arr)

    if res_flag:
      raise TypeError("det: the determinant of a dmat is a float; out= is not supported.")
    # end if
    res = crres

  else:
    raise TypeError("Unsupported types at det operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef norm(object arr, coeff_t p = 2.0, object out = None):
  """
  PURPOSE:  Matrix norm
  """
  #***************************************************************************************************

  cdef dmat       R
  cdef dmatfe    F
  cdef coeff_t   crres
  cdef fednum_t  cfres
  cdef dnumfe     fres
  

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  matso
  #    -  dmatfe
  #    -  darr

  if   tarr is dmatfe:
    
    F = arr
    if res_flag:
      fres = out
      fedarr_pnorm_to( &F.arr, p, &fres.num)
    else:
      cfres = fedarr_pnorm( &F.arr, p)
      res = dnumfe.create(&cfres)
    # end if    

  elif tarr is dmat:
    
    R = arr
    R._sync()
    crres = darr_pnorm( &R.arr, p)
    if res_flag:
      raise TypeError("norm: the norm of a dmat is a float; out= is not supported.")
    # end if
    res = crres

  else:
    raise TypeError("Unsupported types at det operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------









#*****************************************************************************************************
cpdef inv(object arr, object out = None):
  """
  PURPOSE:   Matrix inverse. Only supported up to 3x3 matrices.
  """
  #***************************************************************************************************

  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef dmatfe    F, Fres
  cdef fedarr_t cFres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  dmatfe
  #    -  darr

  if   tarr is dmatfe:    
    F = arr
    _check_square(0, F.arr.nrows, F.arr.ncols)
    if res_flag:
      Fres = out
      fedarr_invert_to( &F.arr, &Fres.arr)
    else:
      cFres = fedarr_invert( &F.arr)
      res = dmatfe.create(&cFres)
    # end if 
  elif tarr is dmat:    
    R = arr
    _check_square(R._lk, R.nd.shape[0], R.nd.shape[1])
    R._sync()
    if res_flag:
      Rres = _dmat_out(out, R)
      Rres._check_out()
      darr_invert_to( &R.arr, &Rres.arr)
    else:
      cRres = darr_invert( &R.arr)
      res = dmat.create(&cRres)
    # end if 
  else:
    raise TypeError("Unsupported types at inverse operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
cpdef solve(object K_in, dmat b_in, dmat out = None, solver = 'SuperLU', solver_args = {}):
  """
  PURPOSE:   Solve OTI linear system of equations.
  """
  #***************************************************************************************************
  
  from scipy.linalg import lu_factor, lu_solve
  import scipy.sparse.linalg as spla
  import  scipy.sparse as spr

  cdef uint64_t i,j,k,l
  cdef ord_t ordi, ord_lhs, ord_rhs, Oord
  cdef uint8_t res_flag = 1
  cdef object res

  tK = type(K_in)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  matso
  #    -  csr_matso

  if   tK is dmat:
    
    if res_flag:
      solve_dense( K_in, b_in, out = out)
    else:      
      res = solve_dense(K_in, b_in, out = None, solver = solver, solver_args = solver_args )
    # end if

  elif isinstance(K_in,spr.spmatrix):
    
    if res_flag:
      solve_sparse( K_in, b_in, out = out)
    else:      
      res = solve_sparse(K_in, b_in, out = None, solver = solver, solver_args = solver_args )
    # end if

  else:
    raise TypeError("Unsupported types at Block-solver inverse operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cdef solve_dense(dmat K_in, dmat b_in, dmat out = None, solver = 'SuperLU', solver_args = {}):
  """
  PURPOSE:   Solve OTI linear system of equations for a dense K_in.
  """
  #***************************************************************************************************
  

  from scipy.linalg import lu_factor, lu_solve

  cdef dmat      R, Rres, Rtmp
  cdef uint64_t i,j,k,l
  cdef uint8_t res_flag = 1

  if out is None:
    res_flag = 0
  # end if      
  
  _check_square(K_in._lk, K_in.nd.shape[0], K_in.nd.shape[1])

  if b_in.nd.shape[0] != K_in.nd.shape[0]:

    # NumPy raises a plain ValueError (not LinAlgError) for a right-hand side of the wrong size.
    raise ValueError("solve: the right-hand side has {} rows but the matrix has {}".format(
                     b_in.nd.shape[0], K_in.nd.shape[0]))

  # end if

  if res_flag:
    Rres = out
    Rres._check_out()
  else:
    Rres = zeros(b_in.shape)
  # end if

  lu = lu_factor(K_in.real)
  rhs = b_in.real
  # Solve the real system of equations, using LU solver. The solution is the RETURNED array: with
  # overwrite_b=True scipy only works in place when rhs is Fortran-contiguous, which a row-major
  # (n, k) matrix with k > 1 is not (it was dropped before, so k > 1 columns came back unsolved).
  rhs = lu_solve(lu, rhs, overwrite_b=True)

  # Solve the real coefficient
  Rres.to_numpy()[...] = rhs
  if res_flag == 0:
    return Rres
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
cdef solve_sparse(object K_in, dmat b_in, dmat out = None, solver = 'SuperLU', solver_args = {}):
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
  
  from scipy.sparse.linalg import splu
  import scipy.sparse as spr

  cdef dmat      R, Rres
  cdef np.ndarray tmp1, tmp2
  cdef uint64_t i,j,solver_id = 1
  cdef uint8_t res_flag = 1

  if out is None:
    res_flag = 0
  # end if      
  
  if res_flag:
    Rres = out
    Rres._check_out()
  else:
    Rres = zeros(b_in.shape)
  # end if

  Kr_csc = K_in.tocsc()
  
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
  Rres.to_numpy()[...] = rhs
  if res_flag == 0:
    return Rres
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def solve_sparse_tests(object K_in, dmat b_in, np.ndarray out = None):
  """
  PURPOSE:   Solve real linear system of equations for a sparse K.
  """
  #***************************************************************************************************
  
  from scipy.sparse.linalg import splu
  import scipy.sparse as spr

  cdef dmat      R
  cdef np.ndarray[double,ndim=2] Rres
  cdef np.ndarray[double,ndim=2] rhs
  cdef uint64_t i,j
  cdef uint8_t res_flag = 1

  if out is None:
    res_flag = 0
  # end if      
  
  if res_flag:
    Rres = out
  else:
    Rres = np.zeros((b_in.nd.shape[0], b_in.nd.shape[1]))
  # end if

  lu = splu(K_in.tocsc())
  rhs = b_in.real.reshape(b_in.nd.shape[0], b_in.nd.shape[1])
  # Solve the real system of equations, using LU solver:
  Rres = lu.solve(rhs)

  # # Solve the real coefficient
  # for i in range(Rres.nrows):
  #   for j in range(Rres.ncols):
  #     darr_set_item_ij_r( rhs[i,j], i, j, &Rres.arr)
  #   # end for
  # # end for  

  if res_flag == 0:
    return rhs
  # end if 

  return out

#-----------------------------------------------------------------------------------------------------
