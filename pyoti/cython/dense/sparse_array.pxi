







# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  spr_omat   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class spr_omat:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  #                                --->      Look in spr_omat.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self, shape, bases_t nbases = 0 , ord_t order = 0, uint8_t spr_type = 2):
    """
    PURPOSE:      Constructor of the spr_omat class.

    DESCRIPTION:  Creates a new sparse oti matrix OTI matirx.

    

    ## Constructor 1: Empty constructor. ##

      DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

    Arguments:
                  
                  shape:  Shape of the matrix.

                  order:  Maximum order of the OTI numbers that will be stored. Default: 1

                  m:      Number of basis the vector will have.

                  spr_type: Type of sparse matrix to be created.  0: csr, 1: coo, 2: lil

                  
    """

    global dhl

    


    cdef uint64_t i
    cdef ord_t ordi


    self.order  = order
    self.nbases = nbases       
    self.nrows  = shape[0]
    self.ncols  = shape[1]
    self.size   = self.nrows * self.ncols 
    self.ndir   = 0 # Initialize the number of imaginary directions.
    self.spr_type = spr_type



    base_sprmat_creator = self.get_base_sprmat_creator()

      
    # create real element

    self.re = base_sprmat_creator( shape , dtype = np.float64)

    self.p_im   = np.empty( self.order, dtype=np.ndarray)
    self.p_ndpo = np.zeros( self.order, dtype=np.uint64)

    for ordi in range(self.order):
      
      self.p_ndpo[ordi] = dhelp_extract_ndirOrder( self.nbases, ordi+1, dhl )
      
      self.p_im[ordi]   = np.empty( self.p_ndpo[ordi], dtype=object)

      self.ndir += self.p_ndpo[ordi]

      for i in range(self.p_ndpo[ordi]):

        self.p_im[ordi][i] = base_sprmat_creator( shape , dtype = np.float64)
      

    # end for

    

  #---------------------------------------------------------------------------------------------------



  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print the representation of the class.

    """
    #*************************************************************************************************

    head = '<spr_omat, '
    tail = ">"
    body = ''
    body += 'shape: ('+str(self.nrows)+","+str(self.ncols)+'), '
    body += 'ndir: ' + str(self.ndir) +', '
    body += 'nbases: ' + str(self.nbases) +', '
    body += 'order: ' + str(self.order) + ', ' 

    if self.spr_type == 0:     # CSR Matrix
      
      body += "spr_type: csr"

    elif self.spr_type == 1:   # COO Matrix
      
      body += "spr_type: coo" 

    elif self.spr_type == 2:

      body += "spr_type: lil"  

    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef object get_base_sprmat_creator(self):
    """
    PORPUSE: Obtain the sparse matrix creator required to generate the corresponding 
             sparse matrix elements.
    """

    from scipy.sparse import csr_matrix, coo_matrix, lil_matrix

    if self.spr_type == 0:     # CSR Matrix
      
      base_sprmat_creator = csr_matrix

    elif self.spr_type == 1:   # COO Matrix
      
      base_sprmat_creator = coo_matrix 

    elif self.spr_type == 2:   # LIL matrix

      base_sprmat_creator = lil_matrix  

    else:

      raise TypeError("Unknown spr_type: "+str(self.spr_type)+". Try 0: CSR matrix or 1: COO matrix.")

    # end if 

    return base_sprmat_creator
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the spr_otinum object that could 
             be easy to read and understand.  
    

    """
    #*************************************************************************************************
    
    cdef uint64_t i
    cdef ord_t ordi
    # cdef uint64_t[:] indx = np.arange(self.Ndir,dtype = np.uint64)
    # cdef spr_otinum spr_oti

    head = '< spr_omat class, '
    tail = " >"

    body = ''
    body += 'shape: ('+str(self.nrows)+","+str(self.ncols)+'), '
    body += 'ndir: ' + str(self.ndir) +', '
    body += 'nbases: ' + str(self.nbases) +', '
    body += 'order: ' + str(self.order) + ', \n' 

    body += str(self.re)+"\n"
    for ordi in range(self.order):

      for i in range(self.p_ndpo[ordi]):

        body += '+ e(' 
        
        body += str(h.get_compact_fulldir(i,ordi+1)).replace(' ','')
        body += ") * \n"
        body += str(self.p_im[ordi][i])+'\n'

      # end for 
    # end for
    
    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __getitem__(self, index):
    """
    PURPOSE:  To get the value of a spr_omat coefficient.

    """
    #*************************************************************************************************
    
    global dhl

    cdef otinum_t res_oti

    # Try first the following:
    tmp = self.re[index]
    
    if type(tmp) == np.float64:
    
      # result is an otinum
      res_oti = oti_createEmpty(self.nbases, self.order, dhl)

      res_oti.re = self.re[index]

      for ordi in range(self.order):
        
        for i in range(self.p_ndpo[ordi]):

          res_oti.p_im[ordi][i] = self.p_im[ordi][i][index]


        # end for 

      # end for 

      return otinum.create(&res_oti)

    else:

      res_mat = spr_omat( tmp.shape, nbases=self.nbases,
                          order=self.order,spr_type=self.spr_type   )

      res_mat.re = self.re[index]

      for ordi in range(self.order):
        
        for i in range(self.p_ndpo[ordi]):

          res_mat.p_im[ordi][i] = self.p_im[ordi][i][index]


        # end for 

      # end for 
      
      
      return res_mat

    # end if.

    
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, index, value):
    """
    PURPOSE:  To set the value of an spr_omat coefficient.

    """
    #*************************************************************************************************
    cdef ord_t ordi
    cdef uint64_t i

    t_value = type(value)

    if t_value == otinum:

      self.set_from_otinum(index, value)

    else: 
      
      self.re[index] = value

      for ordi in range(self.order):

        for i in range(self.p_ndpo[ordi]):

          self.p_im[ordi][i][index] = 0.0

        # end for 

      # end for

    # end if 


  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  cpdef set_from_otinum(self, index, otinum in_otinum):
    """
    PORPUSE: Set element by otinum.

    """

    cdef uint64_t i 
    cdef ord_t ordi, loop_order
    cdef flag_t greater_order, greater_nbases
    cdef bases_t 

    greater_order  = in_otinum.num.order  > self.order
    greater_nbases = in_otinum.num.nbases > self.nbases
    
    
    if greater_nbases:

      self.change_nbases(in_otinum.num.nbases)

    # end if 


    if greater_order:
    
      self.change_order(in_otinum.num.order)  
    
    # end if 

    

    self.re[index] = in_otinum.num.re

    # At this point they either have the same nbases and order or the number has lower.

    for ordi in range(in_otinum.num.order):
      
      for i in range(in_otinum.num.p_ndpo[ordi]):
      
        self.p_im[ordi][i][index] = in_otinum.num.p_im[ordi][i]

      # end for

      # Fill the others with zero.
      for i in range(in_otinum.num.p_ndpo[ordi],self.p_ndpo[ordi]):
      
          self.p_im[ordi][i][index] = 0.0

      # end for

    # end for      

    for ordi in range(in_otinum.num.order,self.order):
      
      # Fill the others with zero.
      for i in range(self.p_ndpo[ordi]):

          self.p_im[ordi][i][index] = 0.0

      # end for

    # end for


  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  cdef set_and_sum_from_otinum_t(self, tuple index, otinum_t* num):
    """
    PURPOSE:  Add to an element of the array from a sotinum_t

    """
    cdef uint64_t i 
    cdef ord_t ordi, loop_order
    cdef flag_t greater_order, greater_nbases
    cdef bases_t 

    greater_order  = num[ZERO].order  > self.order
    greater_nbases = num[ZERO].nbases > self.nbases
    
    
    if greater_nbases:

      self.change_nbases(num[ZERO].nbases)

    # end if 


    if greater_order:
    
      self.change_order(num[ZERO].order)  
    
    # end if 

    

    self.re[index] = num[ZERO].re

    # At this point they either have the same nbases and order or the number has lower.

    for ordi in range(num[ZERO].order):
      
      for i in range(num[ZERO].p_ndpo[ordi]):
        
        self.p_im[ordi][i][index] += num[ZERO].p_im[ordi][i]

      # end for

    # end for      

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def set_and_sum_from_otinum(self, tuple index, otinum in_otinum):
    """
    PURPOSE:  Add to an element of the array from a sotinum_t

    """
    cdef uint64_t i 
    cdef ord_t ordi, loop_order
    cdef flag_t greater_order, greater_nbases
    cdef bases_t 

    greater_order  = in_otinum.num.order  > self.order
    greater_nbases = in_otinum.num.nbases > self.nbases
    
    
    if greater_nbases:

      self.change_nbases(in_otinum.num.nbases)

    # end if 


    if greater_order:
    
      self.change_order(in_otinum.num.order)  
    
    # end if 

    

    self.re[index] = in_otinum.num.re

    # At this point they either have the same nbases and order or the number has lower.

    for ordi in range(in_otinum.num.order):
      
      for i in range(in_otinum.num.p_ndpo[ordi]):
        
        self.p_im[ordi][i][index] += in_otinum.num.p_im[ordi][i]

      # end for

    # end for      

    

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def change_nbases_order(self,bases_t new_nbases, ord_t new_order):
    """
    PURPOSE:  Change allocation to new order.

    """
    #*************************************************************************************************
    
    # First change nbases.
    self.change_nbases(new_nbases)

    # then change order.
    self.change_order(new_order)
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef change_order(self, ord_t new_order):
    """
    PORPUSE: Change in memory the order with corresponding allocation changesa

    """

    cdef uint64_t i
    cdef ord_t ordi
    cdef ndir_t new_ndir
    # cdef np.ndarray new_p_im, new_p_ndpo
    
    shape = (self.nrows, self.ncols) # Get shape

    base_sprmat_creator = self.get_base_sprmat_creator() # Get creator.

    # In case the order changes.
    if( new_order > self.order ):
      
      
      # Requires creation of new element
      self.p_im   = np.resize(self.p_im  ,new_order)

      self.p_ndpo = np.resize(self.p_ndpo,new_order)

      # just modify the new ones
      for ordi in range(self.order, new_order):
        
        self.p_ndpo[ordi] = dhelp_extract_ndirOrder( self.nbases, ordi+1, dhl )
        
        self.p_im[ordi]   = np.empty( self.p_ndpo[ordi], dtype=object)

        # Create new arrays to the new elements.
        for i in range(self.p_ndpo[ordi]):

          self.p_im[ordi][i] = base_sprmat_creator( shape , dtype = np.float64)
      
        # end for 

      # end for 

      self.order = new_order
    
    elif( new_order < self.order ):

      # Requires creation of new element
      
      self.p_im   = np.resize(self.p_im  ,new_order)
      self.p_ndpo = np.resize(self.p_ndpo,new_order)

      self.order = new_order

    # end if 

    # Recompute ndir.
    self.recompute_ndir()
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef change_nbases(self,bases_t new_nbases):
    """
    PORPUSE: Change in memory the nbases for allocation.
    """
    cdef uint64_t i
    cdef ord_t ordi
    cdef ndir_t new_ndir
    # cdef np.ndarray tmp_p_im_i

    shape = (self.nrows, self.ncols) # Get shape

    base_sprmat_creator = self.get_base_sprmat_creator() # Get creator.

    if(new_nbases > self.nbases ):

      # Elements should be resized and allocated.
      for ordi in range(self.order):

        new_ndir = dhelp_extract_ndirOrder( new_nbases, ordi+1, dhl )

        self.p_im[ordi] = np.resize( self.p_im[ordi], new_ndir)
        # tmp_p_im_i = np.empty(new_ndir, dtype = self.self.p_im[ordi].dtype)
        # tmp_p_im_i[1:self.p_ndpo[ordi]] = self.p_im[ordi][:]

        for i in range(self.p_ndpo[ordi], new_ndir):

          self.p_im[ordi][i] = base_sprmat_creator( shape , dtype = np.float64)

        # end for 

        self.p_ndpo[ordi] = new_ndir

      # end for 

      self.nbases = new_nbases

    elif(new_nbases < self.nbases ):

      # Elements should be resized but remains with the same number of elements.
      for ordi in range(self.order):

        new_ndir = dhelp_extract_ndirOrder( new_nbases, ordi+1, dhl )

        self.p_im[ordi] = np.resize( self.p_im[ordi], new_ndir)
        
        self.p_ndpo[ordi] = new_ndir

      # end for 

      self.nbases = new_nbases

    # end if 

    # Recompute ndir.
    self.recompute_ndir()
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef recompute_ndir(self):
    """
    PURPOSE:  Convert to CSR sparse format.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i
    cdef ord_t ordi

    self.ndir = 0
    
    for ordi in range(self.order):

      self.ndir += self.p_ndpo[ordi]

    # end for

  #---------------------------------------------------------------------------------------------------   

  #***************************************************************************************************
  def to_csr(self):
    """
    PURPOSE:  Convert to CSR sparse format.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i
    cdef ord_t ordi

    self.re = self.re.tocsr()
    
    for ordi in range(self.order):

      for i in range(self.p_ndpo[ordi]):

        self.p_im[ordi][i] = self.p_im[ordi][i].tocsr()

      # end for
    
    # end for


  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def to_coo(self):
    """
    PURPOSE:  Convert to COO sparse format.

    """
    #*************************************************************************************************
    
    cdef uint64_t i
    cdef ord_t ordi

    self.re = self.re.tocoo()
    
    for ordi in range(self.order):

      for i in range(self.p_ndpo[ordi]):

        self.p_im[ordi][i] = self.p_im[ordi][i].tocoo()

      # end for
    
    # end for

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def to_lil(self):
    """
    PURPOSE:  Convert to LIL sparse format.

    """
    #*************************************************************************************************
        
    cdef uint64_t i
    cdef ord_t ordi

    self.re = self.re.tolil()
    
    for ordi in range(self.order):

      for i in range(self.p_ndpo[ordi]):

        self.p_im[ordi][i] = self.p_im[ordi][i].tolil()

      # end for
    
    # end for

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def to_dense(self):
    """
    PURPOSE:  Convert to dense omat representation.

    """
    #*************************************************************************************************
    
    global dhl

    cdef uint64_t i
    cdef ord_t ordi
    cdef np.ndarray tmp
    cdef oarr_t res
    
    res = oarr_createEmpty(self.nrows, self.ncols, self.nbases, self.order, dhl)
    
    copy_numpy2d_to_ptr_f64(self.re.toarray(),res.re)
    
    for ordi in range(self.order):

      for i in range(self.p_ndpo[ordi]):

        copy_numpy2d_to_ptr_f64(self.p_im[ordi][i].toarray(),res.p_im[ordi][i])

      # end for
    
    # end for

    return omat.create(&res)

  #---------------------------------------------------------------------------------------------------














  #***************************************************************************************************
  def get_deriv(self, hum_dir):
    """
    PURPOSE:  Get the factor to be multiplied to the coprresponding imaginary coefficient to get the 
              exact value of the derivative.
    """
    #***************************************************************************************************
    global dhl

    cdef list item = imdir(hum_dir)
    
    cdef coeff_t factor

    # Check first if derivative is the real coefficient.

    if item[ONE] == 0: # order 0.
    
      return self.re
    
    else:
      
      factor = dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

      return factor * self.p_im[ item[ONE]-1 ][ item[ZERO] ]

    # end if 

  #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def setDual(self, dirArray, value):
  #   """
  #   PURPOSE:      To add a human friendly form to set elements of a 
  #                 spr_otinum.
    
  #   EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
  #                 >>> print(a)
  #                 1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
  #                 >>> a.setDual([1,3],10)
  #                 >>> print(a)
  #                 1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
  #                 >>> a.setDual([1],2.5)
  #                 >>> print(a)
  #                 1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
  #   """
  #   #*************************************************************************************************
  
  #   if type(dirArray)==int:
    
  #     indxArray = [dirArray]

  #   else:

  #     indxArray = dirArray
      
  #   # end if
      
  #   tmp_dirA,tmp_expA = getDirExpA(indxArray)

  #   cdef uint8_t maxorder = np.sum(tmp_expA)
  #   cdef uint8_t i
  #   cdef uint64_t indx

  #   if maxorder > self.maxorder:

  #     raise ValueError("dirArray must correspond with the maxorder of the otivec")

  #   # end if 
    
  #   # create the real direction arrays:
  #   dirA = np.zeros(self.maxorder,dtype = np.uint16)
  #   expA = np.zeros(self.maxorder,dtype = np.uint8)
    
  #   for i in range(len(tmp_expA)):
      
  #     dirA[i] = tmp_dirA[i]
  #     expA[i] = tmp_expA[i]

  #   # end for 

  #   if indxArray[0] == 0:
        
  #     indx = 0

  #   elif self.maxorder == 1:

  #     indx = indxArray[0]

  #   else:

  #     indx = h.findIndx(dirA,expA,self.maxorder)

  #   # end if


  #   self.elements[indx] = value

  

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
  #   """
  #   PURPOSE:      to retrieve the n'th derivative according to the taylor 
  #                 series expansion with dual numbers.
                
  #   DESCRIPTION:  Simply given the combinations of derivatives with the 
  #                 dirArray, the function multiplys the terms that require
  #                 extra factors to get the desired derivatives.
    
    

  #   """
  #   #*************************************************************************************************
    
  #   cdef uint8_t   order = np.sum(expA)
    
  #   # If asking for a coefficient of higher order, return 0.0
  #   if order > self.maxorder:

  #     if self.spr_type == 0:
        
  #       return spr.csr_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

  #     elif self.spr_type == 1:
        
  #       return spr.coo_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

  #     elif self.spr_type == 2:
        
  #       return spr.lil_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

  #     # end if 

  #   # end if 
    
  #   cdef float64_t factor = 1.0
  #   cdef uint16_t[::1] tmp_dirA = np.zeros(self.maxorder,dtype = np.uint16)
  #   cdef uint8_t[::1]  tmp_expA = np.zeros(self.maxorder,dtype = np.uint8)
  #   cdef uint8_t i

    
  #   # Compute the multiplication factor and fill in the temporary arrays.

  #   for i in range(dirA.size):
      
  #     factor *= factorial(expA[i])
  #     tmp_dirA[i] = dirA[i]
  #     tmp_expA[i] = expA[i]
    
  #   # end for
    
    
  #   indx  = h.findIndx(tmp_dirA,tmp_expA,self.maxorder)
    
  #   cdef object mat = self.elements[indx] * factor

    
        
  #   return mat

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def getDeriv(self, dirArray):
  #   """
  #   PURPOSE:      to retrieve the n'th derivative according to the taylor 
  #                 series expansion with dual numbers.
                
  #   DESCRIPTION:  Simply given the combinations of derivatives with the 
  #                 dirArray, the function multiplys the terms that require
  #                 extra factors to get the desired derivatives.
    
  #   EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
  #                 >>>
  #                 >>> getDerivative(a,[0])
  #                 1.
  #                 >>> getDerivative(a,[1])
  #                 2.
  #                 >>> getDerivative(a,[[1,2]])
  #                 6.
  #                 >>> getDerivative(a,[2])
  #                 4.
  #                 >>> getDerivative(a,[1,2])
  #                 5.
  #                 >>> getDerivative(a,[[2,2]])
  #                 12.

  #   """
  #   #*************************************************************************************************

  #   if type(dirArray)==int:
      
  #     indxArray = [dirArray]
      
  #   else:
      
  #     indxArray = dirArray
      
  #   # end if

    
  #   tmp_dirA,tmp_expA = getDirExpA(dirArray)
  #   cdef uint8_t maxorder = np.sum(tmp_expA)
  #   cdef uint8_t i
  #   cdef uint64_t indx

  #   # create the real direction arrays:
  #   cdef uint16_t[::1] dirA = np.zeros(maxorder,dtype = np.uint16)
  #   cdef uint8_t[::1]  expA = np.zeros(maxorder,dtype = np.uint8)
    
  #   for i in range(len(tmp_expA)):
      
  #     dirA[i] = tmp_dirA[i]
  #     expA[i] = tmp_expA[i]

  #   # end for 


  #   return self.getDerivByDirExp(dirA,expA)

  # #---------------------------------------------------------------------------------------------------  




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class spr_omat :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
































