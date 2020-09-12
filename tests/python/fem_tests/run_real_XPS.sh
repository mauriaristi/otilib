#!/bin/bash


# Base variables
BASEN=real
THISDIR=$(dirname "$(readlink -f "$0")")

for HIDX in 10
do
	JOBOUT=result_xps_tri3_real

	echo -e "\nSetting up and run at $JOBOUT."

	# Run simulation.
	python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} --real --export ${JOBOUT} --elorder 1

done

for HIDX in 10
do
	JOBOUT=result_xps_tri6_real

	echo -e "\nSetting up and run at $JOBOUT."

	# Run simulation.
	python3.7 test_2d_cylinder_performance_XPS.py -h ${HIDX} --real --export ${JOBOUT} --elorder 2

done