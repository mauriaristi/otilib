# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=True
# cython: linetrace=True
# cython: binding=True
# cython: embedsignature=True
# distutils: define_macros=CYTHON_TRACE_NOGIL=1
# distutils: libraries = oti otifem 
# distutils: extra_compile_args = -arch i386 -arch x86_64
# filename: otilib.pyx
#$$$$$$ bounds/check=True, wrap/around=True, none/check=False

  

## @package otinum
# This package contains the tools necessary to use Order Truncated Imaginary numbers in 
# python. The library is sparse, therefore it is intended to be efficient with respect
# to large problems with lots of variables and high order derivatives.

## @mainpage  OTI Number library otinum
# Library to handle sparse Order Truncated Imaginary Numbers in Python, with a particular
# focus on automatic differentiation. \n\n
#
# <b> Current Version </b>: 0.9      \n
# <b> First Created </b>: 04/20/2016 \n
# <b> Last Modified </b>: 06/13/2018 \n
#
# <b>Contributors</b>: \n
# Mauricio Aristizabal Cano\n
# Applied Mechanics Research Group (Mecanica Aplicada) \n
# Universidad EAFIT, Medellín, Colombia.
#
# Manuel Julio Garcia Ruiz\n
# Applied Mechanics Research Group (Mecanica Aplicada) \n
# Universidad EAFIT, Medellín, Colombia.\n
# Department of Mechanical Engineering\n
# University of Texas at San Antonio, USA.
 

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
# import meshio                       # manipulating mesh

#-----------------------------------------------------------------------------------------------------



include "otinum.pxi"


include "sotinum.pxi"


include "ndarray.pxi"


include "oticore.pxi"


include "otimat.pxi"


include "sndarray.pxi"


include "otifem.pxi"










































































































































































































































































# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::      Auxiliary Functions      ::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 


# #*****************************************************************************************************
# cdef float64_t[:,::1] __sprotinum2Mat_dense(spr_otinum mySelf, uint64_t finalshape):
#   """
#   PURPOSE:  To implement in c-speed the multiplication of dual numbers.

#   """
#   #***************************************************************************************************





#   cdef float64_t[:,::1] mat = np.zeros([finalshape,finalshape],dtype = np.float64)

#   cdef uint64_t i
#   cdef uint64_t j
#   cdef uint64_t k

#   cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
#   # get real coefficient
#   # fill up the diagonal
  
#   if mySelf.maxorder == 1:
    
#     # Fill up diagonal.
#     if mySelf.indx[0]==0:

#       for i in range(finalshape):
        
#         mat[i,i] = mySelf.coefs[0] 
        
#       # end for

#     # end if
    
#     for i in range(mySelf.indx.size):
      
#       # k'th element of the dual number self.

#       mat[mySelf.indx[i],0] = mySelf.coefs[i]
      
#     # end for
    
#   else:
    
#     # loop in each element of the matrix
#     for i in range(mySelf.indx.size):

#       for j in range(finalshape):
#         # Get the directions and the exponents of the column j directions

#         k =  mySelf.h.multIndx(mySelf.indx[i],j,error)

#         if k<finalshape and error[0] == 0:

#           mat[k,j] = mySelf.coefs[i]

#         # end if 

#       # end for
      
#     # end for
    
#   # end if

#   return mat
  
# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cdef float64_t[:,::1] __otinum2Mat_dense(otinum mySelf, uint64_t finalshape):
#   """
#   PURPOSE:  To implement in c-speed the multiplication of dual numbers.

#   """
#   #***************************************************************************************************





#   cdef float64_t[:,::1] mat = np.zeros([finalshape,finalshape],dtype = np.float64)

#   cdef uint64_t i
#   cdef uint64_t j
#   cdef uint64_t k



#   cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
  
#   cdef float64_t coef  

#   # get real coefficient
#   # fill up the diagonal
  
#   if mySelf.maxorder == 1:
    
#     # Fill up diagonal.
    
#     j = 0
#     for i in range(finalshape):
            
#       mat[i,i] = mySelf.coefs[j] 
          
#     # end for
    
#     for i in range(mySelf.coefs.size):
      
#       # k'th element of the dual number self.

