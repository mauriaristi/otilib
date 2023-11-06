
# Set gfortran or ifort to compile
# FC = ifort
FC = ifx # Default compiler

# Flags:
#   -O3: Optimization level 3 for best performance. O2 for great perf. with more robustness.
#   -fPIC: For shared library.
#   -fopenmp: For compatibility with parallel calls from Abaqus and others.
FCFLAGS = -O3 -fPIC -fopenmp

# Define the sources that will be compiled
SOURCES =  otim1n1.f90
# SOURCES =  otim1n1.f90 otim1n2.f90 otim1n3.f90 otim1n4.f90
# SOURCES += otim2n1.f90 otim2n2.f90 otim2n3.f90 otim2n4.f90
# SOURCES += otim3n1.f90 otim3n2.f90 otim3n3.f90 otim3n4.f90
# SOURCES += otim4n1.f90 otim4n2.f90 otim4n3.f90 otim4n4.f90


all: $(subst .f90,.mod, $(SOURCES))




master_parameters.mod: master_parameters.f90
	$(FC) -c $*.f90 $(FCFLAGS) 
	ar rc lib$*.a $*.o
	ranlib lib$*.a

real_utils.mod: real_utils.f90 master_parameters.mod 
	$(FC) -c $*.f90 $(FCFLAGS) -L. -lmaster_parameters
	ar rc lib$*.a $*.o master_parameters.o
	ranlib lib$*.a


# ==============================================================================
%.mod: %.f90 $(subst oti, cwrap,%).f90 master_parameters.mod real_utils.mod

	$(FC) -c $< $(FCFLAGS) -lmaster_parameters -lreal_utils
	ar rc lib$*.a $*.o master_parameters.o real_utils.o
	ranlib lib$*.a

	$(FC) -c $(subst oti,cwrap,$<) $(FCFLAGS) -lmaster_parameters -lreal_utils -l$*
	ar rc lib$(subst oti,cwrap,$*).a $(subst oti,cwrap,$*).o master_parameters.o real_utils.o $*.o
	ranlib lib$(subst oti,cwrap,$*).a

# ==============================================================================

# ==============================================================================
# Change the Intel Fortran Compiler (default) to gfortran.
# ==============================================================================
changegfortran:
	
	$(eval FC = gfortran)

# ==============================================================================

# ==============================================================================
# This line compiles the fortran code with gfortran. 
# ==============================================================================
gfortran: changegfortran $(subst .f90,.mod, $(SOURCES))
# ==============================================================================


clean:
	-rm -f *.o *.mod *.a
