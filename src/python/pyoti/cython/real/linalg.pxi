
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
    if   trhs is dmatfe: # RF
      Frhs = rhs
      if res_flag:
        Fres = out
        fedarr_matmul_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)
      else:
        cFres = fedarr_matmul_RF( &Rlhs.arr, &Frhs.arr )
        res = dmatfe.create(&cFres)
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
    if res_flag:
      fres = out
      fedarr_det_to( &F.arr, &fres.num)
    else:
      cfres = fedarr_det( &F.arr)
      res = dnumfe.create(&cfres)
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
    if res_flag:
      Fres = out
      fedarr_invert_to( &F.arr, &Fres.arr)
    else:
      cFres = fedarr_invert( &F.arr)
      res = dmatfe.create(&cFres)
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
  # end if 

  if res_flag == 0:
    return res
  # end if 

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
  
  if res_flag:
    Rres = out
  else:
    Rres = zeros(b_in.shape)
  # end if

  lu = lu_factor(K_in.real)
  rhs = b_in.real
  # Solve the real system of equations, using LU solver:
  lu_solve(lu,rhs, overwrite_b=True)

  # Solve the real coefficient
  for i in range(Rres.nrows):      
    for j in range(Rres.ncols):

      darr_set_item_ij_r( rhs[i,j], i, j, &Rres.arr)

    # end for
  # end for
  
  if res_flag == 0:
    return Rres
  # end if 

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
  for i in range(Rres.nrows):
    for j in range(Rres.ncols):
      darr_set_item_ij_r( rhs[i,j], i, j, &Rres.arr)
    # end for
  # end for  

  if res_flag == 0:
    return Rres
  # end if 

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
    Rres = np.zeros(b_in.shape)
  # end if

  lu = splu(K_in.tocsc())
  rhs = b_in.real
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

#-----------------------------------------------------------------------------------------------------
