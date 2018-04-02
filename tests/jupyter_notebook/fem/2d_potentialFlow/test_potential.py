# 1. SET GLOBAL PATH 
import sys
# path2oti = '/Users/mauriaristi/Dropbox/EAFIT/PHD/Thesis-MAC/DUAL/otilibv0.8/'
path2oti = '../../../'
sys.path.append(path2oti) # Add path to OTI library.


# 2. IMPORT OTI LIBRARY.
import otilib as oti
np = oti.np 
np.set_printoptions(linewidth=133,precision=1)


# 3. Import plot functions
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


#3. 
import time

# Rename imaginary direction module.
e  = oti.se 

# Rename integration functions
intV = oti.intOmega
intS = oti.intGamma
on   = oti.on

# Rename derivation functions
dx = oti.dx
dy = oti.dy




Th = oti.mesh("mesh_foil.msh",otiorder = 1)

Vh = oti.fespace2(Th,oti.TriP1)

# State functions
psi = Vh.newUndefinedFunction()

# Test functions
w = Vh.newTestFunction()


# var = Th.x + Th.y

psi_zero = Vh.newFunction(0)


problem = intV( dx(psi)*dx(w)+dy(psi)*dy(w) ) + \
    on('right',  psi, Th.y    ) +\
    on('left',   psi, Th.y    ) +\
    on('bottom', psi, Th.y    ) +\
    on('top',    psi, Th.y    ) +\
    on('foil',   psi, psi_zero)


ex1 = oti.feproblem([ psi ],[ w ],   problem  )

ex1.solve()


nodesx = Th.xcoords.real.reshape( Th.xcoords.real.shape[0])
nodesy = Th.ycoords.real.reshape( Th.ycoords.real.shape[0])

sol_psi = psi.data.getDeriv(0)




# factor = 100


# plt.figure()
plt.triplot(nodesx,  nodesy, triangles=(Th.domainElements[:,:-1]-1),linewidth=0.2)
#
plt.tricontourf(nodesx, nodesy ,sol_psi, triangles=(Th.domainElements[:,:-1]-1), cmap = 'jet',linewidth=1.2,levels=np.arange(-0.5,0.5+0.05,0.05))
# plt.trisurf(nodesx, nodesy, sol.getDeriv(0),triangles=(Th.domainElements[:,:-1]-1),cmap='jet', linewidth=1.2)

plt.show()










