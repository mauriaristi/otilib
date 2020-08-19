

# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::     CLASS  spr_omat   :::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class spr_mdarr2_t:
  
#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------

#   #                                --->      Look in spr_omat.pxd    <---

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def __cinit__(self, shape, bases_t nbases = 0 , ord_t order = 0, uint8_t spr_type = 2):
#     """
#     PURPOSE:      Constructor of the spr_omat class.

#     DESCRIPTION:  Creates a new sparse oti matrix OTI matirx.

    

#     ## Constructor 1: Empty constructor. ##

#       DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

#     Arguments:
                  
#                   shape:  Shape of the matrix.

#                   order:  Maximum order of the OTI numbers that will be stored. Default: 1

#                   m:      Number of basis the vector will have.

#                   spr_type: Type of sparse matrix to be created.  0: csr, 1: coo, 2: lil

                  
#     """

#     

    

#     cdef uint64_t i
#     cdef ord_t ordi

#     self.order  = order
#     self.nbases = nbases
#     self.nrows  = shape[0]
#     self.ncols  = shape[1]
#     self.size   = self.nrows * self.ncols 
#     self.ndir   = 0 # Initialize the number of imaginary directions.
#     self.spr_type = spr_type

#     base_sprmat_creator = self.get_base_sprmat_creator()

      
#     # create real element

#     self.re = base_sprmat_creator( shape , dtype = np.float64)

#     self.p_im   = np.empty( self.order, dtype=np.ndarray)
#     self.p_ndpo = np.zeros( self.order, dtype=np.uint64)

#     for ordi in range(self.order):
      
#       self.p_ndpo[ordi] = dhelp_extract_ndirOrder( self.nbases, ordi+1 )
      
#       self.p_im[ordi]   = np.empty( self.p_ndpo[ordi], dtype=object)

#       self.ndir += self.p_ndpo[ordi]

#       for i in range(self.p_ndpo[ordi]):

#         self.p_im[ordi][i] = base_sprmat_creator( shape , dtype = np.float64)
      

#     # end for

    

#   #---------------------------------------------------------------------------------------------------

#   #*************************************************************************************************** 
#   def __repr__(self):
#     """
#     PURPOSE:  To print the representation of the class.

#     """
#     #*************************************************************************************************

#     head = '<spr_omat, '
#     tail = ">"
#     body = ''
#     body += 'shape: ('+str(self.nrows)+","+str(self.ncols)+'), '
#     body += 'ndir: ' + str(self.ndir) +', '
#     body += 'nbases: ' + str(self.nbases) +', '
#     body += 'order: ' + str(self.order) + ', ' 

#     if self.spr_type == 0:     # CSR Matrix
      
#       body += "spr_type: csr"

#     elif self.spr_type == 1:   # COO Matrix
      
#       body += "spr_type: coo" 

#     elif self.spr_type == 2:

#       body += "spr_type: lil"  

    
#     return (head + body + tail)

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   cpdef object get_base_sprmat_creator(self):
#     """
#     PORPUSE: Obtain the sparse matrix creator required to generate the corresponding 
#              sparse matrix elements.
#     """

#     from scipy.sparse import csr_matrix, coo_matrix, lil_matrix

#     if self.spr_type == 0:     # CSR Matrix
      
#       base_sprmat_creator = csr_matrix

#     elif self.spr_type == 1:   # COO Matrix
      
#       base_sprmat_creator = coo_matrix 

#     elif self.spr_type == 2:   # LIL matrix

#       base_sprmat_creator = lil_matrix  

#     else:

#       raise TypeError("Unknown spr_type: "+str(self.spr_type)+". Try 0: CSR matrix or 1: COO matrix.")

#     # end if 

#     return base_sprmat_creator
#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def __str__(self):
#     """
#     PURPOSE: To print a representation of the spr_otinum object that could 
#              be easy to read and understand.  
    

#     """
#     #*************************************************************************************************
    
