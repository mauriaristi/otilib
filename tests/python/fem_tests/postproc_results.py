import os
import sys
import json
import numpy as np

import matplotlib.pyplot as plt

out_dir = "results/"

results = {}

def main():

    for r,d,f in os.walk(out_dir):

        for item in f:
            name = item.split(".")[0]
            sections = name.split('_')
            h      = int(sections[-1])
            alg    = sections[-2]
            system = sections[-3]
            if system == 'yarumal' and alg == 'real' and h==10:
                continue
            # end if 

            print("--- Found "+alg+" with h: "+str(h))

            f = open(os.path.join(r,item))
            res_dict = json.load(f)
            f.close()

            

            for val in res_dict.values():
                
                keys = list(val.keys())
                
                alg_key = keys[0]
                
                res = val[alg_key]
                
                Knnz = val['K_nnz']
                Kshp = val['K_shape']

                msh_nnodes = val['mesh_DOFs']
                dof_fem    = msh_nnodes*2
                msh_stats  = val['meshstats']
                


                if alg_key not in results.keys():
                    results[alg_key]={}
                # end if 
                
                results[alg_key][h]={}
                res_ = results[alg_key][h]


                mesh_time = np.average(res['mesh'])
                assm_time = np.average(res['assembly'])
                bound_time = np.average(res['boundary'])
                
                ch_time = np.average(res['sol_cholesky'])
                su_time = np.average(res['sol_superlu'])
                um_time = np.average(res['sol_umfpack'])
                
                # mem_bf_mesh = np.array(res['mem_bf_mesh'])
                # mem_af_mesh = np.array(res['mem_aft_mesh'])
                
                # mem_bf_creation = np.array(res['mem_bf_creation'])
                # mem_af_creation = np.array(res['mem_aft_creation'])
                
                # mem_af_assm = np.array('mem_aft_assembly')
                
                
                res_['mesh']      = mesh_time
                res_['assembly']  = assm_time
                res_['boundary']  = bound_time
                
                res_['cholesky']  = ch_time
                res_['superlu']   = su_time
                res_['umfpack']   = um_time

                res_['DOF']       = dof_fem
                res_['Knnz']      = Knnz
                res_['Kshp']      = Kshp
                res_['nnodes']    = msh_nnodes
                res_['meshstats'] = msh_stats

                # res_['mem_']      = mem_bf_mesh 

            # end for 
            
        # end for
        break 
    # end for

#

if __name__ == "__main__":
    main()
    
    h = 10
    orders = 5
    nvars = 5


    mesh_time = results['real'][h]["mesh"]
    assm_time = results['real'][h]["assembly"]
    bc_time   = results['real'][h]["boundary"]

    

    ch_time  = results['real'][h]["cholesky"]
    su_time  = results['real'][h]["superlu"]
    um_time  = results['real'][h]["umfpack"]






    mesh_times = np.zeros((orders,nvars))
    assm_times = np.zeros((orders,nvars))
    bc_times   = np.zeros((orders,nvars))

    ch_times   = np.zeros((orders,nvars))
    su_times   = np.zeros((orders,nvars))
    um_times   = np.zeros((orders,nvars))

    totals_ch   = np.zeros((orders,nvars))
    totals_su   = np.zeros((orders,nvars))
    totals_um   = np.zeros((orders,nvars))


    for n in range(1,orders+1):
        for m in range(1,nvars+1):
            key = 'onumm'+str(m)+'n'+str(n)
            times = results[key][h]
            
            mesh_times[n-1,m-1] = times["mesh"]
            assm_times[n-1,m-1] = times["assembly"]
            bc_times[  n-1,m-1] = times["boundary"]

            ch_times[n-1,m-1] = times["cholesky"]
            su_times[n-1,m-1] = times["superlu"]
            um_times[n-1,m-1] = times["umfpack"]


   
        # end for 
    # end for 


    totals_ch = mesh_times+assm_times+bc_times+ch_times
    totals_su = mesh_times+assm_times+bc_times+su_times
    totals_um = mesh_times+assm_times+bc_times+um_times

    total_ch = mesh_time+assm_time+bc_time+ch_time
    total_su = mesh_time+assm_time+bc_time+su_time
    total_um = mesh_time+assm_time+bc_time+um_time

    

    orders= 5
    

    plt.figure()
    for n in range(1,orders+1):

        plt.semilogy(range(1,m+1),totals_ch[n-1,:]/total_ch, label = 'Order '+str(n))

    # end for 

    plt.xlabel("Number of basis")
    plt.ylabel("Relative CPU time")
    plt.title("Relative cpu times for Cholesky solver.")
    plt.legend()
    plt.grid()
    plt.show()


    plt.figure()
    for n in range(1,orders+1):
        plt.semilogy(range(1,m+1),totals_su[n-1,:]/total_su, label = 'Order '+str(n))
    # end for 

    plt.xlabel("Number of basis")
    plt.ylabel("Relative CPU time")
    plt.title("Relative cpu times for SuperLU solver.")
    plt.legend()
    plt.grid()
    plt.show()

    plt.figure()
    for n in range(1,orders+1):
        plt.semilogy(range(1,m+1),totals_um[n-1,:]/total_um, label = 'Order '+str(n))
    # end for 

    plt.xlabel("Number of basis")
    plt.ylabel("Relative CPU time")
    plt.title("Relative cpu times for UMFPACK solver.")
    plt.legend()
    plt.grid()
    plt.show()

# end if 