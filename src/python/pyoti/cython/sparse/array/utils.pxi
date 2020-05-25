



#*****************************************************************************************************
def matso_dot(matso lhs, matso rhs, matso out = None):
  """
  PURPOSE: Matrix multiplication.
  """
  global dhl
  
  cdef arrso_t res 


  if out is not None:
    
    arrso_matmul_OO_to( &lhs.arr, &rhs.arr ,&out.arr, dhl)

  else:

    res = arrso_matmul_OO( &lhs.arr, &rhs.arr , dhl)

    return matso.create(&res)

  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def matso_inv(matso A, matso out = None):
  """
  PURPOSE: Matrix invertion.
  """
  global dhl

  cdef arrso_t res

  if out is None:

    res = arrso_invert( &A.arr, dhl )

    return matso.create(&res)

  else:

    arrso_invert_to( &A.arr, &out.arr, dhl )

  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
def matso_transpose(matso A, matso out = None):
  """
  PURPOSE: Matrix transpose.
  """
  global dhl

  cdef arrso_t res

  if out is None:

    res = arrso_transpose( &A.arr, dhl )

    return matso.create(&res)

  else:

    arrso_transpose_to( &A.arr, &out.arr, dhl )

  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def matso_det(matso A, sotinum out = None):
  """
  PURPOSE: Matrix determinant.
  """
  global dhl

  cdef sotinum_t res 

  if out is None:

    res = arrso_det( &A.arr, dhl)

    return sotinum.create(&res)

  else: 

    arrso_det_to( &A.arr, &out.num, dhl)

  # end if 
  
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def matso_norm(matso A, double p = 2.0, sotinum out = None):
  """
  PURPOSE: Matrix norm.
  """
  global dhl

  cdef sotinum_t res 

  if out is None:

    if (p == 2.0):

      res = arrso_norm( &A.arr, dhl)

    else:
      
      res = arrso_pnorm( &A.arr, p, dhl)    

    # end if 


    return sotinum.create(&res)

  else:

    if (p == 2.0):

      arrso_norm_to( &A.arr, &out.num, dhl)

    else:
      
      arrso_pnorm_to( &A.arr, p, &out.num, dhl)    

    # end if 

  # end if 

#-----------------------------------------------------------------------------------------------------











#*****************************************************************************************************
cpdef matso eye(uint64_t size, bases_t nbases=0, ord_t order=0):
  """
  PURPOSE: Create identity matrix of shape: (size,size).

  """
  global dhl

  cdef arrso_t res = arrso_eye_bases(size, nbases, order, dhl)

  return matso.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso zeros( uint64_t nrows, uint64_t ncols, bases_t nbases=0, ord_t order=0):
  """
  PURPOSE: Create matrix filled with zeroes of shape: (nrows,ncols).

  """
  global dhl

  cdef arrso_t res = arrso_zeros_bases(nrows,ncols,nbases,order,dhl)

  return matso.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso ones(uint64_t nrows,uint64_t ncols, bases_t nbases=0, ord_t order=0):
  """
  PURPOSE: Create matrix filled with ones of shape: (nrows,ncols).

  """
  global dhl

  cdef arrso_t res = arrso_ones_bases(nrows,ncols,nbases,order,dhl)

  return matso.create(&res)
  
#-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# def solve(matso A, matso b):
#   """  
#   PORPUSE: To solve a dense linear system of equations of OTI algebra.
#   """
#   global dhl

#   from scipy.sparse import coo_matrix
#   from scipy.linalg import lu_factor, lu_solve

#   # Get the corresponding matrix form.
#   cdef uint64_t i, j, k
#   # cdef arrso_t arrso_res
#   cdef matso res
#   cdef np.ndarray[coeff_t, ndim=2] tmp
#   cdef np.ndarray[coeff_t, ndim=2] tmp_rhs
#   cdef np.ndarray[coeff_t, ndim=2] tmp_dot

#   cdef matrix_form_t matform

#   cdef np.ndarray[uint64_t, ndim=1] rows
#   cdef np.ndarray[uint64_t, ndim=1] cols
#   cdef np.ndarray[uint64_t, ndim=1] idx_coo  
#   cdef np.ndarray[ uint8_t, ndim=1] ord_coo

#   maxorder  = max(arrso_get_order(&A.arr),arrso_get_order(&b.arr))
#   maxnbases = max(A.arr.nbases,b.arr.nbases)

#   res = zeros(b.arr.nrows, b.arr.ncols, nbases = maxnbases, order = maxorder)

#   # TODO: use matrix inner product from dmat object.
#   matform = dhelp_matrix_form_indices(maxnbases,maxorder,dhl)

