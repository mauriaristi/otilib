import os
import sys
import json
import numpy as np

import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator


from matplotlib import rc
# rc('font',**{'family':'sans-serif','sans-serif':['Helvetica']})
## for Palatino and other serif fonts use:
rc('font',**{'family':'serif','serif':['Palatino'],'size': 16})
rc('text', usetex=True)

out_dir = "../results/"

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

    # end for 
# ===================================================================================================================================

        
def plot_bars(names, assembly, boundary, solution, total_r, 
    special = '', assembly_only = False, solution_only = False,
    filepre = 'figure', save = False, figsize = (10,5)):

    
    total    = solution+boundary+assembly

    plt.figure(figsize=figsize)
    
    if assembly_only:

        block_plt = plt.bar(names,(boundary+assembly)/total_r,                         width=0.5, label='Assembly')
    
    elif solution_only:

        block_plt = plt.bar(names,solution/solution,                                    width=0.5, color = 'C7',label='Factor $\\mathbf{K}_r$ and solve $\\mathbf{u}_r$.')
        block_plt = plt.bar(names,(solution-total_r)/total_r, bottom=solution/solution, width=0.5, color = 'C8',label='Solve all $[\\mathbf{u}]^{p}$.')

    else:

        assem_plt = plt.bar(names,(boundary+assembly)/total_r,                         width=0.5, label='Assembly')
        block_plt = plt.bar(names,solution/total_r,bottom=(boundary+assembly)/total_r, width=0.5, label='Solution')

    # end if 

    # autolabel(assem_plt)
    # autolabel(block_plt)
    autolabel_top(block_plt)

    plt.legend(loc='upper left')


    # plt.title("Relative CPU time to real analysis for 1 Million DOFs " + special)
    if assembly_only:
        plt.ylabel("Relative CPU time to real assembly.")
    elif solution_only:
        plt.ylabel("Relative CPU time to real solution.")
    else:
        plt.ylabel("Relative CPU time to real analysis.")
    # end if 
    plt.xticks(rotation=45)
    plt.axis([None,None,None,22])
    plt.grid(axis='y', color='#CCCCCC')
    plt.minorticks_on()
    plt.grid( color='#EEEEEE',  which='minor', axis='y')
    plt.tight_layout()

    ax = plt.gca()
    ax.set_axisbelow(True)
    ax.yaxis.set_minor_locator(MultipleLocator(1))
    ax.yaxis.set_major_locator(MultipleLocator(2))
    ax.xaxis.set_minor_locator(MultipleLocator(1))

    if save:
        if special is not '':
            filename = filepre + "_" + special + '.pdf' 
        else:
            filename = filepre + '.pdf' 
        # end if 
        plt.savefig(filename, dpi=150)
        # plt.show()
    # end if 

# ===================================================================================================================================



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
# ===================================================================================================================================