#       mat[i,j] = mySelf.coefs[i]
      
#     # end for
    
#   else:
    
#     # loop in each element of the matrix
#     for i in range(mySelf.coefs.size):
      
#       coef = mySelf.coefs[i]
      
#       if coef != 0.0:

#         for j in range(finalshape):
#           # Get the directions and the exponents of the column j directions

#           k =  h.multIndx(i, j, mySelf.maxorder, error)

#           if k<finalshape and error[0] == 0:

#             mat[k,j] = mySelf.coefs[i]

#           # end if 

#         # end for

#       # end if
      
#     # end for
    
#   # end if

#   return mat
  
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef object __otinum2Mat_spr(spr_otinum mySelf, uint64_t finalshape):
#   """
#   PURPOSE:  To implement in c-speed the multiplication of dual numbers.

#   """
#   #***************************************************************************************************

#   cdef object mat = spr.lil_matrix((finalshape,finalshape))

#   cdef uint64_t i
#   cdef uint64_t j
#   cdef uint64_t k

#   cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
#   # get real coefficient
#   # fill up the diagonal
  
#   # get real coefficient
#   # fill up the diagonal
  
#   if mySelf.maxorder == 1:
    
#     # Fill up diagonal.
    
#     j = 0
#     for i in range(finalshape):
            
#       mat[i,i] = mySelf.coefs[j] 
          
#     # end for
    
#     for i in range(mySelf.coefs.size):
      
#       # k'th element of the dual number self.

#       mat[i,j] = mySelf.coefs[i]
      
#     # end for
    
#   else:
    
#     # loop in each element of the matrix
#     for i in range(mySelf.coefs.size):
      
#       coef = mySelf.coefs[i]
      
#       if coef != 0.0:

#         for j in range(finalshape):
#           # Get the directions and the exponents of the column j directions

#           k =  h.multIndx(i, j, mySelf.maxorder, error)

#           if k<finalshape and error[0] == 0:

#             mat[k,j] = mySelf.coefs[i]

#           # end if 

#         # end for

#       # end if
      
#     # end for
    
#   # end if

#   return mat
  
# #-----------------------------------------------------------------------------------------------------





# #*****************************************************************************************************
# cdef object __sprotinum2Mat_spr(spr_otinum mySelf, uint64_t finalshape):
#   """
#   PURPOSE:  To implement in c-speed the multiplication of dual numbers.

#   """
#   #***************************************************************************************************

#   cdef object mat = spr.lil_matrix((finalshape,finalshape))

#   cdef uint64_t i
#   cdef uint64_t j
#   cdef uint64_t k

#   cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
#   # get real coefficient
#   # fill up the diagonal
  
#   if mySelf.maxorder == 1:
    
#     # Fill up diagonal.
#     if mySelf.indx[0]==0:

#       for i in range(finalshape):
        
#         mat[i,i] = mySelf.coefs[0] 
        
#       # end for

#     # end if
    
#     for i in range(mySelf.indx.size):
      
#       # k'th element of the dual number self.

#       mat[mySelf.indx[i],0] = mySelf.coefs[i]
      
#     # end for
    
#   else:
    
#     # loop in each element of the matrix
#     for i in range(mySelf.indx.size):

#       for j in range(finalshape):
#         # Get the directions and the exponents of the column j directions

#         k =  mySelf.h.multIndx(mySelf.indx[i],j,error)

#         if k<finalshape and error[0] == 0:

#           mat[k,j] = mySelf.coefs[i]

#         # end if 

#       # end for
      
#     # end for
    
#   # end if

#   return mat
  
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef spr_otinum __sum_otinum__(spr_otinum mySelf,spr_otinum other_in):
#   """
#   PURPOSE:  To implement in c-speed the sum of dual numbers.

#   """
#   #***************************************************************************************************

#   # Create a new array to contain the sum of all the coefficients.
#   cdef uint64_t  otherEls = other_in.indx.size
#   cdef uint64_t  SEls     = mySelf.indx.size
#   cdef uint64_t  maxEls   = otherEls + SEls
#   cdef uint64_t[::1]  tmpIndx  = np.empty(maxEls,dtype=np.uint64)
#   cdef float64_t[::1] tmpCoefs = np.empty(maxEls,dtype=np.float64)
#   cdef uint64_t k1 = 0 
#   cdef uint64_t k2 = 0
#   cdef uint64_t count = 0
#   cdef spr_otinum S     = mySelf.copy()
#   cdef spr_otinum other = other_in.copy()
#   cdef spr_otinum answer
  

