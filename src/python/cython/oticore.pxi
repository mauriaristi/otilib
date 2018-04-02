# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=True
# cython: linetrace=True
# cython: binding=True
# cython: embedsignature=True
# distutils: define_macros=CYTHON_TRACE_NOGIL=1

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                  # General numerical library
cimport numpy as np                 # C-level functions of numpy
from libc.stdlib cimport malloc,free# import memory managment functions.
from libc.stdlib cimport realloc    #    "              "
from libc.string cimport memcpy     # fast memory block copy.
from libc.string cimport memset     # fast memory instantiation.
from warnings import warn           # Warnings
from math import factorial          # Compute factorials
import scipy.sparse as spr          # Manipulator of sparse matrices
from scipy.special import comb      # Classic combinatorials
from partitionsets import partition # Compute partitions of sets
import whereotilib                  # A pure python script to get the current path of this folder.
from c_otilib cimport *             # OTI lib in C.
cimport cython                      #
from cpython cimport PyObject       #
from cpython cimport Py_INCREF      #

#-----------------------------------------------------------------------------------------------------










# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::      CLASS HELPER      :::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 
cdef class dHelp:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  #
  #                                --->      Look in oticore.pxd    <---
  #
  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __init__(self):
    """
    PURPOSE:     Initialize the h_indx for the specified This will load the respective
                 direction and exponent arrays, and will also pre-load in memory supplementary
                 arrays.
     
    DESCRIPTION: This will create, allocate, and initialize (if necessary) memory for all internal 
                 helper attributes.
              
    """
    #*************************************************************************************************
    global p_dH
    cdef str PATH_TO_FILES = whereotilib.getpath() # "/.../.../spr_otilibvX.Y/"

    cdef uint8_t i

    # Number of basis for the following orders
    # self.__mmax = np.array([65535, # ------------------   1 -> Probably not necessary
    #                          1000, # ------------------   2
    #                           100, # ------------------   3
    #                           100, # ------------------   4
    #                            10, # ------------------   5
    #                            10, # ------------------   6
    #                            10, # ------------------   7 
    #                            10, # ------------------   8
    #                            10, # ------------------   9
    #                            10], dtype = np.uint16) # 10
    
    self.__mmax = np.array([65535, # ------------------   1 -> Probably not necessary
                             1000, # ------------------   2
                              100, # ------------------   3
                               10, # ------------------   4
                               10, # ------------------   5
                               10, # ------------------   6
                               10, # ------------------   7 
                               10, # ------------------   8
                               10, # ------------------   9
                               10], dtype = np.uint16) # 10
    
    # Store the number of helpers somewhere
    self.nhelps =  self.__mmax.size

    self.nn = 3
    # initialize the value of merror. Not necessary but as a GPP (Good programing practice).
    self.merror =  1

    # Allocate memory for all helpers:
    self.p_dH   =  <directionHelper* >malloc(self.nhelps*sizeof(directionHelper))

    if not self.p_dH:      # Check memory allocation.
      raise MemoryError("Unable to get enough memory to load the direction helpers @dHelp object")
    # end if
    

    cdef char* c_string = <char*>malloc(256*sizeof(char))

    # copy data to c_string
    for i in range(len(PATH_TO_FILES)):
      c_string[i] = <char>ord(PATH_TO_FILES[i])
      # print(chr(c_string[i]))
    #
    c_string[len(PATH_TO_FILES)] = <char>ord('\0') 

    # Iterate to fill the helper:
    for i in range(self.nhelps):

      c_loadDirHelper(c_string, i+1, self.__mmax[i], self.nn, &self.p_dH[i])

    # end for 
    free( c_string)
    c_string = NULL
    p_dH = self.p_dH  # Copy direction helper to a Global C pointer, so that access to the helper is 
                      # less expensive.

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:     Deallocate all memory that was manually allocated.
     
    DESCRIPTION: This will first dealloc what is inside each helper loaded, and then free the helper.
                 
              
    """
    #*************************************************************************************************


    # free all dHelps:
    for i in range(self.nhelps):
      
      c_freeDirHelper(&self.p_dH[i])
    
    # end for

    free(self.p_dH)

  #--------------------------------------------------------------------------------------------------- 



  #***************************************************************************************************
  def findIndx(self, dirA,  expA):
    """
    PURPOSE:      Implements a binary search so that it can find the given pair (dirA,expA) in
                  (self.dirA,self.expA)
     
    DESCRIPTION:  The condition that this satisfies is that it will return i such that

                  >>> (self.dirA[i,:],self.expA[i,:]) == (dirA,expA)
                  True

    INPUTS:      
              - uint16_t* dirA: Direction array with the basis of the direction to search.

              - uint8_t*  expA: Exponent array with the exponents of the basis that 
                                are present in the direction to search.

    OUTPUTS: 
              - uint64_t indx : position of the pair 

                        (dirA[:],expA[:]) in (p_dH.dirA[:,:],p_dH.expA[:,:])
              
    """
    #*************************************************************************************************
    
    cdef:
      uint16_t[::1] memv_DirA = np.array( dirA, dtype = np.uint16)
      uint8_t[::1]  memv_ExpA = np.array( expA, dtype = np.uint8 )
      uint8_t order = memv_ExpA.size

    return self.c_findIndx(&memv_DirA[0],&memv_ExpA[0],order)
  
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  cdef uint64_t c_findIndx(self, uint16_t* dirA,  uint8_t* expA, uint8_t order):
    """
    PURPOSE:      Implements a binary search so that it can find the given pair (dirA,expA) in
                  (self.dirA,self.expA)
     
    DESCRIPTION:  The condition that this satisfies is that it will return i such that

                  >>> (self.dirA[i,:],self.expA[i,:]) == (dirA,expA)
                  True

    INPUTS:      
              - uint16_t* dirA: Direction array with the basis of the direction to search.

              - uint8_t*  expA: Exponent array with the exponents of the basis that 
                                are present in the direction to search.

    OUTPUTS: 
              - uint64_t indx : position of the pair 

                        (dirA[:],expA[:]) in (p_dH.dirA[:,:],p_dH.expA[:,:])
              
    """
    #*************************************************************************************************
    cdef uint64_t indx = 0  # Initialized to avoid warnings from the compiler.

    if dirA[ZERO] == 0:     # Case where dirA and expA are all zeros

      return indx
    
    # end if     

    if order == 1:
      
      indx =  <uint64_t>dirA[ZERO]

    else:
      
      indx = c_binarySearch_dH( dirA, expA, &self.p_dH[order-1]) + 1

    # end if 

    return indx
  
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint64_t multIndx (self, uint64_t indx1, uint64_t indx2, uint8_t order):
    """
    PURPOSE:     Function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    """
    #*************************************************************************************************

    cdef uint64_t indx = 0  # Initialize so that there are no warnings in the compiler.
    cdef uint64_t indx1m1 = indx1-1, indx2m1 = indx2-1,

    if order == 1:
      
      if (indx1 == 0 ):
        
        self.merror = 0
        return indx2

      elif(indx2 == 0):

        self.merror = 0
        return indx1

      else:

        self.merror = 1
        indx = 0             # To avoid warnings from compiler
        return indx

      # end if 

    else:
      
      # Check first if the given indices are zero

      if (indx1 == 0 ):
        
        self.merror = 0
        return indx2

      elif(indx2 == 0):

        self.merror = 0
        return indx1

      # end if 

      indx = c_multDirections_dH( indx1m1, indx2m1, &self.p_dH[order-1], &self.merror)

    # end if 


    return indx + 1

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef uint64_t multIndxFast(self, uint64_t indx1, uint64_t indx2, uint8_t order):
    """
    PURPOSE:     Function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    """
    #*************************************************************************************************

    return c_helper_multIndx(indx1,indx2,order,self.p_dH,&self.merror)

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def getExpA(self, uint64_t indx, uint8_t order):
    """
    PURPOSE:    Return the corresponding exponent array of indx.  There is a cimport version of this 
                method: c_getExpA(uint64_t indx, uint8_t order) for much faster use
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] expA: Array containing the exponents of direction indx.
              
    """
    #*************************************************************************************************

    cdef:
      uint8_t* res = self.c_getExpA(indx,order)
      uint8_t i
    
    b = np.empty(order,dtype = np.uint8)

    for i in range(order):
      b[i] = res[i]
    # end for

    return b 

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  cdef uint8_t* c_getExpA(self, uint64_t indx, uint8_t order):
    """
    PURPOSE:    Return the corresponding exponent array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] expA: Array containing the exponents of direction indx.
              
    """
    #*************************************************************************************************

    cdef uint8_t i
    cdef uint64_t indx_m1 = indx-1

    
    
      
    if indx != 0:

      return &self.p_dH[order-1].p_expA[indx_m1*order]

    else:

      for i in range(order):

        self.p_dH[order-1].p_mexpA[i] = 0

      # end for

      return self.p_dH[order-1].p_mexpA

    # end if 

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef inline uint8_t* c_getUExpA(self, uint8_t order, uint8_t n = 1):
    """
    PURPOSE:  Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************
      
    return &self.p_dH[order-1].p_uexpA[(n-1)*order]
  
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef inline uint16_t* c_getUDirA(self, uint8_t order, uint8_t n = 1):
    """
    PURPOSE:    Return the corresponding user direction array.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************

    return &self.p_dH[order-1].p_udirA[(n-1)*order]
  
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def getDirA(self, uint64_t indx, uint8_t order):
    """
    PURPOSE:    Return the corresponding direction array of indx. There is a cimport version of this 
                method: c_getExpA(uint64_t indx, uint8_t order) for much faster use.
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************
    cdef:
      uint16_t* res = self.c_getDirA(indx,order)
      uint8_t i
    
    b = np.empty(order,dtype = np.uint16)

    # Copy the values.
    for i in range(order):
      b[i] = res[i]
    # end for

    return b 

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef uint16_t* c_getDirA(self, uint64_t indx, uint8_t order):
    """
    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************
    cdef uint8_t i
    cdef uint64_t indx_m1 = indx-1

    
    
      
    if indx != 0:

      return &self.p_dH[order-1].p_dirA[indx_m1*order]

    else:

      for i in range(order):

        self.p_dH[order-1].p_mdirA[i] = 0

      # end for

      return self.p_dH[order-1].p_mdirA

    # end if 

    

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uint64_t findMaxDir(self, uint64_t index, uint8_t order):
    """
    PURPOSE:    Return the maximum direction of count.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint64_t The maximum basis of said direction.
              
    """
    #*************************************************************************************************

    cdef uint64_t res = 0                 # Variable that has the maximum direction
    cdef uint64_t indx = index + 1

    if order == 1:
      
      res = indx - 1

    else:
      
      res = c_binarySearchUI64( self.p_dH[order-1].p_countOTI, indx ,self.p_dH[order-1].Nbasis )

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uint64_t getNels(self, uint64_t m, uint8_t order):
    """
    PURPOSE:    Return the number of total elements for m basis and maxorder.  
     
    INPUTS:      
              - uint64_t m: Number of directions.

    OUTPUTS:
              - uint64_t Number of elements.
              
    """
    #*************************************************************************************************

    cdef uint64_t res = 0  # Variable that has the maximum direction

    if order == 1:
      
      res = m + 1

    else:
      
      res = self.p_dH[order-1].p_countOTI[m] # TODO: Check when m > countOTI.size

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uint64_t getNParts(self, uint8_t order):
    """
    PURPOSE:    Return the number of partition sets for the given size of set.
     
    INPUTS:      
              - uint8_t n: number of elements of the set.

    OUTPUTS:
              - uint64_t: number of partitions for a set of n elements.
              
    """
    #*************************************************************************************************
    
    return self.p_dH[order-1].Npart

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint16_t getSet(self, uint8_t order,uint64_t i,uint64_t j):
    """
    PURPOSE:    Return the set, in binary format, for the given partition i and subset j.
     
    INPUTS:      
              - uint8_t  maxorder: number of elements of the set.

              - uint64_t i: Number of partition to look for.

              - uint64_t j: subset of the partition to look for.

    OUTPUTS:
              - uint16_t: number in which the high bits correspond to the position of the elements
                          that belong to the asked partition.
              
    """
    #*************************************************************************************************

    return self.p_dH[order-1].p_part[ i*order + j ]

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def getMultiples(self,uint64_t i, uint8_t order):
    """
    PURPOSE:    Return the set, in binary format, for the given partition i and subset j.
     
    INPUTS:      
              - uint8_t  maxorder: number of elements of the set.

              - uint64_t i: Index of the direction to look for .

    OUTPUTS:
              - uint8_t[:,:]: Matrix with all multiples.
              
    """
    #*************************************************************************************************
    cdef:
      uint64_t Nmult=0
      uint64_t j,k

    # Compute the multiples in C
    c_helper_getMultpl(&self.p_dH[order-1].p_expA[(i-1)*order], order, self.p_dH, &Nmult)

    # Create the numpy array to be returned.
    res = np.empty((Nmult,order),dtype = np.uint8)

    for j in range(Nmult):

      for k in range(order):

        res[j,k] = self.p_dH[order-1].p_multpl[j*order+k]

      # end for. 

    # end for.

    # for j in range(Nmult):

      



    # # end for




    return res

  #---------------------------------------------------------------------------------------------------







# c_helper_ordDirExpA(uint16_t* p_dirA, uint8_t* multiple, uint8_t order, 
#                         uint16_t* p_ndirA, uint8_t* p_nexpA)
    

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::   END OF CLASS HELPER   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




















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

  cdef extern from "numpy/arrayobject.h":
      void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)

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

  cdef extern from "numpy/arrayobject.h":
      void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)

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
  cdef extern from "numpy/arrayobject.h":
      void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)
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
  cdef extern from "numpy/arrayobject.h":
      void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)
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
cdef void c_getDirExpA(list dirArray, uint16_t** p_dirA, uint8_t** p_expA, uint8_t* order):
  """
  PURPOSE:      To convert a direction array given in human readable  form
                into its index number. 

  DESCRIPTION:  It just activates the binary positions of the corresponding 
                directions according to what is given in the dirArray.

  PARAMETERS
                dirArray:  a list of dual directions.
                
                maxorder: Order that changes the representation of the 
                binary number 

  RESULT:       An integer. The position of the coefficient that involves
                the given directions.
  """
  #***************************************************************************************************

  global h
  cdef uint8_t i = 0,k
  
  order[0] = 0
  p_dirA[0] = h.c_getUDirA(len(h.__mmax)-1,n=1)
  p_expA[0] = h.c_getUExpA(len(h.__mmax)-1,n=1)

  for dir_i in dirArray:
      
    if type(dir_i) == list:
    
      p_dirA[0][i] = dir_i[ZERO]
      p_expA[0][i] = dir_i[ONE]
      order[0] += dir_i[ONE]

    else:
    
      p_dirA[0][i] = dir_i
      p_expA[0][i] = 1
      order[0] += 1
        
    # end if

    i+=1
      
  # end for

  for k in range(i,len(h.__mmax)+2):

    p_dirA[0][k] = 0

    p_expA[0][k] = 0

  # end for 

#-----------------------------------------------------------------------------------------------------


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
def getDirExpA(dirArray):
  """
  PURPOSE:      To convert a direction array given in human readable  form
                into its index number. 

  DESCRIPTION:  It just activates the binary positions of the corresponding 
                directions according to what is given in the dirArray.

  PARAMETERS
                dirArray:  a list of dual directions.
                
                maxorder: Order that changes the representation of the 
                binary number 

  RESULT:       An integer. The position of the coefficient that involves
                the given directions.
  """
  #***************************************************************************************************

  # Add a piece of code to create the arrays according to the order.
  dirA = []
  expA = []



  for dir_i in dirArray:
      
    if type(dir_i) == list:
    
      dirA.append( dir_i[0] )
      expA.append( dir_i[1] )

    else:
    
      dirA.append( dir_i )
      expA.append( 1     )
        
    # end if
      
  # end for
  

  return (dirA,expA)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def findComb(int m,int n):
  """
  PURPOSE:   To find all possible combinations to create a dual number of 
             order n with m directions.

  EXAMPLE:
            >>> # for m=3, n=2
            >>> findComb(3+1,2)   # ...+1 to take into account the real direction.

  """
  #***************************************************************************************************
  
  if n == 0:
    
    return 1
    
  else:
    
    return comb(n+m-1,m-1,exact=True) # from scipy.special import comb
    
  # end if
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def printOrderPos(pos):
  """
  PURPOSE:  To print the imaginary direction referenced to a position of the 
            binary indexing.
  """
  #***************************************************************************************************
  if len(pos) == 0:
    head = ''
    body = ''
    tail = ''
  
  elif len(pos) == 1:
    head = ' * e('
    tail = ')'
    body = str(pos)#[1:-1]
  
  else:
    head = ' * e('
    tail = ')'
    body = str(pos)
  return (head + body.replace(" ","") + tail)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def printOrderPosLatex(list pos):
  """
  PURPOSE:  To print the imaginary direction referenced to a position of the 
            binary indexing.
  """
  #***************************************************************************************************
  if len(pos) == 0:
    head = '$'
    body = 'Re'
    tail = '$'
  
  elif len(pos) == 1:
    head = '$'
    tail = '$'
    body = '\epsilon_'+str(pos[0])#[1:-1]
  
  else:
    head = '$'
    tail = '$'
    body = ''
    eps = '\epsilon'
    for i in range(len(pos)):
      body += printLatexDir(pos[i])
    # end for 
  return (head + body.replace(" ","") + tail)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef str printLatexDir(object pos):
  """
  PURPOSE:  To print the imaginary direction referenced to a position of the 
            binary indexing.
  """
  #***************************************************************************************************
  cdef str body =''

  if pos.__class__ == list:
    body += '\epsilon_'+str(pos[0])+'^'+str(pos[1])
  else:    
    body += '\epsilon_'+str(pos)
  # end if 
  
  return body
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def getLatexDir(uint64_t indx_i,uint8_t order):
  """
  PURPOSE:  Create a human friendly string version version of the direction indx_i that it is representing.

  INPUTS:
          -> indx_i: Index representing a direction.

          -> order:  Maximum order of the direction.

  EXAMPLE:
          >>> getDirArray(9,2)  -> [2,3]
          >>> getDirArray(10,2) -> [[3,2]]
  """
  #***************************************************************************************************
  
  global h

  cdef: 
    uint64_t i
    uint16_t* dirs
    uint8_t*  aexp
  
  
  if indx_i == 0 :
    
    return '$Re$'

  elif order == 1:

    return '$\epsilon_'+str(indx_i)+'$'

  # find the non-zero values of dirArray
  i = order
  dirs = h.c_getDirA(indx_i,order)
  exps = h.c_getExpA(indx_i,order)
  body = '$'
  humDir = []

  for i in range(order):
    
       
    if exps[i]>1:
      
      # If the order is greater than zero, then the direction given
      # contains an exponent, therefore it should be organized by the
      # exponent as an array.
      body += '\epsilon_'+str(dirs[i])+'^'+str(exps[i])
      # humDir.append([dirs[i],exps[i]])
      
    elif exps[i] == 1:

      # If it does not contain an exponent, just add the direction.
      body += '\epsilon_'+str(dirs[i])
      # humDir.append(dirs[i])

    else:
      
      # No more things to add.
      break
      
    # end if
    
  # end for
  body+='$'
  return body
#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
def getDirArray(uint64_t indx_i,uint8_t order):
  """
  PURPOSE:  Create a human friendly version of the direction indx_i that it is representing.

  INPUTS:
          -> indx_i: Index representing a direction.

          -> order:  Maximum order of the direction.

  EXAMPLE:
          >>> getDirArray(9,2)  -> [2,3]
          >>> getDirArray(10,2) -> [[3,2]]
  """
  #***************************************************************************************************
  
  global h

  cdef: 
    uint64_t i
    uint16_t* dirs
    uint8_t*  aexp
  
  
  if indx_i == 0 :
    
    return []

  elif order == 1:

    return[indx_i]

  # find the non-zero values of dirArray
  i = order
  dirs = h.c_getDirA(indx_i,order)
  exps = h.c_getExpA(indx_i,order)
  
  humDir = []

  for i in range(order):
    
       
    if exps[i]>1:
      
      # If the order is greater than zero, then the direction given
      # contains an exponent, therefore it should be organized by the
      # exponent as an array.

      humDir.append([dirs[i],exps[i]])
      
    elif exps[i] == 1:

      # If it does not contain an exponent, just add the direction.
      humDir.append(dirs[i])

    else:
      
      # No more things to add.
      break
      
    # end if
    
  # end for
  
  return humDir
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def get_dHelp():
  """
  PURPOSE:  Return the global helper that is a global variable inside the otilib.

  """
  #***************************************************************************************************
  global h

  return h
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def get_CR(uint64_t nvar, uint8_t order):
  """
  PURPOSE:  Return the matrix form of an oti number of "nvar" variables and order "order".

  """
  #***************************************************************************************************
  global h
  cdef coomat_ui64_t resmat
  cdef uint64_t i=0

  resmat = c_oti_matform( nvar, order, p_dH)

  pymat = spr.lil_matrix( ( resmat.sizex, resmat.sizey ), dtype = np.uint64)

  for i in range(resmat.nonzero):
    
    pymat[resmat.p_rows[i],resmat.p_cols[i]] = resmat.p_data[i]

  # end for 

  free(resmat.p_data)
  free(resmat.p_rows)
  free(resmat.p_cols)

  return pymat
#-----------------------------------------------------------------------------------------------------


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
# def mdualGetMatPos(dirBasis,maxBasis):
    
   
     



#-----------------------------------------------------------------------------------------------------
#-------------------------------------   INITIALIZATION ONLY   ---------------------------------------
#-----------------------------------------------------------------------------------------------------


 


# Global variable to help do the multiplications. One of this is required per core being used. 
# Be careful. It requires some memory.
h = dHelp()


# To provide an easy manner to create numpy arrays from C without copying data
np.import_array()


# Define an array to check number types.
# Change to a function that checks all items.
# TODO: LOOK FOR A MORE EFFICIENT WAY TO CHECK VARIOUS data types.
number_types = (   float,      int, np.float64,   np.int64,\
                np.int32, np.int16,    np.int8, np.float32  )

int_types = ( int, np.int64, np.int32, np.int16, np.int8)

ZERO = 0
ONE  = 1

#-----------------------------------------------------------------------------------------------------