






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::     CLASS  FESPACE    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fespace2:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, mesh mesh, elBase elType):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a class to relate the triangulation with interpolation functions defined by the
                  element type.

    INPUTS:

            -> mesh:     Mesh that defines the domain of the function.

            -> elementType:  Defines the interpolation functions of the discretized domain.

    """
    
    self.mesh       = mesh         # Reference to the mesh
    self.elType     = elType       # Reference to the element type.
    self.fespaceId  = self.mesh.addNewSpace(self) # Stack


    # TODO: How to add warning on how to require mesh and element type?
    
  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  cdef uint64_t addNewOperation(self):
    """
    PURPOSE:      Add a new Finite Element operation. 
                  Returns an Id of the operation

    """
    
    return self.mesh.addNewOperation()

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
  def newUndefinedFunction(self):
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

    if type(data) in number_types:

      data_conv = data + 0*se(1 ,order = self.mesh.otiorder )

    elif type(data) == sotinum or  type(data) == sndarray or type(data) == ndarray:
    
      data_conv = data

    elif type(data) == np.ndarray:

      data_conv = sarray(data,self.mesh.otiorder)

    else:

      raise ValueError("Can't create function from data type ",type(data) )

    # end if 



    res = fefunction(self, feNatDef, data = data_conv) 
    res.shape = [1,1]
    return res
  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::: END OF CLASS FESPACE2 ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






