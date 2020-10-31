import os
import sys
import json
import numpy as np

import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator
from matplotlib.patches import Patch

from matplotlib import rc
# rc('font',**{'family':'sans-serif','sans-serif':['Helvetica']})
## for Palatino and other serif fonts use:
rc('font',**{'family':'serif','serif':['Palatino'],'size': 12})
rc('text', usetex=True)

out_dir = "results_sparse/"

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
                    ha='center', va='bottom',rotation=90)

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
            print("\nFile:",item)
            if item.split(".")[-1]!='json':
                continue
            sections = name.split('_')
            ver    = int(sections[-1])
            alg    = sections[-2]
            eltype = sections[-3]
            system = sections[-4]

            print("--- Found "+alg+" with version: "+str(ver))

            f = open(os.path.join(r,item))
            res_dict = json.load(f)
            f.close()

            if 'real' in res_dict.keys():

                val = res_dict['real']
                if 'real' not in results_full.keys():
                    results_full['real']=[]
                # end if
                results_full['real'].append(res_dict['real'])

            else:

                if 'sparse' not in results_full.keys():
                    results_full['sparse']={}
                # end if

                if res_dict['sparse']['order'] not in results_full['sparse'].keys():
                    results_full['sparse'][res_dict['sparse']['order']]=[]
                # end if

                results_full['sparse'][res_dict['sparse']['order']].append(res_dict['sparse'])

            # end if
        # end for
        break 
    # end for
# ===================================================================================================================================



def plot_first_order_multiple_derivs(filepre = 'figs/test', figsize=(5,5)):
    nvars = 100
    assm_times    = np.zeros(nvars)
    bc_times      = np.zeros(nvars)
    ch_times      = np.zeros(nvars)

    assm_full_times    = np.zeros(nvars)
    bc_full_times      = np.zeros(nvars)
    ch_full_times      = np.zeros(nvars)

    totals_ch     = np.zeros(nvars)

    names         = np.empty(nvars,dtype=object)
    names_full    = np.empty(nvars,dtype=object)
   
    total_ch = assm_time+bc_time+ch_time

    # evaluate order 1:
    res = results_full['sparse'][1]

    assm_times[:]=0
    bc_times[:]=0
    ch_times[:]=0

    l=0
    l2=0

    for k in range(len(res)):

        if res[k]['nnodes_perturbed']>0 and res[k]['nnodes_perturbed']<40000:

            assm_times[l]=res[k]['assembly']
            bc_times[l]=res[k]['boundary']
            ch_times[l]=res[k]['solution']
            names[l] = str(res[k]['nbases'])
            l+=1

        elif res[k]['nnodes_perturbed']==40000 and res[k]['variable']=='r':

            assm_full_times[l2]=res[k]['assembly']
            bc_full_times[l2]=res[k]['boundary']
            ch_full_times[l2]=res[k]['solution']
            names_full[l2] = str(res[k]['nbases'])
            l2+=1

        # end if 
    # end if

    print(names)
    print(names_full)
    
    idx = np.argsort(names[:l])

    n = 1
    total_r = assm_time + bc_time + ch_time
    
    

    # for n in range(1,orders+1):
    

    assembly = assm_times[idx]
    boundary = bc_times[idx]
    solution = ch_times[idx]

    total    = solution+boundary+assembly

    plt.figure(figsize=figsize)
    
    width = 0.35; sep = 0.05
    x_vals = np.arange(len(idx))

    assem_plt = plt.bar(x_vals-width/2-sep/2,(boundary+assembly)/total_r,                         
        color='C0',width=width, label='Assembly $<1\%$ perturbed')
    block_plt = plt.bar(x_vals-width/2-sep/2,solution/total_r,bottom=(boundary+assembly)/total_r, 
        color='C1',width=width, label='Solution $<1\%$ perturbed')

    autolabel_top(block_plt)

    idx = np.argsort(names_full[:l2])
    assembly = assm_full_times[idx]
    boundary = bc_full_times[idx]
    solution = ch_full_times[idx]

    total    = solution+boundary+assembly

    assem_plt = plt.bar(x_vals+width/2+sep/2,(boundary+assembly)/total_r,                         
        color='C0', width=width, linewidth=0.8,hatch='/'*4,label='Assembly $100\%$ perturbed')
    block_plt = plt.bar(x_vals+width/2+sep/2,solution/total_r,bottom=(boundary+assembly)/total_r, 
        color='C1', width=width, linewidth=0.8,hatch='/'*4,label='Solution $100\%$ perturbed')
    
    autolabel_top(block_plt)


    legend_elements = [Patch(facecolor='C0', edgecolor='k',label='Assembly'),
    Patch(facecolor='C1', edgecolor='k',label='Solution'),
    Patch(facecolor='w', edgecolor='k',label='Nodes perturbed: $<1\%$'),
    Patch(facecolor='w', edgecolor='k',hatch='/'*4,label='Nodes perturbed: $100\%$'),
    ]

    plt.legend(handles=legend_elements,loc='upper left')


    plt.ylabel("Relative CPU time to real analysis.")    
    plt.xlabel("Number of first order derivatives.")    

    plt.xticks(rotation=45)
    plt.axis([None,None,None,120])
    plt.grid(axis='y', color='#CCCCCC')
    plt.minorticks_on()
    plt.grid( color='#EEEEEE',  which='minor', axis='y')
    plt.tight_layout()

    ax = plt.gca()
    ax.set_xticks(x_vals)
    ax.set_xticklabels(names_full[idx])

    ax.set_axisbelow(True)
    ax.yaxis.set_minor_locator(MultipleLocator(2))
    ax.yaxis.set_major_locator(MultipleLocator(10))
    ax.xaxis.set_minor_locator(MultipleLocator(1))
    
    filename = filepre + '.pdf' 
    
    plt.savefig(filename, dpi=150)
    
