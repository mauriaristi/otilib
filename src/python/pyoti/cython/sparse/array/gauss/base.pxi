


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  matsofe    :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class matsofe:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  
  def __init__(self, shape, uint64_t nip, ord_t order = 0, bases_t nbases = 0): 
    """
    PURPOSE:      Python level constructor of the matsofe class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t i,j
    cdef ord_t ordi

    #
    if (isinstance(shape, tuple)):

      ndim = len(shape)
            
      if( ndim == 1 ):
      
        self.arr = fearrso_zeros_bases(shape[0], 1, nip, nbases, order, dhl) 
      
      elif(ndim == 2):

        self.arr = fearrso_zeros_bases(shape[0], shape[1], nip, nbases, order, dhl) 

      else:

        raise ValueError("Cant create matsofe for dimensions greater than 2.")
      
      # end if   
       
    elif(isinstance(shape,int)):

      self.arr = fearrso_zeros_bases(shape, 1, nip, nbases, order, dhl)

    else:

      raise ValueError("Input should be either tuple or integer.")

    # end if 
    
    self.FLAGS = 1



  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if self.FLAGS == 1:
    
      fearrso_free(&self.arr)

    # end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nip(self): 
    """
    PURPOSE:     Return the number of integration points. 
    """
    #*************************************************************************************************

    return self.arr.nip

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return fearrso_get_order(&self.arr)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return (self.arr.nrows,self.arr.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef np.ndarray[coeff_t, ndim=1] tmp
    cdef uint64_t i, j, k
    cdef sotinum_t soti_tmp

    tmp = np.empty( (self.nrows,self.ncols,self.nip) , dtype = np.float64)

    for k in range(self.arr.nip):
      
      for i in range(self.arr.nrows):
        
        for j in range(self.arr.ncols):
          
          soti_tmp = fearrso_get_item_ijk(&self.arr, i,j,k,dhl);
          tmp[i,j,k] = soti_tmp.re
        
        # end for
      
      # end for
    
    # end for

    return tmp

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef matsofe create(fearrso_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef matsofe res = <matsofe> matsofe.__new__(matsofe)

    res.arr = arr[0]
    res.FLAGS = FLAGS

    return res

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    out =  "matsofe< "
    out += "nip: "+str(self.nip)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def long_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "matsofe< "
    out += "shape: "+str(self.shape)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def list_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef uint64_t i
    cdef matso tmp

    out =  "matsofe< "
    out += "nip: "+str(self.nip)+ ", \n"

    for i in range(self.nip):

      out += "(Integration point - {0:d}) \n".format(i)
      out += "-------------------------\n"
      
      tmp = self.get_ip( i )
      
      out += tmp.__str__()
      
      out += "\n"
      out += "-------------------------\n"
     
    # end for 

    out += ">"

    return out

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #*************************************************************************************************

    global dhl
  
    cdef sotinum_t d_soti
    cdef sotinum   soti

    out  = self.list_repr()

    return out

  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    global dhl
  
    cdef sotinum_t d_soti
    cdef sotinum   soti

    out  = self.list_repr()

    return out

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    # global dhl

    # cdef arrso_t res

    # if (isinstance(val, int)):
      
    #   res = fearrso_get_item_k( &self.arr, val, dhl)
    
    # else:
      
    #   return NotImplemented

    # # end if

    # return matso.create(&res)

















    global dhl

    cdef sotinum_t ores
    cdef fesoti_t  fres
    cdef arrso_t   Ores
    cdef fearrso_t Fres
    cdef object res = None
    cdef int64_t starti, stopi, stepi
    cdef int64_t startj, stopj, stepj

    tval = type(val)
    
    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        Fres = fearrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
        res  = matsofe.create(&Fres)

      else:

        raise IndexError("Index out of bounds.")

      # end if 

    #   ores = arrso_get_item_ij( &self.arr, val[0], val[1], dhl)
    #   res  = sotinum.create( &ores, FLAGS = 0 )

    elif tval == slice: #slice of multiple items
      
      # print(val)
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      # print("i: ( {0}, {1}, {2})".format(starti, stopi, stepi) )
      # print("j: ( {0}, {1}, {2})".format(startj, stopj, stepj) )

      Fres = fearrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
      res  = matsofe.create(&Fres)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if   tval0 == int and tval1 == int:
          
          # print("Case 1")
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            fres = fearrso_get_item_ij( &self.arr, val[0], val[1], dhl)
            res  = sotife.create( &fres )
          
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == int and tval1 == slice:

          # print("Case 2")
          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            Fres = fearrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
            res  = matsofe.create(&Fres)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == slice and tval1 == int:

          # print("Case 3")
          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            Fres = fearrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
            res  = matsofe.create(&Fres)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 


        elif tval0 == slice and tval1 == slice:

          # print("Case 3")
          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          Fres = fearrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
          res  = matsofe.create(&Fres) 

        else:

          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")

        # end if 

      else:

        raise IndexError("ERROR: Getting integration points by index is not yet supported.")

      # end if 

    else:

      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")

    # end if

    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, indices, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
        
    global dhl

    cdef sotinum oin
    cdef matso   Oin
    cdef matsofe Fin
    cdef sotife  fin
    
    tindices = type(indices)
    tvalue   = type(value)

    if tindices == int:
      raise IndexError("Slicing not yet implemented in matsofe class.")
    #   # This is a slice
    #   if val < self.arr.nrows:
        
    #     starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
    #     startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

    #     Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
    #     res  = matso.create(&Ores)

    #   else:

    #     raise IndexError("Index out of bounds.")

    #   # end if 

    # #   ores = arrso_get_item_ij( &self.arr, val[0], val[1], dhl)
    # #   res  = sotinum.create( &ores, FLAGS = 0 )

    # elif tval == slice: #slice of multiple items
      
    #   # print(val)
    #   # This is a slice
    #   starti, stopi, stepi = val.indices( self.arr.nrows )
    #   startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

    #   # print("i: ( {0}, {1}, {2})".format(starti, stopi, stepi) )
    #   # print("j: ( {0}, {1}, {2})".format(startj, stopj, stepj) )

    #   Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
    #   res  = matso.create(&Ores)
    
    elif tindices == tuple:
      
      if len(indices) == 2:

        tind0 = type(indices[0])
        tind1 = type(indices[1])

        if tind0 == int and tind1 == int:
          
          # print("Case 1")
          if indices[0] < self.arr.nrows and indices[1] < self.arr.ncols:
            
            if ( tvalue == sotinum ):

              oin = value
              fearrso_set_item_ij_o( &oin.num, indices[0], indices[1], &self.arr, dhl)

            elif ( tvalue == sotife ):
              
              fin = value
              fearrso_set_item_ij_f( &fin.num, indices[0], indices[1], &self.arr, dhl)

            elif ( tvalue in number_types ):

              fearrso_set_item_ij_r(    value, indices[0], indices[1], &self.arr, dhl)              

            else:

              raise ValueError("Cant assign an item as {0}.".format( tvalue ))
            # end if 
            
          else:

            raise IndexError("Index out of bounds for indices {0} and shape {1}.".format(indices,self.shape))

          # end if 

        # elif tval0 == int and tval1 == slice:

        #   # print("Case 2")
        #   if val[0] < self.arr.nrows:

        #     starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
        #     startj, stopj, stepj = val[1].indices( self.arr.ncols )

        #     Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
        #     res  = matso.create(&Ores)  

        #   else:

        #     raise IndexError("Index out of bounds.")

        #   # end if 

        # elif tval0 == slice and tval1 == int:

        #   # print("Case 3")
        #   if val[1] < self.arr.ncols:

        #     starti, stopi, stepi = val[0].indices( self.arr.nrows )
        #     startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

        #     Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
        #     res  = matso.create(&Ores)  

        #   else:

        #     raise IndexError("Index out of bounds.")

        #   # end if 


        # elif tval0 == slice and tval1 == slice:

        #   # print("Case 3")
        #   starti, stopi, stepi = val[0].indices( self.arr.nrows )
        #   startj, stopj, stepj = val[1].indices( self.arr.ncols )

        #   Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
        #   res  = matso.create(&Ores) 

        else:

          raise IndexError("ERROR: Integer indices ( i, j) or slices (`:`) are valid getters.")

        # end if 

      else:

        raise IndexError("ERROR: Only tuples of two integers are supported.")

      # end if 

    else:

      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")

    # end if


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE: Copy to a new object.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fearrso_t res = fearrso_copy(&self.arr, dhl)

    return matsofe.create(&res)
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fearrso_t res = fearrso_neg(&self.arr, dhl)

    return matsofe.create(&res)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fearrso_t res 
    cdef matsofe Flhs,Frhs
    cdef sotife  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef sotinum olhs,orhs
    cdef matso   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = fearrso_sum_FF(&Flhs.arr,&Frhs.arr,dhl)

    elif (tlhs == sotife): # fF

      flhs = self
      Frhs = other

      res = fearrso_sum_fF(&flhs.num,&Frhs.arr,dhl)

    elif (trhs == sotife): # Ff

      Flhs = self
      frhs = other

      res = fearrso_sum_fF(&frhs.num,&Flhs.arr,dhl)

    elif (tlhs == matso): # OF

      Olhs = self
      Frhs = other

      res = fearrso_sum_OF(&Olhs.arr,&Frhs.arr,dhl)

    elif (trhs == matso): # FO

      Flhs = self
      Orhs = other

      res = fearrso_sum_OF(&Orhs.arr,&Flhs.arr,dhl)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = fearrso_sum_RO(&Dlhs.arr,&Frhs.arr, dhl)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = fearrso_sum_RO(&Drhs.arr,&Flhs.arr, dhl)

    elif ( tlhs  == sotinum ): # oF

      olhs = self
      Frhs = other

      res = fearrso_sum_oF(&olhs.num,&Frhs.arr, dhl)

    elif ( trhs  == sotinum ): # oF

      Flhs = self
      orhs = other

      res = fearrso_sum_oF(&orhs.num,&Flhs.arr, dhl)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = fearrso_sum_rF(self, &Frhs.arr, dhl)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = fearrso_sum_rF(other, &Flhs.arr, dhl)

    else:

      return NotImplemented

    # end if 
      
    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(self, other):
    """
    PURPOSE: Inplace addition overload.
    """
    #*************************************************************************************************

    return self + other

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other):
    """
    PURPOSE: Subtraction overload.
    """
  #***************************************************************************************************
    
    global dhl
    
    cdef fearrso_t res 
    cdef matsofe Flhs,Frhs
    cdef sotife  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef sotinum olhs,orhs
    cdef matso   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = fearrso_sub_FF(&Flhs.arr,&Frhs.arr,dhl)

    elif (tlhs == sotife): # fF

      flhs = self
      Frhs = other

      res = fearrso_sub_fF(&flhs.num,&Frhs.arr,dhl)

    elif (trhs == sotife): # Ff

      Flhs = self
      frhs = other

      res = fearrso_sub_Ff(&Flhs.arr,&frhs.num,dhl)

    elif (tlhs == matso): # OF

      Olhs = self
      Frhs = other

      res = fearrso_sub_OF(&Olhs.arr,&Frhs.arr,dhl)

    elif (trhs == matso): # FO

      Flhs = self
      Orhs = other

      res = fearrso_sub_FO(&Flhs.arr,&Orhs.arr,dhl)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = fearrso_sub_RO(&Dlhs.arr,&Frhs.arr, dhl)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = fearrso_sub_OR(&Drhs.arr,&Flhs.arr, dhl)

    elif ( tlhs  == sotinum ): # oF

      olhs = self
      Frhs = other

      res = fearrso_sub_oF(&olhs.num,&Frhs.arr, dhl)

    elif ( trhs  == sotinum ): # Fo

      Flhs = self
      orhs = other

      res = fearrso_sub_Fo(&Flhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = fearrso_sub_rF(self, &Frhs.arr, dhl)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = fearrso_sub_Fr( &Flhs.arr, other, dhl)

    else:

      return NotImplemented

    # end if 
      
    return matsofe.create(&res)

  #-----------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE: Inplace subtraction overload.
    """
    #*************************************************************************************************
  
    return self - other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other):
    """ 
    PURPOSE: Multiplication overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fearrso_t res 
    cdef matsofe Flhs,Frhs
    cdef sotife  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef sotinum olhs,orhs
    cdef matso   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = fearrso_mul_FF(&Flhs.arr,&Frhs.arr,dhl)

    elif (tlhs == sotife): # fF

      flhs = self
      Frhs = other

      res = fearrso_mul_fF(&flhs.num,&Frhs.arr,dhl)

    elif (trhs == sotife): # Ff

      Flhs = self
      frhs = other

      res = fearrso_mul_fF(&frhs.num,&Flhs.arr,dhl)

    elif (tlhs == matso): # OF

      Olhs = self
      Frhs = other

      res = fearrso_mul_OF(&Olhs.arr,&Frhs.arr,dhl)

    elif (trhs == matso): # FO

      Flhs = self
      Orhs = other

      res = fearrso_mul_OF(&Orhs.arr,&Flhs.arr,dhl)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = fearrso_mul_RO(&Dlhs.arr,&Frhs.arr, dhl)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = fearrso_mul_RO(&Drhs.arr,&Flhs.arr, dhl)

    elif ( tlhs  == sotinum ): # oF

      olhs = self
      Frhs = other

      res = fearrso_mul_oF(&olhs.num,&Frhs.arr, dhl)

    elif ( trhs  == sotinum ): # oF

      Flhs = self
      orhs = other

      res = fearrso_mul_oF(&orhs.num,&Flhs.arr, dhl)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = fearrso_mul_rF(self, &Frhs.arr, dhl)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = fearrso_mul_rF(other, &Flhs.arr, dhl)

    else:

      return NotImplemented

    # end if 
      
    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE: Inplace multiplication overload.
    """
    #*************************************************************************************************

    return self * other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE: Division overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fearrso_t res 
    cdef matsofe Flhs,Frhs
    cdef sotife  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef sotinum olhs,orhs
    cdef matso   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = fearrso_div_FF(&Flhs.arr,&Frhs.arr,dhl)

    elif (tlhs == sotife): # fF

      flhs = self
      Frhs = other

      res = fearrso_div_fF(&flhs.num,&Frhs.arr,dhl)

    elif (trhs == sotife): # Ff

      Flhs = self
      frhs = other

      res = fearrso_div_Ff(&Flhs.arr,&frhs.num,dhl)

    elif (tlhs == matso): # OF

      Olhs = self
      Frhs = other

      res = fearrso_div_OF(&Olhs.arr,&Frhs.arr,dhl)

    elif (trhs == matso): # FO

      Flhs = self
      Orhs = other

      res = fearrso_div_FO(&Flhs.arr,&Orhs.arr,dhl)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = fearrso_div_RO(&Dlhs.arr,&Frhs.arr, dhl)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = fearrso_div_OR(&Drhs.arr,&Flhs.arr, dhl)

    elif ( tlhs  == sotinum ): # oF

      olhs = self
      Frhs = other

      res = fearrso_div_oF(&olhs.num,&Frhs.arr, dhl)

    elif ( trhs  == sotinum ): # Fo

      Flhs = self
      orhs = other

      res = fearrso_div_Fo(&Flhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = fearrso_div_rF(self, &Frhs.arr, dhl)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = fearrso_div_Fr( &Flhs.arr, other, dhl)

    else:

      return NotImplemented

    # end if 
      
    return matsofe.create(&res)

  #-----------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function overload

    res = self ** n

    """
    #*************************************************************************************************
    
    global dhl

    cdef fearrso_t res 
    cdef matsofe S = self

    res = fearrso_pow( &S.arr, n, dhl)
    
    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    global dhl

    cdef sotife  frhs
    cdef sotinum orhs
    cdef coeff_t rrhs

    cdef matsofe Frhs
    cdef matso   Orhs
    cdef dmat    Rrhs

    trhs = type(rhs)

    if   trhs is sotinum:

      orhs = rhs
      fearrso_set_o( &orhs.num, &self.arr, dhl)

    elif trhs is sotife:

      frhs = rhs
      fearrso_set_f( &frhs.num, &self.arr, dhl)      

    # elif trhs is matso:

    #   Orhs = rhs
    #   fearrso_set_O( &Orhs.arr, &self.arr, dhl)   

    # elif trhs is matsofe:

    #   Frhs = rhs
    #   fearrso_set_F( &Frhs.arr, &self.arr, dhl)   

    else:

      try:
      
        rrhs = rhs
        fearrso_set_r( rrhs, &self.arr, dhl)      
      
      except:
      
        raise ValueError("Supported values are real scalar, sotinum and sotife.")

      # end try

    # end if 

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def gauss_integrate(self, sotife w  ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef arrso_t res = arrso_init()

    res = fearrso_integrate( &self.arr, &w.num, dhl)

    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fearrso_t res
    
    indx, order = imdir(humdir)
    
    res = fearrso_truncate_im( indx, order, &self.arr, dhl) 

    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fearrso_t res
    
    indx, order = imdir(humdir)
    
    res = fearrso_extract_im( indx, order, &self.arr, dhl) 

    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fearrso_t res
    
    indx, order = imdir(humdir)
    
    res = fearrso_extract_deriv( indx, order, &self.arr, dhl) 

    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fearrso_t res
    
    indx, order = imdir(humdir)
    
    res = fearrso_get_im( indx, order, &self.arr, dhl) 

    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_ip( self, int64_t ip):
    """
    PURPOSE:      Get an Integration point.

    """
    #*************************************************************************************************
    global dhl

    cdef arrso_t res

    if (ip < 0):

      ip += self.nip

    # end if  

    if (ip > self.nip or ip < 0 ):

      raise IndexError("Index out of bounds for ip ({0:d}) and nip ({1:d}).".format(ip,self.nip))

    # end if

    res = fearrso_get_item_k( &self.arr, ip, dhl)
    
    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fearrso_t res
    
    indx, order = imdir(humdir)
    
    res = fearrso_get_deriv( indx, order, &self.arr, dhl) 

    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #*************************************************************************************************
    global dhl
    
    cdef fearrso_t res
    
    res = fearrso_get_order_im( order, &self.arr,  dhl)

    return matsofe.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """

    """
    global dhl

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    fearrso_get_active_bases( &self.arr, bases_list, dhl)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------
  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS matsofe ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
















