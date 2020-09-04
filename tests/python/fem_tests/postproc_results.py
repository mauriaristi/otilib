import os
import sys
import json
import numpy as np

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
            print("--- Found "+alg+" with h: "+str(h))

            f = open(os.join(r,item))
            res_dict = json.load(f)
            f.close()

            

            for val in res_dict.values():
                keys = val.keys()
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
                mesh_time = np.average(res['mesh'])
                assm_time = np.average(res['assembly'])
                bound_time = np.average(res['boundary'])
                ch_time = np.average(res['sol_cholesky'])
                su_time = np.average(res['sol_superlu'])
                um_time = np.average(res['sol_umfpack'])
                
                mem_bf_mesh = np.array(res['mem_bf_mesh'])
                mem_af_mesh = np.array(res['mem_aft_mesh'])
                
                mem_bf_creation = np.array(res['mem_bf_creation'])
                mem_af_creation = np.array(res['mem_aft_creation'])
                
                mem_af_assm = np.array('mem_aft_assembly')
                
                results[alg_key][h]={}

                results[alg_key][h]={}
            break
        # end for
        break 
    # end for

#

if __name__ == "__main__":
    main()
# end if 