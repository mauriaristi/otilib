
#*****************************************************************************************************
cdef uint8_t is_integer(type in1):
  
  if (in1 == int     or in1 == np.int  or in1 == np.int64  or in1 == np.int32  or in1 == np.int16  or 
      in1 == np.int8 or in1 == np.uint or in1 == np.uint64 or in1 == np.uint32 or in1 == np.uint16 or
      in1 == np.uint8 ):
  
    return 1
  
  else:
  
    return 0
  
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def div_imdir_idxord( imdir_t numidx, ord_t numord, imdir_t denidx, ord_t denord):
  """
  """
  global h
  global dhl

  cdef imdir_t residx
  cdef ord_t   resord
  cdef int success;

  dhelp_div_imdir(numidx, numord, denidx, denord, &residx, &resord, &success, dhl)

  if (success != 0):

    return -1

  else:

    return [residx,resord]

  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def div_imdir(humdir_num, humdir_den):
  """
  """
  global h
  global dhl

  cdef imdir_t numidx, denidx, residx
  cdef ord_t   numord, denord, resord
  cdef int success;

  numidx, numord = imdir(humdir_num)
  denidx, denord = imdir(humdir_den)

  dhelp_div_imdir(numidx, numord, denidx, denord, &residx, &resord, &success, dhl)

  if (success != 0):

    return -1

  else:

    return h.get_compact_fulldir(residx,resord)

  # end if 

#-----------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def print_capabilities():
  
  global h

  h.print_capabilities()
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef list imdir(hum_dir):
  
  global h

  # First expand imaignary direction and sort it.
  cdef list expanded_dir = expand_imdir(hum_dir)
  
  cdef ord_t order = len(expanded_dir) 
  cdef ord_t i
  cdef bases_t imb
  cdef imdir_t indx = 0

  # Only when the order is valid.
  if order <= h.dhl.ndh:


    for i in range(1,order+1):
  
      imb = expanded_dir[i-1]
      
      # Only when the base is valid.
      if imb <= h.dhl.p_dh[i-1].Nbasis :
        
        indx += h.dhl.p_dh[i-1].p_ndirs[imb-1]
  
      else:
  
        raise ValueError("Unsupported direction. Basis "+str(imb)+
          " larger than maximum supported "+str(h.dhl.p_dh[i-1].Nbasis))
  
      # end if 
  
    # end for 
  
  else:
  
    raise ValueError( "Unsupported direction. Order "+str(order)+
      " greater than the maximum supported order "+str(h.dhl.ndh) )
  
  # end if 
  
  return [indx,order]
  
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef list expand_imdir(hum_dir):
  """
  """
  cdef list res = []

  if type(hum_dir) in int_types:

    if hum_dir != 0:

      res.append(hum_dir)

    # end if 

  else:

    for el in hum_dir:
      
      if type(el) is list:

        base = el[0]
        repet = el[1]
    
        if base != 0:
    
          res.extend([base]*repet)
    
        # end if
    
      else:

        if el != 0:
    
          res.append(el)
    
        # end if 
    
      # end if 
    
    # end for

  # end if 

  res.sort()

  return res