#   # check to preserve the maximum order             
#   if other.maxorder!=S.maxorder:
    
#     if other.maxorder > S.maxorder:
      
#       S.changeOrder(other.maxorder)
      
#     else:
      
#       other.changeOrder(S.maxorder)
      
#     # end if
    
#   # end if
  
#   if otherEls != 0 and SEls != 0:

    
    
#     while (k1+k2) !=  maxEls:

#       if k1 == SEls:
        
#         tmpIndx[count] = other.indx[k2]
#         tmpCoefs[count]= other.coefs[k2]
#         count += 1
#         k2+=1
        
#       elif k2 == otherEls:
        
#         tmpIndx[count] = S.indx[k1]
#         tmpCoefs[count]= S.coefs[k1]
#         count += 1
#         k1    += 1 
        
#       elif S.indx[k1] < other.indx[k2]:
        
#         tmpIndx[count] = S.indx[k1]
#         tmpCoefs[count]= S.coefs[k1]
#         k1    += 1
#         count += 1

#       elif other.indx[k2] < S.indx[k1]:
        
#         tmpIndx[count] = other.indx[k2]
#         tmpCoefs[count]= other.coefs[k2]
#         count += 1
#         k2+=1 

#       else:
        
#         # add tolerance check
#         if np.abs(other.coefs[k2] + S.coefs[k1])>S.tol:

#           tmpIndx[count] = other.indx[k2]
#           tmpCoefs[count]= other.coefs[k2] + S.coefs[k1]
          
#           count+=1

#         # end if

#         k1+=1
#         k2+=1

#       # end if

#     # end while

#     answer = spr_otinum(tmpIndx[:count],tmpCoefs[:count],S.maxorder)


    
#   elif SEls == 0:  
    
#     answer = other

#   else:

#     answer = S

#   # end if
#   return answer

# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef spr_otinum __mult_otinum(spr_otinum mySelf, spr_otinum other_in):
#   """
#   PURPOSE:  To implement in c-speed the multiplication of dual numbers.

#   """
#   #***************************************************************************************************

#   # Initialize an empty multicomplex number.
#   cdef spr_otinum S        = spr_otinum(np.array([],dtype=np.uint64), np.array([],dtype=np.float64),mySelf.maxorder)
#   cdef spr_otinum other    = other_in.copy()
#   cdef spr_otinum selfcopy = mySelf.copy()
#   cdef uint8_t[:] error
#   cdef uint64_t resIndx

#   # Preserve only the lowest order
#   if other.maxorder!=S.maxorder:
    
#     if other.maxorder > S.maxorder:
      
#       other.changeOrder(S.maxorder)
      
#     else:

#       selfcopy.changeOrder(other.maxorder)
#       S.changeOrder(other.maxorder)
      
#     # end if
    
#   # end if

#   # If any of the numbers is zero, then the result will be zero.
#   if (selfcopy.indx.size != 0) and (other.indx.size != 0) :

#     error = np.array([0],dtype=np.uint8)

#     # define particular result for order == 1.
#     if S.maxorder == 1:

#       return selfcopy[0]*other + other[0]*selfcopy - selfcopy[0]*other[0]

#     # end if

#     for i in range(0,selfcopy.indx.size):
      
#       for j in range(0,other.indx.size):
        
#         if selfcopy.indx[i] == 0:

#           S[ other.indx[j] ] = S[ other.indx[j] ] + other.coefs[j]*selfcopy.coefs[i] 

#         elif other.indx[j] == 0:

#           S[ selfcopy.indx[i] ] = S[ selfcopy.indx[i] ] + selfcopy.coefs[i] * other.coefs[j] 
        
#         else:

#           # Compute the order of the terms the operation.
#           resIndx = S.h.multIndx(selfcopy.indx[i],other.indx[j],error)

#           if error[0] == 0 :    # No error.

