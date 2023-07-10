import pyoti.sparse as oti
import numpy as np





def helmholtz_free_fwd(x,b,A,T):
    '''
        This function evaluates the Helmholtz free energy function 
        (see arxiv,org/pdf/1502.05767)

    INPUTS:
    - x: Array of size n, number of variables.
    - b: Array of size n, vector of constants.
    - A: Matrix of size (n x n) of constants.
    - T: Scalar, temperature.
    '''
    
    n = x.shape[0]

    R = 8.314 # J/mol

    
    t1 = np.dot(b,x)
    t2 = np.dot(x,np.dot(A,x))

    
    t3 = t2 / (np.sqrt(8) * t1)
    
    t4 = np.log( ( 1 + ( 1+np.sqrt(2) * t1 ) ) / ( 1 + ( 1 - np.sqrt(2) * t1 ) ) ) 

    t5 = t3*t4

    t6 = 0.0
    t7 = 1.0/(1-t1)

    for i in range(n):
        t6 += np.log(x[i]*t7)
    # end for 

    f = t6* R * T - t5

    return f

# end function



def helmholtz_free_oti(x,b,A,T):
    '''
        This function evaluates the Helmholtz free energy function 
        (see arxiv,org/pdf/1502.05767)

    INPUTS:
    - x: Array of size n, number of variables.
    - b: Array of size n, vector of constants.
    - A: Matrix of size (n x n) of constants.
    - T: Scalar, temperature.
    '''
    
    n = x.shape[0]

    R = 8.314 # J/mol

    
    t1 = oti.dot_product(b,x)
    t2 = oti.dot_product(x,oti.dot(A,x))

    
    t3 = t2 / (np.sqrt(8) * t1)
    
    t4 = oti.log( ( 1 + ( 1+np.sqrt(2) * t1 ) ) / ( 1 + ( 1 - np.sqrt(2) * t1 ) ) ) 

    t5 = t3*t4

    t6 = 0.0
    t7 = 1.0/(1-t1)

    for i in range(n):
        t6 += oti.log(x[i,0]*t7)
    # end for 
    
    f = t6* R * T - t5

    return f

# end function



def helmholtz_free_oti_rev(x,b,A,T):
    '''
        This function evaluates the Helmholtz free energy function 
        (see arxiv,org/pdf/1502.05767)

    INPUTS:
    - x: Array of size n, number of variables.
    - b: Array of size n, vector of constants.
    - A: Matrix of size (n x n) of constants.
    - T: Scalar, temperature.
    '''
    
    n = x.shape[0]

    R = 8.314 # J/mol

    
    t1 = oti.dot_product(b,x)
    t2 = oti.dot_product(x,oti.dot(A,x))

    
    t3 = t2 / (np.sqrt(8) * t1)
    
    t4 = oti.log( ( 1 + ( 1+np.sqrt(2) * t1 ) ) / ( 1 + ( 1 - np.sqrt(2) * t1 ) ) ) 

    t5 = t3*t4

    t6 = 0.0
    t7 = 1.0/(1-t1)

    for i in range(n):
        t6 += oti.log(x[i,0]*t7)
    # end for 
    
    f = t6* R * T - t5

    return f

# end function

n = 50

x = np.ones(n)*0.02
b = np.ones(n)*0.05
A = np.ones((n,n))



T = 300.0


f = helmholtz_free_fwd(x,b,A,T)

print(f)



# OTI version!

order=2
xo = oti.array(x)
for i in range(n):
    xo[i,0] = xo[i,0] + oti.e(i+1,order=order)
# perturb here
bo = oti.array(b)
Ao = oti.array(A)



fo = helmholtz_free_oti(xo,bo,Ao,T)

print(fo)


