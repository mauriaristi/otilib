# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=True
# cython: linetrace=True
# cython: binding=True
# cython: embedsignature=False
# distutils: define_macros=CYTHON_TRACE_NOGIL=1
# distutils: libraries = oti 
## distutils: extra_compile_args = -arch i386 -arch x86_64
# filename: spr_omat.pyx

# import scipy.sparse as spr
# import numpy as np                  # General numerical library
# cimport numpy as np                 # C-level functions of numpy
# from pyoti.core  import   number_types, getDirArray, dHelp, int_types,findComb
# from pyoti.core  cimport  p_dH, ZERO, ONE, c_getDirExpA
# from pyoti.core  cimport  get_cython_dHelp, dHelp
# import pyoti.dense
# from   pyoti.dense   cimport  otinum
# from   pyoti.ndarray cimport  ndarray

# Get the Cython version of the helper
cdef dHelp h = get_cython_dHelp()



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
  def __cinit__(self, shape, m,order, spr_type): #*args, **kwargs
    """
    PURPOSE:      Constructor of the spr_omat class.

    DESCRIPTION:  Creates a new OTI matirx given different types of constructors.

    

    ## Constructor 1: Empty constructor. ##

      DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

    Arguments:
                  
                  shape:  Shape of the matrix.

                  order:  Maximum order of the OTI numbers that will be stored. Default: 1

                  m:      Number of basis the vector will have.

                  spr_type: Type of sparse matrix to be created.  0: csr, 1: coo, 2: lil

                  
    """

    self.order = order
    self.m        = m       
    self.shape    = np.array(shape, dtype = np.uint64)
    self.Ndir     = findComb(self.m+1, self.order)    
    self.spr_type = spr_type


    cdef uint64_t i

    if spr_type == 0:     # CSR Matrix
      
      self.elements = np.empty(self.Ndir,dtype = spr.csr_matrix)

      for i in range(self.Ndir):
        
        self.elements[i] = spr.csr_matrix(shape,dtype = np.float64)

      # end for

    elif spr_type == 1:   # COO Matrix
      
      self.elements = np.empty(self.Ndir,dtype = spr.coo_matrix)

      for i in range(self.Ndir):
        
        self.elements[i] = spr.coo_matrix(shape,dtype = np.float64)

      # end for

    elif spr_type == 2:   # LIL Matrix
      
      self.elements = np.empty(self.Ndir,dtype = spr.lil_matrix)

      for i in range(self.Ndir):
        
        self.elements[i] = spr.lil_matrix(shape,dtype = np.float64)

      # end for

    else:

      raise TypeError("Unknown spr_type: "+str(spr_type)+". Try 0: CSR matrix or 1: COO matrix.")

    # end if 

  #---------------------------------------------------------------------------------------------------



  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the dualnum object that could be
              used to create new dualnum objects, in a compact form.
  
    EXAMPLE:  
              >>> spr_otinum([0,1,2,5],[1,2,3,4],2)
              spr_otinum([0,1,2,5],[1.,2.,3.,4.],2)
              
              >>> spr_otinum([0,1,2,4],[1,2,3,4],1)
              spr_otinum([0,1,2,4],[1.,2.,3.,4.],1)
    """
    #*************************************************************************************************

    head      = '< spr_omat'
    body      = ''
    body += ' of shape ('+str(self.shape[0])+","+str(self.shape[1])+') with oti numbers of'
    body += ' order ' + str(self.order) 
    body += ' and ' + str(self.m)+' basis'
    tail = " >"
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the spr_otinum object that could 
             be easy to read and understand.  
    
    EXAMPLE:  
              >>> spr_otinum([0,1,2,5],[1,2,3,4],2)
              1.0 + 2.0 * e(1) + 3.0 * e([[1,2]]) + 4.0 * e([1,2])
              
              >>> spr_otinum([0,1,2,4],[1,2,3,4],1)
              1.0 + 2.0 * e(1) + 3.0 * e(2) + 4.0 * e(3)
    """
    #*************************************************************************************************
    
    cdef uint64_t i
    # cdef uint64_t[:] indx = np.arange(self.Ndir,dtype = np.uint64)
    # cdef spr_otinum spr_oti

    head      = '< spr_omat'
    body      = ''
    body += ' of shape ('+str(self.shape[0])+","+str(self.shape[1])+') with oti numbers of'
    body += ' order ' + str(self.order) 
    body += ' and ' + str(self.m)+' basis: \n'
    body += "["

    for i in range(0,self.Ndir):
      
      body += '  ' + repr(self.elements[i])+ ',\n'
      
    # end for

    body = body[:-2]
    tail = "] >"
    
    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __getitem__(self, index):
    """
    PURPOSE:  To get the value of a spr_omat coefficient.

    """
    #*************************************************************************************************
    
    
    cdef np.ndarray[float64_t,ndim=1] newcoefs = np.empty(self.Ndir,dtype = np.float64)
    
    cdef object mat

    cdef uint64_t i 

    cdef otinum oti


    if type(index) == tuple:
      
      for i in range(self.Ndir):

        newcoefs[i] = self.elements[i][index]

      # end for 
      
      # spr_oti = spr_otinum(newindx,newcoefs,self.maxorder)
      # spr_oti.checkZeros()
      oti = otinum(newcoefs, self.order)

      return oti


    # TODO: add support for slices.
    # elif type(index) == slice:



    elif type(index) == int: # integer

      if index > self.Ndir:
        
        raise IndexError("Index out of bounds.")

      # end if 

      return self.elements[index]

      # end if 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, index, value):
    """
    PURPOSE:  To set the value of an spr_omat coefficient.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i 
    

    if type(index) == tuple:      


      for i in range(self.Ndir):
        self.elements[i][index] = value[i] # safe manner to add whatever the value has.
      # end for

    # TODO: add support for slices.
    # elif type(index) == slice:

    elif type(index) == int: # integer

      if index > self.Ndir:
        
        raise IndexError("Index out of bounds.")

      # end if 

      self.elements[index] = value # Add a new matrix...

    # end if 


  #--------------------------------------------------------------------------------------------------- 
  


  #***************************************************************************************************
  cdef void c_setSumFromSotinum(self, list index, sotinum_t* value):
    """
    PURPOSE:  Add to an element of the array from a sotinum_t

    """
    cdef uint64_t i, imDir, iZero_ = 0
    cdef double matCoef

    for i in range(value[iZero_].size):
      
      

      imDir = value[iZero_].p_indx[i]

      # print("Setting element direction ",imDir, " in position " ,index)

      matCoef = self.elements[imDir][index[0], index[1]]

      # print("  set coeff ",matCoef)

      # print("  as  ",matCoef + value[iZero_].p_coefs[i] )

      self.elements[imDir][ index[0], index[1] ] = matCoef + value[iZero_].p_coefs[i] 
    
    # end for

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def tocsr(self):
    """
    PURPOSE:  Convert to CSR sparse format.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i

    for i in range(self.Ndir):

      self.elements[i] = self.elements[i].tocsr()
    
    # end for
  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def tocoo(self):
    """
    PURPOSE:  Convert to CSR sparse format.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i

    for i in range(self.Ndir):

      self.elements[i] = self.elements[i].tocoo()
    
    # end for
  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def tolil(self):
    """
    PURPOSE:  Convert to CSR sparse format.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i

    for i in range(self.Ndir):

      self.elements[i] = self.elements[i].tolil()
    
    # end for
  #---------------------------------------------------------------------------------------------------



  # #***************************************************************************************************
  # def getDual(self, dirArray):
  #   """
  #   PURPOSE:      To add a human friendly form to get elements from a 
  #                 spr_otinum.
    
  #   EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
  #                 >>> print(a)
  #                 1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
  #                 >>> a.getDual([1,3])
  #                 5.0
  #                 >>> a.getDual([1])
  #                 0.0
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

  #     if self.spr_type == 0:
        
  #       return spr.csr_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

  #     elif self.spr_type == 1:
        
  #       return spr.coo_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

  #     elif self.spr_type == 2:
        
  #       return spr.lil_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

  #     # end if  
    
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
    
  #   return self.elements[indx]

  # #---------------------------------------------------------------------------------------------------  


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
































