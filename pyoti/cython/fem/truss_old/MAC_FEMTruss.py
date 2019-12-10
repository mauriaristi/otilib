import numpy as np
import matplotlib.pyplot as plt
import sys
sys.path.append('../aaguirr2/mcxlib/')
sys.path.append('../spr_duallib/')
sys.path.append('../spr_otilibv0.6/')
from mcxlib import *
import spr_duallib as dn 
import spr_otilib as otin

def MAC_PlotSys(nds,els,dsp,fce,U,scaleF=1.0,C=[],M='o-'):
    #DESCRIPTION:   Function that plots the system using a displacement array
    
    #plt.figure()
    ax = plt.axes()

    U_plot=U.copy()
    U_plot=U_plot.reshape(nds.shape[0],2)
    U_plot*=scaleF
    
    Ci=C.copy()
    
    for i in range(0,els.shape[0]):

        v0x=nds[els[i,0],0]+U_plot[els[i,0],0]
        v0y=nds[els[i,0],1]+U_plot[els[i,0],1]
        
        v1x=nds[els[i,1],0]+U_plot[els[i,1],0]
        v1y=nds[els[i,1],1]+U_plot[els[i,1],1]
        if len(Ci)==0:
            plt.plot([v0x, v1x], [v0y, v1y], M, color='k', linewidth=2)
        elif len(Ci)==1:
            plt.plot([v0x, v1x], [v0y, v1y], M, color=str(Ci[0]), linewidth=2)
        elif len(Ci)==els.shape[0]:
            plt.plot([v0x, v1x], [v0y, v1y], M, color=str(Ci[i]), linewidth=2*(2.-Ci[i]))
        else:
            raise TypeError('Unsupported length of color array C -= :' + ': \'' +
              str(len(Ci)) + '\' . It should be same length of number of elements or an array of length = 1' )

    
    for i in range(0,dsp.shape[0]):
        
        v0x=nds[int(dsp[i,0]),0]+U_plot[int(dsp[i,0]),0]
        v0y=nds[int(dsp[i,0]),1]+U_plot[int(dsp[i,0]),1]
        
        v1x=v0x-0.2*(1-dsp[i,1])
        v1y=v0y-0.2*(  dsp[i,1])
        
        plt.plot([v0x, v1x], [v0y, v1y],'r--', linewidth=3)
    
    for i in range(0,fce.shape[0]):
        
        v0x=nds[int(fce[i,0]),0]+U_plot[int(fce[i,0]),0]
        v0y=nds[int(fce[i,0]),1]+U_plot[int(fce[i,0]),1]
        
        v1x=0.1*(fce[i,1])
        v1y=0.1*(fce[i,2])
        
        
        ax.arrow(v0x, v0y, v1x, v1y, head_width=0.05, head_length=0.1, fc='b', ec='b')
    
    tsf=nds+U_plot
    mgn=0.5
    
    minX = np.min(tsf[:,0])
    maxX = np.max(tsf[:,0])
    
    minY = np.min(tsf[:,1])
    maxY = np.max(tsf[:,1])
    
    cX = 0.5*(maxX+minX)
    cY = 0.5*(maxY+minY)
    
    deltaX=maxX-minX
    deltaY=maxY-minY
    
    maxDelta=np.max([deltaX,deltaY])
    
    _minX=cX-maxDelta*.5-mgn
    _maxX=cX+maxDelta*.5+mgn
    _minY=cY-maxDelta*.5-mgn
    _maxY=cY+maxDelta*.5+mgn
    
    plt.xlabel("x")
    plt.ylabel("y")
    ax.set_xlim([_minX,_maxX])
    ax.set_ylim([_minY,_maxY])
    #plt.show()
    
# ==========================================
       
