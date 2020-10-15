import sys
path2oti = '../../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

import pyoti.real   as r
import pyoti.sparse as oti 
import pyoti.core   as coti
import pyoti.fem    as fem 

np = oti.np
































#*****************************************************************************************************
def solve_2d_axisymmetric_heat_conduction(Th, Bii, Bio, s, stats=True, solver = 'SuperLU', times = None, verb=1):
    
    
    from timeit import default_timer as time

    alg = fem.get_global_algebra()
    
    if verb!=0:
        print("Setting up problem")
    
    start_time = time()
    
    
    ndim_analysis = 2
    
    els = Th.elements[2]

    fem.end_elements()
    
    nNodes = Th.nnodes
    nDOF = nNodes
    
    K = alg.lil_matrix((nDOF,nDOF))
    f = alg.zeros((nDOF,1))
    
    if verb!=0:
        print("\nStarting elemental computations.")
    
    #  INT 2D
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=8)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = True)

            fh = alg.zeros( ( elem.nbasis, 1 ) )
            r    = alg.zero(    nip = elem.nip   )
            rneg = alg.zero(    nip = elem.nip   )
            rinv = alg.zero(    nip = elem.nip   )
            
            # Temps
            NT  = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            NxT = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            NyT = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            
            NxNx = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NyNy = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NNx  = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )

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
            
            alg.div( 1.0, r , out = rinv)
            
            # problem heat(Theta,w)=
            #    -int2d(Th)(    dx(Theta) * dx(w) ) // -- Goes in K
            #    -int2d(Th)(    dy(Theta) * dy(w) ) // -- Goes in K
            #    +int2d(Th)(    dx(Theta) * w / x ) // -- Goes in K            
            #    +int2d(Th)(    Q * w             ) // -- RHS only
            #
            #    -int1d(Th,4)(  w * Bi1 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  w * Bi2 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  w * Bi2           );// -- RHS only
                      
            alg.sum( NxNx, NyNy, out = NN_tmp1 )
            alg.neg(    NN_tmp1, out = NN_tmp2 )
            
            alg.mul( rinv, NT, out =  N_tmp1 )
            alg.dot(  N_tmp1, Nx, out = NNx )
            alg.sum( NNx, NN_tmp2, out = NN_tmp3)
            
            alg.gauss_integrate( NN_tmp3, elem.dV, out = tmp_Ke )
            
            
            alg.mul(    s,    NT, out = N_tmp1 )
            alg.neg(    N_tmp1, out = N_tmp2 )
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
    
    if verb!=0:
        print("\nFinished assembly.\nSetting up boundary condition.")
    
    # 
    els = Th.group_names['left']['members'][0]
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=8)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = False)
         
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
            
            tmp_Ke = -alg.gauss_integrate( (Bii)*NN, elem.dV)
            # tmp_fe = alg.gauss_integrate( (Bii)*N, elem.dV)
            
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
            elem.allocate(intorder=8)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = False)

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elem.set_coordinates(Th.x,Th.y,Th.z,elems)
            elem.compute_jacobian()
            
            N  = alg.transpose(elem.N)
            r  = alg.dot_product( elem.x, N ) 
            
            NN = alg.dot(N,elem.N)
            
            #    -int1d(Th,4)(  w * Bi1 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  w * Bi2 * Theta   ) // -- Goes in K
            #    -int1d(Th,2)(  w * Bi2           );// -- RHS only
            
            tmp_Ke = -alg.gauss_integrate( (Bio)*NN, elem.dV)
            tmp_fe =  alg.gauss_integrate( (Bio)*N , elem.dV)
            
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
    
    if verb!=0:
        print("\nEnded boundary condition setup.\nStarting system solution.")
    
    u = 0
    K = K.tocsr()#(preserve_in=False)
    
    if verb!=0:
        print("\nConverted matrix to csr format. - Starting solution process.")
    
    u = alg.solve(K,f,solver=solver)
    
    if verb!=0:
        print("\nSolved problem.")
    
    end_solve_time = time()
    
    if stats and (time is not None):
        times['assembly'].append(  end_assmbly_time - start_time       )
        times['bc'].append( end_bc_time      - end_assmbly_time  )
        times['solve'].append(  end_solve_time   - end_bc_time      )
        times['total'].append( end_solve_time   - start_time        )

        if verb!=0:
            print("Total run time: {0:.6f} s ".format( end_solve_time   - start_time       ) )
            print()
    # end if 

    return u,K,f

#-----------------------------------------------------------------------------------------------------





def analytic_solution_r( r, Bii, Bio, s, ri, ro, log = alg.log):
    
    #real K1 = ( 2.0 * Bi2 * Q - Bi1 * Bi2 * Q + 2.0 * Bi1 * Q * rho - 4.0*Bi1*Bi2 + Bi1*Bi2*Q*rho^2);
    #
    #real KDiv = (Bi1*Bi2*rho*log(rho)+Bi1+Bi2*rho);
    #
    #real K2 = (2.0*Q*rho^2-4.0*Bi2*rho+Bi2*Q*rho^3-2.0*Bi2*Q*rho*log(rho)+
    #           Bi1*Bi2*Q*rho*log(rho)-2.0*Q+Bi1*Q);

    # ThetaAnalytic = -0.25*Q*x^2 + 0.25*rho*log(x)*K1/KDiv + 0.25*K2/KDiv;
    
    
    rho = ro/ri
    
    K1 = ( 2.0 * Bio * s - Bii * Bio * s + 2.0 * Bii * s * rho - 4.0 * Bii * Bio + Bii * Bio * s * rho**2)
    
    KDiv = ( Bii * Bio * rho * log(rho) + Bii + Bio * rho )
    
    K2 = ( 2.0 * s * rho**2 - 4.0 * Bio * rho + Bio * s * rho**3 - 2.0 * Bio * s * rho * log(rho) +
           Bii * Bio * s * rho * log(rho) - 2.0 * s + Bii * s )


    Theta = - 0.25 * s * r**2 + 0.25 * rho * log(r) * K1 / KDiv + 0.25 * K2 / KDiv
    
    return Theta
#-----------------------------------------------------------------------------------------------------