#             # Add result to the number
#             # TODO: Here we are doing two binarySearch calls. Modify it so that 
#             # we only create one.
#             S[resIndx] = S[resIndx] + selfcopy.coefs[i] * other.coefs[j]

#           # end if 

#         # end if
        
#       # end for. j
      
#     # end for. i

#   # end if 
#   return S
# #-----------------------------------------------------------------------------------------------------









# #*****************************************************************************************************
# cpdef ndarray solveLU(otimat A, ndarray b, solver = 0):
#   """
#   PURPOSE:  Solve a system Ax = b

#   """
#   #***************************************************************************************************

  
#   cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.order ) 
#   cdef uint64_t i, indxX, indxA, k
#   cdef uint8_t  j , pos
#   cdef uint8_t[:,::1] multiples
#   cdef uint8_t[::1]  expArray
#   cdef uint16_t[::1] dirArray
#   cdef float64_t[:] fi, solvedX   # Holder for the solution  
#   # cdef np.ndarray[float64_t, ndim=1] 
#   cdef object K0, Kj, A0
#   cdef uint16_t[::1] dirA = np.zeros(A.maxorder,dtype = np.uint16)
#   cdef uint16_t[::1] dirX = np.zeros(A.maxorder,dtype = np.uint16)
#   cdef uint8_t[::1] expA = np.zeros(A.maxorder,dtype = np.uint8)
#   cdef uint8_t[::1] expX = np.zeros(A.maxorder,dtype = np.uint8)
#   cdef uint8_t[::1] newExpA
#   # Create a copy of A?
#   # Change the type of sparse matrix to CSR
#   A.tocsr()

#   A0 = spr.linalg.splu(A[ZERO].tocsc())

#   # TODO: Check dimensions of b, A to match.
  
#   # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
#   for i in range(A.ndir):
    

#     fi = b.data[:,i]

#     # Get direction and exponent arrays:
#     expArray = h.getExpA(i,A.maxorder)
#     dirArray = h.getDirA(i,A.maxorder)

#     # get the multiples of the exponent array:
#     multiples = compMultiples(expArray)

#     # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
#     # loop in all multiples
#     for j in range(multiples.shape[0]-1):

#       # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
#       pos = multiples.shape[0]-j-1

#       c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , pos,\
#                   &dirA[0], &expA[0], A.maxorder)

#       # Get the mirrored multiple for vector X
#       c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , j, \
#                   &dirX[0], &expX[0], A.maxorder)
      
#       # Get the equivalent index for A.
#       indxA = h.findIndx(dirA, expA, A.maxorder)

#       if dirX[0] == 0:

#         indxX = 0

#       else:

#         # Get the equivalent index for X.
#         indxX = h.findIndx(dirX, expX, A.maxorder)

#       # end if 

#       # Subtract A_indxA * x_indxX to the fi vector
#       fi -= A[indxA].dot(x.data[:,indxX])


#       # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
#       # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
#     # end for

#     # TODO: Change according to all different solvers selected.

#     x.data[:,i]  = A0.solve(fi.base)   # Solve factorized system


#   # end for

#   return x



# #-----------------------------------------------------------------------------------------------------











# #*****************************************************************************************************
# cpdef ndarray solveLU2(otimat A, ndarray b, solver = 0):
#   """
#   PURPOSE:  Solve a system Ax = b

#   """
#   #***************************************************************************************************

  
#   cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.maxorder ) 
#   cdef uint64_t i, indxX, indxA, k
#   cdef uint8_t  j , pos
#   cdef uint8_t[:,::1] multiples
#   cdef uint8_t[::1]  expArray
#   cdef uint16_t[::1] dirArray
#   # cdef float64_t[:]  solvedX   # Holder for the solution  
#   cdef np.ndarray fi 
#   cdef object A0
#   cdef uint16_t[::1] dirA = np.zeros(A.maxorder,dtype = np.uint16)
#   cdef uint16_t[::1] dirX = np.zeros(A.maxorder,dtype = np.uint16)
#   cdef uint8_t[::1] expA = np.zeros(A.maxorder,dtype = np.uint8)
#   cdef uint8_t[::1] expX = np.zeros(A.maxorder,dtype = np.uint8)
#   cdef uint8_t[::1] newExpA
#   # Create a copy of A?
#   # Change the type of sparse matrix to CSR
#   A.tocsr()