#     cdef uint64_t i
#     cdef ord_t ordi
#     # cdef uint64_t[:] indx = np.arange(self.Ndir,dtype = np.uint64)
#     # cdef spr_otinum spr_oti

#     head = '< spr_omat class, '
#     tail = " >"

#     body = ''
#     body += 'shape: ('+str(self.nrows)+","+str(self.ncols)+'), '
#     body += 'ndir: ' + str(self.ndir) +', '
#     body += 'nbases: ' + str(self.nbases) +', '
#     body += 'order: ' + str(self.order) + ', \n' 

#     body += str(self.re)+"\n"
#     for ordi in range(self.order):

#       for i in range(self.p_ndpo[ordi]):

#         body += '+ e(' 
        
#         body += str(h.get_compact_fulldir(i,ordi+1)).replace(' ','')
#         body += ") * \n"
#         body += str(self.p_im[ordi][i])+'\n'

#       # end for 
#     # end for
    
#     return (head + body + tail)

#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def __getitem__(self, index):
#     """
#     PURPOSE:  To get the value of a spr_omat coefficient.

#     """
#     #*************************************************************************************************
    
#     

#     cdef otinum_t res_oti

#     # Try first the following:
#     tmp = self.re[index]
    
#     if type(tmp) == np.float64:
    
#       # result is an otinum
#       res_oti = oti_createEmpty(self.nbases, self.order)

#       res_oti.re = self.re[index]

#       for ordi in range(self.order):
        
#         for i in range(self.p_ndpo[ordi]):

#           res_oti.p_im[ordi][i] = self.p_im[ordi][i][index]

#         # end for 

#       # end for 

#       return otinum.create(&res_oti)

#     else:

#       res_mat = spr_omat( tmp.shape, nbases=self.nbases,
#                           order=self.order,spr_type=self.spr_type   )

#       res_mat.re = self.re[index]

#       for ordi in range(self.order):
        
#         for i in range(self.p_ndpo[ordi]):

#           res_mat.p_im[ordi][i] = self.p_im[ordi][i][index]

#         # end for 

#       # end for 
      
      
#       return res_mat

#     # end if.

    
#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def __setitem__(self, index, value):
#     """
#     PURPOSE:  To set the value of an spr_omat coefficient.

#     """
#     #*************************************************************************************************
#     cdef ord_t ordi
#     cdef uint64_t i

#     t_value = type(value)

#     if t_value == otinum:

#       self.set_from_otinum(index, value)

#     else: 
      
#       self.re[index] = value

#       # Set the values of the imaginary directions to zero.
#       for ordi in range(self.order):

#         for i in range(self.p_ndpo[ordi]):

#           self.p_im[ordi][i][index] = 0.0

#         # end for 

#       # end for

#     # end if 

#   #--------------------------------------------------------------------------------------------------- 
  

#   #***************************************************************************************************
#   cpdef set_from_otinum(self, index, otinum in_otinum):
#     """
#     PORPUSE: Set element by otinum.

#     """

#     cdef uint64_t i 
#     cdef ord_t ordi, loop_order
#     cdef flag_t greater_order, greater_nbases
#     cdef bases_t 

#     greater_order  = in_otinum.num.order  > self.order
#     greater_nbases = in_otinum.num.nbases > self.nbases
    
    
#     if greater_nbases:

#       self.change_nbases(in_otinum.num.nbases)

#     # end if 

#     if greater_order:
    
#       self.change_order(in_otinum.num.order)  
    
#     # end if 

    

#     self.re[index] = in_otinum.num.re

#     # At this point they either have the same nbases and order or the number has lower.

#     for ordi in range(in_otinum.num.order):
      
#       for i in range(in_otinum.num.p_ndpo[ordi]):
      
#         self.p_im[ordi][i][index] = in_otinum.num.p_im[ordi][i]

#       # end for

#       # Fill the others with zero.
#       for i in range(in_otinum.num.p_ndpo[ordi],self.p_ndpo[ordi]):
      