# #*****************************************************************************************************
# def solveLU(spr_omat A, ndarray b, **kwargs):
#   """
#   PURPOSE:  Solve a system Ax = b

#   """
#   #***************************************************************************************************

  
#   global p_dH

#   cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
#   cdef uint64_t i, indxX, indxA, k
#   cdef uint8_t  j , pos, order = A.order
#   cdef uint8_t* multiples = p_dH[order-1].p_multpl
#   cdef uint64_t Nmultpls
#   cdef uint8_t*  expArray
#   cdef uint16_t* dirArray
#   cdef np.ndarray[float64_t,ndim=1] fi   # Holder for the solution  
  
#   # cdef np.ndarray[float64_t, ndim=1] 
  
#   cdef object K0, Kj#, A0
#   cdef uint16_t* dirA = p_dH[order-1].p_udirA
#   cdef uint16_t* dirX = &p_dH[order-1].p_udirA[order]
#   cdef uint8_t* expA = p_dH[order-1].p_uexpA
#   cdef uint8_t* expX = &p_dH[order-1].p_uexpA[order]
#   # cdef uint8_t* newExpA
#   # Create a copy of A?
#   # Change the type of sparse matrix to CSR
#   A.tocsr()
#   print("In solve LU, kwargs: ", kwargs)
#   # A0 = spr.linalg.spilu(A[ZERO].tocsc(),**kwargs)
#   A0 = spr.linalg.splu(A[ZERO].tocsc(),**kwargs)

