# Auxiliary plot functions 

import numpy as np


import matplotlib.pyplot as plt              # Import plot library
import matplotlib.patches as mpatches
import matplotlib.lines as mlines
from matplotlib.ticker import MultipleLocator, FormatStrFormatter

import sympy as sym

import otilib as oti 

oti.h = oti.get_dHelp()

# np.set_printoptions(precision=4,linewidth=130)



# Define Auxiliary Functions

def plotK(K, figsize = 8, issave = False):
    
    near_sq = nearest_square(K.Ndir)
        
    if near_sq < K.Ndir:
        cols = int(np.sqrt(near_sq))
        rows = int(np.sqrt(near_sq)+1)
    else:
        cols = int(np.sqrt(near_sq))
        rows = int(np.sqrt(near_sq))

    # end if 


    f, AX = plt.subplots(rows,cols, sharex='col', sharey='row', figsize = (figsize,figsize))
    

    if cols == rows:

        plt.subplots_adjust(wspace = 0.3 ,hspace = 0.2)  # m=2, n=3
        
    else:
        
        plt.subplots_adjust(wspace = 0.3 ,hspace = 0.2) # m=3 , n=3
        
    # end if 
    
    for i_eval in range(K.Ndir):

        col = i_eval%cols
        row = i_eval//cols

        #figureSize = (9,9)
        #plt.savefig("HyperDual_Spy_CR_n"+str(order)+"_m"+str(nvar)+".pdf",dpi=300)
        #plt.close()

        #plt.figure(figsize=figureSize)
        if cols == 1 and rows == 1:
            ax = AX
        elif cols == 1 or rows ==1:
            ax = AX[i_eval]
        else:
            ax = AX[row,col]
        # end if 
        ax.matshow(K[i_eval].toarray()!=0,cmap='binary',vmax = 1.5)
        title = "$K_{"+directionString(i_eval,K.order,string_mode =0)+"}$"
        ax.set_title(title)
        
        ax.set_xlim(-0.5,K.shape[0]+0.5)
        ax.set_ylim(K.shape[0]+0.5,-0.5)
        
        min_ = -0.5
        max_ = K.shape[0]-0.5
        
        ax.axis('off')        
        ax.set(adjustable='box-forced', aspect='equal')


        if K.shape[0] <50:

            linewidth = 0.2

            for i in range(0,K.shape[0]-1):
                
                
                ax.plot([min_,max_],[i+0.5,i+0.5],'k',linewidth=linewidth)
                ax.plot([i+0.5,i+0.5],[min_,max_],'k',linewidth=linewidth)

            # end for

        # end if
    # end for 
    
    for i in range(i_eval+1,cols*rows):
            
        col = i%cols
        row = i//cols

        if cols == 1 and rows == 1:
            ax = AX
        elif cols == 1 or rows ==1:
            ax = AX[i_eval]
        else:
            ax = AX[row,col]
        # end if 
        ax.set(adjustable='box-forced', aspect='equal')
        ax.axis('off')

    # end for 
    #f.tight_layout()
    if cols == rows:

        plt.subplots_adjust(wspace = -0.35 ,hspace = 0.3)  # m=2, n=3
        
    else:
        
        plt.subplots_adjust(wspace = -0.35 ,hspace = 0.3) # m=3 , n=3
        
    # end if 




# Define Auxiliary Functions

def plotU_2D(x,y,u,th, figsize = 8, issave = False, filename = 'u_2d_alldir',cmap = 'jet'):
    
    # find the best manner to arrange the figure.

    near_sq = nearest_square(u.Ndir)
        
    if near_sq < u.Ndir:
        cols = int(np.sqrt(near_sq))
        rows = int(np.sqrt(near_sq)+1)
    else:
        cols = int(np.sqrt(near_sq))
        rows = int(np.sqrt(near_sq))

    # end if 


    f, AX = plt.subplots(rows,cols, sharex='col', sharey='row', figsize = (figsize,figsize))
    

    if cols == rows:

        plt.subplots_adjust(wspace = 0.3 ,hspace = 0.2)  # m=2, n=3
        
    else:
        
        plt.subplots_adjust(wspace = 0.3 ,hspace = 0.2) # m=3 , n=3
        
    # end if 
    
    for i_eval in range(u.Ndir):

        col = i_eval%cols
        row = i_eval//cols

        
        if cols == 1 and rows == 1:
            ax = AX
        elif cols == 1 or rows ==1:
            ax = AX[i_eval]
        else:
            ax = AX[row,col]
        # end if 
        # plt.tricontourf(nodes[:,0], nodes[:,1],u0, triangles=triang, cmap = 'jet')
