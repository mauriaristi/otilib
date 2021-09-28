import sys
path2oti = '../../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

import pyoti.real   as r
import pyoti.sparse as oti 
import pyoti.core   as coti
import pyoti.fem    as fem 

e  = oti.e
np = oti.np

global times
from timeit import default_timer as time

















#*****************************************************************************************************
def solve_2d_cavity(Th, utop, stats=True, solver = 'SuperLU'):
    
    global times
    from timeit import default_timer as time
    
    print("Setting up problem")
    start_time = time()
    
    c1 = -1e-10 # Constant for p*q term 
    
    ndim_analysis = 2
    els = Th.elements[2]

    fem.end_elements()
    
    nnodes_tri6 = Th.nnodes
    nnodes_tri3 = np.unique(Th.elements[2]['indices'][0][:,:3]).size
    
    nDOF   = 2*nnodes_tri6 + nnodes_tri3 # Nodes for order 2   
    
    
    K = alg.lil_matrix((nDOF,nDOF))
    f = alg.zeros((nDOF,1))
    
    
    print("\nStarting elemental computations.")
    
    # 
    for j in range(els['types'].size):

        elm_o2 = fem.element_list[ els['types'][j] ][2] # Take order 2
        elm_o1 = fem.element_list[ els['types'][j] ][1] # Take order 1

        if (not elm_o2.is_allocated()) or (not elm_o1.is_allocated()):

            elm_o2.end()
            elm_o1.end()
            
            elm_o2.allocate(intorder=2)
            elm_o2.allocate_spatial(ndim_analysis,compute_Jinv = True)
            
            elm_o1.allocate(intorder=2)
            elm_o1.allocate_spatial(ndim_analysis,compute_Jinv = True)

            # Temps
            
            UxT = alg.zeros( ( elm_o2.nbasis, 1 ), nip = elm_o2.nip )
            UyT = alg.zeros( ( elm_o2.nbasis, 1 ), nip = elm_o2.nip )
            UT  = alg.zeros( ( elm_o2.nbasis, 1 ), nip = elm_o2.nip )
            
            UxUx = alg.zeros( ( elm_o2.nbasis, elm_o2.nbasis ), nip = elm_o2.nip )
            UyUy = alg.zeros( ( elm_o2.nbasis, elm_o2.nbasis ), nip = elm_o2.nip )

            UU_tmp1 = alg.zeros( ( elm_o2.nbasis, elm_o2.nbasis ), nip = elm_o2.nip )
            
            PT  = alg.zeros( ( elm_o1.nbasis, 1 ), nip = elm_o2.nip )
            PxT = alg.zeros( ( elm_o1.nbasis, 1 ), nip = elm_o2.nip )
            PyT = alg.zeros( ( elm_o1.nbasis, 1 ), nip = elm_o2.nip )
            
            PP = alg.zeros( ( elm_o1.nbasis, elm_o1.nbasis ), nip = elm_o1.nip )
            PP_tmp1 = alg.zeros( ( elm_o1.nbasis, elm_o1.nbasis ), nip = elm_o1.nip )
                        
            UPx = alg.zeros( ( elm_o2.nbasis, elm_o1.nbasis ), nip = elm_o2.nip )
            UPy = alg.zeros( ( elm_o2.nbasis, elm_o1.nbasis ), nip = elm_o2.nip )
            
            
            PUx = alg.zeros( ( elm_o1.nbasis, elm_o2.nbasis ), nip = elm_o2.nip )
            PUy = alg.zeros( ( elm_o1.nbasis, elm_o2.nbasis ), nip = elm_o2.nip )
                        
            tmp11 = alg.zeros( ( elm_o2.nbasis, elm_o2.nbasis ) )
            tmp22 = alg.zeros( ( elm_o2.nbasis, elm_o2.nbasis ) )
            
            tmp13 = alg.zeros( ( elm_o2.nbasis, elm_o1.nbasis ) )
            tmp23 = alg.zeros( ( elm_o2.nbasis, elm_o1.nbasis ) )
            
            tmp31 = alg.zeros( ( elm_o1.nbasis, elm_o2.nbasis ) )
            tmp32 = alg.zeros( ( elm_o1.nbasis, elm_o2.nbasis ) )
            
            tmp33 = alg.zeros( ( elm_o1.nbasis, elm_o1.nbasis ) )

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elm_o2.set_coordinates(Th.x,Th.y,Th.z,elems)
            elm_o2.compute_jacobian()
            
            elm_o1.set_coordinates(Th.x,Th.y,Th.z,elems)
            elm_o1.compute_jacobian()

            Ux = elm_o2.Nx
            Uy = elm_o2.Ny
            U  = elm_o2.N
            
            Px = elm_o1.Nx
            Py = elm_o1.Ny
            P  = elm_o1.N
            
            alg.transpose(U,  out = UT )
            alg.transpose(Ux, out = UxT)
            alg.transpose(Uy, out = UyT)
            
            alg.transpose(P,  out = PT )
            alg.transpose(Px, out = PxT)
            alg.transpose(Py, out = PyT)
            
            alg.dot( UxT, Ux, out = UxUx )
            alg.dot( UyT, Uy, out = UyUy )
            
            alg.dot( PT, P, out = PP )
            
            alg.dot( PT, Ux, out = PUx )
            alg.dot( PT, Uy, out = PUy )
            
            alg.dot( UT, Px, out = UPx )
            alg.dot( UT, Py, out = UPy )
            

            # solve stokes([ux,uy,p],[vx,vy,q]) = 
            #     int2d(Th)( dx(ux)*dx(vx) + dy(ux)*dy(vx)  ) + 
            #     int2d(Th)( dx(uy)*dx(vy) + dy(uy)*dy(vy)  ) + 
            #     int2d(Th)( dx(p)*vx      + dy(p)*vy       ) + 
            #     int2d(Th)( q*dx(ux)      + q*dy(uy)       ) + 
            #     int2d(Th)( (-1e-10)*p*q                   ) + 
            #     on(3,ux =  1) + on(3,uy = 0) +
            #     on(4,ux =  0) + on(4,uy = 0) +
            #     on(1,ux =  0) + on(1,uy = 0) +
            #     on(2,ux =  0) + on(2,uy = 0) ;
            
            
            alg.sum( UxUx, UyUy, out= UU_tmp1 )
            alg.gauss_integrate( UU_tmp1, elm_o2.dV, out = tmp11 ) # vx,ux
            
            alg.gauss_integrate( UU_tmp1, elm_o2.dV, out = tmp22 ) # vy,uy
            
            alg.gauss_integrate( UPx, elm_o2.dV, out = tmp13 ) # 
            alg.gauss_integrate( UPy, elm_o2.dV, out = tmp23 ) # 
            
            alg.gauss_integrate( PUx, elm_o2.dV, out = tmp31 ) # 
            alg.gauss_integrate( PUy, elm_o2.dV, out = tmp32 ) # 
            
            alg.mul( c1, PP, out = PP_tmp1 )
            alg.gauss_integrate( PP_tmp1, elm_o2.dV, out = tmp33 ) # 
            
            # assemble globals
            
            for k in range(elm_o2.nbasis):
        
                ii=int(elems[k])
                
                i1 = ii
                i2 = ii + nnodes_tri6 
                i3 = ii + nnodes_tri6 + nnodes_tri3 
                
                for l in range(elm_o2.nbasis):

                    jj=int(elems[l])
                    
                    j1 = jj
                    j2 = jj + nnodes_tri6 
                    j3 = jj + nnodes_tri6 + nnodes_tri3 
                    
                    K[i1,j1] = K[i1,j1] + tmp11[k,l]                    
                    K[i2,j2] = K[i2,j2] + tmp22[k,l]
                    
                # end for 

            # end for 

            for k in range(elm_o1.nbasis):
        
                ii=int(elems[k])
                
                i1 = ii
                i2 = ii + nnodes_tri6 
                i3 = ii + nnodes_tri6 + nnodes_tri3 
                
                for l in range(elm_o1.nbasis):

                    jj=int(elems[l])
                    
                    j1 = jj
                    j2 = jj + nnodes_tri6 
                    j3 = jj + nnodes_tri6 + nnodes_tri3 
                    
                    K[i1,j3] = K[i1,j3] + tmp13[k,l]
                    K[i2,j3] = K[i2,j3] + tmp23[k,l]
                    
                    K[i3,j1] = K[i3,j1] + tmp31[k,l]
                    K[i3,j2] = K[i3,j2] + tmp32[k,l]
                    
                    K[i3,j3] = K[i3,j3] + tmp33[k,l]

                # end for 

            # end for 
 
 
        # end for

    # end for

    fem.end_elements()   

    end_assmbly_time = time()
    print("\nFinished assembly.\nSetting up boundary condition.")
    
    # Setting Dirichlet BCs using TGV.
    TGV = 1e30
    
    # Every 1D node has dirichlet bc = 0
    els = Th.group_names['top']['members'][0]
    for j in range(els['types'].size):

        elm_nodes = np.unique(els['indices'][j])

        for ii_ in elm_nodes:
            i1 = int(ii_)
            i2 = int(ii_) + nnodes_tri6

            K[i1,i1] = TGV
            f[i1,0]  = utop
            
            K[i2,i2] = TGV
            f[i2,0]  = 0.0
            
        # end for 
                
    # end for
    
    
    # Every 1D node has dirichlet bc = 0
    els = Th.group_names['right']['members'][0]
    for j in range(els['types'].size):

        elm_nodes = np.unique(els['indices'][j])

        for ii_ in elm_nodes:
            i1 = int(ii_)
            i2 = int(ii_) + nnodes_tri6

            K[i1,i1] = TGV
            f[i1,0]  = 0.0
            
            K[i2,i2] = TGV
            f[i2,0]  = 0.0
            
        # end for 
                
    # end for
    
    
    # Every 1D node has dirichlet bc = 0
    els = Th.group_names['left']['members'][0]
    for j in range(els['types'].size):

        elm_nodes = np.unique(els['indices'][j])

        for ii_ in elm_nodes:
            i1 = int(ii_)
            i2 = int(ii_) + nnodes_tri6

            K[i1,i1] = TGV
            f[i1,0]  = 0.0
            
            K[i2,i2] = TGV
            f[i2,0]  = 0.0
            
        # end for 
                
    # end for
    
    
    # Every 1D node has dirichlet bc = 0
    els = Th.group_names['bottom']['members'][0]
    for j in range(els['types'].size):

        elm_nodes = np.unique(els['indices'][j])

        for ii_ in elm_nodes:
            i1 = int(ii_)
            i2 = int(ii_) + nnodes_tri6

            K[i1,i1] = TGV
            f[i1,0]  = 0.0
            
            K[i2,i2] = TGV
            f[i2,0]  = 0.0
            
        # end for 
                
    # end for
    
    
    
    print("\nEnded boundary condition setup.\nStarting system solution.")
    
    u = 0
    K = K.tocsr()#(preserve_in=False)
    
    print("\nConverted matrix to csr format. - Starting solution process.")
    
    u = alg.solve(K,f,solver=solver)
    
    print("\nSolved problem.")
    
    end_solve_time = time()
    
    if stats:
        times['assembly'].append(  end_assmbly_time - start_time       )
        times['bc'].append( end_bc_time      - end_assmbly_time  )
        times['solve'].append(  end_solve_time   - end_bc_time      )
        times['total'].append( end_solve_time   - start_time        )
        
