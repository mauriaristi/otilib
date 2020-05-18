




# Creation functions.




#*****************************************************************************************************
def e( hum_dir ,ord_t order = 0,bases_t nbases = 0):
  """
  PURPOSE:  To create an OTI number with value 1 at the specified
            direction, in a human friendly manner.

  """
  #***************************************************************************************************
  
  global dhl

  cdef imdir_t indx_hd
  cdef ord_t order_hd = 0
  cdef bases_t bases_hd = 0
  cdef otinum_t res


  # Get the index and order of the human direction.
  [indx_hd, order_hd] = imdir(hum_dir)
  
  # Get the number of bases from the hum_dir direction
  if order_hd !=0:
    bases_hd = (dhelp_get_imdir( indx_hd, order_hd, dhl))[order_hd-1]
  # end if 
  
  res = oti_createZero(max(bases_hd,nbases), max(order_hd,order), dhl)

  # Set the coefficient to 1.
  
  oti_setIm_IdxOrd(1.0,indx_hd,order_hd,&res,dhl)    

  return otinum.create(&res)

#-----------------------------------------------------------------------------------------------------

cpdef multiply_val(otinum a ):

  # return a*a*a*a*a
  return mul(mul(mul(mul(a,a),a),a),a)















#***************************************************************************************************
cpdef otinum add(otinum lhs, otinum rhs):
  """
  PURPOSE:      Add two OTI numbers.
                
  DESCRIPTION:  Eliminates the need to type check the input parameters 
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum, optional. Result holder
                
  """
  #*************************************************************************************************
  global dhl
  cdef otinum_t res  
  
  res = oti_sum_oo(&lhs.num, &rhs.num, dhl)

  return otinum.create(&res)

#---------------------------------------------------------------------------------------------------  


#***************************************************************************************************
cpdef add_to(otinum lhs, otinum rhs, otinum out):
  """
  PURPOSE:      Add two OTI numbers.
                
  DESCRIPTION:  Faster version to add two oti numbers to something already allocated.
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum, optional. Result holder
                
  """
  #*************************************************************************************************
  global dhl

  oti_sum_oo_to(&lhs.num, &rhs.num, &out.num ,dhl)


#---------------------------------------------------------------------------------------------------  







#***************************************************************************************************
cpdef otinum mul(otinum lhs, otinum rhs):
  """
  PURPOSE:      Add two OTI numbers.
                
  DESCRIPTION:  Faster version to add two oti numbers to something already allocated.
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                
                
  """
  #*************************************************************************************************
  global dhl

  cdef otinum_t res
  
  res = oti_mul_oo(&lhs.num, &rhs.num,dhl)

  return otinum.create(&res)

#---------------------------------------------------------------------------------------------------  



#***************************************************************************************************
cpdef mul_to(otinum lhs, otinum rhs, otinum res):
  """
  PURPOSE:      Multiply two OTI numbers.
                
  DESCRIPTION:  Faster version to multiply two oti numbers to something already allocated.
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum. Result holder
                
  """
  #*************************************************************************************************
  global dhl

  
  
  oti_mul_oo_to(&lhs.num, &rhs.num, &res.num, dhl)


#---------------------------------------------------------------------------------------------------  



#***************************************************************************************************
cpdef mulr_to(otinum lhs, coeff_t rhs, otinum res):
  """
  PURPOSE:      Multiply two OTI numbers.
                
  DESCRIPTION:  Faster version to multiply two oti numbers to something already allocated.
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum. Result holder
                
  """
  #*************************************************************************************************
  global dhl

  oti_mul_ro_to(rhs, &lhs.num,  &res.num, dhl)


#---------------------------------------------------------------------------------------------------  




#***************************************************************************************************
cpdef otinum sub(otinum lhs, otinum rhs):
  """
  PURPOSE:      subtract two OTI numbers.
                
  DESCRIPTION:  Eliminates the need to type check the input parameters 
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum, optional. Result holder
                
  """
  #*************************************************************************************************
  global dhl
  cdef otinum_t res
  # 
  res = oti_sub_oo(&lhs.num, &rhs.num, dhl)

  return otinum.create(&res)

#---------------------------------------------------------------------------------------------------  


#***************************************************************************************************
cpdef sub_to(otinum lhs, otinum rhs, otinum out):
  """
  PURPOSE:      subtract two OTI numbers.
                
  DESCRIPTION:  Faster version to operate two oti numbers to something already allocated.
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum. Result holder
                
  """
  #*************************************************************************************************
  global dhl

  oti_sub_oo_to(&lhs.num, &rhs.num, &out.num ,dhl)


#---------------------------------------------------------------------------------------------------  