#   # TODO: Check dimensions of b, A to match.
  
#   # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
#   for i in range(A.Ndir):
    
#     fi = b.data[:,i]

#     # Get direction and exponent arrays:
#     expArray = c_helper_getExpA(i,A.order,p_dH)
#     dirArray = c_helper_getDirA(i,A.order,p_dH)

#     # get the multiples of the exponent array:
#     c_helper_getMultpl(expArray,order,p_dH, &Nmultpls)
    
#     # c_Py_print2DArrayUI8(multiples, Nmultpls, order)
#     # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
#     # loop in all multiples
#     for j in range(Nmultpls-1):

#       # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
#       pos = Nmultpls-j-1

#       c_helper_ordDirExpA(dirArray,    &multiples[pos*order] , order,\
#                   dirA, expA)
      
#       # print("\n\nA: multiple position: ",pos)
#       # c_Py_printArrayUI16(dirA,order)
#       # c_Py_printArrayUI8(expA,order)

#       # Get the mirrored multiple for vector X
#       c_helper_ordDirExpA(dirArray,    &multiples[j*order] , order, \
#                   dirX, expX)
      
#       # print("\nX: multiple position: ",j)
#       # c_Py_printArrayUI16(dirX,order)
#       # c_Py_printArrayUI8(expX,order)
      
