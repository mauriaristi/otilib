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


# print(problem)
# problem = intV(  dy(p)*vy  )
# problem = intV( dx(p)*vx      + dy(p)*vy  ) 


start_time = time.time()
ex1 = oti.feproblem([ ux, uy, p ],[ vx, vy, q ] ,   problem  )
end_time   = time.time()

print('\n Time to define problem: ',end_time-start_time," s")

start_time = time.time()
ex1.assembleSystem()
end_time   = time.time()

print('\n Time to assembly: ',end_time-start_time," s")

start_time = time.time()
sol = oti.solveLU(ex1.K,ex1.f)
end_time   = time.time()

print('\n Time to solve: ',end_time-start_time," s")
sol_real = sol.getDeriv(0)
sol_ux =  sol_real[   0: 3721]
sol_uy =  sol_real[3721:7442]
sol_p  =  sol_real[7442:8403]
 #  0 3721 7442 8403


nodesx = Th.xcoords.real.reshape( Th.xcoords.real.shape[0])
nodesy = Th.ycoords.real.reshape( Th.ycoords.real.shape[0])

normx = np.empty_like(sol_ux)
normy = np.empty_like(sol_uy)

for i in range(len(sol_ux)):
	
	xx = sol_ux[i]
	yy = sol_uy[i]
	r = xx**2 + yy**2
	
	if r>1e-10:
	
		r = np.sqrt(r)
		normx[i] = xx/r
		normy[i] = yy/r
	
	# end if 

# end for



plt.figure()
# Create triangulation object:
# mplib_triangulation = mtri.Triangulation(nodesx[:len(sol_p)], nodesy[:len(sol_p)], Th.domainElements[:,0:3]-1)
mplib_triangulation = mtri.Triangulation(nodesx, nodesy)

xi, yi = np.meshgrid(np.linspace(-.5, .5, 60), np.linspace(-.5, .5, 60))

interp_lin = mtri.LinearTriInterpolator(mplib_triangulation, sol_ux)
ux_lin = interp_lin(xi, yi)

interp_lin = mtri.LinearTriInterpolator(mplib_triangulation, sol_uy)
uy_lin = interp_lin(xi, yi)
Color = ux_lin**2 + uy_lin**2

plt.triplot(nodesx,  nodesy, triangles=(Th.domainElements[:,0:3]-1),linewidth=0.2)
# plt.tricontourf(nodesx[:len(sol_p)], nodesy[:len(sol_p)], sol_p,  cmap = 'jet',zorder= 0)#,levels=np.arange(-0.1,0.1,0.001))
plt.tricontourf(nodesx, nodesy, sol_ux,  cmap = 'jet',zorder= 0)#,levels=np.arange(-0.1,0.1,0.001))
cbar = plt.colorbar()
# cbar.ax.set_ylabel('Pressure')
cbar.ax.set_ylabel('ux')
plt.streamplot(xi, yi, ux_lin, uy_lin, linewidth=1, color = Color,cmap=plt.cm.autumn,zorder = 1)
plt.axis('equal')
plt.show()










