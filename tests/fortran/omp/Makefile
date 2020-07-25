
IFC = ifort
GFC = gfortran

IFORTFLAGS = -warn
GFORTFLAGS = -Wall -ffree-line-length-1024 -O3 -fopenmp
FORTFLAGSDEBUG = -g
M = 5
N = 10
KEYWORD_TYPE = OTI_TYPE
KEYWORD_MOD = OTI_MOD
OTI_TYPE = ONUMM$(M)N$(N)
OTI_MOD = otim$(M)n$(N)


all: gnu


gnu: 
	gfortran -o test omp_helloworld.f90 -fopenmp -O3