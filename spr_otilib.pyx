#cython: boundscheck=True, wraparound=True, nonecheck=False

## @package spr_otinum
# This package contains the tools necessary to use Multi Power Multi Dual numbers in 
# python. The library is sparse, therefore it is intended to be efficient with respect
# to large problems with lots of variables and high order derivatives.



## @mainpage  OTI Number library spr_otinum
# Library to handle sparse Order Truncated Imaginary Numbers in Python, with a particular
# focus on automatic differentiation. \n\n
#
# <b> Current Version</b>: 0.6  \n
# <b> First Created</b>: 04/20/2016 \n
# <b> Last Modified</b>: 02/16/2017 \n
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
from warnings import warn           # Warnings
from math import factorial          # Compute factorials
import scipy.sparse as spr          # Handle sparse matrices
from scipy.special import comb      # Classic combinatorials
from partitionsets import partition # Compute partitions of sets
import whereotilib                   # A pure python script to get the current path of this folder.
#-----------------------------------------------------------------------------------------------------




#-----------------------------------------------------------------------------------------------------
#--------------------------------------     TYPE DECLARATIONS     ------------------------------------
#-----------------------------------------------------------------------------------------------------
# ctypedef np.float64_t     float64_t   # 64 bit Float
# ctypedef   np.uint8_t       uint8_t   #  8 bit unsigned int
# ctypedef  np.uint16_t      uint16_t   # 16 bit unsigned int
# ctypedef  np.uint32_t      uint32_t   # 32 bit unsigned int
# ctypedef  np.uint64_t      uint64_t   # 64 bit unsigned int


ctypedef   double             float64_t   # 64 bit Float
ctypedef   unsigned char        uint8_t   #  8 bit unsigned int
ctypedef   unsigned short      uint16_t   # 16 bit unsigned int
ctypedef   unsigned long       uint32_t   # 32 bit unsigned int
ctypedef   unsigned long long  uint64_t   # 64 bit unsigned int
#-----------------------------------------------------------------------------------------------------






#-----------------------------------------------------------------------------------------------------
#-------------------------------------   INITIALIZATION ONLY   ---------------------------------------
#-----------------------------------------------------------------------------------------------------

PATH_TO_FILES = whereotilib.getpath() # "/.../.../spr_otilibvX.Y/"


# Define an array to check number types.
# Change to a function that checks all items.
number_types = (int,   np.int8,      np.int16,  np.int32,  np.int64,\
              float,   np.float16, np.float32, np.float64)

cdef partsets psets = partsets()   # Class to handle efficiently precomputed partition sets


# Load in h all the different index combinations and 

H=[]
H.append(h_indx_1())

for i in range(1,10):
  
  H.append(h_indx(i+1))


# cdef h_indx_new h = h_indx_new() # Does not work...
h = h_indx_new()

cdef float64_t[::1] FACTORIALS = np.array([1.,1.,2.,6.,24,120.,720.,5040.,40320.,362880.],dtype = np.float64)

cdef uint64_t ZERO = 0
cdef uint64_t  ONE = 1


#-----------------------------------------------------------------------------------------------------







#-----------------------------------------------------------------------------------------------------
#-----------------------------------   IMPORT EXTERNAL C FUNCTIONS   ---------------------------------
#-----------------------------------------------------------------------------------------------------
cdef extern from "c_auxfunc.c" :

  #***************************************************************************************************
  uint64_t c_convToIndex(uint16_t* ptr_dirA,uint8_t* ptr_expA, uint8_t order) 
  # """
  # c_convToIndex( ptr_dirA, ptr_expA, order):

  # Function that converts a set of exponents and directions to a corresponding 
  # integer value.

  # INPUTS:
  #     -> ptr_dirA: Array of values that represent the directions of a number
  #         Example: [3,4]

  #     -> ptr_expA: Array of values that represent the exponents of those directions
  #         Example: [1,2]

  #     -> order:    Order of the OTI number that is being used.
  #         Example: 3 


  # OUTPUTS:
  #     -> The result is an uint64_t with the following formula

  #             \sum{expA[i]*(order+1)^(dirA[i]-1)}

  #         Example: 144 = c_convToIndex([3,4],[1,2], 3)

  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  void c_mapDirArray( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,\
                      uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2, uint16_t* ptr_mapder)
  # """
  # c_mapDirArray( ptr_dirA1 , ptr_dirA2,       order,
  #                ptr_mdirA2, ptr_mdirA2, ptr_mapder):

  # Function that maps two direction arrays to a consecutive ordered 
  # direction arrays starting from 1.

  # INPUTS:
  #     -> ptr_dirA1 (order): Array of values that represent the directions of a number
  #         Example: [ 3, 8, 0, 0]

  #     -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
  #         Example: [ 7,10, 0, 0]

  #     -> order:    Order of the OTI number that is being used.
  #         Example: 4 


  # OUTPUTS:
  #     -> The result are 3 arrays:

  #         -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
  #         dirA1.
  #         Example: [1, 3, 0, 0]

  #         -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
  #         Example: [2, 4, 0, 0]

  #         -> ptr_mapder (2 * order): Array of the corresponding (real) directions that correlates the mapped
  #         directions
  #         Example: [3,7,8,10,0,0,0,0]
  
  # Note: All arrays must come already allocated.

  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  void c_mapDirArrayNoMapder( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,\
                      uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2)
  # """
  # c_mapDirArray( ptr_dirA1 , ptr_dirA2,       order,
  #                ptr_mdirA2, ptr_mdirA2):

  # Function that maps two direction arrays to a consecutive ordered 
  # direction arrays starting from 1.

  # INPUTS:
  #     -> ptr_dirA1 (order): Array of values that represent the directions of a number
  #         Example: [ 3, 8, 0, 0]

  #     -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
  #         Example: [ 7,10, 0, 0]

  #     -> order:    Order of the OTI number that is being used.
  #         Example: 4 


  # OUTPUTS:
  #     -> The result are 3 arrays:

  #         -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
  #         dirA1.
  #         Example: [1, 3, 0, 0]

  #         -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
  #         Example: [2, 4, 0, 0]


  
  # Note: All arrays must come already allocated.

  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  uint64_t c_binarySearch(  uint16_t* ptr_dirArray, uint8_t* ptr_expArray,\
                          uint16_t* ptr_dirA,     uint8_t* ptr_expA,     uint8_t order,\
                          uint64_t  N, uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2)
  # """
  # c_binarySearch( c_binarySearch(  ptr_dirArray, ptr_expArray,
  #                                    ptr_dirA,     ptr_expA,      order,
  #                                    N,            ptr_mdirA1,    ptr_mdirA2):

  # Function applies the binary search to find what is the position at which the 
  # pair dirs,exps exist on an array of size N that contains it.

  # INPUTS:
      
  #     -> ptr_dirArray[N,order]:   Array of all possible combinations of directions 
  #                                 for m number of base directions.
  #         Example: [1,0,   
  #                   1,0,
  #                   2,0,
  #                   1,2,
  #                   2,0,
  #                   3,0,   // for m=3
  #                   1,3,
  #                   2,3,
  #                   3,0]

  #     -> ptr_expArray[N,order]:   Array of all possible combinations of exponents, 
  #                                 associated to those directions.
  #         Example: [1,0,
  #                   2,0,   
  #                   1,0,
  #                   1,1,   // the sum of each row should always be \leq order.
  #                   2,0,
  #                   1,0,
  #                   1,1,
  #                   1,1,
  #                   2,0]


  #     -> ptr_dirA:    Array of values that represent the directions of a number
  #         Example: [3,0]

  #     -> ptr_expA:    Array of values that represent the exponents of those directions
  #         Example: [1,0]

  #     -> order:       Order of the OTI number that is being used.
  #         Example: 2 (as in the example) 

  #     -> N:           number of columns of the dirArray and expArray.
  #         Example: 9 

  #     -> ptr_mdirA1,ptr_mdirA2: Allocated arrays to handle the algorithm.


  # OUTPUTS:
  #     -> The result is the index that indicates where the combination dirA,expA occurs:

  #         Example: For the values shown as examples in inputs,

  #             >> 5 = c_binarySearch(...)

  # NOTE: All arrays must come allocated.
  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  void c_convToDirExp(uint64_t index, uint8_t order, uint16_t* ptr_dirA, uint8_t* ptr_expA)
  # """
  # c_convToDirExp( ptr_dirA, ptr_expA, order):

  # Function that converts a set of exponents and directions to a corresponding 
  # integer value.

  # INPUTS:
  #     -> index:    Integer form of the sets of directions and exponents.
  #         Example: 24

  #     -> order:    Order of the OTI number that is being used.
  #         Example: 3 

  #     -> ptr_expA: Array of values that represent the exponents of those directions
  #         Example: [1,2]


  # OUTPUTS:
  #     -> The result is an uint64_t with the following formula

  #             \sum{expA[i]*(order+1)^(dirA[i]-1)}

  #         Example: 144 = c_convToIndex([3,4],[1,2], 3)
  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  void c_test(uint16_t * pointer,uint8_t size)
  # """
  #   c_test( ... )

  #   Dummy function to do tests with functions programmed in c.
  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  void c_reMapDirArray( uint16_t*  ptr_mdirA1, uint16_t* ptr_mapder, uint8_t order,\
                      uint16_t* ptr_dirA1) 
  # """
  # c_reMapDirArray( ptr_mdirA1 , ptr_mdirA2, ptr_mapder,
  #                  ptr_dir1, ptr_dirA2 ):

  # Function that maps two direction arrays to a consecutive-ordered 
  # direction arrays starting from 1.

  # INPUTS:
  #     -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
  #         dirA1.
  #         Example: [1, 3, 0, 0]

  #         -> ptr_mdirA2 (order): Array of values with the corresponding mapped directions of array 
  #         dirA2.
  #         Example: [2, 4, 0, 0]

  #     -> ptr_mapder (2 * order): Array of the corresponding (real) directions that correlates the mapped
  #         directions
  #         Example: [3,7,8,10,0,0,0,0]

  #     -> order:    Order of the OTI number that is being used.
  #         Example: 4 



  # OUTPUTS:
  #     -> The result are 3 arrays:

  #         -> ptr_dirA1 (order): Array of values that represent the directions of a number
  #         Example: [ 3, 8, 0, 0]

  #         -> ptr_dirA2 (order): Array of values that represent the directions of a number
  #         Example: [ 7,10, 0, 0]

          
  
  # Note: All arrays must come already allocated.

  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************  
  uint64_t c_multDirections(uint16_t* ptr_dirArray, uint8_t* ptr_expArray, \
                        uint16_t* ptr_dirA1,  uint8_t* ptr_expA1,   \
                        uint16_t* ptr_dirA2,  uint8_t* ptr_expA2,   \
                        uint16_t* ptr_mdirA1, uint8_t* ptr_mexpA1,  \
                        uint16_t* ptr_mdirA2, uint16_t* ptr_mdirA3, \
                        uint16_t* ptr_mapder, \
                        uint8_t order, uint64_t N, uint8_t* error )
  # """
  # c_multDirections(ptr_dirA1, ptr_expA2, ptr_dirA1, ptr_expA2, order):
  
  # Function that multiplies two directions i,j.

  # INPUTS:

  #     -> ptr_dirArray[N,order]:   Array of all possible combinations of directions 
  #                                 for m number of base directions.
  #         Example: [1,0,   
  #                   1,0,
  #                   2,0,
  #                   1,2,
  #                   2,0,
  #                   3,0,   // for m=3
  #                   1,3,
  #                   2,3,
  #                   3,0]

  #     -> ptr_expArray[N,order]:   Array of all possible combinations of exponents, 
  #                                 associated to those directions.
  #         Example: [1,0,
  #                   2,0,   
  #                   1,0,
  #                   1,1,   // the sum of each row should always be \leq order.
  #                   2,0,
  #                   1,0,
  #                   1,1,
  #                   1,1,
  #                   2,0]


  #     ->  ptr_dirA<1,2>: Array of values that represent the directions of a number
  #         Example: ptr_dirA1 [3,0] , ptr_dirA2 [2,0] 

  #     ->  ptr_expA<1,2>: Array of values that represent the exponents of those directions
  #         Example: ptr_expA1 [1,0] , ptr_expA2 [1,0]

  #     ->  order:    Order of the OTI number that is being used.
  #         Example: 2

  #     -> ptr_mdirA<1,2,3>: Allocated arrays to handle the algorithm.

  #     -> ptr_mexpA1: Allocated array to handle the exponent of the algorithm.

  #     -> N:         Number of rows of the dirArray and expArray.
  #         Example: 9 
  #     -> error: Indicator to show if the result is valid or not.


  # OUTPUTS:
  #     ->  The result is an uint64_t which corresponds to the index of the 
  #         multiplied indices.

  #         Example: 7 = c_multDirections(...)

  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  uint64_t c_binarySearchUI64(  uint64_t* ptr_indxArray, uint64_t indx,uint64_t  N)
  # """
  # c_binarySearchUI64( ptr_indxArray, indx, N):

  # Function that applies binary search to find what is the position at which the 
  # indx belongs in indxArray. However, if indx does not belong to indxArray, it will tell 
  # at which position it must be inserted.

  # INPUTS:
      
  #     -> ptr_indxArray[N]:   Array with indices, in ascending order. 
  #         Example: [1,  
  #                   4,
  #                   5,
  #                   6,
  #                   9,
  #                   20,
  #                   25,
  #                   45,
  #                   50]

  #     -> indx:    Value to seek in indxArray 
  #         Example: 5

  #     -> N:       Number of elements in indxArray
  #         Example: 9

  # OUTPUTS:
  #     -> The result is the index that indicates where the indx value exist in indxArray,
  #     or where should it be inserted
  #         Example: 2 = c_binarySearchUI64( ptr_indxArray, indx, N)
  # """
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  uint8_t c_sumUI8(uint8_t* ptr_,uint8_t n)
  # """
  #   c_sumUI8( ptr_, size):

  #   Function that sums all elements of array of unsigned integers of 8 bits of size n.

  # """
  #--------------------------------------------------------------------------------------------------- 

  void c_mapPartition(uint16_t part,  uint16_t*  ptr_dir,  uint8_t  order, \
                    uint16_t*  ptr_map) 

  

  void c_orderDirExpArray(uint16_t* dirA,    uint8_t*    multExpA ,uint8_t pos,\
             uint16_t* newDirA, uint8_t* newExpA, uint8_t order)