#       # Get the equivalent index for A.
#       indxA = c_helper_findIndex(dirA, expA, order,p_dH)

#       if dirX[0] == 0:

#         indxX = 0

#       else:

#         # Get the equivalent index for X.
#         indxX = c_helper_findIndex(dirX, expX, order,p_dH)

#       # end if 
      
#       # print("indxA",indxA, getDirArray(indxA,order))
#       # print("indxX ",indxX,getDirArray(indxX,order))
      
#       # Subtract A_indxA * x_indxX to the fi vector
#       fi -= A[indxA].dot(x.data[:,indxX])


#       # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
#       # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
#     # end for

#     # TODO: Change according to all different solvers selected.

#     x.data[:,i]  = A0.solve(fi)   # Solve factorized system


#   # end for

#   return x



# #-----------------------------------------------------------------------------------------------------





# #*****************************************************************************************************
# def solve(spr_omat A, ndarray b, solver = 0):
#   """
#   PURPOSE:  Solve a system Ax = b

#   """
#   #***************************************************************************************************

#   global p_dH

#   cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
#   cdef uint64_t i, indxX, indxA, k
#   cdef uint8_t  j , pos, order = A.order
#   cdef uint8_t* multiples = p_dH[order-1].p_multpl
#   cdef uint64_t Nmultpls
#   cdef uint8_t*  expArray
#   cdef uint16_t* dirArray
#   cdef np.ndarray[float64_t,ndim=1] fi, solvedX   # Holder for the solution  
  
