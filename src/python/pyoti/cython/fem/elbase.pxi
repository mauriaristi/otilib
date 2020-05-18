







# Point element.
include "element/point1_iso.pxi"

# Line element.
include "element/line1_iso.pxi"
include "element/line2_iso.pxi"
include "element/line3_iso.pxi"

# Triangle element.
include "element/tri1_iso.pxi"
include "element/tri3_iso.pxi"
include "element/tri4_iso.pxi"
include "element/tri6_iso.pxi"

# Quad element.
include "element/quad1_iso.pxi"
include "element/quad4_iso.pxi"
include "element/quad8_iso.pxi"
include "element/quad9_iso.pxi"

# Tetrahedron element.
include "element/tet1_iso.pxi"
include "element/tet4_iso.pxi"

# Brick element (Hexahedron).
include "element/hex1_iso.pxi"
include "element/hex8_iso.pxi"
include "element/hex20_iso.pxi"




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
  # cdef elBase createNewElement(uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim, \
  #             int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil, list boundEls ):
  cdef elBase createNewElement(uint64_t nbasis, uint8_t order, int64_t geomBase, int64_t  kind,   \
     uint8_t  ndim, object basis, list boundEls ):
    """
    PURPOSE:      C-level constructor of the Element class. Use this when adding new element types.

    DESCRIPTION:  Creates and associates an element that can be called from the Problem class.

    PARAMETERS:

      -> nbasis:   Number of basis - Number of degrees of freedom - Number of nodes.
      -> order:    Maximum order of the element.
      -> geomBase: Geometric element type - elLine, elTriangle, etc ...
      -> kind:     Kind of element: Affine - IsoParametric
      -> ndim:     Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
      -> basis:    Function that evaluates the interpolation basis (N) of the element at the 
                   integration points:

                    [N0,N1,...] = basis(xi,eta,chi,derOrder)

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
    
    # elem_start( &newElement.elem, nbasis, geomBase, kind, ndim, basis_f)
    elem_start( &newElement.elem, nbasis, geomBase, kind, ndim)
    newElement.pyFunct = basis
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

        body += " - Object status: ---------------- " + "Started"+"\n"
        body += " - Geometric type: --------------- " + enum2string(self.elem.geomBase)+"\n"
        body += " - Kind of evaluation: ----------- " + enum2string(self.elem.kind)+"\n"
        
        body += " - Number of derivatives: -------- " + str(self.elem.nder)+"\n"
        body += " - Number of dimensions: --------- " + str(self.elem.ndim)+"\n"
        body += " - Number of basis: -------------- " + str(self.elem.nbasis)+"\n"
        body += " - Order: ------------------------ " + str(self.elem.order)+"\n"
        

        if (elem_is_allocated( &self.elem ) ):

          body += " - Object allocation: ------------ " + "Allocated"+"\n"
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
        else:

          body += " - Array allocation: -------------- " + "Not allocated"+"\n"

        # end if
    else:
      body += " - Object status: ---------------- " + "Not started"+"\n"
    # end if 

    return head + body + tail


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef allocate(self, uint64_t intorder):
    """
    DESCRIPTION:
    """
    cdef uint64_t i, j, k
    cdef coeff_t xi = 0.0, eta = 0.0, chi = 0.0

    if self.is_allocated():
      self.end()
    # end if 
    
    elem_allocate(&self.elem, intorder)

    # Call evaluation of basis functions at integration points.
    for i in range(self.elem.nIntPts):

      # get integration point.
      xi, eta, chi = self.get_integration_point(i)
      
      # Evaluates all basis functions for the given coords.
      N = self.pyFunct(xi, eta, chi, 1)
      # N[j] has the jth basis evaluated at xi,eta,chi; with its derivatives.

      for j in range(self.elem.nbasis):
        k = 0
        # Evaluated basis
        darr_set_item_ij(N[j].get_deriv([0]),j,i,&self.elem.p_evalBasis[k]); k+=1

        # First order derivatives
        darr_set_item_ij(N[j].get_deriv([1]),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv([2]),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv([3]),j,i,&self.elem.p_evalBasis[k]); k+=1

        # Second order derivatives
        darr_set_item_ij(N[j].get_deriv([[1,2]]),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv( [1,2] ),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv([[2,2]]),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv( [1,3] ),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv( [2,3] ),j,i,&self.elem.p_evalBasis[k]); k+=1
        darr_set_item_ij(N[j].get_deriv([[3,2]]),j,i,&self.elem.p_evalBasis[k]); k+=1

      # self.set_basis(N)

    # end for

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_integration_point(self, uint64_t i):
    """
    DESCRIPTION:

    """

    cdef coeff_t xi = 0.0, eta = 0.0, chi = 0.0

    if not self.is_allocated():

      raise ValueError("Element must be initialized.")

    # end if 

    if i < self.elem.nIntPts:

      xi = darr_get_item_ij(&self.elem.intPts,i,0)

      if self.elem.ndim > 1 :

        eta = darr_get_item_ij(&self.elem.intPts,i,1)
      
      # end if 

      if self.elem.ndim > 2:

        chi = darr_get_item_ij(&self.elem.intPts,i,2)

      # end if

    else:

      raise IndexError("Index out of bounds for integration point "+str(i)+" for array with " +
                       str(self.elem.nIntPts)+" integration points.")

    # end if 

    return [ xi, eta, chi]

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef is_allocated(self):

    return elem_is_allocated(&self.elem)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef is_initialized(self):

    return elem_is_started(&self.elem)
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
  # cpdef integrate(self, gauss_array func):
  #   """
  #   PURPOSE:      Integrate a gauss array given it belongs to this element. This is determined by
  #                 the number of integration points.
                  
  #   """
  #   cdef sndarray res = spzeros((1,1))
  #   return res
  # #---------------------------------------------------------------------------------------------------
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


