#-----------------------------------------------------------------------------------------------------


















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM   :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef public uint8_t maxorder          # Stores the maximum order of the number.
  cdef public uint64_t size             # Number of elements in coefs...
  cdef public float64_t[::1] coefs      # Array of coefficients of the OTI number.
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self,float64_t[::1] coefs,uint8_t order,exact = False):
    """
    PURPOSE:      Constructor of the otinum class.

    DESCRIPTION:  Creates a new OTI number given a list of coefficients.

    PARAMETERS:
                 
                  coefs:  List of coefficients. 
                  
                  order:  Integer that sets the maximum order of the number.
                  
                      Example:  coefs = [1, 2, 3],
                                order = 2
                                
                      creates an OTI number:
                      1.0 + 2.0 * e([1]) + 3.0 * e([[1,2]])     

    RESULT:       
            The next attributes are allocated:
                  
                  obj.coefs:    a numpy 1D array that contains the
                                coefficients corresponding to the OTI.
                                
                  obj.maxorder: an integer that indicates the order of the 
                                system.
                  
    """
    #*************************************************************************************************

    cdef uint64_t sizeOfCoefs, m_max, newSizeOfCoefs

    #Add warning for higher orders and orders that are not required
    if type(coefs) in number_types:
      
      # create a list to handle the index numbers 
      m_max = 0
      newSizeOfCoefs = h.getNels(m_max,order)

      self.coefs = np.zeros(newSizeOfCoefs,dtype = np.float64)
      
      #self.coefs[0] = coefs
      
      self.maxorder = order
    
    else:

      if  not exact:
      
        sizeOfCoefs = coefs.size
        m_max = h.findMaxDir(sizeOfCoefs-1,order)
        newSizeOfCoefs = h.getNels(m_max,order)


        self.coefs = np.empty(newSizeOfCoefs,dtype = np.float64)



        for m_max in range(sizeOfCoefs):

          self.coefs[m_max] = coefs[m_max]


        # end for 

        for m_max in range(sizeOfCoefs,newSizeOfCoefs):

          self.coefs[m_max] = 0.0

        # end for
      
      else:

        self.coefs = coefs


      self.maxorder = order

      # TODO: Add warning and error if no enough coefficients are added 
      # to the coefs vector
      # 
      # Add also a code that enables the index array to be only a list with 
      # elements of type int (python integer, not numpy integer).
      #

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

    head      = 'otinum('
    body      = ''
    body+= (np.array2string(np.array(self.coefs),separator=",")).replace(" ","")
    tail = ', '+str(self.maxorder)+')'
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

    head      = ''
    body      = ''
    


    for i in range(0,self.coefs.size):
      
      dirArray = getDirArray(i,self.maxorder)
      
      coef = str('%+g' %self.coefs[i])
      
      e_dir = printOrderPos(dirArray)
      
      if i == 0 :
        
        sign = ''
       
        if coef[0]=='-':
          
          sign = coef[0] + ' '
          
        # end if

      else: 
        
        sign = coef[0] + ' '
        
      # end if
      
      body = body + sign + str(abs(self.coefs[i])) + e_dir + ' '
      
    # end for
    
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __getitem__(self, uint64_t index):
    """
    PURPOSE:  To get the value of an otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    cdef float64_t zero = 0.0

    if index < self.coefs.size:

      return self.coefs[index]

    else:

      return zero

    # end if

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, uint64_t index, float64_t value):
    """
    PURPOSE:  To set the value of an otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]+=10
              >>> a
              spr_otinum([0,4,17], [10.,2.,3.], 2)
              >>> a[4] = 7
              >>> a
              spr_otinum([0,4,17], [10.,7.,3.], 2)
              >>> a[2] = 5
              >>> a
              spr_otinum([0,2,4,17], [10.,5.,7.,3.], 2)
    """
    #*************************************************************************************************
    
    cdef float64_t[::1] tmp_coefs
    cdef uint64_t m_max,i

    if index < self.coefs.size:
    
      self.coefs[index] = value
    
    else:
    
      # change the size of coefs:
      sizeOfCoefs    = self.coefs.size
      m_max          = h.findMaxDir(index,self.maxorder)
      newSizeOfCoefs = h.getNels(m_max,self.maxorder)

      tmp_coefs = self.coefs
      self.coefs = np.empty(newSizeOfCoefs,dtype = np.float64)

      for i in range(sizeOfCoefs):

        self.coefs[i] = tmp_coefs[i]

      # end for 

      for i in range(sizeOfCoefs,newSizeOfCoefs):
        
        if i == index:
        
          self.coefs[i] = value
        
        else:
        
          self.coefs[i] = 0.0
        
        # end if

      # end for

    # end if

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      To define how to turn a spr_otinum into its opposite
                  (negative)

    DESCRIPTION:  It overloads the operator "-".
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [10.,7.,3.], 2)
                  >>> -a
                  spr_otinum([0,4,17], [-10.,-7.,-3.], 2)
    """
    #*************************************************************************************************
    cdef uint64_t i
    cdef float64_t[::1] coefs = self.coefs.copy()
    
    for i in range(self.coefs.size):
    
      coefs[i] = -coefs[i]

    # end for

    return otinum(coefs,self.maxorder, exact = True)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      To define how to sum two spr_otinum numbers.

    DESCRIPTION:  It overloads the sum operator "+". It allows the addition
                  of spr_otinum numbers of different orders, or even the 
                  addition of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a + b
                  spr_otinum([0,2,4,17], [8.,9.,14.,5.], 2)
                  
                  >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a + 15
                  spr_otinum([0,4,17], [16.,3.,5.], 2)
    """
    #*************************************************************************************************
    
    cdef uint64_t i = 0

    if ( type(other_in) in number_types) : # Case 1. Sum to real number.
      
      S = self.copy()
      S[i] += other_in
      

    elif ( type(self) in number_types): # Case 1.5. reverse Sum to real number.
      
      S = other_in.copy()
      S[i] += self

    elif type(other_in) is otinum: # Case 2. Sum to spr_otinum.
      
      S = self.copy()
      O = other_in

      if S.maxorder != O.maxorder:
        
        # Preserve the maximum order.
        if S.maxorder>O.maxorder:

          O = O.copy()         
          O.changeOrder(S.maxorder)

        else:

          S.changeOrder(O.maxorder)

        # end if

      # end if

      if S.coefs.size != O.coefs.size:

        if S.coefs.size > O.coefs.size:

          for i in range(O.coefs.size):
          
            S.coefs[i] = S.coefs[i] + O.coefs[i]

          # end for

        else:

          O = O.copy()

          for i in range(S.coefs.size):
        
            O.coefs[i] = O.coefs[i] + S.coefs[i]

          # end for

          return O

        # end if

      else:

        for i in range(S.coefs.size):
        
          S.coefs[i] = S.coefs[i] + O.coefs[i]

        # end for

    # TODO: Add support for interfacing with spr_otinum

    # end if. Type cases.
    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(self, other_in):
    """
    PURPOSE:      To define how to sum two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace sum operator "+=". It allows the 
                  addition of spr_otinum numbers of different orders, and 
                  the addition of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a += b
                  >>> a 
                  spr_otinum([0,2,4,17], [8.,9.,14.,5.], 2)
                  >>> b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************
    
    cdef uint64_t i = 0

    if ( type(other_in) in number_types) : # Case 1. Sum to real number.
      
      S = self
      S[i] += other_in
      

    elif ( type(self) in number_types): # Case 1.5. reverse Sum to real number.
      
      S = other_in
      S[i] += self
      return S

    elif type(other_in) is otinum: # Case 2. Sum to spr_otinum.
      
      S = self
      O = other_in

      if S.maxorder != O.maxorder:
        
        # Preserve the maximum order.
        if S.maxorder>O.maxorder:

          O = O.copy()         
          O.changeOrder(S.maxorder)

        else:

          S.changeOrder(O.maxorder)

        # end if

      # end if

      if S.coefs.size != O.coefs.size:

        if S.coefs.size > O.coefs.size:

          for i in range(O.coefs.size):
          
            S.coefs[i] = S.coefs[i] + O.coefs[i]

          # end for

        else:
        
          O = O.copy()

          for i in range(S.coefs.size):
        
            O.coefs[i] = O.coefs[i] + S.coefs[i]

          # end for

          return O

        # end if

      else:

        for i in range(S.coefs.size):
        
          S.coefs[i] = S.coefs[i] + O.coefs[i]

        # end for

    # TODO: Add support for interfacing with spr_otinum

    # end if. Type cases.

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the subtract operator "-". It allows the 
                  subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a - b
                  spr_otinum([0,2,4,17], [-6.,-9.,-8.,5.], 2)
                  
                  >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a - 15
                  spr_otinum([0,4,17], [-14.,3.,5.], 2)
    """
  #************************************************************************
    
    cdef uint64_t i = 0

    if ( type(other_in) in number_types) : # Case 1. Sum to real number.
      
      S = self.copy()
      S[i] -= other_in
      

    elif ( type(self) in number_types): # Case 1.5. reverse Sum to real number.
      
      S = other_in.copy()
      S[i] -= self

    elif type(other_in) is otinum: # Case 2. Sum to spr_otinum.
      
      S = self.copy()
      O = other_in

      if S.maxorder != O.maxorder:
        
        # Preserve the maximum order.
        if S.maxorder>O.maxorder:

          O = O.copy()         
          O.changeOrder(S.maxorder)

        else:

          S.changeOrder(O.maxorder)

        # end if

      # end if

      if S.coefs.size != O.coefs.size:

        if S.coefs.size > O.coefs.size:

          for i in range(O.coefs.size):
          
            S.coefs[i] = S.coefs[i] - O.coefs[i]

          # end for

        else:

          O = O.copy()

          for i in range(S.coefs.size):
        
            O.coefs[i] = O.coefs[i] - S.coefs[i]

          # end for

          return O

        # end if

      else:

        for i in range(S.coefs.size):
        
          S.coefs[i] = S.coefs[i] - O.coefs[i]

        # end for

    # TODO: Add support for interfacing with spr_otinum

    # end if. Type cases.
    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace subtract operator "-=". It allows
                  the subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a -= b
                  >>> a
                  spr_otinum([0,2,4,17], [-6.,-9.,-8.,5.], 2)
                  >>>b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************
  
    cdef uint64_t i = 0

    if ( type(other_in) in number_types) : # Case 1. Sum to real number.
      
      S = self
      S[i] -= other_in
      

    elif ( type(self) in number_types): # Case 1.5. reverse Sum to real number.
      
      S = other_in
      S[i] -= self
      return S

    elif type(other_in) is otinum: # Case 2. Sum to spr_otinum.
      
      S = self
      O = other_in

      if S.maxorder != O.maxorder:
        
        # Preserve the maximum order.
        if S.maxorder>O.maxorder:

          O = O.copy()         
          O.changeOrder(S.maxorder)

        else:

          S.changeOrder(O.maxorder)

        # end if

      # end if

      if S.coefs.size != O.coefs.size:

        if S.coefs.size > O.coefs.size:

          for i in range(O.coefs.size):
          
            S.coefs[i] = S.coefs[i] - O.coefs[i]

          # end for

        else:
        
          O = O.copy()

          for i in range(S.coefs.size):
        
            O.coefs[i] = O.coefs[i] - S.coefs[i]

          # end for

          return O

        # end if

      else:

        for i in range(S.coefs.size):
        
          S.coefs[i] = S.coefs[i] - O.coefs[i]

        # end for

    # TODO: Add support for interfacing with spr_otinum

    # end if. Type cases.

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other_in):
    """
    PURPOSE:      To define how to multiply two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*". It allows
                  the multiplication of OTI numbers of different 
                  orders, no matter how they are sorted, or even the 
                  multiplication of an OTI number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a * b
                  spr_otinum([0,2,4,8,17], [7.,9.,32.,33.,35.], 2)
    """
    #*************************************************************************************************
    
    cdef uint64_t i
    cdef uint64_t j
    cdef uint64_t resIndx
    cdef uint8_t sizeOfCoefs
    cdef float64_t[::1] newCoefs
    cdef uint8_t[:] error
    cdef otinum S,O

    if type(other_in) in number_types:   # Case 1. Mult to real scalar.
      
      S = self.copy()
      
      for i in range(S.coefs.size):
        
        S.coefs[i] = S.coefs[i] * other_in

      # end for
    
    if type(self) in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      S = other_in.copy()
      
      for i in range(S.coefs.size):
        
        S.coefs[i] = S.coefs[i] * self

      # end for

    elif type(other_in) is otinum:   # Case 2. Mult to spr_otinum.
      

      S = self.copy()
      O = other_in.copy()
      error = np.array([0],dtype=np.uint8)


      if S.maxorder != O.maxorder:
        
        # Preserve the minimum order.
        if S.maxorder<O.maxorder:
          
          O.changeOrder(S.maxorder)

        else:

          S.changeOrder(O.maxorder)

        # end if

      # end if

      if S.coefs.size>O.coefs.size:

        sizeOfCoefs = S.coefs.size

      else:

        sizeOfCoefs = O.coefs.size
      
      # end if

      newCoefs = np.zeros(sizeOfCoefs,dtype = np.float64)

      for i in range(S.coefs.size):

        for j in range(O.coefs.size):

          # multiply coefficients
          resIndx = h.multIndx(i,j,S.maxorder,error)

          if error[0] == 0:

            newCoefs[resIndx] = newCoefs[resIndx] + S.coefs[i]*O.coefs[j] 

          # end if

        # end for

      # end for

      S.coefs = newCoefs
      
    # End if. Type cases.
    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE:      To define how to make an inplace multiplication between
                  two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*=". It allows
                  the multiplication of OTI numbers of different orders, 
                  or even the multiplication with scalars.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a *= b
                  >>> a
                  spr_otinum([0,2,4,8,17], [7.,9.,32.,33.,35.], 2)
                  >>> b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************

    
    self = self * other_in

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE:      To define how to divide two spr_otinum numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 

    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a/b
                  spr_otinum([0,2,4,8,17], [0.14285714,-0.18367347,
                                    0.20408163,-0.32069971,0.71428571], 2)
    """
    #*************************************************************************************************
    
    cdef float64_t factor
    cdef uint64_t i
    cdef float64_t[::1] coefs
    if type(other) in number_types:    # Case 1. real number.
      
      
      S = self.copy()
      
      factor = (1./other)
      
      for i in range(S.coefs.size):
        
        S.coefs[i] *= factor

      # end for 

    elif type(self) in number_types:    # Case 1.5 reverse real number. 

      # print("!!!!! THIS IS THE CASE !!!!!")

      # S = other.copy()
      coefs = np.zeros(other.coefs.size,dtype = np.float64)
      coefs[0] = self
      return otinum(coefs,other.maxorder,exact = True)/other
      # return spr_otinum(np.array([0],dtype = np.uint64),np.array([self],dtype = np.float64),other.maxorder)/other
      
    elif type(other) is otinum:   # Case 2. spr_otinum.
      
      
      
      S = self * power(other,-1)
      # S *= power(other,-1)
      
    # End if. Type cases.

    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      To provide power function.
  
    DESCRIPTION:  It defines how to make a mcxnumber to the power of n.
  
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a**3
                  spr_otinum([0,4,8,17], [1.,9.,27.,15.], 2)
    """
    #*************************************************************************************************
    
    
    P = power(self,n)

    
    return P

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE:      To create a copy of a spr_otinum object, totally 
                  independent of the original.

    DESCRIPTION:  The equality operator "=" is intended to create aliases
                  of multicomplex numbers. You should use copy() when you
                  need a copy instead of an alias.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,7.,3.], 2)
                  >>> b = a.copy()
                  >>> b[1] = 10
                  >>> a
                  spr_otinum([0,4,17], [1.,7.,3.], 2)
                  >>> b
                  spr_otinum([0,1,4,17], [1.,10.,7.,3.], 2)
    """
    #*************************************************************************************************

      
    return otinum(self.coefs.copy(),self.maxorder, exact = True)
  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  cpdef void changeOrder(self,uint8_t neworder):
    """
    PURPOSE:      To change the order of a spr_otinum.
  
    DESCRIPTION:  According to the new order, the index values are changed. 

    """
    #*************************************************************************************************
    
    cdef uint16_t[::1] oldDirA = np.empty(self.maxorder,dtype = np.uint16) 
    cdef uint16_t[::1] newDirA = np.empty(neworder,dtype = np.uint16) 
    cdef uint8_t[::1]  oldExpA = np.empty(self.maxorder,dtype = np.uint8) 
    cdef uint8_t[::1]  newExpA = np.empty(neworder,dtype = np.uint8)
    cdef float64_t[::1] newCoefs
    cdef uint64_t newIndx
    cdef uint64_t m_max, newSizeOfCoefs
    cdef uint64_t i
    cdef uint8_t j
    
    if neworder != self.maxorder:

      
      m_max = h.findMaxDir(self.coefs.size-1,self.maxorder)
      
      

      newSizeOfCoefs = h.getNels(m_max,neworder)
      
      
      # Case for a new order greater than previous order.
      if neworder > self.maxorder:
        
        newCoefs = np.zeros(newSizeOfCoefs,dtype = np.float64)
        

        # iterate over the previous coefs

        for i in range(self.coefs.size):

          # Get old arrays ...
          oldDirA = h.getDirA(i,self.maxorder)
          oldExpA = h.getExpA(i,self.maxorder)

          for j in range(self.maxorder):
            newDirA[j] = oldDirA[j] 
            newExpA[j] = oldExpA[j]
          # end for 

          for j in range(self.maxorder, neworder):
            newDirA[j] = 0
            newExpA[j] = 0
          # end for 

          # find new indx.
          newIndx = h.findIndx(newDirA,newExpA,neworder)

          newCoefs[newIndx] = self.coefs[i]

        # end for

        self.coefs = newCoefs
        self.maxorder = neworder

      elif neworder < self.maxorder:

        newCoefs = np.empty(newSizeOfCoefs,dtype = np.float64)


        # iterate over the previous coefs

        for i in range(newSizeOfCoefs):

          # Get new arrays ...
          newDirA = h.getDirA(i,neworder)
          newExpA = h.getExpA(i,neworder)

          for j in range(neworder):
            oldDirA[j] = newDirA[j] 
            oldExpA[j] = newExpA[j]
          # end for 

          for j in range(neworder,self.maxorder):
            oldDirA[j] = 0
            oldExpA[j] = 0
          # end for 

          # find new indx.
          newIndx = h.findIndx(oldDirA,oldExpA,self.maxorder)

          newCoefs[i] = self.coefs[newIndx]

        # end for

        self.coefs = newCoefs
        self.maxorder = neworder

      # end if 

    # end if 


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDual(self, dirArray):
    """
    PURPOSE:      To add a human friendly form to get elements from a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.getDual([1,3])
                  5.0
                  >>> a.getDual([1])
                  0.0
    """
    #*************************************************************************************************

    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
    
    tmp_dirA, tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:
      
      return np.float64(0.0)  
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = h.findIndx(dirA,expA,self.maxorder)

    # end if
    
    return self[indx]

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def setDual(self, dirArray, value):
    """
    PURPOSE:      To add a human friendly form to set elements of a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.setDual([1,3],10)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
                  >>> a.setDual([1],2.5)
                  >>> print(a)
                  1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
    """
    #*************************************************************************************************
  
    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:
      return 0.
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = h.findIndx(dirA,expA,self.maxorder)

    # end if

    self[indx] = value

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************
    
    
    cdef uint8_t   order  = np.sum(expA)
    
    # If asking for a coefficient of higher order, return 0.0
    if order > self.maxorder:
    
      return np.float64(0.0)  

    # end if 
    
    cdef float64_t factor = 1.0
    cdef uint16_t[::1] tmp_dirA = np.zeros(self.maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  tmp_expA = np.zeros(self.maxorder,dtype = np.uint8)
    cdef uint8_t i
    cdef uint64_t indx
    cdef float64_t value = 0.0

    
    # Compute the multiplication factor and fill in the temporary arrays.

    for i in range(dirA.size):
      
      factor *= factorial(expA[i])
      tmp_dirA[i] = dirA[i]
      tmp_expA[i] = expA[i]
    
    # end for
    
    indx  = h.findIndx(tmp_dirA,tmp_expA,self.maxorder)
    value = self[indx]*factor
    
    return value
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDeriv(self, dirArray):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************

    if type(dirArray)==int:
      
      indxArray = [dirArray]
      
    else:
      
      indxArray = dirArray
      
    # end if

    
    tmp_dirA,tmp_expA = getDirExpA(dirArray)
    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i

    # create the real direction arrays:
    cdef uint16_t[::1] dirA = np.zeros(maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  expA = np.zeros(maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 


    return self.getDerivByDirExp(dirA,expA)

  #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def toVector(self):
  #   """
  #   PURPOSE:      To convert a spr_otinum into its vector form.
                  
  #   DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.

                    
  #   """
  #   #*************************************************************************************************

  #   return self.expand(ismat =0)

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def toMatrix(self,ismat = 1,m = -1,isspr = 0):
  #   """
  #   PURPOSE:      To convert a spr_otinum into its matrix form.
                  
  #   DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.
    
  #   INPUTS:
  #                 ismat: To define a matrix (1) or a vector (0)
  #                 isshape: To use the shape that will result of the number 
  #                   (-1) or an specific shape (given value).
  #                 isspr: To result in a sparse matrix (1) or not (0).
  #   """
  #   #*************************************************************************************************

  #   return self.expand(ismat = ismat, m = m, isspr = isspr)

  # #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def expand(self,ismat = 1,m = -1 , isspr = 0):
    """
    PURPOSE:      To convert a spr_otinum into its matrix form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation form.
                   
    INPUTS:
                  ismat: To define a matrix (1) or a vector (0)
                  m: To use the shape that will result of the number 
                    (-1) or an specific shape (given value).
                  isspr: To result in a sparse matrix (1) or not (0).
                    
    """
    #*************************************************************************************************
    
    cdef uint8_t[:] error = np.zeros([0],dtype = np.uint8)
    cdef uint64_t i
    cdef uint64_t k
    cdef uint64_t j
    cdef uint64_t finalshape

    if m == -1:
      # Deduce the matrix dimension by looking at the last indx and 
      # looking for the maximum base direction
      
      # Separate cases for order 1 and others.
      if self.maxorder == 1:
        
        m_max =  h.findMaxDir(self.coefs.size-1,self.maxorder)
      
      else: 
        
        # dirA = h.getDirA(self.indx[self.indx.size-1],self.maxorder)
        # m_max = np.max(dirA)
        m_max =  h.findMaxDir(self.coefs.size-1,self.maxorder)

      # end if 

    else:
      
      m_max = m
      
    # end if

    finalshape = findComb(m_max+1,self.maxorder)

    
    if ismat ==0:
      # vector type
      
      mat = np.zeros(finalshape)
      
      # Do only a certain amount of iterations:

      nIterMin = np.min([self.coefs.size,finalshape])
      k = 0

      for i in range(nIterMin):
        
        mat[i] = self.coefs[i]
        
        # end if

      # end for
      
    else:

      # matrix type
      
      if isspr == 0:
        #return the np.array?
        mat = np.array(__otinum2Mat_dense(self, finalshape))
        
      else:
        
        mat = __otinum2Mat_spr(self, finalshape)
        
        
      # end if
      

    # end if 
    
    
    return mat

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef assignAll(self, float64_t value):
    """
    PURPOSE:      Fast function to assign to all coefficients in self the given value.

    """
    #*************************************************************************************************
    cdef uint64_t i

    for i in range(self.coefs.size):

      self.coefs[i] = value

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef one(self):
    """
    PURPOSE:      Fast function to assign to all coefficients in self the given value.

    """
    #*************************************************************************************************
    cdef uint64_t i
    cdef float64_t value = 0.

    for i in range(self.coefs.size):
      
      if i == 0:
        
        self.coefs[i] = 1.0

      else:

        self.coefs[i] = value

      # end if

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def sum(self, *args):
    """
    PURPOSE:  Function to sum self with other otinum numbers without allocating memory between 
              processes. Input can be only one number or many otinum separated by commas.

              Notice that they need to have the same dimensions, otherwise it wont give accurate 
              results.

              example: Given otinum a,b,c,d:

                  >>> a.sum(b,c,d)       # Gives the same as doing:

                  >>> a = a + b + c + d  # but in a faster way. 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, nels = self.coefs.size
    cdef otinum other_in     # holder to increase access speed

    for i in range(len(args)):

      other_in = args[i] # Get input by input

      for j in range(nels):

        self.coefs[j] += other_in.coefs[j]

      # end for 

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def sub(self, *args):
    """
    PURPOSE:  Function to substract self with other otinum numbers without allocating memory between 
              processes. Input can be only one number or many otinum separated by commas.

              Notice that they need to have the same dimensions, otherwise it wont give accurate 
              results.

              example: Given otinum a,b,c,d:

                  >>> a.sum(b,c,d)       # Gives the same as doing:

                  >>> a = a - b - c - d  # but in a faster way. 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, nels = self.coefs.size
    cdef otinum other_in     # holder to increase access speed

    for i in range(len(args)):

      other_in = args[i] # Get input by input

      for j in range(nels):

        self.coefs[j] -= other_in.coefs[j]

      # end for 

    # end for   

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def inv(self):
    """
    PURPOSE:  Function to divide 1.0/self with another otinum number without allocating memory between 
              processes.

              example: Given otinum a,b,c,d:

                  >>> a.inv()          # Gives the same as doing:

                  >>> a = 1.0 / a      # but in a faster way. 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, nels = self.coefs.size
    cdef otinum other_in     # holder to increase access speed
    cdef float64_t val1, val2
    
    if self.maxorder == 1:

      val1 = 1/self.coefs[ZERO]
      val2 = -1./(self.coefs[ZERO])
      
      for i in range(self.coefs.size):

        if i == 0:
        
          self.coefs[i] = val1
        
        else:
        
          self.coefs[i] = val2*self.coefs[i]
        
        # end if

      # end for

    else:

      self = 1.0/self

    # end if  

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def mult(self, *args,float64_t[:] prealloc = None):
    """
    PURPOSE:  Function to multiply self with other otinum numbers without allocating memory between 
              processes. Input can be only one number or many otinums separated by commas.

              Notice that they need to have the same dimensions, otherwise it wont do a correct 
              operation.

              example: Given the otinum objects:  a, b, c and d:

                  >>> a.mult(b)          # Gives the same as doing:

                  >>> a = a * b          # but in a faster way. 

                  >>> a.mult(b,c,d)      # Gives the same as doing:

                  >>> a = a + b + c + d  # but in a faster way. 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, k, nels = self.coefs.size
    cdef otinum other_in           # holder to increase access speed
    cdef float64_t zerof = 0.
    cdef uint8_t[:] error = np.array([0],dtype=np.uint8)

    if prealloc == None:           # Check if the given prealloc value is allocated.
    
      prealloc = np.empty(nels,dtype = np.float64)

    # end if 
    
    for k in range(len(args)):

      O = args[k]  # Get one by one the given elements.

      # initialize prealloc:
      for i in range(nels):

        prealloc[i] = zerof

      # end for 

      for i in range(nels):

        for j in range(nels):

          # multiply coefficients
          resIndx = h.multIndx(i,j,self.maxorder,error)

          if error[0] == 0:     # when error[0] is 1 the multiplication gives a non admissible dir.

            prealloc[resIndx] = prealloc[resIndx] + self.coefs[i]*O.coefs[j] 

          # end if

        # end for

      # end for

      for i in range(nels):
      
        self.coefs[i] = prealloc[i]

      # end for 

    # end for 

  #--------------------------------------------------------------------------------------------------- 

  # #***************************************************************************************************
  # def mult2(self, *args,float64_t[:] prealloc = None):
  #   """
  #   PURPOSE:  Function to multiply self with other otinum numbers without allocating memory between 
  #             processes. Input can be only one number or many otinums separated by commas.

  #             Notice that they need to have the same dimensions, otherwise it wont do a correct 
  #             operation.

  #             example: Given the otinum objects:  a, b, c and d:

  #                 >>> a.mult(b)          # Gives the same as doing:

  #                 >>> a = a * b          # but in a faster way. 

  #                 >>> a.mult(b,c,d)      # Gives the same as doing:

  #                 >>> a = a + b + c + d  # but in a faster way. 
  #   """
  #   #*************************************************************************************************
    
  #   cdef uint64_t i, j, k, nels = self.coefs.size
  #   cdef otinum other_in           # holder to increase access speed
  #   cdef float64_t zerof = 0.
  #   cdef uint8_t[:] error = np.array([0],dtype=np.uint8) # avoid mallocs.....


  #   if prealloc == None:           # Check if the given prealloc value is allocated.
    
  #     prealloc = np.empty(nels,dtype = np.float64)

  #   # end if 
    
    
  #   compMultiplesPre(uint8_t[::1] expArray, uint8_t[:,::1] multiples, \
  #                                     uint8_t[::1] multiple, uint64_t[:] maxiter)


  #   for k in range(len(args)):

  #     O = args[k]  # Get one by one the given elements.

  #     # initialize prealloc:
  #     for i in range(nels):

  #       prealloc[i] = zerof

  #     # end for 

  #     for i in range(nels):

  #       # Get direction and exponent arrays:
  #       expArray = h.getExpA(i,A.maxorder)
  #       dirArray = h.getDirA(i,A.maxorder)

  #       # get the multiples of the exponent array:
  #       multiples = compMultiples(expArray)

  #       # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
        
  #       # loop in all multiples
  #       for j in range(multiples.shape[0]-1):

  #         # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
  #         pos = multiples.shape[0]-j-1

  #         c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , pos,\
  #                     &dirA[0], &expA[0], A.maxorder)

  #         # Get the mirrored multiple for vector X
  #         c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , j, \
  #                     &dirX[0], &expX[0], A.maxorder)
          
  #         # Get the equivalent index for A.
  #         indxA = h.findIndx(dirA, expA, A.maxorder)

  #         if dirX[0] == 0:

  #           indxX = 0

  #         else:

  #           # Get the equivalent index for X.
  #           indxX = h.findIndx(dirX, expX, A.maxorder)

  #         # end if 

  #         # Subtract A_indxA * x_indxX to the fi vector
  #         fi -= A[indxA].dot(x.data[:,indxX])


  #         # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
  #         # string += 'x'+ str(getDirArray(indxX,A.maxorder))

          
  #       # end for

  #       # TODO: Change according to all different solvers selected.

  #       x.data[:,i]  = A0.solve(fi.base)   # Solve factorized system


  #     # end for




























  #   for k in range(len(args)):

  #     O = args[k]  # Get one by one the given elements.

  #     # initialize prealloc:
  #     for i in range(nels):

  #       prealloc[i] = zerof

  #     # end for 

  #     for i in range(nels):

  #       for j in range(nels):

  #         # multiply coefficients
  #         resIndx = h.multIndx(i,j,self.maxorder,error)

  #         if error[0] == 0:     # when error[0] is 1 the multiplication gives a non admissible dir.

  #           prealloc[resIndx] = prealloc[resIndx] + self.coefs[i]*O.coefs[j] 

  #         # end if

  #       # end for

  #     # end for

  #     for i in range(nels):
      
  #       self.coefs[i] = prealloc[i]

  #     # end for 

  #   # end for 

  # #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  cpdef null(self):
    """
    PURPOSE:      Fast function to assign to all coefficients 0 .

    """
    #*************************************************************************************************
    
    cdef float64_t value = 0.0
    
    self.assignAll(value)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef assign(self, float64_t[:] values):
    """
    PURPOSE:      Fast function to assign all coefficients from an array object.

    """
    #*************************************************************************************************
    cdef uint64_t i

    for i in range(self.coefs.size):

      self.coefs[i] = values[i]

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef neg(self):
    """
    PURPOSE:      Fast function to negate all coefficients of self.

    """
    #*************************************************************************************************
    cdef float64_t value = -1.0
    self.scale(value)   

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef scale(self,float64_t value):
    """
    PURPOSE:      Fast function to multiply all coefficients to scalar value.

    """
    #*************************************************************************************************
    
    cdef uint64_t i

    for i in range(self.coefs.size):

      self.coefs[i] *= value

    # end for   

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class otinum :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::









































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class spr_otinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef object         h                 # h_indx handler.
  cdef float64_t      tol               # tolerance to remove a term (sparse condition, 
                                        # if abs(coef)<tol -> coef[i] = 0.0
  
  cdef public uint8_t maxorder          # Stores the maximum order of the number.
  cdef public float64_t[::1] coefs      # Array of coefficients of the OTI number.
  cdef public uint64_t[::1]  indx       # Array of direction indices of the OTI number.
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self,uint64_t[::1] indx,float64_t[::1] coefs,uint8_t order, float64_t tol = 1e-20):
    """
    PURPOSE:      Constructor of the spr_otinum class.

    DESCRIPTION:  Creates a new OTI number given a list of coefficients.

    PARAMETERS:
                  indx:   Array of integers containing the corresponding  
                          directions of each coefficient.

                  coefs:  List of coefficients. 
                  
                  order:  Integer that sets the maximum order of the number.
                  
                      Example:  indx  = [0, 1, ],
                                coefs = [1, 2, 3],
                                order = 2
                                
                      creates a OTI number:
                      1.0 + 2.0 * e([1]) + 3.0 * e([[1,2],3])     

    RESULT:       
            The next attributes are allocated:
                  obj.indx:     the index of positions of the multicomplex 
                                number.
                  obj.coefs:    a numpy 1D array that contains the
                                coefficients corresponding to the obj.indx.
                                
                  obj.maxorder: an integer that indicates the order of the 
                                system.
                  
    """
    #*************************************************************************************************


    #Add warning for higher orders and orders that are not required
    self.h = H[order-1]
    if type(coefs) in number_types:
      
      # create a list to handle the index numbers      
      self.indx  = np.array([indx],dtype = np.uint64) 
      self.coefs = np.array([coefs],dtype = np.float64)
      self.maxorder = order
      self.tol = tol
    
    else:
      
      self.indx  = np.array(indx,dtype = np.uint64)
      self.coefs = np.array(coefs,dtype =np.float64) 
      self.maxorder = order
      self.tol = tol
      
      # TODO: Add warning and error if no enough coefficients are added 
      # to the coefs vector
      # 
      # Add also a code that enables the index array to be only a list with 
      # elements of type int (python integer, not numpy integer).
      #

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

    head      = 'spr_otinum('
    body      = ''
    
    body+= (np.array2string(np.array(self.indx),separator=",")).replace(" ","") +", "
    body+= (np.array2string(np.array(self.coefs),separator=",")).replace(" ","")
    
    tail = ', '+str(self.maxorder)+')'
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

    head      = ''
    body      = ''
    indx      = self.indx
    


    for i in range(0,indx.size):
      
      dirArray=getDirArray(indx[i],self.maxorder)
      
      coef = str('%+g' %self.coefs[i])
      
      e_dir = printOrderPos(dirArray)
      
      if i == 0 :
        
        sign = ''
       
        if coef[0]=='-':
          
          sign = coef[0] + ' '
          
        # end if

      else: 
        
        sign = coef[0] + ' '
        
      # end if
      
      body = body + sign + str(abs(self.coefs[i])) + e_dir + ' '
      
    # end for
    
    if len(indx) == 0:
      
      body="0.0"
      
    # end if
    
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __getitem__(self, uint64_t index):
    """
    PURPOSE:  To get the value of a spr_otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    cdef float64_t num = 0.

    if index == 0:

      if self.indx[0] == 0:
      
        return self.coefs[0]
      
      else:
      
        return num
      
      #end if
    
    #end if

    i=binarySearch(self.indx,index)

    if i!=self.indx.size:             


      if self.indx[i] == index :

        num = self.coefs[i]    

      # end if

    # end if
    
    return num

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, uint64_t index, float64_t value):
    """
    PURPOSE:  To set the value of a spr_otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]+=10
              >>> a
              spr_otinum([0,4,17], [10.,2.,3.], 2)
              >>> a[4] = 7
              >>> a
              spr_otinum([0,4,17], [10.,7.,3.], 2)
              >>> a[2] = 5
              >>> a
              spr_otinum([0,2,4,17], [10.,5.,7.,3.], 2)
    """
    #*************************************************************************************************
    
    cdef np.ndarray[uint64_t,ndim = 1,mode='c']  tmp_indx  = np.array(self.indx)
    cdef np.ndarray[float64_t,ndim = 1,mode='c'] tmp_coefs = np.array(self.coefs)


    if index == 0:
      if self.indx.size > 0:
        
        if self.indx[0] == 0:
        
          self.coefs[0] = value
        
        else:
          
          # insert new item in indx vector.
          tmp_coefs = np.insert(tmp_coefs,0,value)
          tmp_indx = np.insert(tmp_indx,0,0)

          # redefine the arrays

          self.indx  = tmp_indx 
          self.coefs = tmp_coefs

        #end if

        # Check if there were zeros added.
        self.checkZeros()

        return

      else:

        # insert new item in indx vector.
        tmp_coefs = np.insert(tmp_coefs,0,value)
        tmp_indx = np.insert(tmp_indx,0,0)

        # redefine the arrays

        self.indx  = tmp_indx 
        self.coefs = tmp_coefs


      # end if 
    
    #end if

    i=binarySearch(self.indx,index)
    
    if i!=self.indx.size:
      
      if self.indx[i] == index:

        self.coefs[i] = value

      elif i == 0:

        tmp_coefs = np.insert(tmp_coefs,0,value)
        tmp_indx = np.insert(tmp_indx,0,index)

        # redefine the arrays
        self.indx  = tmp_indx 
        self.coefs = tmp_coefs

      else:

        tmp_coefs = np.insert(tmp_coefs,i,value)
        tmp_indx = np.insert(tmp_indx,i,index)

        # redefine the arrays
        self.indx  = tmp_indx 
        self.coefs = tmp_coefs

      # end if

    else:
      
      tmp_coefs = np.insert(tmp_coefs,i,value)
      tmp_indx = np.insert(tmp_indx,i,index)

      # redefine the arrays
      self.indx  = tmp_indx 
      self.coefs = tmp_coefs

    # end if
    
    # Check if there were zeros added.
    self.checkZeros()

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      To define how to turn a spr_otinum into its opposite
                  (negative)

    DESCRIPTION:  It overloads the operator "-".
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [10.,7.,3.], 2)
                  >>> -a
                  spr_otinum([0,4,17], [-10.,-7.,-3.], 2)
    """
    #*************************************************************************************************

    return spr_otinum(np.array(self.indx),-np.array(self.coefs),self.maxorder)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      To define how to sum two spr_otinum numbers.

    DESCRIPTION:  It overloads the sum operator "+". It allows the addition
                  of spr_otinum numbers of different orders, or even the 
                  addition of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a + b
                  spr_otinum([0,2,4,17], [8.,9.,14.,5.], 2)
                  
                  >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a + 15
                  spr_otinum([0,4,17], [16.,3.,5.], 2)
    """
    #*************************************************************************************************
    
    
    if (type(other_in) in number_types) : # Case 1. Sum to real number.
      S = self.copy()
      # Check if the number is zero.
      if S.indx.size>0:
        
        # check if the real coefficient exists
        if S.indx[0]==0:
          
          S.coefs[0] = S.coefs[0] + other_in
          
        else:
          
          i=0
          S.indx  = np.insert(S.indx, i,       i)
          S.coefs = np.insert(S.coefs,i,other_in)
          
        # end if 
        
      else:
        
        S[0]=other_in
        
      # end if 

      S.checkZeros()

    elif (type(self) in number_types): # Case 1.5. reverse Sum to real number.
      
      S = other_in.copy()
      
      # Check if the number is zero.
      if S.indx.size>0:
        
        # check if the real coefficient exists
        if S.indx[0]==0:
          
          S.coefs[0] = S.coefs[0] + self
          
        else:
          
          i=0
          S.indx  = np.insert(S.indx, i,       i)
          S.coefs = np.insert(S.coefs,i,    self)
          
        # end if 
        
      else:
        
        S[0]=self
        
      # end if 

      S.checkZeros()

    elif type(other_in) is spr_otinum: # Case 2. Sum to spr_otinum.
      
      S = __sum_otinum__(self.copy() , other_in.copy() )

    # end if. Type cases.
    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(self, other_in):
    """
    PURPOSE:      To define how to sum two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace sum operator "+=". It allows the 
                  addition of spr_otinum numbers of different orders, and 
                  the addition of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a += b
                  >>> a 
                  spr_otinum([0,2,4,17], [8.,9.,14.,5.], 2)
                  >>> b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************
    
    self =  self + other_in

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the subtract operator "-". It allows the 
                  subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a - b
                  spr_otinum([0,2,4,17], [-6.,-9.,-8.,5.], 2)
                  
                  >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a - 15
                  spr_otinum([0,4,17], [-14.,3.,5.], 2)
    """
  #************************************************************************
    
    return self + (-other_in)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace subtract operator "-=". It allows
                  the subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a -= b
                  >>> a
                  spr_otinum([0,2,4,17], [-6.,-9.,-8.,5.], 2)
                  >>>b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************
  
    self = self + (-other_in)

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other_in):
    """
    PURPOSE:      To define how to multiply two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*". It allows
                  the multiplication of OTI numbers of different 
                  orders, no matter how they are sorted, or even the 
                  multiplication of an OTI number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a * b
                  spr_otinum([0,2,4,8,17], [7.,9.,32.,33.,35.], 2)
    """
    #*************************************************************************************************
    
    cdef uint64_t i
    cdef uint64_t j
    cdef uint64_t resIndx
    cdef uint8_t[:] error
    cdef spr_otinum S

    if type(other_in) in number_types:   # Case 1. Mult to real scalar.
      
      S = self.copy()
      
      for i in range(S.coefs.size):
        
        S.coefs[i] = S.coefs[i] * other_in

      # end for
    
    if type(self) in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      S = other_in.copy()
      
      for i in range(S.coefs.size):
        
        S.coefs[i] = S.coefs[i] * self

      # end for

    elif type(other_in) is spr_otinum:   # Case 2. Mult to spr_otinum.
      
      S = __mult_otinum(self, other_in)
      
      # end if  (case the numbers are zero.)
      
    # End if. Type cases.
    S.checkZeros()
    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE:      To define how to make an inplace multiplication between
                  two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*=". It allows
                  the multiplication of OTI numbers of different orders, 
                  or even the multiplication with scalars.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a *= b
                  >>> a
                  spr_otinum([0,2,4,8,17], [7.,9.,32.,33.,35.], 2)
                  >>> b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************

    
    self = self * other_in

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE:      To define how to divide two spr_otinum numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 

    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a/b
                  spr_otinum([0,2,4,8,17], [0.14285714,-0.18367347,
                                    0.20408163,-0.32069971,0.71428571], 2)
    """
    #*************************************************************************************************
    
    cdef float64_t factor
    cdef uint64_t i
    if type(other) in number_types:    # Case 1. real number.
      
      
      S = self.copy()
      
      factor = (1./other)
      
      for i in range(S.coefs.size):
        
        S.coefs[i] *= factor

      # end for 

      S.checkZeros()

    elif type(self) in number_types:    # Case 1.5 reverse real number. 

      return spr_otinum(np.array([0],dtype = np.uint64),np.array([self],dtype = np.float64),other.maxorder)/other
      
    elif type(other) is spr_otinum:   # Case 2. spr_otinum.
      
      
      
      S = self.copy()
      S *= power(other,-1)
      
    # End if. Type cases.

    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      To provide power function.
  
    DESCRIPTION:  It defines how to make a mcxnumber to the power of n.
  
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a**3
                  spr_otinum([0,4,8,17], [1.,9.,27.,15.], 2)
    """
    #*************************************************************************************************
    
    # print(self)
    # print(n)
    # print(z)

    
    P = power(self.copy(),n)

    
    return P

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE:      To create a copy of a spr_otinum object, totally 
                  independent of the original.

    DESCRIPTION:  The equality operator "=" is intended to create aliases
                  of multicomplex numbers. You should use copy() when you
                  need a copy instead of an alias.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,7.,3.], 2)
                  >>> b = a.copy()
                  >>> b[1] = 10
                  >>> a
                  spr_otinum([0,4,17], [1.,7.,3.], 2)
                  >>> b
                  spr_otinum([0,1,4,17], [1.,10.,7.,3.], 2)
    """
    #*************************************************************************************************

    if self.indx.size != 0:
      
      return spr_otinum(self.indx.copy(),self.coefs.copy(),self.maxorder)

    else:

      #empty number, MemoryView does not know how to handle them, therefore...
      return spr_otinum(np.array(self.indx),np.array(self.coefs),self.maxorder)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef void checkZeros(self):
    """
    PURPOSE:      check and eliminate the zeros of a spr_otinum.
    
    DESCRIPTION:  it simply search for elements less than a tolerance value
                  and erases them from the index and coefs array. 
    """
    #*************************************************************************************************
    
    # Initialize a counter for the number of deleted items
    cdef uint64_t j=0
    cdef uint64_t k=0
    
    cdef np.ndarray[uint64_t,ndim = 1] posToPreserve=np.empty(0,dtype=np.uint64)

    cdef np.ndarray[float64_t,ndim = 1,mode = 'c'] tmp_coefs 
    cdef np.ndarray[uint64_t,ndim = 1,mode = 'c']  tmp_indx

    # Search all items and select the positions that are outside the 
    # tolerance

    for j in range(self.indx.size):

      # If item is near zero, delete it.
      if abs(self.coefs[j]) > self.tol:
        
        posToPreserve = np.insert(posToPreserve,k,j)
        k+=1
      
      # end if
      
    # end for

    # remove the positions
    tmp_coefs = np.empty(posToPreserve.size,dtype = np.float64)
    tmp_indx = np.empty(posToPreserve.size,dtype = np.uint64)


    # Fill in the data to be preserved:

    for j in range(posToPreserve.size):
      
      tmp_coefs[j]=self.coefs[posToPreserve[j]]
      tmp_indx[j]=self.indx[posToPreserve[j]]

    # end for

    self.coefs = tmp_coefs
    self.indx  = tmp_indx 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef void changeOrder(self,uint8_t neworder):
    """
    PURPOSE:      To change the order of a spr_otinum.
  
    DESCRIPTION:  According to the new order, the index values are changed. 

    """
    #*************************************************************************************************
    
    # Initialize a counter for the number of deleted items
    cdef uint64_t count = 0
    cdef uint64_t elimin = 0

    cdef uint16_t[::1] oldDirA  
    cdef uint16_t[::1] newDirA 
    cdef uint8_t[::1]  oldExpA 
    cdef uint8_t[::1]  newExpA 
    cdef uint64_t starti
    cdef uint64_t j
    cdef uint8_t i

    cdef object new_h = H[neworder-1]
    
    # Case for a new order greater than previous order.
    if neworder>self.maxorder:
      

      newDirA = np.zeros(neworder,      dtype=np.uint16)
      newExpA = np.zeros(neworder,      dtype=np.uint8)
      
      if self.maxorder == 1:

        # check if the real coefficient exist.
        if self.indx[0] != 0:

          starti = 0

        else:

          starti = 1

        # end if
        
        newExpA[0] = 1

        # Search all index terms.
        for j in range(starti,self.indx.size):
          

          # Calculate the indx in base representation for the new order.
          newDirA[0] = self.indx[j]

          # find the new spr_otinum index for the new Order.
          self.indx[j] = new_h.findIndx(newDirA, newExpA)

        # end for

      else:
        

        # check if the real coefficient exist.
        if self.indx[0] != 0:

          starti = 0

        else:

          starti = 1

        # end if

        # Search all index terms.
        for j in range(starti,self.indx.size):
          
          # find old Exp and Dir arrays
          
          oldDirA = self.h.getDirA(self.indx[j])
          oldExpA = self.h.getExpA(self.indx[j])

          
          for i in range(self.maxorder):

            newDirA[i] = oldDirA[i]
            newExpA[i] = oldExpA[i]

          # end for
          
          # find the new spr_otinum index for the new Order.
          self.indx[j] = new_h.findIndx(newDirA, newExpA)

        # end for

      # end if

    elif neworder<self.maxorder:
      
      
      newDirA = np.zeros(neworder,      dtype=np.uint16)
      newExpA = np.zeros(neworder,      dtype=np.uint8)
      
      # check if the real coefficient exist.
      if self.indx[0] != 0:

        starti = 0

      else:

        starti = 1

      # end if

      for j in range(starti,self.indx.size):

        oldExpA = self.h.getExpA(self.indx[j])

        # calculate the order of the term:
        termOrder =  c_sumUI8(&oldExpA[0],self.maxorder)

        if termOrder<= neworder:

          oldDirA = self.h.getDirA(self.indx[j])
          
          # determine actions for order = 1.
          if neworder == 1:

            self.indx[count] = oldDirA[0]
            count+=1
          
          else:

            newDirA = oldDirA[:neworder]
            newExpA = oldExpA[:neworder]

            # find the new spr_otinum index for the new Order.
            self.indx[count] = new_h.findIndx(newDirA, newExpA)
            count+=1

        # end if
        
      # end for
      
      # eliminate the other elements that were not counted in:
      # look for a more efficient way...
      
      self.indx = self.indx[:count]
      self.coefs = self.coefs[:count]

    # end if

    #add check for other implementation

    self.h = H[neworder-1]
    self.maxorder = neworder

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDual(self, dirArray):
    """
    PURPOSE:      To add a human friendly form to get elements from a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.getDual([1,3])
                  5.0
                  >>> a.getDual([1])
                  0.0
    """
    #*************************************************************************************************

    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:
      return 0.
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = self.h.findIndx(dirA,expA)

    # end if
    
    return self[indx]

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def setDual(self, dirArray, value):
    """
    PURPOSE:      To add a human friendly form to set elements of a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.setDual([1,3],10)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
                  >>> a.setDual([1],2.5)
                  >>> print(a)
                  1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
    """
    #*************************************************************************************************
  
    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:
      return 0.
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = self.h.findIndx(dirA,expA)

    # end if

    self[indx] = value

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************
    
    
    cdef uint8_t   order  = np.sum(expA)
    
    # If asking for a coefficient of higher order, return 0.0
    if order > self.maxorder:
    
      return np.float64(0.0)  

    # end if 
    
    cdef float64_t factor = 1.0
    cdef uint16_t[::1] tmp_dirA = np.zeros(self.maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  tmp_expA = np.zeros(self.maxorder,dtype = np.uint8)
    cdef uint8_t i

    
    # Compute the multiplication factor and fill in the temporary arrays.

    for i in range(dirA.size):
      
      factor *= factorial(expA[i])
      tmp_dirA[i] = dirA[i]
      tmp_expA[i] = expA[i]
    
    # end for
    
    value = np.float64(0.0)
    indx  = self.h.findIndx(tmp_dirA,tmp_expA)
    value = self[indx]*factor
    
    return value

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDeriv(self, dirArray):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************

    if type(dirArray)==int:
      
      indxArray = [dirArray]
      
    else:
      
      indxArray = dirArray
      
    # end if

    
    tmp_dirA,tmp_expA = getDirExpA(dirArray)
    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    # create the real direction arrays:
    cdef uint16_t[::1] dirA = np.zeros(maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  expA = np.zeros(maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 


    return self.getDerivByDirExp(dirA,expA)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def toVector(self):
    """
    PURPOSE:      To convert a spr_otinum into its vector form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.

                    
    """
    #*************************************************************************************************

    return self.expand(ismat =0)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def toMatrix(self,ismat = 1,m = -1,isspr = 0):
    """
    PURPOSE:      To convert a spr_otinum into its matrix form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.
    
    INPUTS:
                  ismat: To define a matrix (1) or a vector (0)
                  isshape: To use the shape that will result of the number 
                    (-1) or an specific shape (given value).
                  isspr: To result in a sparse matrix (1) or not (0).
    """
    #*************************************************************************************************

    return self.expand(ismat = ismat, m = m, isspr = isspr)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def expand(self,ismat = 1,m = -1 , isspr = 0):
    """
    PURPOSE:      To convert a spr_otinum into its matrix form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation form.
                   
    INPUTS:
                  ismat: To define a matrix (1) or a vector (0)
                  m: To use the shape that will result of the number 
                    (-1) or an specific shape (given value).
                  isspr: To result in a sparse matrix (1) or not (0).
                    
    """
    #*************************************************************************************************
    
    cdef uint8_t[:] error = np.zeros([0],dtype = np.uint8)
    cdef uint64_t i
    cdef uint64_t k
    cdef uint64_t j
    cdef uint64_t finalshape

    if m == -1:
      # Deduce the matrix dimension by looking at the last indx and 
      # looking for the maximum base direction
      i = self.indx.size-1
      # Separate cases for order 1 and others.
      if self.maxorder == 1:

        m_max =  self.indx[i]
      
      else: 
        
        dirA = self.h.getDirA(self.indx[i])
        m_max = np.max(dirA)

      # end if 

    else:
      
      m_max = m
      
    # end if

    finalshape = findComb(m_max+1,self.maxorder)

    
    if ismat ==0:
      # vector type
      
      mat = np.zeros(finalshape)
      
      # Do only a certain amount of iterations:
      i = self.indx.size-1
      nIterMin = np.min([self.indx[i]+1,finalshape])
      k = 0

      for i in range(nIterMin):
        
        if i == self.indx[k]:

          mat[i] = self.coefs[k] 
          k+=1
        
        #end if

      # end for
      
    else:

      # matrix type
      
      if isspr == 0:
        #return the np.array?
        mat = np.array(__sprotinum2Mat_dense(self, finalshape))#np.zeros([finalshape,finalshape],dtype = np.float64)
        
      else:
        
        mat = __sprotinum2Mat_spr(self, finalshape)#spr.lil_matrix((finalshape,finalshape))
        
        
      # end if
      

    # end if 
    
    
    return mat

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: End of class spr_otinum :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
































































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  ndarray   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class ndarray:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  cdef public uint8_t maxorder          # Stores the maximum order of the vector.
  # cdef public float64_t[:,::1] data   # Array of coefficients of the OTI vector.
  cdef public np.ndarray data
  cdef public uint16_t m                # Number of basis of the OTI numbers inside.
  cdef public uint64_t size             # Number of oti numbers inside.
  cdef public uint64_t ndir             # Number of OTI directions in the OTIVEC
  cdef public tuple shape              
  cdef public tuple imshape             # Imaginary shape (taking into account the number of directions)
   #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self, tuple shape = None, uint8_t maxorder = 0, uint16_t m = 1, object buffer = None): 
    """
    PURPOSE:      Constructor of a general array class. (dense arrays)

    DESCRIPTION:  Creates a new OTI vector given different types of constructors.

    

    ## Constructor 1: Dense constructor. ##

      DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

    Mandatory Keywords:
                  
                  shape:  Tuple representing shape.
                          Remark: All elements in D are considered to have the same order. 

                  maxorder: Maximum order of the elements that will be stored.



    Optional Keyword Arguments:

                  m:      Number of basis the array will allocate. In particular m=1.
                  buffer: Data to be transfered to the array. buffer = None, 
                          so by default it creates an empty array. TODO!
                  

                  
    """

    cdef uint64_t i, j, nImDir

    # Determine the size of the array.

    # Number of imaginary directions:
    if maxorder == 0:
      
      raise ValueError("Unable to create OTI ndarray with maxorder 0.") # TODO: Allow non OTI numbers ...

    # end if 

    if shape == None:

      raise ValueError("Unable to create OTI ndarray with no specifyed shape.")

    # end if 
    
    self.shape = shape

    self.ndir = h.getNels(m,maxorder)
    
    self.imshape = shape + (self.ndir,) # TODO: Check which one is more efficient.

    if len(shape) >= 3:
    
      raise ValueError("Unable to create OTI array with dimensions greater than 3")

    # end if 

    self.size = 0
    
    for i in range(len(shape)):
      
      self.size *= self.shape[i]

    # end for
    
    self.data = np.empty( self.imshape, dtype = np.float64)         

    self.maxorder = maxorder

    self.m        = m
    
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

    head      = 'otiarray( maxorder = '+str(self.maxorder)+ ",\n"
    body      = ''
    body += (np.array2string(np.array(self.data),separator=","))
    body += ' \n'

        
    tail = " )"
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
    

    head      = ''
    body = (np.array2string(np.array(self.data),separator=","))
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __getitem__(self, index):
    """
    PURPOSE:  To get the value of a spr_otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    
    
    if type(index) == int or type(index) == slice:
    
      tuple_indx = (index,)
    
    else:
    
      tuple_indx = index
    
    # end if 
                                                 # this only gets one dimension, not tuples or slices...
    cdef float64_t[::1] coefs = self.data[index] # be careful with the dimensions... 


    return otinum(coefs,self.maxorder,exact = True)
    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, index,  value):
    """
    PURPOSE:  To set the value of a spr_otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]+= 10
              >>> a
              spr_otinum([0,4,17], [10.,2.,3.], 2)
              >>> a[4] = 7
              >>> a
              spr_otinum([0,4,17], [10.,7.,3.], 2)
              >>> a[2] = 5
              >>> a
              spr_otinum([0,2,4,17], [10.,5.,7.,3.], 2)
    """
    #*************************************************************************************************
    
    if type(index) == int or type(index) == slice:
    
      tuple_indx = (index,)
    
    else:
    
      tuple_indx = index
    
    # end if 

    # how to assign the values of the array?

    if type(value) == otinum:

      self.data[index] = value.coefs # this must have the same dimensions....

    # end if 

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

  #     return np.zeros(self.nels,dtype = np.float64)
    
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
    
  #   return self.coefs[:,indx]

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

  #   # check if dimensions agree.

  #   if value.size == self.nels:

  #     self.coefs[:,indx] = value

  #   else:

  #     raise ValueError("The length of the vector must equals the number of elements of the otivec.")

  #   # end if 

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
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
    
  #   cdef uint8_t   order  = np.sum(expA)
    
  #   # If asking for a coefficient of higher order, return 0.0
  #   if order > self.maxorder:
    
  #     return np.zeros(self.nels,dtype=np.float64)  

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
    
  #   cdef float64_t[:] coefs  = np.empty(self.nels,dtype = np.float64)
    
  #   for i in range(self.nels):

  #     coefs[i] = self.coefs[i,indx]*factor 

  #   # end for
        
  #   return coefs

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
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class ndarray ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::































































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  otivec   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otivec:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  cdef public uint8_t maxorder          # Stores the maximum order of the vector.
  cdef public float64_t[:,::1] coefs    # Array of coefficients of the OTI vector.
  cdef public uint16_t m                # Number of basis of the OTI numbers inside.
  cdef public uint64_t nels             # Number of oti numbers inside.
  cdef public uint64_t ndir             # Number of OTI directions in the OTIVEC
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self,D, **kwargs):#*args, **kwargs
    """
    PURPOSE:      Constructor of the otivec class.

    DESCRIPTION:  Creates a new OTI vector given different types of constructors.

    

    ## Constructor 1: Dense constructor. ##

      DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

    Arguments:
                  
                  D:      Numpy 1D array of spr_otinum.
                          Remark: All elements in D are considered to have the same order. 

    Optional Keyword Arguments:

                  m:      Number of basis the vector will have. Default: The number of 






    ## Constructor 2: Full constructor. ##

    DESCRIPTION:  Creates an vector of oti elements given by a 2D matrix that has the coefficients
                  for all results.

    Keyword Arguments:
                  
                  order:  Maximum order of the OTI numbers that will be stored. Default: 1

                  m:      Number of basis the vector will have. 

                  ?nels:   Number of OTI elements to be stored in the vector.



    ## Constructor 3: Constructor from another otivec. ##

    DESCRIPTION:  Creates an vector of oti elements given by a 2D matrix that has the coefficients
                  for all results.

    Keyword Arguments:
                  
                  order:  Maximum order of the OTI numbers that will be stored. Default: 1

                  m:      Number of basis the vector will have. 

                  ?nels:   Number of OTI elements to be stored in the vector.

                  
    """
    cdef int i
    cdef int j
    cdef spr_otinum[:] dense_oti_vector

    cdef uint64_t max_indx = 0
    cdef uint64_t last_i = 0
    cdef spr_otinum spr_oti
    cdef uint16_t max_basis = 0
    cdef uint64_t total_coefficients = 0
    # Determine constructor:
    if type(D) == otivec:

      # Constructor 3:  Same otivec.
      self.maxorder = D.maxorder 
      self.coefs = np.copy(D.coefs)
      self.m = D.m
      self.nels = D.nels
      self.ndir = D.ndir

    else:

      if len(D.shape) == 1:

        if type(D[0]) == spr_otinum:
        
          # CONSTRUCTOR 1.
          
          # For fast manipulation in cython
          dense_oti_vector = np.array(D,dtype=spr_otinum)

          # Search for the maximum index
          

          # TODO: Check that all OTI numbers have the same maxorder? ...
          self.maxorder = dense_oti_vector[0].maxorder

          self.nels = dense_oti_vector.size
          # Get the maximum index of the elements in data
          for i in range(self.nels):
            
            spr_oti = dense_oti_vector[i]

            if spr_oti.indx.size>0:

              last_i = spr_oti.indx.size -1
              
              if max_indx < spr_oti.indx[last_i]:

                max_indx = spr_oti.indx[last_i]

              # end if
            # end if

          # end for 

          # Get (if given) the maximum number of imaginary directions.
          if 'm' in kwargs:
            
            self.m = kwargs['m']
          
          else:

            # For that indx, find the corresponding maximum number of directions.
            self.m = np.max(h.getDirA(max_indx,self.maxorder))

          # end if   


          # generate the number of elements in the matrix:
          self.ndir = findComb(self.m+1,self.maxorder) 

          # create dense array:
          self.coefs = np.zeros((self.nels,self.ndir),dtype = np.float64)

          for i in range(self.nels):
            
            spr_oti = dense_oti_vector[i]

            for j in range(spr_oti.indx.size):

              self.coefs[i,spr_oti.indx[j]] = spr_oti.coefs[j]
            
            # end for.
          
          # end for. 


        else:

          # CONSTRUCTOR 2

          # Entering a vector of real numbers
          # Get (if given) the maximum number of imaginary directions.
          if 'm' in kwargs:
            
            self.m = kwargs['m']
          
          else:

            # Default number of directions.
            self.m = 1

          # end if   

          if 'order' in kwargs:
        
            self.maxorder = kwargs['order']
          
          else:

            # Default order: 1
            self.maxorder = 1

          # end if 

          # generate the number of elements in the matrix:
          self.ndir = findComb(self.m+1,self.maxorder) 
          self.nels = dense_oti_vector.size
          # create dense array:
          self.coefs = np.zeros((self.nels,self.ndir),dtype = np.float64)

          # Assign the values of D in the coefs matrix.
          self.coefs[:,0] = D

      else:

        # CONSTRUCTOR 2.
        
        # TODO: Add support for only defining one: either m or order.

        if 'm' in kwargs:
          
          self.m = kwargs['m']
        
        else:

          raise ValueError("m must be specified.\n Try otivec(...,m=5) or the specific number of basis matrix represent.")

        # end if   

        if 'order' in kwargs:
      
          self.maxorder = kwargs['order']
        
        else:

          # Default order: 1
          raise ValueError("Maximum order must be specified.\n Try otivec(...,order=5) or whatever order the matrix represent.")

        # end if 

        # generate the number of elements in the matrix:
        self.ndir = findComb(self.m+1,self.maxorder) 

        self.nels = D.shape[0]

        if D.shape[1] == self.ndir:

          # create dense array: Make sure that the type of data is float 64.
          self.coefs = np.array(D,dtype = np.float64)

        else:

          # error, the number of 
          raise ValueError("The dimension of D must correspond to the 'm' and 'order' given.")

      # end if 

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

    head      = '< otivec with '
    body      = ''
    body += ' '+str(self.nels)+' oti numbers of'
    body += ' order ' + str(self.maxorder) 
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
    cdef uint64_t[:] indx = np.arange(self.ndir,dtype = np.uint64)
    cdef spr_otinum spr_oti

    head      = ''
    body      = '['
    


    for i in range(0,self.nels):
      
      spr_oti = spr_otinum(indx,self.coefs[i,:],self.maxorder)
      spr_oti.checkZeros()

      
      body += '  ' + str(spr_oti)+ ',\n'
      
      
    # end for
    body = body[:-2]
    tail = ']'
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __getitem__(self, uint64_t index):
    """
    PURPOSE:  To get the value of a spr_otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    
    
    cdef uint64_t[:] indx = np.arange(self.ndir,dtype = np.uint64)
    cdef float64_t[:] coefs = self.coefs[index,:]

    cdef uint64_t[:] nonZero = np.array(np.nonzero(coefs)[0],dtype=np.uint64)

    cdef uint64_t[:] newindx = np.empty(nonZero.size,dtype = np.uint64)
    cdef float64_t[:] newcoefs = np.empty(nonZero.size,dtype = np.float64)

    cdef uint64_t i 

    cdef spr_otinum spr_oti

    if index > self.nels:

      raise IndexError("Index ("+str(index)+") greater than number of elements in otivec ("+str(self.nels)+").")
    
    # end if


    # TODO: Check and do something if a larger basis system is given.
    for i in range(nonZero.size):
      
      newindx[i] = indx[nonZero[i]]
      newcoefs[i] = coefs[nonZero[i]]

    # end for 
    
    spr_oti = spr_otinum(newindx,newcoefs,self.maxorder)

    return spr_oti
    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, uint64_t index, spr_otinum value):
    """
    PURPOSE:  To set the value of a spr_otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]+= 10
              >>> a
              spr_otinum([0,4,17], [10.,2.,3.], 2)
              >>> a[4] = 7
              >>> a
              spr_otinum([0,4,17], [10.,7.,3.], 2)
              >>> a[2] = 5
              >>> a
              spr_otinum([0,2,4,17], [10.,5.,7.,3.], 2)
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j

    if index > self.nels:

      raise IndexError("Index ("+str(index)+") greater than number of elements in otivec ("+str(self.nels)+").")
    
    # end if

    # TODO: Check and do something if a larger basis system is given.
    # TODO: Put everything else zero.
    
    j = 0

    for i in range(self.coefs.shape[1]):

      if j<value.indx.size:
        
        if value.indx[j] == i:
          
          self.coefs[index,i] = value.coefs[j]
          j+=1

        else: 
          
          self.coefs[index,i] = 0

        # end if 

      else: 

        self.coefs[index,i] = 0 

      # end if 

    # end for

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def getDual(self, dirArray):
    """
    PURPOSE:      To add a human friendly form to get elements from a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.getDual([1,3])
                  5.0
                  >>> a.getDual([1])
                  0.0
    """
    #*************************************************************************************************


    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:

      return np.zeros(self.nels,dtype = np.float64)
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = h.findIndx(dirA,expA,self.maxorder)

    # end if
    
    return self.coefs[:,indx]

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def setDual(self, dirArray, value):
    """
    PURPOSE:      To add a human friendly form to set elements of a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.setDual([1,3],10)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
                  >>> a.setDual([1],2.5)
                  >>> print(a)
                  1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
    """
    #*************************************************************************************************
  
    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:

      raise ValueError("dirArray must correspond with the maxorder of the otivec")

    # end if 
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = h.findIndx(dirA,expA,self.maxorder)

    # end if

    # check if dimensions agree.

    if value.size == self.nels:

      self.coefs[:,indx] = value

    else:

      raise ValueError("The length of the vector must equals the number of elements of the otivec.")

    # end if 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************
    
    cdef uint8_t   order  = np.sum(expA)
    
    # If asking for a coefficient of higher order, return 0.0
    if order > self.maxorder:
    
      return np.zeros(self.nels,dtype=np.float64)  

    # end if 
    
    cdef float64_t factor = 1.0
    cdef uint16_t[::1] tmp_dirA = np.zeros(self.maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  tmp_expA = np.zeros(self.maxorder,dtype = np.uint8)
    cdef uint8_t i

    
    # Compute the multiplication factor and fill in the temporary arrays.

    for i in range(dirA.size):
      
      factor *= factorial(expA[i])
      tmp_dirA[i] = dirA[i]
      tmp_expA[i] = expA[i]
    
    # end for
    
    
    indx  = h.findIndx(tmp_dirA,tmp_expA,self.maxorder)
    
    cdef float64_t[:] coefs  = np.empty(self.nels,dtype = np.float64)
    
    for i in range(self.nels):

      coefs[i] = self.coefs[i,indx]*factor 

    # end for
        
    return coefs

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDeriv(self, dirArray):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************

    if type(dirArray)==int:
      
      indxArray = [dirArray]
      
    else:
      
      indxArray = dirArray
      
    # end if

    
    tmp_dirA,tmp_expA = getDirExpA(dirArray)
    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    # create the real direction arrays:
    cdef uint16_t[::1] dirA = np.zeros(maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  expA = np.zeros(maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 


    return self.getDerivByDirExp(dirA,expA)

  #---------------------------------------------------------------------------------------------------  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class otivec :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
























# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  otimat   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otimat:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  cdef public uint8_t maxorder          # Stores the maximum order of the vector.
  cdef public object[:] elements        # Array of matrices for each oti dir.
  cdef public uint16_t m                # Number of basis of the OTI numbers inside.
  cdef public uint64_t[:] shape         # Number of oti numbers inside.
  cdef public uint64_t ndir             # Number of OTI directions in the otimat
  cdef public uint8_t spr_type          # Number that indicates the type of sparse matrix. 
                                        # 0: csr, 1: coo, 2: lil
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self, shape, m,order, spr_type): #*args, **kwargs
    """
    PURPOSE:      Constructor of the otimat class.

    DESCRIPTION:  Creates a new OTI matirx given different types of constructors.

    

    ## Constructor 1: Empty constructor. ##

      DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

    Arguments:
                  
                  shape:  Shape of the matrix.

                  order:  Maximum order of the OTI numbers that will be stored. Default: 1

                  m:      Number of basis the vector will have.

                  spr_type: Type of sparse matrix to be created.  0: csr, 1: coo, 2: lil

                  
    """

    self.maxorder = order
    self.m        = m       
    self.shape    = np.array(shape, dtype = np.uint64)
    self.ndir     = findComb(self.m+1, self.maxorder)    
    self.spr_type = spr_type


    cdef uint64_t i

    if spr_type == 0:     # CSR Matrix
      
      self.elements = np.empty(self.ndir,dtype = spr.csr_matrix)

      for i in range(self.ndir):
        
        self.elements[i] = spr.csr_matrix(shape,dtype = np.float64)

      # end for

    elif spr_type == 1:   # COO Matrix
      
      self.elements = np.empty(self.ndir,dtype = spr.coo_matrix)

      for i in range(self.ndir):
        
        self.elements[i] = spr.coo_matrix(shape,dtype = np.float64)

      # end for

    elif spr_type == 2:   # LIL Matrix
      
      self.elements = np.empty(self.ndir,dtype = spr.lil_matrix)

      for i in range(self.ndir):
        
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

    head      = '< otimat'
    body      = ''
    body += ' of shape ('+str(self.shape[0])+","+str(self.shape[1])+') with oti numbers of'
    body += ' order ' + str(self.maxorder) 
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
    cdef uint64_t[:] indx = np.arange(self.ndir,dtype = np.uint64)
    cdef spr_otinum spr_oti

    head      = '< otimat'
    body      = ''
    body += ' of shape ('+str(self.shape[0])+","+str(self.shape[1])+') with oti numbers of'
    body += ' order ' + str(self.maxorder) 
    body += ' and ' + str(self.m)+' basis: \n'
    body += "["

    for i in range(0,self.ndir):
      
      body += '  ' + repr(self.elements[i])+ ',\n'
      
    # end for

    body = body[:-2]
    tail = "] >"
    
    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __getitem__(self, index):
    """
    PURPOSE:  To get the value of a otimat coefficient.

    """
    #*************************************************************************************************
    
    
    cdef float64_t[::1] newcoefs = np.empty(self.ndir,dtype = np.float64)
    
    cdef object mat

    cdef uint64_t i 

    cdef otinum oti


    if type(index) == tuple:
      
      
      
      for i in range(self.ndir):

        newcoefs[i] = self.elements[i][index]

      

      # spr_oti = spr_otinum(newindx,newcoefs,self.maxorder)
      # spr_oti.checkZeros()
      oti = otinum(newcoefs, self.maxorder,exact = True)

      return oti


    # TODO: add support for slices.
    # elif type(index) == slice:



    elif type(index) == int: # integer

      if index > self.ndir:
        
        raise IndexError("Index out of bounds.")

      # end if 

      return self.elements[index]

      # end if 

  #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __setitem__(self, index, spr_otinum value):
  #   """
  #   PURPOSE:  To set the value of a otimat coefficient.

  #   """
  #   #*************************************************************************************************
    
    
  #   cdef uint64_t i 
  #   cdef object mat
    

  #   if type(index) == tuple:      

  #     j = 0

  #     for i in range(self.ndir):
      
  #       if j<value.indx.size:
          
  #         if value.indx[j] == i:
            
  #           mat = self.elements[i]
  #           mat[index] = value.coefs[j]
  #           j+=1

  #         else: 
            
  #           mat = self.elements[i]
            
  #           if mat[index]!= 0.0:

  #             mat[index] = 0.0

  #           # end if 

  #         # end if 

  #       else: 

  #         mat = self.elements[i]
            
  #         if mat[index]!= 0.0:

  #           mat[index] = 0.0
            
  #         # end if

  #       # end if 

  #     # end for

  #   # TODO: add support for slices.
  #   # elif type(index) == slice:

  #   elif type(index) == int: # integer

  #     if index > self.ndir:
        
  #       raise IndexError("Index out of bounds.")

  #     # end if 

  #     self.elements[index] = value

  #   # end if 


  # #--------------------------------------------------------------------------------------------------- 



  #***************************************************************************************************
  def __setitem__(self, index, otinum value):
    """
    PURPOSE:  To set the value of a otimat coefficient.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i 
    cdef object mat
    

    if type(index) == tuple:      

      j = 0

      for i in range(self.ndir):
        self.elements[i][index] = value[i]
      # end for

    # TODO: add support for slices.
    # elif type(index) == slice:

    elif type(index) == int: # integer

      if index > self.ndir:
        
        raise IndexError("Index out of bounds.")

      # end if 

      self.elements[index] = value

    # end if 


  #--------------------------------------------------------------------------------------------------- 

    
  #***************************************************************************************************
  def tocsr(self):
    """
    PURPOSE:  Convert to CSR sparse format.

    """
    #*************************************************************************************************
    
    
    cdef uint64_t i

    for i in range(self.ndir):

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

    for i in range(self.ndir):

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

    for i in range(self.ndir):

      self.elements[i] = self.elements[i].tolil()
    
    # end for
  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def getDual(self, dirArray):
    """
    PURPOSE:      To add a human friendly form to get elements from a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.getDual([1,3])
                  5.0
                  >>> a.getDual([1])
                  0.0
    """
    #*************************************************************************************************


    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:

      if self.spr_type == 0:
        
        return spr.csr_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

      elif self.spr_type == 1:
        
        return spr.coo_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

      elif self.spr_type == 2:
        
        return spr.lil_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

      # end if  
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = h.findIndx(dirA,expA,self.maxorder)

    # end if
    
    return self.elements[indx]

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def setDual(self, dirArray, value):
    """
    PURPOSE:      To add a human friendly form to set elements of a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.setDual([1,3],10)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
                  >>> a.setDual([1],2.5)
                  >>> print(a)
                  1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
    """
    #*************************************************************************************************
  
    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if
      
    tmp_dirA,tmp_expA = getDirExpA(indxArray)

    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    if maxorder > self.maxorder:

      raise ValueError("dirArray must correspond with the maxorder of the otivec")

    # end if 
    
    # create the real direction arrays:
    dirA = np.zeros(self.maxorder,dtype = np.uint16)
    expA = np.zeros(self.maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 

    if indxArray[0] == 0:
        
      indx = 0

    elif self.maxorder == 1:

      indx = indxArray[0]

    else:

      indx = h.findIndx(dirA,expA,self.maxorder)

    # end if


    self.elements[indx] = value

  

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    

    """
    #*************************************************************************************************
    
    cdef uint8_t   order = np.sum(expA)
    
    # If asking for a coefficient of higher order, return 0.0
    if order > self.maxorder:

      if self.spr_type == 0:
        
        return spr.csr_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

      elif self.spr_type == 1:
        
        return spr.coo_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

      elif self.spr_type == 2:
        
        return spr.lil_matrix((self.shape[0],self.shape[1]),dtype=np.float64)  

      # end if 

    # end if 
    
    cdef float64_t factor = 1.0
    cdef uint16_t[::1] tmp_dirA = np.zeros(self.maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  tmp_expA = np.zeros(self.maxorder,dtype = np.uint8)
    cdef uint8_t i

    
    # Compute the multiplication factor and fill in the temporary arrays.

    for i in range(dirA.size):
      
      factor *= factorial(expA[i])
      tmp_dirA[i] = dirA[i]
      tmp_expA[i] = expA[i]
    
    # end for
    
    
    indx  = h.findIndx(tmp_dirA,tmp_expA,self.maxorder)
    
    cdef object mat = self.elements[indx] * factor

    
        
    return mat

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDeriv(self, dirArray):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************

    if type(dirArray)==int:
      
      indxArray = [dirArray]
      
    else:
      
      indxArray = dirArray
      
    # end if

    
    tmp_dirA,tmp_expA = getDirExpA(dirArray)
    cdef uint8_t maxorder = np.sum(tmp_expA)
    cdef uint8_t i
    cdef uint64_t indx

    # create the real direction arrays:
    cdef uint16_t[::1] dirA = np.zeros(maxorder,dtype = np.uint16)
    cdef uint8_t[::1]  expA = np.zeros(maxorder,dtype = np.uint8)
    
    for i in range(len(tmp_expA)):
      
      dirA[i] = tmp_dirA[i]
      expA[i] = tmp_expA[i]

    # end for 


    return self.getDerivByDirExp(dirA,expA)

  #---------------------------------------------------------------------------------------------------  




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class otimat :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::













































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::      Auxiliary Functions      ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 


#*****************************************************************************************************
cdef float64_t[:,::1] __sprotinum2Mat_dense(spr_otinum mySelf, uint64_t finalshape):
  """
  PURPOSE:  To implement in c-speed the multiplication of dual numbers.

  """
  #***************************************************************************************************





  cdef float64_t[:,::1] mat = np.zeros([finalshape,finalshape],dtype = np.float64)

  cdef uint64_t i
  cdef uint64_t j
  cdef uint64_t k

  cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
  # get real coefficient
  # fill up the diagonal
  
  if mySelf.maxorder == 1:
    
    # Fill up diagonal.
    if mySelf.indx[0]==0:

      for i in range(finalshape):
        
        mat[i,i] = mySelf.coefs[0] 
        
      # end for

    # end if
    
    for i in range(mySelf.indx.size):
      
      # k'th element of the dual number self.

      mat[mySelf.indx[i],0] = mySelf.coefs[i]
      
    # end for
    
  else:
    
    # loop in each element of the matrix
    for i in range(mySelf.indx.size):

      for j in range(finalshape):
        # Get the directions and the exponents of the column j directions

        k =  mySelf.h.multIndx(mySelf.indx[i],j,error)

        if k<finalshape and error[0] == 0:

          mat[k,j] = mySelf.coefs[i]

        # end if 

      # end for
      
    # end for
    
  # end if

  return mat
  
#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef float64_t[:,::1] __otinum2Mat_dense(otinum mySelf, uint64_t finalshape):
  """
  PURPOSE:  To implement in c-speed the multiplication of dual numbers.

  """
  #***************************************************************************************************





  cdef float64_t[:,::1] mat = np.zeros([finalshape,finalshape],dtype = np.float64)

  cdef uint64_t i
  cdef uint64_t j
  cdef uint64_t k



  cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
  
  cdef float64_t coef  

  # get real coefficient
  # fill up the diagonal
  
  if mySelf.maxorder == 1:
    
    # Fill up diagonal.
    
    j = 0
    for i in range(finalshape):
            
      mat[i,i] = mySelf.coefs[j] 
          
    # end for
    
    for i in range(mySelf.coefs.size):
      
      # k'th element of the dual number self.

      mat[i,j] = mySelf.coefs[i]
      
    # end for
    
  else:
    
    # loop in each element of the matrix
    for i in range(mySelf.coefs.size):
      
      coef = mySelf.coefs[i]
      
      if coef != 0.0:

        for j in range(finalshape):
          # Get the directions and the exponents of the column j directions

          k =  h.multIndx(i, j, mySelf.maxorder, error)

          if k<finalshape and error[0] == 0:

            mat[k,j] = mySelf.coefs[i]

          # end if 

        # end for

      # end if
      
    # end for
    
  # end if

  return mat
  
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __otinum2Mat_spr(spr_otinum mySelf, uint64_t finalshape):
  """
  PURPOSE:  To implement in c-speed the multiplication of dual numbers.

  """
  #***************************************************************************************************

  cdef object mat = spr.lil_matrix((finalshape,finalshape))

  cdef uint64_t i
  cdef uint64_t j
  cdef uint64_t k

  cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
  # get real coefficient
  # fill up the diagonal
  
  # get real coefficient
  # fill up the diagonal
  
  if mySelf.maxorder == 1:
    
    # Fill up diagonal.
    
    j = 0
    for i in range(finalshape):
            
      mat[i,i] = mySelf.coefs[j] 
          
    # end for
    
    for i in range(mySelf.coefs.size):
      
      # k'th element of the dual number self.

      mat[i,j] = mySelf.coefs[i]
      
    # end for
    
  else:
    
    # loop in each element of the matrix
    for i in range(mySelf.coefs.size):
      
      coef = mySelf.coefs[i]
      
      if coef != 0.0:

        for j in range(finalshape):
          # Get the directions and the exponents of the column j directions

          k =  h.multIndx(i, j, mySelf.maxorder, error)

          if k<finalshape and error[0] == 0:

            mat[k,j] = mySelf.coefs[i]

          # end if 

        # end for

      # end if
      
    # end for
    
  # end if

  return mat
  
#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
cdef object __sprotinum2Mat_spr(spr_otinum mySelf, uint64_t finalshape):
  """
  PURPOSE:  To implement in c-speed the multiplication of dual numbers.

  """
  #***************************************************************************************************

  cdef object mat = spr.lil_matrix((finalshape,finalshape))

  cdef uint64_t i
  cdef uint64_t j
  cdef uint64_t k

  cdef uint8_t[:] error = np.array([0],dtype = np.uint8)
  # get real coefficient
  # fill up the diagonal
  
  if mySelf.maxorder == 1:
    
    # Fill up diagonal.
    if mySelf.indx[0]==0:

      for i in range(finalshape):
        
        mat[i,i] = mySelf.coefs[0] 
        
      # end for

    # end if
    
    for i in range(mySelf.indx.size):
      
      # k'th element of the dual number self.

      mat[mySelf.indx[i],0] = mySelf.coefs[i]
      
    # end for
    
  else:
    
    # loop in each element of the matrix
    for i in range(mySelf.indx.size):

      for j in range(finalshape):
        # Get the directions and the exponents of the column j directions

        k =  mySelf.h.multIndx(mySelf.indx[i],j,error)

        if k<finalshape and error[0] == 0:

          mat[k,j] = mySelf.coefs[i]

        # end if 

      # end for
      
    # end for
    
  # end if

  return mat
  
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef spr_otinum __sum_otinum__(spr_otinum mySelf,spr_otinum other_in):
  """
  PURPOSE:  To implement in c-speed the sum of dual numbers.

  """
  #***************************************************************************************************

  # Create a new array to contain the sum of all the coefficients.
  cdef uint64_t  otherEls = other_in.indx.size
  cdef uint64_t  SEls     = mySelf.indx.size
  cdef uint64_t  maxEls   = otherEls + SEls
  cdef uint64_t[::1]  tmpIndx  = np.empty(maxEls,dtype=np.uint64)
  cdef float64_t[::1] tmpCoefs = np.empty(maxEls,dtype=np.float64)
  cdef uint64_t k1 = 0 
  cdef uint64_t k2 = 0
  cdef uint64_t count = 0
  cdef spr_otinum S     = mySelf.copy()
  cdef spr_otinum other = other_in.copy()
  cdef spr_otinum answer
  

  # check to preserve the maximum order             
  if other.maxorder!=S.maxorder:
    
    if other.maxorder > S.maxorder:
      
      S.changeOrder(other.maxorder)
      
    else:
      
      other.changeOrder(S.maxorder)
      
    # end if
    
  # end if
  
  if otherEls != 0 and SEls != 0:

    
    
    while (k1+k2) !=  maxEls:

      if k1 == SEls:
        
        tmpIndx[count] = other.indx[k2]
        tmpCoefs[count]= other.coefs[k2]
        count += 1
        k2+=1
        
      elif k2 == otherEls:
        
        tmpIndx[count] = S.indx[k1]
        tmpCoefs[count]= S.coefs[k1]
        count += 1
        k1    += 1 
        
      elif S.indx[k1] < other.indx[k2]:
        
        tmpIndx[count] = S.indx[k1]
        tmpCoefs[count]= S.coefs[k1]
        k1    += 1
        count += 1

      elif other.indx[k2] < S.indx[k1]:
        
        tmpIndx[count] = other.indx[k2]
        tmpCoefs[count]= other.coefs[k2]
        count += 1
        k2+=1 

      else:
        
        # add tolerance check
        if np.abs(other.coefs[k2] + S.coefs[k1])>S.tol:

          tmpIndx[count] = other.indx[k2]
          tmpCoefs[count]= other.coefs[k2] + S.coefs[k1]
          
          count+=1

        # end if

        k1+=1
        k2+=1

      # end if

    # end while

    answer = spr_otinum(tmpIndx[:count],tmpCoefs[:count],S.maxorder)


    
  elif SEls == 0:  
    
    answer = other

  else:

    answer = S

  # end if
  return answer

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef spr_otinum __mult_otinum(spr_otinum mySelf, spr_otinum other_in):
  """
  PURPOSE:  To implement in c-speed the multiplication of dual numbers.

  """
  #***************************************************************************************************

  # Initialize an empty multicomplex number.
  cdef spr_otinum S        = spr_otinum(np.array([],dtype=np.uint64), np.array([],dtype=np.float64),mySelf.maxorder)
  cdef spr_otinum other    = other_in.copy()
  cdef spr_otinum selfcopy = mySelf.copy()
  cdef uint8_t[:] error
  cdef uint64_t resIndx

  # Preserve only the lowest order
  if other.maxorder!=S.maxorder:
    
    if other.maxorder > S.maxorder:
      
      other.changeOrder(S.maxorder)
      
    else:

      selfcopy.changeOrder(other.maxorder)
      S.changeOrder(other.maxorder)
      
    # end if
    
  # end if

  # If any of the numbers is zero, then the result will be zero.
  if (selfcopy.indx.size != 0) and (other.indx.size != 0) :

    error = np.array([0],dtype=np.uint8)

    # define particular result for order == 1.
    if S.maxorder == 1:

      return selfcopy[0]*other + other[0]*selfcopy - selfcopy[0]*other[0]

    # end if

    for i in range(0,selfcopy.indx.size):
      
      for j in range(0,other.indx.size):
        
        if selfcopy.indx[i] == 0:

          S[ other.indx[j] ] = S[ other.indx[j] ] + other.coefs[j]*selfcopy.coefs[i] 

        elif other.indx[j] == 0:

          S[ selfcopy.indx[i] ] = S[ selfcopy.indx[i] ] + selfcopy.coefs[i] * other.coefs[j] 
        
        else:

          # Compute the order of the terms the operation.
          resIndx = S.h.multIndx(selfcopy.indx[i],other.indx[j],error)

          if error[0] == 0 :    # No error.

            # Add result to the number
            # TODO: Here we are doing two binarySearch calls. Modify it so that 
            # we only create one.
            S[resIndx] = S[resIndx] + selfcopy.coefs[i] * other.coefs[j]

          # end if 

        # end if
        
      # end for. j
      
    # end for. i

  # end if 
  return S
#-----------------------------------------------------------------------------------------------------









#*****************************************************************************************************
cpdef ndarray solveLU(otimat A, ndarray b, solver = 0):
  """
  PURPOSE:  Solve a system Ax = b

  """
  #***************************************************************************************************

  
  cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.maxorder ) 
  cdef uint64_t i, indxX, indxA, k
  cdef uint8_t  j , pos
  cdef uint8_t[:,::1] multiples
  cdef uint8_t[::1]  expArray
  cdef uint16_t[::1] dirArray
  cdef float64_t[:] fi, solvedX   # Holder for the solution  
  # cdef np.ndarray[float64_t, ndim=1] 
  cdef object K0, Kj, A0
  cdef uint16_t[::1] dirA = np.zeros(A.maxorder,dtype = np.uint16)
  cdef uint16_t[::1] dirX = np.zeros(A.maxorder,dtype = np.uint16)
  cdef uint8_t[::1] expA = np.zeros(A.maxorder,dtype = np.uint8)
  cdef uint8_t[::1] expX = np.zeros(A.maxorder,dtype = np.uint8)
  cdef uint8_t[::1] newExpA
  # Create a copy of A?
  # Change the type of sparse matrix to CSR
  A.tocsr()

  A0 = spr.linalg.splu(A[ZERO].tocsc())

  # TODO: Check dimensions of b, A to match.
  
  # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
  for i in range(A.ndir):
    

    fi = b.data[:,i]

    # Get direction and exponent arrays:
    expArray = h.getExpA(i,A.maxorder)
    dirArray = h.getDirA(i,A.maxorder)

    # get the multiples of the exponent array:
    multiples = compMultiples(expArray)

    # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
    # loop in all multiples
    for j in range(multiples.shape[0]-1):

      # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
      pos = multiples.shape[0]-j-1

      c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , pos,\
                  &dirA[0], &expA[0], A.maxorder)

      # Get the mirrored multiple for vector X
      c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , j, \
                  &dirX[0], &expX[0], A.maxorder)
      
      # Get the equivalent index for A.
      indxA = h.findIndx(dirA, expA, A.maxorder)

      if dirX[0] == 0:

        indxX = 0

      else:

        # Get the equivalent index for X.
        indxX = h.findIndx(dirX, expX, A.maxorder)

      # end if 

      # Subtract A_indxA * x_indxX to the fi vector
      fi -= A[indxA].dot(x.data[:,indxX])


      # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
      # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
    # end for

    # TODO: Change according to all different solvers selected.

    x.data[:,i]  = A0.solve(fi.base)   # Solve factorized system


  # end for

  return x



