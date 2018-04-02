# 1. SET GLOBAL PATH 
import sys
# path2oti = '/Users/mauriaristi/Dropbox/EAFIT/PHD/Thesis-MAC/DUAL/otilibv0.8/'
path2oti = '../../'
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

# print( (50+0*e(1,order = 2)) * Th.xcoords)
# print( Th.xcoords * (50+0*e(1,order = 2)) )
# print(Th.xcoords*50)
# print(50*Th.xcoords)


zero = Vh.newFunction(0)
one  = Vh.newFunction(1)

Pe = 10
f = 0
# ex1 = oti.feproblem([u],[v],   intV(-dx(u)*dx(v)) + intV(Da*dx(u)*v) + intV(u*v) + intV(-f*v) )
ex1 = oti.feproblem([u],[v],   intV(dx(u)*dx(v)) + \
    intV(Pe*dx(u)*v) + intV(-f*v) + \
    on(Th.nameIds['left'],u,zero) + on(Th.nameIds['right'],u,one) )


# print(ex1.operMat)


# ex1.intorder = 5
ex1.assembleSystem()

sol = oti.solveLU(ex1.K,ex1.f)

# print(ex1.problem.)

plt.plot(Th.xcoords.real,sol.getDeriv(0))


plt.show()
# for i in range(ex1.K.Ndir):
# 	print(ex1.K.elements[i].toarray())
# # end for 

# print(ex1.operMat)