








include "element/point1_iso.pxi"
include "element/line2_iso.pxi"
include "element/line3_iso.pxi"
include "element/tri3_iso.pxi"
include "element/tri4_iso.pxi"
include "element/tri6_iso.pxi"
include "element/quad4_iso.pxi"
include "element/quad8_iso.pxi"






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
    self.elem = elem_init()
    self.FLAG = 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __cinit__(self):
    """
    PURPOSE:      Constructor of the base element class. Its main purpose is to 
                  allow a base for every new element definition.


    """
    self.elem = elem_init()
    self.FLAG = 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """

    PURPOSE:      Destructor of the base element class. 


    """
    # print("trying Dealloc elBase")
    if self.elem.isInit:
      elem_free(&self.elem)
    # end if 
    # print("finished Dealloc elBase")

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  @staticmethod
  cdef elBase createNewElement(uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim, \
              int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil, list boundEls ):
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

    newElement.elem = elem_init()
    
    elem_start( &newElement.elem, nbasis, geomBase, kind, ndim, basis_f)

    newElement.FLAG = 1 # Defined in c.

    return newElement
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __repr__(self):


    cdef uint64_t i

    head = ""
    body = ""
    tail = ""

    head += "< elbase object: \n"
    tail += "end elbase object >"

    if (self.FLAG & 1):
      
      if (elem_is_started( &self.elem )):

        body += " - Geometric type: --------------- " + enum2string(self.elem.geomBase)+"\n"
        body += " - Kind of evaluation: ----------- " + enum2string(self.elem.kind)+"\n"
        
        body += " - Number of derivatives: -------- " + str(self.elem.nder)+"\n"
        body += " - Number of dimensions: --------- " + str(self.elem.ndim)+"\n"
        body += " - Number of basis: -------------- " + str(self.elem.nbasis)+"\n"
        body += " - Order: ------------------------ " + str(self.elem.order)+"\n"
        

        if (elem_is_allocated( &self.elem ) ):
        
          body += " - Number of Integration points: - " + str(self.elem.nIntPts)+"\n"
          body += " - Integration points: \n"
          body += repr(dmat.create(&self.elem.intPts,FLAGS=0))
          
          body += "\n - Integration weights: \n"
          body += repr(dmat.create(&self.elem.intWts,FLAGS=0))
          
          body += "\n - Evaluated basis functions: \n"

          for i in range(self.elem.nder):

            body += " ---- " + enum2string( i + derN ) + "\n"
            body += repr(dmat.create(&self.elem.p_evalBasis[i],FLAGS=0)) + "\n"

          # end for 

        # end if

    # end if 

    return head + body + tail


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef allocate(self, uint64_t intorder):

    elem_allocate(&self.elem, intorder)


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef end(self):
    
    if (self.FLAG &1):
      
      elem_end(&self.elem)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def intWts(self):
    """
    PURPOSE:      Get self.elemProps.intWeights

    """
    #*************************************************************************************************

    return  dmat.create(&self.elem.intWts,FLAGS=0)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def intPts(self):
    """
    PURPOSE:      Get self.elemProps.intPoints

    """
    #*************************************************************************************************

    return dmat.create(&self.elem.intPts,FLAGS=0)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nIntPts(self):
    """
    PURPOSE:      Get self.elemProps.nIntPts

    """
    #*************************************************************************************************

    return self.elem.nIntPts

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def nder(self):
    """
    PURPOSE:      Get self.elemProps.nder

    """
    #*************************************************************************************************

    return self.elem.nder

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def isInit(self):
    """
    PURPOSE:      Get self.elemProps.isInit

    """
    #*************************************************************************************************
    
    return self.elem.isInit

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def nbasis(self):
    """
    PURPOSE:      Get self.elemProps.nbasis

    """
    #*************************************************************************************************

    return self.elem.nbasis

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self):
    """
    PURPOSE:      Get self.elemProps.order

    """
    #*************************************************************************************************

    return self.elem.order

  #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @order.setter
  # def order(self, uint8_t new_order):
  #   """
  #   PURPOSE:      Get self.elemProps.order

  #   """
  #   #*************************************************************************************************
  #   cdef elem_t new_elem;

  #   new_elem = elem_init()


  #   elem_allocate( &new_elem, self.elem.nbasis, new_order, self.elem.geomBase, self.elem.kind, 
  #     self.elem.ndim, self.elem.f_basis)

  #   elem_free(&self.elem)

  #   self.elem = new_elem




  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def geomBase(self):
    """
    PURPOSE:      Get self.elemProps.geomBase

    """
    #*************************************************************************************************

    return self.elem.geomBase

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def kind(self):
    """
    PURPOSE:      Get self.elemProps.kind

    """
    #*************************************************************************************************

    return self.elem.kind

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ndim(self):
    """
    PURPOSE:      Get self.elemProps.ndim

    """
    #*************************************************************************************************

    return self.elem.ndim

  #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other):
  #   """
  #   PURPOSE:      Given the nodal coordinates, etc, calculate the elemental stiffness matrix for this
  #                 problem.
                  
  #   """
  #   cdef sndarray res = spzeros((1,1))
  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other):
  #   """
  #   PURPOSE:      Given the nodal coordinates, etc, calculate the elemental force vector a 
  #                 problem.
                  
  #   """
    


  #   cdef sndarray res = spzeros((1,1))
  #   return res
  # #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBase :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


