#-----------------------------------------------------------------------------------------------------








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







#*****************************************************************************************************
cpdef ndarray solve(otimat A, ndarray b, solver = 0):
  """
  PURPOSE:  Solve a system Ax = b

  """
  #***************************************************************************************************

  
  cdef ndarray x = ndarray(shape = b.shape,  m = b.m, maxorder = b.maxorder ) 
  cdef uint64_t i, indxX, indxA, k
  cdef uint8_t  j , pos
  cdef uint8_t[:,::1] multiples
  cdef uint8_t[::1]  expArray
  cdef uint16_t[::1] dirArray
  cdef float64_t[:] fi, solvedX   # Holder for the solution  
  # cdef np.ndarray[float64_t, ndim=1] 
  cdef object K0, Kj, A0
  cdef uint16_t[::1] dirA = np.zeros(A.maxorder,dtype = np.uint16)
  cdef uint16_t[::1] dirX = np.zeros(A.maxorder,dtype = np.uint16)
  cdef uint8_t[::1] expA = np.zeros(A.maxorder,dtype = np.uint8)
  cdef uint8_t[::1] expX = np.zeros(A.maxorder,dtype = np.uint8)
  cdef uint8_t[::1] newExpA
  # Create a copy of A?
  # Change the type of sparse matrix to CSR
  A.tocsr()

  A0 = spr.linalg.splu(A[ZERO].tocsc())

  # TODO: Check dimensions of b, A to match.
  
  # TODO: Depending on the solver, one can factorize K0 once for all solutions.
  
  for i in range(A.ndir):
    

    fi = b.data[:,i]

    # Get direction and exponent arrays:
    expArray = h.getExpA(i,A.maxorder)
    dirArray = h.getDirA(i,A.maxorder)

    # get the multiples of the exponent array:
    multiples = compMultiples(expArray)

    # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
    
    # loop in all multiples
    for j in range(multiples.shape[0]-1):

      # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
      pos = multiples.shape[0]-j-1

      c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , pos,\
                  &dirA[0], &expA[0], A.maxorder)

      # Get the mirrored multiple for vector X
      c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , j, \
                  &dirX[0], &expX[0], A.maxorder)
      
      # Get the equivalent index for A.
      indxA = h.findIndx(dirA, expA, A.maxorder)

      if dirX[0] == 0:

        indxX = 0

      else:

        # Get the equivalent index for X.
        indxX = h.findIndx(dirX, expX, A.maxorder)

      # end if 

      # Subtract A_indxA * x_indxX to the fi vector
      fi -= A[indxA].dot(x.data[:,indxX])


      # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
      # string += 'x'+ str(getDirArray(indxX,A.maxorder))

      
    # end for

    # TODO: Change according to all different solvers selected.

    # print(string)
    
    solvedX = spr.linalg.spsolve( A[ZERO], fi )
    # x.data[:,i]  = A0.solve(fi)   # Solve factorized system

    for k in range(solvedX.size):

      x.data[k,i] = solvedX[k] 

    # end for

  # end for

  return x



