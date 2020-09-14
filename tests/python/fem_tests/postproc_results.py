import os
import sys
import json
import numpy as np

import matplotlib.pyplot as plt

out_dir = "results/"

results_full = {}



def autolabel_top(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        y = rect.get_y()
        plt.annotate('{0:.2f}x'.format(y+height),
                    xy=(rect.get_x() + rect.get_width() / 2, y+height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')
        
def plot_bars(names, assembly, boundary, solution,total_r, special = ''):

    
    total    = solution+boundary+assembly

    plt.figure()

    assem_plt = plt.bar(names,(boundary+assembly)/total_r,                         width=0.5, label='Assembly')
    block_plt = plt.bar(names,solution/total_r,bottom=(boundary+assembly)/total_r,width=0.5, label='Block Solver')

    # autolabel(assem_plt)
    # autolabel(block_plt)
    autolabel_top(block_plt)

    plt.legend(loc='lower right')


    plt.title("Relative CPU time to real analysis for 1 Million DOFs " + special)
    plt.ylabel("Total CPU time.")
    plt.xticks(rotation=45)
    # plt.show()





def main():

    for r,d,f in os.walk(out_dir):

        for item in f:
            name = item.split(".")[0]
            sections = name.split('_')
            h      = int(sections[-1])
            alg    = sections[-2]
            eltype = sections[-3]
            system = sections[-4]
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
                
                if eltype not in results_full.keys():
                    results_full[eltype]={}
                # end if 
                
                results = results_full[eltype]

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
    orders = 10
    nvars = 10

    results = results_full['tri6']

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

    names       = np.zeros((orders,nvars),dtype=object)


    md_mesh_times = np.zeros(orders)
    md_assm_times = np.zeros(orders)
    md_bc_times   = np.zeros(orders)
    md_ch_times   = np.zeros(orders)
    md_su_times   = np.zeros(orders)
    md_um_times   = np.zeros(orders)
    md_totals_ch  = np.zeros(orders)
    md_totals_su  = np.zeros(orders)
    md_totals_um  = np.zeros(orders)

    md_names      = np.zeros(orders,dtype=object)


    for n in range(1,orders+1):
        # Add mdual
        if n == 1:
            key = 'onumm1n'+str(n)
        else:
            key = 'mdnum'+str(n)
        #
        if key in results.keys():
            times = results[key][h]
                
            md_mesh_times[ n-1 ] = times["mesh"]
            md_assm_times[ n-1 ] = times["assembly"]
            md_bc_times[   n-1 ] = times["boundary"]
            md_ch_times[   n-1 ] = times["cholesky"]
            md_su_times[   n-1 ] = times["superlu"]
            md_um_times[   n-1 ] = times["umfpack"]
            md_names[      n-1 ] = 'mdual'+str(n) 
        else:
            md_mesh_times[ n-1 ] = np.nan
            md_assm_times[ n-1 ] = np.nan
            md_bc_times[   n-1 ] = np.nan
            md_ch_times[   n-1 ] = np.nan
            md_su_times[   n-1 ] = np.nan
            md_um_times[   n-1 ] = np.nan
            md_names[      n-1 ] = 'mdual'+str(n) 

        for m in range(1,nvars+1):
            key = 'onumm'+str(m)+'n'+str(n)
            if key in results.keys():
                times = results[key][h]
                
                mesh_times[n-1,m-1] = times["mesh"]
                assm_times[n-1,m-1] = times["assembly"]
                bc_times[  n-1,m-1] = times["boundary"]

                ch_times[n-1,m-1] = times["cholesky"]
                su_times[n-1,m-1] = times["superlu"]
                um_times[n-1,m-1] = times["umfpack"]

                names[n-1,m-1] = 'om'+str(m)+'n'+str(n)
            else:
                mesh_times[n-1,m-1] = np.nan
                assm_times[n-1,m-1] = np.nan
                bc_times[  n-1,m-1] = np.nan
                ch_times[n-1,m-1] = np.nan
                su_times[n-1,m-1] = np.nan
                um_times[n-1,m-1] = np.nan
                names[n-1,m-1] = 'om'+str(m)+'n'+str(n)  
        # end for 
    # end for 


    totals_ch = mesh_times+assm_times+bc_times+ch_times
    totals_su = mesh_times+assm_times+bc_times+su_times
    totals_um = mesh_times+assm_times+bc_times+um_times

    md_totals_ch = md_mesh_times+md_assm_times+md_bc_times+md_ch_times
    md_totals_su = md_mesh_times+md_assm_times+md_bc_times+md_su_times
    md_totals_um = md_mesh_times+md_assm_times+md_bc_times+md_um_times

    total_ch = mesh_time+assm_time+bc_time+ch_time
    total_su = mesh_time+assm_time+bc_time+su_time
    total_um = mesh_time+assm_time+bc_time+um_time

    

    
    

    # plt.figure()
    # for n in range(1,orders+1):

    #     plt.semilogy(range(1,m+1),totals_ch[n-1,:]/total_ch, label = 'Order '+str(n))

    # # end for 

    # plt.xlabel("Number of basis")
    # plt.ylabel("Relative CPU time")
    # plt.title("Relative cpu times for Cholesky solver.")
    # plt.legend()
    # plt.grid()
    # # plt.show()


    # plt.figure()
    # for n in range(1,orders+1):
    #     plt.semilogy(range(1,m+1),totals_su[n-1,:]/total_su, label = 'Order '+str(n))
    # # end for 

    # plt.xlabel("Number of basis")
    # plt.ylabel("Relative CPU time")
    # plt.title("Relative cpu times for SuperLU solver.")
    # plt.legend()
    # plt.grid()
    # # plt.show()

    # plt.figure()
    # for n in range(1,orders+1):
    #     plt.semilogy(range(1,m+1),totals_um[n-1,:]/total_um, label = 'Order '+str(n))
    # # end for 

    # plt.xlabel("Number of basis")
    # plt.ylabel("Relative CPU time")
    # plt.title("Relative cpu times for UMFPACK solver.")
    # plt.legend()
    # plt.grid()
    # # plt.show()


    print(results.keys())

    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + ch_time
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], ch_times[n-1,:], total_r, special = 'Cholesky')


    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + su_time
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], su_times[n-1,:], total_r, special = 'SuperLU')





    n = 1
    total_r = assm_time + bc_time + ch_time
    # for n in range(1,orders+1):
    
    plot_bars(md_names, md_assm_times, 
        md_bc_times, md_ch_times, total_r, special = 'Cholesky')


    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + su_time
    # for n in range(1,orders+1):
    
    plot_bars(md_names, md_assm_times, 
        md_bc_times, md_su_times, total_r, special = 'SuperLU')





    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + ch_time
    # for m in range(1,nvars+1):
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], ch_times[:,m-1], total_r, special = 'Cholesky')



    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + su_time
    # for m in range(1,nvars+1):
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], su_times[:,m-1], total_r, special = 'SuperLU')



    plt.show()
# end if 