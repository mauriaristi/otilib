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

Th = oti.mesh("cylinder.msh",otiorder = order)

Vh = oti.fespace2(Th,oti.QuadP1)

x = Th.x
y = Th.y

# State functions
ux = Vh.newUndefinedFunction()
uy = Vh.newUndefinedFunction()

# Test functions
vx = Vh.newTestFunction()
vy = Vh.newTestFunction()

nx, ny, nz = Th.getBoundNormals(['in','out'])

nx = Vh.newFunction(oti.sarray(nx,order=order) )
ny = Vh.newFunction(oti.sarray(ny,order=order) )

ri = 1.0
ro = 2.0

pi = 1
po = 100

fxi = pi*nx
fyi = pi*ny

fxo = po*nx
fyo = po*ny

zero = Vh.newFunction(0)

E  = 21e5
nu = 0.28
mu = E/(2*(1+nu))


# Analytic solution:
A = ri**2*ro**2*(po-pi)/(ro**2-ri**2)
B = (ri**2*pi - ro**2*po)/(ro**2-ri**2)

uxAnalytic = oti.spzeros(shape = x.data.shape , order = Th.otiorder)
uyAnalytic = oti.spzeros(shape = x.data.shape , order = Th.otiorder)

for i in range(x.data.shape[0]):
    
    x_i = Th.xcoords[i,0] 
    y_i = Th.ycoords[i,0]
    
    r_i = oti.ssqrt(x_i**2+y_i**2)



    ur = (1+nu)*r_i/E*((1-2*nu)*B-A/(r_i**2))

    uxAnalytic[i,0] = ur*x_i/r_i
    uyAnalytic[i,0] = ur*y_i/r_i

# end for   
    
uxAnal = Vh.newFunction(uxAnalytic.tondarray())
uyAnal = Vh.newFunction(uyAnalytic.tondarray())


c1 = Vh.newFunction(E*nu/((1+nu)*(1-2*nu))) # Lambda
c2 = Vh.newFunction(2*mu)
c3 = Vh.newFunction(mu)


problem = intV( c1*dx(ux)*dx(vx) + c1*dx(ux)*dy(vy)) + \
          intV( c1*dy(uy)*dx(vx) + c1*dy(uy)*dy(vy)) + \
          intV( c2*dx(ux)*dx(vx) + c2*dy(uy)*dy(vy)) + \
          intV( c3*dy(ux)*dy(vx) + c3*dy(ux)*dx(vy)) + \
          intV( c3*dx(uy)*dy(vx) + c3*dx(uy)*dx(vy)) + \
          intS( 'in' , fxi*vx + fyi*vy ) + \
          intS( 'out', fxo*vx + fyo*vy ) + \
          on(   'left' , ux, 0.0) + \
          on(   'right', uy, 0.0)


ex1 = oti.feproblem([ ux, uy],[ vx, vy],   problem  )
ex1.solve()

Th.exportToVTK("test_cylinder.vtk",pd=[[ux,uy],[uxAnal,uyAnal]],pdNames=['uh','u'])






