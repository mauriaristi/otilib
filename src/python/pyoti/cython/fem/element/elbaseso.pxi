

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elbaseso    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elbaseso:
  
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
    self.elem = elemso_init()
    self.FLAG = 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __cinit__(self):
    """
    PURPOSE:      Constructor of the base element class. Its main purpose is to 
                  allow a base for every new element definition.


    """
    self.elem = elemso_init()
    self.FLAG = 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """

    PURPOSE:      Destructor of the base element class. 


    """
    
    elemso_free(&self.elem)

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  @staticmethod
  def createElement(uint64_t nbasis, uint8_t order, int64_t geomBase, int64_t  kind,   \
     uint8_t  ndim, object basis, list boundEls ):
    """
    PURPOSE:      Constructor of the Element class. Use this when adding new element types.

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
            A new elbaseso object is created.

    EXAMPLE:

            TriP1 = elbaseso.createNewElement(3,           \ # Number of basis 
                                            1,           \ # Characteristic order of the polynomials
                                            elTriangle,  \ # Geometric type
                                            elkindiso,   \ # Kind of element 
                                            2,           \ # Number of dimensions
                                            &c_fem_basisFunctions_N_TriangP1_2Diso) # Basis functions.

                  
    """
    #*************************************************************************************************

    global dhl

    # create new empty object:
    cdef elbaseso newElement = <elbaseso> elbaseso.__new__(elbaseso)

    newElement.elem = elemso_init()
    
    # elemso_start( &newElement.elem, nbasis, geomBase, kind, ndim, basis_f)
    elemso_start( &newElement.elem, nbasis, geomBase, kind, ndim, dhl)
    newElement.basis = basis
    newElement.FLAG = 1 # Defined in c.

    return newElement
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __repr__(self):
    """
    PURPOSE: Get represerntation of the structure.

    """

    cdef uint64_t i

    head = ""
    body = ""
    tail = ""

    head += "< elbaseso object: \n"
    tail += "end elbaseso object >"

    if (self.FLAG & 1):
      
      if (elemso_is_started( &self.elem )):

        body += " - Object status: ---------------- " + "Started"+"\n"
        body += " - Geometric type: --------------- " + enum2string(self.elem.geomBase)+"\n"
        body += " - Kind of evaluation: ----------- " + enum2string(self.elem.kind)+"\n"
        
        body += " - Number of derivatives: -------- " + str(self.elem.nder)+"\n"
        body += " - Number of dimensions: --------- " + str(self.elem.ndim)+"\n"
        body += " - Number of basis: -------------- " + str(self.elem.nbasis)+"\n"
        body += " - Order: ------------------------ " + str(self.elem.order)+"\n"
        
        if (elemso_is_allocated( &self.elem ) ):

          body += " - Object allocation: ------------ " + "Allocated"+"\n"
          body += " - Number of Integration points: - " + str(self.elem.nip)+"\n"
          body += " - Integration points: \n"
          body += " ----   xi: \n"
          body += repr(self.xi)
          body += " ----  eta: \n"
          body += repr(self.eta)
          body += " ---- zeta: \n"
          body += repr(self.zeta)
          body += "\n - Integration weights: \n"
          body += repr(self.w)
          body += "\n - Evaluated basis functions: \n"

          for i in range(self.elem.nbasis):

            body += " ---- " + enum2string( i + derN ) + "\n"
            body += repr(self.N[i]) + "\n"

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
  cpdef allocate(self, uint64_t intorder, bases_t nbases = 0, ord_t order = 0):
    """
    DESCRIPTION:
    """

    global dhl

    cdef uint64_t i, j, k

    if self.is_allocated():
      self.end()
    # end if 
    
    elemso_allocate(&self.elem, intorder, nbases, order, dhl)


    # Call the basis function, get the 
    self.N = self.basis(  self.xi + se(1),  self.eta + se(2), self.zeta + se(3) )

    # Call evaluation of basis functions at integration points.
    # for i in range(self.elem.nip):

    #   # get integration point.
    #   xi, eta, chi = self.get_integration_point(i)
      
    #   # Evaluates all basis functions for the given coords.
    #   N = self.basis(xi, eta, chi, 1)
    #   # N[j] has the jth basis evaluated at xi,eta,chi; with its derivatives.

    #   for j in range(self.elem.nbasis):
    #     k = 0
    #     # Evaluated basis
    #     darr_set_item_ij(N[j].get_deriv([0]),j,i,&self.elem.p_evalBasis[k]); k+=1

    #     # First order derivatives
    #     darr_set_item_ij(N[j].get_deriv([1]),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv([2]),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv([3]),j,i,&self.elem.p_evalBasis[k]); k+=1

    #     # Second order derivatives
    #     darr_set_item_ij(N[j].get_deriv([[1,2]]),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv( [1,2] ),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv([[2,2]]),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv( [1,3] ),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv( [2,3] ),j,i,&self.elem.p_evalBasis[k]); k+=1
    #     darr_set_item_ij(N[j].get_deriv([[3,2]]),j,i,&self.elem.p_evalBasis[k]); k+=1

    #   # self.set_basis(N)

    # # end for

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef is_allocated(self):

    return elemso_is_allocated(&self.elem)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef is_initialized(self):

    return elemso_is_started(&self.elem)
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef end(self):
    
    if (self.FLAG &1):
      
      elemso_end(&self.elem)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def w(self):
    """
    PURPOSE:      Returns the integration weights.

    """
    #*************************************************************************************************

    return  sotife.create(&self.elem.w,FLAGS=0)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def xi(self):
    """
    PURPOSE:      Get self.elemProps.intPoints

    """
    #*************************************************************************************************

    return sotife.create(&self.elem.xi,FLAGS=0)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def eta(self):
    """
    PURPOSE:      Get self.elemProps.intPoints

    """
    #*************************************************************************************************

    return sotife.create(&self.elem.eta,FLAGS=0)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def zeta(self):
    """
    PURPOSE:      Get self.elemProps.intPoints

    """
    #*************************************************************************************************

    return sotife.create(&self.elem.zeta,FLAGS=0)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nip(self):
    """
    PURPOSE:      Get self.elemProps.nIntPts

    """
    #*************************************************************************************************

    return self.elem.nip

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
  



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elbaseso :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