#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef ndarray zeros(shape = None , uint8_t maxorder = 1 , uint16_t m = 1):
  """
  PURPOSE: Create a ndarray filled with zeros.

  """
  #***************************************************************************************************

  cdef tuple finalShape
  cdef ndarray res 
  cdef uint64_t i,j,k,l
  cdef float64_t value = 0.

  if type(shape) == int:
    
    finalShape = (shape,)

  else:
    
    finalShape = shape

  # end if 

  res = ndarray(shape = finalShape,  m = m, maxorder = maxorder ) 

  res.data[:]=value

  return res

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef ndarray ones(shape = None , uint8_t maxorder = 1 , uint16_t m = 1):
  """
  PURPOSE: Create a ndarray filled with ones in the real component.

  """
  #***************************************************************************************************

  cdef tuple finalShape
  cdef ndarray res 
  cdef uint64_t i,j,k,l
  cdef float64_t value = 1., zeroval = 0.

  if shape == None:
    raise ValueError("shape keyword must be defined.")
  if type(shape) == int:
    
    finalShape = (shape,)

  else:
    
    finalShape = shape

  # end if 

  res = ndarray(shape = finalShape,  m = m, maxorder = maxorder ) 
  res[:] = zeroval

  if len(res.shape) == 1:
    # 1D OTI array

    res.data[:,0] = value

  elif len(res.shape) == 2:
    # 2D OTI array
    
    res.data[:,0,0] = value    

  elif len(res.shape) == 3:
    # 3D OTI array

    res.data[:,0,0,0] = value

  # end if

  return res

