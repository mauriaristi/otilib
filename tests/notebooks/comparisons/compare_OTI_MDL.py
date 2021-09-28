# 1. SET GLOBAL PATH 
import sys
path2oti = '../'
sys.path.append(path2oti) # Add path to OTI library.
path2mdl = '../../aaguirr2/multi-z/Python/'
sys.path.append(path2mdl) # Add path to MDL library.

# 2. OTI LIBRARY
import otilib as oti
np = oti.np
oti_e = oti.e


# 3. MULTIDUAL LIBRARY
import multiZ.mdual as mdl


# 4. SPARSE MATRIX LIBRARY.
import scipy as sp



# 5. TIME MEASURING 
import time

# 6. PLOTTING
import matplotlib.pyplot as plt
# %matplotlib notebook
import matplotlib.patches as mpatches
import matplotlib.lines as mlines
from matplotlib.ticker import MultipleLocator, FormatStrFormatter




colors = ['m','b','g','c','r','k']
o_patch = []



nvarsTotal = 10000
x_realVals = np.arange(0.01,2*np.pi,2*np.pi/nvarsTotal)

# sp.sparse.csr_matrix

h = oti.get_dHelp()



# ###########################################################################
#                                FUNCTIONS
# ###########################################################################

# ***************************************************************************
def numExp(num):
    """
    DESCRIPTION: This function returns the ordinal number compliment
                 according to the given input number.

    """
    # -----------------------------------------------------------------------
    if num == 1:
        return 'st'
    elif num == 2:
        return 'nd'
    elif num==3:
        return 'rd'
    else:
        return 'th'
    # end if
# ***************************************************************************

# ***************************************************************************
def f(X_oti):
    """
    DESCRIPTION: This function evaluates the multiplication of sines of 
                 multiple sparse matrices that represents HyperComplex 
                 numbers.

    """
    # -----------------------------------------------------------------------
    
    # Create empty holder
    res = sp.sparse.csr_matrix(np.eye(X_oti[0].shape[0]))
    
    for i in range(len(X_oti)):
    
        res = res*X_oti[i].sin()
    
    # end for 

    return res
# ***************************************************************************

# ***************************************************************************
def ffast(X_oti):
    """
    DESCRIPTION: Fast version of function f implemented so that 
                 multiplication of sparse matrices is replaced to
                 matrix-vector multiplications
                 

    """
    # -----------------------------------------------------------------------

    # Create empty holder
    res = np.zeros(X_oti[0].shape[0])
    res[0]=1

    for i in range(len(X_oti)):

        res = X_oti[i].sin()*res

    # end for 

    return res
# ***************************************************************************

# ***************************************************************************
def multidual_numevals_efficient(m,order):
    
    return sp.special.comb(order+m-1,m-1,exact=True)
# ***************************************************************************

# ***************************************************************************
def mdualGetMatPos(dirBasis,maxBasis):
    
    maxBin= 2**maxBasis-1
    binEq = 2**(dirBasis-1)
    bitLenght = dirBasis
    
    bit64= (2**64-1)^maxBin
    dimR = dirBasis-1
    dimL = maxBasis-dirBasis
    col = np.empty(2**(maxBasis-1),dtype = np.uint64)
    row = np.empty(2**(maxBasis-1),dtype = np.uint64)
    
    
    for i in range( 0, ( 2**(maxBasis-1) ) ):
                  
        left = i >> dimR << dimR
        right  = (i^left) 
        left = left<<1
        
        
        row[i] = left+right+binEq
        col[i] = left+right
        
    return row,col
# ***************************************************************************


# ###########################################################################
#                              END FUNCTIONS
# ###########################################################################







# ###########################################################################
#                                MAIN PROGRAM
# ###########################################################################
# 


# ###########################################################################
#                         1. PLAIN OTI EVALUATION
# ###########################################################################
# 
print("\n --- Plain OTI --- \n")
var_oti = [ [1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900],
            [1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100],
            [1,2,3,4,5,6,7,8,9,10,20,30,40,50,60]]
# var_oti = [ [1,2,3,4,5,6,7,8,9,10],
#             [1,2,3,4,5,6,7,8,9,10],
#             [1,2,3,4,5,6,7,8,9,10]]

ord_oti = [1,2,3]
cputimes_oti = []

for i in range(len(ord_oti)):

    cputimes_oti.append(np.empty( (len( var_oti[i] ), 3 ) ,dtype=np.float64))

# end for 



