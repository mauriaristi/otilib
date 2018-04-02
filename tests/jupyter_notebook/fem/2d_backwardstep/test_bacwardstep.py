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

# 3. Import VTK writing tool by Andres Aguirre
from writeVTK import writeVTK



# 4. Import plot functions
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.tri  as mtri




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
Th = oti.mesh("mesh_backwardstep.msh", otiorder = 1)   # print(Th)
# Th.exportToVTK("test.vtk")
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

y = Th.y

u = 4
ux_in  = Vh.newFunction((-4)*y.data*y.data + 4*y.data)
zero   = Vh.newFunction(0.0)

# "inlet"      
# "bottom_wall"
# "outlet"     
# "top_wall"   

problem = intV( dx(ux)*dx(vx) + dy(ux)*dy(vx)  ) + \
          intV( dx(uy)*dx(vy) + dy(uy)*dy(vy)  ) + \
          intV( dx(p)*vx      + dy(p)*vy       ) + \
          intV( dx(ux)*q      + dy(uy)*q       ) + \
          intV( (-1e-10)*p*q                   ) + \
          on('bottom_wall',  ux,  zero) + on('bottom_wall', uy, zero) + \
          on('top_wall',     ux,  zero) + on('top_wall',    uy, zero) + \
          on('inlet',        ux, ux_in) + on('inlet',       uy, zero)



ex1 = oti.feproblem([ ux, uy, p ],[ vx, vy, q ] ,   problem  )

# ex1.solveLU(permc_spec='NATURAL')
# ex1.solveLU()
ex1.solve()

sol_ux = ux.data.getDeriv(0)
sol_uy = uy.data.getDeriv(0)
sol_p  =  p.data.getDeriv(0)


# 0  4241  8482 12723


nodesx = Th.xcoords.real.reshape( Th.xcoords.real.shape[0])
nodesy = Th.ycoords.real.reshape( Th.ycoords.real.shape[0])




Th.exportToVTK("test_backwardstep.vtk",pd=[[ux,uy],p],pdNames=['u','p'])




# # Create triangulation object:
# # mplib_triangulation = mtri.Triangulation(nodesx[:len(sol_p)], nodesy[:len(sol_p)], Th.domainElements[:,0:3]-1)
# # mplib_triangulation = mtri.Triangulation(nodesx, nodesy)

# # xi, yi = np.meshgrid(np.linspace(0.0, 1.5, 150), np.linspace(-0.5, 0.5, 150))

# # interp_lin = mtri.LinearTriInterpolator(mplib_triangulation, sol_ux)
# # ux_lin = interp_lin(xi, yi)

# # interp_lin = mtri.LinearTriInterpolator(mplib_triangulation, sol_uy)
# # uy_lin = interp_lin(xi, yi)
# # Color = ux_lin**2 + uy_lin**2







# plt.figure()

# plt.triplot(nodesx[:len(sol_p)],  nodesy[:len(sol_p)], triangles=(Th.domainElements[:,0:3]-1),linewidth=0.2)
# plt.tricontourf(nodesx[:len(sol_p)], nodesy[:len(sol_p)], sol_p, triangles=(Th.domainElements[:,0:3]-1), cmap = 'jet',zorder= 0)
# cbar = plt.colorbar()
# cbar.ax.set_ylabel('p')
# plt.axis('equal')

# plt.figure()
# plt.triplot(nodesx[:len(sol_p)],  nodesy[:len(sol_p)], triangles=(Th.domainElements[:,0:3]-1),linewidth=0.2)
# plt.tricontourf(nodesx[:len(sol_p)], nodesy[:len(sol_p)], sol_ux[:len(sol_p)], triangles=(Th.domainElements[:,0:3]-1),cmap = 'jet',zorder= 0)
# cbar = plt.colorbar()
# cbar.ax.set_ylabel('ux')
# plt.axis('equal')

# plt.figure()
# plt.triplot(nodesx[:len(sol_p)],  nodesy[:len(sol_p)], triangles=(Th.domainElements[:,0:3]-1),linewidth=0.2)
# plt.tricontourf(nodesx[:len(sol_p)], nodesy[:len(sol_p)], sol_uy[:len(sol_p)], triangles=(Th.domainElements[:,0:3]-1),cmap = 'jet',zorder= 0)
# cbar = plt.colorbar()
# cbar.ax.set_ylabel('uy')
# plt.axis('equal')
# plt.show()






# # plt.streamplot(xi, yi, ux_lin, uy_lin, linewidth=1, density=3.0,color = Color,cmap=plt.cm.autumn,zorder = 1)




