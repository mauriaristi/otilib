

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  lil_{arr_pytype}    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class lil_{arr_pytype}:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, shape): 
    """
    PURPOSE:      Python level constructor of the lil_{arr_pytype} class.

    DESCRIPTION:  Creates a new empty lil_{arr_pytype} matrix.
                 
    """
    #*************************************************************************************************
    
    cdef uint64_t i

    if isinstance( shape, tuple) and len(shape) == 2:
      
      self.nrows = shape[0]
      self.ncols = shape[1]

      self.size = self.nrows*self.ncols
      
      self.rows = np.empty((self.nrows,), dtype=object)
      self.data = np.empty((self.nrows,), dtype=object)

      for i in range(self.nrows):
      
        self.data[i] = []
        self.rows[i] = []

      # end for 

    else:

      raise ValueError("Wrong shape format. Only 2x2 matrix are supported.")

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nnz(self): 
    """
    PURPOSE:      Return the number of non-zero elements in the stored matrix. 
    """
    #*************************************************************************************************

    cdef uint64_t nnz = 0, i

    for i in range(self.nrows):
      nnz += len(self.data[i])
    # end for 

    return nnz

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return (self.nrows,self.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def data(self): 
    """
    PURPOSE:      Return the data list of lists of the stored matrix. 
    """
    #*************************************************************************************************

    return np.array(self.data)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def rows(self): 
    """
    PURPOSE:      Return the rows list of lists of the stored matrix. 
    """
    #*************************************************************************************************

    return np.array(self.rows)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************
    cdef ord_t order = 0
    cdef uint64_t i, j

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        order = max(order,self.data[i][j].order )

      # end for 

    # end if 

    return order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef np.ndarray[coeff_t, ndim=1] data
    cdef np.ndarray[np.int32_t, ndim=1] rows
    cdef np.ndarray[np.int32_t, ndim=1] cols
    cdef list tmp_list
    cdef uint64_t i,j,k = 0, nnz

    nnz  = self.nnz
    data = np.empty( (nnz,), dtype=np.float64 )
    rows = np.empty( (nnz,), dtype=np.int32   )
    cols = np.empty( (nnz,), dtype=np.int32   )

    for i in range( self.nrows ):

      for j in range( len(self.data[i]) ):

        rows[k] = i
        cols[k] = self.rows[i][j]
        data[k] = self.data[i][j].real
        
        k     += 1

      # end for

    # end for

    return sci_spr.csr_matrix((data,(rows,cols)), shape = self.shape).tolil()

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #*************************************************************************************************

    out  = "<{{0}} sparse matrix of OTI numbers with \n".format(self.shape)
    out += "         {{0}} stored elements in LInked List format>".format(self.nnz)

    return out

  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************

    cdef uint64_t i, j, k
    out  = ""

    for i in range( self.nrows ):

      for j in range( len(self.data[i]) ):

        out += "({{0:3d}},{{1:3d}}) {{2}}\n".format( i, self.rows[i][j], self.data[i][j] )
        
      # end for

    # end for

    # out  += "\n"

    return out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    

    cdef object res = None
    cdef uint64_t i, j, pos

    tval = type(val)
    
    if tval == tuple and len(val) == 2:

      i, j = val
    
      if i < self.nrows and j < self.ncols:

        row  = self.rows[i]
        data = self.data[i]

        pos = binSearch_list( row, j )

        if pos != len(row) and row[pos] == j : # New element required
          
          res = data[pos].copy()

        else:

          res = {num_pytype}(0.0)

        # end if 
        
      else:

        raise IndexError("Index out of bounds {0} for shape {1}.".format(val,self.shape))

      # end if 

    else:

      raise IndexError("Only integer pair ( , ) is suported for element indexing.")

    # end if

    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
        
    

    cdef {num_pytype} valt
    cdef uint64_t i, j, k, l, pos
    cdef list row, data
    
    tval = type(value)

    if (isinstance(val, tuple)):
      
      if tval == {num_pytype}:
        
        valt = value.copy()

      else:
        
        valt = {num_pytype}( value )

      # end if 

      i, j = val
      
      if i < self.nrows and j < self.ncols:

        row  = self.rows[i]
        data = self.data[i]

        pos = binSearch_list( row, j )

        if pos == len(row) : # New element required
          
          row.append(j)  
          data.append(valt)

        elif row[pos] != j : # Position does not exist, so data is inserted
          
          row.insert(pos,    j)  
          data.insert(pos, valt)

        else:

          data[pos] = valt

        # end if 

      else:

        raise IndexError("Index out of bounds {0} for shape {1}.".format(val,self.shape))

      # end if 

    else:

      raise IndexError("Only ( , ) integer tuples allowed for setting an element in the matrix.")

    # end if


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE: Deep copy to a new object.
    """
    #*************************************************************************************************
    
    

    cdef lil_{arr_pytype} res = lil_{arr_pytype}(self.shape)
    cdef uint64_t i, k
    
    for i in range(self.nrows):

      res.data[i] = [None]*len(self.data[i])  
      res.rows[i] = self.rows[i].copy()

      for j in range(len(self.data[i])):

        res.data[i][j] = self.data[i][j].copy()

      # end for 

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def zeros_like(self):
    """
    PURPOSE: Create new object with OTI zeros in positions.
    """
    #*************************************************************************************************
    
    

    cdef lil_{arr_pytype} res = lil_{arr_pytype}(self.shape)
    cdef uint64_t i, j
    
    for i in range(self.nrows):

      res.data[i] = [None]*len(self.data[i])  
      res.rows[i] = self.rows[i].copy()

      for j in range(len(self.data[i])):

        res.data[i][j] = {num_pytype}(0.0)

      # end for 

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_deriv(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef lil_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        ores = res.data[i][j]
        oval = self.data[i][j]
        {num_func}_get_deriv_to( indx, order, &oval.num, &ores.num)

      # end for 

    # end if 

    return res 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_im(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef lil_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        ores = res.data[i][j]
        oval = self.data[i][j]
        {num_func}_get_im_to_o( indx, order, &oval.num, &ores.num)

      # end for 

    # end if 

    return res 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef extract_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the {arr_pytype} object.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef lil_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        ores = res.data[i][j]
        oval = self.data[i][j]
        {num_func}_extract_im_to( indx, order, &oval.num, &ores.num)

      # end for 

    # end if 

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  extract_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding derivative in the {arr_pytype} object, as OTI number.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef lil_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        ores = res.data[i][j]
        oval = self.data[i][j]
        {num_func}_extract_deriv_to( indx, order, &oval.num, &ores.num)

      # end for 

    # end if 

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the {arr_pytype} object, as OTI number.
    """
    #*************************************************************************************************
    
    
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef lil_{arr_pytype} res

    res = self.zeros_like()

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        ores = res.data[i][j]
        oval = self.data[i][j]
        {num_func}_get_order_im_to( order, &oval.num, &ores.num)

      # end for 

    # end if

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object hum_dir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef lil_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.nrows):

      for j in range(len(self.data[i])):
        
        ores = res.data[i][j]
        oval = self.data[i][j]
        {num_func}_truncate_im_to( indx, order, &oval.num, &ores.num)

      # end for 

    # end if 

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def tocsr(self):
    """
    PORPUSE:  Convert the matrix to CSR format.
    """
    return csr_{arr_pytype}(self,shape=self.shape)

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS {arr_pytype} :::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

