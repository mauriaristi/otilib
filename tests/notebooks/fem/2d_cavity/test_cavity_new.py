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
np = oti.np 
np.set_printoptions(linewidth=233,precision=2)


# 3. Import plot functions
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.tri  as mtri



# 4. Import time measuring library
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


# Define the mesh
Th = oti.mesh("mesh_simple_square.msh", otiorder = 1)   # print(Th)

Vh = oti.fespace2(Th,oti.TriP2)
Qh = oti.fespace2(Th,oti.TriP1)

# State functions
ux = Vh.newUndefinedFunction()
uy = Vh.newUndefinedFunction()
p  = Qh.newUndefinedFunction()

# Test functions
vx = Vh.newTestFunction()
vy = Vh.newTestFunction()
q  = Qh.newTestFunction()


one  = Vh.newFunction(1.0)
zero = Vh.newFunction(0.0)

problem = intV( dx(ux)*dx(vx) + dy(ux)*dy(vx)  ) + \
          intV( dx(uy)*dx(vy) + dy(uy)*dy(vy)  ) + \
          intV( dx(p)*vx      + dy(p)*vy       ) + \
          intV( dx(ux)*q      + dy(uy)*q       ) + \
          intV( (-1e-10)*p*q                   ) + \
          on('left',     ux, zero) + on('left',  uy, zero) + \
          on('bottom',   ux, zero) + on('bottom',uy, zero) + \
          on('right',    ux, zero) + on('right', uy, zero) + \
          on('up',       ux,  one) + on('up',    uy, zero) 



ex1 = oti.feproblem([ ux, uy, p ],[ vx, vy, q ] ,   problem  )

ex1.solve()


Th.exportToVTK("test_cavity_new.vtk",pd=[[ux,uy],p],pdNames=['u','p'])