#           self.p_im[ordi][i][index] = 0.0

#       # end for

#     # end for      

#     for ordi in range(in_otinum.num.order,self.order):
      
#       # Fill the others with zero.
#       for i in range(self.p_ndpo[ordi]):

#           self.p_im[ordi][i][index] = 0.0

#       # end for

#     # end for

#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   cdef set_and_sum_from_otinum_t(self, tuple index, otinum_t* num):
#     """
#     PURPOSE:  Add to an element of the array from a mdnum2_t

#     """
#     cdef uint64_t i 
#     cdef ord_t ordi, loop_order
#     cdef flag_t greater_order, greater_nbases
#     cdef bases_t 

#     greater_order  = num[ZERO].order  > self.order
#     greater_nbases = num[ZERO].nbases > self.nbases
    
    
#     if greater_nbases:

#       self.change_nbases(num[ZERO].nbases)

#     # end if 

#     if greater_order:
    
#       self.change_order(num[ZERO].order)  
    
#     # end if 

    

#     self.re[index] = num[ZERO].re

#     # At this point they either have the same nbases and order or the number has lower.

#     for ordi in range(num[ZERO].order):
      
#       for i in range(num[ZERO].p_ndpo[ordi]):
        
#         self.p_im[ordi][i][index] += num[ZERO].p_im[ordi][i]

#       # end for

#     # end for      

#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def set_and_sum_from_otinum(self, tuple index, otinum in_otinum):
#     """
#     PURPOSE:  Add to an element of the array from a mdnum2_t

#     """
#     cdef uint64_t i 
#     cdef ord_t ordi, loop_order
#     cdef flag_t greater_order, greater_nbases
#     cdef bases_t 

#     greater_order  = in_otinum.num.order  > self.order
#     greater_nbases = in_otinum.num.nbases > self.nbases
    
    
#     if greater_nbases:

#       self.change_nbases(in_otinum.num.nbases)

#     # end if 

#     if greater_order:
    
#       self.change_order(in_otinum.num.order)  
    
#     # end if 

    

#     self.re[index] = in_otinum.num.re

#     # At this point they either have the same nbases and order or the number has lower.

#     for ordi in range(in_otinum.num.order):
      
#       for i in range(in_otinum.num.p_ndpo[ordi]):
        
#         self.p_im[ordi][i][index] += in_otinum.num.p_im[ordi][i]

#       # end for

#     # end for      

    

#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def change_nbases_order(self,bases_t new_nbases, ord_t new_order):
#     """
#     PURPOSE:  Change allocation to new order.

#     """
#     #*************************************************************************************************
    
#     # First change nbases.
#     self.change_nbases(new_nbases)

#     # then change order.
#     self.change_order(new_order)
    
#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   cpdef change_order(self, ord_t new_order):
#     """
#     PORPUSE: Change in memory the order with corresponding allocation changesa

#     """

#     cdef uint64_t i
#     cdef ord_t ordi
#     cdef ndir_t new_ndir
#     # cdef np.ndarray new_p_im, new_p_ndpo
    
#     shape = (self.nrows, self.ncols) # Get shape

#     base_sprmat_creator = self.get_base_sprmat_creator() # Get creator.

#     # In case the order changes.
#     if( new_order > self.order ):
      
      
#       # Requires creation of new element
#       self.p_im   = np.resize(self.p_im  ,new_order)

#       self.p_ndpo = np.resize(self.p_ndpo,new_order)

#       # just modify the new ones
#       for ordi in range(self.order, new_order):
        
#         self.p_ndpo[ordi] = dhelp_extract_ndirOrder( self.nbases, ordi+1 )
        
#         self.p_im[ordi]   = np.empty( self.p_ndpo[ordi], dtype=object)

#         # Create new arrays to the new elements.
#         for i in range(self.p_ndpo[ordi]):

#           self.p_im[ordi][i] = base_sprmat_creator( shape , dtype = np.float64)
      
