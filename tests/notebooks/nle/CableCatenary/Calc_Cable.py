import numpy as np
import pyoti.sparse as oti
import matplotlib as mpl
import matplotlib.pyplot as plt

def leer_entradas(Directorio_problema):
	Dir = Directorio_problema+"/"
	cable_prop = np.loadtxt(Dir + "cable_prop.csv", dtype = object, delimiter = ",")
	cable_prop[:,1] = cable_prop[:,1].astype(float)
	cargas = np.reshape(np.loadtxt(Dir + "loads.csv", delimiter = ","), (-1, 2))
	for i in range(len(cable_prop)):
		globals()[cable_prop[i,0]] = cable_prop[i,1]
	return (l,h,L0,A0,E,w,cargas)

def param_adim(l,h,L0,A0,E,w,cargas):
	W = w*L0
	gamma = l/L0
	delta = h/L0
	beta = W/(E*A0)
	Psi = oti.zeros((cargas.shape[0]+2,1))
	Sigmas = oti.zeros((cargas.shape[0]+1,1))
	for i in range(cargas.shape[0]):
		Psi[i+2,0] = cargas[i,0]/W
		Sigmas[i+1,0] = cargas[i,1]/L0
	#Psi = np.append([0,0],cargas[:,0])/W
	#Sigmas = np.append([0],cargas[:,1])/L0
	return (gamma,delta,beta,Psi,Sigmas)

def calc_gi_fi(order,nbases,gamma,delta,beta,Psi,Sigmas,gi_0,fi_0):
    x0 = oti.zeros(2,nbases=nbases,order=order)
    x0[0], x0[1] =  gi_0, fi_0
    tol = 1e-15
    root = newton_otisis(func, j_oti, x0, tol, args=(gamma,delta,beta,Psi,Sigmas))
    return root

def newton_otisis(func, jaco, x, tol, maxiter=50, args=(),verbose=False):
    error = 1e30
    n = 0
    nx = x.shape[0]
    dx = oti.zeros( (nx,1), order=x.order)
    while error > tol:
        if n==maxiter:
            print("No converge.", maxiter, "it.")
            break
        dx = oti.dot(oti.inv(-jaco(x,*args)),func(x,*args))
        error = oti.norm(dx).real/oti.norm(x).real
        if verbose:
            print("Error for iter {0} - {1:.6e}".format(n,error))
            print("Current solution:\n",x.real)
        x+= dx
        n+= 1
    #print("niter: ",n)
    #print("rel_err:",(oti.norm(dx)/oti.norm(x)).get_deriv(0))
    return x

def j_DF (x, *args):
    h = 1e-8
    nx = x.shape[0]
    J = oti.zeros((nx,nx), order=x.order)
    for i in range(nx):
        xh = x.copy()
        xh[i,0]+= h
        dfdxi = (func(xh,*args) - func(x,*args))/h
        for j in range(nx):
            J[j,i] = dfdxi[j,0]
    return J

def j_oti (x, *args):
    nx = x.shape[0]
    next_base = max(func(x,*args).get_active_bases()) + 1
    e_x = oti.zeros((nx,1), order=x.order+1)
    for i in range(nx):
        e_x[i] = oti.e(next_base + i, order=x.order+1 )
    J = oti.zeros((nx,nx), order=x.order)
    fun = func(x+e_x, *args) 
    for n in range(nx):
        J_col = fun.extract_deriv(next_base + n)
        for j in range(nx):
            J_col = J_col.truncate(next_base + j)
        for m in range(nx):
            J[m,n] = J_col[m,0]
    return J


def sumpsi(Psi,j):
    if j==-1:
        return Psi[0,0]
    else:
        sumPsi = 0
        for i in range(j+2):
            sumPsi = sumPsi + Psi[i,0]
        #end for
        return sumPsi
    # end if 

