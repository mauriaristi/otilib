


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::     CLASS  FESPACE    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fespace:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, mesh mesh, uint8_t order, special = 'std'):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a class to relate the triangulation with interpolation functions defined by the
                  element type.

    INPUTS:

            -> mesh:    Mesh that defines the domain of the function.
            -> elOrder: Defines the interpolation functions of the discretized domain.

    """
    
    self.mesh       = mesh         # Reference to the mesh.
    self.order      = order        # Reference to the element order.
    self.special    = special      # Reference to element special.
    self.fespaceId  = self.mesh.addNewSpace(self) # Stack


    # TODO: How to add warning on how to require mesh and element type?
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def newTestFunction(self, kind = None):
    """
    PURPOSE:      Add a new Finite Element function. 
                  As such, it is added to the operation stack as a variable definition.

    """
    
    res = fefunction(self, feNatTest)

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  # def newUndefinedFunction(self):
  def newSolutionFunction(self):
    """
    PURPOSE:      Add a new Finite Element function that will be defined by solving a 
                  Finite element problem

    """
    
    res = fefunction(self, feNatUndef)

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def newFunction(self, object data):
    """
    PURPOSE:      Add a new Finite Element function that is defined in the space.

    """
    cdef object data_conv

    tdata = type(data)

    if tdata in number_types:

      data_conv = data + 0*e(1 , nbases = self.mesh.otinbases, order = self.mesh.otiorder )

    elif tdata == otinum or  tdata == omat or tdata == dmat:
    
      data_conv = data

    elif tdata == np.ndarray:

      data_conv = array( data )

    else:

      raise ValueError("Can't create function from data type ",type(data) )

    # end if 



    res = fefunction(self, feNatDef, data = data_conv) 
    res.shape = [1,1]
    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef uint64_t addNewOperation(self):
    """
    PURPOSE:      Add a new Finite Element operation. 
                  Returns an Id of the operation

    """
    
    return self.mesh.addNewOperation()

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::: END OF CLASS FESPACE :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






