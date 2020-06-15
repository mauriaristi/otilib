

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

    INPUTS:

      -> nbasis:   Number of basis - Number of degrees of freedom - Number of nodes.
      -> order:    Maximum order of the element.
      -> geomBase: Geometric element type - elLine, elTriangle, etc ...
      -> kind:     Kind of element: Affine - IsoParametric
      -> ndim:     Number of dimensions of the element. (0-> 0D, 1 -> 1D, 2 -> 2D, 3 -> 3D)
      -> basis:    Function that evaluates the interpolation basis (N) of the element at the 
                   integration points:

                    [N0,N1,...] = basis( xi, eta, chi)

      -> boundEls: List of the already defined interpolation functions that define the boundary 
                   interpolation, in the following order.  --> [0D, 1D, 2D]

    RESULT:       
            A new elbaseso object is created.

    EXAMPLE:

            tri3 = elbaseso.createNewElement(3,           \ # Number of basis 
                                             1,           \ # Characteristic order of the polynomials
                                             elTriangle,  \ # Geometric type
                                             elkindiso,   \ # Kind of element 
                                             2,           \ # Number of dimensions
                                             &tri3_iso)     # Basis functions.

                  
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
    newElement.boundEls = boundEls

    return newElement
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __repr__(self):
    """
    PURPOSE: Get representation of the structure.

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

            body += "\n ==== " + enum2string( 0 + derN ) + "\n"
            body += repr( self.N ) + "\n"

            body += "\n ==== " + enum2string( 1 + derN ) + "\n"
            body += repr( self.Nxi ) + "\n"

            body += "\n ==== " + enum2string( 2 + derN ) + "\n"
            body += repr( self.Neta ) + "\n"

            body += "\n ==== " + enum2string( 3 + derN ) + "\n"
            body += repr( self.Nzeta ) + "\n"

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
  cpdef allocate(self, uint64_t intorder, bases_t nbases=0, ord_t order=0):
    """
    DESCRIPTION: Allocate all items as integration points.

    INPUTS:
      
      -> intorder: Integration order of the element (helps define the number of integration points).
      -> nbases:   Number of OTI imaginary bases to allocate.
      -> order:    Truncation order of the OTI members of the number.

    OUTPUTS: 

      None. Things occur internally.

    """

    global dhl

    cdef uint64_t i, j, k
    cdef sotife tmp

    if self.is_allocated():
      self.end()
    # end if 
    
    self.otiorder  = order
    self.otinbases = nbases

    elemso_allocate(&self.elem, intorder, nbases, order, dhl)

    self.N     = matsofe.create(&self.elem.p_evalBasis[0],FLAGS=0)
    self.Nxi   = matsofe.create(&self.elem.p_evalBasis[1],FLAGS=0)
    self.Neta  = matsofe.create(&self.elem.p_evalBasis[2],FLAGS=0)
    self.Nzeta = matsofe.create(&self.elem.p_evalBasis[3],FLAGS=0)

    self.w    = sotife.create(&self.elem.w    ,FLAGS=0)
    self.xi   = sotife.create(&self.elem.xi   ,FLAGS=0)
    self.eta  = sotife.create(&self.elem.eta  ,FLAGS=0)
    self.zeta = sotife.create(&self.elem.zeta ,FLAGS=0)

    # Initialize Spatial variables.
    self.J    = None
    self.detJ = None
    self.Jinv = None
    self.w_dJ = None

    # Call the basis function, get the derivatives using OTI numbers.
    N = self.basis(  self.xi + e(1),  self.eta + e(2), self.zeta + e(3) )

    # Call evaluation of basis functions at integration points.
    for i in range(self.elem.nbasis):
      
      # Standard basis.
      # self.N[i,0] = get_deriv( 0, N[i])
      tmp = get_deriv( 0, N[i])
      fearrso_set_item_ij_f( &tmp.num, i, 0, &self.N.arr,     dhl)
      
      # First order derivatives
      # self.Nxi[i,0] = get_deriv( 1, N[i])
      tmp = get_deriv( 1, N[i])
      fearrso_set_item_ij_f( &tmp.num, i, 0, &self.Nxi.arr,   dhl)
      
      # self.Neta[i,0] = get_deriv( 2, N[i])
      tmp = get_deriv( 2, N[i])
      fearrso_set_item_ij_f( &tmp.num, i, 0, &self.Neta.arr,  dhl)
      
      # self.Nzeta[i,0] = get_deriv( 3, N[i])
      tmp = get_deriv( 3, N[i])
      fearrso_set_item_ij_f( &tmp.num, i, 0, &self.Nzeta.arr, dhl)

    # end for

  #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # cpdef allocate_spatial(self, uint64_t nDimAnalysis, uint8_t compute_Jinv = False ):
  #   """
  #   DESCRIPTION: Allocate all spatial variables.
  #   """

  #   global dhl

  #   cdef uint64_t i, j, k
  #   cdef sotife tmp

  #   if self.is_allocated():

  #     self.nDimAnalysis = nDimAnalysis

  #     self.J    = None # zeros( (), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
  #     self.x    = None
  #     self.y    = None
  #     self.z    = None

  #     self.detJ = sotife( 0., nbases=self.otinbases, order=self.otiorder, nip=self.nip )
  #     self.w_dJ = sotife( 0., nbases=self.otinbases, order=self.otiorder, nip=self.nip )

  #     if compute_Jinv :

  #       self.Jinv = None #  zeros( (,), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
        
  #       self.Nx = None #  zeros( (,), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
  #       self.Ny = None #  zeros( (,), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
  #       self.Nz = None #  zeros( (,), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
      
  #     # end if 

  #   else:

  #     raise ValueError("Element must be allocated first. "+
  #       "Trying to allocate spatial coordinates with no allocated element.")

  #   # end if 

  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef is_allocated(self):
    """
    Return boolean if the element is allocated.
    """

    return elemso_is_allocated(&self.elem)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef is_initialized(self):
    """
    Return boolean if the element is initialized.
    """

    return elemso_is_started(&self.elem)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef end(self):
    """
    Finalize element memory allocation.
    """
    if (self.FLAG &1):
      
      elemso_end(&self.elem)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def set_coordinates(self, matso x, matso y, matso z):
    
    #set coordinates of the number
    
    self.x[:,:] = x

    
    if self.ndim >= 1:
    
      self.y[:,:] = y
    
    # end if
    
    if self.ndim >= 2:
      
      self.z[:,:] = z

    # end if 


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nip(self):
    """
    PURPOSE:      Get element number of integration points.

    """
    #*************************************************************************************************

    return self.elem.nip

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def nder(self):
    """
    PURPOSE:      Get element number of derivatives.

    """
    #*************************************************************************************************

    return self.elem.nder

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def isInit(self):
    """
    PURPOSE:      Get if Element is initialized

    """
    #*************************************************************************************************
    
    return self.elem.isInit

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def nbasis(self):
    """
    PURPOSE:      Get number of basis functions of the element.

    """
    #*************************************************************************************************

    return self.elem.nbasis

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self):
    """
    PURPOSE:      Get Element integration order

    """
    #*************************************************************************************************

    return self.elem.order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def geomBase(self):
    """
    PURPOSE:      Get element geometric base.

    """
    #*************************************************************************************************

    return self.elem.geomBase

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def kind(self):
    """
    PURPOSE:      Get element kind.

    """
    #*************************************************************************************************

    return self.elem.kind

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ndim(self):
    """
    PURPOSE:      Get element number of dimensions  
                  
                  - 0 for point, 
                  - 1 for line, 
                  - 2 for triangle/quad, 
                  - 3 for tetrahedra and brick element.

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

