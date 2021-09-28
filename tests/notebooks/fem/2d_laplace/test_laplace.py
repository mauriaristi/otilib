# 1. SET GLOBAL PATH 
import sys
# path2oti = '/Users/mauriaristi/Dropbox/EAFIT/PHD/Thesis-MAC/DUAL/otilibv0.8/'
path2oti = '../../'
sys.path.append(path2oti) # Add path to OTI library.


# 2. IMPORT OTI LIBRARY.
import otilib as oti
np = oti.np 
np.set_printoptions(linewidth=133,precision=1)

from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


# Rename imaginary direction module.
e  = oti.se 

# Rename integration functions
intV = oti.intOmega
intS = oti.intGamma
on = oti.on

# Rename derivation functions
dx = oti.dx
dy = oti.dy







Th = oti.mesh("simpleSquare.msh",otiorder = 1)

Vh = oti.fespace2(Th,oti.QuadP1)

u = Vh.newUndefinedFunction()
v = Vh.newTestFunction()


u_bottom = Vh.newFunction(20)
u_top    = Vh.newFunction(10)



ex1 = oti.feproblem([u],[v],   intV( dx(u)*dx(v)+dy(u)*dy(v) ) + \
    on(Th.nameIds['left'],u,10*Th.y) + on(Th.nameIds['right'],u,10*Th.y) )



ex1.assembleSystem()

sol = oti.solveLU(ex1.K,ex1.f)


nodesx = Th.xcoords.real.reshape( Th.xcoords.real.shape[0])
nodesy = Th.ycoords.real.reshape( Th.ycoords.real.shape[0])








# plt.plot(Th.xcoords.real,sol.getDeriv(0))


plt.figure()
plt.tricontourf(nodesx, nodesy, sol.getDeriv(0), triangles=(Th.domainElements[:,:-1]-1), cmap = 'jet')

fig = plt.figure()

ax = fig.gca(projection='3d')

ax.plot_trisurf(nodesx, nodesy, sol.getDeriv(0),triangles=(Th.domainElements[:,:-1]-1),cmap='jet', linewidth=1.2)


plt.show()