# plt.triplot(nodes[:,0], nodes[:,1],'-k' , triangles=triang,linewidth = 0.2)

        cax = ax.tricontourf(x.data[:,0], y.data[:,0], u.data[:,i_eval], triangles=th, cmap=cmap)
        ax.triplot(x.data[:,0], y.data[:,0],'-k' , triangles=th,linewidth = 0.2)

        title = "$u_{"+directionString(i_eval,u.order,string_mode =0)+"}$"
        cbar=f.colorbar(cax,ax = ax)
        # cbar.ax.set_ylabel(title)
        ax.axis('equal')
        ax.set_xlabel("X")
        ax.set_ylabel("Y")
        ax.set_title(title)
        
        
        # ax.axis('off')        
        ax.set(adjustable='box-forced', aspect='equal')


    # end for 
    
    for i in range(i_eval+1,cols*rows):
            
        col = i%cols
        row = i//cols

        if cols == 1 and rows == 1:
            ax = AX
        elif cols == 1 or rows ==1:
            ax = AX[i_eval]
        else:
            ax = AX[row,col]
        # end if 
        ax.set(adjustable='box-forced', aspect='equal')
        ax.axis('off')

    # end for 
    #f.tight_layout()
    # if cols == rows:

    #     plt.subplots_adjust(wspace = 0.05,hspace = 0.3)  # m=2, n=3
        
    # else:
        
    #     plt.subplots_adjust(wspace = 0.05 ,hspace = 0.3) # m=3 , n=3
        
    # # end if 
    

    
    
def forceAspect(ax,aspect=1):
    im = ax.get_images()
    extent =  im[0].get_extent()
    ax.set_aspect(abs((extent[1]-extent[0])/(extent[3]-extent[2]))/aspect)
    

    
    
def nearest_square(num):
    return np.round(np.sqrt(num))**2


def directionString(indx,order,string_mode = 1):
    
    if string_mode == 0:
        
        # get direction and exponent arrays
        dirA = np.array(oti.h.getDirA(indx,order))
        expA = np.array(oti.h.getExpA(indx,order))
        eps = '\epsilon'
        string = ''
        if np.sum(dirA) == 0:
            string = '_{Re}'
        else:
            for i in range(order):
                if dirA[i] == 0:
                    pass
                else:
                    string += eps+'_{'+str(dirA[i])+'}'
                    if expA[i] != 1:
                        string += '^{'+str(expA[i])+'}'

        return string
    
    else:
        
        return str(indx)


def compareResults(f1d_eval, f1s, var_n, var_s, dnfloat, rel = False,val = False,absolute = False, m=1, n=1):
    # Retreive the derivatives using the dual numbers.
    
    neval = oti.findComb(m+1,n)
    f_d = [f1d_eval[0]]
    
    f_syl =   sym.lambdify(tuple(var_s), f1s)
    f_s   =   [f_syl(*tuple(var_n))]
    
    strings = ['Re']
    
    for i in range(1,neval):
        deriv = oti.getDirArray(i,n)
        
        strings.append(str(deriv).replace(" ",""))
        
        f_d.append(f1d_eval.getDeriv(deriv))
        f_l = f1s
        
        # differentiate:
        for der in deriv:
            
            if type(der)== list:
                 for k in range(int(der[1])):
                    f_l = f_l.diff(var_s[der[0]-1])
                #f_l = f_l.diff(var_s[der[0]-1],int(der[1]))
            else:
                
                f_l = f_l.diff(var_s[der-1])
                
            # end if
            
        # end for
        # print("\n\nFunction to evaluate: ", str(deriv))
        # print(f_l)
        
        f_leval = sym.lambdify(tuple(var_s),f_l.doit())
            
        f_s.append(dnfloat(f_leval(*tuple(var_n))))
        
    # print values:
    
    if val:
        print(" --- Comparing results between the libraries ---")
        print(" ")
        print("----------------------------------------------------")
        
        for i in range(neval):
            print(strings[i] +": \t" + str(f_d[i])+"\t : " + str(f_s[i])  ) 
            
    if absolute:
        print(" --- Comparing absolute error ---")
        print(" ")
        print("----------------------------------------------------")
        
        for i in range(neval):
            print(strings[i] +":\t " + str(abs(f_d[i]-f_s[i]))  )
            
    if rel:
        print(" --- Comparing relative error ---")
        print(" ")
        print("----------------------------------------------------")
        
        for i in range(neval):
            print(strings[i] +":\t " + str(abs(f_d[i]-f_s[i])/abs(f_s[i]))  )
    