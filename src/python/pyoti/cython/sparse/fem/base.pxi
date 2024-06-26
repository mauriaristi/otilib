

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

    self.otinbases = 0 
    self.otiorder  = 0 

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
  cpdef allocate(self, uint8_t ndim, uint64_t nbasis, uint64_t nip, bases_t nbases=0, ord_t order=0):
    """
    DESCRIPTION: Allocate all integration points.

    INPUTS:
      
      -> nbasis:            Number of basis.
      -> nip:               Number of integration points.
      -> nbases (Optional): Number of OTI imaginary bases to allocate.
      -> order  (Optional): Truncation order of the OTI members of the number.

    """
    self.ndim      = ndim
    self.nip       = nip
    self.nbasis    = nbasis

    self.otiorder  = order
    self.otinbases = nbases

    self.N     = zeros( ( 1, nbasis ), nip=nip, nbases=nbases, order=order )
    self.Nxi   = zeros( ( 1, nbasis ), nip=nip, nbases=nbases, order=order )
    self.Neta  = zeros( ( 1, nbasis ), nip=nip, nbases=nbases, order=order )
    self.Nzeta = zeros( ( 1, nbasis ), nip=nip, nbases=nbases, order=order )

    self.w    = zero( nip=nip, nbases=nbases, order=order )
    self.xi   = zero( nip=nip, nbases=nbases, order=order )
    self.eta  = zero( nip=nip, nbases=nbases, order=order )
    self.zeta = zero( nip=nip, nbases=nbases, order=order )

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

      self.J = zeros( ( self.ndim, self.ndim_an ), nbases=self.otinbases, order=self.otiorder, nip=self.nip)

      self.x = zeros( ( self.nbasis, 1), nbases=self.otinbases, order=self.otiorder )
      self.y = zeros( ( self.nbasis, 1), nbases=self.otinbases, order=self.otiorder )
      self.z = zeros( ( self.nbasis, 1), nbases=self.otinbases, order=self.otiorder )

      self.detJ = zero( nbases=self.otinbases, order=self.otiorder, nip=self.nip )
      self.dV   = zero( nbases=self.otinbases, order=self.otiorder, nip=self.nip )

      self.compute_Jinv = compute_Jinv

      if compute_Jinv :

        self.Jinv = zeros( ( self.ndim_an, self.ndim ), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
        
        # Allocate the cartesian derivatives of basis functions.
        self.Nx   = zeros( ( 1, self.nbasis ), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
        self.Ny   = zeros( ( 1, self.nbasis ), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
        self.Nz   = zeros( ( 1, self.nbasis ), nbases=self.otinbases, order=self.otiorder, nip=self.nip)
      
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

    self.otiorder  = 0 
    self.otinbases = 0 

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
  def get(self, matso a, np.ndarray elem_indices, out=None):
    """
    DESCRIPTION: Get the elemental array from a global array. That is, extract the nodal values from
                 an array containing information for all the nodes in a domain.

    INPUTS:
      
      -> a:              Global vector.
      -> elem_indices:   Array with the indices of the corresponding degrees of freedom of the element.

    OUTPUTS:

      -> Vector with the corresponding dimension with elemental values.
      
    """
     
    cdef uint64_t i, j
    cdef uint8_t res_flag = 1
    cdef matso res

    if out is None:
      res_flag = 0
      res = out
    else:
      res = zeros( (self.nbasis,1) ) 
    # end if 

    # Get element nodal values
    for i in range(self.nbasis):      
      j = elem_indices[i]
      res[ i, 0 ] = a[ j, 0 ]
    # end for

    if res_flag:
      return res
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def set_coordinates(self, matso x, matso y, matso z, np.ndarray elem_indices):
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
  cpdef set_array(self, matso arr, np.ndarray elem_indices, matso out = None):
    """
    DESCRIPTION: Set the elements of an array from global to local indices.

    INPUTS:
      
      -> arr: Array in global numbering.
      -> elem_indices:   Array with the indices of the corresponding elements in the mesh.

    """
    
    cdef uint64_t i, j, ii, ncols
    cdef matso res 

    ncols = arr.shape[1]

    if out is not None:
      res = out
    else:
      res = zeros(( self.nbasis , ncols ))
    # end if 


    for i in range(self.nbasis):
      
      for j in range(ncols):
      
        ii = elem_indices[i]

        res[ i, j ] = arr[ ii, j ]
      
      # end for 

    # end for

    if out is None:
      return res
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_local(self, matso arr, np.ndarray elem_indices, matso out=None):
    """
    DESCRIPTION: get the local items from an array.

    INPUTS:
      
      -> arr:            Global array. 
      -> elem_indices:   Array with the element nodal indices.

    """
    
    """
    DESCRIPTION: Set the elements of an array from global to local indices.

    INPUTS:
      
      -> arr: Array in global numbering.
      -> elem_indices:   Array with the indices of the corresponding elements in the mesh.

    """
    
    cdef uint64_t i, j, ii, ncols
    cdef matso res 

    ncols = arr.shape[1]

    if out is not None:
      res = out
    else:
      res = zeros(( self.nbasis , ncols ))
    # end if 


    for i in range(self.nbasis):
      
      ii = elem_indices[i]

      for j in range(ncols):
      
        res[ i, j ] = arr[ ii, j ]
      
      # end for 

    # end for

    if out is None:
      return res
    # end if 

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

    cdef sotife tmp1, tmp2, tmp3, tmp4
    
    tmp1 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
    
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
        
        tmp2 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
        tmp3 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
        # tmp4 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
        
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
      
      tmp2 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
      tmp3 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
      
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

      tmp2 = zero( nip=self.nip, nbases = self.otinbases, order=self.otiorder)
      tmp3 = zero( nip=self.nip, nbases = self.otinbases, order=self.otiorder)

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

    # cdef sotife tmp1, tmp2, tmp3, tmp4
    
    # tmp1 = zero(nip=self.nip, nbases = self.otinbases, order=self.otiorder)
    
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

  #***************************************************************************************************
  cpdef integrate(self, object val, object out = None ):
    """
    DESCRIPTION: Domain integral over the element.

    INPUTS:
      
      -> val:  Function that will be integrated.
      -> out(optional): Preallocated array to receive the result.

    OUTPUTS: 

      If out is None, then an ouput is returned with the correct result.

    """

    return gauss_integrate(val,self.dV, out=out)

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS ELM_HELP :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
