
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
  #    -  mdmat8
  #    -  mdmatfe8
  #    -  darr
  # Supported output types:
  #    - mdnum8
  #    - mdnumfe8

  if   tlhs is mdmatfe8:

    res = __dot_product_FX( lhs, rhs, out = out)

  elif tlhs is mdmat8:

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
#   #    -  mdmat8
#   #    -  mdmatfe8
#   #    -  darr
#   # Supported output types:
#   #    - mdnum8
#   #    - mdnumfe8

#   if   tlhs is mdmatfe8:

#     res = __cross_product_FX( lhs, rhs, out = out)

#   elif tlhs is mdmat8:

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

  cdef mdmat8      Olhs, Orhs, Ores
  cdef mdarr8_t   cOres
  cdef dmat       Rlhs, Rrhs, Rres
  cdef darr_t    cRres
  cdef mdmatfe8    Flhs, Frhs, Fres
  cdef femdarr8_t cFres

  cdef csr_matrix  Slhs

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  mdmat8
  #    -  mdmatfe8
  #    -  darr

  if   tlhs is mdmatfe8:
    
    Flhs = lhs
    if   trhs is mdmatfe8: # FF
      Frhs = rhs
      if res_flag:
        Fres = out
        femdarr8_matmul_FF_to( &Flhs.arr, &Frhs.arr ,&Fres.arr)
      else:
        cFres = femdarr8_matmul_FF( &Flhs.arr, &Frhs.arr )
        res = mdmatfe8.create(&cFres)
      # end if 

    elif trhs is mdmat8:   # FO

      Orhs = rhs
      if res_flag:
        Fres = out
        femdarr8_matmul_FO_to( &Flhs.arr, &Orhs.arr ,&Fres.arr)
      else:
        cFres = femdarr8_matmul_FO( &Flhs.arr, &Orhs.arr )
        res = mdmatfe8.create(&cFres)
      # end if 

    elif tlhs is dmat:    # FR

      Rrhs = rhs
      if res_flag:
        Fres = out
        femdarr8_matmul_FR_to( &Flhs.arr, &Rrhs.arr ,&Fres.arr)
      else:
        cFres = femdarr8_matmul_FR( &Flhs.arr, &Rrhs.arr )
        res = mdmatfe8.create(&cFres)
      # end if 

    else:
      raise TypeError("Unsupported types at dot operation.")      
    # end if 

  elif tlhs is mdmat8:

    Olhs = lhs
    if   trhs is mdmatfe8: # OF
      Frhs = rhs
      if res_flag:
        Fres = out
        femdarr8_matmul_OF_to( &Olhs.arr, &Frhs.arr ,&Fres.arr)
      else:
        cFres = femdarr8_matmul_OF( &Olhs.arr, &Frhs.arr )
        res = mdmatfe8.create(&cFres)
      # end if 

    elif trhs is mdmat8:   # OO

      Orhs = rhs
      if res_flag:
        Ores = out
        mdarr8_matmul_OO_to( &Olhs.arr, &Orhs.arr ,&Ores.arr)
      else:
        cOres = mdarr8_matmul_OO( &Olhs.arr, &Orhs.arr )
        res = mdmat8.create(&cOres)
      # end if 

    elif tlhs is dmat:    # OR
    
      Rrhs = rhs
      if res_flag:
        Ores = out
        mdarr8_matmul_OR_to( &Olhs.arr, &Rrhs.arr ,&Ores.arr)
      else:
        cOres = mdarr8_matmul_OR( &Olhs.arr, &Rrhs.arr )
        res = mdmat8.create(&cOres)
      # end if 

    else:
      raise TypeError("Unsupported types at dot operation.")      
    # end if    

  elif tlhs is csr_matrix:

    # Slhs = lhs
    if   trhs is mdmat8: # SO
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
    if   trhs is mdmatfe8: # RF
      Frhs = rhs
      if res_flag:
        Fres = out
        femdarr8_matmul_RF_to( &Rlhs.arr, &Frhs.arr ,&Fres.arr)
      else:
        cFres = femdarr8_matmul_RF( &Rlhs.arr, &Frhs.arr )
        res = mdmatfe8.create(&cFres)
      # end if 

    elif trhs is mdmat8:   # RO
      Orhs = rhs
      if res_flag:
        Ores = out
        mdarr8_matmul_RO_to( &Rlhs.arr, &Orhs.arr ,&Ores.arr)
      else:
        cOres = mdarr8_matmul_RO( &Rlhs.arr, &Orhs.arr )
        res = mdmat8.create(&cOres)
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
cpdef trunc_dot(ord_t ord_lhs, object lhs, ord_t ord_rhs, object rhs, object out = None):
  """
  PURPOSE:  Matrix inner product (standard matrix multiplication).
  """
  #***************************************************************************************************

  cdef mdmat8      Olhs, Orhs, Ores
  cdef mdarr8_t   cOres
  cdef dmat       Rlhs, Rrhs, Rres
  cdef darr_t    cRres
  cdef mdmatfe8    Flhs, Frhs, Fres
  cdef femdarr8_t cFres

  cdef csr_matrix  Slhs

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  mdmat8
  #    -  csr_matrix
  #    -  darr

  if tlhs is csr_matrix:
    # Slhs = lhs
    if   trhs is mdmat8: # SO
      if res_flag:
        Ores = out
        csrmatrix_trunc_matmul_SO_to( ord_lhs, lhs, ord_rhs, rhs, Ores)
      else:
        res = csrmatrix_trunc_matmul_SO( ord_lhs, lhs, ord_rhs, rhs)
      # end if 
    else:
      raise TypeError("Unsupported types at trunc_dot operation.")      
    # end if  
  else:
    raise TypeError("Unsupported types at trunc_dot operation.")
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

  cdef mdmat8      O, Ores
  cdef mdarr8_t   cOres
  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef mdmatfe8    F, Fres
  cdef femdarr8_t cFres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  mdmat8
  #    -  mdmatfe8
  #    -  darr

  if   tarr is mdmatfe8:
    
    F = arr
    if res_flag:
      Fres = out
      femdarr8_transpose_to( &F.arr, &Fres.arr)
    else:
      cFres = femdarr8_transpose( &F.arr)
      res = mdmatfe8.create(&cFres)
    # end if 

  elif tarr is mdmat8:

    O = arr
    if res_flag:
      Ores = out
      mdarr8_transpose_to( &O.arr, &Ores.arr)
    else:
      cOres = mdarr8_transpose( &O.arr)
      res = mdmat8.create(&cOres)
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

  cdef mdmat8      O
  cdef dmat       R
  cdef mdmatfe8    F
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef mdnumfe8     fres
  cdef mdnum8    ores

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  mdmat8
  #    -  mdmatfe8
  #    -  darr

  if   tarr is mdmatfe8:
    
    F = arr
    if res_flag:
      fres = out
      femdarr8_det_to( &F.arr, &fres.num)
    else:
      cfres = femdarr8_det( &F.arr)
      res = mdnumfe8.create(&cfres)
    # end if 

  elif tarr is mdmat8:
    
    O = arr
    if res_flag:      
      ores = out
      mdarr8_det_to( &O.arr, &ores.num)
    else:
      cores = mdarr8_det( &O.arr)
      res = mdnum8.create(&cores)
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

  cdef mdmat8      O
  cdef dmat       R
  cdef mdmatfe8    F
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef mdnumfe8     fres
  cdef mdnum8    ores

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  mdmat8
  #    -  mdmatfe8
  #    -  darr

  if   tarr is mdmatfe8:
    
    F = arr
    if res_flag:
      fres = out
      femdarr8_pnorm_to( &F.arr, p, &fres.num)
    else:
      cfres = femdarr8_pnorm( &F.arr, p)
      res = mdnumfe8.create(&cfres)
    # end if 

  elif tarr is mdmat8:

    O = arr
    if res_flag:
      ores = out
      mdarr8_pnorm_to( &O.arr, p, &ores.num)
    else:
      cores = mdarr8_pnorm( &O.arr, p)
      res = mdnum8.create(&cores)
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

  cdef mdmat8      O, Ores
  cdef mdarr8_t   cOres
  cdef dmat       R, Rres
  cdef darr_t    cRres
  cdef mdmatfe8    F, Fres
  cdef femdarr8_t cFres

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  mdmat8
  #    -  mdmatfe8
  #    -  darr

  if   tarr is mdmatfe8:    
    F = arr
    if res_flag:
      Fres = out
      femdarr8_invert_to( &F.arr, &Fres.arr)
    else:
      cFres = femdarr8_invert( &F.arr)
      res = mdmatfe8.create(&cFres)
    # end if 
  elif tarr is mdmat8:
    O = arr
    if res_flag:
      Ores = out
      mdarr8_invert_to( &O.arr, &Ores.arr)
    else:
      cOres = mdarr8_invert( &O.arr)
      res = mdmat8.create(&cOres)
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
cpdef inv_block(object arr, object out = None):
  """
  PURPOSE:   Matrix inverse using block solver.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores, tmp
  cdef mdarr8_t   cOres
  cdef csr_matrix  S, Sres
  # cdef dmat       R, Rres
  # cdef darr_t    cRres
  # cdef mdmatfe8    F, Fres
  # cdef femdarr8_t cFres

  cdef uint64_t i,j,k,l
  cdef ord_t ordi, ord_lhs, ord_rhs, Oord

  cdef uint8_t res_flag = 1

  cdef object res

  tarr = type(arr)

  if out is None:

    res_flag = 0

  # end if 

  # supported types:
  #    -  mdmat8
  #    -  csr_matrix

  if   tarr is mdmat8:    
    O = arr
    if res_flag:
      Ores = out
    else:
      Ores = zeros(O.shape)
    # end if

    # res = Ores
    inverse = np.linalg.inv(O.real)

    # Copy the inverse to the values of the inverse.
    for i in range(Ores.arr.nrows):
      for j in range(Ores.arr.ncols):
        k = j + i * Ores.arr.ncols
        mdarr8_set_item_ij_r( inverse[i,j], i, j, &Ores.arr)
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
    res = Ores
  else:
    raise TypeError("Unsupported types at Block-solver inverse operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef solve(object K_in, mdmat8 b_in, mdmat8 out = None, solver = 'SuperLU',solver_args = {}):
  """
  PURPOSE:   Solve OTI linear system of equations.
  """
  #***************************************************************************************************
  

  from scipy.linalg import lu_factor, lu_solve
  import scipy.sparse.linalg as spla

  cdef mdmat8      O, Ores, Otmp
  cdef csr_matrix  S, Sres, Stmp  
  cdef uint64_t i,j,k,l
  cdef ord_t ordi, ord_lhs, ord_rhs, Oord
  cdef uint8_t res_flag = 1
  cdef object res

  tK = type(K_in)

  if out is None:
    res_flag = 0
  # end if 

  # supported types:
  #    -  mdmat8
  #    -  csr_matrix

  if   tK is mdmat8:
    
    if res_flag:
      solve_dense( K_in, b_in, out = out, solver = solver, solver_args=solver_args)
    else:      
      res = solve_dense(K_in, b_in, out = None, solver = solver, solver_args=solver_args)
    # end if

  elif tK is csr_matrix:

    if res_flag:
      solve_sparse( K_in, b_in, out = out, solver = solver, solver_args=solver_args)
    else:      
      res = solve_sparse(K_in, b_in, out = None, solver = solver, solver_args=solver_args)
    # end if

  else:
    raise TypeError("Unsupported types at Block-solver inverse operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef solve_dense(mdmat8 K_in, mdmat8 b_in, mdmat8 out = None, solver = 'SuperLU',solver_args = {}):
  """
  PURPOSE:   Solve OTI linear system of equations for a dense K_in.
  """
  #***************************************************************************************************
  

  from scipy.linalg import lu_factor, lu_solve

  cdef mdmat8      O, Ores, Otmp
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

  lu = lu_factor(K_in.real)
  rhs = b_in.real
  # Solve the real system of equations, using LU solver:
  lu_solve(lu,rhs, overwrite_b=True)

  # Solve the real coefficient
  for i in range(Ores.nrows):      
    for j in range(Ores.ncols):

      mdarr8_set_item_ij_r( rhs[i,j], i, j, &Ores.arr)

    # end for
  # end for
  
  Oord = max( K_in.order, b_in.order)

  for ordi in range( 1, Oord + 1 ):
        
    tmp = b_in.get_order_im(ordi)

    for ord_rhs in range(ordi):

      ord_lhs = ordi - ord_rhs

      tmp -= dot( K_in.get_order_im(ord_lhs), Ores.get_order_im(ord_rhs))

    # end for 
    
    # Convert tmp to array (for specific order)
    rhs = get_order_im_array(ordi,tmp)
    # print(rhs)
    rhs = lu_solve( lu, rhs )
    # print(rhs)
    set_order_im_from_array( ordi, rhs, Ores)

  # end for 

  if res_flag == 0:

    return Ores

  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef solve_sparse_old(csr_matrix K_in, mdmat8 b_in, mdmat8 out = None):
  """
  PURPOSE:   Solve OTI linear system of equations for a dense K_in.
  """
  #***************************************************************************************************
  

  from scipy.sparse.linalg import splu

  cdef mdmat8      O, Ores, Otmp
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

  lu = splu(K_in.real.tocsc())
  rhs = b_in.real
  # Solve the real system of equations, using LU solver:
  rhs = lu.solve(rhs)

  # Solve the real coefficient
  for i in range(Ores.nrows):      
    for j in range(Ores.ncols):

      mdarr8_set_item_ij_r( rhs[i,j], i, j, &Ores.arr)

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
    # print(rhs)
    rhs = lu.solve( rhs )
    # print(rhs)
    set_order_im_from_array( ordi, rhs, Ores)

  # end for 

  if res_flag == 0:

    return Ores

  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef solve_sparse(csr_matrix K_in, mdmat8 b_in, mdmat8 out = None, solver = 'SuperLU', solver_args = {}):
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
  

  cdef mdmat8      O, Ores, Otmp, tmp, tmp2, tmp3
  cdef uint64_t i,j,k,l, solver_id=1
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

  elif solver == 'ILU' or solver == 'ilu' or solver == 'spilu':
    
    from scipy.sparse.linalg import spilu
    factorizer = spilu

  elif solver == 'cholesky' or solver == 'ch' or solver == 'CH':
    
    from sksparse.cholmod import cholesky
    factorizer = cholesky
    solver_id = 2

  elif solver == 'UMFPACK' or solver == 'umfpack' or solver == 'luumf':
    
    from scikits.umfpack import splu
    factorizer = splu
    Kr_csc.indices = Kr_csc.indices.astype(np.int64) # Required for UMFPACK
    Kr_csc.indptr  = Kr_csc.indptr.astype(np.int64)  # Required for UMFPACK

  else:

    raise ValueError("Unsupported solver. Try solver = 'SuperLU', solver = 'cholesky' or solver = 'umfpack'" )

  # end if     

  # Factorize matrix. This is usually the most demanding step in the block solver approach.
  factor = factorizer(Kr_csc,**solver_args)

  del(Kr_csc) # Real matrix not needed anymore.

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
      mdarr8_set_item_ij_r( rhs[i,j], i, j, &Ores.arr)
    # end for
  # end for
  
  Oord = max( K_in.order, b_in.order)
  tmp  = zeros( Ores.shape )
  tmp2 = zeros( Ores.shape )

  for ordi in range( 1, Oord + 1 ):
        
    get_order_im( ordi, b_in, out=tmp )

    for ord_rhs in range( ordi ):

      ord_lhs = ordi - ord_rhs

      trunc_dot( ord_lhs, K_in, ord_rhs, Ores, out=tmp2 )
      trunc_sub(ordi,tmp,tmp2,out=tmp)

    # end for 
    
    # Convert tmp to array (for specific order)
    rhs = get_order_im_array_2( ordi, tmp )
    
    rhs = solve( rhs )
    
    set_order_im_from_array_2( ordi, rhs, Ores)

  # end for 

  if res_flag == 0:

    return Ores

  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def solve_sparse_out(csr_matrix K_in, mdmat8 b_in, mdmat8 out = None):
  """
  PURPOSE:   Solve OTI linear system of equations for a dense K_in.
  """
  #***************************************************************************************************
  

  from scipy.sparse.linalg import splu

  cdef mdmat8      O, Ores, Otmp, tmp, tmp2, tmp3
  cdef csr_matrix  Ktmp
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

  lu = splu(K_in.real.tocsc())
  rhs = b_in.real
  # Solve the real system of equations, using LU solver:
  rhs = lu.solve(rhs)

  # Solve the real coefficient
  for i in range(Ores.nrows):      
    for j in range(Ores.ncols):

      mdarr8_set_item_ij_r( rhs[i,j], i, j, &Ores.arr)

    # end for
  # end for
  
  Oord = max( K_in.order, b_in.order)
  Ktmp = K_in.zeros_like()
  tmp = zeros( b_in.shape )
  tmp1 = zeros( b_in.shape )
  tmp2 = zeros( b_in.shape )

  for ordi in range( 1, Oord + 1 ):
        
    # tmp = b_in.get_order_im( ordi )
    get_order_im( ordi, b_in,  out = tmp )

    for ord_rhs in range( ordi ):
      
      Ktmp.set_all(0)

      ord_lhs = ordi - ord_rhs

      # tmp -= dot( K_in.get_order_im( ord_lhs ), Ores.get_order_im( ord_rhs ) )
      get_order_im( ord_lhs, K_in, out = Ktmp )
      get_order_im( ord_rhs, Ores, out = tmp2 )
      dot(Ktmp,tmp2,out=tmp2)
      sub( tmp,tmp2,out=tmp)

    # end for 
    
    # Convert tmp to array (for specific order)
    # maxidx = onumm1n10_get_ndir_order(ordi,&tmp.arr.p_data[0])
    # rhs = np.zeros(( tmp.nrows, tmp.ncols*maxidx ), dtype = np.float64)
    rhs = get_order_im_array( ordi, tmp )
    # print(rhs)
    rhs = lu.solve( rhs )
    # print(rhs)
    set_order_im_from_array( ordi, rhs, Ores)

  # end for 

  if res_flag == 0:
    return Ores
  # end if 

  

  
  
  

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef get_order_im_array(ord_t ordi, mdmat8 tmp):
  """
  PURPOSE:   Get a specific order from .
  """
  #***************************************************************************************************
  

  cdef np.ndarray res
  cdef mdnum8_t otmp
  cdef ord_t order
  cdef imdir_t maxidx = 0, idx
  cdef uint64_t i, j, k

  maxidx = mdnum8_get_ndir_order(ordi,&tmp.arr.p_data[0])
  order  = mdnum8_get_order( &tmp.arr.p_data[0] )
  
  res = np.zeros(( tmp.nrows, tmp.ncols*maxidx ), dtype = np.float64)

  for i in range(tmp.nrows):
    for j in range(tmp.ncols):

      otmp = tmp.arr.p_data[ j + i * tmp.ncols ]

      if order >= ordi:

        for k in range( maxidx ): 
          
          idx = mdnum8_get_indx(k, ordi)
          res[ i, j + tmp.ncols * k ] = mdnum8_get_item( idx, ordi, &otmp)

        # end for

      # end if 

    # end for 
  # end for

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef set_order_im_from_array(ord_t ordi, np.ndarray arr, mdmat8 tmp):
  """
  PURPOSE:   Set a specific order from an array.
  """
  #***************************************************************************************************
  
  
  cdef mdnum8_t otmp
  cdef imdir_t nnz, idx
  cdef coeff_t val
  cdef uint64_t i,j,k

  nnz = arr.shape[1]/tmp.ncols

  for i in range(tmp.nrows):
    
    for j in range(tmp.ncols):

      mdnum8_set_r(0.0, &otmp)
        
      for k in range( nnz ):          
        
        val = arr[ i, j + tmp.ncols * k ] 
        
        idx = mdnum8_get_indx(k, ordi)

        mdnum8_set_item( val, idx, ordi, &otmp)

      # end for

      tmp[i,j] += mdnum8.create( &otmp)

    # end for 
  # end for

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef get_order_im_array_2(ord_t ordi, mdmat8 tmp):
  """
  PURPOSE:   Get a specific order from .
  """
  #***************************************************************************************************
  

  cdef np.ndarray[coeff_t, ndim=2] res
  cdef mdnum8_t otmp
  cdef coeff_t* coeff_list
  cdef ord_t order
  cdef imdir_t maxidx = 0, idx
  cdef uint64_t i, j, k

  maxidx = mdnum8_get_ndir_order(ordi,&tmp.arr.p_data[0])
  order  = mdnum8_get_order( &tmp.arr.p_data[0] )
  
  res = np.zeros(( tmp.nrows, tmp.ncols*maxidx ), dtype = np.float64)

  for i in range(tmp.nrows):
    for j in range(tmp.ncols):

      otmp = tmp.arr.p_data[ j + i * tmp.ncols ]

      if order >= ordi:
        
        coeff_list = mdnum8_get_order_address( ordi, &otmp)

        for k in range( maxidx ): 
          
          res[ i, j + tmp.ncols * k ] = coeff_list[k]

        # end for

      # end if 

    # end for 
  # end for

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef set_order_im_from_array_2(ord_t ordi, np.ndarray arr, mdmat8 tmp):
  """
  PURPOSE:   Set a specific order from an array.
  """
  #***************************************************************************************************
  
  
  cdef mdnum8_t otmp
  cdef imdir_t nnz, idx
  cdef coeff_t val
  cdef uint64_t i,j,k

  nnz = arr.shape[1]/tmp.ncols

  for i in range(tmp.nrows):
    
    for j in range(tmp.ncols):

      mdnum8_set_r(0.0, &otmp)

      coeff_list = mdnum8_get_order_address(ordi,&otmp)
        
      for k in range( nnz ):          
        
        val = arr[ i, j + tmp.ncols * k ] 
        coeff_list[k] = val

      # end for

      tmp[i,j] += mdnum8.create( &otmp)

    # end for 
  # end for

#-----------------------------------------------------------------------------------------------------

