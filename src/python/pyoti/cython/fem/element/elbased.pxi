

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elbased    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elbased:
  
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
    self.ndim_an   = 0 

    self.boundEls  = None
    self.basis     = None

    self.xi        = None
    self.eta       = None
    self.zeta      = None
    self.w         = None

    self.N         = None
    self.Nxi       = None
    self.Neta      = None
    self.Nzeta     = None

    self.Nx        = None
    self.Ny        = None
    self.Nz        = None

    self.x         = None
    self.y         = None
    self.z         = None
    
    self.J         = None
    self.detJ      = None
    self.Jinv      = None
    self.w_dJ      = None

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
            A new elbased object is created.

    EXAMPLE:

            tri3 = elbased.createNewElement(3,           \ # Number of basis 
                                             1,           \ # Characteristic order of the polynomials
                                             elTriangle,  \ # Geometric type
                                             elkindiso,   \ # Kind of element 
                                             2,           \ # Number of dimensions
                                             &tri3_iso)     # Basis functions.

                  
    """
    #*************************************************************************************************

    

    # create new empty object:
    cdef elbased newElement = <elbased> elbased.__new__(elbased)

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

    head += "< elbased object: \n"
    tail += "end elbased object >"

    if (elemd_is_started( &self.elem )):

      body += " - Object status: ---------------- " + "Started"+"\n"
      body += " - Geometric type: --------------- " + enum2string(self.elem.geomBase)+"\n"
      body += " - Kind of evaluation: ----------- " + enum2string(self.elem.kind)+"\n"
      
      body += " - Number of derivatives: -------- " + str(self.elem.nder)+"\n"
      body += " - Number of dimensions: --------- " + str(self.elem.ndim)+"\n"
      body += " - Number of basis: -------------- " + str(self.elem.nbasis)+"\n"
      body += " - Integration Order: ------------ " + str(self.elem.order)+"\n"
      
      if (elemd_is_allocated( &self.elem ) ):

        body += " - Object allocation: ------------ " + "Allocated"+"\n"
        body += " - Number of Integration points: - " + str(self.elem.nip)+"\n"
        body += " - Integration points: \n"
        body += " ----   xi: \n"
        body += repr(self.xi.real)
        body += " ----  eta: \n"
        body += repr(self.eta.real)
        body += " ---- zeta: \n"
        body += repr(self.zeta.real)
        body += "\n - Integration weights: \n"
        body += repr(self.w.real)
        body += "\n - Evaluated basis functions: \n"

        # for i in range(self.elem.nbasis):

        #   body += "\n ==== " + enum2string( 0 + derN ) + "\n"
        #   body += repr( self.N ) + "\n"

        #   body += "\n ==== " + enum2string( 1 + derN ) + "\n"
        #   body += repr( self.Nxi ) + "\n"

        #   body += "\n ==== " + enum2string( 2 + derN ) + "\n"
        #   body += repr( self.Neta ) + "\n"

        #   body += "\n ==== " + enum2string( 3 + derN ) + "\n"
        #   body += repr( self.Nzeta ) + "\n"

        # # end for 

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
    DESCRIPTION: Allocate all items as integration points.

    INPUTS:
      
      -> intorder: Integration order of the element (helps define the number of integration points).
      -> nbases:   Number of OTI imaginary bases to allocate.
      -> order:    Truncation order of the OTI members of the number.

    OUTPUTS: 

      None. Things occur internally.

    """

    

    cdef uint64_t i, j, k
    cdef sotife tmp, xi, eta, zeta

    if self.is_allocated():
      self.end()
    # end if 

    elemd_allocate(&self.elem, intorder)

    self.N     = r.dmatfe.create(&self.elem.p_evalBasis[0],FLAGS=0)
    self.Nxi   = r.dmatfe.create(&self.elem.p_evalBasis[1],FLAGS=0)
    self.Neta  = r.dmatfe.create(&self.elem.p_evalBasis[2],FLAGS=0)
    self.Nzeta = r.dmatfe.create(&self.elem.p_evalBasis[3],FLAGS=0)

    self.w    = r.dnumfe.create(&self.elem.w    ,FLAGS=0)
    self.xi   = r.dnumfe.create(&self.elem.xi   ,FLAGS=0)
    self.eta  = r.dnumfe.create(&self.elem.eta  ,FLAGS=0)
    self.zeta = r.dnumfe.create(&self.elem.zeta ,FLAGS=0)


    # ======================== THIS PART USES SPARSE OTI NUMBERS ====================================
    # Create fesoti numbers.
    xi   = zero(nip=self.elem.nip)
    eta  = zero(nip=self.elem.nip)
    zeta = zero(nip=self.elem.nip)

    for k in range(self.elem.nip):
      xi[k]   = self.xi[k]
      eta[k]  = self.eta[k]
      zeta[k] = self.zeta[k]
    # end for

    # Call the basis function, get the derivatives using OTI numbers.
    N = self.basis(  xi + e(1),  eta + e(2), zeta + e(3) )

    # Call evaluation of basis functions at integration points.
    for i in range(self.elem.nbasis):

      Ni = N[i]
      # Standard basis.
      tmp = get_deriv( 0, Ni)
      # set_dnumfe_from_sotife(self.N[0,i], tmp    )
      set_dmatfe_from_sotife(self.N, 0, i, tmp)
      
      # First order derivatives
      tmp = get_deriv( 1, Ni)
      # set_dnumfe_from_sotife(self.Nxi[0,i], tmp  )
      set_dmatfe_from_sotife(self.Nxi, 0, i, tmp)

      tmp = get_deriv( 2, Ni)
      # set_dnumfe_from_sotife(self.Neta[0,i], tmp )
      set_dmatfe_from_sotife(self.Neta, 0, i, tmp)

      tmp = get_deriv( 3, Ni)
      # set_dnumfe_from_sotife(self.Nzeta[0,i], tmp)
      set_dmatfe_from_sotife(self.Nzeta, 0, i, tmp)

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

    cdef uint64_t i, j, k
    cdef r.dnumfe tmp

    if self.is_allocated():

      self.ndim_an = ndim_an

      self.J = r.zeros( ( self.ndim, self.ndim_an ), nip=self.nip)

      self.x = r.zeros( (self.nbasis, 1) )
      self.y = r.zeros( (self.nbasis, 1) )
      self.z = r.zeros( (self.nbasis, 1) )

      self.detJ = r.zero(  nip=self.nip )
      self.w_dJ = r.zero(  nip=self.nip )

      self.compute_Jinv = compute_Jinv

      if compute_Jinv :

        self.Jinv = r.zeros( ( self.ndim_an, self.ndim ), nip=self.nip)
        
        # Allocate the cartesian derivatives of basis functions.
        self.Nx   = r.zeros( ( 1, self.nbasis ), nip=self.nip)
        self.Ny   = r.zeros( ( 1, self.nbasis ), nip=self.nip)
        self.Nz   = r.zeros( ( 1, self.nbasis ), nip=self.nip)
      
      # end if 

    else:

      raise ValueError("Element must be allocated first. "+
        "Trying to allocate spatial coordinates with no allocated element.")

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef is_allocated(self):
    """
    Return boolean if the element is allocated.
    """

    return elemd_is_allocated(&self.elem)

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
    self.J.set(0) 

    self.x.set(0)
    self.y.set(0)
    self.z.set(0)

    self.detJ.set(0)
    self.w_dJ.set(0)

    if self.compute_Jinv :

      self.Jinv.set(0)
      
      self.Nx.set(0)
      self.Ny.set(0)
      self.Nz.set(0)

    # end if

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef end(self):
    """
    Finalize element memory allocation.
    """
    if (self.FLAGS & 1):
      
      elemd_end(&self.elem)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def set_coordinates(self, dmat x, dmat y, dmat z, np.ndarray elem_indices):
    """
    DESCRIPTION: Set the coordinates of an OTI number from the global vertices coordinates and the given
                 elemental indices

    INPUTS:
      
      -> x, y, z:        Global vertices coordinates.
      -> elem_indices:   Array with the indices of the corresponding elements in the .

    OUTPUTS: 

      None. Things occur internally.
    """
    
    cdef uint64_t i, j

    for i in range(self.nbasis):
      
      j = elem_indices[i]

      self.x[ i, 0 ] = x[ j, 0 ]
      self.y[ i, 0 ] = y[ j, 0 ]
      self.z[ i, 0 ] = z[ j, 0 ]

    # end for

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def compute_jacobian(self):
    """
    DESCRIPTION: Compute jacobian and derived functions.

    INPUTS:
      
      -> x, y, z:        Global vertices coordinates.
      -> elem_indices:   Array with the indices of the corresponding elements in the .

    OUTPUTS: 

      None. Things occur internally.

    """
    
    cdef uint64_t i, j

    cdef r.dnumfe tmp1, tmp2, tmp3, tmp4
    
    tmp1 = r.zero(nip=self.nip)
    
    if self.ndim == 1:
      
      if   self.ndim_an == 1:
        
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        r.dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
     
      elif self.ndim_an == 2:
      
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        r.dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        r.dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1
      
      else:
      
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        # self.J[0,2] = dot(self.Nxi,  self.z)[0,0]
        r.dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        r.dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1
        r.dot_product(self.Nxi,  self.z, out = tmp1)
        self.J[0,2] = tmp1
      
      # end if

    elif self.ndim == 2:
      
      if self.ndim_an == 2:
        
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        
        # self.J[1,0] = dot(self.Neta, self.x)[0,0]
        # self.J[1,1] = dot(self.Neta, self.y)[0,0]

        r.dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        r.dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1

        r.dot_product(self.Neta,  self.x, out = tmp1)
        self.J[1,0] = tmp1
        r.dot_product(self.Neta,  self.y, out = tmp1)
        self.J[1,1] = tmp1

      else:

        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        # self.J[0,2] = dot(self.Nxi,  self.z)[0,0]

        # self.J[1,0] = dot(self.Neta, self.x)[0,0]
        # self.J[1,1] = dot(self.Neta, self.y)[0,0]
        # self.J[1,2] = dot(self.Neta, self.z)[0,0]

        r.dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        r.dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1
        r.dot_product(self.Nxi,  self.z, out = tmp1)
        self.J[0,2] = tmp1

        r.dot_product(self.Neta,  self.x, out = tmp1)
        self.J[1,0] = tmp1
        r.dot_product(self.Neta,  self.y, out = tmp1)
        self.J[1,1] = tmp1
        r.dot_product(self.Neta,  self.z, out = tmp1)
        self.J[1,2] = tmp1


      # end if

    else: # ndim == 3

      # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
      # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
      # self.J[0,2] = dot(self.Nxi,  self.z)[0,0]

      # self.J[1,0] = dot(self.Neta, self.x)[0,0]
      # self.J[1,1] = dot(self.Neta, self.y)[0,0]
      # self.J[1,2] = dot(self.Neta, self.z)[0,0]

      # self.J[2,0] = dot(self.Nzeta,self.x)[0,0]
      # self.J[2,1] = dot(self.Nzeta,self.y)[0,0]
      # self.J[2,2] = dot(self.Nzeta,self.z)[0,0]
      
      r.dot_product(self.Nxi,  self.x, out = tmp1)
      self.J[0,0] = tmp1
      r.dot_product(self.Nxi,  self.y, out = tmp1)
      self.J[0,1] = tmp1
      r.dot_product(self.Nxi,  self.z, out = tmp1)
      self.J[0,2] = tmp1

      r.dot_product(self.Neta,  self.x, out = tmp1)
      self.J[1,0] = tmp1
      r.dot_product(self.Neta,  self.y, out = tmp1)
      self.J[1,1] = tmp1
      r.dot_product(self.Neta,  self.z, out = tmp1)
      self.J[1,2] = tmp1

      r.dot_product(self.Nzeta,  self.x, out = tmp1)
      self.J[2,0] = tmp1
      r.dot_product(self.Nzeta,  self.y, out = tmp1)
      self.J[2,1] = tmp1
      r.dot_product(self.Nzeta,  self.z, out = tmp1)
      self.J[2,2] = tmp1
      
    # end if 

    if self.ndim == self.ndim_an:
      
      r.det(self.J, out = self.detJ)
      
      r.mul(self.w, self.detJ, out = self.w_dJ)
            # self.w_dJ = self.w * self.detJ

      if self.compute_Jinv:

        r.inv( self.J , out = self.Jinv)

        tmp2 = r.zero(nip=self.nip)
        tmp3 = r.zero(nip=self.nip)
        # tmp4 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
        
        if self.ndim_an == 1:

          r.dot( self.Jinv, self.Nxi, out = self.Nx )

        elif self.ndim_an == 2:

          for i in range(self.nbasis):

            # self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i]  
            # self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i]
            self.Jinv.get_item_ij(0,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            r.mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(0,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            r.sum(tmp3,tmp2,out=tmp2)
            self.Nx[0,i]= tmp2


            self.Jinv.get_item_ij(1,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            r.mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(1,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            r.sum(tmp2,tmp3,out=tmp2)
            self.Ny[0,i]= tmp2

          # end for

        else:
          
          for i in range(self.nbasis):

            # self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i] + self.Jinv[0,2]*self.Nzeta[0,i] 
            # self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i] + self.Jinv[1,2]*self.Nzeta[0,i] 
            # self.Nz[0,i] = self.Jinv[2,0]*self.Nxi[0,i] + self.Jinv[2,1]*self.Neta[0,i] + self.Jinv[2,2]*self.Nzeta[0,i] 

            self.Jinv.get_item_ij(0,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            r.mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(0,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            self.Jinv.get_item_ij(0,2,out=tmp1); self.Nzeta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            r.sum(tmp3,tmp2,out=tmp2)
            self.Nx[0,i]= tmp2

            self.Jinv.get_item_ij(1,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            r.mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(1,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            self.Jinv.get_item_ij(1,2,out=tmp1); self.Nzeta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            r.sum(tmp3,tmp2,out=tmp2)
            self.Ny[0,i]= tmp2

            self.Jinv.get_item_ij(2,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            r.mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(2,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            self.Jinv.get_item_ij(2,2,out=tmp1); self.Nzeta.get_item_ij(0,i,out=tmp3)
            r.mul(tmp1,tmp3,out=tmp3)
            r.sum(tmp3,tmp2,out=tmp2)
            self.Nz[0,i]= tmp2

          # end for

        # end if 

      # end if

    elif self.ndim == 1:
      
      self.detJ.set(0) # Necessary?
      
      tmp2 = r.zero(nip=self.nip)
      tmp3 = r.zero(nip=self.nip)
      
      for i in range(self.ndim_an):
        # self.detJ += self.J[0,i]**2
        self.J.get_item_ij( 0, i, out =  tmp1 )
        r.pow(      tmp1,    2, out =      tmp1 )
        r.sum( self.detJ, tmp1, out = self.detJ )
      # end for

      # self.detJ = sqrt(self.detJ)
      r.sqrt(self.detJ,out=self.detJ)

      # self.w_dJ = self.w * self.detJ
      r.mul( self.w, self.detJ, out=self.w_dJ)

    else:

      self.detJ.set(0) # Necessary?

      tmp2 = r.zero( nip=self.nip )
      tmp3 = r.zero( nip=self.nip )

      # self.detJ += (self.J[0,1]*self.J[1,2]-self.J[0,2]*self.J[1,1])**2
      # self.detJ += (self.J[0,2]*self.J[1,0]-self.J[0,0]*self.J[1,2])**2
      # self.detJ += (self.J[0,0]*self.J[1,1]-self.J[0,1]*self.J[1,0])**2


      self.J.get_item_ij(0,1,out=tmp1); self.J.get_item_ij(1,2,out=tmp2)
      r.mul(tmp1,tmp2,out=tmp2)
      self.J.get_item_ij(0,2,out=tmp1); self.J.get_item_ij(1,1,out=tmp3)
      r.mul(tmp1,tmp3,out=tmp3)
      r.sub(tmp2,tmp3,out=tmp2)
      r.pow(tmp2,2,out=tmp2)
      r.sum(self.detJ,tmp2,out=self.detJ)

      self.J.get_item_ij(0,2,out=tmp1); self.J.get_item_ij(1,0,out=tmp2)
      r.mul(tmp1,tmp2,out=tmp2)
      self.J.get_item_ij(0,0,out=tmp1); self.J.get_item_ij(1,2,out=tmp3)
      r.mul(tmp1,tmp3,out=tmp3)
      r.sub(tmp2,tmp3,out=tmp2)
      r.pow(tmp2,2,out=tmp2)
      r.sum(self.detJ,tmp2,out=self.detJ)

      self.J.get_item_ij(0,0,out=tmp1); self.J.get_item_ij(1,1,out=tmp2)
      r.mul(tmp1,tmp2,out=tmp2)
      self.J.get_item_ij(0,1,out=tmp1); self.J.get_item_ij(1,0,out=tmp3)
      r.mul(tmp1,tmp3,out=tmp3)
      r.sub(tmp2,tmp3,out=tmp2)
      r.pow(tmp2,2,out=tmp2)
      r.sum(self.detJ,tmp2,out=self.detJ)
      
      # self.detJ = sqrt(self.detJ)
      r.sqrt(self.detJ,out=self.detJ)

      # self.w_dJ = self.w * self.detJ
      r.mul( self.w, self.detJ, out=self.w_dJ)

    # end if 

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def compute_jacobian_bruteforce(self):
    """
    DESCRIPTION: Compute jacobian and derived functions.

    INPUTS:
      
      -> x, y, z:        Global vertices coordinates.
      -> elem_indices:   Array with the indices of the corresponding elements in the .

    OUTPUTS: 

      None. Things occur internally.

    """
    
    cdef uint64_t i, j

    # cdef dnumfe tmp1, tmp2, tmp3, tmp4
    
    # tmp1 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
    
    if self.ndim == 1:
      
      if   self.ndim_an == 1:
        
        self.J[0,0] = r.dot(self.Nxi,  self.x)[0,0]
             
      elif self.ndim_an == 2:
      
        self.J[0,0] = r.dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = r.dot(self.Nxi,  self.y)[0,0]
              
      else:
      
        self.J[0,0] = r.dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = r.dot(self.Nxi,  self.y)[0,0]
        self.J[0,2] = r.dot(self.Nxi,  self.z)[0,0]
              
      # end if

    elif self.ndim == 2:
      
      if self.ndim_an == 2:
        
        self.J[0,0] = r.dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = r.dot(self.Nxi,  self.y)[0,0]
        
        self.J[1,0] = r.dot(self.Neta, self.x)[0,0]
        self.J[1,1] = r.dot(self.Neta, self.y)[0,0]

      else:

        self.J[0,0] = r.dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = r.dot(self.Nxi,  self.y)[0,0]
        self.J[0,2] = r.dot(self.Nxi,  self.z)[0,0]

        self.J[1,0] = r.dot(self.Neta, self.x)[0,0]
        self.J[1,1] = r.dot(self.Neta, self.y)[0,0]
        self.J[1,2] = r.dot(self.Neta, self.z)[0,0]

      # end if

    else:

      self.J[0,0] = r.dot(self.Nxi,  self.x)[0,0]
      self.J[0,1] = r.dot(self.Nxi,  self.y)[0,0]
      self.J[0,2] = r.dot(self.Nxi,  self.z)[0,0]

      self.J[1,0] = r.dot(self.Neta, self.x)[0,0]
      self.J[1,1] = r.dot(self.Neta, self.y)[0,0]
      self.J[1,2] = r.dot(self.Neta, self.z)[0,0]

      self.J[2,0] = r.dot(self.Nzeta,self.x)[0,0]
      self.J[2,1] = r.dot(self.Nzeta,self.y)[0,0]
      self.J[2,2] = r.dot(self.Nzeta,self.z)[0,0]

    # end if 

    if self.ndim == self.ndim_an:
      
      r.det(self.J, out = self.detJ)
      self.w_dJ = self.w * self.detJ

      if self.compute_Jinv:

        r.inv( self.J , out = self.Jinv)
        
        if self.ndim_an == 1:

          r.dot( self.Jinv, self.Nxi, out = self.Nx )

        elif self.ndim_an == 2:

          for i in range(self.nbasis):

            self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i]  
            self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i]
            
          # end for

        else:
          
          for i in range(self.nbasis):

            self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i] + self.Jinv[0,2]*self.Nzeta[0,i] 
            self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i] + self.Jinv[1,2]*self.Nzeta[0,i] 
            self.Nz[0,i] = self.Jinv[2,0]*self.Nxi[0,i] + self.Jinv[2,1]*self.Neta[0,i] + self.Jinv[2,2]*self.Nzeta[0,i] 

          # end for

        # end if 

      # end if

    elif self.ndim == 1:
      
      self.detJ.set(0) # Necessary?
      
      for i in range(self.ndim_an):
        
        self.detJ += self.J[0,i]**2
        
      # end for

      self.detJ = r.sqrt(self.detJ)
      self.w_dJ = self.w * self.detJ

      if self.compute_Jinv:

        # Right inverse ()
        self.Jinv = r.dot( r.transpose(self.J), r.inv( r.dot( self.J, r.transpose(self.J) ) ) )
        
        if self.ndim_an == 2:

          for i in range(self.nbasis):

            self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i]  
            self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i]
            
          # end for

        else:
          
          for i in range(self.nbasis):

            self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i]
            self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i]
            self.Nz[0,i] = self.Jinv[2,0]*self.Nxi[0,i]

          # end for

        # end if 

      # end if

    else:

      self.detJ.set(0) # Necessary?

      self.detJ += (self.J[0,1]*self.J[1,2]-self.J[0,2]*self.J[1,1])**2
      self.detJ += (self.J[0,2]*self.J[1,0]-self.J[0,0]*self.J[1,2])**2
      self.detJ += (self.J[0,0]*self.J[1,1]-self.J[0,1]*self.J[1,0])**2

      self.detJ = sqrt( self.detJ )  

      self.w_dJ = self.w * self.detJ

      if self.compute_Jinv:

        # Right inverse
        self.Jinv = r.dot( r.transpose(self.J), r.inv( r.dot( self.J, r.transpose(self.J) ) ) )
        
        for i in range(self.nbasis):

          self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i] 
          self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i] 
          self.Nz[0,i] = self.Jinv[2,0]*self.Nxi[0,i] + self.Jinv[2,1]*self.Neta[0,i] 

        # end for

      # end if

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
  # cpdef integrate(self, object val):
  #   """
  #   PURPOSE:      Integrate a function given it was defined for this element. This is determined by
  #                 the number of integration points and/or shape of the array.
                  
  #   """
    
  #   return res
  # #---------------------------------------------------------------------------------------------------
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elbased :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

cdef set_dnumfe_from_sotife(r.dnumfe dst, sotife src):
  
  cdef uint64_t k
  
  if (dst.num.nip == src.num.nip):
    
    for k in range(src.num.nip):

      dst.num.p_data[k] = src.num.p_data[k].re

    # end for

  # end if 

cdef set_dmatfe_from_sotife(r.dmatfe dst, uint64_t i, uint64_t j,  sotife src):
  
  cdef uint64_t k
  
  if (dst.arr.nip == src.num.nip):
    
    for k in range(src.num.nip):

      fedarr_set_item_ijk_r(src.num.p_data[k].re,i,j,k,&dst.arr)

    # end for

  # end if 
