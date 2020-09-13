#!/bin/bash

# Base variables
BASEN=real
THISDIR=$(dirname "$(readlink -f "$0")")
SOLVER="cholesky"

for HIDX in 10
do
	for ORDER in 6 7 8
	do

		JOBDIR=${THISDIR}
		JOBOUT=result_xps_tri3_mdual${ORDER}

		echo -e "\nSetting up and run at $JOBDIR."

		# Run simulation.
		python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} -n ${ORDER}  --export ${JOBOUT} --solver ${SOLVER} --mdual --elorder 1

		# cd $THISDIR



	done

done

for HIDX in 10
do
	for ORDER in 6 
	do

		JOBDIR=${THISDIR}
		JOBOUT=result_xps_tri6_mdual${ORDER}

		echo -e "\nSetting up and run at $JOBDIR."

		# Run simulation.
		python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} -n ${ORDER}  --export ${JOBOUT} --solver ${SOLVER} --mdual --elorder 2

	done

done
