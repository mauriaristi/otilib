# =================================================================== #
# -------------- Generate Precomputed data for OTIlib. -------------- #
# =================================================================== #
#                                                                     #
# Generate the direction and exponent arrays and all necessary data   #
# that OTIlib requires for its standard operation.                    #
#                                                                     #
# The data is usable for any implementation: C, Python, fortran, etc. #
#                                                                     #
# This file focuses on generating the pre-computed data that serves   #
# to the OTI library. Particularly this library focuses on computing  #
# the following elements:                                             #
#                                                                     #
#   - Partition Sets for all (defined) orders and                     #
#   - Direction and Exponent arrays for all possible orders and       #
#     number of variables.                                            #
#                                                                     #
# For this, we'll need to load a combinatorics library from scipy,    #
# partition from partitionsets and numpy.                             #
#                                                                     #
# Author: Mauricio Aristizabal Cano                                   #
# Date:   October 1 / 2018                                            #
# Date last modified: October 1 / 2018                                #
# version: 0.9                                                        #
# =================================================================== #



# =================================================================== #
# ---------------------- IMPORT REQUIRED LIBRARIES. ----------------- #
# =================================================================== #
from   partitionsets import partition
import numpy         as     np
from   scipy.special import comb
# =================================================================== #

# =================================================================== #
# ----------------------- GENERATE PARTITION SETS. ------------------ #
# =================================================================== #

# ------------------------------------------------------------------- #
# --> gen_PartSets(maxorder, outDir)                                  #
#                                                                     #
#     This function generates the partition set matrices that are     #
#     required for function evaluation of dense OTI numbers, based on #
#     the Faa di Bruno approach.                                      #
#                                                                     #
# INPUTS:                                                             #
#                                                                     #
#     - maxorder: < uint8 >  Define the maximum order to compute the  #
#                            partition sets matrices. Minimum         #
#                            maxorder = 1.                            #
#                                                                     #
#     - outDir:   < string > Defines the directory where data is to   #
#                            be exported.                             #
#                                                                     #
# ------------------------------------------------------------------- #
def gen_PartSets(maxorder, outDir):

  print("=============== GENERATE PARTITION SETS =================")
  print("Generating partition set matrix for up to order "+str(maxorder))
  print("into folder "+outDir+"/")
  print()

  for order in range(1,maxorder+1):

    # Create the elements array
    # Holds up to 15 elements due to uint16...
    els =np.array(list(range(0,order)),dtype=np.uint16)


    # Generate the partition sets.
    parts = list(partition.Partition(els))

    # Generate the associated values. Here is where it matters to have 
    # 16, 32 or 64 bits.
    values = np.power(np.uint16(2),els)
    # print(els)
    # print(values)
    numels = len(parts)
    

    # create the Array to store the values of the partition information:
    A = np.zeros((len(parts),order),dtype = np.uint16)

    print("Generating matrix of ",numels," partitions of order ", order)
    # Travel all partition sets and store them in memor
    for k in range(len(parts)):#part in parts:
        
        part = parts[k]      
        
        for j in range(len(part)):#subset in part:
            
            subset = part[j]
            
            for i in range(len(subset)):
                
                A[k,j] +=values[subset[i]]
            
            # end for
            
        # end for 
        
    # end for 

    # Save the array:
    filename = outDir+"/part_n"+str(order)
    print("Saving file << ",filename,".npy >> \n")
    np.save(filename,A)

  # end for 
  print("======================= FINISHED ======================")
# ------------------------------------------------------------------- #
# =================================================================== #




# =================================================================== #
# --------------------- GENERATE DIR & EXP ARRAYS. ------------------ #
# =================================================================== #


def gen_DirExp_Arrays(ndirs,outDir):
  print("\n======= GENERATE EXPONENT AND DIRECTION ARRAYS ========")
  print("Generating direction and exponent arrays for "+str(ndirs))
  print("into folder "+outDir+"/")
  print()

  for i in range(len(ndirs)):
    ndir = ndirs[i]
    maxorder = int(i+1)
    maxIter = comb(maxorder+ndir,ndir,exact=True)-1

    print("\nPreparing to generate <",maxIter,"> directions for order ",maxorder," and ",ndir," pure directions")
    dirArray = np.zeros((maxIter,maxorder),dtype = np.uint16)
    expArray = np.zeros((maxIter,maxorder),dtype = np.uint8)
    print("Expected File Sizes: dir:",str(dirArray.nbytes/(1024**2))," MB  exp: ",str(expArray.nbytes/(1024**2))," MB")
    
    multiple = np.zeros(ndir,dtype = np.uint16)


    dirAr = np.zeros(maxorder,dtype = np.uint16)
    expAr = np.zeros(maxorder,dtype = np.uint8)

    pos = -1
    dirMax = 1
    diri = 1
    expi = 0
    newDir = 0
    niterPrint = 500000

    for i in range(maxIter): #maxIter-1
        
        if i%niterPrint==0:
            print("Computing direction ",i, "of ",maxIter)
        oldOrder = np.sum(expAr)


        if expi == maxorder:

            diri += 1
            expi  = 1
            
        elif oldOrder == maxorder:

            if diri+1 == dirAr[pos+1]:
                
                dirAr[pos] = 0
                expAr[pos] = 0
                pos += 1
                diri = dirAr[pos]
                expi = expAr[pos]+1
            
            else:
                
                diri += 1
                expi  = 1
                
            # end if

        else:

            # if move left is possible, it will
            if diri != 1 and abs(pos-1) <= maxorder:
                
                # moving left.
                pos -= 1
                diri = 1
                expi = 1

            else:
                
                expi += 1
            
            # end if 
            
        # end if 
        dirAr[pos] = diri
        expAr[pos] = expi
        
        nonZ, = np.nonzero(dirAr) 
        
        for k in range(nonZ.size):
            dirArray[i,k] = dirAr[nonZ[k]]
            expArray[i,k] = expAr[nonZ[k]]
        
        #print(dirArray[i,:]," - ",expArray[i,:])

    print("Finished computing ",maxIter, " directions.")
    print("Saving the generated data in files")
    np.save(outDir+'/dir_n'+str(maxorder)+'_m'+str(ndir),dirArray)
    np.save(outDir+'/exp_n'+str(maxorder)+'_m'+str(ndir),expArray)

  # end for 

  print("======================= FINISHED ======================")

# end function
# =================================================================== #




# =================================================================== #
# ----------------------- GENERATE COUNT ARRAYS. -------------------- #
# =================================================================== #


def gen_Count_Arrays(ndirs,outDir):
  print("\n======= GENERATE COUNT ARRAYS ========")
  print("Generating count arrays for "+str(ndirs))
  print("into folder "+outDir+"/")
  print()
  for i in range( len(ndirs) ):
    m_max = ndirs[i]
    maxorder = int(i+1)
    count = np.empty(m_max+1,dtype = np.uint64)
    count[0] = 1
    for m in range(1,m_max +1):
        count[m] = comb(maxorder+m,m,exact=True)
    # end for 

    # Save the file
    print("\nSaving count array for order "+str(maxorder) + " and "
      +str(m)+' dirs')
    np.save(outDir+'/count_n'+str(maxorder)+'_m'+str(m),count)

  # end for 

  print("\n======================= FINISHED ======================")

# end function


# =================================================================== #


outDir='data'

ndirs = [20,20,20]
maxorder = len(ndirs)


gen_PartSets(maxorder,outDir)
gen_DirExp_Arrays(ndirs,outDir)
gen_Count_Arrays(ndirs,outDir)