#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef np.ndarray[double, ndim=3]  c_ptr_to_np_3darray_double(void * ptr, np.npy_intp sizex, \
                                                            np.npy_intp sizey, np.npy_intp sizez, \
                                                            uint8_t numpy_own = 0):
  """
  PURPOSE:    Convert a C pointer to numpy 1D array.
   
  INPUTS:      
            - void *  ptr: C-pointer

            - np.npy_intp size: Length of the 1D array.

            - numpy_own: Flag to state if the numpy given array owns the pointer (will be 
                         released by numpy when the object is deleted). Default is 0 (off).
  OUTPUTS:
            - uint16_t: number in which the high bits correspond to the position of the elements
                        that belong to the asked partition.
            
  """
  #***************************************************************************************************
  cdef np.npy_intp* size

  size=<np.npy_intp*>malloc(3*sizeof(np.npy_intp))
  size[0] = sizex
  size[1] = sizey
  size[2] = sizez

  # cdef extern from "numpy/arrayobject.h":
  #     void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)

  cdef np.ndarray[double, ndim=3] arr = \
          np.PyArray_SimpleNewFromData(3, size, np.NPY_FLOAT64, ptr)
  # PyObject *PyArray_SimpleNewFromData(int ndim, npy_intp* dims, int typenum, void* data)

  if numpy_own != 0:

    # Pass the ownership flag to numpy.
    PyArray_ENABLEFLAGS(arr, np.NPY_OWNDATA)

  # end if

  free(size)
  
  return arr

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef np.ndarray[double, ndim=2]  c_ptr_to_np_2darray_double(void * ptr, np.npy_intp sizex, \
                                                            np.npy_intp sizey, uint8_t numpy_own = 0):
  """
  PURPOSE:    Convert a C pointer to numpy 1D array.
   
  INPUTS:      
            - void *  ptr: C-pointer

            - np.npy_intp size: Length of the 1D array.

            - numpy_own: Flag to state if the numpy given array owns the pointer (will be 
                         released by numpy when the object is deleted). Default is 0 (off).
  OUTPUTS:
            - uint16_t: number in which the high bits correspond to the position of the elements
                        that belong to the asked partition.
            
  """
  #***************************************************************************************************
  cdef np.npy_intp* size

  size=<np.npy_intp*>malloc(2*sizeof(np.npy_intp))
  size[0] = sizex
  size[1] = sizey

  # cdef extern from "numpy/arrayobject.h":
  #     void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)

  cdef np.ndarray[double, ndim=2] arr = \
          np.PyArray_SimpleNewFromData(2, size, np.NPY_FLOAT64, ptr)
  # PyObject *PyArray_SimpleNewFromData(int ndim, npy_intp* dims, int typenum, void* data)

  if numpy_own != 0:

    # Pass the ownership flag to numpy.
    PyArray_ENABLEFLAGS(arr, np.NPY_OWNDATA)

  # end if

  free(size)
  
  return arr

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef np.ndarray[double, ndim=1]  c_ptr_to_np_1darray_double(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = 0):
  """
  PURPOSE:    Convert a C pointer to numpy 1D array.
   
  INPUTS:      
            - void *  ptr: C-pointer

            - np.npy_intp size: Length of the 1D array.

            - numpy_own: Flag to state if the numpy given array owns the pointer (will be 
                         released by numpy when the object is deleted). Default is 0 (off).
  OUTPUTS:
            - uint16_t: number in which the high bits correspond to the position of the elements
                        that belong to the asked partition.


  SOURCES:

    http://blog.enthought.com/python/numpy-arrays-with-pre-allocated-memory/#.WSsNoMaZNN3
    https://gist.github.com/GaelVaroquaux/1249305
    https://docs.scipy.org/doc/numpy/user/c-info.how-to-extend.html
    https://docs.scipy.org/doc/numpy/reference/c-api.dtype.html#c.NPY_DOUBLE



            
  """
  #***************************************************************************************************
  # cdef extern from "numpy/arrayobject.h":
  #     void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)
  # cdef double* data = <double*> ptr

  # for i in range(size):
  #   print(data[i])

  cdef np.ndarray[double, ndim=1] arr = \
          np.PyArray_SimpleNewFromData(1, &size, np.NPY_FLOAT64, ptr)
  # PyObject *PyArray_SimpleNewFromData(int ndim, npy_intp* dims, int typenum, void* data)

  if numpy_own != 0:

    # Pass the ownership flag to numpy.
    PyArray_ENABLEFLAGS(arr, np.NPY_OWNDATA)

  # end if
  
  return arr

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef np.ndarray[uint64_t, ndim=1]  c_ptr_to_np_1darray_uint64(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = 0):
  """
  PURPOSE:    Convert a C pointer to numpy 1D array.
   
  INPUTS:      
            - void *  ptr: C-pointer

            - np.npy_intp size: Length of the 1D array.

            - numpy_own: Flag to state if the numpy given array owns the pointer (will be 
                         released by numpy when the object is deleted). Default is 0 (off).
  OUTPUTS:
            - uint16_t: number in which the high bits correspond to the position of the elements
                        that belong to the asked partition.


  SOURCES:

    http://blog.enthought.com/python/numpy-arrays-with-pre-allocated-memory/#.WSsNoMaZNN3
    https://gist.github.com/GaelVaroquaux/1249305
    https://docs.scipy.org/doc/numpy/user/c-info.how-to-extend.html
    https://docs.scipy.org/doc/numpy/reference/c-api.dtype.html#c.NPY_DOUBLE
            
  """
  #***************************************************************************************************
  # cdef extern from "numpy/arrayobject.h":
  #     void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)
  # cdef double* data = <double*> ptr

  # for i in range(size):
  #   print(data[i])

  cdef np.ndarray[uint64_t, ndim=1] arr = \
          np.PyArray_SimpleNewFromData(1, &size, np.NPY_UINT64, ptr)
  # PyObject *PyArray_SimpleNewFromData(int ndim, npy_intp* dims, int typenum, void* data)

  if numpy_own != 0:

    # Pass the ownership flag to numpy.
    PyArray_ENABLEFLAGS(arr, np.NPY_OWNDATA)

  # end if
  
  return arr

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef np.ndarray[uint16_t, ndim=1]  c_ptr_to_np_1darray_uint16(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = 0):
  """
  PURPOSE:    Convert a C pointer to numpy 1D array.
   
  INPUTS:      
            - void *  ptr: C-pointer

            - np.npy_intp size: Length of the 1D array.

            - numpy_own: Flag to state if the numpy given array owns the pointer (will be 
                         released by numpy when the object is deleted). Default is 0 (off).
  OUTPUTS:
            - uint16_t: number in which the high bits correspond to the position of the elements
                        that belong to the asked partition.


  SOURCES:

    http://blog.enthought.com/python/numpy-arrays-with-pre-allocated-memory/#.WSsNoMaZNN3
    https://gist.github.com/GaelVaroquaux/1249305
    https://docs.scipy.org/doc/numpy/user/c-info.how-to-extend.html
    https://docs.scipy.org/doc/numpy/reference/c-api.dtype.html#c.NPY_DOUBLE
            
  """
  #***************************************************************************************************
  # cdef extern from "numpy/arrayobject.h":
  #     void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)
  # cdef double* data = <double*> ptr

  # for i in range(size):
  #   print(data[i])

  cdef np.ndarray[uint16_t, ndim=1] arr = \
          np.PyArray_SimpleNewFromData(1, &size, np.NPY_UINT16, ptr)
  # PyObject *PyArray_SimpleNewFromData(int ndim, npy_intp* dims, int typenum, void* data)

  if numpy_own != 0:

    # Pass the ownership flag to numpy.
    PyArray_ENABLEFLAGS(arr, np.NPY_OWNDATA)

  # end if
  
  return arr

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef np.ndarray[uint8_t, ndim=1]  c_ptr_to_np_1darray_uint8(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = 0):
  """
  PURPOSE:    Convert a C pointer to numpy 1D array.
   
  INPUTS:      
            - void *  ptr: C-pointer

            - np.npy_intp size: Length of the 1D array.

            - numpy_own: Flag to state if the numpy given array owns the pointer (will be 
                         released by numpy when the object is deleted). Default is 0 (off).
  OUTPUTS:
            - uint16_t: number in which the high bits correspond to the position of the elements
                        that belong to the asked partition.


  SOURCES:

    http://blog.enthought.com/python/numpy-arrays-with-pre-allocated-memory/#.WSsNoMaZNN3
    https://gist.github.com/GaelVaroquaux/1249305
    https://docs.scipy.org/doc/numpy/user/c-info.how-to-extend.html
    https://docs.scipy.org/doc/numpy/reference/c-api.dtype.html#c.NPY_DOUBLE
            
  """
  #***************************************************************************************************
  # cdef extern from "numpy/arrayobject.h":
  #     void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)
  # cdef double* data = <double*> ptr

  # for i in range(size):
  #   print(data[i])

  cdef np.ndarray[uint8_t, ndim=1] arr = \
          np.PyArray_SimpleNewFromData(1, &size, np.NPY_UINT8, ptr)
  # PyObject *PyArray_SimpleNewFromData(int ndim, npy_intp* dims, int typenum, void* data)

  if numpy_own != 0:

    # Pass the ownership flag to numpy.
    PyArray_ENABLEFLAGS(arr, np.NPY_OWNDATA)

  # end if
  
  return arr

