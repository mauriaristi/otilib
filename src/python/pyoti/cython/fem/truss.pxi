
# Consider not importing this in the library itself.
import matplotlib.pyplot as plt


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  TRUSS      :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class truss2D:
  """
  CLASS TRUSS:  Class FEM truss from the module FEM of the pyoti library.

  This class allows to solve Truss FEM problems using OTI algebra.

  Example:

  >>>
  >>>
  >>>
  >>>

  """
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------



  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __cinit__(self, nodes, elements, displ, forces, E, A):
    """
    DESCRIPTION:

    INPUTS:
      - nodes:    Coordinates of the nodes.
      - elements: Elements of the system.
      - displ:    Displacement boundary conditions.
      - forces:   Force Boundary conditions.
      - E:        Young modulus (per element).
      - A:        Area (per element).

    EXAMPLE:

    >>>
    >>>
    >>>

    """

    self.nodes    = nodes
    self.elements = elements
    self.displ    = displ
    self.forces   = forces

    if isinstance( E, np.ndarray):
      self.E = array(E)
    else:
      self.E = E * ones( ( self.elements.shape[0], 1 ) )
    # end if 

    if isinstance( A, np.ndarray):
      self.A = array(A)
    else:
      self.A = A * ones( ( self.elements.shape[0], 1 ) )
    # end if

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def plot(self, plt = None, scaleF=1.0, colors=[], marker='o-', integrate=False, bases=None, 
                 deltas=None):
    """
    DESCRIPTION:   Function that plots the given truss system using a displacement array

    INPUTS:
      - scaleF: Scalr Factor (Default 1.0)
      - colors: Color Array (Default colors=[])
      - marker: Plot Marker. (Default marker='o-')

    """
    # 
    
    ax = plt.axes()

    U_plot  = self.U.real
    U_plot  = U_plot.reshape(self.nodes.shape[0],2)
    U_plot *= scaleF
    
    Ci = colors.copy()

    # PLOT ELEMENTS
    for i in range(0,self.elements.shape[0]):

      v0x = self.nodes[ self.elements[i,0], 0 ] + U_plot[ self.elements[i,0], 0 ]
      v0y = self.nodes[ self.elements[i,0], 1 ] + U_plot[ self.elements[i,0], 1 ]
      
      v1x = self.nodes[ self.elements[i,1], 0 ] + U_plot[ self.elements[i,1], 0 ]
      v1y = self.nodes[ self.elements[i,1], 1 ] + U_plot[ self.elements[i,1], 1 ]

      if len(Ci)==0:
        plt.plot( [v0x, v1x], [v0y, v1y], M, color='k', linewidth=2)
      elif len(Ci)==1:
        plt.plot( [v0x, v1x], [v0y, v1y], M, color=str(Ci[0]), linewidth=2)
      elif len(Ci)==self.elements.shape[0]:
        plt.plot( [v0x, v1x], [v0y, v1y], M, color=str(Ci[i]), linewidth= 2 * ( 2. - Ci[i] ) )
      else:
        raise TypeError('Unsupported length of color array C -= :' + ': \'' +
          str(len(Ci)) + '\' . It should be same length of number of elements or an array of length = 1' )
      # end if

    # end for 

    # PLOT DISPLACEMENTS
    for i in range(0,self.displ.shape[0]):
      
      v0x = self.nodes[ int(self.displ[i,0]), 0 ] + U_plot[ int( self.displ[i,0] ), 0 ]
      v0y = self.nodes[ int(self.displ[i,0]), 1 ] + U_plot[ int( self.displ[i,0] ), 1 ]
      
      v1x = v0x - 0.2 * ( 1 - self.displ[i,1] )
      v1y = v0y - 0.2 * (     self.displ[i,1] )
      
      plt.plot( [v0x, v1x], [v0y, v1y], 'r--', linewidth=3)
    
    # end for
    
    # PLOT FORCES
    for i in range(0,self.forces.shape[0]):
      
      v0x = self.nodes[ int( self.forces[i,0] ), 0 ]+U_plot[ int( self.forces[i,0] ), 0 ]
      v0y = self.nodes[ int( self.forces[i,0] ), 1 ]+U_plot[ int( self.forces[i,0] ), 1 ]
      
      v1x=0.1*(self.forces[i,1])
      v1y=0.1*(self.forces[i,2])
      
      ax.arrow(v0x, v0y, v1x, v1y, head_width=0.05, head_length=0.1, fc='b', ec='b')
    
    # end for

    # Setup the max and min points.
    tsf = self.nodes.real+U_plot
    mgn = 0.5
    
    minX = np.min(tsf[:,0])
    maxX = np.max(tsf[:,0])
    
    minY = np.min(tsf[:,1])
    maxY = np.max(tsf[:,1])
    
    cX = 0.5*(maxX+minX)
    cY = 0.5*(maxY+minY)
    
    deltaX=maxX-minX
    deltaY=maxY-minY
    
    maxDelta=np.max([deltaX,deltaY])
    
    _minX = cX - maxDelta*.5 - mgn
    _maxX = cX + maxDelta*.5 + mgn
    _minY = cY - maxDelta*.5 - mgn
    _maxY = cY + maxDelta*.5 + mgn
    
    plt.xlabel("x")
    plt.ylabel("y")

    ax.set_xlim( [ _minX, _maxX ] )
    ax.set_ylim( [ _minY, _maxY ] )

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def computeElementalK(self, el_i, A_i, E_i):
    """
    DESCRIPTION: Compute elemental stiffness matrix.

    INPUTS:

      - el_i: (2,) vector with the indices of the nodes forming element i.
      - A_i:  Area of the i'th element.
      - E_i:  Young modulus of the i'th element.

    """

    # Compute elemental stiffness matrix
    delta_x = self.nodes[ el_i[1], 0 ] - self.nodes[ el_i[0], 0 ]
    delta_y = self.nodes[ el_i[1], 1 ] - self.nodes[ el_i[0], 1 ]
    L_e     = ( delta_x**2 + delta_y**2 )**0.5
    
    # Compute the angle of inclination of the element.
    # theta = np.arctan2(delta_y,delta_x) # (y,x)
    c_th = delta_x / L_e # cos(theta)
    s_th = delta_y / L_e # sin(theta)
    
    C = ( A_i * E_i / L_e )
    cc = c_th * c_th * C
    ss = s_th * s_th * C
    cs = c_th * s_th * C

    # Form the elemental stiffness matrix
    self.K_e[0,0] =  cc
    self.K_e[0,1] =  cs
    self.K_e[0,2] = -cc
    self.K_e[0,3] = -cs

    self.K_e[1,0] =  cs
    self.K_e[1,1] =  ss
    self.K_e[1,2] = -cs
    self.K_e[1,3] = -ss

    self.K_e[2,0] = -cc
    self.K_e[2,1] = -cs
    self.K_e[2,2] =  cc
    self.K_e[2,3] =  cs

    self.K_e[3,0] = -cs
    self.K_e[3,1] = -ss
    self.K_e[3,2] =  cs
    self.K_e[3,3] =  ss

    # K_e = array([
    #     [ cc, cs,-cc,-cs],
    #     [ cs, ss,-cs,-ss],
    #     [-cc,-cs, cc, cs],
    #     [-cs,-ss, cs, ss],
    #   ], dtype = object )

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def assembleK(self, el_i, K_e):
    """
    DESCRIPTION: Assemble elemental stiffness matrix into Global matrix.

    INPUTS:
      - el_i: (2,) vector with the indices of the nodes forming element i.
      - K_e:  Elemental stiffness matrix.

    """
    # Assemble the global matrix
    for l in range(0,2):
      for j in range(0,2):
        # Reorganize the elemental stiffness matrix within the global stiffness matrix.
        e_i1 = int( el_i[l] * 2     )
        e_i2 = int( el_i[l] * 2 + 1 )
        e_j1 = int( el_i[j] * 2     )
        e_j2 = int( el_i[j] * 2 + 1 )
        
        i1 = l * 2    
        i2 = l * 2 + 1
        j1 = j * 2    
        j2 = j * 2 + 1
        
        self.K_s[ e_i1, e_j1 ] = self.K_s[ e_i1, e_j1 ] + self.K_e[ i1, j1 ]
        self.K_s[ e_i1, e_j2 ] = self.K_s[ e_i1, e_j2 ] + self.K_e[ i1, j2 ]
        self.K_s[ e_i2, e_j1 ] = self.K_s[ e_i2, e_j1 ] + self.K_e[ i2, j1 ]
        self.K_s[ e_i2, e_j2 ] = self.K_s[ e_i2, e_j2 ] + self.K_e[ i2, j2 ]
        
      # end for
    # end for

  #---------------------------------------------------------------------------------------------------


  # ****************************************************************************************************
  def solve(self, nbases = 0, order = 0):
    """
    DESCRIPTION: Solve the Truss problem

    INPUTS:


    """
    
    # SOLVE THE SYSTEM   
    # Global matrix.
    self.K_s = spr_matso( ( self.nodes.shape[0]*2 , self.nodes.shape[0]*2), nbases = nbases, order = order )
    # create force vector.
    self.F_s =     zeros( ( self.nodes.shape[0]*2 , 1                    ), nbases = nbases, order = order )

    self.K_e =     zeros( ( 4,4 ) )
    
    # Compute global K
    for i in range(0,els.shape[0]):

      el_i = self.elements[i,:]
      
      # Compute Elemental K_e
      self.computeElementalK(el_i,self.A[i,0],self.E[i,0])
      
      # Assemble the global matrix
      self.assembleK( K_e, el_i )

    # end for
    
    # Compute Global F
    # Implement force boundary conditions
    for i in range(0,fce.shape[0]):

      F_s[ int( self.forces[i,0]*2    ), 0 ] = F_s[ int( self.forces[i,0] )*2   , 0 ] + fce[i,1]
      F_s[ int( self.forces[i,0]*2 + 1), 0 ] = F_s[ int( self.forces[i,0]*2+1 ) , 0 ] + fce[i,2]
      
    # end for
    
    TGV=1e30

    # Setup displacement boundary conditions.
    # Implement displacement boundary conditions
    for i in range(  0,  self.displ.shape[0]  ):
   
      e_i = int( self.displ[i,0]*2 + self.displ[i,1])
      e_j = e_i

      self.K_s[e_i, e_j] = TGV
      self.F_s[e_i,   0] = TGV * self.displ[i,2]
        
    # end for

    self.U = solve(self.K_s,self.F_s)
    
  #---------------------------------------------------------------------------------------------------



