PROGRAM MAIN

    USE OMP_LIB

    IMPLICIT NONE

    INTEGER :: ID, I
    INTEGER,PARAMETER::NELS = 16
    INTEGER :: A(NELS)

    
    !$OMP PARALLEL PRIVATE(ID)
    ID =  omp_get_thread_num()

    WRITE(*,*) "Hello World! from thread: ", ID
    !$OMP END PARALLEL

    !$OMP PARALLEL DO PRIVATE(ID)
    DO I = 1,NELS
        ID =  omp_get_thread_num()
        A(I)=ID
    END DO
    !$OMP END PARALLEL DO

    PRINT*, A


END PROGRAM MAIN