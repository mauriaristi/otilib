

import numpy as np
from scipy.special import comb



# Generate all precomputed imaginary directions from order 1 until order 'maxOrder'.
# The number of maximum basis per order is given by the array 'max_basis_k'
def genPrecompData(max_basis_k=[3,3,3,3,3],maindir=''):
    
    maxOrder = len(max_basis_k)
    precDir =  []    # Array to hold the precomputed directions.
    precNdir = []    # Array to hold the precomputed number of directions.

    print("Precomputing order ",1)
    # Generate order 1:
    m = max_basis_k[0]
    order_i_dir = np.arange(1,m+1,dtype = np.uint16)
    order_i_dir.shape = (m,1)
    
    precDir.append(order_i_dir)
#     precNdir.append(order_i_dir.copy().reshape((max_basis_k[0],)))
    precNdir.append(np.arange(0,m+1,dtype = np.uint64))
    
    # Save files in Numpy format.
    pathname = maindir#+"/"

    filename = 'fulldir_n'+str(1)+'_m'+str(m)
    np.save(pathname+filename,order_i_dir)      # all OTI directions of order 'order'.

    filename = 'ndirs_n'+str(1)+'_m'+str(m)
    np.save(pathname+filename,precNdir[0])       # number of directions of with m and before.
    
    for order in range(2,maxOrder+1):
        
        print("Precomputing order ",order)
        m = max_basis_k[order - 1]
        ndir = comb(order+m-1,order,exact =True)
        order_i_dir = np.zeros([ndir,order],dtype = np.uint16)

        kk = 0
        for i in range(1,m+1):
            
            ndir_ord_m_1 = precNdir[-1][i]
            order_i_dir[kk:int(kk+ndir_ord_m_1),:-1] = precDir[-1][:ndir_ord_m_1,:]
            order_i_dir[kk:int(kk+ndir_ord_m_1), -1] = i
            
            kk = int(kk + ndir_ord_m_1)
            
        # end for
        
        
        ndir_ord_i = np.zeros(m+1,dtype=np.uint64)
        for mm in range(1,m+1):
            
            ndir_ord_i[mm] = comb(order+mm-1,order,exact = True)
            
        # end for 
        
        
        
        precDir.append(order_i_dir)
        precNdir.append(ndir_ord_i) 
        
        
        genPrecompMult( order, m, precDir, precNdir, maindir=maindir)
        
        
        # Save files in Numpy format.
        pathname = maindir#+"/"
        
        filename = 'fulldir_n'+str(order)+'_m'+str(m)
        np.save(pathname+filename,order_i_dir)      # all OTI directions of order 'order'.
        
        filename = 'ndirs_n'+str(order)+'_m'+str(m)
        np.save(pathname+filename,ndir_ord_i)       # number of directions of with m and before.

        
    # end for
    
    return (precDir,precNdir)
    
# end function

def genPrecompMult( order, m, precDir, precNdir,maindir=''):
    print('order: ',order)
    ii=0
    for ord1 in range(1,order//2+1):
        ord2 = int(order-ord1)
        print('multiplication of orders: ', ord1, ord2)
        
        size1 = precNdir[ord1-1][m]
        size2 = precNdir[ord2-1][m]
        dirs1 = precDir[ord1-1][:size1]
        dirs2 = precDir[ord2-1][:size2]
        
        multresi = np.zeros((size1,size2),dtype=np.uint64)
        i = 0
        
        for dir1 in dirs1:
            
            j = 0
            if i%100==0:
                print('  - Multiplying dir ',dir1)
            # end if 
            
            for dir2 in dirs2:

                pos = multiplyDirs(dir1,dir2,precDir,precNdir)
                multresi[i,j] = pos
                j += 1
                
            # end for 
            
            i += 1
            
        # end for 
        
        # Save files in Numpy format.
        pathname = maindir#+"/"
        
        filename = 'multtabl_n'+str(order)+'_m'+str(m)+'_'+str(ii)
        np.save(pathname+filename,multresi)      # all OTI directions of order 'order'.
        
        ii+=1
        
        
# end function

def multiplyDirs(dir1,dir2,precDir,precNdir):
    # print('dir1: ',dir1)
    # print('dir2: ',dir2)
    concat = np.concatenate((dir1,dir2))# creates a new array...
    # print(concat)
    newdir = np.sort(concat)
    # print(newdir)
    neword = newdir.size
    # print('neword: ', neword)
    pos = np.uint64(0)
    for i in range(1,neword+1):
        m = newdir[i-1]
        # print('m: ',m)
        # print('i: ',i)
        # print(precNdir[i-1][m-1])
        pos += np.uint64(precNdir[i-1][m-1])
        # print('pos = ', pos)
    # end function
    # print('final pos = ', pos)
    # print('newdir:  ', newdir)
    # print('Dir Res: ', precDir[neword-1][pos])
    return pos
    
# end function



ndirs = [10,10,10,10,10,10,10,10,10,10]
outDir = 'data/'

# [65535,10000,100,100,10,10,10,10,10,10]
(precDir,precNdir) = genPrecompData(max_basis_k=ndirs,maindir=outDir)