#-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef void c_getDirExpA(list dirArray, uint16_t** p_dirA, uint8_t** p_expA, uint8_t* order):
#   """
#   PURPOSE:      To convert a direction array given in human readable  form
#                 into its index number. 

#   DESCRIPTION:  It just activates the binary positions of the corresponding 
#                 directions according to what is given in the dirArray.

#   PARAMETERS
#                 dirArray:  a list of dual directions.
                
#                 maxorder: Order that changes the representation of the 
#                 binary number 

#   RESULT:       An integer. The position of the coefficient that involves
#                 the given directions.
#   """
#   #***************************************************************************************************

#   global h
#   cdef uint8_t i = 0,k
  
#   order[0] = 0
#   p_dirA[0] = h.c_getUDirA(len(h.__mmax)-1,n=1)
#   p_expA[0] = h.c_getUExpA(len(h.__mmax)-1,n=1)

#   for dir_i in dirArray:
      
#     if type(dir_i) == list:
    
#       p_dirA[0][i] = dir_i[ZERO]
#       p_expA[0][i] = dir_i[ONE]
#       order[0] += dir_i[ONE]

#     else:
    
#       p_dirA[0][i] = dir_i
#       p_expA[0][i] = 1
#       order[0] += 1
        
#     # end if

#     i+=1
      