#   rows    = c_ptr_to_np_1darray_uint64( matform.p_rows, matform.nonzero)
#   cols    = c_ptr_to_np_1darray_uint64( matform.p_cols, matform.nonzero)
#   idx_coo = c_ptr_to_np_1darray_uint64( matform.p_im  , matform.nonzero)
#   ord_coo = c_ptr_to_np_1darray_uint8 ( matform.p_ord , matform.nonzero)


  
#   indices = np.arange( 1, matform.nonzero+1, dtype = np.uint64)

#   dummy_mat = coo_matrix( ( indices, (rows.copy(), cols.copy()) ), dtype = np.uint64 )
#   dummy_mat = dummy_mat.tocsr()

#   # first_col_indices = dummy_mat[:,0].data-1
#   first_col_indices = indices[ (matform.sizex-1) : (2*matform.sizex-1) ] - 1
  
#   # Get vector form index and order pairs
#   vec_form_idx = idx_coo[first_col_indices]
#   vec_form_ord = ord_coo[first_col_indices]
  
  

#   # Factorize system.
#   factorization = lu_factor( A.get_imdir(0,0) )

#   # Solve the real system of equations.
#   tmp = lu_solve(factorization, b.get_imdir(0,0) )
#   res.set_imdir( tmp, 0, 0)

#   # Solve the imaginary systems.
#   tmp_rhs = np.zeros(b.shape,dtype = np.float64)
#   tmp_dot = np.zeros(b.shape,dtype = np.float64)

#   for i in range(1, dummy_mat.shape[0]):

#     # print("\n\ni: ",i)
#     # get the i'th row of elements to operate.
#     # row_indices = dummy_mat[i].data - 1
#     row_indices = dummy_mat.data[dummy_mat.indptr[i]:dummy_mat.indptr[i+1]] - 1

#     row_idx = idx_coo[row_indices]
#     row_ord = ord_coo[row_indices]

#     # Get the imaginary direation from the OTI rhs
#     tmp_rhs[:,:] = b.get_imdir( row_idx[ZERO], row_ord[ZERO], copy=False )

#     # print("RHS:\n",tmp_rhs)
    
#     k = row_idx.size-1
#     # Get A imaginary times b real.
#     np.dot( A.get_imdir(row_idx[ZERO], row_ord[ZERO], copy=False ), 
#           res.get_imdir(row_idx[   k], row_ord[   k], copy=False ), out = tmp_dot )

#     tmp_rhs -= tmp_dot

#     # print("RHS:\n",tmp_rhs)
#     # Solving 
#     for j in range(1,row_idx.size-1):

#       k = (row_idx.size-1) - j

#       # Get A imaginary times b real.

#       np.dot( A.get_imdir(row_idx[j], row_ord[j], copy=False ), 
#             res.get_imdir(row_idx[k], row_ord[k], copy=False ),out = tmp_dot )
#       tmp_rhs -= tmp_dot
#     # end for 

#     # print("\n\nFinal RHS:\n",tmp_rhs)
#     # Solve the system of equations.
#     tmp = lu_solve(factorization, tmp_rhs )

#     # Write the result on the system.
#     res.set_imdir( tmp, vec_form_idx[i], vec_form_ord[i])

#   # end for 
  
#   free(matform.p_im)
#   free(matform.p_ord)
#   free(matform.p_rows)
#   free(matform.p_cols)

#   return res

# #-----------------------------------------------------------------------------------------------------









#***************************************************************************************************
def get_active_bases(obj_in):
  """

  """
  global dhl

  cdef bases_t  size       = dhl.p_dh[0].Nbasis
  cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
  cdef matso SO
  cdef sotinum so
  cdef uint64_t i
  
  # Initialize all elements as zero (deactivated)
  for i in range(size):

    bases_list[i]=0

  # end for 
  tobj_in = type(obj_in)

  if tobj_in is list:

    for obj in obj_in:
      
      tobj = type(obj)

      if tobj is matso:

        SO = obj
        arrso_get_active_bases( &SO.arr, bases_list, dhl)

      elif tobj is sotinum:
        
        so = obj
        soti_get_active_bases( &so.num, bases_list, dhl) 

      else:

        raise ValueError("Input should be list of sotinum or matso.") 

      # end if 

    # end for

  elif tobj_in is matso:

    SO = obj_in
    arrso_get_active_bases( &SO.arr, bases_list, dhl)

  elif tobj_in is sotinum:
    
    so = obj_in
    soti_get_active_bases( &so.num, bases_list, dhl)        

  else:

    raise ValueError("Input should be list of sotinum and/or matso.") 

  # end if 
  
  res = []

  for i in range(size):

    if bases_list[i] == 1:
    
      res.append(i+1)

    # end if 

  # end for 

  return res

  #---------------------------------------------------------------------------------------------------