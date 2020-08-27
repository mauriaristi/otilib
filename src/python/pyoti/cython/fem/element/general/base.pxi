

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::      CLASS  elbase     ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elbase:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------



  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __cinit__(self):
    """
    PURPOSE:      Constructor of the base element class. Its main purpose is to 
                  allow a base for every new element definition.

    """

    self.elem      = elemd_init()

    self.FLAGS     = 0
    self.elorder   = 0

    self.boundEls  = None
    self.basis     = None

    self.elh  = None

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """

    PURPOSE:      Destructor of the base element class. 


    """
    if self.FLAGS != 0:
      elemd_free(&self.elem)
    # end if 

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
            A new elbase object is created.

    EXAMPLE:

            tri3 = elbase.createNewElement(3,           \ # Number of basis 
                                             1,           \ # Characteristic order of the polynomials
                                             elTriangle,  \ # Geometric type
                                             elkindiso,   \ # Kind of element 
                                             2,           \ # Number of dimensions
                                             &tri3_iso)     # Basis functions.

                  
    """
    #*************************************************************************************************

    

    # create new empty object:
    cdef elbase newElement = <elbase> elbase.__new__(elbase)

    newElement.elem = elemd_init()
    
    # elemd_start( &newElement.elem, nbasis, geomBase, kind, ndim, basis_f)
    elemd_start( &newElement.elem, nbasis, geomBase, kind, ndim)
    newElement.basis    = basis
    newElement.FLAGS     = 1 
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

    head += "< elbase object: \n"
    tail += "end elbase object >"

    if (elemd_is_started( &self.elem )):

      body += " - Object status: ---------------- " + "Started"+"\n"
      body += " - Geometric type: --------------- " + enum2string(self.elem.geomBase)+"\n"
      body += " - Kind of evaluation: ----------- " + enum2string(self.elem.kind)+"\n"
      
      body += " - Number of derivatives: -------- " + str(self.elem.nder)+"\n"
      body += " - Number of dimensions: --------- " + str(self.elem.ndim)+"\n"
      body += " - Number of basis: -------------- " + str(self.elem.nbasis)+"\n"
      body += " - Integration Order: ------------ " + str(self.elem.order)+"\n"
      
      body += str(self.elh) + "\n"

    else:

      body += " - Object status: ---------------- " + "Not started"+"\n"

    # end if 

    return head + body + tail


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def allocate(self, uint64_t intorder,**kwargs):
    """
    DESCRIPTION: Allocate all items as integrat ion points.

    INPUTS:
      
      -> intorder: Integration order of the element (helps define the number of integration points).
      -> nbases:   Number of OTI imaginary bases to allocate.
      -> order:    Truncation order of the OTI members of the number.

    OUTPUTS: 

      None. Things occur internally.

    """
    global alg    

    cdef uint64_t i, j, k
    cdef sotife tmp

    if self.is_allocated():
      self.end()
    # end if 

    elemd_allocate(&self.elem, intorder)

    rN     = r.dmatfe.create(&self.elem.p_evalBasis[0],FLAGS=0)
    rNxi   = r.dmatfe.create(&self.elem.p_evalBasis[1],FLAGS=0)
    rNeta  = r.dmatfe.create(&self.elem.p_evalBasis[2],FLAGS=0)
    rNzeta = r.dmatfe.create(&self.elem.p_evalBasis[3],FLAGS=0)

    rw    = r.dnumfe.create(&self.elem.w    ,FLAGS=0)
    rxi   = r.dnumfe.create(&self.elem.xi   ,FLAGS=0)
    reta  = r.dnumfe.create(&self.elem.eta  ,FLAGS=0)
    rzeta = r.dnumfe.create(&self.elem.zeta ,FLAGS=0)

    # Create a new element helper from the selected algebra.
    self.elh = alg.elm_help()

    # Allocate element helper 
    self.elh.allocate( self.elem.ndim, self.elem.nbasis, self.elem.nip, **kwargs)

    # ======================== THIS PART USES SPARSE OTI NUMBERS ====================================
    # Create fesoti numbers.
    xi   = soti.zero(nip=self.elem.nip)
    eta  = soti.zero(nip=self.elem.nip)
    zeta = soti.zero(nip=self.elem.nip)

    for k in range(self.elem.nip):
      self.elh.xi[k]   = rxi[k]
      self.elh.eta[k]  = reta[k]
      self.elh.zeta[k] = rzeta[k]
      self.elh.w[k]    = rw[k]
      xi[k]   = rxi[k]
      eta[k]  = reta[k]
      zeta[k] = rzeta[k]
    # end for

    # Call the basis function, get the derivatives using OTI numbers.
    N = self.basis(  xi + e(1),  eta + e(2), zeta + e(3) )

    # Call evaluation of basis functions at integration points.
    for i in range(self.elem.nbasis):

      Ni = N[i]
      N_i     = get_deriv( 0, Ni)
      Nxi_i   = get_deriv( 1, Ni)
      Neta_i  = get_deriv( 2, Ni)
      Nzeta_i = get_deriv( 3, Ni)

      for k in range(self.elem.nip):

        self.elh.N.set_ijk(    N_i[k].real,     0, i, k)
        self.elh.Nxi.set_ijk(  Nxi_i[k].real,   0, i, k)
        self.elh.Neta.set_ijk( Neta_i[k].real,  0, i, k)
        self.elh.Nzeta.set_ijk(Nzeta_i[k].real, 0, i, k)
        
      # end for 

    # end for

    # ======================== THIS PART USES SPARSE OTI NUMBERS ====================================

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef allocate_spatial(self, uint64_t ndim_an, uint8_t compute_Jinv = False ):
    """
    DESCRIPTION: Allocate all spatial variables.

    INPUTS:
      
      -> ndim_an:        Number of dimensions of the analysis.
      -> compute_Jinv:   Bool to compute inverse of jacobian (Default False).

    OUTPUTS: 

      None. Things occur internally.

    """

    

    self.elh.allocate_spatial(ndim_an, compute_Jinv=compute_Jinv)
    # try:
    # except:
    #   raise ValueError("Algebra must provide element helper.")
    # # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef is_allocated(self):
    """
    Return boolean if the element is allocated.
    """
    return elemd_is_allocated(&self.elem) and self.elh.is_allocated()
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef is_initialized(self):
    """
    Return boolean if the element is initialized.
    """
    return elemd_is_started(&self.elem)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef reset(self):
    """
    Reset the values of all spatial variables.
    """
    self.elh.reset()
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef end(self):
    """
    Finalize element memory allocation.
    """
    if self.elh is not None:
      self.elh.end()
    # end if 
    if (self.FLAGS & 1):      
      elemd_end(&self.elem)
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def set_coordinates(self, object x, object y, object z, np.ndarray elem_indices):
    """
    DESCRIPTION: Set the coordinates of an OTI number from the global vertices coordinates and the given
                 elemental indices

    INPUTS:
      
      -> x, y, z:        Global vertices coordinates.
      -> elem_indices:   Array with the indices of the corresponding elements in the .

    OUTPUTS: 

      None. Things occur internally.
    """
    
    self.elh.set_coordinates( x, y, z, elem_indices)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def compute_jacobian(self):
    """
    DESCRIPTION: Compute jacobian and derived functions.

    """
    
    self.elh.compute_jacobian()

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def compute_jacobian_bruteforce(self):
    """
    DESCRIPTION: Compute jacobian and derived functions.

    """ 
    self.elh.compute_jacobian_bruteforce()

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
  def xi(self):
    return self.elh.xi   
  @property
  def eta(self):
    return self.elh.eta  
  @property
  def zeta(self):
    return self.elh.zeta 
  @property
  def w(self):
    return self.elh.w   
  @property
  def N(self):
    return self.elh.N    
  @property
  def Nxi(self):
    return self.elh.Nxi  
  @property
  def Neta(self):
    return self.elh.Neta 
  @property
  def Nzeta(self):
    return self.elh.Nzeta
  @property
  def Nx(self):
    return self.elh.Nx   
  @property
  def Ny(self):
    return self.elh.Ny   
  @property
  def Nz(self):
    return self.elh.Nz   
  @property
  def x(self):
    return self.elh.x    
  @property
  def y(self):
    return self.elh.y    
  @property
  def z(self):
    return self.elh.z    
  @property
  def J(self):
    return self.elh.J    
  @property
  def detJ(self):
    return self.elh.detJ 
  @property
  def Jinv(self):
    return self.elh.Jinv 
  @property
  def dV(self):
    return self.elh.dV   
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


  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elbase  :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# cdef set_dnumfe_from_sotife(r.dnumfe dst, sotife src):
  
#   cdef uint64_t k
  
#   if (dst.num.nip == src.num.nip):
    
#     for k in range(src.num.nip):

#       dst.num.p_data[k] = src.num.p_data[k].re

#     # end for

#   # end if 

# cdef set_dmatfe_from_sotife(r.dmatfe dst, uint64_t i, uint64_t j,  sotife src):
  
#   cdef uint64_t k
  
#   if (dst.arr.nip == src.num.nip):
    
#     for k in range(src.num.nip):

#       fedarr_set_item_ijk_r(src.num.p_data[k].re,i,j,k,&dst.arr)

#     # end for

#   # end if 
