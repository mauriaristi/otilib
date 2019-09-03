


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  FEFUNCTION    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fefunction:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, fespace baseSpace, int64_t nature, int64_t interpDer = basisN, \
               object data = None ):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a common parameter to store all the procedures and variables to be performed
                  during the Finite Element calculations.

    INPUTS:

          -> baseSpace: Finite element space that this function is associated.

          -> nature:    Nature of the problem. Can be:
                        * feNatTest:  For test function
                        * feNatUndef: For function that will be defined by solving a FE problem. 
                        * feNatDef:   Defined, and has data already.

          -> interpDer: *Optional* Basis function derivative with which it will be approximated.

    """
    #*************************************************************************************************

    self.baseSpace  = baseSpace

    self.interpDer  = interpDer

    self.nature = nature

    self.intorder  = self.baseSpace.elType.order  # modify it outside if required.

    self.funcid    = self.baseSpace.addNewOperation()
    
    if self.nature == feNatDef:

      self.position = [0]
      self.data = data

    else:

      self.position = [self.funcid]
      self.data = None

    # end if 

    self.baseFunc = [ self ] 

    if self.nature == feNatTest:

      self.shape = [baseSpace.elType.nbasis,1]

    elif self.nature == feNatUndef:

      self.shape = [1,baseSpace.elType.nbasis]

    else:

      self.shape = [1,1]

    # end if 
                      # 0D, 1D, 2D
    self.shapeBounds = [[], [], []]

    cdef int64_t i

    for i in range(len(baseSpace.elType.boundEls)):

      if self.nature == feNatTest:

        self.shapeBounds[i] = [baseSpace.elType.boundEls[i].nbasis,1]

      elif self.nature == feNatUndef:

        self.shapeBounds[i] = [1,baseSpace.elType.boundEls[i].nbasis]

      else:

        self.shapeBounds[i] = [1,1]

      # end if 

    # end for 
    

    self.Koper        = np.array([[opDef, self.funcid, self.funcid, 0]],dtype = np.int64) # definitions goes only in the matrix. 

    self.foper        = np.array([[opDef, self.funcid, self.funcid, 0]],dtype = np.int64) #

    self.essentialOper= np.array([[opDef, self.funcid, self.funcid, 0]],dtype = np.int64) # 


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operK(self):
    return self.Koper
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operf(self):
    return self.foper
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operEssential(self):
    return self.essentialOper
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef fefunction newFromOperation(int64_t operId, fefunction func1, fefunction func2):
    """
    PURPOSE:  Create a new element from 


    INPUTS:  

      -> operId:Id that characterizes the operation.

              opAdd    , opSub    , opMul    , 
              opTruediv, opPowr   , opInt1d  , 
              opInt2d  , opInt3d  , opDx     , 
              opDxx    , opDy     , opDxy    , 
              opDyy    , opDz     , opDxz    , 
              opDyz    , opDzz    , opDef    ,                   
    """
    #*************************************************************************************************
    
    cdef fefunction res = <fefunction> fefunction.__new__(fefunction)
    cdef np.ndarray newOperation 
    res.interpDer  = basisN

    
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % %     MULTIPLICATION      % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    if operId == opMul:
      

      if func1.nature == feNatDef and func2.nature == feNatDef:
        
        # TODO: Operation between two defined functions that have
        #       different spaces should be performed as an operation
        #       to be done later rather than an operation inplace.

        # Perform the operation
        res = func1.baseSpace.newFunction(func1.data*func2.data)
        
        res.intorder = func1.intorder + func2.intorder

        return res

      # end if 

      # The base space is that of the greatest  order
      if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
        res.baseSpace = func1.baseSpace
      else:
        res.baseSpace = func2.baseSpace
      # end if 

      res.intorder = func1.intorder + func2.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()

      # Add only unique base functions, i.e., do not duplicate.
      for base in func2.baseFunc:
        if base not in res.baseFunc:
          res.baseFunc.append(base)
        # end if 
      # end for 

      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # Organize the operation matrix

      # case 1: test * undef funct
      if func1.nature == feNatTest and func2.nature == feNatUndef:

        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        res.Koper = np.append(res.Koper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)
        res.foper = np.array([],dtype=np.uint64)
        
        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape =    [func1.shape[0],func2.shape[1]]
        res.shapeBounds = [[],[],[]]
        
        for i in range(3):
          if len(func1.shapeBounds[i])!=0:
            res.shapeBounds[i] = [func1.shapeBounds[i][0],func2.shapeBounds[i][1]]
          # end if 
        # end for 
        
        res.position = [func1.position[0],func2.position[0]]

      # case 2: undef funct * test
      elif func1.nature == feNatUndef and func2.nature == feNatTest:

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        
        # add new operation to the operations
        res.Koper = np.append(res.Koper,\
                             [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        # initialize the other two operation matrices as void.
        res.foper = np.array([],dtype=np.int64)
        
        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape    = [func2.shape[0],    func1.shape[1] ]
        res.shapeBounds = [[],[],[]]
        
        for i in range(3):
          if len(func1.shapeBounds[i])!=0:
            res.shapeBounds[i] = [func2.shapeBounds[i][0],func1.shapeBounds[i][1]]
          # end if 
        # end for 

        res.position = [func2.position[0],func1.position[0]]


      # case 3: def funct * test
      elif func1.nature == feNatTest and func2.nature == feNatDef:
        
        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatTest
        res.shape = func1.shape.copy()
        res.shapeBounds = func1.shapeBounds.copy()
        res.position = func1.position.copy()

      # case 4: def funct * test
      elif func1.nature == feNatDef and func2.nature == feNatTest:

        # append both operation matrices
        res.foper = func2.foper.copy()
        res.foper = np.append(res.foper,func1.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatTest
        res.shape = func2.shape.copy()
        res.shapeBounds = func2.shapeBounds.copy()
        res.position = func2.position.copy()


      # case 5: Undef * def funct
      elif func1.nature == feNatUndef and func2.nature == feNatDef:
        
        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatUndef
        res.shape = func1.shape.copy()
        res.shapeBounds = func1.shapeBounds.copy()
        res.position = func1.position.copy()

      # case 6: def funct * Undef
      elif func1.nature == feNatDef and func2.nature == feNatUndef:

        # append both operation matrices
        res.foper = func2.foper.copy()
        res.foper = np.append(res.foper,func1.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)
        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatUndef
        res.shape = func2.shape.copy()
        res.shapeBounds = func2.shapeBounds.copy()
        res.position = func2.position.copy()


      # case 5: Undef * def funct
      elif func1.nature == feNatOperRes and func2.nature == feNatDef:
        
        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)


        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape = func1.shape.copy()
        res.shapeBounds = func1.shapeBounds.copy()
        res.position = func1.position.copy()

      # case 6: def funct * Undef
      elif func1.nature == feNatDef and func2.nature == feNatOperRes:

        # append both operation matrices
        res.foper = func2.foper.copy()
        res.foper = np.append(res.foper,func1.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape = func2.shape.copy()
        res.shapeBounds = func2.shapeBounds.copy()
        res.position = func2.position.copy()

      else:

        raise ValueError("Can't operate the functions.")

      # end if 


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %   ADDITION / SUBTRACTION  % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opAdd or operId == opSub:   # Addition

      # If both are defined.
      if func1.nature == feNatDef and func2.nature == feNatDef:
        
        # Perform the operation
        if operId == opAdd:
          res = func1.baseSpace.newFunction(func1.data+func2.data)
        else:
          res = func1.baseSpace.newFunction(func1.data-func2.data)
        # end if 

        res.intorder = max(func1.intorder , func2.intorder)

        return res

      # end if 

      # The base space is that of the greatest order
      if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
        res.baseSpace = func1.baseSpace
      else:
        res.baseSpace = func2.baseSpace
      # end if 

      res.intorder = max(func1.intorder,func2.intorder)
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()

      # Add only unique base functions, i.e., do not duplicate.
      for base in func2.baseFunc:
        if base not in res.baseFunc:
          res.baseFunc.append(base)
        # end if 
      # end for 

      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # Organize the operation matrix
      
      # case 1: operation result +/- operation result
      if func1.nature == feNatOperRes and func2.nature == feNatOperRes:

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        
        # add new operation to the operations
        res.Koper = np.append(res.Koper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # initialize the other two operation matrices as void.
        res.foper = np.array([],dtype=np.int64)
        res.essentialOper = np.array([],dtype=np.int64)
        res.nature = feNatOperRes

      # case 2: post integral +/- post integral
      elif func1.nature == feNatPostIntK and func2.nature == feNatPostIntK:

        # The base space is that of the greatest order
        if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
          res.baseSpace = func1.baseSpace
        else:
          res.baseSpace = func2.baseSpace
        # end if 

        res.intorder = max(func1.intorder,func2.intorder)
        res.funcid   = res.baseSpace.addNewOperation()

        res.baseFunc = func1.baseFunc.copy()

        # Add only unique base functions, i.e., do not duplicate.
        for base in func2.baseFunc:
          if base not in res.baseFunc:
            res.baseFunc.append(base)
          # end if 
        # end for 

        # Add itself to the list of baseFunctions
        res.baseFunc.append(res)
        
        # add new operation to the operation matrix
        if func1.foper.ndim != 1 and func2.foper.ndim != 1:
          
          # append both foper matrices
          res.foper = np.append(func1.foper,func2.foper, axis = 0)
        
        elif func1.foper.ndim == 1 and func2.foper.ndim != 1:

          res.foper = func2.foper.copy()

        elif func1.foper.ndim != 1 and func2.foper.ndim == 1:

          res.foper = func1.foper.copy()

        else: 
          
          res.foper = func1.foper.copy()

        # end if 


        # add new operation to the operation matrix
        if func1.Koper.ndim != 1 and func2.Koper.ndim != 1:
          
          # append both Koper matrices
          res.Koper = np.append(func1.Koper,func2.Koper, axis = 0)
        
        elif func1.Koper.ndim == 1 and func2.Koper.ndim != 1:

          res.Koper = func2.Koper.copy()

        elif func1.Koper.ndim != 1 and func2.Koper.ndim == 1:

          res.Koper = func1.Koper.copy()

        else: 
          
          res.Koper = func1.Koper.copy()

        # end if 

        
        # add new operation to the operation matrix
        if func1.essentialOper.ndim != 1 and func2.essentialOper.ndim != 1:
          
          # append both essentialOper matrices
          res.essentialOper = np.append(func1.essentialOper,func2.essentialOper, axis = 0)
        
        elif func1.essentialOper.ndim == 1 and func2.essentialOper.ndim != 1:

          res.essentialOper = func2.essentialOper.copy()

        elif func1.essentialOper.ndim != 1 and func2.essentialOper.ndim == 1:

          res.essentialOper = func1.essentialOper.copy()

        else: 
          
          res.essentialOper = func1.essentialOper.copy()

        # end if 
        

        res.nature = feNatPostIntK

      # elif func1.nature == feNatTest and func2.nature == feNatPostIntF:

      # elif func1.nature == feNatPostIntF and func2.nature == feNatTest:

      # elif func1.nature == feNatPostIntF and func2.nature == feNatPostIntF:


      elif func1.nature == feNatTest and func2.nature == feNatTest:

        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # initialize the other two operation matrices as void.
        res.Koper = np.array([],dtype=np.int64)
        
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper, func2.essentialOper, axis = 0)
        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatTest

      else:

        raise ValueError("Can't operate the functions.")

      # end if 

      res.shape = []
      res.shapeBounds = [[],[],[]]
      res.position=[0]


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %       DOMAIN INTEGRAL     % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opInt3d:   # integral over domain

        res.baseSpace = func1.baseSpace
        
        res.intorder = func1.intorder
        res.funcid   = res.baseSpace.addNewOperation()

        res.baseFunc = func1.baseFunc.copy()
        
        # Add itself to the list of baseFunctions
        res.baseFunc.append(res)

        if func1.nature == feNatTest:

          # append both foper matrices
          res.foper = func1.foper.copy()

          # append both Koper matrices
          res.Koper = np.array([],dtype=np.int64)

          # add new operation to the operation matrix
          res.foper = np.append(res.foper,\
                               [[operId,res.funcid,func1.funcid,0]],\
                                axis = 0)

          # initialize the other two operation matrices as void.
          res.essentialOper = np.array([],dtype=np.int64)

        elif func1.nature == feNatOperRes:

          # append both foper matrices
          res.foper = np.array([],dtype=np.int64)

          # append both Koper matrices
          res.Koper = func1.Koper.copy()

          # add new operation to the operation matrix
          res.Koper = np.append(res.Koper,\
                               [[operId,res.funcid,func1.funcid,0]],\
                                axis = 0)

          # initialize the other two operation matrices as void.
          res.essentialOper = np.array([],dtype=np.int64)

        else:

          raise ValueError("Domain integral only supports natures "+\
            str(feNatTest)+" or "+str(feNatOperRes)+".")

        # end if 
        # TODO: ADD INDICATION TO THE INTEGRATION REGION!
        res.nature   = feNatPostIntK 
        res.shape    = []
        res.shapeBounds = [[],[],[]]
        res.position = [0]


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %      BOUNDARY  INTEGRAL     % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opInt2d:   # integral over boundary

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      if func1.nature == feNatTest:

        # append both Koper matrices
        res.Koper = np.array([],dtype=np.int64)

        # add new operation to the operation matrix
        res.foper = np.array([],dtype=np.int64)

        res.essentialOper = func1.essentialOper.copy()

        # add new operation to the operation matrix
        
        res.essentialOper = np.append(res.essentialOper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

      elif func1.nature == feNatOperRes:

        # append both Koper matrices
        res.Koper = np.array([],dtype=np.int64)

        # add new operation to the operation matrix
        res.foper = np.array([],dtype=np.int64)

        res.essentialOper = func1.essentialOper.copy()

        # add new operation to the operation matrix
        
        res.essentialOper = np.append(res.essentialOper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)
      
      else:

        raise ValueError("Boundary integral only supports natures "+\
            str(feNatTest)+" or "+str(feNatOperRes)+".")

      # end if 

      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = feNatPostIntK
      res.shape  = []
      res.shapeBounds = [[],[],[]]
      res.position=[0]


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %    BOUNDARY CONDITION     % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opOn:   # Boundary value condition.

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # append both foper matrices
      res.foper = func1.foper.copy()

      # append both Koper matrices
      res.Koper = np.array([],dtype=np.int64)

      # add new operation to the operation matrix
      if func1.essentialOper.ndim != 1:
        res.essentialOper = np.append(func1.essentialOper,\
                           [[operId,res.funcid,func1.funcid,func2.funcid]],\
                            axis = 0)
      else:
        res.essentialOper = np.array([[operId,res.funcid,func1.funcid,func2.funcid]],dtype=np.int64)
      # end if 

      # initialize the other two operation matrices as void.
      res.foper = np.array([],dtype=np.int64)


      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = feNatPostIntK
      res.shape =[]
      res.shapeBounds = [[],[],[]]
      res.position = [0] #  Add here the position of the variable that is being defined.

    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % %    NEGATION     % % % % % % % % % % % % % % % % % 
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opNeg:   # Negation operation.

      if func1.nature == feNatDef :
        
        # TODO: Operation between two defined functions that have
        #       different spaces should be performed as an operation
        #       to be done later rather than an operation inplace.

        # Perform the operation
        res = func1.baseSpace.newFunction(-func1.data)

        return res

      # end if 

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # append both foper matrices
      res.foper = func1.foper.copy()

      if res.foper.ndim != 1:
        res.foper = np.append(res.foper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.Koper = func1.Koper.copy()
      if res.Koper.ndim != 1:
        res.Koper = np.append(res.Koper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.essentialOper = func1.essentialOper.copy()
      if res.essentialOper.ndim != 1:
        res.essentialOper = np.append(res.essentialOper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 


      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = func1.nature
      res.shape = func1.shape.copy()
      res.shapeBounds = func1.shapeBounds.copy()
      res.position = func1.position.copy()


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % %    DERIV. X     % % % % % % % % % % % % % % % % % 
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opDx or operId == opDy or operId == opDz:   # Derivative with respect to x.

      # For now: Not supported dx( dx(...) )

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder-1

      if func1.interpDer != basisN:
        raise ValueError("multiple concatenation of derivative operations is "+
                         "currently not supported")

      if   operId == opDx:

        res.interpDer= basisNx 

      elif operId == opDy:

        res.interpDer= basisNy 

      elif operId == opDz:

        res.interpDer= basisNz  

      # end if 

      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # append both foper matrices
      res.foper = func1.foper.copy()

      if res.foper.ndim != 1:
        res.foper = np.append(res.foper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.Koper = func1.Koper.copy()
      if res.Koper.ndim != 1:
        res.Koper = np.append(res.Koper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.essentialOper = func1.essentialOper.copy()
      if res.essentialOper.ndim != 1:
        res.essentialOper = np.append(res.essentialOper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 


      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = func1.nature
      res.shape = func1.shape.copy()
      res.shapeBounds = func1.shapeBounds.copy()
      res.position = func1.position.copy()
      
    
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %        NOT DEFINED        % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    else:

      raise ValueError("Operation with id "+ str(operId) + " is not defined.")

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************      
  def reorderBoundOpers(self):
    """
    PORPUSE:  Reorder the boundary operations such that first are done all those related with 
              Dirichlet conditions and newmann conditions

    """
    cdef int64_t start = 0, end = 0, i
    cdef uint64_t iZero_ = 0 

    cdef np.ndarray newBoundOper = np.array([], dtype = np.int64)

    for i in range(self.essentialOper.shape[iZero_]):


      if self.essentialOper[i,iZero_] == opInt2d:

        end = i+1

        # add new operation to the operation matrix
        if newBoundOper.ndim != 1:

          newBoundOper = np.append(self.essentialOper[start:end,:] , \
                                    newBoundOper , \
                                    axis = iZero_)


        else:

          newBoundOper = self.essentialOper[start:end,:]

        # end if 

        start = end

      elif self.essentialOper[i,iZero_] == opOn:

        end = i+1
        # add new operation to the operation matrix
        if newBoundOper.ndim != 1:
          newBoundOper = np.append(newBoundOper , \
                                    self.essentialOper[start:end,:]  , \
                                    axis = iZero_)

        else:

          newBoundOper = self.essentialOper[start:end,:]

        # end if 

        start = end

      # end if 

    # end for 

    self.essentialOper =  newBoundOper

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************      
  def __repr__(self):
    
    if self.nature == feNatDef:
    
      out = "<FE function"
      out += " id "+str(self.funcid)
      out += ", Nature "+ str(self.nature)
      out += ", iord "+ str(self.intorder)
      out += ", data:\n"
      out += repr(self.data)
      out += "\n>"
    
    else:
    
      out = "<FE function"
      out += " id "+str(self.funcid)
      out += ", Nature "+ str(self.nature)
      out += ", iord "+ str(self.intorder)
      out += ">"
    
    # end if 

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __str__(self):
    
    # if self.nature == feNatDef:
    #   out = "<FE function"
    #   out += " id "+str(self.funcid)
    #   out += ", Nature "+ str(self.nature)
    #   out += ", iord "+ str(self.intorder)
    #   out += ", data:\n"
    #   out += str(self.data)
    #   out += "\n>"
    
    # else:
    
    out = "<FE function"
    out += " id "+str(self.funcid)
    out += ", Nature "+ str(self.nature)
    out += ", iord "+ str(self.intorder)
    out += ">"
    
    # end if 

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    
    cdef fefunction res 
    res   = fefunction.newFromOperation(opNeg,self,None)            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self,other):
    
    cdef fefunction res 
    cdef fefunction func1
    cdef fefunction func2
    
    type1 = type(self)
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class fefunction
      
      func1 = self
      func2 = other
      res   = fefunction.newFromOperation(opAdd,func1,func2)

    # end if 
            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __sub__(self,other):
    
    return self + (-other)
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __mul__(self,other):
    
    cdef fefunction res 
    cdef fefunction func1
    cdef fefunction func2
    
    type1 = type(self)    
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class fefunction
      
      func1 = self
      func2 = other
      res   = fefunction.newFromOperation(opMul,func1,func2)

    elif type2 == fefunction:
      
      func2 = other
      func1 = func2.baseSpace.newFunction(self)

      res = func1*func2 

    elif type1 == fefunction:

      func1 = self
      func2 = func1.baseSpace.newFunction(other)
      
      res = func1*func2

    else:

      return NotImplemented

    # end if 



    return res
  #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # def __truediv__(self,other):
    
  #   cdef fevar res 
  #   cdef fevar S
    
  #   type1 = type(self)
  #   type2 = type(other)
    
  #   if type1 == type2: # invalid operation ?
      
  #     S = self
  #     res = fevar(S.base)
  #     res.kind = fem_checkFevarKind(opTruediv,(S.kind,other.kind) )
  #     res.intorder= S.intorder+other.intorder # Check this! ... Is this really possible?

  #     res.pos = S.base.msh.addNewVariable(res.kind)

  #     # S.base.msh.addOper('/', S, other, res)
  #     S.base.msh.addOperNp([opTruediv,    \
  #           S.num,     S.kind,     S.pos, \
  #       other.num, other.kind, other.pos, \
  #         res.num,   res.kind,   res.pos     ])

  #     # Add vars
  #     res.baseVars = list(set(S.baseVars+other.baseVars))

  #   # end if 

  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def __pow__(self,exp,z):
    
  #   cdef fevar res 
  #   cdef fevar S
    
    
  #   S = self 
  #   res = fevar(S.base)
  #   res.kind = fem_checkFevarKind(opPowr,(S.kind,) )
  #   res.intorder = S.intorder*exp

  #   res.pos = S.base.msh.addNewVariable(res.kind)

  #   # Deprecated:
  #   # S.base.msh.addOperConst('pow', S, exp, res)

  #   S.base.msh.addOperNp([opPowr,                         \
  #     S.num,    S.kind,  S.pos,                           \
  #     S.base.msh.addNewConstant(np.float64(exp), kindReal) , kindReal , \
  #     res.num, res.kind, res.pos])

  #   # Add vars
  #   res.baseVars = self.baseVars.copy()
  #   # TODO: Add to constant arrays.

  #   return res
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
# ::::::::::::::::::::::::::::::::::: END OF CLASS FEFUNCTION ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


