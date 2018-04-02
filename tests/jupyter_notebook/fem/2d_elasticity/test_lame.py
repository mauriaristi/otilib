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
np.set_printoptions(linewidth=133,precision=1)


# 3. Import plot functions
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


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



# ============================================================================================
#                                    Helper Functions.
# ============================================================================================
def plotQuads(plt, nodesx, nodesy, els, solution=None, fmt = 'k'):
    """
    Function that plots Quads instead of triangles. 

    INPUTS:

        -> plt:     Pyplot handle

        -> nodesx:  ( 1 x n ) array with x coordinates
        
        -> nodesy:  ( 1 x n ) array with y coordinates

        -> els:     ( m x k ) array with the node ids of the elements that form the mesh.

        -> solution (optional): ( 1 x n ) array with with node data.

        -> fmt (optional):      String with the format of the plot.

    

    """


    for i in range(els.shape[0]):

        quad = els[i]-1
        # plot Quad:

        p1x = nodesx[quad[0]]
        p2x = nodesx[quad[1]]
        p3x = nodesx[quad[2]]
        p4x = nodesx[quad[3]]


        p1y = nodesy[quad[0]]
        p2y = nodesy[quad[1]]
        p3y = nodesy[quad[2]]
        p4y = nodesy[quad[3]]

        # This only plots the wireframe.
        plt.plot([p1x,p2x,p3x,p4x,p1x],[p1y,p2y,p3y,p4y,p1y],fmt,linewidth=0.2)

         

    # end for 


    # if type(solution)!= type(None):

    #     # local_sol = solution[ [quad[0],quad[1],quad[2],quad[3]] ]
            
    #     plt.tricontourf(nodesx,nodesy,solution,triangles = els[1:4,:]-1, vmin=min(solution), vmax=max(solution), cmap = 'jet')

    # # end if

    
    plt.axis('equal')

# end function

# ============================================================================================
#                               End Helper Functions.
# ============================================================================================






Th = oti.mesh("simpleSquare.msh",otiorder = 1)

Vh = oti.fespace2(Th,oti.QuadP1)

# State functions
ux = Vh.newUndefinedFunction()
uy = Vh.newUndefinedFunction()

# Test functions
vx = Vh.newTestFunction()
vy = Vh.newTestFunction()




ux_left = Vh.newFunction(0)
uy_left = Vh.newFunction(0)

E  = 21e5
nu = 0.28
mu= E/(2*(1+nu))

c1 = Vh.newFunction(E*nu/((1+nu)*(1-2*nu))) # Lambda
c2 = Vh.newFunction(2*mu)
c3 = Vh.newFunction(mu)

problem = intV( c1*dx(ux)*dx(vx) + c1*dx(ux)*dy(vy) ) + \
    intV( c1*dy(uy)*dx(vx) + c1*dy(uy)*dy(vy)) + \
    intV( c2*dx(ux)*dx(vx) + c2*dy(uy)*dy(vy)) + \
    intV( c3*dy(ux)*dy(vx) + c3*dy(ux)*dx(vy)) + \
    intV( c3*dx(uy)*dy(vx) + c3*dx(uy)*dx(vy)) + \
    intV( vy ) + \
    on('left',ux,ux_left) +on('left',uy,uy_left)

# start_time = time.time()
ex1 = oti.feproblem([ ux, uy],[ vx, vy],   problem  )
# end_time   = time.time()
# ex1.intorder = 6
# print('\n Time to define problem: ',end_time-start_time," s")

# start_time = time.time()
# ex1.assembleSystem()
# end_time   = time.time()

# print('\n Time to assembly: ',end_time-start_time," s")

# start_time = time.time()
# sol = oti.solve(ex1.K,ex1.f)
# end_time   = time.time()

# print('\n Time to solve: ',end_time-start_time," s")
# sol_real = sol.getDeriv(0)
# sol_ux =  sol_real[:ex1.globalDOF//2]
# sol_uy =  sol_real[ex1.globalDOF//2:]


ex1.solve()


nodesx = Th.xcoords.real.reshape( Th.xcoords.real.shape[0])
nodesy = Th.ycoords.real.reshape( Th.ycoords.real.shape[0])

sol_ux = ux.data.getDeriv(0)
sol_uy = uy.data.getDeriv(0)


Th.exportToVTK("test_lame2.vtk",pd=[[ux,uy]],pdNames=['u'])
# Th.exportToVTK("exported.vtk",pointData=[[ux,uy]],pointDataNames=['u'])
# factor = 100




# plt.figure()


# # plotQuads(plt,nodesx, nodesy, Th.domainElements,fmt = 'k-')
# plotQuads(plt,nodesx+factor*sol_ux, nodesy+factor*sol_uy, Th.domainElements,fmt = 'r', solution=sol_ux)

# plt.show()