# ==================================================================================================================





if __name__ == "__main__":

    main()
    
    
    orders = 1
    nvars = 10
    eltype = 'tri6'
    results = results_full['sparse']

    assm_time     = results_full['real'][0]["assembly"]
    bc_time       = results_full['real'][0]["boundary"]
    ch_time       = results_full['real'][0]["solution"]
    
    assm_times    = np.zeros(nvars)
    bc_times      = np.zeros(nvars)
    ch_times      = np.zeros(nvars)
    totals_ch     = np.zeros(nvars)

    names         = np.empty(nvars,dtype=object)
   
    total_ch = assm_time+bc_time+ch_time

    # evaluate order 1:
    res = results[1]

    assm_times[:]=0
    bc_times[:]=0
    ch_times[:]=0
    l=0
    for k in range(len(res)):

        if res[k]['nnodes_perturbed']>0 and res[k]['nnodes_perturbed']<40000:
            assm_times[l]=res[k]['assembly']
            bc_times[l]=res[k]['boundary']
            ch_times[l]=res[k]['solution']
            names[l] = str(res[k]['nbases'])
            l+=1
        # end if 
    # end if

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
    print(names)
    # print(names_full)
    
    idx = np.argsort(names[:l])


    plot_first_order_multiple_derivs(filepre='figs/test_2var', figsize=(5,5))
    # n = 1
    # total_r = assm_time + bc_time + ch_time
    # # for n in range(1,orders+1):
    # filename = 'figs/test_2'
    # plot_bars(names[idx], assm_times[idx], 
    #     bc_times[idx], ch_times[idx], total_r, figsize=(5,5),special = 'Cholesky', filepre = filename, save=True)

    






    # # Plot Order 1
    # n = 1
    # total_r = assm_time + bc_time + ch_time
    # filename = 'figs/figure_'+eltype+'_total_oti_n{0}'
    # # for n in range(1,orders+1):
    # for n in range(1,2+1):
    #     plot_bars(names[n-1,:], assm_times[n-1,:], 
    #         bc_times[n-1,:], ch_times[n-1,:], total_r, special = 'Cholesky', filepre = filename.format(n), save=True )


    # # Plot Order 1
    # n = 1
    # total_r = assm_time + bc_time + su_time
    # # for n in range(1,orders+1):
    # for n in range(1,2+1):
    #     plot_bars(names[n-1,:], assm_times[n-1,:], 
    #         bc_times[n-1,:], su_times[n-1,:], total_r, special = 'SuperLU', filepre = filename.format(n), save=True )





    # n = 1
    # total_r = assm_time + bc_time + ch_time
    # # for n in range(1,orders+1):
    # filename = 'figs/figure_'+eltype+'_total_mdual'
    # plot_bars(md_names[1:], md_assm_times[1:], 
    #     md_bc_times[1:], md_ch_times[1:], total_r, special = 'Cholesky', filepre = filename, save=True)


    # # Plot Order 1
    # n = 1
    # total_r = assm_time + bc_time + su_time
    # # for n in range(1,orders+1):
    
    # plot_bars(md_names[1:], md_assm_times[1:], 
    #     md_bc_times[1:], md_su_times[1:], total_r, special = 'SuperLU', filepre = filename, save=True)





    # # Plot Order 1
    # n = 1
    # total_r = assm_time + bc_time + ch_time
    # # for m in range(1,nvars+1):
    # filename = 'figs/figure_'+eltype+'_total_oti_m{0}'
    # for m in range(1,2+1):
    #     plot_bars(names[:,m-1], assm_times[:,m-1], 
    #         bc_times[:,m-1], ch_times[:,m-1], total_r, special = 'Cholesky', filepre = filename.format(m), save=True )



    # # Plot Order 1
    # n = 1
    # total_r = assm_time + bc_time + su_time
    # # for m in range(1,nvars+1):
    # for m in range(1,2+1):
    #     plot_bars(names[:,m-1], assm_times[:,m-1], 
    #         bc_times[:,m-1], su_times[:,m-1], total_r, special = 'SuperLU', filepre = filename.format(m), save=True )










    
    # total_r = assm_time + bc_time 
    # filename = 'figs/figure_'+eltype+'_assm_real'
    # plot_bars(real_cmp_names, real_cmp_assm, 
    #     real_cmp_bc, real_cmp_ch, total_r, assembly_only=True,figsize=(5,5), filepre = filename, save=True)




    # # Plot Order 1
    # filename = 'figs/figure_'+eltype+'_assm_mdual'
    # n = 1
    # total_r = assm_time + bc_time 
    # # for n in range(1,orders+1):
    
    # plot_bars(md_names[1:], md_assm_times[1:], 
    #     md_bc_times[1:], md_ch_times[1:], total_r, assembly_only = True, filepre = filename, save=True)
    

    # # Plot Order 1
    
    # total_r = assm_time + bc_time 
    # filename = 'figs/figure_'+eltype+'_assm_oti_m{0}'
    # # for m in range(1,nvars+1):
    # for m in range(1,2+1):
    #     plot_bars(names[:,m-1], assm_times[:,m-1], 
    #         bc_times[:,m-1], su_times[:,m-1], total_r, assembly_only = True, filepre = filename.format(m), save=True)


    # # Plot Order 1
    
    # total_r = assm_time + bc_time
    # filename = 'figs/figure_'+eltype+'_assm_oti_n{0}' 
    # # for n in range(1,orders+1):
    # for n in range(1,2+1):
    #     plot_bars(names[n-1,:], assm_times[n-1,:], 
    #         bc_times[n-1,:], su_times[n-1,:], total_r, assembly_only = True, filepre = filename.format(n), save=True)













    # total_r = assm_time + bc_time + ch_time
    # filename = 'figs/figure_'+eltype+'_sol_real'
    # plot_bars(real_cmp_names, real_cmp_assm, 
    #     real_cmp_bc, real_cmp_ch, total_r, solution_only=True,figsize=(5,5),special = 'Cholesky', filepre = filename, save=True)

    # total_r = assm_time + bc_time + su_time
    # plot_bars(real_cmp_names, real_cmp_assm, 
    #     real_cmp_bc, real_cmp_su, total_r, solution_only=True,figsize=(5,5),special = 'SuperLU', filepre = filename, save=True)


    # # Plot Order 1
    # filename = 'figs/figure_'+eltype+'_sol_mdual'
    # n = 1
    # total_r = ch_time
    # # for n in range(1,orders+1):
    
    # plot_bars(md_names[1:], md_assm_times[1:], 
    #     md_bc_times[1:], md_ch_times[1:], total_r, special='Cholesky', solution_only = True, filepre = filename, save=True)
    

    # # Plot Order 1
    
    # total_r = ch_time
    # filename = 'figs/figure_'+eltype+'_sol_oti_m{0}'
    # # for m in range(1,nvars+1):
    # for m in range(1,2+1):
    #     plot_bars(names[:,m-1], assm_times[:,m-1], 
    #         bc_times[:,m-1], ch_times[:,m-1], total_r, special='Cholesky', solution_only = True, filepre = filename.format(m), save=True)


    # # Plot Order 1
    
    # total_r = ch_time
    # filename = 'figs/figure_'+eltype+'_sol_oti_n{0}' 
    # # for n in range(1,orders+1):
    # for n in range(1,2+1):
    #     plot_bars(names[n-1,:], assm_times[n-1,:], 
    #         bc_times[n-1,:], ch_times[n-1,:], total_r, special='Cholesky', solution_only = True, filepre = filename.format(n), save=True)









    # # Plot Order 1
    # filename = 'figs/figure_'+eltype+'_sol_mdual'
    # n = 1
    # total_r = su_time
    # # for n in range(1,orders+1):
    
    # plot_bars(md_names[1:], md_assm_times[1:], 
    #     md_bc_times[1:], md_su_times[1:], total_r, special='SuperLU', solution_only = True, filepre = filename, save=True)
    

    # # Plot Order 1
    
    # total_r = su_time
    # filename = 'figs/figure_'+eltype+'_sol_oti_m{0}'
    # # for m in range(1,nvars+1):
    # for m in range(1,2+1):
    #     plot_bars(names[:,m-1], assm_times[:,m-1], 
    #         bc_times[:,m-1], su_times[:,m-1], total_r, special='SuperLU', solution_only = True, filepre = filename.format(m), save=True)


    # # Plot Order 1
    
    # total_r = su_time
    # filename = 'figs/figure_'+eltype+'_sol_oti_n{0}' 
    # # for n in range(1,orders+1):
    # for n in range(1,2+1):
    #     plot_bars(names[n-1,:], assm_times[n-1,:], 
    #         bc_times[n-1,:], su_times[n-1,:], total_r, special='SuperLU', solution_only = True, filepre = filename.format(n), save=True)





    # plt.show()

# end if 