
IFC = ifort
GFC = gfortran

IFORTFLAGS = -warn
GFORTFLAGS = -Wall -ffree-line-length-1024 -O3
FORTFLAGSDEBUG = -g
M = 5
N = 10
KEYWORD_TYPE = OTI_TYPE
KEYWORD_MOD = OTI_MOD
OTI_TYPE = ONUMM$(M)N$(N)
OTI_MOD = otim$(M)n$(N)


all: gnu


gnu: 
	sed -e 's/$(KEYWORD_TYPE)/$(OTI_TYPE)/g' -e 's/$(KEYWORD_MOD)/$(OTI_MOD)/g' testoti.f90.in > testoti.f90
	$(GFC) -c $(OTI_MOD).f90 $(FORTFLAGSDEBUG) $(GFORTFLAGS)
	$(GFC) -c testoti.f90 $(FORTFLAGSDEBUG) $(GFORTFLAGS)   
	$(GFC) testoti.o $(OTI_MOD).o -o test 