#   # cdef np.ndarray[float64_t, ndim=1] 
  
#   cdef object K0, Kj#, A0
#   cdef uint16_t* dirA = p_dH[order-1].p_udirA
#   cdef uint16_t* dirX = &p_dH[order-1].p_udirA[order]
#   cdef uint8_t* expA = p_dH[order-1].p_uexpA
#   cdef uint8_t* expX = &p_dH[order-1].p_uexpA[order]
#   # cdef uint8_t* newExpA
#   # Create a copy of A?
#   # Change the type of sparse matrix to CSR
#   A.tocsr()

#   # A0 = spr.linalg.splu(A[ZERO].tocsc())

#   # TODO: Check dimensions of b, A to match.
  
#   # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
#   for i in range(A.Ndir):
    
#     fi = b.data[:,i]

#     # Get direction and exponent arrays:
#     expArray = c_helper_getExpA(i,A.order,p_dH)
#     dirArray = c_helper_getDirA(i,A.order,p_dH)

#     # get the multiples of the exponent array:
#     c_helper_getMultpl(expArray,order,p_dH, &Nmultpls)
    
#     # c_Py_print2DArrayUI8(multiples, Nmultpls, order)
#     # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
#     # loop in all multiples
#     for j in range(Nmultpls-1):

#       # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
#       pos = Nmultpls-j-1

