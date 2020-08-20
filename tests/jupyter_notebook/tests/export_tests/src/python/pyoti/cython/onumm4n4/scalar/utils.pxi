

# #*****************************************************************************************************
# def e( hum_dir ,ord_t order = 0, bases_t nbases = 0):
#   """
#   PURPOSE:  To create a onumm4n4_t with value 1 at the specified imaginary direction
#             in a human friendly manner

#   """
#   #***************************************************************************************************
  

#   

#   cdef imdir_t indx_hd
#   cdef ord_t order_hd
#   cdef bases_t bases_hd
#   cdef onumm4n4_t res
  
#   [indx_hd, order_hd] = imdir(hum_dir)

#   if order_hd <= order:

#     res = onumm4n4_createReal(0.0, order)

#     # Set the coefficient to 1.
#     onumm4n4_set_item(1.0, indx_hd, order_hd, &res)

#   else:

#     res = onumm4n4_createReal(0.0, order_hd)

#     # Set the coefficient to 1.
#     onumm4n4_set_item(1.0, indx_hd, order_hd, &res) 

#   return onumm4n4_t.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# def get_deriv(np.ndarray inarr, hum_dir):
#   """
#   PURPOSE:  Return the derivative selected from a numpy array of onumm4n4_ts.

#   """
#   #***************************************************************************************************

#   cdef uint64_t i,j,k,ZERO=0,ONE=1,TWO=2
#   cdef np.ndarray out = np.empty_like( inarr, dtype= np.float64 )
#   shape = inarr.shape

#   if inarr.ndim == 1:
#     for i in range(shape[ZERO]):
#       out[i] = inarr[i].get_deriv(hum_dir)
#     # end for 
#   elif inarr.ndim == 2:
#     for i in range(shape[ZERO]):
#       for j in range(shape[ONE]):
#         out[i,j] = inarr[i,j].get_deriv(hum_dir)
#       # end for 
#     # end for 
#   elif inarr.ndim == 3:
#     for i in range(shape[ZERO]):
#       for j in range(shape[ONE]):
#         for k in range(shape[TWO]):
#           out[i,j,k] = inarr[i,j,k].get_deriv(hum_dir)
#         # end for 
#       # end for 
#     # end for 
#   else:
#     raise IndexError("Cant handle arrays with more than 3 dimensions")
#   # end if 

#   return out

# #-----------------------------------------------------------------------------------------------------
