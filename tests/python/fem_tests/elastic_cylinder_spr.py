import psutil

mem_before_load = psutil.virtual_memory()

import sys
path2oti = '../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

# import pyoti.real   as r
# import pyoti.sparse as oti 
# import pyoti.core   as coti
import pyoti.fem    as fem 

np = fem.np

from timeit import default_timer as time

mem_after_load = psutil.virtual_memory()


def cylinder(ri, ro, he = 1.0, element_order = 1, quads = False, 
           quad_incomplete = 1, quad_linear = 1, structured = False, save=False):
    """
    PORPUSE: Define a cylinder section mesh.
    """
    #***************************************************************************************************
    import gmsh

    gmsh.initialize()
    # gmsh.fltk.initialize()

    # Lets create a simple square element:
    model = gmsh.model
    geo   = model.geo
    option= gmsh.option

    P1 = geo.addPoint( 0.0, 0.0, 0.0, he, 1)
    P2 = geo.addPoint( 0.0,  ri, 0.0, he, 2)
    P3 = geo.addPoint(  ri, 0.0, 0.0, he, 3)
    P4 = geo.addPoint( 0.0,  ro, 0.0, he, 4)
    P5 = geo.addPoint(  ro, 0.0, 0.0, he, 5)

    C1 = geo.addCircleArc(P2,P1,P3)
    C2 = geo.addCircleArc(P5,P1,P4)
    
    geo.remove([P1])
    
    L1 = geo.addLine(P4,P2) # Left
    L2 = geo.addLine(P3,P5) # bottom

    loop1 = geo.addCurveLoop([C1,L2,C2,L1])

    surface = geo.addPlaneSurface([loop1])

    model.addPhysicalGroup( 0, [P1],        100 )
    model.addPhysicalGroup( 0, [P2],        101 )
    model.addPhysicalGroup( 0, [P3],        102 )
    model.addPhysicalGroup( 0, [P4],        103 )
    model.addPhysicalGroup( 0, [P5],        104 )

    model.addPhysicalGroup( 1, [C1],        201 )
    model.addPhysicalGroup( 1, [C2],        202 )
    model.addPhysicalGroup( 1, [L1],        203 )
    model.addPhysicalGroup( 1, [L2],        204 )

    model.addPhysicalGroup( 2, [surface],   301 )
    
    model.setPhysicalName( 0, 100, "center"  )
    model.setPhysicalName( 0, 101, "ri_left"  )
    model.setPhysicalName( 0, 102, "ri_right" )
    model.setPhysicalName( 0, 103, "ro_left"  )
    model.setPhysicalName( 0, 104, "ro_right" )

    model.setPhysicalName( 1, 201, "ri"    )
    model.setPhysicalName( 1, 202, "ro"    )
    model.setPhysicalName( 1, 203, "left"  )
    model.setPhysicalName( 1, 204, "right" )

    model.setPhysicalName( 2, 301, "domain"      )

    
    geo.synchronize()

    option.setNumber('Mesh.ElementOrder',element_order)


    # Recombine if quads are wanted.
    if quads:

        # Set body to recombine into quads.
        option.setNumber('Mesh.SecondOrderIncomplete',quad_incomplete)
        option.setNumber('Mesh.SecondOrderLinear',    quad_linear    )
        option.setNumber('Mesh.RecombineAll',         1)

    else:

        option.setNumber('Mesh.SecondOrderIncomplete',quad_incomplete)
        option.setNumber('Mesh.SecondOrderLinear',    quad_linear    )
        option.setNumber('Mesh.RecombineAll',         0)

    # end if 

    if structured:
        nels_L = int((ro-ri)/he)+1
        nels_C = int((ri*np.pi*2)/(4*he))+1
        model.mesh.setTransfiniteCurve(L1,nels_L)
        model.mesh.setTransfiniteCurve(L2,nels_L)
        model.mesh.setTransfiniteCurve(C1,nels_C)
        model.mesh.setTransfiniteCurve(C2,nels_C)
        model.mesh.setTransfiniteSurface(surface)#,"left",[P2,P3,P4])
    # end if 

    model.mesh.generate(2)

    if save:
        gmsh.write("cylinder.msh")
    # end if 

    Th = fem.mesh.from_gmsh(gmsh)
