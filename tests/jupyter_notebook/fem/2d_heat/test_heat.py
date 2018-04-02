# ============================================================================================
#                                    Library Imports.
# ============================================================================================
# 1. SET GLOBAL PATH 
import sys
path2oti = '../../../'
sys.path.append(path2oti) # Add path to OTI library.


# 2. IMPORT OTI LIBRARY.
import otilib as oti
np = oti.np 
np.set_printoptions(linewidth=233,precision=2)
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
dR = oti.dx
dy = oti.dy

# ============================================================================================
#                                    End Function renaming.
# ============================================================================================


# Define the number of variables and order of derivatives.
nvar = 3
order = 3


# Define the mesh
Th = oti.mesh("simpleSquare.msh", otiorder = order)   # print(Th)

# Vh = oti.fespace2(Th,oti.QuadP1)
Vh = oti.fespace2(Th,oti.QuadSerP2)
# Vh = oti.fespace2(Th,oti.TriP1)

# Perturb all elements of 'outer' boundary in  direction e(1) to get its derivative.

boundId = Th.nameIds['outer']
boundIndx = Th.elsIds[1].index(boundId)
nodes = np.unique(Th.elemTable[1][boundIndx][:,:-1])-1

for i in range(nodes.size):
    Th.xcoords[nodes[i],0] = Th.xcoords[nodes[i],0]+e(1, order = order)
# end for 


nodes1 = np.unique(Th.elemTable[1][0][:,:-1])-1
nodes2 = np.unique(Th.elemTable[1][1][:,:-1])-1
nodes = np.unique(np.append(nodes1,nodes2))

allnodes = np.unique(Th.domainElements[:,:-1])-1

j=0


for i in range(allnodes.size):
    if allnodes[i] == nodes[j]:
        j+=1
        if j>=nodes.size:
            j=nodes.size-1

    else: 
        Th.xcoords[allnodes[i],0] = Th.xcoords[allnodes[i],0]+e(2, order = order)




# State functions
Theta = Vh.newUndefinedFunction() # Change to StateFunction

# Test functions
w = Vh.newTestFunction()

R = Th.x

rho_r = 1.5
Q   = 5.0 + e(3, order = order)
Bi1 = 0.1
Bi2 = 1.0

R1 = 1.0
R2 = 1.5

R_r = R.data.real

ThetaAnalytic = oti.spzeros(shape = R.data.shape , order = Th.otiorder)
for i in range(R.data.shape[0]):
    

    rho = rho_r + e(1, order = order)
    r_i = R_r[i,0] + e(2, order = order) #R.data[i,0]

    K1 = (2.0*Bi2*Q-Bi1*Bi2*Q+2.0*Bi1*Q*rho-4.0*Bi1*Bi2+Bi1*Bi2*Q*rho**2)
    KDiv = (Bi1*Bi2*rho*oti.slog(rho)+Bi1+Bi2*rho)
    K2 = (2.0*Q*rho**2-4.0*Bi2*rho+Bi2*Q*rho**3-2.0*Bi2*Q*rho*oti.slog(rho)+Bi1*Bi2*Q*rho*oti.slog(rho)-2.0*Q+Bi1*Q)
    num = -0.25*Q*(r_i)**2 + 0.25*rho*oti.slog(r_i)*K1/KDiv + 0.25*K2/KDiv;

    ThetaAnalytic[i,0] = num
    
ThAnal = Vh.newFunction(ThetaAnalytic.tondarray())
R_funct = Vh.newFunction(R.data.tondarray())
# Compute analytic solution:







problem = intV(         -  R * dR(Theta) * dR(w) ) + \
          intV(         -  R * dy(Theta) * dy(w) ) + \
          intV(           (  Q * R) * w          ) + \
          intS('inner', - (Bi1 * R) * Theta * w  ) + \
          intS('outer', - (Bi2 * R) * Theta * w  ) + \
          intS('outer', - (Bi2 * R) * w          )
# on('inner', Theta, 1.47625) + \
# on('outer', Theta, 0.983754)

print(problem)
ex1 = oti.feproblem([ Theta ],[ w ] ,   problem  ,m=nvar)
# # ex1.intorder = 16 
ex1.solveLU()

Th.exportToVTK("test_heat.vtk",pd=[Theta,ThAnal,[R_funct]],pdNames=['Theta','ThetaAnalytic',"DomainPert"])
