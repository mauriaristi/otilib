

















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elBase    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elBase:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------



  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self):
    """
    PURPOSE:      Constructor of the base element class. Its main purpose is to 
                  allow a base for every new element definition.


    """
    
    self.a=1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """

    PURPOSE:      Destructor of the base element class. 


    """
    # print("trying Dealloc elBase")
    if self.elemProps.isInit:
      c_fem_unInitElement(&self.elemProps)
    # end if 
    # print("finished Dealloc elBase")

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  @staticmethod
  cdef elBase createNewElement(uint64_t nbasis, uint64_t order, int64_t geomBase, \
                               int64_t  kind,   uint8_t  ndim, \
              int64_t (*basis_f)(int64_t,int64_t,darray_t*,void*,darray_t*), list boundEls ):
    """
    PURPOSE:      C-level constructor of the Element class. Use this when adding new element types.

    DESCRIPTION:  Creates and associates an element that can be called from the Problem class.

    PARAMETERS:

      -> nbasis:   Number of basis - Number of degrees of freedom - Number of nodes.

      -> order:    Maximum order of the element.

      -> geomBase: Geometric element type - elLine, elTriangle, etc ...

      -> kind:     Kind of element: Affine - IsoParametric

      -> ndim:     Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)

      -> basis_f:  Interpolation function.

      -> boundEls: List of the already defined interpolation functions that define the boundary 
                   interpolation, in the following order.  --> [0D, 1D, 2D]

    RESULT:       
            A new elBase object is created.

    EXAMPLE:

            TriP1 = elBase.createNewElement(3,           \ # Number of basis 
                                            1,           \ # Characteristic order of the polynomials
                                            elTriangle,  \ # Geometric type
                                            elkindiso,   \ # Kind of element 
                                            2,           \ # Number of dimensions
                                            &c_fem_basisFunctions_N_TriangP1_2Diso) # Basis functions.

                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef elBase newElement = <elBase> elBase.__new__(elBase)
    cdef uint64_t nder = 0

    newElement.elemProps.nbasis   = nbasis
    newElement.elemProps.order    = order
    newElement.elemProps.geomBase = geomBase
    newElement.elemProps.kind     = kind
    newElement.elemProps.ndim     = ndim
    newElement.elemProps.f_basis  = basis_f

    if ndim == 0:

      nder = 1

    elif ndim == 1:

      nder = 3

    elif ndim == 2:

      nder = 6

    elif ndim == 3:

      nder = 10

    # end if

    newElement.elemProps.nder                = nder
    newElement.elemProps.isInit              = 0
    newElement.elemProps.nIntPts             = 0
    newElement.elemProps.p_intPoints.p_data  = NULL
    newElement.elemProps.p_intPoints.ncols   = 0
    newElement.elemProps.p_intPoints.nrows   = 0
    newElement.elemProps.p_intPoints.size    = 0 
    newElement.elemProps.p_intWeights.p_data = NULL
    newElement.elemProps.p_intWeights.ncols  = 0
    newElement.elemProps.p_intWeights.nrows  = 0
    newElement.elemProps.p_intWeights.size   = 0 
    newElement.elemProps.p_evalBasis         = NULL

    # newElement.elemProps.f_init   = &
    # newElement.elemProps.f_unInit = &


    newElement.elorder = order
    newElement.a = 10
    newElement.boundEls = boundEls

    return newElement
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef initElement(self, uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis):

    c_fem_initElement( order, otiorder, nDimAnalysis,&self.elemProps)


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uninitElement(self):
    if self.elemProps.isInit == 1:
      c_fem_unInitElement(&self.elemProps)
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def intWeights(self):
    """
    PURPOSE:      Get self.elemProps.intWeights

    """
    #*************************************************************************************************

    return  darray_2_numpyArray(&self.elemProps.p_intWeights)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def intPoints(self):
    """
    PURPOSE:      Get self.elemProps.intPoints

    """
    #*************************************************************************************************

    return darray_2_numpyArray(&self.elemProps.p_intPoints)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nIntPts(self):
    """
    PURPOSE:      Get self.elemProps.nIntPts

    """
    #*************************************************************************************************

    return self.elemProps.nIntPts

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def nder(self):
    """
    PURPOSE:      Get self.elemProps.nder

    """
    #*************************************************************************************************

    return self.elemProps.nder

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nIntPts(self):
    """
    PURPOSE:      Get self.elemProps.nIntPts

    """
    #*************************************************************************************************

    return self.elemProps.nIntPts

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def isInit(self):
    """
    PURPOSE:      Get self.elemProps.isInit

    """
    #*************************************************************************************************
    
    return self.elemProps.isInit

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def nbasis(self):
    """
    PURPOSE:      Get self.elemProps.nbasis

    """
    #*************************************************************************************************

    return self.elemProps.nbasis

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self):
    """
    PURPOSE:      Get self.elemProps.order

    """
    #*************************************************************************************************

    return self.elemProps.order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def geomBase(self):
    """
    PURPOSE:      Get self.elemProps.geomBase

    """
    #*************************************************************************************************

    return self.elemProps.geomBase

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def kind(self):
    """
    PURPOSE:      Get self.elemProps.kind

    """
    #*************************************************************************************************

    return self.elemProps.kind

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ndim(self):
    """
    PURPOSE:      Get self.elemProps.ndim

    """
    #*************************************************************************************************

    return self.elemProps.ndim

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other):
    """
    PURPOSE:      Given the nodal coordinates, etc, calculate the elemental stiffness matrix for this
                  problem.
                  
    """
    cdef sndarray res = spzeros((1,1))
    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef sndarray fe(self,sndarray coords, np.ndarray connect, other):
    """
    PURPOSE:      Given the nodal coordinates, etc, calculate the elemental force vector a 
                  problem.
                  
    """
    


    cdef sndarray res = spzeros((1,1))
    return res
  #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBase :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





