#-----------------------------------------------------------------------------------------------------



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



#*****************************************************************************************************
cpdef uint8_t[:,::1] compMultiples(uint8_t[::1] expArray):
  """
  PURPOSE:  Compute the multiples of an exponent array.

  """
  #***************************************************************************************************
  

  cdef uint64_t maxiter = 1
  cdef uint64_t i 
  cdef uint8_t exp, k, passed
  cdef uint8_t[::1] multiple = np.zeros(expArray.size,dtype = np.uint8)
  cdef uint8_t[:,::1] multiples 

  for exp in expArray:
                
    maxiter *= exp+1 

  # end for

  
  multiples = np.zeros((maxiter,expArray.size),dtype = np.uint8)

  for i in range(1,maxiter):

    passed = 0
    k = 0

    while passed == 0:

      if (multiple[k]+1)>expArray[k]:

        multiple[k] = 0
        k += 1

      else:

        multiple[k] += 1
        passed = 1

      # end if
    
    # end while

    # print(np.array(multiple))

    for k in range(expArray.size):

      multiples[i,k] = multiple[k]

    # print(np.array(multiple))

  # end for 

  return multiples 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef uint8_t[::1] orderDirExpArray(uint16_t[::1] dirA,    uint8_t[::1]    multExpA ,\
                                      uint16_t[::1] newDirA):
  """
  PURPOSE:  Organize a Multiple exponent array into the standard of this library.

  """
  #***************************************************************************************************
  

  cdef uint8_t i
  cdef uint8_t j = 0 
  cdef uint8_t[::1] newExpA
  # cdef uint8_t exp, k, passed
  
  newDirA = np.zeros(dirA.size,dtype=np.uint16)
  newExpA = np.zeros(dirA.size,dtype=np.uint8)

  for i in range(dirA.size):

    if multExpA[i] != 0: # the exponent exist in the solution.
      
      newDirA[j] = dirA[i]
      newExpA[j] = multExpA[i]
      j += 1

    # end if

  # end for

  return newExpA
  

#-----------------------------------------------------------------------------------------------------




















#*****************************************************************************************************
def e_spr(dirArray):
  """
  PURPOSE:  To create a dual number with value 1 at the specified
            dual direction, in a human friendly manner.

  EXAMPLE:  >>> e(2)
            1.0 * e(2)
            
            >>> e([1,2])
            1.0 * e([1,2])
            
            >>> e([1,[2,3]])
            1.0 * e([1,[2,3]])
  """
  #***************************************************************************************************
  
  if type(dirArray)==int:
    
    return spr_otinum(np.array([dirArray],dtype=np.uint64),np.array([1.],dtype=np.float64),1)
    
  # end if
    
  tmp_dirA,tmp_expA = getDirExpA(dirArray)
  cdef uint8_t maxorder = np.sum(tmp_expA)
  cdef uint8_t i
  cdef uint64_t indx

  # create the real direction arrays:
  dirA = np.zeros(maxorder,dtype = np.uint16)
  expA = np.zeros(maxorder,dtype = np.uint8)
  
  for i in range(len(tmp_expA)):
    
    dirA[i] = tmp_dirA[i]
    expA[i] = tmp_expA[i]

  # end for 

  if dirArray[0] == 0:
      
    indx = 0

  elif maxorder == 1:

    indx = dirArray[0]

  else:

    h =  H[maxorder-1]
    indx = h.findIndx(dirA,expA)

  # end if
  
  return spr_otinum(np.array([indx],dtype=np.uint64),np.array([1.],dtype=np.float64),maxorder)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def e(dirArray,uint8_t maxorder = 1,uint16_t m = 0):
  """
  PURPOSE:  To create a dual number with value 1 at the specified
            dual direction, in a human friendly manner.

  EXAMPLE:  >>> e(2)
            1.0 * e(2)
            
            >>> e([1,2])
            1.0 * e([1,2])
            
            >>> e([1,[2,3]])
            1.0 * e([1,[2,3]])
  """
  #***************************************************************************************************
  

  cdef float64_t[::1] coefs
  cdef uint64_t indx
  cdef uint16_t[::1] dirA
  cdef uint8_t[::1]  expA

  if type(dirArray)==int:
    
    if m == 0:

      indx = h.getNels(dirArray, maxorder)

    else: 

      indx = h.getNels(m, maxorder)

    # end if 

    coefs = np.zeros(indx,dtype = np.float64)

    if maxorder == 1:

      indx = dirArray

    else:

      dirA = h.getUDirA(maxorder,n=1)
      expA = h.getUExpA(maxorder,n=1)
      dirA[ZERO] = dirArray
      expA[ZERO] = 1
      indx = h.findIndx(dirA,expA,maxorder)

    # end if 

    if indx < coefs.size:

      coefs[indx] = 1.0

    # end if

    
    return otinum(coefs, maxorder, exact = True)
    
  # end if
    
  tmp_dirA,tmp_expA = getDirExpA(dirArray)
  cdef uint8_t maxorderi = max(np.sum(tmp_expA),maxorder)
  cdef uint8_t i
  

  # create the real direction arrays:
  dirA = h.getUDirA(maxorderi,n=1)
  expA = h.getUExpA(maxorderi,n=1)
  
  cdef uint16_t m_max = max(tmp_dirA)
  indx = h.getNels(m_max, maxorderi)
  coefs = np.zeros(indx,dtype = np.float64)


  for i in range(len(tmp_expA)):
    
    dirA[i] = tmp_dirA[i]
    expA[i] = tmp_expA[i]

  # end for 

  for i in range(len(tmp_expA),maxorderi):
    dirA[i] = 0
    expA[i] = 0
  # end if 

  if dirArray[0] == 0:
      
    indx = 0

  elif maxorderi == 1:

    indx = dirArray[0]

  else:

    indx = h.findIndx(dirA,expA,maxorderi)

  # end if

  coefs[indx] = 1.0
  
  return otinum(coefs,maxorderi, exact = True)

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
def getDirArray(indx_i,maxorder):
  """
  PURPOSE:  Create a human readable version of the direction indx_i is representing.
  """
  #***************************************************************************************************
  k=0
  
  if indx_i == 0 :
    
    return []

  elif maxorder == 1:

    return[indx_i]

  # find the non-zero values of dirArray
  adir = np.array((H[maxorder-1]).getDirA(indx_i))
  aexp = np.array((H[maxorder-1]).getExpA(indx_i))

  nonZ = np.nonzero(adir)
  
  dirs = adir[nonZ]
  exps  = aexp[nonZ]
  
  
  dirArray = [0]*dirs.size

  for i in range(dirs.size):
    
       
    if exps[i]>1:
      
      # If the order is greater than zero, then the direction given
      # contains an exponent, therefore it should be organized by the
      # exponent as an array.
      dirArray[i] = [dirs[i],exps[i]]
      
    else:
      
      # If it does not contain an exponent, just add the direction.
      dirArray[i] = dirs[i]
      
    # end if
    
  # end for
  
  return dirArray
#-----------------------------------------------------------------------------------------------------




















#*****************************************************************************************************
cpdef uint64_t binarySearch( uint64_t[::1] indxArray, uint64_t indx):
  """
  PURPOSE:  Search across indxArray to find indx in it.
  """
  #***************************************************************************************************
  
  return c_binarySearchUI64( &indxArray[0], indx, indxArray.shape[0])

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def getDerivative(dualnum, dirArray):
  """
  PURPOSE:      to retrieve the n'th derivative according to the taylor 
                series expansion with OTI numbers.
              
  DESCRIPTION:  Simply given the  of derivatives with the 
                dirArray, the function multiplys the terms that require
                extra factors to get the desired derivatives.

  """
  #***************************************************************************************************

  return dualnum.getDeriv(dirArray)

