import pyoti.core as coti
import pyoti.sparse as oti

import numpy as np

np.set_printoptions(linewidth=120)
oti.set_printoptions(terms_print=-1)


# Residual eqution for the intersection of circle and line.
def fun2(X,r,m,b):
    #INTERSECTION BETWEEN CURVES.
    f = oti.zeros((2,1))
    x = X[0,0]
    y = X[1,0]
    f[0,0] = x**2 + y**2 - r**2 
    f[1,0] = y - ( m * x + b )
    return f


def intersect_pts(r,m,b,alg=oti):
    #CURVES.
        
    #     x[0,0] = (-m*b + oti.sqrt( (m*b)**2 - (m+1)*(b**2-r**2) ) )/( (m+1) )
    #     x[1,0] = (-m*b - oti.sqrt( (m*b)**2 - (m+1)*(b**2-r**2) ) )/( (m+1) )
    x1 = alg.zeros((2,1))
    x1[0,0] = (-b*m + alg.sqrt(-b**2 + m**2*r**2 + r**2))/(m**2 + 1)
    x1[1,0] = m * x1[0,0] + b
    
    x2 = alg.zeros((2,1))
    x2[0,0] = (-b*m - alg.sqrt(-b**2 + m**2*r**2 + r**2))/(m**2 + 1)
    x2[1,0] = m * x2[0,0] + b
        
    return x1,x2




print("Implementation of residual method in Python")
print('using pyoti')

# Define parameters of interest:

r = 4
m = 3
b = -4


# Step 1: Compute Known solution 
# Evaluate the roots of the problem from analytical solution:
Roots =  intersect_pts(r,m,b,alg=np)

X = Roots[0] # Pick first solution.
print()
print('--> Out step1: ')
print(X)
print( 80*"=")

# Step 2: COmpute Tangent 

# Perturb solution to compute tangent

x1 = X[0,0] + oti.e(1) # 2.4,  0
x2 = X[1,0] + oti.e(2) # 3.2, -4

X = oti.array([x1,x2])

res = fun2(X,r,m,b)

# Define tangent matrix:
T = np.zeros((2,2)) 
T[:,0:1] = res.get_im([1])
T[:,1:2] = res.get_im([2])


Tinv = np.linalg.inv(T)
print()
print("--> Out step2:")
print(Tinv)

print( 80*"=")


# Step 3: Residual evaluation to compute derivatives:

# Perturb input variables to compute the derivatives wanted.
# Using first truncation order 1.
order = 1
r = r.real + oti.e(1,order=order)
m = m.real + oti.e(2,order=order)
b = b.real + oti.e(3,order=order)

# Define the solution values from the real values known.
# No imaginary perturbations!
x1 = x1.real 
x2 = x2.real 

X = oti.array([x1,x2])
X # X has no OTI perturbations yet.


# Define maximum order of derivative to compute:
order = 3
for p in range(1,order+1):
    
    # Set truncation order for desing and state variables to ordi.
    
    r = r + 0*oti.e(1,order=p)
    m = m + 0*oti.e(1,order=p)
    b = b + 0*oti.e(1,order=p)

    X = X + 0*oti.e(1,order=p)
    
    # Evaluate residual equation:
    # Evaluate the residual at the known solution.
    res = fun2(X,r,m,b)
    


    # Compute p'th order RHS
    rhsp = oti.get_order_im_array(p,res)
    
    # Solve p'th order imdir of solution .
    Xp = np.dot(Tinv,-rhsp)
    
    # Apply imdirs along OTI solution vector X
    oti.set_order_im_from_array(p,Xp,X)

print()
print("--> Out step 3: Solution & derivatives.")
print(X)

print( 80*"=")
print()
# In[18]:
print("Verification 1: Total derivatives of residual for each order.")

# Check residual calculation:
res = fun2(X,r,m,b)
for p in range(1,order+1):
    RESp = oti.get_order_im_array(p,res)
    print('Total derivative of order {0}'.format(p))
    print(RESp)
# end for



print( 80*"=")

print("Verification 2: Total derivatives compared:")
# Evaluate the roots of the problem from analytical solution:
RootsProblem =  intersect_pts(r,m,b,alg=oti)


X_an = RootsProblem[0]

diff = X-X_an
for p in range(1,order+1):
    errp = oti.get_order_im_array(p,diff)
    print('Abs error for derivs of order {0}'.format(p))
    print(errp)
# end for


