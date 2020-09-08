#!/bin/bash


# Base variables
BASEN=real
THISDIR=$(dirname "$(readlink -f "$0")")
# SOLVERS="umfpack cholesky SuperLU"

# for HIDX in 1 2 3 4 5 6 7 8 9 10
for HIDX in 10
do
	# for SOLVER in $SOLVERS
	# do

		JOBOUT=result_xps_real

		echo -e "\nSetting up and run at $JOBOUT."

		# Run simulation.
		# python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} --real --export ${JOBOUT} --solver ${SOLVER}
		python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} --real --export ${JOBOUT}

	# done

done
# for ATYPE in bs2


# Messages
# abaqus cae noGUI=Python_Extract_Solution.py
# echo -e "\nSimulation running. To check status, use the command:"
# echo -e "tail -f $JOBNAME.log\n"