# ==========================================
def MAC_CompK_e(nds,el_i,A_i,E_i):
    
    # Compute elemental stiffness matrix
    
    delta_x = nds[el_i[1],0]-nds[el_i[0],0]
    delta_y = nds[el_i[1],1]-nds[el_i[0],1]
    L_e = np.sqrt(delta_x**2+delta_y**2)
    
    # Compute the angle of inclination of the element.
    theta = np.arctan2(delta_y,delta_x) # (y,x)

    c_th=np.cos(theta)
    s_th=np.sin(theta)

    # Form the elemental stiffness matrix
    


    K_e = np.array([
            [   c_th**2, c_th*s_th,  -c_th**2,-c_th*s_th],
            [ c_th*s_th,   s_th**2,-c_th*s_th,  -s_th**2],
            [-c_th**2  ,-c_th*s_th,   c_th**2, c_th*s_th],
            [-c_th*s_th,  -s_th**2, c_th*s_th,   s_th**2],
        ])*( A_i*E_i/L_e )
    
    return K_e




def MAC_AssmK(K_s,K_e,el_i):
    
    # Assemble the global matrix
    for l in range(0,2):

        for j in range(0,2):

            # Reorganize the elemental stiffness matrix within the global stiffness matrix.
            
            e_i1 = int(el_i[l]*2)
            e_i2 = int(el_i[l]*2+1)
            e_j1 = int(el_i[j]*2)
            e_j2 = int(el_i[j]*2+1)
            
            i1 = l*2
            i2 = l*2+1
            j1 = j*2
            j2 = j*2+1
            
            K_s[e_i1,e_j1]=K_s[e_i1,e_j1] + K_e[i1,j1]
            K_s[e_i1,e_j2]=K_s[e_i1,e_j2] + K_e[i1,j2]
            K_s[e_i2,e_j1]=K_s[e_i2,e_j1] + K_e[i2,j1]
            K_s[e_i2,e_j2]=K_s[e_i2,e_j2] + K_e[i2,j2]
            

        # end for

    # end for
# ==========================================