for ordIndx in range(len(ord_oti)):
    
    orderAnalysis = ord_oti[ordIndx]
    print(orderAnalysis)
    
    k = 0

    for nvarAnalysis in var_oti[ordIndx]:

        print("-"+str(nvarAnalysis))
               
        # create oti matrices:

        baseMatr = oti.get_CR(nvarAnalysis,orderAnalysis).tocoo()
        eyeMatr = sp.sparse.diags([1],0,shape=baseMatr.shape,format="lil")
        X_oti = []
        factor = 0.0

        for i in range(nvarAnalysis):
            
            x_oti_tmp = x_realVals[i] * eyeMatr
            
            
            pos = h.getNels(i,orderAnalysis)
            indxPos, = np.where(baseMatr.data==pos+1)
            
            for kkk in indxPos:
            
                x_oti_tmp[baseMatr.row[kkk],baseMatr.col[kkk] ] = 1.0
            
            # end for 
                
            

            X_oti.append(x_oti_tmp.tocsr())

        # end for 
        
        nevals = 10 # Number of evaluations of function f to get 
                    # statistical mean of cputime.

        start = time.time()
        
        for i in range(nevals):

            f_eval_oti = ffast(X_oti)

        # end for 
        
        end = time.time()
        
        cputimes_oti[ordIndx][k,0] = nvarAnalysis
        cputimes_oti[ordIndx][k,1] = orderAnalysis
        cputimes_oti[ordIndx][k,2] = (end-start)/nevals*1000 # time in us
        
        k+=1

    # end for 

# end for


# ###########################################################################
#                         2. REPETITIVE MDL EVALUATION
# ###########################################################################
# 
print("\n --- Repetitive MultiDual --- \n")
cputimes_rmdl = []

for i in range(len(ord_oti)):

    cputimes_rmdl.append(np.empty( (len( var_oti[i] ), 3 ) ,dtype=np.float64))

# end for 

for ordIndx in range(len(ord_oti)):
    
    orderAnalysis = ord_oti[ordIndx]
    print(orderAnalysis)
    
    k = 0

    for nvarAnalysis in var_oti[ordIndx]:
        print('-'+str(nvarAnalysis))
        
        # create oti matrices:


        X_mdl = []
        factor = 0.0
        base_mdl = mdl.mdual(np.zeros(2**(orderAnalysis)))

        for i in range(nvarAnalysis):
            
            x_mdl_tmp = base_mdl + x_realVals[i]
            
            # The first idea is to evaluate "brute force method, all derivatives in one analysis

            kk=1
            for o in range(orderAnalysis):
                
                x_mdl_tmp += mdl.eps(kk)
                kk+=1

            # end for
            
            X_mdl.append( sp.sparse.csr_matrix( x_mdl_tmp.tomatrix() ) )

        # end for 
        
        nevals = 10
        start = time.time()
        
        for i in range(nevals):

            f_eval_oti = ffast(X_mdl)

        # end for 
        
        end = time.time()
        
        cputimes_rmdl[ordIndx][k,0] = nvarAnalysis
        cputimes_rmdl[ordIndx][k,1] = orderAnalysis
        cputimes_rmdl[ordIndx][k,2] = (end-start)/nevals*1000*multidual_numevals_efficient(nvarAnalysis,orderAnalysis) # time in us
        
        k+=1
        
    # end for 

# end for


# ###########################################################################
#                         3. PLAIN MULTIDUAL EVALUATION
# ###########################################################################
# 

print("\n --- Plain MultiDual --- \n")
variables_mdl = [[1,2,3,4,5,6,7,8,9,10,20],[1,2,3,4,5,6,7,8,9,10],[1,2,3,4,5,6,7]]
orders_mdl = [1,2,3]

cputimes_mdl = [np.empty((len(variables_mdl[0]),3),dtype=np.float64),
               np.empty((len(variables_mdl[1]),3),dtype=np.float64),
               np.empty((len(variables_mdl[2]),3),dtype=np.float64)]
for ordIndx in range(len(orders_mdl)):

    orderAnalysis = orders_mdl[ordIndx]
    k = 0
    print(orderAnalysis)
    for nvarAnalysis in variables_mdl[orderAnalysis-1]:
       
        
        X_mdl = []
        factor = 0.0

        size = 2**(orderAnalysis*nvarAnalysis)
        eyeMatr = sp.sparse.diags([1],0,shape=(size,size),format="lil")
        
        kk=1
        

        
        endl = '\r'
        print('- %d --> Progress Matrix Generation:   0.0 %s       '%(nvarAnalysis,'%'),end=endl)
        for i in range(nvarAnalysis):
            

            
            x_mdl_tmp = eyeMatr*x_realVals[i]
            
            
                
            # The first idea is to evaluate "brute force method, all derivatives in one analysis
            
            for o in range(orderAnalysis):
                rows,cols =oti.get_CR_mdl(kk,orderAnalysis*nvarAnalysis)
                x_mdl_tmp[rows,cols] = 1.0
                kk+=1
            
            # end for
                
            
            
            X_mdl.append( x_mdl_tmp.tocsr()  )
            print('- %d --> Progress Matrix Generation: %.1f %s       '%(nvarAnalysis, int((i+1)/nvarAnalysis*1000)/10.0,'%'),end=endl)
            

        # end for 
        print('- %d --> Progress Matrix Generation: %.1f %s'%(nvarAnalysis,int((i+1)/nvarAnalysis*1000)/10.0,'%'))
        
        nevals = 10
        start = time.time()
        
        for i in range(nevals):
            f_eval_oti = ffast(X_mdl)
        # end for 
        
        end = time.time()
        
        cputimes_mdl[ordIndx][k,0] = nvarAnalysis
        cputimes_mdl[ordIndx][k,1] = orderAnalysis
        cputimes_mdl[ordIndx][k,2] = (end-start)/nevals*1000 # time in us
        
        k+=1
        # print('finished computing !\n')       
        
        
    # end for 