#       c_helper_ordDirExpA(dirArray,    &multiples[pos*order] , order,\
#                   dirA, expA)
      
#       # print("\n\nA: multiple position: ",pos)
#       # c_Py_printArrayUI16(dirA,order)
#       # c_Py_printArrayUI8(expA,order)

#       # Get the mirrored multiple for vector X
#       c_helper_ordDirExpA(dirArray,    &multiples[j*order] , order, \
#                   dirX, expX)
      
#       # print("\nX: multiple position: ",j)
#       # c_Py_printArrayUI16(dirX,order)
#       # c_Py_printArrayUI8(expX,order)
      
#       # Get the equivalent index for A.
#       indxA = c_helper_findIndex(dirA, expA, order,p_dH)

#       if dirX[0] == 0:

#         indxX = 0

#       else:

#         # Get the equivalent index for X.
#         indxX = c_helper_findIndex(dirX, expX, order,p_dH)

#       # end if 
      
#       # print("indxA",indxA, getDirArray(indxA,order))
#       # print("indxX ",indxX,getDirArray(indxX,order))
      
#       # Subtract A_indxA * x_indxX to the fi vector
#       fi -= A[indxA].dot(x.data[:,indxX])


#       # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
#       # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
#     # end for

#     # TODO: Change according to all different solvers selected.

