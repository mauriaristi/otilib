# 1. SET GLOBAL PATH 
import sys
# path2oti = '/Users/mauriaristi/Dropbox/EAFIT/PHD/Thesis-MAC/DUAL/otilibv0.8/'
path2oti = '../../'
sys.path.append(path2oti) # Add path to OTI library.


# 2. IMPORT OTI LIBRARY.
import otilib as oti
np = oti.np 
np.set_printoptions(linewidth=133,precision=4)


# Rename imaginary direction module.
e  = oti.se 

# Rename integration functions
intV = oti.intOmega
intS = oti.intGamma
on = oti.on

# Rename derivation functions
dx = oti.dx
dy = oti.dy




# Define the mesh
Th = oti.mesh("mesh_simple_square.msh", otiorder = 2)   # print(Th)

# # Define a Finite Element space: 
# Vh = oti.fespace2( Th, oti.TriP2) # Define common FE space
# Qh = oti.fespace2( Th, oti.TriP1) # Define common FE space


# x = Th.x
# y = Th.y

# # Declare variables that belong to the space Vh
# # This step is mandatory.

# ux = Vh.newUndefinedFunction()       
# vx = Vh.newTestFunction()

# uy = Vh.newUndefinedFunction()      
# vy = Vh.newTestFunction()

# p  = Qh.newUndefinedFunction()
# q  = Qh.newTestFunction() 


# laplace2D = oti.feproblem([ux,uy,p],[vx,vy,q], intV( dx(ux)*dx(vx) + dy(uy)*dy(vy) ) +    \
#                            intV(vx+vy) +    intV(p*q) +                                    \
#                           intS(Th.nameIds['up'], vx + vy ) + intS(Th.nameIds['left'], vx + vy ) +                         \
#                           on(Th.nameIds['bottom'],ux,x) + on(Th.nameIds['right'],uy,y) + \
#                           on(Th.nameIds['left'], p, x)        )