#         # end for 

#       # end for 

#       self.order = new_order
    
#     elif( new_order < self.order ):

#       # Requires creation of new element
      
#       self.p_im   = np.resize(self.p_im  ,new_order)
#       self.p_ndpo = np.resize(self.p_ndpo,new_order)

#       self.order = new_order

#     # end if 

#     # Recompute ndir.
#     self.recompute_ndir()
#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   cpdef change_nbases(self,bases_t new_nbases):
#     """
#     PORPUSE: Change in memory the nbases for allocation.
#     """
#     cdef uint64_t i
#     cdef ord_t ordi
#     cdef ndir_t new_ndir
#     # cdef np.ndarray tmp_p_im_i

#     shape = (self.nrows, self.ncols) # Get shape

#     base_sprmat_creator = self.get_base_sprmat_creator() # Get creator.

#     if(new_nbases > self.nbases ):

#       # Elements should be resized and allocated.
#       for ordi in range(self.order):

#         new_ndir = dhelp_extract_ndirOrder( new_nbases, ordi+1 )

#         self.p_im[ordi] = np.resize( self.p_im[ordi], new_ndir)
#         # tmp_p_im_i = np.empty(new_ndir, dtype = self.self.p_im[ordi].dtype)
#         # tmp_p_im_i[1:self.p_ndpo[ordi]] = self.p_im[ordi][:]

#         for i in range(self.p_ndpo[ordi], new_ndir):

#           self.p_im[ordi][i] = base_sprmat_creator( shape , dtype = np.float64)

#         # end for 

#         self.p_ndpo[ordi] = new_ndir

#       # end for 

#       self.nbases = new_nbases

#     elif(new_nbases < self.nbases ):

#       # Elements should be resized but remains with the same number of elements.
#       for ordi in range(self.order):

#         new_ndir = dhelp_extract_ndirOrder( new_nbases, ordi+1 )

#         self.p_im[ordi] = np.resize( self.p_im[ordi], new_ndir)
        
#         self.p_ndpo[ordi] = new_ndir

#       # end for 

#       self.nbases = new_nbases

#     # end if 

#     # Recompute ndir.
#     self.recompute_ndir()
#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   cpdef recompute_ndir(self):
#     """
#     PURPOSE:  Convert to CSR sparse format.

#     """
#     #*************************************************************************************************
    
    
#     cdef uint64_t i
#     cdef ord_t ordi

#     self.ndir = 0
    
#     for ordi in range(self.order):

#       self.ndir += self.p_ndpo[ordi]

#     # end for

#   #---------------------------------------------------------------------------------------------------   

#   #***************************************************************************************************
#   def to_csr(self):
#     """
#     PURPOSE:  Convert to CSR sparse format.

#     """
#     #*************************************************************************************************
    
    
#     cdef uint64_t i
#     cdef ord_t ordi

#     self.re = self.re.tocsr()
    
#     for ordi in range(self.order):

#       for i in range(self.p_ndpo[ordi]):

#         self.p_im[ordi][i] = self.p_im[ordi][i].tocsr()

#       # end for
    
#     # end for

#     self.spr_type = 0

#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def to_coo(self):
#     """
#     PURPOSE:  Convert to COO sparse format.

#     """
#     #*************************************************************************************************
    
#     cdef uint64_t i
#     cdef ord_t ordi

#     self.re = self.re.tocoo()
    
#     for ordi in range(self.order):

#       for i in range(self.p_ndpo[ordi]):

#         self.p_im[ordi][i] = self.p_im[ordi][i].tocoo()

#       # end for
    
#     # end for

#     self.spr_type = 1
#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def to_lil(self):
#     """
#     PURPOSE:  Convert to LIL sparse format.

#     """
#     #*************************************************************************************************
        
#     cdef uint64_t i
#     cdef ord_t ordi

#     self.re = self.re.tolil()
    
#     for ordi in range(self.order):

#       for i in range(self.p_ndpo[ordi]):