#   A0 = spr.linalg.splu(A[ZERO].tocsc())

#   # TODO: Check dimensions of b, A to match.
  
#   # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
#   for i in range(A.ndir):
    

#     fi = b.data[:,i].copy()

#     # Get direction and exponent arrays:
#     expArray = h.getExpA(i,A.maxorder)
#     dirArray = h.getDirA(i,A.maxorder)

#     # get the multiples of the exponent array:
#     multiples = compMultiples(expArray)

#     # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
#     # loop in all multiples
#     for j in range(multiples.shape[0]-1):

#       # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
#       pos = multiples.shape[0]-j-1

#       c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , pos,\
#                   &dirA[0], &expA[0], A.maxorder)

#       # Get the mirrored multiple for vector X
#       c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , j, \
#                   &dirX[0], &expX[0], A.maxorder)
      
#       # Get the equivalent index for A.
#       indxA = h.findIndx(dirA, expA, A.maxorder)

#       if dirX[0] == 0:

#         indxX = 0

#       else:

#         # Get the equivalent index for X.
#         indxX = h.findIndx(dirX, expX, A.maxorder)

#       # end if 

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
# cpdef ndarray ones(shape = None , uint8_t maxorder = 1 , uint16_t m = 1):
#   """
#   PURPOSE: Create a ndarray filled with ones in the real component.

#   """
#   #***************************************************************************************************

#   cdef tuple finalShape
#   cdef ndarray res 
#   cdef uint64_t i,j,k,l
#   cdef float64_t value = 1., zeroval = 0.

#   if shape == None:
#     raise ValueError("shape keyword must be defined.")
#   if type(shape) == int:
    
#     finalShape = (shape,)

#   else:
    
#     finalShape = shape

#   # end if 

#   res = ndarray(shape = finalShape,  m = m, maxorder = maxorder ) 
#   res[:] = zeroval

#   if len(res.shape) == 1:
#     # 1D OTI array

#     res.data[:,0] = value

#   elif len(res.shape) == 2:
#     # 2D OTI array
    
#     res.data[:,0,0] = value    

#   elif len(res.shape) == 3:
#     # 3D OTI array

#     res.data[:,0,0,0] = value

#   # end if

