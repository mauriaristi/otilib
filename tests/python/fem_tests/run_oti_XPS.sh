#!/bin/bash


# Base variables
BASEN=real
THISDIR=$(dirname "$(readlink -f "$0")")
SOLVER="cholesky"

# for HIDX in 1 2 3 4 5 6 7 8 9
for HIDX in 0 1 2 3 4 5 6 7 8 9 10
do
	for ORDER in 1 
	do

		# for NVAR in 1 2 3 4
		for NVAR in 1 2 3 4 5 6 7 8 9 10
		do

			JOBDIR=${THISDIR}
			JOBOUT=result_xps_om${NVAR}n${ORDER}

			echo -e "\nSetting up and run at $JOBDIR."

			# Remove previous results with same name.
			# rm $JOBNAME.*
			# Run simulation.
			python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} -n ${ORDER} -m ${NVAR} --export ${JOBOUT} --solver ${SOLVER}

			# cd $THISDIR


		done

	done

done
# for ATYPE in bs2


# Messages
# abaqus cae noGUI=Python_Extract_Solution.py
# echo -e "\nSimulation running. To check status, use the command:"
# echo -e "tail -f $JOBNAME.log\n"