#         self.p_im[ordi][i] = self.p_im[ordi][i].tolil()

#       # end for
    
#     # end for

#     self.spr_type = 2
#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   def to_dense(self):
#     """
#     PURPOSE:  Convert to dense omat representation.

#     """
#     #*************************************************************************************************
    
#     

#     cdef uint64_t i
#     cdef ord_t ordi
#     cdef np.ndarray tmp
#     cdef oarr_t res
    
#     res = oarr_createEmpty(self.nrows, self.ncols, self.nbases, self.order)
    
#     copy_numpy2d_to_ptr_f64(self.re.toarray(),res.re)
    
#     for ordi in range(self.order):

#       for i in range(self.p_ndpo[ordi]):

#         copy_numpy2d_to_ptr_f64(self.p_im[ordi][i].toarray(),res.p_im[ordi][i])

#       # end for
    
#     # end for

#     return omat.create(&res)

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   def get_deriv(self, hum_dir):
#     """
#     PURPOSE:  Get the factor to be multiplied to the coprresponding imaginary coefficient to get the 
#               exact value of the derivative.
#     """
#     #***************************************************************************************************
#     

#     cdef list item = imdir(hum_dir)
    
#     cdef coeff_t factor

#     # Check first if derivative is the real coefficient.

#     if item[ONE] == 0: # order 0.
    
#       return self.re
    
#     else:
      
#       factor = dhelp_get_deriv_factor(item[ZERO], item[ONE])

#       return factor * self.p_im[ item[ONE]-1 ][ item[ZERO] ]

#     # end if 

#   #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def get_deriv(self, hum_dir):
#     """
#     PURPOSE:  Get the factor to be multiplied to the coprresponding imaginary coefficient to get the 
#               exact value of the derivative.
#     """
#     #***************************************************************************************************
#     

#     cdef list item = imdir(hum_dir)
    
#     cdef coeff_t factor = 1.0

#     # Check first if derivative is the real coefficient.

      
#     factor = dhelp_get_deriv_factor(item[ZERO], item[ONE])

#     return factor * self.get_imdir( item[ZERO], item[ONE] )

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   cpdef get_imdir(self, imdir_t idx , ord_t order):
#     """
#     PURPOSE: Get the corresponding imaginary direction in the omat object.
#     """
#     #*************************************************************************************************
#     

#     cdef object tmp

#     # Check first if derivative is the real coefficient.

    
#     if order <= self.order:

#       if order == 0:

#         tmp = self.re

#       else: 
        
#         if idx < self.p_ndpo[order-1]:
          
#           tmp =  self.p_im[ order-1 ][ idx ]
          
#         else:
          
#           base_sprmat_creator = self.get_base_sprmat_creator() # Get creator.
#           tmp = base_sprmat_creator(self.shape,dtype=self.re.dtype)

#         # end if

#       # end if 

#     else: 

#       base_sprmat_creator = self.get_base_sprmat_creator() # Get creator.
#       tmp = base_sprmat_creator(self.shape,dtype=self.re.dtype)
   
#     # end if 

#     return tmp

#   #---------------------------------------------------------------------------------------------------
 
 

# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: End of class spr_omat :::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# #*****************************************************************************************************
# def spsolve(spr_omat A, omat b, solver='LU'):
#   """
  
#   PORPUSE: To solve a sparse linear system of equations of OTI algebra.

#   """
  
#   

#   from scipy.sparse import coo_matrix, linalg as spla
#   from scipy.linalg import lu_factor, lu_solve

#   # Get the corresponding matrix form.
#   cdef uint64_t i, j, k
#   # cdef oarr_t oarr_res
#   cdef omat res
#   cdef np.ndarray[coeff_t, ndim=2] tmp
#   cdef np.ndarray[coeff_t, ndim=2] tmp_rhs
#   cdef np.ndarray[coeff_t, ndim=2] tmp_dot

#   cdef matrix_form_t matform

