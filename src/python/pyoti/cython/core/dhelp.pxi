













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
  def print_capabilities(self):
    """
    PURPOSE: Print capabilities of the direction helper.
    """
    import pandas as pd
    cdef np.ndarray[ uint64_t, ndim=2] data = np.zeros((self.dhl.ndh,3),dtype=np.uint64)

    for i in range(self.dhl.ndh):
      
      data[i,ZERO] = i+1
      data[i,ONE ] = self.dhl.p_dh[i].Nbasis
      data[i,TWO ] =  self.dhl.p_dh[i].Ndir

    # end for

    df = pd.DataFrame(data,columns=['Order', 'Nbases', 'Ndir'])
    with pd.option_context('display.max_rows', None, 'display.max_columns', None):
      print(df.to_string(index=False))

    # out = ""
    # out += "Current capabilities of the library: "+str(self.dhl.ndh)+" helpers:\n"
    # out += "Summary: Maximum order: "+str(self.dhl.ndh)+"\n"

    # # Loop over all direction helpers
    # for i in range(self.dhl.ndh):
      
    #   out += " -> order: {0:3d}, ".format(i+1)
    #   out += " - Max nbases: {0:8d}".format(int(self.dhl.p_dh[i].Nbasis))
    #   out += " - Ndir: {0:8d}".format(int(self.dhl.p_dh[i].Ndir))+"\n"

    # # end for
    # out = out[:-1]
    # print(out)
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def get_deriv_factor(self, imdir_t indx, ord_t order):

    return dhelp_get_deriv_factor( indx, order, self.dhl);

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def get_fulldir(self, imdir_t indx, ord_t order):
    """
    PURPOSE: Get the expanded representation of an imaginary direction as an array.
    """  
  
    cdef bases_t* dirs
    cdef np.ndarray out

    if order != 0:
           
      dirs = dhelp_get_imdir(indx,order,self.dhl)
      out = c_ptr_to_np_1darray_uint16(<void*> dirs, order, numpy_own = 0) 
    else:
    
      out = np.zeros(1,dtype = np.uint16)
    
    # end if 

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

  #***************************************************************************************************
  def get_ndir_total(self, bases_t nbases, ord_t order ):
    """
    PURPOSE: Return the total number of imaginary directions for the given number of
             basis and truncation order.

    @param[in] nbases: Number of imaginary basis
    @param[in] order:  Truncation order

    """  
    return dhelp_ndirTotal(nbases, order)
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def get_ndir_order(self, bases_t nbases, ord_t order ):
    """
    PURPOSE: Return the number of imaginary directions of given order for the number of
             basis given.

    @param[in] nbases: Number of imaginary basis.
    @param[in] order:  Order of imagianry direcitions.

    """  
    return dhelp_ndirOrder(nbases, order)
  #--------------------------------------------------------------------------------------------------- 

  def mult_dir(self,imdir_t indx1, ord_t ord1, imdir_t indx2, ord_t ord2):
    """
    PURPOSE: Multiply two imaginary directions.

    @param[in] indx1, ord1: Pair defining imaginary direction 1.
    @param[in] indx2, ord2: Pair defining imaginary direction 2.

    """  
    cdef imdir_t ixres
    cdef ord_t ores
    dhelp_multDir(indx1, ord1,indx2, ord2, &ixres, &ores, self.dhl)
    return [ixres,ores]
  #--------------------------------------------------------------------------------------------------- 
    
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::   END OF CLASS HELPER   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::












