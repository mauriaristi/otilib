from elastic_cylinder import *
from utils import *


algebras = [r, md2, md3, md4, md5,om0n0, dual,
            om1n2,om1n3,om1n4,om1n5,om1n6,om1n7,om1n8,om1n9,om1n10,
            om2n1,om2n2,om2n3,om2n4,om2n5,om2n6,om2n7,om2n8,om2n9,om2n10,
            om3n1,om3n2,om3n3,om3n4,om3n5,
            om4n1,om4n2,om4n3,om4n4,om4n5,
            om5n1,om5n2,om5n3,om5n4,om5n5
            ]

# algebras = [r, md2, md3, #md4, md5, om0n0, dual,
#             # om1n2,om1n3,om1n4,om1n5,om1n6,om1n7,om1n8,om1n9,om1n10,
#             # om2n1,om2n2,om2n3,om2n4,om2n5,om2n6,om2n7,om2n8,om2n9,om2n10,
#             # om3n1,om3n2,om3n3,om3n4,om3n5,
#             # om4n1,om4n2,om4n3,om4n4,om4n5,
#             # om5n1,om5n2,om5n3,om5n4,om5n5
#             ]

solvers = ['cholesky','umfpack']
solver = 'cholesky'
nevals = 3

hes = [0.01,]

for i in range(10):
    # hes.append(hes[-1]*0.66)
    hes.append(hes[-1]*0.84)
# end for

hes[-1]=0.00177

times_algebras = {}
print("Will analyze the following values:", hes)

for algebra in algebras:
    
    alg_key = algebra.__name__.split(".")[-1]
    
    times_algebras[alg_key] = {}
    
    for he in hes: 
        
        
        print("Analyzing algebra {0} he {1}".format(alg_key,he))

        times_algebras[alg_key][he] = {}
        times = times_algebras[alg_key][he]

        times['mesh']     = []
        times['mesh_DOFs'] = 0
        times['assembly'] = []
        times['boundary'] = []
        times['solution'] = []
        for i in range(nevals):
            
            fem.set_global_algebra(algebra)
            alg = fem.get_global_algebra()

            start_time = time()
            Th = cylinder( 1, 2, he=he, quads=False, save=False, structured=True )
            end_time = time()
            times['mesh_DOFs'] = Th.nnodes
            times['meshstats'] = repr(Th)
            times['mesh'].append( end_time  - start_time )

            E  = alg.number(21e5)#+alg.e(1,order=1)#,order=1)#,1,10,2,1000
            nu = alg.number(0.28)#+alg.e(2,order=10)
            ri = alg.number(1)
            Pi = alg.number(10)  #+alg.e(3,order=1)# Pi = alg.number(1400)
            ro = alg.number(2)
            Po = alg.number(1000)#+alg.e(4,order=1)

        
            u_res,K,f = solve_2d_linear_elasticity(Th,E,nu,ri,Pi,ro,Po,times=times, solver = solver)

        # end for

        report_times_in_file(times_algebras, filename="report_times_static.json")

    # end for 

# end for 