#   return res

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef compMultiplesPre(uint8_t[::1] expArray, uint8_t[:,::1] multiples, \
#                                       uint8_t[::1] multiple, uint64_t[:] maxiter):
#   """
#   PURPOSE:  Compute the multiples of an exponent array with preallocated array.

#   """
#   #***************************************************************************************************
  
#   cdef uint64_t i ,j
#   cdef uint8_t exp, k, passed
#   # cdef uint8_t[::1] multiple = np.zeros(expArray.size,dtype = np.uint8)
#   # cdef uint8_t multiples 
  

#   maxiter[ZERO] = 1
  
#   for exp in expArray:
                
#     maxiter[ZERO] *= exp+1 

#   # end for

#   for i in range(multiples.shape[ZERO]):

#     for j in range(multiples.shape[ONE]):

#       multiples[i,j] = ZERO
#       multiple[j] = ZERO

#     # end for

#   # end for 

#   for i in range(1,maxiter[ZERO]):

#     passed = 0
#     k = 0

#     while passed == 0:

#       if (multiple[k]+1)>expArray[k]:

#         multiple[k] = 0
#         k += 1

#       else:

#         multiple[k] += 1
#         passed = 1

#       # end if
    
#     # end while

#     for k in range(expArray.size):

#       multiples[i,k] = multiple[k]

#     # end for

#   # end for 

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef uint8_t[:,::1] compMultiples(uint8_t[::1] expArray):
#   """
#   PURPOSE:  Compute the multiples of an exponent array.

#   """
#   #***************************************************************************************************
  

#   cdef uint64_t maxiter = 1
#   cdef uint64_t i 
#   cdef uint8_t exp, k, passed
#   cdef uint8_t[::1] multiple = np.zeros(expArray.size,dtype = np.uint8)
#   cdef uint8_t[:,::1] multiples 

#   for exp in expArray:
                
#     maxiter *= exp+1 

#   # end for

  
#   multiples = np.zeros((maxiter,expArray.size),dtype = np.uint8)

#   for i in range(1,maxiter):

#     passed = 0
#     k = 0

#     while passed == 0:

#       if (multiple[k]+1)>expArray[k]:

#         multiple[k] = 0
#         k += 1

#       else:

#         multiple[k] += 1
#         passed = 1

#       # end if
    
#     # end while

#     # print(np.array(multiple))

#     for k in range(expArray.size):

#       multiples[i,k] = multiple[k]

#     # print(np.array(multiple))

#   # end for 

#   return multiples 

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef uint8_t[::1] orderDirExpArray(uint16_t[::1] dirA,    uint8_t[::1]    multExpA ,\
#                                       uint16_t[::1] newDirA):
#   """
#   PURPOSE:  Organize a Multiple exponent array into the standard of this library.

#   """
#   #***************************************************************************************************
  

#   cdef uint8_t i
#   cdef uint8_t j = 0 
#   cdef uint8_t[::1] newExpA
#   # cdef uint8_t exp, k, passed
  
#   newDirA = np.zeros(dirA.size,dtype=np.uint16)
#   newExpA = np.zeros(dirA.size,dtype=np.uint8)

#   for i in range(dirA.size):

#     if multExpA[i] != 0: # the exponent exist in the solution.
      
#       newDirA[j] = dirA[i]
#       newExpA[j] = multExpA[i]
#       j += 1

#     # end if

#   # end for

#   return newExpA
  

# #-----------------------------------------------------------------------------------------------------















# #*****************************************************************************************************
# def e_spr(dirArray):
#   """
#   PURPOSE:  To create a dual number with value 1 at the specified
#             dual direction, in a human friendly manner.

#   EXAMPLE:  >>> e(2)
#             1.0 * e(2)
            
#             >>> e([1,2])
#             1.0 * e([1,2])
            
#             >>> e([1,[2,3]])
#             1.0 * e([1,[2,3]])
#   """
#   #***************************************************************************************************
  
#   if type(dirArray)==int:
    
#     return spr_otinum(np.array([dirArray],dtype=np.uint64),np.array([1.],dtype=np.float64),1)
    
#   # end if
    
#   tmp_dirA,tmp_expA = getDirExpA(dirArray)
#   cdef uint8_t maxorder = np.sum(tmp_expA)
#   cdef uint8_t i
#   cdef uint64_t indx

#   # create the real direction arrays:
#   dirA = np.zeros(maxorder,dtype = np.uint16)
#   expA = np.zeros(maxorder,dtype = np.uint8)
  
#   for i in range(len(tmp_expA)):
    
#     dirA[i] = tmp_dirA[i]
#     expA[i] = tmp_expA[i]

#   # end for 

#   if dirArray[0] == 0:
      
#     indx = 0

#   elif maxorder == 1:

#     indx = dirArray[0]

#   else:

#     h =  H[maxorder-1]
#     indx = h.findIndx(dirA,expA)

#   # end if
  
#   return spr_otinum(np.array([indx],dtype=np.uint64),np.array([1.],dtype=np.float64),maxorder)

# #-----------------------------------------------------------------------------------------------------















# #*****************************************************************************************************
# cdef spr_otinum derivMultivFunc(float64_t[::1] f_der, spr_otinum val):
#   """
#   PURPOSE:  To differentiate a function f that depends on another function
#             g which depends on several variables. 

#             i.e. f( g(x1,...,xn) )

#             g comes evaluated and it is represented by the OTI number 
#             val.
  
#   WARNING: This is a very rudimentary implementation. If you have time to
#           contribute, this is a function that might be very crucial to 
#           optimize.

#   EXAMPLE:   
#   """
#   #***************************************************************************************************
  

#   # Check if the input is a real number only.

#   if (val.indx.size==1) and (val.indx[0]==0):

#     return spr_otinum(np.array([0],dtype=np.uint64),np.array([f_der[0]],dtype = np.float64),val.maxorder)

#   # end if 
  
#   # Get all directions of the current number

#   # compute the maximum index for this.
#   cdef uint16_t[::1] allDir = np.empty(val.indx.size*val.maxorder,dtype=np.uint16)
#   cdef uint64_t i, k, j
#   cdef uint16_t[::1] iDir
  
#   for i in range(val.indx.size):
    
#     iDir = val.h.getDirA(val.indx[i])


#     j = i*val.maxorder
#     # k = (i+1)*val.maxorder

#     # add all directions to the main array:
#     for k in range(val.maxorder):

#       allDir[j+k] = iDir[k]

#     # end for
  
#   # all base directions should be here
  
#   # VERY SLOW. THINK ABOUT MODIFYING THIS LINES
#   allDir = np.unique(allDir)
#   cdef uint16_t[::1] variables = np.array(allDir)[np.nonzero(allDir)]
  
#   # For an 'efficient' implementation, the variables associated to the dual 
#   # directions are mapped to an organized ascending set of variables, despite 
#   # the variables can be handled easily like implemented.
#   # This is, if the variables to compute derivatives are [1,10,20]
#   # the mapped array is [1,2,3]
#   cdef uint16_t n_var = variables.size
  

#   # maximum number of coefficients...
#   cdef uint64_t max_i = findComb(n_var+1,val.maxorder)-1 # take out the real part
  

#   # Create the arrays to define an spr_otinum.

#   cdef float64_t[::1] resCoefs = np.empty(max_i+1,dtype = np.float64)
#   cdef uint64_t[::1]  resIndx = np.empty(max_i+1,dtype = np.uint64)
#   cdef uint16_t[::1]  dirA
#   cdef uint16_t[::1]  mdirA = np.empty(val.maxorder,dtype = np.uint16)
#   cdef uint8_t[::1]   expA

#   #define the real components.
#   resIndx[0]  = 0
#   resCoefs[0] = f_der[0]

#   for i in range(1,max_i+1):
    
#     # A more efficient implementation would know that if 
#     # one of the values of val is not present, some FaaDiBruno
#     # coefficients wont need to be computed. Therefore,
#     # that might help to improve the performance of the algorithm.

#     # get the direction array.
#     dirA = val.h.getDirA(i)
#     expA = val.h.getExpA(i)

#     # map the directions.
#     mapDirArray(dirA,variables,mdirA)
    
    
#     # Define the new positions in the object
#     resIndx[i] = val.h.findIndx(mdirA,expA)
#     resCoefs[i] = FaaDiBruno(mdirA,expA,f_der,val)
    
#   # end for

#   return spr_otinum(resIndx,resCoefs,val.maxorder)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef void mapDirArray(uint16_t[::1] dirA,uint16_t[::1]  mapder, uint16_t[::1] mdirA):
#   """
#   PURPOSE:  Map OTI number direction array with respect to a mapping 
#             array.
   
#   EXAMPLE:   
#             >>> mapDirArray([[1,2],3,4],[2,10,15,18])
#             [[2,2],15,18]

#             >>> mapDirArray([1,2,3,[4,3],[6,10]],[10,11,12,13,14,15,16])
#             [10,11,12,[13,3],[15,10]]
#   """
#   #***************************************************************************************************
  
#   cdef uint8_t i

#   for i in range(dirA.size):

#     if dirA[i] != 0:
      
#       mdirA[i] = mapder[dirA[i]-1]

#     else:
      
#       mdirA[i] = 0

#     # end if 
      
#   # end for

# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef void collapseArray(uint16_t[::1] array, uint16_t[::1] dirA, uint8_t[::1] expA):
#   """
#   PURPOSE:  To collapse an expanded OTI number direction array into its 
#             corresponding OTI direction array 
   
#   EXAMPLE:   
#             >>> collapseArray([1,1,1,1,1])
#             [[1,5]]

#             >>> collapseArray([1,1,2,3,3,3])
#             [[1,2],2,[3,3]]
#   """
#   #***************************************************************************************************

#   cdef uint16_t oldValue = array[0]
#   cdef uint8_t  count = 0
#   cdef uint8_t  iDir  = 0
#   cdef uint8_t  i

#   for i in range(array.size):

#     if array[i] == 0:

#       continue

#     elif array[i] == oldValue:
      
#       count += 1

#     else:
      
#       expA[iDir] = count
#       dirA[iDir] = oldValue
#       iDir += 1
#       oldValue = array[i]
#       count = 1

#     # end if 

#   # end for

#   expA[iDir] = count
#   dirA[iDir] = oldValue
#   iDir += 1

#   # Put zeros in all other values of the array, if it is the case:

#   if iDir != dirA.size:
    
#     for i in range(iDir,dirA.size):

#       expA[i] = 0
#       dirA[i] = 0

#     # end for

#   # end if 
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************   
# cdef uint16_t[::1] expandArray(uint16_t[::1] dirA, uint8_t[::1] expA):
#   """
#   PURPOSE:  Expand a OTI number direction array, where the direction
#             indicator is repeated the number of times the exponent 
#             indicates. 

#             * Useful for Faa di Bruno Formula.
   
#   EXAMPLE:   
#             >>> expandArray([[1,5]])
#             [1,1,1,1,1]

#             >>> expandArray([[1,2],2,[3,3]])
#             [1,1,2,3,3,3]
#   """
#   #***************************************************************************************************
  
#   cdef uint8_t order = np.sum(expA)
#   cdef uint16_t[::1] newarray = np.zeros(dirA.size,dtype = np.uint16)
  
#   cdef uint8_t idir = 0
#   cdef uint8_t count = 0
#   cdef uint8_t i

#   for i in range(order):
    
#     newarray[i]=dirA[idir]

#     #update counter
#     count = count+1
    
#     if count == expA[idir]:
    
#       count = 0
#       idir +=1
    
#     # end if 

#   # end for 

#   return newarray
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cdef float64_t FaaDiBruno(uint16_t[::1] dirA, uint8_t[::1] expA, float64_t[::1] f_der, spr_otinum x):
#   """
#   PURPOSE:  To apply the Faa di bruno formula to find the coefficient
#             that corresponds to a specific partial derivative of f.
  
#   """
#   #***************************************************************************************************
    
#   # expand the deriv array into a single level array
#   # expandArray(dirA,expA)
  
#   cdef float64_t sum_ = 0.
#   cdef float64_t mult 
#   cdef uint16_t[::1] dirA_ = np.empty(x.maxorder,dtype = np.uint16) # It is expensive to create arrays
#   cdef uint8_t[::1] expA_ = np.empty(x.maxorder,dtype = np.uint8)   # at each iteration. Consider 
#   cdef uint8_t i, j, el, count, nsets                               # inputing the allocated arrays  
#   cdef uint16_t seti
#   cdef uint8_t order = np.sum(expA)
#   cdef uint16_t[::1] expandedArray = expandArray(dirA,expA)
#   cdef uint16_t[::1] mdir = np.empty(x.maxorder,dtype = np.uint16)

   
  
#   # for part in partition.Partition( expandArray(dirA,expA) ):
#   for i in range(psets.getNParts(order)):                      # Look up partition i

#     mult = 1.

#     nsets = 0

#     # for subpart in part:
#     for j in range(order):    # Subpart j

#         seti = psets.getSet(order,i,j)  # get the j'th set of the partition i.

#         if seti == 0:   # if partition is == 0 set is full of zeros, therefore avoid computation.

#           continue

#         # end if

#         nsets += 1           # counts the number of sets in the partition.

#         el = 0               # gets the element  at which 
#         count = 0

#         while seti != 0:     # values of the sets are stored in the bits of seti

#           if seti & 1:

#             mdir[count] = expandedArray[el]
#             count+=1

#           # end if 

#           seti = (seti>>1)
#           el += 1

#         # end while

#         # fill up the other values as zeros:

#         for k in range(count,x.maxorder):

#           mdir[k] = 0

#         # end 

        
#         collapseArray(mdir, dirA_, expA_ )
        
#         mult *= x.getDerivByDirExp(dirA_,expA_)
        
#     # end for

#     sum_ +=  f_der[nsets]  *  mult
      
#   # end for
  
#   cdef float64_t factor = 1.
  
#   for i in range(expA.size):
    
#     factor *= factorial(expA[i])
  
#   # end for
  
#   return sum_/factor
# #-----------------------------------------------------------------------------------------------------