# end for




# ###########################################################################
#                         4. PLOT AND SAVE
# ###########################################################################

def plotResults(alphaMDL,alphaRMDL,alphaOTI):
    o_patch = []
    plt.figure()
    ax = plt.subplot(111)

    # alphaMDL  = 1.0
    # alphaRMDL = 1.0
    # alphaOTI  = 1.0


    for i in range(len(ord_oti)):
        
        plt.semilogy(var_oti[i],cputimes_oti[i][:,2],colors[i]+'-',alpha=alphaOTI) 
        o_patch.append(mpatches.Patch(color=colors[i%len(colors)], label='$'+str(ord_oti[i])+'^{'+numExp(ord_oti[i])+'}$ order'))

    # end for 

    for i in range(len(ord_oti)):
        
        plt.semilogy(var_oti[i],cputimes_rmdl[i][:,2],colors[i]+'-^', alpha=alphaRMDL) 

    # end for 

       
    for i in range(len(orders_mdl)):
        
        plt.semilogy(variables_mdl[i],cputimes_mdl[i][:,2],colors[i]+'--', alpha=alphaMDL)    
        
    # end for

    if alphaMDL >0.0:
        o_patch.append( mlines.Line2D([], [], color='gray',ls='--',label='MDL',alpha=alphaMDL) ) 
        stage = '1'
    if alphaRMDL > 0.0:
        o_patch.append( mlines.Line2D([], [], color='gray',marker='^',label='Repetitive\nMDL',alpha=alphaRMDL) )  
        stage = '2'
    if alphaOTI > 0.0:
        o_patch.append( mlines.Line2D([], [], color='gray',label='OTI',alpha=alphaOTI) )  
        stage = '3'
    # end if
     


    plt.grid(b=True, which='major')
    plt.grid(b=True, which='minor')
    # plt.ylim([1,15])
    plt.ylabel('CPU time [$\mu s$]')
    plt.xlabel('$m$: Number of variables.')
    plt.legend(handles=o_patch,loc='center left', bbox_to_anchor=(1, 0.5))

    # Shrink current axis by 20%
    box = ax.get_position()
    ax.set_position([box.x0, box.y0, box.width * 0.8, box.height])


    # plt.xlim([1,100])
    plt.savefig("pyOTIvsMMDL_CompTimes_semilog_"+stage+".pdf",dpi=300)
    # plt.show() 



    plt.figure()
    ax = plt.subplot(111)

    for i in range(len(ord_oti)):
        
        plt.loglog(var_oti[i],cputimes_oti[i][:,2],colors[i]+'-',alpha=alphaOTI) 

    # end for 

    for i in range(len(ord_oti)):

        plt.loglog(var_oti[i],cputimes_rmdl[i][:,2],colors[i]+'-^', alpha=alphaRMDL) 

    # end for 

       
    for i in range(len(orders_mdl)):
        
        plt.loglog(variables_mdl[i],cputimes_mdl[i][:,2],colors[i]+'--', alpha=alphaMDL)    
        
    # end for

    plt.grid(b=True, which='major')
    plt.grid(b=True, which='minor')
    # plt.ylim([1,15])
    plt.ylabel('CPU time [$\mu s$]')
    plt.xlabel('$m$: Number of variables.')
    plt.legend(handles=o_patch,loc='center left', bbox_to_anchor=(1, 0.5))

    # Shrink current axis by 20%
    box = ax.get_position()
    ax.set_position([box.x0, box.y0, box.width * 0.8, box.height])


    # plt.xlim([1,100])
    plt.savefig("pyOTIvsMMDL_CompTimes_loglog_"+stage+".pdf",dpi=300)




plotResults(1.0,0.0,0.0)
plotResults(1.0,1.0,0.0)
plotResults(1.0,1.0,1.0)






