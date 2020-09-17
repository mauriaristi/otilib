import sys
path2oti = '../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

import pyoti.real   as r
import pyoti.sparse as oti 
import pyoti.fem    as fem

np = fem.np

def solve_2d_axisymmetric_heat_conduction(Th, Bii, Bio, s, stats=True, solver = 'SuperLU'):
    
    global times
    from timeit import default_timer as time
    
    print("Setting up problem")
    
    start_time = time()
    
    
    ndim_analysis = 2
    
    els = Th.elements[2]

    fem.end_elements()
    
    nNodes = Th.nnodes
    nDOF = nNodes
    
    K = alg.lil_matrix((nDOF,nDOF))
    f = alg.zeros((nDOF,1))
    
    print("\nStarting elemental computations.")
    
    #  INT 2D
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=2)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = True)

            fh = alg.zeros( ( elem.nbasis, 1 ) )
            r    = alg.zero(    nip = elem.nip   )
            rneg = alg.zero(    nip = elem.nip   )
            
            # Temps
            NT  = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            NxT = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            NyT = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            
            NxNx = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NyNy = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )

            NN_tmp1 = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NN_tmp2 = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NN_tmp3 = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            
            N_tmp1 = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            N_tmp2 = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            N_tmp3 = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            
            tmp_Ke = alg.zeros( ( elem.nbasis, elem.nbasis ) )
            tmp_fe = alg.zeros( ( elem.nbasis,       1     ) )

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elem.set_coordinates(Th.x,Th.y,Th.z,elems)
            elem.compute_jacobian()
            
            Nx = elem.Nx
            Ny = elem.Ny
            N  = elem.N
            x  = elem.x # Extract x-coordinates.
            
            alg.transpose(Nx, out = NxT)
            alg.transpose(Ny, out = NyT)
            alg.transpose( N, out = NT )
            
            alg.dot( NxT, Nx, out = NxNx )
            alg.dot( NyT, Ny, out = NyNy )
            
            alg.dot_product( x, NT, out = r ) 
            
            alg.neg( r , out = rneg)

            
            # problem heat(Theta,w)=
            #    -int2d(Th)(    x * dx(Theta) * dx(w) ) // -- Goes in K
            #    -int2d(Th)(    x * dy(Theta) * dy(w) ) // -- Goes in K
            #    +int2d(Th)(    x * Q * w             ) // -- RHS only
            #
            #    -int1d(Th,4)(  x * w * Bi1 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  x * w * Bi2 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  x * w * Bi2           );// -- RHS only
                      
            alg.mul(    rneg,    NxNx, out = NN_tmp1 )
            alg.mul(    rneg,    NyNy, out = NN_tmp2 )
            alg.sum( NN_tmp1, NN_tmp2, out = NN_tmp3 )
            alg.gauss_integrate( NN_tmp3, elem.dV, out = tmp_Ke )
            
            alg.mul( rneg, NT    , out = N_tmp1 )
            alg.mul(    s, N_tmp1, out = N_tmp2 )
            alg.gauss_integrate( N_tmp2, elem.dV, out = tmp_fe )
            
          
            # assemble globals            
            for k in range(elems.size):
        
                ii=int(elems[k])
            
                f[ii,0] = f[ii,0] + tmp_fe[k,0]
                
                for l in range(elems.size):

                    jj=int(elems[l])
            
                    K[ii,jj] = K[ii,jj] + tmp_Ke[k,l]

                # end for 

            # end for 
 
        # end for

    # end for

    fem.end_elements()   

    end_assmbly_time = time()
    print("\nFinished assembly.\nSetting up boundary condition.")
    
    # 
    els = Th.group_names['left']['members'][0]
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=6)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = False)
         

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elem.set_coordinates(Th.x,Th.y,Th.z,elems)
            elem.compute_jacobian()
            
            # print(elem.N)

            N  = alg.transpose(elem.N)
            # print(elem.x)
            r  = alg.dot_product( elem.x, N ) 
            # print(r)
            NN = alg.dot(N,elem.N)
            # print(NN)
            #    -int1d(Th,4)(  x * w * Bi1 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  x * w * Bi2 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  x * w * Bi2           );// -- RHS only
            
            tmp_Ke = -alg.gauss_integrate( (Bii)*r*NN, elem.dV)
            # tmp_fe = alg.gauss_integrate( (Bii)*r*N, elem.dV)
            
            # assemble globals            
            for k in range(elems.size):
        
                ii=int(elems[k])
            
                # f[ii,0] = f[ii,0] + tmp_fe[k,0]
                
                for l in range(elems.size):

                    jj=int(elems[l])
            
                    K[ii,jj] = K[ii,jj] + tmp_Ke[k,l]

                # end for 

            # end for 
 
        # end for

    # end for

    fem.end_elements()  
    
    els = Th.group_names['right']['members'][0]
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=2)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = False)

            fh = alg.zeros( ( elem.nbasis, 1 ) )

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elem.set_coordinates(Th.x,Th.y,Th.z,elems)
            elem.compute_jacobian()
            
            N  = alg.transpose(elem.N)
            r  = alg.dot_product( elem.x, N ) 
            
            NN = alg.dot(N,elem.N)
            
            #    -int1d(Th,4)(  x * w * Bi1 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  x * w * Bi2 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  x * w * Bi2           );// -- RHS only
            
            tmp_Ke = -alg.gauss_integrate( (Bio)*r*NN, elem.dV)
            tmp_fe =  alg.gauss_integrate( (Bio)*r*N , elem.dV)
            
            # assemble globals            
            for k in range(elems.size):
        
                ii=int(elems[k])
            
                f[ii,0] = f[ii,0] + tmp_fe[k,0]
                
                for l in range(elems.size):

                    jj=int(elems[l])
            
                    K[ii,jj] = K[ii,jj] + tmp_Ke[k,l]

                # end for 

            # end for 
 
        # end for

    # end for

    fem.end_elements()
    
    end_bc_time = time()
    
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


fem.set_global_algebra(oti)
alg = fem.get_global_algebra()

Th = fem.square(0.5,2,he=0.01,element_order=2,quads=False,save=False, structured=True)


Th.x = Th.x + 1.25 



Bii = alg.number(0.1)#+alg.e(2, order = order)
Bio = alg.number(1.0)#+alg.e(1, order = order)
s   = alg.number(5.0)

solver = 'SuperLU'



times = {}
times['assembly'] = []
times['bc'] = []
times['solve'] = []
times['total'] = []



for i in range(1):
    u_res,K,f = solve_2d_axisymmetric_heat_conduction(Th,Bii,Bio,s,solver=solver)
#end for
print(u_res.real)
print('\n\nTimes:'+str(type(u_res)))
print("- Avg Assembly time:  {0:.6f} s ".format(np.average(times['assembly'] ) ) )
print("- Avg Boundary time:  {0:.6f} s ".format(np.average(times['bc'])      ) )
print("- Avg Solution time:  {0:.6f} s ".format(np.average(times['solve'])   ) )
print("- Avg Total run time: {0:.6f} s ".format(np.average(times['total'])   ) )