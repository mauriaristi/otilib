# 1. SET GLOBAL PATH 
import sys
path2oti = '../../../build'
sys.path.append(path2oti) # Add path to OTI library.
# path2mdl = '/Users/mauriaristi/Documents/src/multi-z/Python/'
# sys.path.append(path2mdl) # Add path to MDL library.


import pyoti.dense as oti
eps = oti.e
from pyoti.core import imdir

import numpy as np













# ****************************************************************************************************
def ode_comp_F_derivs(F,x0,eps=1e-3,order = 5):
    
    oti.set_trunc_order(order)
    x = []
    for i in range(len(x0)):
        
        x.append(x0[i]+oti.e(1,nbases=1, order = order))

    # end for 
    
    for i in range(order+1):
        
        x_t = F(x)
        
        # Update x from x_t.
        for k in range(1,order+1):
            
            for i in range(len(x)):
                x[i][[0,k]] = x_t[i][[0,k-1]]/k
                
            # end for 

        # end for 
        
    # end for 
    
    # estimate step
    # print("x_t: \nx1: ",x_t[0],"\nx2: ",x_t[1])
    # print()
    Err = np.zeros(len(x_t))
    dts = np.zeros(len(x_t))
    norm_np1 = 1.0
    
#     for i in range(len(x)):

#         norm_np1 += (x[i][[0,order]])**2 # Extract the last derivative to estimate the error.
#                                 # squared to get norm 2.
#     # end for  

    for i in range(len(x_t)):
        
        Err[i] = x_t[i][[0,order]]/(order+1) # Extract the last derivative to estimate the error.
                                # squared to get norm 2.
        # print("Function: --- ",i)
        # print("eps: ", eps)
        # print("(n+1)!: ", np.math.factorial(order+1))
        # print("d^{n+1}x/dt^{n+1}: ", x_t[i][[0,order]]/(order+1) )
        # print("1/(n+1): ", 1.0/(order+1.0) )
        # print("\n\n")

        dts[i] = np.power(eps*np.math.factorial(order+1)/abs(x_t[i][[0,order]]/(order+1)),1.0/(order+1.0))
    # end for  

    # print("Error: ",Err)
    
    norm_np1 = np.linalg.norm(Err,1)#np.sqrt(norm_np1)
    
    # print("Err:  ",Err)
    # print("\nNorm_2: ",np.linalg.norm(Err,1))
    # print("\nNorm_inf: ",norm_np1)
    print("\ndts: ",dts)


    print()

    # Estimate the maximum step-size to obtain eps or less error.
    dt = np.power(eps*np.math.factorial(order+1)/norm_np1,1.0/(order+1.0))
    
    return x, dt
# ====================================================================================================









# ****************************************************************************************************
def euler_integration(F,x0,dt,tf):

    x1 = x0.copy()

    nevals = int(tf//dt+1)
    t = 0
    x_diff = np.zeros((nevals+1,2))

    x_diff[0] = x0

    for i in range(1,nevals):
        
        # Get dF/dt.
        df    = F(x1)

        for k in range(len(df)):
        
            x1[k] = x1[k]+df[k]*dt
        
        # end for 

        t += dt # accumulate t.
        
        x_diff[i] = x1
        
    # end for 

    
    # Add step for x(tf)
    
    df    = F(x1)
    
    for k in range(len(df)):
        
        x1[k] = x1[k]+df[k]*(tf-t)
    
    # end for 
    
    x_diff[-1] = x1

    
    return x_diff

# ====================================================================================================






# ****************************************************************************************************
def get_x(dt,tf,x,order = None):

    t_vals = np.arange(0,tf,dt)
    x_vals = np.zeros((t_vals.size+1,2))
    
    i=0
    
    for t in t_vals:
        
        x_vals[i] = X(t,x,order)
        i += 1

    # end for 

    # Add end point
    x_vals[-1] = X(tf,x,order)

    return x_vals
# ====================================================================================================




    
# ****************************************************************************************************
def X(t,X,order = None):
    
    n_functs = len(X)

    X_val = [0]*n_functs

    
    if order is not None:
        iters = order+1
    else : 
        iters = X[0].order+1
    # end if 
    
    
    for i in range(iters):
        
        for k in range(n_functs):
            
            X_val[k] += X[k][[0,i]]*t**i
        
        # end for 
        
    # end for 
    
    return X_val


# ====================================================================================================