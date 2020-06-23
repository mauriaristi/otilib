


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::     CLASS  FESPACE    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class space:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, mesh in_mesh, uint8_t order, special = 'std', reduced_integration = False):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a class to relate the triangulation with interpolation functions defined by the
                  element type.

    INPUTS:

            -> mesh:    Mesh that defines the domain of the function.
            -> elOrder: Defines the interpolation functions of the discretized domain.

    """
    
    self.mesh       = in_mesh              # Reference to a mesh.
    self.order      = order                # Element order (polynomial order).
    self.special    = special              # Special element? Possible inputs are: 
                                           #   - 'std' (default),
                                           #   - 'bubble' (aliases: 'b')
                                           #   - 'serendipity' (aliases: 'serend', 's')

    self.red_int    = reduced_integration  # Reduced integration flag.

    # TODO: How to add warning on how to require mesh and element type?
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __call__(self, *args,**kwargs):
    """
    PURPOSE:  This is the call of a finite element space already created. 

    Possible calls:

    >>> Vh = pyoti.fem.space(Th,2)  # This creates a FE space for a mesh Th of interpolation order=2.

    >>> var = Vh()    # This creates an undefined variable that will become: test function or 
                      # solution of fem problem.

    >>> var = Vh(3.5) # This creates a defined variable. You can use this variable in a FE problem, 
                      # and change its value later without the need to re-define a problem.

    >>> var = Vh( sin(Th.x) ) # Creates a defined variable. You can use this variable in a FE problem.

    """
    
    cdef object data_conv
    
    len_args = len(args)
    
    if len_args == 0:

      return res = fefunction(self, feNatUndef)

    else:

      if len_args == 1:

        data = args[0]

        tdata = type(data)

        if is_fefunction_supported( tdata ):

          if tdata in number_types:
            data_conv = number(data)
          elif tdata == sotinum or tdata == matso or tdata == dmat:
            data_conv = data
          elif tdata == np.ndarray:
            data_conv = array( data )
          # end if

        else:
          raise ValueError("Unsupported type {0}  in FE space call.".format(tdata))
        # end if

      else:
        raise ValueError("Unsupported number of inputs in FE space call.")
      # end if
    
  #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def newTestFunction(self, kind = None):
  #   """
  #   PURPOSE:      Add a new Finite Element function. 
  #                 As such, it is added to the operation stack as a variable definition.

  #   """
    
  #   res = fefunction(self, feNatTest)

  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def newSolutionFunction(self):
  #   """
  #   PURPOSE:      Add a new Finite Element function that will be defined by solving a 
  #                 Finite element problem

  #   """
    
  #   res = fefunction(self, feNatUndef)

  #   return res
  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def newFunction(self, object data):
    """
    PURPOSE:      Add a new Finite Element function that is defined in the space.

    """
    cdef object data_conv

    tdata = type(data)

    if tdata in number_types:

      data_conv = number(data)

    elif tdata == sotinum or  tdata == matso or tdata == dmat:
    
      data_conv = data

    elif tdata == np.ndarray:

      data_conv = array( data )

    else:
      raise ValueError("Can't create function from data type ", type(data) )
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