def func(x,gamma,delta,beta,Psi,Sigmas):
    f= oti.zeros((2,1), order=x.order)
    sum_gi = 0
    sum_fi = 0
    sumPsi = 0
    
    gi = x[0,0]
    fi = x[1,0]

    for i in range(Psi.shape[0]):
        sumPsi = sumPsi + Psi[i,0]
    #end for

    for i in range(Sigmas.shape[0]):
        
        sum_gi = ( sum_gi + 
                   oti.asinh( ( fi - sumpsi(Psi,i  ) - Sigmas[i,0]) / gi) - 
                   oti.asinh( ( fi - sumpsi(Psi,i-1) - Sigmas[i,0]) / gi) )

        sum_fi = ( sum_fi + 
                   beta * Psi[i+1,0] * ( Sigmas[i,0] - 1 ) + 
                   oti.sqrt( (fi - sumpsi(Psi,i  ) - Sigmas[i,0] )**2 + gi**2 ) - 
                   oti.sqrt( (fi - sumpsi(Psi,i-1) - Sigmas[i,0] )**2 + gi**2 )   )
    # end for 
    f[0,0] = beta - gamma/gi + oti.asinh(fi/gi) - oti.asinh((fi-sumPsi-1)/gi) + sum_gi
    f[1,0] = beta*(fi-0.5) - delta + oti.sqrt(fi**2+gi**2) - oti.sqrt((fi-sumPsi-1)**2 + gi**2) + sum_fi
    return f

def solu(gi,fi,beta,Psi,Sigmas,s,n):
    sum_xi = 0
    sum_eta = 0
    sumPsi = 0
   
    for i in range(0,n+2):
        sumPsi = sumPsi + Psi[i,0]
    # end for
    
    for i in range(n):

        sum_xi = ( sum_xi + 
                   oti.asinh((fi-sumpsi(Psi,i+1)-Sigmas[i+1,0])/gi) - 
                   oti.asinh((fi-sumpsi(Psi,i  )-Sigmas[i+1,0])/gi)    )

        sum_eta = ( sum_eta + beta*Psi[i+2,0]*(Sigmas[i+1,0]-s) + 
                    oti.sqrt(gi**2 + (fi-sumpsi(Psi,i+1)-Sigmas[i+1,0])**2) - 
                    oti.sqrt(gi**2 + (fi-sumpsi(Psi,i  )-Sigmas[i+1,0])**2)    )

    # end for


    xi = gi*(beta*s + oti.asinh(fi/gi) - oti.asinh((fi-sumPsi-s)/gi) + sum_xi)
    eta = beta*s*(fi-s/2) + oti.sqrt(gi**2 + fi**2) - oti.sqrt(gi**2 + (fi-sumPsi-s)**2) + sum_eta
    tau = oti.sqrt(gi**2 + (fi - sumPsi - s)**2)
    return(xi,eta,tau)

def curva(nbases,order,gi,fi,beta,Psi,Sigmas,p):
    S = np.linspace(0,1,p)
    N = Sigmas.shape[0] - 1
    a = p + N
    A = oti.zeros((a,3),nbases=nbases,order=order)
    c = 0
    for n in range(N+1):
        sn = Sigmas[n,0].get_deriv(0)
        if n < N:
            sn_1 = Sigmas[n+1,0].get_deriv(0)
        elif n==N:
            sn_1 = 1.
        s0 = S[S<=sn_1]
        s = s0[s0>=sn]
        xi, eta, tau = solu(gi,fi,beta,Psi,Sigmas,sn,n)
        A[c,0] = xi
        A[c,1] = eta
        A[c,2] = -1
        c+=1
        for i in range(len(s)): 
            if s[i]>sn and s[i]<sn_1:
                xi, eta, tau = solu(gi,fi,beta,Psi,Sigmas,s[i],n)
                A[c,0] = xi
                A[c,1] = eta
                A[c,2] = tau
                c+=1
            elif s[i]==sn_1:
                xi, eta, tau = solu(gi,fi,beta,Psi,Sigmas,s[i],n)
                A[c,0] = xi
                A[c,1] = eta
                A[c,2] = -1
                c+=1
    return(A)

def plot_curva(x,y,T,u,x_0,x_2,y_0,y_2,color=None):
    P = np.where(T < -1)[0]
    xf = np.zeros(len(P))
    yf = np.zeros(len(P))
    for i in range(len(P)):
        j = P[i]
        xf[i] = x[j]
        yf[i]= y[j]
    print("Conf. " + str(u) + ": x = "+str(xf[1])+" , y = "+str(yf[1]))
    plt.gca().invert_yaxis()
    if color is not None:
        plt.plot(x,y,color=color, ls='-', lw=3, label="Load case "+str(u))
    else:
        plt.plot(x,y, ls='-', lw=3, label="Load case "+str(u))
    if x_0.any() != None:
        plt.plot(x_0,y_0, ':', lw=2.5, color="orange" ,label="ROM Load case 0")
        plt.plot(x_2,y_2, ':', lw=2.5, color="r" ,label="ROM Load case 2")
    
    plt.plot(xf,yf, 'oC5', markersize=5, zorder=1000)
    
    
   
    