#   # end for

#   for k in range(i,len(h.__mmax)+2):

#     p_dirA[0][k] = 0

#     p_expA[0][k] = 0

#   # end for 

# #-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void c_Py_print2DArrayUI8(uint8_t* array,uint64_t dim1, uint8_t dim2):
  """
  PURPOSE:      To print a 2D array of unsinged integers of 8 bits. 

  PARAMETERS:
                array:  The array itself.
                
                dim1, dim2: the two dimensions. 

  RESULT:       Output to console of the printed array.
  """
  #***************************************************************************************************
  
  cdef str string = '['
  cdef uint8_t i
  for i in range(dim1):
    
    string+="["
    
    for j in range(dim2):

      string += str(array[i*dim2+j])+","

    # end for

    string = string[:len(string)-1]+']\n'

  # end for

  string = string[:len(string)-1]+']'
  print('uint8_t* \n',string)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void c_Py_printArrayUI8(uint8_t* array,uint8_t size):
  """
  PURPOSE:      To print a 1D array of unsinged integers of 8 bits. 

  PARAMETERS:
                array:  The array itself.
                
                dim1, dim2: the two dimensions. 

  RESULT:       Output to console of the printed array.
  """
  #***************************************************************************************************
  
  cdef str string = '['
  cdef uint8_t i
  for i in range(size):
    string += str(array[i])+","
  # end for
  string = string[:len(string)-1]+']'
  print('uint8_t* ',string)


#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void c_Py_printArrayUI16(uint16_t* array,uint8_t size):
  """
  PURPOSE:      To print a 1D array of unsinged integers of 16 bits. 

  PARAMETERS:
                array:  The array itself.
                
                dim1, dim2: the two dimensions. 

  RESULT:       Output to console of the printed array.
  """
  #***************************************************************************************************
  
  cdef str string = '['
  cdef uint8_t i
  for i in range(size):
    string += str(array[i])+","
  # end for
  string = string[:len(string)-1]+']'
  print('uint16_t* ',string)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void c_Py_printArrayUI64(uint64_t* array,uint64_t size):
  """
  PURPOSE:      To print a 1D array of unsinged integers of 64 bits. 

  PARAMETERS:
                array:  The array itself.
                
                dim1, dim2: the two dimensions. 

  RESULT:       Output to console of the printed array.
  """
  #***************************************************************************************************
  
  cdef str string = '['
  cdef uint64_t i
  for i in range(size):
    string += str(array[i])+","
  # end for
  string = string[:len(string)-1]+']'
  print('uint64_t* ',string)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def ndir_total(bases_t nbases,ord_t order):
  """
  PURPOSE: Compute the total number of directions. 

  PARAMETERS:
          
          nbases: Number of basis.
          order: Truncation order. 

  """

  return dhelp_ndirTotal( nbases, order)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def ndir_order(bases_t nbases,ord_t order):
  """
  PURPOSE: Compute the number of directions for a given truncation order. 

  PARAMETERS:
          
          nbases: Number of basis.
          order: Truncation order. 

  """

  return dhelp_ndirOrder( nbases, order)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************

# #*****************************************************************************************************
# def getDirExpA(dirArray):
#   """
#   PURPOSE:      To convert a direction array given in human readable  form
#                 into its index number. 

#   DESCRIPTION:  It just activates the binary positions of the corresponding 
#                 directions according to what is given in the dirArray.

#   PARAMETERS
#                 dirArray:  a list of dual directions.
                
#                 maxorder: Order that changes the representation of the 
#                 binary number 

#   RESULT:       An integer. The position of the coefficient that involves
#                 the given directions.
#   """
#   #***************************************************************************************************

