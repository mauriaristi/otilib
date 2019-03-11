# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=False
# cython: linetrace=False
# cython: binding=True
# cython: embedsignature=False
## distutils: define_macros=CYTHON_TRACE_NOGIL=1
## distutils: libraries = oti 
## distutils: extra_compile_args = -arch i386 -arch x86_64 
# filename: core.pyx

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                        # General numerical library
cimport numpy as np                       # C-level functions of numpy 
from libc.stdlib cimport malloc,free      # import memory managment functions.
from libc.stdlib cimport realloc          #    "              "
from libc.string cimport memcpy           # fast memory block copy.
from libc.string cimport memset           # fast memory instantiation.
from warnings import warn                 # Warnings
# from math import factorial                # Compute factorials
import scipy.sparse as spr                # Manipulator of sparse matrices
from scipy.special import comb            # Classic combinatorials
# from partitionsets import partition       # Compute partitions of sets
import pyoti.whereotilib as whereotilib   # A pure python script to get 
                                          #the current path of this folder.
from c_otilib cimport *                   # OTI lib in C.
cimport cython                            #
from cpython cimport PyObject             #
from cpython cimport Py_INCREF            #

#-----------------------------------------------------------------------------------------------------


cdef extern from "numpy/arrayobject.h":
      void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)

np.import_array()





# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::      CLASS HELPER      :::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 
cdef class dHelp:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  #
  #                                --->      Look in oti/core.pxd    <---
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
    # cdef str PATH_TO_FILES = whereotilib.getpath()+'../' # "/.../.../spr_otilibvX.Y/"
    cdef str PATH_TO_FILES = whereotilib.getpath()+'../data'
    cdef char* c_string = <char*>malloc(1024*sizeof(char))
    cdef uint64_t i   

    
    # copy data to to a c_string (to pass to a c_function.)
    for i in range(len(PATH_TO_FILES)):
    
      c_string[i] = <char>ord(PATH_TO_FILES[i])
    
    # end for 
    
    c_string[len(PATH_TO_FILES)] = <char>ord('\0') 

    # Load direction helper list using c_function.
    dhelp_load(c_string, &self.dhl)
    
    # Set also the global object.
    dhl = self.dhl

    # Unload variables.
    free(c_string)
    c_string = NULL

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:     Deallocate all memory that was manually allocated.
     
    DESCRIPTION: This will first dealloc what is inside each helper loaded, and then free the helper.
                 
              
    """
    #*************************************************************************************************

    dhelp_free( &self.dhl );

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __repr__(self):
    """
    PURPOSE:  Compact representation of direction helper.
              
    """

    cdef str out=''

    out += "<dhelp with "+str(self.dhl.ndh)+" helpers loaded>"

    return out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: Expanded representation of direction helper.
    """

    cdef str out=''
    cdef ord_t i

    out += "Direction Helper object with "+str(self.dhl.ndh)+" helpers:\n"

    # Loop over all direction helpers
    for i in range(self.dhl.ndh):
      
      out += "\nHelper "+ str(i+1)+":\n"
      out += "  - Truncation order: " + str(self.dhl.p_dh[i].order)+"\n"
      out += "  - Number of imaginary bases: " + str(self.dhl.p_dh[i].Nbasis)+"\n"
      out += "  - Total number of imaginary directions: " + str(self.dhl.p_dh[i].Ndir)+"\n"
      out += "  - Total number of multiplication tables: " + str(self.dhl.p_dh[i].Nmult)+"\n"
    # end for

    return out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def get_str_fulldir(self, imdir_t indx, ord_t order):
    """
    PURPOSE: Get the expanded string representation of an imaginary direction.
    """  
    cdef str out = ''
    cdef bases_t* dirs
    cdef ord_t j

    if order != 0:
      out += '['
      
      dirs = dhelp_get_imdir(indx,order,self.dhl)
           
      for j in range(order):
        out += str(dirs[j]) + ','
      # end for

      out = out[:-1] # remove last comma
      out += ']'
    # end if 


    return out
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def get_base_exp(self, imdir_t indx, ord_t order):
    """
    PURPOSE: Get the base - exponent representation of an imaginary direction given by its index 
    and order.
    """  
    cdef bases_t* dirs
    cdef bases_t im = 0
    cdef ord_t j,k=0, multiplicity = 0
    
    bases = []
    multipl = []

    if order != 0: 
      
      dirs = dhelp_get_imdir(indx,order,self.dhl)

      for j in range(order):
        # print(j, dirs[j])
        if k==0:
        
          im = dirs[j]
          k=1
          bases.append(im)
          multipl.append(0)
        
        # end if 

        if im == dirs[j]:

          multipl[len(multipl)-1] += 1

        else:

          im = dirs[j]
          bases.append(im)
          multipl.append(1)

        # end if

      # end for
    # end if 
    return [np.array(bases,dtype=np.uint16), np.array(multipl,dtype=np.uint8)]

  #***************************************************************************************************
  def get_compact_fulldir(self, imdir_t indx, ord_t order):
    """
    PURPOSE: Get the compact representation of an imaginary direction defined by (index,order).
    """  
    cdef ord_t j
    
    bases, multipl= self.get_base_exp(indx,order)

    out = []

    for j in range(len(multipl)):
      
      if multipl[j] == 1:
      
        out.append(bases[j])
      
      else:
      
        out.append([bases[j],multipl[j]])
      
      # end if 

    # end for 

    return out 
  #--------------------------------------------------------------------------------------------------- 


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::   END OF CLASS HELPER   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





























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
  
  cpdef list res = []
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