#     # print(string)
    
#     solvedX = spr.linalg.spsolve( A[ZERO], fi )
#     # x.data[:,i]  = A0.solve(fi)   # Solve factorized system

#     for k in range(<uint64_t>solvedX.size):

#       x.data[k,i] = solvedX[k] 

#     # end for

#   # end for

#   return x



# #-----------------------------------------------------------------------------------------------------




# UTILS










#*****************************************************************************************************
def helper_get_multpl(hum_dir):
    
    global h

    cdef uint64_t i=0, k=0, Nmultpl=1
    cdef uint8_t passed
    cdef np.ndarray multiple, multiples
    cdef np.ndarray bases
    cdef np.ndarray exp
    
    bases, exp = h.get_base_exp(*imdir(hum_dir))

    order = np.sum(exp)

    multiple = np.empty(exp.size, dtype = np.uint8)
    
    for i in range(exp.size):
      # Multiply by the number of possible values of each basis exponent.
      Nmultpl *= exp[i]+1;

      # Initialize the multiple holder's values.
      multiple[i] = 0;  # First multiple is real (all exps zero).
      
    # end for 

    multiples = np.zeros( ( Nmultpl, exp.size ), dtype = np.uint8)

    for i in range(1,Nmultpl):

      passed = 0; # termination flag off.
      k=0;        # Set the counter to the initial position

      while(passed == 0 and k<exp.size):

        # Check if the current exponent can be summed 1 and still meet the 
        # exponent array limits.
        if( (multiple[k]+1) > exp[k]) :
            
            # This means that if the current k'th exponent + 1 will not meet 
            # the conditions.
            multiple[k] = 0 # reset the current exponent
            k+=1             # go to next position.

        else :

            # the exponent can be summed 1.
            multiple[k] += 1
            passed = 1        # rise the flag.

        # end if 

      # end while

      for k in range(exp.size):

          multiples[i,k] = multiple[k];

      # end for 

    # end for

    return bases,multiples

#-----------------------------------------------------------------------------------------------------