#   # Add a piece of code to create the arrays according to the order.
#   dirA = []
#   expA = []



#   for dir_i in dirArray:
      
#     if type(dir_i) == list:
    
#       dirA.append( dir_i[0] )
#       expA.append( dir_i[1] )

#     else:
    
#       dirA.append( dir_i )
#       expA.append( 1     )
        
#     # end if
      
#   # end for
  

#   return (dirA,expA)

# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# def findComb(int m,int n):
#   """
#   PURPOSE:   To find all possible combinations to create a dual number of 
#              order n with m directions.

#   EXAMPLE:
#             >>> # for m=3, n=2
#             >>> findComb(3+1,2)   # ...+1 to take into account the real direction.

#   """
#   #***************************************************************************************************
  
#   if n == 0:
    
#     return 1
    
#   else:
    
#     return comb(n+m-1,m-1,exact=True) # from scipy.special import comb
    
#   # end if
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# def printOrderPos(pos):
#   """
#   PURPOSE:  To print the imaginary direction referenced to a position of the 
#             binary indexing.
#   """
#   #***************************************************************************************************
#   if len(pos) == 0:
#     head = ''
#     body = ''
#     tail = ''
  
#   elif len(pos) == 1:
#     head = ' * e('
#     tail = ')'
#     body = str(pos)#[1:-1]
  
#   else:
#     head = ' * e('
#     tail = ')'
#     body = str(pos)
#   return (head + body.replace(" ","") + tail)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# def printOrderPosLatex(list pos):
#   """
#   PURPOSE:  To print the imaginary direction referenced to a position of the 
#             binary indexing.
#   """
#   #***************************************************************************************************
#   if len(pos) == 0:
#     head = '$'
#     body = 'Re'
#     tail = '$'
  
#   elif len(pos) == 1:
#     head = '$'
#     tail = '$'
#     body = '\epsilon_'+str(pos[0])#[1:-1]
  
#   else:
#     head = '$'
#     tail = '$'
#     body = ''
#     eps = '\epsilon'
#     for i in range(len(pos)):
#       body += printLatexDir(pos[i])
#     # end for 
#   return (head + body.replace(" ","") + tail)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cdef str printLatexDir(object pos):
#   """
#   PURPOSE:  To print the imaginary direction referenced to a position of the 
#             binary indexing.
#   """
#   #***************************************************************************************************
#   cdef str body =''

#   if pos.__class__ == list:
#     body += '\epsilon_'+str(pos[0])+'^'+str(pos[1])
#   else:    
#     body += '\epsilon_'+str(pos)
#   # end if 
  
#   return body
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# def getLatexDir(uint64_t indx_i,uint8_t order):
#   """
#   PURPOSE:  Create a human friendly string version version of the direction indx_i that it is representing.

#   INPUTS:
#           -> indx_i: Index representing a direction.

#           -> order:  Maximum order of the direction.

#   EXAMPLE:
#           >>> getDirArray(9,2)  -> [2,3]
#           >>> getDirArray(10,2) -> [[3,2]]
#   """
#   #***************************************************************************************************
  
#   global h

#   cdef: 
#     uint64_t i
#     uint16_t* dirs
#     uint8_t*  aexp
  
  
#   if indx_i == 0 :
    
#     return '$Re$'

#   elif order == 1:

#     return '$\epsilon_'+str(indx_i)+'$'

#   # find the non-zero values of dirArray
#   i = order
#   dirs = h.c_getDirA(indx_i,order)
#   exps = h.c_getExpA(indx_i,order)
#   body = '$'
#   humDir = []

#   for i in range(order):
    
       
#     if exps[i]>1:
      
#       # If the order is greater than zero, then the direction given
#       # contains an exponent, therefore it should be organized by the
#       # exponent as an array.
#       body += '\epsilon_'+str(dirs[i])+'^'+str(exps[i])
#       # humDir.append([dirs[i],exps[i]])
      
#     elif exps[i] == 1:

#       # If it does not contain an exponent, just add the direction.
#       body += '\epsilon_'+str(dirs[i])
#       # humDir.append(dirs[i])

#     else:
      
#       # No more things to add.
#       break
      
#     # end if
    
#   # end for
#   body+='$'
#   return body
# #-----------------------------------------------------------------------------------------------------




