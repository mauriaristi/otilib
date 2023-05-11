

FC = ifort

FCFLAGS = -O3 -fopenmp
LCFLAGS = -I../sparse/ -L../sparse/ -lsparse_oti
LCFLAGS += -I../core/ -L../core/ -lreal_utils -lmaster_parameters


all: otilib main


clean:
	+$(MAKE) clean -C ../core/ 
	+$(MAKE) clean -C ../sparse/
	rm *.exe

otilib:
	+$(MAKE) -C ../core/ 
	+$(MAKE) -C ../sparse/


otilibfort:
	+$(MAKE) -C ../core/ gfortran
	+$(MAKE) -C ../sparse/ gfortran

changegfortran:
	$(eval FC = gfortran)

gfortran: staticfort changegfortran main

main:
	$(FC) test.f90 -o test.exe $(FCFLAGS) $(LCFLAGS)