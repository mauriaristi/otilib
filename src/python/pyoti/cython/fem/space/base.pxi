


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::     CLASS  SPACE    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class space: 

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self,  uint8_t order, special = 'std', reduced_integration = False):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a class to relate the mesh with interpolation functions defined by the
                  element type.

    INPUTS:

            -> order:   Defines the order of interpolation for the discretized domain.
            -> special: Defines special characteristics of the element.
                        - 'std' (default): Standard polynomial element.
                        - 'serendipity':   Serendipity iterpolation.
                        - 'bubble':        Bubble function interpolation.
            -> reduced_integration: Bool to set reduced integration. (default False).

    EXAMPLE:

        >>> Vh = pyoti.fem.space(2)  # This creates a FE space for a mesh Th of interpolation order=2.

    """
    
    # self.mesh       = in_mesh    # Reference to a mesh.
    self.order      = order      # Element order (polynomial order).
    self.special    = special    # Special element? Possible inputs are: 
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
    
    >>> Vh = pyoti.fem.space(2) # Creates an space with polynomial interpolation functions of order 2.

    >>> var = Vh()    # This creates an undefined variable that will become: test function or 
                      # solution of fem problem.

    >>> var = Vh(3.5) # This creates a defined constant function. This is useful in a FE analysis, 
                      # as you define it with a constant scalar value and then you change its value 
                      # without the need to re-define the problem.

    >>> var = Vh( sin(Th.x) ) # Creates a defined function. This is useful in a FE analysis, 
                              # as you can specify the appropriate interpolation functions and update
                              # the values of the function without the need to re-define the problem.

    """
    
    cdef object data_conv
    
    len_args = len(args)
    
    if len_args == 0:

      # print("Creating undefined function.")
      return __create_opDef__( baseSpace = self, basis = basisN, data = None)

    elif len_args == 1:

      # print("Creating defined function from space.")
      data = args[0]
      tdata = type(data)

      # if tdata in number_types:
      #   data_conv = alg.number(data)
      # elif tdata == sotinum or tdata == matso or tdata == dmat:
      #   data_conv = data
      # elif tdata == np.ndarray:
      #   data_conv = array( data )
      # else:
      #   raise ValueError("Unsupported type {0} in FE space call.".format(tdata))
      # # end if

      # Define a new function with the given data.
      return __create_opDef__( baseSpace =  self, basis = basisN, data = data)

    else:

      raise ValueError("Unsupported number of inputs in FE space call.")

    # end if
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __repr__(self):
    """
    PURPOSE:  Representation of the object. 

    """

    return self.tostr()
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:  String representation of the object. 

    """
    
    return self.tostr()
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef tostr(self):
    """
    PURPOSE:  String representation of the object. 

    """
    cdef str out = ""

    out += "<space object with \n"
    # out += "   Mesh: --------------- "+str(self.mesh) + "\n"
    out += "   Order: -------------- "+str(self.order) + "\n"
    out += "   Special: ------------ "+str(self.special) + "\n"
    out += "   Reduced Integration:  "+str(self.red_int!=0) + "\n"
    out += ">\n"

    return out
  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::: END OF CLASS SPACE   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::







