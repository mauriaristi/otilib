import sys, getopt
from elastic_cylinder import *
from utils import *

#=====================================================================================================
#============  SETUP  ================================================================================
#=====================================================================================================

algebras = {}

algebras['real'] = r
algebras['mdual']=[
            [om0n0],
            [dual], 
            [md2], 
            [md3], 
            [md4], 
            [md5]]
algebras['oti']=[
            [om0n0,],
            [dual,om1n2,om1n3,om1n4,om1n5,om1n6,om1n7,om1n8,om1n9,om1n10], 
            [om2n1,om2n2,om2n3,om2n4,om2n5,om2n6,om2n7,om2n8,om2n9,om2n10,], 
            [om3n1,om3n2,om3n3,om3n4,om3n5,], 
            [om4n1,om4n2,om4n3,om4n4,om4n5,], 
            [om5n1,om5n2,om5n3,om5n4,om5n5]]

# solvers = ['cholesky','umfpack']
solver = 'umfpack'

hes = [0.01,]
for i in range(10):
    # hes.append(hes[-1]*0.66)
    hes.append(hes[-1]*0.84)
# end for

hes[-1]=0.00177

# Defaults

setup = {}
setup['h']      = 0
setup['order']  = 0
setup['nbases'] = 0
setup['ismdual']= False
setup['isreal'] = False
setup['export'] = 'results_real'
setup['nevals'] = 3
setup['solver'] = 'umfpack'

times_algebras = {}

#=====================================================================================================
#============  SETUP  ================================================================================
#=====================================================================================================





#*****************************************************************************************************
def run_analysis():

    hi     = setup['h']      
    order  = setup['order']  
    nbases = setup['nbases'] 
    ismdual= setup['ismdual']
    isreal = setup['isreal'] 
    export = setup['export'] 
    nevals = setup['nevals'] 
    solver = setup['solver'] 

    he = hes[hi]

    times_algebras[he] = {}
    
    algebra = None

    if isreal:
        algebra = algebras['real']
    elif ismdual:
        algebra = algebras['mdual'][order]
    else:
        algebra = algebras['oti'][order][nbases-1]
    # end if 

    alg_key = algebra.__name__.split(".")[-1]
        
    times_algebras[he][alg_key] = {}
    times = times_algebras[he][alg_key]
    
    print("")
    print("Analyzing algebra {0} he {1}".format(alg_key,he))
    print("")
    print("==================================================")
    print("")

    times['mesh']     = []
    times['assembly'] = []
    times['boundary'] = []
    times['solution'] = []
    times['mem_bf_mesh']      = []
    times['mem_aft_mesh']     = []
    times['mem_bf_creation']  = []
    times['mem_aft_creation'] = []
    times['mem_aft_assembly'] = []
    times['mem_aft_bc']       = []
    times['mem_aft_solve']    = []
    times['mem_aft_solve2d']  = []
    times['mem_aft_del_K']    = []

    export_dir = 'results/'
    filename = export_dir + export+"_"+solver+"_"+str(hi)+".json"

    for i in range(nevals):

        fem.set_global_algebra(algebra)
        alg = fem.get_global_algebra()
        
        times['mem_bf_mesh'].append( psutil.virtual_memory() )

        start_time = time()
        Th = cylinder( 1, 2, he=he, quads=False, save=False, structured=True )
        end_time = time()

        times['mem_aft_mesh'].append( psutil.virtual_memory() )

        times_algebras[he]['mesh_DOFs'] = Th.nnodes
        times_algebras[he]['meshstats'] = repr(Th)

        print("")
        print(" - Run {0} out of {1} for {2} DOFs.".format(i+1,nevals,2*Th.nnodes))
        
        times['mesh'].append( end_time  - start_time )

        E  = alg.number(21e5)#+alg.e(1,order=1)#,order=1)#,1,10,2,1000
        nu = alg.number(0.28)#+alg.e(2,order=10)
        ri = alg.number(1)
        Pi = alg.number(10)  #+alg.e(3,order=1)# Pi = alg.number(1400)
        ro = alg.number(2)
        Po = alg.number(1000)#+alg.e(4,order=1)

        u_res,K,f = solve_2d_linear_elasticity(Th,E,nu,ri,Pi,ro,Po,times=times, solver = solver)


        times['mem_aft_solve2d'].append( psutil.virtual_memory() )
        
        times_algebras[he]['K_nnz']   = K.nnz
        times_algebras[he]['K_shape'] = K.shape[0]

        report_times_in_file(times_algebras, filename=filename)
        del(u_res)
        del(K)
        del(f)

        times['mem_aft_del_K'].append( psutil.virtual_memory() )
        

    # end for
    
    

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def main(argv):
    
    opts, args = getopt.getopt(argv,"m:n:rh:",["order=","nbases=","real","mdual","export=","solver=","nevals="])
    
    for opt, arg in opts:
    
        if opt in ("-m", "--nbases"):
            setup['nbases'] = int(arg)
        elif opt in ("-h"):
            setup['h'] = int(arg)
        elif opt in ("-n", "--order"):
            setup['order'] = int(arg)
        elif opt in ("-r", "--real"):
            setup['isreal'] = True 
        elif opt in ("--mdual",):
            setup['ismdual'] = True 
        elif opt in ["--export",]:
            setup['export'] = arg
        elif opt in ["--solver",]:
            setup['solver'] = arg
        elif opt in ["--nevals",]:
            setup['nevals'] = arg
        # end if 

    # end for 
    
    print(" --- SETUP --- ")
    for key in setup.keys():
        print("   {0:10}: {1}".format( key, setup[key] ) )
    #end for 
    print(" --- SETUP --- ")

    run_analysis()

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
if __name__ == '__main__':
    main(sys.argv[1:])
# end if 
#-----------------------------------------------------------------------------------------------------