#   cdef np.ndarray[uint64_t, ndim=1] rows
#   cdef np.ndarray[uint64_t, ndim=1] cols
#   cdef np.ndarray[uint64_t, ndim=1] idx_coo  
#   cdef np.ndarray[ uint8_t, ndim=1] ord_coo

#   maxorder  = max(A.order, b.arr.order)
#   maxnbases = max(A.nbases,b.arr.nbases)

#   res = zeros(b.arr.nrows, b.arr.ncols, nbases = maxnbases, order = maxorder)

#   # TODO: use matrix inner product from dmat object.
#   matform = dhelp_matrix_form_indices(maxnbases,maxorder)

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
  
#   sol = solver.upper() # Convert to uppercase the string.
  
#   # Factorize system.
#   if   (sol == 'LU'):
#     lu = spla.splu( A.get_imdir(0,0).tocsc() )
#   elif (sol == 'ILU'):
#     lu = spla.spilu( A.get_imdir(0,0).tocsc() )
#   # end if 

#   # Convert first to csr format (faster for operations)
#   A.to_csr()

#   # Solve the real system of equations.
#   tmp = lu.solve( b.get_imdir(0,0) )
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
#     tmp_rhs[:,:] = b.get_imdir( row_idx[ZERO], row_ord[ZERO])

#     # print("RHS:\n",tmp_rhs)
    
#     k = row_idx.size-1

#     # Get A imaginary times b real.
#     tmp_dot = A.get_imdir(row_idx[ZERO], row_ord[ZERO]).dot( res.get_imdir(row_idx[k],row_ord[k]) )
#     tmp_rhs -= tmp_dot

#     # Solving 
#     for j in range(1,row_idx.size-1):

#       k = (row_idx.size-1) - j

#       # Get A imaginary times b real.
#       tmp_dot = A.get_imdir(row_idx[j], row_ord[j]).dot( res.get_imdir(row_idx[k], row_ord[k]) )
#       tmp_rhs -= tmp_dot

#     # end for 

#     # Solve the system of equations.
#     tmp = lu.solve( tmp_rhs )

#     # Write the result on the system.
#     res.set_imdir( tmp, vec_form_idx[i], vec_form_ord[i])

#   # end for 
  
#   free(matform.p_im)
#   free(matform.p_ord)
#   free(matform.p_rows)
#   free(matform.p_cols)

#   return res

# #-----------------------------------------------------------------------------------------------------

# # #*****************************************************************************************************
# # def solveLU(spr_omat A, ndarray b, **kwargs):
# #   """
# #   PURPOSE:  Solve a system Ax = b

# #   """
# #   #***************************************************************************************************

  
# #   global p_dH

# #   cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
# #   cdef uint64_t i, indxX, indxA, k
# #   cdef uint8_t  j , pos, order = A.order
# #   cdef uint8_t* multiples = p_dH[order-1].p_multpl
# #   cdef uint64_t Nmultpls
# #   cdef uint8_t*  expArray
# #   cdef uint16_t* dirArray
# #   cdef np.ndarray[float64_t,ndim=1] fi   # Holder for the solution  
  
# #   # cdef np.ndarray[float64_t, ndim=1] 
  
# #   cdef object K0, Kj#, A0
# #   cdef uint16_t* dirA = p_dH[order-1].p_udirA
# #   cdef uint16_t* dirX = &p_dH[order-1].p_udirA[order]
# #   cdef uint8_t* expA = p_dH[order-1].p_uexpA
# #   cdef uint8_t* expX = &p_dH[order-1].p_uexpA[order]
# #   # cdef uint8_t* newExpA
# #   # Create a copy of A?
# #   # Change the type of sparse matrix to CSR
# #   A.tocsr()
# #   print("In solve LU, kwargs: ", kwargs)
# #   # A0 = spr.linalg.spilu(A[ZERO].tocsc(),**kwargs)
# #   A0 = spr.linalg.splu(A[ZERO].tocsc(),**kwargs)

