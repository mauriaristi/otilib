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

import pyoti.static.onumm1n1    as dual
import pyoti.static.mdnum1      as md1
import pyoti.static.mdnum2      as md2
import pyoti.static.mdnum3      as md3
import pyoti.static.mdnum4      as md4
import pyoti.static.mdnum5      as md5
import pyoti.static.mdnum6      as md6
import pyoti.static.mdnum7      as md7
import pyoti.static.mdnum8      as md8
import pyoti.static.mdnum9      as md9
import pyoti.static.mdnum10     as md10

import pyoti.static.onumm0n0    as om0n0

import pyoti.static.onumm1n1    as om1n1
import pyoti.static.onumm1n2    as om1n2
import pyoti.static.onumm1n3    as om1n3
import pyoti.static.onumm1n4    as om1n4
import pyoti.static.onumm1n5    as om1n5
import pyoti.static.onumm1n6    as om1n6
import pyoti.static.onumm1n7    as om1n7
import pyoti.static.onumm1n8    as om1n8
import pyoti.static.onumm1n9    as om1n9
import pyoti.static.onumm1n10   as om1n10

import pyoti.static.onumm2n1    as om2n1
import pyoti.static.onumm2n2    as om2n2
import pyoti.static.onumm2n3    as om2n3
import pyoti.static.onumm2n4    as om2n4
import pyoti.static.onumm2n5    as om2n5
import pyoti.static.onumm2n6    as om2n6
import pyoti.static.onumm2n7    as om2n7
import pyoti.static.onumm2n8    as om2n8
import pyoti.static.onumm2n9    as om2n9
import pyoti.static.onumm2n10   as om2n10

import pyoti.static.onumm3n1    as om3n1
import pyoti.static.onumm3n2    as om3n2
import pyoti.static.onumm3n3    as om3n3
import pyoti.static.onumm3n4    as om3n4
import pyoti.static.onumm3n5    as om3n5

import pyoti.static.onumm4n1    as om4n1
import pyoti.static.onumm4n2    as om4n2
import pyoti.static.onumm4n3    as om4n3
import pyoti.static.onumm4n4    as om4n4
import pyoti.static.onumm4n5    as om4n5

import pyoti.static.onumm5n1    as om5n1
import pyoti.static.onumm5n2    as om5n2
import pyoti.static.onumm5n3    as om5n3
import pyoti.static.onumm5n4    as om5n4
import pyoti.static.onumm5n5    as om5n5

import pyoti.static.onumm6n1    as om6n1
import pyoti.static.onumm6n2    as om6n2

import pyoti.static.onumm7n1    as om7n1
import pyoti.static.onumm7n2    as om7n2

import pyoti.static.onumm8n1    as om8n1
import pyoti.static.onumm8n2    as om8n2

import pyoti.static.onumm9n1    as om9n1
import pyoti.static.onumm9n2    as om9n2

import pyoti.static.onumm10n1   as om10n1
import pyoti.static.onumm10n2   as om10n2

e  = oti.e
np = oti.np






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
            [md5],
            [md6],
            [md7],
            [md8],
            [md9],
            [md10],
        ]

algebras['oti']=[
    [om0n0,],
    [ dual,   om2n1,  om3n1,  om4n1, om5n1, om6n1, om7n1, om8n1, om9n1, om10n1],
    [ om1n2,  om2n2,  om3n2,  om4n2, om5n2, om6n2, om7n2, om8n2, om9n2, om10n2],
    [ om1n3,  om2n3,  om3n3,  om4n3, om5n3                                    ],
    [ om1n4,  om2n4,  om3n4,  om4n4, om5n4                                    ],
    [ om1n5,  om2n5,  om3n5,  om4n5, om5n5                                    ],
    [ om1n6,  om2n6                                                           ],
    [ om1n7,  om2n7                                                           ],
    [ om1n8,  om2n8                                                           ],
    [ om1n9,  om2n9                                                           ],
    [ om1n10, om2n10                                                          ], 
]

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
setup['export'] = 'results_real'
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
    
    algebra = None

    if isreal:
        algebra = algebras['real']
    elif ismdual:
        algebra = algebras['mdual'][order][0]
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
        end_time = time()

        times['mem_aft_mesh'].append( psutil.virtual_memory().used )

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