# #*****************************************************************************************************
# def getDirArray(uint64_t indx_i,uint8_t order):
#   """
#   PURPOSE:  Create a human friendly version of the direction indx_i that it is representing.

#   INPUTS:
#           -> indx_i: Index representing a direction.

#           -> order:  Maximum order of the direction.

#   EXAMPLE:
#           >>> getDirArray(9,2)  -> [2,3]
#           >>> getDirArray(10,2) -> [[3,2]]
#   """
#   #***************************************************************************************************
  
#   global h

#   cdef: 
#     uint64_t i
#     uint16_t* dirs
#     uint8_t*  aexp
  
  
#   if indx_i == 0 :
    
#     return []

#   elif order == 1:

#     return[indx_i]

#   # find the non-zero values of dirArray
#   i = order
#   dirs = h.c_getDirA(indx_i,order)
#   exps = h.c_getExpA(indx_i,order)
  
#   humDir = []

#   for i in range(order):
    
       
#     if exps[i]>1:
      
#       # If the order is greater than zero, then the direction given
#       # contains an exponent, therefore it should be organized by the
#       # exponent as an array.

#       humDir.append([dirs[i],exps[i]])
      
#     elif exps[i] == 1:

#       # If it does not contain an exponent, just add the direction.
#       humDir.append(dirs[i])

#     else:
      
#       # No more things to add.
#       break
      
#     # end if
    
#   # end for
  
#   return humDir
# #-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def get_dHelp():
  """
  PURPOSE:  Return the global helper that is a global variable inside the otilib.

  """
  #***************************************************************************************************
  global h

  return h
#-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# def get_CR(uint64_t nvar, uint8_t order):
#   """
#   PURPOSE:  Return the matrix form of an oti number of "nvar" variables and order "order".

#   """
#   #***************************************************************************************************
#   global h
#   cdef coomat_ui64_t resmat
#   cdef uint64_t i=0

#   resmat = c_oti_matform( nvar, order, p_dH)

#   pymat = spr.lil_matrix( ( resmat.sizex, resmat.sizey ), dtype = np.uint64)

#   for i in range(resmat.nonzero):
    
#     pymat[resmat.p_rows[i],resmat.p_cols[i]] = resmat.p_data[i]

#   # end for 

#   free(resmat.p_data)
#   free(resmat.p_rows)
#   free(resmat.p_cols)

#   return pymat
# #-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def get_CR_mdl(uint64_t dirBasis,uint64_t maxBasis):
  """
  PURPOSE:  Return the matrix positions where a dual number will exist in the current OTI number
            of an oti number of "nvar" variables and order "order".

  """
  #***************************************************************************************************
  global h
  cdef uint64_t maxBin= 2**maxBasis-1
  cdef uint64_t binEq = 2**(dirBasis-1)
  cdef uint64_t bitLenght = dirBasis
  cdef uint64_t dimR = dirBasis-1
  cdef uint64_t dimL = maxBasis-dirBasis
  cdef np.ndarray[uint64_t, ndim=1] col = np.empty(2**(maxBasis-1),dtype = np.uint64)
  cdef np.ndarray[uint64_t, ndim=1] row = np.empty(2**(maxBasis-1),dtype = np.uint64)
  cdef uint64_t i, left, right

  for i in range( 2**(maxBasis-1) ):
                
    left = i >> dimR << dimR
    right= (i^left) 
    left = left<<1
    # print(bin(i),'   ',bin(left),bin(binEq),bin(right))
    row[i] = left+right+binEq
    col[i] = left+right#+binEq
      
  # end for 
                
  return row,col
#-----------------------------------------------------------------------------------------------------
    
   







#*****************************************************************************************************
cdef dHelp get_cython_dHelp():
  """
  PURPOSE:  Return the global helper that is a global variable inside the otilib.

  """
  #***************************************************************************************************
  global h

  return h
#-----------------------------------------------------------------------------------------------------