# #   # TODO: Check dimensions of b, A to match.
  
# #   # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
# #   for i in range(A.Ndir):
    
# #     fi = b.data[:,i]

# #     # Get direction and exponent arrays:
# #     expArray = c_helper_getExpA(i,A.order,p_dH)
# #     dirArray = c_helper_getDirA(i,A.order,p_dH)

# #     # get the multiples of the exponent array:
# #     c_helper_getMultpl(expArray,order,p_dH, &Nmultpls)
    
# #     # c_Py_print2DArrayUI8(multiples, Nmultpls, order)
# #     # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
# #     # loop in all multiples
# #     for j in range(Nmultpls-1):

# #       # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
# #       pos = Nmultpls-j-1

# #       c_helper_ordDirExpA(dirArray,    &multiples[pos*order] , order,\
# #                   dirA, expA)
      
# #       # print("\n\nA: multiple position: ",pos)
# #       # c_Py_printArrayUI16(dirA,order)
# #       # c_Py_printArrayUI8(expA,order)

# #       # Get the mirrored multiple for vector X
# #       c_helper_ordDirExpA(dirArray,    &multiples[j*order] , order, \
# #                   dirX, expX)
      
# #       # print("\nX: multiple position: ",j)
# #       # c_Py_printArrayUI16(dirX,order)
# #       # c_Py_printArrayUI8(expX,order)
      
# #       # Get the equivalent index for A.
# #       indxA = c_helper_findIndex(dirA, expA, order,p_dH)

# #       if dirX[0] == 0:

# #         indxX = 0

# #       else:

# #         # Get the equivalent index for X.
# #         indxX = c_helper_findIndex(dirX, expX, order,p_dH)

# #       # end if 
      
# #       # print("indxA",indxA, getDirArray(indxA,order))
# #       # print("indxX ",indxX,getDirArray(indxX,order))
      
# #       # Subtract A_indxA * x_indxX to the fi vector
# #       fi -= A[indxA].dot(x.data[:,indxX])

# #       # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
# #       # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
# #     # end for

# #     # TODO: Change according to all different solvers selected.

# #     x.data[:,i]  = A0.solve(fi)   # Solve factorized system

# #   # end for

# #   return x

# # #-----------------------------------------------------------------------------------------------------

# # #*****************************************************************************************************
# # def solve(spr_omat A, ndarray b, solver = 0):
# #   """
# #   PURPOSE:  Solve a system Ax = b

# #   """
# #   #***************************************************************************************************

# #   global p_dH

# #   cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
# #   cdef uint64_t i, indxX, indxA, k
# #   cdef uint8_t  j , pos, order = A.order
# #   cdef uint8_t* multiples = p_dH[order-1].p_multpl
# #   cdef uint64_t Nmultpls
# #   cdef uint8_t*  expArray
# #   cdef uint16_t* dirArray
# #   cdef np.ndarray[float64_t,ndim=1] fi, solvedX   # Holder for the solution  
  
# #   # cdef np.ndarray[float64_t, ndim=1] 
  
# #   cdef object K0, Kj#, A0
# #   cdef uint16_t* dirA = p_dH[order-1].p_udirA
# #   cdef uint16_t* dirX = &p_dH[order-1].p_udirA[order]
# #   cdef uint8_t* expA = p_dH[order-1].p_uexpA
# #   cdef uint8_t* expX = &p_dH[order-1].p_uexpA[order]
# #   # cdef uint8_t* newExpA
# #   # Create a copy of A?
# #   # Change the type of sparse matrix to CSR
# #   A.tocsr()

# #   # A0 = spr.linalg.splu(A[ZERO].tocsc())

# #   # TODO: Check dimensions of b, A to match.
  
# #   # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
# #   for i in range(A.Ndir):
    
# #     fi = b.data[:,i]

# #     # Get direction and exponent arrays:
# #     expArray = c_helper_getExpA(i,A.order,p_dH)
# #     dirArray = c_helper_getDirA(i,A.order,p_dH)