#*****************************************************************************************************
def solveLU(spr_omat A, ndarray b, **kwargs):
  """
  PURPOSE:  Solve a system Ax = b

  """
  #***************************************************************************************************

  
  global p_dH

  cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
  cdef uint64_t i, indxX, indxA, k
  cdef uint8_t  j , pos, order = A.order
  cdef uint8_t* multiples = p_dH[order-1].p_multpl
  cdef uint64_t Nmultpls
  cdef uint8_t*  expArray
  cdef uint16_t* dirArray
  cdef np.ndarray[float64_t,ndim=1] fi   # Holder for the solution  
  
  # cdef np.ndarray[float64_t, ndim=1] 
  
  cdef object K0, Kj#, A0
  cdef uint16_t* dirA = p_dH[order-1].p_udirA
  cdef uint16_t* dirX = &p_dH[order-1].p_udirA[order]
  cdef uint8_t* expA = p_dH[order-1].p_uexpA
  cdef uint8_t* expX = &p_dH[order-1].p_uexpA[order]
  # cdef uint8_t* newExpA
  # Create a copy of A?
  # Change the type of sparse matrix to CSR
  A.tocsr()
  print("In solve LU, kwargs: ", kwargs)
  # A0 = spr.linalg.spilu(A[ZERO].tocsc(),**kwargs)
  A0 = spr.linalg.splu(A[ZERO].tocsc(),**kwargs)

  # TODO: Check dimensions of b, A to match.
  
  # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
  for i in range(A.Ndir):
    
    fi = b.data[:,i]

    # Get direction and exponent arrays:
    expArray = c_helper_getExpA(i,A.order,p_dH)
    dirArray = c_helper_getDirA(i,A.order,p_dH)

    # get the multiples of the exponent array:
    c_helper_getMultpl(expArray,order,p_dH, &Nmultpls)
    
    # c_Py_print2DArrayUI8(multiples, Nmultpls, order)
    # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
    # loop in all multiples
    for j in range(Nmultpls-1):

      # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
      pos = Nmultpls-j-1

      c_helper_ordDirExpA(dirArray,    &multiples[pos*order] , order,\
                  dirA, expA)
      
      # print("\n\nA: multiple position: ",pos)
      # c_Py_printArrayUI16(dirA,order)
      # c_Py_printArrayUI8(expA,order)

      # Get the mirrored multiple for vector X
      c_helper_ordDirExpA(dirArray,    &multiples[j*order] , order, \
                  dirX, expX)
      
      # print("\nX: multiple position: ",j)
      # c_Py_printArrayUI16(dirX,order)
      # c_Py_printArrayUI8(expX,order)
      
      # Get the equivalent index for A.
      indxA = c_helper_findIndex(dirA, expA, order,p_dH)

      if dirX[0] == 0:

        indxX = 0

      else:

        # Get the equivalent index for X.
        indxX = c_helper_findIndex(dirX, expX, order,p_dH)

      # end if 
      
      # print("indxA",indxA, getDirArray(indxA,order))
      # print("indxX ",indxX,getDirArray(indxX,order))
      
      # Subtract A_indxA * x_indxX to the fi vector
      fi -= A[indxA].dot(x.data[:,indxX])


      # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
      # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
    # end for

    # TODO: Change according to all different solvers selected.

    x.data[:,i]  = A0.solve(fi)   # Solve factorized system


  # end for

  return x