if __name__ == "__main__":

    main()
    
    h = 10
    orders = 10
    nvars = 10
    eltype = 'tri6'
    results = results_full[eltype]

    mesh_time     = results['real'][h]["mesh"]
    assm_time     = results['real'][h]["assembly"]
    bc_time       = results['real'][h]["boundary"]

    ch_time       = results['real'][h]["cholesky"]
    su_time       = results['real'][h]["superlu"]
    um_time       = results['real'][h]["umfpack"]

    mesh_times    = np.zeros((orders,nvars))
    assm_times    = np.zeros((orders,nvars))
    bc_times      = np.zeros((orders,nvars))

    ch_times      = np.zeros((orders,nvars))
    su_times      = np.zeros((orders,nvars))
    um_times      = np.zeros((orders,nvars))

    totals_ch     = np.zeros((orders,nvars))
    totals_su     = np.zeros((orders,nvars))
    totals_um     = np.zeros((orders,nvars))

    names         = np.zeros((orders,nvars),dtype=object)

    md_mesh_times = np.zeros(orders+1)
    md_assm_times = np.zeros(orders+1)
    md_bc_times   = np.zeros(orders+1)
    md_ch_times   = np.zeros(orders+1)
    md_su_times   = np.zeros(orders+1)
    md_um_times   = np.zeros(orders+1)
    md_totals_ch  = np.zeros(orders+1)
    md_totals_su  = np.zeros(orders+1)
    md_totals_um  = np.zeros(orders+1)

    md_names      = np.zeros(orders+1,dtype=object)

    # real_only
    for n in range(0,orders+1):
        
        # Add mdual

        if n == 1:
            key = 'onumm1n'+str(n)
        elif n == 0:
            key = 'onumm0n'+str(n)
        else:
            key = 'mdnum'+str(n)
        # end if

        if key in results.keys():
            times = results[key][h]
                
            md_mesh_times[ n ] = times["mesh"]
            md_assm_times[ n ] = times["assembly"]
            md_bc_times[   n ] = times["boundary"]
            md_ch_times[   n ] = times["cholesky"]
            md_su_times[   n ] = times["superlu"]
            md_um_times[   n ] = times["umfpack"]
            md_names[      n ] = '$\\mathbb{{D}}_{{{0}}}$'.format(n)#'mdual'+str(n) 
        else:
            md_mesh_times[ n ] = np.nan
            md_assm_times[ n ] = np.nan
            md_bc_times[   n ] = np.nan
            md_ch_times[   n ] = np.nan
            md_su_times[   n ] = np.nan
            md_um_times[   n ] = np.nan
            md_names[      n ] = '$\\mathbb{{D}}_{{{0}}}$'.format(n)#'mdual'+str(n) 

        if n != 0:

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

                    names[n-1,m-1] = '$\\mathbb{{OTI}}^{{{0}}}_{{{1}}}$'.format(n,m)#'om'+str(m)+'n'+str(n)
                else:
                    mesh_times[n-1,m-1] = np.nan
                    assm_times[n-1,m-1] = np.nan
                    bc_times[  n-1,m-1] = np.nan
                    ch_times[n-1,m-1] = np.nan
                    su_times[n-1,m-1] = np.nan
                    um_times[n-1,m-1] = np.nan
                    names[n-1,m-1] = '$\\mathbb{{OTI}}^{{{0}}}_{{{1}}}$'.format(n,m)#'om'+str(m)+'n'+str(n)  
                
                # end if 

            
            # end for 
        # end if 
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










    real_cmp_mesh = np.array([mesh_time, md_mesh_times[0] ])
    real_cmp_assm = np.array([assm_time, md_assm_times[0] ])
    real_cmp_bc   = np.array([bc_time  , md_bc_times[0]   ])
    real_cmp_ch   = np.array([ch_time  , md_ch_times[0]   ])
    real_cmp_su   = np.array([su_time  , md_su_times[0]   ])
    real_cmp_names= np.array(["$\\mathbb{R}$", "$\\mathbb{OTI}^{0}_{0}$"])
    
    

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
    


    n = 1
    total_r = assm_time + bc_time + ch_time
    # for n in range(1,orders+1):
    filename = 'figs/figure_'+eltype+'_total_real'
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_ch, total_r, figsize=(5,5),special = 'Cholesky', filepre = filename, save=True)

    total_r = assm_time + bc_time + su_time
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_su, total_r, figsize=(5,5),special = 'SuperLU', filepre = filename, save=True)






    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + ch_time
    filename = 'figs/figure_'+eltype+'_total_oti_n{0}'
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], ch_times[n-1,:], total_r, special = 'Cholesky', filepre = filename.format(n), save=True )


    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + su_time
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], su_times[n-1,:], total_r, special = 'SuperLU', filepre = filename.format(n), save=True )





    n = 1
    total_r = assm_time + bc_time + ch_time
    # for n in range(1,orders+1):
    filename = 'figs/figure_'+eltype+'_total_mdual'
    plot_bars(md_names[1:], md_assm_times[1:], 
        md_bc_times[1:], md_ch_times[1:], total_r, special = 'Cholesky', filepre = filename, save=True)


    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + su_time
    # for n in range(1,orders+1):
    
    plot_bars(md_names[1:], md_assm_times[1:], 
        md_bc_times[1:], md_su_times[1:], total_r, special = 'SuperLU', filepre = filename, save=True)





    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + ch_time
    # for m in range(1,nvars+1):
    filename = 'figs/figure_'+eltype+'_total_oti_m{0}'
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], ch_times[:,m-1], total_r, special = 'Cholesky', filepre = filename.format(m), save=True )



    # Plot Order 1
    n = 1
    total_r = assm_time + bc_time + su_time
    # for m in range(1,nvars+1):
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], su_times[:,m-1], total_r, special = 'SuperLU', filepre = filename.format(m), save=True )










    
    total_r = assm_time + bc_time 
    filename = 'figs/figure_'+eltype+'_assm_real'
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_ch, total_r, assembly_only=True,figsize=(5,5), filepre = filename, save=True)




    # Plot Order 1
    filename = 'figs/figure_'+eltype+'_assm_mdual'
    n = 1
    total_r = assm_time + bc_time 
    # for n in range(1,orders+1):
    
    plot_bars(md_names[1:], md_assm_times[1:], 
        md_bc_times[1:], md_ch_times[1:], total_r, assembly_only = True, filepre = filename, save=True)
    

    # Plot Order 1
    
    total_r = assm_time + bc_time 
    filename = 'figs/figure_'+eltype+'_assm_oti_m{0}'
    # for m in range(1,nvars+1):
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], su_times[:,m-1], total_r, assembly_only = True, filepre = filename.format(m), save=True)


    # Plot Order 1
    
    total_r = assm_time + bc_time
    filename = 'figs/figure_'+eltype+'_assm_oti_n{0}' 
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], su_times[n-1,:], total_r, assembly_only = True, filepre = filename.format(n), save=True)













    total_r = assm_time + bc_time + ch_time
    filename = 'figs/figure_'+eltype+'_sol_real'
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_ch, total_r, solution_only=True,figsize=(5,5),special = 'Cholesky', filepre = filename, save=True)

    total_r = assm_time + bc_time + su_time
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_su, total_r, solution_only=True,figsize=(5,5),special = 'SuperLU', filepre = filename, save=True)


    # Plot Order 1
    filename = 'figs/figure_'+eltype+'_sol_mdual'
    n = 1
    total_r = ch_time
    # for n in range(1,orders+1):
    
    plot_bars(md_names[1:], md_assm_times[1:], 
        md_bc_times[1:], md_ch_times[1:], total_r, special='Cholesky', solution_only = True, filepre = filename, save=True)
    

    # Plot Order 1
    
    total_r = ch_time
    filename = 'figs/figure_'+eltype+'_sol_oti_m{0}'
    # for m in range(1,nvars+1):
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], ch_times[:,m-1], total_r, special='Cholesky', solution_only = True, filepre = filename.format(m), save=True)


    # Plot Order 1
    
    total_r = ch_time
    filename = 'figs/figure_'+eltype+'_sol_oti_n{0}' 
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], ch_times[n-1,:], total_r, special='Cholesky', solution_only = True, filepre = filename.format(n), save=True)









    # Plot Order 1
    filename = 'figs/figure_'+eltype+'_sol_mdual'
    n = 1
    total_r = su_time
    # for n in range(1,orders+1):
    
    plot_bars(md_names[1:], md_assm_times[1:], 
        md_bc_times[1:], md_su_times[1:], total_r, special='SuperLU', solution_only = True, filepre = filename, save=True)
    

    # Plot Order 1
    
    total_r = su_time
    filename = 'figs/figure_'+eltype+'_sol_oti_m{0}'
    # for m in range(1,nvars+1):
    for m in range(1,2+1):
        plot_bars(names[:,m-1], assm_times[:,m-1], 
            bc_times[:,m-1], su_times[:,m-1], total_r, special='SuperLU', solution_only = True, filepre = filename.format(m), save=True)


    # Plot Order 1
    
    total_r = su_time
    filename = 'figs/figure_'+eltype+'_sol_oti_n{0}' 
    # for n in range(1,orders+1):
    for n in range(1,2+1):
        plot_bars(names[n-1,:], assm_times[n-1,:], 
            bc_times[n-1,:], su_times[n-1,:], total_r, special='SuperLU', solution_only = True, filepre = filename.format(n), save=True)





    # plt.show()

# end if 