# #     # get the multiples of the exponent array:
# #     c_helper_getMultpl(expArray,order,p_dH, &Nmultpls)
    
# #     # c_Py_print2DArrayUI8(multiples, Nmultpls, order)
# #     # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
# #     # loop in all multiples
# #     for j in range(Nmultpls-1):

# #       # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
# #       pos = Nmultpls-j-1

# #       c_helper_ordDirExpA(dirArray,    &multiples[pos*order] , order,\
# #                   dirA, expA)
      
# #       # print("\n\nA: multiple position: ",pos)
# #       # c_Py_printArrayUI16(dirA,order)
# #       # c_Py_printArrayUI8(expA,order)

# #       # Get the mirrored multiple for vector X
# #       c_helper_ordDirExpA(dirArray,    &multiples[j*order] , order, \
# #                   dirX, expX)
      
# #       # print("\nX: multiple position: ",j)
# #       # c_Py_printArrayUI16(dirX,order)
# #       # c_Py_printArrayUI8(expX,order)
      
# #       # Get the equivalent index for A.
# #       indxA = c_helper_findIndex(dirA, expA, order,p_dH)

# #       if dirX[0] == 0:

# #         indxX = 0

# #       else:

# #         # Get the equivalent index for X.
# #         indxX = c_helper_findIndex(dirX, expX, order,p_dH)

# #       # end if 
      
# #       # print("indxA",indxA, getDirArray(indxA,order))
# #       # print("indxX ",indxX,getDirArray(indxX,order))
      
# #       # Subtract A_indxA * x_indxX to the fi vector
# #       fi -= A[indxA].dot(x.data[:,indxX])

# #       # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
# #       # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
# #     # end for

# #     # TODO: Change according to all different solvers selected.

# #     # print(string)
    
# #     solvedX = spr.linalg.spsolve( A[ZERO], fi )
# #     # x.data[:,i]  = A0.solve(fi)   # Solve factorized system

# #     for k in range(<uint64_t>solvedX.size):

# #       x.data[k,i] = solvedX[k] 

# #     # end for

# #   # end for

# #   return x

# # #-----------------------------------------------------------------------------------------------------

# # UTILS

# #*****************************************************************************************************
# def helper_get_multpl(hum_dir):
    
#     global h

#     cdef uint64_t i=0, k=0, Nmultpl=1
#     cdef uint8_t passed
#     cdef np.ndarray multiple, multiples
#     cdef np.ndarray bases
#     cdef np.ndarray exp
    
#     bases, exp = h.get_base_exp(*imdir(hum_dir))

#     order = np.sum(exp)

#     multiple = np.empty(exp.size, dtype = np.uint8)
    
#     for i in range(exp.size):
#       # Multiply by the number of possible values of each basis exponent.
#       Nmultpl *= exp[i]+1;

#       # Initialize the multiple holder's values.
#       multiple[i] = 0;  # First multiple is real (all exps zero).
      
#     # end for 

#     multiples = np.zeros( ( Nmultpl, exp.size ), dtype = np.uint8)

#     for i in range(1,Nmultpl):

#       passed = 0; # termination flag off.
#       k=0;        # Set the counter to the initial position

#       while(passed == 0 and k<exp.size):

#         # Check if the current exponent can be summed 1 and still meet the 
#         # exponent array limits.
#         if( (multiple[k]+1) > exp[k]) :
            
#             # This means that if the current k'th exponent + 1 will not meet 
#             # the conditions.
#             multiple[k] = 0 # reset the current exponent
#             k+=1             # go to next position.

#         else :

#             # the exponent can be summed 1.
#             multiple[k] += 1
#             passed = 1        # rise the flag.

#         # end if 

#       # end while

#       for k in range(exp.size):

#           multiples[i,k] = multiple[k];

#       # end for 

#     # end for

#     return bases,multiples

# #-----------------------------------------------------------------------------------------------------