#*****************************************************************************************************
def dhelp_get_matrix_form(bases_t nbases, ord_t order, export_latex = True, 
  export_strings=False, export_sparse = False):
  
  global dhl
  global h
  
  cdef matrix_form_t res = dhelp_matrix_form_indices(nbases,order,dhl);
  cdef np.ndarray[uint64_t, ndim=1] rows
  cdef np.ndarray[uint64_t, ndim=1] cols
  cdef np.ndarray[uint64_t, ndim=1] im  
  cdef np.ndarray[uint8_t, ndim=1]  orde

  cdef str body = ""
  cdef uint64_t i, j  
  
  if export_sparse == True:

    from scipy.sparse.coo import coo_matrix 

    rows= c_ptr_to_np_1darray_uint64( res.p_rows, res.nonzero)
    cols= c_ptr_to_np_1darray_uint64( res.p_cols, res.nonzero)
    im  = c_ptr_to_np_1darray_uint64( res.p_im  , res.nonzero)
    orde= c_ptr_to_np_1darray_uint8 ( res.p_ord , res.nonzero)

    im   = im.copy()
    rows = rows.copy()
    cols = cols.copy()
    orde = orde.copy()

    free(res.p_im)
    free(res.p_ord)
    free(res.p_rows)
    free(res.p_cols)

    mat_idx = coo_matrix( (   im, (rows,cols) ), shape=(res.sizex,res.sizey), dtype = np.uint64)    
    mat_ord = coo_matrix( ( orde, (rows,cols) ), shape=(res.sizex,res.sizey), dtype = np.uint8 )

    return (mat_idx, mat_ord)

  elif (export_strings == True):

    A = np.zeros((res.sizex,res.sizey),dtype=object)
    A[:,:] = ''

    for i in range(res.nonzero):

      # print("Setting value at ("+str(res.p_rows[i])+","+str(res.p_cols[i])+") as ["+str(res.p_im[i])+","+str(res.p_ord[i])+"]: ") 
      # print( str( get_latex_dir(res.p_im[i], res.p_ord[i]) ) )

      A[res.p_rows[i],res.p_cols[i]] = get_latex_dir( res.p_im[i], res.p_ord[i] )
      
    # end for 

    free(res.p_im)
    free(res.p_ord)
    free(res.p_rows)
    free(res.p_cols)

    return A

  elif(export_latex==True):

    A = np.zeros((res.sizex,res.sizey),dtype=object)
    A[:,:] = '0'

    for i in range(res.nonzero):

      # print("Setting value at ("+str(res.p_rows[i])+","+str(res.p_cols[i])+") as ["+str(res.p_im[i])+","+str(res.p_ord[i])+"]: ") 
      # print( str( get_latex_dir(res.p_im[i], res.p_ord[i]) ) )

      A[res.p_rows[i],res.p_cols[i]] = get_latex_dir( res.p_im[i], res.p_ord[i] )
      
    # end for 

    free(res.p_im)
    free(res.p_ord)
    free(res.p_rows)
    free(res.p_cols)

    body = ""

    for i in range(A.shape[0]):
      for j in range(A.shape[1]):
        body+=A[i,j] + " & "
      # end for 
      body = body[:len(body)-2]
      body +="\\\\\n"
    # end for
    return body

  # end if 
#-----------------------------------------------------------------------------------------------------




def set_global_test_py(int x):

  set_global_test(x)


def print_global_test_py():

  print_global_test() 

def print_python_error_py():

  print_python_error_def( )


def exit_with_error():
  
  error_exit(-1);


