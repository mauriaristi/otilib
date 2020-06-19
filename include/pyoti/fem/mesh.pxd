
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTIMESH    :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class mesh:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  
  cdef public list            elements    # List of elements in each dimension 
  #                                       # [ 0D elems ->    ... ,
  #                                       #   1D elems ->    ... ,
  #                                       #   2D elems ->    ... ,
  #                                       #   3D elems ->    ... ]

  cdef public list            groups      # List of groups in the mesh.
  cdef public dict            group_names # Dictionary with the group names.
  cdef public dict            group_ids   # Dictionary with the group names.

  cdef public int8_t          ndim        # Maximum dimension of the mesh.
  
  cdef public np.ndarray      nodes       # Nodes in numpy array format.
  
  cdef public list            spaces      # List of finite element spaces. (needed?)
  cdef public uint64_t        opCount     # Counter for the number of operations. ??
  
  cdef public uint8_t         xyzInit     # flag for initialization of x,y,z

  cdef public matso           x           # x Nodal coordinates
  cdef public matso           y           # y Nodal coordinates
  cdef public matso           z           # z Nodal coordinates

  # cdef public dict     cells        # Elements
  # cdef public dict     point_data   # Contains information of the points
  # cdef public dict     cell_data    # Contains information of the elements
  # cdef public dict     field_data   # Contains labels.
  # cdef public dict     nameIds      # Contains labels.
  # cdef public uint8_t  ndim         # Characteristic number of dimensions in the mesh.
  # cdef public omat     xcoords      # Nodal coordinates as oti arrays.
  # cdef public omat     ycoords      # Nodal coordinates as oti arrays.
  # cdef public omat     zcoords      # Nodal coordinates as oti arrays.
  # cdef public bases_t  otinbases    # Number of bases of oti numbers.
  # cdef public ord_t    otiorder     # order of the oti numbers.
  # cdef public int64_t  baseGeomType # Basic geometric type

  # cdef public list elemTable        # List of elements in each dimension 
  #                                   # [ 0D elems ->    ... ,
  #                                   #   1D elems ->    ... ,
  #                                   #   2D elems ->    ... ,
  #                                   #   3D elems ->    ... ]

  # cdef np.ndarray   domainEls       # Elements that define the domain.
  # cdef np.ndarray   normalx         # x component of the boundary normal
  # cdef np.ndarray   normaly         # y component of the boundary normal
  # cdef np.ndarray   normalz         # z component of the boundary normal
  # cdef public  int64_t domainType    # Geometric type of the domain.
  # cdef public uint64_t domainElDofs  # D.O.Fs of the domain element.
  # cdef public  list boundaEls       # Elements that define the boundary elements.
  # cdef public  list boundaType      # Geometric type of the boundaries.
  # cdef public  list boundaElsIds    # Ids of the boundary elements 
  # cdef public  list elsIds
 
  # cdef public list fespaces         # List of finite element spaces that are currently in the mesh.
  #                                   # Is this required? or maybe only add the element types only?
 
  # cdef public list elTypes          # List of interpolating functions defined for the triangulation.

  # cdef public uint64_t operationCount

  # cdef public fefunction x
  # cdef public fefunction y
  # cdef public fefunction z
  # cdef public uint8_t    xyzInit    # flag for initialization of x,y,z

  #---------------------------------------------------------------------------------------------------

  
  # cdef uint64_t getBaseDOFs(self)
  # cdef uint64_t getDomainVtkCellId(self, dofs)
  # cpdef uint64_t getGlobalDOFBound(self,int64_t ndim, fespace space)
  # cpdef uint64_t getGlobalDOF(self,fespace space)
  # cdef uint64_t addNewOperation(self)
  # cdef uint64_t addNewSpace(self,fespace space)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTIMESH ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::     CLASS  OTIMESH    :::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class mesh:
  
#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------

#   cdef public dict     cells        # Elements
#   cdef public dict     point_data   # Contains information of the points
#   cdef public dict     cell_data    # Contains information of the elements
#   cdef public dict     field_data   # Contains labels.
#   cdef public dict     nameIds      # Contains labels.
#   cdef public uint8_t  ndim         # Characteristic number of dimensions in the mesh.
#   cdef public omat     xcoords      # Nodal coordinates as oti arrays.
#   cdef public omat     ycoords      # Nodal coordinates as oti arrays.
#   cdef public omat     zcoords      # Nodal coordinates as oti arrays.
#   cdef public bases_t  otinbases    # Number of bases of oti numbers.
#   cdef public ord_t    otiorder     # order of the oti numbers.
#   cdef public int64_t  baseGeomType # Basic geometric type

#   cdef public list elemTable        # List of elements in each dimension 
#                                     # [ 0D elems ->    ... ,
#                                     #   1D elems ->    ... ,
#                                     #   2D elems ->    ... ,
#                                     #   3D elems ->    ... ]

#   cdef np.ndarray   domainEls       # Elements that define the domain.
#   cdef np.ndarray   normalx         # x component of the boundary normal
#   cdef np.ndarray   normaly         # y component of the boundary normal
#   cdef np.ndarray   normalz         # z component of the boundary normal
#   cdef public  int64_t domainType    # Geometric type of the domain.
#   cdef public uint64_t domainElDofs  # D.O.Fs of the domain element.
#   cdef public  list boundaEls       # Elements that define the boundary elements.
#   cdef public  list boundaType      # Geometric type of the boundaries.
#   cdef public  list boundaElsIds    # Ids of the boundary elements 
#   cdef public  list elsIds
 
#   cdef public list fespaces         # List of finite element spaces that are currently in the mesh.
#                                     # Is this required? or maybe only add the element types only?
 
#   cdef public list elTypes          # List of interpolating functions defined for the triangulation.

#   cdef public uint64_t operationCount

#   cdef public fefunction x
#   cdef public fefunction y
#   cdef public fefunction z
#   cdef public uint8_t    xyzInit    # flag for initialization of x,y,z

#   #---------------------------------------------------------------------------------------------------

  
#   cdef uint64_t getBaseDOFs(self)
#   cdef uint64_t getDomainVtkCellId(self, dofs)
#   cpdef uint64_t getGlobalDOFBound(self,int64_t ndim, fespace space)
#   cpdef uint64_t getGlobalDOF(self,fespace space)
#   cdef uint64_t addNewOperation(self)
#   cdef uint64_t addNewSpace(self,fespace space)


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: END OF CLASS OTIMESH ::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






