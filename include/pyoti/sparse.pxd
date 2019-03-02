
from c_otilib cimport *


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef sotinum_t num
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef sotinum create(sotinum_t* num, uint8_t FLAGS = *)
 
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: End of class spr_otinum :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



#*****************************************************************************************************
# cpdef sotinum scos(sotinum val)
# cpdef sotinum ssin(sotinum val)
# cpdef sotinum stan(sotinum val)
# cpdef sotinum satan(sotinum val)
# cpdef sotinum satan2(sotinum valx, sotinum valy)
# cpdef sotinum sacos(sotinum val)
# cpdef sotinum sasin(sotinum val)
# cpdef sotinum ssinh(sotinum val)
# cpdef sotinum sasinh(sotinum val)
# cpdef sotinum scosh(sotinum val)
# cpdef sotinum sacosh(sotinum val)
# cpdef sotinum stanh(sotinum val)
# cpdef sotinum satanh(sotinum val)
# cpdef sotinum slogb(sotinum val, int base)
# cpdef sotinum slog10(sotinum val)
# cpdef sotinum slog(sotinum val)
# cpdef sotinum sexp(sotinum val)
# cpdef sotinum spower(sotinum val, double exponent)
# cpdef sotinum ssqrt(sotinum val)
# cdef object c_soti_print(sotinum_t* num)
#*****************************************************************************************************