#*****************************************************************************************************
def get_latex_dir(imdir_t indx, ord_t order, real = '_{\mbox{Re}}', epsilon='\epsilon'):
  """
  PURPOSE:  To print the imaginary direction referenced to a position of the 
            binary indexing.
  """
  #***************************************************************************************************
  global h

  cdef object body ='' 

  cdef np.ndarray bases, exponents 
  
  bases,exponents = h.get_base_exp( indx,  order)


  if bases.size == 0:
    
    body += real

  else:
    
    for i in range(bases.size):
    
      body += epsilon+'_{'+str(bases[i])+'}'
    
      if exponents[i]!=1:
    
        body += '^{'+str(exponents[i])+'}'
    
      # end if 
    
    #end for 

  # end if 
  
  return body
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef copy_numpy2d_to_ptr_f64(np.ndarray[coeff_t, ndim=2] src, coeff_t* dst):
  """
  PURPOSE:  Copy data from a numpy array (2D) into a pointer.
  """
  #***************************************************************************************************
  cdef uint64_t i,j,ncols = src.shape[1]

  for i in range(src.shape[0]):
    for j in range(ncols):
      dst[j + i*ncols] = src[i,j];
    # end for 
  # end for 
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef get_deriv_factor(hum_dir):
  """
  PURPOSE:  Get the factor to be multiplied to the coprresponding imaginary coefficient to get the 
            exact value of the derivative.
  """
  #***************************************************************************************************
  global dhl

  cdef list item = imdir(hum_dir)

  return dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def compilation_status():
  """
  PURPOSE:  Returns true if the library was compiled with openmp support.
            
  """
  #***************************************************************************************************
  
  cdef object res

  if is_openmp_compiled():
    res = True
  else:
    res = False
  # end of

  return res
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def set_trunc_order(ord_t order):
  """
  PURPOSE:  Set the global truncation order for OTI algebra. This allows to compute derivatives up to 
            the set order using oti numbers.
  """
  #***************************************************************************************************


  global dhl

  # Check first that it is plaussible to compute the derivatives.
  
  if order <= dhl.ndh:

    dhl.order[ZERO] = order

  else:

    # If the order is greater than the number of helpers, then set it to the maximum possible 
    # to compute derivatives.
    dhl.order[ZERO] = dhl.ndh  

  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef ord_t get_trunc_order( ):
  """
  PURPOSE:  Get the global truncation order for OTI algebra. 
  """
  #***************************************************************************************************

  global dhl

  return dhl.order[ZERO]

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef void error_function( int64_t err_id ) noexcept nogil:
  
  raise ValueError("Found an error: "+str(err_id))
  # All python errors
  # AssertionError         # Raised when the assert statement fails.
  # AttributeError         # Raised on the attribute assignment or reference fails.
  # EOFError               # Raised when the input() function hits the end-of-file condition.
  # FloatingPointError     # Raised when a floating point operation fails.
  # GeneratorExit          # Raised when a generator's close() method is called.
  # ImportError            # Raised when the imported module is not found.
  # IndexError             # Raised when the index of a sequence is out of range.
  # KeyError               # Raised when a key is not found in a dictionary.
  # KeyboardInterrupt      # Raised when the user hits the interrupt key (Ctrl+c or delete).
  # MemoryError            # Raised when an operation runs out of memory.
  # NameError              # Raised when a variable is not found in the local or global scope.
  # NotImplementedError    # Raised by abstract methods.
  # OSError                # Raised when a system operation causes a system-related error.
  # OverflowError          # Raised when the result of an arithmetic operation is too large to be represented.
  # ReferenceError         # Raised when a weak reference proxy is used to access a garbage collected referent.
  # RuntimeError           # Raised when an error does not fall under any other category.
  # StopIteration          # Raised by the next() function to indicate that there is no further item to be returned by the iterator.
  # SyntaxError            # Raised by the parser when a syntax error is encountered.
  # IndentationError       # Raised when there is an incorrect indentation.
  # TabError               # Raised when the indentation consists of inconsistent tabs and spaces.
  # SystemError            # Raised when the interpreter detects internal error.
  # SystemExit             # Raised by the sys.exit() function.
  # TypeError              # Raised when a function or operation is applied to an object of an incorrect type.
  # UnboundLocalError      # Raised when a reference is made to a local variable in a function or method, but no value has been bound to that variable.
  # UnicodeError           # Raised when a Unicode-related encoding or decoding error occurs.
  # UnicodeEncodeError     # Raised when a Unicode-related error occurs during encoding.
  # UnicodeDecodeError     # Raised when a Unicode-related error occurs during decoding.
  # UnicodeTranslateError  # Raised when a Unicode-related error occurs during translation.
  # ValueError             # Raised when a function gets an argument of correct type but improper value.
  # ZeroDivisionError      # Raised when the second operand of a division or module operation is zero.

#-----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#-------------------------------------   INITIALIZATION ONLY   ---------------------------------------
#-----------------------------------------------------------------------------------------------------

# Global variable to help do the multiplications. One of this is required per core being used. 
# Be careful. It requires some memory.
h = dHelp()

cdef dhelpl_t dhl = h.dhl

# Set the python exit error function in the C-OTI LIBRARY.
set_python_error_function(&error_function)


# To provide an easy manner to create numpy arrays from C without copying data
np.import_array()


# Define an array to check number types.
# Change to a function that checks all items.
# TODO: LOOK FOR A MORE EFFICIENT WAY TO CHECK VARIOUS data types.
number_types = (   float,      int, np.float64,   np.int64,\
                np.int32, np.int16,    np.int8, np.float32  )

int_types = ( int, np.int64, np.int32, np.int16, np.int8)

ZERO = 0  # these whatfor?
ONE  = 1
TWO  = 2

#-----------------------------------------------------------------------------------------------------