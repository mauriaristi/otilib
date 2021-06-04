



cdef uint64_t __varid_counter = 1
cdef uint64_t __opid_counter  = 1



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  elemental_operation    ::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elemental_operation:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  # def __init__(self, int64_t nature, space baseSpace=None, int64_t interpDer = basisN, \
  #              object data = None ):
  def __init__(self): 
    """
    PURPOSE:      Constructor of the elemental operation class. Its main purpose is to define 
                  a common parameter to store all the procedures and variables to be performed
                  during the Finite Element calculations.

    INPUTS:

          -> baseSpace: Finite element space that this function is associated.

          -> nature:    Nature of the operation. Can be:
                        * feNatUndef: For function with no known data. 
                        * feNatDef:   Defined, and has data already.

          -> interpDer: Basis function derivative to be used. Can be:
                        
                        * basisN

                        * basisNx
                        * basisNy
                        * basisNz

    """
    #*************************************************************************************************

    self.baseSpace  = None
    # self.interpDer = 0 
    self.nature     = feUndefined
    self.intorder   = 0
    
    self.op_id      = 0
    self.var_id     = 0
    
    self.data       = None

    self.op_graph   = np.zeros((0,4),dtype = object)
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def short_repr(self):
    """
    PURPOSE:      Return a short representation of the elemental_operations.
    """
    #*************************************************************************************************
    
    cdef str out = ""

    out += "op_id({0})".format(self.op_id)
    
    return out
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def tostr(self):
    """
    PURPOSE:      Return a human readable version of the elemental_operations.

    """
    #*************************************************************************************************
    
    cdef int i, noper = self.op_graph.shape[0]
    cdef str out = ""

    out += "<elemental_operation"
    out += " with {0} operations: \n".format(noper)

    for i in range(noper):    
      out += "{0:8^}, ".format(enum2string_2(self.op_graph[i,0]))
      
      lhs = self.op_graph[i,1]
      if lhs is not None:
        out += lhs.short_repr()+', '

      rhs = self.op_graph[i,2]
      if rhs is not None:
        out += rhs.short_repr()+', '
      # end if 

      res = self.op_graph[i,3]
      out +="result_op: {0}".format( res.short_repr() )

      out += "\n"

    # end for 

    out += ">"
    return out
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Return a human readable string of the class.

    """
    #*************************************************************************************************

    return self.tostr()

  #---------------------------------------------------------------------------------------------------

   #***************************************************************************************************      
  def __repr__(self):
    """
    PURPOSE:      Return a human readable string of the class.

    """
    #*************************************************************************************************
    
    return self.tostr()
  #---------------------------------------------------------------------------------------------------


  


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      Negation overload.

    """
    #*************************************************************************************************
    
    cdef elemental_operation res = __create_opNeg__(opNeg, self )
    
    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self,other):
    """
    PURPOSE:      Addition overload.

    """
    #*************************************************************************************************
    cdef elemental_operation res 
    cdef elemental_operation func1
    cdef elemental_operation func2
    
    type1 = type(self)
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class elemental_operation
      
      func1 = self
      func2 = other
      res   = __create_opElementwise__( opAdd, func1, func2)

    else:

      raise TypeError('Cannot operate {0} with {1}'.format(type1,type2))

    # end if 
            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __sub__(self,other):
    """
    PURPOSE:      Subtraction overload.

    """
    #*************************************************************************************************
    cdef elemental_operation res 
    cdef elemental_operation func1
    cdef elemental_operation func2
    
    type1 = type(self)
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class elemental_operation
      
      func1 = self
      func2 = other
      res   = __create_opElementwise__( opSub, func1, func2)

    else:

      raise TypeError('Cannot operate {0} with {1}'.format(type1,type2))

    # end if 
            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __mul__(self,other):
    """
    PURPOSE:      Multiplication overload.

    """
    #*************************************************************************************************
    cdef elemental_operation res 
    cdef elemental_operation func1
    cdef elemental_operation func2
    
    type1 = type(self)
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class elemental_operation
      
      func1 = self
      func2 = other
      res   = __create_opElementwise__( opMul, func1, func2)

    else:

      raise TypeError('Cannot operate {0} with {1}'.format(type1,type2))

    # end if 
            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __truediv__(self,other):
    """
    PURPOSE:      Division overload.

    """
    #*************************************************************************************************
    cdef elemental_operation res 
    cdef elemental_operation func1
    cdef elemental_operation func2
    
    type1 = type(self)
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class elemental_operation
      
      func1 = self
      func2 = other
      res   = __create_opElementwise__( opTruediv, func1, func2)

    else:

      raise TypeError('Cannot operate {0} with {1}'.format(type1,type2))

    # end if 
            

    return res
  #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def operK(self):
  #   return self.Koper
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def operf(self):
  #   return self.foper
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def operEssential(self):
  #   return self.essentialOper
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @staticmethod
  # cdef elemental_operation create(int64_t operId, elemental_operation lhs, elemental_operation rhs):
  #   """
  #   PURPOSE:  Create a new elemental operation from an operation Id and two functions


  #   INPUTS:  

  #     -> operId: Id of the operation. Operations can be:
  #       * Unary: Only one input, 'rhs' will be None.
  #         - opDef: Definition operation. 
  #         - opInt0d, opInt1d, opInt2d, opInt3d: Integral operations 
  #         - opDx, opDy, opDz, opDxx, opDxy, opDyy, opDxz, opDyz, opDzz, 

  #       * Binary: Two inputs are performed.
  #         - opAdd, opSub: Addition and subtraction operations.
  #         - opMul:        Multiplication operation. 
  #         - opTruediv:    Division operator.
  #         - opPowr:       Power function operator (e.g. x ** 2 ). 

  #     -> lhs: Left hand side operator.
  #     -> rhs: Right hand side operator.

  #   """
  #   #*************************************************************************************************
    
  #   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  #   cdef np.ndarray newOperation 
  #   res.interpDer  = basisN

    
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % %     MULTIPLICATION      % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   if operId == opMul:
      

  #     if func1.nature == feNatDef and func2.nature == feNatDef:
        
  #       # TODO: Operation between two defined functions that have
  #       #       different spaces should be performed as an operation
  #       #       to be done later rather than an operation inplace.

  #       # Perform the operation
  #       res = func1.baseSpace.newFunction(func1.data*func2.data)
        
  #       res.intorder = func1.intorder + func2.intorder

  #       return res

  #     # end if 

  #     # The base space is that of the greatest  order
  #     if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
  #       res.baseSpace = func1.baseSpace
  #     else:
  #       res.baseSpace = func2.baseSpace
  #     # end if 

  #     res.intorder = func1.intorder + func2.intorder
  #     res.funcid   = res.baseSpace.addNewOperation()

  #     res.baseFunc = func1.baseFunc.copy()

  #     # Add only unique base functions, i.e., do not duplicate.
  #     for base in func2.baseFunc:
  #       if base not in res.baseFunc:
  #         res.baseFunc.append(base)
  #       # end if 
  #     # end for 

  #     # Add itself to the list of baseFunctions
  #     res.baseFunc.append(res)

  #     # Organize the operation matrix

  #     # case 1: test * undef funct
  #     if func1.nature == feNatTest and func2.nature == feNatUndef:

  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper,axis=0)
  #       res.Koper = np.append(res.Koper,\
  #                            [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)
  #       res.foper = np.array([],dtype=np.uint64)
        
  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatOperRes
  #       res.shape =    [func1.shape[0],func2.shape[1]]
  #       res.shapeBounds = [[],[],[]]
        
  #       for i in range(3):
  #         if len(func1.shapeBounds[i])!=0:
  #           res.shapeBounds[i] = [func1.shapeBounds[i][0],func2.shapeBounds[i][1]]
  #         # end if 
  #       # end for 
        
  #       res.position = [func1.position[0],func2.position[0]]

  #     # case 2: undef funct * test
  #     elif func1.nature == feNatUndef and func2.nature == feNatTest:

  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        
  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper,\
  #                            [[operId,res.funcid,func2.funcid,func1.funcid]],\
  #                             axis = 0)

  #       # initialize the other two operation matrices as void.
  #       res.foper = np.array([],dtype=np.int64)
        
  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func2.funcid,func1.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatOperRes
  #       res.shape    = [func2.shape[0],    func1.shape[1] ]
  #       res.shapeBounds = [[],[],[]]
        
  #       for i in range(3):
  #         if len(func1.shapeBounds[i])!=0:
  #           res.shapeBounds[i] = [func2.shapeBounds[i][0],func1.shapeBounds[i][1]]
  #         # end if 
  #       # end for 

  #       res.position = [func2.position[0],func1.position[0]]


  #     # case 3: def funct * test
  #     elif func1.nature == feNatTest and func2.nature == feNatDef:
        
  #       # append both operation matrices
  #       res.foper = func1.foper.copy()
  #       res.foper = np.append(res.foper,func2.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatTest
  #       res.shape = func1.shape.copy()
  #       res.shapeBounds = func1.shapeBounds.copy()
  #       res.position = func1.position.copy()

  #     # case 4: def funct * test
  #     elif func1.nature == feNatDef and func2.nature == feNatTest:

  #       # append both operation matrices
  #       res.foper = func2.foper.copy()
  #       res.foper = np.append(res.foper,func1.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func2.funcid,func1.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatTest
  #       res.shape = func2.shape.copy()
  #       res.shapeBounds = func2.shapeBounds.copy()
  #       res.position = func2.position.copy()


  #     # case 5: Undef * def funct
  #     elif func1.nature == feNatUndef and func2.nature == feNatDef:
        
  #       # append both operation matrices
  #       res.foper = func1.foper.copy()
  #       res.foper = np.append(res.foper,func2.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatUndef
  #       res.shape = func1.shape.copy()
  #       res.shapeBounds = func1.shapeBounds.copy()
  #       res.position = func1.position.copy()

  #     # case 6: def funct * Undef
  #     elif func1.nature == feNatDef and func2.nature == feNatUndef:

  #       # append both operation matrices
  #       res.foper = func2.foper.copy()
  #       res.foper = np.append(res.foper,func1.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func2.funcid,func1.funcid]],\
  #                             axis = 0)
  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatUndef
  #       res.shape = func2.shape.copy()
  #       res.shapeBounds = func2.shapeBounds.copy()
  #       res.position = func2.position.copy()


  #     # case 5: Undef * def funct
  #     elif func1.nature == feNatOperRes and func2.nature == feNatDef:
        
  #       # append both operation matrices
  #       res.foper = func1.foper.copy()
  #       res.foper = np.append(res.foper,func2.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)


  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatOperRes
  #       res.shape = func1.shape.copy()
  #       res.shapeBounds = func1.shapeBounds.copy()
  #       res.position = func1.position.copy()

  #     # case 6: def funct * Undef
  #     elif func1.nature == feNatDef and func2.nature == feNatOperRes:

  #       # append both operation matrices
  #       res.foper = func2.foper.copy()
  #       res.foper = np.append(res.foper,func1.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func2.funcid,func1.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # append both operation matrices
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatOperRes
  #       res.shape = func2.shape.copy()
  #       res.shapeBounds = func2.shapeBounds.copy()
  #       res.position = func2.position.copy()

  #     else:

  #       raise ValueError("Can't operate the functions.")

  #     # end if 


  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % %   ADDITION / SUBTRACTION  % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   elif operId == opAdd or operId == opSub:   # Addition

  #     # If both are defined.
  #     if func1.nature == feNatDef and func2.nature == feNatDef:
        
  #       # Perform the operation
  #       if operId == opAdd:
  #         res = func1.baseSpace.newFunction(func1.data+func2.data)
  #       else:
  #         res = func1.baseSpace.newFunction(func1.data-func2.data)
  #       # end if 

  #       res.intorder = max(func1.intorder , func2.intorder)

  #       return res

  #     # end if 

  #     # The base space is that of the greatest order
  #     if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
  #       res.baseSpace = func1.baseSpace
  #     else:
  #       res.baseSpace = func2.baseSpace
  #     # end if 

  #     res.intorder = max(func1.intorder,func2.intorder)
  #     res.funcid   = res.baseSpace.addNewOperation()

  #     res.baseFunc = func1.baseFunc.copy()

  #     # Add only unique base functions, i.e., do not duplicate.
  #     for base in func2.baseFunc:
  #       if base not in res.baseFunc:
  #         res.baseFunc.append(base)
  #       # end if 
  #     # end for 

  #     # Add itself to the list of baseFunctions
  #     res.baseFunc.append(res)

  #     # Organize the operation matrix
      
  #     # case 1: operation result +/- operation result
  #     if func1.nature == feNatOperRes and func2.nature == feNatOperRes:

  #       # append both operation matrices
  #       res.Koper = func1.Koper.copy()
  #       res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        
  #       # add new operation to the operations
  #       res.Koper = np.append(res.Koper,\
  #                            [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # initialize the other two operation matrices as void.
  #       res.foper = np.array([],dtype=np.int64)
  #       res.essentialOper = np.array([],dtype=np.int64)
  #       res.nature = feNatOperRes

  #     # case 2: post integral +/- post integral
  #     elif func1.nature == feNatPostIntK and func2.nature == feNatPostIntK:

  #       # The base space is that of the greatest order
  #       if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
  #         res.baseSpace = func1.baseSpace
  #       else:
  #         res.baseSpace = func2.baseSpace
  #       # end if 

  #       res.intorder = max(func1.intorder,func2.intorder)
  #       res.funcid   = res.baseSpace.addNewOperation()

  #       res.baseFunc = func1.baseFunc.copy()

  #       # Add only unique base functions, i.e., do not duplicate.
  #       for base in func2.baseFunc:
  #         if base not in res.baseFunc:
  #           res.baseFunc.append(base)
  #         # end if 
  #       # end for 

  #       # Add itself to the list of baseFunctions
  #       res.baseFunc.append(res)
        
  #       # add new operation to the operation matrix
  #       if func1.foper.ndim != 1 and func2.foper.ndim != 1:
          
  #         # append both foper matrices
  #         res.foper = np.append(func1.foper,func2.foper, axis = 0)
        
  #       elif func1.foper.ndim == 1 and func2.foper.ndim != 1:

  #         res.foper = func2.foper.copy()

  #       elif func1.foper.ndim != 1 and func2.foper.ndim == 1:

  #         res.foper = func1.foper.copy()

  #       else: 
          
  #         res.foper = func1.foper.copy()

  #       # end if 


  #       # add new operation to the operation matrix
  #       if func1.Koper.ndim != 1 and func2.Koper.ndim != 1:
          
  #         # append both Koper matrices
  #         res.Koper = np.append(func1.Koper,func2.Koper, axis = 0)
        
  #       elif func1.Koper.ndim == 1 and func2.Koper.ndim != 1:

  #         res.Koper = func2.Koper.copy()

  #       elif func1.Koper.ndim != 1 and func2.Koper.ndim == 1:

  #         res.Koper = func1.Koper.copy()

  #       else: 
          
  #         res.Koper = func1.Koper.copy()

  #       # end if 

        
  #       # add new operation to the operation matrix
  #       if func1.essentialOper.ndim != 1 and func2.essentialOper.ndim != 1:
          
  #         # append both essentialOper matrices
  #         res.essentialOper = np.append(func1.essentialOper,func2.essentialOper, axis = 0)
        
  #       elif func1.essentialOper.ndim == 1 and func2.essentialOper.ndim != 1:

  #         res.essentialOper = func2.essentialOper.copy()

  #       elif func1.essentialOper.ndim != 1 and func2.essentialOper.ndim == 1:

  #         res.essentialOper = func1.essentialOper.copy()

  #       else: 
          
  #         res.essentialOper = func1.essentialOper.copy()

  #       # end if 
        

  #       res.nature = feNatPostIntK

  #     # elif func1.nature == feNatTest and func2.nature == feNatPostIntF:

  #     # elif func1.nature == feNatPostIntF and func2.nature == feNatTest:

  #     # elif func1.nature == feNatPostIntF and func2.nature == feNatPostIntF:


  #     elif func1.nature == feNatTest and func2.nature == feNatTest:

  #       # append both operation matrices
  #       res.foper = func1.foper.copy()
  #       res.foper = np.append(res.foper,func2.foper, axis = 0)

  #       # add new operation to the operations
  #       res.foper = np.append(res.foper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       # initialize the other two operation matrices as void.
  #       res.Koper = np.array([],dtype=np.int64)
        
  #       res.essentialOper = func1.essentialOper.copy()
  #       res.essentialOper = np.append(res.essentialOper, func2.essentialOper, axis = 0)
  #       # add new operation to the operations
  #       res.essentialOper = np.append(res.essentialOper, \
  #                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #       res.nature = feNatTest

  #     else:

  #       raise ValueError("Can't operate the functions.")

  #     # end if 

  #     res.shape = []
  #     res.shapeBounds = [[],[],[]]
  #     res.position=[0]


  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % %     INTEGRALS     % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   elif operId == opInt3d:   # integral over domain

      


  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % %      BOUNDARY  INTEGRAL     % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   elif operId == opInt2d:   # integral over boundary

  #     res.baseSpace = func1.baseSpace
      
  #     res.intorder = func1.intorder
  #     res.funcid   = res.baseSpace.addNewOperation()

  #     res.baseFunc = func1.baseFunc.copy()
      
  #     # Add itself to the list of baseFunctions
  #     res.baseFunc.append(res)

  #     if func1.nature == feNatTest:

  #       # append both Koper matrices
  #       res.Koper = np.array([],dtype=np.int64)

  #       # add new operation to the operation matrix
  #       res.foper = np.array([],dtype=np.int64)

  #       res.essentialOper = func1.essentialOper.copy()

  #       # add new operation to the operation matrix
        
  #       res.essentialOper = np.append(res.essentialOper,\
  #                            [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)

  #     elif func1.nature == feNatOperRes:

  #       # append both Koper matrices
  #       res.Koper = np.array([],dtype=np.int64)

  #       # add new operation to the operation matrix
  #       res.foper = np.array([],dtype=np.int64)

  #       res.essentialOper = func1.essentialOper.copy()

  #       # add new operation to the operation matrix
        
  #       res.essentialOper = np.append(res.essentialOper,\
  #                            [[operId,res.funcid,func1.funcid,func2.funcid]],\
  #                             axis = 0)
      
  #     else:
  #       raise ValueError("Boundary integral only supports natures "+\
  #           str(feNatTest)+" or "+str(feNatOperRes)+".")
  #     # end if 

  #     # TODO: ADD INDICATION TO THE INTEGRATION REGION!
  #     res.nature = feNatPostIntK
  #     res.shape  = []
  #     res.shapeBounds = [[],[],[]]
  #     res.position=[0]


  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % %    BOUNDARY CONDITION     % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   elif operId == opOn:   # Boundary value condition.
      
  #     res = __create_opOn__(operId, lhs) 

  #   elif operId == opNeg:   # Negation operation.

  #     res = __create_opNeg__(operId, lhs) 

  #   elif operId == opDx or operId == opDy or operId == opDz:   # Derivative with respect to x.

  #     res = __create_opDxx__(operId, lhs)      
    
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % %        NOT DEFINED        % % % % % % % % % % % % % % % %
  #   # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
  #   else:

  #     raise ValueError("Operation with id "+ str(operId) + " is not defined.")

  #   # end if 

  #   return res
  # #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************      
  # def reorderBoundOpers(self):
  #   """
  #   PORPUSE:  Reorder the boundary operations such that first are done all those related with 
  #             Dirichlet conditions and newmann conditions

  #   """
  #   cdef int64_t start = 0, end = 0, i
  #   cdef uint64_t iZero_ = 0 

  #   cdef np.ndarray newBoundOper = np.array([], dtype = np.int64)

  #   for i in range(self.essentialOper.shape[iZero_]):


  #     if self.essentialOper[i,iZero_] == opInt2d:

  #       end = i+1

  #       # add new operation to the operation matrix
  #       if newBoundOper.ndim != 1:

  #         newBoundOper = np.append(self.essentialOper[start:end,:] , \
  #                                   newBoundOper , \
  #                                   axis = iZero_)


  #       else:

  #         newBoundOper = self.essentialOper[start:end,:]

  #       # end if 

  #       start = end

  #     elif self.essentialOper[i,iZero_] == opOn:

  #       end = i+1
  #       # add new operation to the operation matrix
  #       if newBoundOper.ndim != 1:
  #         newBoundOper = np.append(newBoundOper , \
  #                                   self.essentialOper[start:end,:]  , \
  #                                   axis = iZero_)

  #       else:

  #         newBoundOper = self.essentialOper[start:end,:]

  #       # end if 

  #       start = end

  #     # end if 

  #   # end for 

  #   self.essentialOper =  newBoundOper

  # #---------------------------------------------------------------------------------------------------




  # #***************************************************************************************************
  # def set(self,expr):
    
  #   self.data = expr
  #   self.varTyp = constant
  #   type1 = type(expr)
  #   self.baseVars = []

  #   if type1 == sndarray:
      
  #     # TODO: check that the data has correct dimensions.
  #     self.kind = kindOtiArr

  #   elif type1 == sotinum:

  #     self.kind = kindOtiNum

  #   elif type1 in number_types:
      
  #     self.kind = kindReal

  #   # end if 
  # #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::: END OF CLASS ELEMENTAL_OPERATION :::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