#     Th = None

    gmsh.finalize()

    return Th

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
def solve_2d_linear_elasticity(Th, E, nu, ri, Pi, ro, Po, stats=True, times = None, solver='cholesky'):
    
    from timeit import default_timer as time
    
    mem_bf_creation = psutil.virtual_memory().used

    start_time = time()
    
    alg = fem.get_global_algebra()

    mu = E/(2*(1+nu))
    
    c1 = E*nu/((1+nu)*(1-2*nu))
    c2 = 2*mu
    c3 = mu
    c4 = c1+c2
    
    ndim_analysis = 2
    els = Th.elements[2]

    fem.end_elements()
    
    nNodes = Th.x.shape[0]
    nDOF = 2*nNodes
    
    K = alg.lil_matrix((nDOF,nDOF))
    f = alg.zeros((nDOF,1))
    
    K[nNodes,nNodes] = 1.0 # Removes "center" node.
    K[0,0] = 1.0 # Removes "center" node.
    
    mem_aft_creation = psutil.virtual_memory().used
    # 
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=2)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = True)
            # print(elem)
            fh = alg.zeros( ( elem.nbasis, 1 ) )
            
            # Temps
            
            NxT = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            NyT = alg.zeros( ( elem.nbasis, 1 ), nip = elem.nip )
            
            NxNx = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NxNy = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NyNx = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NyNy = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )

            NN_tmp1 = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NN_tmp2 = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            NN_tmp3 = alg.zeros( ( elem.nbasis, elem.nbasis ), nip = elem.nip )
            
            tmp11 = alg.zeros( ( elem.nbasis, elem.nbasis ) )
            tmp12 = alg.zeros( ( elem.nbasis, elem.nbasis ) )
            tmp21 = alg.zeros( ( elem.nbasis, elem.nbasis ) )
            tmp22 = alg.zeros( ( elem.nbasis, elem.nbasis ) )

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elem.set_coordinates(Th.x,Th.y,Th.z,elems)
            elem.compute_jacobian()

            Nx = elem.Nx
            Ny = elem.Ny
            N  = elem.N
            
            alg.transpose(Nx, out = NxT)
            alg.transpose(Ny, out = NyT)
            
            alg.dot( NxT, Nx, out = NxNx )
            alg.dot( NyT, Ny, out = NyNy )
            alg.dot( NyT, Nx, out = NyNx )
            alg.dot( NxT, Ny, out = NxNy )

           
            # alg.gauss_integrate( c4*NxNx + c3*NyNy , elem.dV,out=tmp11) # vx,ux            
            alg.mul(      c4,    NxNx, out=NN_tmp1 )
            alg.mul(      c3,    NyNy, out=NN_tmp2 )
            alg.sum( NN_tmp1, NN_tmp2, out=NN_tmp3 )
            alg.gauss_integrate( NN_tmp3, elem.dV, out = tmp11 ) # vx,ux
            
            # alg.gauss_integrate( c1*NxNy + c3*NyNx , elem.dV,out=tmp12) # vx,uy
            alg.mul(      c1,    NxNy, out=NN_tmp1 )
            alg.mul(      c3,    NyNx, out=NN_tmp2 )
            alg.sum( NN_tmp1, NN_tmp2, out=NN_tmp3 )
            alg.gauss_integrate( NN_tmp3, elem.dV, out = tmp12 ) # vx,uy
            
            # alg.gauss_integrate( c1*NyNx + c3*NxNy , elem.dV,out=tmp21) # vy,ux
            alg.mul(      c1,    NyNx, out=NN_tmp1 )
            alg.mul(      c3,    NxNy, out=NN_tmp2 )
            alg.sum( NN_tmp1, NN_tmp2, out=NN_tmp3 )
            alg.gauss_integrate( NN_tmp3, elem.dV, out = tmp21 ) # vy,ux
            
            # alg.gauss_integrate( c4*NyNy + c3*NxNx , elem.dV,out=tmp22) # vy,uy
            alg.mul(      c4,    NyNy, out=NN_tmp1 )
            alg.mul(      c3,    NxNx, out=NN_tmp2 )
            alg.sum( NN_tmp1, NN_tmp2, out=NN_tmp3 )
            alg.gauss_integrate( NN_tmp3, elem.dV, out = tmp22 ) # vy,uy
            

                      
            # assemble globals
            
            for k in range(elems.size):
        
                ii=int(elems[k])
                
                i1 = ii
                i2 = ii + nNodes # Move DOF for second variable
                
                for l in range(elems.size):

                    jj=int(elems[l])
                    
                    j1 = jj
                    j2 = jj + nNodes # Move DOF for second variable
                    
                    K[i1,j1] = K[i1,j1] + tmp11[k,l]
                    
                    K[i1,j2] = K[i1,j2] + tmp12[k,l]
                    
                    K[i2,j1] = K[i2,j1] + tmp21[k,l]
                    
                    K[i2,j2] = K[i2,j2] + tmp22[k,l]

                # end for 

            # end for 
 
        # end for

    # end for
    # Free all Temporals
    del(fh)    
    del(NxT)
    del(NyT)
    del(NxNx)
    del(NxNy)
    del(NyNx)
    del(NyNy)
    del(NN_tmp1)
    del(NN_tmp2)
    del(NN_tmp3)
    del(tmp11)
    del(tmp12)
    del(tmp21)
    del(tmp22)

    fem.end_elements() 

    mem_aft_assembly = psutil.virtual_memory().used

    end_assmbly_time = time()
    

    
    # 
    els = Th.group_names['ri']['members'][0]
    for j in range(els['types'].size):

        elem = fem.element[ els['types'][j] ]

        if not elem.is_allocated():

            elem.end()
            elem.allocate(intorder=2)
            elem.allocate_spatial(ndim_analysis,compute_Jinv = False)

            nxel = alg.zeros( ( elem.nbasis, 1 ) )
            xel  = alg.zeros( ( elem.nbasis, 1 ) )
            nyel = alg.zeros( ( elem.nbasis, 1 ) )
            yel  = alg.zeros( ( elem.nbasis, 1 ) )
            

        # end if 

        elm_nodes = els['indices'][j]

        for i in range(elm_nodes.shape[0]):
            
            elems = elm_nodes[i,:]
            
            elem.set_coordinates(Th.x,Th.y,Th.z,elems)
            elem.compute_jacobian()
            
            N  = alg.transpose(elem.N)  
            
            for k in range(elems.size):
                xel[k,0] = Th.x[int(elems[k]),0]
                yel[k,0] = Th.y[int(elems[k]),0]
            # end for 
            
            nxel = xel/ri
            nyel = yel/ri
            
            
            tmp1 = alg.gauss_integrate( (Pi)*alg.dot_product(nxel,N)*N, elem.dV) # vx,ux
            tmp2 = alg.gauss_integrate( (Pi)*alg.dot_product(nyel,N)*N, elem.dV) # vy,ux
            
            # assemble globals            
            for k in range(elems.size):
        
                ii=int(elems[k])

                i1 = ii
                i2 = ii + nNodes
                
                f[i1,0] = f[i1,0] + tmp1[k,0]
                f[i2,0] = f[i2,0] + tmp2[k,0]

                # end for 

            # end for 
 
        # end for

    # end for

    fem.end_elements()  
    
    els = Th.group_names['ro']['members'][0]
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
            
            for k in range(elems.size):
                xel[k,0] = Th.x[int(elems[k]),0]
                yel[k,0] = Th.y[int(elems[k]),0]
            # end for 
            
            nxel = xel/ro
            nyel = yel/ro
            
            
            tmp1 = alg.gauss_integrate( (-Po)*alg.dot_product(nxel,N)*N, elem.dV) # vx,ux
            tmp2 = alg.gauss_integrate( (-Po)*alg.dot_product(nyel,N)*N, elem.dV) # vy,ux
            

            # assemble globals            
            for k in range(elems.size):
        
                ii=int(elems[k])

                i1 = ii
                i2 = ii + nNodes
                
                f[i1,0] = f[i1,0] + tmp1[k,0]
                f[i2,0] = f[i2,0] + tmp2[k,0]

                # end for 

            # end for 
 
        # end for

    # end for

    fem.end_elements()
    
    # Setting Dirichlet BCs using TGV.
    TGV = 1e30
    
    # Every 1D node has dirichlet bc = 0
    els = Th.group_names['right']['members'][0]
    for j in range(els['types'].size):

        elm_nodes = np.unique(els['indices'][j])

        for ii_ in elm_nodes:

            i1 = int(ii_) # uy
            i2 = int(ii_)+nNodes # uy

            K[i2,i2] = TGV
            f[i2,0] = 0.0
        
        # end for 
        
        
    # end for
    
    els = Th.group_names['left']['members'][0]
    for j in range(els['types'].size):

        elm_nodes = np.unique(els['indices'][j])

        for ii_ in elm_nodes:
            ii = int(ii_) # ux
            K[ii,ii] = TGV
            # end for
            f[ii,0] = 0.0
        # end for 
        
    # end for
    mem_aft_bc = psutil.virtual_memory().used
    
    end_bc_time = time()
    
    K = K.tocsr()

    mem_aft_tocsr = psutil.virtual_memory().used 

    # u = alg.solve( K, f, solver=solver)

    # mem_aft_solve = psutil.virtual_memory().used
    # end_solve_time = time()
    
    times['mem_bf_cholesky'].append( psutil.virtual_memory().used )
    start_cholesky_time = time()
    u = alg.solve( K, f, solver='cholesky')
    end_cholesky_time = time()
    times['mem_aft_cholesky'].append( psutil.virtual_memory().used )

    del(u)

    times['mem_bf_superlu'].append( psutil.virtual_memory().used )
    start_superlu_time = time()
    u = alg.solve( K, f, solver='SuperLU' )
    end_superlu_time = time()
    times['mem_aft_superlu'].append( psutil.virtual_memory().used )

    
    del(u)


    times['mem_bf_umfpack'].append( psutil.virtual_memory().used )
    start_umfpack_time = time()
    u = alg.solve( K, f, solver='umfpack' )
    end_umfpack_time = time()
    times['mem_aft_umfpack'].append( psutil.virtual_memory().used )

    


    mem_aft_solve = psutil.virtual_memory().used
    end_solve_time = time()
    
    if stats:
        times['mem_bf_creation'].append(  mem_bf_creation  )
        times['mem_aft_creation'].append( mem_aft_creation )
        times['mem_aft_assembly'].append( mem_aft_assembly )
        times['mem_aft_bc'].append(       mem_aft_bc       )
        # times['mem_aft_solve'].append(    mem_aft_solve    )
        times['assembly'].append(  end_assmbly_time - start_time       )
        times['boundary'].append(  end_bc_time      - end_assmbly_time )
        # times['solution'].append(  end_solve_time   - end_bc_time      )
        times['sol_cholesky'].append(  end_cholesky_time- start_cholesky_time )
        times['sol_superlu'].append(   end_superlu_time - start_superlu_time  )
        times['sol_umfpack'].append(   end_umfpack_time - start_umfpack_time  )
    # end if 

    return u,K,f

#-----------------------------------------------------------------------------------------------------