#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
def solve(spr_omat A, ndarray b, solver = 0):
  """
  PURPOSE:  Solve a system Ax = b

  """
  #***************************************************************************************************

  global p_dH

  cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
  cdef uint64_t i, indxX, indxA, k
  cdef uint8_t  j , pos, order = A.order
  cdef uint8_t* multiples = p_dH[order-1].p_multpl
  cdef uint64_t Nmultpls
  cdef uint8_t*  expArray
  cdef uint16_t* dirArray
  cdef np.ndarray[float64_t,ndim=1] fi, solvedX   # Holder for the solution  
  
  # cdef np.ndarray[float64_t, ndim=1] 
  
  cdef object K0, Kj#, A0
  cdef uint16_t* dirA = p_dH[order-1].p_udirA
  cdef uint16_t* dirX = &p_dH[order-1].p_udirA[order]
  cdef uint8_t* expA = p_dH[order-1].p_uexpA
  cdef uint8_t* expX = &p_dH[order-1].p_uexpA[order]
  # cdef uint8_t* newExpA
  # Create a copy of A?
  # Change the type of sparse matrix to CSR
  A.tocsr()

  # A0 = spr.linalg.splu(A[ZERO].tocsc())

  # TODO: Check dimensions of b, A to match.
  
  # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
  for i in range(A.Ndir):
    
    fi = b.data[:,i]

    # Get direction and exponent arrays:
    expArray = c_helper_getExpA(i,A.order,p_dH)
    dirArray = c_helper_getDirA(i,A.order,p_dH)

    # get the multiples of the exponent array:
    c_helper_getMultpl(expArray,order,p_dH, &Nmultpls)
    
    # c_Py_print2DArrayUI8(multiples, Nmultpls, order)
    # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
    # loop in all multiples
    for j in range(Nmultpls-1):

      # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
      pos = Nmultpls-j-1

      c_helper_ordDirExpA(dirArray,    &multiples[pos*order] , order,\
                  dirA, expA)
      
      # print("\n\nA: multiple position: ",pos)
      # c_Py_printArrayUI16(dirA,order)
      # c_Py_printArrayUI8(expA,order)

      # Get the mirrored multiple for vector X
      c_helper_ordDirExpA(dirArray,    &multiples[j*order] , order, \
                  dirX, expX)
      
      # print("\nX: multiple position: ",j)
      # c_Py_printArrayUI16(dirX,order)
      # c_Py_printArrayUI8(expX,order)
      
      # Get the equivalent index for A.
      indxA = c_helper_findIndex(dirA, expA, order,p_dH)

      if dirX[0] == 0:

        indxX = 0

      else:

        # Get the equivalent index for X.
        indxX = c_helper_findIndex(dirX, expX, order,p_dH)

      # end if 
      
      # print("indxA",indxA, getDirArray(indxA,order))
      # print("indxX ",indxX,getDirArray(indxX,order))
      
      # Subtract A_indxA * x_indxX to the fi vector
      fi -= A[indxA].dot(x.data[:,indxX])


      # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
      # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
    # end for

    # TODO: Change according to all different solvers selected.

    # print(string)
    
    solvedX = spr.linalg.spsolve( A[ZERO], fi )
    # x.data[:,i]  = A0.solve(fi)   # Solve factorized system

    for k in range(<uint64_t>solvedX.size):

      x.data[k,i] = solvedX[k] 

    # end for

  # end for

  return x



#-----------------------------------------------------------------------------------------------------











