
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cimport numpy as np
from c_otilib cimport *             # OTI lib in C.

#-----------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otinum:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef otinum_t num             # Stores the number in a c-level fashion.
  cdef uint8_t FLAGS

  #---------------------------------------------------------------------------------------------------


  @staticmethod
  cdef otinum create(otinum_t* num, uint8_t FLAGS = *)
  cpdef copy(self)
  cpdef coeff_t get_deriv( self, hum_dir)

  # @staticmethod
  # def otinum add(otinum lhs, otinum rhs, otinum out = *)
  
  # @staticmethod
  # def otinum add_to(otinum lhs, otinum rhs, otinum out)
  # @staticmethod
  # cdef double getitem(self, uint64_t index)
  # cdef otinum neg(self)
  # cpdef otinum selfNeg(self)
  # cpdef void changeOrder(self,uint8_t neworder)
  # cdef double c_getDerivByDirExp( self, uint16_t* p_dirA, uint8_t* p_expA)
  # cpdef assignAll(self, float64_t value)
  # cpdef one(self)
  # cpdef null(self)
  # cpdef scale(self,float64_t value)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OMAT    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class omat:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef oarr_t arr             # Stores the number in a c-level fashion.
  cdef uint8_t FLAGS

  #---------------------------------------------------------------------------------------------------

  @staticmethod
  cdef omat create(oarr_t* arr, uint8_t FLAGS = *)
  cpdef copy(self)
  cpdef get_im(self, hum_dir, copy = *)
  cpdef get_imdir(self, imdir_t idx , ord_t order, copy = *)
  cpdef set_imdir(self,np.ndarray[coeff_t, ndim=2] arr, imdir_t idx , ord_t order)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OMAT :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  spr_omat   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class spr_omat:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public object          re    # Real Coefficient.
  cdef public np.ndarray    p_im    # Array of imaginary coefficients.
  cdef public np.ndarray  p_ndpo    # Number of imaginary directions per orde
  cdef public ndir_t        ndir    # Number of imaginary directions.
  cdef public bases_t     nbases    # Number of bases.
  cdef public ord_t        order    # Truncation order.
  cdef public uint64_t     nrows    # Number of rows of every array.
  cdef public uint64_t     ncols    # Number of columns of every array.
  cdef public uint64_t     size     # Total number of elements in per array.
  cdef public uint8_t      spr_type # Number that indicates the type of sparse 
                                                          # matrix. 
                                                          # 0: csr, 1: coo, 2: lil
  #---------------------------------------------------------------------------------------------------  

  cpdef object get_base_sprmat_creator(self)
  cdef set_and_sum_from_otinum_t(self, tuple index, otinum_t* num)
  cpdef set_from_otinum(self, index, otinum value)
  cpdef recompute_ndir(self)
  cpdef change_order(self, ord_t new_order)
  cpdef change_nbases(self,bases_t new_nbases)
  cpdef get_imdir(self, imdir_t idx , ord_t order)

  # cdef void c_setSumFromSotinum(self, list index, sotinum_t* value)
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class spr_omat :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




#-----------------------------------------------------------------------------------------------------
#-------------------------------------     OTHER FUNCTIONS     ---------------------------------------
#-----------------------------------------------------------------------------------------------------
# cpdef  otinum cos(otinum val)
# cpdef  otinum sin(otinum val)
# cpdef  otinum tan(otinum val)
# cpdef  otinum atan(otinum val)
# cpdef  otinum atan2(otinum valx, otinum valy)
# cpdef  otinum acos(otinum val)
# cpdef  otinum asin(otinum val)
# cpdef  otinum sinh(otinum val)
# cpdef  otinum asinh(otinum val)
# cpdef  otinum cosh(otinum val)
# cpdef  otinum acosh(otinum val)
# cpdef  otinum tanh(otinum val)
# cpdef  otinum atanh(otinum val)
# cpdef  otinum logb(otinum val, int base)
# cpdef  otinum log10(otinum val)
# cpdef  otinum log(otinum val)
# cpdef  otinum exp(otinum val)
# cpdef  otinum power(otinum val, double exponent)
# cpdef  otinum sqrt(otinum val)
#-----------------------------------------------------------------------------------------------------





# cpdef solve(omat A, omat b)

cpdef otinum add(otinum lhs, otinum rhs, otinum out = *)
cpdef add_to(otinum lhs, otinum rhs, otinum out)
