# ==========================================
def MAC_SolveFEMTruss(nds,els,A,E,dsp,fce,m = -1):

    # SOLVE THE SYSTEM
    typesOfComplex=(np.complex128,np.complex,
        np.complex256,np.complex_,np.complexfloating)
    
    typesOfNumbers=(int,np.int32,np.int64,float,np.float64)
    
    if (type(A[0,0]) is dn.spr_dualnum) or (type(E[0,0]) is dn.spr_dualnum):
        
        if type(A[0,0]) is dn.spr_dualnum:
          
          maxorder = (A[0,0]).maxorder
          
        else:
          
          maxorder = (E[0,0]).maxorder
          
        # end if

        K_s = dn.spr_dualmat((nds.shape[0]*2 , nds.shape[0]*2),maxorder = maxorder)
        
        dualnum = 0.0*dn.e(0)
        
        dualnum.changeOrder(maxorder)

        F_s = np.zeros(nds.shape[0]*2) * dualnum


    elif (type(A[0,0]) is otin.spr_otinum) or (type(E[0,0]) is otin.spr_otinum):


        
        if type(A[0,0]) is otin.spr_otinum:
          
          maxorder = (A[0,0]).maxorder
          
        else:
          
          maxorder = (E[0,0]).maxorder
          
        # end if

        K_s = otin.otimat((nds.shape[0]*2 , nds.shape[0]*2),m,maxorder,2)
        
        otinum = 0.0*otin.e([1])
        
        otinum.changeOrder(maxorder)

        F_s = otin.otivec(np.zeros(nds.shape[0]*2) * otinum,m=m)



        
    elif (type(A[0,0]) is mcxnum) or (type(E[0,0]) is mcxnum):
        
        Order = E[0,0].order
        
        K_s = np.zeros( [nds.shape[0]*2 , nds.shape[0]*2] ) * im(Order)
        F_s = np.zeros(  nds.shape[0]*2 ) * im(Order)
        
    elif (type(A[0,0]) in typesOfComplex) or (type(E[0,0]) in typesOfComplex):
        
        K_s = np.zeros( [nds.shape[0]*2,nds.shape[0]*2] )*1j
        F_s = np.zeros(  nds.shape[0]*2 ) * 1j
    
    elif (type(A[0,0]) in typesOfNumbers) or (type(E[0,0]) in typesOfNumbers):
        
        K_s = np.zeros( [nds.shape[0]*2 , nds.shape[0]*2] )
        F_s = np.zeros(  nds.shape[0]*2 )
        
    else:
        
        raise TypeError('Unsupported format type(s) for -= A:' + ': \'' +
          str(type(A[0])) + '\' and E: \'' + str(type(E[0])) + '\'' )
        
    # end if


    for i in range(0,els.shape[0]):
        el_i = els[i,:]
        
        K_e = MAC_CompK_e(nds,el_i,A[i,0],E[i,0])
        
        # Assemble the global matrix
        MAC_AssmK(K_s,K_e,el_i)

    # end for
    #print(K_s)
    
    # Implement force boundary conditions
    
    for i in range(0,fce.shape[0]):
        F_s[int(fce[i,0])*2] = F_s[int(fce[i,0])*2]+ fce[i,1]
        F_s[int(fce[i,0]*2+1)] = F_s[int(fce[i,0]*2+1)] + fce[i,2]
        
    # end for
    
    TGV=1e30
    
    # Implement displacement boundary conditions
    for i in range(0,dsp.shape[0]):
        
        e_i = int(dsp[i,0]*2+dsp[i,1])
        e_j = int(dsp[i,0]*2+dsp[i,1])
        
        if (type(K_s[0,0]) is mcxnum):
            
            K_s[e_i,e_j]=TGV*mcxnum(np.ones(2**Order))
            F_s[e_j]=dsp[i,2]*TGV*mcxnum(np.ones(2**Order))

        elif (type(K_s[0,0]) is dn.spr_dualnum):
            
            dualnum = 1.0+0*dn.e(1)
            dualnum.changeOrder(maxorder)
            K_s[e_i,e_j]=TGV*dualnum
            F_s[e_i]=dsp[i,2]*TGV*dualnum

        elif (type(K_s[0,0]) is otin.spr_otinum):
            
            otinum = 1.0+0*otin.e(1)
            otinum.changeOrder(maxorder)
            K_s[e_i,e_j]=TGV*otinum
            F_s[e_i]=dsp[i,2]*TGV*otinum
            
        else:
            
            K_s[e_i,e_j]=TGV
            F_s[e_i]=dsp[i,2]*TGV
            
    # end for
    
    
    #Convert to Cauchy Riemann formulation to solve the problem
    if (type(K_s[0,0]) is mcxnum):
        lim=2**Order
        
        K_s_R=np.zeros([K_s.shape[0]*lim,K_s.shape[0]*lim])
        F_s_R=np.zeros([K_s.shape[0]*lim,1])
        
        for i in range(0,K_s.shape[0]):
            for j in range(0,K_s.shape[1]):
                
                K_s_R[i*lim:(i+1)*lim,j*lim:(j+1)*lim] = (K_s[i,j]).toMatrix()  
            F_s_R[i*lim:(i+1)*lim,:]=((F_s[i]).toVector()).reshape([2**Order,1])
            
    
    
    
    # SOLVE THE SYSTEM OF EQUATIONS:    
    if(type(K_s[0,0]) is mcxnum):
        
        U_s_R=np.linalg.solve(K_s_R,F_s_R)
        
        U_s=np.zeros( [nds.shape[0]*2,1] ) * im(Order)
        
        
        for i in range(0,nds.shape[0]*2):
            U_s[i,0]+=mcxnum(U_s_R[i*lim:(i+1)*lim,:])
        
        return (U_s,K_s,F_s.reshape([nds.shape[0]*2,1]))
        
    elif (type(K_s[0,0]) is dn.spr_dualnum):
        
        U_s = dn.solve(K_s,F_s)
        U_s = U_s.reshape(U_s.shape[0],1)
        
        return (U_s,K_s,F_s)


    
    elif (type(K_s[0,0]) is otin.spr_otinum):
        
        
        

        U_s = otin.solve(K_s,F_s)
        #U_s = U_s.reshape(U_s.shape[0],1)
        
        return (U_s,K_s,F_s)


        
    else:
        U_s=np.linalg.solve(K_s,F_s)
        return (U_s,K_s,F_s)
# ==========================================

