

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  ELM_HELP    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elm_help:
  
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

    self.special   = None

    self.nbasis    = 0 
    self.nip       = 0 
    self.ndim_an   = 0  

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
    self.dV        = None 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """

    PURPOSE:      Destructor of the base element class. 

    """
    #*************************************************************************************************
    
    self.end()

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

    head += "< elm_help object: \n"
    tail += "end elm_help object >"

    if (self.is_allocated( )):

      body += " - Object allocation: ------------ " + "Allocated"+"\n"
      body += " - Number of Integration points: - " + str(self.nip)+"\n"
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

    else:
      body += " - Object allocation: -------------- " + "Not allocated"+"\n"
    # end if

    return head + body + tail

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef allocate(self, uint8_t ndim, uint64_t nbasis, uint64_t nip):
    """
    DESCRIPTION: Allocate all integration points.

    INPUTS:
      
      -> nbasis:            Number of basis.
      -> nip:               Number of integration points.

    """
    self.ndim      = ndim
    self.nip       = nip
    self.nbasis    = nbasis

    self.N     = zeros( ( 1, nbasis ), nip=nip )
    self.Nxi   = zeros( ( 1, nbasis ), nip=nip )
    self.Neta  = zeros( ( 1, nbasis ), nip=nip )
    self.Nzeta = zeros( ( 1, nbasis ), nip=nip )

    self.w    = zero( nip=nip )
    self.xi   = zero( nip=nip )
    self.eta  = zero( nip=nip )
    self.zeta = zero( nip=nip )

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

    if self.is_allocated():

      self.ndim_an = ndim_an

      self.J = zeros( ( self.ndim, self.ndim_an ), nip=self.nip)

      self.x = zeros( ( self.nbasis, 1) )
      self.y = zeros( ( self.nbasis, 1) )
      self.z = zeros( ( self.nbasis, 1) )

      self.detJ = zero( nip=self.nip )
      self.dV   = zero( nip=self.nip )

      self.compute_Jinv = compute_Jinv

      if compute_Jinv :

        self.Jinv = zeros( ( self.ndim_an, self.ndim ), nip=self.nip)
        
        # Allocate the cartesian derivatives of basis functions.
        self.Nx   = zeros( ( 1, self.nbasis ), nip=self.nip)
        self.Ny   = zeros( ( 1, self.nbasis ), nip=self.nip)
        self.Nz   = zeros( ( 1, self.nbasis ), nip=self.nip)
      
      # end if 

    else:
      raise ValueError("elm_help must be allocated first. "+
        "Trying to allocate spatial coordinates with no allocated element.")
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef is_allocated(self):
    """
    Return boolean if the element is allocated.
    """
    res = True
    # if  (self.xi   is None) or (self.eta   is None) or (self.zeta  is None) or \
    #     (self.w    is None) or (self.N     is None) or (self.Nxi   is None) or \
    #     (self.Neta is None) or (self.Nzeta is None) or (self.Nx    is None) or \
    #     (self.Nz   is None) or (self.x     is None) or (self.y     is None) or \
    #     (self.z    is None) or (self.J     is None) or (self.dV    is None) or \
    #     (self.Ny   is None) or (self.detJ  is None) or (self.Jinv  is None)    :
    if  (self.w     is None) : # Fast check for allocation.
      res = False
    # end if 

    return res

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
    self.dV.set(0)

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
    self.special   = None

    self.nbasis    = 0 
    self.nip       = 0 
    self.ndim_an   = 0 

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
    self.dV        = None

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def set_coordinates(self, omatm2n9 x, omatm2n9 y, omatm2n9 z, np.ndarray elem_indices):
    """
    DESCRIPTION: Set the coordinates of an OTI number from the global vertices coordinates and the given
                 elemental indices

    INPUTS:
      
      -> x, y, z:        Global vertices coordinates.
      -> elem_indices:   Array with the indices of the corresponding elements in the .

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

    cdef feonumm2n9 tmp1, tmp2, tmp3, tmp4
    
    tmp1 = zero(nip=self.nip)
    
    if self.ndim == 1:
      
      if   self.ndim_an == 1:
        
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
     
      elif self.ndim_an == 2:
      
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1
      
      else:
      
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        # self.J[0,2] = dot(self.Nxi,  self.z)[0,0]
        dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1
        dot_product(self.Nxi,  self.z, out = tmp1)
        self.J[0,2] = tmp1
      
      # end if

    elif self.ndim == 2:
      
      if self.ndim_an == 2:
        
        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        
        # self.J[1,0] = dot(self.Neta, self.x)[0,0]
        # self.J[1,1] = dot(self.Neta, self.y)[0,0]

        dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1

        dot_product(self.Neta,  self.x, out = tmp1)
        self.J[1,0] = tmp1
        dot_product(self.Neta,  self.y, out = tmp1)
        self.J[1,1] = tmp1

      else:

        # self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        # self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        # self.J[0,2] = dot(self.Nxi,  self.z)[0,0]

        # self.J[1,0] = dot(self.Neta, self.x)[0,0]
        # self.J[1,1] = dot(self.Neta, self.y)[0,0]
        # self.J[1,2] = dot(self.Neta, self.z)[0,0]

        dot_product(self.Nxi,  self.x, out = tmp1)
        self.J[0,0] = tmp1
        dot_product(self.Nxi,  self.y, out = tmp1)
        self.J[0,1] = tmp1
        dot_product(self.Nxi,  self.z, out = tmp1)
        self.J[0,2] = tmp1

        dot_product(self.Neta,  self.x, out = tmp1)
        self.J[1,0] = tmp1
        dot_product(self.Neta,  self.y, out = tmp1)
        self.J[1,1] = tmp1
        dot_product(self.Neta,  self.z, out = tmp1)
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
      
      dot_product(self.Nxi,  self.x, out = tmp1)
      self.J[0,0] = tmp1
      dot_product(self.Nxi,  self.y, out = tmp1)
      self.J[0,1] = tmp1
      dot_product(self.Nxi,  self.z, out = tmp1)
      self.J[0,2] = tmp1

      dot_product(self.Neta,  self.x, out = tmp1)
      self.J[1,0] = tmp1
      dot_product(self.Neta,  self.y, out = tmp1)
      self.J[1,1] = tmp1
      dot_product(self.Neta,  self.z, out = tmp1)
      self.J[1,2] = tmp1

      dot_product(self.Nzeta,  self.x, out = tmp1)
      self.J[2,0] = tmp1
      dot_product(self.Nzeta,  self.y, out = tmp1)
      self.J[2,1] = tmp1
      dot_product(self.Nzeta,  self.z, out = tmp1)
      self.J[2,2] = tmp1
      
    # end if 

    if self.ndim == self.ndim_an:
      
      det(self.J, out = self.detJ)
      
      mul(self.w, self.detJ, out = self.dV)
            # self.dV = self.w * self.detJ

      if self.compute_Jinv:

        inv( self.J , out = self.Jinv)

        tmp2 = zero(nip=self.nip)
        tmp3 = zero(nip=self.nip)
        # tmp4 = zero(nip=self.nip)
        
        if self.ndim_an == 1:

          dot( self.Jinv, self.Nxi, out = self.Nx )

        elif self.ndim_an == 2:

          for i in range(self.nbasis):

            # self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i]  
            # self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i]
            self.Jinv.get_item_ij(0,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(0,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Nx[0,i]= tmp2

            self.Jinv.get_item_ij(1,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(1,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp2,tmp3,out=tmp2)
            self.Ny[0,i]= tmp2

          # end for

        else:
          
          for i in range(self.nbasis):

            # self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i] + self.Jinv[0,2]*self.Nzeta[0,i] 
            # self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i] + self.Jinv[1,2]*self.Nzeta[0,i] 
            # self.Nz[0,i] = self.Jinv[2,0]*self.Nxi[0,i] + self.Jinv[2,1]*self.Neta[0,i] + self.Jinv[2,2]*self.Nzeta[0,i] 

            self.Jinv.get_item_ij(0,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(0,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Jinv.get_item_ij(0,2,out=tmp1); self.Nzeta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Nx[0,i]= tmp2

            self.Jinv.get_item_ij(1,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(1,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Jinv.get_item_ij(1,2,out=tmp1); self.Nzeta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Ny[0,i]= tmp2

            self.Jinv.get_item_ij(2,0,out=tmp1); self.Nxi.get_item_ij(0,i,out=tmp2)
            mul(tmp1,tmp2,out=tmp2)
            self.Jinv.get_item_ij(2,1,out=tmp1); self.Neta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Jinv.get_item_ij(2,2,out=tmp1); self.Nzeta.get_item_ij(0,i,out=tmp3)
            mul(tmp1,tmp3,out=tmp3)
            sum(tmp3,tmp2,out=tmp2)
            self.Nz[0,i]= tmp2

          # end for

        # end if 

      # end if

    elif self.ndim == 1:
      
      self.detJ.set(0) # Necessary?
      
      tmp2 = zero(nip=self.nip)
      tmp3 = zero(nip=self.nip)
      
      for i in range(self.ndim_an):
        # self.detJ += self.J[0,i]**2
        self.J.get_item_ij( 0, i, out =  tmp1 )
        pow(      tmp1,    2, out =      tmp1 )
        sum( self.detJ, tmp1, out = self.detJ )
      # end for

      # self.detJ = sqrt(self.detJ)
      sqrt(self.detJ,out=self.detJ)

      # self.dV = self.w * self.detJ
      mul( self.w, self.detJ, out=self.dV)

    else:

      self.detJ.set(0) # Necessary?

      tmp2 = zero( nip=self.nip)
      tmp3 = zero( nip=self.nip)

      # self.detJ += (self.J[0,1]*self.J[1,2]-self.J[0,2]*self.J[1,1])**2
      # self.detJ += (self.J[0,2]*self.J[1,0]-self.J[0,0]*self.J[1,2])**2
      # self.detJ += (self.J[0,0]*self.J[1,1]-self.J[0,1]*self.J[1,0])**2

      self.J.get_item_ij(0,1,out=tmp1); self.J.get_item_ij(1,2,out=tmp2)
      mul(tmp1,tmp2,out=tmp2)
      self.J.get_item_ij(0,2,out=tmp1); self.J.get_item_ij(1,1,out=tmp3)
      mul(tmp1,tmp3,out=tmp3)
      sub(tmp2,tmp3,out=tmp2)
      pow(tmp2,2,out=tmp2)
      sum(self.detJ,tmp2,out=self.detJ)

      self.J.get_item_ij(0,2,out=tmp1); self.J.get_item_ij(1,0,out=tmp2)
      mul(tmp1,tmp2,out=tmp2)
      self.J.get_item_ij(0,0,out=tmp1); self.J.get_item_ij(1,2,out=tmp3)
      mul(tmp1,tmp3,out=tmp3)
      sub(tmp2,tmp3,out=tmp2)
      pow(tmp2,2,out=tmp2)
      sum(self.detJ,tmp2,out=self.detJ)

      self.J.get_item_ij(0,0,out=tmp1); self.J.get_item_ij(1,1,out=tmp2)
      mul(tmp1,tmp2,out=tmp2)
      self.J.get_item_ij(0,1,out=tmp1); self.J.get_item_ij(1,0,out=tmp3)
      mul(tmp1,tmp3,out=tmp3)
      sub(tmp2,tmp3,out=tmp2)
      pow(tmp2,2,out=tmp2)
      sum(self.detJ,tmp2,out=self.detJ)
      
      # self.detJ = sqrt(self.detJ)
      sqrt(self.detJ,out=self.detJ)

      # self.dV = self.w * self.detJ
      mul( self.w, self.detJ, out=self.dV)

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

    # cdef feonumm2n9 tmp1, tmp2, tmp3, tmp4
    
    # tmp1 = zero(nip=self.nip)
    
    if self.ndim == 1:
      
      if   self.ndim_an == 1:
        
        self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
             
      elif self.ndim_an == 2:
      
        self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
              
      else:
      
        self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        self.J[0,2] = dot(self.Nxi,  self.z)[0,0]
              
      # end if

    elif self.ndim == 2:
      
      if self.ndim_an == 2:
        
        self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        
        self.J[1,0] = dot(self.Neta, self.x)[0,0]
        self.J[1,1] = dot(self.Neta, self.y)[0,0]

      else:

        self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
        self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
        self.J[0,2] = dot(self.Nxi,  self.z)[0,0]

        self.J[1,0] = dot(self.Neta, self.x)[0,0]
        self.J[1,1] = dot(self.Neta, self.y)[0,0]
        self.J[1,2] = dot(self.Neta, self.z)[0,0]

      # end if

    else:

      self.J[0,0] = dot(self.Nxi,  self.x)[0,0]
      self.J[0,1] = dot(self.Nxi,  self.y)[0,0]
      self.J[0,2] = dot(self.Nxi,  self.z)[0,0]

      self.J[1,0] = dot(self.Neta, self.x)[0,0]
      self.J[1,1] = dot(self.Neta, self.y)[0,0]
      self.J[1,2] = dot(self.Neta, self.z)[0,0]

      self.J[2,0] = dot(self.Nzeta,self.x)[0,0]
      self.J[2,1] = dot(self.Nzeta,self.y)[0,0]
      self.J[2,2] = dot(self.Nzeta,self.z)[0,0]

    # end if 

    if self.ndim == self.ndim_an:
      
      det(self.J, out = self.detJ)
      self.dV = self.w * self.detJ

      if self.compute_Jinv:

        inv( self.J , out = self.Jinv)
        
        if self.ndim_an == 1:

          dot( self.Jinv, self.Nxi, out = self.Nx )

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

      self.detJ = sqrt(self.detJ)
      self.dV = self.w * self.detJ

      if self.compute_Jinv:

        # Right inverse ()
        self.Jinv = dot( transpose(self.J), inv( dot( self.J, transpose(self.J) ) ) )
        
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

      self.dV = self.w * self.detJ

      if self.compute_Jinv:

        # Right inverse
        self.Jinv = dot( transpose(self.J), inv( dot( self.J, transpose(self.J) ) ) )
        
        for i in range(self.nbasis):

          self.Nx[0,i] = self.Jinv[0,0]*self.Nxi[0,i] + self.Jinv[0,1]*self.Neta[0,i] 
          self.Ny[0,i] = self.Jinv[1,0]*self.Nxi[0,i] + self.Jinv[1,1]*self.Neta[0,i] 
          self.Nz[0,i] = self.Jinv[2,0]*self.Nxi[0,i] + self.Jinv[2,1]*self.Neta[0,i] 

        # end for

      # end if

    # end if 

  #---------------------------------------------------------------------------------------------------

 
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS ELM_HELP :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