#------------------------------------------------------------------------



























# #*****************************************************************************************************
# cpdef spr_otinum cos(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of cosine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************

#   # Compute all derivatives of the function 
#   # up to max order of the number.
  
#   cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
#   cdef uint8_t i
#   cdef uint8_t s = 0
#   cdef float64_t sign = 1
  
#   for i in range(val.maxorder+1):
      
#     # exact method
#     if s == 0:
        
#       derivs[i]=sign*np.cos(val[0])
        
#     else:
        
#       sign = sign * (-1)
#       derivs[i]=sign*np.sin(val[0])
    
#     # end if
    
#     s = (s+1)%2
      
#   # end for
  
#   return derivMultivFunc(derivs,val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum  sin(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of sine for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************

#   # Compute all derivatives of the function 
#   # up to max order of the number.
  
#   cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
#   cdef uint8_t i
#   cdef uint8_t s = 1
#   cdef float64_t sign = -1
  
#   for i in range(val.maxorder+1):
    
#     if s == 0:
        
#       derivs[i]=sign*np.cos(val[0])
        
#     else:
        
#       sign = sign * (-1)
#       derivs[i]=sign*np.sin(val[0])
    
#     # end if
    
#     s = (s+1)%2
     
#   # end for

  
#   return derivMultivFunc(derivs,val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum tan(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of tangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   return sin(val)*power(cos(val),-1)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum sec(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of secant for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   return 1.0/cos(val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum csc(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of cosecant for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   return 1.0/sin(val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum cosh(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   return 0.5*(exp(val)+exp(-val))
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum sinh(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   return 0.5*(exp(val)-exp(-val))
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum tanh(spr_otinum val):
#   """
#   PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   return sinh(val)/cosh(val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  spr_otinum log(spr_otinum val):
#   """
#   PURPOSE:  Natural logarithm for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************  
#   #Natural Logarithm
  
#   # Compute all derivatives of the function 
#   # up to max order of the number.
  
#   cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
#   cdef uint8_t i
  
#   cdef float64_t sign = -1
#   cdef float64_t factor = 1
      
#   for i in range(val.maxorder+1):
      
#     if i ==0:
        
#       derivs[i]=np.log(val[0])
        
#     else:
#       #factor = factor*i
        
#       derivs[i]=factor * (sign**(i+1))*(1.0/(val[0]**i))
#       factor = factor*i
    
#     # end if
      
#   # end for
  
#   return derivMultivFunc(derivs,val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum exp(spr_otinum val):
#   """
#   PURPOSE:  Exponential function for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #*************************************************************************************************** 
  
#   # create an array that contains the 
#   # Compute all derivatives of the function 
#   # up to max order of the number.
  
  

#   cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
#   cdef uint8_t i
      
#   for i in range(val.maxorder+1):
      
#     derivs[i]=np.exp(val[0])
      
#   # end for
  
#   # Compute all the derivatives 

#   return derivMultivFunc(derivs,val)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef spr_otinum power(spr_otinum val, float64_t exponent):
#   """
#   PURPOSE:  Power function for OTI numbers, for non integer exponents.
   
#   EXAMPLE:   
#   """
#   #*************************************************************************************************** 
  
#   cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
#   cdef float64_t power_i = exponent
#   cdef float64_t factor = 1.
#   cdef uint8_t i
  
#   for i in range(val.maxorder+1):
      
#     derivs[i]=factor*np.power(val[0],power_i)
#     factor = factor*power_i
    
#     if power_i == 0.0:
      
#       break

#     # end if
    
#     power_i -= 1.0 

#   # end for
  
#   # Compute all the derivatives 

#   return derivMultivFunc(derivs,val)
# #-----------------------------------------------------------------------------------------------------


























































#*****************************************************************************************************
cpdef otinum cos(otinum val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************

  # Compute all derivatives of the function 
  # up to max order of the number.
  
  cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
  cdef uint8_t i
  cdef uint8_t s = 0
  cdef float64_t sign = 1
  
  for i in range(val.maxorder+1):
      
    # exact method
    if s == 0:
        
      derivs[i]=sign*np.cos(val[0])
        
    else:
        
      sign = sign * (-1)
      derivs[i]=sign*np.sin(val[0])
    
    # end if
    
    s = (s+1)%2
      
  # end for
  
  return derivMultivFuncNonSpr(derivs,val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum  sin(otinum val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
   
  EXAMPLE:   
  """
  #***************************************************************************************************

  # Compute all derivatives of the function 
  # up to max order of the number.
  
  cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
  cdef uint8_t i
  cdef uint8_t s = 1
  cdef float64_t sign = -1
  
  for i in range(val.maxorder+1):
    
    if s == 0:
        
      derivs[i]=sign*np.cos(val[0])
        
    else:
        
      sign = sign * (-1)
      derivs[i]=sign*np.sin(val[0])
    
    # end if
    
    s = (s+1)%2
     
  # end for

  
  return derivMultivFuncNonSpr(derivs,val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum tan(otinum val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  return sin(val)*power(cos(val),-1)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum sec(otinum val):
  """
  PURPOSE:  Mathematical function of secant for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  return 1.0/cos(val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum csc(otinum val):
  """
  PURPOSE:  Mathematical function of cosecant for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  return 1.0/sin(val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum cosh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  return 0.5*(exp(val)+exp(-val))
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum sinh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  return 0.5*(exp(val)-exp(-val))
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum tanh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  return sinh(val)/cosh(val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum log(otinum val):
  """
  PURPOSE:  Natural logarithm for OTI numbers.
   
  EXAMPLE:   
  """
  #***************************************************************************************************  
  #Natural Logarithm
  
  # Compute all derivatives of the function 
  # up to max order of the number.
  
  cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
  cdef uint8_t i
  
  cdef float64_t sign = -1
  cdef float64_t factor = 1
      
  for i in range(val.maxorder+1):
      
    if i ==0:
        
      derivs[i]=np.log(val[0])
        
    else:
      #factor = factor*i
        
      derivs[i]=factor * (sign**(i+1))*(1.0/(val[0]**i))
      factor = factor*i
    
    # end if
      
  # end for
  
  return derivMultivFuncNonSpr(derivs,val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum exp(otinum val):
  """
  PURPOSE:  Exponential function for OTI numbers.
   
  EXAMPLE:   
  """
  #*************************************************************************************************** 
  
  # create an array that contains the 
  # Compute all derivatives of the function 
  # up to max order of the number.
  
  

  cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
  cdef uint8_t i
      
  for i in range(val.maxorder+1):
      
    derivs[i]=np.exp(val[0])
      
  # end for
  
  # Compute all the derivatives 

  return derivMultivFuncNonSpr(derivs,val)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef otinum power(otinum val, float64_t exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
   
  EXAMPLE:   
  """
  #*************************************************************************************************** 
  
  cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
  cdef float64_t power_i = exponent
  cdef float64_t factor = 1.
  cdef uint8_t i
  
  for i in range(val.maxorder+1):
      
    derivs[i]=factor*np.power(val[0],power_i)
    factor = factor*power_i
    
    if power_i == 0.0:
      
      break

    # end if
    
    power_i -= 1.0 

  # end for
  
  # Compute all the derivatives 

  return derivMultivFuncNonSpr(derivs,val)
#-----------------------------------------------------------------------------------------------------

















#*****************************************************************************************************
cpdef otinum power_Nspr(otinum val, float64_t exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
   
  EXAMPLE:   
  """
  #*************************************************************************************************** 
  
  cdef float64_t[::1] derivs = np.zeros(val.maxorder+1,dtype = np.float64)
  cdef float64_t power_i = exponent
  cdef float64_t factor = 1.
  cdef uint8_t i
  
  for i in range(val.maxorder+1):
      
    derivs[i] = factor*np.power(val[0],power_i)
    
    factor    = factor*power_i
    
    if power_i == 0.0:
      
      break

    # end if
    
    power_i -= 1.0 

  # end for

  # Compute all the derivatives 

  return derivMultivFuncNonSpr(derivs,val)
#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cdef otinum derivMultivFuncNonSpr(float64_t[::1] f_der, otinum val):
  """
  PURPOSE:  To differentiate a function f that depends on another function
            g which depends on several variables. 

            i.e. f( g(x1,...,xn) )

            g comes evaluated and it is represented by the OTI number 
            val.
  
  WARNING: This is a very rudimentary implementation. If you have time to
          contribute, this is a function that might be very crucial to 
          optimize.

  EXAMPLE:   
  """
  #***************************************************************************************************
  

  # Check if the input is a real number only.
  cdef uint64_t i = 0
  if (val.coefs.size == 1):

    return otinum(np.array([f_der[i]],dtype = np.float64),val.maxorder)

  # end if 
  
  cdef uint16_t nval = h.findMaxDir(val.coefs.size-1,val.maxorder)
  

  # maximum number of coefficients...
  cdef uint64_t max_i = h.getNels(nval,val.maxorder) # take out the real part
  

  # Create the arrays to define an spr_otinum.

  cdef float64_t[::1] resCoefs = np.empty(max_i,dtype = np.float64)

  #define the real component.
  resCoefs[ZERO] = f_der[ZERO]

  for i in range(1,max_i):
    
    if val.maxorder == 1:

      resCoefs[i] = val[i]*f_der[ONE]

    else:

      resCoefs[i] = FaaDiBrunoNonSpr(i,f_der,val)

    # end if 
    
  # end for

  return otinum(resCoefs,val.maxorder,exact = True)
#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cdef float64_t FaaDiBrunoNonSpr(uint64_t indx, float64_t[::1] f_der, otinum x):
  """
  PURPOSE:  To apply the Faa di bruno formula to find the coefficient
            that corresponds to a specific partial derivative of f.
  
  """
  #***************************************************************************************************
    
  # expand the deriv array into a single level array
  # expandArray(dirA,expA)
  
  cdef float64_t sum_ = 0.
  cdef float64_t mult 
  cdef uint16_t[::1] dirA  = h.getDirA(indx,x.maxorder)        # 
  cdef uint8_t[::1] expA   = h.getExpA(indx,x.maxorder)        # 
  cdef uint16_t[::1] dirA_ = h.getUDirA(x.maxorder,n=1)        # It is expensive to create arrays
  cdef uint8_t[::1] expA_  = h.getUExpA(x.maxorder,n=1)        # at each iteration. Consider 
  cdef uint8_t i, j, k, el, count, nsets ,index                # inputing the allocated arrays  
  cdef uint16_t seti
  cdef uint8_t order = np.sum(expA)
  cdef uint16_t[::1] expandedArray = h.getUDirA(x.maxorder,n=2)     
  cdef uint16_t[::1] mdir = h.getUDirA(x.maxorder,n=3)    
  cdef float64_t factor

  # Expand the directions according to the exponents
  expandArrayNspr(dirA,expA,expandedArray)

  
  # for part in partition.Partition( expandArray(dirA,expA) ):
  for i in range(psets.getNParts(order)):                      # Look up partition i

    mult = 1.

    nsets = 0

    # for subpart in part:
    for j in range(order):    # Subpart j

        seti = psets.getSet(order,i,j)  # get the j'th set of the partition i.

        if seti == 0:   # if partition is == 0 set is full of zeros, therefore avoid computation.

          continue

        # end if

        nsets += 1           # counts the number of sets in the partition.

        el = 0               # gets the element  at which 
        count = 0

        while seti != 0:     # values of the sets are stored in the bits of seti

          if seti & 1:

            mdir[count] = expandedArray[el]
            count+=1

          # end if 

          seti = (seti>>1)
          el += 1

        # end while

        # fill up the other values as zeros:

        for k in range(count,x.maxorder):

          mdir[k] = 0

        # end 

        collapseArray(mdir, dirA_, expA_ )


        index = h.findIndx(dirA_,expA_,x.maxorder)

        factor = 1.

        # print(expA_)

        for k in range(x.maxorder):
          
          if expA_[k] != 0:
            
            factor *= factorial(expA_[k])

          # end if 

        # end for


        mult *= x[index]*factor

    # end for

    sum_ +=  f_der[nsets]  *  mult
      
  # end for
  
  factor = 1.0

  for i in range(x.maxorder):
    
    if expA[i] != 0:
      
      factor *= factorial(expA[i])     # Check out if factorial is very inefficient...

    # end if
  
  # end for

  
  return sum_/factor
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************   
cdef expandArrayNspr(uint16_t[::1] dirA, uint8_t[::1] expA, uint16_t[::1] newarray ):
  """
  PURPOSE:  Expand a OTI number direction array, where the direction
            indicator is repeated the number of times the exponent 
            indicates. 

            * Useful for Faa di Bruno Formula.
   
  EXAMPLE:   
            >>> expandArray([[1,5]])
            [1,1,1,1,1]

            >>> expandArray([[1,2],2,[3,3]])
            [1,1,2,3,3,3]
  """
  #***************************************************************************************************
  
  cdef uint8_t order = np.sum(expA)
  # cdef uint16_t[::1] newarray = np.zeros(dirA.size,dtype = np.uint16)
  
  cdef uint8_t idir = 0
  cdef uint8_t count = 0
  cdef uint8_t i

  for i in range(order):
    
    newarray[i]=dirA[idir]

    #update counter
    count = count+1
    
    if count == expA[idir]:
    
      count = 0
      idir +=1
    
    # end if 

  # end for 

  #return newarray
#-----------------------------------------------------------------------------------------------------




























#*****************************************************************************************************
cdef spr_otinum derivMultivFunc(float64_t[::1] f_der, spr_otinum val):
  """
  PURPOSE:  To differentiate a function f that depends on another function
            g which depends on several variables. 

            i.e. f( g(x1,...,xn) )

            g comes evaluated and it is represented by the OTI number 
            val.
  
  WARNING: This is a very rudimentary implementation. If you have time to
          contribute, this is a function that might be very crucial to 
          optimize.

  EXAMPLE:   
  """
  #***************************************************************************************************
  

  # Check if the input is a real number only.

  if (val.indx.size==1) and (val.indx[0]==0):

    return spr_otinum(np.array([0],dtype=np.uint64),np.array([f_der[0]],dtype = np.float64),val.maxorder)

  # end if 
  
  # Get all directions of the current number

  # compute the maximum index for this.
  cdef uint16_t[::1] allDir = np.empty(val.indx.size*val.maxorder,dtype=np.uint16)
  cdef uint64_t i, k, j
  cdef uint16_t[::1] iDir
  
  for i in range(val.indx.size):
    
    iDir = val.h.getDirA(val.indx[i])


    j = i*val.maxorder
    # k = (i+1)*val.maxorder

    # add all directions to the main array:
    for k in range(val.maxorder):

      allDir[j+k] = iDir[k]

    # end for
  
  # all base directions should be here
  
  # VERY SLOW. THINK ABOUT MODIFYING THIS LINES
  allDir = np.unique(allDir)
  cdef uint16_t[::1] variables = np.array(allDir)[np.nonzero(allDir)]
  
  # For an 'efficient' implementation, the variables associated to the dual 
  # directions are mapped to an organized ascending set of variables, despite 
  # the variables can be handled easily like implemented.
  # This is, if the variables to compute derivatives are [1,10,20]
  # the mapped array is [1,2,3]
  cdef uint16_t n_var = variables.size
  

  # maximum number of coefficients...
  cdef uint64_t max_i = findComb(n_var+1,val.maxorder)-1 # take out the real part
  

  # Create the arrays to define an spr_otinum.

  cdef float64_t[::1] resCoefs = np.empty(max_i+1,dtype = np.float64)
  cdef uint64_t[::1]  resIndx = np.empty(max_i+1,dtype = np.uint64)
  cdef uint16_t[::1]  dirA
  cdef uint16_t[::1]  mdirA = np.empty(val.maxorder,dtype = np.uint16)
  cdef uint8_t[::1]   expA

  #define the real components.
  resIndx[0]  = 0
  resCoefs[0] = f_der[0]

  for i in range(1,max_i+1):
    
    # A more efficient implementation would know that if 
    # one of the values of val is not present, some FaaDiBruno
    # coefficients wont need to be computed. Therefore,
    # that might help to improve the performance of the algorithm.

    # get the direction array.
    dirA = val.h.getDirA(i)
    expA = val.h.getExpA(i)

    # map the directions.
    mapDirArray(dirA,variables,mdirA)
    
    
    # Define the new positions in the object
    resIndx[i] = val.h.findIndx(mdirA,expA)
    resCoefs[i] = FaaDiBruno(mdirA,expA,f_der,val)
    
  # end for

  return spr_otinum(resIndx,resCoefs,val.maxorder)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void mapDirArray(uint16_t[::1] dirA,uint16_t[::1]  mapder, uint16_t[::1] mdirA):
  """
  PURPOSE:  Map OTI number direction array with respect to a mapping 
            array.
   
  EXAMPLE:   
            >>> mapDirArray([[1,2],3,4],[2,10,15,18])
            [[2,2],15,18]

            >>> mapDirArray([1,2,3,[4,3],[6,10]],[10,11,12,13,14,15,16])
            [10,11,12,[13,3],[15,10]]
  """
  #***************************************************************************************************
  
  cdef uint8_t i

  for i in range(dirA.size):

    if dirA[i] != 0:
      
      mdirA[i] = mapder[dirA[i]-1]

    else:
      
      mdirA[i] = 0

    # end if 
      
  # end for

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef void collapseArray(uint16_t[::1] array, uint16_t[::1] dirA, uint8_t[::1] expA):
  """
  PURPOSE:  To collapse an expanded OTI number direction array into its 
            corresponding OTI direction array 
   
  EXAMPLE:   
            >>> collapseArray([1,1,1,1,1])
            [[1,5]]

            >>> collapseArray([1,1,2,3,3,3])
            [[1,2],2,[3,3]]
  """
  #***************************************************************************************************

  cdef uint16_t oldValue = array[0]
  cdef uint8_t  count = 0
  cdef uint8_t  iDir  = 0
  cdef uint8_t  i

  for i in range(array.size):

    if array[i] == 0:

      continue

    elif array[i] == oldValue:
      
      count += 1

    else:
      
      expA[iDir] = count
      dirA[iDir] = oldValue
      iDir += 1
      oldValue = array[i]
      count = 1

    # end if 

  # end for

  expA[iDir] = count
  dirA[iDir] = oldValue
  iDir += 1

  # Put zeros in all other values of the array, if it is the case:

  if iDir != dirA.size:
    
    for i in range(iDir,dirA.size):

      expA[i] = 0
      dirA[i] = 0

    # end for

  # end if 
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************   
cdef uint16_t[::1] expandArray(uint16_t[::1] dirA, uint8_t[::1] expA):
  """
  PURPOSE:  Expand a OTI number direction array, where the direction
            indicator is repeated the number of times the exponent 
            indicates. 

            * Useful for Faa di Bruno Formula.
   
  EXAMPLE:   
            >>> expandArray([[1,5]])
            [1,1,1,1,1]

            >>> expandArray([[1,2],2,[3,3]])
            [1,1,2,3,3,3]
  """
  #***************************************************************************************************
  
  cdef uint8_t order = np.sum(expA)
  cdef uint16_t[::1] newarray = np.zeros(dirA.size,dtype = np.uint16)
  
  cdef uint8_t idir = 0
  cdef uint8_t count = 0
  cdef uint8_t i

  for i in range(order):
    
    newarray[i]=dirA[idir]

    #update counter
    count = count+1
    
    if count == expA[idir]:
    
      count = 0
      idir +=1
    
    # end if 

  # end for 

  return newarray
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef float64_t FaaDiBruno(uint16_t[::1] dirA, uint8_t[::1] expA, float64_t[::1] f_der, spr_otinum x):
  """
  PURPOSE:  To apply the Faa di bruno formula to find the coefficient
            that corresponds to a specific partial derivative of f.
  
  """
  #***************************************************************************************************
    
  # expand the deriv array into a single level array
  # expandArray(dirA,expA)
  
  cdef float64_t sum_ = 0.
  cdef float64_t mult 
  cdef uint16_t[::1] dirA_ = np.empty(x.maxorder,dtype = np.uint16) # It is expensive to create arrays
  cdef uint8_t[::1] expA_ = np.empty(x.maxorder,dtype = np.uint8)   # at each iteration. Consider 
  cdef uint8_t i, j, el, count, nsets                               # inputing the allocated arrays  
  cdef uint16_t seti
  cdef uint8_t order = np.sum(expA)
  cdef uint16_t[::1] expandedArray = expandArray(dirA,expA)
  cdef uint16_t[::1] mdir = np.empty(x.maxorder,dtype = np.uint16)

   
  
  # for part in partition.Partition( expandArray(dirA,expA) ):
  for i in range(psets.getNParts(order)):                      # Look up partition i

    mult = 1.

    nsets = 0

    # for subpart in part:
    for j in range(order):    # Subpart j

        seti = psets.getSet(order,i,j)  # get the j'th set of the partition i.

        if seti == 0:   # if partition is == 0 set is full of zeros, therefore avoid computation.

          continue

        # end if

        nsets += 1           # counts the number of sets in the partition.

        el = 0               # gets the element  at which 
        count = 0

        while seti != 0:     # values of the sets are stored in the bits of seti

          if seti & 1:

            mdir[count] = expandedArray[el]
            count+=1

          # end if 

          seti = (seti>>1)
          el += 1

        # end while

        # fill up the other values as zeros:

        for k in range(count,x.maxorder):

          mdir[k] = 0

        # end 

        
        collapseArray(mdir, dirA_, expA_ )
        
        mult *= x.getDerivByDirExp(dirA_,expA_)
        
    # end for

    sum_ +=  f_der[nsets]  *  mult
      
  # end for
  
  cdef float64_t factor = 1.
  
  for i in range(expA.size):
    
    factor *= factorial(expA[i])
  
  # end for
  
  return sum_/factor
#-----------------------------------------------------------------------------------------------------








































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::      CLASS h_indx      :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 
cdef class h_indx:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef uint16_t[::1] __mmax         # Variable to hold the maximum number 
                                    # of base directions to load.
  
  cdef uint8_t __ord                # Maximum order of the numbers.
  cdef uint64_t N                   # number of rows in data.
   
  cdef uint16_t[:,::1] dirA         # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA         # All possible Exponents for each dir.

  cdef uint16_t[::1] mdirA1         # Temporal array.
  cdef uint16_t[::1] mdirA2         # Temporal array.
  cdef uint16_t[::1] mdirA3         # Temporal array.
  cdef uint8_t[::1]  mexpA1         # Temporal array.
  cdef uint16_t[::1] mapder         # Temporal array.

  cdef uint8_t merror               # value to hold multiplication errors

  cdef uint16_t[::1] zdirA          # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA          # Temporal array to return zeros.
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self,uint8_t order):
    """
    PURPOSE:     Initialize the h_indx for the specified order
     
    DESCRIPTION: This will create and allocate memory for all internal attributes
                 so that later on, accessing the dual directions is fast.   
              
    """
    #*************************************************************************************************

    self.__mmax = np.array([1000, 100, 100, 10, 10,
                               10, 10, 10, 10], dtype = np.uint16)
    self.__ord = order
    self.load()
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cdef void load(self):
    """
    PURPOSE:     To load the data related to a specified order. This will load the respective
                 direction and exponent arrays, and will also pre-load in memory supplementary
                 arrays.
     
    DESCRIPTION: Sets up the following variables:
            - dirA           - N              - mdirA2          - mexpA1         - zdirA           
            - expA           - mdirA1         - mdirA3          - mapder         - zexpA             
    """
    #*************************************************************************************************
    # Load and initialize all arrays related to order __ord.
         
    strlast = '_n'+str(self.__ord)+'_m'+str(self.__mmax[self.__ord-2])+'.npy'

    self.dirA = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.N = self.dirA.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1=np.empty(self.__ord,dtype = np.uint16)
    self.mdirA2=np.empty(self.__ord,dtype = np.uint16)
    self.mdirA3=np.empty(self.__ord,dtype = np.uint16)
    self.mexpA1=np.empty(self.__ord,dtype = np.uint8)
    self.mapder=np.empty(2*self.__ord,dtype = np.uint16)

    # TODO: Consider deprecating these arrays
    self.zdirA=np.zeros(self.__ord,dtype = np.uint16)
    self.zexpA=np.zeros(self.__ord,dtype = np.uint8)
    
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def findIndx(self, uint16_t[::1] dirA,  uint8_t[::1] expA):
    """
    PURPOSE:      Implements a binary search so that it can find the given pair (dirA,expA) in
                  (self.dirA,self.expA)
     
    DESCRIPTION:  The condition that this satisfies is that it will return i such that

                  >>> (self.dirA[i,:],self.expA[i,:]) == (dirA,expA)
                  True

    INPUTS:      
              - uint16_t[::1] dirA: Direction array with the basis of the direction to search.

              - uint8_t[::1]  expA: Exponent array with the exponents of the basis that 
                                    are present in the direction to search.

    OUTPUTS: 
              - uint64_t indx : position of the pair 

                        (dirA[:],expA[:]) in (self.dirA[:,:],self.expA[:,:])
              
    """
    #*************************************************************************************************
    cdef uint64_t indx
    
    indx =  c_binarySearch(&self.dirA[0,0],&self.expA[0,0],&dirA[0],\
                          &expA[0],self.__ord,self.N,&self.mdirA1[0],&self.mdirA2[0])+1
    return indx
  
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint64_t multIndx (self, uint64_t indx1,uint64_t indx2, uint8_t[:] error):
    """
    PURPOSE:     Function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error[0] = 0  -> Operation results in a viable direction.

                            error[0] = 1  -> Operation results in a not viable direction, and 
                                             indx should not be used. 
                                             e.g. the two directions result in a direction with 
                                             order greater than the maximum allowed order.
              
    """
    #*************************************************************************************************

    cdef uint64_t indx

    # Check first if the indx given are zero

    if (indx1 ==0 ):
      
      error[0] = 0
      return indx2

    elif(indx2 ==0):

      error[0] = 0
      return indx1

    # end if 

    indx = c_multDirections( &self.dirA[0,0], &self.expA[0,0], &self.dirA[indx1-1,0],  \
          &self.expA[indx1-1,0], &self.dirA[indx2-1,0],&self.expA[indx2-1,0],\
          &self.mdirA1[0], &self.mexpA1[0],  &self.mdirA2[0], &self.mdirA3[0],\
          &self.mapder[0], self.__ord, self.N, &error[0])

    return indx + 1

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint8_t[::1] getExpA(self, uint64_t indx):
    """
    PURPOSE:    Return the corresponding exponent array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] expA: Array containing the exponents of direction indx.
              
    """
    #*************************************************************************************************

    if indx != 0:
      
      return self.expA[indx-1,:]

    else:

      return self.zexpA

    # end if 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint16_t[::1] getDirA(self, uint64_t indx):
    """
    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************

    if indx != 0:
      
      return self.dirA[indx-1,:]

    else:

      return self.zdirA

    # end if 

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::   END OF CLASS h_indx   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::









# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::      CLASS partsets      ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 
cdef class partsets:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef uint16_t[:,::1] A1
  cdef uint16_t[:,::1] A2
  cdef uint16_t[:,::1] A3
  cdef uint16_t[:,::1] A4
  cdef uint16_t[:,::1] A5
  cdef uint16_t[:,::1] A6
  cdef uint16_t[:,::1] A7
  cdef uint16_t[:,::1] A8
  cdef uint16_t[:,::1] A9
  cdef uint16_t[:,::1] A10

  cdef uint64_t[:] nels
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self):
    """
    PURPOSE:    Initialize the class to handle pre-computed partition sets.  
              
    """
    #*************************************************************************************************
    
    self.nels = np.empty(10,dtype = np.uint64)

    self.A1  = np.load(PATH_TO_FILES+"data/part_n1.npy" )
    self.nels[0] = self.A1.shape[0]

    self.A2  = np.load(PATH_TO_FILES+"data/part_n2.npy" )
    self.nels[1] = self.A2.shape[0]   

    self.A3  = np.load(PATH_TO_FILES+"data/part_n3.npy" )
    self.nels[2] = self.A3.shape[0]  

    self.A4  = np.load(PATH_TO_FILES+"data/part_n4.npy" )
    self.nels[3] = self.A4.shape[0]  

    self.A5  = np.load(PATH_TO_FILES+"data/part_n5.npy" )
    self.nels[4] = self.A5.shape[0]  

    self.A6  = np.load(PATH_TO_FILES+"data/part_n6.npy" )
    self.nels[5] = self.A6.shape[0]  

    self.A7  = np.load(PATH_TO_FILES+"data/part_n7.npy" )
    self.nels[6] = self.A7.shape[0] 

    self.A8  = np.load(PATH_TO_FILES+"data/part_n8.npy" )
    self.nels[7] = self.A8.shape[0]  

    self.A9  = np.load(PATH_TO_FILES+"data/part_n9.npy" )
    self.nels[8] = self.A9.shape[0] 

    self.A10 = np.load(PATH_TO_FILES+"data/part_n10.npy")
    self.nels[9] = self.A10.shape[0]    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint64_t getNParts(self,uint8_t n):
    """
    PURPOSE:    Return the number of partition sets for the given size of set.
     
    INPUTS:      
              - uint8_t n: number of elements of the set.

    OUTPUTS:
              - uint64_t: number of partitions for a set of n elements.
              
    """
    #*************************************************************************************************
    
    return self.nels[n-1]

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint16_t getSet(self,uint8_t maxorder,uint64_t i,uint64_t j):
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

    if maxorder == 1:
      
      return self.A1[i,j]

    elif maxorder == 2:
      
      return self.A2[i,j]

    elif maxorder == 3:
      
      return self.A3[i,j]

    elif maxorder == 4:
      
      return self.A4[i,j]

    elif maxorder == 5:
      
      return self.A5[i,j]

    elif maxorder == 6:
      
      return self.A6[i,j]

    elif maxorder == 7:
      
      return self.A7[i,j]

    elif maxorder == 8:
      
      return self.A8[i,j]

    elif maxorder == 9:
      
      return self.A9[i,j]

    elif maxorder == 10:
      
      return self.A10[i,j]

    # end if 

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::   END OF CLASS partsets   ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


















# SHOULD BE MERGED WITH H_INDX !!!
#*****************************************************************************************************  
cdef class h_indx_1:
  
  
  def __cinit__(self):
    pass

  def findIndx(self, uint16_t[::1] dirA,  uint8_t[::1] expA):

    return np.uint64(dirA[0])


  def getExpA(self, uint64_t indx):

    return np.array([1],dtype = np.uint8)


  def getDirA(self, uint64_t indx):

    return np.array([indx],dtype = np.uint16)

#************************************************************************  








































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::      CLASS h_indx      :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: 
cdef class h_indx_new:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef uint16_t[::1] __mmax         # Variable to hold the maximum number 
                                    # of base directions to load.
  cdef uint8_t merror               # value to hold multiplication errors

  cdef uint64_t N_2                 # number of rows in data.
  cdef uint64_t N_3                 # number of rows in data.
  cdef uint64_t N_4                 # number of rows in data.
  cdef uint64_t N_5                 # number of rows in data.
  cdef uint64_t N_6                 # number of rows in data.
  cdef uint64_t N_7                 # number of rows in data.
  cdef uint64_t N_8                 # number of rows in data.
  cdef uint64_t N_9                 # number of rows in data.
  cdef uint64_t N_10                # number of rows in data.
   
  cdef uint16_t[::1] dirA_1         # All possible Direction combinations.
  cdef uint8_t[::1]  expA_1         # All possible Exponents for each dir.
  cdef uint16_t[::1] zdirA_1        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_1        # Temporal array to return zeros.
  cdef uint16_t[::1] udirA1_1       # User Temporal array.
  cdef uint16_t[::1] udirA2_1       # User Temporal array.
  cdef uint16_t[::1] udirA3_1       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_1       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_1       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_1       # User Temporal array.

  cdef uint16_t[:,::1] dirA_2       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_2       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_2      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_2      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_2       # Temporal array.
  cdef uint16_t[::1] mdirA2_2       # Temporal array.
  cdef uint16_t[::1] mdirA3_2       # Temporal array.
  cdef uint8_t[::1]  mexpA1_2       # Temporal array.
  cdef uint16_t[::1] mapder_2       # Temporal array.
  cdef uint16_t[::1] udirA1_2      # User Temporal array.
  cdef uint16_t[::1] udirA2_2      # User Temporal array.
  cdef uint16_t[::1] udirA3_2      # User Temporal array.
  cdef uint8_t[::1]  uexpA1_2      # User Temporal array.
  cdef uint8_t[::1]  uexpA2_2      # User Temporal array.
  cdef uint8_t[::1]  uexpA3_2      # User Temporal array.
  cdef uint16_t[::1] zdirA_2        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_2        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_2     # Array with the number of elements for 
                                    # each number of variables possible


  cdef uint16_t[:,::1] dirA_3       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_3       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_3      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_3      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_3       # Temporal array.
  cdef uint16_t[::1] mdirA2_3       # Temporal array.
  cdef uint16_t[::1] mdirA3_3       # Temporal array.
  cdef uint8_t[::1]  mexpA1_3       # Temporal array.
  cdef uint16_t[::1] mapder_3       # Temporal array.
  cdef uint16_t[::1] udirA1_3       # User Temporal array.
  cdef uint16_t[::1] udirA2_3       # User Temporal array.
  cdef uint16_t[::1] udirA3_3       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_3       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_3       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_3       # User Temporal array.
  cdef uint16_t[::1] zdirA_3        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_3        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_3     # Array with the number of elements for 
                                    # each number of variables possible
  

  cdef uint16_t[:,::1] dirA_4       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_4       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_4      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_4      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_4       # Temporal array.
  cdef uint16_t[::1] mdirA2_4       # Temporal array.
  cdef uint16_t[::1] mdirA3_4       # Temporal array.
  cdef uint8_t[::1]  mexpA1_4       # Temporal array.
  cdef uint16_t[::1] mapder_4       # Temporal array.
  cdef uint16_t[::1] udirA1_4       # User Temporal array.
  cdef uint16_t[::1] udirA2_4       # User Temporal array.
  cdef uint16_t[::1] udirA3_4       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_4       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_4       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_4       # User Temporal array.
  cdef uint16_t[::1] zdirA_4        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_4        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_4     # Array with the number of elements for 
                                    # each number of variables possible

  cdef uint16_t[:,::1] dirA_5       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_5       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_5      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_5      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_5       # Temporal array.
  cdef uint16_t[::1] mdirA2_5       # Temporal array.
  cdef uint16_t[::1] mdirA3_5       # Temporal array.
  cdef uint8_t[::1]  mexpA1_5       # Temporal array.
  cdef uint16_t[::1] mapder_5       # Temporal array.
  cdef uint16_t[::1] udirA1_5       # User Temporal array.
  cdef uint16_t[::1] udirA2_5       # User Temporal array.
  cdef uint16_t[::1] udirA3_5       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_5       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_5       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_5       # User Temporal array.
  cdef uint16_t[::1] zdirA_5        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_5        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_5     # Array with the number of elements for 
                                    # each number of variables possible

  cdef uint16_t[:,::1] dirA_6       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_6       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_6      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_6      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_6       # Temporal array.
  cdef uint16_t[::1] mdirA2_6       # Temporal array.
  cdef uint16_t[::1] mdirA3_6       # Temporal array.
  cdef uint8_t[::1]  mexpA1_6       # Temporal array.
  cdef uint16_t[::1] mapder_6       # Temporal array.
  cdef uint16_t[::1] udirA1_6       # User Temporal array.
  cdef uint16_t[::1] udirA2_6       # User Temporal array.
  cdef uint16_t[::1] udirA3_6       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_6       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_6       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_6       # User Temporal array.
  cdef uint16_t[::1] zdirA_6        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_6        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_6     # Array with the number of elements for 
                                    # each number of variables possible

  cdef uint16_t[:,::1] dirA_7       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_7       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_7      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_7      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_7       # Temporal array.
  cdef uint16_t[::1] mdirA2_7       # Temporal array.
  cdef uint16_t[::1] mdirA3_7       # Temporal array.
  cdef uint8_t[::1]  mexpA1_7       # Temporal array.
  cdef uint16_t[::1] mapder_7       # Temporal array.
  cdef uint16_t[::1] udirA1_7       # User Temporal array.
  cdef uint16_t[::1] udirA2_7       # User Temporal array.
  cdef uint16_t[::1] udirA3_7       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_7       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_7       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_7       # User Temporal array.
  cdef uint16_t[::1] zdirA_7        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_7        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_7     # Array with the number of elements for 
                                    # each number of variables possible

  cdef uint16_t[:,::1] dirA_8       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_8       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_8      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_8      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_8       # Temporal array.
  cdef uint16_t[::1] mdirA2_8       # Temporal array.
  cdef uint16_t[::1] mdirA3_8       # Temporal array.
  cdef uint8_t[::1]  mexpA1_8       # Temporal array.
  cdef uint16_t[::1] mapder_8       # Temporal array.
  cdef uint16_t[::1] udirA1_8       # User Temporal array.
  cdef uint16_t[::1] udirA2_8       # User Temporal array.
  cdef uint16_t[::1] udirA3_8       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_8       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_8       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_8       # User Temporal array.
  cdef uint16_t[::1] zdirA_8        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_8        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_8     # Array with the number of elements for 
                                    # each number of variables possible

  cdef uint16_t[:,::1] dirA_9       # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_9       # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_9      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_9      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_9       # Temporal array.
  cdef uint16_t[::1] mdirA2_9       # Temporal array.
  cdef uint16_t[::1] mdirA3_9       # Temporal array.
  cdef uint8_t[::1]  mexpA1_9       # Temporal array.
  cdef uint16_t[::1] mapder_9       # Temporal array.
  cdef uint16_t[::1] udirA1_9       # User Temporal array.
  cdef uint16_t[::1] udirA2_9       # User Temporal array.
  cdef uint16_t[::1] udirA3_9       # User Temporal array.
  cdef uint8_t[::1]  uexpA1_9       # User Temporal array.
  cdef uint8_t[::1]  uexpA2_9       # User Temporal array.
  cdef uint8_t[::1]  uexpA3_9       # User Temporal array.
  cdef uint16_t[::1] zdirA_9        # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_9        # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_9     # Array with the number of elements for 
                                    # each number of variables possible

  cdef uint16_t[:,::1] dirA_10      # All possible Direction combinations.
  cdef uint8_t[:,::1]  expA_10      # All possible Exponents for each dir.
  cdef uint16_t[::1]  rdirA_10      # Returning array efficiently.
  cdef uint8_t[::1]   rexpA_10      # Returning array efficiently.
  cdef uint16_t[::1] mdirA1_10      # Temporal array.
  cdef uint16_t[::1] mdirA2_10      # Temporal array.
  cdef uint16_t[::1] mdirA3_10      # Temporal array.
  cdef uint16_t[::1] udirA1_10      # User Temporal array.
  cdef uint16_t[::1] udirA2_10      # User Temporal array.
  cdef uint16_t[::1] udirA3_10      # User Temporal array.
  cdef uint8_t[::1]  uexpA1_10      # User Temporal array.
  cdef uint8_t[::1]  uexpA2_10      # User Temporal array.
  cdef uint8_t[::1]  uexpA3_10      # User Temporal array.
  cdef uint8_t[::1]  mexpA1_10      # Temporal array.
  cdef uint16_t[::1] mapder_10      # Temporal array.
  cdef uint16_t[::1] zdirA_10       # Temporal array to return zeros.
  cdef uint8_t[::1]  zexpA_10       # Temporal array to return zeros.
  cdef uint64_t[::1] countOTI_10    # Array with the number of elements for 
                                    # each number of variables possible
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self):
    """
    PURPOSE:     Initialize the h_indx for the specified This will load the respective
                 direction and exponent arrays, and will also pre-load in memory supplementary
                 arrays.
     
    DESCRIPTION: This will create and allocate memory for all internal attributes
                 so that later on, accessing the dual directions is fast. Sets up the
                 following variables:

            - dirA           - N              - mdirA2          - mexpA1         - zdirA           
            - expA           - mdirA1         - mdirA3          - mapder         - zexpA 
              
    """
    #*************************************************************************************************

    self.__mmax = np.array([1000, 100, 100, 10, 10,
                               10, 10, 10, 10], dtype = np.uint16)
    
    #  === === ORDER 1 === === 
    cdef uint8_t order = 1     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_1 = np.empty(order,dtype = np.uint16)
    self.expA_1 = np.empty(order,dtype = np.uint8)
    self.udirA1_1=np.empty(order,dtype = np.uint16)
    self.udirA2_1=np.empty(order,dtype = np.uint16)
    self.udirA3_1=np.empty(order,dtype = np.uint16)
    self.uexpA1_1=np.empty(order,dtype = np.uint8)
    self.uexpA2_1=np.empty(order,dtype = np.uint8)
    self.uexpA3_1=np.empty(order,dtype = np.uint8)
    
    # TODO: Consider deprecating these arrays
    self.zdirA_1 = np.zeros(order,dtype = np.uint16)
    self.zexpA_1 = np.zeros(order,dtype = np.uint8)


    #  === === ORDER 2 === ===     
    order = 2     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_2 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_2 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_2 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_2 = self.dirA_2.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_2=np.empty(order,dtype = np.uint16)
    self.mdirA2_2=np.empty(order,dtype = np.uint16)
    self.mdirA3_2=np.empty(order,dtype = np.uint16)
    self.mexpA1_2=np.empty(order,dtype = np.uint8)
    self.mapder_2=np.empty(2*order,dtype = np.uint16)
    self.udirA1_2=np.empty(order,dtype = np.uint16)
    self.udirA2_2=np.empty(order,dtype = np.uint16)
    self.udirA3_2=np.empty(order,dtype = np.uint16)
    self.rdirA_2=np.empty(order,dtype = np.uint16)
    self.uexpA1_2=np.empty(order,dtype = np.uint8)
    self.uexpA2_2=np.empty(order,dtype = np.uint8)
    self.uexpA3_2=np.empty(order,dtype = np.uint8)
    self.rexpA_2=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_2=np.zeros(order,dtype = np.uint16)
    self.zexpA_2=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 3 === === 
    order = 3     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_3 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_3 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_3 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_3 = self.dirA_3.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_3=np.empty(order,dtype = np.uint16)
    self.mdirA2_3=np.empty(order,dtype = np.uint16)
    self.mdirA3_3=np.empty(order,dtype = np.uint16)
    self.mexpA1_3=np.empty(order,dtype = np.uint8)
    self.mapder_3=np.empty(2*order,dtype = np.uint16)
    self.udirA1_3=np.empty(order,dtype = np.uint16)
    self.udirA2_3=np.empty(order,dtype = np.uint16)
    self.udirA3_3=np.empty(order,dtype = np.uint16)
    self.rdirA_3=np.empty(order,dtype = np.uint16)
    self.uexpA1_3=np.empty(order,dtype = np.uint8)
    self.uexpA2_3=np.empty(order,dtype = np.uint8)
    self.uexpA3_3=np.empty(order,dtype = np.uint8)
    self.rexpA_3=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_3=np.zeros(order,dtype = np.uint16)
    self.zexpA_3=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 4 === === 
    order = 4     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_4 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_4 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_4 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_4 = self.dirA_4.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_4=np.empty(order,dtype = np.uint16)
    self.mdirA2_4=np.empty(order,dtype = np.uint16)
    self.mdirA3_4=np.empty(order,dtype = np.uint16)
    self.mexpA1_4=np.empty(order,dtype = np.uint8)
    self.mapder_4=np.empty(2*order,dtype = np.uint16)

    self.udirA1_4=np.empty(order,dtype = np.uint16)
    self.udirA2_4=np.empty(order,dtype = np.uint16)
    self.udirA3_4=np.empty(order,dtype = np.uint16)
    self.rdirA_4=np.empty(order,dtype = np.uint16)
    self.uexpA1_4=np.empty(order,dtype = np.uint8)
    self.uexpA2_4=np.empty(order,dtype = np.uint8)
    self.uexpA3_4=np.empty(order,dtype = np.uint8)
    self.rexpA_4=np.empty(order,dtype = np.uint8)


    # TODO: Consider deprecating these arrays
    self.zdirA_4=np.zeros(order,dtype = np.uint16)
    self.zexpA_4=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 5 === === 
    order = 5     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_5 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_5 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_5 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_5 = self.dirA_5.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_5=np.empty(order,dtype = np.uint16)
    self.mdirA2_5=np.empty(order,dtype = np.uint16)
    self.mdirA3_5=np.empty(order,dtype = np.uint16)
    self.mexpA1_5=np.empty(order,dtype = np.uint8)
    self.mapder_5=np.empty(2*order,dtype = np.uint16)
    self.udirA1_5=np.empty(order,dtype = np.uint16)
    self.udirA2_5=np.empty(order,dtype = np.uint16)
    self.udirA3_5=np.empty(order,dtype = np.uint16)
    self.rdirA_5=np.empty(order,dtype = np.uint16)
    self.uexpA1_5=np.empty(order,dtype = np.uint8)
    self.uexpA2_5=np.empty(order,dtype = np.uint8)
    self.uexpA3_5=np.empty(order,dtype = np.uint8)
    self.rexpA_5=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_5=np.zeros(order,dtype = np.uint16)
    self.zexpA_5=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 6 === === 
    order = 6     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_6 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_6 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_6 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_6 = self.dirA_6.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_6=np.empty(order,dtype = np.uint16)
    self.mdirA2_6=np.empty(order,dtype = np.uint16)
    self.mdirA3_6=np.empty(order,dtype = np.uint16)
    self.mexpA1_6=np.empty(order,dtype = np.uint8)
    self.mapder_6=np.empty(2*order,dtype = np.uint16)
    self.udirA1_6=np.empty(order,dtype = np.uint16)
    self.udirA2_6=np.empty(order,dtype = np.uint16)
    self.udirA3_6=np.empty(order,dtype = np.uint16)
    self.rdirA_6=np.empty(order,dtype = np.uint16)
    self.uexpA1_6=np.empty(order,dtype = np.uint8)
    self.uexpA2_6=np.empty(order,dtype = np.uint8)
    self.uexpA3_6=np.empty(order,dtype = np.uint8)
    self.rexpA_6=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_6=np.zeros(order,dtype = np.uint16)
    self.zexpA_6=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 7 === === 
    order = 7     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_7 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_7 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_7 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_7 = self.dirA_7.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_7=np.empty(order,dtype = np.uint16)
    self.mdirA2_7=np.empty(order,dtype = np.uint16)
    self.mdirA3_7=np.empty(order,dtype = np.uint16)
    self.mexpA1_7=np.empty(order,dtype = np.uint8)
    self.mapder_7=np.empty(2*order,dtype = np.uint16)
    self.udirA1_7=np.empty(order,dtype = np.uint16)
    self.udirA2_7=np.empty(order,dtype = np.uint16)
    self.udirA3_7=np.empty(order,dtype = np.uint16)
    self.rdirA_7=np.empty(order,dtype = np.uint16)
    self.uexpA1_7=np.empty(order,dtype = np.uint8)
    self.uexpA2_7=np.empty(order,dtype = np.uint8)
    self.uexpA3_7=np.empty(order,dtype = np.uint8)
    self.rexpA_7=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_7=np.zeros(order,dtype = np.uint16)
    self.zexpA_7=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 9 === === 
    order = 8     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_8 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_8 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_8 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_8 = self.dirA_8.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_8=np.empty(order,dtype = np.uint16)
    self.mdirA2_8=np.empty(order,dtype = np.uint16)
    self.mdirA3_8=np.empty(order,dtype = np.uint16)
    self.mexpA1_8=np.empty(order,dtype = np.uint8)
    self.mapder_8=np.empty(2*order,dtype = np.uint16)
    self.udirA1_8=np.empty(order,dtype = np.uint16)
    self.udirA2_8=np.empty(order,dtype = np.uint16)
    self.udirA3_8=np.empty(order,dtype = np.uint16)
    self.rdirA_8=np.empty(order,dtype = np.uint16)
    self.uexpA1_8=np.empty(order,dtype = np.uint8)
    self.uexpA2_8=np.empty(order,dtype = np.uint8)
    self.uexpA3_8=np.empty(order,dtype = np.uint8)
    self.rexpA_8=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_8=np.zeros(order,dtype = np.uint16)
    self.zexpA_8=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 9 === === 
    order = 9     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_9 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_9 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_9 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_9 = self.dirA_9.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_9=np.empty(order,dtype = np.uint16)
    self.mdirA2_9=np.empty(order,dtype = np.uint16)
    self.mdirA3_9=np.empty(order,dtype = np.uint16)
    self.mexpA1_9=np.empty(order,dtype = np.uint8)
    self.mapder_9=np.empty(2*order,dtype = np.uint16)
    self.udirA1_9=np.empty(order,dtype = np.uint16)
    self.udirA2_9=np.empty(order,dtype = np.uint16)
    self.udirA3_9=np.empty(order,dtype = np.uint16)
    self.rdirA_9=np.empty(order,dtype = np.uint16)
    self.uexpA1_9=np.empty(order,dtype = np.uint8)
    self.uexpA2_9=np.empty(order,dtype = np.uint8)
    self.uexpA3_9=np.empty(order,dtype = np.uint8)
    self.rexpA_9=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_9=np.zeros(order,dtype = np.uint16)
    self.zexpA_9=np.zeros(order,dtype = np.uint8)


    #  === === ORDER 10 === === 
    order = 10     
    strlast = '_n'+str(order)+'_m'+str(self.__mmax[order-2])+'.npy'

    self.dirA_10 = np.load(PATH_TO_FILES+'data/dir'+strlast)
    self.expA_10 = np.load(PATH_TO_FILES+'data/exp'+strlast)
    self.countOTI_10 = np.load(PATH_TO_FILES+'data/count'+strlast)
    self.N_10 = self.dirA_10.shape[0]

    # Allocate memory for the "supplementary arrays"
    self.mdirA1_10=np.empty(order,dtype = np.uint16)
    self.mdirA2_10=np.empty(order,dtype = np.uint16)
    self.mdirA3_10=np.empty(order,dtype = np.uint16)
    self.mexpA1_10=np.empty(order,dtype = np.uint8)
    self.mapder_10=np.empty(2*order,dtype = np.uint16)
    self.udirA1_10=np.empty(order,dtype = np.uint16)
    self.udirA2_10=np.empty(order,dtype = np.uint16)
    self.udirA3_10=np.empty(order,dtype = np.uint16)
    self.rdirA_10=np.empty(order,dtype = np.uint16)
    self.uexpA1_10=np.empty(order,dtype = np.uint8)
    self.uexpA2_10=np.empty(order,dtype = np.uint8)
    self.uexpA3_10=np.empty(order,dtype = np.uint8)
    self.rexpA_10=np.empty(order,dtype = np.uint8)

    # TODO: Consider deprecating these arrays
    self.zdirA_10=np.zeros(order,dtype = np.uint16)
    self.zexpA_10=np.zeros(order,dtype = np.uint8)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint64_t findIndx(self, uint16_t[::1] dirA,  uint8_t[::1] expA, uint8_t maxorder):
    """
    PURPOSE:      Implements a binary search so that it can find the given pair (dirA,expA) in
                  (self.dirA,self.expA)
     
    DESCRIPTION:  The condition that this satisfies is that it will return i such that

                  >>> (self.dirA[i,:],self.expA[i,:]) == (dirA,expA)
                  True

    INPUTS:      
              - uint16_t[::1] dirA: Direction array with the basis of the direction to search.

              - uint8_t[::1]  expA: Exponent array with the exponents of the basis that 
                                    are present in the direction to search.

    OUTPUTS: 
              - uint64_t indx : position of the pair 

                        (dirA[:],expA[:]) in (self.dirA[:,:],self.expA[:,:])
              
    """
    #*************************************************************************************************
    cdef uint64_t indx = 0            # Initialized to avoid warnings from the compiler.

    if dirA[0] == 0: # Case  where dirA and expA are all zeros

      return indx
    
    if maxorder == 1:
      
      indx = np.uint64(dirA[0])

    elif maxorder == 2:
      
      indx =  c_binarySearch(&self.dirA_2[0,0],&self.expA_2[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_2,&self.mdirA1_2[0],&self.mdirA2_2[0])+1

    elif maxorder == 3:
      
      indx =  c_binarySearch(&self.dirA_3[0,0],&self.expA_3[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_3,&self.mdirA1_3[0],&self.mdirA2_3[0])+1

    elif maxorder == 4:
      
      indx =  c_binarySearch(&self.dirA_4[0,0],&self.expA_4[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_4,&self.mdirA1_4[0],&self.mdirA2_4[0])+1

    elif maxorder == 5:
      
      indx =  c_binarySearch(&self.dirA_5[0,0],&self.expA_5[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_5,&self.mdirA1_5[0],&self.mdirA2_5[0])+1

    elif maxorder == 6:
      
      indx =  c_binarySearch(&self.dirA_6[0,0],&self.expA_6[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_6,&self.mdirA1_6[0],&self.mdirA2_6[0])+1

    elif maxorder == 7:
      
      indx =  c_binarySearch(&self.dirA_7[0,0],&self.expA_7[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_7,&self.mdirA1_7[0],&self.mdirA2_7[0])+1

    elif maxorder == 8:
      
      indx =  c_binarySearch(&self.dirA_8[0,0],&self.expA_8[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_8,&self.mdirA1_8[0],&self.mdirA2_8[0])+1

    elif maxorder == 9:
      
      indx =  c_binarySearch(&self.dirA_9[0,0],&self.expA_9[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_9,&self.mdirA1_9[0],&self.mdirA2_9[0])+1

    elif maxorder == 10:
      
      indx =  c_binarySearch(&self.dirA_10[0,0],&self.expA_10[0,0],&dirA[0],\
                          &expA[0],maxorder,self.N_10,&self.mdirA1_10[0],&self.mdirA2_10[0])+1

    # end if 

    return indx
  
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint64_t multIndx (self, uint64_t indx1, uint64_t indx2, uint8_t maxorder, uint8_t[:] error):
    """
    PURPOSE:     Function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error[0] = 0  -> Operation results in a viable direction.

                            error[0] = 1  -> Operation results in a not viable direction, and 
                                             indx should not be used. 
                                             e.g. the two directions result in a direction with 
                                             order greater than the maximum allowed order.
              
    """
    #*************************************************************************************************

    cdef uint64_t indx = 0  # Initialize so that there are no warnings in the compiler.

    if maxorder == 1:
      
      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      else:

        error[0] = 1
        indx = 0             # To avoid warnings from compiler
        return indx

      # end if 

    elif maxorder == 2:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_2[0,0], &self.expA_2[0,0], &self.dirA_2[indx1-1,0],  \
            &self.expA_2[indx1-1,0], &self.dirA_2[indx2-1,0],&self.expA_2[indx2-1,0],\
            &self.mdirA1_2[0], &self.mexpA1_2[0],  &self.mdirA2_2[0], &self.mdirA3_2[0],\
            &self.mapder_2[0], maxorder, self.N_2, &error[0])

    elif maxorder == 3:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_3[0,0], &self.expA_3[0,0], &self.dirA_3[indx1-1,0],  \
            &self.expA_3[indx1-1,0], &self.dirA_3[indx2-1,0],&self.expA_3[indx2-1,0],\
            &self.mdirA1_3[0], &self.mexpA1_3[0],  &self.mdirA2_3[0], &self.mdirA3_3[0],\
            &self.mapder_3[0], maxorder, self.N_3, &error[0])

    elif maxorder == 4:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_4[0,0], &self.expA_4[0,0], &self.dirA_4[indx1-1,0],  \
            &self.expA_4[indx1-1,0], &self.dirA_4[indx2-1,0],&self.expA_4[indx2-1,0],\
            &self.mdirA1_4[0], &self.mexpA1_4[0],  &self.mdirA2_4[0], &self.mdirA3_4[0],\
            &self.mapder_4[0], maxorder, self.N_4, &error[0])

    elif maxorder == 5:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_5[0,0], &self.expA_5[0,0], &self.dirA_5[indx1-1,0],  \
            &self.expA_5[indx1-1,0], &self.dirA_5[indx2-1,0],&self.expA_5[indx2-1,0],\
            &self.mdirA1_5[0], &self.mexpA1_5[0],  &self.mdirA2_5[0], &self.mdirA3_5[0],\
            &self.mapder_5[0], maxorder, self.N_5, &error[0])

    elif maxorder == 6:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_6[0,0], &self.expA_6[0,0], &self.dirA_6[indx1-1,0],  \
            &self.expA_6[indx1-1,0], &self.dirA_6[indx2-1,0],&self.expA_6[indx2-1,0],\
            &self.mdirA1_6[0], &self.mexpA1_6[0],  &self.mdirA2_6[0], &self.mdirA3_6[0],\
            &self.mapder_6[0], maxorder, self.N_6, &error[0])

    elif maxorder == 7:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_7[0,0], &self.expA_7[0,0], &self.dirA_7[indx1-1,0],  \
            &self.expA_7[indx1-1,0], &self.dirA_7[indx2-1,0],&self.expA_7[indx2-1,0],\
            &self.mdirA1_7[0], &self.mexpA1_7[0],  &self.mdirA2_7[0], &self.mdirA3_7[0],\
            &self.mapder_7[0], maxorder, self.N_7, &error[0])

    elif maxorder == 8:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_8[0,0], &self.expA_8[0,0], &self.dirA_8[indx1-1,0],  \
            &self.expA_8[indx1-1,0], &self.dirA_8[indx2-1,0],&self.expA_8[indx2-1,0],\
            &self.mdirA1_8[0], &self.mexpA1_8[0],  &self.mdirA2_8[0], &self.mdirA3_8[0],\
            &self.mapder_8[0], maxorder, self.N_8, &error[0])

    elif maxorder == 9:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_9[0,0], &self.expA_9[0,0], &self.dirA_9[indx1-1,0],  \
            &self.expA_9[indx1-1,0], &self.dirA_9[indx2-1,0],&self.expA_9[indx2-1,0],\
            &self.mdirA1_9[0], &self.mexpA1_9[0],  &self.mdirA2_9[0], &self.mdirA3_9[0],\
            &self.mapder_9[0], maxorder, self.N_9, &error[0])

    elif maxorder == 10:
      
      # Check first if the given indxs are zero

      if (indx1 == 0 ):
        
        error[0] = 0
        return indx2

      elif(indx2 == 0):

        error[0] = 0
        return indx1

      # end if 

      indx = c_multDirections( &self.dirA_10[0,0], &self.expA_10[0,0], &self.dirA_10[indx1-1,0],  \
            &self.expA_10[indx1-1,0], &self.dirA_10[indx2-1,0],&self.expA_10[indx2-1,0],\
            &self.mdirA1_10[0], &self.mexpA1_10[0],  &self.mdirA2_10[0], &self.mdirA3_10[0],\
            &self.mapder_10[0], maxorder, self.N_10, &error[0])

    # end if 


    return indx + 1

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef uint8_t[::1] getExpA(self, uint64_t indx, uint8_t maxorder):
    """
    PURPOSE:    Return the corresponding exponent array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] expA: Array containing the exponents of direction indx.
              
    """
    #*************************************************************************************************

    cdef uint8_t i
    
    if maxorder == 1:
      
      if indx != 0:

        return self.expA_1

      else:

        return self.zexpA_1

      # end if 

    elif maxorder == 2:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_2[i] = self.expA_2[indx-1,i]

        # end for 
        
        return self.rexpA_2

      else:

        return self.zexpA_2

      # end if 

    elif maxorder == 3:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_3[i] = self.expA_3[indx-1,i]

        # end for 
        
        return self.expA_3[indx-1,:]

      else:

        return self.zexpA_3

      # end if 

    elif maxorder == 4:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_4[i] = self.expA_4[indx-1,i]

        # end for 
        
        return self.expA_4[indx-1,:]

      else:

        return self.zexpA_4

      # end if 

    elif maxorder == 5:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_5[i] = self.expA_5[indx-1,i]

        # end for 
        
        return self.expA_5[indx-1,:]

      else:

        return self.zexpA_5

      # end if 

    elif maxorder == 6:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_6[i] = self.expA_6[indx-1,i]

        # end for 
        
        return self.expA_6[indx-1,:]

      else:

        return self.zexpA_6

      # end if 

    elif maxorder == 7:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_7[i] = self.expA_7[indx-1,i]

        # end for 
        
        return self.expA_7[indx-1,:]

      else:

        return self.zexpA_7

      # end if 

    elif maxorder == 8:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_8[i] = self.expA_8[indx-1,i]

        # end for 
        
        return self.expA_8[indx-1,:]

      else:

        return self.zexpA_8

      # end if 

    elif maxorder == 9:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_9[i] = self.expA_9[indx-1,i]

        # end for 
        
        return self.expA_9[indx-1,:]

      else:

        return self.zexpA_9

      # end if 

    elif maxorder == 10:
      
      if indx != 0:

        for i in range(maxorder):

          self.rexpA_10[i] = self.expA_10[indx-1,i]

        # end for 
        
        return self.expA_10[indx-1,:]

      else:

        return self.zexpA_10

      # end if 

    # end if 

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef uint8_t[::1] getUExpA(self, uint8_t maxorder, uint8_t n = 1):
    """
    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************

    if maxorder == 1:
      
      if n == 1:

        return self.uexpA1_1

      elif n == 2:

        return self.uexpA2_1

      else:

        return self.uexpA3_1

      # end if 

    elif maxorder == 2:
    
      if n == 1:

        return self.uexpA1_2

      elif n == 2:

        return self.uexpA2_2
        
      else:

        return self.uexpA3_2

      # end if 
      

    elif maxorder == 3:
      
      if n == 1:

        return self.uexpA1_3

      elif n == 2:

        return self.uexpA2_3
        
      else:

        return self.uexpA3_3

      # end if 

    elif maxorder == 4:
      
      if n == 1:

        return self.uexpA1_4

      elif n == 2:

        return self.uexpA2_4
        
      else:

        return self.uexpA3_4

      # end if 

    elif maxorder == 5:
      
      if n == 1:

        return self.uexpA1_5

      elif n == 2:

        return self.uexpA2_5
        
      else:

        return self.uexpA3_5

      # end if 

    elif maxorder == 6:
      
      if n == 1:

        return self.uexpA1_6

      elif n == 2:

        return self.uexpA2_6
        
      else:

        return self.uexpA3_6

      # end if 

    elif maxorder == 7:
      
      if n == 1:

        return self.uexpA1_7

      elif n == 2:

        return self.uexpA2_7
        
      else:

        return self.uexpA3_7

      # end if 

    elif maxorder == 8:
      
      if n == 1:

        return self.uexpA1_8

      elif n == 2:

        return self.uexpA2_8
        
      else:

        return self.uexpA3_8

      # end if 

    elif maxorder == 9:
      
      if n == 1:

        return self.uexpA1_9

      elif n == 2:

        return self.uexpA2_9
        
      else:

        return self.uexpA3_9

      # end if 

    elif maxorder == 10:
      
      if n == 1:

        return self.uexpA1_10

      elif n == 2:

        return self.uexpA2_10
        
      else:

        return self.uexpA3_10

      # end if 

    # end if 
  
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef uint16_t[::1] getUDirA(self, uint8_t maxorder, uint8_t n = 1):
    """
    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************

    if maxorder == 1:
      
      if n == 1:

        return self.udirA1_1

      elif n == 2:

        return self.udirA2_1

      else:

        return self.udirA3_1

      # end if 

    elif maxorder == 2:

      if n == 1:

        return self.udirA1_2

      elif n == 2:

        return self.udirA2_2
        
      else:

        return self.udirA3_2

      # end if 
      

    elif maxorder == 3:
      
      if n == 1:

        return self.udirA1_3

      elif n == 2:

        return self.udirA2_3
        
      else:

        return self.udirA3_3

      # end if 

    elif maxorder == 4:
      
      if n == 1:

        return self.udirA1_4

      elif n == 2:

        return self.udirA2_4
        
      else:

        return self.udirA3_4

      # end if 

    elif maxorder == 5:
      
      if n == 1:

        return self.udirA1_5

      elif n == 2:

        return self.udirA2_5
        
      else:

        return self.udirA3_5

      # end if 

    elif maxorder == 6:
      
      if n == 1:

        return self.udirA1_6

      elif n == 2:

        return self.udirA2_6
        
      else:

        return self.udirA3_6

      # end if 

    elif maxorder == 7:
      
      if n == 1:

        return self.udirA1_7

      elif n == 2:

        return self.udirA2_7
        
      else:

        return self.udirA3_7

      # end if 

    elif maxorder == 8:
      
      if n == 1:

        return self.udirA1_8

      elif n == 2:

        return self.udirA2_8
        
      else:

        return self.udirA3_8

      # end if 

    elif maxorder == 9:
      
      if n == 1:

        return self.udirA1_9

      elif n == 2:

        return self.udirA2_9
        
      else:

        return self.udirA3_9

      # end if 

    elif maxorder == 10:
      
      if n == 1:

        return self.udirA1_10

      elif n == 2:

        return self.udirA2_10
        
      else:

        return self.udirA3_10

      # end if 

    # end if 
  
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef uint16_t[::1] getDirA(self, uint64_t indx, uint8_t maxorder):
    """
    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.
              
    """
    #*************************************************************************************************
    cdef uint8_t i
    if maxorder == 1:
      
      if indx != 0:

        self.dirA_1[0] = np.uint16(indx)
        return self.dirA_1

      else:

        return self.zdirA_1

      # end if 

    elif maxorder == 2:
      
      if indx != 0:        

        for i in range(maxorder):

          self.rdirA_2[i] = self.dirA_2[indx-1,i]

        # end for 

        return   self.rdirA_2

      else:

        return self.zdirA_2

      # end if 

    elif maxorder == 3:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_3[i] = self.dirA_3[indx-1,i]

        # end for 
        
        return self.rdirA_3

      else:

        return self.zdirA_3

      # end if 

    elif maxorder == 4:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_4[i] = self.dirA_4[indx-1,i]

        # end for 
        
        return self.rdirA_4

      else:

        return self.zdirA_4

      # end if 

    elif maxorder == 5:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_5[i] = self.dirA_5[indx-1,i]

        # end for 
        
        return self.rdirA_5

      else:

        return self.zdirA_5

      # end if 

    elif maxorder == 6:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_6[i] = self.dirA_6[indx-1,i]

        # end for 
        
        return self.rdirA_6

      else:

        return self.zdirA_6

      # end if 

    elif maxorder == 7:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_7[i] = self.dirA_7[indx-1,i]

        # end for 
        
        return self.rdirA_7

      else:

        return self.zdirA_7

      # end if 

    elif maxorder == 8:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_8[i] = self.dirA_8[indx-1,i]

        # end for 
        
        return self.rdirA_8

      else:

        return self.zdirA_8

      # end if 

    elif maxorder == 9:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_9[i] = self.dirA_9[indx-1,i]

        # end for 
        
        return self.rdirA_9

      else:

        return self.zdirA_9

      # end if 

    elif maxorder == 10:
      
      if indx != 0:

        for i in range(maxorder):

          self.rdirA_10[i] = self.dirA_10[indx-1,i]

        # end for 
        
        return self.rdirA_10

      else:

        return self.zdirA_10

      # end if 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uint64_t findMaxDir(self, uint64_t index, uint8_t maxorder):
    """
    PURPOSE:    Return the maximum direction of count.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint64_t The maximum basis of said direction.
              
    """
    #*************************************************************************************************

    cdef uint64_t res = 0  # Variable that has the maximum direction
    cdef uint64_t indx = index + 1

    if maxorder == 1:
      
      res = indx - 1

    elif maxorder == 2:
      
      res = c_binarySearchUI64(&self.countOTI_2[0],indx,self.countOTI_2.shape[0])

    elif maxorder == 3:
      
      res = c_binarySearchUI64(&self.countOTI_3[0],indx,self.countOTI_3.shape[0])
      
    elif maxorder == 4:
      
      res = c_binarySearchUI64(&self.countOTI_4[0],indx,self.countOTI_4.shape[0])
      
    elif maxorder == 5:
      
      res = c_binarySearchUI64(&self.countOTI_5[0],indx,self.countOTI_5.shape[0])
      
    elif maxorder == 6:
      
      res = c_binarySearchUI64(&self.countOTI_6[0],indx,self.countOTI_6.shape[0])

    elif maxorder == 7:
      
      res = c_binarySearchUI64(&self.countOTI_7[0],indx,self.countOTI_7.shape[0])

    elif maxorder == 8:
      
      res = c_binarySearchUI64(&self.countOTI_8[0],indx,self.countOTI_8.shape[0])

    elif maxorder == 9:
      
      res = c_binarySearchUI64(&self.countOTI_9[0],indx,self.countOTI_9.shape[0])

    elif maxorder == 10:
      
      res = c_binarySearchUI64(&self.countOTI_10[0],indx,self.countOTI_10.shape[0])

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uint64_t getNels(self, uint64_t m, uint8_t maxorder):
    """
    PURPOSE:    Return the number of total elements for m basis and maxorder.  
     
    INPUTS:      
              - uint64_t m: Number of directions.

    OUTPUTS:
              - uint64_t Number of elements.
              
    """
    #*************************************************************************************************

    cdef uint64_t res = 0  # Variable that has the maximum direction

    if maxorder == 1:
      
      res = m + 1

    elif maxorder == 2:
      
      res = self.countOTI_2[m] # TODO: Check when m > countOTI.size

    elif maxorder == 3:
      
      res = self.countOTI_3[m]
      
    elif maxorder == 4:
      
      res = self.countOTI_4[m]
      
    elif maxorder == 5:
      
      res = self.countOTI_5[m]
      
    elif maxorder == 6:
      
      res = self.countOTI_6[m]

    elif maxorder == 7:
      
      res = self.countOTI_7[m]

    elif maxorder == 8:
      
      res = self.countOTI_8[m]

    elif maxorder == 9:
      
      res = self.countOTI_9[m]

    elif maxorder == 10:
      
      res = self.countOTI_10[m]

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

    

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::   END OF CLASS h_indx   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::







