FC = ifort

LIBFOLDER=oti_type
all: static main


static:
	
	+$(MAKE) -C oti_type/

main:  
	$(FC) test_oti_type.f90 -o test_oti_type.exe -O2 -I$(LIBFOLDER) -L$(LIBFOLDER) -lotistamod 