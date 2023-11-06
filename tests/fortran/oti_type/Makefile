
# Set gfortran or ifort to compile
FC = ifort # Default compiler

# Flags:
#   -O3: Optimization level 3 for best performance.
#   -fPIC: For shared library.
#   -fopenmp: For compatibility with parallel calls from Abaqus and others.
# FCFLAGS = -O2 -fPIC -fopenmp -fpconstant  -init=snan,arrays -traceback -fpe0
FCFLAGS = -O2 -fPIC -fopenmp 


SOURCES = master_parameters.f90 real_utils.f90 otistamod.f90 

all: $(subst .f90,.mod, $(SOURCES))

# %.mod: %.f90
	
# 	$(FC) -c $< $(FCFLAGS) 
# 	ar rc lib$*.a $*.o
# 	ranlib lib$*.a

otistamod.mod: otistamod.f90 master_parameters.mod real_utils.mod
	$(FC) -c $*.f90 $(FCFLAGS) -lmaster_parameters -lreal_utils
	ar rc lib$*.a $*.o master_parameters.o real_utils.o
	ranlib lib$*.a

master_parameters.mod: master_parameters.f90
	$(FC) -c $*.f90 $(FCFLAGS) 
	ar rc lib$*.a $*.o
	ranlib lib$*.a

real_utils.mod: real_utils.f90 master_parameters.mod 
	$(FC) -c $*.f90 $(FCFLAGS) -L. -lmaster_parameters
	ar rc lib$*.a $*.o master_parameters.o
	ranlib lib$*.a

changegfortran:
	$(eval FC = gfortran)

gfortran: changegfortran $(subst .f90,.mod, $(SOURCES))

clean:
	-rm -f *.o *.mod *.a
