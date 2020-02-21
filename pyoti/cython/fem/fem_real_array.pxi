



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::     CLASS  FEM_REAL_MATRIX    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class fem_real_matrix:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in fem.pxd    <---
  # cdef np.ndarray array    #
  # cdef uint64_t   nintpts  #
  # cdef tuple      shape    #

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __init__(self, shape, uint64_t n_int_points = 0): 
    """
    PURPOSE:      Python level constructor of the fem_real_matrix class. The porpuse of this class
                  is to provide a high level interface to an array used in the integration process
                  of a Finite Element calculation. In particular a FEM array is an "list of arrays"
                  where each element of the list correspond to an item related with the computations
                  of each integration point.

                  A = fem_real_matrix(n_int_points = 8)

                  Creates a list of 
                 
    """
    #*************************************************************************************************
    self.array = []

    # Check that the number of integration points is greater than 0.
    self.nintpts = n_int_points

    for i in range(self.nintpts):
    
      self.array.append( np.zeros(shape,dtype=np.float64) )
    
    # end for 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      String conversion of the class.

                  Returns lhs + rhs according to what input types are.
    """
    #*************************************************************************************************

    out = ""

    out += "<gaussian_real_matrix, shape: " , nint_points = "+str(self.nintpts)+" >\n"

    for i in range(self.nintpts):

      out += "Integration point "+str(i+1)+":\n"
      out += str(self.array[i]) + "\n"

    # end for

    return out
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __repr__(self):
    """
    PURPOSE:      String conversion of the class.

                  Returns lhs + rhs according to what input types are.
    """
    #*************************************************************************************************

    out = ""

    out += "<gaussian_real_matrix, n_int_points = "+str(self.nintpts)+" >\n"

    for i in range(self.nintpts):

      out += "Integration point "+str(i)+":\n"
      out += str(self.array[i]) + "\n"

    # end for

    return out
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, rhs):
    """
    PURPOSE:      Addition operation overload for the class.

                  Returns self + rhs according to what input types are.
    """
    #*************************************************************************************************

    res = fem_real_matrix(self.array[0].shape, self.nintpts)

    for i in range(self.nintpts):

      res.array[i] = self.array[i] + rhs.array[i]

    # end for

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __mul__(self, rhs):
    """
    PURPOSE:      Addition operation overload for the class.

                  Returns self + rhs according to what input types are.
    """
    #*************************************************************************************************

    t_self = type(self)
    t_rhs  = type(rhs)

    if t_self == t_rhs:

      res = fem_real_matrix(self.array[0].shape, self.nintpts)

      for i in range(self.nintpts):

        res.array[i] = self.array[i] * rhs.array[i]

      # end for

    elif t_rhs == np.ndarray:

      pass

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------


# def det(rhs):

#   t_rhs = type(rhs)

#   if t_rhs == np.ndarray