#         print("Assembly time:  {0:.6f} s ".format( end_assmbly_time - start_time       ) )
#         print("Boundary time:  {0:.6f} s ".format( end_bc_time      - end_assmbly_time ) )
#         print("Solution time:  {0:.6f} s ".format( end_solve_time   - end_bc_time      ) )
        print("Total run time: {0:.6f} s ".format( end_solve_time   - start_time       ) )
        print()
    # end if 

    return u,K,f

    #-----------------------------------------------------------------------------------------------------



# fem.set_global_algebra(r)
fem.set_global_algebra(oti)
# fem.set_global_algebra(dual)
alg = fem.get_global_algebra()

start_time = time()

hx = 1
hy = 1

Th = fem.square(hx,hy,he=0.01,element_order=2,quads=False,save=False, structured=True)

end_time = time()

print(end_time - start_time,"seg")

# move the mesh
Th.x += hx/2
Th.y += hy/2

order = 2
utop = alg.number(1)#+alg.e(2, order = order)
solver = 'umfpack'

times = {}
times['assembly'] = []
times['bc'] = []
times['solve'] = []
times['total'] = []



for i in range(1):
    u_res,K,f = solve_2d_cavity(Th, utop, solver=solver)
#end for

print('\n\nTimes:'+str(type(u_res)))
print("- Avg Assembly time:  {0:.6f} s ".format(np.average(times['assembly'] ) ) )
print("- Avg Boundary time:  {0:.6f} s ".format(np.average(times['bc'])      ) )
print("- Avg Solution time:  {0:.6f} s ".format(np.average(times['solve'])   ) )
print("- Avg Total run time: {0:.6f} s ".format(np.average(times['total'])   ) )