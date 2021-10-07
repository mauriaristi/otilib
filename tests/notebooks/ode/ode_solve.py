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
def ode_step(F,x0,t0,eps=1e-3,order = 5, dt_tol = 1e-11):
    
    oti.set_trunc_order(order)
    x = []
    zero_oti = 0*oti.e(1,nbases=1, order = order)
    # Create  holders for the result.
    for i in range(len(x0)):
        
        x.append( x0[i] + zero_oti )

    # end for 
    t = t0 + oti.e(1, nbases=1, order = order)
    for _ in range(order+1):
        
        x_t = F(t,x)
        
        # Update x from x_t.
        for k in range(1,order+1):

            # Set all imaginary directions from the result.
            for i in range(len(x)):
                x[i][[0,k]] = x_t[i][[0,k-1]]/k
                
            # end for 

        # end for 
        
    # end for 
    
    # Estimate step dt.
    Err = np.zeros(len(x_t))
    norm_np1 = 1.0
    
    for i in range(len(x_t)):
        
        Err[i] = x_t[i][[0,order]]/(order+1) # Extract the last derivative to estimate the error.
                                # squared to get norm 2.

    # end for  

    norm_np1 = np.linalg.norm(Err,2)

    x_max = 1e-30
    for xi in x0:
        xk = abs( xi[ [ 0, 0 ] ] )
        if xk > x_max:
            x_max = xk
        # end if 
    # end for
     
    
    # if norm_np1 <= dt_tol:

    #     ordi = order
    #     break_flag = 1

    #     # try other derivatives.
    #     while (ordi > 1 and break_flag):

    #         for i in range(len(x)):
                
    #             Err[i] = x[i][[0,ordi]]

    #         # end for

    #         ordi -= 1 # decrease by one.

    #         norm_np1 = np.linalg.norm(Err,2)

    #         if norm_np1 > dt_tol:

    #             break_flag = 0

    #         # end if 

            
    #     # end while

    #     if break_flag:

    #         # the whole step can be undertaken.
    

    # Estimate the maximum step-size to obtain eps or less error.
    
    dt = np.power(eps/norm_np1,1.0/(order+1.0))
    
    return [x, dt]
# ====================================================================================================



# ****************************************************************************************************
def ode_integrate( F, x0, t0, tf, eps=1e-3, order = 5, niter_max = 10000):
    
    # For now, t0 always 0.

    ti = t0
    xi = x0.copy()
    
    n_functs = len(x0)
    iteration = 0

    res = []

    res.append([ xi, xi, ti])
    #loop until the final point is reached.
    
    while( ti < tf and iteration < niter_max  ):

        # Get OTI result and dt.
        x, dt_est = ode_step( F, xi, ti, eps=eps,order = order)

        # 

        ti = ti + dt_est
        xi = X(dt_est,x)

        iteration += 1

        # for i in range(n_functs):

        #     xi[i] = xf[i]

        # # end for.

        res.append([xi, x, ti])

    # end while.

    if iteration >= niter_max:

        print("WARNING: Maximum number of iteration reached. Results may not be valid. Review results carefully.")
    
    # end if.

    return res

# ====================================================================================================




# ****************************************************************************************************
def euler_integration(F,x0,dt,tf):

    x1 = x0.copy()

    nevals = int(tf//dt+1)
    t = 0
    x_diff = np.zeros((nevals+1,3))

    x_diff[0,0:2] = x0
    x_diff[0,2] = t

    for i in range(1,nevals):
        
        # Get dF/dt.
        df    = F(t,x1)

        for k in range(len(df)):
        
            x1[k] = x1[k]+df[k]*dt
        
        # end for 

        t += dt # accumulate t.
        
        x_diff[i,0:2] = x1
        x_diff[i,2]   = t
        
    # end for 

    
    # Add step for x(tf)
    
    df    = F(tf,x1)
    
    for k in range(len(df)):
        
        x1[k] = x1[k]+df[k]*(tf-t)
    
    # end for 
    
    x_diff[-1,0:2] = x1
    x_diff[-1,2]   = tf

    
    return x_diff

# ====================================================================================================


    
# ****************************************************************************************************
def get_interpolate(ode_sol, dt, tf, order = None):

    t_sim = ode_sol[-1][2]
    
    t_vals = np.arange(0,min(tf,t_sim)+dt,dt)
    
    x_vals = np.zeros((t_vals.size,3))
    
    k = 1 # Use the first element in the solution.
    i = 0

    t_eval1 = ode_sol[k-1][2]
    t_eval2 = ode_sol[k][2]
    x_eval  = ode_sol[k][1]

    for t in t_vals:

        dti = t - t_eval1
        dtf = t_eval2 - t
        if dtf < 0:
            # The next element from the solution should be taken.

            while (dtf < 0):
                k += 1
                t_eval1 = ode_sol[k-1][2]
                t_eval2 = ode_sol[k][2]
                x_eval = ode_sol[k][1]
                
                dti = t - t_eval1
                dtf = t_eval2 - t
            # end while

        # end if 
        
        x_vals[i,0:2] = X(dti,x_eval,order)
        x_vals[i,2  ] = t
        i += 1

    # end for 
    

    return x_vals

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