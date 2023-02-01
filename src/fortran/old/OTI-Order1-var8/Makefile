
IFC = ifort
GFC = gfortran

IFORTFLAGS = -warn
GFORTFLAGS = -O3
FORTFLAGSDEBUG = -g

all: intel


intel:
	$(IFC) -c Octonions.f90 $(FORTFLAGSDEBUG) $(IFORTFLAGS)
	$(IFC) -c testOctoMat.f90 $(FORTFLAGSDEBUG) $(IFORTFLAGS)   
	$(IFC) testOctoMat.o Octonions.o -o testOctoMat

gnu: 
	$(GFC) -c Octonions.f90 $(FORTFLAGSDEBUG) $(GFORTFLAGS)
	$(GFC) -c testOctoMat.f90 $(FORTFLAGSDEBUG) $(GFORTFLAGS)   
	$(GFC) testOctoMat.o Octonions.o -o testOctoMat
	
