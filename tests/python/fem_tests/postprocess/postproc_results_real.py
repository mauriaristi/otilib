import os
import sys
import json
import numpy as np
import sys
path2oti = '../../../../build/'
sys.path.append(path2oti) # Add path to OTI library.

import pyoti.core as coti

import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator
from matplotlib.patches import Patch

from matplotlib import rc
# rc('font',**{'family':'sans-serif','sans-serif':['Helvetica']})
## for Palatino and other serif fonts use:
rc('font',**{'family':'serif','serif':['Palatino'],'size': 12})
rc('text', usetex=True)

outdirs = ["../results/",'results_sparse_real']

results_full = {}
helper = coti.get_dHelp()


def autolabel_top(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        y = rect.get_y()
        plt.annotate('{0:.2f}x'.format(y+height),
                    xy=(rect.get_x() + rect.get_width() / 2, y+height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom', rotation=90)

    # end for 
# ===================================================================================================================================
def autolabel_middle(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        y = rect.get_y()
        plt.annotate('({0:.2f}x)'.format(y+height),
                    xy=(rect.get_x() + rect.get_width() / 2, y+height/2),
                    # xytext=(0, 3),  # 3 points vertical offset
                    # textcoords="offset points",
                    ha='center', va='bottom', rotation=90)

    # end for 
# ===================================================================================================================================


def plot_bars_names(names, assembly, total_r,  names_colors = [], names_hatches = [],
    special = '', assembly_only = False, solution_only = False,hatches = ["",'/'*4,'.'*4,'*'*4],colors=['C0','C7','C8','C1'],
    filepre = 'figure', save = False, figsize = (10,5), rotation=0, width = 0.3, sep = 0.05, label_hatches = True,
    annotate_middle=False, xlabel="", ylabel="" ):
    
    plt.figure(figsize=figsize)
    
    if type(assembly) is list:

        pos = np.arange(1,len(names)+1)

        nvals = len(assembly)
        total_space = nvals * width + (nvals-1)*sep

        
        strt = (-total_space+width)*.5

        for i in range(nvals):

            prev = np.zeros(len(assembly[i][0]))
            kk = 0
            for bar in assembly[i]:

                block_plt = plt.bar(pos + strt + i*(width+sep) ,bar/total_r, 
                                    bottom = prev,
                                     width=width, 
                                     color=colors[kk],
                                     linewidth = 0.8, hatch=hatches[i])
                prev = prev+bar/total_r
                kk+=1
            # end for
            
            autolabel_top(block_plt)
        # end for 

        legend_elements = []

        for i in range(len(assembly[0])):
            legend_elements.append(Patch(facecolor=colors[i], edgecolor='k',label=names_colors[i]))
        if label_hatches:
            for i in range(nvals):
                legend_elements.append(Patch(facecolor='w', hatch=hatches[i],edgecolor='k',label=names_hatches[i]))
        
        plt.legend(handles = legend_elements, loc='upper left', ncol=4)
        ax = plt.gca() 
        ax.set_xticks(pos)
        ax.set_xticklabels(names)
        plt.xlabel(xlabel)
    
  


    # plt.title("Relative CPU time to real analysis for 1 Million DOFs " + special)
    
    plt.ylabel(ylabel)
    
    plt.xticks(rotation=rotation)
    # plt.axis([None,None,None,22])
    plt.grid(axis='y', color='#CCCCCC')
    plt.minorticks_on()
    plt.grid( color='#EEEEEE',  which='minor', axis='y')
    plt.tight_layout()

    ax = plt.gca()
    ax.set_axisbelow(True)
    # ax.yaxis.set_minor_locator(MultipleLocator(1))
    # ax.yaxis.set_major_locator(MultipleLocator(2))
    ax.xaxis.set_minor_locator(MultipleLocator(1))
    ylims = ax.get_ylim()


    plt.axis([None,None,None,max(4, ylims[-1]*1.35)])

    if save:
        
        filename = filepre
        
        filename += ".pdf"

        plt.savefig(filename, dpi=150)
        
    # end if 

# ===================================================================================================================================


        
def plot_bars(names, assembly, boundary, solution, total_r, 
    special = '', assembly_only = False, solution_only = False,
    filepre = 'figure', save = False, figsize = (10,5), rotation=0,
    annotate_middle=False,xlabel=""):
    
    plt.figure(figsize=figsize)

    hatchs = ["",'/'*4,'.'*4,'*'*4]
    if type(assembly) is list:

        pos = np.arange(1,len(names)+1)

        width = 0.3
        sep = 0.05

        dev = [-(width+sep)/2,(width+sep)/2]

        for i in range(len(assembly)):
            total    = solution[i]+boundary[i]+assembly[i]
            if assembly_only:
                block_plt = plt.bar(pos +dev[i] ,(boundary[i]+assembly[i])/total_r, 
                    width=width, color='C0', linewidth = 0.8, hatch=hatchs[i])
            elif solution_only:

                assem_plt = plt.bar(pos +dev[i], solution[i]/solution[i],
                    width=width, color='C7', linewidth = 0.8, hatch=hatchs[i])
                block_plt = plt.bar(pos +dev[i] ,(solution[i]-total_r)/total_r,bottom=solution[i]/solution[i], 
                    width=width, color='C8', linewidth = 0.8, hatch=hatchs[i])
            else:
                assem_plt = plt.bar(pos +dev[i] ,(boundary[i]+assembly[i])/total_r, 
                    width=width, color='C0', linewidth = 0.8, hatch=hatchs[i])
                block_plt = plt.bar(pos +dev[i] ,solution[i]/total_r,bottom=(boundary[i]+assembly[i])/total_r, 
                    width=width, color='C1', linewidth = 0.8, hatch=hatchs[i])
            # end if 
            
            autolabel_top(block_plt)
        # end for 


        if assembly_only:
            legend_elements = [Patch(facecolor='C0', edgecolor='k',label='Assembly'),
            Patch(facecolor='w', edgecolor='k',label='OTI'),
            Patch(facecolor='w', edgecolor='k',hatch='/'*4,label='Multidual'),
            ]
        elif solution_only:
            legend_elements = [Patch(facecolor='C7', edgecolor='k',label='Sol. $\\mathbf{K}_r\\mathbf{u}_r=\\mathbf{f}_r$'),
            Patch(facecolor='C8', edgecolor='k',label='Sol. $[\\mathbf{u}]^{p}$'),
            Patch(facecolor='w', edgecolor='k',label='OTI'),
            Patch(facecolor='w', edgecolor='k',hatch='/'*4,label='Multidual'),
            ]
        else:
            legend_elements = [Patch(facecolor='C0', edgecolor='k',label='Assembly'),
            Patch(facecolor='C1', edgecolor='k',label='Solution'),
            Patch(facecolor='w', edgecolor='k',label='OTI'),
            Patch(facecolor='w', edgecolor='k',hatch='/'*4,label='Multidual'),
            ]
        # end if 
        plt.legend(handles = legend_elements, loc='upper left', ncol=4)
        ax = plt.gca() 
        ax.set_xticks(pos)
        ax.set_xticklabels(names)
        plt.xlabel(xlabel)

    else:
    
        total    = solution+boundary+assembly

        ncols = 2    
        
        if assembly_only:

            block_plt = plt.bar(names,(boundary+assembly)/total_r,                         width=0.5, label='Assembly')
            ncols =1
        
        elif solution_only:

            block_plt = plt.bar(names,solution/solution,                                    width=0.5, color = 'C7',label='Factor $\\mathbf{K}_r$ and solve $\\mathbf{u}_r$.')
            block_plt = plt.bar(names,(solution-total_r)/total_r, bottom=solution/solution, width=0.5, color = 'C8',label='Solve all $[\\mathbf{u}]^{p}$.')

        else:

            assem_plt = plt.bar(names,(boundary+assembly)/total_r,                         width=0.5, label='Assembly')
            block_plt = plt.bar(names,solution/total_r,bottom=(boundary+assembly)/total_r, width=0.5, label='Solution')

        # end if 

        if annotate_middle:
            autolabel_middle(assem_plt)

        # autolabel(assem_plt)
        # autolabel(block_plt)
        autolabel_top(block_plt)

        plt.legend(loc='upper left', ncol=ncols)


    # plt.title("Relative CPU time to real analysis for 1 Million DOFs " + special)
    if solution_only:
        plt.ylabel("Relative CPU time to real solution.")
    else:
        plt.ylabel("Relative CPU time to real analysis.")
    # end if 
    plt.xticks(rotation=rotation)
    # plt.axis([None,None,None,22])
    plt.grid(axis='y', color='#CCCCCC')
    plt.minorticks_on()
    plt.grid( color='#EEEEEE',  which='minor', axis='y')
    plt.tight_layout()

    ax = plt.gca()
    ax.set_axisbelow(True)
    # ax.yaxis.set_minor_locator(MultipleLocator(1))
    # ax.yaxis.set_major_locator(MultipleLocator(2))
    ax.xaxis.set_minor_locator(MultipleLocator(1))
    ylims = ax.get_ylim()

    ylims
    plt.axis([None,None,None,max(4, ylims[-1]*1.35)])

    if save:
        filename = filepre
        if special is not '':
            filename += "_" + special 
        
        if assembly_only:
            filename += "_assembly"
        elif solution_only:
            filename += "_solution"
        filename += ".pdf"

        # end if 
        plt.savefig(filename, dpi=150)
        # plt.show()
    # end if 

# ===================================================================================================================================



def main():
    for out_dir in outdirs:
        for r,d,f in os.walk(out_dir):

            for item in f:

                name = item.split(".")[0]
                if item.split(".")[-1]!='json':
                    continue
                sections = name.split('_')
                h      = int(sections[-1])
                alg    = sections[-2]
                if 'spr' in sections:
                    alg = 'spr'+alg
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
                    
                    if alg_key == 'sparse':
                        print(alg_key)
                        alg_key = alg
                    #

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
    # end for
# ===================================================================================================================================

def plot_real_cmp(filepre = 'figs/test', figsize=(5,5)):
    
    h = 10
    orders = 10
    nvars  = 10
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
    names         = np.empty(nvars,dtype=object)
    names_full    = np.empty(nvars,dtype=object)
   
    total_ch = assm_time+bc_time+ch_time

    # evaluate order 1:
    res = results_full['sprom0n0'][1]

    assm_times[:]=0
    bc_times[:]=0
    ch_times[:]=0

    l =0
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
        color='C0',width=width)
    block_plt = plt.bar(x_vals-width/2-sep/2,solution/total_r,bottom=(boundary+assembly)/total_r, 
        color='C1',width=width)

    autolabel_top(block_plt)

    idx = np.argsort(names_full[:l2])
    assembly = assm_full_times[idx]
    boundary = bc_full_times[idx]
    solution = ch_full_times[idx]

    total    = solution+boundary+assembly

    assem_plt = plt.bar(x_vals+width/2+sep/2,(boundary+assembly)/total_r,                         
        color='C0', width=width, linewidth=0.8,hatch='/'*4)
    block_plt = plt.bar(x_vals+width/2+sep/2,solution/total_r,bottom=(boundary+assembly)/total_r, 
        color='C1', width=width, linewidth=0.8,hatch='/'*4)
    
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
    # ax.yaxis.set_minor_locator(MultipleLocator(2))
    # ax.yaxis.set_major_locator(MultipleLocator(10))
    # ax.xaxis.set_minor_locator(MultipleLocator(1))
    
    filename = filepre + '.pdf' 
    
    plt.savefig(filename, dpi=150)
    
# ==================================================================================================================

def compare_with_multidual_order(mmin, mmax, n,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names):
    
    total_r = assm_time + bc_time + ch_time

    md_assm_times_fix = np.zeros(mmax-mmin+1)
    md_bc_times_fix   = np.zeros(mmax-mmin+1)
    md_ch_times_fix   = np.zeros(mmax-mmin+1)
    md_su_times_fix   = np.zeros(mmax-mmin+1)
    
    name_vals = []
    
    # Compute mdual times
    for m in range(mmin,mmax+1):
        n_p_deriv = helper.get_ndir_order(m,n)
        md_assm_times_fix[m-mmin] = md_assm_times[n]*n_p_deriv
        md_bc_times_fix[m-mmin]   = md_bc_times[n]*n_p_deriv
        md_ch_times_fix[m-mmin] = ch_time + (md_ch_times[n]-ch_time)*n_p_deriv
        md_su_times_fix[m-mmin] = su_time + (md_su_times[n]-su_time)*n_p_deriv
        name_vals.append(str(m))

    filename = 'figs/figure_'+eltype+'_total_otimdual_n'+str(n)
    print(name_vals)
    total_r = assm_time + bc_time + ch_time
    plot_bars(name_vals, [assm_times[n-1,mmin-1:mmax],md_assm_times_fix], 
        [bc_times[n-1,mmin-1:mmax],md_bc_times_fix], [ch_times[n-1,mmin-1:mmax],md_ch_times_fix], total_r, 
        figsize=(7,4), special = 'Cholesky',  filepre = filename, save=True,
        xlabel="Number of variables")

    total_r = assm_time + bc_time + su_time
    plot_bars(name_vals, [assm_times[n-1,mmin-1:mmax],md_assm_times_fix], 
        [bc_times[n-1,mmin-1:mmax],md_bc_times_fix], [su_times[n-1,mmin-1:mmax],md_su_times_fix], total_r, 
        figsize=(7,4), special = 'SuperLU',  filepre = filename, save=True,
        xlabel="Number of variables")

    total_r = assm_time + bc_time 
    plot_bars(name_vals, [assm_times[n-1,mmin-1:mmax],md_assm_times_fix], 
        [bc_times[n-1,mmin-1:mmax],md_bc_times_fix], [su_times[n-1,mmin-1:mmax],md_su_times_fix], total_r, 
        figsize=(7,4), assembly_only=True, filepre = filename, save=True,
        xlabel="Number of variables")

    total_r = ch_time 
    plot_bars(name_vals, [assm_times[n-1,mmin-1:mmax],md_assm_times_fix], 
        [bc_times[n-1,mmin-1:mmax],md_bc_times_fix], [ch_times[n-1,mmin-1:mmax],md_ch_times_fix], total_r, 
        figsize=(7,4), solution_only=True, special = 'Cholesky',  filepre = filename, save=True,
        xlabel="Number of variables")

    total_r = su_time 
    plot_bars(name_vals, [assm_times[n-1,mmin-1:mmax],md_assm_times_fix], 
        [bc_times[n-1,mmin-1:mmax],md_bc_times_fix], [su_times[n-1,mmin-1:mmax],md_su_times_fix], total_r, 
        figsize=(7,4), solution_only=True, special = 'SuperLU',  filepre = filename, save=True,
        xlabel="Number of variables")










def compare_with_multidual(m, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names):
    total_r = assm_time + bc_time + ch_time

    
    md_assm_times_fix = md_assm_times[1:nmax+1].copy()
    md_bc_times_fix   = md_bc_times[1:nmax+1].copy()
    md_ch_times_fix   = md_ch_times[1:nmax+1].copy()
    md_su_times_fix   = md_su_times[1:nmax+1].copy()
    name_vals = []

    # Compute mdual times
    for p in range(1,nmax+1):
        n_p_deriv = helper.get_ndir_order(m,p)
        md_assm_times_fix[p-1]*=n_p_deriv
        md_bc_times_fix[p-1]  *= n_p_deriv
        md_ch_times_fix[p-1] = ch_time + (md_ch_times_fix[p-1]-ch_time)*n_p_deriv
        md_su_times_fix[p-1] = su_time + (md_su_times_fix[p-1]-su_time)*n_p_deriv
        name_vals.append(str(p))


    print("-------->",m,md_assm_times_fix[0], md_assm_times[1])
    filename = 'figs/figure_'+eltype+'_total_otimdual_m'+str(m)
    print(name_vals)
    
    plot_bars(name_vals, [assm_times[:nmax,m-1],md_assm_times_fix], 
        [bc_times[:nmax,m-1],md_bc_times_fix], [ch_times[:nmax,m-1],md_ch_times_fix], total_r, 
        figsize=(7,4), special = 'Cholesky',  filepre = filename, save=True,
        xlabel="Order of derivative")

    total_r = assm_time + bc_time + su_time
    plot_bars(name_vals, [assm_times[:nmax,m-1],md_assm_times_fix], 
        [bc_times[:nmax,m-1],md_bc_times_fix], [su_times[:nmax,m-1],md_su_times_fix], total_r, 
        figsize=(7,4), special = 'SuperLU',  filepre = filename, save=True,
        xlabel="Order of derivative")

    total_r = assm_time + bc_time 
    plot_bars(name_vals, [assm_times[:nmax,m-1],md_assm_times_fix], 
        [bc_times[:nmax,m-1],md_bc_times_fix], [su_times[:nmax,m-1],md_su_times_fix], total_r, 
        figsize=(7,4), assembly_only=True, filepre = filename, save=True,
        xlabel="Order of derivative")

    total_r = ch_time 
    plot_bars(name_vals, [assm_times[:nmax,m-1],md_assm_times_fix], 
        [bc_times[:nmax,m-1],md_bc_times_fix], [ch_times[:nmax,m-1],md_ch_times_fix], total_r, 
        figsize=(7,4), solution_only=True, special = 'Cholesky',  filepre = filename, save=True,
        xlabel="Order of derivative")

    total_r = su_time 
    plot_bars(name_vals, [assm_times[:nmax,m-1],md_assm_times_fix], 
        [bc_times[:nmax,m-1],md_bc_times_fix], [su_times[:nmax,m-1],md_su_times_fix], total_r, 
        figsize=(7,4), solution_only=True, special = 'SuperLU',  filepre = filename, save=True,
        xlabel="Order of derivative")

if __name__ == "__main__":

    main()
    
    h = 10
    orders = 10
    nvars  = 10
    eltype = 'tri6'
    results = results_full[eltype]

    mesh_time     = results['real'][h]["mesh"]
    assm_time     = results['real'][h]["assembly"]
    bc_time       = results['real'][h]["boundary"]

    ch_time       = results['real'][h]["cholesky"]
    su_time       = results['real'][h]["superlu"]
    um_time       = results['real'][h]["umfpack"]

    # print(results.keys())
    sp_mesh_time     = results['sprom0n0'][h]["mesh"]
    sp_assm_time     = results['sprom0n0'][h]["assembly"]
    sp_bc_time       = results['sprom0n0'][h]["boundary"]

    sp_ch_time       = results['sprom0n0'][h]["cholesky"]
    sp_su_time       = results['sprom0n0'][h]["superlu"]
    sp_um_time       = results['sprom0n0'][h]["umfpack"]

    mesh_times    = np.zeros((orders,nvars))
    assm_times    = np.zeros((orders,nvars))
    bc_times      = np.zeros((orders,nvars))

    ch_times      = np.zeros((orders,nvars))
    su_times      = np.zeros((orders,nvars))
    um_times      = np.zeros((orders,nvars))

    totals_ch     = np.zeros((orders,nvars))
    totals_su     = np.zeros((orders,nvars))
    totals_um     = np.zeros((orders,nvars))

    spr_mesh_times    = np.zeros((orders,nvars))
    spr_assm_times    = np.zeros((orders,nvars))
    spr_bc_times      = np.zeros((orders,nvars))

    spr_ch_times      = np.zeros((orders,nvars))
    spr_su_times      = np.zeros((orders,nvars))
    spr_um_times      = np.zeros((orders,nvars))

    spr_totals_ch     = np.zeros((orders,nvars))
    spr_totals_su     = np.zeros((orders,nvars))
    spr_totals_um     = np.zeros((orders,nvars))

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

                key = 'sprom'+str(m)+'n'+str(n)

                if key in results.keys():
                    times = results[key][h]
                    
                    spr_mesh_times[n-1,m-1] = times["mesh"]
                    spr_assm_times[n-1,m-1] = times["assembly"]
                    spr_bc_times[  n-1,m-1] = times["boundary"]

                    spr_ch_times[n-1,m-1] = times["cholesky"]
                    spr_su_times[n-1,m-1] = times["superlu"]
                    spr_um_times[n-1,m-1] = times["umfpack"]

                    # names[n-1,m-1] = '$\\mathbb{{OTI}}^{{{0}}}_{{{1}}}$'.format(n,m)#'om'+str(m)+'n'+str(n)
                else:
                    spr_mesh_times[n-1,m-1] = np.nan
                    spr_assm_times[n-1,m-1] = np.nan
                    spr_bc_times[  n-1,m-1] = np.nan
                    spr_ch_times[n-1,m-1] = np.nan
                    spr_su_times[n-1,m-1] = np.nan
                    spr_um_times[n-1,m-1] = np.nan
                    # names[n-1,m-1] = '$\\mathbb{{OTI}}^{{{0}}}_{{{1}}}$'.format(n,m)#'om'+str(m)+'n'+str(n)  
                
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


    print(su_time,md_su_times[0],md_su_times[1])
    su_time = min(su_time,md_su_times[0]) # For consistency

    real_cmp_mesh = np.array([mesh_time, md_mesh_times[0] , sp_mesh_time ])
    real_cmp_assm = np.array([assm_time, md_assm_times[0] , sp_assm_time ])
    real_cmp_bc   = np.array([bc_time  , md_bc_times[0]   , sp_bc_time   ])
    real_cmp_ch   = np.array([ch_time  , md_ch_times[0]   , sp_ch_time   ])
    real_cmp_su   = np.array([su_time  , md_su_times[0]   , sp_su_time   ])
    real_cmp_names= np.array(["Real", "Static Dense", "Sparse"])
    
    

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
    
    if eltype is 'tri3':
        nmax=4
    else:
        nmax = 10

    n = 2
    total_r = assm_time + bc_time + ch_time
    print("REAL STATS: Assm:{0:.3f} chol:{1:.3f} Tot_chol:{2:.3f} SLU:{3:.3f} SLUtot:{4:.3f}".format(assm_time + bc_time ,ch_time,assm_time + bc_time +ch_time, su_time, assm_time + bc_time +su_time))
    # for n in range(1,orders+1):
    filename = 'figs/figure_'+eltype+'_total_real'
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_ch, total_r, annotate_middle=False,
        figsize=(7,4),special = 'Cholesky', filepre = filename, save=True)

    total_r = assm_time + bc_time + su_time
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_su, total_r, annotate_middle=False,
        figsize=(7,4),special = 'SuperLU', filepre = filename, save=True)


    total_r = assm_time + bc_time 
    plot_bars(real_cmp_names, real_cmp_assm, 
        real_cmp_bc, real_cmp_ch, total_r, 
        figsize=(7,4), assembly_only=True, filepre = filename, save=True)



    bars = [ [real_cmp_assm + real_cmp_bc,real_cmp_ch ],
             # [real_cmp_assm + 100*real_cmp_bc,real_cmp_ch ],
    ]

    total_r = assm_time + bc_time + ch_time    
    plot_bars_names(real_cmp_names, bars, total_r, names_colors = ['Assm','Fact','Sol'], names_hatches = ['Real'],
        hatches = ["",'/'*4,'.'*4,'*'*4], colors=['C0','C8','C1'], width = 0.5, label_hatches =False,
        filepre = 'figs/figure_test_reals_Cholesky', save = True, figsize = (7,4), 
        annotate_middle=False, xlabel="", ylabel="Relative CPU time to real Analysis" )

    bars = [ [real_cmp_assm + real_cmp_bc,real_cmp_su ],
             # [real_cmp_assm + 100*real_cmp_bc,real_cmp_ch ],
    ]

    total_r = assm_time + bc_time + su_time    
    plot_bars_names(real_cmp_names, bars, total_r, names_colors = ['Assm','Fact','Sol'], names_hatches = ['Real'],
        hatches = ["",'/'*4,'.'*4,'*'*4], colors=['C0','C8','C1'], width = 0.5, label_hatches =False,
        filepre = 'figs/figure_test_reals_SuperLU', save = True, figsize = (7,4), 
        annotate_middle=False, xlabel="", ylabel="Relative CPU time to real Analysis" )



    # order_names = []
    # nvar_names  = []

    # for i in range(orders):
    #     order_names.append(str(i+1))

    # for i in range(nvars):
    #     nvar_names.append(str(i+1))
    

    # m=1

    # nmax = 10


    # md_assm_times_fix = md_assm_times[1:nmax+1].copy()
    # md_bc_times_fix   = md_bc_times[1:nmax+1].copy()
    # md_ch_times_fix   = md_ch_times[1:nmax+1].copy()
    # md_su_times_fix   = md_su_times[1:nmax+1].copy()
    # name_vals = []

    # # Compute mdual times
    # for p in range(1,nmax+1):
    #     n_p_deriv = helper.get_ndir_order(m,p)
    #     md_assm_times_fix[p-1]*=n_p_deriv
    #     md_bc_times_fix[p-1]  *= n_p_deriv
    #     md_ch_times_fix[p-1] = ch_time + (md_ch_times_fix[p-1]-ch_time)*n_p_deriv
    #     md_su_times_fix[p-1] = su_time + (md_su_times_fix[p-1]-su_time)*n_p_deriv
    #     name_vals.append(str(p))

    # bars = [ [assm_times[:,m-1]     + bc_times[:,m-1],     su_time*su_times[:,m-1]    /su_times[:,m-1],     su_times[:,m-1]    -su_time ],
    #          [spr_assm_times[:,m-1] + spr_bc_times[:,m-1], su_time*spr_su_times[:,m-1]/spr_su_times[:,m-1], spr_su_times[:,m-1]-su_time ],
    #          [md_assm_times_fix     + md_bc_times_fix   ,  su_time*md_su_times_fix    /md_su_times_fix   ,  md_su_times_fix    -su_time ],
    # ]
    # total_r = assm_time + bc_time + su_time    
    # plot_bars_names(order_names, bars, total_r, names_colors = ['Assm','Fact','Sol'], names_hatches = ['D. OTI','Spr. OTI','Multidual'],
    #     hatches = ["",'/'*4,'.'*4,'*'*4], colors=['C0','C8','C1'], width = 0.25,
    #     filepre = 'figs/figure_test_m'+str(m)+'_SuperLU', save = True, figsize = (7,4), 
    #     annotate_middle=False, xlabel="Order of derivative.", ylabel="Relative CPU time to real Analysis" )

    # bars = [ [assm_times[:,m-1]     + bc_times[:,m-1],     ch_time*ch_times[:,m-1]    /ch_times[:,m-1],     ch_times[:,m-1]    -ch_time ],
    #          [spr_assm_times[:,m-1] + spr_bc_times[:,m-1], ch_time*spr_ch_times[:,m-1]/spr_ch_times[:,m-1], spr_ch_times[:,m-1]-ch_time ],
    #          [md_assm_times_fix     + md_bc_times_fix   ,  ch_time*md_ch_times_fix    /md_ch_times_fix   ,  md_ch_times_fix   -ch_time ],
    # ]
    # total_r = assm_time + bc_time + ch_time    
    # plot_bars_names(order_names, bars, total_r, names_colors = ['Assm','Fact','Sol'], names_hatches = ['D. OTI','Spr. OTI','Multidual'],
    #     hatches = ["",'/'*4,'.'*4,'*'*4], colors=['C0','C8','C1'], width = 0.25,
    #     filepre = 'figs/figure_test_m'+str(m)+'_Cholesky', save = True, figsize = (7,4), 
    #     annotate_middle=False, xlabel="Order of derivative.", ylabel="Relative CPU time to real Analysis" )

    # mmin = 3
    # mmax = 10
    # n=2

    # md_assm_times_fix = np.zeros(mmax-mmin+1)
    # md_bc_times_fix   = np.zeros(mmax-mmin+1)
    # md_ch_times_fix   = np.zeros(mmax-mmin+1)
    # md_su_times_fix   = np.zeros(mmax-mmin+1)
    
    # name_vals = []
    
    # # Compute mdual times
    # for m in range(mmin,mmax+1):
    #     n_p_deriv = helper.get_ndir_order(m,n)
    #     md_assm_times_fix[m-mmin] = md_assm_times[n]*n_p_deriv
    #     md_bc_times_fix[m-mmin]   = md_bc_times[n]*n_p_deriv
    #     md_ch_times_fix[m-mmin] = ch_time + (md_ch_times[n]-ch_time)*n_p_deriv
    #     md_su_times_fix[m-mmin] = su_time + (md_su_times[n]-su_time)*n_p_deriv
    #     name_vals.append(str(m))


    # bars = [ [assm_times[n-1,mmin-1:mmax]     + bc_times[n-1,mmin-1:mmax],     su_time*su_times[n-1,mmin-1:mmax]    /su_times[n-1,mmin-1:mmax],     su_times[n-1,mmin-1:mmax]    -su_time ],
    #          [spr_assm_times[n-1,mmin-1:mmax] + spr_bc_times[n-1,mmin-1:mmax], su_time*spr_su_times[n-1,mmin-1:mmax]/spr_su_times[n-1,mmin-1:mmax], spr_su_times[n-1,mmin-1:mmax]-su_time ],
    #          [md_assm_times_fix     + md_bc_times_fix   ,  su_time*md_su_times_fix    /md_su_times_fix   ,  md_su_times_fix    -su_time ],
    # ]
    # total_r = assm_time + bc_time + su_time
    # plot_bars_names(name_vals, bars, total_r, names_colors = ['Assm.','Fact.','Sol.'], names_hatches = ['D. OTI','Spr. OTI','Multidual'],
    #     hatches = ["",'/'*4,'.'*4,'*'*4], colors=['C0','C8','C1'], width = 0.25,
    #     filepre = 'figs/figure_test_n'+str(n)+'_SuperLU', save = True, figsize = (7,4), 
    #     annotate_middle=False, xlabel="Number of Variables.", ylabel="Relative CPU time to real analysis" )

    # bars = [ [assm_times[n-1,mmin-1:mmax]     + bc_times[n-1,mmin-1:mmax],     ch_time*ch_times[n-1,mmin-1:mmax]    /ch_times[n-1,mmin-1:mmax],     ch_times[n-1,mmin-1:mmax]    -ch_time ],
    #          [spr_assm_times[n-1,mmin-1:mmax] + spr_bc_times[n-1,mmin-1:mmax], ch_time*spr_ch_times[n-1,mmin-1:mmax]/spr_ch_times[n-1,mmin-1:mmax], spr_ch_times[n-1,mmin-1:mmax]-ch_time ],
    #          [md_assm_times_fix     + md_bc_times_fix   ,  ch_time*md_ch_times_fix    /md_ch_times_fix   ,  md_ch_times_fix    -ch_time ],
    # ]
    # total_r = assm_time + bc_time + ch_time
    # plot_bars_names(name_vals, bars, total_r, names_colors = ['Assem.','Fact.','Sol.'], names_hatches = ['D. OTI','Spr. OTI','Multidual'],
    #     hatches = ["",'/'*4,'.'*4,'*'*4], colors=['C0','C8','C1'], width = 0.25,
    #     filepre = 'figs/figure_test_n'+str(n)+'_Cholesky', save = True, figsize = (7,4), 
    #     annotate_middle=False, xlabel="Number of Variables.", ylabel="Relative CPU time to real analysis" )



























    # # m=1
    # compare_with_multidual_order(3,10, 1,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)
    # compare_with_multidual_order(3,10, 2,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)



    # compare_with_multidual(1, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)
    # compare_with_multidual(2, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)
    

    # if eltype is 'tri3':
    #     nmax=4
    #     compare_with_multidual(3, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)
    #     compare_with_multidual(4, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)
    # else:

    #     nmax = 2
    #     compare_with_multidual(3, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)
    #     compare_with_multidual(4, nmax,  assm_time,  bc_time,  ch_time,md_assm_times, md_bc_times, md_ch_times, md_su_times, assm_times, bc_times, ch_times, names)

    # # plt.show()

# end if 



