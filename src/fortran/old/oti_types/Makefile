
IFC = ifort
GFC = gfortran

IFORTFLAGS = -warn
GFORTFLAGS = -O3
FORTFLAGSDEBUG = -g

all: gnu


gnu: 
	$(GFC) -c otim2n2.f90 $(FORTFLAGSDEBUG) $(GFORTFLAGS)
	$(GFC) -c testoti.f90 $(FORTFLAGSDEBUG) $(GFORTFLAGS)   
	$(GFC) testoti.o otim2n2.o -o test
	
