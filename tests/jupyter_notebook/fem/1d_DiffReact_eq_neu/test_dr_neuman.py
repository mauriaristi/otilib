# 1. SET GLOBAL PATH 
import sys
# path2oti = '/Users/mauriaristi/Dropbox/EAFIT/PHD/Thesis-MAC/DUAL/otilibv0.8/'
path2oti = '../../..'
sys.path.append(path2oti) # Add path to OTI library.


# 2. IMPORT OTI LIBRARY.
import otilib as oti
np = oti.np 
np.set_printoptions(linewidth=133,precision=1)


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




Th = oti.mesh("lineTest.msh",otiorder = 1)

Vh = oti.fespace2(Th,oti.LineP1)

u = Vh.newUndefinedFunction()
v = Vh.newTestFunction()

Pe = 10
f = 0
# # ex1 = oti.feproblem([u],[v],   intV(-dx(u)*dx(v)) + intV(Da*dx(u)*v) + intV(u*v) + intV(-f*v) )
# ex1 = oti.feproblem([u],[v],   intV(dx(u)*dx(v)) + \
#     intV(Pe*dx(u)*v) + intV(-f*v) + \
#     intS('right', - v  ) + \
#     on('left', u, 0) )

# intV(Pe*dx(u)*v) + intV(-f*v) + \
ex1 = oti.feproblem([u],[v],   intV(dx(u)*dx(v)) + \
    intS('left', -1.0*v  ) + \
    on('right', u, 1) )


ex1.solveLU(permc_spec='NATURAL',diag_pivot_thresh=0.9)


# Th.exportToVTK("test_laplace_1d.vtk",pd=[u],pdNames=['u'])


# print(ex1.K.elements[0].toarray())
# print(ex1.f)
# print(u.data.getDeriv(0))
print(Th.nx)
print(Th.ny)
print(Th.nz)

plt.plot(Th.xcoords.real,u.data.getDeriv(0), '-o')
plt.axis('equal')
plt.grid('on')
plt.show()
