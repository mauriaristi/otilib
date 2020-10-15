import sys, getopt
from elastic_cylinder import *
from utils import *
import gc

import sys
path2oti = '../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

import pyoti.real   as r
import pyoti.sparse as oti 
import pyoti.core   as coti

e  = oti.e
np = oti.np






#=====================================================================================================
#============  SETUP  ================================================================================
#=====================================================================================================


# solvers = ['cholesky','umfpack']
solver = 'SuperLU'

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
setup['export'] = 'results_spr_real'
setup['nevals'] = 3
setup['elorder'] = 1
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
    elorder = setup['elorder']

    he = hes[hi] * elorder

    times_algebras[he] = {}
    
    algebra = oti

    
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
    # times['solution'] = []
    times['sol_cholesky'] = []
    times['sol_superlu']  = []
    times['sol_umfpack']  = []
    times['mem_bf_mesh']      = []
    times['mem_aft_mesh']     = []
    times['mem_bf_creation']  = []
    times['mem_aft_creation'] = []
    times['mem_aft_assembly'] = []
    times['mem_aft_bc']       = []
    times['mem_bf_cholesky']  = []
    times['mem_aft_cholesky'] = []
    times['mem_bf_superlu']   = []
    times['mem_aft_superlu']  = []
    times['mem_bf_umfpack']   = []
    times['mem_aft_umfpack']  = []
    # times['mem_aft_solve']    = []
    times['mem_aft_solve2d']  = []
    times['mem_aft_del_K']    = []

    export_dir = 'results/'
    # filename = export_dir + export+"_"+solver+"_"+str(hi)+".json"
    filename = export_dir + export+"_"+str(hi)+".json"

    for i in range(nevals):

        fem.set_global_algebra(algebra)
        alg = fem.get_global_algebra()
        
        times['mem_bf_mesh'].append( psutil.virtual_memory().used )

        start_time = time()
        Th = cylinder( 1, 2, he=he, quads=False, element_order=elorder, save=False, structured=True )
        if ismdual:
            if nbases > 0:
                for kkk in range(1,nbases+1):
                    Th.x += Th.x*algebra.e(kkk,order=order)
                    Th.y -= Th.y*algebra.e(kkk,order=order)
        end_time = time()

        times['mem_aft_mesh'].append( psutil.virtual_memory().used )

        times_algebras[he]['mesh_DOFs'] = Th.nnodes
        times_algebras[he]['meshstats'] = repr(Th)

        print("")
        print(" - Run {0} out of {1} for {2} DOFs.".format(i+1,nevals,2*Th.nnodes))
        
        times['mesh'].append( end_time  - start_time )
        E  = alg.number(21e5)#+alg.e(1,order=1)#,order=1)#,1,10,2,1000
        if not ismdual:
            for kkk in range(1,nbases+1):
                E = E + algebra.e(kkk,order=order)
        nu = alg.number(0.28)#+alg.e(2,order=10)
        ri = alg.number(1)
        Pi = alg.number(10)  #+alg.e(3,order=1)# Pi = alg.number(1400)
        ro = alg.number(2)
        Po = alg.number(1000)#+alg.e(4,order=1)

        u_res,K,f = solve_2d_linear_elasticity(Th,E,nu,ri,Pi,ro,Po,times=times, solver = solver)


        times['mem_aft_solve2d'].append( psutil.virtual_memory().used )
        
        times_algebras[he]['K_nnz']   = K.nnz
        times_algebras[he]['K_shape'] = K.shape[0]
        
        del(u_res)
        del(K)
        del(f)
        del(Th)
        
        gc.collect()

        times['mem_aft_del_K'].append( psutil.virtual_memory().used )


        report_times_in_file(times_algebras, filename=filename)
        

    # end for
    
    

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def main(argv):
    
    opts, args = getopt.getopt(argv,"m:n:rh:",["order=","nbases=","real","mdual","export=","solver=","nevals=", "elorder="])
    
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
        elif opt in ["--elorder",]:
            setup['elorder'] = int(arg)
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
