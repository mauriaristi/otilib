# ============================================================================================
#                                    Library Imports.
# ============================================================================================
# 1. SET GLOBAL PATH 
import sys
# path2oti = '/Users/mauriaristi/Dropbox/EAFIT/PHD/Thesis-MAC/DUAL/otilibv0.8/'
path2oti = '../../../'
sys.path.append(path2oti) # Add path to OTI library.


# 2. IMPORT OTI LIBRARY.
import otilib as oti
np = oti.np                                     # Get numpy from distribution.
np.set_printoptions(linewidth=133,precision=1)  # Set width and 


# 3. Import time measuring library
import time

# ============================================================================================
#                                   End Library Imports.
# ============================================================================================




# ============================================================================================
#                                    Function renaming.
# ============================================================================================

# Rename imaginary direction module.
e  = oti.se 

# Rename integration functions
intV = oti.intOmega
intS = oti.intGamma
on = oti.on

# Rename derivation functions
dx = oti.dx
dy = oti.dy

# ============================================================================================
#                                    End Function renaming.
# ============================================================================================


nvar = 1
order = 1

Th = oti.mesh("cruciform.msh",otiorder = order)

# Vh = oti.fespace2(Th,oti.QuadSerP2)
Vh = oti.fespace2(Th,oti.TriP2)

x = Th.x
y = Th.y

# State functions
ux = Vh.newUndefinedFunction()
uy = Vh.newUndefinedFunction()

# Test functions
vx = Vh.newTestFunction()
vy = Vh.newTestFunction()

po = 100

E  = 21e5
nu = 0.28
mu = E/(2*(1+nu))

c1 = Vh.newFunction(E*nu/((1+nu)*(1-2*nu))) # Lambda
c2 = Vh.newFunction(2*mu)
c3 = Vh.newFunction(mu)

problem = intV( c1*dx(ux)*dx(vx) + c1*dx(ux)*dy(vy)) + \
          intV( c1*dy(uy)*dx(vx) + c1*dy(uy)*dy(vy)) + \
          intV( c2*dx(ux)*dx(vx) + c2*dy(uy)*dy(vy)) + \
          intV( c3*dy(ux)*dy(vx) + c3*dy(ux)*dx(vy)) + \
          intV( c3*dx(uy)*dy(vx) + c3*dx(uy)*dx(vy)) + \
          intS( 'top' , -po*vy   ) + \
          on(   'bottom', uy, 0.0) + \
          on(   'left'  , ux, 0.0) + \
          on(   'right' , ux, 0.0)

ex1 = oti.feproblem([ ux, uy],[ vx, vy],   problem  )
ex1.solve()

Th.exportToVTK("test_cruciform.vtk",pd=[[ux,uy]],pdNames=['u'])



